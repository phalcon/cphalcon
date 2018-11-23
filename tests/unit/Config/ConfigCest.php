<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit;

use Phalcon\Config;
use Phalcon\Test\Unit\Config\Helper\ConfigBase;
use UnitTester;

class ConfigCest extends ConfigBase
{
    /**
     * Tests path method
     *
     * @author michanismus
     * @since  2017-03-29
     */
    public function testConfigPath(UnitTester $I)
    {
        $config = new Config($this->config);

        $expected = 'yeah';
        $actual   = $config->path('test.parent.property2');
        $I->assertEquals($expected, $actual);

        $expected = 'No';
        $actual   = $config->path('test.parent.property3', 'No');
        $I->assertEquals($expected, $actual);

        $expected = 'Phalcon\Config';
        $actual   = $config->path('test.parent');
        $I->assertInstanceOf($expected, $actual);

        $actual = $config->path('unknown.path');
        $I->assertNull($actual);

        Config::setPathDelimiter('/');

        $actual = $config->path('test.parent.property2', false);
        $I->assertFalse($actual);

        $expected = 'yeah';
        $actual   = $config->path('test/parent/property2');
        $I->assertEquals($expected, $actual);

        $expected = 'Phalcon\Config';
        $actual   = $config->path('test/parent');
        $I->assertInstanceOf($expected, $actual);
    }

    /**
     * Tests toArray method
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-17
     */
    public function testConfigToArray(UnitTester $I)
    {
        $settings = [
            'database' => [
                'adapter'  => 'Mysql',
                'host'     => 'localhost',
                'username' => 'scott',
                'password' => 'cheetah',
                'name'     => 'test_db',
            ],
            'other'    => [1, 2, 3, 4],
        ];

        $config = new Config($settings);

        $expected = $settings;
        $actual   = $config->toArray();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests implementing of Countable interface
     *
     * @author Faruk Brbovic <fbrbovic@devstub.com>
     * @since  2014-11-03
     */
    public function testConfigCount(UnitTester $I)
    {
        $config = new Config(
            [
                "controllersDir" => "../x/y/z",
                "modelsDir"      => "../x/y/z",
            ]
        );

        $expected = 2;
        $actual   = count($config);
        $I->assertEquals($expected, $actual);

        $expected = 2;
        $actual   = $config->count();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Standard Config
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-18
     */
    public function testStandardConfig(UnitTester $I)
    {
        $config = new Config($this->config);
        $this->compareConfig($I, $this->config, $config);
    }

    /**
     * Tests access by numeric key
     *
     * @author Rian Orie <rian.orie@gmail.com>
     * @since  2014-11-12
     */
    public function testNumericConfig(UnitTester $I)
    {
        $config = new Config(['abc']);

        $expected = 'abc';
        $actual   = $config->{0};
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests converting child array to config object
     *
     * @author Rian Orie <rian.orie@gmail.com>
     * @since  2014-11-12
     */
    public function testChildArrayToConfigObject(UnitTester $I)
    {
        $config = new Config(
            [
                'childNode' => ['A', 'B', 'C'],
            ]
        );

        $expected = 'Phalcon\Config';
        $actual   = $config->childNode;
        $I->assertInstanceOf($expected, $actual);

        $expected = 'Phalcon\Config';
        $actual   = $config->get('childNode');
        $I->assertInstanceOf($expected, $actual);

        $expected = 'Phalcon\Config';
        $actual   = $config->offsetGet('childNode');
        $I->assertInstanceOf($expected, $actual);
    }

    /**
     * Tests standard config simple array
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-09-11
     */
    public function testStandardConfigSimpleArray(UnitTester $I)
    {
        $settings = [
            'database' => [
                'adapter'  => 'Mysql',
                'host'     => 'localhost',
                'username' => 'scott',
                'password' => 'cheetah',
                'name'     => 'test_db',
            ],
            'other'    => [1, 2, 3, 4],
        ];

        $expected = Config::__set_state(
            [
                'database' => Config::__set_state(
                    [
                        'adapter'  => 'Mysql',
                        'host'     => 'localhost',
                        'username' => 'scott',
                        'password' => 'cheetah',
                        'name'     => 'test_db',
                    ]
                ),
                'other'    => [
                    0 => 1,
                    1 => 2,
                    2 => 3,
                    3 => 4,
                ],
            ]
        );
        $actual   = new Config($settings);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests merging config objects
     *
     * @author kjdev
     * @since  2015-02-18
     */
    public function testConfigMergeArray(UnitTester $I)
    {
        $config = new Config(['keys' => ['scott', 'cheetah']]);

        $expected = Config::__set_state(
            [
                'keys' => Config::__set_state(
                    [
                        '0' => 'scott',
                        '1' => 'cheetah',
                        '2' => 'peter',
                    ]
                ),
            ]
        );
        $actual   = $config->merge(new Config(['keys' => ['peter']]));
        $I->assertEquals($expected, $actual);

        $config = new Config(['keys' => ['peter']]);

        $expected = Config::__set_state([
            'keys' => Config::__set_state([
                '0' => 'peter',
                '1' => 'scott',
                '2' => 'cheetah',
            ]),
        ]);
        $actual   = $config->merge(new Config(['keys' => ['scott', 'cheetah']]));
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests merging complex config objects
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-12-16
     */
    public function testConfigMergeComplexObjects(UnitTester $I)
    {
        $config1 = new Config([
            'controllersDir' => '../x/y/z',
            'modelsDir'      => '../x/y/z',
            'database'       => [
                'adapter'      => 'Mysql',
                'host'         => 'localhost',
                'username'     => 'scott',
                'password'     => 'cheetah',
                'name'         => 'test_db',
                'charset'      => [
                    'primary' => 'utf8',
                ],
                'alternatives' => [
                    'primary' => 'latin1',
                    'second'  => 'latin1',
                ],
            ],
        ]);

        $config2 = new Config([
            'modelsDir' => '../x/y/z',
            'database'  => [
                'adapter'      => 'Postgresql',
                'host'         => 'localhost',
                'username'     => 'peter',
                'options'      => [
                    'case'                        => 'lower',
                    \PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8',
                ],
                'alternatives' => [
                    'primary' => 'swedish',
                    'third'   => 'american',
                ],
            ],
        ]);

        $config1->merge($config2);

        $expected = Config::__set_state(
            [
                'controllersDir' => '../x/y/z',
                'modelsDir'      => '../x/y/z',
                'database'       => Config::__set_state(
                    [
                        'adapter'      => 'Postgresql',
                        'host'         => 'localhost',
                        'username'     => 'peter',
                        'password'     => 'cheetah',
                        'name'         => 'test_db',
                        'charset'      => Config::__set_state(
                            [
                                'primary' => 'utf8',
                            ]
                        ),
                        'alternatives' => Config::__set_state(
                            [
                                'primary' => 'swedish',
                                'second'  => 'latin1',
                                'third'   => 'american',
                            ]
                        ),
                        'options'      => Config::__set_state(
                            [
                                'case'                                 => 'lower',
                                (string) \PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8',
                            ]
                        ),
                    ]
                ),
            ]
        );
        $actual   = $config1;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests issue 12779
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12779
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-06-19
     */
    public function testIssue12779(UnitTester $I)
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


        $expected = [
            'a' => [
                [
                    1,
                    2,
                ],
            ],
        ];
        $actual   = $config->toArray();
        $I->assertEquals($expected, $actual);
    }
}
