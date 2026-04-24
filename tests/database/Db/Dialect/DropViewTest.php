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

final class DropViewTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function getDialects(): array
    {
        return [
            [
                Mysql::class,
                'DROP VIEW IF EXISTS `schema`.`table`',

            ],
            [
                Postgresql::class,
                'DROP VIEW IF EXISTS "schema"."table"',
            ],
            [
                Sqlite::class,
                'DROP VIEW IF EXISTS "schema"."table"',
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
                'DROP VIEW `schema`.`table`',

            ],
            [
                Postgresql::class,
                'DROP VIEW "schema"."table"',
            ],
            [
                Sqlite::class,
                'DROP VIEW "schema"."table"',
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: dropView
     *
     * @dataProvider getDialects
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group sqlite
     */
    public function testDbDialectDropView(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->dropView('table', 'schema');
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect :: dropView - ifExists false
     *
     * @dataProvider getDialectsNotExists
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group sqlite
     */
    public function testDbDialectDropViewNotExists(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $actual = $dialect->dropView('table', 'schema', false);
        $this->assertSame($expected, $actual);
    }
}
