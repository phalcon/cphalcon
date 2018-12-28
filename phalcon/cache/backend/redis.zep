
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
use Phalcon\Cache\Exception;
use Phalcon\Cache\FrontendInterface;

/**
 * Phalcon\Cache\Backend\Redis
 *
 * Allows to cache output fragments, PHP data or raw data to a redis backend
 *
 *<code>
 * use Phalcon\Cache\Backend\Redis;
 * use Phalcon\Cache\Frontend\Data as FrontData;
 *
 * // Cache data for 2 days
 * $frontCache = new FrontData(
 *     [
 *         "lifetime" => 172800,
 *     ]
 * );
 *
 * // Create the Cache setting redis connection options
 * $cache = new Redis(
 *     $frontCache,
 *     [
 *         "host"       => "localhost",
 *         "port"       => 6379,
 *         "auth"       => "foobared",
 *         "persistent" => false,
 *         "index"      => 0,
 *     ]
 * );
 *
 * // Create the Cache setting redis connection options with statsKey
 * $cache = new Redis(
 *     $frontCache,
 *     [
 *         "host"       => "localhost",
 *         "port"       => 6379,
 *         "auth"       => "foobared",
 *         "persistent" => false,
 *         "index"      => 0,
 *         "statsKey"   => "_PHCR_",
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
class Redis extends Backend
{
	protected redis = null;

	/**
	 * @var string
	 */
	protected statsKey = "";

	/**
	 * Phalcon\Cache\Backend\Redis constructor
	 */
	public function __construct(<FrontendInterface> frontend, array options = [])
	{
		if typeof options != "array" {
			let options = [];
		}

		if !isset options["host"] {
			let options["host"] = "127.0.0.1";
		}

		if !isset options["port"] {
			let options["port"] = 6379;
		}

		if !isset options["index"] {
			let options["index"] = 0;
		}

		if !isset options["persistent"] {
			let options["persistent"] = false;
		}

		if !isset options["statsKey"] {
			// Disable tracking of cached keys per default
			let options["statsKey"] = "";
		}

		if !isset options["auth"] {
			let options["auth"] = "";
		}
		if !isset options["timeout"] {
			let options["timeout"] = 0;
		}

		let this->statsKey = options["statsKey"];
		parent::__construct(frontend, options);
	}

	/**
	 * Create internal connection to redis
	 */
	public function connect()
	{
		var options, redis, persistent, success, host, port, auth, index, timeout;

		let options = this->_options;
		let redis   = new \Redis();

		if !fetch host, options["host"] || !fetch port, options["port"] || !fetch persistent, options["persistent"] || !fetch timeout, options["timeout"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		if persistent {
			let success = redis->pconnect(host, port, timeout);
		} else {
			let success = redis->connect(host, port, timeout);
		}

		if !success {
			throw new Exception("Could not connect to the Redisd server ".host.":".port);
		}

		if fetch auth, options["auth"] && !empty options["auth"] {
			let success = redis->auth(auth);

			if !success {
				throw new Exception("Failed to authenticate with the Redisd server");
			}
		}

		if fetch index, options["index"] && index > 0 {
			let success = redis->select(index);

			if !success {
				throw new Exception("Redis server selected database failed");
			}
		}

		let this->redis = redis;
	}

	/**
	 * Returns a cached content
	 */
	public function get(string keyName, var lifetime = null) -> var | null
	{
		var redis, frontend, cachedContent;

		let redis = this->redis;
 		if typeof redis != "object" {
 			this->connect();
 			let redis = this->redis;
 		}

		let frontend       = this->_frontend;
		let this->_lastKey = this->getStoreKey(keyName);
		let cachedContent  = redis->get(this->_lastKey);

		if cachedContent === false {
			return null;
		}

		if is_numeric(cachedContent) {
			return cachedContent;
		}

		return frontend->afterRetrieve(cachedContent);
	}

	/**
	 * Stores cached content into the file backend and stops the frontend
	 *
	 * <code>
	 * $cache->save("my-key", $data);
	 *
	 * // Save data termlessly
	 * $cache->save("my-key", $data, -1);
	 * </code>
	 *
	 * @param int|string keyName
	 * @param string content
	 * @param int lifetime
	 * @param bool stopBuffer
	 */
	public function save(keyName = null, content = null, lifetime = null, bool stopBuffer = true) -> bool
	{
		var prefixedKey, frontend, redis, cachedContent, preparedContent,
			tmp, ttl, success, isBuffering;

		if keyName === null {
			let prefixedKey = substr(this->_lastKey, strlen(this->statsKey));
		} else {
			let prefixedKey    = this->getPrefixedKey(keyName),
				this->_lastKey = this->getStoreKey(keyName);
		}

		if !this->_lastKey {
			throw new Exception("The cache must be started first");
		}

		let frontend = this->_frontend;
		/**
		 * Check if a connection is created or make a new one
		 */
		let redis = this->redis;
 		if typeof redis != "object" {
 			this->connect();
 			let redis = this->redis;
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

		let success = redis->set(this->_lastKey, preparedContent);

		if !success {
			throw new Exception("Failed storing the data in redis");
		}

		// Don't set expiration for negative ttl or zero
		if ttl >= 1 {
			redis->setTimeout(this->_lastKey, ttl);
		}

		if this->statsKey != "" {
			redis->sAdd(this->statsKey, prefixedKey);
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
	 */
	public function delete(var keyName) -> bool
	{
		var redis, prefixedKey;

		let redis = this->redis;
 		if typeof redis != "object" {
 			this->connect();
 			let redis = this->redis;
 		}

		let prefixedKey    = this->getPrefixedKey(keyName);
		let this->_lastKey = this->getStoreKey(keyName);

		if this->statsKey != "" {
			redis->sRem(this->statsKey, prefixedKey);
		}

		/**
		* Delete the key from redis
		*/
		return (bool) redis->delete(this->_lastKey);
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
		var redis, keys, key, idx;

		let redis = this->redis;
 		if typeof redis != "object" {
 			this->connect();
 			let redis = this->redis;
 		}

		if this->statsKey == "" {
			throw new Exception("Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCR')!");
		}

		/**
		* Get the key from redis
		*/
		let keys = redis->sMembers(this->statsKey);
		if typeof keys != "array" {
			return [];
		}

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
		var redis;

		if keyName {
			let this->_lastKey = this->getStoreKey(keyName);
		}

		if this->_lastKey {
			let redis = this->redis;
			if typeof redis != "object" {
				this->connect();
				let redis = this->redis;
			}

			return (bool) redis->exists(this->_lastKey);
		}

		return false;
	}

	/**
	 * Increment of given $keyName by $value
	 *
	 * @param string keyName
	 */
	public function increment(keyName = null, int value = 1) -> int
	{
		var redis;

		let redis = this->redis;
 		if typeof redis != "object" {
 			this->connect();
 			let redis = this->redis;
 		}

		if keyName {
			let this->_lastKey = this->getStoreKey(keyName);
		}

		return redis->incrBy(this->_lastKey, value);
	}

	/**
	 * Decrement of $keyName by given $value
	 *
	 * @param string keyName
	 */
	public function decrement(keyName = null, int value = 1) -> int
	{
		var redis;

		let redis = this->redis;
 		if typeof redis != "object" {
 			this->connect();
 			let redis = this->redis;
 		}

		if keyName {
			let this->_lastKey = this->getStoreKey(keyName);
		}

		return redis->decrBy(this->_lastKey, value);
	}

	/**
	 * Immediately invalidates all existing items.
	 */
	public function flush() -> bool
	{
		var redis, keys, key, lastKey;

		if this->statsKey == "" {
			throw new Exception("Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCR')!");
		}

		let redis = this->redis;
 		if typeof redis != "object" {
 			this->connect();
 			let redis = this->redis;
 		}

		let keys = redis->sMembers(this->statsKey);
		if typeof keys == "array" {
			for key in keys {
				let lastKey = this->statsKey . key;
				redis->sRem(this->statsKey, key);
				redis->delete(lastKey);
			}
		}

		return true;
	}

	/**
	 * Returns the key with its prefix
	 */
	private function getPrefixedKey(string keyName) -> string
	{
		return this->_prefix . keyName;
	}

	/**
	 * Returns the store key with the special key and prefix
	 */
	private function getStoreKey(string keyName) -> string
	{
		return this->statsKey . this->getPrefixedKey(keyName);
	}
}
