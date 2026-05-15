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

namespace Phalcon\Tests\Database\Db\Dialect;

use Phalcon\Db\Check;
use Phalcon\Db\Column;
use Phalcon\Db\Dialect\Mysql;
use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class CreateTableWithCheckTest extends AbstractDatabaseTestCase
{
    /**
     * MySQL — `definition["checks"]` produces an inline `CONSTRAINT ... CHECK`
     * line at the end of the column list.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     */
    public function testDbDialectMysqlCreateTableWithCheck(): void
    {
        $dialect = new Mysql();

        $column = new Column(
            'price',
            [
                'type' => Column::TYPE_INTEGER,
                'size' => 11,
            ]
        );

        $check = new Check(
            'chk_price_positive',
            [
                'expression' => 'price > 0',
            ]
        );

        $expected = "CREATE TABLE `schema`.`table` (\n"
            . "\t`price` INT(11) NOT NULL,\n"
            . "\tCONSTRAINT `chk_price_positive` CHECK (price > 0)\n"
            . ")";

        $actual = $dialect->createTable(
            'table',
            'schema',
            [
                'columns' => [$column],
                'checks'  => [$check],
            ]
        );

        $this->assertSame($expected, $actual);
    }

    /**
     * PostgreSQL — `definition["checks"]` produces an inline constraint line.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    public function testDbDialectPostgresqlCreateTableWithCheck(): void
    {
        $dialect = new Postgresql();

        $column = new Column(
            'price',
            [
                'type' => Column::TYPE_INTEGER,
                'size' => 11,
            ]
        );

        $check = new Check(
            'chk_price_positive',
            [
                'expression' => 'price > 0',
            ]
        );

        $actual = $dialect->createTable(
            'table',
            'schema',
            [
                'columns' => [$column],
                'checks'  => [$check],
            ]
        );

        $this->assertStringContainsString(
            'CONSTRAINT "chk_price_positive" CHECK (price > 0)',
            $actual
        );
    }

    /**
     * SQLite — CHECK is supported inline in CREATE TABLE (the only place
     * SQLite allows it).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group sqlite
     */
    public function testDbDialectSqliteCreateTableWithCheck(): void
    {
        $dialect = new Sqlite();

        $column = new Column(
            'price',
            [
                'type' => Column::TYPE_INTEGER,
                'size' => 11,
            ]
        );

        $check = new Check(
            'chk_price_positive',
            [
                'expression' => 'price > 0',
            ]
        );

        $actual = $dialect->createTable(
            'table',
            'schema',
            [
                'columns' => [$column],
                'checks'  => [$check],
            ]
        );

        $this->assertStringContainsString(
            'CONSTRAINT `chk_price_positive` CHECK (price > 0)',
            $actual
        );
    }
}
