
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2016 Phalcon Team (https://phalconphp.com)       |
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

namespace Phalcon\Http\Response;

/**
 * Phalcon\Http\Response\HeadersInterface
 *
 * Interface for Phalcon\Http\Response\Headers compatible bags
 */
interface HeadersInterface
{

	/**
	 * Sets a header to be sent at the end of the request
	 */
	public function set(string name, string value);

	/**
	 * Gets a header value from the internal bag
	 */
	public function get(string name) -> string | boolean;

	/**
	 * Sets a raw header to be sent at the end of the request
	 */
	public function setRaw(string header);

	/**
	 * Sends the headers to the client
	 */
	public function send() -> boolean;

	/**
	 * Reset set headers
	 */
	public function reset();

	/**
	 * Restore a \Phalcon\Http\Response\Headers object
	 */
	public static function __set_state(array! data) -> <HeadersInterface>;

}