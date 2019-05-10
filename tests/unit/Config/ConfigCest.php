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
use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

class ConfigCest
{
    use ConfigTrait;

    /**
     * Tests access by numeric key
     *
     * @author Rian Orie <rian.orie@gmail.com>
     * @since  2014-11-12
     */
    public function testNumericConfig(UnitTester $I)
    {
        $config = new Config(
            [
                'abc',
            ]
        );

        $I->assertEquals(
            'abc',
            $config->{0}
        );
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

        $I->assertInstanceOf(
            Config::class,
            $config->childNode
        );

        $I->assertInstanceOf(
            Config::class,
            $config->get('childNode')
        );

        $I->assertInstanceOf(
            Config::class,
            $config->offsetGet('childNode')
        );
    }

    /**
     * Tests standard config simple array
     *
     * @author Phalcon Team <team@phalconphp.com>
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

        $actual = new Config($settings);

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

        $actual = $config->toArray();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests issue 13351
     *
     * @link   https://github.com/phalcon/cphalcon/issues/13351
     * @author Zamrony P. Juhara <zamronypj@yahoo.com>
     * @since  2018-04-27
     */
    public function testIssue13351MergeNonZeroBasedNumericKey(UnitTester $I)
    {
        $config = new Config(
            [
                1 => 'Apple',
            ]
        );

        $config2 = new Config(
            [
                2 => 'Banana',
            ]
        );

        $config->merge($config2);


        $expected = [
            1 => 'Apple',
            2 => 'Banana',
        ];

        $actual = $config->toArray();

        $I->assertEquals($expected, $actual);


        $config = new Config(
            [
                0 => 'Apple',
            ]
        );

        $config2 = new Config(
            [
                1 => 'Banana',
            ]
        );

        $config->merge($config2);


        $expected = [
            0 => 'Apple',
            1 => 'Banana',
        ];

        $actual = $config->toArray();

        $I->assertEquals($expected, $actual);


        $config = new Config(
            [
                1   => 'Apple',
                'p' => 'Pineapple',
            ]
        );

        $config2 = new Config(
            [
                2 => 'Banana',
            ]
        );

        $config->merge($config2);


        $expected = [
            1   => 'Apple',
            'p' => 'Pineapple',
            2   => 'Banana',
        ];

        $actual = $config->toArray();

        $I->assertEquals($expected, $actual);


        $config = new Config(
            [
                'One' => [
                    1   => 'Apple',
                    'p' => 'Pineapple',
                ],
                'Two' => [
                    1 => 'Apple',
                ],
            ]
        );

        $config2 = new Config(
            [
                'One' => [
                    2 => 'Banana',
                ],
                'Two' => [
                    2 => 'Banana',
                ],
            ]
        );

        $config->merge($config2);


        $expected = [
            'One' => [
                1   => 'Apple',
                'p' => 'Pineapple',
                2   => 'Banana',
            ],
            'Two' => [
                1 => 'Apple',
                2 => 'Banana',
            ],
        ];

        $actual = $config->toArray();

        $I->assertEquals($expected, $actual);
    }
}
