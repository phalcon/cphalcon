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

use Phalcon\Db\Column;
use Phalcon\Db\Dialect\Mysql;
use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

final class AddColumnGeneratedTest extends AbstractDatabaseTestCase
{
    /**
     * MySQL STORED.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    public function testDbDialectMysqlAddColumnGeneratedStored(): void
    {
        $dialect = new Mysql();

        $column = new Column(
            'total',
            [
                'type'             => Column::TYPE_INTEGER,
                'size'             => 11,
                'generated'        => 'price * quantity',
                'generationStored' => true,
            ]
        );

        $expected = 'ALTER TABLE `schema`.`table` ADD `total` INT(11) '
            . 'GENERATED ALWAYS AS (price * quantity) STORED NOT NULL';
        $actual   = $dialect->addColumn('table', 'schema', $column);

        $this->assertSame($expected, $actual);
    }

    /**
     * MySQL - confirm DEFAULT/AUTO_INCREMENT are not emitted for a generated
     * column (they cannot legally coexist; both would otherwise be appended
     * after the type by `addColumn`).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    public function testDbDialectMysqlAddColumnGeneratedSuppressesDefault(): void
    {
        $dialect = new Mysql();

        $column = new Column(
            'total',
            [
                'type'      => Column::TYPE_INTEGER,
                'size'      => 11,
                'generated' => 'price * quantity',
            ]
        );

        $actual = $dialect->addColumn('table', 'schema', $column);

        $this->assertStringNotContainsString(' DEFAULT ', $actual);
        $this->assertStringNotContainsString(' AUTO_INCREMENT', $actual);
    }
    /**
     * MySQL VIRTUAL.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    public function testDbDialectMysqlAddColumnGeneratedVirtual(): void
    {
        $dialect = new Mysql();

        $column = new Column(
            'total',
            [
                'type'      => Column::TYPE_INTEGER,
                'size'      => 11,
                'generated' => 'price * quantity',
            ]
        );

        $expected = 'ALTER TABLE `schema`.`table` ADD `total` INT(11) '
            . 'GENERATED ALWAYS AS (price * quantity) VIRTUAL NOT NULL';
        $actual   = $dialect->addColumn('table', 'schema', $column);

        $this->assertSame($expected, $actual);
    }

    /**
     * PostgreSQL - always emits STORED regardless of `generationStored`.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('pgsql')]
    public function testDbDialectPostgresqlAddColumnGeneratedAlwaysStored(): void
    {
        $dialect = new Postgresql();

        $column = new Column(
            'total',
            [
                'type'             => Column::TYPE_INTEGER,
                'size'             => 11,
                'generated'        => 'price * quantity',
                'generationStored' => false,
            ]
        );

        $expected = 'ALTER TABLE "schema"."table" ADD COLUMN "total" INT '
            . 'GENERATED ALWAYS AS (price * quantity) STORED NOT NULL';
        $actual   = $dialect->addColumn('table', 'schema', $column);

        $this->assertSame($expected, $actual);
    }

    /**
     * SQLite STORED.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('sqlite')]
    public function testDbDialectSqliteAddColumnGeneratedStored(): void
    {
        $dialect = new Sqlite();

        $column = new Column(
            'total',
            [
                'type'             => Column::TYPE_INTEGER,
                'size'             => 11,
                'generated'        => 'price * quantity',
                'generationStored' => true,
            ]
        );

        $expected = 'ALTER TABLE "schema"."table" ADD COLUMN "total" INTEGER '
            . 'GENERATED ALWAYS AS (price * quantity) STORED NOT NULL';
        $actual   = $dialect->addColumn('table', 'schema', $column);

        $this->assertSame($expected, $actual);
    }

    /**
     * SQLite VIRTUAL.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('sqlite')]
    public function testDbDialectSqliteAddColumnGeneratedVirtual(): void
    {
        $dialect = new Sqlite();

        $column = new Column(
            'total',
            [
                'type'      => Column::TYPE_INTEGER,
                'size'      => 11,
                'generated' => 'price * quantity',
            ]
        );

        $expected = 'ALTER TABLE "schema"."table" ADD COLUMN "total" INTEGER '
            . 'GENERATED ALWAYS AS (price * quantity) VIRTUAL NOT NULL';
        $actual   = $dialect->addColumn('table', 'schema', $column);

        $this->assertSame($expected, $actual);
    }
}
