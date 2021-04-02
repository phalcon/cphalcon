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

namespace Phalcon\Test\Database\Mvc\Model\Criteria;

use DatabaseTester;
use Phalcon\Mvc\Model\Criteria;

class GetColumnsCest
{
    /**
     * Tests Phalcon\Mvc\Model\Criteria :: getColumns()
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
     */
    public function mvcModelCriteriaGetColumns(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - getColumns()');

        $criteria = new Criteria();
        $criteria
            ->columns('inv_id, inv_cst_id, inv_total');

        $expected = 'inv_id, inv_cst_id, inv_total';
        $actual   = $criteria->getColumns();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model\Criteria :: getColumns() - array
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
     */
    public function mvcModelCriteriaGetColumnsArray(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - getColumns() - array');

        $criteria = new Criteria();
        $criteria
            ->columns(
                [
                    'id'     => 'inv_id',
                    'cst_id' => 'inv_cst_id',
                    'total'  => 'inv_total',
                ]
            );

        $expected = [
            'id'     => 'inv_id',
            'cst_id' => 'inv_cst_id',
            'total'  => 'inv_total',
        ];
        $actual   = $criteria->getColumns();
        $I->assertEquals($expected, $actual);
    }
}
