
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

namespace Phalcon\Cache;

use Phalcon\Cache\Exception;
use Phalcon\Cache\BackendInterface;

/**
 * Phalcon\Cache\Multiple
 *
 * Allows to read to chained backend adapters writing to multiple backends
 *
 *<code>
 *   use Phalcon\Cache\Frontend\Data as DataFrontend,
 *       Phalcon\Cache\Multiple,
 *       Phalcon\Cache\Backend\Apc as ApcCache,
 *       Phalcon\Cache\Backend\Memcache as MemcacheCache,
 *       Phalcon\Cache\Backend\File as FileCache;
 *
 *   $ultraFastFrontend = new DataFrontend(array(
 *       "lifetime" => 3600
 *   ));
 *
 *   $fastFrontend = new DataFrontend(array(
 *       "lifetime" => 86400
 *   ));
 *
 *   $slowFrontend = new DataFrontend(array(
 *       "lifetime" => 604800
 *   ));
 *
 *   //Backends are registered from the fastest to the slower
 *   $cache = new Multiple(array(
 *       new ApcCache($ultraFastFrontend, array(
 *           "prefix" => 'cache',
 *       )),
 *       new MemcacheCache($fastFrontend, array(
 *           "prefix" => 'cache',
 *           "host" => "localhost",
 *           "port" => "11211"
 *       )),
 *       new FileCache($slowFrontend, array(
 *           "prefix" => 'cache',
 *           "cacheDir" => "../app/cache/"
 *       ))
 *   ));
 *
 *   //Save, saves in every backend
 *   $cache->save('my-key', $data);
 *</code>
 */
class Multiple
{

	protected _backends;

	/**
	 * Phalcon\Cache\Multiple constructor
	 *
	 * @param	Phalcon\Cache\BackendInterface[] backends
	 */
	public function __construct(backends = null)
	{
		if typeof backends != "null" {
			if typeof backends != "array" {
				throw new Exception("The backends must be an array");
			}
			let this->_backends = backends;
		}
	}

	/**
	 * Adds a backend
	 */
	public function push(<BackendInterface> backend) -> <Multiple>
	{
		let this->_backends[] = backend;
		return this;
	}

	/**
	 * Returns a cached content reading the internal backends
	 *
	 * @param 	string|int keyName
	 * @param   long lifetime
	 * @return  mixed
	 */
	public function get(var keyName, lifetime = null)
	{
		var backend, content;

		for backend in this->_backends {
			let content = backend->get(keyName, lifetime);
			if content != null {
				return content;
			}
		}

		return null;
	}

	/**
	 * Starts every backend
	 *
	 * @param string|int keyName
	 * @param long lifetime
	 */
	public function start(var keyName, lifetime = null) -> void
	{
		var backend;

		for backend in this->_backends {
			backend->start(keyName, lifetime);
		}
	}

	/**
	* Stores cached content into all backends and stops the frontend
	*
	* @param string keyName
	* @param string content
	* @param long lifetime
	* @param boolean stopBuffer
	*/
	public function save(var keyName = null, content = null, lifetime = null, stopBuffer = null) -> void
	{
		var backend;

		for backend in this->_backends {
			backend->save(keyName, content, lifetime, stopBuffer);
		}
	}

	/**
	 * Deletes a value from each backend
	 *
	 * @param string|int keyName
	 * @return boolean
	 */
	public function delete(var keyName) -> boolean
	{
		var backend;

		for backend in this->_backends {
			backend->delete(keyName);
		}

		return true;
	}

	/**
	 * Checks if cache exists in at least one backend
	 *
	 * @param  string|int keyName
	 * @param  long lifetime
	 * @return boolean
	 */
	public function exists(var keyName = null, lifetime = null) -> boolean
	{
		var backend;

		for backend in this->_backends {
			if backend->exists(keyName, lifetime) == true {
				return true;
			}
		}

		return false;
	}
}
