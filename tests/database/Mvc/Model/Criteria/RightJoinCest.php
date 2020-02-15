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

namespace Phalcon\Test\Database\Mvc\Model\Criteria;

use DatabaseTester;
use Phalcon\Mvc\Model\Criteria;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Customers;
use Phalcon\Test\Models\Invoices;

/**
 * Class RightJoinCest
 */
class RightJoinCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: rightJoin()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     */
    public function mvcModelCriteriaRightJoin(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - rightJoin()');

        $criteria = new Criteria();
        $criteria->setDI($this->container);

        $criteria
            ->setModelName(Invoices::class)
            ->rightJoin(Customers::class, 'inv_cst_id = cst_id', 'customer')
        ;

        $builder = $criteria->createBuilder();

        $I->assertInstanceOf(Builder::class, $builder);

        $expected = 'SELECT [Phalcon\Test\Models\Invoices].* '
            . 'FROM [Phalcon\Test\Models\Invoices] '
            . 'RIGHT JOIN [Phalcon\Test\Models\Customers] AS [customer] ON inv_cst_id = cst_id';
        $actual   = $builder->getPhql();
        $I->assertEquals($expected, $actual);
    }
}
