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

namespace Phalcon\Test\Unit\Config\Factory;

use Phalcon\Config\Adapter\Ini;
use Phalcon\Config\Factory;
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
     * Tests Phalcon\Config\Factory :: load() - Config
     *
     * @param UnitTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function configFactoryLoadConfig(UnitTester $I)
    {
        $I->wantToTest('Config\Factory - load() - Config');
        $options = $this->config->config;
        /** @var Ini $ini */
        $ini = Factory::load($options);

        $expected = Ini::class;
        $actual   = $ini;
        $I->assertInstanceOf($expected, $actual);
    }

    /**
     * Tests Phalcon\Config\Factory :: load() - array
     *
     * @param UnitTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function configFactoryLoadArray(UnitTester $I)
    {
        $I->wantToTest('Config\Factory - load() - array');
        $options = $this->arrayConfig["config"];
        /** @var Ini $ini */
        $ini = Factory::load($options);

        $expected = Ini::class;
        $actual   = $ini;
        $I->assertInstanceOf($expected, $actual);
    }

    /**
     * Tests Phalcon\Config\Factory :: load() - string
     *
     * @param UnitTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-11-24
     */
    public function configFactoryLoadString(UnitTester $I)
    {
        $I->wantToTest('Config\Factory - load() - string');
        $filePath = $this->arrayConfig['config']['filePathExtension'];
        /** @var Ini $ini */
        $ini = Factory::load($filePath);

        $expected = Ini::class;
        $actual   = $ini;
        $I->assertInstanceOf($expected, $actual);
    }
}
