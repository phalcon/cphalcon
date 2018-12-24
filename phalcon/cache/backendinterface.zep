
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
	public function stop(bool stopBuffer = true);

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
	public function isFresh() -> bool;

	/**
	 * Checks whether the cache has starting buffering or not
	 */
	public function isStarted() -> bool;

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
	public function get(string keyName, var lifetime = null) -> var | null;

	/**
	 * Stores cached content into the file backend and stops the frontend
	 *
	 * @param int|string keyName
	 * @param string content
	 * @param int lifetime
	 * @return bool true on success/false otherwise
	 */
	public function save(keyName = null, content = null, lifetime = null, bool stopBuffer = true) -> bool;

	/**
	 * Deletes a value from the cache by its key
	 *
	 * @param int|string keyName
	 */
	public function delete(keyName) -> bool;

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
	public function exists(var keyName = null, int lifetime = null) -> bool;
}
