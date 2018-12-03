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

class GetIteratorCest
{
    /**
     * Tests Phalcon\Session\Bag :: getIterator()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionBagGetIterator(IntegrationTester $I)
    {
        $I->wantToTest("Session\Bag - getIterator()");
        $I->skipTest("Need implementation");
    }
}
