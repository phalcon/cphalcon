
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Messages\Traits;

use Phalcon\Contracts\Messages\MessagesTypes;
use Phalcon\Messages\Exceptions\MessageNotObject;
use Phalcon\Messages\MessageInterface;

/**
 * Trait MessagesHelperTrait
 *
 * @phpstan-import-type messages_list from MessagesTypes
 */
trait MessagesHelperTrait
{
    /**
     * @var messages_list
     */
    protected array messages = [];

    protected int position = 0;

    /**
     * Returns the number of messages in the list
     *
     * @return int
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
     */
    public function offsetExists(mixed offset) -> bool
    {
        return isset this->messages[offset];
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
    public function offsetGet(mixed offset) -> mixed
    {
        var message;

        if fetch message, this->messages[offset] {
            return message;
        }

        return null;
    }

    /**
     * Sets an attribute using the array-syntax
     *
     *```php
     * $messages[0] = new \Phalcon\Messages\Message("This is a message");
     *```
     *
     * @throws MessageNotObject
     */
    public function offsetSet(mixed offset, var value) -> void
    {
        if typeof value !== "object" || !(value instanceof MessageInterface) {
            throw new MessageNotObject();
        }

        if (offset === null) {
            let this->messages[] = value;
        } else {
            let this->messages[offset] = value;
        }
    }

    /**
     * Removes a message from the list
     *
     *```php
     * unset($message["database"]);
     *```
     */
    public function offsetUnset(mixed offset) -> void
    {
        if (isset(this->messages[offset])) {
            array_splice(this->messages, offset, 1);
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
    public function valid() -> bool
    {
        return isset this->messages[this->position];
    }
}
