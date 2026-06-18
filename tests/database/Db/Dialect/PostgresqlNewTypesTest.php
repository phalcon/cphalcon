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
use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class PostgresqlNewTypesTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function provideScalarTypes(): array
    {
        return [
            [Column::TYPE_BYTEA,      'BYTEA'],
            [Column::TYPE_INET,       'INET'],
            [Column::TYPE_CIDR,       'CIDR'],
            [Column::TYPE_MACADDR,    'MACADDR'],
            [Column::TYPE_INT4RANGE,  'INT4RANGE'],
            [Column::TYPE_INT8RANGE,  'INT8RANGE'],
            [Column::TYPE_NUMRANGE,   'NUMRANGE'],
            [Column::TYPE_TSRANGE,    'TSRANGE'],
            [Column::TYPE_TSTZRANGE,  'TSTZRANGE'],
            [Column::TYPE_DATERANGE,  'DATERANGE'],
        ];
    }

    /**
     * PostgreSQL - getColumnDefinition emits the new type keywords.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    #[DataProvider('provideScalarTypes')]
    public function testDbDialectPostgresqlGetColumnDefinitionNewTypes(
        int $type,
        string $expected
    ): void {
        $dialect = new Postgresql();
        $column  = new Column(
            'col',
            [
                'type' => $type,
            ]
        );

        $this->assertSame($expected, $dialect->getColumnDefinition($column));
    }

    /**
     * Array suffix is appended after the type when `isArray()` is true.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    public function testDbDialectPostgresqlGetColumnDefinitionArrayOfInt(): void
    {
        $dialect = new Postgresql();
        $column  = new Column(
            'tags',
            [
                'type'  => Column::TYPE_INTEGER,
                'array' => true,
            ]
        );

        $this->assertSame('INT[]', $dialect->getColumnDefinition($column));
    }

    /**
     * Array suffix works with the new types too.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    public function testDbDialectPostgresqlGetColumnDefinitionArrayOfInet(): void
    {
        $dialect = new Postgresql();
        $column  = new Column(
            'addresses',
            [
                'type'  => Column::TYPE_INET,
                'array' => true,
            ]
        );

        $this->assertSame('INET[]', $dialect->getColumnDefinition($column));
    }

    /**
     * Column::isArray() defaults to false.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbColumnIsArrayFalseByDefault(): void
    {
        $column = new Column(
            'col',
            [
                'type' => Column::TYPE_INTEGER,
            ]
        );

        $this->assertFalse($column->isArray());
    }

    /**
     * Column::isArray() returns true when set.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbColumnIsArrayTrue(): void
    {
        $column = new Column(
            'col',
            [
                'type'  => Column::TYPE_INTEGER,
                'array' => true,
            ]
        );

        $this->assertTrue($column->isArray());
    }
}
