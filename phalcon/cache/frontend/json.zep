
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

namespace Phalcon\Cache\Frontend;

use Phalcon\Cache\FrontendInterface;

/**
 * Phalcon\Cache\Frontend\Json
 *
 * Allows to cache data converting/deconverting them to JSON.
 *
 * This adapter uses the json_encode/json_decode PHP's functions
 *
 * As the data is encoded in JSON other systems accessing the same backend could
 * process them
 *
 *<code>
 *<?php
 *
 * // Cache the data for 2 days
 * $frontCache = new \Phalcon\Cache\Frontend\Json(
 *     [
 *         "lifetime" => 172800,
 *     ]
 * );
 *
 * // Create the Cache setting memcached connection options
 * $cache = new \Phalcon\Cache\Backend\Memcache(
 *     $frontCache,
 *     [
 *         "host"       => "localhost",
 *         "port"       => 11211,
 *         "persistent" => false,
 *     ]
 * );
 *
 * // Cache arbitrary data
 * $cache->save("my-data", [1, 2, 3, 4, 5]);
 *
 * // Get data
 * $data = $cache->get("my-data");
 *</code>
 */
class Json implements FrontendInterface
{

	protected _frontendOptions;

	/**
	 * Phalcon\Cache\Frontend\Base64 constructor
	 *
	 * @param array frontendOptions
	 */
	public function __construct(frontendOptions = null)
	{
		let this->_frontendOptions = frontendOptions;
	}

	/**
	 * Returns the cache lifetime
	 */
	public function getLifetime() -> int
	{
		var options, lifetime;
		let options = this->_frontendOptions;
		if typeof options == "array" {
			if fetch lifetime, options["lifetime"] {
				return lifetime;
			}
		}
		return 1;
	}

	/**
	 * Check whether if frontend is buffering output
	 */
	public function isBuffering() -> boolean
	{
		return false;
	}

	/**
	 * Starts output frontend. Actually, does nothing
	 */
	public function start()
	{

	}

	/**
	 * Returns output cached content
	 *
	 * @return string
	 */
	public function getContent()
	{
		return null;
	}

	/**
	 * Stops output frontend
	 */
	public function stop() -> void
	{

	}

	/**
	 * Serializes data before storing them
	 */
	public function beforeStore(var data) -> string
	{
		return json_encode(data);
	}

	/**
	 * Unserializes data after retrieval
	 */
	public function afterRetrieve(var data) -> var
	{

		return json_decode(data);
	}
}
