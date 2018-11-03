<?php

namespace Helper\Dialect;

use Phalcon\Db\Index;
use Phalcon\Db\Column;
use Phalcon\Db\Reference;

/**
 * \Helper\Dialect\SqliteTrait
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Helper\Dialect
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
trait SqliteTrait
{
    protected function getAddIndex()
    {
        return [
            [null,     'index1',  'CREATE INDEX "index1" ON "table" ("column1")'],
            ['schema', 'index1',  'CREATE INDEX "schema"."index1" ON "table" ("column1")'],
            [null,     'index2',  'CREATE INDEX "index2" ON "table" ("column1", "column2")'],
            ['schema', 'index2',  'CREATE INDEX "schema"."index2" ON "table" ("column1", "column2")'],
        ];
    }

    protected function getDropTable()
    {
        return [
            [null,     true,  'DROP TABLE IF EXISTS "table"'],
            ['schema', true,  'DROP TABLE IF EXISTS "schema"."table"'],
            [null,     false, 'DROP TABLE "table"'],
            ['schema', false, 'DROP TABLE "schema"."table"'],
        ];
    }

    protected function getTruncateTable()
    {
        return [
            [null,     'DELETE FROM "table"'],
            ['schema', 'DELETE FROM "schema"."table"'],
        ];
    }

    protected function getAddColumns()
    {
        return [
            [
                null,
                'column1',
                'ALTER TABLE "table" ADD COLUMN "column1" VARCHAR(10)'
            ],
            [
                'schema',
                'column1',
                'ALTER TABLE "schema"."table" ADD COLUMN "column1" VARCHAR(10)'
            ],
            [
                null,
                'column2',
                'ALTER TABLE "table" ADD COLUMN "column2" INTEGER'
            ],
            [
                'schema',
                'column2',
                'ALTER TABLE "schema"."table" ADD COLUMN "column2" INTEGER'
            ],
            [
                null,
                'column3',
                'ALTER TABLE "table" ADD COLUMN "column3" NUMERIC(10,2) NOT NULL'
            ],
            [
                'schema',
                'column3',
                'ALTER TABLE "schema"."table" ADD COLUMN "column3" NUMERIC(10,2) NOT NULL'
            ],
            [
                null,
                'column4',
                'ALTER TABLE "table" ADD COLUMN "column4" CHARACTER(100) NOT NULL'
            ],
            [
                'schema',
                'column4',
                'ALTER TABLE "schema"."table" ADD COLUMN "column4" CHARACTER(100) NOT NULL'
            ],
            [
                null,
                'column5',
                'ALTER TABLE "table" ADD COLUMN "column5" DATE NOT NULL'
            ],
            [
                'schema',
                'column5',
                'ALTER TABLE "schema"."table" ADD COLUMN "column5" DATE NOT NULL'
            ],
            [
                null,
                'column6',
                'ALTER TABLE "table" ADD COLUMN "column6" DATETIME NOT NULL'
            ],
            [
                'schema',
                'column6',
                'ALTER TABLE "schema"."table" ADD COLUMN "column6" DATETIME NOT NULL'
            ],
            [
                null,
                'column7',
                'ALTER TABLE "table" ADD COLUMN "column7" TEXT NOT NULL'
            ],
            [
                'schema',
                'column7',
                'ALTER TABLE "schema"."table" ADD COLUMN "column7" TEXT NOT NULL'
            ],
            [
                null,
                'column8',
                'ALTER TABLE "table" ADD COLUMN "column8" FLOAT NOT NULL'
            ],
            [
                'schema',
                'column8',
                'ALTER TABLE "schema"."table" ADD COLUMN "column8" FLOAT NOT NULL'
            ],
            [
                null,
                'column9',
                'ALTER TABLE "table" ADD COLUMN "column9" VARCHAR(10) DEFAULT "column9"'
            ],
            [
                'schema',
                'column9',
                'ALTER TABLE "schema"."table" ADD COLUMN "column9" VARCHAR(10) DEFAULT "column9"'
            ],
            [
                null,
                'column10',
                'ALTER TABLE "table" ADD COLUMN "column10" INTEGER DEFAULT "10"'
            ],
            [
                'schema',
                'column10',
                'ALTER TABLE "schema"."table" ADD COLUMN "column10" INTEGER DEFAULT "10"'
            ],
            [
                null,
                'column13',
                'ALTER TABLE "table" ADD COLUMN "column13" TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL'
            ],
            [
                'schema',
                'column13',
                'ALTER TABLE "schema"."table" ADD COLUMN "column13" TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL'
            ],
            [
                null,
                'column14',
                'ALTER TABLE "table" ADD COLUMN "column14" TINYBLOB NOT NULL'
            ],
            [
                'schema',
                'column14',
                'ALTER TABLE "schema"."table" ADD COLUMN "column14" TINYBLOB NOT NULL'
            ],
            [
                null,
                'column15',
                'ALTER TABLE "table" ADD COLUMN "column15" MEDIUMBLOB NOT NULL'
            ],
            [
                'schema',
                'column15',
                'ALTER TABLE "schema"."table" ADD COLUMN "column15" MEDIUMBLOB NOT NULL'
            ],
            [
                null,
                'column16',
                'ALTER TABLE "table" ADD COLUMN "column16" BLOB NOT NULL'
            ],
            [
                'schema',
                'column16',
                'ALTER TABLE "schema"."table" ADD COLUMN "column16" BLOB NOT NULL'
            ],
            [
                null,
                'column17',
                'ALTER TABLE "table" ADD COLUMN "column17" LONGBLOB NOT NULL'
            ],
            [
                'schema',
                'column17',
                'ALTER TABLE "schema"."table" ADD COLUMN "column17" LONGBLOB NOT NULL'
            ],
            [
                null,
                'column18',
                'ALTER TABLE "table" ADD COLUMN "column18" TINYINT'
            ],
            [
                'schema',
                'column18',
                'ALTER TABLE "schema"."table" ADD COLUMN "column18" TINYINT'
            ],
            [
                null,
                'column19',
                'ALTER TABLE "table" ADD COLUMN "column19" DOUBLE'
            ],
            [
                'schema',
                'column19',
                'ALTER TABLE "schema"."table" ADD COLUMN "column19" DOUBLE'
            ],
            [
                null,
                'column20',
                'ALTER TABLE "table" ADD COLUMN "column20" DOUBLE UNSIGNED'
            ],
            [
                'schema',
                'column20',
                'ALTER TABLE "schema"."table" ADD COLUMN "column20" DOUBLE UNSIGNED'
            ],
        ];
    }

    protected function getColumnDefinition()
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

    protected function getColumnList()
    {
        return [
            [['column1', 'column2', 'column3', 'column13'], '"column1", "column2", "column3", "column13"'],
            [['foo'],                                       '"foo"'],
        ];
    }

    protected function getDropIndex()
    {
        return [
            [null,     'index1', 'DROP INDEX "index1"'],
            ['schema', 'index1', 'DROP INDEX "schema"."index1"'],
        ];
    }

    protected function getCreateView()
    {
        return [
            [['sql' => 'SELECT 1'],  null,    'CREATE VIEW "test_view" AS SELECT 1'],
            [['sql' => 'SELECT 1'], 'schema', 'CREATE VIEW "schema"."test_view" AS SELECT 1'],
        ];
    }

    protected function getDropView()
    {
        return [
            [null,     false, 'DROP VIEW "test_view"'],
            [null,     true,  'DROP VIEW IF EXISTS "test_view"'],
            ['schema', false, 'DROP VIEW "schema"."test_view"'],
            ['schema', true,  'DROP VIEW IF EXISTS "schema"."test_view"'],
        ];
    }

    protected function getListViews()
    {
        return  [
            [null,     "SELECT tbl_name FROM sqlite_master WHERE type = 'view' ORDER BY tbl_name"],
            ['schema', "SELECT tbl_name FROM sqlite_master WHERE type = 'view' ORDER BY tbl_name"],
        ];
    }

    protected function getViewExists()
    {
        return [
            [
                null,
                "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='view' AND tbl_name='view'"
            ],
            [
                'schema',
                "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='view' AND tbl_name='view'"
            ]
        ];
    }

    protected function getDescribeColumns()
    {
        return [
            ['schema.name.with.dots', "PRAGMA table_info('table')"],
            [null,                    "PRAGMA table_info('table')"],
            ['schema',                "PRAGMA table_info('table')"],
        ];
    }

    protected function getDescribeReferences()
    {
        return [
            [ null,    "PRAGMA foreign_key_list('table')"],
            ['schema', "PRAGMA foreign_key_list('table')"],
        ];
    }

    protected function getCreateTable()
    {
        return [
            'example1' => [
                null,
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
                rtrim(file_get_contents(PATH_FIXTURES . 'sqlite/example1.sql')),
            ],
            'example2' => [
                null,
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
                rtrim(file_get_contents(PATH_FIXTURES . 'sqlite/example2.sql')),
            ],
            'example3' => [
                null,
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
                rtrim(file_get_contents(PATH_FIXTURES . 'sqlite/example3.sql')),
            ],
            'example4' => [
                null,
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
                rtrim(file_get_contents(PATH_FIXTURES . 'sqlite/example4.sql')),
            ],
            'example5' => [
                null,
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
                rtrim(file_get_contents(PATH_FIXTURES . 'sqlite/example5.sql')),
            ],
            'example6' => [
                null,
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
                rtrim(file_get_contents(PATH_FIXTURES . 'sqlite/example6.sql')),
            ],
            'example7' => [
                null,
                [
                    'columns' => [
                        new Column('column18', [
                            'type' => Column::TYPE_BOOLEAN,
                        ]),
                    ],
                ],
                rtrim(file_get_contents(PATH_FIXTURES . 'sqlite/example7.sql')),
            ],
            'example8' => [
                null,
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
                rtrim(file_get_contents(PATH_FIXTURES . 'sqlite/example8.sql')),
            ],
        ];
    }
}
