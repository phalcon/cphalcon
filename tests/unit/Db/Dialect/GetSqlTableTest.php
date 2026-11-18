<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Db\Dialect;

use Phalcon\Db\Dialect\Mysql;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class GetSqlTableTest extends AbstractUnitTestCase
{
    /**
     * For a table array, getSqlTable() calls prepareTable() with the table,
     * the schema (null for no schema), the alias (null for no alias) and the
     * escape character.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-17
     */
    public function testDbDialectGetSqlTableCallsPrepareTable(): void
    {
        $dialect = new class () extends Mysql {
            public array $calls = [];

            protected function prepareTable(
                string $table,
                ?string $schema = null,
                ?string $alias = null,
                ?string $escapeChar = null
            ): string {
                $this->calls[] = [$table, $schema, $alias, $escapeChar];

                return parent::prepareTable(
                    $table,
                    $schema,
                    $alias,
                    $escapeChar
                );
            }
        };

        $this->assertSame(
            '`co_invoices`',
            $dialect->getSqlTable(['co_invoices'])
        );
        $this->assertSame(
            '`phalcon`.`co_invoices` AS `i`',
            $dialect->getSqlTable(['co_invoices', 'phalcon', 'i'])
        );
        $this->assertSame(
            '"co_invoices" AS "i"',
            $dialect->getSqlTable(['co_invoices', null, 'i'], '"')
        );

        $expected = [
            ['co_invoices', null, null, null],
            ['co_invoices', 'phalcon', 'i', null],
            ['co_invoices', null, 'i', '"'],
        ];
        $this->assertSame($expected, $dialect->calls);
    }
}
