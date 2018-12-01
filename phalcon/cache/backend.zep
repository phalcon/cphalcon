
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

use Phalcon\Cache\FrontendInterface;

/**
 * Phalcon\Cache\Backend
 *
 * This class implements common functionality for backend adapters. A backend cache adapter may extend this class
 */
abstract class Backend implements BackendInterface
{

	/**
	 * @var Phalcon\Cache\FrontendInterface
	 */
	protected _frontend;

	/**
	 * @var array
	 */
	protected _options { get, set };

	/**
	 * @var string
	 */
	protected _prefix = "";

	/**
	 * @var string
	 */
	protected _lastKey = "" { get, set };

	protected _lastLifetime = null;

	protected _fresh = false;

	protected _started = false;

	/**
	 * Phalcon\Cache\Backend constructor
	 */
	public function __construct(<FrontendInterface> frontend, array options = [])
	{
		var prefix;

		/**
		 * A common option is the prefix
		 */
		if fetch prefix, options["prefix"] {
			let this->_prefix = prefix;
		}

		let this->_frontend = frontend,
			this->_options = options;
	}

	/**
	 * @var Phalcon\Cache\FrontendInterface
	 */
	public function getFrontend() -> <FrontendInterface>
	{
		return this->_frontend;
	}

	public function setFrontend(<FrontendInterface> frontend) -> void
	{
		let this->_frontend = frontend;
	}

	/**
	 * Starts a cache. The keyname allows to identify the created fragment
	 *
	 * @param   int|string keyName
	 * @param   int lifetime
	 * @return  mixed
	 */
	public function start(var keyName, lifetime = null)
	{
		var existingCache, fresh;

		/**
		 * Get the cache content verifying if it was expired
		 */
		let existingCache = this->{"get"}(keyName, lifetime);

		if existingCache === null {
			let fresh = true;
			this->_frontend->start();
		} else {
			let fresh = false;
		}

		let this->_fresh = fresh,
			this->_started = true;

		/**
		 * Update the last lifetime to be used in save()
		 */
		if typeof lifetime != "null" {
			let this->_lastLifetime = lifetime;
		}

		return existingCache;
	}

	/**
	 * Stops the frontend without store any cached content
	 */
	public function stop(bool stopBuffer = true) -> void
	{
		if stopBuffer === true {
			this->_frontend->stop();
		}
		let this->_started = false;
	}

	/**
	 * Checks whether the last cache is fresh or cached
	 */
	public function isFresh() -> bool
	{
		return this->_fresh;
	}

	/**
	 * Checks whether the cache has starting buffering or not
	 */
	public function isStarted() -> bool
	{
		return this->_started;
	}

	/**
	 * Gets the last lifetime set
	 */
	public function getLifetime() -> int
	{
		return this->_lastLifetime;
	}
}
