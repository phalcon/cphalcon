<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

return [
    'phalcon'     => [
        'baseuri' => '/phalcon4/',
    ],
    'models'      => [
        'metadata' => 'memory',
    ],
    'database'    => [
        'adapter'  => 'mysql',
        'host'     => 'localhost',
        'username' => 'user',
        'password' => 'passwd',
        'name'     => 'demo',
    ],
    'test'        => [
        'parent' => [
            'property'  => 1,
            'property2' => 'yeah',
        ],
    ],
    'issue-12725' => [
        'channel' => [
            'handlers' => [
                0 => [
                    'name'           => 'stream',
                    'level'          => 'debug',
                    'fingersCrossed' => 'info',
                    'filename'       => 'channel.log',
                ],
                1 => [
                    'name'           => 'redis',
                    'level'          => 'debug',
                    'fingersCrossed' => 'info',
                ],
            ],
        ],
    ],
];
