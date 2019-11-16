<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\Logger;

use Phalcon\Logger;
use UnitTester;

class GetSetLogLevelCest
{
    /**
     * Tests Phalcon\Logger :: getLogLevel()/setLogLevel()
     */
    public function loggerGetSetLogLevel(UnitTester $I)
    {
        $I->wantToTest('Logger - getLogLevel()/setLogLevel()');
        $logger = new Logger('my-name');

        $I->assertEquals(Logger::CUSTOM, $logger->getLogLevel());

        $object = $logger->setLogLevel(LOGGER::INFO);
        $I->assertInstanceOf(Logger::class, $object);

        $I->assertEquals(Logger::INFO, $logger->getLogLevel());

        $logger->setLogLevel(99);
        $I->assertEquals(Logger::CUSTOM, $logger->getLogLevel());
    }
}
