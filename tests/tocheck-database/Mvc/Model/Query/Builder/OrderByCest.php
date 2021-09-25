<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Mvc\Model\Query\Builder;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Robots;

class OrderByCest
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
     * Tests Builder::orderBy to create correct PHQL query
     *
     * @test
     * @author       Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since        2017-11-03
     *
     * @dataProvider shouldGenerateCorrectPhqlProvider
     */
    public function shouldGenerateCorrectPhql(IntegrationTester $I, Example $example)
    {
        $orderBy  = $example[0];
        $expected = $example[1];

        $builder = new Builder();
        $builder->setDi($this->container);

        $query = 'SELECT r.year, r.name AS robot_name FROM [' . Robots::class . '] AS [r] ';

        $phql = $builder
            ->from(['r' => Robots::class])
            ->columns(['r.year', 'r.name AS robot_name'])
            ->orderBy($orderBy)
            ->getPhql()
        ;

        $I->assertEquals(
            $query . $expected,
            $phql
        );
    }

    /**
     * Tests Builder::orderBy to create correct SQL query
     *
     * @author       Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since        2017-11-03
     *
     * @dataProvider shouldGenerateCorrectSqlProvider
     */
    public function shouldGenerateCorrectSql(IntegrationTester $I, Example $example)
    {
        $orderBy  = $example[0];
        $expected = $example[1];

        $builder = new Builder();
        $builder->setDi($this->container);

        $query = 'SELECT `r`.`year` AS `r_year`, `r`.`name` AS `robot_name` FROM `robots` AS `r` ';

        $phql = $builder
            ->from(['r' => Robots::class])
            ->columns(['r.year', 'r.name AS robot_name'])
            ->orderBy($orderBy)
            ->getQuery()
        ;

        $phql = $phql->getSql();

        $I->assertEquals(
            $query . $expected,
            $phql['sql']
        );
    }

    private function shouldGenerateCorrectPhqlProvider(): array
    {
        return [
            [
                'robot_name DESC',
                'ORDER BY robot_name DESC',
            ],
            [
                'r.name DESC',
                'ORDER BY r.name DESC',
            ],
            [
                ['r.name DESC'],
                'ORDER BY r.name DESC',
            ],
            [
                ['robot_name DESC'],
                'ORDER BY [robot_name] DESC',
            ],
            [
                ['robot_name DESC', 'r.name DESC'],
                'ORDER BY [robot_name] DESC, r.name DESC',
            ],
            [
                [1, 'r.name DESC'],
                'ORDER BY 1, r.name DESC',
            ],
        ];
    }

    private function shouldGenerateCorrectSqlProvider(): array
    {
        return [
            [
                'robot_name DESC',
                'ORDER BY `robot_name` DESC',
            ],
            [
                'r.name DESC',
                'ORDER BY `r`.`name` DESC',
            ],
            [
                ['r.name DESC'],
                'ORDER BY `r`.`name` DESC',
            ],
            [
                ['robot_name DESC'],
                'ORDER BY `robot_name` DESC',
            ],
            [
                ['robot_name DESC', 'r.name DESC'],
                'ORDER BY `robot_name` DESC, `r`.`name` DESC',
            ],
            [
                [1, 'r.name DESC'],
                'ORDER BY 1, `r`.`name` DESC',
            ],
        ];
    }
}
