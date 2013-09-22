
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

/**
 * Phalcon\DiInterface
 *
 * Interface for Phalcon\Di
 */
interface DiInterface extends ArrayAccess
{

	/**
	 * Registers a service in the services container
	 *
	 * @param string name
	 * @param mixed definition
	 * @param boolean shared
	 * @return Phalcon\Di\ServiceInterface
	 */
	public function set(name, definition, shared=false);

	/**
	 * Registers an "always shared" service in the services container
	 *
	 * @param string name
	 * @param mixed definition
	 * @return Phalcon\Di\ServiceInterface
	 */
	public function setShared(name, definition);

	/**
	 * Removes a service in the services container
	 *
	 * @param string name
	 */
	public function remove(name);

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
	public function attempt(name, definition, shared=false);

	/**
	 * Resolves the service based on its configuration
	 *
	 * @param string name
	 * @param array parameters
	 * @return mixed
	 */
	public function get(name, parameters=null);

	/**
	 * Returns a shared service based on their configuration
	 *
	 * @param string name
	 * @param array parameters
	 * @return mixed
	 */
	public function getShared(name, parameters=null);

	/**
	 * Sets a service using a raw Phalcon\Di\Service definition
	 *
	 * @param string name
	 * @param Phalcon\Di\ServiceInterface rawDefinition
	 * @return Phalcon\Di\ServiceInterface
	 */
	public function setRaw(name, rawDefinition);

	/**
	 * Returns a service definition without resolving
	 *
	 * @param string name
	 * @return mixed
	 */
	public function getRaw(name);

	/**
	 * Returns the corresponding Phalcon\Di\Service instance for a service
	 *
	 * @param string name
	 * @return Phalcon\Di\ServiceInterface
	 */
	public function getService(name);

	/**
	 * Check whether the DI contains a service by a name
	 *
	 * @param string name
	 * @return boolean
	 */
	public function has(name);

	/**
	 * Check whether the last service obtained via getShared produced a fresh instance or an existing one
	 *
	 * @return boolean
	 */
	public function wasFreshInstance();

	/**
	 * Return the services registered in the DI
	 *
	 * @return array
	 */
	public function getServices();

	/**
	 * Set a default dependency injection container to be obtained into static methods
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public static function setDefault(dependencyInjector);

	/**
	 * Return the last DI created
	 *
	 * @return Phalcon\DiInterface
	 */
	public static function getDefault();

	/**
	 * Resets the internal default DI
	 */
	public static function reset();

}
