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

namespace Phalcon\Test\Integration\Mvc\Model\Transaction;

use IntegrationTester;
use Phalcon\Db\AdapterInterface;
use Phalcon\Test\Fixtures\Traits\DiTrait;

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
     * @author Phalcon Team <team@phalconphp.com>
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
