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

namespace Phalcon\Tests\Integration\Mvc\Model\Query;

use IntegrationTester;
use Phalcon\Mvc\Model\Query;
use Phalcon\Mvc\Model\Transaction;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class GetSetTransactionCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiSqlite();
    }

    /**
     * Tests Phalcon\Mvc\Model\Query :: getTransaction() / getTransaction()
     */
    public function mvcModelQueryGetSetTransaction(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query - getTransaction() / getTransaction()');

        $transaction = new Transaction($this->container);
        $query       = new Query(null, $this->container);

        $query->setTransaction($transaction);

        $I->assertSame(
            $transaction,
            $query->getTransaction()
        );
    }
}
