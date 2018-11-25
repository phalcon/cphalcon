<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\Adapter\Syslog;

use UnitTester;

class GetFormatterCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: getFormatter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterSyslogGetFormatter(UnitTester $I)
    {
        $I->wantToTest("Logger\Adapter\Syslog - getFormatter()");
        $I->skipTest("Need implementation");
    }
}
