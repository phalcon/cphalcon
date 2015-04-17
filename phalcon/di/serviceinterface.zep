
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

namespace Phalcon\Di;

/**
 * Phalcon\Di\ServiceInterface
 *
 * Represents a service in the services container
 */
interface ServiceInterface
{

	/**
	 * Phalcon\Di\ServiceInterface
	 *
	 * @param string name
	 * @param mixed definition
	 * @param boolean shared
	 */
	public function __construct(string name, definition, boolean shared = false);

	/**
	 * Returns the service's name
	 *
	 * @param string
	 */
	public function getName();

	/**
	 * Sets if the service is shared or not
	 */
	public function setShared(boolean shared);

	/**
	 * Check whether the service is shared or not
	 */
	public function isShared() -> boolean;

	/**
	 * Set the service definition
	 *
	 * @param mixed definition
	 */
	public function setDefinition(definition);

	/**
	 * Returns the service definition
	 *
	 * @return mixed
	 */
	public function getDefinition();

	/**
	 * Resolves the service
	 *
	 * @param array parameters
	 * @param Phalcon\DiInterface dependencyInjector
	 * @return mixed
	 */
	public function resolve(parameters = null, <\Phalcon\DiInterface> dependencyInjector = null);

	/**
	 * Restore the interal state of a service
	 */
	public static function __set_state(array! attributes) -> <ServiceInterface>;

}
