
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Phalcon\DiInterface;
use Phalcon\Di\ServiceInterface;

/**
 * Phalcon\DiInterface
 *
 * Interface for Phalcon\Di
 */
interface DiInterface extends \ArrayAccess
{
    /**
     * Attempts to register a service in the services container
     * Only is successful if a service hasn't been registered previously
     * with the same name
     *
     * @param mixed definition
     */
    public function attempt(string! name, definition, bool shared = false) -> <ServiceInterface> | bool;

    /**
     * Resolves the service based on its configuration
     *
     * @param array parameters
     */
    public function get(string! name, parameters = null) -> var;

    /**
     * Return the last DI created
     */
    public static function getDefault() -> <DiInterface> | null;

    /**
     * Returns a service definition without resolving
     */
    public function getRaw(string! name) -> var;

    /**
     * Returns the corresponding Phalcon\Di\Service instance for a service
     */
    public function getService(string! name) -> <ServiceInterface>;

    /**
     * Return the services registered in the DI
     */
    public function getServices() -> <ServiceInterface[]>;

    /**
     * Returns a shared service based on their configuration
     *
     * @param array parameters
     */
    public function getShared(string! name, parameters = null) -> var;

    /**
     * Check whether the DI contains a service by a name
     */
    public function has(string! name) -> bool;

    /**
     * Removes a service in the services container
     */
    public function remove(string! name);

    /**
     * Resets the internal default DI
     */
    public static function reset();

    /**
     * Registers a service in the services container
     *
     * @param mixed definition
     */
    public function set(string! name, definition, bool shared = false) -> <ServiceInterface>;

    /**
     * Set a default dependency injection container to be obtained into static methods
     */
    public static function setDefault(<DiInterface> container);

    /**
     * Sets a service using a raw Phalcon\Di\Service definition
     */
    public function setRaw(string! name, <ServiceInterface> rawDefinition) -> <ServiceInterface>;

    /**
     * Registers an "always shared" service in the services container
     *
     * @param mixed definition
     */
    public function setShared(string! name, definition) -> <ServiceInterface>;
}
