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

class CommitCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Blackhole :: commit()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterBlackholeCommit(UnitTester $I)
    {
        $I->wantToTest("Logger\Adapter\Blackhole - commit()");
        $I->skipTest("Need implementation");
    }
}
