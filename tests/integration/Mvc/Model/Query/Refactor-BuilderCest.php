<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Query;

use IntegrationTester;
use Phalcon\Cache\Backend\File;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Parts;
use Phalcon\Test\Models\RobotsParts;
use Phalcon\Test\Models\Snapshot\Robots;
use function outputFolder;

class BuilderCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    /**
     * Tests Models cache
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-12-09
     */
    public function shouldSaveToUseComplexSnapshotCache(IntegrationTester $I)
    {
        $I->wantToTest("Saving snapshot using complex resultset while using modelsCache");
        $I->skipTest('TODO - Check me');
        $I->addServiceToContainer(
            'modelsCache',
            function () {
                return new File(
                    new Data(
                        ['lifetime' => 20,]
                    ),
                    ['cacheDir' => outputFolder('tests/cache/')]
                );
            },
            true
        );

        for ($i = 0; $i <= 1; $i++) {
            $builder = new Builder();
            $result  = $builder->columns(['rp.*,r.*'])
                               ->from(['rp' => RobotsParts::class])
                               ->leftJoin(Robots::class, 'r.id = rp.robots_id', 'r')
                               ->where('rp.id = 1')
                               ->getQuery()
                               ->cache(
                                   [
                                       'key' => 'robots-cache-complex',
                                   ]
                               )
                               ->getSingleResult()
            ;
            /** @var Robots $robot */
            $robot = $result['r'];
            /** @var RobotsParts $robotParts */
            $robotParts = $result['rp'];
            $I->assertInstanceOf(Robots::class, $robot);
            $I->assertNotEmpty($robot->getSnapshotData());
            $I->assertEquals($robot->getSnapshotData(), $robot->toArray());
            $I->assertInstanceOf(RobotsParts::class, $robotParts);
            $I->assertNotEmpty($robotParts->getSnapshotData());
            $I->assertEquals($robotParts->getSnapshotData(), $robotParts->toArray());
            $I->seeFileFound(outputFolder("tests/cache/robots-cache-complex"));
        }
    }

    /**
     * Tests merge bind types for Builder::where
     *
     * @issue https://github.com/phalcon/cphalcon/issues/11487
     */
    public function shouldMergeBinTypesForWhere(IntegrationTester $I)
    {
        $builder = new Builder();
        $builder->setDi($this->container);

        $builder
            ->from(Robots::class)
            ->where(
                'id = :id:',
                [':id:' => 3],
                [':id:' => \PDO::PARAM_INT]
            )
        ;

        $builder->where(
            'name = :name:',
            [':name:' => 'Terminator'],
            [':name:' => \PDO::PARAM_STR]
        );

        $actual   = $builder->getQuery()->getBindTypes();
        $expected = [':id:' => 1, ':name:' => 2];

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests merge bind types for Builder::having
     *
     * @issue https://github.com/phalcon/cphalcon/issues/11487
     */
    public function shouldMergeBinTypesForHaving(IntegrationTester $I)
    {
        $builder = new Builder();
        $builder->setDi($this->container);

        $builder
            ->from(Robots::class)
            ->columns(
                [
                    'COUNT(id)',
                    'name',
                ]
            )
            ->groupBy('COUNT(id)')
            ->having(
                'COUNT(id) > :cnt:',
                [':cnt:' => 5],
                [':cnt:' => \PDO::PARAM_INT]
            )
        ;

        $builder->having(
            "CONCAT('is_', type) = :type:",
            [':type:' => 'mechanical'],
            [':type:' => \PDO::PARAM_STR]
        );

        $actual   = $builder->getQuery()->getBindTypes();
        $expected = [':cnt:' => 1, ':type:' => 2];

        $I->assertEquals($expected, $actual);
    }

    public function testAction(IntegrationTester $I)
    {
        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "]");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from([Robots::class, RobotsParts::class])
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].*, [" . RobotsParts::class . "].* FROM [" . Robots::class . "], [" . RobotsParts::class . "]");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->columns("*")
                           ->from(Robots::class)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT * FROM [" . Robots::class . "]");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->columns(["id", "name"])
                           ->from(Robots::class)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT id, name FROM [" . Robots::class . "]");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->columns("id")
                           ->from(Robots::class)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT id FROM [" . Robots::class . "]");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->where("Robots.name = 'Voltron'")
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] WHERE Robots.name = 'Voltron'");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->where("Robots.name = 'Voltron'")
                           ->andWhere("Robots.id > 100")
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] WHERE (Robots.name = 'Voltron') AND (Robots.id > 100)");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->where("Robots.name = 'Voltron'")
                           ->orWhere("Robots.id > 100")
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] WHERE (Robots.name = 'Voltron') OR (Robots.id > 100)");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->where(100)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] WHERE [" . Robots::class . "].[id] = 100");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->groupBy("Robots.name")
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] GROUP BY Robots.name");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->groupBy(["Robots.name", "Robots.id"])
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] GROUP BY Robots.name, Robots.id");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->columns(["Robots.name", "SUM(Robots.price)"])
                           ->from(Robots::class)
                           ->groupBy("Robots.name")
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->columns(["Robots.name", "SUM(Robots.price)"])
                           ->from(Robots::class)
                           ->groupBy("Robots.name")
                           ->having("SUM(Robots.price) > 1000")
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING SUM(Robots.price) > 1000");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->columns(["Robots.name", "SUM(Robots.price)"])
                           ->from(Robots::class)
                           ->groupBy("Robots.name")
                           ->having("SUM(Robots.price) > 1000")
                           ->andHaving("SUM(Robots.price) < 2000")
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING (SUM(Robots.price) > 1000) AND (SUM(Robots.price) < 2000)");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->columns(["Robots.name", "SUM(Robots.price)"])
                           ->from(Robots::class)
                           ->groupBy("Robots.name")
                           ->having("SUM(Robots.price) > 1000")
                           ->orHaving("SUM(Robots.price) < 500")
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING (SUM(Robots.price) > 1000) OR (SUM(Robots.price) < 500)");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->columns(["Robots.name", "SUM(Robots.price)"])
                           ->from(Robots::class)
                           ->groupBy("Robots.name")
                           ->inHaving("SUM(Robots.price)", [1, 2, 3])
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING SUM(Robots.price) IN (:AP0:, :AP1:, :AP2:)");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->columns(["Robots.name", "SUM(Robots.price)"])
                           ->from(Robots::class)
                           ->groupBy("Robots.name")
                           ->notInHaving("SUM(Robots.price)", [1, 2, 3])
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING SUM(Robots.price) NOT IN (:AP0:, :AP1:, :AP2:)");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->columns(["Robots.name", "SUM(Robots.price)"])
                           ->from(Robots::class)
                           ->groupBy("Robots.name")
                           ->having("SUM(Robots.price) > 100")
                           ->inHaving("SUM(Robots.price)", [1, 2, 3], Builder::OPERATOR_OR)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING (SUM(Robots.price) > 100) OR (SUM(Robots.price) IN (:AP0:, :AP1:, :AP2:))");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->columns(["Robots.name", "SUM(Robots.price)"])
                           ->from(Robots::class)
                           ->groupBy("Robots.name")
                           ->having("SUM(Robots.price) > 100")
                           ->notInHaving("SUM(Robots.price)", [1, 2, 3], Builder::OPERATOR_OR)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING (SUM(Robots.price) > 100) OR (SUM(Robots.price) NOT IN (:AP0:, :AP1:, :AP2:))");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->columns(["Robots.name", "SUM(Robots.price)"])
                           ->from(Robots::class)
                           ->groupBy("Robots.name")
                           ->betweenHaving("SUM(Robots.price)", 100, 200)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING SUM(Robots.price) BETWEEN :AP0: AND :AP1:");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->columns(["Robots.name", "SUM(Robots.price)"])
                           ->from(Robots::class)
                           ->groupBy("Robots.name")
                           ->notBetweenHaving("SUM(Robots.price)", 100, 200)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT Robots.name, SUM(Robots.price) FROM [" . Robots::class . "] GROUP BY Robots.name HAVING SUM(Robots.price) NOT BETWEEN :AP0: AND :AP1:");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->join(RobotsParts::class)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] JOIN [" . RobotsParts::class . "]");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->join(RobotsParts::class, null, "p")
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] JOIN [" . RobotsParts::class . "] AS [p]");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->join(RobotsParts::class, "Robots.id = RobotsParts.robots_id", "p")
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] JOIN [" . RobotsParts::class . "] AS [p] ON Robots.id = RobotsParts.robots_id");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->join(RobotsParts::class, "Robots.id = RobotsParts.robots_id", "p")
                           ->join(Parts::class, "Parts.id = RobotsParts.parts_id", "t")
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] JOIN [" . RobotsParts::class . "] AS [p] ON Robots.id = RobotsParts.robots_id JOIN [" . Parts::class . "] AS [t] ON Parts.id = RobotsParts.parts_id");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->leftJoin(RobotsParts::class, "Robots.id = RobotsParts.robots_id")
                           ->leftJoin(Parts::class, "Parts.id = RobotsParts.parts_id")
                           ->where("Robots.id > 0")
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] LEFT JOIN [" . RobotsParts::class . "] ON Robots.id = RobotsParts.robots_id LEFT JOIN [" . Parts::class . "] ON Parts.id = RobotsParts.parts_id WHERE Robots.id > 0");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->addFrom(Robots::class, "r")
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [r].* FROM [" . Robots::class . "] AS [r]");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->addFrom(Parts::class, "p")
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].*, [p].* FROM [" . Robots::class . "], [" . Parts::class . "] AS [p]");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(["r" => Robots::class])
                           ->addFrom(Parts::class, "p")
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [r].*, [p].* FROM [" . Robots::class . "] AS [r], [" . Parts::class . "] AS [p]");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(["r" => Robots::class, "p" => Parts::class])
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [r].*, [p].* FROM [" . Robots::class . "] AS [r], [" . Parts::class . "] AS [p]");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->orderBy("Robots.name")
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] ORDER BY Robots.name");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->orderBy([1, "Robots.name"])
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] ORDER BY 1, Robots.name");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->limit(10)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] LIMIT :APL0:");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->limit(10, 5)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] LIMIT :APL0: OFFSET :APL1:");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->where("Robots.name = 'Voltron'")
                           ->betweenWhere("Robots.id", 0, 50)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] WHERE (Robots.name = 'Voltron') AND (Robots.id BETWEEN :AP0: AND :AP1:)");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->where("Robots.name = 'Voltron'")
                           ->inWhere("Robots.id", [1, 2, 3])
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] WHERE (Robots.name = 'Voltron') AND (Robots.id IN (:AP0:, :AP1:, :AP2:))");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->where("Robots.name = 'Voltron'")
                           ->betweenWhere("Robots.id", 0, 50, Builder::OPERATOR_OR)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] WHERE (Robots.name = 'Voltron') OR (Robots.id BETWEEN :AP0: AND :AP1:)");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->where("Robots.name = 'Voltron'")
                           ->inWhere("Robots.id", [1, 2, 3], Builder::OPERATOR_OR)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT [" . Robots::class . "].* FROM [" . Robots::class . "] WHERE (Robots.name = 'Voltron') OR (Robots.id IN (:AP0:, :AP1:, :AP2:))");
    }

    public function testIssue701(IntegrationTester $I)
    {
        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->from(Robots::class)
                           ->leftJoin(RobotsParts::class, "Robots.id = RobotsParts.robots_id")
                           ->leftJoin(Parts::class, "Parts.id = RobotsParts.parts_id")
                           ->where("Robots.id > :1: AND Robots.id < :2:", [1 => 0, 2 => 1000])
        ;

        $params = $phql->getQuery()->getBindParams();
        $I->assertEquals($params[1], 0);
        $I->assertEquals($params[2], 1000);

        $phql->andWhere(
            "Robots.name = :name:",
            [
                "name" => "Voltron",
            ]
        );

        $params = $phql->getQuery()->getBindParams();
        $I->assertEquals($params[1], 0);
        $I->assertEquals($params[2], 1000);
        $I->assertEquals($params["name"], "Voltron");
    }

    public function testIssue1115(IntegrationTester $I)
    {
        $builder = new Builder();

        $phql = $builder->setDi($this->container)
                        ->columns(["Robots.name"])
                        ->from(Robots::class)
                        ->having("Robots.price > 1000")
                        ->getPhql()
        ;

        $I->assertEquals($phql, "SELECT Robots.name FROM [" . Robots::class . "] HAVING Robots.price > 1000");
    }

    public function testSelectDistinctAll(IntegrationTester $I)
    {
        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->distinct(true)
                           ->columns(["Robots.name"])
                           ->from(Robots::class)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT DISTINCT Robots.name FROM [" . Robots::class . "]");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->distinct(false)
                           ->columns(["Robots.name"])
                           ->from(Robots::class)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT ALL Robots.name FROM [" . Robots::class . "]");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->distinct(true)
                           ->distinct(null)
                           ->columns(["Robots.name"])
                           ->from(Robots::class)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT Robots.name FROM [" . Robots::class . "]");

        $builder = new Builder();
        $phql    = $builder->setDi($this->container)
                           ->distinct(true)
                           ->from(Robots::class)
                           ->getPhql()
        ;
        $I->assertEquals($phql, "SELECT DISTINCT [" . Robots::class . "].* FROM [" . Robots::class . "]");
    }

    /**
     * Test checks passing query params and dependency injector into
     * constructor
     */
    public function testConstructor(IntegrationTester $I)
    {
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

        $builder = new Builder($params, $this->container);

        $expectedPhql = "SELECT id, name, status FROM [" . Robots::class . "] "
            . "WHERE a > 5 GROUP BY [type], [source] "
            . "HAVING b < 5 ORDER BY [name], [created] "
            . "LIMIT :APL0: OFFSET :APL1:";

        $I->assertEquals($expectedPhql, $builder->getPhql());
        $I->assertEquals($this->container, $builder->getDI());
    }

    /**
     * Test checks passing 'limit'/'offset' query param into constructor.
     * limit key can take:
     * - single numeric value
     * - array of 2 values (limit, offset)
     */
    public function testConstructorLimit(IntegrationTester $I)
    {
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

        $I->assertEquals($builderLimitAndOffset->getPhql(), $expectedPhql);
        $I->assertEquals($builderLimitWithOffset->getPhql(), $expectedPhql);
    }

    /**
     * Test checks passing 'condition' query param into constructor.
     * Conditions can now be passed as an string(as before) and
     * as an array of 3 elements:
     * - condition string for example "age > :age: AND created > :created:"
     * - bind params for example array('age' => 18, 'created' => '2013-09-01')
     * - bind types for example array('age' => PDO::PARAM_INT, 'created' =>
     * PDO::PARAM_STR)
     *
     * First two params are REQUIRED, bind types are optional.
     */
    public function testConstructorConditions(IntegrationTester $I)
    {
        // ------------- test for setters(classic) way ----------------

        $standardBuilder = new Builder();
        $standardBuilder->from(Robots::class)
                        ->where(
                            "year > :min: AND year < :max:",
                            ["min" => "2013-01-01", "max" => "2100-01-01"],
                            ["min" => \PDO::PARAM_STR, "max" => \PDO::PARAM_STR]
                        )
        ;

        $standardResult = $standardBuilder->getQuery()->execute();

        // --------------- test for single condition ------------------
        $params = [
            "models"     => Robots::class,
            "conditions" => [
                [
                    "year > :min: AND year < :max:",
                    ["min" => "2013-01-01", "max" => "2100-01-01"],
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

        $I->assertEquals($standardBuilder->getPhql(), $expectedPhql);
        $I->assertInstanceOf("Phalcon\\Mvc\\Model\\Resultset\\Simple", $standardResult);

        $I->assertEquals($builderWithSingleCondition->getPhql(), $expectedPhql);
        $I->assertInstanceOf("Phalcon\\Mvc\\Model\\Resultset\\Simple", $singleConditionResult);

        $I->assertEquals($builderMultipleConditions->getPhql(), $expectedPhql);
        $I->assertInstanceOf("Phalcon\\Mvc\\Model\\Resultset\\Simple", $multipleConditionResult);
    }

    public function testGroup(IntegrationTester $I)
    {
        $builder = new Builder();

        $phql = $builder->setDi($this->container)
                        ->columns(["name", "SUM(price)"])
                        ->from(Robots::class)
                        ->groupBy("id, name")
                        ->getPhql()
        ;

        $I->assertEquals($phql, "SELECT name, SUM(price) FROM [" . Robots::class . "] GROUP BY [id], [name]");
    }

    /**
     * Tests work with limit / offset
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12419
     * @author Serghei Iakovelv <serghei@phalconphp.com>
     * @since  2016-12-18
     */
    public function shouldCorrectHandleLimitAndOffset(IntegrationTester $I)
    {
        $examples = $this->limitOffsetProvider();
        foreach ($examples as $item) {
            $limit    = $item[0];
            $offset   = $item[1];
            $expected = $item[2];

            $builder = new Builder(null, $this->container);
            $phql    = $builder
                ->columns(['name'])
                ->from(Robots::class)
                ->limit($limit, $offset)
                ->getPhql()
            ;

            /** Just prevent IDE to highlight this as not valid SQL dialect */
            $I->assertEquals($phql, 'SELECT name ' . "FROM {$expected}");
        }
    }

    protected function limitOffsetProvider()
    {
        return [
            [-7, null, "[" . Robots::class . "] LIMIT :APL0:"],
            /**
             * @todo Check these examples
             */
            //            ["-7234", null, "[" . Robots::class . "] LIMIT :APL0:"],
            //            ["18", null, "[" . Robots::class . "] LIMIT :APL0:"],
            //            ["18", 2, "[" . Robots::class . "] LIMIT :APL0: OFFSET :APL1:"],
            //            ["-1000", -200, "[" . Robots::class . "] LIMIT :APL0: OFFSET :APL1:"],
            //            ["1000", "-200", "[" . Robots::class . "] LIMIT :APL0: OFFSET :APL1:"],
            //            ["0", "-200", "[" . Robots::class . "]"],
            //            ["%3CMETA%20HTTP-EQUIV%3D%22refresh%22%20CONT ENT%3D%220%3Burl%3Djavascript%3Aqss%3D7%22%3E", 50, "[" . Robots::class . "]"],
        ];
    }
}
