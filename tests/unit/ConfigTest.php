<?php

namespace Phalcon\Test\Unit;

use Phalcon\Test\Unit\Config\Helper\ConfigBase;
use Phalcon\Test\Proxy\Config;
use Phalcon\Config as PhConfig;

/**
 * \Phalcon\Test\Unit\ConfigTest
 * Tests the \Phalcon\Config component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ConfigTest extends ConfigBase
{
    /**
     * Tests toArray method
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-17
     */
    public function testConfigToArray()
    {
        $this->specify(
            "Transform Config to the array does not returns the expected result",
            function () {
                $settings = [
                    'database' => [
                        'adapter'  => 'Mysql',
                        'host'     => 'localhost',
                        'username' => 'scott',
                        'password' => 'cheetah',
                        'name'     => 'test_db',
                    ],
                    'other' => [1, 2, 3, 4]
                ];

                $config = new Config($settings);
                expect($config->toArray())->equals($settings);
            }
        );
    }

    /**
     * Tests implementing of Countable interface
     *
     * @author Faruk Brbovic <fbrbovic@devstub.com>
     * @since  2014-11-03
     */
    public function testConfigCount()
    {
        $this->specify(
            "Returns the count of properties set in the config",
            function () {
                $config = new Config([
                    "controllersDir" => "../x/y/z",
                    "modelsDir"      => "../x/y/z",
                ]);

                expect(count($config))->equals(2);
                expect($config->count())->equals(2);
            }
        );
    }

    /**
     * Tests Standard Config
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-18
     */
    public function testStandardConfig()
    {
        $this->specify(
            "Comparison of configurations returned a not identical result",
            function () {
                $config = new Config($this->config);
                $this->compareConfig($this->config, $config);
            }
        );
    }

    /**
     * Tests access by numeric key
     *
     * @author Rian Orie <rian.orie@gmail.com>
     * @since  2014-11-12
     */
    public function testNumericConfig()
    {
        $this->specify(
            "Access by numeric key does not return the expected result",
            function () {
                $config = new Config(['abc']);
                expect($config->{0})->equals('abc');
            }
        );
    }

    /**
     * Tests converting child array to config object
     *
     * @author Rian Orie <rian.orie@gmail.com>
     * @since  2014-11-12
     */
    public function testChildArrayToConfigObject()
    {
        $this->specify(
            "Child node don't converted to the config object",
            function () {
                $config = new Config(['childNode' => ['A', 'B', 'C']]);
                expect($config->childNode)->isInstanceOf('Phalcon\Config');
                expect($config->get('childNode'))->isInstanceOf('Phalcon\Config');
                expect($config->offsetGet('childNode'))->isInstanceOf('Phalcon\Config');
            }
        );
    }

    /**
     * Tests standard config simple array
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-09-11
     */
    public function testStandardConfigSimpleArray()
    {
        $this->specify(
            "Comparison of objects returned a not identical result",
            function () {
                $expectedConfig = PhConfig::__set_state([
                    'database' => PhConfig::__set_state(
                        [
                            'adapter'  => 'Mysql',
                            'host'     => 'localhost',
                            'username' => 'scott',
                            'password' => 'cheetah',
                            'name'     => 'test_db',
                        ]
                    ),
                    'other' => [
                        0 => 1,
                        1 => 2,
                        2 => 3,
                        3 => 4,
                    ],
                ]);

                $settings = [
                    'database' => [
                        'adapter'  => 'Mysql',
                        'host'     => 'localhost',
                        'username' => 'scott',
                        'password' => 'cheetah',
                        'name'     => 'test_db',
                    ],
                    'other' => [1, 2, 3, 4]
                ];

                expect(new PhConfig($settings))->equals($expectedConfig);
            }
        );
    }

    /**
     * Tests merging config objects
     *
     * @author kjdev
     * @since  2015-02-18
     */
    public function testConfigMergeArray()
    {
        $this->specify(
            "Config objects does not merged properly",
            function () {
                $expected = PhConfig::__set_state([
                    'keys' => PhConfig::__set_state([
                        '0' => 'scott',
                        '1' => 'cheetah',
                        '2' => 'peter',
                    ]),
                ]);

                $config = new PhConfig(['keys' => ['scott', 'cheetah']]);
                expect($config->merge(new PhConfig(['keys' => ['peter']])))->equals($expected);

                $expected = PhConfig::__set_state([
                    'keys' => PhConfig::__set_state([
                        '0' => 'peter',
                        '1' => 'scott',
                        '2' => 'cheetah',
                    ]),
                ]);

                $config = new PhConfig(['keys' => ['peter']]);
                expect($config->merge(new PhConfig(['keys' => ['scott', 'cheetah']])))->equals($expected);
            }
        );
    }

    /**
     * Tests merging complex config objects
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-12-16
     */
    public function testConfigMergeComplexObjects()
    {
        $this->specify(
            "Config objects does not merged properly",
            function () {
                $config1 = new PhConfig([
                    'controllersDir' => '../x/y/z',
                    'modelsDir'      => '../x/y/z',
                    'database'       => [
                        'adapter'  => 'Mysql',
                        'host'     => 'localhost',
                        'username' => 'scott',
                        'password' => 'cheetah',
                        'name'     => 'test_db',
                        'charset'  => [
                            'primary' => 'utf8'
                        ],
                        'alternatives' => [
                            'primary' => 'latin1',
                            'second'  => 'latin1'
                        ]
                    ],
                ]);

                $config2 = new PhConfig([
                    'modelsDir' => '../x/y/z',
                    'database'  => [
                        'adapter'  => 'Postgresql',
                        'host'     => 'localhost',
                        'username' => 'peter',
                        'options'  => [
                            'case' => 'lower',
					        \PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8',
                        ],
                        'alternatives' => [
                            'primary' => 'swedish',
                            'third'   => 'american',
                        ],
                    ],
                ]);

                $config1->merge($config2);

                $expected = PhConfig::__set_state([
                    'controllersDir' => '../x/y/z',
                    'modelsDir'      => '../x/y/z',
                    'database' => PhConfig::__set_state([
                        'adapter'  => 'Postgresql',
                        'host'     => 'localhost',
                        'username' => 'peter',
                        'password' => 'cheetah',
                        'name'     => 'test_db',
                        'charset'  => PhConfig::__set_state([
                            'primary' => 'utf8',
                        ]),
                        'alternatives' => PhConfig::__set_state([
                            'primary' => 'swedish',
                            'second'  => 'latin1',
                            'third'   => 'american',
                        ]),
                        'options' => PhConfig::__set_state([
                            'case' => 'lower',
					        (string) \PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8',
                        ]),
                    ]),
                ]);

                expect($config1)->equals($expected);
            }
        );
    }
}
