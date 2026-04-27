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

final class DropColumnTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function getDialects(): array
    {
        return [
            [
                Mysql::class,
                'ALTER TABLE `schema`.`table` DROP COLUMN `column`',

            ],
            [
                Postgresql::class,
                'ALTER TABLE "schema"."table" DROP COLUMN "column"',
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: dropColumn - sqlite throws exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     *
     * @group sqlite
     */
    public function testDbDialectDropColumnSqlite(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Dropping DB column is not supported by SQLite'
        );

        $dialect = new Sqlite();

        $dialect->dropColumn('table', 'schema', 'column');
    }

    /**
     * Tests Phalcon\Db\Dialect :: dropColumn
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
    public function testDbDialectDropColumn(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->dropColumn('table', 'schema', 'column');
        $this->assertSame($expected, $actual);
    }
}
