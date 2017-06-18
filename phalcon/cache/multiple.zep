
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

namespace Phalcon\Cache;

use Phalcon\Cache\Exception;
use Phalcon\Cache\BackendInterface;

/**
 * Phalcon\Cache\Multiple
 *
 * Allows to read to chained backend adapters writing to multiple backends
 *
 *<code>
 * use Phalcon\Cache\Frontend\Data as DataFrontend;
 * use Phalcon\Cache\Multiple;
 * use Phalcon\Cache\Backend\Apc as ApcCache;
 * use Phalcon\Cache\Backend\Memcache as MemcacheCache;
 * use Phalcon\Cache\Backend\File as FileCache;
 *
 * $ultraFastFrontend = new DataFrontend(
 *     [
 *         "lifetime" => 3600,
 *     ]
 * );
 *
 * $fastFrontend = new DataFrontend(
 *     [
 *         "lifetime" => 86400,
 *     ]
 * );
 *
 * $slowFrontend = new DataFrontend(
 *     [
 *         "lifetime" => 604800,
 *     ]
 * );
 *
 * //Backends are registered from the fastest to the slower
 * $cache = new Multiple(
 *     [
 *         new ApcCache(
 *             $ultraFastFrontend,
 *             [
 *                 "prefix" => "cache",
 *             ]
 *         ),
 *         new MemcacheCache(
 *             $fastFrontend,
 *             [
 *                 "prefix" => "cache",
 *                 "host"   => "localhost",
 *                 "port"   => "11211",
 *             ]
 *         ),
 *         new FileCache(
 *             $slowFrontend,
 *             [
 *                 "prefix"   => "cache",
 *                 "cacheDir" => "../app/cache/",
 *             ]
 *         ),
 *     ]
 * );
 *
 * //Save, saves in every backend
 * $cache->save("my-key", $data);
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
	 * @param string|int keyName
	 * @param int lifetime
	 * @return mixed
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
	 * @param int lifetime
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
	* @param int lifetime
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
	 * @param  int lifetime
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

	/**
	 * Flush all backend(s)
	 */
	public function flush() -> boolean
	{
		var backend;

		for backend in this->_backends {
			backend->flush();
		}

		return true;
	}
}
