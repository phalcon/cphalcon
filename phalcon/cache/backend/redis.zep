
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2016 Phalcon Team (https://phalconphp.com)          |
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
use Phalcon\Cache\BackendInterface;
use Phalcon\Cache\FrontendInterface;

/**
 * Phalcon\Cache\Backend\Redis
 *
 * Allows to cache output fragments, PHP data or raw data to a redis backend
 *
 * This adapter uses the special redis key "_PHCR" to store all the keys internally used by the adapter
 *
 *<code>
 * use Phalcon\Cache\Backend\Redis;
 * use Phalcon\Cache\Frontend\Data as FrontData;
 *
 * // Cache data for 2 days
 * $frontCache = new FrontData([
 *     'lifetime' => 172800
 * ]);
 *
 * // Create the Cache setting redis connection options
 * $cache = new Redis($frontCache, [
 *     'host' => 'localhost',
 *     'port' => 6379,
 *     'auth' => 'foobared',
 *     'persistent' => false
 *     'index' => 0,
 * ]);
 *
 * // Cache arbitrary data
 * $cache->save('my-data', [1, 2, 3, 4, 5]);
 *
 * // Get data
 * $data = $cache->get('my-data');
 *</code>
 */
class Redis extends Backend implements BackendInterface
{
	protected _redis = null;

	/**
	 * Phalcon\Cache\Backend\Redis constructor
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

		parent::__construct(frontend, options);
	}

	/**
	 * Create internal connection to redis
	 */
	public function _connect()
	{
		var options, redis, persistent, success, host, port, auth, index;

		let options = this->_options;
		let redis = new \Redis();

		if !fetch host, options["host"] || !fetch port, options["port"] || !fetch persistent, options["persistent"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		if persistent {
			let success = redis->pconnect(host, port);
		} else {
			let success = redis->connect(host, port);
		}

		if !success {
			throw new Exception("Could not connect to the Redisd server ".host.":".port);
		}

		if fetch auth, options["auth"] {
			let success = redis->auth(auth);

			if !success {
				throw new Exception("Failed to authenticate with the Redisd server");
			}
		}

		if fetch index, options["index"] {
			let success = redis->select(index);

			if !success {
				throw new Exception("Redisd server selected database failed");
			}
		}

		let this->_redis = redis;
	}

	/**
	 * Returns a cached content
	 */
	public function get(string keyName, int lifetime = null) -> var | null
	{
		var redis, frontend, prefix, lastKey, cachedContent;

		let redis = this->_redis;
		if typeof redis != "object" {
			this->_connect();
			let redis = this->_redis;
		}

		let frontend = this->_frontend;
		let prefix = this->_prefix;
		let lastKey = "_PHCR" . prefix . keyName;
		let this->_lastKey = lastKey;
		let cachedContent = redis->get(lastKey);

		if !cachedContent {
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
	 * @param int|string keyName
	 * @param string content
	 * @param long lifetime
	 * @param boolean stopBuffer
	 */
	public function save(keyName = null, content = null, lifetime = null, boolean stopBuffer = true) -> boolean
	{
		var prefixedKey, lastKey, prefix, frontend, redis, cachedContent, preparedContent,
			tmp, tt1, success, options, specialKey, isBuffering;

		if keyName === null {
			let lastKey = this->_lastKey;
			let prefixedKey = substr(lastKey, 5);
		} else {
			let prefix = this->_prefix;
			let prefixedKey = prefix . keyName;
			let lastKey = "_PHCR" . prefixedKey;
			let this->_lastKey = lastKey;
		}

		if !lastKey {
			throw new Exception("The cache must be started first");
		}

		let frontend = this->_frontend;

		/**
		 * Check if a connection is created or make a new one
		 */
		let redis = this->_redis;
		if typeof redis != "object" {
			this->_connect();
			let redis = this->_redis;
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

		if is_numeric(cachedContent) {
			let success = redis->set(lastKey, cachedContent);
		} else {
			let success = redis->set(lastKey, preparedContent);
		}

		if !success {
			throw new Exception("Failed storing the data in redis");
		}

		redis->settimeout(lastKey, tt1);

		let options = this->_options;

		if !fetch specialKey, options["statsKey"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		if specialKey != "" {
			redis->sAdd(specialKey, prefixedKey);
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
	public function delete(keyName) -> boolean
	{
		var redis, prefix, prefixedKey, lastKey, options, specialKey;

		let redis = this->_redis;
		if typeof redis != "object" {
			this->_connect();
			let redis = this->_redis;
		}

		let prefix = this->_prefix;
		let prefixedKey = prefix . keyName;
		let lastKey = "_PHCR" . prefixedKey;
		let options = this->_options;

		if !fetch specialKey, options["statsKey"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		if specialKey != "" {
			redis->sRem(specialKey, prefixedKey);
		}

		/**
		* Delete the key from redis
		*/
		return (bool) redis->delete(lastKey);
	}

	/**
	 * Query the existing cached keys
	 *
	 * @param string prefix
	 */
	public function queryKeys(prefix = null) -> array
	{
		var redis, options, keys, specialKey, key, value;

		let redis = this->_redis;

		if typeof redis != "object" {
			this->_connect();
			let redis = this->_redis;
		}

		let options = this->_options;

		if !fetch specialKey, options["statsKey"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		if specialKey == "" {
			throw new Exception("Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!");
		}

		/**
		* Get the key from redis
		*/
		let keys = redis->sMembers(specialKey);
		if typeof keys == "array" {
			for key, value in keys {
				if prefix && !starts_with(value, prefix) {
					unset(keys[key]);
				}
			}

			return keys;
		}

		return [];
	}

	/**
	 * Checks if cache exists and it isn't expired
	 *
	 * @param string keyName
	 * @param   long lifetime
	 * @return boolean
	 */
	public function exists(keyName = null, lifetime = null) -> boolean
	{
		var lastKey, redis, prefix;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let prefix = this->_prefix;
			let lastKey = "_PHCR" . prefix . keyName;
		}

		if lastKey {
			let redis = this->_redis;
			if typeof redis != "object" {
				this->_connect();
				let redis = this->_redis;
			}

			if !redis->get(lastKey) {
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
	 * @param long value
	 */
	public function increment(keyName = null, value = null) -> int
	{
		var redis, prefix, lastKey;

		let redis = this->_redis;

		if typeof redis != "object" {
			this->_connect();
			let redis = this->_redis;
		}

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let prefix = this->_prefix;
			let lastKey = "_PHCR" . prefix . keyName;
			let this->_lastKey = lastKey;
		}

		if !value {
			let value = 1;
		}

		return redis->incrBy(lastKey, value);
	}

	/**
	 * Decrement of $keyName by given $value
	 *
	 * @param string keyName
	 * @param long value
	 */
	public function decrement(keyName = null, value = null) -> int
	{
		var redis, prefix, lastKey;

		let redis = this->_redis;

		if typeof redis != "object" {
			this->_connect();
			let redis = this->_redis;
		}

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let prefix = this->_prefix;
			let lastKey = "_PHCR" . prefix . keyName;
			let this->_lastKey = lastKey;
		}

		if !value {
			let value = 1;
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

		let redis = this->_redis;

		if typeof redis != "object" {
			this->_connect();
			let redis = this->_redis;
		}

		if specialKey == "" {
			throw new Exception("Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCM')!");
		}

		let keys = redis->sMembers(specialKey);
		if typeof keys == "array" {
			for key in keys {
				let lastKey = "_PHCR" . key;
				redis->sRem(specialKey, key);
				redis->delete(lastKey);
			}
		}

		return true;
	}
}
