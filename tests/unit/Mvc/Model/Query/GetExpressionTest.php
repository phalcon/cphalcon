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

namespace Phalcon\Tests\Unit\Mvc\Model\Query;

use Phalcon\Mvc\Model\Query;
use Phalcon\Tests\AbstractUnitTestCase;
use ReflectionClass;

final class GetExpressionTest extends AbstractUnitTestCase
{
    private int $PHQL_T_AND         = 266;
    private int $PHQL_T_OR          = 267;
    private int $PHQL_T_BETWEEN     = 331;
    private int $PHQL_T_BETWEEN_NOT = 332;

    /**
     * @issue  16812
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-28
     */
    public function testMvcModelQueryGetExpressionNotBetween(): void
    {
        $expected = [
            'type'  => 'binary-op',
            'op'    => 'NOT BETWEEN',
            'left'  => null,
            'right' => null,
        ];

        $expr = ['type' => $this->PHQL_T_BETWEEN_NOT];

        $query         = new Query();
        $reflection    = new ReflectionClass(Query::class);
        $getExpression = $reflection->getMethod('getExpression');
        $getExpression->setAccessible(true);

        $this->assertSame($expected, $getExpression->invokeArgs($query, [$expr, false]));
    }

    /**
     * @issue  15553
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-09-21
     */
    public function testMvcModelQueryGetExpression(): void
    {
        $valueOne = [
            'type'  => 'binary-op',
            'op'    => 'AND',
            'left'  => null,
            'right' => null,
        ];
        $valueTwo = [
            'type'  => 'binary-op',
            'op'    => 'OR',
            'left'  => null,
            'right' => null,
        ];

        $oneExpr = [
            'type' => $this->PHQL_T_AND,
        ];

        $twoExpr = [
            'type' => $this->PHQL_T_OR,
        ];

        $query         = new Query();
        $reflection    = new ReflectionClass(Query::class);
        $getExpression = $reflection->getMethod('getExpression');
        $getExpression->setAccessible(true);

        $this->assertSame($valueOne, $getExpression->invokeArgs($query, [$oneExpr, false]));
        $this->assertSame($valueTwo, $getExpression->invokeArgs($query, [$twoExpr, false]));
    }
}
