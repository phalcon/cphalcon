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
use PHPUnit\Framework\Attributes\Group;

final class AddIndexInvisibleTest extends AbstractDatabaseTestCase
{
    /**
     * MySQL - invisible index emits `INVISIBLE` after the column list.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    public function testDbDialectMysqlAddIndexInvisible(): void
    {
        $dialect = new Mysql();
        $index   = new Index(
            'idx_hidden',
            [
                'columns'   => ['col1'],
                'invisible' => true,
            ]
        );

        $expected = 'ALTER TABLE `schema`.`table`'
            . ' ADD INDEX `idx_hidden` (`col1`) INVISIBLE';
        $actual   = $dialect->addIndex('table', 'schema', $index);

        $this->assertSame($expected, $actual);
    }

    /**
     * MySQL - visible index (default) emits no `INVISIBLE` keyword.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    public function testDbDialectMysqlAddIndexVisibleByDefault(): void
    {
        $dialect = new Mysql();
        $index   = new Index('idx_email', ['email']);

        $actual = $dialect->addIndex('table', 'schema', $index);

        $this->assertStringNotContainsString(' INVISIBLE', $actual);
    }

    /**
     * PostgreSQL - has no INVISIBLE concept; the flag must not leak.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('pgsql')]
    public function testDbDialectPostgresqlAddIndexIgnoresInvisible(): void
    {
        $dialect = new Postgresql();
        $index   = new Index(
            'idx_hidden',
            [
                'columns'   => ['col1'],
                'invisible' => true,
            ]
        );

        $actual = $dialect->addIndex('table', 'schema', $index);

        $this->assertStringNotContainsString('INVISIBLE', $actual);
    }

    /**
     * SQLite - same: no INVISIBLE concept.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('sqlite')]
    public function testDbDialectSqliteAddIndexIgnoresInvisible(): void
    {
        $dialect = new Sqlite();
        $index   = new Index(
            'idx_hidden',
            [
                'columns'   => ['col1'],
                'invisible' => true,
            ]
        );

        $actual = $dialect->addIndex('table', 'schema', $index);

        $this->assertStringNotContainsString('INVISIBLE', $actual);
    }
}
