
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations\Adapter;

use Phalcon\Annotations\Reflection;

/**
 * Stores the parsed annotations in memory. This adapter is the suitable
 * development/testing
 */
class Memory extends AbstractAdapter
{
    /**
     * @var mixed
     */
    protected data;

    /**
     * Reads parsed annotations from memory
     */
    public function read(string! key) -> <Reflection> | bool
    {
        var data;

        if !fetch data, this->data[strtolower(key)] {
            return false;
        }

        return data;
    }

    /**
     * Writes parsed annotations to memory
     */
    public function write(string! key, <Reflection> data) -> void
    {
        var lowercasedKey;

        let lowercasedKey = strtolower(key);
        let this->data[lowercasedKey] = data;
    }
}
