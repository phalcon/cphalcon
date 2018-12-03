<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Session\Adapter;

use IntegrationTester;

class HasCest
{
    /**
     * Tests Phalcon\Session\Adapter :: has()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterHas(IntegrationTester $I)
    {
        $I->wantToTest("Session\Adapter - has()");
        $I->skipTest("Need implementation");
    }
}
