
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
	 *
	 * @param boolean useEncryption
	 * @return Phalcon\Http\Response\CookiesInterface
	 */
	public function useEncryption(useEncryption);

	/**
	 * Returns if the bag is automatically encrypting/decrypting cookies
	 *
	 * @return boolean
	 */
	public function isUsingEncryption();

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
	public function set(name, value=null, expire=0, path='/', secure=null, domain=null, httpOnly=null);

	/**
	 * Gets a cookie from the bag
	 *
	 * @param string name
	 * @return Phalcon\Http\Cookie
	 */
	public function get(name);

	/**
	 * Check if a cookie is defined in the bag or exists in the _COOKIE superglobal
	 *
	 * @param string name
	 * @return boolean
	 */
	public function has(name);

	/**
	 * Deletes a cookie by its name
	 * This method does not removes cookies from the _COOKIE superglobal
	 *
	 * @param string name
	 * @return boolean
	 */
	public function delete(name);

	/**
	 * Sends the cookies to the client
	 *
	 * @return boolean
	 */
	public function send();

	/**
	 * Reset set cookies
	 *
	 * @return Phalcon\Http\Response\CookiesInterface
	 */
	public function reset();

}
