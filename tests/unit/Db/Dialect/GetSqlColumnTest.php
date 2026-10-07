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

namespace Phalcon\Tests\Unit\Db\Dialect;

use Phalcon\Db\Dialect\Mysql;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class GetSqlColumnTest extends AbstractUnitTestCase
{
    /**
     * getSqlColumn() calls getSqlExpression() for an expression (a typed
     * column, "*"), not for a plain column ([field, domain, alias]).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-07
     */
    public function testDbDialectGetSqlColumnCallsGetSqlExpressionOnlyForExpressions(): void
    {
        $dialect = new class () extends Mysql {
            public array $types = [];

            public function getSqlExpression(
                array $expression,
                ?string $escapeChar = null,
                array $bindCounts = []
            ): string {
                $this->types[] = $expression['type'];

                return parent::getSqlExpression(
                    $expression,
                    $escapeChar,
                    $bindCounts
                );
            }
        };

        $this->assertSame(
            '`r`.`name`',
            $dialect->getSqlColumn(['name', 'r'])
        );
        $this->assertSame([], $dialect->types);

        $dialect->getSqlColumn(
            [
                'type' => 'qualified',
                'name' => 'name',
            ]
        );
        $dialect->getSqlColumn(['*', 'r']);
        $this->assertSame(['qualified', 'all'], $dialect->types);
    }

    /**
     * For a plain column, getSqlColumn() calls prepareQualified() with the
     * field, the domain (null for an empty domain) and the escape character.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-07
     */
    public function testDbDialectGetSqlColumnCallsPrepareQualified(): void
    {
        $dialect = new class () extends Mysql {
            public array $calls = [];

            protected function prepareQualified(
                string $column,
                ?string $domain = null,
                ?string $escapeChar = null
            ): string {
                $this->calls[] = [$column, $domain, $escapeChar];

                return parent::prepareQualified(
                    $column,
                    $domain,
                    $escapeChar
                );
            }
        };

        $this->assertSame(
            '`r`.`name` AS `nick`',
            $dialect->getSqlColumn(['name', 'r', 'nick'])
        );
        $this->assertSame(
            '`name`',
            $dialect->getSqlColumn(['name', ''])
        );
        $this->assertSame(
            '"r"."name"',
            $dialect->getSqlColumn(['name', 'r'], '"')
        );

        $expected = [
            ['name', 'r', null],
            ['name', null, null],
            ['name', 'r', '"'],
        ];
        $this->assertSame($expected, $dialect->calls);
    }

    /**
     * The column forms give the same SQL: plain columns ([field, domain,
     * alias]), "*", a scalar expression and a typed column.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-07
     */
    public function testDbDialectGetSqlColumnPlainColumn(): void
    {
        $dialect = new Mysql();

        $this->assertSame(
            '`name`',
            $dialect->getSqlColumn(['name'])
        );
        $this->assertSame(
            '`r`.`name`',
            $dialect->getSqlColumn(['name', 'r'])
        );
        $this->assertSame(
            '`r`.`name` AS `nick`',
            $dialect->getSqlColumn(['name', 'r', 'nick'])
        );
        $this->assertSame(
            '`name`',
            $dialect->getSqlColumn(['name', null])
        );
        $this->assertSame(
            '`name`',
            $dialect->getSqlColumn(['name', ''])
        );
        $this->assertSame(
            '`r`.`name`',
            $dialect->getSqlColumn(['name', 'r', ''])
        );
        $this->assertSame(
            '`r`.`name`',
            $dialect->getSqlColumn(['name', 'r', null])
        );
        $this->assertSame(
            '`r`.`name`.`x`',
            $dialect->getSqlColumn(['name.x', 'r'])
        );

        $this->assertSame(
            '`r`.*',
            $dialect->getSqlColumn(['*', 'r'])
        );
        $this->assertSame(
            '1 AS `one`',
            $dialect->getSqlColumn(
                [
                    [
                        'type'  => 'literal',
                        'value' => '1',
                    ],
                    null,
                    'one',
                ]
            )
        );
        $this->assertSame(
            '`r`.`name` AS `nick`',
            $dialect->getSqlColumn(
                [
                    'type'   => 'qualified',
                    'name'   => 'name',
                    'domain' => 'r',
                    'alias'  => 'nick',
                ]
            )
        );
    }
}
