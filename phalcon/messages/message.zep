
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Messages;

use Phalcon\Messages\MessageInterface;

/**
 * Phalcon\Messages\Message
 *
 * Stores a message from various components
 */
class Message implements MessageInterface, \JsonSerializable
{

	protected _type;

	protected _message;

	protected _field;

	protected _code;

	/**
	 * Phalcon\Messages\Message constructor
	 */
	public function __construct(string! message, var field = null, string type = null, int code = null)
	{
		let this->_message = message,
			this->_field = field,
			this->_type = type,
			this->_code = code;
	}

	/**
	 * Returns the message code
	 */
	public function getCode() -> int
	{
		return this->_code;
	}

	/**
	 * Returns field name related to message
	 *
	 * @return mixed
	 */
	public function getField()
	{
		return this->_field;
	}

	/**
	 * Returns verbose message
	 */
	public function getMessage() -> string
	{
		return this->_message;
	}

	/**
	 * Returns message type
	 */
	public function getType() -> string
	{
		return this->_type;
	}

    /**
    * Serializes the object for json_encode
    */
	public function jsonSerialize() -> array
	{
		return [
			"field": this->_field,
			"message": this->_message,
			"type": this->_type,
			"code": this->_code
		];
	}

	/**
	 * Sets code for the message
	 */
	public function setCode(int code) -> <MessageInterface>
	{
		let this->_code = code;
		return this;
	}

	/**
	 * Sets field name related to message
	 */
	public function setField(var field) -> <MessageInterface>
	{
		let this->_field = field;
		return this;
	}

	/**
	 * Sets verbose message
	 */
	public function setMessage(string! message) -> <MessageInterface>
	{
		let this->_message = message;
		return this;
	}

	/**
	 * Sets message type
	 */
	public function setType(string! type) -> <MessageInterface>
	{
		let this->_type = type;
		return this;
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
