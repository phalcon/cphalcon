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

namespace Phalcon\Tests\Integration\Mvc\Model\Transaction\Manager;

use IntegrationTester;

/**
 * Class GetOrCreateTransactionCest
 */
class GetOrCreateTransactionCest
{
    /**
     * Tests Phalcon\Mvc\Model\Transaction\Manager :: getOrCreateTransaction()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelTransactionManagerGetOrCreateTransaction(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Transaction\Manager - getOrCreateTransaction()');
        $I->skipTest('Need implementation');
    }
}
