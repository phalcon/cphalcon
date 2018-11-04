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

use Phalcon\Config\Adapter\Grouped;
use Phalcon\Test\Unit\Config\Helper\ConfigBase;
use UnitTester;

class GroupedCest extends ConfigBase
{
    /**
     * Tests Grouped config
     *
     * @test
     * @author fenikkusu
     * @since  2017-06-06
     */
    public function shouldCreateComplexConfigInstance(UnitTester $I)
    {
        $this->config["test"]["property2"] = "something-else";

        $config = new Grouped(
            [
                PATH_DATA . 'config/config.php',
                [
                    'filePath' => PATH_DATA . 'config/config.json',
                    'adapter'  => 'json',
                ],
                [
                    'adapter' => 'array',
                    'config'  => [
                        "test" => [
                            "property2" => "something-else",
                        ],
                    ],
                ],
            ]
        );
        $this->compareConfig($I, $this->config, $config);
    }

    /**
     * Testing for exception
     *
     * @test
     * @author                    Fenikkusu
     * @since                     2017-06-06
     *
     * @expectedException         \Phalcon\Factory\Exception
     * @expectedExceptionMessage  To use 'array' adapter you have to specify
     *                            the 'config' as an array.
     */
    public function shouldThrowsFactoryExceptionInCaseOfAbsentConfigParameter(UnitTester $I)
    {
        $I->expectThrowable(
            \Exception::class,
            function () {
                new Grouped(
                    [
                        [
                            'adapter' => 'array',
                        ],
                    ]
                );
            }
        );
    }
}
