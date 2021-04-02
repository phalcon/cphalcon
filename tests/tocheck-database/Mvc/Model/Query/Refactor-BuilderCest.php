<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Query;

use IntegrationTester;
use PDO;
use Phalcon\Cache\Backend\File;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Parts;
use Phalcon\Test\Models\RobotsParts;
use Phalcon\Test\Models\Snapshot\Robots;

use function outputDir;

class BuilderCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Models cache
     *
     * @author Phalcon Team <team@phalcon.io>
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-12-09
     */
    public function shouldSaveToUseComplexSnapshotCache(IntegrationTester $I)
    {
        $I->wantToTest('Saving snapshot using complex resultset while using modelsCache');

        $I->skipTest('TODO - Check me');

        $I->addServiceToContainer(
            'modelsCache',
            function () {
                return new File(
                    new Data(
                        ['lifetime' => 20,]
                    ),
                    [
                        'storageDir' => outputDir('tests/cache/'),
                    ]
                );
            },
            true
        );

        for ($i = 0; $i <= 1; $i++) {
            $builder = new Builder();

            $result = $builder
                ->columns(['rp.*,r.*'])
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

            $I->assertInstanceOf(
                Robots::class,
                $robot
            );

            $I->assertNotEmpty(
                $robot->getSnapshotData()
            );

            $I->assertEquals(
                $robot->toArray(),
                $robot->getSnapshotData()
            );

            $I->assertInstanceOf(
                RobotsParts::class,
                $robotParts
            );

            $I->assertNotEmpty(
                $robotParts->getSnapshotData()
            );

            $I->assertEquals(
                $robotParts->toArray(),
                $robotParts->getSnapshotData()
            );

            $I->seeFileFound(
                outputDir('tests/cache/robots-cache-complex')
            );
        }
    }

    public function testAction(IntegrationTester $I)
    {
        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from(Robots::class)
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' . Robots::class . ']',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from([Robots::class, RobotsParts::class])
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].*, [' .
            RobotsParts::class . '].* FROM [' .
            Robots::class . '], [' . RobotsParts::class . ']',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->columns('*')
                        ->from(Robots::class)
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT * FROM [' . Robots::class . ']',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->columns(['id', 'name'])
                        ->from(Robots::class)
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT id, name FROM [' . Robots::class . ']',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->columns('id')
                        ->from(Robots::class)
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT id FROM [' . Robots::class . ']',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from(Robots::class)
                        ->where("Robots.name = 'Voltron'")
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . "] WHERE Robots.name = 'Voltron'",
            $phql
        );
        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from(Robots::class)
                        ->where("Robots.name = 'Voltron'")
                        ->andWhere('Robots.id > 100')
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . "] WHERE (Robots.name = 'Voltron') AND (Robots.id > 100)",
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from(Robots::class)
                        ->where("Robots.name = 'Voltron'")
                        ->orWhere('Robots.id > 100')
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . "] WHERE (Robots.name = 'Voltron') OR (Robots.id > 100)",
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from(Robots::class)
                        ->where(100)
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . '] WHERE [' . Robots::class . '].[id] = 100',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from(Robots::class)
                        ->groupBy('Robots.name')
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . '] GROUP BY Robots.name',
            $phql
        );


        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from(Robots::class)
                        ->groupBy(['Robots.name', 'Robots.id'])
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . '] GROUP BY Robots.name, Robots.id',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->columns(['Robots.name', 'SUM(Robots.price)'])
                        ->from(Robots::class)
                        ->groupBy('Robots.name')
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT Robots.name, SUM(Robots.price) FROM [' .
            Robots::class . '] GROUP BY Robots.name',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->columns(['Robots.name', 'SUM(Robots.price)'])
                        ->from(Robots::class)
                        ->groupBy('Robots.name')
                        ->having('SUM(Robots.price) > 1000')
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT Robots.name, SUM(Robots.price) FROM [' .
            Robots::class . '] GROUP BY Robots.name HAVING SUM(Robots.price) > 1000',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->columns(['Robots.name', 'SUM(Robots.price)'])
                        ->from(Robots::class)
                        ->groupBy('Robots.name')
                        ->having('SUM(Robots.price) > 1000')
                        ->andHaving('SUM(Robots.price) < 2000')
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT Robots.name, SUM(Robots.price) FROM [' .
            Robots::class . '] GROUP BY Robots.name ' .
            'HAVING (SUM(Robots.price) > 1000) AND (SUM(Robots.price) < 2000)',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->columns(['Robots.name', 'SUM(Robots.price)'])
                        ->from(Robots::class)
                        ->groupBy('Robots.name')
                        ->having('SUM(Robots.price) > 1000')
                        ->orHaving('SUM(Robots.price) < 500')
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT Robots.name, SUM(Robots.price) FROM [' .
            Robots::class . '] GROUP BY Robots.name ' .
            'HAVING (SUM(Robots.price) > 1000) OR (SUM(Robots.price) < 500)',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->columns(['Robots.name', 'SUM(Robots.price)'])
                        ->from(Robots::class)
                        ->groupBy('Robots.name')
                        ->inHaving('SUM(Robots.price)', [1, 2, 3])
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT Robots.name, SUM(Robots.price) FROM [' .
            Robots::class . '] GROUP BY Robots.name ' .
            'HAVING SUM(Robots.price) IN (:AP0:, :AP1:, :AP2:)',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder
            ->columns(['Robots.name', 'SUM(Robots.price)'])
            ->from(Robots::class)
            ->groupBy('Robots.name')
            ->notInHaving('SUM(Robots.price)', [1, 2, 3])
            ->getPhql()
        ;

        $I->assertEquals(
            'SELECT Robots.name, SUM(Robots.price) FROM [' .
            Robots::class . '] GROUP BY Robots.name ' .
            'HAVING SUM(Robots.price) NOT IN (:AP0:, :AP1:, :AP2:)',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder
            ->columns(['Robots.name', 'SUM(Robots.price)'])
            ->from(Robots::class)
            ->groupBy('Robots.name')
            ->having('SUM(Robots.price) > 100')
            ->inHaving('SUM(Robots.price)', [1, 2, 3], Builder::OPERATOR_OR)
            ->getPhql()
        ;

        $I->assertEquals(
            'SELECT Robots.name, SUM(Robots.price) FROM [' .
            Robots::class . '] GROUP BY Robots.name ' .
            'HAVING (SUM(Robots.price) > 100) OR (SUM(Robots.price) IN (:AP0:, :AP1:, :AP2:))',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder
            ->columns(['Robots.name', 'SUM(Robots.price)'])
            ->from(Robots::class)
            ->groupBy('Robots.name')
            ->having('SUM(Robots.price) > 100')
            ->notInHaving('SUM(Robots.price)', [1, 2, 3], Builder::OPERATOR_OR)
            ->getPhql()
        ;

        $I->assertEquals(
            'SELECT Robots.name, SUM(Robots.price) FROM [' .
            Robots::class . '] GROUP BY Robots.name ' .
            'HAVING (SUM(Robots.price) > 100) OR (SUM(Robots.price) NOT IN (:AP0:, :AP1:, :AP2:))',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder
            ->columns(['Robots.name', 'SUM(Robots.price)'])
            ->from(Robots::class)
            ->groupBy('Robots.name')
            ->betweenHaving('SUM(Robots.price)', 100, 200)
            ->getPhql()
        ;

        $I->assertEquals(
            'SELECT Robots.name, SUM(Robots.price) FROM [' .
            Robots::class . '] GROUP BY Robots.name ' .
            'HAVING SUM(Robots.price) BETWEEN :AP0: AND :AP1:',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder
            ->columns(['Robots.name', 'SUM(Robots.price)'])
            ->from(Robots::class)
            ->groupBy('Robots.name')
            ->notBetweenHaving('SUM(Robots.price)', 100, 200)
            ->getPhql()
        ;

        $I->assertEquals(
            'SELECT Robots.name, SUM(Robots.price) FROM [' .
            Robots::class . '] GROUP BY Robots.name ' .
            'HAVING SUM(Robots.price) NOT BETWEEN :AP0: AND :AP1:',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from(Robots::class)
                        ->join(RobotsParts::class)
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . '] JOIN [' . RobotsParts::class . ']',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from(Robots::class)
                        ->join(RobotsParts::class, null, 'p')
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . '] JOIN [' . RobotsParts::class . '] AS [p]',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder
            ->from(Robots::class)
            ->join(RobotsParts::class, 'Robots.id = RobotsParts.robots_id', 'p')
            ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . '] JOIN [' .
            RobotsParts::class . '] AS [p] ON Robots.id = RobotsParts.robots_id',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder
            ->from(Robots::class)
            ->join(RobotsParts::class, 'Robots.id = RobotsParts.robots_id', 'p')
            ->join(Parts::class, 'Parts.id = RobotsParts.parts_id', 't')
            ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . '] JOIN [' .
            RobotsParts::class . '] AS [p] ON Robots.id = RobotsParts.robots_id JOIN [' .
            Parts::class . '] AS [t] ON Parts.id = RobotsParts.parts_id',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder
            ->from(Robots::class)
            ->leftJoin(RobotsParts::class, 'Robots.id = RobotsParts.robots_id')
            ->leftJoin(Parts::class, 'Parts.id = RobotsParts.parts_id')
            ->where('Robots.id > 0')
            ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . '] LEFT JOIN [' .
            RobotsParts::class . '] ON Robots.id = RobotsParts.robots_id LEFT JOIN [' .
            Parts::class . '] ON Parts.id = RobotsParts.parts_id WHERE Robots.id > 0',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->addFrom(Robots::class, 'r')
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [r].* FROM [' . Robots::class . '] AS [r]',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from(Robots::class)
                        ->addFrom(Parts::class, 'p')
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].*, [p].* FROM [' .
            Robots::class . '], [' . Parts::class . '] AS [p]',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from(['r' => Robots::class])
                        ->addFrom(Parts::class, 'p')
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [r].*, [p].* FROM [' .
            Robots::class . '] AS [r], [' . Parts::class . '] AS [p]',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from(['r' => Robots::class, 'p' => Parts::class])
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [r].*, [p].* FROM [' .
            Robots::class . '] AS [r], [' . Parts::class . '] AS [p]',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from(Robots::class)
                        ->orderBy('Robots.name')
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . '] ORDER BY Robots.name',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from(Robots::class)
                        ->orderBy([1, 'Robots.name'])
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . '] ORDER BY 1, Robots.name',
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from(Robots::class)
                        ->limit(10)
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . '] LIMIT :APL0:',
            $phql
        );


        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from(Robots::class)
                        ->limit(10, 5)
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . '] LIMIT :APL0: OFFSET :APL1:',
            $phql
        );


        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->from(Robots::class)
                        ->where("Robots.name = 'Voltron'")
                        ->betweenWhere('Robots.id', 0, 50)
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . "] WHERE (Robots.name = 'Voltron') AND (Robots.id BETWEEN :AP0: AND :AP1:)",
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder
            ->from(Robots::class)
            ->where("Robots.name = 'Voltron'")
            ->inWhere('Robots.id', [1, 2, 3])
            ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . "] WHERE (Robots.name = 'Voltron') " .
            "AND (Robots.id IN (:AP0:, :AP1:, :AP2:))",
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder
            ->from(Robots::class)
            ->where("Robots.name = 'Voltron'")
            ->betweenWhere('Robots.id', 0, 50, Builder::OPERATOR_OR)
            ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . "] WHERE (Robots.name = 'Voltron') " .
            "OR (Robots.id BETWEEN :AP0: AND :AP1:)",
            $phql
        );

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder
            ->from(Robots::class)
            ->where("Robots.name = 'Voltron'")
            ->inWhere('Robots.id', [1, 2, 3], Builder::OPERATOR_OR)
            ->getPhql()
        ;

        $I->assertEquals(
            'SELECT [' . Robots::class . '].* FROM [' .
            Robots::class . "] WHERE (Robots.name = 'Voltron') " .
            "OR (Robots.id IN (:AP0:, :AP1:, :AP2:))",
            $phql
        );
    }

    public function testIssue701(IntegrationTester $I)
    {
        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder
            ->from(Robots::class)
            ->leftJoin(RobotsParts::class, 'Robots.id = RobotsParts.robots_id')
            ->leftJoin(Parts::class, 'Parts.id = RobotsParts.parts_id')
            ->where('Robots.id > :1: AND Robots.id < :2:', [1 => 0, 2 => 1000])
        ;

        $params = $phql->getQuery()->getBindParams();

        $I->assertEquals(
            0,
            $params[1]
        );
        $I->assertEquals(
            1000,
            $params[2]
        );


        $phql->andWhere(
            'Robots.name = :name:',
            [
                'name' => 'Voltron',
            ]
        );

        $params = $phql->getQuery()->getBindParams();

        $I->assertEquals(
            0,
            $params[1]
        );

        $I->assertEquals(
            1000,
            $params[2]
        );

        $I->assertEquals(
            'Voltron',
            $params['name']
        );
    }

    public function testIssue1115(IntegrationTester $I)
    {
        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->columns(['Robots.name'])
                        ->from(Robots::class)
                        ->having('Robots.price > 1000')
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT Robots.name FROM [' . Robots::class . '] HAVING Robots.price > 1000',
            $phql
        );
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

        $standardBuilder
            ->from(Robots::class)
            ->where(
                'year > :min: AND year < :max:',
                ['min' => '2013-01-01', 'max' => '2100-01-01'],
                ['min' => PDO::PARAM_STR, 'max' => PDO::PARAM_STR]
            )
        ;

        $standardResult = $standardBuilder->getQuery()->execute();

        // --------------- test for single condition ------------------
        $params = [
            'models'     => Robots::class,
            'conditions' => [
                [
                    'year > :min: AND year < :max:',
                    ['min' => '2013-01-01', 'max' => '2100-01-01'],
                    ['min' => PDO::PARAM_STR, 'max' => PDO::PARAM_STR],
                ],
            ],
        ];

        $builderWithSingleCondition = new Builder($params);
        $singleConditionResult      = $builderWithSingleCondition->getQuery()->execute();

        // ------------- test for multiple conditions ----------------

        $params = [
            'models'     => Robots::class,
            'conditions' => [
                [
                    'year > :min:',
                    ['min' => '2000-01-01'],
                    ['min' => PDO::PARAM_STR],
                ],
                [
                    'year < :max:',
                    ['max' => '2100-01-01'],
                    ['max' => PDO::PARAM_STR],
                ],
            ],
        ];

        // conditions are merged!
        $builderMultipleConditions = new Builder($params);
        $multipleConditionResult   = $builderMultipleConditions->getQuery()->execute();

        $expectedPhql = 'SELECT [' . Robots::class . '].* FROM ['
                      . Robots::class . '] WHERE year > :min: AND year < :max:';

        /* ------------ ASSERTING --------- */

        $I->assertEquals(
            $expectedPhql,
            $standardBuilder->getPhql()
        );

        $I->assertInstanceOf(
            Simple::class,
            $standardResult
        );

        $I->assertEquals(
            $expectedPhql,
            $builderWithSingleCondition->getPhql()
        );

        $I->assertInstanceOf(
            Simple::class,
            $singleConditionResult
        );

        $I->assertEquals(
            $expectedPhql,
            $builderMultipleConditions->getPhql()
        );

        $I->assertInstanceOf(
            Simple::class,
            $multipleConditionResult
        );
    }
}
