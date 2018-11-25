<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Router\Annotations;

use UnitTester;

class GetControllerNameCest
{
    /**
     * Tests Phalcon\Mvc\Router\Annotations :: getControllerName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcRouterAnnotationsGetControllerName(UnitTester $I)
    {
        $I->wantToTest("Mvc\Router\Annotations - getControllerName()");
        $I->skipTest("Need implementation");
    }
}
