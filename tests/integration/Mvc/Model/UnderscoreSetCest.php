<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;

class UnderscoreSetCest
{
    /**
     * Tests Phalcon\Mvc\Model :: __set()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelUnderscoreSet(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model - __set()");
        $I->skipTest("Need implementation");
    }
}
