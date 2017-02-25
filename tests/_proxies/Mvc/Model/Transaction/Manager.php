<?php

namespace Phalcon\Test\Proxy\Mvc\Model\Transaction;

use Phalcon\DiInterface;
use Phalcon\Mvc\Model\TransactionInterface;
use Phalcon\Mvc\Model\Transaction\Manager as PhManager;

/**
 * \Phalcon\Test\Proxy\Mvc\Model\Transaction\Manager
 * Transaction Manager proxy class for \Phalcon\Mvc\Model\Transaction\Manager
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Mvc\Model\Transaction
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Manager extends PhManager
{
    public function __construct(DiInterface $dependencyInjector = null)
    {
        parent::__construct($dependencyInjector);
    }

    public function setDI(DiInterface $dependencyInjector)
    {
        parent::setDI($dependencyInjector);
    }

    public function getDI()
    {
        return parent::getDI();
    }

    public function setDbService($service)
    {
        return parent::setDbService($service);
    }

    public function getDbService()
    {
        return parent::getDbService();
    }

    public function setRollbackPendent($rollbackPendent)
    {
        return parent::setRollbackPendent($rollbackPendent);
    }

    public function getRollbackPendent()
    {
        return parent::getRollbackPendent();
    }

    public function has()
    {
        return parent::has();
    }

    public function get($autoBegin = true)
    {
        return parent::get($autoBegin);
    }

    public function getOrCreateTransaction($autoBegin = true)
    {
        return parent::getOrCreateTransaction($autoBegin);
    }

    public function rollbackPendent()
    {
        parent::rollbackPendent();
    }

    public function commit()
    {
        parent::commit();
    }

    public function rollback($collect = true)
    {
        parent::rollback($collect);
    }

    public function notifyRollback(TransactionInterface $transaction)
    {
        parent::notifyRollback($transaction);
    }

    public function notifyCommit(TransactionInterface $transaction)
    {
        parent::notifyCommit($transaction);
    }

    public function collectTransactions()
    {
        parent::collectTransactions();
    }
}
