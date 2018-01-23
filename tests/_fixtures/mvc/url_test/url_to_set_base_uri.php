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
    //Tests the url with a controller and action
    [
        [
            'base_url' => '/',
            'param' => [
                'for'        => 'adminProducts',
                'controller' => 'products',
                'action'     => 'index',
            ],
        ],
        '/admin/products/p/index',
    ],
    //Tests the url with a controller
    [
        [
            'base_url' => '/',
            'param' => [
                'for'   => 'classApi',
                'class' => 'Some',
            ],
        ],
        '/api/classes/Some',
    ],
    //Tests the url with a year/month/title
    [
        [
            'base_url' => '/',
            'param' => [
                'for'        => 'lang-controller',
                'lang'       => 'de',
                'controller' => 'index',
            ],
        ],
        '/de/index',
    ],
    //Tests the url for a different language
    [
        [
            'base_url' => '/',
            'param' => [
                'for'   => 'blogPost',
                'year'  => '2010',
                'month' => '10',
                'title' => 'cloudflare-anade-recursos-a-tu-servidor',
            ],
        ],
        '/2010/10/cloudflare-anade-recursos-a-tu-servidor',
    ],
    //Tests the url with external website
    [
        [
            'base_url' => '/',
            'param' => [
                'for'     => 'wikipedia',
                'article' => 'Television_news',
            ],
        ],
        '/wiki/Television_news'
    ]
];
