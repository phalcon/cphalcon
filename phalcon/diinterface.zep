
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
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
	 * Registers a service in the services container
	 *
	 * @param string name
	 * @param mixed definition
	 * @param boolean shared
	 * @return Phalcon\Di\ServiceInterface
	 */
	public function set(string! name, definition, boolean shared = false) -> <ServiceInterface>;

	/**
	 * Registers an "always shared" service in the services container
	 *
	 * @param string name
	 * @param mixed definition
	 * @return Phalcon\Di\ServiceInterface
	 */
	public function setShared(string! name, definition) -> <ServiceInterface>;

	/**
	 * Removes a service in the services container
	 */
	public function remove(string! name);

	/**
	 * Attempts to register a service in the services container
	 * Only is successful if a service hasn't been registered previously
	 * with the same name
	 *
	 * @param string name
	 * @param mixed definition
	 * @param boolean shared
	 * @return Phalcon\Di\ServiceInterface
	 */
	public function attempt(string! name, definition, boolean shared = false) -> <ServiceInterface>;

	/**
	 * Resolves the service based on its configuration
	 *
	 * @param string name
	 * @param array parameters
	 * @return mixed
	 */
	public function get(string! name, parameters = null);

	/**
	 * Returns a shared service based on their configuration
	 *
	 * @param string name
	 * @param array parameters
	 * @return mixed
	 */
	public function getShared(string! name, parameters = null);

	/**
	 * Sets a service using a raw Phalcon\Di\Service definition
	 */
	public function setRaw(string! name, <ServiceInterface> rawDefinition) -> <ServiceInterface>;

	/**
	 * Returns a service definition without resolving
	 *
	 * @param string name
	 * @return mixed
	 */
	public function getRaw(string! name);

	/**
	 * Returns the corresponding Phalcon\Di\Service instance for a service
	 */
	public function getService(string! name) -> <ServiceInterface>;

	/**
	 * Check whether the DI contains a service by a name
	 */
	public function has(string! name) -> boolean;

	/**
	 * Check whether the last service obtained via getShared produced a fresh instance or an existing one
	 */
	public function wasFreshInstance() -> boolean;

	/**
	 * Return the services registered in the DI
	 *
	 * @return array
	 */
	public function getServices();

	/**
	 * Set a default dependency injection container to be obtained into static methods
	 */
	public static function setDefault(<DiInterface> dependencyInjector);

	/**
	 * Return the last DI created
	 */
	public static function getDefault() -> <DiInterface>;

	/**
	 * Resets the internal default DI
	 */
	public static function reset();
}
