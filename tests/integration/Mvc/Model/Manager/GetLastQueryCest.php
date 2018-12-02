<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Manager;

use IntegrationTester;

class GetLastQueryCest
{
    /**
     * Tests Phalcon\Mvc\Model\Manager :: getLastQuery()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelManagerGetLastQuery(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model\Manager - getLastQuery()");
        $I->skipTest("Need implementation");
    }
}
