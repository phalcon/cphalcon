<?php

namespace Phalcon\Test\Unit\Config\Adapter;

use Phalcon\Factory\Exception;
use Phalcon\Config\Adapter\Grouped;
use Phalcon\Test\Unit\Config\Helper\ConfigBase;

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
 * bundled with this package in the file LICENSE.txt
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
     * @test
     * @author fenikkusu
     * @since  2017-06-06
     */
    public function shouldCreateComplexConfigInstance()
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
     * Testing for exception
     *
     * @test
     * @author fenikkusu
     * @since  2017-06-06
     */
    public function shouldThrowsFactoryExceptionInCaseOfAbsentConfigParameter()
    {
        $this->specify(
            "Exception not thrown when config array not set.",
            function () {
                new Grouped(
                    [
                        [
                            'adapter' => 'array'
                        ]
                    ]
                );
            },
            [
                'throws' => new Exception("To use 'array' adapter you have to specify the 'config' as an array.")
            ]
        );
    }
}
