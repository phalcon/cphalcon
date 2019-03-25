<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Paginator\Adapter;

use IntegrationTester;
use Phalcon\Paginator\Adapter\QueryBuilder;
use Phalcon\Paginator\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robos;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\RobotsParts;
use Phalcon\Test\Models\Stock;

class QueryBuilderCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests query builder pagination with having and group
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-15
     */
    public function testIssue12111WithGroup(IntegrationTester $I)
    {
        $this->setDiMysql();
        $manager = $this->getService('modelsManager');
        $builder = $manager
            ->createBuilder()
            ->columns("name, COUNT(*) as stock_count")
            ->from(['Stock' => Stock::class])
            ->groupBy('name')
            ->having('SUM(Stock.stock) > 0')
        ;

        $paginate = (new QueryBuilder(
            [
                "builder" => $builder,
                "limit"   => 1,
                "page"    => 2,
            ]
        ))->paginate();

        $I->assertEquals(2, $paginate->last);
        $I->assertEquals(2, $paginate->total_items);
    }

    /**
     * Tests query builder pagination with having not throwing exception when
     * should
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-15
     */
    public function testIssue12111WithoutGroupException(IntegrationTester $I)
    {
        $I->expectThrowable(
            new Exception('When having is set there should be columns option provided for which calculate row count'),
            function () {
                $this->setDiMysql();
                $manager = $this->getService('modelsManager');
                $builder = $manager
                    ->createBuilder()
                    ->columns("COUNT(*) as stock_count")
                    ->from(['Stock' => Stock::class])
                    ->having('SUM(Stock.stock) > 0')
                ;

                $paginate = (new QueryBuilder(
                    [
                        "builder" => $builder,
                        "limit"   => 1,
                        "page"    => 2,
                    ]
                ))->paginate();
            }
        );
    }

    /**
     * Tests query builder pagination with having and without group
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-15
     */
    public function testIssue12111WithoutGroup(IntegrationTester $I)
    {
        $this->setDiMysql();
        $db = $this->getService('db');
        /*
         * There is no clean way to rewrite query builder's query in the
         * strict mode: if we remove all nonaggregated columns, we will get
         * "Unknown column 'Stock.stock' in 'having clause'", otherwise
         * "In aggregated query without GROUP BY, expression #1 of SELECT
         * list contains nonaggregated column 'phalcon_test.Stock.stock'"
         */
        $db->query(
            "SET SESSION sql_mode='STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE," .
            "ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION'"
        );

        $manager = $this->getService('modelsManager');
        $builder = $manager
            ->createBuilder()
            ->columns("*, COUNT(*) as stock_count")
            ->from(['Stock' => Stock::class])
            ->having('stock > 0')
        ;

        $paginate = (new QueryBuilder(
            [
                "builder" => $builder,
                "limit"   => 1,
                "page"    => 2,
                "columns" => "id,stock",
            ]
        ))->paginate();

        $I->assertEquals(2, $paginate->last);
        $I->assertEquals(2, $paginate->total_items);
    }

    /**
     * Tests query builder pagination with having and group with a different db
     * service than 'db'
     *
     * @author David Napierata
     * @since  2017-07-18
     */
    public function testIssue12957(IntegrationTester $I)
    {
        $this->setDiMysql();
        $modelsManager = $this->getService('modelsManager');

        $this->container->set(
            'dbTwo',
            $this->container->get('db')
        );

        $builder = $modelsManager->createBuilder()
                                 ->columns("COUNT(*) as robos_count")
                                 ->from(['Robos' => Robos::class])
                                 ->groupBy('type')
                                 ->having('MAX(Robos.year) > 1970')
        ;

        $paginate = (new QueryBuilder(
            [
                "builder" => $builder,
                "limit"   => 1,
                "page"    => 2,
            ]
        ))->paginate();

        $I->assertEquals(2, $paginate->last);
        $I->assertEquals(2, $paginate->total_items);
    }

    /**
     * Tests for "Column not found: 1054 Unknown column in 'having clause'".
     * Pending further information from reporter.
     *
     * @author Cameron Hall
     * @since  2018-12-12
     */
    public function testIssue13552(IntegrationTester $I)
    {
        $this->setDiMysql();
        $modelsManager = $this->getService('modelsManager');

        $builder = $modelsManager->createBuilder()
                                 ->columns("Robots.*")
                                 ->from(['Robots' => Robots::class])
                                 ->join(RobotsParts::class, "RobotsParts.robots_id = Robots.id", "RobotsParts", "LEFT")
                                 ->groupBy('Robots.id, RobotsParts.id, RobotsParts.parts_id')
                                 ->having('Robots.id > 2')
        ;

        $paginate = (new QueryBuilder(
            [
                "builder" => $builder,
                "limit"   => 10,
                "page"    => 1,
            ]
        ))->paginate();

        $I->assertEquals(1, $paginate->last);
        $I->assertEquals(4, $paginate->total_items);
    }
}
