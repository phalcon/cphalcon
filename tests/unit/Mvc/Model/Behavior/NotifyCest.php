<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Model\Behavior;

use UnitTester;

class NotifyCest
{
    /**
     * Tests Phalcon\Mvc\Model\Behavior :: notify()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelBehaviorNotify(UnitTester $I)
    {
        $I->wantToTest("Mvc\Model\Behavior - notify()");
        $I->skipTest("Need implementation");
    }
}
