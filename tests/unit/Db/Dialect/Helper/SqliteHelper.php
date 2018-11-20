<?php

namespace Phalcon\Test\Unit\Db\Dialect\Helper;

use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class SqliteHelper
{
    use DialectTrait;

//    /**
//     * Tests Dialect::modifyColumn
//     *
//     * @param UnitTester $I
//     */
//    public function testModifyColumn(UnitTester $I)
//    {
//        /**
//         * No test - modifying columns not allowed in Sqlite
//         */
//    }
//
//    /**
//     * Tests Dialect::modifyColumn
//     *
//     * @param UnitTester $I
//     */
//    public function testModifyColumn13012(UnitTester $I)
//    {
//        /**
//         * No test - modifying columns not allowed in Sqlite
//         */
//    }



    /**
     * @return array
     */
    protected function getAddIndexFixtures()
    {
        return [
            ['',       'index1',  'CREATE INDEX "index1" ON "table" ("column1")'],
            ['schema', 'index1',  'CREATE INDEX "schema"."index1" ON "table" ("column1")'],
            ['',       'index2',  'CREATE INDEX "index2" ON "table" ("column1", "column2")'],
            ['schema', 'index2',  'CREATE INDEX "schema"."index2" ON "table" ("column1", "column2")'],
        ];
    }

    /**
     * @return array
     */
    protected function getAddPrimaryKeyFixtures(): array
    {
        return [];
    }

    /**
     * @return array
     */
    protected function getColumnDefinitionFixtures(): array
    {
        return [
            ['column1',  'VARCHAR(10)'],
            ['column2',  'INTEGER'],
            ['column3',  'NUMERIC(10,2)'],
            ['column4',  'CHARACTER(100)'],
            ['column5',  'DATE'],
            ['column6',  'DATETIME'],
            ['column7',  'TEXT'],
            ['column8',  'FLOAT'],
            ['column9',  'VARCHAR(10)'],
            ['column10', 'INTEGER'],
            ['column13', 'TIMESTAMP'],
            ['column14', 'TINYBLOB'],
            ['column15', 'MEDIUMBLOB'],
            ['column16', 'BLOB'],
            ['column17', 'LONGBLOB'],
            ['column18', 'TINYINT'],
            ['column19', 'DOUBLE'],
            ['column20', 'DOUBLE UNSIGNED'],
        ];
    }

    /**
     * @return array
     */
    protected function getColumnListFixtures(): array
    {
        return [
            [
                ['column1', 'column2', 'column3', 'column13'],
                '"column1", "column2", "column3", "column13"',
            ],
            [
                ['foo'],
                '"foo"',
            ],
        ];
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
                        new Column('column1', [
                            'type' => Column::TYPE_VARCHAR,
                            'size' => 10
                        ]),
                        new Column('column2', [
                            'type'     => Column::TYPE_INTEGER,
                            'size'     => 18,
                            'unsigned' => true,
                            'notNull'  => false
                        ]),
                    ]
                ],
                rtrim(file_get_contents(PATH_DATA . 'fixtures/Db/sqlite/example1.sql')),
            ],
            'example2' => [
                '',
                [
                    'columns' => [
                        new Column('column2', [
                            'type'     => Column::TYPE_INTEGER,
                            'size'     => 18,
                            'unsigned' => true,
                            'notNull'  => false
                        ]),
                        new Column('column3', [
                            'type'     => Column::TYPE_DECIMAL,
                            'size'     => 10,
                            'scale'    => 2,
                            'unsigned' => false,
                            'notNull'  => true
                        ]),
                        new Column('column1', [
                            'type' => Column::TYPE_VARCHAR,
                            'size' => 10
                        ]),
                    ],
                    'indexes' => [
                        new Index('PRIMARY', ['column3']),
                    ]
                ],
                rtrim(file_get_contents(PATH_DATA . 'fixtures/Db/sqlite/example2.sql')),
            ],
            'example3' => [
                '',
                [
                    'columns' => [
                        new Column('column2', [
                            'type'     => Column::TYPE_INTEGER,
                            'size'     => 18,
                            'unsigned' => true,
                            'notNull'  => false
                        ]),
                        new Column('column3', [
                            'type'     => Column::TYPE_DECIMAL,
                            'size'     => 10,
                            'scale'    => 2,
                            'unsigned' => false,
                            'notNull'  => true
                        ]),
                        new Column('column1', [
                            'type' => Column::TYPE_VARCHAR,
                            'size' => 10
                        ]),
                    ],
                    'indexes' => [
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
                rtrim(file_get_contents(PATH_DATA . 'fixtures/Db/sqlite/example3.sql')),
            ],
            'example4' => [
                '',
                [
                    'columns' => [
                        new Column('column9', [
                            'type'    => Column::TYPE_VARCHAR,
                            'size'    => 10,
                            'default' => 'column9'
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
                rtrim(file_get_contents(PATH_DATA . 'fixtures/Db/sqlite/example4.sql')),
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
                            'notNull'       => false
                        ]),
                        new Column('column13', [
                            'type'    => Column::TYPE_TIMESTAMP,
                            'notNull' => true,
                            'default' => 'CURRENT_TIMESTAMP',
                        ]),
                    ],
                ],
                rtrim(file_get_contents(PATH_DATA . 'fixtures/Db/sqlite/example5.sql')),
            ],
            'example6' => [
                '',
                [
                    'columns' => [
                        new Column('column14', [
                            'type'    => Column::TYPE_TINYBLOB,
                            'notNull' => true
                        ]),
                        new Column('column16', [
                            'type'    => Column::TYPE_BLOB,
                            'notNull' => true
                        ]),
                    ],
                ],
                rtrim(file_get_contents(PATH_DATA . 'fixtures/Db/sqlite/example6.sql')),
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
                rtrim(file_get_contents(PATH_DATA . 'fixtures/Db/sqlite/example7.sql')),
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
                            'unsigned' => true
                        ]),
                    ],
                ],
                rtrim(file_get_contents(PATH_DATA . 'fixtures/Db/sqlite/example8.sql')),
            ],
        ];
    }

    /**
     * @return string
     */
    protected function getCreateSavepointSql(): string
    {
        return 'SAVEPOINT PH_SAVEPOINT_1';
    }

    /**
     * @return array
     */
    protected function getCreateViewFixtures(): array
    {
        return [
            [['sql' => 'SELECT 1'],  null,    'CREATE VIEW "test_view" AS SELECT 1'],
            [['sql' => 'SELECT 1'], 'schema', 'CREATE VIEW "schema"."test_view" AS SELECT 1'],
        ];
    }

    /**
     * @return array
     */
    protected function getDescribeColumnsFixtures(): array
    {
        return [
            ['schema.name.with.dots', "PRAGMA table_info('table')"],
            ['',                      "PRAGMA table_info('table')"],
            ['schema',                "PRAGMA table_info('table')"],
        ];
    }

    /**
     * @return array
     */
    protected function getDescribeReferencesFixtures()
    {
        return [
            [ '',      "PRAGMA foreign_key_list('table')"],
            ['schema', "PRAGMA foreign_key_list('table')"],
        ];
    }

    /**
     * @return array
     */
    protected function getDropColumnFixtures(): array
    {
        return [];
    }

    /**
     * @return array
     */
    protected function getDropForeignKeyFixtures(): array
    {
        return [];
    }

    /**
     * @return array
     */
    protected function getDropIndexFixtures()
    {
        return [
            ['',       'index1', 'DROP INDEX "index1"'],
            ['schema', 'index1', 'DROP INDEX "schema"."index1"'],
        ];
    }

    /**
     * @return array
     */
    protected function getDropPrimaryKeyFixtures(): array
    {
        return [];
    }

    /**
     * @return array
     */
    protected function getDropTableFixtures(): array
    {
        return [
            ['',       true,  'DROP TABLE IF EXISTS "table"'],
            ['schema', true,  'DROP TABLE IF EXISTS "schema"."table"'],
            ['',       false, 'DROP TABLE "table"'],
            ['schema', false, 'DROP TABLE "schema"."table"'],
        ];
    }

    /**
     * @return array
     */
    protected function getDropViewFixtures(): array
    {
        return [
            ['',       false, 'DROP VIEW "test_view"'],
            ['',       true,  'DROP VIEW IF EXISTS "test_view"'],
            ['schema', false, 'DROP VIEW "schema"."test_view"'],
            ['schema', true,  'DROP VIEW IF EXISTS "schema"."test_view"'],
        ];
    }

    /**
     * @return array
     */
    protected function getListViewFixtures(): array
    {
        return  [
            ['',       "SELECT tbl_name FROM sqlite_master WHERE type = 'view' ORDER BY tbl_name"],
            ['schema', "SELECT tbl_name FROM sqlite_master WHERE type = 'view' ORDER BY tbl_name"],
        ];
    }

    /**
     * @return array
     */
    protected function getModifyColumnFixtures(): array
    {
        return [];
    }

    /**
     * @return array
     */
    protected function getModifyColumnFixtures13012(): array
    {
        return [
            new Column('old', ['type' => Column::TYPE_VARCHAR]),
            new Column('new', ['type' => Column::TYPE_VARCHAR]),
        ];
    }

    /**
     * @return string
     */
    protected function getModifyColumnSql(): string
    {
        return '';
    }

    /**
     * @return string
     */
    protected function getReleaseSavepointSql(): string
    {
        return 'RELEASE SAVEPOINT PH_SAVEPOINT_1';
    }

    /**
     * @return string
     */
    protected function getRollbackSavepointSql(): string
    {
        return 'ROLLBACK TO SAVEPOINT PH_SAVEPOINT_1';
    }

    /**
     * @return array
     */
    protected function getTableExistsFixtures(): array
    {
        return [];
    }

    /**
     * @return array
     */
    protected function getTruncateTableFixtures(): array
    {
        return [
            ['',       'DELETE FROM "table"'],
            ['schema', 'DELETE FROM "schema"."table"'],
        ];
    }

    /**
     * @return array
     */
    protected function getViewExistsFixtures(): array
    {
        return [
            [
                null,
                "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END " .
                "FROM sqlite_master WHERE type='view' AND tbl_name='view'"
            ],
            [
                'schema',
                "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END " .
                "FROM sqlite_master WHERE type='view' AND tbl_name='view'"
            ]
        ];
    }

    /**
     * Returns the object for the dialect
     *
     * @return Sqlite
     */
    protected function getDialectObject(): Sqlite
    {
        return new Sqlite();
    }
}
