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

use Phalcon\Db\Column;
use Phalcon\Db\Index;
use Phalcon\Db\Reference;
use Phalcon\Test\Integration\Db\Dialect\Helper\DialectBase;

class PostgresqlCest extends DialectBase
{
    /**
     * @var string
     */
    protected $adapter = 'Postgresql';

    /**
     * @return array
     */
    protected function getAddColumnFixtures(): array
    {
        return [
            [
                '',
                'column1',
                'ALTER TABLE "table" ADD COLUMN "column1" CHARACTER VARYING(10)',
            ],
            [
                'schema',
                'column1',
                'ALTER TABLE "schema"."table" ADD COLUMN "column1" CHARACTER VARYING(10)',
            ],
            [
                '',
                'column2',
                'ALTER TABLE "table" ADD COLUMN "column2" INT',
            ],
            [
                'schema',
                'column2',
                'ALTER TABLE "schema"."table" ADD COLUMN "column2" INT',
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
                'ALTER TABLE "table" ADD COLUMN "column6" TIMESTAMP NOT NULL',
            ],
            [
                'schema',
                'column6',
                'ALTER TABLE "schema"."table" ADD COLUMN "column6" TIMESTAMP NOT NULL',
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
                'ALTER TABLE "table" ADD COLUMN "column9" CHARACTER VARYING(10) DEFAULT \'column9\'',
            ],
            [
                'schema',
                'column9',
                'ALTER TABLE "schema"."table" ADD COLUMN "column9" CHARACTER VARYING(10) DEFAULT \'column9\'',
            ],
            [
                '',
                'column10',
                'ALTER TABLE "table" ADD COLUMN "column10" INT DEFAULT 10',
            ],
            [
                'schema',
                'column10',
                'ALTER TABLE "schema"."table" ADD COLUMN "column10" INT DEFAULT 10',
            ],
            [
                '',
                'column11',
                'ALTER TABLE "table" ADD COLUMN "column11" BIGINT',
            ],
            [
                'schema',
                'column11',
                'ALTER TABLE "schema"."table" ADD COLUMN "column11" BIGINT',
            ],
            [
                '',
                'column12',
                'ALTER TABLE "table" ADD COLUMN "column12" ENUM(\'A\', \'B\', \'C\') DEFAULT \'A\' NOT NULL',
            ],
            [
                'schema',
                'column12',
                'ALTER TABLE "schema"."table" ADD COLUMN "column12" ENUM(\'A\', \'B\', \'C\') DEFAULT \'A\' NOT NULL',
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
        ];
    }

    /**
     * @return array
     */
    protected function getAddForeignKeyFixtures(): array
    {
        return [
            [
                '',
                'fk1',
                'ALTER TABLE "table" ADD CONSTRAINT "fk1" FOREIGN KEY ("column1") ' .
                'REFERENCES "ref_table" ("column2")',
            ],
            [
                'schema',
                'fk1',
                'ALTER TABLE "schema"."table" ADD CONSTRAINT "fk1" FOREIGN KEY ("column1") ' .
                'REFERENCES "ref_table" ("column2")',
            ],
            [
                '',
                'fk2',
                'ALTER TABLE "table" ADD CONSTRAINT "fk2" FOREIGN KEY ("column3", "column4") ' .
                'REFERENCES "ref_table" ("column5", "column6")',
            ],
            [
                'schema',
                'fk2',
                'ALTER TABLE "schema"."table" ADD CONSTRAINT "fk2" FOREIGN KEY ("column3", "column4") ' .
                'REFERENCES "ref_table" ("column5", "column6")',
            ],
            [
                '',
                'fk3',
                'ALTER TABLE "table" ADD CONSTRAINT "fk3" FOREIGN KEY ("column1") ' .
                'REFERENCES "ref_table" ("column2") ON DELETE CASCADE',
            ],
            [
                'schema',
                'fk3',
                'ALTER TABLE "schema"."table" ADD CONSTRAINT "fk3" FOREIGN KEY ("column1") ' .
                'REFERENCES "ref_table" ("column2") ON DELETE CASCADE',
            ],
            [
                '',
                'fk4',
                'ALTER TABLE "table" ADD CONSTRAINT "fk4" FOREIGN KEY ("column1") ' .
                'REFERENCES "ref_table" ("column2") ON UPDATE SET NULL',
            ],
            [
                'schema',
                'fk4',
                'ALTER TABLE "schema"."table" ADD CONSTRAINT "fk4" FOREIGN KEY ("column1") ' .
                'REFERENCES "ref_table" ("column2") ON UPDATE SET NULL',
            ],
            [
                '',
                'fk5',
                'ALTER TABLE "table" ADD CONSTRAINT "fk5" FOREIGN KEY ("column1") ' .
                'REFERENCES "ref_table" ("column2") ON DELETE CASCADE ON UPDATE NO ACTION',
            ],
            [
                'schema',
                'fk5',
                'ALTER TABLE "schema"."table" ADD CONSTRAINT "fk5" FOREIGN KEY ("column1") ' .
                'REFERENCES "ref_table" ("column2") ON DELETE CASCADE ON UPDATE NO ACTION',
            ],
        ];
    }

    /**
     * @return array
     */
    protected function getAddIndexFixtures()
    {
        return [
            ['', 'index1', 'CREATE INDEX "index1" ON "table" ("column1")'],
            ['schema', 'index1', 'CREATE INDEX "index1" ON "schema"."table" ("column1")'],
            ['', 'index2', 'CREATE INDEX "index2" ON "table" ("column1", "column2")'],
            ['schema', 'index2', 'CREATE INDEX "index2" ON "schema"."table" ("column1", "column2")'],
            ['', 'PRIMARY', 'ALTER TABLE "table" ADD CONSTRAINT "table_PRIMARY" PRIMARY KEY ("column3")'],
            ['schema', 'PRIMARY', 'ALTER TABLE "schema"."table" ADD CONSTRAINT "table_PRIMARY" PRIMARY KEY ("column3")'],
            ['', 'index4', 'CREATE UNIQUE INDEX "index4" ON "table" ("column4")'],
            ['schema', 'index4', 'CREATE UNIQUE INDEX "index4" ON "schema"."table" ("column4")'],
        ];
    }

    /**
     * @return array
     */
    protected function getAddPrimaryKeyFixtures(): array
    {
        return [
            ['', 'PRIMARY', 'ALTER TABLE "table" ADD CONSTRAINT "table_PRIMARY" PRIMARY KEY ("column3")'],
            ['schema', 'PRIMARY', 'ALTER TABLE "schema"."table" ADD CONSTRAINT "table_PRIMARY" PRIMARY KEY ("column3")'],
        ];
    }

    /**
     * @return array
     */
    protected function getColumnDefinitionFixtures(): array
    {
        return [
            ['column1', 'CHARACTER VARYING(10)'],
            ['column2', 'INT'],
            ['column3', 'NUMERIC(10,2)'],
            ['column4', 'CHARACTER(100)'],
            ['column5', 'DATE'],
            ['column6', 'TIMESTAMP'],
            ['column7', 'TEXT'],
            ['column8', 'FLOAT'],
            ['column9', 'CHARACTER VARYING(10)'],
            ['column10', 'INT'],
            ['column11', 'BIGINT'],
            ['column12', "ENUM('A', 'B', 'C')"],
            ['column13', 'TIMESTAMP'],
            ['column21', 'BIGSERIAL'],
            ['column22', 'BIGINT'],
            ['column23', 'SERIAL'],
        ];
    }

    /**
     * @return array
     */
    protected function getColumnListFixtures(): array
    {
        return [
            [
                ['column1', 'column2', 'column3'],
                '"column1", "column2", "column3"',
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
                rtrim(file_get_contents(dataFolder('fixtures/Db/postgresql/example1.sql'))),
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
                rtrim(file_get_contents(dataFolder('fixtures/Db/postgresql/example2.sql'))),
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
                rtrim(file_get_contents(dataFolder('fixtures/Db/postgresql/example3.sql'))),
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
                rtrim(file_get_contents(dataFolder('fixtures/Db/postgresql/example4.sql'))),
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
                        new Column('column12', [
                            'type'       => 'ENUM',
                            'typeValues' => ['A', 'B', 'C'],
                            'notNull'    => true,
                            'default'    => 'A',
                            'after'      => 'column11',
                        ]),
                        new Column('column13', [
                            'type'    => Column::TYPE_TIMESTAMP,
                            'notNull' => true,
                            'default' => 'CURRENT_TIMESTAMP',
                        ]),
                    ],
                ],
                rtrim(file_get_contents(dataFolder('fixtures/Db/postgresql/example5.sql'))),
            ],
            'example6' => [
                '',
                [
                    'columns' => [
                        new Column('column14', [
                            'type'          => Column::TYPE_INTEGER,
                            'notNull'       => true,
                            'autoIncrement' => true,
                            'first'         => true,
                        ]),
                        new Column('column15', [
                            'type'    => Column::TYPE_INTEGER,
                            'default' => 5,
                            'notNull' => true,
                            'after'   => 'user_id',
                        ]),
                        new Column('column16', [
                            'type'    => Column::TYPE_VARCHAR,
                            'size'    => 10,
                            'default' => 'column16',
                        ]),
                        new Column('column17', [
                            'type'    => Column::TYPE_BOOLEAN,
                            'default' => "false",
                            'notNull' => true,
                            'after'   => 'track_id',
                        ]),
                        new Column('column18', [
                            'type'    => Column::TYPE_BOOLEAN,
                            'default' => "true",
                            'notNull' => true,
                            'after'   => 'like',
                        ]),
                    ],
                ],
                rtrim(file_get_contents(dataFolder('fixtures/Db/postgresql/example6.sql'))),
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
            [
                'schema.name.with.dots',
                "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, " .
                "c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, " .
                "c.numeric_scale AS NumericScale, c.is_nullable AS Null, " .
                "CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, " .
                "CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' " .
                "THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, " .
                "c.column_default FROM information_schema.columns c " .
                "LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema " .
                "FROM information_schema.table_constraints tc " .
                "INNER JOIN information_schema.key_column_usage kcu on " .
                "(kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name " .
                "and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc " .
                "ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND " .
                "c.table_name=pkc.table_name) WHERE c.table_schema='schema.name.with.dots' AND " .
                "c.table_name='table' ORDER BY c.ordinal_position",
            ],
            [
                null,
                "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, " .
                "c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, " .
                "c.numeric_scale AS NumericScale, c.is_nullable AS Null, " .
                "CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, " .
                "CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' " .
                "THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, " .
                "c.column_default FROM information_schema.columns c " .
                "LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema " .
                "FROM information_schema.table_constraints tc " .
                "INNER JOIN information_schema.key_column_usage kcu on " .
                "(kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and " .
                "kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc " .
                "ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND " .
                "c.table_name=pkc.table_name) WHERE c.table_schema='public' AND c.table_name='table' " .
                "ORDER BY c.ordinal_position",
            ],
            [
                'schema',
                "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, " .
                "c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, " .
                "c.numeric_scale AS NumericScale, c.is_nullable AS Null, " .
                "CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, " .
                "CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' " .
                "THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, " .
                "c.column_default FROM information_schema.columns c " .
                "LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema " .
                "FROM information_schema.table_constraints tc " .
                "INNER JOIN information_schema.key_column_usage kcu on " .
                "(kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and " .
                "kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc " .
                "ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND " .
                "c.table_name=pkc.table_name) WHERE c.table_schema='schema' AND c.table_name='table' " .
                "ORDER BY c.ordinal_position",
            ],
        ];
    }

