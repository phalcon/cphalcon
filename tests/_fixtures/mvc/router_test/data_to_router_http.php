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
        '/docs/index',
        [
            'controller' => 'documentation2222',
            'action' => 'index'
        ],
    ],
    [
        'methodName' => 'addPost',
        '/docs/index',
        [
            'controller' => 'documentation3',
            'action' => 'index'
        ],
    ],
    [
        'methodName' => 'addGet',
        '/docs/index',
        [
            'controller' => 'documentation4',
            'action' => 'index'
        ],
    ],
    [
        'methodName' => 'addPut',
        '/docs/index',
        [
            'controller' => 'documentation5',
            'action' => 'index'
        ],
    ],
    [
        'methodName' => 'addDelete',
        '/docs/index',
        [
            'controller' => 'documentation6',
            'action' => 'index'
        ],
    ],
    [
        'methodName' => 'addOptions',
        '/docs/index',
        [
            'controller' => 'documentation7',
            'action' => 'index'
        ],
    ],
    [
        'methodName' => 'addHead',
        '/docs/index',
        [
            'controller' => 'documentation8',
            'action' => 'index'
        ],
    ],
    [
        'methodName' => 'addPurge',
        '/docs/index',
        [
            'controller' => 'documentation9',
            'action' => 'index'
        ],
    ],
    [
        'methodName' => 'addTrace',
        '/docs/index',
        [
            'controller' => 'documentation10',
            'action' => 'index'
        ],
    ],
    [
        'methodName' => 'addConnect',
        '/docs/index',
        [
            'controller' => 'documentation11',
            'action' => 'index'
        ],
    ],
];
