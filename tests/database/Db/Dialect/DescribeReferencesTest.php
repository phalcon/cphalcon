<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Db\Dialect;

use Phalcon\Db\Dialect\Mysql;
use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

final class DescribeReferencesTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function getDialects(): array
    {
        return [
            [
                Mysql::class,
                "SELECT DISTINCT "
                . "KCU.TABLE_NAME, KCU.COLUMN_NAME, KCU.CONSTRAINT_NAME, "
                . "KCU.REFERENCED_TABLE_SCHEMA, KCU.REFERENCED_TABLE_NAME, "
                . "KCU.REFERENCED_COLUMN_NAME, RC.UPDATE_RULE, "
                . "RC.DELETE_RULE "
                . "FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE AS KCU "
                . "LEFT JOIN INFORMATION_SCHEMA.REFERENTIAL_CONSTRAINTS AS RC "
                . "ON RC.CONSTRAINT_NAME = KCU.CONSTRAINT_NAME "
                . "AND RC.CONSTRAINT_SCHEMA = KCU.CONSTRAINT_SCHEMA "
                . "WHERE KCU.REFERENCED_TABLE_NAME IS NOT NULL "
                . "AND KCU.CONSTRAINT_SCHEMA = 'schema' "
                . "AND KCU.TABLE_NAME = 'table'",

            ],
            [
                Postgresql::class,
                "SELECT c.relname AS TABLE_NAME, "
                . "a.attname AS COLUMN_NAME, "
                . "con.conname AS CONSTRAINT_NAME, "
                . "current_database() AS REFERENCED_TABLE_SCHEMA, "
                . "fc.relname AS REFERENCED_TABLE_NAME, "
                . "fa.attname AS REFERENCED_COLUMN_NAME, "
                . "CASE con.confupdtype WHEN 'c' THEN 'CASCADE' "
                . "WHEN 'n' THEN 'SET NULL' WHEN 'd' THEN 'SET DEFAULT' "
                . "WHEN 'r' THEN 'RESTRICT' WHEN 'a' THEN 'NO ACTION' "
                . "END AS UPDATE_RULE, "
                . "CASE con.confdeltype WHEN 'c' THEN 'CASCADE' "
                . "WHEN 'n' THEN 'SET NULL' WHEN 'd' THEN 'SET DEFAULT' "
                . "WHEN 'r' THEN 'RESTRICT' WHEN 'a' THEN 'NO ACTION' "
                . "END AS DELETE_RULE "
                . "FROM pg_catalog.pg_constraint AS con "
                . "JOIN pg_catalog.pg_class AS c ON c.oid = con.conrelid "
                . "JOIN pg_catalog.pg_namespace AS n ON n.oid = c.relnamespace "
                . "JOIN pg_catalog.pg_class AS fc ON fc.oid = con.confrelid "
                . "CROSS JOIN LATERAL unnest(con.conkey, con.confkey) "
                . "WITH ORDINALITY AS k(colnum, refcolnum, colpos) "
                . "JOIN pg_catalog.pg_attribute AS a "
                . "ON a.attrelid = con.conrelid AND a.attnum = k.colnum "
                . "JOIN pg_catalog.pg_attribute AS fa "
                . "ON fa.attrelid = con.confrelid AND fa.attnum = k.refcolnum "
                . "WHERE con.contype = 'f' "
                . "AND n.nspname = 'schema' "
                . "AND c.relname = 'table' "
                . "ORDER BY con.conname, k.colpos",
            ],
            [
                Sqlite::class,
                "PRAGMA foreign_key_list('table')",
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function getDialectsNoSchema(): array
    {
        return [
            [
                Mysql::class,
                "SELECT DISTINCT "
                . "KCU.TABLE_NAME, KCU.COLUMN_NAME, KCU.CONSTRAINT_NAME, "
                . "KCU.REFERENCED_TABLE_SCHEMA, KCU.REFERENCED_TABLE_NAME, "
                . "KCU.REFERENCED_COLUMN_NAME, RC.UPDATE_RULE, RC.DELETE_RULE "
                . "FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE AS KCU "
                . "LEFT JOIN INFORMATION_SCHEMA.REFERENTIAL_CONSTRAINTS AS RC "
                . "ON RC.CONSTRAINT_NAME = KCU.CONSTRAINT_NAME "
                . "AND RC.CONSTRAINT_SCHEMA = KCU.CONSTRAINT_SCHEMA "
                . "WHERE KCU.REFERENCED_TABLE_NAME IS NOT NULL "
                . "AND KCU.CONSTRAINT_SCHEMA = DATABASE() "
                . "AND KCU.TABLE_NAME = 'table'",
            ],
            [
                Postgresql::class,
                "SELECT c.relname AS TABLE_NAME, "
                . "a.attname AS COLUMN_NAME, "
                . "con.conname AS CONSTRAINT_NAME, "
                . "current_database() AS REFERENCED_TABLE_SCHEMA, "
                . "fc.relname AS REFERENCED_TABLE_NAME, "
                . "fa.attname AS REFERENCED_COLUMN_NAME, "
                . "CASE con.confupdtype WHEN 'c' THEN 'CASCADE' "
                . "WHEN 'n' THEN 'SET NULL' WHEN 'd' THEN 'SET DEFAULT' "
                . "WHEN 'r' THEN 'RESTRICT' WHEN 'a' THEN 'NO ACTION' "
                . "END AS UPDATE_RULE, "
                . "CASE con.confdeltype WHEN 'c' THEN 'CASCADE' "
                . "WHEN 'n' THEN 'SET NULL' WHEN 'd' THEN 'SET DEFAULT' "
                . "WHEN 'r' THEN 'RESTRICT' WHEN 'a' THEN 'NO ACTION' "
                . "END AS DELETE_RULE "
                . "FROM pg_catalog.pg_constraint AS con "
                . "JOIN pg_catalog.pg_class AS c ON c.oid = con.conrelid "
                . "JOIN pg_catalog.pg_namespace AS n ON n.oid = c.relnamespace "
                . "JOIN pg_catalog.pg_class AS fc ON fc.oid = con.confrelid "
                . "CROSS JOIN LATERAL unnest(con.conkey, con.confkey) "
                . "WITH ORDINALITY AS k(colnum, refcolnum, colpos) "
                . "JOIN pg_catalog.pg_attribute AS a "
                . "ON a.attrelid = con.conrelid AND a.attnum = k.colnum "
                . "JOIN pg_catalog.pg_attribute AS fa "
                . "ON fa.attrelid = con.confrelid AND fa.attnum = k.refcolnum "
                . "WHERE con.contype = 'f' "
                . "AND n.nspname = 'public' "
                . "AND c.relname = 'table' "
                . "ORDER BY con.conname, k.colpos",
            ],
            [
                Sqlite::class,
                "PRAGMA foreign_key_list('table')",
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: describeReferences
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getDialects')]
    public function testDbDialectDescribeReferences(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->describeReferences('table', 'schema');
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect :: describeReferences - no schema
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getDialectsNoSchema')]
    public function testDbDialectDescribeReferencesNoSchema(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->describeReferences('table');
        $this->assertSame($expected, $actual);
    }
}
