
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

namespace Phalcon\Cache\Frontend;

use Phalcon\Cache\FrontendInterface;

/**
 * Phalcon\Cache\Frontend\Output
 *
 * Allows to cache output fragments captured with ob_* functions
 *
 *<code>
 * <?php
 *
 * //Create an Output frontend. Cache the files for 2 days
 * $frontCache = new \Phalcon\Cache\Frontend\Output(array(
 *   "lifetime" => 172800
 * ));
 *
 * // Create the component that will cache from the "Output" to a "File" backend
 * // Set the cache file directory - it's important to keep the "/" at the end of
 * // the value for the folder
 * $cache = new \Phalcon\Cache\Backend\File($frontCache, array(
 *     "cacheDir" => "../app/cache/"
 * ));
 *
 * // Get/Set the cache file to ../app/cache/my-cache.html
 * $content = $cache->start("my-cache.html");
 *
 * // If $content is null then the content will be generated for the cache
 * if ($content === null) {
 *
 *     //Print date and time
 *     echo date("r");
 *
 *     //Generate a link to the sign-up action
 *     echo Phalcon\Tag::linkTo(
 *         array(
 *             "user/signup",
 *             "Sign Up",
 *             "class" => "signup-button"
 *         )
 *     );
 *
 *     // Store the output into the cache file
 *     $cache->save();
 *
 * } else {
 *
 *     // Echo the cached output
 *     echo $content;
 * }
 *</code>
 */
class Output implements FrontendInterface
{

	protected _buffering = false;

	protected _frontendOptions;

	/**
	 * Phalcon\Cache\Frontend\Output constructor
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
		return this->_buffering;
	}

	/**
	 * Starts output frontend. Currently, does nothing
	 */
	public function start() -> void
	{
		let this->_buffering = true;
		ob_start();
	}

	/**
	 * Returns output cached content
	 *
	 * @return string
	 */
	public function getContent()
	{
		if this->_buffering {
			return ob_get_contents();
		}

		return null;
	}

	/**
	 * Stops output frontend
	 */
	public function stop() -> void
	{
		if this->_buffering {
			ob_end_clean();
		}

		let this->_buffering = false;
	}

	/**
	 * Serializes data before storing them
	 *
	 * @param mixed data
	 * @return string
	 */
	public function beforeStore(var data) -> string
	{
		return data;
	}

	/**
	 * Unserializes data after retrieval
	 *
	 * @param mixed data
	 * @return mixed
	 */
	public function afterRetrieve(var data)
	{
		return data;
	}
}
