<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Collection\Manager;

use UnitTester;

class GetEventsManagerCest
{
    /**
     * Tests Phalcon\Mvc\Collection\Manager :: getEventsManager()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcCollectionManagerGetEventsManager(UnitTester $I)
    {
        $I->wantToTest("Mvc\Collection\Manager - getEventsManager()");
        $I->skipTest("Need implementation");
    }
}
