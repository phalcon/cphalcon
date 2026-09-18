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

use Phalcon\Mvc\Model\Query;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function sprintf;

/**
 * The scanner resolves the escape sequences of a PHQL string literal, and the
 * dialect then escapes the result for its own syntax. MySQL doubles the
 * backslash, because there it is a string escape character; the other engines
 * keep it. An unknown sequence keeps its backslash on every engine, so a LIKE
 * pattern such as "100\%" still matches a percent sign.
 *
 * @issue https://github.com/phalcon/cphalcon/issues/17585
 */
#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
#[Group('phql')]
final class StringEscapeTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private InvoicesMigration $invoiceMigration;

    public function setUp(): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }

        $this->setDatabase();

        $this->invoiceMigration = new InvoicesMigration(self::getPdoConnection());
    }

    /**
     * Every escape sequence must reach the compiled SQL as the character it
     * names, quoted for the target engine.
     */
    public function testEscapeSequencesInCompiledSql(): void
    {
        $isMysql = 'mysql' === self::getDatabaseDialect();

        // PHQL literal => the quoted literal the dialect must emit
        $expected = [
            "a\\nb"  => "'a\nb'",
            "a\\rb"  => "'a\rb'",
            "a\\tb"  => "'a\tb'",
            "a\\'b"  => "'a''b'",
            'a\\"b'  => "'a\"b'",
            "a\\\\b" => $isMysql ? "'a\\\\b'" : "'a\\b'",
            '100\\%' => $isMysql ? "'100\\\\%'" : "'100\\%'",
            "a\\db"  => $isMysql ? "'a\\\\db'" : "'a\\db'",
        ];

        foreach ($expected as $literal => $quoted) {
            $phql = sprintf(
                "SELECT inv_id FROM [%s] WHERE inv_title = '%s'",
                Invoices::class,
                $literal
            );

            $this->assertStringContainsString(
                $quoted,
                (new Query($phql, $this->container))->getSql()['sql'],
                $literal
            );
        }
    }

    /**
     * The reported case: "\n" must match a stored newline, so REPLACE()
     * changes it. Before the fix the literal held a backslash and an "n".
     */
    public function testNewlineEscapeMatchesStoredNewline(): void
    {
        $this->invoiceMigration->insert(1, 1, 0, "alpha\nbeta", 100);

        $phql = sprintf(
            "SELECT REPLACE(inv_title, '\\n', '<br>') AS title "
            . 'FROM [%s] WHERE inv_id = 1',
            Invoices::class
        );

        $result = (new Query($phql, $this->container))->execute();

        $this->assertSame('alpha<br>beta', $result[0]->title);
    }
}
