
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
use Phalcon\Cache\Exception;

/**
 * Phalcon\Cache\Backend\Memory
 *
 * Stores content in memory. Data is lost when the request is finished
 *
 *<code>
 *	//Cache data
 *	$frontCache = new \Phalcon\Cache\Frontend\Data();
 *
 *  $cache = new \Phalcon\Cache\Backend\Memory($frontCache);
 *
 *	//Cache arbitrary data
 *	$cache->save('my-data', array(1, 2, 3, 4, 5));
 *
 *	//Get data
 *	$data = $cache->get('my-data');
 *
 *</code>
 */
class Memory extends Backend implements BackendInterface, \Serializable
{

	protected _data;

	/**
	 * Returns a cached content
	 *
	 * @param 	string keyName
	 * @param   long lifetime
	 * @return  mixed
	 */
	public function get(var keyName, lifetime = null)
	{
		var lastKey, cachedContent;

		if keyName === null {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = this->_prefix . keyName, this->_lastKey = lastKey;
		}

		if !fetch cachedContent, this->_data[lastKey] {
			return null;
		}

		if cachedContent === null {
			return null;
		}

		return this->_frontend->afterRetrieve(cachedContent);
	}

	/**
	 * Stores cached content into the backend and stops the frontend
	 *
	 * @param string keyName
	 * @param string content
	 * @param long lifetime
	 * @param boolean stopBuffer
	 */
	public function save(var keyName = null, var content = null, lifetime = null, boolean stopBuffer = true) -> void
	{
		var lastKey, frontend, cachedContent, preparedContent, isBuffering;

		if keyName === null {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = this->_prefix . keyName;
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

		let preparedContent = frontend->beforeStore(cachedContent),
			this->_data[lastKey] = preparedContent;

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
	 * @param string keyName
	 * @return boolean
	 */
	public function delete(var keyName) -> boolean
	{
		var key;

		let key = this->_prefix . keyName;
		if isset this->_data[key] {
			unset this->_data[key];
			return true;
		}

		return false;
	}

	/**
	 * Query the existing cached keys
	 *
	 * @param string|int prefix
	 * @return array
	 */
	public function queryKeys(var prefix = null) -> array
	{
		var data, index, keys;

		let data = this->_data;
		if typeof data == "array" {
			if !prefix {
				let keys = (array) array_keys(data);
			} else {
			    	let keys = [];
				for index, _ in data {
					let keys[] = index;
				}
			}
		}
		return keys;
	}

	/**
	 * Checks if cache exists and it hasn't expired
	 *
	 * @param  string|int keyName
	 * @param  long lifetime
	 * @return boolean
	 */
	public function exists(var keyName = null, lifetime = null) -> boolean
	{
		var lastKey;

		if keyName === null {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = this->_prefix . keyName;
		}

		if lastKey {
			if isset this->_data[lastKey] {
				return true;
			}
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
		var lastKey, prefix, cachedContent, result;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let prefix = this->_prefix;
			let lastKey = prefix . keyName;
			let this->_lastKey = lastKey;
		}

		if !fetch cachedContent, this->_data[lastKey] {
			return null;
		}

		if !cachedContent {
			return null;
		}

		if !value {
			let value = 1;
		}

		let result = cachedContent + value;
		let this->_data[lastKey] = result;

		return result;
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
		var lastKey, prefix, cachedContent, result;

		if !keyName {
			let lastKey = this->_lastKey;
		} else {
			let prefix = this->_prefix;
			let lastKey = prefix . keyName;
			let this->_lastKey = lastKey;
		}

		if !fetch cachedContent, this->_data[lastKey] {
			return null;
		}

		if !cachedContent {
			return null;
		}

		if !value {
			let value = 1;
		}

		let result = cachedContent - value;
		let this->_data[lastKey] = result;

		return result;
	}

	/**
	 * Immediately invalidates all existing items.
	 */
	public function flush() -> boolean
	{
		let this->_data = null;
		return true;
	}

	/**
	 * Required for interface \Serializable
	 */
	public function serialize() -> string
	{
		return serialize([
			"frontend": this->_frontend
		]);
	}

	/**
	 * Required for interface \Serializable
	 */
	public function unserialize(var data)
	{
		var unserialized;

		let unserialized = unserialize(data);
		if typeof unserialized != "array" {
			throw new \Exception("Unserialized data must be an array");
		}

		let this->_frontend = unserialized["frontend"];
	}
}
