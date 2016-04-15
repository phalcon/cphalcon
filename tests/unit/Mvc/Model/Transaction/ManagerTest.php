<?php

namespace Phalcon\Test\Unit\Mvc\Model\Transaction;

use Phalcon\Test\Models\Select;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Mvc\Model\Transaction\Failed;
use Phalcon\Test\Proxy\Mvc\Model\Transaction\Manager;

/**
 * \Phalcon\Test\Unit\Mvc\Model\Transaction\Manager
 * Tests the Phalcon\Mvc\Model\Transaction\Manager component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Nochum Sossonko <nsossonko@hotmail.com>
 * @package   Phalcon\Test\Unit\Mvc\Model\Transaction
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ManagerTest extends UnitTest
{
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
                $tm = new Manager;

                $transaction = $tm->get(true);

                $select = new Select();
                $select->setTransaction($transaction);
                $select->create(['name' => 'Crack of Dawn']);


                expect($this->tester->getProtectedProperty($tm, '_number'))->equals(1);
                expect($this->tester->getProtectedProperty($tm, '_transactions'))->count(1);

                try {
                    $transaction->rollback();
                } catch(Failed $e) {
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
                $tm = new Manager;

                $transaction = $tm->get(true);

                $select = new Select();
                $select->setTransaction($transaction);
                $select->create(['name' => 'Crack of Dawn']);

                expect($this->tester->getProtectedProperty($tm, '_number'))->equals(1);
                expect($this->tester->getProtectedProperty($tm, '_transactions'))->count(1);

                $transaction->commit();

                expect($this->tester->getProtectedProperty($tm, '_number'))->equals(0);
                expect($this->tester->getProtectedProperty($tm, '_transactions'))->count(0);
            }
        );
    }
}
