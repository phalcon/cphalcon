<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\Query;

use PDO;
use Phalcon\Mvc\Model\Query;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function json_encode;
use function sprintf;

/**
 * Before/after regression tests for the PHQL compiler injection sinks.
 *
 * Each test asserts the SECURE behavior, so it FAILS against the current
 * (unfixed) build and PASSES once the fix is in place. Run before the fix to
 * confirm the vulnerability, then after the fix (rebuild the extension) to
 * confirm it is closed.
 *
 * - F1: PHQL_T_STRING literal - phalcon_orm_singlequotes() (ext/.../orm.c)
 *       under-escapes an embedded quote preceded by a backslash. On engines
 *       where "\" is not a string escape (sqlite, pgsql standard strings) the
 *       quote terminates the literal and the tail runs as SQL.
 * - F2: functionCall name is emitted raw by the dialect. An escaped
 *       identifier "[ ... ]" carries arbitrary SQL into the name position.
 * - F3: CAST/CONVERT type (RAW_QUALIFIED) is emitted raw, same escaped
 *       identifier vector as F2.
 */
#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
#[Group('phql')]
final class PhqlInjectionTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * Value stored in a table the audited query never names. If it appears in
     * a result set, an injection read across table boundaries.
     */
    private const SECRET = 'S3CR3T-PHQL-DO-NOT-LEAK';

    private const SECRET_TABLE = 'phql_injection_secret';

    public function setUp(): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }

        $this->setDatabase();

        $connection = $this->getPdoConnection();

        // Public table the audited query is allowed to read
        $migration = new InvoicesMigration($connection);
        $migration->insert(1, 1, 0, 'alpha', 100);
        $migration->insert(2, 1, 0, 'beta', 200);

        // Out-of-scope table that holds a secret
        $connection->exec(
            sprintf('DROP TABLE IF EXISTS %s', self::SECRET_TABLE)
        );
        $connection->exec(
            sprintf('CREATE TABLE %s (tok VARCHAR(64))', self::SECRET_TABLE)
        );
        $connection->exec(
            sprintf(
                "INSERT INTO %s (tok) VALUES ('%s')",
                self::SECRET_TABLE,
                self::SECRET
            )
        );
    }

    public function tearDown(): void
    {
        $this->getPdoConnection()->exec(
            sprintf('DROP TABLE IF EXISTS %s', self::SECRET_TABLE)
        );

        parent::tearDown();
    }

    /**
     * F1 - the compiled SQL must neutralize an embedded single quote, even
     * when a backslash precedes it. The dialect escapes for its own syntax:
     * standard engines double the quote; MySQL doubles the backslash too,
     * because there the backslash is an escape character. Before the fix the
     * quote was emitted as "\'" and the "OR 1=1" tail escaped the literal.
     */
    public function testF1CompiledSqlNeutralizesEmbeddedQuote(): void
    {
        $phql = sprintf(
            "SELECT inv_id FROM [%s] WHERE inv_title = 'x\\' OR 1=1 -- '",
            Invoices::class
        );

        $sql = (new Query($phql, $this->container))->getSql()['sql'];

        // Standard: 'x\'' ...   MySQL: 'x\\'' ...   (quote is data, not a terminator)
        $expected = 'mysql' === $this->getDatabaseDialect()
            ? "x\\\\'' OR 1=1 -- '"
            : "x\\'' OR 1=1 -- '";

        $this->assertStringContainsString($expected, $sql);
    }

    /**
     * F1 - running the compiled SQL must not let the injected "OR 1=1" widen
     * the result. No row has the crafted title, so a safe build returns
     * nothing; before the fix the broken-out "OR 1=1" returns every row.
     */
    public function testF1ExecutionDoesNotBypassFilter(): void
    {
        $phql = sprintf(
            "SELECT inv_id FROM [%s] WHERE inv_title = 'x\\' OR 1=1 -- '",
            Invoices::class
        );

        $sql  = (new Query($phql, $this->container))->getSql()['sql'];
        $rows = $this->getPdoConnection()
                     ->query($sql)
                     ->fetchAll(PDO::FETCH_ASSOC);

        $this->assertCount(0, $rows);
    }

    /**
     * F2 - an escaped identifier in the function-name position must not smuggle
     * a UNION that reads the out-of-scope secret table.
     */
    public function testF2FunctionNameCannotLeakOtherTable(): void
    {
        $payload = sprintf(
            'inv_title FROM co_invoices UNION SELECT tok FROM %s -- ',
            self::SECRET_TABLE
        );

        $phql = sprintf(
            'SELECT [%s](inv_id) FROM [%s]',
            $payload,
            Invoices::class
        );

        $this->assertPayloadDoesNotLeak($phql);
    }

    /**
     * F3 - an escaped identifier in the CAST type position must not smuggle a
     * UNION that reads the out-of-scope secret table.
     */
    public function testF3CastTypeCannotLeakOtherTable(): void
    {
        $payload = sprintf(
            'char) FROM co_invoices UNION SELECT tok FROM %s -- ',
            self::SECRET_TABLE
        );

        $phql = sprintf(
            'SELECT CAST(inv_id AS [%s]) FROM [%s]',
            $payload,
            Invoices::class
        );

        $this->assertPayloadDoesNotLeak($phql);
    }

    /**
     * A neutralized identifier makes the crafted query invalid, so compiling
     * or running it may throw - that is a secure outcome. If it does run, the
     * secret from the out-of-scope table must not be in the result.
     */
    private function assertPayloadDoesNotLeak(string $phql): void
    {
        try {
            $sql      = (new Query($phql, $this->container))->getSql()['sql'];
            $haystack = (string) json_encode(
                $this->getPdoConnection()
                     ->query($sql)
                     ->fetchAll(PDO::FETCH_ASSOC)
            );
        } catch (\Throwable $e) {
            // Rejected once the identifier is validated - no data returned.
            $haystack = $e->getMessage();
        }

        $this->assertStringNotContainsString(
            self::SECRET,
            $haystack,
            'PHQL identifier injection leaked out-of-scope data'
        );
    }
}
