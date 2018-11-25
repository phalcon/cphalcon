<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\View\Engine;

use UnitTester;

class GetEventsManagerCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine :: getEventsManager()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewEngineGetEventsManager(UnitTester $I)
    {
        $I->wantToTest("Mvc\View\Engine - getEventsManager()");
        $I->skipTest("Need implementation");
    }
}
