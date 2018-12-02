<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Micro;

use IntegrationTester;

class SetEventsManagerCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: setEventsManager()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcMicroSetEventsManager(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Micro - setEventsManager()");
        $I->skipTest("Need implementation");
    }
}
