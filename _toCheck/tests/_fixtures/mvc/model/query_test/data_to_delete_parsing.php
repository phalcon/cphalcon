<?php

/**
 * Fixture for Query test
 *
 * @copyright (c) 2011-present Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Sergii Svyrydenko <sergey.v.svyrydenko@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc\Model
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
use Phalcon\Test\Models\Robots;

return [
    [
        [
            'query' => 'DELETE FROM ' . Robots::class,
        ],
        [
            'tables' => ['robots',],
            'models' => [Robots::class,],
        ],
    ],
    [
        [
            'query' => 'DELETE FROM ' . Robots::class . ' AS r WHERE r.id > 100',
        ],
        [
            'tables' => [
                ['robots', null, 'r',],
            ],
            'models' => [Robots::class,],
            'where' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => ['type' => 'literal', 'value' => '100',],
            ],
        ],
    ],
    [
        [
            'query' => 'DELETE FROM ' . Robots::class . ' as r WHERE r.id > 100',
        ],
        [
            'tables' => [
                ['robots', null, 'r',],
            ],
            'models' => [Robots::class,],
            'where' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => ['type' => 'literal', 'value' => '100',],
            ],
        ],
    ],
    [
        [
            'query' => 'DELETE FROM ' . Robots::class . ' r LIMIT 10',
        ],
        [
            'tables' => [
                ['robots', null, 'r',],
            ],
            'models' => array(
                Robots::class,
            ),
            'limit' => [
                'number' => ['type' => 'literal', 'value' => '10',],
            ],
        ],
    ],
    [
        [
            'query' => 'DELETE FROM ' . Robots::class . ' r WHERE r.id > 100 LIMIT 10',
        ],
        [
            'tables' => [
                ['robots', null, 'r',],
            ],
            'models' => [Robots::class,],
            'where' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => ['type' => 'literal', 'value' => '100',],
            ],
            'limit' => [
                'number' => ['type' => 'literal', 'value' => '10',],
            ],
        ],
    ],
    // Issue 1011
    [
        [
            'query' => 'DELETE FROM ' . Robots::class . ' r WHERE r.id > 100 LIMIT :limit:',
        ],
        [
            'tables' => [
                ['robots', null, 'r',],
            ],
            'models' => [Robots::class,],
            'where' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => ['type' => 'literal', 'value' => '100',],
            ],
            'limit' => [
                'number' => ['type' => 'placeholder', 'value' => ':limit',],
            ],
        ],
    ],
];
