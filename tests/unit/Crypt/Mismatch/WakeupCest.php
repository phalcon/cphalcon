<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Crypt\Mismatch;

use UnitTester;

class WakeupCest
{
    /**
     * Tests Phalcon\Crypt\Mismatch :: __wakeup()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cryptMismatchWakeup(UnitTester $I)
    {
        $I->wantToTest("Crypt\Mismatch - __wakeup()");
        $I->skipTest("Need implementation");
    }
}
