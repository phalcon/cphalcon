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
                "SELECT DISTINCT tc.table_name AS TABLE_NAME, "
                . "kcu.column_name AS COLUMN_NAME, "
                . "tc.constraint_name AS CONSTRAINT_NAME, "
                . "tc.table_catalog AS REFERENCED_TABLE_SCHEMA, "
                . "ccu.table_name AS REFERENCED_TABLE_NAME, "
                . "ccu.column_name AS REFERENCED_COLUMN_NAME, "
                . "rc.update_rule AS UPDATE_RULE, "
                . "rc.delete_rule AS DELETE_RULE "
                . "FROM information_schema.table_constraints AS tc "
                . "JOIN information_schema.key_column_usage AS kcu "
                . "ON tc.constraint_name = kcu.constraint_name "
                . "JOIN information_schema.constraint_column_usage AS ccu "
                . "ON ccu.constraint_name = tc.constraint_name "
                . "JOIN information_schema.referential_constraints rc "
                . "ON tc.constraint_catalog = rc.constraint_catalog "
                . "AND tc.constraint_schema = rc.constraint_schema "
                . "AND tc.constraint_name = rc.constraint_name "
                . "AND tc.constraint_type = 'FOREIGN KEY' "
                . "WHERE constraint_type = 'FOREIGN KEY' "
                . "AND tc.table_schema = 'schema' "
                . "AND tc.table_name='table'",
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
                "SELECT DISTINCT tc.table_name AS TABLE_NAME, "
                . "kcu.column_name AS COLUMN_NAME, "
                . "tc.constraint_name AS CONSTRAINT_NAME, "
                . "tc.table_catalog AS REFERENCED_TABLE_SCHEMA, "
                . "ccu.table_name AS REFERENCED_TABLE_NAME, "
                . "ccu.column_name AS REFERENCED_COLUMN_NAME, "
                . "rc.update_rule AS UPDATE_RULE, "
                . "rc.delete_rule AS DELETE_RULE "
                . "FROM information_schema.table_constraints AS tc "
                . "JOIN information_schema.key_column_usage AS kcu "
                . "ON tc.constraint_name = kcu.constraint_name "
                . "JOIN information_schema.constraint_column_usage AS ccu "
                . "ON ccu.constraint_name = tc.constraint_name "
                . "JOIN information_schema.referential_constraints rc "
                . "ON tc.constraint_catalog = rc.constraint_catalog "
                . "AND tc.constraint_schema = rc.constraint_schema "
                . "AND tc.constraint_name = rc.constraint_name "
                . "AND tc.constraint_type = 'FOREIGN KEY' "
                . "WHERE constraint_type = 'FOREIGN KEY' "
                . "AND tc.table_schema = 'public' "
                . "AND tc.table_name='table'",
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
     * @dataProvider getDialects
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group sqlite
     */
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
     * @dataProvider getDialectsNoSchema
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group sqlite
     */
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
