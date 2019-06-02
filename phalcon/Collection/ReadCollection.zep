
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Collection;

use Phalcon\Collection\Collection;

/**
 * Phalcon\Collection
 *
 * Phalcon\Collection is a supercharged object oriented array. It implements
 * ArrayAccess, Countable, IteratorAggregate, JsonSerializable, Serializable
 *
 * It can be used in any part of the application that needs collection of data
 * Such implementations are for instance accessing globals `$_GET`, `$_POST`
 * etc.
 */
class ReadCollection extends Collection
{
    /**
     * Delete the element from the collection
     *
     * @param string $element
     * @param bool   $insensitive
     *
     * @throws Exception
     */
    public function remove(string element, bool insensitive = true) -> void
    {
        throw new Exception("The object is read only");
    }

    /**
     * Set an element in the collection
     *
     * @param string $element
     * @param mixed  $value
     *
     * @throws Exception
     */
    public function set(string element, var value) -> void
    {
        throw new Exception("The object is read only");
    }
}
