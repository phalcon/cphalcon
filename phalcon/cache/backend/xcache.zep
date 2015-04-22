
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
 * Phalcon\Cache\Backend\Xcache
 *
 * Allows to cache output fragments, PHP data and raw data using an XCache backend
 *
 *<code>
 *	//Cache data for 2 days
 *	$frontCache = new \Phalcon\Cache\Frontend\Data(array(
 *		'lifetime' => 172800
 *	));
 *
 *  $cache = new \Phalcon\Cache\Backend\Xcache($frontCache, array(
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
class Xcache extends Backend implements BackendInterface
{

	/**
	 * Phalcon\Cache\Backend\Xcache constructor
	 *
	 * @param Phalcon\Cache\FrontendInterface frontend
	 * @param array options
	 */
	public function __construct(<FrontendInterface> frontend, options = null)
	{
		if typeof options != "array" {
			let options = [];
		}

		if !isset options["statsKey"] {
			let options["statsKey"] = "_PHCX";
		}

		parent::__construct(frontend, options);
	}

	/**
	 * Returns a cached content
	 *
	 * @param int|string keyName
	 * @param   long lifetime
	 * @return  mixed
	 */
	public function get(var keyName, lifetime = null)
	{
		var frontend, prefixedKey, cachedContent;

		let frontend = this->_frontend;
		let prefixedKey = "_PHCX" . this->_prefix . keyName;
		let this->_lastKey = prefixedKey;
		let cachedContent = xcache_get(prefixedKey);

		if !cachedContent {
			return null;
		}

		if is_numeric(cachedContent) {
			return cachedContent;
		} else {
			return frontend->afterRetrieve(cachedContent);
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
		var lastKey, frontend, cachedContent, preparedContent, tmp, tt1, success, isBuffering,
			options, keys, specialKey;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = "_PHCX" . this->_prefix . keyName;
		}

		if !lastKey {
			throw new Exception("Cache must be started first");
		}

		let frontend = this->_frontend;
		if !content {
			let cachedContent = frontend->getContent();
		} else {
			let cachedContent = content;
		}

		if !is_numeric(cachedContent) {
			let preparedContent = frontend->beforeStore(cachedContent);
		}

		/**
		 * Take the lifetime from the frontend or read it from the set in start()
		 */
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
			let success = xcache_set(lastKey, cachedContent, tt1);
		} else {
			let success = xcache_set(lastKey, preparedContent, tt1);
		}

		let isBuffering = frontend->isBuffering();

		if stopBuffer === true {
			frontend->stop();
		}

		if isBuffering === true {
			echo cachedContent;
		}

		let this->_started = false;

		if success {
			let options = this->_options;

			if !fetch specialKey, this->_options["statsKey"] {
				throw new Exception("Unexpected inconsistency in options");
			}

			/**
			 * xcache_list() is available only to the administrator (unless XCache was
			 * patched). We have to update the list of the stored keys.
			 */
			let keys = xcache_get(specialKey);
			if typeof keys != "array" {
				let keys = [];
			}

			let keys[lastKey] = tt1;
			xcache_set(specialKey, keys);
		}
	}

	/**
	 * Deletes a value from the cache by its key
	 *
	 * @param int|string keyName
	 * @return boolean
	 */
	public function delete(var keyName)
	{
		var prefixedKey, specialKey, keys;

		let prefixedKey = "_PHCX" . this->_prefix . keyName;

		if !fetch specialKey, this->_options["statsKey"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		let keys = xcache_get(specialKey);
		if typeof keys != "array" {
			let keys = [];
		}

		unset keys[prefixedKey];

		xcache_set(specialKey, keys);
	}

	/**
	 * Query the existing cached keys
	 *
	 * @param string prefix
	 * @return array
	 */
	public function queryKeys(prefix = null) -> array
	{
		var options, prefixed, specialKey, keys, retval, key, realKey;

		if !prefix {
			let prefixed = "_PHCX";
		} else {
			let prefixed = "_PHCX" . prefix;
		}

		let options = this->_options;

		if !fetch specialKey, this->_options["statsKey"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		let retval = [];

		/**
		* Get the key from XCache (we cannot use xcache_list() as it is available only to
		* the administrator)
		*/
		let keys = xcache_get(specialKey);
		if typeof keys == "array" {
			for key, _ in keys {
				if starts_with(key, prefixed) {
					let realKey = substr(key, 5);
					let retval[] = realKey;
				}
			}
		}

		return retval;
	}

	/**
	 * Checks if cache exists and it isn't expired
	 *
	 * @param string keyName
	 * @param   long lifetime
	 * @return boolean
	 */
	public function exists(var keyName = null, lifetime = null) -> boolean
	{
		var lastKey;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = "_PHCX" . this->_prefix . keyName;
		}

		if lastKey {
			return xcache_isset(lastKey);
		}
		return false;
	}

	/**
	* Atomic increment of a given key, by number $value
	*
	* @param  string keyName
	* @param  long value
	* @return mixed
	*/
	public function increment(var keyName, long value = 1)
	{
		var lastKey, newVal, origVal;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = "_PHCX" . this->_prefix . keyName;
		}

		if !lastKey {
			throw new Exception("Cache must be started first");
		}

		if function_exists("xcache_inc") {
			let newVal = xcache_inc(lastKey, value);
		} else {
			let origVal = xcache_get(lastKey);
			let newVal = origVal - value;
			xcache_set(lastKey, newVal);
		}

		return newVal;
	}

	/**
	 * Atomic decrement of a given key, by number $value
	 *
	 * @param  string keyName
	 * @param  long value
	 * @return mixed
	 */
	public function decrement(keyName, long value = 1)
	{
		var lastKey, newVal, origVal, success;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = "_PHCX" . this->_prefix . keyName;
		}

		if !lastKey {
			throw new Exception("Cache must be started first");
		}

		if function_exists("xcache_dec") {
			let newVal = xcache_dec(lastKey, value);
		} else {
			let origVal = xcache_get(lastKey);
			let newVal = origVal - value;
			let success = xcache_set(lastKey, newVal);
		}

		return newVal;
	}

	/**
	 * Immediately invalidates all existing items.
	 */
	public function flush() -> boolean
	{
		var options, specialKey, keys, key;

		let options = this->_options;

		if !fetch specialKey, this->_options["statsKey"] {
			throw new Exception("Unexpected inconsistency in options");
		}

		let keys = xcache_get(specialKey);

		if typeof keys == "array" {
			for key, _ in keys {
				unset keys[key];
				xcache_unset(key);
			}
			xcache_set(specialKey, keys);
		}

		return true;
	}
}
