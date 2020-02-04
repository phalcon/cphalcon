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
 * Class DistinctCest
 */
class DistinctCest
{
    /**
     * Tests Phalcon\Mvc\Model\Criteria :: distinct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     */
    public function mvcModelCriteriaDistinct(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - distinct()');

        $criteria = new Criteria();

        $expected = [];
        $actual   = $criteria->getParams();
        $I->assertEquals($expected, $actual);

        $criteria->distinct('inv_cst_id');

        $expected = [
            'distinct' => 'inv_cst_id',
        ];
        $actual   = $criteria->getParams();
        $I->assertEquals($expected, $actual);
    }
}
