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
use Phalcon\Logger\Formatter\FormatterInterface;
use Phalcon\Logger\Formatter\Line;
use UnitTester;

class GetSetFormatterCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: getFormatter()/setFormatter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerAdapterSyslogGetSetFormatter(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Syslog - getFormatter()/setFormatter()');

        $streamName = $I->getNewFileName('log', 'log');

        $adapter = new Syslog($streamName);
        $adapter->setFormatter(new Line());

        $I->assertInstanceOf(FormatterInterface::class, $adapter->getFormatter());
    }
}
