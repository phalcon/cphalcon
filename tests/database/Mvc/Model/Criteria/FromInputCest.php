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
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Invoices;

/**
 * Class FromInputCest
 */
class FromInputCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: fromInput()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-05
     *
     * @group mysql
     */
    public function mvcModelCriteriaFromInputMysql(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - fromInput()');

        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        $criteria = Criteria::fromInput(
            $this->container,
            Invoices::class,
            [
                'inv_id'          => 1,
                'inv_cst_id'      => 2,
                'inv_status_flag' => 3,
                'inv_title'       => 'title',
                'inv_total'       => 100.10,
                'inv_created_at'  => '2020-12-25 01:02:03',
            ]
        );

        $builder = $criteria->createBuilder();
        $expected = 'SELECT [Phalcon\Test\Models\Invoices].* '
            . 'FROM [Phalcon\Test\Models\Invoices] '
            . 'WHERE [inv_id] = :inv_id: '
            . 'AND [inv_cst_id] = :inv_cst_id: '
            . 'AND [inv_status_flag] = :inv_status_flag: '
            . 'AND [inv_title] LIKE :inv_title: '
            . 'AND [inv_total] = :inv_total: '
            . 'AND [inv_created_at] = :inv_created_at:';
        $actual   = $builder->getPhql();
        $I->assertEquals($expected, $actual);

        $expected = [
            'inv_id'          => 1,
            'inv_cst_id'      => 2,
            'inv_status_flag' => 3,
            'inv_title'       => '%title%',
            'inv_total'       => 100.10,
            'inv_created_at'  => '2020-12-25 01:02:03',
        ];
        $actual   = $builder->getBindParams();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: fromInput()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-05
     *
     * @group sqlite
     */
    public function mvcModelCriteriaFromInputSqlite(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - fromInput()');

        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        $criteria = Criteria::fromInput(
            $this->container,
            Invoices::class,
            [
                'inv_id'          => 1,
                'inv_cst_id'      => 2,
                'inv_status_flag' => 3,
                'inv_title'       => 'title',
                'inv_total'       => 100.10,
                'inv_created_at'  => '2020-12-25 01:02:03',
            ]
        );

        $builder = $criteria->createBuilder();
        $expected = 'SELECT [Phalcon\Test\Models\Invoices].* '
            . 'FROM [Phalcon\Test\Models\Invoices] '
            . 'WHERE [inv_id] = :inv_id: '
            . 'AND [inv_cst_id] = :inv_cst_id: '
            . 'AND [inv_status_flag] = :inv_status_flag: '
            . 'AND [inv_title] = :inv_title: '
            . 'AND [inv_total] LIKE :inv_total: '
            . 'AND [inv_created_at] = :inv_created_at:';
        $actual   = $builder->getPhql();
        $I->assertEquals($expected, $actual);

        $expected = [
            'inv_id'          => 1,
            'inv_cst_id'      => 2,
            'inv_status_flag' => 3,
            'inv_title'       => 'title',
            'inv_total'       => '%100.1%',
            'inv_created_at'  => '2020-12-25 01:02:03',
        ];
        $actual   = $builder->getBindParams();
        $I->assertEquals($expected, $actual);
    }
}
