<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\User\Module;

use UnitTester;

class GetEventsManagerCest
{
    /**
     * Tests Phalcon\Mvc\User\Module :: getEventsManager()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcUserModuleGetEventsManager(UnitTester $I)
    {
        $I->wantToTest("Mvc\User\Module - getEventsManager()");
        $I->skipTest("Need implementation");
    }
}
