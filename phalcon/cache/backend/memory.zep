
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 * Phalcon\Cache\Backend\Memory
 *
 * Stores content in memory. Data is lost when the request is finished
 *
 *<code>
 *	//Cache data
 *	$frontCache = new Phalcon\Cache\Frontend\Data();
 *
 *  $cache = new Phalcon\Cache\Backend\Memory($frontCache);
 *
 *	//Cache arbitrary data
 *	$cache->save('my-data', array(1, 2, 3, 4, 5));
 *
 *	//Get data
 *	$data = $cache->get('my-data');
 *
 *</code>
 */
class Memory extends Phalcon\Cache\Backend implements Phalcon\Cache\BackendInterface
{

	protected _data;

	/**
	 * Returns a cached content
	 *
	 * @param 	string keyName
	 * @param   long lifetime
	 * @return  mixed
	 */
	public function get(var keyName, lifetime=null)
	{
		var lastKey, cachedContent;

		if keyName === null {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = this->_prefix . keyName;
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
	public function save(var keyName=null, var content=null, lifetime=null, stopBuffer=true) -> void
	{
		var lastKey, frontend, cachedContent, preparedContent;

		if keyName === null {
			let lastKey = this->_lastKey;
		} else {
			let lastKey = this->_prefix . keyName;
		}

		if !lastKey {
			throw new Phalcon\Cache\Exception("The cache must be started first");
		}

		let frontend = this->_frontend;

		if content === null {
			let cachedContent = frontend->getContent();
		} else {
			let cachedContent = content;
		}

		let preparedContent = frontend->beforeStore(cachedContent),
			this->_data[lastKey] = preparedContent;

		if stopBuffer === true {
			frontend->stop();
		}

		if frontend->isBuffering() === true {
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
	public function delete(var keyName)
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
	public function queryKeys(var prefix=null)
	{

	}

	/**
	 * Checks if cache exists and it hasn't expired
	 *
	 * @param  string|int keyName
	 * @param  long lifetime
	 * @return boolean
	 */
	public function exists(var keyName=null, lifetime=null)
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

}
