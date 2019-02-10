<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Model\Transaction\Manager;

use UnitTester;

/**
 * Class NotifyCommitCest
 */
class NotifyCommitCest
{
    /**
     * Tests Phalcon\Mvc\Model\Transaction\Manager :: notifyCommit()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcModelTransactionManagerNotifyCommit(UnitTester $I)
    {
        $I->wantToTest('Mvc\Model\Transaction\Manager - notifyCommit()');
        $I->skipTest('Need implementation');
    }
}
