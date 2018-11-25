<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Model\Relation;

use UnitTester;

class GetIntermediateModelCest
{
    /**
     * Tests Phalcon\Mvc\Model\Relation :: getIntermediateModel()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelRelationGetIntermediateModel(UnitTester $I)
    {
        $I->wantToTest("Mvc\Model\Relation - getIntermediateModel()");
        $I->skipTest("Need implementation");
    }
}