    /**
     * @return array
     */
    protected function getDescribeReferencesFixtures()
    {
        return [
            [
                null,
                rtrim(file_get_contents(dataFolder('fixtures/Db/postgresql/example7.sql'))),
            ],
            [
                'schema',
                rtrim(file_get_contents(dataFolder('fixtures/Db/postgresql/example8.sql'))),
            ],
        ];
    }

    /**
     * @return array
     */
    protected function getDropColumnFixtures(): array
    {
        return [
            ['', 'column1', 'ALTER TABLE "table" DROP COLUMN "column1"'],
            ['schema', 'column1', 'ALTER TABLE "schema"."table" DROP COLUMN "column1"'],
        ];
    }

    /**
     * @return array
     */
    protected function getDropForeignKeyFixtures(): array
    {
        return [
            ['', 'fk1', 'ALTER TABLE "table" DROP CONSTRAINT "fk1"'],
            ['schema', 'fk1', 'ALTER TABLE "schema"."table" DROP CONSTRAINT "fk1"'],
        ];
    }

    /**
     * @return array
     */
    protected function getDropIndexFixtures()
    {
        return [
            ['', 'index1', 'DROP INDEX "index1"'],
            ['schema', 'index1', 'DROP INDEX "index1"'],
        ];
    }

    /**
     * @return array
     */
    protected function getDropPrimaryKeyFixtures(): array
    {
        return [
            ['', 'ALTER TABLE "table" DROP CONSTRAINT "table_PRIMARY"'],
            ['schema', 'ALTER TABLE "schema"."table" DROP CONSTRAINT "table_PRIMARY"'],
        ];
    }

