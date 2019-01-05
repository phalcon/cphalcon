<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Column;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Column;

/**
 * Class IsAutoIncrementCest
 */
class IsAutoIncrementCest
{
    /**
     * Tests Phalcon\Db\Column :: isAutoIncrement() - Mysql
     *
     * @param IntegrationTester $I
     * @param Example           $data
     *
     * @dataProvider connectionProvider
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2018-11-13
     */
    public function dbColumnIsAutoIncrement(IntegrationTester $I, Example $data)
    {
        $I->wantToTest(sprintf('Db\Column - isAutoIncrement() - %s', $data['name']));
        $columns  = $data['data'];
        $expected = $data['expected'];
        foreach ($columns as $index => $column) {
            $I->assertEquals($expected[$index], $column->isAutoIncrement());
        }
    }

    /**
     * Returns the connections for each data provider
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     *
     * @return array
     */
    private function connectionProvider()
    {
        return [
            [
                'name'     => 'Mysql',
                'data'     => [
                    0 => Column::__set_state(
                        [
                            '_columnName'    => 'field_primary',
                            '_schemaName'    => null,
                            '_type'          => Column::TYPE_INTEGER,
                            '_isNumeric'     => true,
                            '_size'          => 11,
                            '_scale'         => 0,
                            '_default'       => null,
                            '_unsigned'      => false,
                            '_notNull'       => true,
                            '_autoIncrement' => true,
                            '_primary'       => true,
                            '_first'         => true,
                            '_after'         => null,
                            '_bindType'      => Column::BIND_PARAM_INT,
                        ]
                    ),
                    1 => Column::__set_state(
                        [
                            '_columnName'    => 'field_bigint',
                            '_schemaName'    => null,
                            '_type'          => Column::TYPE_BIGINTEGER,
                            '_isNumeric'     => true,
                            '_size'          => 20,
                            '_scale'         => 0,
                            '_default'       => null,
                            '_unsigned'      => false,
                            '_notNull'       => false,
                            '_autoIncrement' => false,
                            '_primary'       => false,
                            '_first'         => false,
                            '_after'         => 'field_bit_default',
                            '_bindType'      => Column::BIND_PARAM_INT,
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
                    Column::__set_state(
                        [
                            '_columnName'    => 'field_primary',
                            '_schemaName'    => null,
                            '_type'          => Column::TYPE_INTEGER,
                            '_isNumeric'     => true,
                            '_size'          => 0,
                            '_scale'         => 0,
                            '_default'       => "nextval('dialect_table_field_primary_seq'::regclass)",
                            '_unsigned'      => false,
                            '_notNull'       => true,
                            '_autoIncrement' => true,
                            '_primary'       => true,
                            '_first'         => true,
                            '_after'         => null,
                            '_bindType'      => Column::BIND_PARAM_INT,
                        ]
                    ),
                    Column::__set_state(
                        [
                            '_columnName'    => 'field_bigint',
                            '_schemaName'    => null,
                            '_type'          => Column::TYPE_BIGINTEGER,
                            '_isNumeric'     => true,
                            '_size'          => 0,
                            '_scale'         => 0,
                            '_default'       => null,
                            '_unsigned'      => false,
                            '_notNull'       => false,
                            '_autoIncrement' => false,
                            '_primary'       => false,
                            '_first'         => false,
                            '_after'         => 'field_bit_default',
                            '_bindType'      => Column::BIND_PARAM_INT,
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
