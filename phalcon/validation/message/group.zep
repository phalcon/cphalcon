
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

namespace Phalcon\Validation\Message;

/**
 * Phalcon\Validation\Message\Group
 *
 * Represents a group of validation messages
 */
class Group implements Countable, ArrayAccess, Iterator
{

	protected _position;

	protected _messages;

	/**
	 * Phalcon\Validation\Message\Group constructor
	 *
	 * @param array messages
	 */
	public function __construct(messages=null)
	{
		if typeof messages == "array" {
			let this->_messages = messages;
		}
	}

	/**
	 * Gets an attribute a message using the array syntax
	 *
	 *<code>
	 * print_r($messages[0]);
	 *</code>
	 *
	 * @param string index
	 * @return Phalcon\Validation\Message
	 */
	public function offsetGet(int index) -> <Phalcon\Validation\Message>
	{
		var messages, message;
		let messages = this->_messages;
		if fetch message, messages[index] {
			return message;
		}
		return null;
	}

	/**
	 * Sets an attribute using the array-syntax
	 *
	 *<code>
	 * $messages[0] = new Phalcon\Validation\Message('This is a message');
	 *</code>
	 *
	 * @param string index
	 * @param Phalcon\Validation\Message message
	 */
	public function offsetSet(string index, <Phalcon\Validation\Message> message)
	{
		if typeof message != "object" {
			throw new Phalcon\Validation\Exception("The message must be an object");
		}
		let this->_messages[index] = message;
	}

	/**
	 * Checks if an index exists
	 *
	 *<code>
	 * var_dump(isset($message['database']));
	 *</code>
	 *
	 * @param string index
	 * @return boolean
	 */
	public function offsetExists(string index)
	{
		var messages;
		let messages = this->_messages;
		return isset messages[index];
	}

	/**
	 * Removes a message from the list
	 *
	 *<code>
	 * unset($message['database']);
	 *</code>
	 *
	 * @param string index
	 */
	public function offsetUnset(index)
	{
		var messages;
		let messages = this->_messages;
		if isset messages[index] {
			//unset this->_messages[index];
		}
		return false;
	}

	/**
	 * Appends a message to the group
	 *
	 *<code>
	 * $messages->appendMessage(new Phalcon\Validation\Message('This is a message'));
	 *</code>
	 *
	 * @param Phalcon\Validation\MessageInterface message
	 */
	public function appendMessage(message)
	{
		if typeof message != "object" {
			throw new Phalcon\Validation\Exception("The message must be an object");
		}
		let this->_messages[] = message;
	}

	/**
	 * Appends an array of messages to the group
	 *
	 *<code>
	 * $messages->appendMessages($messagesArray);
	 *</code>
	 *
	 * @param Phalcon\Validation\MessageInterface[] messages
	 */
	public function appendMessages(messages)
	{
		var currentMessages, finalMessages, message;

		if typeof messages != "array" {
			if typeof messages != "object" {
				throw new Phalcon\Validation\Exception("The messages must be array or object");
			}
		}

		let currentMessages = this->_messages;
		if typeof messages == "array" {

			/**
			 * An array of messages is simply merged into the current one
			 */
			if currentMessages == "array" {
				let finalMessages = array_merge(currentMessages, messages);
			} else {
				let finalMessages = messages;
			}
			let this->_messages = finalMessages;
		} else {

			/**
			 * A group of messages is iterated and appended one-by-one to the current list
			 */
			for message in iterator(messages) {
				this->appendMessage(message);
			}
		}
	}

	/**
	 * Filters the message group by field name
	 *
	 * @param string fieldName
	 * @return array
	 */
	public function filter(string fieldName)
	{
		var filtered, messages, message;

		let filtered = [],
			messages = this->_messages;
		if typeof messages == "array" {

			/**
			 * A group of messages is iterated and appended one-by-one to the current list
			 */
			for message in messages {

				/**
				 * Get the field name
				 */
				if method_exists(message, "getField") {
					if fieldName == message->getField() {
						let filtered[] = message;
					}
				}
			}

		}

		return filtered;
	}

	/**
	 * Returns the number of messages in the list
	 *
	 * @return int
	 */
	public function count() -> int
	{
		return count(this->_messages);
	}

	/**
	 * Rewinds the internal iterator
	 */
	public function rewind()
	{
		let this->_position = 0;
	}

	/**
	 * Returns the current message in the iterator
	 *
	 * @return Phalcon\Validation\Message
	 */
	public function current() -> <Phalcon\Validation\Message>
	{
		var messages, message;
		let messages = this->_messages;
		if fetch message, messages[this->_position] {
			return message;
		}
		return null;
	}

	/**
	 * Returns the current position/key in the iterator
	 *
	 * @return int
	 */
	public function key() -> int
	{
		return this->_position;
	}

	/**
	 * Moves the internal iteration pointer to the next position
	 *
	 */
	public function next()
	{
		let this->_position++;
	}

	/**
	 * Check if the current message in the iterator is valid
	 *
	 * @return boolean
	 */
	public function valid() -> boolean
	{
		var messages;
		let messages = this->_messages;
		return isset messages[this->_position];
	}

	/**
	 * Magic __set_state helps to re-build messages variable when exporting
	 *
	 * @param array group
	 * @return Phalcon\Mvc\Model\Message\Group
	 */
	public static function __set_state(group) -> <Phalcon\Mvc\Model\Message\Group>
	{
		return new self(group["_messages"]);
	}

}