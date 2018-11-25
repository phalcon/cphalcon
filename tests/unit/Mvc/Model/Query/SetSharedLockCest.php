<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Model\Query;

use UnitTester;

class SetSharedLockCest
{
    /**
     * Tests Phalcon\Mvc\Model\Query :: setSharedLock()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelQuerySetSharedLock(UnitTester $I)
    {
        $I->wantToTest("Mvc\Model\Query - setSharedLock()");
        $I->skipTest("Need implementation");
    }
}
