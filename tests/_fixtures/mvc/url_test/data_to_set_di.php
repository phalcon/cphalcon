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
        '/admin/:controller/p/:action',
        [
            'controller' => 1,
            'action'     => 2,
        ],
        'methodName' => 'add',
        'setname' => 'adminProducts',
    ],
    [
        '/api/classes/{class}',
        'methodName' => 'add',
        'setname' => 'classApi',
    ],
    [
        '/{year}/{month}/{title}',
        'methodName' => 'add',
        'setname' => 'blogPost',
    ],
    [
        '/wiki/{article:[a-z]+}',
        'methodName' => 'add',
        'setname' => 'wikipedia',
    ],
    [
        '/news/{country:[a-z]{2}}/([a-z+])/([a-z\-+])/{page}',
        [
            'section' => 2,
            'article' => 3,
        ],
        'methodName' => 'add',
        'setname' => 'news',
    ],
    [
        '/([a-z]{2})/([a-zA-Z0-9_-]+)(/|)',
        [
            'lang'       => 1,
            'module'     => 'main',
            'controller' => 2,
            'action'     => 'index',
        ],
        'methodName' => 'add',
        'setname' => 'lang-controller',
    ],
];
