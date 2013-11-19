
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

namespace Phalcon\Mvc\Model\Transaction;

/**
 * Phalcon\Mvc\Model\Transaction\Failed
 *
 * This class will be thrown to exit a try/catch block for isolated transactions
 */
class Failed extends Phalcon\Mvc\Model\Transaction\Exception
{

	protected _record = null;

	/**
	 * Phalcon\Mvc\Model\Transaction\Failed constructor
	 *
	 * @param string message
	 * @param Phalcon\Mvc\ModelInterface record
	 */
	public function __construct(string! message, <Phalcon\Mvc\ModelInterface> record)
	{
		let this->_record = record;
		parent::__construct(message);
	}

	/**
	 * Returns validation record messages which stop the transaction
	 *
	 * @return Phalcon\Mvc\Model\MessageInterface[]
	 */
	public function getRecordMessages() -> <Phalcon\Mvc\Model\MessageInterface[]>
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
	 *
	 * @return Phalcon\Mvc\ModelInterface
	 */
	public function getRecord() -> <Phalcon\Mvc\ModelInterface>
	{
		return this->_record;
	}

}
