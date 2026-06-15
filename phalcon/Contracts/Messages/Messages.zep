
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Messages;

use ArrayAccess;
use Countable;
use Iterator;
use Phalcon\Messages\MessageInterface;

/**
 * Canonical contract for Phalcon\Messages\Messages.
 *
 * The collection stores Phalcon\Messages\MessageInterface objects and is
 * iterated by integer position. An entry added under a string key through the
 * ArrayAccess interface stays reachable by that offset but is not visited
 * during iteration (`foreach`), which walks the integer sequence only.
 */
interface Messages extends ArrayAccess, Countable, Iterator
{
    /**
     * Appends a message to the collection
     */
    public function appendMessage(<MessageInterface> message) -> void;

    /**
     * Appends an array of messages to the collection
     *
     * @param \Phalcon\Messages\MessageInterface[] messages
     */
    public function appendMessages(messages);

    /**
     * Filters the message collection by field name
     */
    public function filter(string! fieldName) -> array;
}
