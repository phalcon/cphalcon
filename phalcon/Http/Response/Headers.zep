
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
 * Phalcon\Http\Response\Headers
 *
 * This class is a bag to manage the response headers
 */
class Headers implements HeadersInterface
{
    /**
     * @var array
     */
    protected headers = [];

    /**
     * @var bool
     */
    protected isSent = false;

    /**
     * Gets a header value from the internal bag
     */
    public function get(string name) -> string | bool
    {
        var headers, headerValue;

        let headers = this->headers;

        if !fetch headerValue, headers[name] {
            return false;
        }

        return headerValue;
    }

    /**
     * Checks if a header exists
     */
    public function has(string name) -> bool
    {
        return isset this->headers[name];
    }

    /**
     * Returns if the headers have already been sent
     */
    public function isSent() -> bool
    {
        return this->isSent;
    }

    /**
     * Removes a header to be sent at the end of the request
     */
    public function remove(string header) -> <HeadersInterface>
    {
        var headers;

        let headers = this->headers;
        unset headers[header];
        let this->headers = headers;

        return this;
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

        if true === headers_sent() || true === this->isSent() {
            return false;
        }

        for header, value in this->headers {
            if value !== null {
                header(
                    header . ": " . value,
                    true
                );
            } else {
                if memstr(header, ":") || substr(header, 0, 5) == "HTTP/" {
                    header(
                        header,
                        true
                    );
                } else {
                    header(
                        header . ": ",
                        true
                    );
                }
            }
        }

        let this->isSent = true;

        return true;
    }

    /**
     * Sets a header to be sent at the end of the request
     */
    public function set(string name, string value) -> <HeadersInterface>
    {
        let this->headers[name] = value;

        return this;
    }

    /**
     * Sets a raw header to be sent at the end of the request
     */
    public function setRaw(string header) -> <HeadersInterface>
    {
        let this->headers[header] = null;

        return this;
    }

    /**
     * Returns the current headers as an array
     */
    public function toArray() -> array
    {
        return this->headers;
    }
}
