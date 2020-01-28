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

namespace Phalcon\Test\Unit\Logger\LoggerFactory;

use Phalcon\Logger;
use Phalcon\Logger\AdapterFactory;
use Phalcon\Logger\LoggerFactory;
use Psr\Log\LoggerInterface;
use UnitTester;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Logger\LoggerFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-03
     */
    public function loggerLoggerFactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Logger\LoggerFactory - newInstance()');

        $factory = new LoggerFactory(
            new AdapterFactory()
        );

        $logger = $factory->newInstance('my-logger');

        $I->assertInstanceOf(
            Logger::class,
            $logger
        );

        $I->assertInstanceOf(
            LoggerInterface::class,
            $logger
        );
    }
}
