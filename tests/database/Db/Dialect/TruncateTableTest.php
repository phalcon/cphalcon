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
     * @return array[]
     */
    public static function getDialectsQuoteCharacter(): array
    {
        return [
            [
                Mysql::class,
                'co_inv`oices',
                'acc`ounts',
                "TRUNCATE TABLE `acc``ounts`.`co_inv``oices`",
            ],
            [
                Mysql::class,
                'co_inv`oices',
                '',
                "TRUNCATE TABLE `co_inv``oices`",
            ],
            [
                Postgresql::class,
                'co_inv"oices',
                'acc"ounts',
                'TRUNCATE TABLE "acc""ounts"."co_inv""oices"',
            ],
            [
                Postgresql::class,
                'co_inv"oices',
                '',
                'TRUNCATE TABLE "co_inv""oices"',
            ],
            [
                Sqlite::class,
                'co_inv"oices',
                'ma"in',
                'DELETE FROM "ma""in"."co_inv""oices"',
            ],
            [
                Sqlite::class,
                'co_inv"oices',
                '',
                'DELETE FROM "co_inv""oices"',
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: truncateTable
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getDialects')]
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
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getDialectsNoSchema')]
    public function testDbDialectTruncateTableNoSchema(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->truncateTable('table', '');
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect :: truncateTable - the quote character in a
     * name is doubled
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17808
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-26
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getDialectsQuoteCharacter')]
    public function testDbDialectTruncateTableQuoteCharacter(
        string $dialectClass,
        string $table,
        string $schema,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->truncateTable($table, $schema);
        $this->assertSame($expected, $actual);
    }
}
