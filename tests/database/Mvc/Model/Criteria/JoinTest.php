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

use Phalcon\Mvc\Model\Criteria;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\Orders;
use Phalcon\Tests\Support\Models\Products;
use Phalcon\Tests\Support\Traits\DiTrait;

final class JoinTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * @throws Exception
     */
    public function setUp(): void
    {
        $this->setNewFactoryDefault();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     */
    public function testMvcModelCriteriaJoin(): void
    {
        $criteria = new Criteria();
        $criteria->setDI($this->container);

        $criteria
            ->setModelName(Invoices::class)
            ->join(Customers::class, 'inv_cst_id = cst_id', 'customer')
        ;

        $builder = $criteria->createBuilder();

        $this->assertInstanceOf(Builder::class, $builder);

        $expected = 'SELECT [Phalcon\Tests\Support\Models\Invoices].* '
            . 'FROM [Phalcon\Tests\Support\Models\Invoices] '
            . 'JOIN [Phalcon\Tests\Support\Models\Customers] AS [customer] ON inv_cst_id = cst_id';
        $actual   = $builder->getPhql();
        $this->assertEquals($expected, $actual);
    }

    /**
     * @issue  14716
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-06
     *
     * @group mysql
     * @group pgsql
     */
    public function testMvcModelCriteriaJoinManyToManyMultipleSchema(): void
    {
        $this->markTestSkipped('TODO: Check the schemas');
        $this->setDatabase();

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

        $this->assertStringContainsString($expected, $request['sql']);

        $this->assertInstanceOf(Simple::class, $query->execute());
    }
}
