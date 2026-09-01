
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http;

use DateTime;
use Phalcon\Http\Response\HeadersInterface;

/**
 * Phalcon\Http\Response
 *
 * Interface for Phalcon\Http\Response
 */
interface ResponseInterface
{
    /**
     * Appends a string to the HTTP response body
     */
    public function appendContent(string content) -> <ResponseInterface>;

    /**
     * Gets the HTTP response body
     *
     * @return string
     */
    public function getContent() -> string;

    /**
     * Returns headers set by the user
     *
     * @return HeadersInterface
     */
    public function getHeaders() -> <HeadersInterface>;

    /**
     * Returns the status code
     *
     * @return int|null
     */
    public function getStatusCode() -> int | null;

    /**
     * Checks if a header exists
     *
     * @param string $name
     *
     * @return bool
     */
    public function hasHeader(string name) -> bool;

    /**
     * Checks if the response was already sent
     *
     * @return bool
     */
    public function isSent() -> bool;

    /**
     * Redirect by HTTP to another action or URL
     *
     * @param string|null $location
     * @param bool        $externalRedirect
     * @param int         $statusCode
     *
     * @return ResponseInterface
     */
    public function redirect(string location = null, bool externalRedirect = false, int statusCode = 302) -> <ResponseInterface>;

    /**
     * Resets all the established headers
     *
     * @return ResponseInterface
     */
    public function resetHeaders() -> <ResponseInterface>;

    /**
     * Prints out HTTP response to the client
     *
     * @return ResponseInterface
     */
    public function send() -> <ResponseInterface>;

    /**
     * Sends cookies to the client
     *
     * @return ResponseInterface
     */
    public function sendCookies() -> <ResponseInterface>;

    /**
     * Sends headers to the client
     */
    public function sendHeaders() -> bool | <ResponseInterface>;

    /**
     * Sets HTTP response body
     */
    public function setContent(string content) -> <ResponseInterface>;

    /**
     * Sets the response content-length
     */
    public function setContentLength(int contentLength) -> <ResponseInterface>;

    /**
     * Sets the response content-type mime, optionally the charset
     *
     * @todo check the null
     */
    public function setContentType(string contentType, string charset = null) -> <ResponseInterface>;

    /**
     * Sets output expire time header
     */
    public function setExpires(<DateTime> datetime) -> <ResponseInterface>;

    /**
     * Sets an attached file to be sent at the end of the request
     *
     * @todo check the null
     */
    public function setFileToSend(string filePath, string attachmentName = null) -> <ResponseInterface>;

    /**
     * Overwrites a header in the response
     */
    public function setHeader(string name, string value) -> <ResponseInterface>;

    /**
     * Sets HTTP response body. The parameter is automatically converted to JSON
     *
     *```php
     * $response->setJsonContent(
     *     [
     *         "status" => "OK",
     *     ]
     * );
     *```
     *
     * @todo check the parameter type
     */
    public function setJsonContent(var content) -> <ResponseInterface>;

    /**
     * Sends a Not-Modified response
     */
    public function setNotModified() -> <ResponseInterface>;

    /**
     * Send a raw header to the response
     */
    public function setRawHeader(string header) -> <ResponseInterface>;

    /**
     * Sets the HTTP response code
     *
     * @todo change $message to only string
     */
    public function setStatusCode(int code, string message = null) -> <ResponseInterface>;
}
