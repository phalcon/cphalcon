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

namespace Phalcon\Tests\Integration\Db\Column;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Column;

class IsAutoIncrementCest
{
    /**
     * Tests Phalcon\Db\Column :: isAutoIncrement() - Mysql
     *
     * @dataProvider connectionProvider
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function dbColumnIsAutoIncrement(IntegrationTester $I, Example $example)
    {
        $I->wantToTest(
            sprintf(
                'Db\Column - isAutoIncrement() - %s',
                $example['name']
            )
        );

        $columns  = $example['data'];
        $expected = $example['expected'];

        foreach ($columns as $index => $column) {
            $I->assertEquals(
                $expected[$index],
                $column->isAutoIncrement()
            );
        }
    }

    /**
     * Returns the connections for each data provider
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    private function connectionProvider(): array
    {
        return [
            [
                'name'     => 'Mysql',
                'data'     => [
                    0 => new Column(
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
                    1 => new Column(
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
                ],
                'expected' => [
                    0 => true,
                    1 => false,
                ],
            ],
            [
                'name'     => 'Postgresql',
                'data'     => [
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
                ],
                'expected' => [
                    0 => true,
                    1 => false,
                ],
            ],
        ];
    }
}
