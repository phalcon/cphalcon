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

namespace Phalcon\Tests\Database\Db\Dialect;

use Phalcon\Db\Column;
use Phalcon\Db\Dialect\Mysql;
use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

final class EscapeIntrospectionTest extends AbstractDatabaseTestCase
{
    /**
     * @return array<array{class-string}>
     */
    public static function getDialects(): array
    {
        return [
            [Mysql::class],
            [Postgresql::class],
            [Sqlite::class],
        ];
    }

    /**
     * ENUM/SET values are written into single-quoted SQL literals, so a quote
     * in a value has to be escaped (doubled) or it breaks out of the literal
     * (CWE-89).
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getDialects')]
    public function testDbDialectGetColumnDefinitionEscapesTypeValues(
        string $dialectClass
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $arrayColumn = new Column(
            'status',
            [
                'type'       => 'ENUM',
                'typeValues' => ["rob'ots", "kn'ives"],
            ]
        );
        $scalarColumn = new Column(
            'status',
            [
                'type'       => 'SET',
                'typeValues' => "rob'ots",
            ]
        );

        $this->assertSame(
            "ENUM('rob''ots', 'kn''ives')",
            $dialect->getColumnDefinition($arrayColumn)
        );
        $this->assertSame(
            "SET('rob''ots')",
            $dialect->getColumnDefinition($scalarColumn)
        );
    }

    /**
     * The schema-introspection helpers concatenate the table/schema name into a
     * single-quoted SQL literal, so a quote in the name has to be escaped
     * (doubled) or it breaks out of the literal (CWE-89).
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getDialects')]
    public function testDbDialectIntrospectionEscapesQuotes(string $dialectClass): void
    {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $payload = "a'b";

        $this->assertStringContainsString(
            "a''b",
            $dialect->tableExists($payload, $payload)
        );
        $this->assertStringContainsString(
            "a''b",
            $dialect->viewExists($payload, $payload)
        );
        $this->assertStringContainsString(
            "a''b",
            $dialect->describeColumns($payload, $payload)
        );
        $this->assertStringContainsString(
            "a''b",
            $dialect->describeReferences($payload, $payload)
        );
    }

    /**
     * A string DEFAULT is written into a single-quoted SQL literal, so MySQL
     * has to escape both the quote and the backslash (CWE-89).
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbDialectMysqlAddColumnEscapesDefault(): void
    {
        $dialect = new Mysql();

        $column = new Column(
            'field_old',
            [
                'type'    => Column::TYPE_VARCHAR,
                'size'    => 20,
                'default' => "rob'ots\\x",
                'notNull' => false,
            ]
        );

        $this->assertSame(
            'ALTER TABLE `schema`.`table` ADD `field_old` VARCHAR(20) NULL '
            . "DEFAULT 'rob''ots\\\\x'",
            $dialect->addColumn('table', 'schema', $column)
        );
    }

    /**
     * MySQL treats the backslash as an escape character, so a backslash in the
     * name has to be doubled together with the quote.
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbDialectMysqlIntrospectionEscapesBackslash(): void
    {
        $dialect = new Mysql();

        $this->assertStringContainsString(
            "a\\\\b",
            $dialect->tableExists("a\\b")
        );
    }

    /**
     * The MySQL helpers that take an optional schema build the same literals in
     * both branches, so the no-schema branch has to escape the quote too
     * (CWE-89).
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbDialectMysqlIntrospectionEscapesQuotes(): void
    {
        $dialect = new Mysql();

        $table  = "rob'ots";
        $schema = "sch'ema";

        // [statement, escaped literal, unescaped literal]
        $checks = [
            [$dialect->listViews($schema), "'sch''ema'", "'sch'ema'"],
            [$dialect->tableOptions($table, $schema), "'sch''ema'", "'sch'ema'"],
            [$dialect->tableOptions($table, $schema), "'rob''ots'", "'rob'ots'"],
            [$dialect->tableOptions($table), "'rob''ots'", "'rob'ots'"],
            [$dialect->viewExists($table), "'rob''ots'", "'rob'ots'"],
            [$dialect->describeReferences($table), "'rob''ots'", "'rob'ots'"],
        ];

        foreach ($checks as $check) {
            $this->assertStringContainsString($check[1], $check[0]);
            $this->assertStringNotContainsString($check[2], $check[0]);
        }
    }

    /**
     * `listTables()` puts the schema name in a quoted identifier, so a backtick
     * in the name has to be escaped (doubled) by `escape()` (CWE-89).
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbDialectMysqlListTablesEscapesIdentifier(): void
    {
        $dialect = new Mysql();

        $this->assertSame(
            'SHOW TABLES FROM `sch``ema`',
            $dialect->listTables('sch`ema')
        );
    }

    /**
     * A string DEFAULT is written into a single-quoted SQL literal, so a quote
     * in the value has to be escaped (doubled) (CWE-89).
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbDialectMysqlModifyColumnEscapesDefault(): void
    {
        $dialect = new Mysql();

        $column = new Column(
            'field_old',
            [
                'type'    => Column::TYPE_VARCHAR,
                'size'    => 20,
                'default' => "rob'ots",
                'notNull' => false,
            ]
        );

        $this->assertSame(
            'ALTER TABLE `schema`.`table` MODIFY `field_old` VARCHAR(20) NULL '
            . "DEFAULT 'rob''ots'",
            $dialect->modifyColumn('table', 'schema', $column)
        );
    }

    /**
     * `castDefault()` wraps a string default in a single-quoted SQL literal.
     * PostgreSQL doubles the quote; a backslash escape is not valid there
     * (CWE-89).
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbDialectPostgresqlCastDefaultEscapesQuotes(): void
    {
        $dialect = new Postgresql();

        $column = new Column(
            'field',
            [
                'type'    => Column::TYPE_VARCHAR,
                'size'    => 20,
                'default' => "rob'ots",
                'notNull' => false,
            ]
        );

        $actual = $dialect->addColumn('table', 'schema', $column);

        $this->assertSame(
            'ALTER TABLE "schema"."table" ADD COLUMN "field" '
            . "CHARACTER VARYING(20) DEFAULT 'rob''ots' NULL",
            $actual
        );
        $this->assertStringNotContainsString("\\'", $actual);
    }

    /**
     * The PostgreSQL index and catalog helpers concatenate the table/schema
     * name into a single-quoted SQL literal, so a quote in the name has to be
     * escaped (doubled) (CWE-89).
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbDialectPostgresqlIntrospectionEscapesQuotes(): void
    {
        $dialect = new Postgresql();

        $table  = "rob'ots";
        $schema = "sch'ema";

        // [statement, escaped literal, unescaped literal]
        $checks = [
            [$dialect->describeIndexes($table), "'rob''ots'", "'rob'ots'"],
            [$dialect->listTables($schema), "'sch''ema'", "'sch'ema'"],
            [$dialect->listViews($schema), "'sch''ema'", "'sch'ema'"],
            [$dialect->tableOptions($table, $schema), "'rob''ots'", "'rob'ots'"],
            [$dialect->tableOptions($table, $schema), "'sch''ema'", "'sch'ema'"],
        ];

        foreach ($checks as $check) {
            $this->assertStringContainsString($check[1], $check[0]);
            $this->assertStringNotContainsString($check[2], $check[0]);
        }
    }

    /**
     * The SQLite PRAGMA helpers put the index/table name in a single-quoted SQL
     * literal, so a quote in the name has to be escaped (doubled) (CWE-89).
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbDialectSqliteIntrospectionEscapesQuotes(): void
    {
        $dialect = new Sqlite();

        $payload = "rob'ots";

        $this->assertSame(
            "PRAGMA index_info('rob''ots')",
            $dialect->describeIndex($payload)
        );
        $this->assertSame(
            "PRAGMA index_list('rob''ots')",
            $dialect->describeIndexes($payload)
        );
    }
}
