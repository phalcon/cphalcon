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

namespace Phalcon\Tests\Integration\Db\Dialect\Sqlite;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Column;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Db\Index;
use Phalcon\Db\Reference;

class CreateTableCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: createTable()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-
     *
     * @dataProvider getCreateTableFixtures
     */
    public function dbDialectSqliteCreateTable(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Db\Dialect\Sqlite - createTable()");

        $schema     = $example[0];
        $definition = $example[1];
        $expected   = $example[2];
        $dialect    = new Sqlite();

        $actual = $dialect->createTable(
            'table',
            $schema,
            $definition
        );

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
                rtrim(file_get_contents(dataDir('fixtures/Db/sqlite/example1.sql'))),
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
                rtrim(file_get_contents(dataDir('fixtures/Db/sqlite/example2.sql'))),
            ],
            'example3' => [
                '',
                [
                    'columns'    => [
                        new Column('column2', [
                            'type'     => Column::TYPE_INTEGER,
                            'size'     => 18,
                            'unsigned' => true,
                            'notNull'  => false,
                        ]),
                        new Column('column3', [
                            'type'     => Column::TYPE_DECIMAL,
                            'size'     => 10,
                            'scale'    => 2,
                            'unsigned' => false,
                            'notNull'  => true,
                        ]),
                        new Column('column1', [
                            'type' => Column::TYPE_VARCHAR,
                            'size' => 10,
                        ]),
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
                rtrim(file_get_contents(dataDir('fixtures/Db/sqlite/example3.sql'))),
            ],
            'example4' => [
                '',
                [
                    'columns' => [
                        new Column('column9', [
                            'type'    => Column::TYPE_VARCHAR,
                            'size'    => 10,
                            'default' => 'column9',
                        ]),
                        new Column('column10', [
                            'type'     => Column::TYPE_INTEGER,
                            'size'     => 18,
                            'unsigned' => true,
                            'notNull'  => false,
                            'default'  => 10,
                        ]),
                    ],
                ],
                rtrim(file_get_contents(dataDir('fixtures/Db/sqlite/example4.sql'))),
            ],
            'example5' => [
                '',
                [
                    'columns' => [
                        new Column('column11', [
                            'type'          => 'BIGINT',
                            'typeReference' => Column::TYPE_INTEGER,
                            'size'          => 20,
                            'unsigned'      => true,
                            'notNull'       => false,
                        ]),
                        new Column('column13', [
                            'type'    => Column::TYPE_TIMESTAMP,
                            'notNull' => true,
                            'default' => 'CURRENT_TIMESTAMP',
                        ]),
                    ],
                ],
                rtrim(file_get_contents(dataDir('fixtures/Db/sqlite/example5.sql'))),
            ],
            'example6' => [
                '',
                [
                    'columns' => [
                        new Column('column14', [
                            'type'    => Column::TYPE_TINYBLOB,
                            'notNull' => true,
                        ]),
                        new Column('column16', [
                            'type'    => Column::TYPE_BLOB,
                            'notNull' => true,
                        ]),
                    ],
                ],
                rtrim(file_get_contents(dataDir('fixtures/Db/sqlite/example6.sql'))),
            ],
            'example7' => [
                '',
                [
                    'columns' => [
                        new Column('column18', [
                            'type' => Column::TYPE_BOOLEAN,
                        ]),
                    ],
                ],
                rtrim(file_get_contents(dataDir('fixtures/Db/sqlite/example7.sql'))),
            ],
            'example8' => [
                '',
                [
                    'columns' => [
                        new Column('column19', [
                            'type' => Column::TYPE_DOUBLE,
                        ]),
                        new Column('column20', [
                            'type'     => Column::TYPE_DOUBLE,
                            'unsigned' => true,
                        ]),
                    ],
                ],
                rtrim(file_get_contents(dataDir('fixtures/Db/sqlite/example8.sql'))),
            ],
        ];
    }
}
