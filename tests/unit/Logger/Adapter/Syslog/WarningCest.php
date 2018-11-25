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

class WarningCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: warning()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterSyslogWarning(UnitTester $I)
    {
        $I->wantToTest("Logger\Adapter\Syslog - warning()");
        $I->skipTest("Need implementation");
    }
}
