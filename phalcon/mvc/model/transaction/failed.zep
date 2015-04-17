
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Mvc\Model\Transaction;

use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\Transaction\Exception;
use Phalcon\Mvc\Model\MessageInterface;

/**
 * Phalcon\Mvc\Model\Transaction\Failed
 *
 * This class will be thrown to exit a try/catch block for isolated transactions
 */
class Failed extends Exception
{

	protected _record = null;

	/**
	 * Phalcon\Mvc\Model\Transaction\Failed constructor
	 */
	public function __construct(string! message, <ModelInterface> record = null)
	{
		let this->_record = record;
		parent::__construct(message);
	}

	/**
	 * Returns validation record messages which stop the transaction
	 */
	public function getRecordMessages() -> <MessageInterface[]>
	{
		var record;

		let record = this->_record;
		if record !== null {
			return record->getMessages();
		}

		return this->getMessage();
	}

	/**
	 * Returns validation record messages which stop the transaction
	 */
	public function getRecord() -> <ModelInterface>
	{
		return this->_record;
	}
}
