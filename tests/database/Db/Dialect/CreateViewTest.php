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

final class CreateViewTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function getDialects(): array
    {
        return [
            [
                Mysql::class,
                'CREATE VIEW `schema`.`view` AS DEFINITION-VIEW',
            ],
            [
                Postgresql::class,
                'CREATE VIEW "schema"."view" AS DEFINITION-VIEW',
            ],
            [
                Sqlite::class,
                'CREATE VIEW "schema"."view" AS DEFINITION-VIEW',
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function getDialectsException(): array
    {
        return [
            [
                Mysql::class,
            ],
            [
                Postgresql::class,
            ],
            [
                Sqlite::class,
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: createView
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
    public function testDbDialectCreateView(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $definition['sql'] = 'DEFINITION-VIEW';
        $actual            = $dialect->createView('view', $definition, 'schema');
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect :: createView - exception on missing sql definition
     *
     * @dataProvider getDialectsException
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbDialectCreateViewException(
        string $dialectClass
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $this->expectException(\Phalcon\Db\Exception::class);
        $this->expectExceptionMessage(
            "The index 'sql' is required in the definition array"
        );
        $definition = [];
        $dialect->createView('view', $definition, 'schema');
    }
}
