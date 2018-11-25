<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter;

use IntegrationTester;

class GetRealSQLStatementCest
{
    /**
     * Tests Phalcon\Db\Adapter :: getRealSQLStatement()
     *
     * @param IntegrationTester $I
     * 
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterGetRealSQLStatement(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter - getRealSQLStatement()");
        $I->skipTest("Need implementation");
    }
}
