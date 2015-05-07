
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

use Phalcon\Cache\Exception;
use Phalcon\Cache\Backend;
use Phalcon\Cache\BackendInterface;

/**
 * Phalcon\Cache\Backend\Apc
 *
 * Allows to cache output fragments, PHP data and raw data using an APC backend
 *
 *<code>
 *	//Cache data for 2 days
 *	$frontCache = new \Phalcon\Cache\Frontend\Data(array(
 *		'lifetime' => 172800
 *	));
 *
 *  $cache = new \Phalcon\Cache\Backend\Apc($frontCache, array(
 *      'prefix' => 'app-data'
 *  ));
 *
 *	//Cache arbitrary data
 *	$cache->save('my-data', array(1, 2, 3, 4, 5));
 *
 *	//Get data
 *	$data = $cache->get('my-data');
 *
 *</code>
 */
class Apc extends Backend implements BackendInterface
{

	/**
	 * Returns a cached content
	 *
	 * @param 	string|long keyName
	 * @param   long lifetime
	 * @return  mixed
	 */
	public function get(string! keyName, var lifetime = null)
	{
		var prefixedKey, cachedContent;

		let prefixedKey = "_PHCA" . this->_prefix . keyName,
			this->_lastKey = prefixedKey;

		let cachedContent = apc_fetch(prefixedKey);
		if cachedContent === false {
			return null;
		}

		return this->_frontend->afterRetrieve(cachedContent);
	}

	/**
	 * Stores cached content into the APC backend and stops the frontend
	 *
	 * @param string|long keyName
	 * @param string content
	 * @param long lifetime
	 * @param boolean stopBuffer
	 */
	public function save(var keyName = null, var content = null, var lifetime = null, boolean stopBuffer = true)
	{
		var lastKey, frontend, cachedContent, preparedContent, ttl, isBuffering;

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

		let preparedContent = frontend->beforeStore(cachedContent);

		/**
		 * Take the lifetime from the frontend or read it from the set in start()
		 */
		if lifetime === null {
			let lifetime = this->_lastLifetime;
			if lifetime === null {
				let ttl = frontend->getLifetime();
			} else {
				let ttl = lifetime;
			}
		} else {
			let ttl = lifetime;
		}

		/**
		 * Call apc_store in the PHP userland since most of the time it isn't available at compile time
		 */
		apc_store(lastKey, preparedContent, ttl);

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
	 * Increment of a given key, by number $value
	 *
	 * @param  string keyName
	 * @param  long value
	 * @return mixed
	 */
	public function increment(keyName = null, int value = 1)
	{
		var prefixedKey, cachedContent, result;

		let prefixedKey = "_PHCA" . this->_prefix . keyName;
		let this->_lastKey = prefixedKey;

		if function_exists("apc_inc") {
			let result = apc_inc(prefixedKey, value);
			return result;
		} else {
			let cachedContent = apc_fetch(prefixedKey);

			if is_numeric(cachedContent) {
				let result = cachedContent + value;
				this->save(keyName, result);
				return result;
			} else {
				return false;
			}
		}
	}

	/**
	 * Decrement of a given key, by number $value
	 *
	 * @param  string keyName
	 * @param  long value
	 * @return mixed
	 */
	public function decrement(keyName = null, int value = 1)
	{
		var lastKey, cachedContent, result;

		let lastKey = "_PHCA" . this->_prefix . keyName,
			this->_lastKey = lastKey;

		if function_exists("apc_dec") {
			return apc_dec(lastKey, value);
		} else {
			let cachedContent = apc_fetch(lastKey);

			if is_numeric(cachedContent) {
				let result = cachedContent - value;
				this->save(keyName, result);
				return result;
			} else {
				return false;
			}
		}
	}

	/**
	 * Deletes a value from the cache by its key
	 */
	public function delete(string! keyName) -> boolean
	{
		return apc_delete("_PHCA" . this->_prefix . keyName);
	}

	/**
	 * Query the existing cached keys
	 *
	 * @param string prefix
	 * @return array
	 */
	public function queryKeys(string prefix = null) -> array
	{
		var prefixPattern, apc, keys, key;

		if !prefix {
			let prefixPattern = "/^_PHCA/";
		} else {
			let prefixPattern = "/^_PHCA" . prefix . "/";
		}

		let keys = [],
			apc = new \APCIterator("user", prefixPattern);

		for key, _ in iterator(apc) {
			let keys[] = substr(key, 5);
		}

		return keys;
	}

	/**
	 * Checks if cache exists and it hasn't expired
	 *
	 * @param  string|long keyName
	 * @param  long lifetime
	 * @return boolean
	 */
	public function exists(keyName = null, lifetime = null) -> boolean
	{
		var lastKey;

		if keyName === null {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = "_PHCA" . this->_prefix . keyName;
		}

		if lastKey {
			if apc_exists(lastKey) !== false {
				return true;
			}
		}

		return false;
	}

	/**
 	 * Immediately invalidates all existing items.
	 */
	public function flush() -> boolean
	{
		var item;

		for item in iterator(new \APCIterator("user")) {
			apc_delete(item["key"]);
		}

		return true;
	}
}
