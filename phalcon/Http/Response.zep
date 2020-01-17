
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
use DateTimeZone;
use Phalcon\Di;
use Phalcon\Di\DiInterface;
use Phalcon\Helper\Fs;
use Phalcon\Helper\Json;
use Phalcon\Http\Response\Exception;
use Phalcon\Http\Response\HeadersInterface;
use Phalcon\Http\Response\CookiesInterface;
use Phalcon\Url\UrlInterface;
use Phalcon\Mvc\ViewInterface;
use Phalcon\Http\Response\Headers;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;

/**
 * Part of the HTTP cycle is return responses to the clients.
 * Phalcon\HTTP\Response is the Phalcon component responsible to achieve this task.
 * HTTP responses are usually composed by headers and body.
 *
 *```php
 * $response = new \Phalcon\Http\Response();
 *
 * $response->setStatusCode(200, "OK");
 * $response->setContent("<html><body>Hello</body></html>");
 *
 * $response->send();
 *```
 */
class Response implements ResponseInterface, InjectionAwareInterface, EventsAwareInterface
{
    protected container;

    protected content;

    protected cookies;

    protected eventsManager;

    protected file;

    protected headers;

    /**
     * @var bool
     */
    protected sent = false;

    protected statusCodes;

    /**
     * Phalcon\Http\Response constructor
     */
    public function __construct(content = null, code = null, status = null)
    {
        /**
         * A Phalcon\Http\Response\Headers bag is temporary used to manage the headers before sent them to the client
         */
        let this->headers = new Headers();

        let this->content = content;

        if code !== null {
            this->setStatusCode(code, status);
        }
    }

    /**
     * Appends a string to the HTTP response body
     */
    public function appendContent(content) -> <ResponseInterface>
    {
        let this->content = this->getContent() . content;

        return this;
    }

    /**
     * Gets the HTTP response body
     */
    public function getContent() -> string
    {
        return this->content;
    }

    /**
     * Returns cookies set by the user
     */
    public function getCookies() -> <CookiesInterface>
    {
        return this->cookies;
    }

    /**
     * Returns the internal dependency injector
     */
    public function getDI() -> <DiInterface>
    {
        var container;

        let container = <DiInterface> this->container;

        if typeof container != "object" {
            let container = Di::getDefault();

            if unlikely typeof container != "object" {
                throw new Exception(
                    Exception::containerServiceNotFound("the 'url' service")
                );
            }

            let this->container = container;
        }

        return container;
    }

    /**
     * Returns the internal event manager
     */
    public function getEventsManager() -> <ManagerInterface>
    {
        return this->eventsManager;
    }

    /**
     * Returns headers set by the user
     */
    public function getHeaders() -> <HeadersInterface>
    {
        return this->headers;
    }

    /**
     * Returns the reason phrase
     *
     *```php
     * echo $response->getReasonPhrase();
     *```
     */
    public function getReasonPhrase() -> string | null
    {
        var statusReasonPhrase;

        let statusReasonPhrase = mb_substr(
            this->getHeaders()->get("Status"),
            4
        );

        return statusReasonPhrase ? statusReasonPhrase : null;
    }

    /**
     * Returns the status code
     *
     *```php
     * echo $response->getStatusCode();
     *```
     */
    public function getStatusCode() -> int | null
    {
        var statusCode;

        let statusCode = mb_substr(
            this->getHeaders()->get("Status"),
            0,
            3
        );

        return statusCode ? (int) statusCode : null;
    }

    /**
     * Checks if a header exists
     *
     *```php
     * $response->hasHeader("Content-Type");
     *```
     */
    public function hasHeader(string name) -> bool
    {
        var headers;

        let headers = this->getHeaders();

        return headers->has(name);
    }

    /**
     * Check if the response is already sent
     */
    public function isSent() -> bool
    {
        return this->sent;
    }

