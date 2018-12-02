
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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

use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\MessageInterface;

/**
 * Phalcon\Mvc\Model\Message
 *
 * Encapsulates validation info generated before save/delete records fails
 *
 *<code>
 * use Phalcon\Mvc\Model\Message as Message;
 *
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function beforeSave()
 *     {
 *         if ($this->name === "Peter") {
 *             $text  = "A robot cannot be named Peter";
 *             $field = "name";
 *             $type  = "InvalidValue";
 *
 *             $message = new Message($text, $field, $type);
 *
 *             $this->appendMessage($message);
 *         }
 *     }
 * }
 * </code>
 *
 */
class Message implements MessageInterface
{

	/**
	 * @var string
	 */
	protected _type { get };

	/**
	 * @var string
	 */
	protected _message { get };

	protected _field;

	protected _model;

	protected _code;

	/**
	 * Phalcon\Mvc\Model\Message constructor
	 *
	 * @param string message
	 * @param string|array field
	 * @param string type
	 * @param \Phalcon\Mvc\ModelInterface model
         * @param int|null code
	 */
	public function __construct(string! message, field = null, type = null, model = null, int code = null)
	{
		let this->_message = message,
			this->_field = field,
			this->_type = type,
			this->_code = code;
		if typeof model == "object" {
			let this->_model = model;
		}
	}

	/**
	 * Sets message type
	 */
	public function setType(string! type) -> <Message>
	{
		let this->_type = type;
		return this;
	}

	/**
	 * Sets verbose message
	 */
	public function setMessage(string! message) -> <Message>
	{
		let this->_message = message;
		return this;
	}

	/**
	 * Sets field name related to message
	 */
	public function setField(var field) -> <Message>
	{
		let this->_field = field;
		return this;
	}

	/**
	 * Returns field name related to message
	 */
	public function getField()
	{
		return this->_field;
	}

	/**
	 * Set the model who generates the message
	 */
	public function setModel(<ModelInterface> model) -> <Message>
	{
		let this->_model = model;
		return this;
	}

	/**
	 * Sets code for the message
	 */
	public function setCode(int code) -> <Message>
	{
		let this->_code = code;
		return this;
	}

	/**
	 * Returns the model that produced the message
	 */
	public function getModel() -> <ModelInterface>
	{
		return this->_model;
	}

	/**
	 * Returns the message code
	 */
	public function getCode() -> int
	{
		return this->_code;
	}

	/**
	 * Magic __toString method returns verbose message
	 */
	public function __toString() -> string
	{
		return this->_message;
	}

	/**
	 * Magic __set_state helps to re-build messages variable exporting
	 */
	public static function __set_state(array! message) -> <MessageInterface>
	{
		return new self(message["_message"], message["_field"], message["_type"], message["_code"]);
	}
}
