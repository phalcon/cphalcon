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

final class AddIndexDirectionsTest extends AbstractDatabaseTestCase
{
    /**
     * MySQL - empty directions array preserves legacy plain rendering.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    public function testDbDialectMysqlAddIndexEmptyDirectionsIsLegacy(): void
    {
        $dialect = new Mysql();
        $index   = new Index('idx_email', ['email']);

        $expected = 'ALTER TABLE `schema`.`table` ADD INDEX `idx_email` (`email`)';
        $actual   = $dialect->addIndex('table', 'schema', $index);

        $this->assertSame($expected, $actual);
    }

    /**
     * MySQL - missing trailing positions default to ASC.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    public function testDbDialectMysqlAddIndexShortDirectionsDefaultAsc(): void
    {
        $dialect = new Mysql();
        $index   = new Index(
            'idx_compound',
            [
                'columns'    => ['col1', 'col2', 'col3'],
                'directions' => ['DESC'],
            ]
        );

        $expected = 'ALTER TABLE `schema`.`table`'
            . ' ADD INDEX `idx_compound`'
            . ' (`col1` DESC, `col2` ASC, `col3` ASC)';
        $actual   = $dialect->addIndex('table', 'schema', $index);

        $this->assertSame($expected, $actual);
    }
    /**
     * MySQL - explicit per-column directions are emitted.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    public function testDbDialectMysqlAddIndexWithDirections(): void
    {
        $dialect = new Mysql();
        $index   = new Index(
            'idx_compound',
            [
                'columns'    => ['col1', 'col2'],
                'directions' => ['ASC', 'DESC'],
            ]
        );

        $expected = 'ALTER TABLE `schema`.`table`'
            . ' ADD INDEX `idx_compound` (`col1` ASC, `col2` DESC)';
        $actual   = $dialect->addIndex('table', 'schema', $index);

        $this->assertSame($expected, $actual);
    }

    /**
     * PostgreSQL - directions are emitted on `CREATE INDEX`.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('pgsql')]
    public function testDbDialectPostgresqlAddIndexWithDirections(): void
    {
        $dialect = new Postgresql();
        $index   = new Index(
            'idx_compound',
            [
                'columns'    => ['col1', 'col2'],
                'directions' => ['ASC', 'DESC'],
            ]
        );

        $actual = $dialect->addIndex('table', 'schema', $index);

        $this->assertStringContainsString(
            '("col1" ASC, "col2" DESC)',
            $actual
        );
    }

    /**
     * SQLite - directions are emitted on `CREATE INDEX`.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('sqlite')]
    public function testDbDialectSqliteAddIndexWithDirections(): void
    {
        $dialect = new Sqlite();
        $index   = new Index(
            'idx_compound',
            [
                'columns'    => ['col1', 'col2'],
                'directions' => ['ASC', 'DESC'],
            ]
        );

        $actual = $dialect->addIndex('table', 'schema', $index);

        $this->assertStringContainsString(
            '("col1" ASC, "col2" DESC)',
            $actual
        );
    }
}