    /**
     * Redirect by HTTP to another action or URL
     *
     *```php
     * // Using a string redirect (internal/external)
     * $response->redirect("posts/index");
     * $response->redirect("http://en.wikipedia.org", true);
     * $response->redirect("http://www.example.com/new-location", true, 301);
     *
     * // Making a redirection based on a named route
     * $response->redirect(
     *     [
     *         "for"        => "index-lang",
     *         "lang"       => "jp",
     *         "controller" => "index",
     *     ]
     * );
     *```
     */
    public function redirect(
        var location = null,
        bool externalRedirect = false,
        int statusCode = 302
    ) -> <ResponseInterface> {
        var header, url, container, matched, view;

        if !location {
            let location = "";
        }

        if externalRedirect {
            let header = location;
        } else {
            if typeof location == "string" && strstr(location, "://") {
                let matched = preg_match("/^[^:\\/?#]++:/", location);

                if matched {
                    let header = location;
                } else {
                    let header = null;
                }
            } else {
                let header = null;
            }
        }

        let container = this->getDI();

        if !header {
            let url = <UrlInterface> container->getShared("url"),
                header = url->get(location);
        }

        if container->has("view") {
            let view = container->getShared("view");

            if view instanceof ViewInterface {
                view->disable();
            }
        }

        /**
         * The HTTP status is 302 by default, a temporary redirection
         */
        if statusCode < 300 || statusCode > 308 {
            let statusCode = 302;
        }

        this->setStatusCode(statusCode);

        /**
         * Change the current location using 'Location'
         */
        this->setHeader("Location", header);

        return this;
    }

    /**
     * Remove a header in the response
     *
     *```php
     * $response->removeHeader("Expires");
     *```
     */
    public function removeHeader(string name) -> <ResponseInterface>
    {
        var headers;

        let headers = this->getHeaders();

        headers->remove(name);

        return this;
    }
    /**
     * Resets all the established headers
     */
    public function resetHeaders() -> <ResponseInterface>
    {
        var headers;

        let headers = this->getHeaders();

        headers->reset();

        return this;
    }

    /**
     * Prints out HTTP response to the client
     */
    public function send() -> <ResponseInterface>
    {
        var content, file;

        if unlikely this->sent {
            throw new Exception("Response was already sent");
        }

        this->sendHeaders();

        this->sendCookies();

        /**
         * Output the response body
         */
        let content = this->content;

        if content != null {
            echo content;
        } else {
            let file = this->file;

            if typeof file == "string" && mb_strlen(file) {
                readfile(file);
            }
        }

        let this->sent = true;

        return this;
    }

    /**
     * Sends cookies to the client
     */
    public function sendCookies() -> <ResponseInterface>
    {
        var cookies;

        let cookies = this->cookies;

        if typeof cookies == "object" {
            cookies->send();
        }

        return this;
    }

    /**
     * Sends headers to the client
     */
    public function sendHeaders() -> <ResponseInterface> | boolean
    {
        var headers, eventsManager;

        let headers = <HeadersInterface> this->getHeaders();
        let eventsManager = <ManagerInterface> this->getEventsManager();

        if typeof eventsManager == "object" {
            if eventsManager->fire("response:beforeSendHeaders", this) === false {
                return false;
            }
        }

        /**
         * Send headers
         */
        if headers->send() && typeof eventsManager == "object" {
            eventsManager->fire("response:afterSendHeaders", this);
        }

        return this;
    }

    /**
     * Sets Cache headers to use HTTP cache
     *
     *```php
     * $this->response->setCache(60);
     *```
     */
    public function setCache(int! minutes) -> <ResponseInterface>
    {
        var date;

        let date = new DateTime();

        date->modify(
            "+" . minutes . " minutes"
        );

        this->setExpires(date);

        this->setHeader(
            "Cache-Control",
            "max-age=" . (minutes * 60)
        );

        return this;
    }

    /**
     * Sets HTTP response body
     *
     *```php
     * $response->setContent("<h1>Hello!</h1>");
     *```
     */
    public function setContent(string content) -> <ResponseInterface>
    {
        let this->content = content;

        return this;
    }

