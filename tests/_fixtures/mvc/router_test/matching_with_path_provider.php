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
        '/route0',
        'Feed',
        [
            'controller' => 'feed'
        ]
    ],
    [
        '/route1',
        'Feed::get',
        [
            'controller' => 'feed',
            'action' => 'get',
        ]
    ],
    [
        '/route2',
        'News::Posts::show',
        [
            'module' => 'News',
            'controller' => 'posts',
            'action' => 'show',
        ]
    ],
    [
        '/route3',
        'MyApp\Controllers\Posts::show',
        [
            'namespace' => 'MyApp\Controllers',
            'controller' => 'posts',
            'action' => 'show',
        ]
    ],
    [
        '/route3',
        'MyApp\Controllers\::show',
        [
            'controller' => '',
            'action' => 'show',
        ]
    ],
    [
        '/route3',
        'News::MyApp\Controllers\Posts::show',
        [
            'module' => 'News',
            'namespace' => 'MyApp\\Controllers',
            'controller' => 'posts',
            'action' => 'show',
        ]
    ],
    [
        '/route3',
        '\Posts::show',
        [
            'controller' => 'posts',
            'action' => 'show',
        ]
    ],
];
