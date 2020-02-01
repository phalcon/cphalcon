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
 * Class JoinCest
 */
class JoinCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: join()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
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

        $expected = 'SELECT [Phalcon\Test\Models\Invoices].* '
            . 'FROM [Phalcon\Test\Models\Invoices] '
            . 'JOIN [Phalcon\Test\Models\Customers] AS [customer] ON inv_cst_id = cst_id';
        $actual   = $builder->getPhql();
        $I->assertEquals($expected, $actual);
    }
}
