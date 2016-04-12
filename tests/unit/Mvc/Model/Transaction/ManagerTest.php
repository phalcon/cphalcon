<?php

namespace Phalcon\Test\Unit\Mvc\Model\Transaction;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Proxy\Mvc\Model\Transaction\Manager as TransactionManager;
use Phalcon\Test\Models\Select;

/**
 * \Phalcon\Test\Unit\Mvc\CollectionTest
 * Tests the Phalcon\Mvc\Collection component
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
                $tm = new TransactionManager();
                $transaction = $tm->get(true);
                $select = new Select();
                $select->setTransaction($transaction);
                $select->create(
                    array(
                        'name' => 'Crack of Dawn'
                    )
                );
                expect($tm->count())->equals(1);
                expect(count($tm->getTransactions()))->equals(1);
                try {
                    $transaction->rollback();
                }
                catch(\Phalcon\Mvc\Model\Transaction\Failed $e) {}
                expect($tm->count())->equals(0);
                expect(count($tm->getTransactions()))->equals(0);
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
                $tm = new TransactionManager();
                $transaction = $tm->get(true);
                $select = new Select();
                $select->setTransaction($transaction);
                $select->create(
                    array(
                        'name'   => 'Crack of Dawn'
                    )
                );
                expect($tm->count())->equals(1);
                expect(count($tm->getTransactions()))->equals(1);
                $transaction->commit();
                expect($tm->count())->equals(0);
                expect(count($tm->getTransactions()))->equals(0);
            }
        );
    }
}
