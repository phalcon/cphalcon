
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
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
     * Gets a header value from the internal bag
     */
    public function get(string name) -> string | bool;

    /**
     * Checks if a header exists
     */
    public function has(string name) -> bool;

    /**
     * Reset set headers
     */
    public function reset();

    /**
     * Sends the headers to the client
     */
    public function send() -> bool;

    /**
     * Sets a header to be sent at the end of the request
     */
    public function set(string name, string value);

    /**
     * Sets a raw header to be sent at the end of the request
     */
    public function setRaw(string header);
}
