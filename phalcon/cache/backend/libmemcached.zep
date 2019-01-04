
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cache\Backend;

use Phalcon\Cache\Backend;
use Phalcon\Cache\FrontendInterface;
use Phalcon\Cache\Exception;

/**
 * Phalcon\Cache\Backend\Libmemcached
 *
 * Allows to cache output fragments, PHP data or raw data to a libmemcached backend.
 * Per default persistent memcached connection pools are used.
 *
 *<code>
 * use Phalcon\Cache\Backend\Libmemcached;
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
 * $cache = new Libmemcached(
 *     $frontCache,
 *     [
 *         "servers" => [
 *             [
 *                 "host"   => "127.0.0.1",
 *                 "port"   => 11211,
 *                 "weight" => 1,
 *             ],
 *         ],
 *         "client" => [
 *             \Memcached::OPT_HASH       => \Memcached::HASH_MD5,
 *             \Memcached::OPT_PREFIX_KEY => "prefix.",
 *         ],
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
class Libmemcached extends Backend
{

	protected _memcache = null;

	/**
	 * Phalcon\Cache\Backend\Memcache constructor
	 *
	 * @param	array options
	 */
	public function __construct(<FrontendInterface> frontend, options = null)
	{
		var servers;

		if typeof options != "array" {
			let options = [];
		}

		if !isset options["servers"] {
			let servers = [0: ["host": "127.0.0.1", "port": 11211, "weight": 1]];
			let options["servers"] = servers;
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
		var options, memcache, client, servers, persistentId;

		let options = this->_options;

		/* Enable persistent memcache connection per default */
		if !fetch persistentId, options["persistent_id"] {
			let persistentId = "phalcon_cache";
		}

		/* Get memcached pool connection */
		let memcache = new \Memcached(persistentId);

		/* Persistent memcached pools need to be reconnected if getServerList() is empty */
		if empty memcache->getServerList() {
			if !fetch servers, options["servers"] {
				throw new Exception("Servers must be an array");
			}

			if typeof servers != "array" {
				throw new Exception("Servers must be an array");
			}

			if !fetch client, options["client"] {
				let client = [];
			}

			if typeof client !== "array" {
				throw new Exception("Client options must be instance of array");
			}

			if !memcache->setOptions(client) {
				throw new Exception("Cannot set to Memcached options");
			}

			if !memcache->addServers(servers) {
				throw new Exception("Cannot connect to Memcached server");
			}
		}

		let this->_memcache = memcache;
	}

	/**
	 * Returns a cached content
	 */
	public function get(string keyName, var lifetime = null) -> var | null
	{
		var memcache, prefixedKey, cachedContent;

		let memcache = this->_memcache;
		if typeof memcache != "object" {
			this->_connect();
			let memcache = this->_memcache;
		}

		let prefixedKey = this->_prefix . keyName;
		let this->_lastKey = prefixedKey;

		let cachedContent = memcache->get(prefixedKey);

		if \Memcached::RES_NOTFOUND === memcache->getResultCode() {
			return null;
		}

		if is_numeric(cachedContent) {
			return cachedContent;
		}

		return this->_frontend->afterRetrieve(cachedContent);
	}

	/**
	 * Stores cached content into the file backend and stops the frontend
	 *
	 * @param int|string keyName
	 * @param string content
	 * @param int lifetime
	 */
	public function save(keyName = null, content = null, lifetime = null, bool stopBuffer = true) -> bool
	{
		var lastKey, frontend, memcache, cachedContent, preparedContent, tmp, tt1, success, options,
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
				let tt1 = frontend->getLifetime();
			} else {
				let tt1 = tmp;
			}
		} else {
			let tt1 = lifetime;
		}

		let success = memcache->set(lastKey, preparedContent, tt1);

		if !success {
			throw new Exception("Failed storing data in memcached, error code: " . memcache->getResultCode());
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
				let keys[lastKey] = tt1;
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
	 * @return bool
	 */
	public function delete(var keyName) -> bool
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
	public function exists(var keyName = null, int lifetime = null) -> bool
	{
		var lastKey, memcache, value;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = this->_prefix . keyName;
		}

		if lastKey {
			let memcache = this->_memcache;
			if typeof memcache != "object" {
				this->_connect();
				let memcache = this->_memcache;
			}
			let value = memcache->get(lastKey);
			if !value {
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
	public function increment(keyName = null, int value = 1) -> int | bool
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
	public function decrement(keyName = null, int value = 1) -> int | bool
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
	 *
	 * Memcached does not support flush() per default. If you require flush() support, set $config["statsKey"].
     * All modified keys are stored in "statsKey". Note: statsKey has a negative performance impact.
     *
     *<code>
     * $cache = new \Phalcon\Cache\Backend\Libmemcached(
     *     $frontCache,
     *     [
     *         "statsKey" => "_PHCM",
     *     ]
     * );
     *
     * $cache->save("my-data", [1, 2, 3, 4, 5]);
     *
     * // 'my-data' and all other used keys are deleted
     * $cache->flush();
     *</code>
	 */
	public function flush() -> bool
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
