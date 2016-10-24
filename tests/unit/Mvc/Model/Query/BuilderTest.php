<?php

namespace Phalcon\Test\Unit\Mvc\Model\Query;

use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Mvc\Model\Query\BuilderTest
 * Tests the Phalcon\Mvc\Model\Query\Builder component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc\Model
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
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



    public function testAction()
    {
        $this->specify(
            "Query Builders don't build the expect queries",
            function () {
                $di = $this->di;

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from("Robots")
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(["Robots", "RobotsParts"])
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].*, [RobotsParts].* FROM [Robots], [RobotsParts]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns("*")
                                ->from("Robots")
                                ->getPhql();
                expect($phql)->equals("SELECT * FROM [Robots]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns(["id", "name"])
                                ->from("Robots")
                                ->getPhql();
                expect($phql)->equals("SELECT id, name FROM [Robots]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns("id")
                                ->from("Robots")
                                ->getPhql();
                expect($phql)->equals("SELECT id FROM [Robots]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from("Robots")
                                ->where("Robots.name = 'Voltron'")
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] WHERE Robots.name = 'Voltron'");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from("Robots")
                                ->where("Robots.name = 'Voltron'")
                                ->andWhere("Robots.id > 100")
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] WHERE (Robots.name = 'Voltron') AND (Robots.id > 100)");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from("Robots")
                                ->where("Robots.name = 'Voltron'")
                                ->orWhere("Robots.id > 100")
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] WHERE (Robots.name = 'Voltron') OR (Robots.id > 100)");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from("Robots")
                                ->where(100)
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] WHERE [Robots].[id] = 100");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from("Robots")
                                ->groupBy("Robots.name")
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] GROUP BY Robots.name");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from("Robots")
                                ->groupBy(["Robots.name", "Robots.id"])
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] GROUP BY Robots.name, Robots.id");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns(["Robots.name", "SUM(Robots.price)"])
                                ->from("Robots")
                                ->groupBy("Robots.name")
                                ->getPhql();
                expect($phql)->equals("SELECT Robots.name, SUM(Robots.price) FROM [Robots] GROUP BY Robots.name");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->columns(["Robots.name", "SUM(Robots.price)"])
                                ->from("Robots")
                                ->groupBy("Robots.name")
                                ->having("SUM(Robots.price) > 1000")
                                ->getPhql();
                expect($phql)->equals("SELECT Robots.name, SUM(Robots.price) FROM [Robots] GROUP BY Robots.name HAVING SUM(Robots.price) > 1000");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from("Robots")
                                ->join("RobotsParts")
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] JOIN [RobotsParts]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from("Robots")
                                ->join("RobotsParts", null, "p")
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] JOIN [RobotsParts] AS [p]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from("Robots")
                                ->join("RobotsParts", "Robots.id = RobotsParts.robots_id", "p")
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] JOIN [RobotsParts] AS [p] ON Robots.id = RobotsParts.robots_id");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from("Robots")
                                ->join("RobotsParts", "Robots.id = RobotsParts.robots_id", "p")
                                ->join("Parts", "Parts.id = RobotsParts.parts_id", "t")
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] JOIN [RobotsParts] AS [p] ON Robots.id = RobotsParts.robots_id JOIN [Parts] AS [t] ON Parts.id = RobotsParts.parts_id");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from("Robots")
                                ->leftJoin("RobotsParts", "Robots.id = RobotsParts.robots_id")
                                ->leftJoin("Parts", "Parts.id = RobotsParts.parts_id")
                                ->where("Robots.id > 0")
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] LEFT JOIN [RobotsParts] ON Robots.id = RobotsParts.robots_id LEFT JOIN [Parts] ON Parts.id = RobotsParts.parts_id WHERE Robots.id > 0");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->addFrom("Robots", "r")
                                ->getPhql();
                expect($phql)->equals("SELECT [r].* FROM [Robots] AS [r]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from("Robots")
                                ->addFrom("Parts", "p")
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].*, [p].* FROM [Robots], [Parts] AS [p]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(["r" => "Robots"])
                                ->addFrom("Parts", "p")
                                ->getPhql();
                expect($phql)->equals("SELECT [r].*, [p].* FROM [Robots] AS [r], [Parts] AS [p]");


                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from(["r" => "Robots", "p" => "Parts"])
                                ->getPhql();
                expect($phql)->equals("SELECT [r].*, [p].* FROM [Robots] AS [r], [Parts] AS [p]");


                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from("Robots")
                                ->orderBy("Robots.name")
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] ORDER BY Robots.name");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from("Robots")
                                ->orderBy([1, "Robots.name"])
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] ORDER BY 1, Robots.name");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from("Robots")
                                ->limit(10)
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] LIMIT :APL0:");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                                ->from("Robots")
                                ->limit(10, 5)
                                ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] LIMIT :APL0: OFFSET :APL1:");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                    ->from("Robots")
                    ->where("Robots.name = 'Voltron'")
                    ->betweenWhere("Robots.id", 0, 50)
                    ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] WHERE (Robots.name = 'Voltron') AND (Robots.id BETWEEN :AP0: AND :AP1:)");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                    ->from("Robots")
                    ->where("Robots.name = 'Voltron'")
                    ->inWhere("Robots.id", [1, 2, 3])
                    ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] WHERE (Robots.name = 'Voltron') AND (Robots.id IN (:AP0:, :AP1:, :AP2:))");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                    ->from("Robots")
                    ->where("Robots.name = 'Voltron'")
                    ->betweenWhere("Robots.id", 0, 50, Builder::OPERATOR_OR)
                    ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] WHERE (Robots.name = 'Voltron') OR (Robots.id BETWEEN :AP0: AND :AP1:)");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                    ->from("Robots")
                    ->where("Robots.name = 'Voltron'")
                    ->inWhere("Robots.id", [1, 2, 3], Builder::OPERATOR_OR)
                    ->getPhql();
                expect($phql)->equals("SELECT [Robots].* FROM [Robots] WHERE (Robots.name = 'Voltron') OR (Robots.id IN (:AP0:, :AP1:, :AP2:))");
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
                    ->from("Robots")
                    ->leftJoin("RobotsParts", "Robots.id = RobotsParts.robots_id")
                    ->leftJoin("Parts", "Parts.id = RobotsParts.parts_id")
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
                    ->from("Robots")
                    ->having("Robots.price > 1000")
                    ->getPhql();

                expect($phql)->equals("SELECT Robots.name FROM [Robots] HAVING Robots.price > 1000");
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
                    ->from("Robots")
                    ->getPhql();
                expect($phql)->equals("SELECT DISTINCT Robots.name FROM [Robots]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                    ->distinct(false)
                    ->columns(["Robots.name"])
                    ->from("Robots")
                    ->getPhql();
                expect($phql)->equals("SELECT ALL Robots.name FROM [Robots]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                    ->distinct(true)
                    ->distinct(null)
                    ->columns(["Robots.name"])
                    ->from("Robots")
                    ->getPhql();
                expect($phql)->equals("SELECT Robots.name FROM [Robots]");

                $builder = new Builder();
                $phql = $builder->setDi($di)
                    ->distinct(true)
                    ->from("Robots")
                    ->getPhql();
                expect($phql)->equals("SELECT DISTINCT [Robots].* FROM [Robots]");
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
                    "models"     => "Robots",
                    "columns"    => ["id", "name", "status"],
                    "conditions" => "a > 5",
                    "group"      => ["type", "source"],
                    "having"     => "b < 5",
                    "order"      => ["name", "created"],
                    "limit"      => 10,
                    "offset"     => 15,
                ];

                $builder = new Builder($params, $di);

                $expectedPhql = "SELECT id, name, status FROM [Robots] "
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
     * - signle numeric value
     * - array of 2 values (limit, offset)
     */
    public function testConstructorLimit()
    {
        $this->specify(
            "Query Builders don't work with separate limit and offset in the constructor params",
            function () {
                // separate limit and offset

                $params = [
                    "models" => "Robots",
                    "limit"  => 10,
                    "offset" => 15,
                ];

                $builderLimitAndOffset = new Builder($params);

                // separate limit with offset

                $params = [
                    "models" => "Robots",
                    "limit"  => [10, 15],
                ];

                $builderLimitWithOffset = new Builder($params);

                $expectedPhql = "SELECT [Robots].* FROM [Robots] LIMIT :APL0: OFFSET :APL1:";

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
                $standardBuilder->from("Robots")
                    ->where(
                        "year > :min: AND year < :max:",
                        ["min" => "2013-01-01",   "max" => "2100-01-01"],
                        ["min" => PDO::PARAM_STR, "max" => PDO::PARAM_STR]
                    );

                $standardResult = $standardBuilder->getQuery()->execute();

                // --------------- test for single condition ------------------
                $params = [
                    "models"     => "Robots",
                    "conditions" => [
                        [
                            "year > :min: AND year < :max:",
                            ["min" => "2013-01-01",   "max" => "2100-01-01"],
                            ["min" => PDO::PARAM_STR, "max" => PDO::PARAM_STR],
                        ],
                    ],
                ];

                $builderWithSingleCondition = new Builder($params);
                $singleConditionResult      = $builderWithSingleCondition->getQuery()->execute();

                // ------------- test for multiple conditions ----------------

                $params = [
                    "models"     => "Robots",
                    "conditions" => [
                        [
                            "year > :min:",
                            ["min" => "2000-01-01"],
                            ["min" => PDO::PARAM_STR],
                        ],
                        [
                            "year < :max:",
                            ["max" => "2100-01-01"],
                            ["max" => PDO::PARAM_STR],
                        ],
                    ],
                ];

                // conditions are merged!
                $builderMultipleConditions = new Builder($params);
                $multipleConditionResult   = $builderMultipleConditions->getQuery()->execute();

                $expectedPhql = "SELECT [Robots].* FROM [Robots] WHERE year > :min: AND year < :max:";

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
                        ->from("Robots")
                        ->groupBy("id, name")
                        ->getPhql();

                expect($phql)->equals("SELECT name, SUM(price) FROM [Robots] GROUP BY [id], [name]");
            }
        );
    }
}