    /**
     * Sets the response content-length
     *
     *```php
     * $response->setContentLength(2048);
     *```
     */
    public function setContentLength(int contentLength) -> <ResponseInterface>
    {
        this->setHeader("Content-Length", contentLength);

        return this;
    }

    /**
     * Sets the response content-type mime, optionally the charset
     *
     *```php
     * $response->setContentType("application/pdf");
     * $response->setContentType("text/plain", "UTF-8");
     *```
     */
    public function setContentType(string contentType, charset = null) -> <ResponseInterface>
    {
        if charset !== null {
            let contentType .= "; charset=" . charset;
        }

        this->setHeader("Content-Type", contentType);

        return this;
    }

    /**
     * Sets a cookies bag for the response externally
     */
    public function setCookies(<CookiesInterface> cookies) -> <ResponseInterface>
    {
        let this->cookies = cookies;

        return this;
    }

    /**
     * Sets the dependency injector
     */
    public function setDI(<DiInterface> container) -> void
    {
        let this->container = container;
    }

    /**
     * Set a custom ETag
     *
     *```php
     * $response->setEtag(
     *     md5(
     *         time()
     *     )
     * );
     *```
     */
    public function setEtag(string etag) -> <ResponseInterface>
    {
        this->setHeader("Etag", etag);

        return this;
    }

    /**
     * Sets an Expires header in the response that allows to use the HTTP cache
     *
     *```php
     * $this->response->setExpires(
     *     new DateTime()
     * );
     *```
     */
    public function setExpires(<DateTime> datetime) -> <ResponseInterface>
    {
        var date;

        let date = clone datetime;

        /**
         * All the expiration times are sent in UTC
         * Change the timezone to UTC
         */
        date->setTimezone(
            new DateTimeZone("UTC")
        );

        /**
         * The 'Expires' header set this info
         */
        this->setHeader(
            "Expires",
            date->format("D, d M Y H:i:s") . " GMT"
        );

        return this;
    }

    /**
     * Sets the events manager
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        let this->eventsManager = eventsManager;
    }

    /**
     * Sets an attached file to be sent at the end of the request
     */
    public function setFileToSend(string filePath, attachmentName = null, attachment = true) -> <ResponseInterface>
    {
        var basePath;
        var basePathEncoding = "ASCII";

        if typeof attachmentName != "string" {
            let basePath = Fs::basename(filePath);
        } else {
            let basePath = attachmentName;
        }
        if attachment {
            let basePathEncoding = mb_detect_encoding(
                basePath,
                mb_detect_order(),
                true
            );

            this->setRawHeader("Content-Description: File Transfer");
            this->setRawHeader("Content-Type: application/octet-stream");
            this->setRawHeader("Content-Transfer-Encoding: binary");
            // According RFC2231 section-7, non-ASCII header param must add a extended one to indicate charset
            if basePathEncoding != "ASCII" {
                let basePath = rawurlencode(basePath);
                this->setRawHeader("Content-Disposition: attachment; filename=" . basePath . "; filename*=". mb_strtolower(basePathEncoding) . "''" . basePath);
            } else {
                // According RFC2045 section-5.1, header param value contains special chars must be as quoted-string
                // Always quote value is accepted because the special chars is a large list
                // According RFC822 appendix-D, CR "\" <"> must to be quoted in syntax rule of quoted-string
                let basePath = addcslashes(basePath, "\15\17\\\"");
                this->setRawHeader("Content-Disposition: attachment; filename=\"" . basePath . "\"");
            }
        }

        let this->file = filePath;

        return this;
    }

    /**
     * Overwrites a header in the response
     *
     *```php
     * $response->setHeader("Content-Type", "text/plain");
     *```
     */
    public function setHeader(string name, value) -> <ResponseInterface>
    {
        var headers;

        let headers = this->getHeaders();

        headers->set(name, value);

        return this;
    }

