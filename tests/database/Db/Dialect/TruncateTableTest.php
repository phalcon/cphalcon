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

final class TruncateTableTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function getDialects(): array
    {
        return [
            [
                Mysql::class,
                "TRUNCATE TABLE `schema`.`table`",
            ],
            [
                Postgresql::class,
                'TRUNCATE TABLE "schema"."table"',
            ],
            [
                Sqlite::class,
                'DELETE FROM "schema"."table"',
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
                "TRUNCATE TABLE `table`",
            ],
            [
                Postgresql::class,
                'TRUNCATE TABLE "table"',
            ],
            [
                Sqlite::class,
                'DELETE FROM "table"',
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: truncateTable
     *
     * @dataProvider getDialects
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group sqlite
     */
    public function testDbDialectTruncateTable(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->truncateTable('table', 'schema');
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect :: truncateTable - no schema
     *
     * @dataProvider getDialectsNoSchema
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group sqlite
     */
    public function testDbDialectTruncateTableNoSchema(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->truncateTable('table', '');
        $this->assertSame($expected, $actual);
    }
}
