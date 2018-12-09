<?php

namespace Phalcon\Test\Integration\Db\Dialect\Helper;

use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class SqliteHelper
{
    use DialectTrait;

//    /**
//     * Tests Dialect::modifyColumn
//     *
//     * @param IntegrationTester $I
//     */
//    public function testModifyColumn(IntegrationTester $I)
//    {
//        /**
//         * No test - modifying columns not allowed in Sqlite
//         */
//    }
//
//    /**
//     * Tests Dialect::modifyColumn
//     *
//     * @param IntegrationTester $I
//     */
//    public function testModifyColumn13012(IntegrationTester $I)
//    {
//        /**
//         * No test - modifying columns not allowed in Sqlite
//         */
//    }


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
