<?php

namespace Phalcon\Test\Unit\Mvc\Model\Transaction;

use Phalcon\Di;
use Helper\ModelTrait;
use Phalcon\Test\Models\Select;
use Phalcon\Test\Models\Personas;
use Phalcon\Test\Module\UnitTest;
use Helper\Db\Connection\MysqlFactory;
use Helper\Db\Connection\SqliteFactory;
use Phalcon\Mvc\Model\Transaction\Failed;
use Phalcon\Mvc\Model\Transaction\Manager;
use Helper\Db\Connection\PostgresqlFactory;

/**
 * Phalcon\Test\Unit\Mvc\Model\Transaction\Manager
 * Tests the Phalcon\Mvc\Model\Transaction\Manager component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Nochum Sossonko <nsossonko@hotmail.com>
 * @package   Phalcon\Test\Unit\Mvc\Model\Transaction
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ManagerTest extends UnitTest
{
    use ModelTrait;

    /**
     * Tests Manager::get
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-07
     * @test
     */
    public function shouldGetANewTransactionOrAnAlreadyCreatedOnce()
    {
        $this->specify(
            'Unable to create a new transaction',
            function ($connection) {
                $manager = $this->setUpConnectionAwareModelsManager($connection);

                /**
                 * @var Manager $tm
                 * @var \Phalcon\Db\AdapterInterface $db
                 */
                $tm = $manager->getDI()->getShared('transactionManager');
                $db = $manager->getDI()->getShared('db');

                $transaction = $tm->get();

                expect($transaction)->isInstanceOf('Phalcon\Mvc\Model\Transaction');
                expect($tm->get(true))->same($transaction);
                expect($tm->get(false))->same($transaction);

                expect($transaction->getConnection())->isInstanceOf('Phalcon\Db\AdapterInterface');
                expect($transaction->getConnection()->getConnectionId())->equals($db->getConnectionId());
            },
            ['examples' => $this->connectionProvider()]
        );
    }

    /**
     * Tests the transaction's rollback.
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-03-04
     * @test
     */
    public function shouldRollbackNewInserts()
    {
        $this->specify(
            "The transaction's rollback doesn't works as expected",
            function ($connection) {
                $manager = $this->setUpConnectionAwareModelsManager($connection);

                /** @var Manager $tm */
                $tm = $manager->getDI()->getShared('transactionManager');

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

                    expect($persona->save())->true();
                }

                try {
                    $transaction->rollback();
                    $this->assertTrue(
                        false,
                        "The transaction's rollback didn't throw an expected exception. Emergency stop"
                    );
                } catch (Failed $e) {
                    expect($e->getMessage())->equals("Transaction aborted");
                }

                expect(Personas::count())->equals($numPersonas);
            },
            ['examples' => $this->connectionProvider()]
        );
    }

    /**
     * Tests the transaction's commit.
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-03-04
     * @test
     */
    public function shouldCommitNewInserts()
    {
        $this->specify(
            "The transaction's commit doesn't works as expected",
            function ($connection) {
                $manager = $this->setUpConnectionAwareModelsManager($connection);

                /**
                 * @var Manager $tm
                 * @var \Phalcon\Db\AdapterInterface $db
                 */
                $tm = $manager->getDI()->getShared('transactionManager');
                $db = $manager->getDI()->getShared('db');

                $db->delete("personas", "cedula LIKE 'T-Cx%'");

                $numPersonas = Personas::count();
                $transaction = $tm->get();

                for ($i = 0; $i < 10; $i++) {
                    $persona = new Personas();
                    $persona->setDI($manager->getDI());
                    $persona->setTransaction($transaction);
                    $persona->cedula            = 'T-Cx' . $i;
                    $persona->tipo_documento_id = 1;
                    $persona->nombres           = 'LOST LOST';
                    $persona->telefono          = '2';
                    $persona->cupo              = 0;
                    $persona->estado            = 'A';

                    expect($persona->save() === true)->true();
                }

                expect($transaction->commit())->true();
                expect(Personas::count())->equals($numPersonas + 10);
            },
            ['examples' => $this->connectionProvider()]
        );
    }

    /**
     * Tests transaction is removed when rolled back.
     *
     * @author Nochum Sossonko <nsossonko@hotmail.com>
     * @since  2016-04-09
     */
    public function testTransactionRemovedOnRollback()
    {
        $this->specify(
            "Test does not remove transaction when rolled back",
            function ($connection) {
                $this->setUpConnectionAwareModelsManager($connection);

                /** @var Manager $tm */
                $tm = Di::getDefault()->getShared('transactionManager');

                $transaction = $tm->get(true);

                $select = new Select();
                $select->setTransaction($transaction);
                $select->create(['name' => 'Crack of Dawn']);


                expect($this->tester->getProtectedProperty($tm, '_number'))->equals(1);
                expect($this->tester->getProtectedProperty($tm, '_transactions'))->count(1);

                try {
                    $transaction->rollback();
                } catch (Failed $e) {
                    // do nothing
                }

                expect($this->tester->getProtectedProperty($tm, '_number'))->equals(0);
                expect($this->tester->getProtectedProperty($tm, '_transactions'))->count(0);
            },
            ['examples' => $this->connectionProvider()]
        );
    }

    /**
     * Tests transaction is removed when committed.
     *
     * @author Nochum Sossonko <nsossonko@hotmail.com>
     * @since  2016-04-09
     */
    public function testTransactionRemovedOnCommit()
    {
        $this->specify(
            "Test does not remove transaction when committed",
            function ($connection) {
                $this->setUpConnectionAwareModelsManager($connection);

                /** @var Manager $tm */
                $tm = Di::getDefault()->getShared('transactionManager');
                $transaction = $tm->get(true);

                $select = new Select();
                $select->setTransaction($transaction);
                $select->create(['name' => 'Crack of Dawn']);

                expect($this->tester->getProtectedProperty($tm, '_number'))->equals(1);
                expect($this->tester->getProtectedProperty($tm, '_transactions'))->count(1);

                $transaction->commit();

                expect($this->tester->getProtectedProperty($tm, '_number'))->equals(0);
                expect($this->tester->getProtectedProperty($tm, '_transactions'))->count(0);
            },
            ['examples' => $this->connectionProvider()]
        );
    }

    /**
     * @param string $connection
     * @return \Phalcon\Mvc\Model\Manager
     */
    protected function setUpConnectionAwareModelsManager($connection)
    {
        $factory = new $connection();
        $manager = $this->setUpModelsManager($factory->createConnection());

        $tm = new Manager();
        $tm->setDI($manager->getDI());

        $manager->getDI()->set('transactionManager', $tm);

        return $manager;
    }

    protected function connectionProvider()
    {
        return [
            [MysqlFactory::class],
            [SqliteFactory::class],
            [PostgresqlFactory::class],
        ];
    }
}
