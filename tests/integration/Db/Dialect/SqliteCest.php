<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Db\Dialect;

use IntegrationTester;
use Phalcon\Db\Column;
use Phalcon\Db\Index;
use Phalcon\Db\Reference;
use Phalcon\Test\Integration\Db\Dialect\Helper\DialectBase;

class SqliteCest extends DialectBase
{
    /**
     * @var string
     */
    protected $adapter = 'Sqlite';

    /**
     * Tests Dialect::modifyColumn
     *
     * @param IntegrationTester $I
     */
    public function testModifyColumn(IntegrationTester $I)
    {
        /**
         * No test - modifying columns not allowed in Sqlite
         */
    }

    /**
     * Tests Dialect::modifyColumn
     *
     * @param IntegrationTester $I
     */
    public function testModifyColumn13012(IntegrationTester $I)
    {
        /**
         * No test - modifying columns not allowed in Sqlite
         */
    }

    /**
     * @return array
     */
    protected function getAddColumnFixtures(): array
    {
        return [
            [
                '',
                'column1',
                'ALTER TABLE "table" ADD COLUMN "column1" VARCHAR(10)',
            ],
            [
                'schema',
                'column1',
                'ALTER TABLE "schema"."table" ADD COLUMN "column1" VARCHAR(10)',
            ],
            [
                '',
                'column2',
                'ALTER TABLE "table" ADD COLUMN "column2" INTEGER',
            ],
            [
                'schema',
                'column2',
                'ALTER TABLE "schema"."table" ADD COLUMN "column2" INTEGER',
            ],
            [
                '',
                'column3',
                'ALTER TABLE "table" ADD COLUMN "column3" NUMERIC(10,2) NOT NULL',
            ],
            [
                'schema',
                'column3',
                'ALTER TABLE "schema"."table" ADD COLUMN "column3" NUMERIC(10,2) NOT NULL',
            ],
            [
                '',
                'column4',
                'ALTER TABLE "table" ADD COLUMN "column4" CHARACTER(100) NOT NULL',
            ],
            [
                'schema',
                'column4',
                'ALTER TABLE "schema"."table" ADD COLUMN "column4" CHARACTER(100) NOT NULL',
            ],
            [
                '',
                'column5',
                'ALTER TABLE "table" ADD COLUMN "column5" DATE NOT NULL',
            ],
            [
                'schema',
                'column5',
                'ALTER TABLE "schema"."table" ADD COLUMN "column5" DATE NOT NULL',
            ],
            [
                '',
                'column6',
                'ALTER TABLE "table" ADD COLUMN "column6" DATETIME NOT NULL',
            ],
            [
                'schema',
                'column6',
                'ALTER TABLE "schema"."table" ADD COLUMN "column6" DATETIME NOT NULL',
            ],
            [
                '',
                'column7',
                'ALTER TABLE "table" ADD COLUMN "column7" TEXT NOT NULL',
            ],
            [
                'schema',
                'column7',
                'ALTER TABLE "schema"."table" ADD COLUMN "column7" TEXT NOT NULL',
            ],
            [
                '',
                'column8',
                'ALTER TABLE "table" ADD COLUMN "column8" FLOAT NOT NULL',
            ],
            [
                'schema',
                'column8',
                'ALTER TABLE "schema"."table" ADD COLUMN "column8" FLOAT NOT NULL',
            ],
            [
                '',
                'column9',
                'ALTER TABLE "table" ADD COLUMN "column9" VARCHAR(10) DEFAULT "column9"',
            ],
            [
                'schema',
                'column9',
                'ALTER TABLE "schema"."table" ADD COLUMN "column9" VARCHAR(10) DEFAULT "column9"',
            ],
            [
                '',
                'column10',
                'ALTER TABLE "table" ADD COLUMN "column10" INTEGER DEFAULT "10"',
            ],
            [
                'schema',
                'column10',
                'ALTER TABLE "schema"."table" ADD COLUMN "column10" INTEGER DEFAULT "10"',
            ],
            [
                '',
                'column13',
                'ALTER TABLE "table" ADD COLUMN "column13" TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL',
            ],
            [
                'schema',
                'column13',
                'ALTER TABLE "schema"."table" ADD COLUMN "column13" TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL',
            ],
            [
                '',
                'column14',
                'ALTER TABLE "table" ADD COLUMN "column14" TINYBLOB NOT NULL',
            ],
            [
                'schema',
                'column14',
                'ALTER TABLE "schema"."table" ADD COLUMN "column14" TINYBLOB NOT NULL',
            ],
            [
                '',
                'column15',
                'ALTER TABLE "table" ADD COLUMN "column15" MEDIUMBLOB NOT NULL',
            ],
            [
                'schema',
                'column15',
                'ALTER TABLE "schema"."table" ADD COLUMN "column15" MEDIUMBLOB NOT NULL',
            ],
            [
                '',
                'column16',
                'ALTER TABLE "table" ADD COLUMN "column16" BLOB NOT NULL',
            ],
            [
                'schema',
                'column16',
                'ALTER TABLE "schema"."table" ADD COLUMN "column16" BLOB NOT NULL',
            ],
            [
                '',
                'column17',
                'ALTER TABLE "table" ADD COLUMN "column17" LONGBLOB NOT NULL',
            ],
            [
                'schema',
                'column17',
                'ALTER TABLE "schema"."table" ADD COLUMN "column17" LONGBLOB NOT NULL',
            ],
            [
                '',
                'column18',
                'ALTER TABLE "table" ADD COLUMN "column18" TINYINT',
            ],
            [
                'schema',
                'column18',
                'ALTER TABLE "schema"."table" ADD COLUMN "column18" TINYINT',
            ],
            [
                '',
                'column19',
                'ALTER TABLE "table" ADD COLUMN "column19" DOUBLE',
            ],
            [
                'schema',
                'column19',
                'ALTER TABLE "schema"."table" ADD COLUMN "column19" DOUBLE',
            ],
            [
                '',
                'column20',
                'ALTER TABLE "table" ADD COLUMN "column20" DOUBLE UNSIGNED',
            ],
            [
                'schema',
                'column20',
                'ALTER TABLE "schema"."table" ADD COLUMN "column20" DOUBLE UNSIGNED',
            ],
        ];
    }

