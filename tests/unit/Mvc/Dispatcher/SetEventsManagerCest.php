<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Dispatcher;

use UnitTester;

class SetEventsManagerCest
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: setEventsManager()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcDispatcherSetEventsManager(UnitTester $I)
    {
        $I->wantToTest("Mvc\Dispatcher - setEventsManager()");
        $I->skipTest("Need implementation");
    }
}
