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

class GetModuleNameCest
{
    /**
     * Tests Phalcon\Mvc\Router :: getModuleName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcRouterGetModuleName(UnitTester $I)
    {
        $I->wantToTest("Mvc\Router - getModuleName()");
        $I->skipTest("Need implementation");
    }
}
