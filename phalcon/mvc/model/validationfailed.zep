
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Mvc\Model;

/**
 * Phalcon\Mvc\Model\ValidationFailed
 *
 * This exception is generated when a model fails to save a record
 * Phalcon\Mvc\Model must be set up to have this behavior
 */
class ValidationFailed extends \Phalcon\Mvc\Model\Exception
{

	protected _model;

	protected _messages;

	/**
	 * Phalcon\Mvc\Model\ValidationFailed constructor
	 *
	 * @param Message[] validationMessages
	 */
	public function __construct(<Model> model, array! validationMessages)
	{
		var messageStr, message;

		if count(validationMessages) > 0 {
			/**
			 * Get the first message in the array
			 */
			let message = validationMessages[0];

			/**
			 * Get the message to use it in the exception
			 */
			let messageStr = message->getMessage();
		} else {
			let messageStr = "Validation failed";
		}

		let this->_model = model;
		let this->_messages = validationMessages;

		parent::__construct(messageStr);
	}

	/**
	 * Returns the model that generated the messages
	 */
	public function getModel() -> <Model>
	{
		return this->_model;
	}

	/**
	 * Returns the complete group of messages produced in the validation
	 */
	public function getMessages() -> <Message[]>
	{
		return this->_messages;
	}
}
