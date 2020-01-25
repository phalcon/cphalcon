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

namespace Phalcon\Test\Unit\Config\Config;

use Phalcon\Config;
use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

class MergeCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config :: merge()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-15
     */
    public function configMergeConfig(UnitTester $I)
    {
        $I->wantToTest('Config - merge() - Config');

        $config = $this->getConfig();

        $I->assertEquals(
            $this->getMergedByConfig(),
            $config
        );
    }

    /**
     * Tests Phalcon\Config :: merge()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-15
     */
    public function configMergeArr(UnitTester $I)
    {
        $I->wantToTest('Config - merge() - array');

        $config = $this->getConfig();

        $I->assertEquals(
            $this->getMergedByArray(),
            $config
        );
    }

    /**
     * Tests merging config objects
     *
     * @author kjdev
     * @since  2015-02-18
     */
    public function testConfigMergeArray(UnitTester $I)
    {
        $config = new Config(
            [
                'keys' => [
                    '0' => 'scott',
                    '1' => 'cheetah',
                ],
            ]
        );

        $b = new Config(
            [
                'keys' => ['peter'],
            ]
        );

        $expected = new Config(
            [
                'keys' => [
                    '0' => 'scott',
                    '1' => 'cheetah',
                    '2' => 'peter',
                ],
            ]
        );

        $actual = $config->merge(
            new Config(
                [
                    'keys' => ['peter'],
                ]
            )
        );


        $I->assertEquals($expected->toArray(), $actual->toArray());

        $config = new Config(
            [
                'keys' => ['peter'],
            ]
        );

        $expected = new Config(
            [
                'keys' => [
                    '0' => 'peter',
                    '1' => 'scott',
                    '2' => 'cheetah',
                ],
            ]
        );

        $actual = $config->merge(
            new Config(
                [
                    'keys' => [
                        'scott',
                        'cheetah',
                    ],
                ]
            )
        );

        $I->assertEquals($expected->toArray(), $actual->toArray());

        //Issue - #14705
        $expected = [
            'test' => 123,
            'empty' => [
                3 => 'toEmpty'
            ],
            'nonEmpty' => [
                3 => 'test',
                5 => 'toNonEmpty'
            ]
        ];

        $cfg = new Config([
            'test' => 123,
            'empty' => [],
            'nonEmpty' => [
                5 => 'test'
            ]
        ]);

        $emptyMerge = new \Phalcon\Config([3 => 'toEmpty']);
        $nonEmptyMerge = new \Phalcon\Config([3 => 'toNonEmpty']);

        $cfg->empty->merge($emptyMerge);
        $cfg->nonEmpty->merge($nonEmptyMerge);

        $I->assertEquals($expected, $cfg->toArray());
    }

    /**
     * Tests merging complex config objects
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-12-16
     */
    public function testConfigMergeComplexObjects(UnitTester $I)
    {
        $config1 = new Config(
            [
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
            ]
        );

        $config2 = new Config(
            [
                'modelsDir' => '../x/y/z',
                'database'  => [
                    'adapter'      => 'Postgresql',
                    'host'         => 'localhost',
                    'username'     => 'peter',
                    'options'      => [
                        'case'     => 'lower',
                        'encoding' => 'SET NAMES utf8',
                    ],
                    'alternatives' => [
                        'primary' => 'swedish',
                        'third'   => 'american',
                    ],
                ],
            ]
        );

        $config1->merge($config2);

        $expected = new Config(
            [
                'controllersDir' => '../x/y/z',
                'modelsDir'      => '../x/y/z',
                'database'       => [
                    'adapter'      => 'Postgresql',
                    'host'         => 'localhost',
                    'username'     => 'peter',
                    'password'     => 'cheetah',
                    'name'         => 'test_db',
                    'charset'      => [
                        'primary' => 'utf8',
                    ],
                    'alternatives' => [
                        'primary' => 'swedish',
                        'second'  => 'latin1',
                        'third'   => 'american',
                    ],
                    'options'      => [
                        'case'     => 'lower',
                        'encoding' => 'SET NAMES utf8',
                    ],
                ],
            ]
        );

        $I->assertEquals($expected->toArray(), $config1->toArray());
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

        $I->assertEquals(
            $expected,
            $config->toArray()
        );
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

        $I->assertEquals(
            $expected,
            $config->toArray()
        );


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

        $I->assertEquals(
            $expected,
            $config->toArray()
        );


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

        $I->assertEquals(
            $expected,
            $config->toArray()
        );


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

        $I->assertEquals(
            $expected,
            $config->toArray()
        );
    }

    /**
     * Merges the reference config object into an empty config object.
     */
    private function getMergedByConfig(): Config
    {
        $config = new Config();

        $config->merge(
            $this->getConfig()
        );

        return $config;
    }

    /**
     * Merges the reference config array data into an empty config object.
     */
    private function getMergedByArray(): Config
    {
        $config = new Config();

        $config->merge(
            require dataDir('assets/config/config.php')
        );

        return $config;
    }

    /**
     * Tests Phalcon\Config :: merge()
     *
     * @author Cameron Hall <me@chall.id.au>
     * @link   https://github.com/phalcon/cphalcon/issues/13201
     * @since  2019-06-19
     */
    public function testNumericKeyMerge(UnitTester $I)
    {
        $params1 = [
            '1' => 'aaa',
            '2' => [
                '11' => 'rrr',
                '12' => 'zzz',
            ],
        ];

        $config = new Config($params1);

        $params2 = [
            '3' => 'ccc',
            '2' => [
                '12' => 'xxx',
            ],
        ];

        $config->merge(
            new Config($params2)
        );

        $expected = [
            '1' => 'aaa',
            '2' => [
                '11' => 'rrr',
                '12' => 'zzz',
                '13' => 'xxx',
            ],
            '3' => 'ccc',
        ];

        $I->assertEquals(
            $expected,
            $config->toArray()
        );


        $config = new Config(
            [
                '0.4' => 0.4,
            ]
        );

        $config->merge(
            new Config(
                [
                    '1.1'                => 1,
                    '1.2'                => 1.2,
                    '2.8610229492188E-6' => 3,
                ]
            )
        );

        $expected = [
            '0.4'                => 0.4,
            '1.1'                => 1,
            '1.2'                => 1.2,
            '2.8610229492188E-6' => 3,
        ];

        $I->assertEquals(
            $expected,
            $config->toArray()
        );
    }

    /**
     * Tests Phalcon\Config :: merge()
     *
     * @author Cameron Hall <me@chall.id.au>
     * @link   https://github.com/phalcon/cphalcon/issues/13768
     * @since  2019-06-19
     */
    public function testAssociativeMergeReplacements(UnitTester $I)
    {
        $params1 = [
            'a' => 'aaa',
            'b' => [
                'bar' => 'rrr',
                'baz' => 'zzz',
            ],
        ];

        $config = new Config($params1);

        $params2 = [
            'c' => 'ccc',
            'b' => [
                'baz' => 'xxx',
            ],
        ];

        $config->merge(
            new Config($params2)
        );

        $expected = [
            'a' => 'aaa',
            'b' => [
                'bar' => 'rrr',
                'baz' => 'xxx',
            ],
            'c' => 'ccc',
        ];

        $I->assertEquals(
            $expected,
            $config->toArray()
        );
    }
}
