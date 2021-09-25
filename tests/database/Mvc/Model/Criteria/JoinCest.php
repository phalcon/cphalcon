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

namespace Phalcon\Tests\Database\Mvc\Model\Criteria;

use DatabaseTester;
use Phalcon\Mvc\Model\Criteria;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Storage\Exception;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Customers;
use Phalcon\Tests\Models\Invoices;
use Phalcon\Tests\Models\Orders;
use Phalcon\Tests\Models\Products;

/**
 * Class JoinCest
 */
class JoinCest
{
    use DiTrait;

    /**
     * @param DatabaseTester $I
     *
     * @throws Exception
     */
    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: join()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
     */
    public function mvcModelCriteriaJoin(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - join()');

        $criteria = new Criteria();
        $criteria->setDI($this->container);

        $criteria
            ->setModelName(Invoices::class)
            ->join(Customers::class, 'inv_cst_id = cst_id', 'customer')
        ;

        $builder = $criteria->createBuilder();

        $I->assertInstanceOf(Builder::class, $builder);

        $expected = 'SELECT [Phalcon\Tests\Models\Invoices].* '
            . 'FROM [Phalcon\Tests\Models\Invoices] '
            . 'JOIN [Phalcon\Tests\Models\Customers] AS [customer] ON inv_cst_id = cst_id';
        $actual   = $builder->getPhql();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: join() and use ManyToMany with
     * Multiple schemas
     *
     * @issue  14716
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-06
     *
     * @group  mysql
     * @group  pgsql
     */
    public function mvcModelCriteriaJoinManyToManyMultipleSchema(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - join() and use ManyToMany with Multiple schemas');

        $this->setDatabase($I);

        /**
         * The following test needs to skip sqlite because I think
         * we can't create multiple schemas with sqlite
         */
        $criteria = new Criteria();
        $criteria->setDI($this->container);

        $builder = $criteria->createBuilder();
        $builder->from(Orders::class);
        $builder->join(Products::class);

        $expected = 'private';
        $query    = $builder->getQuery();
        $request  = $query->getSql();

        $I->assertContains($expected, $request['sql']);

        $I->assertInstanceOf(Simple::class, $query->execute());
    }
}
