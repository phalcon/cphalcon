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

class SetNameCest
{
    /**
     * Tests Phalcon\Session\Adapter\Files :: setName()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterFilesSetName(IntegrationTester $I)
    {
        $I->wantToTest("Session\Adapter\Files - setName()");
        $I->skipTest("Need implementation");
    }
}
