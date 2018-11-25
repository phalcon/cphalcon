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

class GetTypeStringCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Syslog :: getTypeString()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterSyslogGetTypeString(UnitTester $I)
    {
        $I->wantToTest("Logger\Formatter\Syslog - getTypeString()");
        $I->skipTest("Need implementation");
    }
}
