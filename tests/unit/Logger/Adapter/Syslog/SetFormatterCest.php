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
use Phalcon\Logger\Formatter\FormatterInterface;
use Phalcon\Logger\Formatter\Line;
use UnitTester;

/**
 * Class SetFormatterCest
 *
 * @package Phalcon\Test\Unit\Logger
 */
class SetFormatterCest
{
    /**
     * Tests Phalcon\Logger\Adapter\Syslog :: setFormatter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterSyslogSetFormatter(UnitTester $I)
    {
        $I->wantToTest('Logger\Adapter\Syslog - setFormatter()');

        $streamName = $I->getNewFileName('log', 'log');

        $adapter = new Syslog($streamName);
        $adapter->setFormatter(new Line());

        $class  = FormatterInterface::class;
        $actual = $adapter->getFormatter();
        $I->assertInstanceOf($class, $actual);
    }
}
