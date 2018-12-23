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

namespace Phalcon\Test\Unit\Cache\Backend\Factory;

use Phalcon\Cache\Backend\Apcu;
use Phalcon\Cache\Backend\Factory;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Test\Fixtures\Traits\FactoryTrait;
use UnitTester;

/**
 * Class LoadCest
 */
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
     * @param UnitTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function cacheBackendFactoryLoadConfig(UnitTester $I)
    {
        $I->wantToTest("Cache\Backend\Factory - load() - Config");
        $options = $this->config->cache_backend;
        $data    = $options->toArray();
        $this->runTests($I, $options, $data);
    }

    /**
     * Runs the tests based on different configurations
     *
     * @param UnitTester   $I
     * @param Config|array $options
     * @param array        $data
     */
    private function runTests(UnitTester $I, $options, array $data)
    {
        /** @var Apcu $cache */
        $cache = Factory::load($options);

        $class  = Apcu::class;
        $actual = $cache;
        $I->assertInstanceOf($class, $actual);

        $class  = Data::class;
        $actual = $cache->getFrontend();
        $I->assertInstanceOf($class, $actual);

        $expected = array_intersect_assoc($cache->getOptions(), $data);
        $actual   = $cache->getOptions();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Cache\Backend\Factory :: load() - array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function cacheBackendFactoryLoadArray(UnitTester $I)
    {
        $I->wantToTest("Cache\Backend\Factory - load() - array");
        $options = $this->arrayConfig["cache_backend"];
        $data    = $options;
        $this->runTests($I, $options, $data);
    }
}
