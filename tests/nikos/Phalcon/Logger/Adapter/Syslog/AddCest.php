<?php
declare(strict_types=1);

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

class AddCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: add()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function loggerAdapterSyslogAdd(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Syslog - add()');

        $I->skipTest('Need implementation');
    }
}
