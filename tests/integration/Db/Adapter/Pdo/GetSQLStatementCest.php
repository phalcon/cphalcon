<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter\Pdo;

use IntegrationTester;

class GetSQLStatementCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo :: getSQLStatement()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterPdoGetSQLStatement(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo - getSQLStatement()");
        $I->skipTest("Need implementation");
    }
}
