<?php

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
