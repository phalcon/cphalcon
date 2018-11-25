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

class GetFormatterCest
{
    /**
     * Tests Phalcon\Logger\Multiple :: getFormatter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerMultipleGetFormatter(UnitTester $I)
    {
        $I->wantToTest("Logger\Multiple - getFormatter()");
        $I->skipTest("Need implementation");
    }
}
