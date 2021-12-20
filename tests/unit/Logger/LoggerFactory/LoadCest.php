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

namespace Phalcon\Tests\Unit\Logger\LoggerFactory;

use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\AdapterFactory;
use Phalcon\Logger\Exception as LoggerException;
use Phalcon\Logger\Logger;
use Phalcon\Logger\LoggerFactory;
use Phalcon\Tests\Fixtures\Traits\FactoryTrait;
use Psr\Log\LoggerInterface;
use UnitTester;

class LoadCest
{
    use FactoryTrait;

    public function _before(UnitTester $I)
    {
        $this->init();
    }

    /**
     * Tests Phalcon\Logger\LoggerFactory :: load()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerLoggerFactoryLoad(UnitTester $I)
    {
        $I->wantToTest('Logger\LoggerFactory - load()');

        $options = $this->config->logger;
        $factory = new LoggerFactory(new AdapterFactory());

        $logger = $factory->load($options);

        $class = Logger::class;
        $I->assertInstanceOf($class, $logger);

        $class = LoggerInterface::class;
        $I->assertInstanceOf($class, $logger);

        $expected = 2;
        $actual   = $logger->getAdapters();
        $I->assertCount($expected, $actual);
    }

    /**
     * Tests Phalcon\Logger\LoggerFactory :: load() - array
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerLoggerFactoryLoadArray(UnitTester $I)
    {
        $I->wantToTest('Logger\LoggerFactory - load() - array');

        $options = $this->arrayConfig['logger'];
        $factory = new LoggerFactory(new AdapterFactory());

        $logger = $factory->load($options);

        $class = Logger::class;
        $I->assertInstanceOf($class, $logger);

        $class = LoggerInterface::class;
        $I->assertInstanceOf($class, $logger);

        $expected = 2;
        $actual   = $logger->getAdapters();
        $I->assertCount($expected, $actual);
    }

    /**
     * Tests Phalcon\Logger\LoggerFactory :: load() - array - check name
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function loggerLoggerFactoryLoadArrayName(UnitTester $I)
    {
        $I->wantToTest('Logger\LoggerFactory - load() - array - check name');

        $options = $this->arrayConfig['logger'];
        $factory = new LoggerFactory(new AdapterFactory());

        $logger = $factory->load($options);

        $class = Logger::class;
        $I->assertInstanceOf($class, $logger);

        $class = LoggerInterface::class;
        $I->assertInstanceOf($class, $logger);

        $expected = 2;
        $actual   = $logger->getAdapters();
        $I->assertCount($expected, $actual);

        $class  = Stream::class;
        $actual = $logger->getAdapter('main');
        $I->assertInstanceOf($class, $actual);

        $class  = Stream::class;
        $actual = $logger->getAdapter('admin');
        $I->assertInstanceOf($class, $actual);
    }

    /**
     * Tests Phalcon\Translate\Factory :: load() - exceptions
     *
     * @param UnitTester $I
     *
     * @throws LoggerException
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateFactoryLoadExceptions(UnitTester $I)
    {
        $I->wantToTest('Translate\Factory - load() - exceptions');

        $options = $this->arrayConfig['logger'];
        $factory = new LoggerFactory(new AdapterFactory());

        $I->expectThrowable(
            new LoggerException(
                'Config must be array or Phalcon\Config\Config object'
            ),
            function () use ($factory) {
                $factory->load(1234);
            }
        );

        $I->expectThrowable(
            new LoggerException(
                "You must provide 'name' option in factory config parameter."
            ),
            function () use ($factory, $options) {
                $newOptions = $options;
                unset($newOptions['name']);

                $factory->load($newOptions);
            }
        );
    }
}
