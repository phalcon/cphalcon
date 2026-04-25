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

final class DropPrimaryKeyTest extends AbstractDatabaseTestCase
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
                . 'DROP PRIMARY KEY',

            ],
            [
                Postgresql::class,
                'ALTER TABLE "schema"."table" DROP CONSTRAINT "table_PRIMARY"',
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: dropPrimaryKey - sqlite throws exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     *
     * @group sqlite
     */
    public function testDbDialectDropPrimaryKeySqlite(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Removing a primary key after table has been created '
            . 'is not supported by SQLite'
        );

        $dialect = new Sqlite();

        $dialect->dropPrimaryKey('table', 'schema');
    }

    /**
     * Tests Phalcon\Db\Dialect :: dropPrimaryKey
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
    public function testDbDialectDropPrimaryKey(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->dropPrimaryKey('table', 'schema');
        $this->assertSame($expected, $actual);
    }
}
