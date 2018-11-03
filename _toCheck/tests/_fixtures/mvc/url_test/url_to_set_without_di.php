<?php

/**
 * Fixture for URL tests
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
            'base_url' => 'http://www.test.com',
            'get' => '',
        ],
        'http://www.test.com',
    ],
    [
        [
            'base_url' => 'http://www.test.com',
            'get' => '/',
        ],
        'http://www.test.com/',
    ],
    [
        [
            'base_url' => 'http://www.test.com',
            'get' => '/path',
        ],
        'http://www.test.com/path',
    ],
    //Test urls that contains colons in schema definition and as parameter
    [
        [
            'base_url' => 'http://www.test.com',
            'get' => '/controller/action/param/colon:param',
        ],
        'http://www.test.com/controller/action/param/colon:param',
    ],
    [
        [
            'base_url' => 'base_url\' => \'http://www.test.com',
            'get' => 'http://www.example.com',
        ],
        'http://www.example.com',
    ],
    [
        [
            'base_url' => 'base_url\' => \'http://www.test.com',
            'get' => '//www.example.com',
        ],
        '//www.example.com',
    ],
    [
        [
            'base_url' => 'base_url\' => \'http://www.test.com',
            'get' => 'schema:example.com',
        ],
        'schema:example.com',
    ],
];
