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
use Phalcon\Db\Adapter\AdapterInterface;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class GetConnectionCest
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
     * Tests Phalcon\Mvc\Model\Transaction :: getConnection()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-08-07
     */
    public function mvcModelTransactionGetConnection(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Transaction - getConnection()');

        $tm = $this->container->getShared('transactionManager');
        $db = $this->container->getShared('db');

        $transaction = $tm->get();

        $I->assertInstanceOf(
            AdapterInterface::class,
            $transaction->getConnection()
        );
    }
}
