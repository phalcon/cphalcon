<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Router\Group;

use UnitTester;

class BeforeMatchCest
{
    /**
     * Tests Phalcon\Mvc\Router\Group :: beforeMatch()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcRouterGroupBeforeMatch(UnitTester $I)
    {
        $I->wantToTest("Mvc\Router\Group - beforeMatch()");
        $I->skipTest("Need implementation");
    }
}
