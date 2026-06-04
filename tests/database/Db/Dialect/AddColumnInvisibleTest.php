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
use Phalcon\Tests\AbstractDatabaseTestCase;

final class AddColumnInvisibleTest extends AbstractDatabaseTestCase
{
    /**
     * MySQL - INVISIBLE columns emit the `INVISIBLE` keyword after
     * NOT NULL/NULL.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     */
    public function testDbDialectMysqlAddColumnInvisible(): void
    {
        $dialect = new Mysql();
        $column  = new Column(
            'internal_id',
            [
                'type'      => Column::TYPE_INTEGER,
                'size'      => 11,
                'invisible' => true,
            ]
        );

        $expected = 'ALTER TABLE `schema`.`table` ADD `internal_id` INT(11)'
            . ' NOT NULL INVISIBLE';
        $actual   = $dialect->addColumn('table', 'schema', $column);

        $this->assertSame($expected, $actual);
    }

    /**
     * MySQL - `INVISIBLE` is omitted by default (regression for
     * non-invisible columns).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group mysql
     */
    public function testDbDialectMysqlAddColumnVisibleByDefault(): void
    {
        $dialect = new Mysql();
        $column  = new Column(
            'visible_col',
            [
                'type' => Column::TYPE_INTEGER,
                'size' => 11,
            ]
        );

        $actual = $dialect->addColumn('table', 'schema', $column);

        $this->assertStringNotContainsString(' INVISIBLE', $actual);
    }

    /**
     * PostgreSQL - has no INVISIBLE concept; the flag must not leak into
     * its DDL.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group pgsql
     */
    public function testDbDialectPostgresqlAddColumnIgnoresInvisible(): void
    {
        $dialect = new Postgresql();
        $column  = new Column(
            'internal_id',
            [
                'type'      => Column::TYPE_INTEGER,
                'size'      => 11,
                'invisible' => true,
            ]
        );

        $actual = $dialect->addColumn('table', 'schema', $column);

        $this->assertStringNotContainsString('INVISIBLE', $actual);
    }

    /**
     * SQLite - same: no INVISIBLE concept.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     *
     * @group sqlite
     */
    public function testDbDialectSqliteAddColumnIgnoresInvisible(): void
    {
        $dialect = new Sqlite();
        $column  = new Column(
            'internal_id',
            [
                'type'      => Column::TYPE_INTEGER,
                'size'      => 11,
                'invisible' => true,
            ]
        );

        $actual = $dialect->addColumn('table', 'schema', $column);

        $this->assertStringNotContainsString('INVISIBLE', $actual);
    }
}