    /**
     * Sets a headers bag for the response externally
     */
    public function setHeaders(<HeadersInterface> headers) -> <ResponseInterface>
    {
        var data, existing, name, value;

        let data = headers->toArray(),
            existing = this->getHeaders();

        for name, value in data {
            existing->set(name, value);
        }

        let this->headers = existing;

        return this;
    }

    /**
     * Sets HTTP response body. The parameter is automatically converted to JSON
     * and also sets default header: Content-Type: "application/json; charset=UTF-8"
     *
     *```php
     * $response->setJsonContent(
     *     [
     *         "status" => "OK",
     *     ]
     * );
     *```
     */
    public function setJsonContent(var content, int jsonOptions = 0, int depth = 512) -> <ResponseInterface>
    {
        this->setContentType("application/json", "UTF-8");

        this->setContent(
            Json::encode(content, jsonOptions, depth)
        );

        return this;
    }

    /**
     * Sets Last-Modified header
     *
     *```php
     * $this->response->setLastModified(
     *     new DateTime()
     * );
     *```
     */
    public function setLastModified(<DateTime> datetime) -> <ResponseInterface>
    {
        var date;

        let date = clone datetime;

        /**
         * All the Last-Modified times are sent in UTC
         * Change the timezone to UTC
         */
        date->setTimezone(
            new DateTimeZone("UTC")
        );

        /**
         * The 'Last-Modified' header sets this info
         */
        this->setHeader(
            "Last-Modified",
            date->format("D, d M Y H:i:s") . " GMT"
        );

        return this;
    }

    /**
     * Sends a Not-Modified response
     */
    public function setNotModified() -> <ResponseInterface>
    {
        this->setStatusCode(304, "Not modified");

        return this;
    }

