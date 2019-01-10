
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cache\Backend;

use Phalcon\Cache\Exception;
use Phalcon\Cache\Backend;

/**
 * Phalcon\Cache\Backend\Apcu
 *
 * Allows to cache output fragments, PHP data and raw data using an APCu backend
 *
 *<code>
 * use Phalcon\Cache\Backend\Apcu;
 * use Phalcon\Cache\Frontend\Data as FrontData;
 *
 * // Cache data for 2 days
 * $frontCache = new FrontData(
 *     [
 *         "lifetime" => 172800,
 *     ]
 * );
 *
 * $cache = new Apcu(
 *     $frontCache,
 *     [
 *         "prefix" => "app-data",
 *     ]
 * );
 *
 * // Cache arbitrary data
 * $cache->save("my-data", [1, 2, 3, 4, 5]);
 *
 * // Get data
 * $data = $cache->get("my-data");
 *</code>
 */
class Apcu extends Backend
{

	/**
	 * Returns a cached content
	 */
	public function get(string keyName, var lifetime = null) -> var | null
	{
		var prefixedKey, cachedContent;

		let prefixedKey = "_PHCA" . this->_prefix . keyName,
			this->_lastKey = prefixedKey;

		let cachedContent = apcu_fetch(prefixedKey);
		if cachedContent === false {
			return null;
		}

		return this->_frontend->afterRetrieve(cachedContent);
	}

	/**
	 * Stores cached content into the APCu backend and stops the frontend
	 *
	 * @param string|int keyName
	 * @param string content
	 * @param int lifetime
	 * @param bool stopBuffer
	 */
	public function save(var keyName = null, var content = null, var lifetime = null, bool stopBuffer = true) -> bool
	{
		var lastKey, frontend, cachedContent, preparedContent, ttl, isBuffering, success;

		if keyName === null {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = "_PHCA" . this->_prefix . keyName;
		}

		if !lastKey {
			throw new Exception("Cache must be started first");
		}

		let frontend = this->_frontend;
		if content === null {
			let cachedContent = frontend->getContent();
		} else {
			let cachedContent = content;
		}

		if !is_numeric(cachedContent) {
			let preparedContent = frontend->beforeStore(cachedContent);
		} else {
			let preparedContent = cachedContent;
		}

		/**
		 * Take the lifetime from the frontend or read it from the set in start()
		 */
		if lifetime === null {
			let lifetime = this->_lastLifetime;
			if lifetime === null {
				let ttl = frontend->getLifetime();
			} else {
				let ttl = lifetime,
					this->_lastKey = lastKey;
			}
		} else {
			let ttl = lifetime;
		}

		/**
		 * Call apc_store in the PHP userland since most of the time it isn't available at compile time
		 */
		let success = apcu_store(lastKey, preparedContent, ttl);

		if !success {
			throw new Exception("Failed storing data in APCu");
		}

		let isBuffering = frontend->isBuffering();

		if stopBuffer === true {
			frontend->stop();
		}

		if isBuffering === true {
			echo cachedContent;
		}

		let this->_started = false;

		return success;
	}

	/**
	 * Increment of a given key, by number $value
	 *
	 * @param string keyName
	 */
	public function increment(keyName = null, int value = 1) -> int | bool
	{
		var prefixedKey;

		let prefixedKey = "_PHCA" . this->_prefix . keyName;
		let this->_lastKey = prefixedKey;

		return apcu_inc(prefixedKey, value);
	}

	/**
	 * Decrement of a given key, by number $value
	 *
	 * @param string keyName
	 */
	public function decrement(keyName = null, int value = 1) -> int | bool
	{
		var lastKey;

		let lastKey = "_PHCA" . this->_prefix . keyName,
			this->_lastKey = lastKey;

		return apcu_dec(lastKey, value);
	}

	/**
	 * Deletes a value from the cache by its key
	 */
	public function delete(var keyName) -> bool
	{
		return apcu_delete("_PHCA" . this->_prefix . keyName);
	}

	/**
	 * Query the existing cached keys.
	 *
	 * <code>
	 * $cache->save("users-ids", [1, 2, 3]);
	 * $cache->save("projects-ids", [4, 5, 6]);
	 *
	 * var_dump($cache->queryKeys("users")); // ["users-ids"]
	 * </code>
	 */
	public function queryKeys(string prefix = null) -> array
	{
		var prefixPattern, apc, keys, key;

		if empty prefix {
			let prefixPattern = "/^_PHCA/";
		} else {
			let prefixPattern = "/^_PHCA" . prefix . "/";
		}

		let keys = [];

		// The APCu 4.x only has APCIterator, not the newer APCUIterator
		if class_exists("APCUIterator") {
			let apc = new \APCUIterator(prefixPattern);
		} elseif class_exists("APCIterator") {
			let apc = new \APCIterator("user", prefixPattern);
		}

		if typeof apc != "object" {
			return [];
		}

		for key, _ in iterator(apc) {
			let keys[] = substr(key, 5);
		}

		return keys;
	}

	/**
	 * Checks if cache exists and it hasn't expired
	 *
	 * @param  string|int keyName
	 * @param  int lifetime
	 */
	public function exists(var keyName = null, int lifetime = null) -> bool
	{
		var lastKey;

		if keyName === null {
			let lastKey = (string) this->_lastKey;
		} else {
			let lastKey = "_PHCA" . this->_prefix . keyName;
		}

		if empty(lastKey) {
			return false;
		}

		return apcu_exists(lastKey);
	}

	/**
	 * Immediately invalidates all existing items.
	 *
	 * <code>
	 * use Phalcon\Cache\Backend\Apcu;
	 *
	 * $cache = new Apcu($frontCache, ["prefix" => "app-data"]);
	 *
	 * $cache->save("my-data", [1, 2, 3, 4, 5]);
	 *
	 * // 'my-data' and all other used keys are deleted
	 * $cache->flush();
	 * </code>
	 */
	public function flush() -> bool
	{
		var item, prefixPattern, apc = null;

		let prefixPattern = "/^_PHCA" . this->_prefix . "/";

		// The APCu 4.x only has APCIterator, not the newer APCUIterator
		if class_exists("APCUIterator") {
			let apc = new \APCUIterator(prefixPattern);
		} elseif class_exists("APCIterator") {
			let apc = new \APCIterator("user", prefixPattern);
		}

		if typeof apc != "object" {
			return false;
		}

		for item in iterator(apc) {
			apcu_delete(item["key"]);
		}

		return true;
	}
}
