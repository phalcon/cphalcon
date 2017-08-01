
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

namespace Phalcon\Cache;

/**
 * Phalcon\Cache\BackendInterface
 *
 * Interface for Phalcon\Cache\Backend adapters
 */
interface BackendInterface
{
	/**
	 * Starts a cache. The keyname allows to identify the created fragment
	 *
	 * @param int|string keyName
	 * @param   int lifetime
	 * @return  mixed
	 */
	public function start(keyName, lifetime = null);

	/**
	 * Stops the frontend without store any cached content
	 */
	public function stop(boolean stopBuffer = true);

	/**
	 * Returns front-end instance adapter related to the back-end
	 */
	public function getFrontend() -> <FrontendInterface>;

	/**
	 * Returns the backend options
	 */
	public function getOptions() -> array;

	/**
	 * Checks whether the last cache is fresh or cached
	 */
	public function isFresh() -> boolean;

	/**
	 * Checks whether the cache has starting buffering or not
	 */
	public function isStarted() -> boolean;

	/**
	 * Sets the last key used in the cache
	 */
	public function setLastKey(string lastKey);

	/**
	 * Gets the last key stored by the cache
	 */
	public function getLastKey() -> string;

	/**
	 * Returns a cached content
	 */
	public function get(string keyName, int lifetime = null) -> var | null;

	/**
	 * Stores cached content into the file backend and stops the frontend
	 *
	 * @param int|string keyName
	 * @param string content
	 * @param int lifetime
	 * @return boolean true on success/false otherwise
	 */
	public function save(keyName = null, content = null, lifetime = null, boolean stopBuffer = true) -> boolean;

	/**
	 * Deletes a value from the cache by its key
	 *
	 * @param int|string keyName
	 */
	public function delete(keyName) -> boolean;

	/**
	 * Query the existing cached keys
	 */
	public function queryKeys(string prefix = null) -> array;

	/**
	 * Checks if cache exists and it hasn't expired
	 *
	 * @param  string keyName
	 * @param  int lifetime
	 */
	public function exists(keyName = null, int lifetime = null) -> boolean;
}
