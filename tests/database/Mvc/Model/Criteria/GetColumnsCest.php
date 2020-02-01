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

/**
 * Class GetColumnsCest
 */
class GetColumnsCest
{
    /**
     * Tests Phalcon\Mvc\Model\Criteria :: getColumns()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
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
