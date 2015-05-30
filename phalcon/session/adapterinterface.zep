
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

namespace Phalcon\Session;

/**
 * Phalcon\Session\AdapterInterface
 *
 * Interface for Phalcon\Session adapters
 */
interface AdapterInterface
{

	/**
	 * Starts session, optionally using an adapter
	 */
	public function start();

	/**
	 * Sets session options
	 */
	public function setOptions(array! options);

	/**
	 * Get internal options
	 */
	public function getOptions() -> array;

	/**
	 * Gets a session variable from an application context
	 *
	 * @param string index
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function get(string index, defaultValue = null);

	/**
	 * Sets a session variable in an application context
	 *
	 * @param string index
	 * @param string value
	 */
	public function set(string index, value);

	/**
	 * Check whether a session variable is set in an application context
	 */
	public function has(string index) -> boolean;

	/**
	 * Removes a session variable from an application context
	 */
	public function remove(string index);

	/**
	 * Returns active session id
	 */
	public function getId() -> string;

	/**
	 * Check whether the session has been started
	 */
	public function isStarted() -> boolean;

	/**
	 * Destroys the active session
	 */
	public function destroy() -> boolean;

}
