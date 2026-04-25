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

use Phalcon\Db\Dialect\Mysql;
use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class DescribeColumnsTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function getMysqlData(): array
    {
        return [
            [
                'schema.name.with.dots',
                'SHOW FULL COLUMNS FROM `schema.name.with.dots`.`table`',
            ],
            [
                null,
                'SHOW FULL COLUMNS FROM `table`',
            ],
            [
                'schema',
                'SHOW FULL COLUMNS FROM `schema`.`table`',
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function getPostgresqlData(): array
    {
        $base = 'SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, '
            . 'c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, '
            . 'c.numeric_scale AS NumericScale, c.is_nullable AS Null, '
            . "CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, "
            . "CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' "
            . "THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, "
            . 'c.column_default, des.description FROM information_schema.columns c '
            . 'LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema '
            . 'FROM information_schema.table_constraints tc '
            . 'INNER JOIN information_schema.key_column_usage kcu on '
            . '(kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name '
            . "and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc "
            . 'ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND '
            . "c.table_name=pkc.table_name) LEFT JOIN ( SELECT objsubid, description, relname, nspname "
            . "FROM pg_description JOIN pg_class ON pg_description.objoid = pg_class.oid JOIN pg_namespace ON "
            . "pg_class.relnamespace = pg_namespace.oid ) des ON ( des.objsubid = C.ordinal_position "
            . "AND C.table_schema = des.nspname AND C.TABLE_NAME = des.relname )";

        return [
            [
                'schema.name.with.dots',
                $base
                . " WHERE c.table_schema='schema.name.with.dots' AND c.table_name='table' ORDER BY c.ordinal_position",
            ],
            [
                null,
                $base . " WHERE c.table_schema='public' AND c.table_name='table' ORDER BY c.ordinal_position",
            ],
            [
                'schema',
                $base . " WHERE c.table_schema='schema' AND c.table_name='table' ORDER BY c.ordinal_position",
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function getSqliteData(): array
    {
        return [
            [
                'schema.name.with.dots',
                "PRAGMA table_info('table')",
            ],
            [
                '',
                "PRAGMA table_info('table')",
            ],
            [
                'schema',
                "PRAGMA table_info('table')",
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect\Mysql :: describeColumns
     *
     * @dataProvider getMysqlData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbDialectMysqlDescribeColumns(
        ?string $schema,
        string $expected
    ): void {
        $dialect = new Mysql();
        $actual  = $dialect->describeColumns('table', $schema);
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: describeColumns
     *
     * @dataProvider getPostgresqlData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group pgsql
     */
    public function testDbDialectPostgresqlDescribeColumns(
        ?string $schema,
        string $expected
    ): void {
        $dialect = new Postgresql();
        $actual  = $dialect->describeColumns('table', $schema);
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: describeColumns
     *
     * @dataProvider getSqliteData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group sqlite
     */
    public function testDbDialectSqliteDescribeColumns(
        string $schema,
        string $expected
    ): void {
        $dialect = new Sqlite();
        $actual  = $dialect->describeColumns('table', $schema);
        $this->assertSame($expected, $actual);
    }
}
