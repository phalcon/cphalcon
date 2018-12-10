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

class SetDICest
{
    /**
     * Tests Phalcon\Session\Bag :: setDI()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionBagSetDI(IntegrationTester $I)
    {
        $I->wantToTest("Session\Bag - setDI()");
        $session = new \Phalcon\Session\Bag("DiTest");
        $di = new \Phalcon\Di\FactoryDefault();
        $session->setDI($di);
        $I->assertEquals($di, $session->getDI());
    }
}
