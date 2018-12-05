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

class RollbackCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Blackhole :: rollback()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterBlackholeRollback(UnitTester $I)
    {
        $I->wantToTest("Logger\Adapter\Blackhole - rollback()");
        $I->skipTest("Need implementation");
    }
}
