<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Dialect;

use IntegrationTester;

class GetSqlExpressionCest
{
    /**
     * Tests Phalcon\Db\Dialect :: getSqlExpression()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbDialectGetSqlExpression(IntegrationTester $I)
    {
        $I->wantToTest("Db\Dialect - getSqlExpression()");
        $I->skipTest("Need implementation");
    }
}
