<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Config\ConfigFactory;

use Phalcon\Config\Adapter\Ini;
use Phalcon\Config\Adapter\Yaml;
use Phalcon\Config\ConfigFactory;
use Phalcon\Config\Exception;
use Phalcon\Tests\Fixtures\Traits\FactoryTrait;
use UnitTester;

use function dataDir;
use function hash;

class LoadCest
{
    use FactoryTrait;

    /**
     * Executed before each test
     *
     * @param UnitTester $I
     *
     * @return void
     */
    public function _before(UnitTester $I): void
    {
        $this->init();
    }

    /**
     * Tests Phalcon\Config\ConfigFactory :: load() - Config
     *
     * @param UnitTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function configFactoryLoadConfig(UnitTester $I)
    {
        $I->wantToTest('Config\ConfigFactory - load() - Config');

        $class   = Ini::class;
        $options = $this->config->get('config');

        /** @var Ini $ini */
        $ini = (new ConfigFactory())->load($options);
        $I->assertInstanceOf($class, $ini);

        //Issue 14756
        $configFile = dataDir('assets/config/config-with.in-file.name.ini');
        $ini        = new Ini($configFile, INI_SCANNER_NORMAL);
        $I->assertInstanceOf($class, $ini);

        /** @var Ini $ini */
        $ini = (new ConfigFactory())->load($ini->get('config')
                                               ->toArray());
        $I->assertInstanceOf($class, $ini);
    }

    /**
     * Tests Phalcon\Config\ConfigFactory :: load() - array
     *
     * @param UnitTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function configFactoryLoadArray(UnitTester $I)
    {
        $I->wantToTest('Config\ConfigFactory - load() - array');

        $options = $this->arrayConfig['config'];
        $class   = Ini::class;

        /** @var Ini $ini */
        $ini = (new ConfigFactory())->load($options);
        $I->assertInstanceOf($class, $ini);
    }

    /**
     * Tests Phalcon\Config\ConfigFactory :: load() - string
     *
     * @param UnitTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-11-24
     */
    public function configFactoryLoadString(UnitTester $I)
    {
        $I->wantToTest('Config\ConfigFactory - load() - string');

        $filePath = $this->arrayConfig['config']['filePathExtension'];
        $class    = Ini::class;

        /** @var Ini $ini */
        $ini = (new ConfigFactory())->load($filePath);
        $I->assertInstanceOf($class, $ini);
    }

    /**
     * Tests Phalcon\Config\ConfigFactory :: load() -  exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-19
     */
    public function configFactoryLoadYamlCallback(UnitTester $I)
    {
        $I->wantToTest('Config\ConfigFactory - load() - yaml callback');

        $class   = Yaml::class;
        $factory = new ConfigFactory();
        $config  = [
            'adapter'   => 'yaml',
            'filePath'  => dataDir('assets/config/callbacks.yml'),
            'callbacks' => [
                '!decrypt' => function ($value) {
                    return hash('sha256', $value);
                },
                '!approot' => function ($value) {
                    return 'app/root/' . $value;
                },
            ],
        ];

        $config = $factory->load($config);
        $I->assertInstanceOf($class, $config);
    }

    /**
     * Tests Phalcon\Config\ConfigFactory :: load() -  two calls new instances
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-07
     * @issue  14584
     */
    public function configFactoryLoadTwoCallsNewInstances(UnitTester $I)
    {
        $I->wantToTest('Config\ConfigFactory - load() - two calls new instances');

        $factory = new ConfigFactory();

        $configFile1 = dataDir('assets/config/config.php');
        $config      = $factory->load($configFile1);

        $expected = "/phalcon/";
        $actual   = $config->get('phalcon')->baseUri;
        $I->assertEquals($expected, $actual);

        $configFile2 = dataDir('assets/config/config-2.php');
        $config2     = $factory->load($configFile2);

        $expected = "/phalcon4/";
        $actual   = $config2->get('phalcon')->baseUri;
        $I->assertEquals($expected, $actual);
    }
}
