<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\Adapter\Blackhole;

use UnitTester;

class SetLogLevelCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Blackhole :: setLogLevel()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterBlackholeSetLogLevel(UnitTester $I)
    {
        $I->wantToTest("Logger\Adapter\Blackhole - setLogLevel()");
        $I->skipTest("Need implementation");
    }
}
