<?php
namespace Phalcon\Test\Unit\Config\Adapter;

use Phalcon\Test\Unit\Config\Helper\ConfigBase;
use Phalcon\Config\Adapter\Grouped;

/**
 * \Phalcon\Test\Unit\Config\Adapter\GroupedTest
 * Tests the \Phalcon\Config\Adapter\Grouped component
 *
 * @copyright (c) 2011-2017 Phalcon Team
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
class GroupedTest extends ConfigBase
{
    /**
     * Tests Grouped config
     *
     * @author fenikkusu
     * @since  2017-06-06
     */
    public function testGroupedConfig()
    {
        $this->specify(
            "Comparison of configurations returned a not identical result",
            function () {
                $this->config["test"]["property2"] = "something-else";

                $config = new Grouped(
                    [
                        PATH_DATA . 'config/config.php',
                        [
                            'filePath' => PATH_DATA . 'config/config.json',
                            'adapter'  => 'json'
                        ],
                        [
                            'adapter' => 'array',
                            'config'  => [
                                "test" => [
                                    "property2" => "something-else"
                                ]
                            ]
                        ]
                    ]
                );
                $this->compareConfig($this->config, $config);
            }
        );
    }

    /**
     * Testing For Exception
     *
     * @author fenikkusu
     * @since  2017-06-06
     */
    public function testGroupedConfigThrowsException()
    {
        $this->specify(
            "Exception not thrown when config array not set.",
            function () {
                $config = new Grouped(
                    [
                        [
                            'adapter' => 'array'
                        ]
                    ]
                );
                $this->compareConfig($this->config, $config);
            },
            [
                'throws' => 'Phalcon\Factory\Exception'
            ]
        );
    }
}
