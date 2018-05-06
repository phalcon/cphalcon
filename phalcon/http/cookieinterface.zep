
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2018 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Olivier Garbe <ogarbe@voyageprive.com                         |
 +------------------------------------------------------------------------+
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
	 * @return \Phalcon\Http\CookieInterface
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
	public function useEncryption(boolean useEncryption) -> <CookieInterface>;

	/**
	 * Check if the cookie is using implicit encryption
	 */
	public function isUsingEncryption() -> boolean;

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
	public function setSecure(boolean secure) -> <CookieInterface>;

	/**
	 * Returns whether the cookie must only be sent when the connection is secure (HTTPS)
	 */
	public function getSecure() -> boolean;

	/**
	 * Sets if the cookie is accessible only through the HTTP protocol
	 */
	public function setHttpOnly(boolean httpOnly) -> <CookieInterface>;

	/**
	 * Returns if the cookie is accessible only through the HTTP protocol
	 */
	public function getHttpOnly() -> boolean;
}
