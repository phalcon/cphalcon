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
use Phalcon\Db\RawValue;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

final class AddColumnDefaultExpressionTest extends AbstractDatabaseTestCase
{
    /**
     * MySQL - a RawValue default is emitted unquoted (used for expressions
     * like `(UUID())` introduced in MySQL 8.0.13).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    public function testDbDialectMysqlAddColumnDefaultRawExpression(): void
    {
        $dialect = new Mysql();
        $column  = new Column(
            'id',
            [
                'type'    => Column::TYPE_CHAR,
                'size'    => 36,
                'default' => new RawValue('(UUID())'),
            ]
        );

        $actual = $dialect->addColumn('table', 'schema', $column);

        $this->assertStringContainsString('DEFAULT (UUID())', $actual);
        $this->assertStringNotContainsString('DEFAULT "(UUID())"', $actual);
    }

    /**
     * PostgreSQL - RawValue default is emitted verbatim (e.g.
     * `gen_random_uuid()`, `nextval('seq')`).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('pgsql')]
    public function testDbDialectPostgresqlAddColumnDefaultRawExpression(): void
    {
        $dialect = new Postgresql();
        $column  = new Column(
            'id',
            [
                'type'    => Column::TYPE_VARCHAR,
                'size'    => 36,
                'default' => new RawValue('gen_random_uuid()'),
            ]
        );

        $actual = $dialect->addColumn('table', 'schema', $column);

        $this->assertStringContainsString(
            'DEFAULT gen_random_uuid()',
            $actual
        );
        $this->assertStringNotContainsString(
            "DEFAULT 'gen_random_uuid()'",
            $actual
        );
    }

    /**
     * SQLite - RawValue default is emitted verbatim (3.31+ supports
     * arbitrary expressions in DEFAULT).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('sqlite')]
    public function testDbDialectSqliteAddColumnDefaultRawExpression(): void
    {
        $dialect = new Sqlite();
        $column  = new Column(
            'created_at',
            [
                'type'    => Column::TYPE_VARCHAR,
                'size'    => 32,
                'default' => new RawValue("strftime('%s','now')"),
            ]
        );

        $actual = $dialect->addColumn('table', 'schema', $column);

        $this->assertStringContainsString(
            "DEFAULT strftime('%s','now')",
            $actual
        );
        $this->assertStringNotContainsString(
            "DEFAULT \"strftime('%s','now')\"",
            $actual
        );
    }

    /**
     * MySQL - non-RawValue strings still go through the existing quoting
     * path. Regression test for the unchanged behavior.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    public function testDbDialectMysqlAddColumnDefaultStringStillQuoted(): void
    {
        $dialect = new Mysql();
        $column  = new Column(
            'status',
            [
                'type'    => Column::TYPE_VARCHAR,
                'size'    => 10,
                'default' => 'active',
            ]
        );

        $actual = $dialect->addColumn('table', 'schema', $column);

        $this->assertStringContainsString('DEFAULT "active"', $actual);
    }

    /**
     * MySQL - CURRENT_TIMESTAMP string remains unquoted (legacy whitelist).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    public function testDbDialectMysqlAddColumnDefaultCurrentTimestampUnchanged(): void
    {
        $dialect = new Mysql();
        $column  = new Column(
            'created_at',
            [
                'type'    => Column::TYPE_TIMESTAMP,
                'default' => 'CURRENT_TIMESTAMP',
            ]
        );

        $actual = $dialect->addColumn('table', 'schema', $column);

        $this->assertStringContainsString(
            'DEFAULT CURRENT_TIMESTAMP',
            $actual
        );
        $this->assertStringNotContainsString(
            'DEFAULT "CURRENT_TIMESTAMP"',
            $actual
        );
    }
}
