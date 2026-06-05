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

use Phalcon\Contracts\Db\Dialect as DialectContract;
use Phalcon\Db\Dialect\Mysql;
use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class SharedLockModifierTest extends AbstractDatabaseTestCase
{
    /**
     * PostgreSQL - default emits `FOR SHARE`.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    public function testDbDialectPostgresqlSharedLockDefault(): void
    {
        $this->assertSame(
            'SELECT * FROM robots FOR SHARE',
            (new Postgresql())->sharedLock('SELECT * FROM robots')
        );
    }

    /**
     * PostgreSQL - `FOR SHARE NOWAIT`.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    public function testDbDialectPostgresqlSharedLockNoWait(): void
    {
        $this->assertSame(
            'SELECT * FROM robots FOR SHARE NOWAIT',
            (new Postgresql())->sharedLock(
                'SELECT * FROM robots',
                DialectContract::LOCK_NOWAIT
            )
        );
    }

    /**
     * PostgreSQL - `FOR SHARE SKIP LOCKED`.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    public function testDbDialectPostgresqlSharedLockSkipLocked(): void
    {
        $this->assertSame(
            'SELECT * FROM robots FOR SHARE SKIP LOCKED',
            (new Postgresql())->sharedLock(
                'SELECT * FROM robots',
                DialectContract::LOCK_SKIP_LOCKED
            )
        );
    }

    /**
     * MySQL - modifier is silently ignored (legacy `LOCK IN SHARE MODE`
     * does not support `NOWAIT` / `SKIP LOCKED`).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     */
    public function testDbDialectMysqlSharedLockIgnoresModifier(): void
    {
        $dialect = new Mysql();
        $sql     = 'SELECT * FROM robots';

        $this->assertSame(
            $sql . ' LOCK IN SHARE MODE',
            $dialect->sharedLock($sql)
        );
        $this->assertSame(
            $sql . ' LOCK IN SHARE MODE',
            $dialect->sharedLock($sql, DialectContract::LOCK_NOWAIT)
        );
        $this->assertSame(
            $sql . ' LOCK IN SHARE MODE',
            $dialect->sharedLock($sql, DialectContract::LOCK_SKIP_LOCKED)
        );
    }

    /**
     * SQLite - no row-level locking, modifier is ignored.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group sqlite
     */
    public function testDbDialectSqliteSharedLockIgnoresModifier(): void
    {
        $dialect = new Sqlite();
        $sql     = 'SELECT * FROM robots';

        $this->assertSame($sql, $dialect->sharedLock($sql));
        $this->assertSame(
            $sql,
            $dialect->sharedLock($sql, DialectContract::LOCK_NOWAIT)
        );
        $this->assertSame(
            $sql,
            $dialect->sharedLock($sql, DialectContract::LOCK_SKIP_LOCKED)
        );
    }
}
