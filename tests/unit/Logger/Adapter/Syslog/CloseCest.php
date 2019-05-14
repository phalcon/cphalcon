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

use Phalcon\Logger\Adapter\Syslog;
use UnitTester;

class CloseCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: close()
     *
     * @author Phalcon Team <team@phalconphp.com>
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
