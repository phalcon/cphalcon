
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
class Libmemcached extends \Phalcon\Cache\Backend implements \Phalcon\Cache\BackendInterface
{

	protected _memcache = null;

	/**
	 * Phalcon\Cache\Backend\Memcache constructor
	 *
	 * @param	Phalcon\Cache\FrontendInterface frontend
	 * @param	array options
	 */
	public function __construct(<\Phalcon\Cache\FrontendInterface> frontend, options=null)
	{
		var servers;

		if typeof options != "array" {
			let options = [];
		}

		if !isset options["servers"] {
                        let servers = [0: ["host": "127.0.0.1", "port": 11211, "weigth": 1]];

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
		var options, memcache, client, servers, option, res;

		let options = this->_options;
		let memcache = new \Memcached();

		if !fetch servers, options["servers"] {
			throw new \Phalcon\Cache\Exception("Servers must be an array");
		}

		if typeof servers != "array" {
			throw new \Phalcon\Cache\Exception("Servers must be an array");
		}

		if !memcache->addServers(servers) {
			throw new \Phalcon\Cache\Exception("Cannot connect to Memcached server");
		}

		let client = options["client"];
		if typeof client == "array" {
			memcache->setOptions(client);
		} else {
			throw new Exception("Client options must be instance of array");
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
	public function get(keyName, lifetime=null)
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
			this->_frontend->afterRetrieve(cachedContent);
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
	public function save(keyName=null, content=null, lifetime=null, stopBuffer=true)
	{
		var lastKey, frontend, memcache, cachedContent, preparedContent, tmp, tt1, success, options,
			specialKey, keys, isBuffering;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = this->_prefix . keyName;
		}

		if !lastKey {
			throw new \Phalcon\Cache\Exception("The cache must be started first");
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
			throw new \Phalcon\Cache\Exception("Failed storing data in memcached");
		}

		let options = this->_options;

		if !fetch specialKey, options["statsKey"] {
			throw new \Phalcon\Cache\Exception("Unexpected inconsistency in options");
		}

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

		let isBuffering = frontend->isBuffering();

		if !stopBuffer {
			frontend->stop();
		}

		if isBuffering == true {
			echo cachedContent;
		}

		let this->_started = false;
	}

	/**
	 * Increment of a given key, by number $value
	 *
	 * @param  string $keyName
	 * @param  long $value
	 * @return mixed
	 */
	public function increment(keyName=null, value=null)
	{
		var memcache, prefixedKey, cachedContent;

		if !value {
			let value = 1;
		}

		let memcache = this->_memcache;
		if typeof memcache != "object" {
			this->_connect();
			let memcache = this->_memcache;
		}

		let prefixedKey = this->_prefix . keyName;
		let this->_lastKey = prefixedKey;
		let cachedContent = memcache->increment(prefixedKey, value);

		if !cachedContent {
			return null;
		}

		return cachedContent;
	}

	/**
	 * Decrement of a given key, by number $value
	 *
	 * @param  string keyName
	 * @param  long value
	 * @return mixed
	 */
	public function decrement(keyName=null, value=null)
	{
		var memcache, prefixedKey, cachedContent;

		if !value {
			let value = 1;
		}

		let memcache = this->_memcache;
		if typeof memcache != "object" {
			this->_connect();
			let memcache = this->_memcache;
		}

		let prefixedKey = this->_prefix . keyName;
		let this->_lastKey = prefixedKey;
		let cachedContent = memcache->decrement(prefixedKey, value);

		if !cachedContent {
			return null;
		}

		return cachedContent;
	}

	/**
	 * Deletes a value from the cache by its key
	 *
	 * @param int|string keyName
	 * @return boolean
	 */
	public function delete(keyName)
	{
		var memcache, prefixedKey, options, keys, specialKey;

		let memcache = this->_memcache;
		if typeof memcache != "object" {
			this->_connect();
			let memcache = this->_memcache;
		}

		let prefixedKey = this->_prefix . keyName;
		let options = this->_options;

		if !fetch specialKey, options["statsKey"] {
			throw new \Phalcon\Cache\Exception("Unexpected inconsistency in options");
		}

		let keys = memcache->get(specialKey);
		if typeof keys == "array" {
			unset keys[prefixedKey];
			memcache->set(specialKey, keys);
		}

		/**
		 * Delete the key from memcached
		 */
		memcache->delete(prefixedKey);
	}

	/**
	 * Query the existing cached keys
	 *
	 * @param string prefix
	 * @return array
	 */
	public function queryKeys(prefix=null)
	{
		var memcache, options, keys, specialKey, key;

		let memcache = this->_memcache;

		if typeof memcache != "object" {
			this->_connect();
			let memcache = this->_memcache;
		}

		let options = this->_options;

		if !fetch specialKey, options["statsKey"] {
			throw new \Phalcon\Cache\Exception("Unexpected inconsistency in options");
		}

		/**
		 * Get the key from memcached
		 */
		let keys = memcache->get(specialKey);
		if typeof keys == "array" {
			for key in keys {
				if prefix && !starts_with(key, prefix) {
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
	public function exists(keyName=null, lifetime=null) -> boolean
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
	 * Immediately invalidates all existing items.
	 *
	 * @return boolean
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
			throw new \Phalcon\Cache\Exception("Unexpected inconsistency in options");
		}

		/**
		 * Get the key from memcached
		 */
		let keys = memcache->get(specialKey);
		if typeof keys == "array" {
			for key in keys {
				memcache->delete(key);
			}
			memcache->set(specialKey, keys);
		}
		return true;
	}

}
