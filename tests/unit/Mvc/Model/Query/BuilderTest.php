<?php

namespace Phalcon\Test\Unit\Mvc\Model\Query;

use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\RobotsParts;
use Phalcon\Test\Models\Parts;

/**
 * \Phalcon\Test\Unit\Mvc\Model\Query\BuilderTest
 * Tests the Phalcon\Mvc\Model\Query\Builder component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc\Model
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class BuilderTest extends UnitTest
{
    /**
     * @var \Phalcon\DiInterface
     */
    private $di;

    protected function _before()
    {
        parent::_before();

        /** @var \Phalcon\Mvc\Application $app */
        $app = $this->tester->getApplication();

        $this->di = $app->getDI();
    }

    /**
     * Tests merge bind types for Builder::where
     *
     * @test
     * @issue https://github.com/phalcon/cphalcon/issues/11487
     */
    public function shouldMergeBinTypesForWhere()
    {
        $this->specify(
            'Query builder does not merge bind types as expected.',
            function () {
                $builder = new Builder();
                $builder->setDi($this->di);

                $builder
                    ->from(Robots::class)
                    ->where(
                        'id = :id:',
                        [':id:' => 3],
                        [':id:' => \PDO::PARAM_INT]
                    );

                $builder->where(
                    'name = :name:',
                    [':name:' => 'Terminator'],
                    [':name:' => \PDO::PARAM_STR]
                );

                $actual = $builder->getQuery()->getBindTypes();
                $expected = [':id:' => 1, ':name:' => 2];

                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests merge bind types for Builder::having
     *
     * @test
     * @issue https://github.com/phalcon/cphalcon/issues/11487
     */
    public function shouldMergeBinTypesForHaving()
    {
        $this->specify(
            'Query builder does not merge bind types as expected.',
            function () {
                $builder = new Builder();
                $builder->setDi($this->di);

                $builder
                    ->from(Robots::class)
                    ->columns(
                        [
                            'COUNT(id)',
                            'name'
                        ]
                    )
                    ->groupBy('COUNT(id)')
                    ->having(
                        'COUNT(id) > :cnt:',
                        [':cnt:' => 5],
                        [':cnt:' => \PDO::PARAM_INT]
                    );

                $builder->having(
                    "CONCAT('is_', type) = :type:",
                    [':type:' => 'mechanical'],
                    [':type:' => \PDO::PARAM_STR]
                );

                $actual = $builder->getQuery()->getBindTypes();
                $expected = [':cnt:' => 1, ':type:' => 2];

                expect($actual)->equals($expected);
            }
        );
    }

    public function testAction()
    {
        $this->specify(
            "Query Builders don't build the expected queries",
            function () {
                $di = $this->di;

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(Robots::class)
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from([Robots::class, RobotsParts::class])
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].*, [" . RobotsParts::class . "].* FROM [" . Robots::class . "], [" . RobotsParts::class . "]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns("*")
                                ->from(Robots::class)
                                ->getPhql();
                expect($phql)->equals("SELECT * FROM [" . Robots::class . "]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns(["id", "name"])
                                ->from(Robots::class)
                                ->getPhql();
                expect($phql)->equals("SELECT id, name FROM [" . Robots::class . "]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns("id")
                                ->from(Robots::class)
                                ->getPhql();
                expect($phql)->equals("SELECT id FROM [" . Robots::class . "]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(Robots::class)
                                ->where("Robots.name = 'Voltron'")
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] WHERE Robots.name = 'Voltron'");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(Robots::class)
                                ->where("Robots.name = 'Voltron'")
                                ->andWhere("Robots.id > 100")
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] WHERE (Robots.name = 'Voltron') AND (Robots.id > 100)");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(Robots::class)
                                ->where("Robots.name = 'Voltron'")
                                ->orWhere("Robots.id > 100")
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] WHERE (Robots.name = 'Voltron') OR (Robots.id > 100)");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(Robots::class)
                                ->where(100)
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] WHERE [" . Robots::class . "].[id] = 100");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(Robots::class)
                                ->groupBy("Robots.name")
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] GROUP BY Robots.name");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(Robots::class)
                                ->groupBy(["Robots.name", "Robots.id"])
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] GROUP BY Robots.name, Robots.id");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns(["Robots.name", "SUM(Robots.price)"])
                                ->from(Robots::class)
                                ->groupBy("Robots.name")
                                ->getPhql();
                expect($phql)->equals("SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns(["Robots.name", "SUM(Robots.price)"])
                                ->from(Robots::class)
                                ->groupBy("Robots.name")
                                ->having("SUM(Robots.price) > 1000")
                                ->getPhql();
                expect($phql)->equals("SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING SUM(Robots.price) > 1000");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns(["Robots.name", "SUM(Robots.price)"])
                                ->from(Robots::class)
                                ->groupBy("Robots.name")
                                ->having("SUM(Robots.price) > 1000")
                                ->andHaving("SUM(Robots.price) < 2000")
                                ->getPhql();
                expect($phql)->equals("SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING (SUM(Robots.price) > 1000) AND (SUM(Robots.price) < 2000)");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns(["Robots.name", "SUM(Robots.price)"])
                                ->from(Robots::class)
                                ->groupBy("Robots.name")
                                ->having("SUM(Robots.price) > 1000")
                                ->orHaving("SUM(Robots.price) < 500")
                                ->getPhql();
                expect($phql)->equals("SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING (SUM(Robots.price) > 1000) OR (SUM(Robots.price) < 500)");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns(["Robots.name", "SUM(Robots.price)"])
                                ->from(Robots::class)
                                ->groupBy("Robots.name")
                                ->inHaving("SUM(Robots.price)", [1, 2, 3])
                                ->getPhql();
                expect($phql)->equals("SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING SUM(Robots.price) IN (:AP0:, :AP1:, :AP2:)");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns(["Robots.name", "SUM(Robots.price)"])
                                ->from(Robots::class)
                                ->groupBy("Robots.name")
                                ->notInHaving("SUM(Robots.price)", [1, 2, 3])
                                ->getPhql();
                expect($phql)->equals("SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING SUM(Robots.price) NOT IN (:AP0:, :AP1:, :AP2:)");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns(["Robots.name", "SUM(Robots.price)"])
                                ->from(Robots::class)
                                ->groupBy("Robots.name")
                                ->having("SUM(Robots.price) > 100")
                                ->inHaving("SUM(Robots.price)", [1, 2, 3], Builder::OPERATOR_OR)
                                ->getPhql();
                expect($phql)->equals("SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING (SUM(Robots.price) > 100) OR (SUM(Robots.price) IN (:AP0:, :AP1:, :AP2:))");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns(["Robots.name", "SUM(Robots.price)"])
                                ->from(Robots::class)
                                ->groupBy("Robots.name")
                                ->having("SUM(Robots.price) > 100")
                                ->notInHaving("SUM(Robots.price)", [1, 2, 3], Builder::OPERATOR_OR)
                                ->getPhql();
                expect($phql)->equals("SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING (SUM(Robots.price) > 100) OR (SUM(Robots.price) NOT IN (:AP0:, :AP1:, :AP2:))");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns(["Robots.name", "SUM(Robots.price)"])
                                ->from(Robots::class)
                                ->groupBy("Robots.name")
                                ->betweenHaving("SUM(Robots.price)", 100, 200)
                                ->getPhql();
                expect($phql)->equals("SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING SUM(Robots.price) BETWEEN :AP0: AND :AP1:");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns(["Robots.name", "SUM(Robots.price)"])
                                ->from(Robots::class)
                                ->groupBy("Robots.name")
                                ->notBetweenHaving("SUM(Robots.price)", 100, 200)
                                ->getPhql();
                expect($phql)->equals("SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING SUM(Robots.price) NOT BETWEEN :AP0: AND :AP1:");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(Robots::class)
                                ->join(RobotsParts::class)
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] JOIN [" . RobotsParts::class . "]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(Robots::class)
                                ->join(RobotsParts::class, null, "p")
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] JOIN [" . RobotsParts::class . "] AS [p]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(Robots::class)
                                ->join(RobotsParts::class, "Robots.id = RobotsParts.robots_id", "p")
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] JOIN [" . RobotsParts::class . "] AS [p] ON Robots.id = RobotsParts.robots_id");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(Robots::class)
                                ->join(RobotsParts::class, "Robots.id = RobotsParts.robots_id", "p")
                                ->join(Parts::class, "Parts.id = RobotsParts.parts_id", "t")
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] JOIN [" . RobotsParts::class . "] AS [p] ON Robots.id = RobotsParts.robots_id JOIN [" . Parts::class . "] AS [t] ON Parts.id = RobotsParts.parts_id");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(Robots::class)
                                ->leftJoin(RobotsParts::class, "Robots.id = RobotsParts.robots_id")
                                ->leftJoin(Parts::class, "Parts.id = RobotsParts.parts_id")
                                ->where("Robots.id > 0")
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] LEFT JOIN [" . RobotsParts::class . "] ON Robots.id = RobotsParts.robots_id LEFT JOIN [" . Parts::class . "] ON Parts.id = RobotsParts.parts_id WHERE Robots.id > 0");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->addFrom(Robots::class, "r")
                                ->getPhql();
                expect($phql)->equals("SELECT [r].* FROM [" . Robots::class . "] AS [r]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(Robots::class)
                                ->addFrom(Parts::class, "p")
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].*, [p].* FROM [" . Robots::class . "], [" . Parts::class . "] AS [p]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(["r" => Robots::class])
                                ->addFrom(Parts::class, "p")
                                ->getPhql();
                expect($phql)->equals("SELECT [r].*, [p].* FROM [" . Robots::class . "] AS [r], [" . Parts::class . "] AS [p]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(["r" => Robots::class, "p" => Parts::class])
                                ->getPhql();
                expect($phql)->equals("SELECT [r].*, [p].* FROM [" . Robots::class . "] AS [r], [" . Parts::class . "] AS [p]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(Robots::class)
                                ->orderBy("Robots.name")
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] ORDER BY Robots.name");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(Robots::class)
                                ->orderBy([1, "Robots.name"])
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] ORDER BY 1, Robots.name");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(Robots::class)
                                ->limit(10)
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] LIMIT :APL0:");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(Robots::class)
                                ->limit(10, 5)
                                ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] LIMIT :APL0: OFFSET :APL1:");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                    ->from(Robots::class)
                    ->where("Robots.name = 'Voltron'")
                    ->betweenWhere("Robots.id", 0, 50)
                    ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] WHERE (Robots.name = 'Voltron') AND (Robots.id BETWEEN :AP0: AND :AP1:)");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                    ->from(Robots::class)
                    ->where("Robots.name = 'Voltron'")
                    ->inWhere("Robots.id", [1, 2, 3])
                    ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] WHERE (Robots.name = 'Voltron') AND (Robots.id IN (:AP0:, :AP1:, :AP2:))");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                    ->from(Robots::class)
                    ->where("Robots.name = 'Voltron'")
                    ->betweenWhere("Robots.id", 0, 50, Builder::OPERATOR_OR)
                    ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] WHERE (Robots.name = 'Voltron') OR (Robots.id BETWEEN :AP0: AND :AP1:)");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                    ->from(Robots::class)
                    ->where("Robots.name = 'Voltron'")
                    ->inWhere("Robots.id", [1, 2, 3], Builder::OPERATOR_OR)
                    ->getPhql();
                expect($phql)->equals("SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] WHERE (Robots.name = 'Voltron') OR (Robots.id IN (:AP0:, :AP1:, :AP2:))");
            }
        );
    }

    public function testIssue701()
    {
        $this->specify(
            "Query Builders don't work with mixed integer and string placeholders",
            function () {
                $di = $this->di;

                $builder = new Builder();
                $phql = $builder->setDi($di)
                    ->from(Robots::class)
                    ->leftJoin(RobotsParts::class, "Robots.id = RobotsParts.robots_id")
                    ->leftJoin(Parts::class, "Parts.id = RobotsParts.parts_id")
                    ->where("Robots.id > :1: AND Robots.id < :2:", [1 => 0, 2 => 1000]);

                $params = $phql->getQuery()->getBindParams();
                expect($params[1])->equals(0);
                expect($params[2])->equals(1000);

                $phql->andWhere(
                    "Robots.name = :name:",
                    [
                        "name" => "Voltron",
                    ]
                );

                $params = $phql->getQuery()->getBindParams();
                expect($params[1])->equals(0);
                expect($params[2])->equals(1000);
                expect($params["name"])->equals("Voltron");
            }
        );
    }

    public function testIssue1115()
    {
        $this->specify(
            "Query Builders don't work with a HAVING statement",
            function () {
                $di = $this->di;

                $builder = new Builder();

                $phql = $builder->setDi($di)
                    ->columns(["Robots.name"])
                    ->from(Robots::class)
                    ->having("Robots.price > 1000")
                    ->getPhql();

                expect($phql)->equals("SELECT Robots.name FROM [" . Robots::class . "] HAVING Robots.price > 1000");
            }
        );
    }

    public function testSelectDistinctAll()
    {
        $this->specify(
            "Query Builders don't work with SELECT ALL / SELECT DISTINCT statements",
            function () {
                $di = $this->di;

                $builder = new Builder();
                $phql = $builder->setDi($di)
                    ->distinct(true)
                    ->columns(["Robots.name"])
                    ->from(Robots::class)
                    ->getPhql();
                expect($phql)->equals("SELECT DISTINCT Robots.name FROM [" . Robots::class . "]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                    ->distinct(false)
                    ->columns(["Robots.name"])
                    ->from(Robots::class)
                    ->getPhql();
                expect($phql)->equals("SELECT ALL Robots.name FROM [" . Robots::class . "]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                    ->distinct(true)
                    ->distinct(null)
                    ->columns(["Robots.name"])
                    ->from(Robots::class)
                    ->getPhql();
                expect($phql)->equals("SELECT Robots.name FROM [" . Robots::class . "]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                    ->distinct(true)
                    ->from(Robots::class)
                    ->getPhql();
                expect($phql)->equals("SELECT DISTINCT [" . Robots::class . "].* FROM [" . Robots::class . "]");
            }
        );
    }

    /**
     * Test checks passing query params and dependency injector into
     * constructor
     */
    public function testConstructor()
    {
        $this->specify(
            "Query Builders don't work with params in the constructor",
            function () {
                $di = $this->di;

                $params = [
                    "models"     => Robots::class,
                    "columns"    => ["id", "name", "status"],
                    "conditions" => "a > 5",
                    "group"      => ["type", "source"],
                    "having"     => "b < 5",
                    "order"      => ["name", "created"],
                    "limit"      => 10,
                    "offset"     => 15,
                ];

                $builder = new Builder($params, $di);

                $expectedPhql = "SELECT id, name, status FROM [" . Robots::class . "] "
                    . "WHERE a > 5 GROUP BY [type], [source] "
                    . "HAVING b < 5 ORDER BY [name], [created] "
                    . "LIMIT :APL0: OFFSET :APL1:";

                expect($expectedPhql)->equals($builder->getPhql());
                expect($di)->equals($builder->getDI());
            }
        );
    }

    /**
     * Test checks passing 'limit'/'offset' query param into constructor.
     * limit key can take:
     * - single numeric value
     * - array of 2 values (limit, offset)
     */
    public function testConstructorLimit()
    {
        $this->specify(
            "Query Builders don't work with separate limit and offset in the constructor params",
            function () {
                // separate limit and offset

                $params = [
                    "models" => Robots::class,
                    "limit"  => 10,
                    "offset" => 15,
                ];

                $builderLimitAndOffset = new Builder($params);

                // separate limit with offset

                $params = [
                    "models" => Robots::class,
                    "limit"  => [10, 15],
                ];

                $builderLimitWithOffset = new Builder($params);

                $expectedPhql = "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] LIMIT :APL0: OFFSET :APL1:";

                expect($builderLimitAndOffset->getPhql())->equals($expectedPhql);
                expect($builderLimitWithOffset->getPhql())->equals($expectedPhql);
            }
        );
    }

    /**
     * Test checks passing 'condition' query param into constructor.
     * Conditions can now be passed as an string(as before) and
     * as an array of 3 elements:
     * - condition string for example "age > :age: AND created > :created:"
     * - bind params for example array('age' => 18, 'created' => '2013-09-01')
     * - bind types for example array('age' => PDO::PARAM_INT, 'created' => PDO::PARAM_STR)
     *
     * First two params are REQUIRED, bind types are optional.
     */
    public function testConstructorConditions()
    {
        $this->specify(
            "Query Builders don't work with conditions specified in the constructor params",
            function () {
                // ------------- test for setters(classic) way ----------------

                $standardBuilder = new Builder();
                $standardBuilder->from(Robots::class)
                    ->where(
                        "year > :min: AND year < :max:",
                        ["min" => "2013-01-01",    "max" => "2100-01-01"],
                        ["min" => \PDO::PARAM_STR, "max" => \PDO::PARAM_STR]
                    );

                $standardResult = $standardBuilder->getQuery()->execute();

                // --------------- test for single condition ------------------
                $params = [
                    "models"     => Robots::class,
                    "conditions" => [
                        [
                            "year > :min: AND year < :max:",
                            ["min" => "2013-01-01",    "max" => "2100-01-01"],
                            ["min" => \PDO::PARAM_STR, "max" => \PDO::PARAM_STR],
                        ],
                    ],
                ];

                $builderWithSingleCondition = new Builder($params);
                $singleConditionResult      = $builderWithSingleCondition->getQuery()->execute();

                // ------------- test for multiple conditions ----------------

                $params = [
                    "models"     => Robots::class,
                    "conditions" => [
                        [
                            "year > :min:",
                            ["min" => "2000-01-01"],
                            ["min" => \PDO::PARAM_STR],
                        ],
                        [
                            "year < :max:",
                            ["max" => "2100-01-01"],
                            ["max" => \PDO::PARAM_STR],
                        ],
                    ],
                ];

                // conditions are merged!
                $builderMultipleConditions = new Builder($params);
                $multipleConditionResult   = $builderMultipleConditions->getQuery()->execute();

                $expectedPhql = "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] WHERE year > :min: AND year < :max:";

                /* ------------ ASSERTING --------- */

                expect($standardBuilder->getPhql())->equals($expectedPhql);
                expect($standardResult)->isInstanceOf("Phalcon\\Mvc\\Model\\Resultset\\Simple");

                expect($builderWithSingleCondition->getPhql())->equals($expectedPhql);
                expect($singleConditionResult)->isInstanceOf("Phalcon\\Mvc\\Model\\Resultset\\Simple");

                expect($builderMultipleConditions->getPhql())->equals($expectedPhql);
                expect($multipleConditionResult)->isInstanceOf("Phalcon\\Mvc\\Model\\Resultset\\Simple");
            }
        );
    }

    public function testGroup()
    {
        $this->specify(
            "Query Builders don't work with a GROUP BY statement",
            function () {
                $di = $this->di;

                $builder = new Builder();

                $phql = $builder->setDi($di)
                        ->columns(["name", "SUM(price)"])
                        ->from(Robots::class)
                        ->groupBy("id, name")
                        ->getPhql();

                expect($phql)->equals("SELECT name, SUM(price) FROM [" . Robots::class . "] GROUP BY [id], [name]");
            }
        );
    }

    /**
     * Tests work with limit / offset
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12419
     * @author Serghei Iakovelv <serghei@phalconphp.com>
     * @since  2016-12-18
     */
    public function shouldCorrectHandleLimitAndOffset()
    {
        $this->specify(
            'The builder object works with limit / offset incorrectly',
            function ($limit, $offset, $expected) {
                $builder = new Builder(null, $this->di);
                $phql = $builder
                    ->columns(['name'])
                    ->from(Robots::class)
                    ->limit($limit, $offset)
                    ->getPhql();

                /** Just prevent IDE to highlight this as not valid SQL dialect */
                expect($phql)->equals('SELECT name ' . "FROM {$expected}");
            },
            ['examples' => $this->limitOffsetProvider()]
        );
    }

    protected function limitOffsetProvider()
    {
        return [
            [-7,      null,  "[" . Robots::class . "] LIMIT :APL0:"              ],
            ["-7234", null,  "[" . Robots::class . "] LIMIT :APL0:"              ],
            ["18",    null,  "[" . Robots::class . "] LIMIT :APL0:"              ],
            ["18",    2,     "[" . Robots::class . "] LIMIT :APL0: OFFSET :APL1:"],
            ["-1000", -200,  "[" . Robots::class . "] LIMIT :APL0: OFFSET :APL1:"],
            ["1000", "-200", "[" . Robots::class . "] LIMIT :APL0: OFFSET :APL1:"],
            ["0",    "-200", "[" . Robots::class . "]"                           ],
            ["%3CMETA%20HTTP-EQUIV%3D%22refresh%22%20CONT ENT%3D%220%3Burl%3Djavascript%3Aqss%3D7%22%3E", 50, "[" . Robots::class . "]"],
        ];
    }
}
