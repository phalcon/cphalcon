<?php

/**
 * \Phalcon\Test\Unit\Mvc\Model\Query\BuilderTest
 * Tests the Phalcon\Mvc\Model\Query\Builder component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc\Model\Query
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Test\Unit\Mvc\Model\Query;

use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Models\Robots;

class BuilderOrderTest extends UnitTest
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
     * Tests Builder::orderBy to create correct PHQL query
     *
     * @test
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-11-03
     */
    public function shouldGenerateCorrectPhql()
    {
        $this->specify(
            "Query Builders don't build the expected PHQL queries",
            function ($orderBy, $expected) {
                $di = $this->di;
                $builder = new Builder();
                $query = "SELECT r.year, r.name AS robot_name FROM [" . Robots::class . "] AS [r] ";

                $phql = $builder->setDi($di)
                    ->from(['r' => Robots::class])
                    ->columns(['r.year', 'r.name AS robot_name'])
                    ->orderBy($orderBy)
                    ->getPhql();
                expect($phql)->equals($query . $expected);
            },
            [
                'examples' => [
                    ['robot_name DESC', 'ORDER BY robot_name DESC'],
                    ['r.name DESC', 'ORDER BY r.name DESC'],
                    [['r.name DESC'], 'ORDER BY r.name DESC'],
                    [['robot_name DESC'], 'ORDER BY [robot_name] DESC'],
                    [['robot_name DESC', 'r.name DESC'], 'ORDER BY [robot_name] DESC, r.name DESC'],
                    [[1, 'r.name DESC'], 'ORDER BY 1, r.name DESC'],
                ]
            ]
        );
    }

    /**
     * Tests Builder::orderBy to create correct SQL query
     *
     * @test
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-11-03
     */
    public function shouldGenerateCorrectSql()
    {
        $this->specify(
            "Query Builders don't build the expected SQL queries",
            function ($orderBy, $expected) {
                $di = $this->di;
                $builder = new Builder();
                $query = "SELECT `r`.`year` AS `year`, `r`.`name` AS `robot_name` FROM `robots` AS `r` ";

                $phql = $builder->setDi($di)
                    ->from(['r' => Robots::class])
                    ->columns(['r.year', 'r.name AS robot_name'])
                    ->orderBy($orderBy)
                    ->getQuery();
                expect($phql->getSql()['sql'])->equals($query . $expected);
            },
            [
                'examples' => [
                    ['robot_name DESC', 'ORDER BY `robot_name` DESC'],
                    ['r.name DESC', 'ORDER BY `r`.`name` DESC'],
                    [['r.name DESC'], 'ORDER BY `r`.`name` DESC'],
                    [['robot_name DESC'], 'ORDER BY `robot_name` DESC'],
                    [['robot_name DESC', 'r.name DESC'], 'ORDER BY `robot_name` DESC, `r`.`name` DESC'],
                    [[1, 'r.name DESC'], 'ORDER BY 1, `r`.`name` DESC'],
                ]
            ]
        );
    }
}
