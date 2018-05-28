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
            'uri' => '',
            'controller' => 'index',
            'action' => 'index',
            'params' => []
        ]
    ],
    [
        [
            'uri' => '/',
            'controller' => 'index',
            'action' => 'index',
            'params' => []
        ]
    ],
    [
        [
            'uri' => '/documentation/index/hellao/aaadpqñda/bbbAdld/cc-ccc',
            'controller' => 'documentation',
            'action' => 'index',
            'params' => ['hellao', 'aaadpqñda', 'bbbAdld', 'cc-ccc']
        ]
    ],
    [
        [
            'uri' => '/documentation/index/',
            'controller' => 'documentation',
            'action' => 'index',
            'params' => []
        ]
    ],
    [
        [
            'uri' => '/documentation/index',
            'controller' => 'documentation',
            'action' => 'index',
            'params' => []
        ]
    ],
    [
        [
            'uri' => '/documentation/',
            'controller' => 'documentation',
            'action' => null,
            'params' => []
        ]
    ],
    [
        [
            'uri' => '/documentation',
            'controller' => 'documentation',
            'action' => null,
            'params' => []
        ]
    ],
    [
        [
            'uri' => '/system/admin/a/edit/hellao/aaadp',
            'controller' => 'admin',
            'action' => 'edit',
            'params' => ['hellao', 'aaadp']
        ]
    ],
    [
        [
            'uri' => '/es/news',
            'controller' => 'news',
            'action' => 'index',
            'params' => ['language' => 'es']
        ]
    ],
    [
        [
            'uri' => '/admin/posts/edit/100',
            'controller' => 'posts',
            'action' => 'edit',
            'params' => ['id' => 100]
        ]
    ],
    [
        [
            'uri' => '/posts/2010/02/10/title/content',
            'controller' => 'posts',
            'action' => 'show',
            'params' => ['year' => '2010', 'month' => '02', 'day' => '10', 0 => 'title', 1 => 'content']
        ]
    ],
    [
        [
            'uri' => '/manual/en/translate.adapter.html',
            'controller' => 'manual',
            'action' => 'show',
            'params' => ['language' => 'en', 'file' => 'translate.adapter']
        ]
    ],
    [
        [
            'uri' => '/named-manual/en/translate.adapter.html',
            'controller' => 'manual',
            'action' => 'show',
            'params' => ['language' => 'en', 'file' => 'translate.adapter']
        ]
    ],
    [
        [
            'uri' => '/posts/1999/s/le-nice-title',
            'controller' => 'posts',
            'action' => 'show',
            'params' => ['year' => '1999', 'title' => 'le-nice-title']
        ]
    ],
    [
        [
            'uri' => '/feed/fr/blog/diaporema.json',
            'controller' => 'feed',
            'action' => 'get',
            'params' => ['lang' => 'fr', 'blog' => 'diaporema', 'type' => 'json']
        ]
    ],
    [
        [
            'uri' => '/posts/delete/150',
            'controller' => 'posts',
            'action' => 'delete',
            'params' => ['id' => '150']
        ]
    ],
    [
        [
            'uri' => '/very/static/route',
            'controller' => 'static',
            'action' => 'route',
            'params' => []
        ]
    ],
];
