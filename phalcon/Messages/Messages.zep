
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Messages;

use Iterator;
use JsonSerializable;
use Phalcon\Contracts\Messages\Messages as MessagesContract;
use Phalcon\Contracts\Messages\MessagesTypes;
use Phalcon\Messages\Exceptions\MessageNotObject;
use Phalcon\Messages\Exceptions\MessagesNotIterable;
use Phalcon\Messages\Traits\MessagesHelperTrait;
use Traversable;

/**
 * Represents a collection of messages
 *
 * Messages are stored and iterated by integer position. An entry added under a
 * string key through the ArrayAccess interface (for example
 * `$messages["database"] = $message`) stays reachable by that offset but is not
 * visited during iteration (`foreach`), which walks the integer sequence only.
 * Use the append methods (`appendMessage()` / `appendMessages()`) when entries
 * must take part in iteration.
 *
 * @phpstan-import-type messages_list from MessagesTypes
 * @phpstan-import-type messages_serialized from MessagesTypes
 */
class Messages implements MessagesContract, JsonSerializable
{
    use MessagesHelperTrait;

    /**
     * Phalcon\Messages\Messages constructor
     *
     * @param messages_list $messages
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
    public function appendMessage(<MessageInterface> message) -> void
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
     * Accepts an array of MessageInterface objects or an Iterator yielding
     * them. The parameter stays untyped so that a non-iterable argument
     * reaches the guard below and raises MessagesNotIterable rather than a
     * TypeError.
     *
     * @param mixed $messages
     *
     * @return void
     * @throws MessagesNotIterable
     */
    public function appendMessages(var messages)
    {
        var currentMessages, finalMessages, message;

        if typeof messages !== "array" && !(typeof messages === "object" && messages instanceof Traversable) {
            throw new MessagesNotIterable();
        }

        let currentMessages = this->messages;

        if typeof messages == "array" {
            /**
             * An array of messages is simply merged into the current one
             */
            let finalMessages = array_merge(currentMessages, messages);

            let this->messages = finalMessages;
        } else {
            /**
             * A collection of messages is iterated and appended one-by-one to
             * the current list
             */
            messages->rewind();

            while messages->valid() {
                let message = messages->current();
                this->appendMessage(message);
                messages->next();
            }
        }
    }

    /**
     * Filters the message collection by field name
     *
     * @return messages_list
     */
    public function filter(string fieldName) -> array
    {
        var filtered, messages, message;

        let filtered = [],
            messages = this->messages;

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
     *
     * @return messages_serialized
     */
    public function jsonSerialize() -> array
    {
        var message;
        array records = [];

        for message in this->messages {
            let records[] = this->checkSerializable(message);
        }

        return records;
    }

    /**
     * @param mixed $value
     */
    private function checkSerializable(var value) -> mixed
    {
        if (
            typeof value === "object" &&
            true === method_exists(value, "jsonSerialize")
        ) {
            return value->jsonSerialize();
        }

        return value;
    }
}
