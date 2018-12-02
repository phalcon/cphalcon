<?php

namespace Helper\Dialect;

use Phalcon\Db\Index;
use Phalcon\Db\Column;
use Phalcon\Db\Reference;

/**
 * \Helper\Dialect\PostgresqlTrait
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
trait PostgresqlTrait
{
    protected function getModifyColumn()
    {
        return [
            [
                null,
                'column1',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column1";ALTER TABLE "table" ALTER COLUMN "column1" TYPE CHARACTER VARYING(10);'
            ],
            [
                'schema',
                'column1',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column1";ALTER TABLE "schema"."table" ALTER COLUMN "column1" TYPE CHARACTER VARYING(10);'
            ],
            [
                null,
                'column2',
                'column1',
                'ALTER TABLE "table" RENAME COLUMN "column1" TO "column2";ALTER TABLE "table" ALTER COLUMN "column2" TYPE INT;'
            ],
            [
                'schema',
                'column2',
                'column1',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column1" TO "column2";ALTER TABLE "schema"."table" ALTER COLUMN "column2" TYPE INT;'
            ],
            [
                null,
                'column3',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column3";ALTER TABLE "table" ALTER COLUMN "column3" TYPE NUMERIC(10,2);ALTER TABLE "table" ALTER COLUMN "column3" SET NOT NULL;'
            ],
            [
                'schema',
                'column3',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column3";ALTER TABLE "schema"."table" ALTER COLUMN "column3" TYPE NUMERIC(10,2);ALTER TABLE "schema"."table" ALTER COLUMN "column3" SET NOT NULL;'
            ],
            [
                null,
                'column4',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column4";ALTER TABLE "table" ALTER COLUMN "column4" TYPE CHARACTER(100);ALTER TABLE "table" ALTER COLUMN "column4" SET NOT NULL;'
            ],
            [
                'schema',
                'column4',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column4";ALTER TABLE "schema"."table" ALTER COLUMN "column4" TYPE CHARACTER(100);ALTER TABLE "schema"."table" ALTER COLUMN "column4" SET NOT NULL;'
            ],
            [
                null,
                'column5',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column5";ALTER TABLE "table" ALTER COLUMN "column5" TYPE DATE;ALTER TABLE "table" ALTER COLUMN "column5" SET NOT NULL;'
            ],
            [
                'schema',
                'column5',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column5";ALTER TABLE "schema"."table" ALTER COLUMN "column5" TYPE DATE;ALTER TABLE "schema"."table" ALTER COLUMN "column5" SET NOT NULL;'
            ],
            [
                null,
                'column6',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column6";ALTER TABLE "table" ALTER COLUMN "column6" TYPE TIMESTAMP;ALTER TABLE "table" ALTER COLUMN "column6" SET NOT NULL;'
            ],
            [
                'schema',
                'column6',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column6";ALTER TABLE "schema"."table" ALTER COLUMN "column6" TYPE TIMESTAMP;ALTER TABLE "schema"."table" ALTER COLUMN "column6" SET NOT NULL;'
            ],
            [
                null,
                'column7',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column7";ALTER TABLE "table" ALTER COLUMN "column7" TYPE TEXT;ALTER TABLE "table" ALTER COLUMN "column7" SET NOT NULL;'
            ],
            [
                'schema',
                'column7',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column7";ALTER TABLE "schema"."table" ALTER COLUMN "column7" TYPE TEXT;ALTER TABLE "schema"."table" ALTER COLUMN "column7" SET NOT NULL;'
            ],
            [
                null,
                'column8',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column8";ALTER TABLE "table" ALTER COLUMN "column8" TYPE FLOAT;ALTER TABLE "table" ALTER COLUMN "column8" SET NOT NULL;'
            ],
            [
                'schema',
                'column8',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column8";ALTER TABLE "schema"."table" ALTER COLUMN "column8" TYPE FLOAT;ALTER TABLE "schema"."table" ALTER COLUMN "column8" SET NOT NULL;'
            ],
            [
                null,
                'column9',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column9";ALTER TABLE "table" ALTER COLUMN "column9" TYPE CHARACTER VARYING(10);ALTER TABLE "table" ALTER COLUMN "column9" SET DEFAULT \'column9\''
            ],
            [
                'schema',
                'column9',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column9";ALTER TABLE "schema"."table" ALTER COLUMN "column9" TYPE CHARACTER VARYING(10);ALTER TABLE "schema"."table" ALTER COLUMN "column9" SET DEFAULT \'column9\''
            ],
            [
                null,
                'column10',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column10";ALTER TABLE "table" ALTER COLUMN "column10" SET DEFAULT 10'
            ],
            [
                'schema',
                'column10',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column10";ALTER TABLE "schema"."table" ALTER COLUMN "column10" SET DEFAULT 10'
            ],
            [
                null,
                'column11',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column11";ALTER TABLE "table" ALTER COLUMN "column11" TYPE BIGINT;'
            ],
            [
                'schema',
                'column11',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column11";ALTER TABLE "schema"."table" ALTER COLUMN "column11" TYPE BIGINT;'
            ],
            [
                null,
                'column12',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column12";ALTER TABLE "table" ALTER COLUMN "column12" TYPE ENUM(\'A\', \'B\', \'C\');ALTER TABLE "table" ALTER COLUMN "column12" SET NOT NULL;ALTER TABLE "table" ALTER COLUMN "column12" SET DEFAULT \'A\''
            ],
            [
                'schema',
                'column12',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column12";ALTER TABLE "schema"."table" ALTER COLUMN "column12" TYPE ENUM(\'A\', \'B\', \'C\');ALTER TABLE "schema"."table" ALTER COLUMN "column12" SET NOT NULL;ALTER TABLE "schema"."table" ALTER COLUMN "column12" SET DEFAULT \'A\''
            ],
            [
                null,
                'column13',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column13";ALTER TABLE "table" ALTER COLUMN "column13" TYPE TIMESTAMP;ALTER TABLE "table" ALTER COLUMN "column13" SET NOT NULL;ALTER TABLE "table" ALTER COLUMN "column13" SET DEFAULT CURRENT_TIMESTAMP'
            ],
            [
                'schema',
                'column13',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column13";ALTER TABLE "schema"."table" ALTER COLUMN "column13" TYPE TIMESTAMP;ALTER TABLE "schema"."table" ALTER COLUMN "column13" SET NOT NULL;ALTER TABLE "schema"."table" ALTER COLUMN "column13" SET DEFAULT CURRENT_TIMESTAMP'
            ],
        ];
    }

    protected function getAddIndex()
    {
        return [
            [null,     'index1',  'CREATE INDEX "index1" ON "table" ("column1")'],
            ['schema', 'index1',  'CREATE INDEX "index1" ON "schema"."table" ("column1")'],
            [null,     'index2',  'CREATE INDEX "index2" ON "table" ("column1", "column2")'],
            ['schema', 'index2',  'CREATE INDEX "index2" ON "schema"."table" ("column1", "column2")'],
            [null,     'PRIMARY', 'ALTER TABLE "table" ADD CONSTRAINT "PRIMARY" PRIMARY KEY ("column3")'],
            ['schema', 'PRIMARY', 'ALTER TABLE "schema"."table" ADD CONSTRAINT "PRIMARY" PRIMARY KEY ("column3")'],
            [null,     'index4',  'CREATE UNIQUE INDEX "index4" ON "table" ("column4")'],
            ['schema', 'index4',  'CREATE UNIQUE INDEX "index4" ON "schema"."table" ("column4")'],
        ];
    }

    protected function getDropColumn()
    {
        return [
            [null,     'column1', 'ALTER TABLE "table" DROP COLUMN "column1"'],
            ['schema', 'column1', 'ALTER TABLE "schema"."table" DROP COLUMN "column1"'],
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
            [null,     'TRUNCATE TABLE table'],
            ['schema', 'TRUNCATE TABLE schema.table'],
        ];
    }

    protected function getAddColumns()
    {
        return [
            [
                null,
                'column1',
                'ALTER TABLE "table" ADD COLUMN "column1" CHARACTER VARYING(10) NULL'
            ],
            [
                'schema',
                'column1',
                'ALTER TABLE "schema"."table" ADD COLUMN "column1" CHARACTER VARYING(10) NULL'
            ],
            [
                null,
                'column2',
                'ALTER TABLE "table" ADD COLUMN "column2" INT NULL'
            ],
            [
                'schema',
                'column2',
                'ALTER TABLE "schema"."table" ADD COLUMN "column2" INT NULL'
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
                'ALTER TABLE "table" ADD COLUMN "column6" TIMESTAMP NOT NULL'
            ],
            [
                'schema',
                'column6',
                'ALTER TABLE "schema"."table" ADD COLUMN "column6" TIMESTAMP NOT NULL'
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
                'ALTER TABLE "table" ADD COLUMN "column9" CHARACTER VARYING(10) DEFAULT \'column9\' NULL'
            ],
            [
                'schema',
                'column9',
                'ALTER TABLE "schema"."table" ADD COLUMN "column9" CHARACTER VARYING(10) DEFAULT \'column9\' NULL'
            ],
            [
                null,
                'column10',
                'ALTER TABLE "table" ADD COLUMN "column10" INT DEFAULT 10 NULL'
            ],
            [
                'schema',
                'column10',
                'ALTER TABLE "schema"."table" ADD COLUMN "column10" INT DEFAULT 10 NULL'
            ],
            [
                null,
                'column11',
                'ALTER TABLE "table" ADD COLUMN "column11" BIGINT NULL'
            ],
            [
                'schema',
                'column11',
                'ALTER TABLE "schema"."table" ADD COLUMN "column11" BIGINT NULL'
            ],
            [
                null,
                'column12',
                'ALTER TABLE "table" ADD COLUMN "column12" ENUM(\'A\', \'B\', \'C\') DEFAULT \'A\' NOT NULL'
            ],
            [
                'schema',
                'column12',
                'ALTER TABLE "schema"."table" ADD COLUMN "column12" ENUM(\'A\', \'B\', \'C\') DEFAULT \'A\' NOT NULL'
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
        ];
    }

    protected function getColumnDefinition()
    {
        return [
            ['column1',  'CHARACTER VARYING(10)'],
            ['column2',  'INT'],
            ['column3',  'NUMERIC(10,2)'],
            ['column4',  'CHARACTER(100)'],
            ['column5',  'DATE'],
            ['column6',  'TIMESTAMP'],
            ['column7',  'TEXT'],
            ['column8',  'FLOAT'],
            ['column9',  'CHARACTER VARYING(10)'],
            ['column10', 'INT'],
            ['column11', 'BIGINT'],
            ['column12', "ENUM('A', 'B', 'C')"],
            ['column13', 'TIMESTAMP'],
            ['column21', 'BIGSERIAL'],
            ['column22', 'BIGINT'],
            ['column23', 'SERIAL'],
        ];
    }

    protected function getColumnList()
    {
        return [
            [['column1', 'column2', 'column3'], '"column1", "column2", "column3"'],
            [['foo'],                           '"foo"'],
        ];
    }

    protected function getDropIndex()
    {
        return [
            [null,     'index1', 'DROP INDEX "index1"'],
            ['schema', 'index1', 'DROP INDEX "index1"'],
        ];
    }

    protected function getAddPrimaryKey()
    {
        return [
            [null,     'PRIMARY', 'ALTER TABLE "table" ADD CONSTRAINT "PRIMARY" PRIMARY KEY ("column3")'],
            ['schema', 'PRIMARY', 'ALTER TABLE "schema"."table" ADD CONSTRAINT "PRIMARY" PRIMARY KEY ("column3")'],
        ];
    }

    protected function getDropPrimaryKey()
    {
        return [
            [null, 'ALTER TABLE "table" DROP CONSTRAINT "PRIMARY"'],
            ['schema', 'ALTER TABLE "schema"."table" DROP CONSTRAINT "PRIMARY"'],
        ];
    }

    protected function getAddForeignKey()
    {
        return [
            [
                null,
                'fk1',
                'ALTER TABLE "table" ADD CONSTRAINT "fk1" FOREIGN KEY ("column1") REFERENCES "ref_table" ("column2")'
            ],
            [
                'schema',
                'fk1',
                'ALTER TABLE "schema"."table" ADD CONSTRAINT "fk1" FOREIGN KEY ("column1") REFERENCES "ref_table" ("column2")'
            ],
            [
                null,
                'fk2',
                'ALTER TABLE "table" ADD CONSTRAINT "fk2" FOREIGN KEY ("column3", "column4") REFERENCES "ref_table" ("column5", "column6")'
            ],
            [
                'schema',
                'fk2',
                'ALTER TABLE "schema"."table" ADD CONSTRAINT "fk2" FOREIGN KEY ("column3", "column4") REFERENCES "ref_table" ("column5", "column6")'
            ],
            [
                null,
                'fk3',
                'ALTER TABLE "table" ADD CONSTRAINT "fk3" FOREIGN KEY ("column1") REFERENCES "ref_table" ("column2") ON DELETE CASCADE'
            ],
            [
                'schema',
                'fk3',
                'ALTER TABLE "schema"."table" ADD CONSTRAINT "fk3" FOREIGN KEY ("column1") REFERENCES "ref_table" ("column2") ON DELETE CASCADE'
            ],
            [
                null,
                'fk4',
                'ALTER TABLE "table" ADD CONSTRAINT "fk4" FOREIGN KEY ("column1") REFERENCES "ref_table" ("column2") ON UPDATE SET NULL'
            ],
            [
                'schema',
                'fk4',
                'ALTER TABLE "schema"."table" ADD CONSTRAINT "fk4" FOREIGN KEY ("column1") REFERENCES "ref_table" ("column2") ON UPDATE SET NULL'
            ],
            [
                null,
                'fk5',
                'ALTER TABLE "table" ADD CONSTRAINT "fk5" FOREIGN KEY ("column1") REFERENCES "ref_table" ("column2") ON DELETE CASCADE ON UPDATE NO ACTION'
            ],
            [
                'schema',
                'fk5',
                'ALTER TABLE "schema"."table" ADD CONSTRAINT "fk5" FOREIGN KEY ("column1") REFERENCES "ref_table" ("column2") ON DELETE CASCADE ON UPDATE NO ACTION'
            ],
        ];
    }

    protected function getDropForeignKey()
    {
        return [
            [null,     'fk1', 'ALTER TABLE "table" DROP CONSTRAINT "fk1"'],
            ['schema', 'fk1', 'ALTER TABLE "schema"."table" DROP CONSTRAINT "fk1"'],
        ];
    }

    protected function getReferenceAddForeignKey()
    {
        return [
            'fk1' => new Reference('fk1', [
                'referencedTable'   => 'foreign_key_parent',
                'columns'           => ['child_int'],
                'referencedColumns' => ['refer_int'],
                'onDelete'          => 'CASCADE',
                'onUpdate'          => 'RESTRICT',
            ]),
            'fk2' => new Reference('', [
                'referencedTable'   => 'foreign_key_parent',
                'columns'           => ['child_int'],
                'referencedColumns' => ['refer_int']
            ])
        ];
    }

    protected function getForeignKey($foreignKeyName)
    {
        $sql = "SELECT COUNT(tc.constraint_name)
                FROM information_schema.table_constraints tc
                  INNER JOIN information_schema.key_column_usage kcu
                    ON tc.constraint_catalog = kcu.constraint_catalog
                       AND tc.constraint_schema = kcu.constraint_schema
                       AND tc.constraint_name = kcu.constraint_name
                  INNER JOIN information_schema.referential_constraints rc
                    ON tc.constraint_catalog = rc.constraint_catalog
                       AND tc.constraint_schema = rc.constraint_schema
                       AND tc.constraint_name = rc.constraint_name
                       AND  tc.constraint_type = 'FOREIGN KEY'
                  INNER JOIN information_schema.constraint_column_usage ccu
                    ON rc.unique_constraint_catalog = ccu.constraint_catalog
                       AND rc.unique_constraint_schema = ccu.constraint_schema
                       AND rc.unique_constraint_name = ccu.constraint_name
                WHERE tc.constraint_name = '$foreignKeyName'
                      AND rc.update_rule = 'RESTRICT'
                      AND rc.delete_rule = 'CASCADE'";

        return $sql;
    }

    protected function getReferenceDropForeignKey()
    {
        return [
            'fk1' => new Reference('fk1', [
                'referencedTable'   => 'foreign_key_parent',
                'columns'           => ['child_int'],
                'referencedColumns' => ['refer_int'],
                'onDelete'          => 'CASCADE',
                'onUpdate'          => 'RESTRICT',
            ]),
            'fk2' => new Reference('', [
                'referencedTable'   => 'foreign_key_parent',
                'columns'           => ['child_int'],
                'referencedColumns' => ['refer_int'],
                'onDelete'          => 'CASCADE',
                'onUpdate'          => 'RESTRICT',
            ])
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

    protected function getViewExists()
    {
        return [
            [
                null,
                "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='view' AND schemaname='public'"
            ],
            [
                'schema',
                "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='view' AND schemaname='schema'"
            ]
        ];
    }

    protected function getListViews()
    {
        return  [
            [null,     "SELECT viewname AS view_name FROM pg_views WHERE schemaname = 'public' ORDER BY view_name"],
            ['schema', "SELECT viewname AS view_name FROM pg_views WHERE schemaname = 'schema' ORDER BY view_name"],
        ];
    }

    protected function getDescribeColumns()
    {
        return [
            [
                'schema.name.with.dots',
                "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.numeric_scale AS NumericScale, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, c.column_default FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) WHERE c.table_schema='schema.name.with.dots' AND c.table_name='table' ORDER BY c.ordinal_position"
            ],
            [
                null,
                "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.numeric_scale AS NumericScale, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, c.column_default FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) WHERE c.table_schema='public' AND c.table_name='table' ORDER BY c.ordinal_position"
            ],
            [
                'schema',
                "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.numeric_scale AS NumericScale, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, c.column_default FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) WHERE c.table_schema='schema' AND c.table_name='table' ORDER BY c.ordinal_position"
            ],
        ];
    }

    protected function getDescribeReferences()
    {
        return [
            [
                null,
                "SELECT DISTINCT tc.table_name as TABLE_NAME, kcu.column_name as COLUMN_NAME, tc.constraint_name as CONSTRAINT_NAME, tc.table_catalog as REFERENCED_TABLE_SCHEMA, ccu.table_name AS REFERENCED_TABLE_NAME, ccu.column_name AS REFERENCED_COLUMN_NAME FROM information_schema.table_constraints AS tc JOIN information_schema.key_column_usage AS kcu ON tc.constraint_name = kcu.constraint_name JOIN information_schema.constraint_column_usage AS ccu ON ccu.constraint_name = tc.constraint_name WHERE constraint_type = 'FOREIGN KEY' AND tc.table_schema = 'public' AND tc.table_name='table'"
            ],
            [
                'schema',
                "SELECT DISTINCT tc.table_name as TABLE_NAME, kcu.column_name as COLUMN_NAME, tc.constraint_name as CONSTRAINT_NAME, tc.table_catalog as REFERENCED_TABLE_SCHEMA, ccu.table_name AS REFERENCED_TABLE_NAME, ccu.column_name AS REFERENCED_COLUMN_NAME FROM information_schema.table_constraints AS tc JOIN information_schema.key_column_usage AS kcu ON tc.constraint_name = kcu.constraint_name JOIN information_schema.constraint_column_usage AS ccu ON ccu.constraint_name = tc.constraint_name WHERE constraint_type = 'FOREIGN KEY' AND tc.table_schema = 'schema' AND tc.table_name='table'"
            ]
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
                rtrim(file_get_contents(PATH_FIXTURES . 'postgresql/example1.sql')),
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
                rtrim(file_get_contents(PATH_FIXTURES . 'postgresql/example2.sql')),
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
                rtrim(file_get_contents(PATH_FIXTURES . 'postgresql/example3.sql')),
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
                rtrim(file_get_contents(PATH_FIXTURES . 'postgresql/example4.sql')),
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
                        new Column('column12', [
                            'type'       => 'ENUM',
                            'typeValues' => ['A', 'B', 'C'],
                            'notNull'    => true,
                            'default'    => 'A',
                            'after'      => 'column11'
                        ]),
                        new Column('column13', [
                            'type'    => Column::TYPE_TIMESTAMP,
                            'notNull' => true,
                            'default' => 'CURRENT_TIMESTAMP',
                        ]),
                    ],
                ],
                rtrim(file_get_contents(PATH_FIXTURES . 'postgresql/example5.sql')),
            ],
            'example6' => [
                null,
                [
                    'columns' => [
                        new Column('column14', [
                            'type' => Column::TYPE_INTEGER,
                            'notNull' => true,
                            'autoIncrement' => true,
                            'first' => true
                        ]),
                        new Column('column15', [
                            'type' => Column::TYPE_INTEGER,
                            'default' => 5,
                            'notNull' => true,
                            'after' => 'user_id'
                        ]),
                        new Column('column16', [
                            'type'    => Column::TYPE_VARCHAR,
                            'size'    => 10,
                            'default' => 'column16'
                        ]),
                        new Column('column17', [
                            'type' => Column::TYPE_BOOLEAN,
                            'default' => "false",
                            'notNull' => true,
                            'after' => 'track_id'
                        ]),
                        new Column('column18', [
                            'type' => Column::TYPE_BOOLEAN,
                            'default' => "true",
                            'notNull' => true,
                            'after' => 'like'
                        ]),
                    ],
                ],
                rtrim(file_get_contents(PATH_FIXTURES . 'postgresql/example6.sql')),
            ],
        ];
    }
}
