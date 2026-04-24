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

namespace Phalcon\Tests\Database\Db\Column;

use Phalcon\Db\Column;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class IsAutoIncrementTest extends AbstractDatabaseTestCase
{
    /**
     * @return array<string, array{0: Column, 1: bool}>
     */
    public static function columnIsAutoIncrementProvider(): array
    {
        return [
            'mysql-field_primary' => [
                new Column(
                    'field_primary',
                    [
                        'type'          => Column::TYPE_INTEGER,
                        'isNumeric'     => true,
                        'size'          => 11,
                        'scale'         => 0,
                        'default'       => null,
                        'unsigned'      => false,
                        'notNull'       => true,
                        'autoIncrement' => true,
                        'primary'       => true,
                        'first'         => true,
                        'after'         => null,
                        'bindType'      => Column::BIND_PARAM_INT,
                    ]
                ),
                true,
            ],
            'mysql-field_bigint'  => [
                new Column(
                    'field_bigint',
                    [
                        'type'          => Column::TYPE_BIGINTEGER,
                        'isNumeric'     => true,
                        'size'          => 20,
                        'scale'         => 0,
                        'default'       => null,
                        'unsigned'      => false,
                        'notNull'       => false,
                        'autoIncrement' => false,
                        'primary'       => false,
                        'first'         => false,
                        'after'         => 'field_bit_default',
                        'bindType'      => Column::BIND_PARAM_INT,
                    ]
                ),
                false,
            ],
            'pgsql-field_primary' => [
                new Column(
                    'field_primary',
                    [
                        'type'          => Column::TYPE_INTEGER,
                        'isNumeric'     => true,
                        'size'          => 0,
                        'scale'         => 0,
                        'default'       => "nextval('dialect_table_field_primary_seq'::regclass)",
                        'unsigned'      => false,
                        'notNull'       => true,
                        'autoIncrement' => true,
                        'primary'       => true,
                        'first'         => true,
                        'after'         => null,
                        'bindType'      => Column::BIND_PARAM_INT,
                    ]
                ),
                true,
            ],
            'pgsql-field_bigint'  => [
                new Column(
                    'field_bigint',
                    [
                        'type'          => Column::TYPE_BIGINTEGER,
                        'isNumeric'     => true,
                        'size'          => 0,
                        'scale'         => 0,
                        'default'       => null,
                        'unsigned'      => false,
                        'notNull'       => false,
                        'autoIncrement' => false,
                        'primary'       => false,
                        'first'         => false,
                        'after'         => 'field_bit_default',
                        'bindType'      => Column::BIND_PARAM_INT,
                    ]
                ),
                false,
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Column :: isAutoIncrement()
     *
     * @dataProvider columnIsAutoIncrementProvider
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group  mysql
     * @group sqlite
     */
    public function testDbColumnIsAutoIncrement(Column $column, bool $expected): void
    {
        $this->assertSame($expected, $column->isAutoIncrement());
    }
}
