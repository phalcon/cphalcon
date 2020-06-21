
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di\Adapter;

use Phalcon\Di\DiInterface;
use Phalcon\Di\AdapterInterface;

/**
 * This interface must be implemented in those classes that uses internally the
 */
class Memory implements AdapterInterface
{
    /**
     * Latest DI build
     *
     * @var DiInterface | null
     */
     protected _default;

    /**
     * get the dependency injector
     */
    public function has() -> bool
    {
        if !this->_default {
            return false;
        }
        return true;
    }

    /**
     * Returns the internal dependency injector
     */
    public function get() -> <DiInterface> | null
    {
        return this->_default;
    }

    /**
     * Set a default dependency injection container to be obtained into static
     * methods
     */
     public function set(<DiInterface> container = null) -> void
     {
         let this->_default = container;
     }
}
