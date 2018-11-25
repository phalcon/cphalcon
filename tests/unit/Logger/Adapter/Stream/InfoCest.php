<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\Adapter\Stream;

use UnitTester;

class InfoCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Stream :: info()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterStreamInfo(UnitTester $I)
    {
        $I->wantToTest("Logger\Adapter\Stream - info()");
        $I->skipTest("Need implementation");
    }
}
