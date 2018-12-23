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

namespace Phalcon\Test\Integration\Db\Dialect\Mysql;

use IntegrationTester;
use Phalcon\Db\Column;
use Phalcon\Db\Index;
use Phalcon\Db\Reference;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

/**
 * Class CreateTableCest
 */
class CreateTableCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Mysql :: createTable()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function dbDialectMysqlCreateTable(IntegrationTester $I)
    {
        $I->wantToTest("Db\Dialect\Mysql - createTable()");
        $data = $this->getCreateTableFixtures();
        foreach ($data as $item) {
            $schema     = $item[0];
            $definition = $item[1];
            $expected   = $item[2];
            $dialect    = $this->getDialectMysql();
            $actual     = $dialect->createTable('table', $schema, $definition);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * @return array
     */
    protected function getCreateTableFixtures(): array
    {
        return [
            'example1' => [
                '',
                [
                    'columns' => [
                        new Column(
                            'column1',
                            [
                                'type' => Column::TYPE_VARCHAR,
                                'size' => 10,
                            ]
                        ),
                        new Column(
                            'column2',
                            [
                                'type'     => Column::TYPE_INTEGER,
                                'size'     => 18,
                                'unsigned' => true,
                                'notNull'  => false,
                            ]
                        ),
                    ],
                ],
                rtrim(file_get_contents(dataFolder('fixtures/Db/mysql/example1.sql'))),
            ],
            'example2' => [
                '',
                [
                    'columns' => [
                        new Column(
                            'column2',
                            [
                                'type'     => Column::TYPE_INTEGER,
                                'size'     => 18,
                                'unsigned' => true,
                                'notNull'  => false,
                            ]
                        ),
                        new Column(
                            'column3',
                            [
                                'type'     => Column::TYPE_DECIMAL,
                                'size'     => 10,
                                'scale'    => 2,
                                'unsigned' => false,
                                'notNull'  => true,
                            ]
                        ),
                        new Column(
                            'column1',
                            [
                                'type' => Column::TYPE_VARCHAR,
                                'size' => 10,
                            ]
                        ),
                    ],
                    'indexes' => [
                        new Index('PRIMARY', ['column3']),
                    ],
                ],
                rtrim(file_get_contents(dataFolder('fixtures/Db/mysql/example2.sql'))),
            ],
            'example3' => [
                '',
                [
                    'columns'    => [
                        new Column(
                            'column2',
                            [
                                'type'     => Column::TYPE_INTEGER,
                                'size'     => 18,
                                'unsigned' => true,
                                'notNull'  => false,
                            ]
                        ),
                        new Column(
                            'column3',
                            [
                                'type'     => Column::TYPE_DECIMAL,
                                'size'     => 10,
                                'scale'    => 2,
                                'unsigned' => false,
                                'notNull'  => true,
                            ]
                        ),
                        new Column(
                            'column1',
                            [
                                'type' => Column::TYPE_VARCHAR,
                                'size' => 10,
                            ]
                        ),
                    ],
                    'indexes'    => [
                        new Index('PRIMARY', ['column3']),
                    ],
                    'references' => [
                        new Reference('fk3', [
                            'referencedTable'   => 'ref_table',
                            'columns'           => ['column1'],
                            'referencedColumns' => ['column2'],
                            'onDelete'          => 'CASCADE',
                        ]),
                    ],
                ],
                rtrim(file_get_contents(dataFolder('fixtures/Db/mysql/example3.sql'))),
            ],
            'example4' => [
                '',
                [
                    'columns' => [
                        new Column(
                            'column9',
                            [
                                'type'    => Column::TYPE_VARCHAR,
                                'size'    => 10,
                                'default' => 'column9',
                            ]
                        ),
                        new Column(
                            'column10',
                            [
                                'type'     => Column::TYPE_INTEGER,
                                'size'     => 18,
                                'unsigned' => true,
                                'notNull'  => false,
                                'default'  => 10,
                            ]
                        ),
                    ],
                ],
                rtrim(file_get_contents(dataFolder('fixtures/Db/mysql/example4.sql'))),
            ],
            'example5' => [
                '',
                [
                    'columns' => [
                        new Column(
                            'column11',
                            [
                                'type'          => 'BIGINT',
                                'typeReference' => Column::TYPE_INTEGER,
                                'size'          => 20,
                                'unsigned'      => true,
                                'notNull'       => false,
                            ]
                        ),
                        new Column(
                            'column12',
                            [
                                'type'       => 'ENUM',
                                'typeValues' => ['A', 'B', 'C'],
                                'notNull'    => true,
                                'default'    => 'A',
                                'after'      => 'column11',
                            ]
                        ),
                        new Column(
                            'column13',
                            [
                                'type'    => Column::TYPE_TIMESTAMP,
                                'notNull' => true,
                                'default' => 'CURRENT_TIMESTAMP',
                            ]
                        ),
                    ],
                ],
                rtrim(file_get_contents(dataFolder('fixtures/Db/mysql/example5.sql'))),
            ],
        ];
    }
}
