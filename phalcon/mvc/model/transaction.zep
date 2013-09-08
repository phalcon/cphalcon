
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Model;

/**
 * Phalcon\Mvc\Model\Transaction
 *
 * Transactions are protective blocks where SQL statements are only permanent if they can
 * all succeed as one atomic action. Phalcon\Transaction is intended to be used with Phalcon_Model_Base.
 * Phalcon Transactions should be created using Phalcon\Transaction\Manager.
 *
 *<code>
 *try {
 *
 *  $manager = new Phalcon\Mvc\Model\Transaction\Manager();
 *
 *  $transaction = $manager->get();
 *
 *  $robot = new Robots();
 *  $robot->setTransaction($transaction);
 *  $robot->name = 'WALL·E';
 *  $robot->created_at = date('Y-m-d');
 *  if ($robot->save() == false) {
 *    $transaction->rollback("Can't save robot");
 *  }
 *
 *  $robotPart = new RobotParts();
 *  $robotPart->setTransaction($transaction);
 *  $robotPart->type = 'head';
 *  if ($robotPart->save() == false) {
 *    $transaction->rollback("Can't save robot part");
 *  }
 *
 *  $transaction->commit();
 *
 *} catch(Phalcon\Mvc\Model\Transaction\Failed $e) {
 *  echo 'Failed, reason: ', $e->getMessage();
 *}
 *
 *</code>
 */
class Transaction implements Phalcon\Mvc\Model\TransactionInterface
{

	protected _connection;

	protected _activeTransaction = false;

	protected _isNewTransaction = true;

	protected _rollbackOnAbort = false;

	protected _manager;

	protected _messages;

	protected _rollbackRecord;

}
