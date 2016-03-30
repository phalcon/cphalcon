
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
 *
 * // Cache data for 2 days
 * $frontCache = new \Phalcon\Cache\Frontend\Data(array(
 *    "lifetime" => 172800
 * ));
 *
 * //Create the Cache setting redis connection options
 * $cache = new Phalcon\Cache\Backend\Redis($frontCache, array(
 *		'host' => 'localhost',
 *		'port' => 6379,
 *		'auth' => 'foobared',
 *  	'persistent' => false
 * ));
 *
 * //Cache arbitrary data
 * $cache->save('my-data', array(1, 2, 3, 4, 5));
 *
 * //Get data
 * $data = $cache->get('my-data');
 *
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
			let options["statsKey"] = "_PHCR";
		}

		parent::__construct(frontend, options);
	}

	public function _getRedis()
	{
		if typeof this->_redis != "object" {
			this->_connect();
		}

		return this->_redis;
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
			throw new Exception("Could not connect to the Redisd server " . host . ":" . port);
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
	 *
	 * @param int|string keyName
	 * @param   long lifetime
	 * @return  mixed
	 */
	public function get(keyName, lifetime = null)
	{
		var lastKey, cachedContent;

		let lastKey = this->_prefix . keyName;
		let this->_lastKey = lastKey;

		let cachedContent = this->_getRedis()->get(lastKey);
		if !cachedContent {
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
	 * @param long lifetime
	 * @param boolean stopBuffer
	 */
	public function save(keyName = null, content = null, lifetime = null, boolean stopBuffer = true)
	{
		var lastKey, frontend, cachedContent, preparedContent, ttl, success, specialKey, isBuffering;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = this->_prefix . keyName;
		}
		if !lastKey {
			throw new Exception("The cache must be started first");
		}

		let frontend = this->_frontend;

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
			if !this->_lastLifetime {
				let ttl = frontend->getLifetime();
			} else {
				let ttl = this->_lastLifetime;
			}
		} else {
			let ttl = lifetime;
		}

		if is_numeric(cachedContent) {
			let success = this->_getRedis()->set(lastKey, cachedContent, ttl);
		} else {
			let success = this->_getRedis()->set(lastKey, preparedContent, ttl);
		}
		if !success {
			throw new Exception("Failed storing the data in redis");
		}

		if !fetch specialKey, this->_options["statsKey"] {
			throw new Exception("Unexpected inconsistency in options");
		}
		if specialKey != "" {
			this->_getRedis()->sAdd(specialKey, lastKey);
		}

		let isBuffering = frontend->isBuffering();
		if stopBuffer === true {
			frontend->stop();
		}
		if isBuffering === true {
			echo cachedContent;
		}

		let this->_started = false;
	}

	/**
	 * Deletes a value from the cache by its key
	 *
	 * @param int|string keyName
	 * @return boolean
	 */
	public function delete(keyName)
	{
		var lastKey, specialKey;

		let lastKey = this->_prefix . keyName;

		if !fetch specialKey, this->_options["statsKey"] {
			throw new Exception("Unexpected inconsistency in options");
		}
		if specialKey != "" {
			this->_getRedis()->sRem(specialKey, lastKey);
		}

		/**
		* Delete the key from redis
		*/
		return this->_getRedis()->delete(lastKey);
	}

	/**
	 * Query the existing cached keys
	 *
	 * @param string prefix
	 * @return array
	 */
	public function queryKeys(prefix = null)
	{
		var keys, specialKey, key, value;

		if !fetch specialKey, this->_options["statsKey"] {
			throw new Exception("Unexpected inconsistency in options");
		}
		if specialKey == "" {
			throw new Exception("Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCR')!");
		}

		/**
		* Get the key from redis
		*/
		let keys = this->_getRedis()->sMembers(specialKey);
		if typeof keys == "array" {
			for key, value in keys {
				if prefix && !starts_with(value, prefix) {
					unset(keys[key]);
				}
			}
		}

		return keys;
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
		var lastKey;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = this->_prefix . keyName;
		}

		if lastKey {
			return this->_getRedis()->exists(lastKey);
		}

		return false;
	}

	/**
	 * Increment of given $keyName by $value
	 *
	 * @param  string keyName
	 * @param  long value
	 * @return long
	 */
	public function increment(keyName = null, value = null)
	{
		var lastKey;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = this->_prefix . keyName;
			let this->_lastKey = lastKey;
		}

		if !value {
			let value = 1;
		}

		return this->_getRedis()->incrBy(lastKey, value);
	}

	/**
	 * Decrement of $keyName by given $value
	 *
	 * @param  string keyName
	 * @param  long value
	 * @return long
	 */
	public function decrement(keyName = null, value = null)
	{
		var lastKey;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = this->_prefix . keyName;
			let this->_lastKey = lastKey;
		}

		if !value {
			let value = 1;
		}

		return this->_getRedis()->decrBy(lastKey, value);
	}

	/**
	 * Immediately invalidates all existing items.
	 */
	public function flush() -> boolean
	{
		var specialKey, keys, key;

		if !fetch specialKey, this->_options["statsKey"] {
			throw new Exception("Unexpected inconsistency in options");
		}
		if specialKey == "" {
			throw new Exception("Cached keys need to be enabled to use this function (options['statsKey'] == '_PHCR')!");
		}

		let keys = this->_getRedis()->sMembers(specialKey);
		if typeof keys == "array" {
			for key in keys {
				this->_getRedis()->sRem(specialKey, key);
				this->_getRedis()->delete(key);
			}
		}

		return true;
	}
}
