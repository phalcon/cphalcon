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
use PHPUnit\Framework\Attributes\Group;

final class ForUpdateModifierTest extends AbstractDatabaseTestCase
{
    /**
     * The default `forUpdate()` call (no modifier) is unchanged - the
     * existing one-argument call site keeps producing plain `FOR UPDATE`.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    public function testDbDialectForUpdateDefaultUnchanged(): void
    {
        $sql = 'SELECT * FROM robots';

        $this->assertSame(
            $sql . ' FOR UPDATE',
            (new Mysql())->forUpdate($sql)
        );
        $this->assertSame(
            $sql . ' FOR UPDATE',
            (new Postgresql())->forUpdate($sql)
        );
    }

    /**
     * Passing the explicit `Dialect::LOCK_NONE` constant matches the default.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    public function testDbDialectForUpdateLockNoneMatchesDefault(): void
    {
        $sql = 'SELECT * FROM robots';

        $this->assertSame(
            $sql . ' FOR UPDATE',
            (new Mysql())->forUpdate($sql, DialectContract::LOCK_NONE)
        );
    }

    /**
     * Passing `Dialect::LOCK_NOWAIT` appends `NOWAIT`.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    public function testDbDialectForUpdateNoWait(): void
    {
        $sql = 'SELECT * FROM robots';

        $this->assertSame(
            $sql . ' FOR UPDATE NOWAIT',
            (new Mysql())->forUpdate($sql, DialectContract::LOCK_NOWAIT)
        );
        $this->assertSame(
            $sql . ' FOR UPDATE NOWAIT',
            (new Postgresql())->forUpdate($sql, DialectContract::LOCK_NOWAIT)
        );
    }

    /**
     * Passing `Dialect::LOCK_SKIP_LOCKED` appends `SKIP LOCKED`.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    public function testDbDialectForUpdateSkipLocked(): void
    {
        $sql = 'SELECT * FROM robots';

        $this->assertSame(
            $sql . ' FOR UPDATE SKIP LOCKED',
            (new Mysql())->forUpdate($sql, DialectContract::LOCK_SKIP_LOCKED)
        );
        $this->assertSame(
            $sql . ' FOR UPDATE SKIP LOCKED',
            (new Postgresql())->forUpdate(
                $sql,
                DialectContract::LOCK_SKIP_LOCKED
            )
        );
    }

    /**
     * SQLite ignores the modifier - it has no row-level locking.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('sqlite')]
    public function testDbDialectSqliteForUpdateIgnoresModifier(): void
    {
        $sql     = 'SELECT * FROM robots';
        $dialect = new Sqlite();

        $this->assertSame($sql, $dialect->forUpdate($sql));
        $this->assertSame(
            $sql,
            $dialect->forUpdate($sql, DialectContract::LOCK_NOWAIT)
        );
        $this->assertSame(
            $sql,
            $dialect->forUpdate($sql, DialectContract::LOCK_SKIP_LOCKED)
        );
    }
}
