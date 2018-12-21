<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Resultset\Simple;

use IntegrationTester;

class OffsetUnsetCest
{
    /**
     * Tests Phalcon\Mvc\Model\Resultset\Simple :: offsetUnset()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelResultsetSimpleOffsetUnset(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model\Resultset\Simple - offsetUnset()");
        $I->skipTest("Need implementation");
    }
}
