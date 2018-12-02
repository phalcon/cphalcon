<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;

class GetModelsMetaDataCest
{
    /**
     * Tests Phalcon\Mvc\Model :: getModelsMetaData()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelGetModelsMetaData(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model - getModelsMetaData()");
        $I->skipTest("Need implementation");
    }
}
