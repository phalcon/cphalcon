<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\Formatter\Syslog;

use UnitTester;

class InterpolateCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Syslog :: interpolate()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterSyslogInterpolate(UnitTester $I)
    {
        $I->wantToTest("Logger\Formatter\Syslog - interpolate()");
        $I->skipTest("Need implementation");
    }
}
