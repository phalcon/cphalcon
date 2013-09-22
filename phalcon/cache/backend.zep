
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

namespace Phalcon\Cache;

/**
 * Phalcon\Cache\Backend
 *
 * This class implements common functionality for backend adapters. A backend cache adapter may extend this class
 */
abstract class Backend
{

	protected _frontend;

	protected _options;

	protected _prefix = "";

	protected _lastKey = "";

	protected _lastLifetime = null;

	protected _fresh = false;

	protected _started = false;

	/**
	 * Phalcon\Cache\Backend constructor
	 *
	 * @param	Phalcon\Cache\FrontendInterface frontend
	 * @param	array options
	 */
	public function __construct(frontend, options=null)
	{
		var prefix;

		if typeof frontend != "object" {
			throw new Phalcon\Cache\Exception("Frontend must be an Object");
		}

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
	 * Starts a cache. The keyname allows to identify the created fragment
	 *
	 * @param int|string keyName
	 * @param   long lifetime
	 * @return  mixed
	 */
	public function start(keyName, lifetime=null)
	{
		var existingCache, fresh, frontend;

		/**
		 * Get the cache content verifying if it was expired
		 */
		let existingCache = this->{"get"}(keyName, lifetime);
		if existingCache === null {
			let fresh = true,
				frontend = this->_frontend;
			frontend->start();
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
	 *
	 * @param boolean stopBuffer
	 */
	public function stop(stopBuffer=true)
	{
		var frontend;
		if stopBuffer === true {
			let frontend = this->_frontend;
			frontend->stop();
		}
		let this->_started = false;
	}

	/**
	 * Returns front-end instance adapter related to the back-end
	 *
	 * @return mixed
	 */
	public function getFrontend()
	{
		return this->_frontend;
	}

	/**
	 * Returns the backend options
	 *
	 * @return array
	 */
	public function getOptions()
	{
		return this->_options;
	}

	/**
	 * Checks whether the last cache is fresh or cached
	 *
	 * @return boolean
	 */
	public function isFresh()
	{
		return this->_fresh;
	}

	/**
	 * Checks whether the cache has starting buffering or not
	 *
	 * @return boolean
	 */
	public function isStarted()
	{
		return this->_started;
	}

	/**
	 * Sets the last key used in the cache
	 *
	 * @param string lastKey
	 */
	public function setLastKey(lastKey)
	{
		let this->_lastKey = lastKey;
	}

	/**
	 * Gets the last key stored by the cache
	 *
	 * @return string
	 */
	public function getLastKey()
	{
		return this->_lastKey;
	}

	/**
	 * Gets the last lifetime set
	 *
	 * @return int
	 */
	public function getLifetime()
	{
		return this->_lastLifetime;
	}

}
