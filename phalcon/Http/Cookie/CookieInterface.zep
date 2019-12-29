
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Cookie;

/**
 * Interface for Phalcon\Http\Cookie
 */
interface CookieInterface
{
    /**
     * Deletes the cookie
     */
    public function delete();

    /**
     * Returns the domain that the cookie is available to
     */
    public function getDomain() -> string;

    /**
     * Returns the current expiration time
     */
    public function getExpiration() -> string;

    /**
     * Returns if the cookie is accessible only through the HTTP protocol
     */
    public function getHttpOnly() -> bool;

    /**
     * Returns the current cookie's name
     */
    public function getName() -> string;

    /**
     * Returns the current cookie's options
     */
    public function getOptions() -> array;

    /**
     * Returns the current cookie's path
     */
    public function getPath() -> string;

    /**
     * Returns whether the cookie must only be sent when the connection is
     * secure (HTTPS)
     */
    public function getSecure() -> bool;

    /**
     * Returns the cookie's value.
     */
    public function getValue(var filters = null, var defaultValue = null) -> var;

    /**
     * Check if the cookie is using implicit encryption
     */
    public function isUsingEncryption() -> bool;

    /**
     * Sends the cookie to the HTTP client
     */
    public function send() -> <CookieInterface>;

    /**
     * Sets the domain that the cookie is available to
     */
    public function setDomain(string! domain) -> <CookieInterface>;

    /**
     * Sets the cookie's expiration time
     */
    public function setExpiration(int expire) -> <CookieInterface>;

    /**
     * Sets if the cookie is accessible only through the HTTP protocol
     */
    public function setHttpOnly(bool httpOnly) -> <CookieInterface>;

    /**
     * Sets the cookie's options
     */
    public function setOptions(array! options) -> <CookieInterface>;

    /**
     * Sets the cookie's expiration time
     */
    public function setPath(string! path) -> <CookieInterface>;

    /**
     * Sets if the cookie must only be sent when the connection is secure
     * (HTTPS)
     */
    public function setSecure(bool secure) -> <CookieInterface>;

    /**
     * Sets the cookie's value
     *
     * @param string value
     */
    public function setValue(var value) -> <CookieInterface>;

    /**
     * Sets if the cookie must be encrypted/decrypted automatically
     */
    public function useEncryption(bool useEncryption) -> <CookieInterface>;
}
