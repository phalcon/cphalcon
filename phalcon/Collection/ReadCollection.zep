
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
use Phalcon\Collection\Exception;

/**
 * Phalcon\Collection\ReadCollection is a read only Collection object
 */
class ReadCollection extends Collection
{
    /**
     * Delete the element from the collection
     */
    public function remove(string element) -> void
    {
        throw new Exception("The object is read only");
    }

    /**
     * Set an element in the collection
     */
    public function set(string element, var value) -> void
    {
        throw new Exception("The object is read only");
    }
}
