<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Forms\Manager;

use IntegrationTester;

class GetCest
{
    /**
     * Tests Phalcon\Forms\Manager :: get()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsManagerGet(IntegrationTester $I)
    {
        $I->wantToTest("Forms\Manager - get()");
        $I->skipTest("Need implementation");
    }
}
