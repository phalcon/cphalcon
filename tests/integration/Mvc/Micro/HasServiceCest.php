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

class HasServiceCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: hasService()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcMicroHasService(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Micro - hasService()");
        $I->skipTest("Need implementation");
    }
}
