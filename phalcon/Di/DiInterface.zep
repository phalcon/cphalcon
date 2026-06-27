
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

use ArrayAccess;

/**
 * Interface for Phalcon\Di\Di
 */
interface DiInterface extends ArrayAccess
{
    /**
     * Attempts to register a service in the services container
     * Only is successful if a service hasn't been registered previously
     * with the same name
     *
     * @param mixed definition
     */
    public function attempt( string name, definition, bool shared = false) -> <ServiceInterface> | bool;

    /**
     * Resolves the service based on its configuration
     */
    public function get( string name, parameters = null) -> var;

    /**
     * Return the last DI created
     */
    public static function getDefault() -> <DiInterface> | null;

    /**
     * Returns a service definition without resolving
     */
    public function getRaw( string name) -> var;

    /**
     * Returns the corresponding Phalcon\Di\Service instance for a service
     */
    public function getService( string name) -> <ServiceInterface>;

    /**
     * Return the services registered in the DI
     */
    public function getServices() -> <ServiceInterface[]>;

    /**
     * Returns a shared service based on their configuration
     */
    public function getShared( string name, parameters = null) -> var;

    /**
     * Check whether the DI contains a service by a name
     */
    public function has( string name) -> bool;

    /**
     * Check whether the DI has a cached shared instance for a service name.
     *
     * Unlike `has()`, which reports on the service *definition* registry,
     * this method reports only on the resolved-instance cache populated by
     * `getShared()`. A service can be registered (`has()` returns true)
     * without yet having a shared instance (`hasShared()` returns false).
     */
    public function hasShared( string name) -> bool;

    /**
     * Removes a service in the services container
     */
    public function remove( string name) -> void;

    /**
     * Removes the cached shared instance for a service, leaving the service
     * definition intact so the next `getShared()` call rebuilds it.
     *
     * Useful in fork-based multi-process setups where a child inherits the
     * parent's resource handle (e.g. a database connection) and needs to
     * discard the cached instance without re-registering the service.
     */
    public function removeShared( string name) -> void;

    /**
     * Resets the internal default DI
     */
    public static function reset() -> void;

    /**
     * Registers a service in the services container
     */
    public function set( string name, definition, bool shared = false) -> <ServiceInterface>;

    /**
     * Set a default dependency injection container to be obtained into static
     * methods
     */
    public static function setDefault(<DiInterface> container) -> void;

    /**
     * Sets a service using a raw Phalcon\Di\Service definition
     */
    public function setService( string name, <ServiceInterface> rawDefinition) -> <ServiceInterface>;

    /**
     * Registers an "always shared" service in the services container
     */
    public function setShared( string name, definition) -> <ServiceInterface>;
}
