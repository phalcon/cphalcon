<?php

namespace Phalcon\Test\Unit;

use Phalcon\Config;
use Phalcon\Test\Unit\Config\Helper\ConfigBase;

/**
 * \Phalcon\Test\Unit\ConfigTest
 * Tests the \Phalcon\Config component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ConfigTest extends ConfigBase
{
    /**
     * Tests path method
     *
     * @author michanismus
     * @since  2017-03-29
     */
    public function testConfigPath()
    {
        $this->specify(
            "Config path does not return expected value",
            function () {
                $config = new Config($this->config);
                expect($config->path('test.parent.property2'))->equals('yeah');
                expect($config->path('test.parent.property3', 'No'))->equals('No');
                expect($config->path('test.parent'))->isInstanceOf('Phalcon\Config');
                expect($config->path('unknown.path'))->equals(null);
                Config::setPathDelimiter('/');
                expect($config->path('test.parent.property2', false))->equals(false);
                expect($config->path('test/parent/property2'))->equals('yeah');
                expect($config->path('test/parent'))->isInstanceOf('Phalcon\Config');
            }
        );
    }

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
                $expectedConfig = Config::__set_state([
                    'database' => Config::__set_state(
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

                expect(new Config($settings))->equals($expectedConfig);
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
                $expected = Config::__set_state([
                    'keys' => Config::__set_state([
                        '0' => 'scott',
                        '1' => 'cheetah',
                        '2' => 'peter',
                    ]),
                ]);

                $config = new Config(['keys' => ['scott', 'cheetah']]);
                expect($config->merge(new Config(['keys' => ['peter']])))->equals($expected);

                $expected = Config::__set_state([
                    'keys' => Config::__set_state([
                        '0' => 'peter',
                        '1' => 'scott',
                        '2' => 'cheetah',
                    ]),
                ]);

                $config = new Config(['keys' => ['peter']]);
                expect($config->merge(new Config(['keys' => ['scott', 'cheetah']])))->equals($expected);
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
                $config1 = new Config([
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

                $config2 = new Config([
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

                $expected = Config::__set_state([
                    'controllersDir' => '../x/y/z',
                    'modelsDir'      => '../x/y/z',
                    'database' => Config::__set_state([
                        'adapter'  => 'Postgresql',
                        'host'     => 'localhost',
                        'username' => 'peter',
                        'password' => 'cheetah',
                        'name'     => 'test_db',
                        'charset'  => Config::__set_state([
                            'primary' => 'utf8',
                        ]),
                        'alternatives' => Config::__set_state([
                            'primary' => 'swedish',
                            'second'  => 'latin1',
                            'third'   => 'american',
                        ]),
                        'options' => Config::__set_state([
                            'case' => 'lower',
                            (string) \PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8',
                        ]),
                    ]),
                ]);

                expect($config1)->equals($expected);
            }
        );
    }

    /**
     * Tests issue 12779
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12779
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-06-19
     */
    public function testIssue12779()
    {
        $config = new Config(
            [
                'a' => [
                    [
                        1,
                    ],
                ],
            ]
        );

        $config->merge(
            new Config(
                [
                    'a' => [
                        [
                            2,
                        ],
                    ],
                ]
            )
        );
        expect($config->toArray())->equals(
            [
                'a' => [
                    [
                        1,
                        2,
                    ],
                ],
            ]
        );
    }

    /**
     * Tests issue 13351
     *
     * @link https://github.com/phalcon/cphalcon/issues/13351
     * @author Zamrony P. Juhara <zamronypj@yahoo.com>
     * @since  2018-04-27
     */
    public function testIssue13351MergeNonZeroBasedNumericKey()
    {
        $config = new Config([1 => 'Apple']);
        $config2 = new Config([2 => 'Banana']);
        $config->merge($config2);
        expect($config->toArray())->equals(
            [
                1 => 'Apple',
                2 => 'Banana',
            ]
        );

        $config = new Config([0 => 'Apple']);
        $config2 = new Config([1 => 'Banana']);
        $config->merge($config2);
        expect($config->toArray())->equals(
            [
                0 => 'Apple',
                1 => 'Banana',
            ]
        );

        $config = new Config([1 => 'Apple', 'p' => 'Pineapple']);
        $config2 = new Config([2 => 'Banana']);
        $config->merge($config2);
        expect($config->toArray())->equals(
            [
                1 => 'Apple',
                'p' => 'Pineapple',
                2 => 'Banana',
            ]
        );

        $config  = new Config([
            'One' => [1 => 'Apple', 'p' => 'Pineapple'],
            'Two' => [1 => 'Apple'],
        ]);
        $config2 = new Config([
            'One' => [2 => 'Banana'],
            'Two' => [2 => 'Banana'],
        ]);
        $config->merge($config2);
        expect($config->toArray())->equals(
            [
                'One' => [1 => 'Apple', 'p' => 'Pineapple', 2 => 'Banana'],
                'Two' => [1 => 'Apple', 2 => 'Banana'],
            ]
        );
    }
}
