
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

/**
 * This interface must be implemented in those classes that uses internally the
 */
interface AdapterInterface
{
    /**
     * get the dependency injector
     */
    public static function has(<DiInterface> container) -> bool;

    /**
     * Returns the internal dependency injector
     */
    public static function get() -> <DiInterface> | null;

    /**
     * set the dependency injector
     */
     public static function set(<DiInterface> container) -> void;
}
