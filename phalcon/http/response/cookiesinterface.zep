
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
	 *
	 * @param string name
	 * @param mixed value
	 * @param int expire
	 * @param string path
	 * @param boolean secure
	 * @param string domain
	 * @param boolean httpOnly
	 * @return Phalcon\Http\Response\CookiesInterface
	 */
	public function set(string! name, value = null, int expire = 0, string path = "/", secure = null, string! domain = null, httpOnly = null) -> <CookiesInterface>;

	/**
	 * Gets a cookie from the bag
	 */
	public function get(string! name) -> <\Phalcon\Http\Cookie>;

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
