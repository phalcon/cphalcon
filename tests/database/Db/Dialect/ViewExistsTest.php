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

final class ViewExistsTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function getDialects(): array
    {
        return [
            [
                Mysql::class,
                "SELECT IF(COUNT(*) > 0, 1, 0) "
                . "FROM `INFORMATION_SCHEMA`.`VIEWS` "
                . "WHERE `TABLE_NAME`= 'view' "
                . "AND `TABLE_SCHEMA`='schema'",
            ],
            [
                Postgresql::class,
                "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END "
                . "FROM pg_views "
                . "WHERE viewname='view' "
                . "AND schemaname='schema'",
            ],
            [
                Sqlite::class,
                "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END "
                . "FROM sqlite_master "
                . "WHERE type='view' "
                . "AND tbl_name='view'",
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
                "SELECT IF(COUNT(*) > 0, 1, 0) "
                . "FROM `INFORMATION_SCHEMA`.`VIEWS` "
                . "WHERE `TABLE_NAME`='view' "
                . "AND `TABLE_SCHEMA` = DATABASE()",
            ],
            [
                Postgresql::class,
                "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END "
                . "FROM pg_views "
                . "WHERE viewname='view' "
                . "AND schemaname='public'",
            ],
            [
                Sqlite::class,
                "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END "
                . "FROM sqlite_master "
                . "WHERE type='view' "
                . "AND tbl_name='view'",
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: viewExists
     *
     * @dataProvider getDialects
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group sqlite
     */
    public function testDbDialectViewExists(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->viewExists('view', 'schema');
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect :: viewExists - no schema
     *
     * @dataProvider getDialectsNoSchema
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group sqlite
     */
    public function testDbDialectViewExistsNoSchema(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->viewExists('view');
        $this->assertSame($expected, $actual);
    }
}
