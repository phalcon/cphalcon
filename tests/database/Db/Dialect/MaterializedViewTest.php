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

use Phalcon\Db\Dialect\Mysql;
use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Db\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class MaterializedViewTest extends AbstractDatabaseTestCase
{
    /**
     * PostgreSQL - createMaterializedView.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    public function testDbDialectPostgresqlCreateMaterializedView(): void
    {
        $dialect = new Postgresql();
        $sql     = $dialect->createMaterializedView(
            'top_robots',
            ['sql' => 'SELECT * FROM robots ORDER BY score DESC LIMIT 100'],
            'public'
        );

        $this->assertSame(
            'CREATE MATERIALIZED VIEW "public"."top_robots"'
            . ' AS SELECT * FROM robots ORDER BY score DESC LIMIT 100',
            $sql
        );
    }

    /**
     * PostgreSQL - refreshMaterializedView (non-concurrent).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    public function testDbDialectPostgresqlRefreshMaterializedView(): void
    {
        $dialect = new Postgresql();

        $this->assertSame(
            'REFRESH MATERIALIZED VIEW "public"."top_robots"',
            $dialect->refreshMaterializedView('top_robots', 'public')
        );
    }

    /**
     * PostgreSQL - refreshMaterializedView CONCURRENTLY.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    public function testDbDialectPostgresqlRefreshMaterializedViewConcurrent(): void
    {
        $dialect = new Postgresql();

        $this->assertSame(
            'REFRESH MATERIALIZED VIEW CONCURRENTLY "public"."top_robots"',
            $dialect->refreshMaterializedView('top_robots', 'public', true)
        );
    }

    /**
     * PostgreSQL - dropMaterializedView IF EXISTS by default.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    public function testDbDialectPostgresqlDropMaterializedView(): void
    {
        $dialect = new Postgresql();

        $this->assertSame(
            'DROP MATERIALIZED VIEW IF EXISTS "public"."top_robots"',
            $dialect->dropMaterializedView('top_robots', 'public')
        );

        $this->assertSame(
            'DROP MATERIALIZED VIEW "public"."top_robots"',
            $dialect->dropMaterializedView('top_robots', 'public', false)
        );
    }

    /**
     * MySQL - throws on each materialized-view method.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     */
    public function testDbDialectMysqlMaterializedViewThrows(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Materialized views are not supported by this dialect'
        );

        (new Mysql())->createMaterializedView('v', ['sql' => 'SELECT 1']);
    }

    /**
     * SQLite - throws on each materialized-view method.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group sqlite
     */
    public function testDbDialectSqliteMaterializedViewThrows(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Materialized views are not supported by this dialect'
        );

        (new Sqlite())->refreshMaterializedView('v');
    }
}
