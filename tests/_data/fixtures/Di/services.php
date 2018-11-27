<?php

return [
    'unit-test' => [
        'className' => '\Phalcon\Test\Module\UnitTest',
    ],
    'config' => [
        'className' => '\Phalcon\Config',
        'shared' => true,
    ],
    'component' => [
        'className' => '\SomeComponent',
        'arguments' => [
            [
                'type' => 'service',
                'name' => 'config',
            ]
        ],
    ],
];
