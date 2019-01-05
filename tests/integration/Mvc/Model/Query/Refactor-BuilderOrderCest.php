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
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;

class BuilderOrderCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    /**
     * Tests Builder::orderBy to create correct PHQL query
     *
     * @test
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-11-03
     */
    public function shouldGenerateCorrectPhql(IntegrationTester $I)
    {
        $examples = [
            ['robot_name DESC', 'ORDER BY robot_name DESC'],
            ['r.name DESC', 'ORDER BY r.name DESC'],
            [['r.name DESC'], 'ORDER BY r.name DESC'],
            [['robot_name DESC'], 'ORDER BY [robot_name] DESC'],
            [['robot_name DESC', 'r.name DESC'], 'ORDER BY [robot_name] DESC, r.name DESC'],
            [[1, 'r.name DESC'], 'ORDER BY 1, r.name DESC'],
        ];
        foreach ($examples as $item) {
            $orderBy  = $item[0];
            $expected = $item[1];
            $builder  = new Builder();
            $query    = "SELECT r.year, r.name AS robot_name FROM [" . Robots::class . "] AS [r] ";

            $phql = $builder
                ->setDi($this->container)
                ->from(['r' => Robots::class])
                ->columns(['r.year', 'r.name AS robot_name'])
                ->orderBy($orderBy)
                ->getPhql()
            ;

            $I->assertEquals($query . $expected, $phql);
        }
    }

    /**
     * Tests Builder::orderBy to create correct SQL query
     *
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-11-03
     */
    public function shouldGenerateCorrectSql(IntegrationTester $I)
    {
        $examples = [
            ['robot_name DESC', 'ORDER BY `robot_name` DESC'],
            ['r.name DESC', 'ORDER BY `r`.`name` DESC'],
            [['r.name DESC'], 'ORDER BY `r`.`name` DESC'],
            [['robot_name DESC'], 'ORDER BY `robot_name` DESC'],
            [['robot_name DESC', 'r.name DESC'], 'ORDER BY `robot_name` DESC, `r`.`name` DESC'],
            [[1, 'r.name DESC'], 'ORDER BY 1, `r`.`name` DESC'],
        ];
        foreach ($examples as $item) {
            $orderBy  = $item[0];
            $expected = $item[1];
            $builder  = new Builder();
            $query    = "SELECT `r`.`year` AS `r_year`, `r`.`name` AS `robot_name` FROM `robots` AS `r` ";

            $phql = $builder
                ->setDi($this->container)
                ->from(['r' => Robots::class])
                ->columns(['r.year', 'r.name AS robot_name'])
                ->orderBy($orderBy)
                ->getQuery()
            ;
            $phql = $phql->getSql();
            $I->assertEquals($query . $expected, $phql['sql']);
        }
    }
}
