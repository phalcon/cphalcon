<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Transaction\Manager;

use IntegrationTester;

class NotifyCommitCest
{
    /**
     * Tests Phalcon\Mvc\Model\Transaction\Manager :: notifyCommit()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelTransactionManagerNotifyCommit(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model\Transaction\Manager - notifyCommit()");
        $I->skipTest("Need implementation");
    }
}
