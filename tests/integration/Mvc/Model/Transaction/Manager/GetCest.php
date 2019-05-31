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

namespace Phalcon\Test\Integration\Mvc\Model\Transaction\Manager;

use IntegrationTester;
use Phalcon\Mvc\Model\Transaction;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests Phalcon\Mvc\Model\Transaction\Manager :: get() with MySQL
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-08-07
     */
    public function mvcModelTransactionManagerGetMysql(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Transaction\Manager - get() with MySQL');

        $this->setDiMysql();

        $this->testGetNewExistingTransactionOnce($I);
    }

    /**
     * Tests Phalcon\Mvc\Model\Transaction\Manager :: get() with Postgresql
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-08-07
     */
    public function mvcModelTransactionManagerGetPostgresql(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Transaction\Manager - get() with Postgresql');

        $this->setDiPostgresql();

        $this->testGetNewExistingTransactionOnce($I);
    }

    /**
     * Tests Phalcon\Mvc\Model\Transaction\Manager :: get() with Sqlite
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-08-07
     */
    public function mvcModelTransactionManagerGetSqlite(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Transaction\Manager - get() with Sqlite');

        $this->setDiSqlite();

        $this->testGetNewExistingTransactionOnce($I);
    }

    private function testGetNewExistingTransactionOnce(IntegrationTester $I)
    {
        $tm = $this->container->getShared('transactionManager');
        $db = $this->container->getShared('db');

        $transaction = $tm->get();

        $I->assertInstanceOf(
            Transaction::class,
            $transaction
        );

        $I->assertSame(
            $transaction,
            $tm->get(true)
        );

        $I->assertSame(
            $transaction,
            $tm->get(false)
        );

        $I->assertEquals(
            $db->getConnectionId(),
            $transaction->getConnection()->getConnectionId()
        );
    }
}
