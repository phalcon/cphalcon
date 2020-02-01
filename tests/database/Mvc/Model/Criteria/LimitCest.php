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
use Phalcon\Test\Models\Invoices;

/**
 * Class LimitCest
 */
class LimitCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: limit()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelCriteriaLimit(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - limit()');

        $criteria = new Criteria();
        $criteria->setDI($this->container);

        $criteria
            ->setModelName(Invoices::class)
            ->limit(10)
        ;

        $builder = $criteria->createBuilder();

        $I->assertInstanceOf(Builder::class, $builder);

        $expected = 'SELECT [Phalcon\Test\Models\Invoices].* '
            . 'FROM [Phalcon\Test\Models\Invoices] '
            . 'LIMIT :APL0:';
        $actual   = $builder->getPhql();
        $I->assertEquals($expected, $actual);

        $expected = [
            'number' => 10,
            'offset' => 0,
        ];
        $actual   = $criteria->getLimit();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: limit() - offset
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelCriteriaLimitOffset(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - limit() - offset');

        $criteria = new Criteria();
        $criteria->setDI($this->container);

        $criteria
            ->setModelName(Invoices::class)
            ->limit(10, 15)
        ;

        $builder = $criteria->createBuilder();

        $I->assertInstanceOf(Builder::class, $builder);

        $expected = 'SELECT [Phalcon\Test\Models\Invoices].* '
            . 'FROM [Phalcon\Test\Models\Invoices] '
            . 'LIMIT :APL0: OFFSET :APL1:';
        $actual   = $builder->getPhql();
        $I->assertEquals($expected, $actual);

        $expected = [
            'number' => 10,
            'offset' => 15,
        ];
        $actual   = $criteria->getLimit();
        $I->assertEquals($expected, $actual);
    }
}
