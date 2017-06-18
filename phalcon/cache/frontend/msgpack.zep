
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
use Phalcon\Cache\Exception;

/**
 * Phalcon\Cache\Frontend\Msgpack
 *
 * Allows to cache native PHP data in a serialized form using msgpack extension
 * This adapter uses a Msgpack frontend to store the cached content and requires msgpack extension.
 *
 * @link https://github.com/msgpack/msgpack-php
 *
 *<code>
 * use Phalcon\Cache\Backend\File;
 * use Phalcon\Cache\Frontend\Msgpack;
 *
 * // Cache the files for 2 days using Msgpack frontend
 * $frontCache = new Msgpack(
 *     [
 *         "lifetime" => 172800,
 *     ]
 * );
 *
 * // Create the component that will cache "Msgpack" to a "File" backend
 * // Set the cache file directory - important to keep the "/" at the end of
 * // of the value for the folder
 * $cache = new File(
 *     $frontCache,
 *     [
 *         "cacheDir" => "../app/cache/",
 *     ]
 * );
 *
 * $cacheKey = "robots_order_id.cache";
 *
 * // Try to get cached records
 * $robots = $cache->get($cacheKey);
 *
 * if ($robots === null) {
 *     // $robots is null due to cache expiration or data do not exist
 *     // Make the database call and populate the variable
 *     $robots = Robots::find(
 *         [
 *             "order" => "id",
 *         ]
 *     );
 *
 *     // Store it in the cache
 *     $cache->save($cacheKey, $robots);
 * }
 *
 * // Use $robots
 * foreach ($robots as $robot) {
 *     echo $robot->name, "\n";
 * }
 *</code>
 */
class Msgpack extends Data implements FrontendInterface
{
	/**
	 * Phalcon\Cache\Frontend\Msgpack constructor
	 *
	 * @param array frontendOptions
	 */
	public function __construct(frontendOptions = null)
	{
		var lifetime;

		if fetch lifetime, frontendOptions["lifetime"] {
			if typeof lifetime !== "integer" {
				throw new Exception("Option 'lifetime' must be an integer");
			}
		}
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
	 */
	public function getContent() -> null
	{
		return null;
	}

	/**
	 * Stops output frontend
	 */
	public function stop()
	{
	}

	/**
	 * Serializes data before storing them
	 */
	public function beforeStore(var data) -> string
	{
		return msgpack_pack(data);
	}

	/**
	 * Unserializes data after retrieval
	 */
	public function afterRetrieve(var data) -> var
	{
		if is_numeric(data) {
			return data;
		}

		return msgpack_unpack(data);
	}
}
