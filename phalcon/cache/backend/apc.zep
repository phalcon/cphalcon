
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
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

namespace Phalcon\Cache\Backend;

use Phalcon\Cache\Backend;
use Phalcon\Cache\Exception;
use Phalcon\Cache\FrontendInterface;

/**
 * Phalcon\Cache\Backend\Apc
 *
 * Allows to cache output fragments, PHP data and raw data using an APC(u) backend
 *
 *<code>
 * use Phalcon\Cache\Backend\Apc;
 * use Phalcon\Cache\Frontend\Data as FrontData;
 *
 * // Cache data for 2 days
 * $frontCache = new FrontData(
 *     [
 *         "lifetime" => 172800,
 *     ]
 * );
 *
 * $cache = new Apc(
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
class Apc extends Backend
{
	protected useApcu = false;

	/**
	 * Phalcon\Cache\Backend\Apc constructor
	 */
	public function __construct(<FrontendInterface> frontend, array options = null)
	{
		let this->useApcu = function_exists("apcu_fetch");

		parent::__construct(frontend, options);
	}

	/**
	 * Returns a cached content
	 */
	public function get(string keyName, int lifetime = null) -> var | null
	{
		var prefixedKey, cachedContent;

		let prefixedKey = "_PHCA" . this->_prefix . keyName,
			this->_lastKey = prefixedKey;

		if this->useApcu {
			let cachedContent = apcu_fetch(prefixedKey);
		} else {
			let cachedContent = apc_fetch(prefixedKey);
		}

		if cachedContent === false {
			return null;
		}

		return this->_frontend->afterRetrieve(cachedContent);
	}

	/**
	 * Stores cached content into the APC backend and stops the frontend
	 *
	 * @param string|int keyName
	 * @param string content
	 * @param int lifetime
	 * @param boolean stopBuffer
	 */
	public function save(var keyName = null, var content = null, var lifetime = null, boolean stopBuffer = true) -> boolean
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
		if this->useApcu {
			let success = apcu_store(lastKey, preparedContent, ttl);
		} else {
			let success = apc_store(lastKey, preparedContent, ttl);
		}

		if !success {
			throw new Exception("Failed storing data in apc");
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
	public function increment(keyName = null, int value = 1) -> int | boolean
	{
		var prefixedKey, cachedContent, result;

		let prefixedKey = "_PHCA" . this->_prefix . keyName;
		let this->_lastKey = prefixedKey;

		if this->useApcu {
			return apcu_inc(prefixedKey, value);
		}

		if function_exists("apc_inc") {
			return apc_inc(prefixedKey, value);
		} else {
			let cachedContent = apc_fetch(prefixedKey);

			if is_numeric(cachedContent) {
				let result = cachedContent + value;
				this->save(keyName, result);
				return result;
			}
		}

		return false;
	}

	/**
	 * Decrement of a given key, by number $value
	 *
	 * @param string keyName
	 */
	public function decrement(keyName = null, int value = 1) -> int | boolean
	{
		var lastKey, cachedContent, result;

		let lastKey = "_PHCA" . this->_prefix . keyName,
			this->_lastKey = lastKey;

		if this->useApcu {
			return apcu_dec(lastKey, value);
		}

		if function_exists("apc_dec") {
			return apc_dec(lastKey, value);
		} else {
			let cachedContent = apc_fetch(lastKey);

			if is_numeric(cachedContent) {
				let result = cachedContent - value;
				this->save(keyName, result);
				return result;
			}
		}

		return false;
	}

	/**
	 * Deletes a value from the cache by its key
	 */
	public function delete(string! keyName) -> boolean
	{
		if this->useApcu {
			return apc_delete("_PHCA" . this->_prefix . keyName);
		}

		return apc_delete("_PHCA" . this->_prefix . keyName);
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

		if class_exists("APCUIterator") {
			let apc = new \APCUIterator(prefixPattern);
		} else {
			let apc = new \APCIterator("user", prefixPattern);
		}

		let keys = [];
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
	public function exists(keyName = null, lifetime = null) -> boolean
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

		if this->useApcu {
			return apcu_exists(lastKey);
		}

		return apc_exists(lastKey);
	}

	/**
	 * Immediately invalidates all existing items.
	 *
	 * <code>
	 * use Phalcon\Cache\Backend\Apc;
	 *
	 * $cache = new Apc($frontCache, ["prefix" => "app-data"]);
	 *
	 * $cache->save("my-data", [1, 2, 3, 4, 5]);
	 *
	 * // 'my-data' and all other used keys are deleted
	 * $cache->flush();
	 * </code>
	 */
	public function flush() -> boolean
	{
		var item, prefixPattern, apc;

		let prefixPattern = "/^_PHCA" . this->_prefix . "/";

		if class_exists("APCUIterator") {
			let apc = new \APCUIterator(prefixPattern);

			for item in iterator(apc) {
				apcu_delete(item["key"]);
			}
		} else {
			let apc = new \APCIterator("user", prefixPattern);

			for item in iterator(apc) {
				apc_delete(item["key"]);
			}
		}

		return true;
	}
}
