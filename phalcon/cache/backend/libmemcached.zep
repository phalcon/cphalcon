
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
use Phalcon\Cache\BackendInterface;
use Phalcon\Cache\FrontendInterface;
use Phalcon\Cache\Exception;

/**
 * Phalcon\Cache\Backend\Libmemcached
 *
 * Allows to cache output fragments, PHP data or raw data to a libmemcached backend
 *
 * This adapter uses the special memcached key "_PHCM" to store all the keys internally used by the adapter
 *
 *<code>
 *
 * // Cache data for 2 days
 * $frontCache = new \Phalcon\Cache\Frontend\Data(array(
 *    "lifetime" => 172800
 * ));
 *
 * //Create the Cache setting memcached connection options
 * $cache = new \Phalcon\Cache\Backend\Libmemcached($frontCache, array(
 *     "servers" => array(
 *         array('host' => 'localhost',
 *               'port' => 11211,
 *               'weight' => 1),
 *     ),
 *     "client" => array(
 *         Memcached::OPT_HASH => Memcached::HASH_MD5,
 *         Memcached::OPT_PREFIX_KEY => 'prefix.',
 *     )
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
class Libmemcached extends Backend implements BackendInterface
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
		var servers;

		if typeof options != "array" {
			let options = [];
		}

		if !isset options["servers"] {
			let servers = [0: ["host": "127.0.0.1", "port": 11211, "weight": 1]];
			let options["servers"] = servers;
		}

		if !isset options["statsKey"] {
			let options["statsKey"] = "_PHCM";
		}

		parent::__construct(frontend, options);
	}

	/**
	 * Create internal connection to memcached
	 */
	public function _connect()
	{
		var options, memcache, client, servers;

		let options = this->_options;
		let memcache = new \Memcached();

		if !fetch servers, options["servers"] {
			throw new Exception("Servers must be an array");
		}

		if typeof servers != "array" {
			throw new Exception("Servers must be an array");
		}

		if !memcache->addServers(servers) {
			throw new Exception("Cannot connect to Memcached server");
		}

		if fetch client, options["client"] {
			if typeof client !== "array" {
				throw new Exception("Client options must be instance of array");
			}
			memcache->setOptions(client);
		}

		let this->_memcache = memcache;
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
		var memcache, prefixedKey, cachedContent;

		let memcache = this->_memcache;
		if typeof memcache != "object" {
			this->_connect();
			let memcache = this->_memcache;
		}

		let prefixedKey = this->_prefix . keyName;
		let this->_lastKey = prefixedKey;

		let cachedContent = memcache->get(prefixedKey);
		if !cachedContent {
			return null;
		}

		if is_numeric(cachedContent) {
			return cachedContent;
		} else {
			return this->_frontend->afterRetrieve(cachedContent);
		}
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
		var lastKey, frontend, memcache, cachedContent, preparedContent, tmp, tt1, success, options,
			specialKey, keys, isBuffering;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = this->_prefix . keyName;
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

		if !content {
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

		if !lifetime {
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
			let success = memcache->set(lastKey, cachedContent, tt1);
		} else {
			let success = memcache->set(lastKey, preparedContent, tt1);
		}

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
	}

	/**
	 * Deletes a value from the cache by its key
	 *
	 * @param int|string keyName
	 * @return boolean
	 */
	public function delete(keyName)
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
	 * Query the existing cached keys
	 *
	 * @param string prefix
	 * @return array
	 */
	public function queryKeys(prefix = null)
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
			throw new Exception("Cached keys were disabled (options['statsKey'] == ''), you shouldn't use this function");
		}

		/**
		 * Get the key from memcached
		 */
		let keys = memcache->get(specialKey);
		if typeof keys == "array" {
			let keys = array_keys(keys);
			for key in keys {
				if prefix && !starts_with(key, prefix) {
					unset keys[key];
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
	 * @param  string keyName
	 * @param  long lifetime
	 * @return long
	 */
	public function increment(keyName = null, value = null)
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

		if !value {
			let value = 1;
		}

		return memcache->increment(lastKey, value);
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

		if !value {
			let value = 1;
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
			throw new Exception("Cached keys were disabled (options['statsKey'] == ''), flush of memcached phalcon-related keys isn't implemented for now");
		}

		/**
		 * Get the key from memcached
		 */
		let keys = memcache->get(specialKey);
		if typeof keys == "array" {
			for key in array_keys(keys) {
				memcache->delete(key);
			}
			memcache->set(specialKey, keys);
		}

		return true;
	}
}
