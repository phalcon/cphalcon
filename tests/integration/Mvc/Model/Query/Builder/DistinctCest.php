<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Query\Builder;

use IntegrationTester;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Snapshot\Robots;

class DistinctCest
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
     * Tests Phalcon\Mvc\Model\Query\Builder :: distinct
     */
    public function mvcModelQueryBuilderDistinct(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - distinct()');



        $builder = new Builder();

        $phql = $builder->setDi($this->container)
                        ->distinct(true)
                        ->columns(['Robots.name'])
                        ->from(Robots::class)
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT DISTINCT Robots.name FROM [' . Robots::class . ']',
            $phql
        );



        $builder = new Builder();

        $phql = $builder->setDi($this->container)
                        ->distinct(false)
                        ->columns(['Robots.name'])
                        ->from(Robots::class)
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT ALL Robots.name FROM [' . Robots::class . ']',
            $phql
        );



        $builder = new Builder();

        $phql = $builder->setDi($this->container)
                        ->distinct(true)
                        ->distinct(null)
                        ->columns(['Robots.name'])
                        ->from(Robots::class)
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT Robots.name FROM [' . Robots::class . ']',
            $phql
        );



        $builder = new Builder();

        $phql = $builder->setDi($this->container)
                        ->distinct(true)
                        ->from(Robots::class)
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT DISTINCT [' . Robots::class . '].* FROM [' . Robots::class . ']',
            $phql
        );
    }
}
