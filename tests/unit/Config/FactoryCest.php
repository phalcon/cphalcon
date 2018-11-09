<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Config;

use Helper\Traits\FactoryTrait;
use Phalcon\Config\Adapter\Ini;
use Phalcon\Config\Factory;
use UnitTester;

class FactoryCest
{
    use FactoryTrait;

    public function _before(UnitTester $I, $scenario)
    {
        $this->init();
    }

    /**
     * Test factory using Phalcon\Config
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testConfigFactory(UnitTester $I)
    {
        $options = $this->config->config;
        /** @var Ini $ini */
        $ini = Factory::load($options);

        $expected = Ini::class;
        $actual   = $ini;
        $I->assertInstanceOf($expected, $actual);
    }

    /**
     * Test factory using array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testArrayFactory(UnitTester $I)
    {
        $options = $this->arrayConfig["config"];
        /** @var Ini $ini */
        $ini = Factory::load($options);

        $expected = Ini::class;
        $actual   = $ini;
        $I->assertInstanceOf($expected, $actual);
    }

    /**
     * Test factory using array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-11-24
     */
    public function testStringFactory(UnitTester $I)
    {
        $filePath = $this->arrayConfig['config']['filePathExtension'];
        /** @var Ini $ini */
        $ini = Factory::load($filePath);

        $expected = Ini::class;
        $actual   = $ini;
        $I->assertInstanceOf($expected, $actual);
    }
}
