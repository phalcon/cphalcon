<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Criteria;

use IntegrationTester;

class GetModelNameCest
{
    /**
     * Tests Phalcon\Mvc\Model\Criteria :: getModelName()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelCriteriaGetModelName(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model\Criteria - getModelName()");
        $I->skipTest("Need implementation");
    }
}
