<?php

namespace Phalcon\Test\Unit\Mvc\Model\Transaction;

use Helper\ModelTrait;
use Phalcon\Test\Models\Select;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Mvc\Model\Transaction\Failed;
use Phalcon\Mvc\Model\Transaction\Manager;

/**
 * \Phalcon\Test\Unit\Mvc\Model\Transaction\Manager
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
     * Tests transaction is removed when rolled back.
     *
     * @author Nochum Sossonko <nsossonko@hotmail.com>
     * @since  2016-04-09
     */
    public function testTransactionRemovedOnRollback()
    {
        $this->specify(
            "Test does not remove transaction when rolled back",
            function () {
                $modelsManager = $this->setUpModelsManager();

                $tm = new Manager;

                $transaction = $tm->get(true);

                $select = new Select();
                $select->setTransaction($transaction);
                $select->assign(['name' => 'Crack of Dawn']);
                $modelsManager->create($select);


                expect($this->tester->getProtectedProperty($tm, '_number'))->equals(1);
                expect($this->tester->getProtectedProperty($tm, '_transactions'))->count(1);

                try {
                    $transaction->rollback();
                } catch (Failed $e) {
                    // do nothing
                }

                expect($this->tester->getProtectedProperty($tm, '_number'))->equals(0);
                expect($this->tester->getProtectedProperty($tm, '_transactions'))->count(0);
            }
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
            function () {
                $modelsManager = $this->setUpModelsManager();

                $tm = new Manager;

                $transaction = $tm->get(true);

                $select = new Select();
                $select->setTransaction($transaction);
                $select->assign(['name' => 'Crack of Dawn']);
                $modelsManager->create($select);

                expect($this->tester->getProtectedProperty($tm, '_number'))->equals(1);
                expect($this->tester->getProtectedProperty($tm, '_transactions'))->count(1);

                $transaction->commit();

                expect($this->tester->getProtectedProperty($tm, '_number'))->equals(0);
                expect($this->tester->getProtectedProperty($tm, '_transactions'))->count(0);
            }
        );
    }
}
