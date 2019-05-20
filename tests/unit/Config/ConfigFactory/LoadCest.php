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

namespace Phalcon\Test\Unit\Config\ConfigFactory;

use Phalcon\Config\Adapter\Ini;
use Phalcon\Config\ConfigFactory;
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
     * Tests Phalcon\Config\ConfigFactory :: load() - Config
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function configFactoryLoadConfig(UnitTester $I)
    {
        $I->wantToTest('Config\ConfigFactory - load() - Config');

        $options = $this->config->config;

        /** @var Ini $ini */
        $ini = (new ConfigFactory())->load($options);

        $I->assertInstanceOf(
            Ini::class,
            $ini
        );
    }

    /**
     * Tests Phalcon\Config\ConfigFactory :: load() - array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function configFactoryLoadArray(UnitTester $I)
    {
        $I->wantToTest('Config\ConfigFactory - load() - array');

        $options = $this->arrayConfig['config'];

        /** @var Ini $ini */
        $ini = (new ConfigFactory())->load($options);

        $I->assertInstanceOf(
            Ini::class,
            $ini
        );
    }

    /**
     * Tests Phalcon\Config\ConfigFactory :: load() - string
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-11-24
     */
    public function configFactoryLoadString(UnitTester $I)
    {
        $I->wantToTest('Config\ConfigFactory - load() - string');

        $filePath = $this->arrayConfig['config']['filePathExtension'];

        /** @var Ini $ini */
        $ini = (new ConfigFactory())->load($filePath);

        $I->assertInstanceOf(
            Ini::class,
            $ini
        );
    }
}
