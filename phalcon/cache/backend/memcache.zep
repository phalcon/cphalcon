
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

namespace Phalcon\Cache\Backend;

use Phalcon\Cache\Backend;
use Phalcon\Cache\Exception;
use Phalcon\Cache\FrontendInterface;

/**
 * Phalcon\Cache\Backend\Memcache
 *
 * Allows to cache output fragments, PHP data or raw data to a memcache backend
 *
 * This adapter uses the special memcached key "_PHCM" to store all the keys internally used by the adapter
 *
 *<code>
 * use Phalcon\Cache\Backend\Memcache;
 * use Phalcon\Cache\Frontend\Data as FrontData;
 *
 * // Cache data for 2 days
 * $frontCache = new FrontData(
 *     [
 *         "lifetime" => 172800,
 *     ]
 * );
 *
 * // Create the Cache setting memcached connection options
 * $cache = new Memcache(
 *     $frontCache,
 *     [
 *         "host"       => "localhost",
 *         "port"       => 11211,
 *         "persistent" => false,
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
class Memcache extends Backend
{

	protected _memcache = null;

	/**
	 * Phalcon\Cache\Backend\Memcache constructor
	 *
	 * @param	Phalcon\Cache\FrontendInterface frontend
	 * @param	array options
	 */
	public function __construct(<FrontendInterface> frontend, options = null)
	{
		if typeof options != "array" {
			let options = [];
		}

		if !isset options["host"] {
			let options["host"] = "127.0.0.1";
		}

		if !isset options["port"] {
			let options["port"] = 11211;
		}

		if !isset options["persistent"] {
			let options["persistent"] = false;
		}

		if !isset options["statsKey"] {
			// Disable tracking of cached keys per default
			let options["statsKey"] = "";
		}

		parent::__construct(frontend, options);
	}

	/**
	 * Create internal connection to memcached
	 */
	public function _connect()
	{
		var options, memcache, persistent, success, host, port;

		let options = this->_options;
		let memcache = new \Memcache();

		if !fetch host, options["host"] || !fetch port, options["port"] || !fetch persistent, options["persistent"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		if persistent {
			let success = memcache->pconnect(host, port);
		} else {
			let success = memcache->connect(host, port);
		}

		if !success {
			throw new Exception("Cannot connect to Memcached server");
		}

		let this->_memcache = memcache;
	}

	/**
	 * Add servers to memcache pool
	 */
	public function addServers(string! host, int port, boolean persistent = false) -> boolean
	{
		var memcache, success;
		/**
		 * Check if a connection is created or make a new one
		 */
		let memcache = this->_memcache;
		if typeof memcache != "object" {
		    this->_connect();
		    let memcache = this->_memcache;
		}
		let success = memcache->addServer(host, port, persistent);
		let this->_memcache = memcache;
		return success;
	}

	/**
	 * Returns a cached content
	 */
	public function get(string keyName, int lifetime = null) -> var | null
	{
		var memcache, prefixedKey, cachedContent, retrieve;

		let memcache = this->_memcache;
		if typeof memcache != "object" {
			this->_connect();
			let memcache = this->_memcache;
		}

		let prefixedKey = this->_prefix . keyName;
		let this->_lastKey = prefixedKey;
		let cachedContent = memcache->get(prefixedKey);

		if cachedContent === false {
			return null;
		}

		if is_numeric(cachedContent) {
			return cachedContent;
		}

		let retrieve = this->_frontend->afterRetrieve(cachedContent);
		return retrieve;
	}

	/**
	 * Stores cached content into the file backend and stops the frontend
	 *
	 * @param int|string keyName
	 * @param string content
	 * @param int lifetime
	 * @param boolean stopBuffer
	 */
	public function save(var keyName = null, var content = null, var lifetime = null, boolean stopBuffer = true) -> boolean
	{
		var lastKey, frontend, memcache, cachedContent, preparedContent, tmp, ttl, success, options,
			specialKey, keys, isBuffering;

		if keyName === null {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = this->_prefix . keyName,
				this->_lastKey = lastKey;
		}

		if !lastKey {
			throw new Exception("Cache must be started first");
		}

		let frontend = this->_frontend;

		/**
		 * Check if a connection is created or make a new one
		 */
		let memcache = this->_memcache;
		if typeof memcache != "object" {
			this->_connect();
			let memcache = this->_memcache;
		}

		if content === null {
			let cachedContent = frontend->getContent();
		} else {
			let cachedContent = content;
		}

		/**
		 * Prepare the content in the frontend
		 */
		if !is_numeric(cachedContent) {
			let preparedContent = frontend->beforeStore(cachedContent);
		} else {
			let preparedContent = cachedContent;
		}

		if lifetime === null {
			let tmp = this->_lastLifetime;

			if !tmp {
				let ttl = frontend->getLifetime();
			} else {
				let ttl = tmp;
			}
		} else {
			let ttl = lifetime;
		}

		/**
		* We store without flags
		*/
		let success = memcache->set(lastKey, preparedContent, 0, ttl);

		if !success {
			throw new Exception("Failed storing data in memcached");
		}

		let options = this->_options;

		if !fetch specialKey, options["statsKey"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		if specialKey != "" {
			/**
			 * Update the stats key
			 */
			let keys = memcache->get(specialKey);
			if typeof keys != "array" {
				let keys = [];
			}

			if !isset keys[lastKey] {
				let keys[lastKey] = ttl;
				memcache->set(specialKey, keys);
			}
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
	 * Deletes a value from the cache by its key
	 *
	 * @param int|string keyName
	 * @return boolean
	 */
	public function delete(var keyName)
	{
		var memcache, prefixedKey, options, keys, specialKey, ret;

		let memcache = this->_memcache;
		if typeof memcache != "object" {
			this->_connect();
			let memcache = this->_memcache;
		}

		let prefixedKey = this->_prefix . keyName;
		let options = this->_options;

		if !fetch specialKey, options["statsKey"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		if specialKey != "" {
			let keys = memcache->get(specialKey);

			if typeof keys == "array" {
				unset keys[prefixedKey];
				memcache->set(specialKey, keys);
			}
		}

		/**
		 * Delete the key from memcached
		 */
		let ret = memcache->delete(prefixedKey);
		return ret;
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
		var memcache, options, keys, specialKey, key, idx;

		let memcache = this->_memcache;

		if typeof memcache != "object" {
			this->_connect();
			let memcache = this->_memcache;
		}

		let options = this->_options;

		if !fetch specialKey, options["statsKey"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		if specialKey == "" {
			throw new Exception("Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!");
		}

		/**
		 * Get the key from memcached
		 */
		let keys = memcache->get(specialKey);
		if unlikely typeof keys != "array" {
			return [];
		}

		let keys = array_keys(keys);
		for idx, key in keys {
			if !empty prefix && !starts_with(key, prefix) {
				unset keys[idx];
			}
		}

		return keys;
	}

	/**
	 * Checks if cache exists and it isn't expired
	 *
	 * @param string keyName
	 * @param int lifetime
	 */
	public function exists(var keyName = null, int lifetime = null) -> boolean
	{
		var lastKey, memcache, prefix;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let prefix = this->_prefix;
			let lastKey = prefix . keyName;
		}

		if lastKey {

			let memcache = this->_memcache;
			if typeof memcache != "object" {
				this->_connect();
				let memcache = this->_memcache;
			}

			if !memcache->get(lastKey) {
				return false;
			}
			return true;
		}

		return false;
	}

	/**
	 * Increment of given $keyName by $value
	 *
	 * @param string keyName
	 */
	public function increment(keyName = null, int value = 1) -> int | boolean
	{
		var memcache, prefix, lastKey;

		let memcache = this->_memcache;

		if typeof memcache != "object" {
			this->_connect();
			let memcache = this->_memcache;
		}

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let prefix = this->_prefix;
			let lastKey = prefix . keyName;
			let this->_lastKey = lastKey;
		}

		return memcache->increment(lastKey, value);
	}

	/**
	 * Decrement of $keyName by given $value
	 *
	 * @param string keyName
	 */
	public function decrement(keyName = null, int value = 1) -> int | boolean
	{
		var memcache, prefix, lastKey;

		let memcache = this->_memcache;

		if typeof memcache != "object" {
			this->_connect();
			let memcache = this->_memcache;
		}

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let prefix = this->_prefix;
			let lastKey = prefix . keyName;
			let this->_lastKey = lastKey;
		}

		return memcache->decrement(lastKey, value);
	}

	/**
	 * Immediately invalidates all existing items.
	 */
	public function flush() -> boolean
	{
		var memcache, options, keys, specialKey, key;

		let memcache = this->_memcache;

		if typeof memcache != "object" {
			this->_connect();
			let memcache = this->_memcache;
		}

		let options = this->_options;

		if !fetch specialKey, options["statsKey"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		if specialKey == "" {
			throw new Exception("Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!");
		}

		/**
		 * Get the key from memcached
		 */
		let keys = memcache->get(specialKey);
		if unlikely typeof keys != "array" {
			return true;
		}

		for key, _ in keys {
			memcache->delete(key);
		}

		memcache->delete(specialKey);

		return true;
	}

}
