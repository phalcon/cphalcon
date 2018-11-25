<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Router\Route;

use UnitTester;

class BeforeMatchCest
{
    /**
     * Tests Phalcon\Mvc\Router\Route :: beforeMatch()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcRouterRouteBeforeMatch(UnitTester $I)
    {
        $I->wantToTest("Mvc\Router\Route - beforeMatch()");
        $I->skipTest("Need implementation");
    }
}
