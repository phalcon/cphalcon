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
use Phalcon\Test\Models\Some\Products as SomeProducts;

return [
    [
        [
            'query' => 'UPDATE ' . Robots::class . ' SET name = \'some name\'',
        ],
        [
            'tables' => ['robots',],
            'models' => [Robots::class,],
            'fields' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'values' => [
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some name',],
                ],
            ],
        ],
    ],
    [
        [
            'query' => 'UPDATE ' . Robots::class . ' SET ' . Robots::class . '.name = \'some name\'',
        ],
        [
            'tables' => ['robots',],
            'models' => [Robots::class,],
            'fields' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'values' => [
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some name',],
                ],
            ],
        ],
    ],
    [
        [
            'query' => 'UPDATE ' . SomeProducts::class . ' SET ' . SomeProducts::class . '.name = "some name"',
        ],
        [
            'tables' => ['le_products',],
            'models' => [SomeProducts::class,],
            'fields' => [
                [
                    'type' => 'qualified',
                    'domain' => 'le_products',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'values' => [
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some name',],
                ],
            ],
        ],
    ],
    [
        [
            'query' => 'UPDATE ' . SomeProducts::class . ' p SET p.name = "some name"',
        ],
        [
            'tables' => [
                ['le_products', null, 'p',],
            ],
            'models' => [SomeProducts::class,],
            'fields' => [
                [
                    'type' => 'qualified',
                    'domain' => 'p',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'values' => [
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some name',],
                ],
            ],
        ],
    ],
    [
        [
            'query' => 'UPDATE ' . Robots::class . ' SET ' . Robots::class . '.name = \'some name\', ' . Robots::class . '.year = 1990',
        ],
        [
            'tables' => ['robots',],
            'models' => [Robots::class,],
            'fields' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'year',
                    'balias' => 'year',
                ],
            ],
            'values' => [
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some name',],
                ],
                [
                    'type' => 258,
                    'value' => ['type' => 'literal', 'value' => '1990',],
                ],
            ],
        ],
    ],
    [
        [
            'query' => 'UPDATE ' . SomeProducts::class . ' p SET p.name = "some name", p.year = 1990',
        ],
        [
            'tables' => [
                ['le_products', null, 'p',],
            ],
            'models' => [SomeProducts::class,],
            'fields' => [
                [
                    'type' => 'qualified',
                    'domain' => 'p',
                    'name' => 'name',
                    'balias' => 'name',
                ],
                [
                    'type' => 'qualified',
                    'domain' => 'p',
                    'name' => 'year',
                    'balias' => 'year',
                ],
            ],
            'values' => [
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some name',],
                ],
                [
                    'type' => 258,
                    'value' => ['type' => 'literal', 'value' => '1990',],
                ],
            ],
        ],
    ],
    [
        [
            'query' => 'UPDATE ' . Robots::class . ' SET ' . Robots::class . '.name = \'some name\', ' . Robots::class . '.year = YEAR(current_date()) + ' . Robots::class . '.year',
        ],
        [
            'tables' => ['robots',],
            'models' => [Robots::class,],
            'fields' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'year',
                    'balias' => 'year',
                ],
            ],
            'values' => [
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some name',],
                ],
                [
                    'type' => 43,
                    'value' => [
                        'type' => 'binary-op',
                        'op' => '+',
                        'left' => [
                            'type' => 'functionCall',
                            'name' => 'YEAR',
                            'arguments' => [
                                ['type' => 'functionCall', 'name' => 'current_date',],
                            ],
                        ],
                        'right' => [
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'year',
                            'balias' => 'year',
                        ],
                    ],
                ],
            ],
        ],
    ],
    [
        [
            'query' => 'UPDATE ' . Robots::class . ' AS r SET r.name = \'some name\', r.year = YEAR(current_date()) + r.year',
        ],
        [
            'tables' => [
                ['robots', null, 'r',],
            ],
            'models' => [Robots::class,],
            'fields' => [
                [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'name',
                    'balias' => 'name',
                ],
                [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'year',
                    'balias' => 'year',
                ],
            ],
            'values' => [
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some name',],
                ],
                [
                    'type' => 43,
                    'value' => [
                        'type' => 'binary-op',
                        'op' => '+',
                        'left' => [
                            'type' => 'functionCall',
                            'name' => 'YEAR',
                            'arguments' => [
                                ['type' => 'functionCall', 'name' => 'current_date',],
                            ],
                        ],
                        'right' => [
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'year',
                            'balias' => 'year',
                        ],
                    ],
                ],
            ],
        ],
    ],
    [
        [
            'query' => 'UPDATE ' . Robots::class . ' AS r SET r.name = \'some name\' WHERE r.id > 100',
        ],
        [
            'tables' => [
                ['robots', null, 'r',],
            ],
            'models' => [Robots::class,],
            'fields' => [
                [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'values' => [
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some name',],
                ],
            ],
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
            'query' => 'UPDATE ' . Robots::class . ' as r set r.name = \'some name\', r.year = r.year*2 where r.id > 100 and r.id <= 200',
        ],
        [
            'tables' => [
                ['robots', null, 'r',],
            ],
            'models' => [Robots::class,],
            'fields' => [
                [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'name',
                    'balias' => 'name',
                ],
                [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'year',
                    'balias' => 'year',
                ],
            ],
            'values' => [
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some name',],
                ],
                [
                    'type' => 42,
                    'value' => [
                        'type' => 'binary-op',
                        'op' => '*',
                        'left' => [
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'year',
                            'balias' => 'year',
                        ],
                        'right' => ['type' => 'literal', 'value' => '2',],
                    ],
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '<=',
                'left' => [
                    'type' => 'binary-op',
                    'op' => '>',
                    'left' => [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'id',
                        'balias' => 'id',
                    ],
                    'right' => [
                        'type' => 'binary-op',
                        'op' => 'AND',
                        'left' => [
                            'type' => 'literal',
                            'value' => '100',
                        ],
                        'right' => [
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'id',
                            'balias' => 'id',
                        ],
                    ],
                ],
                'right' => ['type' => 'literal', 'value' => '200',],
            ],
        ],
    ],
    [
        [
            'query' => 'update ' . strtolower(Robots::class) . ' as r set r.name = \'some name\' LIMIT 10',
        ],
        [
            'tables' => [
                ['robots', null, 'r',],
            ],
            'models' => [strtolower(Robots::class),],
            'fields' => [
                [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'values' => [
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some name',],
                ],
            ],
            'limit' => [
                'number' => ['type' => 'literal', 'value' => '10',],
            ],
        ],
    ],
    [
        [
            'query' => 'UPDATE ' . Robots::class . ' r SET r.name = \'some name\' LIMIT 10',
        ],
        [
            'tables' => [
                ['robots', null, 'r',],
            ],
            'models' => [Robots::class,],
            'fields' => [
                [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'values' => [
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some name',],
                ],
            ],
            'limit' => [
                'number' => ['type' => 'literal', 'value' => '10',],
            ],
        ],
    ],
    [
        [
            'query' => 'UPDATE ' . Robots::class . ' AS r SET r.name = \'some name\' WHERE r.id > 100 LIMIT 10',
        ],
        [
            'tables' => [
                ['robots', null, 'r',],
            ],
            'models' => [Robots::class,],
            'fields' => [
                [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'values' => [
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some name',],
                ],
            ],
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
            'query' => 'UPDATE ' . Robots::class . ' r SET r.name = \'some name\' LIMIT ?1',
        ],
        [
            'tables' => [
                ['robots', null, 'r',
                ],
            ],
            'models' => [Robots::class,],
            'fields' => [
                [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'values' => [
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some name',],
                ],
            ],
            'limit' => [
                'number' => ['type' => 'placeholder', 'value' => ':1',],
            ],
        ],
    ],
];
