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

class LoadCest
{
    use FactoryTrait;

    public function _before(UnitTester $I)
    {
        $this->init();
    }

    /**
     * Tests Phalcon\Annotations\Factory :: load() - Config
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
     * @param Config|array $options
     */
    private function runTests(UnitTester $I, $options)
    {
        /** @var Apcu $cache */
        $cache = Factory::load($options);

        $I->assertInstanceOf(
            Apcu::class,
            $cache
        );
    }

    /**
     * Tests Phalcon\Annotations\Factory :: load() - array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testArrayFactory(UnitTester $I)
    {
        $I->wantToTest('Annotations\Factory - load() - array');

        /** @var Apc $annotations */
        $options = $this->arrayConfig['annotations'];

        $this->runTests($I, $options);
    }
}
