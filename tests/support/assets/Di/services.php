<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

use Phalcon\Config\Config;
use Phalcon\Tests\Support\Di\ServiceComponent;

return [
    'unit-test' => [
        'className' => UnitTester::class,
    ],
    'config'    => [
        'className' => Config::class,
        'shared'    => true,
    ],
    'component' => [
        'className' => ServiceComponent::class,
        'arguments' => [
            [
                'type' => 'service',
                'name' => 'config',
            ],
        ],
    ],
];
