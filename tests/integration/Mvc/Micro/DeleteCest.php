<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Micro;

use IntegrationTester;

class DeleteCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: delete()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcMicroDelete(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Micro - delete()");
        $I->skipTest("Need implementation");
    }
}
