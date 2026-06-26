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

final class OnConflictUpdateTest extends AbstractDatabaseTestCase
{
    /**
     * MySQL - throws (its `ON DUPLICATE KEY UPDATE` is different).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    public function testDbDialectMysqlOnConflictUpdateThrows(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'ON CONFLICT upserts are not supported by MySQL'
        );

        (new Mysql())->onConflictUpdate(
            "INSERT INTO robots (id) VALUES (1)",
            ['id'],
            ['name']
        );
    }
    /**
     * PostgreSQL - emits `ON CONFLICT (col) DO UPDATE SET ...`.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('pgsql')]
    public function testDbDialectPostgresqlOnConflictUpdate(): void
    {
        $dialect = new Postgresql();
        $sql     = $dialect->onConflictUpdate(
            "INSERT INTO robots (id, name) VALUES (1, 'R2D2')",
            ['id'],
            ['name']
        );

        $this->assertSame(
            "INSERT INTO robots (id, name) VALUES (1, 'R2D2')"
            . ' ON CONFLICT ("id") DO UPDATE SET "name" = excluded."name"',
            $sql
        );
    }

    /**
     * Empty conflict columns throws.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('pgsql')]
    public function testDbDialectPostgresqlOnConflictUpdateEmptyConflictThrows(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'ON CONFLICT requires at least one conflict-target column'
        );

        (new Postgresql())->onConflictUpdate(
            "INSERT INTO robots (id) VALUES (1)",
            [],
            ['name']
        );
    }

    /**
     * Empty update columns throws.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('pgsql')]
    public function testDbDialectPostgresqlOnConflictUpdateEmptyUpdateThrows(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'ON CONFLICT DO UPDATE requires at least one update column'
        );

        (new Postgresql())->onConflictUpdate(
            "INSERT INTO robots (id) VALUES (1)",
            ['id'],
            []
        );
    }

    /**
     * Multiple conflict columns and multiple update columns.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('pgsql')]
    public function testDbDialectPostgresqlOnConflictUpdateMultiple(): void
    {
        $dialect = new Postgresql();
        $sql     = $dialect->onConflictUpdate(
            'INSERT INTO robots (a, b, c) VALUES (1, 2, 3)',
            ['a', 'b'],
            ['c']
        );

        $this->assertStringContainsString(
            'ON CONFLICT ("a", "b") DO UPDATE SET "c" = excluded."c"',
            $sql
        );
    }

    /**
     * SQLite - same standard syntax (3.24+).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('sqlite')]
    public function testDbDialectSqliteOnConflictUpdate(): void
    {
        $dialect = new Sqlite();
        $sql     = $dialect->onConflictUpdate(
            "INSERT INTO robots (id, name) VALUES (1, 'R2D2')",
            ['id'],
            ['name']
        );

        $this->assertStringContainsString(
            'ON CONFLICT ("id") DO UPDATE SET "name" = excluded."name"',
            $sql
        );
    }
}
