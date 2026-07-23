<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model;

use PDO;
use Phalcon\Events\Event;
use Phalcon\Events\Manager;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\GeneratedColumnsMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\GeneratedColumns;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function md5;
use function str_starts_with;
use function strtoupper;
use function uniqid;

final class InsertDefaultValuesTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private ?GeneratedColumnsMigration $migration = null;

    private array $statements = [];

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        (new InvoicesMigration($connection));

        $this->statements = [];
    }

    public function tearDown(): void
    {
        if (null !== $this->migration) {
            $this->migration->drop();
            $this->migration = null;
        }

        $this->tearDownDatabase();
    }

    /**
     * Tests that a column the database can supply a value for is left out of
     * the INSERT entirely on an adapter that does not support the `DEFAULT`
     * keyword (SQLite), rather than being bound as `null`.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17382
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-20
     */
    #[Group('sqlite')]
    public function testMvcModelInsertOmitsDefaultColumnWithoutDefaultSupport(): void
    {
        $this->recordStatements();

        $invoice                  = new Invoices();
        $invoice->inv_cst_id      = 2;
        $invoice->inv_status_flag = 1;
        $invoice->inv_title       = uniqid('inv-');
        $invoice->inv_total       = 100.12;

        $this->assertTrue($invoice->create());

        $actual = $this->getStatement('INSERT');
        $this->assertStringNotContainsString('inv_created_at', $actual);
    }

    /**
     * Tests that a MySQL stored generated column is inserted with `DEFAULT`,
     * which MySQL computes, instead of an explicit `null`, which MySQL rejects
     * with `SQLSTATE[HY000]: General error: 3105`.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17382
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-20
     */
    #[Group('mysql')]
    public function testMvcModelInsertUsesDefaultForGeneratedColumn(): void
    {
        /** @var PDO $connection */
        $pdo             = self::getPdoConnection();
        $this->migration = new GeneratedColumnsMigration($pdo, false);
        $this->migration->create();

        $connection = $this->recordStatements();

        $url                  = 'https://example.com/' . uniqid();
        $record               = new GeneratedColumns();
        $record->gen_url      = $url;

        $this->assertTrue($record->create());

        $actual = $this->getStatement('INSERT');
        $this->assertStringContainsString('DEFAULT', $actual);

        /**
         * The database computed the column
         */
        $actual = $connection->fetchOne(
            'select hex(gen_url_hash) as gen_url_hash from co_generated '
            . 'where gen_id = ' . $record->gen_id
        );
        $this->assertSame(strtoupper(md5($url)), $actual['gen_url_hash']);
    }

    /**
     * Tests that a column the database can supply a value for is inserted with
     * `DEFAULT` instead of a bound `null`, for a nullable column that carries
     * no explicit default.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17382
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    public function testMvcModelInsertUsesDefaultForNullableColumn(): void
    {
        $this->recordStatements();

        $invoice                  = new Invoices();
        $invoice->inv_cst_id      = 2;
        $invoice->inv_status_flag = 1;
        $invoice->inv_title       = uniqid('inv-');
        $invoice->inv_total       = 100.12;

        $this->assertTrue($invoice->create());

        /**
         * The column stays in the statement, but as the `DEFAULT` keyword -
         * never as a literal `null`. `DEFAULT` on its own is not enough of an
         * assertion: PostgreSQL also emits it for the identity column.
         */
        $actual = $this->getStatement('INSERT');
        $this->assertStringContainsString('inv_created_at', $actual);
        $this->assertStringNotContainsString('null', $actual);
    }

    /**
     * Returns the first recorded statement starting with the given prefix
     */
    private function getStatement(string $prefix): string
    {
        foreach ($this->statements as $statement) {
            if (str_starts_with($statement, $prefix)) {
                return $statement;
            }
        }

        return '';
    }

    /**
     * Attaches a listener to the connection recording every statement sent
     * to the database
     */
    private function recordStatements()
    {
        $connection = $this->container->get('db');
        $manager    = new Manager();

        $manager->attach(
            'db:beforeQuery',
            function (Event $event) use ($connection) {
                $this->statements[] = $connection->getSQLStatement();
            }
        );

        $connection->setEventsManager($manager);

        return $connection;
    }
}
