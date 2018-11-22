
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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
	 */
	public function get(string index, var defaultValue = null) -> var;

	/**
	 * Sets a session variable in an application context
	 */
	public function set(string index, var value);

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
	public function destroy(var removeData = null) -> boolean;

	/**
	 * Regenerate session's id
	 */
	public function regenerateId(bool deleteOldSession = true) -> <AdapterInterface>;

	/**
	 * Set session name
	 */
	public function setName(string name);

	/**
	 * Get session name
	 */
	public function getName() -> string;
}
