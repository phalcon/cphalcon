<?php

namespace Phalcon\Test\Integration\Db\Dialect\Helper;

use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class PostgresqlHelper
{
    use DialectTrait;


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
            ['', 'ALTER TABLE "table" DROP CONSTRAINT "PRIMARY"'],
            ['schema', 'ALTER TABLE "schema"."table" DROP CONSTRAINT "PRIMARY"'],
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

    /**
     * Returns the object for the dialect
     *
     * @return Postgresql
     */
    protected function getDialectObject(): Postgresql
    {
        return new Postgresql();
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
