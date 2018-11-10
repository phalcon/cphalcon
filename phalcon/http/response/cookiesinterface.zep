
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

namespace Phalcon\Http\Response;

/**
 * Phalcon\Http\Response\CookiesInterface
 *
 * Interface for Phalcon\Http\Response\Cookies
 */
interface CookiesInterface
{

	/**
	 * Set if cookies in the bag must be automatically encrypted/decrypted
	 */
	public function useEncryption(boolean useEncryption) -> <CookiesInterface>;

	/**
	 * Returns if the bag is automatically encrypting/decrypting cookies
	 */
	public function isUsingEncryption() -> boolean;

	/**
	 * Sets a cookie to be sent at the end of the request
	 */
	public function set(string! name, value = null, int expire = 0, string path = "/", boolean secure = null, string! domain = null, boolean httpOnly = null) -> <CookiesInterface>;

	/**
	 * Gets a cookie from the bag
	 */
	public function get(string! name) -> <CookiesInterface>;

	/**
	 * Check if a cookie is defined in the bag or exists in the _COOKIE superglobal
	 */
	public function has(string! name) -> boolean;

	/**
	 * Deletes a cookie by its name
	 * This method does not removes cookies from the _COOKIE superglobal
	 */
	public function delete(string! name) -> boolean;

	/**
	 * Sends the cookies to the client
	 */
	public function send() -> boolean;

	/**
	 * Reset set cookies
	 */
	public function reset() -> <CookiesInterface>;

}
