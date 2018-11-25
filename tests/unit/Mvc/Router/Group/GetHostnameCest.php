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

class GetHostnameCest
{
    /**
     * Tests Phalcon\Mvc\Router\Group :: getHostname()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcRouterGroupGetHostname(UnitTester $I)
    {
        $I->wantToTest("Mvc\Router\Group - getHostname()");
        $I->skipTest("Need implementation");
    }
}
