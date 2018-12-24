
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Response;

use Phalcon\Http\CookieInterface;

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
	public function useEncryption(bool useEncryption) -> <CookiesInterface>;

	/**
	 * Returns if the bag is automatically encrypting/decrypting cookies
	 */
	public function isUsingEncryption() -> bool;

	/**
	 * Sets a cookie to be sent at the end of the request
	 */
	public function set(string! name, value = null, int expire = 0, string path = "/", bool secure = null, string! domain = null, bool httpOnly = null) -> <CookiesInterface>;

	/**
	 * Gets a cookie from the bag
	 */
	public function get(string! name) -> <CookieInterface>;

	/**
	 * Check if a cookie is defined in the bag or exists in the _COOKIE superglobal
	 */
	public function has(string! name) -> bool;

	/**
	 * Deletes a cookie by its name
	 * This method does not removes cookies from the _COOKIE superglobal
	 */
	public function delete(string! name) -> bool;

	/**
	 * Sends the cookies to the client
	 */
	public function send() -> bool;

	/**
	 * Reset set cookies
	 */
	public function reset() -> <CookiesInterface>;

}
