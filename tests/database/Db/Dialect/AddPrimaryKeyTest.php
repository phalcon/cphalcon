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
use Phalcon\Db\Index;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class AddPrimaryKeyTest extends AbstractDatabaseTestCase
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
                . 'ADD PRIMARY KEY (`field1`, `field2`)',

            ],
            [
                Postgresql::class,
                'ALTER TABLE "schema"."table" '
                . 'ADD CONSTRAINT "table_PRIMARY" '
                . 'PRIMARY KEY ("field1", "field2")',
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: addPrimaryKey - sqlite throws exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     *
     * @group sqlite
     */
    public function testDbDialectAddPrimaryKeySqlite(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Adding a primary key after table has been created '
            . 'is not supported by SQLite'
        );

        $dialect = new Sqlite();

        $index = new Index('index1', ['field1', 'field2']);
        $dialect->addPrimaryKey('table', 'schema', $index);
    }

    /**
     * Tests Phalcon\Db\Dialect :: addPrimaryKey
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
    public function testDbDialectAddPrimaryKey(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $index  = new Index('index1', ['field1', 'field2']);
        $actual = $dialect->addPrimaryKey('table', 'schema', $index);
        $this->assertSame($expected, $actual);
    }
}
