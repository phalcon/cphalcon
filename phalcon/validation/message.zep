
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

namespace Phalcon\Validation;

use Phalcon\Validation\MessageInterface;

/**
 * Phalcon\Validation\Message
 *
 * Encapsulates validation info generated in the validation process
 */
class Message implements MessageInterface
{

	protected _type;

	protected _message;

	protected _field;

	/**
	 * Phalcon\Validation\Message constructor
	 *
	 * @param string message
	 * @param string field
	 * @param string type
	 */
	public function __construct(string! message, field = null, type = null)
	{
		let this->_message = message,
			this->_field = field,
			this->_type = type;
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
	 * Returns message type
	 */
	public function getType() -> string
	{
		return this->_type;
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
	 * Returns verbose message
	 */
	public function getMessage() -> string
	{
		return this->_message;
	}

	/**
	 * Sets field name related to message
	 */
	public function setField(string! field) -> <Message>
	{
		let this->_field = field;
		return this;
	}

	/**
	 * Returns field name related to message
	 *
	 * @return string
	 */
	public function getField()
	{
		return this->_field;
	}

	/**
	 * Magic __toString method returns verbose message
	 */
	public function __toString() -> string
	{
		return this->_message;
	}

	/**
	 * Magic __set_state helps to recover messsages from serialization
	 */
	public static function __set_state(array! message) -> <Message>
	{
		return new self(message["_message"], message["_field"], message["_type"]);
	}
}
