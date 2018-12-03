<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Validation;

use IntegrationTester;

class SetEventsManagerCest
{
    /**
     * Tests Phalcon\Validation :: setEventsManager()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationSetEventsManager(IntegrationTester $I)
    {
        $I->wantToTest("Validation - setEventsManager()");
        $I->skipTest("Need implementation");
    }
}
