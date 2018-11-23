<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Cache\Backend\Factory;

use Phalcon\Cache\Backend\Apc;
use Phalcon\Cache\Backend\Factory;
use Phalcon\Cache\Frontend\Data;
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
     * Tests Phalcon\Cache\Backend\Factory :: load() - Config
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testConfigFactory(UnitTester $I)
    {
        $options = $this->config->cache_backend;
        $this->runTests($I, $options);
    }

    /**
     * Tests Phalcon\Cache\Backend\Factory :: load() - array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testArrayFactory(UnitTester $I)
    {
        $options = $this->arrayConfig["cache_backend"];
        $this->runTests($I, $options);
    }

    /**
     * Runs the tests based on different configurations
     *
     * @param UnitTester   $I
     * @param Config|array $options
     */
    private function runTests(UnitTester $I, $options)
    {
        /** @var Apc $cache */
        $cache = Factory::load($options);

        $class = Apc::class;
        $actual = $cache;
        $I->assertInstanceOf($class, $actual);

        $class = Data::class;
        $actual = $cache->getFrontend();
        $I->assertInstanceOf($class, $actual);

        $expected = array_intersect_assoc($cache->getOptions(), $options->toArray());
        $actual   = $cache->getOptions();
        $I->assertEquals($expected, $actual);
    }
}
