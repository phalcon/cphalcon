<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Model\Behavior\SoftDelete;

use UnitTester;

class NotifyCest
{
    /**
     * Tests Phalcon\Mvc\Model\Behavior\SoftDelete :: notify()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelBehaviorSoftdeleteNotify(UnitTester $I)
    {
        $I->wantToTest("Mvc\Model\Behavior\SoftDelete - notify()");
        $I->skipTest("Need implementation");
    }
}
