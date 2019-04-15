
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Response;

use Phalcon\Http\Response\HeadersInterface;

/**
 * Phalcon\Http\Response\Headers
 *
 * This class is a bag to manage the response headers
 */
class Headers implements HeadersInterface
{
    protected headers = [];

    /**
     * Restore a \Phalcon\Http\Response\Headers object
     */
    public static function __set_state(array! data) -> <HeadersInterface>
    {
        var headers, key, value, dataHeaders;
        let headers = new self();
        if fetch dataHeaders, data["headers"] {
            for key, value in dataHeaders {
                headers->set(key, value);
            }
        }
        return headers;
    }

    /**
     * Gets a header value from the internal bag
     */
    public function get(string name) -> string | bool
    {
        var headers, headerValue;
        let headers = this->headers;

        if fetch headerValue, headers[name] {
            return headerValue;
        }

        return false;
    }

    /**
     * Sets a header to be sent at the end of the request
     */
    public function has(string name) -> bool
    {
        return isset(this->headers[name]);
    }

    /**
     * Removes a header to be sent at the end of the request
     */
    public function remove(string header)
    {
        var headers;

        let headers = this->headers;
        unset headers[header];
        let this->headers = headers;
    }

    /**
     * Reset set headers
     */
    public function reset()
    {
        let this->headers = [];
    }

    /**
     * Sends the headers to the client
     */
    public function send() -> bool
    {
        var header, value;
        if !headers_sent() {
            for header, value in this->headers {
                if value !== null {
                    header(header . ": " . value, true);
                } else {
                    if memstr(header, ":") || substr(header, 0, 5) == "HTTP/" {
                        header(header, true);
                    } else {
                        header(header . ": ", true);
                    }
                }
            }
            return true;
        }
        return false;
    }

    /**
     * Sets a header to be sent at the end of the request
     */
    public function set(string name, string value)
    {
        let this->headers[name] = value;
    }

    /**
     * Sets a raw header to be sent at the end of the request
     */
    public function setRaw(string header)
    {
        let this->headers[header] = null;
    }

    /**
     * Returns the current headers as an array
     */
    public function toArray() -> array
    {
        return this->headers;
    }
}
