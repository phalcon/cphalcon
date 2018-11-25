<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Router;

use UnitTester;

class GetRoutesCest
{
    /**
     * Tests Phalcon\Mvc\Router :: getRoutes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcRouterGetRoutes(UnitTester $I)
    {
        $I->wantToTest("Mvc\Router - getRoutes()");
        $I->skipTest("Need implementation");
    }
}
