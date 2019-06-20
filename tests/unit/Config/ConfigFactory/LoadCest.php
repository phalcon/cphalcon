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
use Phalcon\Config\Adapter\Yaml;
use Phalcon\Config\ConfigFactory;
use Phalcon\Config\Exception;
use Phalcon\Test\Fixtures\Traits\FactoryTrait;
use UnitTester;
use function dataDir;
use function hash;
use const PATH_DATA;

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

    /**
     * Tests Phalcon\Config\ConfigFactory :: load() -  exception
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-06-19
     */
    public function configFactoryLoadException(UnitTester $I)
    {
        $I->wantToTest('Config\ConfigFactory - load() - string - exception');

        $I->expectThrowable(
            new Exception(
                'You need to provide the extension in the file path'
            ),
            function () {
                $ini = (new ConfigFactory())->load('abced');
            }
        );

        $I->expectThrowable(
            new Exception(
                'Config must be array or Phalcon\Config\Config object'
            ),
            function () {
                $ini = (new ConfigFactory())->load(false);
            }
        );

        $I->expectThrowable(
            new Exception(
                "You must provide 'filePath' option in factory config parameter."
            ),
            function () {
                $config = [
                    'adapter' => 'ini',
                ];
                $ini    = (new ConfigFactory())->load($config);
            }
        );

        $I->expectThrowable(
            new Exception(
                "You must provide 'adapter' option in factory config parameter."
            ),
            function () {
                $config = [
                    'filePath' => dataDir('assets/config/config.ini'),
                ];
                $ini    = (new ConfigFactory())->load($config);
            }
        );
    }

    /**
     * Tests Phalcon\Config\ConfigFactory :: load() -  yaml callback
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-06-19
     */
    public function configFactoryLoadYamlCallback(UnitTester $I)
    {
        $I->wantToTest('Config\ConfigFactory - load() - yaml callback');

        $factory = new ConfigFactory();

        $config = [
            'adapter'   => 'yaml',
            'filePath'  => dataDir('assets/config/callbacks.yml'),
            'callbacks' => [
                '!decrypt' => function ($value) {
                    return hash('sha256', $value);
                },
                '!approot' => function ($value) {
                    return PATH_DATA . $value;
                },
            ],
        ];

        $config = $factory->load($config);
        $I->assertInstanceOf(Yaml::class, $config);
    }
}
