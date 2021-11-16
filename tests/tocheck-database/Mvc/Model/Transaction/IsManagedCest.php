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
use Phalcon\Mvc\Model\Transaction;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class IsManagedCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model\Transaction :: isManaged()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     */
    public function mvcModelTransactionIsManaged(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Transaction - isManaged()');

        $transaction = new Transaction(
            $this->container
        );

        $I->assertFalse(
            $transaction->isManaged()
        );

        $transactionManager = $this->container->getShared('transactionManager');

        $transaction->setTransactionManager($transactionManager);

        $I->assertTrue(
            $transaction->isManaged()
        );
    }
}
