<?php

namespace Phalcon\Test\Unit\Config\Adapter;

use Phalcon\Test\Unit\Config\Helper\ConfigBase;
use Phalcon\Config\Adapter\Ini;

/**
 * \Phalcon\Test\Unit\Config\Adapter\IniTest
 * Tests the \Phalcon\Config\Adapter\Ini component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Config\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class IniTest extends ConfigBase
{
    /**
     * Tests toArray method
     *
     * @author kjdev
     * @since  2013-07-18
     */
    public function testConfigToArray()
    {
        $this->specify(
            "Transform Config to the array does not returns the expected result",
            function () {
                $expected = [
                    'test' => [
                        'parent' => [
                            'property' => 1,
                            'property2' => 'yeah',
                            'property3' => ['baseuri' => '/phalcon/'],
                            'property4' => [
                                'models' => ['metadata' => 'memory'],
                            ],
                            'property5' => [
                                'database' => [
                                    'adapter' => 'mysql',
                                    'host' => 'localhost',
                                    'username' => 'user',
                                    'password' => 'passwd',
                                    'name' => 'demo'
                                ],
                            ],
                            'property6' => [
                                'test' => ['a', 'b', 'c'],
                            ],
                        ],
                    ],
                ];

                $config = new Ini(PATH_DATA . 'config/directive.ini');

                expect($config->toArray())->equals($expected);
            }
        );
    }

    /**
     * Tests Ini config
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-18
     */
    public function testIniConfig()
    {
        $this->specify(
            "Comparison of configurations returned a not identical result",
            function () {
                $config = new Ini(PATH_DATA . 'config/config.ini');
                $this->compareConfig($this->config, $config);
            }
        );
    }
}