    /**
     * @return array
     */
    protected function getAddForeignKeyFixtures(): array
    {
        return [];
    }

    /**
     * @return array
     */
    protected function getAddIndexFixtures()
    {
        return [
            ['', 'index1', 'CREATE INDEX "index1" ON "table" ("column1")'],
            ['schema', 'index1', 'CREATE INDEX "schema"."index1" ON "table" ("column1")'],
            ['', 'index2', 'CREATE INDEX "index2" ON "table" ("column1", "column2")'],
            ['schema', 'index2', 'CREATE INDEX "schema"."index2" ON "table" ("column1", "column2")'],
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
            ['column1', 'VARCHAR(10)'],
            ['column2', 'INTEGER'],
            ['column3', 'NUMERIC(10,2)'],
            ['column4', 'CHARACTER(100)'],
            ['column5', 'DATE'],
            ['column6', 'DATETIME'],
            ['column7', 'TEXT'],
            ['column8', 'FLOAT'],
            ['column9', 'VARCHAR(10)'],
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
                            'size' => 10,
                        ]),
                        new Column('column2', [
                            'type'     => Column::TYPE_INTEGER,
                            'size'     => 18,
                            'unsigned' => true,
                            'notNull'  => false,
                        ]),
                    ],
                ],
                rtrim(file_get_contents(dataFolder('fixtures/Db/sqlite/example1.sql'))),
            ],
            'example2' => [
                '',
                [
                    'columns' => [
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
                    'indexes' => [
                        new Index('PRIMARY', ['column3']),
                    ],
                ],
                rtrim(file_get_contents(dataFolder('fixtures/Db/sqlite/example2.sql'))),
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
                rtrim(file_get_contents(dataFolder('fixtures/Db/sqlite/example3.sql'))),
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
                rtrim(file_get_contents(dataFolder('fixtures/Db/sqlite/example4.sql'))),
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
                rtrim(file_get_contents(dataFolder('fixtures/Db/sqlite/example5.sql'))),
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
                rtrim(file_get_contents(dataFolder('fixtures/Db/sqlite/example6.sql'))),
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
                rtrim(file_get_contents(dataFolder('fixtures/Db/sqlite/example7.sql'))),
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
                rtrim(file_get_contents(dataFolder('fixtures/Db/sqlite/example8.sql'))),
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
            [['sql' => 'SELECT 1'], null, 'CREATE VIEW "test_view" AS SELECT 1'],
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
            ['', "PRAGMA table_info('table')"],
            ['schema', "PRAGMA table_info('table')"],
        ];
    }

    /**
     * @return array
     */
    protected function getDescribeReferencesFixtures()
    {
        return [
            ['', "PRAGMA foreign_key_list('table')"],
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
            ['', 'index1', 'DROP INDEX "index1"'],
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
            ['', true, 'DROP TABLE IF EXISTS "table"'],
            ['schema', true, 'DROP TABLE IF EXISTS "schema"."table"'],
            ['', false, 'DROP TABLE "table"'],
            ['schema', false, 'DROP TABLE "schema"."table"'],
        ];
    }

    /**
     * @return array
     */
    protected function getDropViewFixtures(): array
    {
        return [
            ['', false, 'DROP VIEW "test_view"'],
            ['', true, 'DROP VIEW IF EXISTS "test_view"'],
            ['schema', false, 'DROP VIEW "schema"."test_view"'],
            ['schema', true, 'DROP VIEW IF EXISTS "schema"."test_view"'],
        ];
    }

    /**
     * @return array
     */
    protected function getListViewFixtures(): array
    {
        return [
            ['', "SELECT tbl_name FROM sqlite_master WHERE type = 'view' ORDER BY tbl_name"],
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
            ['', 'DELETE FROM "table"'],
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
                "FROM sqlite_master WHERE type='view' AND tbl_name='view'",
            ],
            [
                'schema',
                "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END " .
                "FROM sqlite_master WHERE type='view' AND tbl_name='view'",
            ],
        ];
    }
}
