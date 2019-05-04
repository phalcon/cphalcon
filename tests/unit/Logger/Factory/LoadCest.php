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

namespace Phalcon\Test\Unit\Logger\Factory;

use Phalcon\Logger;
use Phalcon\Logger\Factory;
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
     * Tests Phalcon\Logger\Factory :: load() - Config
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function loggerFactoryLoadConfig(UnitTester $I)
    {
        $I->wantToTest('Logger\Factory - load() - Config');

        $options = $this->config->logger;

        $this->runTests($I, $options);
    }

    /**
     * Runs the tests based on different configurations
     *
     * @param Config|array $options
     */
    private function runTests(UnitTester $I, $options)
    {
        /** @var Logger $logger */
        $logger = Factory::load($options);

        $I->assertInstanceOf(
            Logger::class,
            $logger
        );

        $I->assertEquals(
            $options['name'],
            $logger->getName()
        );

        $adapters = $logger->getAdapters();

        $I->assertCount(
            count($options['adapters']),
            $adapters
        );

        $counter = 0;

        foreach ($adapters as $adapter) {
            $class = sprintf(
                'Phalcon\Logger\Adapter\%s',
                $options['adapters'][$counter]['adapter']
            );

            $I->assertInstanceOf($class, $adapter);

            $I->assertEquals(
                $options['adapters'][$counter]['name'],
                $adapter->getName()
            );

            $counter++;
        }
    }

    /**
     * Tests Phalcon\Logger\Factory :: load() - array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function loggerFactoryLoadArray(UnitTester $I)
    {
        $I->wantToTest('Logger\Factory - load() - array');

        $options = $this->arrayConfig['logger'];

        $this->runTests($I, $options);
    }
}
