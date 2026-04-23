<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Config\ConfigFactory;

use Phalcon\Config\Adapter\Ini;
use Phalcon\Config\Adapter\Yaml;
use Phalcon\Config\ConfigFactory;
use Phalcon\Config\Exception;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\FactoryTrait;

use function hash;
use function supportDir;

use const INI_SCANNER_NORMAL;

final class LoadTest extends AbstractUnitTestCase
{
    use FactoryTrait;

    /**
     * @return void
     */
    public function setUp(): void
    {
        $this->init();
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testConfigFactoryLoadArray(): void
    {
        $options = $this->arrayConfig['config'];
        $class   = Ini::class;

        /** @var Ini $ini */
        $ini = (new ConfigFactory())->load($options);
        $this->assertInstanceOf($class, $ini);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testConfigFactoryLoadConfig(): void
    {
        $class   = Ini::class;
        $options = $this->config->get('config');

        /** @var Ini $ini */
        $ini = (new ConfigFactory())->load($options);
        $this->assertInstanceOf($class, $ini);

        //Issue 14756
        $configFile = supportDir('assets/config/config-with.in-file.name.ini');
        $ini        = new Ini($configFile, INI_SCANNER_NORMAL);
        $this->assertInstanceOf($class, $ini);

        /** @var Ini $ini */
        $ini = (new ConfigFactory())->load(
            $ini->get('config')
                ->toArray()
        );
        $this->assertInstanceOf($class, $ini);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-19
     */
    public function testConfigFactoryLoadExceptionAdapter(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "You must provide 'adapter' option in factory config parameter."
        );

        $config = [
            'filePath' => supportDir('assets/config/config.ini'),
        ];
        (new ConfigFactory())->load($config);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-19
     */
    public function testConfigFactoryLoadExceptionExtension(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'You need to provide the extension in the file path'
        );

        (new ConfigFactory())->load('abced');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-19
     */
    public function testConfigFactoryLoadExceptionFilePath(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "You must provide 'filePath' option in factory config parameter."
        );

        $config = [
            'adapter' => 'ini',
        ];
        (new ConfigFactory())->load($config);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-19
     */
    public function testConfigFactoryLoadExceptionInvalidType(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Config must be array or Phalcon\Config\Config object'
        );

        (new ConfigFactory())->load(false);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-11-24
     */
    public function testConfigFactoryLoadString(): void
    {
        $filePath = $this->arrayConfig['config']['filePathExtension'];
        $class    = Ini::class;

        /** @var Ini $ini */
        $ini = (new ConfigFactory())->load($filePath);
        $this->assertInstanceOf($class, $ini);
    }

    /**
     * @issue 14584
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-07
     */
    public function testConfigFactoryLoadTwoCallsNewInstances(): void
    {
        $factory = new ConfigFactory();

        $configFile1 = supportDir('assets/config/config.php');
        $config      = $factory->load($configFile1);

        $expected = "/phalcon/";
        $actual   = $config->get('phalcon')->baseUri;
        $this->assertSame($expected, $actual);

        $configFile2 = supportDir('assets/config/config-2.php');
        $config2     = $factory->load($configFile2);

        $expected = "/phalcon4/";
        $actual   = $config2->get('phalcon')->baseUri;
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-19
     */
    public function testConfigFactoryLoadYamlCallback(): void
    {
        $class   = Yaml::class;
        $factory = new ConfigFactory();
        $config  = [
            'adapter'   => 'yaml',
            'filePath'  => supportDir('assets/config/callbacks.yml'),
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
        $this->assertInstanceOf($class, $config);
    }
}
