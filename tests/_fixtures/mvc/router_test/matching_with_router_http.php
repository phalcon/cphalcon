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
            'method' => null,
            'uri' => '/documentation/index/hello',
            'controller' => 'documentation',
            'action' => 'index',
            'params' => ['hello']
        ]
    ],
    [
        [
            'method' => 'POST',
            'uri' => '/docs/index',
            'controller' => 'documentation3',
            'action' => 'index',
            'params' => []]
    ],
    [
        [
            'method' => 'GET',
            'uri' => '/docs/index',
            'controller' => 'documentation4',
            'action' => 'index',
            'params' => []
        ]
    ],
    [
        [
            'method' => 'PUT',
            'uri' => '/docs/index',
            'controller' => 'documentation5',
            'action' => 'index',
            'params' => []
        ]
    ],
    [
        [
            'method' => 'DELETE',
            'uri' => '/docs/index',
            'controller' => 'documentation6',
            'action' => 'index',
            'params' => []
        ]
    ],
    [
        [
            'method' => 'OPTIONS',
            'uri' => '/docs/index',
            'controller' => 'documentation7',
            'action' => 'index',
            'params' => []
        ]
    ],
    [
        [
            'method' => 'HEAD',
            'uri' => '/docs/index',
            'controller' => 'documentation8',
            'action' => 'index',
            'params' => []
        ]
    ],
    [
        [
            'method' => 'PURGE',
            'uri' => '/docs/index',
            'controller' => 'documentation9',
            'action' => 'index',
            'params' => []
        ]
    ],
    [
        [
            'method' => 'TRACE',
            'uri' => '/docs/index',
            'controller' => 'documentation10',
            'action' => 'index',
            'params' => []
        ]
    ],
    [
        [
            'method' => 'CONNECT',
            'uri' => '/docs/index',
            'controller' => 'documentation11',
            'action' => 'index',
            'params' => []
        ]
    ],
];
