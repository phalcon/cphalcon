
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

use Phalcon\DiInterface;

/**
 * Phalcon\Di\ServiceInterface
 *
 * Represents a service in the services container
 */
interface ServiceInterface
{
    /**
     * Restore the internal state of a service
     */
    public static function __set_state(array! attributes) -> <ServiceInterface>;

    /**
     * Returns the service definition
     *
     * @return mixed
     */
    public function getDefinition();

    /**
     * Returns a parameter in a specific position
     *
     * @return array
     */
    public function getParameter(int position);

    /**
     * Returns true if the service was resolved
     */
    public function isResolved() -> bool;

    /**
     * Check whether the service is shared or not
     */
    public function isShared() -> bool;

    /**
     * Resolves the service
     *
     * @param array parameters
     * @return mixed
     */
    public function resolve(parameters = null, <DiInterface> container = null);

    /**
     * Set the service definition
     *
     * @param mixed definition
     */
    public function setDefinition(definition);

    /**
     * Changes a parameter in the definition without resolve the service
     */
    public function setParameter(int position, array! parameter) -> <ServiceInterface>;

    /**
     * Sets if the service is shared or not
     */
    public function setShared(bool shared);

}
