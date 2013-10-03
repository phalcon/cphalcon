
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
 * Phalcon\Mvc\Model\Message
 *
 * Encapsulates validation info generated before save/delete records fails
 *
 *<code>
 *	use Phalcon\Mvc\Model\Message as Message;
 *
 *  class Robots extends Phalcon\Mvc\Model
 *  {
 *
 *    public function beforeSave()
 *    {
 *      if (this->name == 'Peter') {
 *        text = "A robot cannot be named Peter";
 *        field = "name";
 *        type = "InvalidValue";
 *        message = new Message(text, field, type);
 *        this->appendMessage(message);
 *     }
 *   }
 *
 * }
 * </code>
 *
 */
class Message implements Phalcon\Mvc\Model\MessageInterface
{

	protected _type;

	protected _message;

	protected _field;

	protected _model;

	/**
	 * Phalcon\Mvc\Model\Message constructor
	 *
	 * @param string message
	 * @param string field
	 * @param string type
	 * @param Phalcon\Mvc\ModelInterface model
	 */
	public function __construct(string! message, field=null, type=null, model=null){
		let this->_message = message,
			this->_field = field,
			this->_type = type;
		if typeof model == "object"{
			let this->_model = model;
		}
	}

	/**
	 * Sets message type
	 *
	 * @param string type
	 * @return Phalcon\Mvc\Model\MessageInterface
	 */
	public function setType(type) -> <Phalcon\Mvc\Model\MessageInterface>
	{
		let this->_type = type;
		return this;
	}

	/**
	 * Returns message type
	 *
	 * @return string
	 */
	public function getType() -> string
	{
		return this->_type;
	}

	/**
	 * Sets verbose message
	 *
	 * @param string message
	 * @return Phalcon\Mvc\Model\MessageInterface
	 */
	public function setMessage(string! message) -> <Phalcon\Mvc\Model\MessageInterface>
	{
		let this->_message = message;
		return this;
	}

	/**
	 * Returns verbose message
	 *
	 * @return string
	 */
	public function getMessage()
	{
		return this->_message;
	}

	/**
	 * Sets field name related to message
	 *
	 * @param string field
	 * @return Phalcon\Mvc\Model\MessageInterface
	 */
	public function setField(string! field) -> <Phalcon\Mvc\Model\MessageInterface>
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
	 * Set the model who generates the message
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @return Phalcon\Mvc\Model\Message
	 */
	public function setModel(<Phalcon\Mvc\ModelInterface> model) -> <Phalcon\Mvc\Model\Message>
	{
		let this->_model = model;
		return this;
	}

	/**
	 * Returns the model that produced the message
	 *
	 * @return Phalcon\Mvc\ModelInterface
	 */
	public function getModel() -> <Phalcon\Mvc\ModelInterface>
	{
		return this->_model;
	}

	/**
	 * Magic __toString method returns verbose message
	 *
	 * @return string
	 */
	public function __toString() -> string
	{
		return this->_message;
	}

	/**
	 * Magic __set_state helps to re-build messages variable exporting
	 *
	 * @param array $message
	 * @return Phalcon\Mvc\Model\MessageInterface
	 */
	public static function __set_state(message) -> <Phalcon\Mvc\Model\MessageInterface>
	{
		return new self(message["_message"], message["_field"], message["_type"]);
	}

}
