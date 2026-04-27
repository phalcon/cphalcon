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
use Phalcon\Db\Reference;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class AddForeignKeyTest extends AbstractDatabaseTestCase
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
                . 'ADD CONSTRAINT `fk1` FOREIGN KEY (`field_primary`) '
                . 'REFERENCES `ref_schema`.`ref_table`(`field_referenced`)',

            ],
            [
                Postgresql::class,
                'ALTER TABLE "schema"."table" '
                . 'ADD CONSTRAINT "fk1" '
                . 'FOREIGN KEY ("field_primary") '
                . 'REFERENCES "ref_table" ("field_referenced")',
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function getDialectsOnDelete(): array
    {
        return [
            [
                Mysql::class,
                'ALTER TABLE `schema`.`table` '
                . 'ADD CONSTRAINT `fk1` FOREIGN KEY (`field_primary`) '
                . 'REFERENCES `ref_schema`.`ref_table`(`field_referenced`) '
                . 'ON DELETE delete command',

            ],
            [
                Postgresql::class,
                'ALTER TABLE "schema"."table" '
                . 'ADD CONSTRAINT "fk1" '
                . 'FOREIGN KEY ("field_primary") '
                . 'REFERENCES "ref_table" ("field_referenced") '
                . 'ON DELETE delete command',
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function getDialectsOnUpdate(): array
    {
        return [
            [
                Mysql::class,
                'ALTER TABLE `schema`.`table` '
                . 'ADD CONSTRAINT `fk1` FOREIGN KEY (`field_primary`) '
                . 'REFERENCES `ref_schema`.`ref_table`(`field_referenced`) '
                . 'ON UPDATE update command',

            ],
            [
                Postgresql::class,
                'ALTER TABLE "schema"."table" '
                . 'ADD CONSTRAINT "fk1" '
                . 'FOREIGN KEY ("field_primary") '
                . 'REFERENCES "ref_table" ("field_referenced") '
                . 'ON UPDATE update command',
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: addForeignKey - sqlite throws exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     *
     * @group sqlite
     */
    public function testDbDialectAddForeignKeySqlite(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Adding a foreign key constraint to an existing table '
            . 'is not supported by SQLite'
        );

        $dialect = new Sqlite();

        $reference = new Reference('fk1', [
            'referencedSchema'  => 'ref_schema',
            'referencedTable'   => 'ref_table',
            'columns'           => ['field_primary'],
            'referencedColumns' => ['field_referenced'],
        ]);
        $dialect->addForeignKey('table', 'schema', $reference);
    }

    /**
     * Tests Phalcon\Db\Dialect :: addForeignKey
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
    public function testDbDialectAddForeignKey(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $reference = new Reference('fk1', [
            'referencedSchema'  => 'ref_schema',
            'referencedTable'   => 'ref_table',
            'columns'           => ['field_primary'],
            'referencedColumns' => ['field_referenced'],
        ]);
        $actual    = $dialect->addForeignKey('table', 'schema', $reference);
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect :: addForeignKey - onDelete
     *
     * @dataProvider getDialectsOnDelete
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbDialectAddForeignKeyOnDelete(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $reference = new Reference('fk1', [
            'referencedSchema'  => 'ref_schema',
            'referencedTable'   => 'ref_table',
            'columns'           => ['field_primary'],
            'referencedColumns' => ['field_referenced'],
            'onDelete'          => 'delete command',
        ]);
        $actual    = $dialect->addForeignKey('table', 'schema', $reference);
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect :: addForeignKey - onUpdate
     *
     * @dataProvider getDialectsOnUpdate
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbDialectAddForeignKeyOnUpdate(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $reference = new Reference('fk1', [
            'referencedSchema'  => 'ref_schema',
            'referencedTable'   => 'ref_table',
            'columns'           => ['field_primary'],
            'referencedColumns' => ['field_referenced'],
            'onUpdate'          => 'update command',
        ]);
        $actual    = $dialect->addForeignKey('table', 'schema', $reference);
        $this->assertSame($expected, $actual);
    }
}
