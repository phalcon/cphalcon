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

final class AddIndexPartialTest extends AbstractDatabaseTestCase
{
    /**
     * PostgreSQL — emits `WHERE <expr>` for partial indexes.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    public function testDbDialectPostgresqlAddIndexPartial(): void
    {
        $dialect = new Postgresql();
        $index   = new Index(
            'idx_active',
            [
                'columns' => ['email'],
                'where'   => 'active = true',
            ]
        );

        $actual = $dialect->addIndex('table', 'schema', $index);

        $this->assertStringContainsString(' WHERE active = true', $actual);
    }

    /**
     * SQLite — emits `WHERE <expr>` for partial indexes.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group sqlite
     */
    public function testDbDialectSqliteAddIndexPartial(): void
    {
        $dialect = new Sqlite();
        $index   = new Index(
            'idx_active',
            [
                'columns' => ['email'],
                'where'   => 'active = 1',
            ]
        );

        $actual = $dialect->addIndex('table', 'schema', $index);

        $this->assertStringContainsString(' WHERE active = 1', $actual);
    }

    /**
     * MySQL — has no partial-index feature; the WHERE predicate is ignored.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     */
    public function testDbDialectMysqlAddIndexIgnoresWhere(): void
    {
        $dialect = new Mysql();
        $index   = new Index(
            'idx_active',
            [
                'columns' => ['email'],
                'where'   => 'active = true',
            ]
        );

        $actual = $dialect->addIndex('table', 'schema', $index);

        $this->assertStringNotContainsString('WHERE', $actual);
    }
}
