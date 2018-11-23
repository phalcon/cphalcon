<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Config\Adapter;

use Phalcon\Config\Adapter\Ini;
use Phalcon\Test\Unit\Config\Helper\ConfigBase;
use UnitTester;

class IniCest extends ConfigBase
{
    /**
     * Tests constants in option values
     *
     * @author zytzagoo
     * @since  2016-08-03
     */
    public function testConstants(UnitTester $I)
    {
        define('TEST_CONST', 'foo');

        $config = new Ini(PATH_DATA . 'assets/config/config-with-constants.ini', INI_SCANNER_NORMAL);

        $expected = [
            'test'    => 'foo',
            'path'    => 'foo/something/else',
            'section' => [
                'test'   => 'foo',
                'path'   => 'foo/another-thing/somewhere',
                'parent' => [
                    'property'  => 'foo',
                    'property2' => 'foohello',
                ],
            ],
        ];
        $actual   = $config->toArray();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests toArray method
     *
     * @author kjdev
     * @since  2013-07-18
     */
    public function testConfigToArray(UnitTester $I)
    {
        $config = new Ini(PATH_DATA . 'assets/config/directive.ini');

        $expected = [
            'test' => [
                'parent' => [
                    'property'  => 1,
                    'property2' => 'yeah',
                    'property3' => ['baseuri' => '/phalcon/'],
                    'property4' => [
                        'models' => ['metadata' => 'memory'],
                    ],
                    'property5' => [
                        'database' => [
                            'adapter'  => 'mysql',
                            'host'     => 'localhost',
                            'username' => 'user',
                            'password' => 'passwd',
                            'name'     => 'demo',
                        ],
                    ],
                    'property6' => [
                        'test' => ['a', 'b', 'c'],
                    ],
                ],
            ],
        ];
        $actual   = $config->toArray();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Ini config
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-18
     */
    public function testIniConfig(UnitTester $I)
    {
        $I->skipTest('To check when refactoring');
        $config = new Ini(PATH_DATA . 'assets/config/config.ini');
        $this->compareConfig($I, $this->config, $config);
    }
}
