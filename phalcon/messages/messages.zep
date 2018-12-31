
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Messages;

use Phalcon\Messages\Message;
use Phalcon\Messages\Exception;
use Phalcon\Messages\MessageInterface;

/**
 * Phalcon\Messages\Messages
 *
 * Represents a collection of messages
 */
class Messages implements \ArrayAccess, \Countable, \Iterator, \JsonSerializable
{
	/**
	 * @var int
	 */
	protected position = 0;

	/**
	 * @var array
	 */
	protected messages;

	/**
	 * Phalcon\Messages\Messages constructor
	 */
	public function __construct(array messages = [])
	{
		let this->messages = messages;
	}

	/**
	 * Appends a message to the collection
	 *
	 *<code>
	 * $messages->appendMessage(
	 *     new \Phalcon\Messages\Message("This is a message")
	 * );
	 *</code>
	 */
	public function appendMessage(<MessageInterface> message)
	{
		let this->messages[] = message;
	}

	/**
	 * Appends an array of messages to the collection
	 *
	 *<code>
	 * $messages->appendMessages($messagesArray);
	 *</code>
	 *
	 * @param \Phalcon\Messages\MessageInterface[] messages
	 */
	public function appendMessages(messages)
	{
		var currentMessages, finalMessages, message;

		if typeof messages != "array" && typeof messages != "object" {
			throw new Exception("The messages must be array or object");
		}

		let currentMessages = this->messages;
		if typeof messages == "array" {

			/**
			 * An array of messages is simply merged into the current one
			 */
			if typeof currentMessages == "array" {
				let finalMessages = array_merge(currentMessages, messages);
			} else {
				let finalMessages = messages;
			}
			let this->messages = finalMessages;

		} else {

			/**
			 * A collection of messages is iterated and appended one-by-one to the current list
			 */
			//for message in iterator(messages) {
			//	this->appendMessage(message);
			//}

			messages->rewind();
			while messages->valid() {
				let message = messages->current();
				this->appendMessage(message);
    			messages->next();
			}
		}
	}

	/**
	 * Returns the number of messages in the list
	 */
	public function count() -> int
	{
		return count(this->messages);
	}

	/**
	 * Returns the current message in the iterator
	 */
	public function current() -> <MessageInterface>
	{
		return this->messages[this->position];
	}

	/**
	 * Filters the message collection by field name
	 */
	public function filter(string! fieldName) -> array
	{
		var filtered, messages, message;

		let filtered = [],
			messages = this->messages;
		if typeof messages == "array" {

			/**
			 * A collection of messages is iterated and appended one-by-one to the current list
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
     * Returns serialised message objects as array for json_encode. Calls
     * jsonSerialize on each object if present
     *
     *<code>
     * $data = $messages->jsonSerialize();
     * echo json_encode($data);
     *</code>
     */
    public function jsonSerialize() -> array
    {
    	var records, message;
    	let records = [];

    	for message in this->messages {
        	if typeof message == "object" && method_exists(message, "jsonSerialize") {
        		let records[] = message->{"jsonSerialize"}();
        	} else {
        	    let records[] = message;
        	}
        }

        return records;
    }

	/**
	 * Returns the current position/key in the iterator
	 */
	public function key() -> int
	{
		return this->position;
	}

	/**
	 * Moves the internal iteration pointer to the next position
	 */
	public function next() -> void
	{
		let this->position++;
	}

	/**
	 * Checks if an index exists
	 *
	 *<code>
	 * var_dump(
	 *     isset($message["database"])
	 * );
	 *</code>
	 *
	 * @param int index
	 */
	public function offsetExists(var index) -> boolean
	{
		return isset this->messages[index];
	}

	/**
	 * Gets an attribute a message using the array syntax
	 *
	 *<code>
	 * print_r(
	 *     $messages[0]
	 * );
	 *</code>
	 */
	public function offsetGet(var index) -> var
	{
		var message, returnValue = null;

		if fetch message, this->messages[index] {
			let returnValue = message;
		}

		return returnValue;
	}

	/**
	 * Sets an attribute using the array-syntax
	 *
	 *<code>
	 * $messages[0] = new \Phalcon\Messages\Message("This is a message");
	 *</code>
	 *
	 * @param \Phalcon\Messages\Message message
	 */
	public function offsetSet(var index, var message) -> void
	{
		if typeof message != "object" {
			throw new Exception("The message must be an object");
		}
		let this->messages[index] = message;
	}

	/**
	 * Removes a message from the list
	 *
	 *<code>
	 * unset($message["database"]);
	 *</code>
	 */
	public function offsetUnset(var index) -> void
	{
		if isset this->messages[index] {
			array_splice(this->messages, index, 1);
		}
	}

	/**
	 * Rewinds the internal iterator
	 */
	public function rewind() -> void
	{
		let this->position = 0;
	}

	/**
	 * Check if the current message in the iterator is valid
	 */
	public function valid() -> boolean
	{
		return isset this->messages[this->position];
	}
}
