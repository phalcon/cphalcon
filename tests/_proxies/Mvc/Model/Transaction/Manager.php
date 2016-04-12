<?php

namespace Phalcon\Test\Proxy\Mvc\Model\Transaction;

use Phalcon\Mvc\Model\Transaction\Manager as PhManager;

/**
 * \Phalcon\Test\Proxy\Mvc\Manager
 * Url proxy class for \Phalcon\Mvc\Manager
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Nochum Sossonko <nsossonko@hotmail.com>
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
    public function getTransactions()
    {
      return $this->_transactions;
    }

    public function count()
    {
      return $this->_number;
    }
}
