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

namespace Phalcon\Test\Unit\Annotations\Factory;

use Phalcon\Annotations\Adapter\Apcu;
use Phalcon\Annotations\Factory;
use Phalcon\Test\Fixtures\Traits\FactoryTrait;
use UnitTester;

/**
 * Class LoadCest
 */
class LoadCest
{
    use FactoryTrait;

    /**
     * @param UnitTester $I
     */
    public function _before(UnitTester $I)
    {
        $this->init();
    }

    /**
     * Tests Phalcon\Annotations\Factory :: load() - Config
     *
     * @param UnitTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testConfigFactory(UnitTester $I)
    {
        $I->wantToTest('Annotations\Factory - load() - Config');
        $options = $this->config->annotations;
        $this->runTests($I, $options);
    }

    /**
     * Runs the tests based on different configurations
     *
     * @param UnitTester   $I
     *
     * @param UnitTester   $I
     * @param Config|array $options
     */
    private function runTests(UnitTester $I, $options)
    {
        /** @var Apcu $cache */
        $cache = Factory::load($options);

        $class  = Apcu::class;
        $actual = $cache;
        $I->assertInstanceOf($class, $actual);
    }

    /**
     * Tests Phalcon\Annotations\Factory :: load() - array
     *
     * @param UnitTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testArrayFactory(UnitTester $I)
    {
        $I->wantToTest('Annotations\Factory - load() - array');
        /** @var Apc $annotations */
        $options = $this->arrayConfig["annotations"];
        $this->runTests($I, $options);
    }
}
