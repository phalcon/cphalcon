
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
 * Represents a service in the services container
 */
interface ServiceInterface
{
    /**
     * Returns the service definition
     */
    public function getDefinition() -> var;

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
     */
    public function resolve(parameters = null, <DiInterface> container = null) -> var;

    /**
     * Set the service definition
     */
    public function setDefinition(var definition);

    /**
     * Changes a parameter in the definition without resolve the service
     */
    public function setParameter(int position, array! parameter) -> <ServiceInterface>;

    /**
     * Sets if the service is shared or not
     */
    public function setShared(bool shared);

    /**
     * Sets which implementations should be used by autowrie compoment
     */
    public function setAutowireTypes(array autowireTypes) -> <ServiceInterface>;
}
