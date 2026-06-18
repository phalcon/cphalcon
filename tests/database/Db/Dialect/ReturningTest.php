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
use PHPUnit\Framework\Attributes\Group;

final class ReturningTest extends AbstractDatabaseTestCase
{
    /**
     * PostgreSQL - RETURNING list.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('pgsql')]
    public function testDbDialectPostgresqlReturningList(): void
    {
        $dialect = new Postgresql();

        $this->assertSame(
            "INSERT INTO robots (name) VALUES ('R2D2') RETURNING \"id\", \"name\"",
            $dialect->returning(
                "INSERT INTO robots (name) VALUES ('R2D2')",
                ['id', 'name']
            )
        );
    }

    /**
     * PostgreSQL - RETURNING *.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('pgsql')]
    public function testDbDialectPostgresqlReturningStar(): void
    {
        $dialect = new Postgresql();

        $this->assertSame(
            "DELETE FROM robots WHERE id = 1 RETURNING *",
            $dialect->returning(
                'DELETE FROM robots WHERE id = 1',
                ['*']
            )
        );
    }

    /**
     * SQLite - RETURNING list (3.35+).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('sqlite')]
    public function testDbDialectSqliteReturningList(): void
    {
        $dialect = new Sqlite();

        $this->assertSame(
            "INSERT INTO robots (name) VALUES ('R2D2') RETURNING \"id\"",
            $dialect->returning(
                "INSERT INTO robots (name) VALUES ('R2D2')",
                ['id']
            )
        );
    }

    /**
     * MySQL - throws (no RETURNING construct).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    public function testDbDialectMysqlReturningThrows(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'RETURNING clauses are not supported by this dialect'
        );

        (new Mysql())->returning(
            "INSERT INTO robots (name) VALUES ('R2D2')",
            ['id']
        );
    }

    /**
     * PostgreSQL - empty columns array throws.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('pgsql')]
    public function testDbDialectPostgresqlReturningEmptyThrows(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "RETURNING requires at least one column or '*'"
        );

        (new Postgresql())->returning(
            "INSERT INTO robots (name) VALUES ('R2D2')",
            []
        );
    }
}
