<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\Criteria;

use DatabaseTester;
use Phalcon\Mvc\Model\Criteria;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Storage\Exception;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Invoices;

class LimitCest
{
    use DiTrait;

    /**
     * Executed before each test
     *
     * @param  DatabaseTester $I
     * @return void
     */
    public function _before(DatabaseTester $I): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $I->fail($e->getMessage());
        }
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: limit() - null
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-05-04
     *
     * @group  common
     */
    public function mvcModelCriteriaNoLimit(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - limit() - null');

        $criteria = new Criteria();
        $criteria->setDI($this->container);
        $criteria->setModelName(Invoices::class);

        $builder = $criteria->createBuilder();

        $I->assertInstanceOf(Builder::class, $builder);

        $expected = 'SELECT [Phalcon\Tests\Models\Invoices].* '
            . 'FROM [Phalcon\Tests\Models\Invoices]';

        $I->assertEquals($expected, $builder->getPhql());
        $I->assertEquals(null, $criteria->getLimit());
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: limit()
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
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

        $expected = 'SELECT [Phalcon\Tests\Models\Invoices].* '
            . 'FROM [Phalcon\Tests\Models\Invoices] '
            . 'LIMIT :APL0:';

        $I->assertEquals($expected, $builder->getPhql());
        $I->assertEquals(10, $criteria->getLimit());
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: limit() - offset
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
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

        $expected = 'SELECT [Phalcon\Tests\Models\Invoices].* '
            . 'FROM [Phalcon\Tests\Models\Invoices] '
            . 'LIMIT :APL0: OFFSET :APL1:';

        $I->assertEquals($expected, $builder->getPhql());

        $expected = [
            'number' => 10,
            'offset' => 15,
        ];

        $I->assertEquals($expected, $criteria->getLimit());
    }
}
