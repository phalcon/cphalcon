
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
	 *
	 * @param boolean stopBuffer
	 */
	public function stop(bool stopBuffer = true);

	/**
	 * Returns front-end instance adapter related to the back-end
	 *
	 * @return mixed
	 */
	public function getFrontend();

	/**
	 * Returns the backend options
	 *
	 * @return array
	 */
	public function getOptions();

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
	 *
	 * @param string lastKey
	 */
	public function setLastKey(lastKey);

	/**
	 * Gets the last key stored by the cache
	 *
	 * @return string
	 */
	public function getLastKey();

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
	 * @param boolean stopBuffer
	 * @return boolean true on success/false otherwise
	 */
	public function save(var keyName = null, var content = null, var lifetime = null, bool stopBuffer = true) -> boolean;

	/**
	 * Deletes a value from the cache by its key
	 *
	 * @param string keyName
	 * @return boolean
	 */
	public function delete(string! keyName);

	/**
	 * Query the existing cached keys
	 *
	 * @param string prefix
	 * @return array
	 */
	public function queryKeys(string prefix = null) -> array;

	/**
	 * Checks if cache exists and it hasn't expired
	 *
	 * @param  string keyName
	 * @param  int lifetime
	 * @return boolean
	 */
	public function exists(var keyName = null, int lifetime = null) -> boolean;
}
