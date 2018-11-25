<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Mysql;

use IntegrationTester;

class UseExplicitIdValueCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: useExplicitIdValue()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterPdoMysqlUseExplicitIdValue(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Mysql - useExplicitIdValue()");
        $I->skipTest("Need implementation");
    }
}
