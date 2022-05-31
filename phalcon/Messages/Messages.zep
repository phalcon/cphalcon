
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Messages;

use ArrayAccess;
use Countable;
use Iterator;
use JsonSerializable;

/**
 * Represents a collection of messages
 */
class Messages implements ArrayAccess, Countable, Iterator, JsonSerializable
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
     *```php
     * $messages->appendMessage(
     *     new \Phalcon\Messages\Message("This is a message")
     * );
     *```
     */
    public function appendMessage(<MessageInterface> message)
    {
        let this->messages[] = message;
    }

    /**
     * Appends an array of messages to the collection
     *
     *```php
     * $messages->appendMessages($messagesArray);
     *```
     *
     * @param \Phalcon\Messages\MessageInterface[] messages
     */
    public function appendMessages(messages)
    {
        var currentMessages, finalMessages, message;

        if typeof messages != "array" && typeof messages != "object" {
            throw new Exception("The messages must be iterable");
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
             * A collection of messages is iterated and appended one-by-one to
             * the current list
             */
            //for message in iterator(messages) {
            //    this->appendMessage(message);
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
             * A collection of messages is iterated and appended one-by-one to
             * the current list
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
     *```php
     * $data = $messages->jsonSerialize();
     * echo json_encode($data);
     *```
     */
    public function jsonSerialize() -> array
    {
        var message;
        array records;

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
     *```php
     * var_dump(
     *     isset($message["database"])
     * );
     *```
     *
     * @param int index
     */
    public function offsetExists(mixed index) -> bool
    {
        return isset this->messages[index];
    }

    /**
     * Gets an attribute a message using the array syntax
     *
     *```php
     * print_r(
     *     $messages[0]
     * );
     *```
     */
    public function offsetGet(mixed index) -> mixed
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
     *```php
     * $messages[0] = new \Phalcon\Messages\Message("This is a message");
     *```
     *
     * @param \Phalcon\Messages\Message message
     */
    public function offsetSet(mixed index, mixed message) -> void
    {
        if typeof message != "object" {
            throw new Exception("The message must be an object");
        }

        let this->messages[index] = message;
    }

    /**
     * Removes a message from the list
     *
     *```php
     * unset($message["database"]);
     *```
     */
    public function offsetUnset(mixed index) -> void
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
