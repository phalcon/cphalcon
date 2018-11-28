<?php

namespace Phalcon\Test\Unit\Config\Helper;

use Phalcon\Config;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Config\Helper\ConfigBase
 * Tests the Phalcon\Config component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Config\Helper
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ConfigBase extends UnitTest
{
    protected $config = [
        'phalcon' => [
            'baseuri' => '/phalcon/'
        ],
        'models' => [
            'metadata' => 'memory'
        ],
        'database' => [
            'adapter'  => 'mysql',
            'host'     => 'localhost',
            'username' => 'user',
            'password' => 'passwd',
            'name'     => 'demo'
        ],
        'test' => [
            'parent' => [
                'property' => 1,
                'property2' => 'yeah'
            ],
        ],
        'issue-12725' => [
            'channel' => [
                'handlers' => [
                    0 => [
                        'name' => 'stream',
                        'level' => 'debug',
                        'fingersCrossed' => 'info',
                        'filename' => 'channel.log'
                    ],
                    1 => [
                        'name' => 'redis',
                        'level' => 'debug',
                        'fingersCrossed' => 'info'
                    ]
                ]
            ]
        ]
    ];

    protected function compareConfig(array $actual, Config $expected)
    {
        $this->assertEquals($actual, $expected->toArray());

        foreach ($actual as $key => $value) {
            $this->assertTrue(isset($expected->$key));

            if (is_array($value)) {
                $this->compareConfig($value, $expected->$key);
            }
        }
    }
}
