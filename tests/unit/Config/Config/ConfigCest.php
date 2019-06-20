<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Config\Config;

use Phalcon\Config\Config;
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

        $expected = new Config(
            [
                'database' => [
                    'adapter'  => 'Mysql',
                    'host'     => 'localhost',
                    'username' => 'scott',
                    'password' => 'cheetah',
                    'name'     => 'test_db',
                ],
                'other'    => [
                    0 => 1,
                    1 => 2,
                    2 => 3,
                    3 => 4,
                ],
            ]
        );
        $actual   = new Config($settings);
        $I->assertEquals($expected, $actual);
    }
}
