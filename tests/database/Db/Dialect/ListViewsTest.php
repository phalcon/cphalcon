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

final class ListViewsTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function getDialects(): array
    {
        return [
            [
                Mysql::class,
                "SELECT `TABLE_NAME` AS view_name "
                . "FROM `INFORMATION_SCHEMA`.`VIEWS` "
                . "WHERE `TABLE_SCHEMA` = 'schema' "
                . "ORDER BY view_name",
            ],
            [
                Postgresql::class,
                "SELECT viewname AS view_name "
                . "FROM pg_views "
                . "WHERE schemaname = 'schema' "
                . "ORDER BY view_name",
            ],
            [
                Sqlite::class,
                "SELECT tbl_name "
                . "FROM sqlite_master "
                . "WHERE type = 'view' "
                . "ORDER BY tbl_name",
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
                "SELECT `TABLE_NAME` AS view_name "
                . "FROM `INFORMATION_SCHEMA`.`VIEWS` "
                . "WHERE `TABLE_SCHEMA` = DATABASE() "
                . "ORDER BY view_name",
            ],
            [
                Postgresql::class,
                "SELECT viewname AS view_name FROM pg_views "
                . "WHERE schemaname = 'public' ORDER BY view_name",
            ],
            [
                Sqlite::class,
                "SELECT tbl_name FROM sqlite_master "
                . "WHERE type = 'view' ORDER BY tbl_name",
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: listViews
     *
     * @dataProvider getDialects
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group sqlite
     */
    public function testDbDialectListViews(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->listViews('schema');
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect :: listViews - no schema
     *
     * @dataProvider getDialectsNoSchema
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group sqlite
     */
    public function testDbDialectListViewsNoSchema(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->listViews();
        $this->assertSame($expected, $actual);
    }
}
