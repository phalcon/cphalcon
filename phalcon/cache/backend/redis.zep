
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
 * Phalcon\Cache\Backend\Redis
 *
 * Allows to cache output fragments, PHP data or raw data to a redis backend
 *
 *<code>
 * use Phalcon\Cache\Backend\Redis as PhRedis;
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
 * $cache = new PhRedis(
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
 * // You can also pass a redis client
 * $redisClient = new \Redis();
 * $redis->connect('localhost', 6379);
 * $cache = new PhRedis(
 *     $frontCache,
 *     [
 *         'client' => $redisClient
 *     ]
 * );
 *
 * // Cache arbitrary data
 * $cache->save("my-data", [1, 2, 3, 4, 5]);
 *
 * // Get data
 * $data = $cache->get("my-data");
 *
 * // If you want to store the keys in a special key for stat purposes you can use `statsKey`
 * $cache = new PhRedis(
 *     $frontCache,
 *     [
 *         "host"       => "localhost",
 *         "port"       => 6379,
 *         "auth"       => "foobared",
 *         "persistent" => false,
 *         "statsKey"   => "_PHCR",
 *         "index"      => 0,
 *     ]
 * );
 *
 *
 *
 *</code>
 */
class Redis extends Backend
{
	protected _redis = null;

	/**
	 * Phalcon\Cache\Backend\Redis constructor
	 */
	public function __construct(<FrontendInterface> frontend, array options = [])
	{
		if typeof options != "array" {
			let options = [];
		}

		if isset options["client"] && typeof options["client"] == "object" && options["client"] instanceof \Redis {
 			let this->_redis = options["client"];
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
		parent::__construct(frontend, options);
	}

	/**
	 * Create internal connection to redis
	 */
	public function _connect()
	{
		var options, redis, persistent, success, host, port, auth, index, timeout;

		let options = this->_options;
		let redis = new \Redis();

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

		let this->_redis = redis;
	}

	/**
	 * Returns the Redis client back. If not set, it will call connect()
	 */
	public function getClient() -> <\Redis>
	{
		if typeof this->_redis != "object" {
			this->_connect();
		}

		return this->_redis;
	}
	/**
	 * Returns a cached content
	 */
	public function get(string keyName, int lifetime = null) -> var | null
	{
		var redis, frontend, lastKey, cachedContent;

		let redis          = this->getClient(),
			frontend       = this->_frontend,
			lastKey        = this->getLastKey(keyName),
			this->_lastKey = lastKey,
			cachedContent  = redis->get(lastKey);

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
	 */
	public function save(keyName = null, content = null, lifetime = null, boolean stopBuffer = true) -> boolean
	{
		var nonePrefixedKey, lastKey, frontend, redis, cachedContent, preparedContent,
			ttl, success, specialKey, isBuffering;

		if keyName === null {
			let lastKey         = this->_lastKey,
				nonePrefixedKey = substr(lastKey, 5 + strlen(this->_prefix));
		} else {
			let nonePrefixedKey = keyName,
				lastKey         = this->getLastKey(keyName),
				this->_lastKey  = lastKey;
		}

		if !lastKey {
			throw new Exception("The cache must be started first");
		}

		let frontend = this->_frontend;

		/**
		 * Check if a connection is created or make a new one
		 */
		let redis = this->getClient();

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
			if !this->_lastLifetime {
				let ttl = frontend->getLifetime();
			} else {
				let ttl = this->_lastLifetime;
			}
		} else {
			let ttl = lifetime;
		}

		let success = redis->set(lastKey, preparedContent);

		if !success {
			throw new Exception("Failed storing the data in redis");
		}

		// Don't set expiration for negative ttl or zero
		if ttl >= 1 {
			redis->setTimeout(lastKey, ttl);
		}

		this->setSpecialKey(nonePrefixedKey);

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
	public function delete(keyName) -> boolean
	{
		var redis, lastKey, options, specialKey;

		let redis   = this->getClient(),
			lastKey = this->getLastKey(keyName);

		this->removeSpecialKey(keyName);

		/**
		* Delete the key from redis
		*/
		return (bool) redis->delete(lastKey);
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
		var redis, options, keys, specialKey, key, idx;

		let redis   = this->getClient(),
			options = this->_options;

		if !fetch specialKey, options["statsKey"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		if specialKey == "" {
			throw new Exception("Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCR')!");
		}

		/**
		* Get the key from redis
		*/
		let keys = redis->sMembers(specialKey);
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
	public function exists(keyName = null, lifetime = null) -> boolean
	{
		var lastKey, redis;

		if keyName === null {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = this->getLastKey(keyName);
		}

		if lastKey {
			let redis = this->getClient();

			return (bool) redis->exists(lastKey);
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
		var redis, lastKey;

		let redis = this->getClient();

		if keyName === null {
			let lastKey = this->_lastKey;
		} else {
			let lastKey        = this->getLastKey(keyName),
				this->_lastKey = lastKey;
		}

		return redis->incrBy(lastKey, value);
	}

	/**
	 * Decrement of $keyName by given $value
	 *
	 * @param string keyName
	 */
	public function decrement(keyName = null, int value = 1) -> int
	{
		var redis, lastKey;

		let redis = this->getClient();

		if keyName === null {
			let lastKey = this->_lastKey;
		} else {
			let lastKey        = this->getLastKey(keyName),
				this->_lastKey = lastKey;
		}

		return redis->decrBy(lastKey, value);
	}

	/**
	 * Immediately invalidates all existing items.
	 */
	public function flush() -> boolean
	{
		var options, specialKey, redis, keys, key, lastKey;

		let options = this->_options;

		if !fetch specialKey, options["statsKey"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		let redis = this->getClient();

		if specialKey == "" {
			throw new Exception("Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCR')!");
		}

		let keys = redis->sMembers(specialKey);
		if typeof keys == "array" {
			for key in keys {
				let lastKey = this->getLastKey(keyName);
				redis->sRem(specialKey, key);
				redis->delete(lastKey);
			}
		}

		return true;
	}

	/**
	 * Returns the stats key with the prefix
	 */
	private function getLastKey(string key) -> string
	{
		return this->_options["statsKey"] . this->_prefix . key;
	}

	/**
	 * Removes the key from the special key if available
	 */
	private function removeSpecialKey(string key) -> void
	{
		var redis;

		let redis = this->getClient();

		if fetch specialKey, this->_options["statsKey"] {
			if specialKey != "" {
				redis->sRem(specialKey, key);
			}
		}
	}

	/**
	 * Stores the key in the special key if available
	 */
	private function setSpecialKey(string key) -> void
	{
		var redis;

		let redis = this->getClient();

		if fetch specialKey, this->_options["statsKey"] {
			if specialKey != "" {
				redis->sAdd(specialKey, key);
			}
		}
	}
}
