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
use Phalcon\Logger\LoggerInterface;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\FactoryTrait;

final class LoadTest extends AbstractUnitTestCase
{
    use FactoryTrait;

    public function setUp(): void
    {
        $this->init();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerFactoryLoadExceptionsInvalidConfig(): void
    {
        $factory = new LoggerFactory(new AdapterFactory());

        $this->expectException(LoggerException::class);
        $this->expectExceptionMessage(
            'Config must be array or Phalcon\Config\Config object'
        );

        $factory->load(1234);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerFactoryLoadExceptionsNoName(): void
    {
        $options = $this->arrayConfig['logger'];
        $factory = new LoggerFactory(new AdapterFactory());

        $this->expectException(LoggerException::class);
        $this->expectExceptionMessage(
            "You must provide the 'name' option in the factory config parameter."
        );

        $newOptions = $options;
        unset($newOptions['name']);

        $factory->load($newOptions);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerLoggerFactoryLoad(): void
    {
        $options = $this->config->logger;
        $factory = new LoggerFactory(new AdapterFactory());

        $logger = $factory->load($options);

        $class = Logger::class;
        $this->assertInstanceOf($class, $logger);

        $class = LoggerInterface::class;
        $this->assertInstanceOf($class, $logger);

        $expected = 2;
        $actual   = $logger->getAdapters();
        $this->assertCount($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerLoggerFactoryLoadArray(): void
    {
        $options = $this->arrayConfig['logger'];
        $factory = new LoggerFactory(new AdapterFactory());

        $logger = $factory->load($options);

        $class = Logger::class;
        $this->assertInstanceOf($class, $logger);

        $class = LoggerInterface::class;
        $this->assertInstanceOf($class, $logger);

        $expected = 2;
        $actual   = $logger->getAdapters();
        $this->assertCount($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerLoggerFactoryLoadArrayName(): void
    {
        $options = $this->arrayConfig['logger'];
        $factory = new LoggerFactory(new AdapterFactory());

        $logger = $factory->load($options);

        $class = Logger::class;
        $this->assertInstanceOf($class, $logger);

        $class = LoggerInterface::class;
        $this->assertInstanceOf($class, $logger);

        $expected = 2;
        $actual   = $logger->getAdapters();
        $this->assertCount($expected, $actual);

        $class  = Stream::class;
        $actual = $logger->getAdapter('main');
        $this->assertInstanceOf($class, $actual);

        $class  = Stream::class;
        $actual = $logger->getAdapter('admin');
        $this->assertInstanceOf($class, $actual);
    }
}
