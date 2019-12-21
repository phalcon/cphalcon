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

namespace Phalcon\Test\Integration\Mvc\Model\Transaction\Manager;

use IntegrationTester;

/**
 * Class NotifyRollbackCest
 */
class NotifyRollbackCest
{
    /**
     * Tests Phalcon\Mvc\Model\Transaction\Manager :: notifyRollback()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelTransactionManagerNotifyRollback(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Transaction\Manager - notifyRollback()');
        $I->skipTest('Need implementation');
    }
}
