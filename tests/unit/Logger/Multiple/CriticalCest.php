<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\Multiple;

use UnitTester;

class CriticalCest
{
    /**
     * Tests Phalcon\Logger\Multiple :: critical()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerMultipleCritical(UnitTester $I)
    {
        $I->wantToTest("Logger\Multiple - critical()");
        $I->skipTest("Need implementation");
    }
}
