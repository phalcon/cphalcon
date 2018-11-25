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

class FormatCest
{
    /**
     * Tests Phalcon\Logger\Formatter\Syslog :: format()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerFormatterSyslogFormat(UnitTester $I)
    {
        $I->wantToTest("Logger\Formatter\Syslog - format()");
        $I->skipTest("Need implementation");
    }
}
