<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Session\Bag;

use IntegrationTester;

class HasCest
{
    /**
     * Tests Phalcon\Session\Bag :: has()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionBagHas(IntegrationTester $I)
    {
        $I->wantToTest("Session\Bag - has()");
        $session = new \Phalcon\Session\Bag("SetTest");

        $testValue = "TestValue";
        $session->set("test", $testValue);

        $I->assertTrue($session->has("test"));
        $I->assertFalse($session->has("unknown"));
        
    }
}
