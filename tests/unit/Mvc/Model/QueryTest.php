<?php

namespace Phalcon\Test\Unit\Mvc\Model;

use Phalcon\DiInterface;
use Phalcon\Mvc\Model\Query;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Models\Deles;
use Phalcon\Test\Models\Parts;
use Phalcon\Test\Models\Personers;
use Phalcon\Test\Models\People;
use Phalcon\Test\Models\Products;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\Robotters;
use Phalcon\Test\Models\RobotsParts;
use Phalcon\Test\Models\RobottersDeles;
use Phalcon\Test\Models\Some\Robotters as SomeRobotters;
use Phalcon\Test\Models\Some\Products as SomeProducts;

/**
 * \Phalcon\Test\Unit\Mvc\Model\QueryTest
 * Tests the Phalcon\Mvc\Model\Query component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc\Model
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class QueryTest extends UnitTest
{
    /**
     * @var DiInterface
     */
    private $di;

    protected function _before()
    {
        parent::_before();

        /** @var \Phalcon\Mvc\Application $app */
        $app = $this->tester->getApplication();
        $this->di = $app->getDI();
    }

    public function testSelectParsing()
    {
        $this->specify(
            "SELECT PHQL queries don't work as expected",
            function ($phql, $expected) {
                $query = new Query($phql);

                $query->setDI($this->di);

                expect($query->parse())->equals($expected);
            },
            [
                "examples" => [
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class,
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                        ),
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . SomeProducts::class,
                        "expected" => array(
                            'models' => array(
                                SomeProducts::class,
                            ),
                            'tables' => array(
                                'le_products',
                            ),
                            'columns' => array(
                                lcfirst(SomeProducts::class) => array(
                                    'type' => 'object',
                                    'model' => SomeProducts::class,
                                    'column' => 'le_products',
                                    'balias' => lcfirst(SomeProducts::class),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ' . SomeProducts::class . '.* FROM ' . SomeProducts::class,
                        "expected" => array(
                            'models' => array(
                                SomeProducts::class,
                            ),
                            'tables' => array(
                                'le_products',
                            ),
                            'columns' => array(
                                lcfirst(SomeProducts::class) => array(
                                    'type' => 'object',
                                    'model' => SomeProducts::class,
                                    'column' => 'le_products',
                                    'balias' => lcfirst(SomeProducts::class),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT p.* FROM ' . SomeProducts::class . ' p',
                        "expected" => array(
                            'models' => array(
                                SomeProducts::class,
                            ),
                            'tables' => array(
                                array(
                                    'le_products',
                                    null,
                                    'p',
                                ),
                            ),
                            'columns' => array(
                                'p' => array(
                                    'type' => 'object',
                                    'model' => SomeProducts::class,
                                    'column' => 'p',
                                    'balias' => 'p',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ' . Robots::class . '.* FROM ' . Robots::class,
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT r.* FROM ' . Robots::class . ' r',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                'r' => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => 'r',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT r.* FROM ' . Robots::class . ' AS r',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                'r' => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => 'r',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT id, name FROM ' . Robots::class,
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                'id' => array(
                                    'type' => 'scalar',
                                    'balias' => 'id',
                                    'sqlAlias' => 'id',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'id',
                                        'balias' => 'id',
                                    ),
                                ),
                                'name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'name',
                                    'sqlAlias' => 'name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT r.id, r.name FROM ' . Robots::class . ' AS r',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                'id' => array(
                                    'type' => 'scalar',
                                    'balias' => 'id',
                                    'sqlAlias' => 'id',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'id',
                                        'balias' => 'id',
                                    ),
                                ),
                                'name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'name',
                                    'sqlAlias' => 'name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT r.id AS le_id, r.name AS le_name FROM ' . Robots::class . ' AS r',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                'le_id' => array(
                                    'type' => 'scalar',
                                    'balias' => 'le_id',
                                    'sqlAlias' => 'le_id',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'id',
                                        'balias' => 'id',
                                    ),
                                ),
                                'le_name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'le_name',
                                    'sqlAlias' => 'le_name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ' . Robots::class . '.id AS le_id, ' . Robots::class . '.name AS le_name FROM ' . Robots::class,
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                'le_id' => array(
                                    'type' => 'scalar',
                                    'balias' => 'le_id',
                                    'sqlAlias' => 'le_id',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'id',
                                        'balias' => 'id',
                                    ),
                                ),
                                'le_name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'le_name',
                                    'sqlAlias' => 'le_name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT \'\' empty_str, 10.5 double_number, 1000 AS long_number FROM ' . Robots::class,
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                'empty_str' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'literal',
                                        'value' => '\'\'',
                                    ),
                                    'balias' => 'empty_str',
                                    'sqlAlias' => 'empty_str',
                                ),
                                'double_number' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'literal',
                                        'value' => '10.5',
                                    ),
                                    'balias' => 'double_number',
                                    'sqlAlias' => 'double_number',
                                ),
                                'long_number' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'literal',
                                        'value' => '1000',
                                    ),
                                    'balias' => 'long_number',
                                    'sqlAlias' => 'long_number',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ' . People::class . '.cedula FROM ' . People::class,
                        "expected" => array(
                            'models' => array(
                                People::class,
                            ),
                            'tables' => array(
                                'personas',
                            ),
                            'columns' => array(
                                'cedula' => array(
                                    'type' => 'scalar',
                                    'balias' => 'cedula',
                                    'sqlAlias' => 'cedula',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'personas',
                                        'name' => 'cedula',
                                        'balias' => 'cedula',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'select ' . strtolower(People::class) . '.cedula from ' . strtolower(People::class),
                        "expected" => array(
                            'models' => array(
                                strtolower(People::class),
                            ),
                            'tables' => array(
                                'personas',
                            ),
                            'columns' => array(
                                'cedula' => array(
                                    'type' => 'scalar',
                                    'balias' => 'cedula',
                                    'sqlAlias' => 'cedula',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'personas',
                                        'name' => 'cedula',
                                        'balias' => 'cedula',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT p.cedula AS cedula FROM ' . People::class . ' p',
                        "expected" => array(
                            'models' => array(
                                People::class,
                            ),
                            'tables' => array(
                                array(
                                    'personas',
                                    null,
                                    'p',
                                ),
                            ),
                            'columns' => array(
                                'cedula' => array(
                                    'type' => 'scalar',
                                    'balias' => 'cedula',
                                    'sqlAlias' => 'cedula',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'p',
                                        'name' => 'cedula',
                                        'balias' => 'cedula',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT CONCAT(cedula,\'-\',nombres) AS nombre FROM ' . People::class,
                        "expected" => array(
                            'models' => array(
                                People::class,
                            ),
                            'tables' => array(
                                'personas',
                            ),
                            'columns' => array(
                                'nombre' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'CONCAT',
                                        'arguments' => array(
                                            array(
                                                'type' => 'qualified',
                                                'domain' => 'personas',
                                                'name' => 'cedula',
                                                'balias' => 'cedula',
                                            ),
                                            array(
                                                'type' => 'literal',
                                                'value' => '\'-\'',
                                            ),
                                            array(
                                                'type' => 'qualified',
                                                'domain' => 'personas',
                                                'name' => 'nombres',
                                                'balias' => 'nombres',
                                            ),
                                        ),
                                    ),
                                    'balias' => 'nombre',
                                    'sqlAlias' => 'nombre',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT CONCAT(' . People::class . '.cedula,\'-\',' . People::class . '.nombres) AS nombre FROM ' . People::class,
                        "expected" => array(
                            'models' => array(
                                People::class,
                            ),
                            'tables' => array(
                                'personas',
                            ),
                            'columns' => array(
                                'nombre' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'CONCAT',
                                        'arguments' => array(
                                            array(
                                                'type' => 'qualified',
                                                'domain' => 'personas',
                                                'name' => 'cedula',
                                                'balias' => 'cedula',
                                            ),
                                            array(
                                                'type' => 'literal',
                                                'value' => '\'-\'',
                                            ),
                                            array(
                                                'type' => 'qualified',
                                                'domain' => 'personas',
                                                'name' => 'nombres',
                                                'balias' => 'nombres',
                                            ),
                                        ),
                                    ),
                                    'balias' => 'nombre',
                                    'sqlAlias' => 'nombre',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' JOIN ' . RobotsParts::class,
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                                lcfirst(RobotsParts::class) => array(
                                    'type' => 'object',
                                    'model' => RobotsParts::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobotsParts::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robots_id',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' CROSS JOIN ' . RobotsParts::class,
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                                lcfirst(RobotsParts::class) => array(
                                    'type' => 'object',
                                    'model' => RobotsParts::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobotsParts::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'CROSS',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robots_id',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' LEFT JOIN ' . RobotsParts::class . ' RIGHT JOIN ' . Parts::class,
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(RobotsParts::class) => array(
                                    'type' => 'object',
                                    'model' => RobotsParts::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobotsParts::class),
                                ),
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                                lcfirst(Parts::class) => array(
                                    'type' => 'object',
                                    'model' => Parts::class,
                                    'column' => 'parts',
                                    'balias' => lcfirst(Parts::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'LEFT',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robots_id',
                                            ),
                                        ),
                                    ),
                                ),
                                array(
                                    'type' => 'RIGHT',
                                    'source' => array(
                                        'parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . RobotsParts::class . ' LEFT OUTER JOIN ' . Robots::class . ' RIGHT OUTER JOIN ' . Parts::class,
                        "expected" => array(
                            'models' => array(
                                RobotsParts::class,
                            ),
                            'tables' => array(
                                'robots_parts',
                            ),
                            'columns' => array(
                                lcfirst(RobotsParts::class) => array(
                                    'type' => 'object',
                                    'model' => RobotsParts::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobotsParts::class),
                                ),
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                                lcfirst(Parts::class) => array(
                                    'type' => 'object',
                                    'model' => Parts::class,
                                    'column' => 'parts',
                                    'balias' => lcfirst(Parts::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'LEFT',
                                    'source' => array(
                                        'robots',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robots_id',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                        ),
                                    ),
                                ),
                                array(
                                    'type' => 'RIGHT',
                                    'source' => array(
                                        'parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'parts_id',
                                                'balias' => 'parts_id',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'parts',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' JOIN ' . RobotsParts::class . ' ON ' . Robots::class . '.id = ' . RobotsParts::class . '.robots_id',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                                lcfirst(RobotsParts::class) => array(
                                    'type' => 'object',
                                    'model' => RobotsParts::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobotsParts::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robots_id',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' LEFT OUTER JOIN ' . RobotsParts::class . ' ON ' . Robots::class . '.id = ' . RobotsParts::class . '.robots_id AND ' . RobotsParts::class . '.robots_id = ' . Robots::class . '.id WHERE ' . Robots::class . '.id IS NULL',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                                lcfirst(RobotsParts::class) => array(
                                    'type' => 'object',
                                    'model' => RobotsParts::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobotsParts::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'LEFT',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'binary-op',
                                                'op' => '=',
                                                'left' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'robots',
                                                    'name' => 'id',
                                                    'balias' => 'id',
                                                ),
                                                'right' => array(
                                                    'type' => 'binary-op',
                                                    'op' => 'AND',
                                                    'left' => array(
                                                        'type' => 'qualified',
                                                        'domain' => 'robots_parts',
                                                        'name' => 'robots_id',
                                                        'balias' => 'robots_id',
                                                    ),
                                                    'right' => array(
                                                        'type' => 'qualified',
                                                        'domain' => 'robots_parts',
                                                        'name' => 'robots_id',
                                                        'balias' => 'robots_id',
                                                    ),
                                                ),
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                            'where' => array(
                                'type' => 'unary-op',
                                'op' => ' IS NULL',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' RIGHT OUTER JOIN ' . RobotsParts::class . ' ON ' . Robots::class . '.id = ' . RobotsParts::class . '.robots_id AND ' . RobotsParts::class . '.robots_id = ' . Robots::class . '.id WHERE ' . RobotsParts::class . '.robots_id IS NOT NULL',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                                lcfirst(RobotsParts::class) => array(
                                    'type' => 'object',
                                    'model' => RobotsParts::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobotsParts::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'RIGHT',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'binary-op',
                                                'op' => '=',
                                                'left' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'robots',
                                                    'name' => 'id',
                                                    'balias' => 'id',
                                                ),
                                                'right' => array(
                                                    'type' => 'binary-op',
                                                    'op' => 'AND',
                                                    'left' => array(
                                                        'type' => 'qualified',
                                                        'domain' => 'robots_parts',
                                                        'name' => 'robots_id',
                                                        'balias' => 'robots_id',
                                                    ),
                                                    'right' => array(
                                                        'type' => 'qualified',
                                                        'domain' => 'robots_parts',
                                                        'name' => 'robots_id',
                                                        'balias' => 'robots_id',
                                                    ),
                                                ),
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                            'where' => array(
                                'type' => 'unary-op',
                                'op' => ' IS NOT NULL',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots_parts',
                                    'name' => 'robots_id',
                                    'balias' => 'robots_id',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' FULL OUTER JOIN ' . RobotsParts::class,
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                                lcfirst(RobotsParts::class) => array(
                                    'type' => 'object',
                                    'model' => RobotsParts::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobotsParts::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'FULL OUTER',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robots_id',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . RobotsParts::class . ' JOIN ' . Robots::class,
                        "expected" => array(
                            'models' => array(
                                RobotsParts::class,
                            ),
                            'tables' => array(
                                'robots_parts',
                            ),
                            'columns' => array(
                                lcfirst(RobotsParts::class) => array(
                                    'type' => 'object',
                                    'model' => RobotsParts::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobotsParts::class),
                                ),
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'robots',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robots_id',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT r.*, p.* FROM ' . Robots::class . ' AS r JOIN ' . RobotsParts::class . ' AS p',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                'r' => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => 'r',
                                ),
                                'p' => array(
                                    'type' => 'object',
                                    'model' => RobotsParts::class,
                                    'column' => 'p',
                                    'balias' => 'p',
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                        'p',
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'r',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'p',
                                                'name' => 'robots_id',
                                                'balias' => 'robots_id',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' AS r JOIN ' . RobotsParts::class . ' AS p',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robots::class),
                                ),
                                lcfirst(RobotsParts::class) => array(
                                    'type' => 'object',
                                    'model' => RobotsParts::class,
                                    'column' => 'p',
                                    'balias' => lcfirst(RobotsParts::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                        'p',
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'r',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'p',
                                                'name' => 'robots_id',
                                                'balias' => 'robots_id',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT r.* FROM ' . Robots::class . ' r INNER JOIN ' . RobotsParts::class,
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                'r' => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => 'r',
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'r',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robots_id',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ( ' . People::class . '.cupo + 100) / (' . Products::class . '.price * 0.15) FROM ' . People::class . ' JOIN ' . Products::class,
                        "expected" => array(
                            'models' => array(
                                People::class,
                            ),
                            'tables' => array(
                                'personas',
                            ),
                            'columns' => array(
                                '_0' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'binary-op',
                                        'op' => '/',
                                        'left' => array(
                                            'type' => 'parentheses',
                                            'left' => array(
                                                'type' => 'binary-op',
                                                'op' => '+',
                                                'left' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'personas',
                                                    'name' => 'cupo',
                                                    'balias' => 'cupo',
                                                ),
                                                'right' => array(
                                                    'type' => 'literal',
                                                    'value' => '100',
                                                ),
                                            ),
                                        ),
                                        'right' => array(
                                            'type' => 'parentheses',
                                            'left' => array(
                                                'type' => 'binary-op',
                                                'op' => '*',
                                                'left' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'products',
                                                    'name' => 'price',
                                                    'balias' => 'price',
                                                ),
                                                'right' => array(
                                                    'type' => 'literal',
                                                    'value' => '0.15',
                                                ),
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'products',
                                        null,
                                    ),
                                    'conditions' => array(
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ( ' . People::class . '.cupo + 100) / (' . SomeProducts::class . '.price * 0.15) AS price FROM ' . People::class . ' JOIN ' . SomeProducts::class,
                        "expected" => array(
                            'models' => array(
                                People::class,
                            ),
                            'tables' => array(
                                'personas',
                            ),
                            'columns' => array(
                                'price' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'binary-op',
                                        'op' => '/',
                                        'left' => array(
                                            'type' => 'parentheses',
                                            'left' => array(
                                                'type' => 'binary-op',
                                                'op' => '+',
                                                'left' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'personas',
                                                    'name' => 'cupo',
                                                    'balias' => 'cupo',
                                                ),
                                                'right' => array(
                                                    'type' => 'literal',
                                                    'value' => '100',
                                                ),
                                            ),
                                        ),
                                        'right' => array(
                                            'type' => 'parentheses',
                                            'left' => array(
                                                'type' => 'binary-op',
                                                'op' => '*',
                                                'left' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'le_products',
                                                    'name' => 'price',
                                                    'balias' => 'price',
                                                ),
                                                'right' => array(
                                                    'type' => 'literal',
                                                    'value' => '0.15',
                                                ),
                                            ),
                                        ),
                                    ),
                                    'balias' => 'price',
                                    'sqlAlias' => 'price',
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'le_products',
                                        null,
                                    ),
                                    'conditions' => array(
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT (p.cupo + 100) / (s.price * 0.15) AS price FROM ' . People::class . ' AS p JOIN ' . SomeProducts::class . ' AS s',
                        "expected" => array(
                            'models' => array(
                                People::class,
                            ),
                            'tables' => array(
                                array(
                                    'personas',
                                    null,
                                    'p',
                                ),
                            ),
                            'columns' => array(
                                'price' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'binary-op',
                                        'op' => '/',
                                        'left' => array(
                                            'type' => 'parentheses',
                                            'left' => array(
                                                'type' => 'binary-op',
                                                'op' => '+',
                                                'left' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'p',
                                                    'name' => 'cupo',
                                                    'balias' => 'cupo',
                                                ),
                                                'right' => array(
                                                    'type' => 'literal',
                                                    'value' => '100',
                                                ),
                                            ),
                                        ),
                                        'right' => array(
                                            'type' => 'parentheses',
                                            'left' => array(
                                                'type' => 'binary-op',
                                                'op' => '*',
                                                'left' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 's',
                                                    'name' => 'price',
                                                    'balias' => 'price',
                                                ),
                                                'right' => array(
                                                    'type' => 'literal',
                                                    'value' => '0.15',
                                                ),
                                            ),
                                        ),
                                    ),
                                    'balias' => 'price',
                                    'sqlAlias' => 'price',
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'le_products',
                                        null,
                                        's',
                                    ),
                                    'conditions' => array(
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ', ' . RobotsParts::class,
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                                RobotsParts::class,
                            ),
                            'tables' => array(
                                'robots',
                                'robots_parts',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                                lcfirst(RobotsParts::class) => array(
                                    'type' => 'object',
                                    'model' => RobotsParts::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobotsParts::class),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' r, ' . RobotsParts::class . ' p',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                                RobotsParts::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                                array(
                                    'robots_parts',
                                    null,
                                    'p',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robots::class),
                                ),
                                lcfirst(RobotsParts::class) => array(
                                    'type' => 'object',
                                    'model' => RobotsParts::class,
                                    'column' => 'p',
                                    'balias' => lcfirst(RobotsParts::class),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' AS r, ' . RobotsParts::class . ' AS p',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                                RobotsParts::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                                array(
                                    'robots_parts',
                                    null,
                                    'p',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robots::class),
                                ),
                                lcfirst(RobotsParts::class) => array(
                                    'type' => 'object',
                                    'model' => RobotsParts::class,
                                    'column' => 'p',
                                    'balias' => lcfirst(RobotsParts::class),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT name, parts_id FROM ' . Robots::class . ' AS r, ' . RobotsParts::class . ' AS p',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                                RobotsParts::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                                array(
                                    'robots_parts',
                                    null,
                                    'p',
                                ),
                            ),
                            'columns' => array(
                                'name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'name',
                                    'sqlAlias' => 'name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                                'parts_id' => array(
                                    'type' => 'scalar',
                                    'balias' => 'parts_id',
                                    'sqlAlias' => 'parts_id',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'p',
                                        'name' => 'parts_id',
                                        'balias' => 'parts_id',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' AS r, ' . RobotsParts::class . ' AS p WHERE r.id = p.robots_id',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                                RobotsParts::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                                array(
                                    'robots_parts',
                                    null,
                                    'p',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robots::class),
                                ),
                                lcfirst(RobotsParts::class) => array(
                                    'type' => 'object',
                                    'model' => RobotsParts::class,
                                    'column' => 'p',
                                    'balias' => lcfirst(RobotsParts::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'r',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                'right' => array(
                                    'type' => 'qualified',
                                    'domain' => 'p',
                                    'name' => 'robots_id',
                                    'balias' => 'robots_id',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ', ' . RobotsParts::class . ' WHERE ' . Robots::class . '.id = ' . RobotsParts::class . '.robots_id',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                                RobotsParts::class,
                            ),
                            'tables' => array(
                                'robots',
                                'robots_parts',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                                lcfirst(RobotsParts::class) => array(
                                    'type' => 'object',
                                    'model' => RobotsParts::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobotsParts::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                'right' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots_parts',
                                    'name' => 'robots_id',
                                    'balias' => 'robots_id',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id = 100',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id != 100',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '<>',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id > 100',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '>',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id < 100',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '<',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id >= 100',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '>=',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id <= 100',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '<=',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name LIKE \'as%\'',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => 'LIKE',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '\'as%\'',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name NOT LIKE \'as%\'',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => 'NOT LIKE',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '\'as%\'',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name BETWEEN \'john\' AND \'mike\'',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => 'BETWEEN',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                                'right' => array(
                                    'type' => 'binary-op',
                                    'op' => 'AND',
                                    'left' => array(
                                        'type' => 'literal',
                                        'value' => '\'john\'',
                                    ),
                                    'right' => array(
                                        'type' => 'literal',
                                        'value' => '\'mike\'',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . SomeProducts::class . ' WHERE DATE(' . SomeProducts::class . '.created_at) = "2010-10-02"',
                        "expected" => array(
                            'models' => array(
                                SomeProducts::class,
                            ),
                            'tables' => array(
                                'le_products',
                            ),
                            'columns' => array(
                                lcfirst(SomeProducts::class) => array(
                                    'type' => 'object',
                                    'model' => SomeProducts::class,
                                    'column' => 'le_products',
                                    'balias' => lcfirst(SomeProducts::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => array(
                                    'type' => 'functionCall',
                                    'name' => 'DATE',
                                    'arguments' => array(
                                        array(
                                            'type' => 'qualified',
                                            'domain' => 'le_products',
                                            'name' => 'created_at',
                                            'balias' => 'created_at',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '\'2010-10-02\'',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . SomeProducts::class . ' WHERE ' . SomeProducts::class . '.created_at < now()',
                        "expected" => array(
                            'models' => array(
                                SomeProducts::class,
                            ),
                            'tables' => array(
                                'le_products',
                            ),
                            'columns' => array(
                                lcfirst(SomeProducts::class) => array(
                                    'type' => 'object',
                                    'model' => SomeProducts::class,
                                    'column' => 'le_products',
                                    'balias' => lcfirst(SomeProducts::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '<',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'le_products',
                                    'name' => 'created_at',
                                    'balias' => 'created_at',
                                ),
                                'right' => array(
                                    'type' => 'functionCall',
                                    'name' => 'now',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id IN (1)',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => 'IN',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                'right' => array(
                                    'type' => 'list',
                                    array(
                                        array(
                                            'type' => 'literal',
                                            'value' => '1',
                                        )
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id IN (1, 2, 3, 4)',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => 'IN',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                'right' => array(
                                    'type' => 'list',
                                    array(
                                        array(
                                            'type' => 'literal',
                                            'value' => '1',
                                        ),
                                        array(
                                            'type' => 'literal',
                                            'value' => '2',
                                        ),
                                        array(
                                            'type' => 'literal',
                                            'value' => '3',
                                        ),
                                        array(
                                            'type' => 'literal',
                                            'value' => '4',
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' r WHERE r.id IN (r.id+1, r.id+2)',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => 'IN',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'r',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                'right' => array(
                                    'type' => 'list',
                                    array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '+',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'r',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                            'right' => array(
                                                'type' => 'literal',
                                                'value' => '1',
                                            ),
                                        ),
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '+',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'r',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                            'right' => array(
                                                'type' => 'literal',
                                                'value' => '2',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name = :name:',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                                'right' => array(
                                    'type' => 'placeholder',
                                    'value' => ':name',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name = ?0',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                                'right' => array(
                                    'type' => 'placeholder',
                                    'value' => ':0',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name = \'R2D2\' OR ' . Robots::class . '.name <> \'C3PO\'',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '<>',
                                'left' => array(
                                    'type' => 'binary-op',
                                    'op' => '=',
                                    'left' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                    'right' => array(
                                        'type' => 'binary-op',
                                        'op' => 'OR',
                                        'left' => array(
                                            'type' => 'literal',
                                            'value' => '\'R2D2\'',
                                        ),
                                        'right' => array(
                                            'type' => 'qualified',
                                            'domain' => 'robots',
                                            'name' => 'name',
                                            'balias' => 'name',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '\'C3PO\'',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name = \'R2D2\' AND ' . Robots::class . '.name <> \'C3PO\'',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '<>',
                                'left' => array(
                                    'type' => 'binary-op',
                                    'op' => '=',
                                    'left' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                    'right' => array(
                                        'type' => 'binary-op',
                                        'op' => 'AND',
                                        'left' => array(
                                            'type' => 'literal',
                                            'value' => '\'R2D2\'',
                                        ),
                                        'right' => array(
                                            'type' => 'qualified',
                                            'domain' => 'robots',
                                            'name' => 'name',
                                            'balias' => 'name',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '\'C3PO\'',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name = :first_name: AND ' . Robots::class . '.name <> :second_name:',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '<>',
                                'left' => array(
                                    'type' => 'binary-op',
                                    'op' => '=',
                                    'left' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                    'right' => array(
                                        'type' => 'binary-op',
                                        'op' => 'AND',
                                        'left' => array(
                                            'type' => 'placeholder',
                                            'value' => ':first_name',
                                        ),
                                        'right' => array(
                                            'type' => 'qualified',
                                            'domain' => 'robots',
                                            'name' => 'name',
                                            'balias' => 'name',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'placeholder',
                                    'value' => ':second_name',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.name = \'R2D2\' AND ' . Robots::class . '.name <> \'C3PO\' AND ' . Robots::class . '.id > 100',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '>',
                                'left' => array(
                                    'type' => 'binary-op',
                                    'op' => '<>',
                                    'left' => array(
                                        'type' => 'binary-op',
                                        'op' => '=',
                                        'left' => array(
                                            'type' => 'qualified',
                                            'domain' => 'robots',
                                            'name' => 'name',
                                            'balias' => 'name',
                                        ),
                                        'right' => array(
                                            'type' => 'binary-op',
                                            'op' => 'AND',
                                            'left' => array(
                                                'type' => 'literal',
                                                'value' => '\'R2D2\'',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'name',
                                                'balias' => 'name',
                                            ),
                                        ),
                                    ),
                                    'right' => array(
                                        'type' => 'binary-op',
                                        'op' => 'AND',
                                        'left' => array(
                                            'type' => 'literal',
                                            'value' => '\'C3PO\'',
                                        ),
                                        'right' => array(
                                            'type' => 'qualified',
                                            'domain' => 'robots',
                                            'name' => 'id',
                                            'balias' => 'id',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE (' . Robots::class . '.name = \'R2D2\' AND ' . Robots::class . '.name <> \'C3PO\') OR ' . Robots::class . '.id > 100',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '>',
                                'left' => array(
                                    'type' => 'binary-op',
                                    'op' => 'OR',
                                    'left' => array(
                                        'type' => 'parentheses',
                                        'left' => array(
                                            'type' => 'binary-op',
                                            'op' => '<>',
                                            'left' => array(
                                                'type' => 'binary-op',
                                                'op' => '=',
                                                'left' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'robots',
                                                    'name' => 'name',
                                                    'balias' => 'name',
                                                ),
                                                'right' => array(
                                                    'type' => 'binary-op',
                                                    'op' => 'AND',
                                                    'left' => array(
                                                        'type' => 'literal',
                                                        'value' => '\'R2D2\'',
                                                    ),
                                                    'right' => array(
                                                        'type' => 'qualified',
                                                        'domain' => 'robots',
                                                        'name' => 'name',
                                                        'balias' => 'name',
                                                    ),
                                                ),
                                            ),
                                            'right' => array(
                                                'type' => 'literal',
                                                'value' => '\'C3PO\'',
                                            ),
                                        ),
                                    ),
                                    'right' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'id',
                                        'balias' => 'id',
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE (' . Robots::class . '.name = \'R2D2\' AND ' . Robots::class . '.name <> \'C3PO\') OR (' . Robots::class . '.id > 100 AND ' . Robots::class . '.id <= 150)',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => 'OR',
                                'left' => array(
                                    'type' => 'parentheses',
                                    'left' => array(
                                        'type' => 'binary-op',
                                        'op' => '<>',
                                        'left' => array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'name',
                                                'balias' => 'name',
                                            ),
                                            'right' => array(
                                                'type' => 'binary-op',
                                                'op' => 'AND',
                                                'left' => array(
                                                    'type' => 'literal',
                                                    'value' => '\'R2D2\'',
                                                ),
                                                'right' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'robots',
                                                    'name' => 'name',
                                                    'balias' => 'name',
                                                ),
                                            ),
                                        ),
                                        'right' => array(
                                            'type' => 'literal',
                                            'value' => '\'C3PO\'',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'parentheses',
                                    'left' => array(
                                        'type' => 'binary-op',
                                        'op' => '<=',
                                        'left' => array(
                                            'type' => 'binary-op',
                                            'op' => '>',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                            'right' => array(
                                                'type' => 'binary-op',
                                                'op' => 'AND',
                                                'left' => array(
                                                    'type' => 'literal',
                                                    'value' => '100',
                                                ),
                                                'right' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'robots',
                                                    'name' => 'id',
                                                    'balias' => 'id',
                                                ),
                                            ),
                                        ),
                                        'right' => array(
                                            'type' => 'literal',
                                            'value' => '150',
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' r WHERE r.id NOT IN (r.id+1, r.id+2)',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => 'NOT IN',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'r',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                'right' => array(
                                    'type' => 'list',
                                    array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '+',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'r',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                            'right' => array(
                                                'type' => 'literal',
                                                'value' => '1',
                                            ),
                                        ),
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '+',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'r',
                                                'name' => 'id',
                                                'balias' => 'id',
                                            ),
                                            'right' => array(
                                                'type' => 'literal',
                                                'value' => '2',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' r LIMIT 100',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'limit' => array(
                                'number' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' r LIMIT 10,100',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'limit' => array(
                                'number' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                                'offset' => array(
                                    'type' => 'literal',
                                    'value' => '10',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' r LIMIT 100 OFFSET 10',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'limit' => array(
                                'number' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                                'offset' => array(
                                    'type' => 'literal',
                                    'value' => '10',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . SomeProducts::class . ' p WHERE p.name = "Artichoke" LIMIT 100',
                        "expected" => array(
                            'models' => array(
                                SomeProducts::class,
                            ),
                            'tables' => array(
                                array(
                                    'le_products',
                                    null,
                                    'p',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(SomeProducts::class) => array(
                                    'type' => 'object',
                                    'model' => SomeProducts::class,
                                    'column' => 'p',
                                    'balias' => lcfirst(SomeProducts::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'p',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '\'Artichoke\'',
                                ),
                            ),
                            'limit' => array(
                                'number' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . SomeProducts::class . ' p ORDER BY p.name',
                        "expected" => array(
                            'models' => array(
                                SomeProducts::class,
                            ),
                            'tables' => array(
                                array(
                                    'le_products',
                                    null,
                                    'p',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(SomeProducts::class) => array(
                                    'type' => 'object',
                                    'model' => SomeProducts::class,
                                    'column' => 'p',
                                    'balias' => lcfirst(SomeProducts::class),
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'qualified',
                                        'domain' => 'p',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . SomeProducts::class . ' ORDER BY ' . SomeProducts::class . '.name',
                        "expected" => array(
                            'models' => array(
                                SomeProducts::class,
                            ),
                            'tables' => array(
                                'le_products',
                            ),
                            'columns' => array(
                                lcfirst(SomeProducts::class) => array(
                                    'type' => 'object',
                                    'model' => SomeProducts::class,
                                    'column' => 'le_products',
                                    'balias' => lcfirst(SomeProducts::class),
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'qualified',
                                        'domain' => 'le_products',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . SomeProducts::class . ' ORDER BY id, ' . SomeProducts::class . '.name, 3',
                        "expected" => array(
                            'models' => array(
                                SomeProducts::class,
                            ),
                            'tables' => array(
                                'le_products',
                            ),
                            'columns' => array(
                                lcfirst(SomeProducts::class) => array(
                                    'type' => 'object',
                                    'model' => SomeProducts::class,
                                    'column' => 'le_products',
                                    'balias' => lcfirst(SomeProducts::class),
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'qualified',
                                        'domain' => 'le_products',
                                        'name' => 'id',
                                        'balias' => 'id',
                                    ),
                                ),
                                array(
                                    array(
                                        'type' => 'qualified',
                                        'domain' => 'le_products',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '3',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' r WHERE NOT (r.name = "shaggy") ORDER BY 1, r.name',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'unary-op',
                                'op' => 'NOT ',
                                'right' => array(
                                    'type' => 'parentheses',
                                    'left' => array(
                                        'type' => 'binary-op',
                                        'op' => '=',
                                        'left' => array(
                                            'type' => 'qualified',
                                            'domain' => 'r',
                                            'name' => 'name',
                                            'balias' => 'name',
                                        ),
                                        'right' => array(
                                            'type' => 'literal',
                                            'value' => '\'shaggy\'',
                                        ),
                                    ),
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '1',
                                    ),
                                ),
                                array(
                                    array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' r WHERE NOT (r.name = "shaggy") ORDER BY 1 DESC, r.name',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'unary-op',
                                'op' => 'NOT ',
                                'right' => array(
                                    'type' => 'parentheses',
                                    'left' => array(
                                        'type' => 'binary-op',
                                        'op' => '=',
                                        'left' => array(
                                            'type' => 'qualified',
                                            'domain' => 'r',
                                            'name' => 'name',
                                            'balias' => 'name',
                                        ),
                                        'right' => array(
                                            'type' => 'literal',
                                            'value' => '\'shaggy\'',
                                        ),
                                    ),
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '1',
                                    ),
                                    'DESC',
                                ),
                                array(
                                    array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' r WHERE NOT (r.name = "shaggy") ORDER BY 1, r.name',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'unary-op',
                                'op' => 'NOT ',
                                'right' => array(
                                    'type' => 'parentheses',
                                    'left' => array(
                                        'type' => 'binary-op',
                                        'op' => '=',
                                        'left' => array(
                                            'type' => 'qualified',
                                            'domain' => 'r',
                                            'name' => 'name',
                                            'balias' => 'name',
                                        ),
                                        'right' => array(
                                            'type' => 'literal',
                                            'value' => '\'shaggy\'',
                                        ),
                                    ),
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '1',
                                    ),
                                ),
                                array(
                                    array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' r WHERE r.name <> "shaggy" ORDER BY 1, 2 LIMIT 5',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '<>',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'r',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '\'shaggy\'',
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '1',
                                    ),
                                ),
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '2',
                                    ),
                                ),
                            ),
                            'limit' => array(
                                'number' => array(
                                    'type' => 'literal',
                                    'value' => '5',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' r WHERE r.name <> "shaggy" ORDER BY 1 ASC, 2 DESC LIMIT 5',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '<>',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'r',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '\'shaggy\'',
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '1',
                                    ),
                                    'ASC',
                                ),
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '2',
                                    ),
                                    'DESC',
                                ),
                            ),
                            'limit' => array(
                                'number' => array(
                                    'type' => 'literal',
                                    'value' => '5',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' GROUP BY ' . Robots::class . '.name',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' GROUP BY ' . Robots::class . '.name, ' . Robots::class . '.id',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ' . Robots::class . '.name, SUM(' . Robots::class . '.price) AS summatory FROM ' . Robots::class . ' GROUP BY ' . Robots::class . '.name',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                'name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'name',
                                    'sqlAlias' => 'name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                                'summatory' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'SUM',
                                        'arguments' => array(
                                            array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'price',
                                                'balias' => 'price',
                                            ),
                                        ),
                                    ),
                                    'balias' => 'summatory',
                                    'sqlAlias' => 'summatory',
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT r.id, r.name, SUM(r.price) AS summatory, MIN(r.price) FROM ' . Robots::class . ' r GROUP BY r.id, r.name',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                'id' => array(
                                    'type' => 'scalar',
                                    'balias' => 'id',
                                    'sqlAlias' => 'id',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'id',
                                        'balias' => 'id',
                                    ),
                                ),
                                'name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'name',
                                    'sqlAlias' => 'name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                                'summatory' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'SUM',
                                        'arguments' => array(
                                            array(
                                                'type' => 'qualified',
                                                'domain' => 'r',
                                                'name' => 'price',
                                                'balias' => 'price',
                                            ),
                                        ),
                                    ),
                                    'balias' => 'summatory',
                                    'sqlAlias' => 'summatory',
                                ),
                                '_3' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'MIN',
                                        'arguments' => array(
                                            array(
                                                'type' => 'qualified',
                                                'domain' => 'r',
                                                'name' => 'price',
                                                'balias' => 'price',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'r',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'r',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id > 5 GROUP BY ' . Robots::class . '.name',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '>',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '5',
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id > 5 GROUP BY ' . Robots::class . '.name LIMIT 10',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '>',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '5',
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                            ),
                            'limit' => array(
                                'number' => array(
                                    'type' => 'literal',
                                    'value' => '10',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id > 5 GROUP BY ' . Robots::class . '.name ORDER BY ' . Robots::class . '.id LIMIT 10',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '>',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '5',
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'id',
                                        'balias' => 'id',
                                    ),
                                ),
                            ),
                            'limit' => array(
                                'number' => array(
                                    'type' => 'literal',
                                    'value' => '10',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' GROUP BY ' . Robots::class . '.name ORDER BY ' . Robots::class . '.id',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'id',
                                        'balias' => 'id',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE ' . Robots::class . '.id != 10 GROUP BY ' . Robots::class . '.name ORDER BY ' . Robots::class . '.id',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '<>',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '10',
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'id',
                                        'balias' => 'id',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ' . Robots::class . '.name, COUNT(*) FROM ' . Robots::class . ' GROUP BY ' . Robots::class . '.name HAVING COUNT(*)>100',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                'name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'name',
                                    'sqlAlias' => 'name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                                '_1' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'COUNT',
                                        'arguments' => array(
                                            array(
                                                'type' => 'all',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                            ),
                            'having' => array(
                                'type' => 'binary-op',
                                'op' => '>',
                                'left' => array(
                                    'type' => 'functionCall',
                                    'name' => 'COUNT',
                                    'arguments' => array(
                                        array(
                                            'type' => 'all',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ' . SomeProducts::class . '.type, SUM(' . SomeProducts::class . '.price) AS price FROM ' . SomeProducts::class . ' GROUP BY ' . SomeProducts::class . '.type HAVING SUM(' . SomeProducts::class . '.price)<100',
                        "expected" => array(
                            'models' => array(
                                SomeProducts::class,
                            ),
                            'tables' => array(
                                'le_products',
                            ),
                            'columns' => array(
                                'type' => array(
                                    'type' => 'scalar',
                                    'balias' => 'type',
                                    'sqlAlias' => 'type',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'le_products',
                                        'name' => 'type',
                                        'balias' => 'type',
                                    ),
                                ),
                                'price' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'SUM',
                                        'arguments' => array(
                                            array(
                                                'type' => 'qualified',
                                                'domain' => 'le_products',
                                                'name' => 'price',
                                                'balias' => 'price',
                                            ),
                                        ),
                                    ),
                                    'balias' => 'price',
                                    'sqlAlias' => 'price',
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'le_products',
                                    'name' => 'type',
                                    'balias' => 'type',
                                ),
                            ),
                            'having' => array(
                                'type' => 'binary-op',
                                'op' => '<',
                                'left' => array(
                                    'type' => 'functionCall',
                                    'name' => 'SUM',
                                    'arguments' => array(
                                        array(
                                            'type' => 'qualified',
                                            'name' => 'price',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT type, SUM(price) AS price FROM ' . SomeProducts::class . ' GROUP BY 1 HAVING SUM(price)<100',
                        "expected" => array(
                            'models' => array(
                                SomeProducts::class,
                            ),
                            'tables' => array(
                                'le_products',
                            ),
                            'columns' => array(
                                'type' => array(
                                    'type' => 'scalar',
                                    'balias' => 'type',
                                    'sqlAlias' => 'type',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'le_products',
                                        'name' => 'type',
                                        'balias' => 'type',
                                    ),
                                ),
                                'price' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'SUM',
                                        'arguments' => array(
                                            array(
                                                'type' => 'qualified',
                                                'domain' => 'le_products',
                                                'name' => 'price',
                                                'balias' => 'price',
                                            ),
                                        ),
                                    ),
                                    'balias' => 'price',
                                    'sqlAlias' => 'price',
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'literal',
                                    'value' => '1',
                                ),
                            ),
                            'having' => array(
                                'type' => 'binary-op',
                                'op' => '<',
                                'left' => array(
                                    'type' => 'functionCall',
                                    'name' => 'SUM',
                                    'arguments' => array(
                                        array(
                                            'type' => 'qualified',
                                            'name' => 'price',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT COUNT(DISTINCT ' . SomeProducts::class . '.type) AS price FROM ' . SomeProducts::class,
                        "expected" => array(
                            'models' => array(
                                SomeProducts::class,
                            ),
                            'tables' => array(
                                'le_products',
                            ),
                            'columns' => array(
                                'price' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'COUNT',
                                        'arguments' => array(
                                            array(
                                                'type' => 'qualified',
                                                'domain' => 'le_products',
                                                'name' => 'type',
                                                'balias' => 'type',
                                            ),
                                        ),
                                        'distinct' => 1,
                                    ),
                                    'balias' => 'price',
                                    'sqlAlias' => 'price',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT COUNT(DISTINCT ' . SomeProducts::class . '.type) price FROM ' . SomeProducts::class,
                        "expected" => array(
                            'models' => array(
                                SomeProducts::class,
                            ),
                            'tables' => array(
                                'le_products',
                            ),
                            'columns' => array(
                                'price' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'COUNT',
                                        'arguments' => array(
                                            array(
                                                'type' => 'qualified',
                                                'domain' => 'le_products',
                                                'name' => 'type',
                                                'balias' => 'type',
                                            ),
                                        ),
                                        'distinct' => 1,
                                    ),
                                    'balias' => 'price',
                                    'sqlAlias' => 'price',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ' . Robots::class . '.name, COUNT(*) FROM ' . Robots::class . ' WHERE ' . Robots::class . '.type = "virtual" GROUP BY ' . Robots::class . '.name HAVING COUNT(*)>100',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                'name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'name',
                                    'sqlAlias' => 'name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                                '_1' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'COUNT',
                                        'arguments' => array(
                                            array(
                                                'type' => 'all',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'type',
                                    'balias' => 'type',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '\'virtual\'',
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                            ),
                            'having' => array(
                                'type' => 'binary-op',
                                'op' => '>',
                                'left' => array(
                                    'type' => 'functionCall',
                                    'name' => 'COUNT',
                                    'arguments' => array(
                                        array(
                                            'type' => 'all',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ' . Robots::class . '.name, COUNT(*) FROM ' . Robots::class . ' WHERE ' . Robots::class . '.type = "virtual" GROUP BY ' . Robots::class . '.name HAVING COUNT(*)>100 ORDER BY 2',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                'name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'name',
                                    'sqlAlias' => 'name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                                '_1' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'COUNT',
                                        'arguments' => array(
                                            array(
                                                'type' => 'all',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'type',
                                    'balias' => 'type',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '\'virtual\'',
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                            ),
                            'having' => array(
                                'type' => 'binary-op',
                                'op' => '>',
                                'left' => array(
                                    'type' => 'functionCall',
                                    'name' => 'COUNT',
                                    'arguments' => array(
                                        array(
                                            'type' => 'all',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '2',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ' . Robots::class . '.name, COUNT(*) FROM ' . Robots::class . ' WHERE ' . Robots::class . '.type = "virtual" GROUP BY ' . Robots::class . '.name HAVING COUNT(*)>100 ORDER BY 2 LIMIT 15',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                'name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'name',
                                    'sqlAlias' => 'name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                                '_1' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'COUNT',
                                        'arguments' => array(
                                            array(
                                                'type' => 'all',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'type',
                                    'balias' => 'type',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '\'virtual\'',
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                            ),
                            'having' => array(
                                'type' => 'binary-op',
                                'op' => '>',
                                'left' => array(
                                    'type' => 'functionCall',
                                    'name' => 'COUNT',
                                    'arguments' => array(
                                        array(
                                            'type' => 'all',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '2',
                                    ),
                                ),
                            ),
                            'limit' => array(
                                'number' => array(
                                    'type' => 'literal',
                                    'value' => '15',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ' . Robots::class . '.name, COUNT(*) FROM ' . Robots::class . ' GROUP BY ' . Robots::class . '.name HAVING COUNT(*)>100 ORDER BY 2 LIMIT 15',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                'name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'name',
                                    'sqlAlias' => 'name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                                '_1' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'COUNT',
                                        'arguments' => array(
                                            array(
                                                'type' => 'all',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                            ),
                            'having' => array(
                                'type' => 'binary-op',
                                'op' => '>',
                                'left' => array(
                                    'type' => 'functionCall',
                                    'name' => 'COUNT',
                                    'arguments' => array(
                                        array(
                                            'type' => 'all',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '2',
                                    ),
                                ),
                            ),
                            'limit' => array(
                                'number' => array(
                                    'type' => 'literal',
                                    'value' => '15',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT name, COUNT(*) FROM ' . Robots::class . ' WHERE type = "virtual" GROUP BY name HAVING COUNT(*)>100 LIMIT 15',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                'name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'name',
                                    'sqlAlias' => 'name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                                '_1' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'COUNT',
                                        'arguments' => array(
                                            array(
                                                'type' => 'all',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'type',
                                    'balias' => 'type',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '\'virtual\'',
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                            ),
                            'having' => array(
                                'type' => 'binary-op',
                                'op' => '>',
                                'left' => array(
                                    'type' => 'functionCall',
                                    'name' => 'COUNT',
                                    'arguments' => array(
                                        array(
                                            'type' => 'all',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                            'limit' => array(
                                'number' => array(
                                    'type' => 'literal',
                                    'value' => '15',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ' . Robots::class . '.name, COUNT(*) FROM ' . Robots::class . ' WHERE ' . Robots::class . '.type = "virtual" GROUP BY ' . Robots::class . '.name HAVING COUNT(*)>100 LIMIT 15',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                'name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'name',
                                    'sqlAlias' => 'name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                                '_1' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'COUNT',
                                        'arguments' => array(
                                            array(
                                                'type' => 'all',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'type',
                                    'balias' => 'type',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '\'virtual\'',
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                            ),
                            'having' => array(
                                'type' => 'binary-op',
                                'op' => '>',
                                'left' => array(
                                    'type' => 'functionCall',
                                    'name' => 'COUNT',
                                    'arguments' => array(
                                        array(
                                            'type' => 'all',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                            'limit' => array(
                                'number' => array(
                                    'type' => 'literal',
                                    'value' => '15',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ' . Robots::class . '.name, COUNT(*) FROM ' . Robots::class . ' GROUP BY ' . Robots::class . '.name HAVING COUNT(*)>100 LIMIT 15',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                'name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'name',
                                    'sqlAlias' => 'name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                                '_1' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'COUNT',
                                        'arguments' => array(
                                            array(
                                                'type' => 'all',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'name',
                                ),
                            ),
                            'having' => array(
                                'type' => 'binary-op',
                                'op' => '>',
                                'left' => array(
                                    'type' => 'functionCall',
                                    'name' => 'COUNT',
                                    'arguments' => array(
                                        array(
                                            'type' => 'all',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                            ),
                            'limit' => array(
                                'number' => array(
                                    'type' => 'literal',
                                    'value' => '15',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class,
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . SomeRobotters::class,
                        "expected" => array(
                            'models' => array(
                                SomeRobotters::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(SomeRobotters::class) => array(
                                    'type' => 'object',
                                    'model' => SomeRobotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(SomeRobotters::class),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ' . SomeRobotters::class . '.* FROM ' . SomeRobotters::class,
                        "expected" => array(
                            'models' => array(
                                SomeRobotters::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(SomeRobotters::class) => array(
                                    'type' => 'object',
                                    'model' => SomeRobotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(SomeRobotters::class),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT r.* FROM ' . SomeRobotters::class . ' r',
                        "expected" => array(
                            'models' => array(
                                SomeRobotters::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                'r' => array(
                                    'type' => 'object',
                                    'model' => SomeRobotters::class,
                                    'column' => 'r',
                                    'balias' => 'r',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ' . Robotters::class . '.* FROM ' . Robotters::class,
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT r.* FROM ' . Robotters::class . ' r',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                'r' => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'r',
                                    'balias' => 'r',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT r.* FROM ' . Robotters::class . ' AS r',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                'r' => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'r',
                                    'balias' => 'r',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT code, theName FROM ' . Robotters::class,
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                'code' => array(
                                    'type' => 'scalar',
                                    'balias' => 'code',
                                    'sqlAlias' => 'code',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'id',
                                        'balias' => 'code',
                                    ),
                                ),
                                'theName' => array(
                                    'type' => 'scalar',
                                    'balias' => 'theName',
                                    'sqlAlias' => 'theName',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'theName',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT r.code, r.theName FROM ' . Robotters::class . ' AS r',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                'code' => array(
                                    'type' => 'scalar',
                                    'balias' => 'code',
                                    'sqlAlias' => 'code',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'id',
                                        'balias' => 'code',
                                    ),
                                ),
                                'theName' => array(
                                    'type' => 'scalar',
                                    'balias' => 'theName',
                                    'sqlAlias' => 'theName',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'name',
                                        'balias' => 'theName',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT r.code AS le_id, r.theName AS le_name FROM ' . Robotters::class . ' AS r',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                'le_id' => array(
                                    'type' => 'scalar',
                                    'balias' => 'le_id',
                                    'sqlAlias' => 'le_id',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'id',
                                        'balias' => 'code',
                                    ),
                                ),
                                'le_name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'le_name',
                                    'sqlAlias' => 'le_name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'name',
                                        'balias' => 'theName',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ' . Robotters::class . '.code AS le_id, ' . Robotters::class . '.theName AS le_name FROM ' . Robotters::class,
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                'le_id' => array(
                                    'type' => 'scalar',
                                    'balias' => 'le_id',
                                    'sqlAlias' => 'le_id',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'id',
                                        'balias' => 'code',
                                    ),
                                ),
                                'le_name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'le_name',
                                    'sqlAlias' => 'le_name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'theName',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT \'\' empty_str, 10.5 double_number, 1000 AS long_number FROM ' . Robotters::class,
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                'empty_str' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'literal',
                                        'value' => '\'\'',
                                    ),
                                    'balias' => 'empty_str',
                                    'sqlAlias' => 'empty_str',
                                ),
                                'double_number' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'literal',
                                        'value' => '10.5',
                                    ),
                                    'balias' => 'double_number',
                                    'sqlAlias' => 'double_number',
                                ),
                                'long_number' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'literal',
                                        'value' => '1000',
                                    ),
                                    'balias' => 'long_number',
                                    'sqlAlias' => 'long_number',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ' . Personers::class . '.borgerId FROM ' . Personers::class,
                        "expected" => array(
                            'models' => array(
                                Personers::class,
                            ),
                            'tables' => array(
                                'personas',
                            ),
                            'columns' => array(
                                'borgerId' => array(
                                    'type' => 'scalar',
                                    'balias' => 'borgerId',
                                    'sqlAlias' => 'borgerId',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'personas',
                                        'name' => 'cedula',
                                        'balias' => 'borgerId',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'select ' . strtolower(Personers::class) . '.borgerId from ' . strtolower(Personers::class),
                        "expected" => array(
                            'models' => array(
                                strtolower(Personers::class),
                            ),
                            'tables' => array(
                                'personas',
                            ),
                            'columns' => array(
                                'borgerId' => array(
                                    'type' => 'scalar',
                                    'balias' => 'borgerId',
                                    'sqlAlias' => 'borgerId',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'personas',
                                        'name' => 'cedula',
                                        'balias' => 'borgerId',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT p.borgerId AS cedula FROM ' . Personers::class . ' p',
                        "expected" => array(
                            'models' => array(
                                Personers::class,
                            ),
                            'tables' => array(
                                array(
                                    'personas',
                                    null,
                                    'p',
                                ),
                            ),
                            'columns' => array(
                                'cedula' => array(
                                    'type' => 'scalar',
                                    'balias' => 'cedula',
                                    'sqlAlias' => 'cedula',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'p',
                                        'name' => 'cedula',
                                        'balias' => 'borgerId',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT CONCAT(' . Personers::class . '.borgerId,\'-\',' . Personers::class . '.navnes) AS navne FROM ' . Personers::class,
                        "expected" => array(
                            'models' => array(
                                Personers::class,
                            ),
                            'tables' => array(
                                'personas',
                            ),
                            'columns' => array(
                                'navne' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'functionCall',
                                        'name' => 'CONCAT',
                                        'arguments' => array(
                                            array(
                                                'type' => 'qualified',
                                                'domain' => 'personas',
                                                'name' => 'cedula',
                                                'balias' => 'borgerId',
                                            ),
                                            array(
                                                'type' => 'literal',
                                                'value' => '\'-\'',
                                            ),
                                            array(
                                                'type' => 'qualified',
                                                'domain' => 'personas',
                                                'name' => 'nombres',
                                                'balias' => 'navnes',
                                            ),
                                        ),
                                    ),
                                    'balias' => 'navne',
                                    'sqlAlias' => 'navne',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' JOIN ' . RobottersDeles::class,
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                                lcfirst(RobottersDeles::class) => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobottersDeles::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'code',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robottersCode',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' CROSS JOIN ' . RobottersDeles::class,
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                                lcfirst(RobottersDeles::class) => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobottersDeles::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'CROSS',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'code',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robottersCode',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' LEFT JOIN ' . RobottersDeles::class . ' RIGHT JOIN ' . Deles::class,
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                                lcfirst(RobottersDeles::class) => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobottersDeles::class),
                                ),
                                lcfirst(Deles::class) => array(
                                    'type' => 'object',
                                    'model' => Deles::class,
                                    'column' => 'parts',
                                    'balias' => lcfirst(Deles::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'LEFT',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'code',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robottersCode',
                                            ),
                                        ),
                                    ),
                                ),
                                array(
                                    'type' => 'RIGHT',
                                    'source' => array(
                                        'parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . RobottersDeles::class . ' LEFT OUTER JOIN ' . Robotters::class . ' RIGHT OUTER JOIN ' . Deles::class,
                        "expected" => array(
                            'models' => array(
                                RobottersDeles::class,
                            ),
                            'tables' => array(
                                'robots_parts',
                            ),
                            'columns' => array(
                                lcfirst(RobottersDeles::class) => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobottersDeles::class),
                                ),
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                                lcfirst(Deles::class) => array(
                                    'type' => 'object',
                                    'model' => Deles::class,
                                    'column' => 'parts',
                                    'balias' => lcfirst(Deles::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'LEFT',
                                    'source' => array(
                                        'robots',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robottersCode',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'code',
                                            ),
                                        ),
                                    ),
                                ),
                                array(
                                    'type' => 'RIGHT',
                                    'source' => array(
                                        'parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'parts_id',
                                                'balias' => 'delesCode',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'parts',
                                                'name' => 'id',
                                                'balias' => 'code',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' JOIN ' . RobottersDeles::class . ' ON ' . Robotters::class . '.code = ' . RobottersDeles::class . '.robottersCode',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                                lcfirst(RobottersDeles::class) => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobottersDeles::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'code',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robottersCode',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' LEFT OUTER JOIN ' . RobottersDeles::class . ' ON ' . Robotters::class . '.code = ' . RobottersDeles::class . '.robottersCode AND ' . RobottersDeles::class . '.robottersCode = ' . Robotters::class . '.code WHERE ' . Robotters::class . '.code IS NULL',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                                lcfirst(RobottersDeles::class) => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobottersDeles::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'LEFT',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'binary-op',
                                                'op' => '=',
                                                'left' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'robots',
                                                    'name' => 'id',
                                                    'balias' => 'code',
                                                ),
                                                'right' => array(
                                                    'type' => 'binary-op',
                                                    'op' => 'AND',
                                                    'left' => array(
                                                        'type' => 'qualified',
                                                        'domain' => 'robots_parts',
                                                        'name' => 'robots_id',
                                                        'balias' => 'robottersCode',
                                                    ),
                                                    'right' => array(
                                                        'type' => 'qualified',
                                                        'domain' => 'robots_parts',
                                                        'name' => 'robots_id',
                                                        'balias' => 'robottersCode',
                                                    ),
                                                ),
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'code',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                            'where' => array(
                                'type' => 'unary-op',
                                'op' => ' IS NULL',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'code',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' RIGHT OUTER JOIN ' . RobottersDeles::class . ' ON ' . Robotters::class . '.code = ' . RobottersDeles::class . '.robottersCode AND ' . RobottersDeles::class . '.robottersCode = ' . Robotters::class . '.code WHERE ' . RobottersDeles::class . '.robottersCode IS NOT NULL',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                                lcfirst(RobottersDeles::class) => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobottersDeles::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'RIGHT',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'binary-op',
                                                'op' => '=',
                                                'left' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'robots',
                                                    'name' => 'id',
                                                    'balias' => 'code',
                                                ),
                                                'right' => array(
                                                    'type' => 'binary-op',
                                                    'op' => 'AND',
                                                    'left' => array(
                                                        'type' => 'qualified',
                                                        'domain' => 'robots_parts',
                                                        'name' => 'robots_id',
                                                        'balias' => 'robottersCode',
                                                    ),
                                                    'right' => array(
                                                        'type' => 'qualified',
                                                        'domain' => 'robots_parts',
                                                        'name' => 'robots_id',
                                                        'balias' => 'robottersCode',
                                                    ),
                                                ),
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'code',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                            'where' => array(
                                'type' => 'unary-op',
                                'op' => ' IS NOT NULL',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots_parts',
                                    'name' => 'robots_id',
                                    'balias' => 'robottersCode',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' FULL OUTER JOIN ' . RobottersDeles::class,
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                                lcfirst(RobottersDeles::class) => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobottersDeles::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'FULL OUTER',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'code',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robottersCode',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . RobottersDeles::class . ' JOIN ' . Robotters::class,
                        "expected" => array(
                            'models' => array(
                                RobottersDeles::class,
                            ),
                            'tables' => array(
                                'robots_parts',
                            ),
                            'columns' => array(
                                lcfirst(RobottersDeles::class) => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobottersDeles::class),
                                ),
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'robots',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robottersCode',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'code',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT r.*, p.* FROM ' . Robotters::class . ' AS r JOIN ' . RobottersDeles::class . ' AS p',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                'r' => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'r',
                                    'balias' => 'r',
                                ),
                                'p' => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'p',
                                    'balias' => 'p',
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                        'p',
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'r',
                                                'name' => 'id',
                                                'balias' => 'code',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'p',
                                                'name' => 'robots_id',
                                                'balias' => 'robottersCode',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' AS r JOIN ' . RobottersDeles::class . ' AS p',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                                lcfirst(RobottersDeles::class) => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'p',
                                    'balias' => lcfirst(RobottersDeles::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                        'p',
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'r',
                                                'name' => 'id',
                                                'balias' => 'code',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'p',
                                                'name' => 'robots_id',
                                                'balias' => 'robottersCode',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT r.* FROM ' . Robotters::class . ' r INNER JOIN ' . RobottersDeles::class,
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                'r' => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'r',
                                    'balias' => 'r',
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'r',
                                                'name' => 'id',
                                                'balias' => 'code',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robottersCode',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . RobottersDeles::class . ' JOIN ' . Robotters::class,
                        "expected" => array(
                            'models' => array(
                                RobottersDeles::class,
                            ),
                            'tables' => array(
                                'robots_parts',
                            ),
                            'columns' => array(
                                lcfirst(RobottersDeles::class) => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobottersDeles::class),
                                ),
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'robots',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robottersCode',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots',
                                                'name' => 'id',
                                                'balias' => 'code',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT r.*, p.* FROM ' . Robotters::class . ' AS r JOIN ' . RobottersDeles::class . ' AS p',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                'r' => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'r',
                                    'balias' => 'r',
                                ),
                                'p' => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'p',
                                    'balias' => 'p',
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                        'p',
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'r',
                                                'name' => 'id',
                                                'balias' => 'code',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'p',
                                                'name' => 'robots_id',
                                                'balias' => 'robottersCode',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' AS r JOIN ' . RobottersDeles::class . ' AS p',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                                lcfirst(RobottersDeles::class) => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'p',
                                    'balias' => lcfirst(RobottersDeles::class),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                        'p',
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'r',
                                                'name' => 'id',
                                                'balias' => 'code',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'p',
                                                'name' => 'robots_id',
                                                'balias' => 'robottersCode',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT r.* FROM ' . Robotters::class . ' r INNER JOIN ' . RobottersDeles::class,
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                'r' => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'r',
                                    'balias' => 'r',
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'robots_parts',
                                        null,
                                    ),
                                    'conditions' => array(
                                        array(
                                            'type' => 'binary-op',
                                            'op' => '=',
                                            'left' => array(
                                                'type' => 'qualified',
                                                'domain' => 'r',
                                                'name' => 'id',
                                                'balias' => 'code',
                                            ),
                                            'right' => array(
                                                'type' => 'qualified',
                                                'domain' => 'robots_parts',
                                                'name' => 'robots_id',
                                                'balias' => 'robottersCode',
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ( ' . Personers::class . '.kredit + 100) / (' . Products::class . '.price * 0.15) FROM ' . Personers::class . ' JOIN ' . Products::class,
                        "expected" => array(
                            'models' => array(
                                Personers::class,
                            ),
                            'tables' => array(
                                'personas',
                            ),
                            'columns' => array(
                                '_0' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'binary-op',
                                        'op' => '/',
                                        'left' => array(
                                            'type' => 'parentheses',
                                            'left' => array(
                                                'type' => 'binary-op',
                                                'op' => '+',
                                                'left' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'personas',
                                                    'name' => 'cupo',
                                                    'balias' => 'kredit',
                                                ),
                                                'right' => array(
                                                    'type' => 'literal',
                                                    'value' => '100',
                                                ),
                                            ),
                                        ),
                                        'right' => array(
                                            'type' => 'parentheses',
                                            'left' => array(
                                                'type' => 'binary-op',
                                                'op' => '*',
                                                'left' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'products',
                                                    'name' => 'price',
                                                    'balias' => 'price',
                                                ),
                                                'right' => array(
                                                    'type' => 'literal',
                                                    'value' => '0.15',
                                                ),
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'products',
                                        null,
                                    ),
                                    'conditions' => array(
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT ( ' . Personers::class . '.kredit + 100) / (' . SomeProducts::class . '.price * 0.15) AS price FROM ' . Personers::class . ' JOIN ' . SomeProducts::class,
                        "expected" => array(
                            'models' => array(
                                Personers::class,
                            ),
                            'tables' => array(
                                'personas',
                            ),
                            'columns' => array(
                                'price' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'binary-op',
                                        'op' => '/',
                                        'left' => array(
                                            'type' => 'parentheses',
                                            'left' => array(
                                                'type' => 'binary-op',
                                                'op' => '+',
                                                'left' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'personas',
                                                    'name' => 'cupo',
                                                    'balias' => 'kredit',
                                                ),
                                                'right' => array(
                                                    'type' => 'literal',
                                                    'value' => '100',
                                                ),
                                            ),
                                        ),
                                        'right' => array(
                                            'type' => 'parentheses',
                                            'left' => array(
                                                'type' => 'binary-op',
                                                'op' => '*',
                                                'left' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'le_products',
                                                    'name' => 'price',
                                                    'balias' => 'price',
                                                ),
                                                'right' => array(
                                                    'type' => 'literal',
                                                    'value' => '0.15',
                                                ),
                                            ),
                                        ),
                                    ),
                                    'balias' => 'price',
                                    'sqlAlias' => 'price',
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'le_products',
                                        null,
                                    ),
                                    'conditions' => array(
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT (p.kredit + 100) / (s.price * 0.15) AS price FROM ' . Personers::class . ' AS p JOIN ' . SomeProducts::class . ' AS s',
                        "expected" => array(
                            'models' => array(
                                Personers::class,
                            ),
                            'tables' => array(
                                array(
                                    'personas',
                                    null,
                                    'p',
                                ),
                            ),
                            'columns' => array(
                                'price' => array(
                                    'type' => 'scalar',
                                    'column' => array(
                                        'type' => 'binary-op',
                                        'op' => '/',
                                        'left' => array(
                                            'type' => 'parentheses',
                                            'left' => array(
                                                'type' => 'binary-op',
                                                'op' => '+',
                                                'left' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'p',
                                                    'name' => 'cupo',
                                                    'balias' => 'kredit',
                                                ),
                                                'right' => array(
                                                    'type' => 'literal',
                                                    'value' => '100',
                                                ),
                                            ),
                                        ),
                                        'right' => array(
                                            'type' => 'parentheses',
                                            'left' => array(
                                                'type' => 'binary-op',
                                                'op' => '*',
                                                'left' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 's',
                                                    'name' => 'price',
                                                    'balias' => 'price',
                                                ),
                                                'right' => array(
                                                    'type' => 'literal',
                                                    'value' => '0.15',
                                                ),
                                            ),
                                        ),
                                    ),
                                    'balias' => 'price',
                                    'sqlAlias' => 'price',
                                ),
                            ),
                            'joins' => array(
                                array(
                                    'type' => 'INNER',
                                    'source' => array(
                                        'le_products',
                                        null,
                                        's',
                                    ),
                                    'conditions' => array(
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ', ' . RobottersDeles::class,
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                                RobottersDeles::class,
                            ),
                            'tables' => array(
                                'robots',
                                'robots_parts',
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                                lcfirst(RobottersDeles::class) => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobottersDeles::class),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' r, ' . RobottersDeles::class . ' p',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                                RobottersDeles::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                                array(
                                    'robots_parts',
                                    null,
                                    'p',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                                lcfirst(RobottersDeles::class) => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'p',
                                    'balias' => lcfirst(RobottersDeles::class),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' AS r, ' . RobottersDeles::class . ' AS p',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                                RobottersDeles::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                                array(
                                    'robots_parts',
                                    null,
                                    'p',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                                lcfirst(RobottersDeles::class) => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'p',
                                    'balias' => lcfirst(RobottersDeles::class),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT theName, delesCode FROM ' . Robotters::class . ' AS r, ' . RobottersDeles::class . ' AS p',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                                RobottersDeles::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                                array(
                                    'robots_parts',
                                    null,
                                    'p',
                                ),
                            ),
                            'columns' => array(
                                'theName' => array(
                                    'type' => 'scalar',
                                    'balias' => 'theName',
                                    'sqlAlias' => 'theName',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'name',
                                        'balias' => 'theName',
                                    ),
                                ),
                                'delesCode' => array(
                                    'type' => 'scalar',
                                    'balias' => 'delesCode',
                                    'sqlAlias' => 'delesCode',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'p',
                                        'name' => 'parts_id',
                                        'balias' => 'delesCode',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' AS r, ' . RobottersDeles::class . ' AS p WHERE r.code = p.robottersCode',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                                RobottersDeles::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                                array(
                                    'robots_parts',
                                    null,
                                    'p',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                                lcfirst(RobottersDeles::class) => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'p',
                                    'balias' => lcfirst(RobottersDeles::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'r',
                                    'name' => 'id',
                                    'balias' => 'code',
                                ),
                                'right' => array(
                                    'type' => 'qualified',
                                    'domain' => 'p',
                                    'name' => 'robots_id',
                                    'balias' => 'robottersCode',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ', ' . RobottersDeles::class . ' WHERE ' . Robotters::class . '.code = ' . RobottersDeles::class . '.robottersCode',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                                RobottersDeles::class,
                            ),
                            'tables' => array(
                                'robots',
                                'robots_parts',
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                                lcfirst(RobottersDeles::class) => array(
                                    'type' => 'object',
                                    'model' => RobottersDeles::class,
                                    'column' => 'robots_parts',
                                    'balias' => lcfirst(RobottersDeles::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '=',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'code',
                                ),
                                'right' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots_parts',
                                    'name' => 'robots_id',
                                    'balias' => 'robottersCode',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' r WHERE NOT (r.theName = "shaggy") ORDER BY 1, r.theName',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'unary-op',
                                'op' => 'NOT ',
                                'right' => array(
                                    'type' => 'parentheses',
                                    'left' => array(
                                        'type' => 'binary-op',
                                        'op' => '=',
                                        'left' => array(
                                            'type' => 'qualified',
                                            'domain' => 'r',
                                            'name' => 'name',
                                            'balias' => 'theName',
                                        ),
                                        'right' => array(
                                            'type' => 'literal',
                                            'value' => '\'shaggy\'',
                                        ),
                                    ),
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '1',
                                    ),
                                ),
                                array(
                                    array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'name',
                                        'balias' => 'theName',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' r WHERE NOT (r.theName = "shaggy") ORDER BY 1 DESC, r.theName',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'unary-op',
                                'op' => 'NOT ',
                                'right' => array(
                                    'type' => 'parentheses',
                                    'left' => array(
                                        'type' => 'binary-op',
                                        'op' => '=',
                                        'left' => array(
                                            'type' => 'qualified',
                                            'domain' => 'r',
                                            'name' => 'name',
                                            'balias' => 'theName',
                                        ),
                                        'right' => array(
                                            'type' => 'literal',
                                            'value' => '\'shaggy\'',
                                        ),
                                    ),
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '1',
                                    ),
                                    'DESC',
                                ),
                                array(
                                    array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'name',
                                        'balias' => 'theName',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' r WHERE NOT (r.theName = "shaggy") ORDER BY 1, r.theName',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'unary-op',
                                'op' => 'NOT ',
                                'right' => array(
                                    'type' => 'parentheses',
                                    'left' => array(
                                        'type' => 'binary-op',
                                        'op' => '=',
                                        'left' => array(
                                            'type' => 'qualified',
                                            'domain' => 'r',
                                            'name' => 'name',
                                            'balias' => 'theName',
                                        ),
                                        'right' => array(
                                            'type' => 'literal',
                                            'value' => '\'shaggy\'',
                                        ),
                                    ),
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '1',
                                    ),
                                ),
                                array(
                                    array(
                                        'type' => 'qualified',
                                        'domain' => 'r',
                                        'name' => 'name',
                                        'balias' => 'theName',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' r WHERE r.theName <> "shaggy" ORDER BY 1, 2 LIMIT 5',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '<>',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'r',
                                    'name' => 'name',
                                    'balias' => 'theName',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '\'shaggy\'',
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '1',
                                    ),
                                ),
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '2',
                                    ),
                                ),
                            ),
                            'limit' => array(
                                'number' => array(
                                    'type' => 'literal',
                                    'value' => '5',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' r WHERE r.theName <> "shaggy" ORDER BY 1 ASC, 2 DESC LIMIT 5',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => '<>',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'r',
                                    'name' => 'name',
                                    'balias' => 'theName',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '\'shaggy\'',
                                ),
                            ),
                            'order' => array(
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '1',
                                    ),
                                    'ASC',
                                ),
                                array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '2',
                                    ),
                                    'DESC',
                                ),
                            ),
                            'limit' => array(
                                'number' => array(
                                    'type' => 'literal',
                                    'value' => '5',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' GROUP BY ' . Robotters::class . '.theName',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'theName',
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robotters::class . ' GROUP BY ' . Robotters::class . '.theName, ' . Robotters::class . '.code',
                        "expected" => array(
                            'models' => array(
                                Robotters::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robotters::class) => array(
                                    'type' => 'object',
                                    'model' => Robotters::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robotters::class),
                                ),
                            ),
                            'group' => array(
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'name',
                                    'balias' => 'theName',
                                ),
                                array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'code',
                                ),
                            ),
                        )
                    ],
                    [
                        // Issue 1011
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' r LIMIT ?1,:limit:',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                array(
                                    'robots',
                                    null,
                                    'r',
                                ),
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'r',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'limit' => array(
                                'number' => array(
                                    'type' => 'placeholder',
                                    'value' => ':limit',
                                ),
                                'offset' => array(
                                    'type' => 'placeholder',
                                    'value' => ':1',
                                ),
                            ),
                        )
                    ],
                    [
                        // SELECT DISTINCT
                        "phql"     => 'SELECT DISTINCT id, name FROM ' . Robots::class,
                        "expected" => array(
                            'distinct' => 1,
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                'id' => array(
                                    'type' => 'scalar',
                                    'balias' => 'id',
                                    'sqlAlias' => 'id',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'id',
                                        'balias' => 'id',
                                    ),
                                ),
                                'name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'name',
                                    'sqlAlias' => 'name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        // SELECT ALL
                        "phql"     => 'SELECT ALL id, name FROM ' . Robots::class,
                        "expected" => array(
                            'distinct' => 0,
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                'id' => array(
                                    'type' => 'scalar',
                                    'balias' => 'id',
                                    'sqlAlias' => 'id',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'id',
                                        'balias' => 'id',
                                    ),
                                ),
                                'name' => array(
                                    'type' => 'scalar',
                                    'balias' => 'name',
                                    'sqlAlias' => 'name',
                                    'column' => array(
                                        'type' => 'qualified',
                                        'domain' => 'robots',
                                        'name' => 'name',
                                        'balias' => 'name',
                                    ),
                                ),
                            ),
                        )
                    ],
                    [
                        "phql"     => 'SELECT * FROM ' . Robots::class . ' WHERE id IN (SELECT robots_id FROM ' . RobotsParts::class . ')',
                        "expected" => array(
                            'models' => array(
                                Robots::class,
                            ),
                            'tables' => array(
                                'robots',
                            ),
                            'columns' => array(
                                lcfirst(Robots::class) => array(
                                    'type' => 'object',
                                    'model' => Robots::class,
                                    'column' => 'robots',
                                    'balias' => lcfirst(Robots::class),
                                ),
                            ),
                            'where' => array(
                                'type' => 'binary-op',
                                'op' => 'IN',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                                'right' => array(
                                    'type' => 'select',
                                    'value' => array(
                                        'models' => array(
                                            RobotsParts::class,
                                        ),
                                        'tables' => array(
                                            'robots_parts',
                                        ),
                                        'columns' => array(
                                            'robots_id' => array(
                                                'type' => 'scalar',
                                                'balias' => 'robots_id',
                                                'sqlAlias' => 'robots_id',
                                                'sqlAlias' => 'robots_id',
                                                'column' => array(
                                                    'type' => 'qualified',
                                                    'domain' => 'robots_parts',
                                                    'name' => 'robots_id',
                                                    'balias' => 'robots_id',
                                                ),
                                            ),
                                        ),
                                    ),
                                ),
                            ),
                        )
                    ]
                ]
            ]
        );
    }

    public function testInsertParsing()
    {
        $this->specify(
            "INSERT PHQL queries don't work as expected",
            function () {
                $expected = array(
                    'model' => Robots::class,
                    'table' => 'robots',
                    'values' => array(
                        array(
                            'type' => 322,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'NULL',
                            ),
                        ),
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some robot',
                            ),
                        ),
                        array(
                            'type' => 258,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '1945',
                            ),
                        ),
                    ),
                );
                $query = new Query('INSERT INTO ' . Robots::class . ' VALUES (NULL, \'some robot\', 1945)');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'model' => strtolower(Robots::class),
                    'table' => 'robots',
                    'values' => array(
                        array(
                            'type' => 322,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'NULL',
                            ),
                        ),
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some robot',
                            ),
                        ),
                        array(
                            'type' => 258,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '1945',
                            ),
                        ),
                    ),
                );
                $query = new Query('insert into ' . strtolower(Robots::class) . ' values (null, \'some robot\', 1945)');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'model' => SomeProducts::class,
                    'table' => 'le_products',
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'Some name',
                            ),
                        ),
                        array(
                            'type' => 259,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '100.15',
                            ),
                        ),
                        array(
                            'type' => 350,
                            'value' => array(
                                'type' => 'functionCall',
                                'name' => 'current_date',
                            ),
                        ),
                        array(
                            'type' => 350,
                            'value' => array(
                                'type' => 'functionCall',
                                'name' => 'now',
                            ),
                        ),
                    ),
                );
                $query = new Query('INSERT INTO ' . SomeProducts::class . ' VALUES ("Some name", 100.15, current_date(), now())');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'model' => Robots::class,
                    'table' => 'robots',
                    'values' => array(
                        array(
                            'type' => 356,
                            'value' => array(
                                'type' => 'parentheses',
                                'left' => array(
                                    'type' => 'binary-op',
                                    'op' => '*',
                                    'left' => array(
                                        'type' => 'binary-op',
                                        'op' => '+',
                                        'left' => array(
                                            'type' => 'literal',
                                            'value' => '1',
                                        ),
                                        'right' => array(
                                            'type' => 'literal',
                                            'value' => '1000',
                                        ),
                                    ),
                                    'right' => array(
                                        'type' => 'placeholder',
                                        'value' => ':le_id',
                                    ),
                                ),
                            ),
                        ),
                        array(
                            'type' => 350,
                            'value' => array(
                                'type' => 'functionCall',
                                'name' => 'CONCAT',
                                'arguments' => array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '\'some\'',
                                    ),
                                    array(
                                        'type' => 'literal',
                                        'value' => '\'robot\'',
                                    ),
                                ),
                            ),
                        ),
                        array(
                            'type' => 258,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '2011',
                            ),
                        ),
                    ),
                );
                $query = new Query('INSERT INTO ' . Robots::class . ' VALUES ((1+1000*:le_id:), CONCAT(\'some\', \'robot\'), 2011)');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'model' => Robots::class,
                    'table' => 'robots',
                    'fields' => array(
                        'name',
                        'type',
                        'year',
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'a name',
                            ),
                        ),
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'virtual',
                            ),
                        ),
                        array(
                            'type' => 273,
                            'value' => array(
                                'type' => 'placeholder',
                                'value' => ':0',
                            ),
                        ),
                    ),
                );
                $query = new Query('INSERT INTO ' . Robots::class . ' (name, type, year) VALUES (\'a name\', \'virtual\', ?0)');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'model' => Robotters::class,
                    'table' => 'robots',
                    'values' => array(
                        array(
                            'type' => 322,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'NULL',
                            ),
                        ),
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some robot',
                            ),
                        ),
                        array(
                            'type' => 258,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '1945',
                            ),
                        ),
                    ),
                );
                $query = new Query('INSERT INTO ' . Robotters::class . ' VALUES (NULL, \'some robot\', 1945)');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'model' => strtolower(Robotters::class),
                    'table' => 'robots',
                    'values' => array(
                        array(
                            'type' => 322,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'NULL',
                            ),
                        ),
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some robot',
                            ),
                        ),
                        array(
                            'type' => 258,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '1945',
                            ),
                        ),
                    ),
                );
                $query = new Query('insert into ' . strtolower(Robotters::class) . ' values (null, \'some robot\', 1945)');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'model' => Robotters::class,
                    'table' => 'robots',
                    'values' => array(
                        array(
                            'type' => 356,
                            'value' => array(
                                'type' => 'parentheses',
                                'left' => array(
                                    'type' => 'binary-op',
                                    'op' => '*',
                                    'left' => array(
                                        'type' => 'binary-op',
                                        'op' => '+',
                                        'left' => array(
                                            'type' => 'literal',
                                            'value' => '1',
                                        ),
                                        'right' => array(
                                            'type' => 'literal',
                                            'value' => '1000',
                                        ),
                                    ),
                                    'right' => array(
                                        'type' => 'placeholder',
                                        'value' => ':le_id',
                                    ),
                                ),
                            ),
                        ),
                        array(
                            'type' => 350,
                            'value' => array(
                                'type' => 'functionCall',
                                'name' => 'CONCAT',
                                'arguments' => array(
                                    array(
                                        'type' => 'literal',
                                        'value' => '\'some\'',
                                    ),
                                    array(
                                        'type' => 'literal',
                                        'value' => '\'robot\'',
                                    ),
                                ),
                            ),
                        ),
                        array(
                            'type' => 258,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '2011',
                            ),
                        ),
                    ),
                );
                $query = new Query('INSERT INTO ' . Robotters::class . ' VALUES ((1+1000*:le_id:), CONCAT(\'some\', \'robot\'), 2011)');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'model' => Robotters::class,
                    'table' => 'robots',
                    'fields' => array(
                        'theName',
                        'theType',
                        'theYear',
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'a name',
                            ),
                        ),
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'virtual',
                            ),
                        ),
                        array(
                            'type' => 273,
                            'value' => array(
                                'type' => 'placeholder',
                                'value' => ':0',
                            ),
                        ),
                    ),
                );
                $query = new Query('INSERT INTO ' . Robotters::class . ' (theName, theType, theYear) VALUES (\'a name\', \'virtual\', ?0)');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);
            }
        );
    }

    public function testUpdateParsing()
    {
        $this->specify(
            "UPDATE PHQL queries don't work as expected",
            function () {
                $expected = array(
                    'tables' => array(
                        'robots',
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' SET name = \'some name\'');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        'robots',
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' SET ' . Robots::class . '.name = \'some name\'');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        'le_products',
                    ),
                    'models' => array(
                        SomeProducts::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'le_products',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . SomeProducts::class . ' SET ' . SomeProducts::class . '.name = "some name"');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'le_products',
                            null,
                            'p',
                        ),
                    ),
                    'models' => array(
                        SomeProducts::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'p',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . SomeProducts::class . ' p SET p.name = "some name"');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        'robots',
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                        array(
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'year',
                            'balias' => 'year',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                        array(
                            'type' => 258,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '1990',
                            ),
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' SET ' . Robots::class . '.name = \'some name\', ' . Robots::class . '.year = 1990');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'le_products',
                            null,
                            'p',
                        ),
                    ),
                    'models' => array(
                        SomeProducts::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'p',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                        array(
                            'type' => 'qualified',
                            'domain' => 'p',
                            'name' => 'year',
                            'balias' => 'year',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                        array(
                            'type' => 258,
                            'value' => array(
                                'type' => 'literal',
                                'value' => '1990',
                            ),
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . SomeProducts::class . ' p SET p.name = "some name", p.year = 1990');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        'robots',
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                        array(
                            'type' => 'qualified',
                            'domain' => 'robots',
                            'name' => 'year',
                            'balias' => 'year',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                        array(
                            'type' => 43,
                            'value' => array(
                                'type' => 'binary-op',
                                'op' => '+',
                                'left' => array(
                                    'type' => 'functionCall',
                                    'name' => 'YEAR',
                                    'arguments' => array(
                                        array(
                                            'type' => 'functionCall',
                                            'name' => 'current_date',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'qualified',
                                    'domain' => 'robots',
                                    'name' => 'year',
                                    'balias' => 'year',
                                ),
                            ),
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' SET ' . Robots::class . '.name = \'some name\', ' . Robots::class . '.year = YEAR(current_date()) + ' . Robots::class . '.year');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'year',
                            'balias' => 'year',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                        array(
                            'type' => 43,
                            'value' => array(
                                'type' => 'binary-op',
                                'op' => '+',
                                'left' => array(
                                    'type' => 'functionCall',
                                    'name' => 'YEAR',
                                    'arguments' => array(
                                        array(
                                            'type' => 'functionCall',
                                            'name' => 'current_date',
                                        ),
                                    ),
                                ),
                                'right' => array(
                                    'type' => 'qualified',
                                    'domain' => 'r',
                                    'name' => 'year',
                                    'balias' => 'year',
                                ),
                            ),
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' AS r SET r.name = \'some name\', r.year = YEAR(current_date()) + r.year');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                    'where' => array(
                        'type' => 'binary-op',
                        'op' => '>',
                        'left' => array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'id',
                            'balias' => 'id',
                        ),
                        'right' => array(
                            'type' => 'literal',
                            'value' => '100',
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' AS r SET r.name = \'some name\' WHERE r.id > 100');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'year',
                            'balias' => 'year',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                        array(
                            'type' => 42,
                            'value' => array(
                                'type' => 'binary-op',
                                'op' => '*',
                                'left' => array(
                                    'type' => 'qualified',
                                    'domain' => 'r',
                                    'name' => 'year',
                                    'balias' => 'year',
                                ),
                                'right' => array(
                                    'type' => 'literal',
                                    'value' => '2',
                                ),
                            ),
                        ),
                    ),
                    'where' => array(
                        'type' => 'binary-op',
                        'op' => '<=',
                        'left' => array(
                            'type' => 'binary-op',
                            'op' => '>',
                            'left' => array(
                                'type' => 'qualified',
                                'domain' => 'r',
                                'name' => 'id',
                                'balias' => 'id',
                            ),
                            'right' => array(
                                'type' => 'binary-op',
                                'op' => 'AND',
                                'left' => array(
                                    'type' => 'literal',
                                    'value' => '100',
                                ),
                                'right' => array(
                                    'type' => 'qualified',
                                    'domain' => 'r',
                                    'name' => 'id',
                                    'balias' => 'id',
                                ),
                            ),
                        ),
                        'right' => array(
                            'type' => 'literal',
                            'value' => '200',
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' as r set r.name = \'some name\', r.year = r.year*2 where r.id > 100 and r.id <= 200');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        strtolower(Robots::class),
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                    'limit' => array(
                        'number' => array(
                            'type' => 'literal',
                            'value' => '10',
                        ),
                    ),
                );
                $query = new Query('update ' . strtolower(Robots::class) . ' as r set r.name = \'some name\' LIMIT 10');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                    'limit' => array(
                        'number' => array(
                            'type' => 'literal',
                            'value' => '10',
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' r SET r.name = \'some name\' LIMIT 10');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                    'where' => array(
                        'type' => 'binary-op',
                        'op' => '>',
                        'left' => array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'id',
                            'balias' => 'id',
                        ),
                        'right' => array(
                            'type' => 'literal',
                            'value' => '100',
                        ),
                    ),
                    'limit' => array(
                        'number' => array(
                            'type' => 'literal',
                            'value' => '10',
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' AS r SET r.name = \'some name\' WHERE r.id > 100 LIMIT 10');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                // Issue 1011
                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'fields' => array(
                        array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'name',
                            'balias' => 'name',
                        ),
                    ),
                    'values' => array(
                        array(
                            'type' => 260,
                            'value' => array(
                                'type' => 'literal',
                                'value' => 'some name',
                            ),
                        ),
                    ),
                    'limit' => array(
                        'number' => array(
                            'type' => 'placeholder',
                            'value' => ':1',
                        ),
                    ),
                );
                $query = new Query('UPDATE ' . Robots::class . ' r SET r.name = \'some name\' LIMIT ?1');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);
            }
        );
    }

    public function testDeleteParsing()
    {
        $this->specify(
            "DELETE PHQL queries don't work as expected",
            function () {
                $expected = array(
                    'tables' => array(
                        'robots',
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                );
                $query = new Query('DELETE FROM ' . Robots::class);
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'where' => array(
                        'type' => 'binary-op',
                        'op' => '>',
                        'left' => array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'id',
                            'balias' => 'id',
                        ),
                        'right' => array(
                            'type' => 'literal',
                            'value' => '100',
                        ),
                    ),
                );
                $query = new Query('DELETE FROM ' . Robots::class . ' AS r WHERE r.id > 100');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'where' => array(
                        'type' => 'binary-op',
                        'op' => '>',
                        'left' => array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'id',
                            'balias' => 'id',
                        ),
                        'right' => array(
                            'type' => 'literal',
                            'value' => '100',
                        ),
                    ),
                );
                $query = new Query('DELETE FROM ' . Robots::class . ' r WHERE r.id > 100');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'where' => array(
                        'type' => 'binary-op',
                        'op' => '>',
                        'left' => array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'id',
                            'balias' => 'id',
                        ),
                        'right' => array(
                            'type' => 'literal',
                            'value' => '100',
                        ),
                    ),
                );
                $query = new Query('DELETE FROM ' . Robots::class . ' as r WHERE r.id > 100');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'limit' => array(
                        'number' => array(
                            'type' => 'literal',
                            'value' => '10',
                        ),
                    ),
                );
                $query = new Query('DELETE FROM ' . Robots::class . ' r LIMIT 10');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'where' => array(
                        'type' => 'binary-op',
                        'op' => '>',
                        'left' => array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'id',
                            'balias' => 'id',
                        ),
                        'right' => array(
                            'type' => 'literal',
                            'value' => '100',
                        ),
                    ),
                    'limit' => array(
                        'number' => array(
                            'type' => 'literal',
                            'value' => '10',
                        ),
                    ),
                );
                $query = new Query('DELETE FROM ' . Robots::class . ' r WHERE r.id > 100 LIMIT 10');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);

                // Issue 1011
                $expected = array(
                    'tables' => array(
                        array(
                            'robots',
                            null,
                            'r',
                        ),
                    ),
                    'models' => array(
                        Robots::class,
                    ),
                    'where' => array(
                        'type' => 'binary-op',
                        'op' => '>',
                        'left' => array(
                            'type' => 'qualified',
                            'domain' => 'r',
                            'name' => 'id',
                            'balias' => 'id',
                        ),
                        'right' => array(
                            'type' => 'literal',
                            'value' => '100',
                        ),
                    ),
                    'limit' => array(
                        'number' => array(
                            'type' => 'placeholder',
                            'value' => ':limit',
                        ),
                    ),
                );
                $query = new Query('DELETE FROM ' . Robots::class . ' r WHERE r.id > 100 LIMIT :limit:');
                $query->setDI($this->di);
                expect($query->parse())->equals($expected);
            }
        );
    }
}
