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
use Phalcon\Test\Models\Invoices;

/**
 * Class GetModelNameCest
 */
class GetModelNameCest
{
    /**
     * Tests Phalcon\Mvc\Model\Criteria :: getModelName()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
     */
    public function mvcModelCriteriaGetModelName(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Criteria - getModelName()');

        $criteria = new Criteria();

        $criteria->setModelName(Invoices::class);

        $expected = Invoices::class;
        $actual   = $criteria->getModelName();
        $I->assertEquals($expected, $actual);
    }
}
