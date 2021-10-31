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

namespace Phalcon\Tests\Unit\Logger\Adapter\Syslog;

use Phalcon\Logger\Adapter\Syslog;
use Phalcon\Logger\Exception;
use UnitTester;

class CloseCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: close()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerAdapterSyslogClose(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Syslog - close()');

        $streamName = $I->getNewFileName('log', 'log');

        $adapter = new Syslog($streamName);

        $actual = $adapter->close();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: close() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-09-03
     * @issue  15638
     */
    public function loggerAdapterSyslogCloseException(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Syslog - close() - exception');

        $I->expectThrowable(
            new Exception('There is an active transaction'),
            function () use ($I) {
                $streamName = $I->getNewFileName('log', 'log');

                $adapter = new Syslog($streamName);

                $adapter->begin();
                $adapter->close();
            }
        );
    }
}
