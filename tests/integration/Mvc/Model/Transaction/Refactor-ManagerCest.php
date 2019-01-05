<?php

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
use Phalcon\Mvc\Model\Transaction;
use Phalcon\Mvc\Model\Transaction\Failed;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Personas;
use Phalcon\Test\Models\Select;

class ManagerCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests Manager::get
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-08-07
     */
    public function checkTransactionMysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $this->testGetNewExistingTransactionOnce($I);
        $this->testRollbackNewInserts($I);
        $this->testCommitNewInserts($I);
        $this->testTransactionRemovedOnCommit($I);
        $this->testTransactionRemovedOnRollback($I);
    }

    private function testGetNewExistingTransactionOnce(IntegrationTester $I)
    {
        $tm          = $this->container->getShared('transactionManager');
        $db          = $this->container->getShared('db');
        $transaction = $tm->get();

        $I->assertInstanceOf(Transaction::class, $transaction);
        $I->assertSame($transaction, $tm->get(true));
        $I->assertSame($transaction, $tm->get(false));

        $I->assertInstanceOf('Phalcon\Db\AdapterInterface', $transaction->getConnection());
        /**
         * @todo - Check why this returns different Ids in db and TM
         */
//        $I->assertEquals($db->getConnectionId(), $transaction->getConnection()->getConnectionId());
    }

    private function testRollbackNewInserts(IntegrationTester $I)
    {
        $tm = $this->container->getShared('transactionManager');

        $numPersonas = Personas::count();
        $transaction = $tm->get();

        for ($i = 0; $i < 10; $i++) {
            $persona = new Personas();
            $persona->setTransaction($transaction);
            $persona->cedula            = 'T-Cx' . $i;
            $persona->tipo_documento_id = 1;
            $persona->nombres           = 'LOST LOST';
            $persona->telefono          = '2';
            $persona->cupo              = 0;
            $persona->estado            = 'A';

            $I->assertTrue($persona->save());
        }

        try {
            $transaction->rollback();
            $I->assertTrue(
                false,
                "The transaction's rollback didn't throw an expected exception. Emergency stop"
            );
        } catch (Failed $e) {
            $I->assertEquals($e->getMessage(), "Transaction aborted");
        }

        $I->assertEquals($numPersonas, Personas::count());
    }

    private function testCommitNewInserts(IntegrationTester $I)
    {
        $tm = $this->container->getShared('transactionManager');
        $db = $this->container->getShared('db');

        $db->delete("personas", "cedula LIKE 'T-Cx%'");

        $numPersonas = Personas::count();
        $transaction = $tm->get();

        for ($i = 0; $i < 10; $i++) {
            $persona = new Personas();
            $persona->setDI($this->container);
            $persona->setTransaction($transaction);
            $persona->cedula            = 'T-Cx' . $i;
            $persona->tipo_documento_id = 1;
            $persona->nombres           = 'LOST LOST';
            $persona->telefono          = '2';
            $persona->cupo              = 0;
            $persona->estado            = 'A';

            $I->assertNotFalse($persona->save());
        }

        $I->assertTrue($transaction->commit());
        $I->assertEquals($numPersonas + 10, Personas::count());
    }

    private function testTransactionRemovedOnCommit(IntegrationTester $I)
    {
        $tm          = $this->container->getShared('transactionManager');
        $transaction = $tm->get();

        $select = new Select();
        $select->setTransaction($transaction);
        $select->assign(['name' => 'Crack of Dawn']);
        $select->create();

        $I->assertEquals(1, $I->getProtectedProperty($tm, '_number'));
        $I->assertCount(1, $I->getProtectedProperty($tm, '_transactions'));

        $transaction->commit();

        $I->assertEquals(0, $I->getProtectedProperty($tm, '_number'));
        $I->assertCount(0, $I->getProtectedProperty($tm, '_transactions'));
    }

    private function testTransactionRemovedOnRollback(IntegrationTester $I)
    {
        $tm          = $this->container->getShared('transactionManager');
        $transaction = $tm->get();

        $select = new Select();
        $select->setTransaction($transaction);
        $select->assign(['name' => 'Crack of Dawn']);
        $select->create();


        $I->assertEquals(1, $I->getProtectedProperty($tm, '_number'));
        $I->assertCount(1, $I->getProtectedProperty($tm, '_transactions'));

        try {
            $transaction->rollback();
        } catch (Failed $e) {
            // do nothing
        }

        $I->assertEquals(0, $I->getProtectedProperty($tm, '_number'));
        $I->assertCount(0, $I->getProtectedProperty($tm, '_transactions'));
    }

    /**
     * Tests Manager::get
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-08-07
     */
    public function checkTransactionPostgresql(IntegrationTester $I)
    {
        $this->setDiPostgresql();

        $this->testGetNewExistingTransactionOnce($I);
        $this->testRollbackNewInserts($I);
        $this->testCommitNewInserts($I);
        $this->testTransactionRemovedOnCommit($I);
        $this->testTransactionRemovedOnRollback($I);
    }

    /**
     * Tests Manager::get
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2012-08-07
     */
    public function checkTransactionSqlite(IntegrationTester $I)
    {
        $I->skipTest('TODO - Check Sqlite locking');
        $this->setDiSqlite();

        $this->testGetNewExistingTransactionOnce($I);
        $this->testRollbackNewInserts($I);
        $this->testCommitNewInserts($I);
        $this->testTransactionRemovedOnCommit($I);
        $this->testTransactionRemovedOnRollback($I);
    }
}
