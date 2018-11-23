<?php

namespace Phalcon\Test\Unit\Config\Helper;

use Phalcon\Config;
use UnitTester;

class ConfigBase
{
    protected $config = [
        'phalcon'  => [
            'baseuri' => '/phalcon/',
        ],
        'models'   => [
            'metadata' => 'memory',
        ],
        'database' => [
            'adapter'  => 'mysql',
            'host'     => 'localhost',
            'username' => 'user',
            'password' => 'passwd',
            'name'     => 'demo',
        ],
        'test'     => [
            'parent' => [
                'property'  => 1,
                'property2' => 'yeah',
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

    protected function compareConfig(UnitTester $I, array $actual, Config $expected)
    {
        $I->assertEquals($actual, $expected->toArray());

        foreach ($actual as $key => $value) {
            $I->assertTrue(isset($expected->$key));

            if (is_array($value)) {
                $this->compareConfig($I, $value, $expected->$key);
            }
        }
    }
}
