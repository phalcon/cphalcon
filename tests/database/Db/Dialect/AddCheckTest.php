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

use Phalcon\Db\Check;
use Phalcon\Db\Dialect\Mysql;
use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Db\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class AddCheckTest extends AbstractDatabaseTestCase
{
    /**
     * MySQL — named CHECK on existing table.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     */
    public function testDbDialectMysqlAddCheckNamed(): void
    {
        $dialect = new Mysql();
        $check   = new Check(
            'chk_price_positive',
            [
                'expression' => 'price > 0',
            ]
        );

        $expected = 'ALTER TABLE `schema`.`table` '
            . 'ADD CONSTRAINT `chk_price_positive` CHECK (price > 0)';
        $actual   = $dialect->addCheck('table', 'schema', $check);

        $this->assertSame($expected, $actual);
    }

    /**
     * MySQL — unnamed CHECK omits the `CONSTRAINT <name>` prefix.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     */
    public function testDbDialectMysqlAddCheckUnnamed(): void
    {
        $dialect = new Mysql();
        $check   = new Check(
            '',
            [
                'expression' => 'price > 0',
            ]
        );

        $expected = 'ALTER TABLE `schema`.`table` ADD CHECK (price > 0)';
        $actual   = $dialect->addCheck('table', 'schema', $check);

        $this->assertSame($expected, $actual);
    }

    /**
     * PostgreSQL — named CHECK on existing table.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    public function testDbDialectPostgresqlAddCheckNamed(): void
    {
        $dialect = new Postgresql();
        $check   = new Check(
            'chk_price_positive',
            [
                'expression' => 'price > 0',
            ]
        );

        $expected = 'ALTER TABLE "schema"."table" '
            . 'ADD CONSTRAINT "chk_price_positive" CHECK (price > 0)';
        $actual   = $dialect->addCheck('table', 'schema', $check);

        $this->assertSame($expected, $actual);
    }

    /**
     * SQLite — addCheck() throws (CHECK can only be declared at CREATE TABLE).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group sqlite
     */
    public function testDbDialectSqliteAddCheckThrows(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Adding a CHECK constraint to an existing table is not supported by SQLite'
        );

        $dialect = new Sqlite();
        $check   = new Check(
            'chk_price_positive',
            [
                'expression' => 'price > 0',
            ]
        );

        $dialect->addCheck('table', 'schema', $check);
    }

    /**
     * MySQL — dropCheck() emits the proper `DROP CHECK` syntax.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     */
    public function testDbDialectMysqlDropCheck(): void
    {
        $dialect = new Mysql();

        $expected = 'ALTER TABLE `schema`.`table` '
            . 'DROP CHECK `chk_price_positive`';
        $actual   = $dialect->dropCheck(
            'table',
            'schema',
            'chk_price_positive'
        );

        $this->assertSame($expected, $actual);
    }

    /**
     * PostgreSQL — dropCheck() emits `DROP CONSTRAINT` (PG does not distinguish
     * CHECK from other constraint kinds in the DROP syntax).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    public function testDbDialectPostgresqlDropCheck(): void
    {
        $dialect = new Postgresql();

        $expected = 'ALTER TABLE "schema"."table" '
            . 'DROP CONSTRAINT "chk_price_positive"';
        $actual   = $dialect->dropCheck(
            'table',
            'schema',
            'chk_price_positive'
        );

        $this->assertSame($expected, $actual);
    }

    /**
     * SQLite — dropCheck() throws.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group sqlite
     */
    public function testDbDialectSqliteDropCheckThrows(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Dropping a CHECK constraint is not supported by SQLite'
        );

        $dialect = new Sqlite();
        $dialect->dropCheck('table', 'schema', 'chk_price_positive');
    }
}
