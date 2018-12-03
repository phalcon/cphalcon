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

class OffsetGetCest
{
    /**
     * Tests Phalcon\Session\Bag :: offsetGet()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionBagOffsetGet(IntegrationTester $I)
    {
        $I->wantToTest("Session\Bag - offsetGet()");
        $I->skipTest("Need implementation");
    }
}
