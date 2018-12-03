<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Session\Adapter\Files;

use IntegrationTester;

class UnderscoreUnsetCest
{
    /**
     * Tests Phalcon\Session\Adapter\Files :: __unset()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterFilesUnderscoreUnset(IntegrationTester $I)
    {
        $I->wantToTest("Session\Adapter\Files - __unset()");
        $I->skipTest("Need implementation");
    }
}
