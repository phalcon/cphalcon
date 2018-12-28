
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Transaction;

use Phalcon\Messages\MessageInterface;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\Transaction\Exception;

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
