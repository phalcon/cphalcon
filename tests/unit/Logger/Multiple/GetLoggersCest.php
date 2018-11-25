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

class GetLoggersCest
{
    /**
     * Tests Phalcon\Logger\Multiple :: getLoggers()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerMultipleGetLoggers(UnitTester $I)
    {
        $I->wantToTest("Logger\Multiple - getLoggers()");
        $I->skipTest("Need implementation");
    }
}
