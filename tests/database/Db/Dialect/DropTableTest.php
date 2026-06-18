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
use PHPUnit\Framework\Attributes\DataProvider;

final class DropTableTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function getDialects(): array
    {
        return [
            [
                Mysql::class,
                'DROP TABLE IF EXISTS `schema`.`table`',

            ],
            [
                Postgresql::class,
                'DROP TABLE IF EXISTS "schema"."table"',
            ],
            [
                Sqlite::class,
                'DROP TABLE IF EXISTS "schema"."table"',
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function getDialectsNotExists(): array
    {
        return [
            [
                Mysql::class,
                'DROP TABLE `schema`.`table`',

            ],
            [
                Postgresql::class,
                'DROP TABLE "schema"."table"',
            ],
            [
                Sqlite::class,
                'DROP TABLE "schema"."table"',
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: dropTable
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    #[DataProvider('getDialects')]
    public function testDbDialectDropTable(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->dropTable('table', 'schema');
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect :: dropTable - ifExists false
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    #[DataProvider('getDialectsNotExists')]
    public function testDbDialectDropTableNotExists(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->dropTable('table', 'schema', false);
        $this->assertSame($expected, $actual);
    }
}
