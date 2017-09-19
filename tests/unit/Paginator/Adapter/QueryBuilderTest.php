<?php

namespace Phalcon\Test\Unit\Paginator\Adapter;

use Helper\ModelTrait;
use Phalcon\Di;
use Phalcon\Paginator\Adapter\QueryBuilder;
use Phalcon\Test\Models\Robos;
use Phalcon\Test\Models\Stock;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Paginator\Adapter\QueryBuilderTest
 * Tests the \Phalcon\Paginator\Adapter\QueryBuilder component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Paginator\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class QueryBuilderTest extends UnitTest
{
    use ModelTrait;

    /**
     * Tests query builder pagination with having and group
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-15
     */
    public function testIssue12111WithGroup()
    {
        $this->specify(
            "Query builder paginator adapter doesn't work correctly with having",
            function () {
                $modelsManager = $this->setUpModelsManager();
                $builder = $modelsManager->createBuilder()
                    ->columns("name, COUNT(*) as stock_count")
                    ->from(['Stock' => Stock::class])
                    ->groupBy('name')
                    ->having('SUM(Stock.stock) > 0');

                $paginate = (new QueryBuilder(
                    [
                        "builder" => $builder,
                        "limit"   => 1,
                        "page"    => 2
                    ]
                ))->getPaginate();

                expect($paginate->total_pages)->equals(2);
                expect($paginate->total_items)->equals(2);
            }
        );
    }

    /**
     * Tests query builder pagination with having not throwing exception when should
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-15
     * @expectedException \Phalcon\Paginator\Exception
     * @expectedExceptionMessage When having is set there should be columns option provided for which calculate row count
     */
    public function testIssue12111WithoutGroupException()
    {
        $this->specify(
            "Query builder paginator adapter doesn't throw exception when no columns option is set",
            function () {
                $modelsManager = $this->setUpModelsManager();
                $builder = $modelsManager->createBuilder()
                    ->columns("COUNT(*) as stock_count")
                    ->from(['Stock' => Stock::class])
                    ->having('SUM(Stock.stock) > 0');

                $paginate = (new QueryBuilder(
                    [
                        "builder" => $builder,
                        "limit"   => 1,
                        "page"    => 2
                    ]
                ))->getPaginate();
            }
        );
    }

    /**
     * Tests query builder pagination with having and without group
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-15
     */
    public function testIssue12111WithoutGroup()
    {
        $this->specify(
            "Query builder paginator adapter doesn't throw exception when no columns option is set",
            function () {
                $di = Di::getDefault();
                $db = $di->getShared('db');
                /*
                 * There is no clean way to rewrite query builder's query in the strict mode:
                 * if we remove all nonaggregated columns, we will get "Unknown column 'Stock.stock' in 'having clause'",
                 * otherwise "In aggregated query without GROUP BY, expression #1 of SELECT list contains nonaggregated column 'phalcon_test.Stock.stock'"
                 */
                $db->query("SET SESSION sql_mode='STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION'");

                $modelsManager = $this->setUpModelsManager();
                $builder = $modelsManager->createBuilder()
                    ->columns("*, COUNT(*) as stock_count")
                    ->from(['Stock' => Stock::class])
                    ->having('stock > 0');

                $paginate = (new QueryBuilder(
                    [
                        "builder" => $builder,
                        "limit"   => 1,
                        "page"    => 2,
                        "columns" => "id,stock"
                    ]
                ))->getPaginate();

                expect($paginate->total_pages)->equals(2);
                expect($paginate->total_items)->equals(2);
            }
        );
    }

    /**
     * Tests query builder pagination with having and group with a different db service than 'db'
     *
     * @author David Napierata
     * @since  2017-07-18
     */
    public function testIssue12957()
    {
        $this->specify(
            "Query builder paginator doesn't work correctly with a different db service",
            function () {
                $modelsManager = $this->setUpModelsManager();
                $di = $modelsManager->getDI();
                $di->set(
                    'dbTwo',
                    $di->get('db')
                );
                $builder = $modelsManager->createBuilder()
                    ->columns("COUNT(*) as robos_count")
                    ->from(['Robos' => Robos::class])
                    ->groupBy('type')
                    ->having('MAX(Robos.year) > 1970');

                $paginate = (new QueryBuilder(
                    [
                        "builder" => $builder,
                        "limit"   => 1,
                        "page"    => 2
                    ]
                ))->getPaginate();

                expect($paginate->total_pages)->equals(2);
                expect($paginate->total_items)->equals(2);
            }
        );
    }
}
