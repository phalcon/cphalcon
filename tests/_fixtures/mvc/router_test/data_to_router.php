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
        'methodName' => 'add',
        '/',
        [
            'controller' => 'index',
            'action' => 'index'
        ],
    ],
    [
        'methodName'=> 'add',
        '/system/:controller/a/:action/:params',
        [
            'controller' => 1,
            'action' => 2,
            'params' => 3,
        ]
    ],
    [
        'methodName'=> 'add',
        '/([a-z]{2})/:controller',
        [
            'controller' => 2,
            'action' => 'index',
            'language' => 1
        ]
    ],
    [
        'methodName'=> 'add',
        '/admin/:controller/:action/:int',
        [
            'controller' => 1,
            'action' => 2,
            'id' => 3
        ]
    ],
    [
        'methodName'=> 'add',
        '/posts/([0-9]{4})/([0-9]{2})/([0-9]{2})/:params',
        [
            'controller' => 'posts',
            'action' => 'show',
            'year' => 1,
            'month' => 2,
            'day' => 3,
            'params' => 4,
        ]
    ],
    [
        'methodName'=> 'add',
        '/manual/([a-z]{2})/([a-z\.]+)\.html',
        [
            'controller' => 'manual',
            'action' => 'show',
            'language' => 1,
            'file' => 2
        ]
    ],
    [
        'methodName'=> 'add',
        '/named-manual/{language:([a-z]{2})}/{file:[a-z\.]+}\.html',
        [
            'controller' => 'manual',
            'action' => 'show',
        ]
    ],
    [
        'methodName'=> 'add',
        '/very/static/route',
        [
            'controller' => 'static',
            'action' => 'route'
        ]
    ],
    [
        'methodName'=> 'add',
        '/feed/{lang:[a-z]+}/blog/{blog:[a-z\-]+}\.{type:[a-z\-]+}',
        'Feed::get'
    ],
    [
        'methodName'=> 'add',
        '/posts/{year:[0-9]+}/s/{title:[a-z\-]+}',
        'Posts::show'
    ],
    [
        'methodName'=> 'add',
        '/posts/delete/{id}',
        'Posts::delete'
    ],
    [
        'methodName'=> 'add',
        '/show/{id:video([0-9]+)}/{title:[a-z\-]+}',
        'Videos::show'
    ],
];
