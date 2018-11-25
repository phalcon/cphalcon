<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Db\Dialect;

use UnitTester;

class GetSqlExpressionCest
{
    /**
     * Tests Phalcon\Db\Dialect :: getSqlExpression()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbDialectGetSqlExpression(UnitTester $I)
    {
        $I->wantToTest("Db\Dialect - getSqlExpression()");
        $I->skipTest("Need implementation");
    }
}
