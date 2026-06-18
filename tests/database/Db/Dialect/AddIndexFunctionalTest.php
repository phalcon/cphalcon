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
use Phalcon\Db\RawValue;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

final class AddIndexFunctionalTest extends AbstractDatabaseTestCase
{
    /**
     * MySQL - a single expression entry is wrapped in `(expr)`.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    public function testDbDialectMysqlAddIndexFunctional(): void
    {
        $dialect = new Mysql();
        $index   = new Index(
            'idx_lower_email',
            [
                'columns' => [new RawValue('LOWER(email)')],
            ]
        );

        $expected = 'ALTER TABLE `schema`.`table`'
            . ' ADD INDEX `idx_lower_email` ((LOWER(email)))';
        $actual   = $dialect->addIndex('table', 'schema', $index);

        $this->assertSame($expected, $actual);
    }

    /**
     * MySQL - mixed columns and expressions.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    public function testDbDialectMysqlAddIndexMixedColumnsAndExpression(): void
    {
        $dialect = new Mysql();
        $index   = new Index(
            'idx_mixed',
            [
                'columns' => [
                    'created_at',
                    new RawValue('LOWER(email)'),
                ],
            ]
        );

        $expected = 'ALTER TABLE `schema`.`table`'
            . ' ADD INDEX `idx_mixed`'
            . ' (`created_at`, (LOWER(email)))';
        $actual   = $dialect->addIndex('table', 'schema', $index);

        $this->assertSame($expected, $actual);
    }

    /**
     * PostgreSQL - expression wrapped in `(expr)`.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('pgsql')]
    public function testDbDialectPostgresqlAddIndexFunctional(): void
    {
        $dialect = new Postgresql();
        $index   = new Index(
            'idx_lower_email',
            [
                'columns' => [new RawValue('lower(email)')],
            ]
        );

        $actual = $dialect->addIndex('table', 'schema', $index);

        $this->assertStringContainsString('((lower(email)))', $actual);
    }

    /**
     * SQLite - expression emitted as-is, no extra parens (its grammar
     * accepts `expr` directly as `indexed-column`).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('sqlite')]
    public function testDbDialectSqliteAddIndexFunctional(): void
    {
        $dialect = new Sqlite();
        $index   = new Index(
            'idx_lower_email',
            [
                'columns' => [new RawValue('lower(email)')],
            ]
        );

        $actual = $dialect->addIndex('table', 'schema', $index);

        $this->assertStringContainsString('(lower(email))', $actual);
        $this->assertStringNotContainsString('((lower(email)))', $actual);
    }

    /**
     * MySQL - expression + direction compose.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-15
     */
    #[Group('mysql')]
    public function testDbDialectMysqlAddIndexFunctionalWithDirection(): void
    {
        $dialect = new Mysql();
        $index   = new Index(
            'idx_lower_email_desc',
            [
                'columns'    => [new RawValue('LOWER(email)')],
                'directions' => ['DESC'],
            ]
        );

        $actual = $dialect->addIndex('table', 'schema', $index);

        $this->assertStringContainsString('((LOWER(email)) DESC)', $actual);
    }
}