    /**
     * Sets the HTTP response code
     *
     *```php
     * $response->setStatusCode(404, "Not Found");
     *```
     */
    public function setStatusCode(int code, string message = null) -> <ResponseInterface>
    {
        var headers, currentHeadersRaw, key, statusCodes, defaultMessage;

        let headers = this->getHeaders(),
            currentHeadersRaw = headers->toArray();

        /**
         * We use HTTP/1.1 instead of HTTP/1.0
         *
         * Before that we would like to unset any existing HTTP/x.y headers
         */
        for key, _ in currentHeadersRaw {
            if typeof key == "string" && strstr(key, "HTTP/") {
                headers->remove(key);
            }
        }

        // if an empty message is given we try and grab the default for this
        // status code. If a default doesn't exist, stop here.
        if message === null {
            // See: http://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml
            let statusCodes = [
                // INFORMATIONAL CODES
                100 : "Continue",                        // RFC 7231, 6.2.1
                101 : "Switching Protocols",             // RFC 7231, 6.2.2
                102 : "Processing",                      // RFC 2518, 10.1
                103 : "Early Hints",
                // SUCCESS CODES
                200 : "OK",                              // RFC 7231, 6.3.1
                201 : "Created",                         // RFC 7231, 6.3.2
                202 : "Accepted",                        // RFC 7231, 6.3.3
                203 : "Non-Authoritative Information",   // RFC 7231, 6.3.4
                204 : "No Content",                      // RFC 7231, 6.3.5
                205 : "Reset Content",                   // RFC 7231, 6.3.6
                206 : "Partial Content",                 // RFC 7233, 4.1
                207 : "Multi-status",                    // RFC 4918, 11.1
                208 : "Already Reported",                // RFC 5842, 7.1
                226 : "IM Used",                         // RFC 3229, 10.4.1
                // REDIRECTION CODES
                300 : "Multiple Choices",                // RFC 7231, 6.4.1
                301 : "Moved Permanently",               // RFC 7231, 6.4.2
                302 : "Found",                           // RFC 7231, 6.4.3
                303 : "See Other",                       // RFC 7231, 6.4.4
                304 : "Not Modified",                    // RFC 7232, 4.1
                305 : "Use Proxy",                       // RFC 7231, 6.4.5
                306 : "Switch Proxy",                    // RFC 7231, 6.4.6 (Deprecated)
                307 : "Temporary Redirect",              // RFC 7231, 6.4.7
                308 : "Permanent Redirect",              // RFC 7538, 3
                // CLIENT ERROR
                400 : "Bad Request",                     // RFC 7231, 6.5.1
                401 : "Unauthorized",                    // RFC 7235, 3.1
                402 : "Payment Required",                // RFC 7231, 6.5.2
                403 : "Forbidden",                       // RFC 7231, 6.5.3
                404 : "Not Found",                       // RFC 7231, 6.5.4
                405 : "Method Not Allowed",              // RFC 7231, 6.5.5
                406 : "Not Acceptable",                  // RFC 7231, 6.5.6
                407 : "Proxy Authentication Required",   // RFC 7235, 3.2
                408 : "Request Time-out",                // RFC 7231, 6.5.7
                409 : "Conflict",                        // RFC 7231, 6.5.8
                410 : "Gone",                            // RFC 7231, 6.5.9
                411 : "Length Required",                 // RFC 7231, 6.5.10
                412 : "Precondition Failed",             // RFC 7232, 4.2
                413 : "Request Entity Too Large",        // RFC 7231, 6.5.11
                414 : "Request-URI Too Large",           // RFC 7231, 6.5.12
                415 : "Unsupported Media Type",          // RFC 7231, 6.5.13
                416 : "Requested range not satisfiable", // RFC 7233, 4.4
                417 : "Expectation Failed",              // RFC 7231, 6.5.14
                418 : "I'm a teapot",                    // RFC 7168, 2.3.3
                421 : "Misdirected Request",
                422 : "Unprocessable Entity",            // RFC 4918, 11.2
                423 : "Locked",                          // RFC 4918, 11.3
                424 : "Failed Dependency",               // RFC 4918, 11.4
                425 : "Unordered Collection",
                426 : "Upgrade Required",                // RFC 7231, 6.5.15
                428 : "Precondition Required",           // RFC 6585, 3
                429 : "Too Many Requests",               // RFC 6585, 4
                431 : "Request Header Fields Too Large", // RFC 6585, 5
                451 : "Unavailable For Legal Reasons",   // RFC 7725, 3
                499 : "Client Closed Request",
                // SERVER ERROR
                500 : "Internal Server Error",           // RFC 7231, 6.6.1
                501 : "Not Implemented",                 // RFC 7231, 6.6.2
                502 : "Bad Gateway",                     // RFC 7231, 6.6.3
                503 : "Service Unavailable",             // RFC 7231, 6.6.4
                504 : "Gateway Time-out",                // RFC 7231, 6.6.5
                505 : "HTTP Version not supported",      // RFC 7231, 6.6.6
                506 : "Variant Also Negotiates",         // RFC 2295, 8.1
                507 : "Insufficient Storage",            // RFC 4918, 11.5
                508 : "Loop Detected",                   // RFC 5842, 7.2
                510 : "Not Extended",                    // RFC 2774, 7
                511 : "Network Authentication Required"  // RFC 6585, 6
            ];

            if unlikely !isset statusCodes[code] {
                throw new Exception(
                    "Non-standard statuscode given without a message"
                );
            }

            let defaultMessage = statusCodes[code],
                message = defaultMessage;
        }

        headers->setRaw("HTTP/1.1 " . code . " " . message);

        /**
         * We also define a 'Status' header with the HTTP status
         */
        headers->set(
            "Status",
            code . " " . message
        );

        return this;
    }

    /**
     * Send a raw header to the response
     *
     *```php
     * $response->setRawHeader("HTTP/1.1 404 Not Found");
     *```
     */
    public function setRawHeader(string header) -> <ResponseInterface>
    {
        var headers;

        let headers = this->getHeaders();

        headers->setRaw(header);

        return this;
    }
}
