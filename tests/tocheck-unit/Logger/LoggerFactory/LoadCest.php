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
use Phalcon\Test\Fixtures\Traits\FactoryTrait;
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-20
     */
    public function loggerLoggerFactoryLoad(UnitTester $I)
    {
        $I->wantToTest('Logger\LoggerFactory - load()');

        $options = $this->config->logger;

        $this->runTests($I, $options);
    }

    /**
     * Tests Phalcon\Logger\LoggerFactory :: load() - array
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-20
     */
    public function loggerLoggerFactoryLoadArray(UnitTester $I)
    {
        $I->wantToTest('Logger\LoggerFactory - load() - array');

        $options = $this->arrayConfig['logger'];

        $this->runTests($I, $options);
    }

    private function runTests(UnitTester $I, $options)
    {
        $factory = new LoggerFactory(
            new AdapterFactory()
        );

        /** @var Logger $object */
        $object = $factory->load($options);

        $I->assertInstanceOf(
            Logger::class,
            $object
        );

        $I->assertEquals(
            [],
            $object->getAdapters()
        );
    }
}
