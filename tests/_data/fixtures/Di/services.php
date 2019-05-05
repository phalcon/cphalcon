<?php

return [
    'unit-test' => [
        'className' => \Phalcon\Test\Module\UnitTest::class,
    ],
    'config' => [
        'className' => \Phalcon\Config::class,
        'shared' => true,
    ],
    'component' => [
        'className' => \SomeComponent::class,
        'arguments' => [
            [
                'type' => 'service',
                'name' => 'config',
            ]
        ],
    ],
];
