<?php
/**
 * Created by PhpStorm.
 * User: fenikkusu
 * Date: 6/6/17
 * Time: 8:05 PM
 */

namespace Phalcon\Test\Unit\Config\Adapter;

use Phalcon\Test\Unit\Config\Helper\ConfigBase;
use Phalcon\Config\Adapter\Grouped;

class GroupTest extends ConfigBase
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
