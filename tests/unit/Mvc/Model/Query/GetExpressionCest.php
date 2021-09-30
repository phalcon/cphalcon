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

namespace Phalcon\Test\Unit\Mvc\Model\Query;

use Phalcon\Mvc\Model\Query;
use UnitTester;

class GetExpressionCest
{
    private $PHQL_T_AND = 266;
    private $PHQL_T_OR = 267;

    /**
     * Tests Phalcon\Mvc\Model\Query :: getExpression()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-09-21
     * @issue        15553
     */
    public function mvcModelQueryGetExpression(UnitTester $I)
    {
        $I->wantToTest('Phalcon\Mvc\Model\Query - getExpression()');

        $valueOne = [
            'type' => 'binary-op',
            'op' => 'AND',
            'left' => null,
            'right' => null,
        ];
        $valueTwo = [
            'type' => 'binary-op',
            'op' => 'OR',
            'left' => null,
            'right' => null,
        ];

        $oneExpr = [
            'type' => $this->PHQL_T_AND,
        ];

        $twoExpr = [
            'type' => $this->PHQL_T_OR,
        ];

        $query = new Query();
        $reflection = new \ReflectionClass(Query::class);
        $getExpression = $reflection->getMethod('getExpression');
        $getExpression->setAccessible(true);

        $I->assertEquals($getExpression->invokeArgs($query, [$oneExpr, false]), $valueOne);
        $I->assertEquals($getExpression->invokeArgs($query, [$twoExpr, false]), $valueTwo);
    }
}