    /**
     * @return array
     */
    protected function getDropTableFixtures(): array
    {
        return [
            [null, true, 'DROP TABLE IF EXISTS "table"'],
            ['schema', true, 'DROP TABLE IF EXISTS "schema"."table"'],
            [null, false, 'DROP TABLE "table"'],
            ['schema', false, 'DROP TABLE "schema"."table"'],
        ];
    }

    /**
     * @return array
     */
    protected function getDropViewFixtures(): array
    {
        return [
            [null, false, 'DROP VIEW "test_view"'],
            [null, true, 'DROP VIEW IF EXISTS "test_view"'],
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
            [null, "SELECT viewname AS view_name FROM pg_views WHERE schemaname = 'public' ORDER BY view_name"],
            ['schema', "SELECT viewname AS view_name FROM pg_views WHERE schemaname = 'schema' ORDER BY view_name"],
        ];
    }

    /**
     * @return array
     */
    protected function getModifyColumnFixtures(): array
    {
        return [
            [
                '',
                'column1',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column1";' .
                'ALTER TABLE "table" ALTER COLUMN "column1" TYPE CHARACTER VARYING(10);',
            ],
            [
                'schema',
                'column1',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column1";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column1" TYPE CHARACTER VARYING(10);',
            ],
            [
                '',
                'column2',
                'column1',
                'ALTER TABLE "table" RENAME COLUMN "column1" TO "column2";' .
                'ALTER TABLE "table" ALTER COLUMN "column2" TYPE INT;',
            ],
            [
                'schema',
                'column2',
                'column1',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column1" TO "column2";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column2" TYPE INT;',
            ],
            [
                '',
                'column3',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column3";' .
                'ALTER TABLE "table" ALTER COLUMN "column3" TYPE NUMERIC(10,2);' .
                'ALTER TABLE "table" ALTER COLUMN "column3" SET NOT NULL;',
            ],
            [
                'schema',
                'column3',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column3";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column3" TYPE NUMERIC(10,2);' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column3" SET NOT NULL;',
            ],
            [
                '',
                'column4',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column4";' .
                'ALTER TABLE "table" ALTER COLUMN "column4" TYPE CHARACTER(100);' .
                'ALTER TABLE "table" ALTER COLUMN "column4" SET NOT NULL;',
            ],
            [
                'schema',
                'column4',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column4";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column4" TYPE CHARACTER(100);' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column4" SET NOT NULL;',
            ],
            [
                '',
                'column5',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column5";' .
                'ALTER TABLE "table" ALTER COLUMN "column5" TYPE DATE;' .
                'ALTER TABLE "table" ALTER COLUMN "column5" SET NOT NULL;',
            ],
            [
                'schema',
                'column5',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column5";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column5" TYPE DATE;' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column5" SET NOT NULL;',
            ],
            [
                '',
                'column6',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column6";' .
                'ALTER TABLE "table" ALTER COLUMN "column6" TYPE TIMESTAMP;' .
                'ALTER TABLE "table" ALTER COLUMN "column6" SET NOT NULL;',
            ],
            [
                'schema',
                'column6',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column6";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column6" TYPE TIMESTAMP;' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column6" SET NOT NULL;',
            ],
            [
                '',
                'column7',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column7";' .
                'ALTER TABLE "table" ALTER COLUMN "column7" TYPE TEXT;' .
                'ALTER TABLE "table" ALTER COLUMN "column7" SET NOT NULL;',
            ],
            [
                'schema',
                'column7',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column7";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column7" TYPE TEXT;' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column7" SET NOT NULL;',
            ],
            [
                '',
                'column8',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column8";' .
                'ALTER TABLE "table" ALTER COLUMN "column8" TYPE FLOAT;' .
                'ALTER TABLE "table" ALTER COLUMN "column8" SET NOT NULL;',
            ],
            [
                'schema',
                'column8',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column8";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column8" TYPE FLOAT;' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column8" SET NOT NULL;',
            ],
            [
                '',
                'column9',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column9";' .
                'ALTER TABLE "table" ALTER COLUMN "column9" TYPE CHARACTER VARYING(10);' .
                'ALTER TABLE "table" ALTER COLUMN "column9" SET DEFAULT \'column9\'',
            ],
            [
                'schema',
                'column9',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column9";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column9" TYPE CHARACTER VARYING(10);' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column9" SET DEFAULT \'column9\'',
            ],
            [
                '',
                'column10',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column10";' .
                'ALTER TABLE "table" ALTER COLUMN "column10" SET DEFAULT 10',
            ],
            [
                'schema',
                'column10',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column10";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column10" SET DEFAULT 10',
            ],
            [
                '',
                'column11',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column11";' .
                'ALTER TABLE "table" ALTER COLUMN "column11" TYPE BIGINT;',
            ],
            [
                'schema',
                'column11',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column11";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column11" TYPE BIGINT;',
            ],
            [
                '',
                'column12',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column12";' .
                'ALTER TABLE "table" ALTER COLUMN "column12" TYPE ENUM(\'A\', \'B\', \'C\');' .
                'ALTER TABLE "table" ALTER COLUMN "column12" SET NOT NULL;' .
                'ALTER TABLE "table" ALTER COLUMN "column12" SET DEFAULT \'A\'',
            ],
            [
                'schema',
                'column12',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column12";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column12" TYPE ENUM(\'A\', \'B\', \'C\');' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column12" SET NOT NULL;' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column12" SET DEFAULT \'A\'',
            ],
            [
                '',
                'column13',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column13";' .
                'ALTER TABLE "table" ALTER COLUMN "column13" TYPE TIMESTAMP;' .
                'ALTER TABLE "table" ALTER COLUMN "column13" SET NOT NULL;' .
                'ALTER TABLE "table" ALTER COLUMN "column13" SET DEFAULT CURRENT_TIMESTAMP',
            ],
            [
                'schema',
                'column13',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column13";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column13" TYPE TIMESTAMP;' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column13" SET NOT NULL;' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column13" SET DEFAULT CURRENT_TIMESTAMP',
            ],
        ];
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
        return 'ALTER TABLE "database"."table" RENAME COLUMN "old" TO "new";';
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
        return [
            [
                null,
                "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END " .
                "FROM information_schema.tables " .
                "WHERE table_schema = 'public' AND table_name='table'",
            ],
            [
                'schema',
                "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END " .
                "FROM information_schema.tables " .
                "WHERE table_schema = 'schema' AND table_name='table'",
            ],
        ];
    }

    /**
     * @return array
     */
    protected function getTruncateTableFixtures(): array
    {
        return [
            ['', 'TRUNCATE TABLE table'],
            ['schema', 'TRUNCATE TABLE schema.table'],
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
                "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='view' AND schemaname='public'",
            ],
            [
                'schema',
                "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='view' AND schemaname='schema'",
            ],
        ];
    }

//    protected function getReferenceAddForeignKey()
//    {
//        return [
//            'fk1' => new Reference('fk1', [
//                'referencedTable'   => 'foreign_key_parent',
//                'columns'           => ['child_int'],
//                'referencedColumns' => ['refer_int'],
//                'onDelete'          => 'CASCADE',
//                'onUpdate'          => 'RESTRICT',
//            ]),
//            'fk2' => new Reference('', [
//                'referencedTable'   => 'foreign_key_parent',
//                'columns'           => ['child_int'],
//                'referencedColumns' => ['refer_int']
//            ])
//        ];
//    }
//
//    protected function getForeignKey($foreignKeyName)
//    {
//        $sql = rtrim(file_get_contents(dataFolder('fixtures/Db/postgresql/example9.sql'));
//        str_replace('%_FK_%', $foreignKeyName, $sql);
//
//        return $sql;
//    }
//
//    protected function getReferenceDropForeignKey()
//    {
//        return [
//            'fk1' => new Reference('fk1', [
//                'referencedTable'   => 'foreign_key_parent',
//                'columns'           => ['child_int'],
//                'referencedColumns' => ['refer_int'],
//                'onDelete'          => 'CASCADE',
//                'onUpdate'          => 'RESTRICT',
//            ]),
//            'fk2' => new Reference('', [
//                'referencedTable'   => 'foreign_key_parent',
//                'columns'           => ['child_int'],
//                'referencedColumns' => ['refer_int'],
//                'onDelete'          => 'CASCADE',
//                'onUpdate'          => 'RESTRICT',
//            ])
//        ];
//    }
//
//
//    protected function getReferenceObject()
//    {
//        return [
//            [
//                ['test_describereferences' => require PATH_FIXTURES . 'metadata/test_describereference.php']
//            ]
//        ];
//    }
}
