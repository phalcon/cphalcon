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
use Phalcon\Db\Exceptions\InvalidSqlExpression;
use Phalcon\Db\Exceptions\InvalidSqlExpressionType;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

final class GetSqlExpressionTest extends AbstractDatabaseTestCase
{
    /**
     * Driver-agnostic expression compilation (literal operands only, so the
     * generated SQL is identical across dialects).
     *
     * @return array[]
     */
    public static function getExpressions(): array
    {
        $one  = ['type' => 'literal', 'value' => '1'];
        $two  = ['type' => 'literal', 'value' => '2'];
        $a    = ['type' => 'literal', 'value' => 'a'];

        return [
            // literal returns its value verbatim
            [['type' => 'literal', 'value' => 'foo'], 'foo'],
            // a simple placeholder returns its value verbatim
            [['type' => 'placeholder', 'value' => ':named'], ':named'],
            // an array placeholder is expanded `times` with a 0-based suffix
            [
                ['type' => 'placeholder', 'value' => '?', 'rawValue' => '?', 'times' => 3],
                '?0, ?1, ?2',
            ],
            // parentheses wrap the inner expression
            [['type' => 'parentheses', 'left' => $one], '(1)'],
            // binary operation: left, spaced operator, right
            [['type' => 'binary-op', 'op' => '=', 'left' => $one, 'right' => $two], '1 = 2'],
            // CAST(left AS right)
            [
                ['type' => 'cast', 'left' => $a, 'right' => ['type' => 'literal', 'value' => 'INTEGER']],
                'CAST(a AS INTEGER)',
            ],
            // CONVERT(left USING right)
            [
                ['type' => 'convert', 'left' => $a, 'right' => ['type' => 'literal', 'value' => 'utf8']],
                'CONVERT(a USING utf8)',
            ],
            // CASE expr WHEN .. THEN .. ELSE .. END
            [
                [
                    'type'         => 'case',
                    'expr'         => $a,
                    'when-clauses' => [
                        ['type' => 'when', 'expr' => $one, 'then' => $two],
                        ['type' => 'else', 'expr' => ['type' => 'literal', 'value' => '3']],
                    ],
                ],
                'CASE a WHEN 1 THEN 2 ELSE 3 END',
            ],
        ];
    }

    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExpressions')]
    public function testDbDialectGetSqlExpression(array $expression, string $expected): void
    {
        $dialect = new Mysql();

        $this->assertSame($expected, $dialect->getSqlExpression($expression));
    }

    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbDialectGetSqlExpressionThrowsForUnknownType(): void
    {
        $this->expectException(InvalidSqlExpressionType::class);

        (new Mysql())->getSqlExpression(['type' => 'no-such-expression-type']);
    }

    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbDialectGetSqlExpressionThrowsWithoutType(): void
    {
        $this->expectException(InvalidSqlExpression::class);

        (new Mysql())->getSqlExpression([]);
    }
}
