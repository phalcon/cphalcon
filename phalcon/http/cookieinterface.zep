
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http;

/**
 * Phalcon\Http\CookieInterface
 *
 * Interface for Phalcon\Http\Cookie
 */
interface CookieInterface
{
	/**
	 * Sets the cookie's value
	 *
	 * @param string value
	 */
	public function setValue(value) -> <CookieInterface>;

	/**
	 * Returns the cookie's value.
	 */
	public function getValue(var filters = null, var defaultValue = null) -> var;

	/**
	 * Sends the cookie to the HTTP client
	 */
	public function send() -> <CookieInterface>;

	/**
	 * Deletes the cookie
	 */
	public function delete();

	/**
	 * Sets if the cookie must be encrypted/decrypted automatically
	 */
	public function useEncryption(bool useEncryption) -> <CookieInterface>;

	/**
	 * Check if the cookie is using implicit encryption
	 */
	public function isUsingEncryption() -> bool;

	/**
	 * Sets the cookie's expiration time
	 */
	public function setExpiration(int expire) -> <CookieInterface>;

	/**
	 * Returns the current expiration time
	 */
	public function getExpiration() -> string;

	/**
	 * Sets the cookie's expiration time
	 */
	public function setPath(string! path) -> <CookieInterface>;

	/**
	 * Returns the current cookie's name
	 */
	public function getName() -> string;

	/**
	 * Returns the current cookie's path
	 */
	public function getPath() -> string;

	/**
	 * Sets the domain that the cookie is available to
	 */
	public function setDomain(string! domain) -> <CookieInterface>;

	/**
	 * Returns the domain that the cookie is available to
	 */
	public function getDomain() -> string;

	/**
	 * Sets if the cookie must only be sent when the connection is secure (HTTPS)
	 */
	public function setSecure(bool secure) -> <CookieInterface>;

	/**
	 * Returns whether the cookie must only be sent when the connection is secure (HTTPS)
	 */
	public function getSecure() -> bool;

	/**
	 * Sets if the cookie is accessible only through the HTTP protocol
	 */
	public function setHttpOnly(bool httpOnly) -> <CookieInterface>;

	/**
	 * Returns if the cookie is accessible only through the HTTP protocol
	 */
	public function getHttpOnly() -> bool;
}
