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
 * Class ForUpdateCest
 */
class ForUpdateCest
{
    /**
     * Tests Phalcon\Mvc\Model\Criteria :: forUpdate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
     */
    public function mvcModelCriteriaForUpdate(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - forUpdate()');

        $criteria = new Criteria();

        $expected = [];
        $actual   = $criteria->getParams();
        $I->assertEquals($expected, $actual);

        $criteria->forUpdate(true);

        $expected = [
            'for_update' => true,
        ];
        $actual   = $criteria->getParams();
        $I->assertEquals($expected, $actual);
    }
}
