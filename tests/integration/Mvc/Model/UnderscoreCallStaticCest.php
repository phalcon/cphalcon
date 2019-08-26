<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;

class UnderscoreCallStaticCest
{
    /**
     * Tests Phalcon\Mvc\Model :: __callStatic()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelUnderscoreCallStatic(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model - __callStatic()");
        $I->skipTest('Need implementation');
    }
}
