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
use Phalcon\Test\Models\Robotters;

return [
    [
        [
            'query' => 'INSERT INTO ' . Robots::class . ' VALUES (NULL, \'some robot\', 1945)',
        ],
        [
            'model' => Robots::class,
            'table' => 'robots',
            'values' => [
                [
                    'type' => 322,
                    'value' => ['type' => 'literal', 'value' => 'NULL',],
                ],
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some robot',],
                ],
                [
                    'type' => 258,
                    'value' => ['type' => 'literal', 'value' => '1945',],
                ],
            ],
        ],
    ],
    [
        [
            'query' => 'insert into ' . strtolower(Robots::class) . ' values (null, \'some robot\', 1945)',
        ],
        [
            'model' => strtolower(Robots::class),
            'table' => 'robots',
            'values' => [
                [
                    'type' => 322,
                    'value' => ['type' => 'literal', 'value' => 'NULL',],
                ],
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some robot',],
                ],
                [
                    'type' => 258,
                    'value' => ['type' => 'literal', 'value' => '1945',],
                ],
            ],
        ],
    ],
    [
        [
            'query' => 'INSERT INTO ' . SomeProducts::class . ' VALUES ("Some name", 100.15, current_date(), now())',
        ],
        [
            'model' => SomeProducts::class,
            'table' => 'le_products',
            'values' => [
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'Some name',],
                ],
                [
                    'type' => 259,
                    'value' => ['type' => 'literal', 'value' => '100.15',],
                ],
                [
                    'type' => 350,
                    'value' => ['type' => 'functionCall', 'name' => 'current_date',],
                ],
                [
                    'type' => 350,
                    'value' => ['type' => 'functionCall', 'name' => 'now',],
                ],
            ],
        ],
    ],
    [
        [
            'query' => 'INSERT INTO ' . Robots::class . ' VALUES ((1+1000*:le_id:), CONCAT(\'some\', \'robot\'), 2011)',
        ],
        [
            'model' => Robots::class,
            'table' => 'robots',
            'values' => [
                [
                    'type' => 356,
                    'value' => [
                        'type' => 'parentheses',
                        'left' => [
                            'type' => 'binary-op',
                            'op' => '*',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '+',
                                'left' => ['type' => 'literal', 'value' => '1',],
                                'right' => ['type' => 'literal', 'value' => '1000',],
                            ],
                            'right' => [
                                'type' => 'placeholder',
                                'value' => ':le_id',
                            ],
                        ],
                    ],
                ],
                [
                    'type' => 350,
                    'value' => [
                        'type' => 'functionCall',
                        'name' => 'CONCAT',
                        'arguments' => [
                            ['type' => 'literal', 'value' => '\'some\'',],
                            ['type' => 'literal', 'value' => '\'robot\'',],
                        ],
                    ],
                ],
                [
                    'type' => 258,
                    'value' => ['type' => 'literal', 'value' => '2011',],
                ],
            ],
        ],
    ],
    [
        [
            'query' => 'INSERT INTO ' . Robots::class . ' (name, type, year) VALUES (\'a name\', \'virtual\', ?0)',
        ],
        [
            'model' => Robots::class,
            'table' => 'robots',
            'fields' => ['name', 'type', 'year',],
            'values' => [
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'a name',],
                ],
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'virtual',],
                ],
                [
                    'type' => 273,
                    'value' => ['type' => 'placeholder', 'value' => ':0',],
                ],
            ],
        ],
    ],
    [
        [
            'query' => 'INSERT INTO ' . Robotters::class . ' VALUES (NULL, \'some robot\', 1945)',
        ],
        [
            'model' => Robotters::class,
            'table' => 'robots',
            'values' => [
                [
                    'type' => 322,
                    'value' => ['type' => 'literal', 'value' => 'NULL',],
                ],
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some robot',],
                ],
                [
                    'type' => 258,
                    'value' => ['type' => 'literal', 'value' => '1945',],
                ],
            ],
        ],
    ],
    [
        [
            'query' => 'insert into ' . strtolower(Robotters::class) . ' values (null, \'some robot\', 1945)',
        ],
        [
            'model' => strtolower(Robotters::class),
            'table' => 'robots',
            'values' => [
                [
                    'type' => 322,
                    'value' => ['type' => 'literal', 'value' => 'NULL',],
                ],
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'some robot',],
                ],
                [
                    'type' => 258,
                    'value' => ['type' => 'literal', 'value' => '1945',],
                ],
            ],
        ],
    ],
    [
        [
            'query' => 'INSERT INTO ' . Robotters::class . ' VALUES ((1+1000*:le_id:), CONCAT(\'some\', \'robot\'), 2011)',
        ],
        [
            'model' => Robotters::class,
            'table' => 'robots',
            'values' => [
                [
                    'type' => 356,
                    'value' => [
                        'type' => 'parentheses',
                        'left' => [
                            'type' => 'binary-op',
                            'op' => '*',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '+',
                                'left' => ['type' => 'literal', 'value' => '1',],
                                'right' => ['type' => 'literal', 'value' => '1000',],
                            ],
                            'right' => ['type' => 'placeholder', 'value' => ':le_id',],
                        ],
                    ],
                ],
                [
                    'type' => 350,
                    'value' => [
                        'type' => 'functionCall',
                        'name' => 'CONCAT',
                        'arguments' => [
                            ['type' => 'literal', 'value' => '\'some\'',],
                            ['type' => 'literal', 'value' => '\'robot\'',],
                        ],
                    ],
                ],
                [
                    'type' => 258,
                    'value' => ['type' => 'literal', 'value' => '2011',],
                ],
            ],
        ],
    ],
    [
        [
            'query' => 'INSERT INTO ' . Robotters::class . ' (theName, theType, theYear) VALUES (\'a name\', \'virtual\', ?0)',
        ],
        [
            'model' => Robotters::class,
            'table' => 'robots',
            'fields' => [
                'theName',
                'theType',
                'theYear',
            ],
            'values' => [
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'a name',],
                ],
                [
                    'type' => 260,
                    'value' => ['type' => 'literal', 'value' => 'virtual',],
                ],
                [
                    'type' => 273,
                    'value' => ['type' => 'placeholder', 'value' => ':0',],
                ],
            ],
        ],
    ],
];
