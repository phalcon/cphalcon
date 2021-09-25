<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Integration\Mvc\Model\Transaction;

use IntegrationTester;
use Phalcon\Mvc\Model\Transaction\Failed;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Personas;
use Phalcon\Tests\Models\Select;

class ManagerCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Manager::get
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-08-07
     */
    public function checkTransactionMysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $this->testCommitNewInserts($I);
        $this->testTransactionRemovedOnCommit($I);
        $this->testTransactionRemovedOnRollback($I);
    }

    /**
     * Tests Manager::get
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-08-07
     */
    public function checkTransactionPostgresql(IntegrationTester $I)
    {
        $this->setDiPostgresql();

        $this->testCommitNewInserts($I);
        $this->testTransactionRemovedOnCommit($I);
        $this->testTransactionRemovedOnRollback($I);
    }

    /**
     * Tests Manager::get
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2012-08-07
     */
    public function checkTransactionSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();

        $I->skipTest('TODO - Check Sqlite locking');

        $this->testCommitNewInserts($I);
        $this->testTransactionRemovedOnCommit($I);
        $this->testTransactionRemovedOnRollback($I);
    }

    private function testCommitNewInserts(IntegrationTester $I)
    {
        $tm = $this->container->getShared('transactionManager');
        $db = $this->container->getShared('db');

        $db->delete('personas', "cedula LIKE 'T-Cx%'");

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

            $I->assertNotFalse(
                $persona->save()
            );
        }

        $I->assertTrue(
            $transaction->commit()
        );

        $I->assertEquals(
            $numPersonas + 10,
            Personas::count()
        );
    }

    private function testTransactionRemovedOnCommit(IntegrationTester $I)
    {
        $tm = $this->container->getShared('transactionManager');

        $transaction = $tm->get();

        $select = new Select();

        $select->setTransaction($transaction);

        $select->assign(
            [
                'name' => 'Crack of Dawn',
            ]
        );

        $select->create();

        $I->assertEquals(
            1,
            $I->getProtectedProperty($tm, 'number')
        );

        $I->assertCount(
            1,
            $I->getProtectedProperty($tm, 'transactions')
        );

        $transaction->commit();

        $I->assertEquals(
            0,
            $I->getProtectedProperty($tm, 'number')
        );

        $I->assertCount(
            0,
            $I->getProtectedProperty($tm, 'transactions')
        );
    }

    private function testTransactionRemovedOnRollback(IntegrationTester $I)
    {
        $tm = $this->container->getShared('transactionManager');

        $transaction = $tm->get();

        $select = new Select();

        $select->setTransaction($transaction);

        $select->assign(
            [
                'name' => 'Crack of Dawn',
            ]
        );

        $select->create();


        $I->assertEquals(
            1,
            $I->getProtectedProperty($tm, 'number')
        );

        $I->assertCount(
            1,
            $I->getProtectedProperty($tm, 'transactions')
        );

        try {
            $transaction->rollback();
        } catch (Failed $e) {
            // do nothing
        }

        $I->assertEquals(
            0,
            $I->getProtectedProperty($tm, 'number')
        );

        $I->assertCount(
            0,
            $I->getProtectedProperty($tm, 'transactions')
        );
    }
}
