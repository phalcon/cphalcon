<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Logger\Adapter\Syslog;

use Phalcon\Logger\Adapter\Syslog;
use UnitTester;

class CloseCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: close()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function loggerAdapterSyslogClose(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Syslog - close()');

        $streamName = $I->getNewFileName('log', 'log');

        $adapter = new Syslog($streamName);

        $I->assertTrue(
            $adapter->close()
        );
    }
}
