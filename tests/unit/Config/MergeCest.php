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

namespace Phalcon\Test\Unit\Config;

use PDO;
use Phalcon\Config;
use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

class MergeCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config :: merge()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-15
     */
    public function configMergeConfig(UnitTester $I)
    {
        $I->wantToTest("Config - merge() - Config");
        $config = $this->getConfig();

        $expected = $this->getMergedByConfig();
        $actual   = $config;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Merges the reference config object into an empty config object.
     *
     * @return Config
     */
    private function getMergedByConfig(): Config
    {
        $config = new Config();
        $config->merge($this->getConfig());

        return $config;
    }

    /**
     * Tests Phalcon\Config :: merge()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-15
     */
    public function configMergeArr(UnitTester $I)
    {
        $I->wantToTest("Config - merge() - array");
        $config = $this->getConfig();

        $expected = $this->getMergedByArray();
        $actual   = $config;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Merges the reference config array data into an empty config object.
     *
     * @return Config
     */
    private function getMergedByArray(): Config
    {
        $config = new Config();
        $config->merge(require dataDir('assets/config/config.php'));

        return $config;
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
                    'scott',
                    'cheetah',
                ],
            ]
        );

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

        $actual = $config->merge(
            new Config(
                [
                    'keys' => ['peter'],
                ]
            )
        );

        $I->assertEquals($expected, $actual);

        $config = new Config(
            [
                'keys' => ['peter'],
            ]
        );

        $expected = Config::__set_state(
            [
                'keys' => Config::__set_state(
                    [
                        '0' => 'peter',
                        '1' => 'scott',
                        '2' => 'cheetah',
                    ]
                ),
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

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests merging complex config objects
     *
     * @author Phalcon Team <team@phalconphp.com>
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
                        'case'                       => 'lower',
                        PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8',
                    ],
                    'alternatives' => [
                        'primary' => 'swedish',
                        'third'   => 'american',
                    ],
                ],
            ]
        );

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
                                'case'                                => 'lower',
                                (string) PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8',
                            ]
                        ),
                    ]
                ),
            ]
        );

        $actual = $config1;

        $I->assertEquals($expected, $actual);
    }
}
