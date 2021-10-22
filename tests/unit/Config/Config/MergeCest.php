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

namespace Phalcon\Tests\Unit\Config\Config;

use Codeception\Example;
use Phalcon\Config\Config;
use Phalcon\Config\Exception;
use Phalcon\Tests\Fixtures\Traits\ConfigTrait;
use UnitTester;

class MergeCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Config :: merge()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-15
     */
    public function configMergeConfig(UnitTester $I)
    {
        $I->wantToTest('Config - merge() - Config');

        $config = $this->getConfig();

        $expected = $this->getMergedByConfig();
        $actual   = $config;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Config\Config :: merge()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @link         https://github.com/phalcon/cphalcon/issues/13351
     * @link         https://github.com/phalcon/cphalcon/issues/13201
     * @link         https://github.com/phalcon/cphalcon/issues/13768
     * @link         https://github.com/phalcon/cphalcon/issues/12779
     * @link         https://github.com/phalcon/phalcon/issues/196
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2121-10-21
     */
    public function configMergeConfigCases(UnitTester $I, Example $example)
    {
        $I->wantToTest('Config - merge() - ' . $example['label']);

        $source = new Config($example['source']);
        $target = new Config($example['target']);

        /**
         * As Config object
         */
        $expected = $example['expected'];
        $actual   = $source->merge($target)
                           ->toArray();
        $I->assertEquals($expected, $actual);

        /**
         * As array
         */
        $expected = $example['expected'];
        $target   = $example['target'];
        $actual   = $source->merge($target)
                           ->toArray();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Config :: merge() - exceptions
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-26
     */
    public function configMergeExceptions(UnitTester $I)
    {
        $I->wantToTest('Phalcon\Config :: merge() - exceptions');

        $config = new Config(
            [
                'my' => 'config'
            ]
        );

        $I->expectThrowable(
            new \Exception(
                'Invalid data type for merge.'
            ),
            function () use ($config) {
                $config->merge('invalid-config');
            }
        );
    }

    /**
     * @return array<array-key, array<string, mixed>>
     */
    private function getExamples(): array
    {
        return [
            [
                'label'    => 'associative array string key',
                'source'   => [
                    'a' => 'aaa',
                    'b' => [
                        'bar' => 'rrr',
                        'baz' => 'zzz',
                    ],
                ],
                'target'   => [
                    'c' => 'ccc',
                    'b' => [
                        'baz' => 'xxx',
                    ],
                ],
                'expected' => [
                    'a' => 'aaa',
                    'b' => [
                        'bar' => 'rrr',
                        'baz' => 'xxx',
                    ],
                    'c' => 'ccc',
                ],
            ],
            [
                'label'    => 'numeric string key with strings',
                'source'   => [
                    '1' => 'aaa',
                    '2' => [
                        '11' => 'rrr',
                        '12' => 'zzz',
                    ],
                ],
                'target'   => [
                    '3' => 'ccc',
                    '2' => [
                        '12' => 'xxx',
                    ],
                ],
                'expected' => [
                    '1' => 'aaa',
                    '2' => [
                        '11' => 'rrr',
                        '12' => 'xxx',
                    ],
                    '3' => 'ccc',
                ],
            ],
            [
                'label'    => 'numeric string key with numbers',
                'source'   => [
                    '0.4' => 0.4,
                ],
                'target'   => [
                    '1.1'                => 1,
                    '1.2'                => 1.2,
                    '2.8610229492188E-6' => 3,
                ],
                'expected' => [
                    '0.4'                => 0.4,
                    '1.1'                => 1,
                    '1.2'                => 1.2,
                    '2.8610229492188E-6' => 3,
                ],
            ],
            [
                'label'    => 'non zero based numeric key',
                'source'   => [
                    1 => 'Apple',
                ],
                'target'   => [
                    2 => 'Banana',
                ],
                'expected' => [
                    1 => 'Apple',
                    2 => 'Banana',
                ],
            ],
            [
                'label'    => 'zero based numeric key',
                'source'   => [
                    0 => 'Apple',
                ],
                'target'   => [
                    2 => 'Banana',
                ],
                'expected' => [
                    0 => 'Apple',
                    2 => 'Banana',
                ],
            ],
            [
                'label'    => 'non zero based mixed key',
                'source'   => [
                    1   => 'Apple',
                    'p' => 'Pineapple',
                ],
                'target'   => [
                    2 => 'Banana',
                ],
                'expected' => [
                    1   => 'Apple',
                    'p' => 'Pineapple',
                    2   => 'Banana',
                ],
            ],
            [
                'label'    => 'string keys mixed sub array keys',
                'source'   => [
                    'One' => [
                        1   => 'Apple',
                        'p' => 'Pineapple',
                    ],
                    'Two' => [
                        1 => 'Apple',
                    ],
                ],
                'target'   => [
                    'One' => [
                        2 => 'Banana',
                    ],
                    'Two' => [
                        2 => 'Banana',
                    ],
                ],
                'expected' => [
                    'One' => [
                        1   => 'Apple',
                        'p' => 'Pineapple',
                        2   => 'Banana',
                    ],
                    'Two' => [
                        1 => 'Apple',
                        2 => 'Banana',
                    ],
                ],
            ],
            [
                'label'    => 'complex objects merge',
                'source'   => [
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
                ],
                'target'   => [
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
                ],
                'expected' => [
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
                ],
            ],
            [
                'label'    => 'numeric string keys merge arrays',
                'source'   => [
                    'keys' => [
                        '0' => 'scott',
                        '1' => 'cheetah',
                    ],
                ],
                'target'   => [
                    'keys' => ['peter'],
                ],
                'expected' => [
                    'keys' => [
                        '0' => 'peter',
                        '1' => 'cheetah',
                    ],
                ],
            ],
            [
                'label'    => 'numeric int keys merge arrays',
                'source'   => [
                    'keys' => [
                        'peter',
                    ],
                ],
                'target'   => [
                    'keys' => [
                        'cheetah',
                        'scott',
                    ],
                ],
                'expected' => [
                    'keys' => [
                        '0' => 'cheetah',
                        '1' => 'scott',
                    ],
                ],
            ],
            [
                'label'    => 'string key, sub array empty, number key',
                'source'   => [
                    'test'     => 123,
                    'empty'    => [],
                    'nonEmpty' => [
                        5 => 'test'
                    ]
                ],
                'target'   => [
                    'empty' => [
                        3 => 'toEmpty'
                    ],
                ],
                'expected' => [
                    'test'     => 123,
                    'empty'    => [
                        3 => 'toEmpty'
                    ],
                    'nonEmpty' => [
                        5 => 'test'
                    ]
                ],
            ],
            [
                'label'    => 'string key, sub array not empty, number key',
                'source'   => [
                    'test'     => 123,
                    'empty'    => [],
                    'nonEmpty' => [
                        5 => 'test'
                    ]
                ],
                'target'   => [
                    'nonEmpty' => [
                        3 => 'toNonEmpty'
                    ],
                ],
                'expected' => [
                    'test'     => 123,
                    'empty'    => [],
                    'nonEmpty' => [
                        5 => 'test',
                        3 => 'toNonEmpty'
                    ]
                ],
            ],
        ];
    }

    /**
     * Merges the reference config object into an empty config object.
     *
     * @return Config
     * @throws Exception
     */
    private function getMergedByConfig(): Config
    {
        $config = new Config();
        $config->merge($this->getConfig());

        return $config;
    }
}
