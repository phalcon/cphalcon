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
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class SpatialTypesTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function provideSpatialTypes(): array
    {
        return [
            [Column::TYPE_GEOMETRY,           'GEOMETRY'],
            [Column::TYPE_POINT,              'POINT'],
            [Column::TYPE_LINESTRING,         'LINESTRING'],
            [Column::TYPE_POLYGON,            'POLYGON'],
            [Column::TYPE_MULTIPOINT,         'MULTIPOINT'],
            [Column::TYPE_MULTILINESTRING,    'MULTILINESTRING'],
            [Column::TYPE_MULTIPOLYGON,       'MULTIPOLYGON'],
            [Column::TYPE_GEOMETRYCOLLECTION, 'GEOMETRYCOLLECTION'],
        ];
    }

    /**
     * MySQL - emits each spatial keyword.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     */
    #[DataProvider('provideSpatialTypes')]
    public function testDbDialectMysqlGetColumnDefinitionSpatial(
        int $type,
        string $expected
    ): void {
        $dialect = new Mysql();
        $column  = new Column(
            'location',
            [
                'type' => $type,
            ]
        );

        $this->assertSame($expected, $dialect->getColumnDefinition($column));
    }

    /**
     * PostgreSQL - emits each spatial keyword (PostGIS interprets them).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    #[DataProvider('provideSpatialTypes')]
    public function testDbDialectPostgresqlGetColumnDefinitionSpatial(
        int $type,
        string $expected
    ): void {
        $dialect = new Postgresql();
        $column  = new Column(
            'location',
            [
                'type' => $type,
            ]
        );

        $this->assertSame($expected, $dialect->getColumnDefinition($column));
    }

    /**
     * MySQL - POINT column inside an ADD COLUMN statement.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     */
    public function testDbDialectMysqlAddColumnPoint(): void
    {
        $dialect = new Mysql();
        $column  = new Column(
            'location',
            [
                'type' => Column::TYPE_POINT,
            ]
        );

        $expected = 'ALTER TABLE `schema`.`table`'
            . ' ADD `location` POINT NOT NULL';
        $actual   = $dialect->addColumn('table', 'schema', $column);

        $this->assertSame($expected, $actual);
    }
}
