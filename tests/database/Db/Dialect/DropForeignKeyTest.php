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
use Phalcon\Db\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class DropForeignKeyTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function getDialects(): array
    {
        return [
            [
                Mysql::class,
                'ALTER TABLE `schema`.`table` '
                . 'DROP FOREIGN KEY `fk_1`',

            ],
            [
                Postgresql::class,
                'ALTER TABLE "schema"."table" DROP CONSTRAINT "fk_1"',
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: dropForeignKey - sqlite throws exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     *
     * @group sqlite
     */
    public function testDbDialectDropForeignKeySqlite(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Dropping a foreign key constraint is not supported by SQLite'
        );

        $dialect = new Sqlite();

        $dialect->dropForeignKey('table', 'schema', 'fk_1');
    }

    /**
     * Tests Phalcon\Db\Dialect :: dropForeignKey
     *
     * @dataProvider getDialects
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbDialectDropForeignKey(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->dropForeignKey('table', 'schema', 'fk_1');
        $this->assertSame($expected, $actual);
    }
}
