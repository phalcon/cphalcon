<?php

use Phalcon\Test\Models\Deles;
use Phalcon\Test\Models\Parts;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\People;
use Phalcon\Test\Models\Products;
use Phalcon\Test\Models\Personers;
use Phalcon\Test\Models\Robotters;
use Phalcon\Test\Models\RobotsParts;
use Phalcon\Test\Models\RobottersDeles;
use Phalcon\Test\Models\Some\Products as SomeProducts;
use Phalcon\Test\Models\Some\Robotters as SomeRobotters;

return [
    [
        "phql"     => 'SELECT * FROM ' . Robots::class,
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
        ],
    ],
    [
        "phql"     => 'SELECT * FROM ' . SomeProducts::class,
        "expected" => [
            'models' => [
                SomeProducts::class,
            ],
            'tables' => [
                'le_products',
            ],
            'columns' => [
                lcfirst(SomeProducts::class) => [
                    'type' => 'object',
                    'model' => SomeProducts::class,
                    'column' => 'le_products',
                    'balias' => lcfirst(SomeProducts::class),
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ' . SomeProducts::class . '.* FROM ' . SomeProducts::class,
        "expected" => [
            'models' => [
                SomeProducts::class,
            ],
            'tables' => [
                'le_products',
            ],
            'columns' => [
                lcfirst(SomeProducts::class) => [
                    'type' => 'object',
                    'model' => SomeProducts::class,
                    'column' => 'le_products',
                    'balias' => lcfirst(SomeProducts::class),
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT p.* FROM ' . SomeProducts::class . ' p',
        "expected" => [
            'models' => [
                SomeProducts::class,
            ],
            'tables' => [
                [
                    'le_products',
                    null,
                    'p',
                ],
            ],
            'columns' => [
                'p' => [
                    'type' => 'object',
                    'model' => SomeProducts::class,
                    'column' => 'p',
                    'balias' => 'p',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ' . Robots::class . '.* FROM ' . Robots::class,
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT r.* FROM ' . Robots::class . ' r',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                'r' => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => 'r',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT r.* FROM ' . Robots::class . ' AS r',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                'r' => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => 'r',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT id, name FROM ' . Robots::class,
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                'id' => [
                    'type' => 'scalar',
                    'balias' => 'id',
                    'sqlAlias' => 'id',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'id',
                        'balias' => 'id',
                    ],
                ],
                'name' => [
                    'type' => 'scalar',
                    'balias' => 'name',
                    'sqlAlias' => 'name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT r.id, r.name FROM ' . Robots::class . ' AS r',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                'id' => [
                    'type' => 'scalar',
                    'balias' => 'id',
                    'sqlAlias' => 'id',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'id',
                        'balias' => 'id',
                    ],
                ],
                'name' => [
                    'type' => 'scalar',
                    'balias' => 'name',
                    'sqlAlias' => 'name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT r.id AS le_id, r.name AS le_name FROM ' . Robots::class . ' AS r',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                'le_id' => [
                    'type' => 'scalar',
                    'balias' => 'le_id',
                    'sqlAlias' => 'le_id',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'id',
                        'balias' => 'id',
                    ],
                ],
                'le_name' => [
                    'type' => 'scalar',
                    'balias' => 'le_name',
                    'sqlAlias' => 'le_name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ' . Robots::class . '.id AS le_id, ' . Robots::class . '.name AS le_name FROM ' . Robots::class,
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                'le_id' => [
                    'type' => 'scalar',
                    'balias' => 'le_id',
                    'sqlAlias' => 'le_id',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'id',
                        'balias' => 'id',
                    ],
                ],
                'le_name' => [
                    'type' => 'scalar',
                    'balias' => 'le_name',
                    'sqlAlias' => 'le_name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT \'\' empty_str, 10.5 double_number, 1000 AS long_number FROM ' . Robots::class,
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                'empty_str' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'literal',
                        'value' => '\'\'',
                    ],
                    'balias' => 'empty_str',
                    'sqlAlias' => 'empty_str',
                ],
                'double_number' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'literal',
                        'value' => '10.5',
                    ],
                    'balias' => 'double_number',
                    'sqlAlias' => 'double_number',
                ],
                'long_number' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'literal',
                        'value' => '1000',
                    ],
                    'balias' => 'long_number',
                    'sqlAlias' => 'long_number',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ' . People::class . '.cedula FROM ' . People::class,
        "expected" => [
            'models' => [
                People::class,
            ],
            'tables' => [
                'personas',
            ],
            'columns' => [
                'cedula' => [
                    'type' => 'scalar',
                    'balias' => 'cedula',
                    'sqlAlias' => 'cedula',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'personas',
                        'name' => 'cedula',
                        'balias' => 'cedula',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'select ' . strtolower(People::class) . '.cedula from ' . strtolower(People::class),
        "expected" => [
            'models' => [
                strtolower(People::class),
            ],
            'tables' => [
                'personas',
            ],
            'columns' => [
                'cedula' => [
                    'type' => 'scalar',
                    'balias' => 'cedula',
                    'sqlAlias' => 'cedula',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'personas',
                        'name' => 'cedula',
                        'balias' => 'cedula',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT p.cedula AS cedula FROM ' . People::class . ' p',
        "expected" => [
            'models' => [
                People::class,
            ],
            'tables' => [
                [
                    'personas',
                    null,
                    'p',
                ],
            ],
            'columns' => [
                'cedula' => [
                    'type' => 'scalar',
                    'balias' => 'cedula',
                    'sqlAlias' => 'cedula',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'p',
                        'name' => 'cedula',
                        'balias' => 'cedula',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT CONCAT(cedula,\'-\',nombres) AS nombre FROM ' . People::class,
        "expected" => [
            'models' => [
                People::class,
            ],
            'tables' => [
                'personas',
            ],
            'columns' => [
                'nombre' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'CONCAT',
                        'arguments' => [
                            [
                                'type' => 'qualified',
                                'domain' => 'personas',
                                'name' => 'cedula',
                                'balias' => 'cedula',
                            ],
                            [
                                'type' => 'literal',
                                'value' => '\'-\'',
                            ],
                            [
                                'type' => 'qualified',
                                'domain' => 'personas',
                                'name' => 'nombres',
                                'balias' => 'nombres',
                            ],
                        ],
                    ],
                    'balias' => 'nombre',
                    'sqlAlias' => 'nombre',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT CONCAT(' . People::class . '.cedula,\'-\',' . People::class . '.nombres) AS nombre FROM ' . People::class,
        "expected" => [
            'models' => [
                People::class,
            ],
            'tables' => [
                'personas',
            ],
            'columns' => [
                'nombre' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'CONCAT',
                        'arguments' => [
                            [
                                'type' => 'qualified',
                                'domain' => 'personas',
                                'name' => 'cedula',
                                'balias' => 'cedula',
                            ],
                            [
                                'type' => 'literal',
                                'value' => '\'-\'',
                            ],
                            [
                                'type' => 'qualified',
                                'domain' => 'personas',
                                'name' => 'nombres',
                                'balias' => 'nombres',
                            ],
                        ],
                    ],
                    'balias' => 'nombre',
                    'sqlAlias' => 'nombre',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' JOIN ' . RobotsParts::class,
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
                lcfirst(RobotsParts::class) => [
                    'type' => 'object',
                    'model' => RobotsParts::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobotsParts::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'robots_parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'id',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robots_id',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' CROSS JOIN ' . RobotsParts::class,
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
                lcfirst(RobotsParts::class) => [
                    'type' => 'object',
                    'model' => RobotsParts::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobotsParts::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'CROSS',
                    'source' => [
                        'robots_parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'id',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robots_id',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' LEFT JOIN ' . RobotsParts::class . ' RIGHT JOIN ' . Parts::class,
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(RobotsParts::class) => [
                    'type' => 'object',
                    'model' => RobotsParts::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobotsParts::class),
                ],
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
                lcfirst(Parts::class) => [
                    'type' => 'object',
                    'model' => Parts::class,
                    'column' => 'parts',
                    'balias' => lcfirst(Parts::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'LEFT',
                    'source' => [
                        'robots_parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'id',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robots_id',
                            ],
                        ],
                    ],
                ],
                [
                    'type' => 'RIGHT',
                    'source' => [
                        'parts',
                        null,
                    ],
                    'conditions' => [
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . RobotsParts::class . ' LEFT OUTER JOIN ' . Robots::class . ' RIGHT OUTER JOIN ' . Parts::class,
        "expected" => [
            'models' => [
                RobotsParts::class,
            ],
            'tables' => [
                'robots_parts',
            ],
            'columns' => [
                lcfirst(RobotsParts::class) => [
                    'type' => 'object',
                    'model' => RobotsParts::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobotsParts::class),
                ],
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
                lcfirst(Parts::class) => [
                    'type' => 'object',
                    'model' => Parts::class,
                    'column' => 'parts',
                    'balias' => lcfirst(Parts::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'LEFT',
                    'source' => [
                        'robots',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robots_id',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'id',
                            ],
                        ],
                    ],
                ],
                [
                    'type' => 'RIGHT',
                    'source' => [
                        'parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'parts_id',
                                'balias' => 'parts_id',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'parts',
                                'name' => 'id',
                                'balias' => 'id',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' JOIN ' . RobotsParts::class . ' ON ' . Robots::class . '.id = ' . RobotsParts::class . '.robots_id',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
                lcfirst(RobotsParts::class) => [
                    'type' => 'object',
                    'model' => RobotsParts::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobotsParts::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'robots_parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'id',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robots_id',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' LEFT OUTER JOIN ' . RobotsParts::class . ' ON ' . Robots::class . '.id = ' . RobotsParts::class . '.robots_id AND ' . RobotsParts::class . '.robots_id = ' . Robots::class . '.id WHERE ' . Robots::class . '.id IS NULL',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
                lcfirst(RobotsParts::class) => [
                    'type' => 'object',
                    'model' => RobotsParts::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobotsParts::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'LEFT',
                    'source' => [
                        'robots_parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => [
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ],
                                'right' => [
                                    'type' => 'binary-op',
                                    'op' => 'AND',
                                    'left' => [
                                        'type' => 'qualified',
                                        'domain' => 'robots_parts',
                                        'name' => 'robots_id',
                                        'balias' => 'robots_id',
                                    ],
                                    'right' => [
                                        'type' => 'qualified',
                                        'domain' => 'robots_parts',
                                        'name' => 'robots_id',
                                        'balias' => 'robots_id',
                                    ],
                                ],
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'id',
                            ],
                        ],
                    ],
                ],
            ],
            'where' => [
                'type' => 'unary-op',
                'op' => ' IS NULL',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'id',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' RIGHT OUTER JOIN ' . RobotsParts::class . ' ON ' . Robots::class . '.id = ' . RobotsParts::class . '.robots_id AND ' . RobotsParts::class . '.robots_id = ' . Robots::class . '.id WHERE ' . RobotsParts::class . '.robots_id IS NOT NULL',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
                lcfirst(RobotsParts::class) => [
                    'type' => 'object',
                    'model' => RobotsParts::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobotsParts::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'RIGHT',
                    'source' => [
                        'robots_parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => [
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ],
                                'right' => [
                                    'type' => 'binary-op',
                                    'op' => 'AND',
                                    'left' => [
                                        'type' => 'qualified',
                                        'domain' => 'robots_parts',
                                        'name' => 'robots_id',
                                        'balias' => 'robots_id',
                                    ],
                                    'right' => [
                                        'type' => 'qualified',
                                        'domain' => 'robots_parts',
                                        'name' => 'robots_id',
                                        'balias' => 'robots_id',
                                    ],
                                ],
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'id',
                            ],
                        ],
                    ],
                ],
            ],
            'where' => [
                'type' => 'unary-op',
                'op' => ' IS NOT NULL',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots_parts',
                    'name' => 'robots_id',
                    'balias' => 'robots_id',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' FULL OUTER JOIN ' . RobotsParts::class,
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
                lcfirst(RobotsParts::class) => [
                    'type' => 'object',
                    'model' => RobotsParts::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobotsParts::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'FULL OUTER',
                    'source' => [
                        'robots_parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'id',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robots_id',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . RobotsParts::class . ' JOIN ' . Robots::class,
        "expected" => [
            'models' => [
                RobotsParts::class,
            ],
            'tables' => [
                'robots_parts',
            ],
            'columns' => [
                lcfirst(RobotsParts::class) => [
                    'type' => 'object',
                    'model' => RobotsParts::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobotsParts::class),
                ],
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'robots',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robots_id',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'id',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT r.*, p.* FROM ' . Robots::class . ' AS r JOIN ' . RobotsParts::class . ' AS p',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                'r' => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => 'r',
                ],
                'p' => [
                    'type' => 'object',
                    'model' => RobotsParts::class,
                    'column' => 'p',
                    'balias' => 'p',
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'robots_parts',
                        null,
                        'p',
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'r',
                                'name' => 'id',
                                'balias' => 'id',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'p',
                                'name' => 'robots_id',
                                'balias' => 'robots_id',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' AS r JOIN ' . RobotsParts::class . ' AS p',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robots::class),
                ],
                lcfirst(RobotsParts::class) => [
                    'type' => 'object',
                    'model' => RobotsParts::class,
                    'column' => 'p',
                    'balias' => lcfirst(RobotsParts::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'robots_parts',
                        null,
                        'p',
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'r',
                                'name' => 'id',
                                'balias' => 'id',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'p',
                                'name' => 'robots_id',
                                'balias' => 'robots_id',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT r.* FROM ' . Robots::class . ' r INNER JOIN ' . RobotsParts::class,
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                'r' => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => 'r',
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'robots_parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'r',
                                'name' => 'id',
                                'balias' => 'id',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robots_id',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ( ' . People::class . '.cupo + 100) / (' . Products::class . '.price * 0.15) FROM ' . People::class . ' JOIN ' . Products::class,
        "expected" => [
            'models' => [
                People::class,
            ],
            'tables' => [
                'personas',
            ],
            'columns' => [
                '_0' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'binary-op',
                        'op' => '/',
                        'left' => [
                            'type' => 'parentheses',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '+',
                                'left' => [
                                    'type' => 'qualified',
                                    'domain' => 'personas',
                                    'name' => 'cupo',
                                    'balias' => 'cupo',
                                ],
                                'right' => [
                                    'type' => 'literal',
                                    'value' => '100',
                                ],
                            ],
                        ],
                        'right' => [
                            'type' => 'parentheses',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '*',
                                'left' => [
                                    'type' => 'qualified',
                                    'domain' => 'products',
                                    'name' => 'price',
                                    'balias' => 'price',
                                ],
                                'right' => [
                                    'type' => 'literal',
                                    'value' => '0.15',
                                ],
                            ],
                        ],
                    ],
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'products',
                        null,
                    ],
                    'conditions' => [
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ( ' . People::class . '.cupo + 100) / (' . SomeProducts::class . '.price * 0.15) AS price FROM ' . People::class . ' JOIN ' . SomeProducts::class,
        "expected" => [
            'models' => [
                People::class,
            ],
            'tables' => [
                'personas',
            ],
            'columns' => [
                'price' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'binary-op',
                        'op' => '/',
                        'left' => [
                            'type' => 'parentheses',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '+',
                                'left' => [
                                    'type' => 'qualified',
                                    'domain' => 'personas',
                                    'name' => 'cupo',
                                    'balias' => 'cupo',
                                ],
                                'right' => [
                                    'type' => 'literal',
                                    'value' => '100',
                                ],
                            ],
                        ],
                        'right' => [
                            'type' => 'parentheses',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '*',
                                'left' => [
                                    'type' => 'qualified',
                                    'domain' => 'le_products',
                                    'name' => 'price',
                                    'balias' => 'price',
                                ],
                                'right' => [
                                    'type' => 'literal',
                                    'value' => '0.15',
                                ],
                            ],
                        ],
                    ],
                    'balias' => 'price',
                    'sqlAlias' => 'price',
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'le_products',
                        null,
                    ],
                    'conditions' => [
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT (p.cupo + 100) / (s.price * 0.15) AS price FROM ' . People::class . ' AS p JOIN ' . SomeProducts::class . ' AS s',
        "expected" => [
            'models' => [
                People::class,
            ],
            'tables' => [
                [
                    'personas',
                    null,
                    'p',
                ],
            ],
            'columns' => [
                'price' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'binary-op',
                        'op' => '/',
                        'left' => [
                            'type' => 'parentheses',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '+',
                                'left' => [
                                    'type' => 'qualified',
                                    'domain' => 'p',
                                    'name' => 'cupo',
                                    'balias' => 'cupo',
                                ],
                                'right' => [
                                    'type' => 'literal',
                                    'value' => '100',
                                ],
                            ],
                        ],
                        'right' => [
                            'type' => 'parentheses',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '*',
                                'left' => [
                                    'type' => 'qualified',
                                    'domain' => 's',
                                    'name' => 'price',
                                    'balias' => 'price',
                                ],
                                'right' => [
                                    'type' => 'literal',
                                    'value' => '0.15',
                                ],
                            ],
                        ],
                    ],
                    'balias' => 'price',
                    'sqlAlias' => 'price',
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'le_products',
                        null,
                        's',
                    ],
                    'conditions' => [
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ', ' . RobotsParts::class,
        "expected" => [
            'models' => [
                Robots::class,
                RobotsParts::class,
            ],
            'tables' => [
                'robots',
                'robots_parts',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
                lcfirst(RobotsParts::class) => [
                    'type' => 'object',
                    'model' => RobotsParts::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobotsParts::class),
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' r, ' . RobotsParts::class . ' p',
        "expected" => [
            'models' => [
                Robots::class,
                RobotsParts::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
                [
                    'robots_parts',
                    null,
                    'p',
                ],
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robots::class),
                ],
                lcfirst(RobotsParts::class) => [
                    'type' => 'object',
                    'model' => RobotsParts::class,
                    'column' => 'p',
                    'balias' => lcfirst(RobotsParts::class),
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' AS r, ' . RobotsParts::class . ' AS p',
        "expected" => [
            'models' => [
                Robots::class,
                RobotsParts::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
                [
                    'robots_parts',
                    null,
                    'p',
                ],
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robots::class),
                ],
                lcfirst(RobotsParts::class) => [
                    'type' => 'object',
                    'model' => RobotsParts::class,
                    'column' => 'p',
                    'balias' => lcfirst(RobotsParts::class),
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT name, parts_id FROM ' . Robots::class . ' AS r, ' . RobotsParts::class . ' AS p',
        "expected" => [
            'models' => [
                Robots::class,
                RobotsParts::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
                [
                    'robots_parts',
                    null,
                    'p',
                ],
            ],
            'columns' => [
                'name' => [
                    'type' => 'scalar',
                    'balias' => 'name',
                    'sqlAlias' => 'name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
                'parts_id' => [
                    'type' => 'scalar',
                    'balias' => 'parts_id',
                    'sqlAlias' => 'parts_id',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'p',
                        'name' => 'parts_id',
                        'balias' => 'parts_id',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' AS r, ' . RobotsParts::class . ' AS p WHERE r.id = p.robots_id',
        "expected" => [
            'models' => [
                Robots::class,
                RobotsParts::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
                [
                    'robots_parts',
                    null,
                    'p',
                ],
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robots::class),
                ],
                lcfirst(RobotsParts::class) => [
                    'type' => 'object',
                    'model' => RobotsParts::class,
                    'column' => 'p',
                    'balias' => lcfirst(RobotsParts::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '=',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => [
                    'type' => 'qualified',
                    'domain' => 'p',
                    'name' => 'robots_id',
                    'balias' => 'robots_id',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ', ' . RobotsParts::class . ' WHERE ' . Robots::class . '.id = ' . RobotsParts::class . '.robots_id',
        "expected" => [
            'models' => [
                Robots::class,
                RobotsParts::class,
            ],
            'tables' => [
                'robots',
                'robots_parts',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
                lcfirst(RobotsParts::class) => [
                    'type' => 'object',
                    'model' => RobotsParts::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobotsParts::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '=',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => [
                    'type' => 'qualified',
                    'domain' => 'robots_parts',
                    'name' => 'robots_id',
                    'balias' => 'robots_id',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id = 100',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '=',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id != 100',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '<>',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id > 100',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id < 100',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '<',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id >= 100',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '>=',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id <= 100',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '<=',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name LIKE \'as%\'',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => 'LIKE',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '\'as%\'',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name NOT LIKE \'as%\'',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => 'NOT LIKE',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '\'as%\'',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name BETWEEN \'john\' AND \'mike\'',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => 'BETWEEN',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
                'right' => [
                    'type' => 'binary-op',
                    'op' => 'AND',
                    'left' => [
                        'type' => 'literal',
                        'value' => '\'john\'',
                    ],
                    'right' => [
                        'type' => 'literal',
                        'value' => '\'mike\'',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . SomeProducts::class . ' WHERE DATE(' . SomeProducts::class . '.created_at) = "2010-10-02"',
        "expected" => [
            'models' => [
                SomeProducts::class,
            ],
            'tables' => [
                'le_products',
            ],
            'columns' => [
                lcfirst(SomeProducts::class) => [
                    'type' => 'object',
                    'model' => SomeProducts::class,
                    'column' => 'le_products',
                    'balias' => lcfirst(SomeProducts::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '=',
                'left' => [
                    'type' => 'functionCall',
                    'name' => 'DATE',
                    'arguments' => [
                        [
                            'type' => 'qualified',
                            'domain' => 'le_products',
                            'name' => 'created_at',
                            'balias' => 'created_at',
                        ],
                    ],
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '\'2010-10-02\'',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . SomeProducts::class . ' WHERE ' . SomeProducts::class . '.created_at < now()',
        "expected" => [
            'models' => [
                SomeProducts::class,
            ],
            'tables' => [
                'le_products',
            ],
            'columns' => [
                lcfirst(SomeProducts::class) => [
                    'type' => 'object',
                    'model' => SomeProducts::class,
                    'column' => 'le_products',
                    'balias' => lcfirst(SomeProducts::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '<',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'le_products',
                    'name' => 'created_at',
                    'balias' => 'created_at',
                ],
                'right' => [
                    'type' => 'functionCall',
                    'name' => 'now',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id IN (1)',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => 'IN',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => [
                    'type' => 'list',
                    [
                        [
                            'type' => 'literal',
                            'value' => '1',
                        ]
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id IN (1, 2, 3, 4)',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => 'IN',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => [
                    'type' => 'list',
                    [
                        [
                            'type' => 'literal',
                            'value' => '1',
                        ],
                        [
                            'type' => 'literal',
                            'value' => '2',
                        ],
                        [
                            'type' => 'literal',
                            'value' => '3',
                        ],
                        [
                            'type' => 'literal',
                            'value' => '4',
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' r WHERE r.id IN (r.id+1, r.id+2)',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => 'IN',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => [
                    'type' => 'list',
                    [
                        [
                            'type' => 'binary-op',
                            'op' => '+',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'r',
                                'name' => 'id',
                                'balias' => 'id',
                            ],
                            'right' => [
                                'type' => 'literal',
                                'value' => '1',
                            ],
                        ],
                        [
                            'type' => 'binary-op',
                            'op' => '+',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'r',
                                'name' => 'id',
                                'balias' => 'id',
                            ],
                            'right' => [
                                'type' => 'literal',
                                'value' => '2',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name = :name:',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '=',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
                'right' => [
                    'type' => 'placeholder',
                    'value' => ':name',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name = ?0',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '=',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
                'right' => [
                    'type' => 'placeholder',
                    'value' => ':0',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name = \'R2D2\' OR ' . Robots::class . '.name <> \'C3PO\'',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '<>',
                'left' => [
                    'type' => 'binary-op',
                    'op' => '=',
                    'left' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                    'right' => [
                        'type' => 'binary-op',
                        'op' => 'OR',
                        'left' => [
                            'type' => 'literal',
                            'value' => '\'R2D2\'',
                        ],
                        'right' => [
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'name',
                            'balias' => 'name',
                        ],
                    ],
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '\'C3PO\'',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name = \'R2D2\' AND ' . Robots::class . '.name <> \'C3PO\'',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '<>',
                'left' => [
                    'type' => 'binary-op',
                    'op' => '=',
                    'left' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                    'right' => [
                        'type' => 'binary-op',
                        'op' => 'AND',
                        'left' => [
                            'type' => 'literal',
                            'value' => '\'R2D2\'',
                        ],
                        'right' => [
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'name',
                            'balias' => 'name',
                        ],
                    ],
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '\'C3PO\'',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name = :first_name: AND ' . Robots::class . '.name <> :second_name:',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '<>',
                'left' => [
                    'type' => 'binary-op',
                    'op' => '=',
                    'left' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                    'right' => [
                        'type' => 'binary-op',
                        'op' => 'AND',
                        'left' => [
                            'type' => 'placeholder',
                            'value' => ':first_name',
                        ],
                        'right' => [
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'name',
                            'balias' => 'name',
                        ],
                    ],
                ],
                'right' => [
                    'type' => 'placeholder',
                    'value' => ':second_name',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name = \'R2D2\' AND ' . Robots::class . '.name <> \'C3PO\' AND ' . Robots::class . '.id > 100',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'binary-op',
                    'op' => '<>',
                    'left' => [
                        'type' => 'binary-op',
                        'op' => '=',
                        'left' => [
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'name',
                            'balias' => 'name',
                        ],
                        'right' => [
                            'type' => 'binary-op',
                            'op' => 'AND',
                            'left' => [
                                'type' => 'literal',
                                'value' => '\'R2D2\'',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'name',
                                'balias' => 'name',
                            ],
                        ],
                    ],
                    'right' => [
                        'type' => 'binary-op',
                        'op' => 'AND',
                        'left' => [
                            'type' => 'literal',
                            'value' => '\'C3PO\'',
                        ],
                        'right' => [
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'id',
                            'balias' => 'id',
                        ],
                    ],
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE (' . Robots::class . '.name = \'R2D2\' AND ' . Robots::class . '.name <> \'C3PO\') OR ' . Robots::class . '.id > 100',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'binary-op',
                    'op' => 'OR',
                    'left' => [
                        'type' => 'parentheses',
                        'left' => [
                            'type' => 'binary-op',
                            'op' => '<>',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => [
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ],
                                'right' => [
                                    'type' => 'binary-op',
                                    'op' => 'AND',
                                    'left' => [
                                        'type' => 'literal',
                                        'value' => '\'R2D2\'',
                                    ],
                                    'right' => [
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ],
                                ],
                            ],
                            'right' => [
                                'type' => 'literal',
                                'value' => '\'C3PO\'',
                            ],
                        ],
                    ],
                    'right' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'id',
                        'balias' => 'id',
                    ],
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE (' . Robots::class . '.name = \'R2D2\' AND ' . Robots::class . '.name <> \'C3PO\') OR (' . Robots::class . '.id > 100 AND ' . Robots::class . '.id <= 150)',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => 'OR',
                'left' => [
                    'type' => 'parentheses',
                    'left' => [
                        'type' => 'binary-op',
                        'op' => '<>',
                        'left' => [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'name',
                                'balias' => 'name',
                            ],
                            'right' => [
                                'type' => 'binary-op',
                                'op' => 'AND',
                                'left' => [
                                    'type' => 'literal',
                                    'value' => '\'R2D2\'',
                                ],
                                'right' => [
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ],
                            ],
                        ],
                        'right' => [
                            'type' => 'literal',
                            'value' => '\'C3PO\'',
                        ],
                    ],
                ],
                'right' => [
                    'type' => 'parentheses',
                    'left' => [
                        'type' => 'binary-op',
                        'op' => '<=',
                        'left' => [
                            'type' => 'binary-op',
                            'op' => '>',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
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
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ],
                            ],
                        ],
                        'right' => [
                            'type' => 'literal',
                            'value' => '150',
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' r WHERE r.id NOT IN (r.id+1, r.id+2)',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => 'NOT IN',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => [
                    'type' => 'list',
                    [
                        [
                            'type' => 'binary-op',
                            'op' => '+',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'r',
                                'name' => 'id',
                                'balias' => 'id',
                            ],
                            'right' => [
                                'type' => 'literal',
                                'value' => '1',
                            ],
                        ],
                        [
                            'type' => 'binary-op',
                            'op' => '+',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'r',
                                'name' => 'id',
                                'balias' => 'id',
                            ],
                            'right' => [
                                'type' => 'literal',
                                'value' => '2',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' r LIMIT 100',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'limit' => [
                'number' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' r LIMIT 10,100',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'limit' => [
                'number' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
                'offset' => [
                    'type' => 'literal',
                    'value' => '10',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' r LIMIT 100 OFFSET 10',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'limit' => [
                'number' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
                'offset' => [
                    'type' => 'literal',
                    'value' => '10',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . SomeProducts::class . ' p WHERE p.name = "Artichoke" LIMIT 100',
        "expected" => [
            'models' => [
                SomeProducts::class,
            ],
            'tables' => [
                [
                    'le_products',
                    null,
                    'p',
                ],
            ],
            'columns' => [
                lcfirst(SomeProducts::class) => [
                    'type' => 'object',
                    'model' => SomeProducts::class,
                    'column' => 'p',
                    'balias' => lcfirst(SomeProducts::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '=',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'p',
                    'name' => 'name',
                    'balias' => 'name',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '\'Artichoke\'',
                ],
            ],
            'limit' => [
                'number' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . SomeProducts::class . ' p ORDER BY p.name',
        "expected" => [
            'models' => [
                SomeProducts::class,
            ],
            'tables' => [
                [
                    'le_products',
                    null,
                    'p',
                ],
            ],
            'columns' => [
                lcfirst(SomeProducts::class) => [
                    'type' => 'object',
                    'model' => SomeProducts::class,
                    'column' => 'p',
                    'balias' => lcfirst(SomeProducts::class),
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'qualified',
                        'domain' => 'p',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . SomeProducts::class . ' ORDER BY ' . SomeProducts::class . '.name',
        "expected" => [
            'models' => [
                SomeProducts::class,
            ],
            'tables' => [
                'le_products',
            ],
            'columns' => [
                lcfirst(SomeProducts::class) => [
                    'type' => 'object',
                    'model' => SomeProducts::class,
                    'column' => 'le_products',
                    'balias' => lcfirst(SomeProducts::class),
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'qualified',
                        'domain' => 'le_products',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . SomeProducts::class . ' ORDER BY id, ' . SomeProducts::class . '.name, 3',
        "expected" => [
            'models' => [
                SomeProducts::class,
            ],
            'tables' => [
                'le_products',
            ],
            'columns' => [
                lcfirst(SomeProducts::class) => [
                    'type' => 'object',
                    'model' => SomeProducts::class,
                    'column' => 'le_products',
                    'balias' => lcfirst(SomeProducts::class),
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'qualified',
                        'domain' => 'le_products',
                        'name' => 'id',
                        'balias' => 'id',
                    ],
                ],
                [
                    [
                        'type' => 'qualified',
                        'domain' => 'le_products',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
                [
                    [
                        'type' => 'literal',
                        'value' => '3',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' r WHERE NOT (r.name = "shaggy") ORDER BY 1, r.name',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'unary-op',
                'op' => 'NOT ',
                'right' => [
                    'type' => 'parentheses',
                    'left' => [
                        'type' => 'binary-op',
                        'op' => '=',
                        'left' => [
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'name',
                        ],
                        'right' => [
                            'type' => 'literal',
                            'value' => '\'shaggy\'',
                        ],
                    ],
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'literal',
                        'value' => '1',
                    ],
                ],
                [
                    [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' r WHERE NOT (r.name = "shaggy") ORDER BY 1 DESC, r.name',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'unary-op',
                'op' => 'NOT ',
                'right' => [
                    'type' => 'parentheses',
                    'left' => [
                        'type' => 'binary-op',
                        'op' => '=',
                        'left' => [
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'name',
                        ],
                        'right' => [
                            'type' => 'literal',
                            'value' => '\'shaggy\'',
                        ],
                    ],
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'literal',
                        'value' => '1',
                    ],
                    'DESC',
                ],
                [
                    [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' r WHERE NOT (r.name = "shaggy") ORDER BY 1, r.name',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'unary-op',
                'op' => 'NOT ',
                'right' => [
                    'type' => 'parentheses',
                    'left' => [
                        'type' => 'binary-op',
                        'op' => '=',
                        'left' => [
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'name',
                        ],
                        'right' => [
                            'type' => 'literal',
                            'value' => '\'shaggy\'',
                        ],
                    ],
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'literal',
                        'value' => '1',
                    ],
                ],
                [
                    [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' r WHERE r.name <> "shaggy" ORDER BY 1, 2 LIMIT 5',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '<>',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'name',
                    'balias' => 'name',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '\'shaggy\'',
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'literal',
                        'value' => '1',
                    ],
                ],
                [
                    [
                        'type' => 'literal',
                        'value' => '2',
                    ],
                ],
            ],
            'limit' => [
                'number' => [
                    'type' => 'literal',
                    'value' => '5',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' r WHERE r.name <> "shaggy" ORDER BY 1 ASC, 2 DESC LIMIT 5',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '<>',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'name',
                    'balias' => 'name',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '\'shaggy\'',
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'literal',
                        'value' => '1',
                    ],
                    'ASC',
                ],
                [
                    [
                        'type' => 'literal',
                        'value' => '2',
                    ],
                    'DESC',
                ],
            ],
            'limit' => [
                'number' => [
                    'type' => 'literal',
                    'value' => '5',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' GROUP BY ' . Robots::class . '.name',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' GROUP BY ' . Robots::class . '.name, ' . Robots::class . '.id',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'id',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ' . Robots::class . '.name, SUM(' . Robots::class . '.price) AS summatory FROM ' . Robots::class . ' GROUP BY ' . Robots::class . '.name',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                'name' => [
                    'type' => 'scalar',
                    'balias' => 'name',
                    'sqlAlias' => 'name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
                'summatory' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'SUM',
                        'arguments' => [
                            [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'price',
                                'balias' => 'price',
                            ],
                        ],
                    ],
                    'balias' => 'summatory',
                    'sqlAlias' => 'summatory',
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT r.id, r.name, SUM(r.price) AS summatory, MIN(r.price) FROM ' . Robots::class . ' r GROUP BY r.id, r.name',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                'id' => [
                    'type' => 'scalar',
                    'balias' => 'id',
                    'sqlAlias' => 'id',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'id',
                        'balias' => 'id',
                    ],
                ],
                'name' => [
                    'type' => 'scalar',
                    'balias' => 'name',
                    'sqlAlias' => 'name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
                'summatory' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'SUM',
                        'arguments' => [
                            [
                                'type' => 'qualified',
                                'domain' => 'r',
                                'name' => 'price',
                                'balias' => 'price',
                            ],
                        ],
                    ],
                    'balias' => 'summatory',
                    'sqlAlias' => 'summatory',
                ],
                '_3' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'MIN',
                        'arguments' => [
                            [
                                'type' => 'qualified',
                                'domain' => 'r',
                                'name' => 'price',
                                'balias' => 'price',
                            ],
                        ],
                    ],
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id > 5 GROUP BY ' . Robots::class . '.name',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '5',
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id > 5 GROUP BY ' . Robots::class . '.name LIMIT 10',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '5',
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'limit' => [
                'number' => [
                    'type' => 'literal',
                    'value' => '10',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id > 5 GROUP BY ' . Robots::class . '.name ORDER BY ' . Robots::class . '.id LIMIT 10',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '5',
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'id',
                        'balias' => 'id',
                    ],
                ],
            ],
            'limit' => [
                'number' => [
                    'type' => 'literal',
                    'value' => '10',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' GROUP BY ' . Robots::class . '.name ORDER BY ' . Robots::class . '.id',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'id',
                        'balias' => 'id',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id != 10 GROUP BY ' . Robots::class . '.name ORDER BY ' . Robots::class . '.id',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '<>',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '10',
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'id',
                        'balias' => 'id',
                    ],
                ],
            ],
        ]
    ],
    [

        "phql"     => 'SELECT ' . Robots::class . '.name, COUNT(*) FROM ' . Robots::class . ' GROUP BY ' . Robots::class . '.name HAVING COUNT(*)>100',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                'name' => [
                    'type' => 'scalar',
                    'balias' => 'name',
                    'sqlAlias' => 'name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
                '_1' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'COUNT',
                        'arguments' => [
                            [
                                'type' => 'all',
                            ],
                        ],
                    ],
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'having' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'functionCall',
                    'name' => 'COUNT',
                    'arguments' => [
                        [
                            'type' => 'all',
                        ],
                    ],
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ' . SomeProducts::class . '.type, SUM(' . SomeProducts::class . '.price) AS price FROM ' . SomeProducts::class . ' GROUP BY ' . SomeProducts::class . '.type HAVING SUM(' . SomeProducts::class . '.price)<100',
        "expected" => [
            'models' => [
                SomeProducts::class,
            ],
            'tables' => [
                'le_products',
            ],
            'columns' => [
                'type' => [
                    'type' => 'scalar',
                    'balias' => 'type',
                    'sqlAlias' => 'type',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'le_products',
                        'name' => 'type',
                        'balias' => 'type',
                    ],
                ],
                'price' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'SUM',
                        'arguments' => [
                            [
                                'type' => 'qualified',
                                'domain' => 'le_products',
                                'name' => 'price',
                                'balias' => 'price',
                            ],
                        ],
                    ],
                    'balias' => 'price',
                    'sqlAlias' => 'price',
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'le_products',
                    'name' => 'type',
                    'balias' => 'type',
                ],
            ],
            'having' => [
                'type' => 'binary-op',
                'op' => '<',
                'left' => [
                    'type' => 'functionCall',
                    'name' => 'SUM',
                    'arguments' => [
                        [
                            'type' => 'qualified',
                            'name' => 'price',
                            'domain' => 'le_products',
                            'balias' => 'price',
                        ],
                    ],
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT type, SUM(price) AS price FROM ' . SomeProducts::class . ' GROUP BY 1 HAVING SUM(price)<100',
        "expected" => [
            'models' => [
                SomeProducts::class,
            ],
            'tables' => [
                'le_products',
            ],
            'columns' => [
                'type' => [
                    'type' => 'scalar',
                    'balias' => 'type',
                    'sqlAlias' => 'type',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'le_products',
                        'name' => 'type',
                        'balias' => 'type',
                    ],
                ],
                'price' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'SUM',
                        'arguments' => [
                            [
                                'type' => 'qualified',
                                'domain' => 'le_products',
                                'name' => 'price',
                                'balias' => 'price',
                            ],
                        ],
                    ],
                    'balias' => 'price',
                    'sqlAlias' => 'price',
                ],
            ],
            'group' => [
                [
                    'type' => 'literal',
                    'value' => '1',
                ],
            ],
            'having' => [
                'type' => 'binary-op',
                'op' => '<',
                'left' => [
                    'type' => 'functionCall',
                    'name' => 'SUM',
                    'arguments' => [
                        [
                            'type' => 'qualified',
                            'name' => 'price',
                        ],
                    ],
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT COUNT(DISTINCT ' . SomeProducts::class . '.type) AS price FROM ' . SomeProducts::class,
        "expected" => [
            'models' => [
                SomeProducts::class,
            ],
            'tables' => [
                'le_products',
            ],
            'columns' => [
                'price' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'COUNT',
                        'arguments' => [
                            [
                                'type' => 'qualified',
                                'domain' => 'le_products',
                                'name' => 'type',
                                'balias' => 'type',
                            ],
                        ],
                        'distinct' => 1,
                    ],
                    'balias' => 'price',
                    'sqlAlias' => 'price',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT COUNT(DISTINCT ' . SomeProducts::class . '.type) price FROM ' . SomeProducts::class,
        "expected" => [
            'models' => [
                SomeProducts::class,
            ],
            'tables' => [
                'le_products',
            ],
            'columns' => [
                'price' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'COUNT',
                        'arguments' => [
                            [
                                'type' => 'qualified',
                                'domain' => 'le_products',
                                'name' => 'type',
                                'balias' => 'type',
                            ],
                        ],
                        'distinct' => 1,
                    ],
                    'balias' => 'price',
                    'sqlAlias' => 'price',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ' . Robots::class . '.name, COUNT(*) FROM ' . Robots::class . ' WHERE ' . Robots::class . '.type = "virtual" GROUP BY ' . Robots::class . '.name HAVING COUNT(*)>100',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                'name' => [
                    'type' => 'scalar',
                    'balias' => 'name',
                    'sqlAlias' => 'name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
                '_1' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'COUNT',
                        'arguments' => [
                            [
                                'type' => 'all',
                            ],
                        ],
                    ],
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '=',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'type',
                    'balias' => 'type',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '\'virtual\'',
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'having' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'functionCall',
                    'name' => 'COUNT',
                    'arguments' => [
                        [
                            'type' => 'all',
                        ],
                    ],
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ' . Robots::class . '.name, COUNT(*) FROM ' . Robots::class . ' WHERE ' . Robots::class . '.type = "virtual" GROUP BY ' . Robots::class . '.name HAVING COUNT(*)>100 ORDER BY 2',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                'name' => [
                    'type' => 'scalar',
                    'balias' => 'name',
                    'sqlAlias' => 'name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
                '_1' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'COUNT',
                        'arguments' => [
                            [
                                'type' => 'all',
                            ],
                        ],
                    ],
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '=',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'type',
                    'balias' => 'type',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '\'virtual\'',
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'having' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'functionCall',
                    'name' => 'COUNT',
                    'arguments' => [
                        [
                            'type' => 'all',
                        ],
                    ],
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'literal',
                        'value' => '2',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ' . Robots::class . '.name, COUNT(*) FROM ' . Robots::class . ' WHERE ' . Robots::class . '.type = "virtual" GROUP BY ' . Robots::class . '.name HAVING COUNT(*)>100 ORDER BY 2 LIMIT 15',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                'name' => [
                    'type' => 'scalar',
                    'balias' => 'name',
                    'sqlAlias' => 'name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
                '_1' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'COUNT',
                        'arguments' => [
                            [
                                'type' => 'all',
                            ],
                        ],
                    ],
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '=',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'type',
                    'balias' => 'type',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '\'virtual\'',
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'having' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'functionCall',
                    'name' => 'COUNT',
                    'arguments' => [
                        [
                            'type' => 'all',
                        ],
                    ],
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'literal',
                        'value' => '2',
                    ],
                ],
            ],
            'limit' => [
                'number' => [
                    'type' => 'literal',
                    'value' => '15',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ' . Robots::class . '.name, COUNT(*) FROM ' . Robots::class . ' GROUP BY ' . Robots::class . '.name HAVING COUNT(*)>100 ORDER BY 2 LIMIT 15',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                'name' => [
                    'type' => 'scalar',
                    'balias' => 'name',
                    'sqlAlias' => 'name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
                '_1' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'COUNT',
                        'arguments' => [
                            [
                                'type' => 'all',
                            ],
                        ],
                    ],
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'having' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'functionCall',
                    'name' => 'COUNT',
                    'arguments' => [
                        [
                            'type' => 'all',
                        ],
                    ],
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'literal',
                        'value' => '2',
                    ],
                ],
            ],
            'limit' => [
                'number' => [
                    'type' => 'literal',
                    'value' => '15',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT name, COUNT(*) FROM ' . Robots::class . ' WHERE type = "virtual" GROUP BY name HAVING COUNT(*)>100 LIMIT 15',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                'name' => [
                    'type' => 'scalar',
                    'balias' => 'name',
                    'sqlAlias' => 'name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
                '_1' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'COUNT',
                        'arguments' => [
                            [
                                'type' => 'all',
                            ],
                        ],
                    ],
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '=',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'type',
                    'balias' => 'type',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '\'virtual\'',
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'having' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'functionCall',
                    'name' => 'COUNT',
                    'arguments' => [
                        [
                            'type' => 'all',
                        ],
                    ],
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
            'limit' => [
                'number' => [
                    'type' => 'literal',
                    'value' => '15',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ' . Robots::class . '.name, COUNT(*) FROM ' . Robots::class . ' WHERE ' . Robots::class . '.type = "virtual" GROUP BY ' . Robots::class . '.name HAVING COUNT(*)>100 LIMIT 15',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                'name' => [
                    'type' => 'scalar',
                    'balias' => 'name',
                    'sqlAlias' => 'name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
                '_1' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'COUNT',
                        'arguments' => [
                            [
                                'type' => 'all',
                            ],
                        ],
                    ],
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '=',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'type',
                    'balias' => 'type',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '\'virtual\'',
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'having' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'functionCall',
                    'name' => 'COUNT',
                    'arguments' => [
                        [
                            'type' => 'all',
                        ],
                    ],
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
            'limit' => [
                'number' => [
                    'type' => 'literal',
                    'value' => '15',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ' . Robots::class . '.name, COUNT(*) FROM ' . Robots::class . ' GROUP BY ' . Robots::class . '.name HAVING COUNT(*)>100 LIMIT 15',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                'name' => [
                    'type' => 'scalar',
                    'balias' => 'name',
                    'sqlAlias' => 'name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
                '_1' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'COUNT',
                        'arguments' => [
                            [
                                'type' => 'all',
                            ],
                        ],
                    ],
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name',
                ],
            ],
            'having' => [
                'type' => 'binary-op',
                'op' => '>',
                'left' => [
                    'type' => 'functionCall',
                    'name' => 'COUNT',
                    'arguments' => [
                        [
                            'type' => 'all',
                        ],
                    ],
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '100',
                ],
            ],
            'limit' => [
                'number' => [
                    'type' => 'literal',
                    'value' => '15',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class,
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robotters::class),
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . SomeRobotters::class,
        "expected" => [
            'models' => [
                SomeRobotters::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(SomeRobotters::class) => [
                    'type' => 'object',
                    'model' => SomeRobotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(SomeRobotters::class),
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ' . SomeRobotters::class . '.* FROM ' . SomeRobotters::class,
        "expected" => [
            'models' => [
                SomeRobotters::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(SomeRobotters::class) => [
                    'type' => 'object',
                    'model' => SomeRobotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(SomeRobotters::class),
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT r.* FROM ' . SomeRobotters::class . ' r',
        "expected" => [
            'models' => [
                SomeRobotters::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                'r' => [
                    'type' => 'object',
                    'model' => SomeRobotters::class,
                    'column' => 'r',
                    'balias' => 'r',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ' . Robotters::class . '.* FROM ' . Robotters::class,
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robotters::class),
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT r.* FROM ' . Robotters::class . ' r',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                'r' => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'r',
                    'balias' => 'r',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT r.* FROM ' . Robotters::class . ' AS r',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                'r' => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'r',
                    'balias' => 'r',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT code, theName FROM ' . Robotters::class,
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                'code' => [
                    'type' => 'scalar',
                    'balias' => 'code',
                    'sqlAlias' => 'code',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'id',
                        'balias' => 'code',
                    ],
                ],
                'theName' => [
                    'type' => 'scalar',
                    'balias' => 'theName',
                    'sqlAlias' => 'theName',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'theName',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT r.code, r.theName FROM ' . Robotters::class . ' AS r',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                'code' => [
                    'type' => 'scalar',
                    'balias' => 'code',
                    'sqlAlias' => 'code',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'id',
                        'balias' => 'code',
                    ],
                ],
                'theName' => [
                    'type' => 'scalar',
                    'balias' => 'theName',
                    'sqlAlias' => 'theName',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'name',
                        'balias' => 'theName',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT r.code AS le_id, r.theName AS le_name FROM ' . Robotters::class . ' AS r',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                'le_id' => [
                    'type' => 'scalar',
                    'balias' => 'le_id',
                    'sqlAlias' => 'le_id',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'id',
                        'balias' => 'code',
                    ],
                ],
                'le_name' => [
                    'type' => 'scalar',
                    'balias' => 'le_name',
                    'sqlAlias' => 'le_name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'name',
                        'balias' => 'theName',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ' . Robotters::class . '.code AS le_id, ' . Robotters::class . '.theName AS le_name FROM ' . Robotters::class,
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                'le_id' => [
                    'type' => 'scalar',
                    'balias' => 'le_id',
                    'sqlAlias' => 'le_id',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'id',
                        'balias' => 'code',
                    ],
                ],
                'le_name' => [
                    'type' => 'scalar',
                    'balias' => 'le_name',
                    'sqlAlias' => 'le_name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'theName',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT \'\' empty_str, 10.5 double_number, 1000 AS long_number FROM ' . Robotters::class,
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                'empty_str' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'literal',
                        'value' => '\'\'',
                    ],
                    'balias' => 'empty_str',
                    'sqlAlias' => 'empty_str',
                ],
                'double_number' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'literal',
                        'value' => '10.5',
                    ],
                    'balias' => 'double_number',
                    'sqlAlias' => 'double_number',
                ],
                'long_number' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'literal',
                        'value' => '1000',
                    ],
                    'balias' => 'long_number',
                    'sqlAlias' => 'long_number',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ' . Personers::class . '.borgerId FROM ' . Personers::class,
        "expected" => [
            'models' => [
                Personers::class,
            ],
            'tables' => [
                'personas',
            ],
            'columns' => [
                'borgerId' => [
                    'type' => 'scalar',
                    'balias' => 'borgerId',
                    'sqlAlias' => 'borgerId',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'personas',
                        'name' => 'cedula',
                        'balias' => 'borgerId',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'select ' . strtolower(Personers::class) . '.borgerId from ' . strtolower(Personers::class),
        "expected" => [
            'models' => [
                strtolower(Personers::class),
            ],
            'tables' => [
                'personas',
            ],
            'columns' => [
                'borgerId' => [
                    'type' => 'scalar',
                    'balias' => 'borgerId',
                    'sqlAlias' => 'borgerId',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'personas',
                        'name' => 'cedula',
                        'balias' => 'borgerId',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT p.borgerId AS cedula FROM ' . Personers::class . ' p',
        "expected" => [
            'models' => [
                Personers::class,
            ],
            'tables' => [
                [
                    'personas',
                    null,
                    'p',
                ],
            ],
            'columns' => [
                'cedula' => [
                    'type' => 'scalar',
                    'balias' => 'cedula',
                    'sqlAlias' => 'cedula',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'p',
                        'name' => 'cedula',
                        'balias' => 'borgerId',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT CONCAT(' . Personers::class . '.borgerId,\'-\',' . Personers::class . '.navnes) AS navne FROM ' . Personers::class,
        "expected" => [
            'models' => [
                Personers::class,
            ],
            'tables' => [
                'personas',
            ],
            'columns' => [
                'navne' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'CONCAT',
                        'arguments' => [
                            [
                                'type' => 'qualified',
                                'domain' => 'personas',
                                'name' => 'cedula',
                                'balias' => 'borgerId',
                            ],
                            [
                                'type' => 'literal',
                                'value' => '\'-\'',
                            ],
                            [
                                'type' => 'qualified',
                                'domain' => 'personas',
                                'name' => 'nombres',
                                'balias' => 'navnes',
                            ],
                        ],
                    ],
                    'balias' => 'navne',
                    'sqlAlias' => 'navne',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' JOIN ' . RobottersDeles::class,
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robotters::class),
                ],
                lcfirst(RobottersDeles::class) => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobottersDeles::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'robots_parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'code',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robottersCode',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' CROSS JOIN ' . RobottersDeles::class,
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robotters::class),
                ],
                lcfirst(RobottersDeles::class) => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobottersDeles::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'CROSS',
                    'source' => [
                        'robots_parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'code',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robottersCode',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' LEFT JOIN ' . RobottersDeles::class . ' RIGHT JOIN ' . Deles::class,
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robotters::class),
                ],
                lcfirst(RobottersDeles::class) => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobottersDeles::class),
                ],
                lcfirst(Deles::class) => [
                    'type' => 'object',
                    'model' => Deles::class,
                    'column' => 'parts',
                    'balias' => lcfirst(Deles::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'LEFT',
                    'source' => [
                        'robots_parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'code',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robottersCode',
                            ],
                        ],
                    ],
                ],
                [
                    'type' => 'RIGHT',
                    'source' => [
                        'parts',
                        null,
                    ],
                    'conditions' => [
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . RobottersDeles::class . ' LEFT OUTER JOIN ' . Robotters::class . ' RIGHT OUTER JOIN ' . Deles::class,
        "expected" => [
            'models' => [
                RobottersDeles::class,
            ],
            'tables' => [
                'robots_parts',
            ],
            'columns' => [
                lcfirst(RobottersDeles::class) => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobottersDeles::class),
                ],
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robotters::class),
                ],
                lcfirst(Deles::class) => [
                    'type' => 'object',
                    'model' => Deles::class,
                    'column' => 'parts',
                    'balias' => lcfirst(Deles::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'LEFT',
                    'source' => [
                        'robots',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robottersCode',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'code',
                            ],
                        ],
                    ],
                ],
                [
                    'type' => 'RIGHT',
                    'source' => [
                        'parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'parts_id',
                                'balias' => 'delesCode',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'parts',
                                'name' => 'id',
                                'balias' => 'code',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' JOIN ' . RobottersDeles::class . ' ON ' . Robotters::class . '.code = ' . RobottersDeles::class . '.robottersCode',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robotters::class),
                ],
                lcfirst(RobottersDeles::class) => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobottersDeles::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'robots_parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'code',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robottersCode',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' LEFT OUTER JOIN ' . RobottersDeles::class . ' ON ' . Robotters::class . '.code = ' . RobottersDeles::class . '.robottersCode AND ' . RobottersDeles::class . '.robottersCode = ' . Robotters::class . '.code WHERE ' . Robotters::class . '.code IS NULL',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robotters::class),
                ],
                lcfirst(RobottersDeles::class) => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobottersDeles::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'LEFT',
                    'source' => [
                        'robots_parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => [
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'code',
                                ],
                                'right' => [
                                    'type' => 'binary-op',
                                    'op' => 'AND',
                                    'left' => [
                                        'type' => 'qualified',
                                        'domain' => 'robots_parts',
                                        'name' => 'robots_id',
                                        'balias' => 'robottersCode',
                                    ],
                                    'right' => [
                                        'type' => 'qualified',
                                        'domain' => 'robots_parts',
                                        'name' => 'robots_id',
                                        'balias' => 'robottersCode',
                                    ],
                                ],
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'code',
                            ],
                        ],
                    ],
                ],
            ],
            'where' => [
                'type' => 'unary-op',
                'op' => ' IS NULL',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'code',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' RIGHT OUTER JOIN ' . RobottersDeles::class . ' ON ' . Robotters::class . '.code = ' . RobottersDeles::class . '.robottersCode AND ' . RobottersDeles::class . '.robottersCode = ' . Robotters::class . '.code WHERE ' . RobottersDeles::class . '.robottersCode IS NOT NULL',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robotters::class),
                ],
                lcfirst(RobottersDeles::class) => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobottersDeles::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'RIGHT',
                    'source' => [
                        'robots_parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => [
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'code',
                                ],
                                'right' => [
                                    'type' => 'binary-op',
                                    'op' => 'AND',
                                    'left' => [
                                        'type' => 'qualified',
                                        'domain' => 'robots_parts',
                                        'name' => 'robots_id',
                                        'balias' => 'robottersCode',
                                    ],
                                    'right' => [
                                        'type' => 'qualified',
                                        'domain' => 'robots_parts',
                                        'name' => 'robots_id',
                                        'balias' => 'robottersCode',
                                    ],
                                ],
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'code',
                            ],
                        ],
                    ],
                ],
            ],
            'where' => [
                'type' => 'unary-op',
                'op' => ' IS NOT NULL',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots_parts',
                    'name' => 'robots_id',
                    'balias' => 'robottersCode',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' FULL OUTER JOIN ' . RobottersDeles::class,
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robotters::class),
                ],
                lcfirst(RobottersDeles::class) => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobottersDeles::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'FULL OUTER',
                    'source' => [
                        'robots_parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'code',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robottersCode',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . RobottersDeles::class . ' JOIN ' . Robotters::class,
        "expected" => [
            'models' => [
                RobottersDeles::class,
            ],
            'tables' => [
                'robots_parts',
            ],
            'columns' => [
                lcfirst(RobottersDeles::class) => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobottersDeles::class),
                ],
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robotters::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'robots',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robottersCode',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'code',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT r.*, p.* FROM ' . Robotters::class . ' AS r JOIN ' . RobottersDeles::class . ' AS p',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                'r' => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'r',
                    'balias' => 'r',
                ],
                'p' => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'p',
                    'balias' => 'p',
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'robots_parts',
                        null,
                        'p',
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'r',
                                'name' => 'id',
                                'balias' => 'code',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'p',
                                'name' => 'robots_id',
                                'balias' => 'robottersCode',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' AS r JOIN ' . RobottersDeles::class . ' AS p',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robotters::class),
                ],
                lcfirst(RobottersDeles::class) => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'p',
                    'balias' => lcfirst(RobottersDeles::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'robots_parts',
                        null,
                        'p',
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'r',
                                'name' => 'id',
                                'balias' => 'code',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'p',
                                'name' => 'robots_id',
                                'balias' => 'robottersCode',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT r.* FROM ' . Robotters::class . ' r INNER JOIN ' . RobottersDeles::class,
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                'r' => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'r',
                    'balias' => 'r',
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'robots_parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'r',
                                'name' => 'id',
                                'balias' => 'code',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robottersCode',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . RobottersDeles::class . ' JOIN ' . Robotters::class,
        "expected" => [
            'models' => [
                RobottersDeles::class,
            ],
            'tables' => [
                'robots_parts',
            ],
            'columns' => [
                lcfirst(RobottersDeles::class) => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobottersDeles::class),
                ],
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robotters::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'robots',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robottersCode',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'id',
                                'balias' => 'code',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT r.*, p.* FROM ' . Robotters::class . ' AS r JOIN ' . RobottersDeles::class . ' AS p',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                'r' => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'r',
                    'balias' => 'r',
                ],
                'p' => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'p',
                    'balias' => 'p',
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'robots_parts',
                        null,
                        'p',
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'r',
                                'name' => 'id',
                                'balias' => 'code',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'p',
                                'name' => 'robots_id',
                                'balias' => 'robottersCode',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' AS r JOIN ' . RobottersDeles::class . ' AS p',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robotters::class),
                ],
                lcfirst(RobottersDeles::class) => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'p',
                    'balias' => lcfirst(RobottersDeles::class),
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'robots_parts',
                        null,
                        'p',
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'r',
                                'name' => 'id',
                                'balias' => 'code',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'p',
                                'name' => 'robots_id',
                                'balias' => 'robottersCode',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT r.* FROM ' . Robotters::class . ' r INNER JOIN ' . RobottersDeles::class,
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                'r' => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'r',
                    'balias' => 'r',
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'robots_parts',
                        null,
                    ],
                    'conditions' => [
                        [
                            'type' => 'binary-op',
                            'op' => '=',
                            'left' => [
                                'type' => 'qualified',
                                'domain' => 'r',
                                'name' => 'id',
                                'balias' => 'code',
                            ],
                            'right' => [
                                'type' => 'qualified',
                                'domain' => 'robots_parts',
                                'name' => 'robots_id',
                                'balias' => 'robottersCode',
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ( ' . Personers::class . '.kredit + 100) / (' . Products::class . '.price * 0.15) FROM ' . Personers::class . ' JOIN ' . Products::class,
        "expected" => [
            'models' => [
                Personers::class,
            ],
            'tables' => [
                'personas',
            ],
            'columns' => [
                '_0' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'binary-op',
                        'op' => '/',
                        'left' => [
                            'type' => 'parentheses',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '+',
                                'left' => [
                                    'type' => 'qualified',
                                    'domain' => 'personas',
                                    'name' => 'cupo',
                                    'balias' => 'kredit',
                                ],
                                'right' => [
                                    'type' => 'literal',
                                    'value' => '100',
                                ],
                            ],
                        ],
                        'right' => [
                            'type' => 'parentheses',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '*',
                                'left' => [
                                    'type' => 'qualified',
                                    'domain' => 'products',
                                    'name' => 'price',
                                    'balias' => 'price',
                                ],
                                'right' => [
                                    'type' => 'literal',
                                    'value' => '0.15',
                                ],
                            ],
                        ],
                    ],
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'products',
                        null,
                    ],
                    'conditions' => [
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT ( ' . Personers::class . '.kredit + 100) / (' . SomeProducts::class . '.price * 0.15) AS price FROM ' . Personers::class . ' JOIN ' . SomeProducts::class,
        "expected" => [
            'models' => [
                Personers::class,
            ],
            'tables' => [
                'personas',
            ],
            'columns' => [
                'price' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'binary-op',
                        'op' => '/',
                        'left' => [
                            'type' => 'parentheses',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '+',
                                'left' => [
                                    'type' => 'qualified',
                                    'domain' => 'personas',
                                    'name' => 'cupo',
                                    'balias' => 'kredit',
                                ],
                                'right' => [
                                    'type' => 'literal',
                                    'value' => '100',
                                ],
                            ],
                        ],
                        'right' => [
                            'type' => 'parentheses',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '*',
                                'left' => [
                                    'type' => 'qualified',
                                    'domain' => 'le_products',
                                    'name' => 'price',
                                    'balias' => 'price',
                                ],
                                'right' => [
                                    'type' => 'literal',
                                    'value' => '0.15',
                                ],
                            ],
                        ],
                    ],
                    'balias' => 'price',
                    'sqlAlias' => 'price',
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'le_products',
                        null,
                    ],
                    'conditions' => [
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT (p.kredit + 100) / (s.price * 0.15) AS price FROM ' . Personers::class . ' AS p JOIN ' . SomeProducts::class . ' AS s',
        "expected" => [
            'models' => [
                Personers::class,
            ],
            'tables' => [
                [
                    'personas',
                    null,
                    'p',
                ],
            ],
            'columns' => [
                'price' => [
                    'type' => 'scalar',
                    'column' => [
                        'type' => 'binary-op',
                        'op' => '/',
                        'left' => [
                            'type' => 'parentheses',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '+',
                                'left' => [
                                    'type' => 'qualified',
                                    'domain' => 'p',
                                    'name' => 'cupo',
                                    'balias' => 'kredit',
                                ],
                                'right' => [
                                    'type' => 'literal',
                                    'value' => '100',
                                ],
                            ],
                        ],
                        'right' => [
                            'type' => 'parentheses',
                            'left' => [
                                'type' => 'binary-op',
                                'op' => '*',
                                'left' => [
                                    'type' => 'qualified',
                                    'domain' => 's',
                                    'name' => 'price',
                                    'balias' => 'price',
                                ],
                                'right' => [
                                    'type' => 'literal',
                                    'value' => '0.15',
                                ],
                            ],
                        ],
                    ],
                    'balias' => 'price',
                    'sqlAlias' => 'price',
                ],
            ],
            'joins' => [
                [
                    'type' => 'INNER',
                    'source' => [
                        'le_products',
                        null,
                        's',
                    ],
                    'conditions' => [
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ', ' . RobottersDeles::class,
        "expected" => [
            'models' => [
                Robotters::class,
                RobottersDeles::class,
            ],
            'tables' => [
                'robots',
                'robots_parts',
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robotters::class),
                ],
                lcfirst(RobottersDeles::class) => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobottersDeles::class),
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' r, ' . RobottersDeles::class . ' p',
        "expected" => [
            'models' => [
                Robotters::class,
                RobottersDeles::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
                [
                    'robots_parts',
                    null,
                    'p',
                ],
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robotters::class),
                ],
                lcfirst(RobottersDeles::class) => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'p',
                    'balias' => lcfirst(RobottersDeles::class),
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' AS r, ' . RobottersDeles::class . ' AS p',
        "expected" => [
            'models' => [
                Robotters::class,
                RobottersDeles::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
                [
                    'robots_parts',
                    null,
                    'p',
                ],
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robotters::class),
                ],
                lcfirst(RobottersDeles::class) => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'p',
                    'balias' => lcfirst(RobottersDeles::class),
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT theName, delesCode FROM ' . Robotters::class . ' AS r, ' . RobottersDeles::class . ' AS p',
        "expected" => [
            'models' => [
                Robotters::class,
                RobottersDeles::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
                [
                    'robots_parts',
                    null,
                    'p',
                ],
            ],
            'columns' => [
                'theName' => [
                    'type' => 'scalar',
                    'balias' => 'theName',
                    'sqlAlias' => 'theName',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'name',
                        'balias' => 'theName',
                    ],
                ],
                'delesCode' => [
                    'type' => 'scalar',
                    'balias' => 'delesCode',
                    'sqlAlias' => 'delesCode',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'p',
                        'name' => 'parts_id',
                        'balias' => 'delesCode',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' AS r, ' . RobottersDeles::class . ' AS p WHERE r.code = p.robottersCode',
        "expected" => [
            'models' => [
                Robotters::class,
                RobottersDeles::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
                [
                    'robots_parts',
                    null,
                    'p',
                ],
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robotters::class),
                ],
                lcfirst(RobottersDeles::class) => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'p',
                    'balias' => lcfirst(RobottersDeles::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '=',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'id',
                    'balias' => 'code',
                ],
                'right' => [
                    'type' => 'qualified',
                    'domain' => 'p',
                    'name' => 'robots_id',
                    'balias' => 'robottersCode',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ', ' . RobottersDeles::class . ' WHERE ' . Robotters::class . '.code = ' . RobottersDeles::class . '.robottersCode',
        "expected" => [
            'models' => [
                Robotters::class,
                RobottersDeles::class,
            ],
            'tables' => [
                'robots',
                'robots_parts',
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robotters::class),
                ],
                lcfirst(RobottersDeles::class) => [
                    'type' => 'object',
                    'model' => RobottersDeles::class,
                    'column' => 'robots_parts',
                    'balias' => lcfirst(RobottersDeles::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '=',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'code',
                ],
                'right' => [
                    'type' => 'qualified',
                    'domain' => 'robots_parts',
                    'name' => 'robots_id',
                    'balias' => 'robottersCode',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' r WHERE NOT (r.theName = "shaggy") ORDER BY 1, r.theName',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robotters::class),
                ],
            ],
            'where' => [
                'type' => 'unary-op',
                'op' => 'NOT ',
                'right' => [
                    'type' => 'parentheses',
                    'left' => [
                        'type' => 'binary-op',
                        'op' => '=',
                        'left' => [
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'theName',
                        ],
                        'right' => [
                            'type' => 'literal',
                            'value' => '\'shaggy\'',
                        ],
                    ],
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'literal',
                        'value' => '1',
                    ],
                ],
                [
                    [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'name',
                        'balias' => 'theName',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' r WHERE NOT (r.theName = "shaggy") ORDER BY 1 DESC, r.theName',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robotters::class),
                ],
            ],
            'where' => [
                'type' => 'unary-op',
                'op' => 'NOT ',
                'right' => [
                    'type' => 'parentheses',
                    'left' => [
                        'type' => 'binary-op',
                        'op' => '=',
                        'left' => [
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'theName',
                        ],
                        'right' => [
                            'type' => 'literal',
                            'value' => '\'shaggy\'',
                        ],
                    ],
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'literal',
                        'value' => '1',
                    ],
                    'DESC',
                ],
                [
                    [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'name',
                        'balias' => 'theName',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' r WHERE NOT (r.theName = "shaggy") ORDER BY 1, r.theName',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robotters::class),
                ],
            ],
            'where' => [
                'type' => 'unary-op',
                'op' => 'NOT ',
                'right' => [
                    'type' => 'parentheses',
                    'left' => [
                        'type' => 'binary-op',
                        'op' => '=',
                        'left' => [
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'theName',
                        ],
                        'right' => [
                            'type' => 'literal',
                            'value' => '\'shaggy\'',
                        ],
                    ],
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'literal',
                        'value' => '1',
                    ],
                ],
                [
                    [
                        'type' => 'qualified',
                        'domain' => 'r',
                        'name' => 'name',
                        'balias' => 'theName',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' r WHERE r.theName <> "shaggy" ORDER BY 1, 2 LIMIT 5',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robotters::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '<>',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'name',
                    'balias' => 'theName',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '\'shaggy\'',
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'literal',
                        'value' => '1',
                    ],
                ],
                [
                    [
                        'type' => 'literal',
                        'value' => '2',
                    ],
                ],
            ],
            'limit' => [
                'number' => [
                    'type' => 'literal',
                    'value' => '5',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' r WHERE r.theName <> "shaggy" ORDER BY 1 ASC, 2 DESC LIMIT 5',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robotters::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '<>',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'r',
                    'name' => 'name',
                    'balias' => 'theName',
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '\'shaggy\'',
                ],
            ],
            'order' => [
                [
                    [
                        'type' => 'literal',
                        'value' => '1',
                    ],
                    'ASC',
                ],
                [
                    [
                        'type' => 'literal',
                        'value' => '2',
                    ],
                    'DESC',
                ],
            ],
            'limit' => [
                'number' => [
                    'type' => 'literal',
                    'value' => '5',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' GROUP BY ' . Robotters::class . '.theName',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robotters::class),
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'theName',
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robotters::class . ' GROUP BY ' . Robotters::class . '.theName, ' . Robotters::class . '.code',
        "expected" => [
            'models' => [
                Robotters::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robotters::class) => [
                    'type' => 'object',
                    'model' => Robotters::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robotters::class),
                ],
            ],
            'group' => [
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'theName',
                ],
                [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'code',
                ],
            ],
        ]
    ],
    [
        // Issue 1011
        "phql"     => 'SELECT * FROM ' . Robots::class . ' r LIMIT ?1,:limit:',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                [
                    'robots',
                    null,
                    'r',
                ],
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'r',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'limit' => [
                'number' => [
                    'type' => 'placeholder',
                    'value' => ':limit',
                ],
                'offset' => [
                    'type' => 'placeholder',
                    'value' => ':1',
                ],
            ],
        ]
    ],
    [
        // SELECT DISTINCT
        "phql"     => 'SELECT DISTINCT id, name FROM ' . Robots::class,
        "expected" => [
            'distinct' => 1,
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                'id' => [
                    'type' => 'scalar',
                    'balias' => 'id',
                    'sqlAlias' => 'id',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'id',
                        'balias' => 'id',
                    ],
                ],
                'name' => [
                    'type' => 'scalar',
                    'balias' => 'name',
                    'sqlAlias' => 'name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
            ],
        ]
    ],
    [
        // SELECT ALL
        "phql"     => 'SELECT ALL id, name FROM ' . Robots::class,
        "expected" => [
            'distinct' => 0,
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                'id' => [
                    'type' => 'scalar',
                    'balias' => 'id',
                    'sqlAlias' => 'id',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'id',
                        'balias' => 'id',
                    ],
                ],
                'name' => [
                    'type' => 'scalar',
                    'balias' => 'name',
                    'sqlAlias' => 'name',
                    'column' => [
                        'type' => 'qualified',
                        'domain' => 'robots',
                        'name' => 'name',
                        'balias' => 'name',
                    ],
                ],
            ],
        ]
    ],
    [
        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE id IN (SELECT robots_id FROM ' . RobotsParts::class . ')',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots',
            ],
            'columns' => [
                lcfirst(Robots::class) => [
                    'type' => 'object',
                    'model' => Robots::class,
                    'column' => 'robots',
                    'balias' => lcfirst(Robots::class),
                ],
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => 'IN',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'id',
                    'balias' => 'id',
                ],
                'right' => [
                    'type' => 'select',
                    'value' => [
                        'models' => [
                            RobotsParts::class,
                        ],
                        'tables' => [
                            'robots_parts',
                        ],
                        'columns' => [
                            'robots_id' => [
                                'type' => 'scalar',
                                'balias' => 'robots_id',
                                'sqlAlias' => 'robots_id',
                                'column' => [
                                    'type' => 'qualified',
                                    'domain' => 'robots_parts',
                                    'name' => 'robots_id',
                                    'balias' => 'robots_id',
                                ],
                            ],
                        ],
                    ],
                ],
            ],
        ]
    ],
    [
        // PR #13124, ISSUE #12971
        "phql"     => 'SELECT UPPER('. Robots::class . '.name) AS name FROM ' . Robots::class . ' WHERE ' . Robots::class .'.name = "Robotina"',
        "expected" => [
            'models' => [
                Robots::class,
            ],
            'tables' => [
                'robots'
            ],
            'columns' => [
                'name' => [
                    'type' => 'scalar',
                    'balias' => 'name',
                    'sqlAlias' => 'name',
                    'column' => [
                        'type' => 'functionCall',
                        'name' => 'UPPER',
                        'arguments' => [
                            [
                                'type' => 'qualified',
                                'domain' => 'robots',
                                'name' => 'name',
                                'balias' => 'name'
                            ]
                        ],
                    ],
                ]
            ],
            'where' => [
                'type' => 'binary-op',
                'op' => '=',
                'left' => [
                    'type' => 'qualified',
                    'domain' => 'robots',
                    'name' => 'name',
                    'balias' => 'name'
                ],
                'right' => [
                    'type' => 'literal',
                    'value' => '\'Robotina\''
                ]
            ]
        ]
    ],
];
