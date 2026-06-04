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
use Phalcon\Db\Index;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class AddIndexConcurrentlyTest extends AbstractDatabaseTestCase
{
    /**
     * PostgreSQL - emits `CONCURRENTLY` between `INDEX` and the name.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    public function testDbDialectPostgresqlAddIndexConcurrently(): void
    {
        $dialect = new Postgresql();
        $index   = new Index(
            'idx_email',
            [
                'columns'      => ['email'],
                'concurrently' => true,
            ]
        );

        $actual = $dialect->addIndex('table', 'schema', $index);

        $this->assertStringContainsString('INDEX CONCURRENTLY "idx_email"', $actual);
    }

    /**
     * PostgreSQL - default (no `concurrently`) preserves legacy emission.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    public function testDbDialectPostgresqlAddIndexDefaultNotConcurrent(): void
    {
        $dialect = new Postgresql();
        $index   = new Index('idx_email', ['email']);

        $actual = $dialect->addIndex('table', 'schema', $index);

        $this->assertStringNotContainsString('CONCURRENTLY', $actual);
    }

    /**
     * MySQL - has no CONCURRENTLY concept; the flag must not leak.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     */
    public function testDbDialectMysqlAddIndexIgnoresConcurrently(): void
    {
        $dialect = new Mysql();
        $index   = new Index(
            'idx_email',
            [
                'columns'      => ['email'],
                'concurrently' => true,
            ]
        );

        $actual = $dialect->addIndex('table', 'schema', $index);

        $this->assertStringNotContainsString('CONCURRENTLY', $actual);
    }

    /**
     * SQLite - has no CONCURRENTLY concept.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group sqlite
     */
    public function testDbDialectSqliteAddIndexIgnoresConcurrently(): void
    {
        $dialect = new Sqlite();
        $index   = new Index(
            'idx_email',
            [
                'columns'      => ['email'],
                'concurrently' => true,
            ]
        );

        $actual = $dialect->addIndex('table', 'schema', $index);

        $this->assertStringNotContainsString('CONCURRENTLY', $actual);
    }
}
