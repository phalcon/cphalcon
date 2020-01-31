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

namespace Phalcon\Test\Integration\Db\Dialect\Mysql;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Column;
use Phalcon\Db\Dialect\Mysql;
use Phalcon\Db\Index;
use Phalcon\Db\Reference;

class CreateTableCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: createTable()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getCreateTableFixtures
     */
    public function dbDialectMysqlCreateTable(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Db\Dialect\Mysql - createTable()");

        $schema     = $example[0];
        $definition = $example[1];
        $expected   = $example[2];

        $dialect = new Mysql();
        $actual  = $dialect->createTable('table', $schema, $definition);

        $I->assertEquals($expected, $actual);
    }

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
                rtrim(file_get_contents(dataDir('fixtures/Db/mysql/example1.sql'))),
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
                rtrim(file_get_contents(dataDir('fixtures/Db/mysql/example2.sql'))),
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
                        new Reference(
                            'fk3',
                            [
                                'referencedTable'   => 'ref_table',
                                'columns'           => ['column1'],
                                'referencedColumns' => ['column2'],
                                'onDelete'          => 'CASCADE',
                            ]
                        ),
                    ],
                ],
                rtrim(file_get_contents(dataDir('fixtures/Db/mysql/example3.sql'))),
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
                rtrim(file_get_contents(dataDir('fixtures/Db/mysql/example4.sql'))),
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
                rtrim(file_get_contents(dataDir('fixtures/Db/mysql/example5.sql'))),
            ],
            'example6' => [
                '',
                [
                    'columns'    => [
                        new Column(
                            'id_user',
                            [
                                'type'          => 'BIGINT',
                                'typeReference' => Column::TYPE_INTEGER,
                                'size'          => 20,
                                'unsigned'      => true,
                                'notNull'       => false,
                            ]
                        ),
                    ],
                    'references' => [
                        new Reference(
                            'fk_id_user',
                            [
                                'referencedTable'   => 'users',
                                'referencedSchema'  => 'database2',
                                'columns'           => ['id_user'],
                                'referencedColumns' => ['id'],
                                'onUpdate'          => 'CASCADE',
                                'onDelete'          => 'SET NULL',
                            ]
                        ),
                    ],
                ],
                rtrim(file_get_contents(dataDir('fixtures/Db/mysql/example6.sql'))),
            ],
            'example7' => [
                '',
                [
                    'columns'    => [
                        new Column(
                            'default_timestamp_update',
                            [
                                'type'          => 'BIGINT',
                                'typeReference' => Column::TYPE_TIMESTAMP,
                                'default' => 'CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP',
                            ]
                        ),
                    ]
                ],
                rtrim(file_get_contents(dataDir('fixtures/Db/mysql/example7.sql'))),
            ],
        ];
    }
}
