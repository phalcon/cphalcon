
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

namespace Phalcon\Mvc;

/**
 * Phalcon\Mvc\ViewInterface
 *
 * Interface for Phalcon\Mvc\View and Phalcon\Mvc\View\Simple
 */
interface ViewBaseInterface
{

	/**
	 * Sets views directory. Depending of your platform, always add a trailing slash or backslash
	 */
	public function setViewsDir(string! viewsDir);

	/**
	 * Gets views directory
	 */
	public function getViewsDir() -> string;

	/**
	 * Adds parameters to views (alias of setVar)
	 *
	 * @param string key
	 * @param mixed value
	 */
	public function setParamToView(string! key, value);

	/**
	 * Adds parameters to views
	 *
	 * @param string key
	 * @param mixed value
	 */
	public function setVar(string! key, value);

	/**
	 * Returns parameters to views
	 */
	public function getParamsToView() -> array;

	/**
	 * Returns the cache instance used to cache
	 */
	public function getCache() -> <\Phalcon\Cache\BackendInterface>;

	/**
	 * Cache the actual view render to certain level
	 *
	 * @param boolean|array options
	 */
	public function cache(options = true);

	/**
	 * Externally sets the view content
	 */
	public function setContent(string! content);

	/**
	 * Returns cached output from another view stage
	 */
	public function getContent() -> string;
}
