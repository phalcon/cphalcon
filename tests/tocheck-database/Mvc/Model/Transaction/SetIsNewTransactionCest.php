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

namespace Phalcon\Tests\Integration\Mvc\Model\Transaction;

use IntegrationTester;

/**
 * Class SetIsNewTransactionCest
 */
class SetIsNewTransactionCest
{
    /**
     * Tests Phalcon\Mvc\Model\Transaction :: setIsNewTransaction()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelTransactionSetIsNewTransaction(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Transaction - setIsNewTransaction()');
        $I->skipTest('Need implementation');
    }
}
