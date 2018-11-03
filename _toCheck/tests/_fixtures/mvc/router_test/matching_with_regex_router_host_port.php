<?php

/**
 * Fixture for Router test
 *
 * @copyright (c) 2011-present Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Sergii Svyrydenko <sergey.v.svyrydenko@gmail.com>
 * @package   Phalcon\Test\Models
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

return [
    [
        [
            'hostname' => 'localhost',
            'port' => null,
            'handle' => '/edit',
        ],
        'posts3'
    ],
    [
        [
            'hostname' => 'my.phalconphp.com',
            'port' => 80,
            'handle' => '/edit',
        ],
        'posts'
    ],
    [
        [
            'hostname' => 'my.phalconphp.com',
            'port' => 8080,
            'handle' => '/edit',
        ],
        'posts'
    ],
    [
        [
            'hostname' => null,
            'port' => 8080,
            'handle' => '/edit',
        ],
        'posts3'
    ],
    [
        [
            'hostname' => 'mail.example.com',
            'port' => 9090,
            'handle' => '/edit',
        ],
        'posts2'
    ],
    [
        [
            'hostname' => 'some-domain.com',
            'port' => 9000,
            'handle' => '/edit',
        ],
        'posts3'
    ],
    [
        [
            'hostname' => 'some.domain.net',
            'port' => 0,
            'handle' => '/edit',
        ],
        'posts4'
    ],
];
