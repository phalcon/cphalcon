
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
	 * Returns true if the header is set, false otherwise
	 */
	public function has(string name) -> bool;

	/**
	 * Sets a header to be sent at the end of the request
	 */
	public function set(string name, string value);

	/**
	 * Gets a header value from the internal bag
	 */
	public function get(string name) -> string | bool;

	/**
	 * Sets a raw header to be sent at the end of the request
	 */
	public function setRaw(string header);

	/**
	 * Sends the headers to the client
	 */
	public function send() -> bool;

	/**
	 * Reset set headers
	 */
	public function reset();

	/**
	 * Restore a \Phalcon\Http\Response\Headers object
	 */
	public static function __set_state(array! data) -> <HeadersInterface>;

}
