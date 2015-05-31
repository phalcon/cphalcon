
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
 * Phalcon\Mvc\UrlInterface
 *
 * Interface for Phalcon\Mvc\UrlInterface
 */
interface UrlInterface
{

	/**
	 * Sets a prefix to all the urls generated
	 */
	public function setBaseUri(string! baseUri);

	/**
	 * Returns the prefix for all the generated urls. By default /
	 */
	public function getBaseUri() -> string;

	/**
	 * Sets a base paths for all the generated paths
	 */
	public function setBasePath(string! basePath);

	/**
	 * Returns a base path
	 */
	public function getBasePath() -> string;

	/**
	 * Generates a URL
	 *
	 * @param string|array uri
	 * @param array|object args Optional arguments to be appended to the query string
	 * @param bool $local
	 * @return string
	 */
	public function get(uri = null, args = null, boolean local = null) -> string;

	/**
	 * Generates a local path
	 *
	 * @param string path
	 * @return string
	 */
	public function path(path = null) -> string;
}
