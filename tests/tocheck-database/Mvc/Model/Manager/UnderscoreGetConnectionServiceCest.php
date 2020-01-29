<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Manager;

use IntegrationTester;

class UnderscoreGetConnectionServiceCest
{
    /**
     * Tests Phalcon\Mvc\Model\Manager :: _getConnectionService()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelManagerUnderscoreGetConnectionService(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model\Manager - _getConnectionService()");
        $I->skipTest('Need implementation');
    }
}
