
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
use Phalcon\Http\Message\ResponseStatusCodeInterface;
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
class Response implements ResponseInterface, InjectionAwareInterface, EventsAwareInterface, ResponseStatusCodeInterface
{
    /**
     * @var DiInterface|null
     */
    protected container = null;

    /**
     * @var string|null
     */
    protected content = null;

    /**
     * @var CookiesInterface|null
     */
    protected cookies = null;

    /**
     * @var ManagerInterface|null
     */
    protected eventsManager = null;

    /**
     * @var string|null
     */
    protected file = null;

    /**
     * @var Headers
     */
    protected headers;

    /**
     * @var bool
     */
    protected sent = false;

    /**
     * @var array
     */
    protected statusCodes = [];

    /**
     * Phalcon\Http\Response constructor
     */
    public function __construct(string! content = null, code = null, status = null)
    {
        // Note: Don't remove exclamation mark above otherwise NULL will be coerced.

        // A Phalcon\Http\Response\Headers bag is temporary used to manage
        // the headers before sent them to the client
        let this->headers = new Headers();

        if content !== null {
            this->setContent(content);
        }

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
        // Type cast is required here to satisfy the interface
        return (string) this->content;
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
    public function getEventsManager() -> <ManagerInterface> | null
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

        let statusReasonPhrase = substr(
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

        let statusCode = substr(
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

            if typeof file == "string" && strlen(file) {
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
            let basePath = this->getBasename(filePath);
        } else {
            let basePath = attachmentName;
        }
        if attachment {
            // mbstring is a non-default extension
            if function_exists("mb_detect_encoding") {
                let basePathEncoding = mb_detect_encoding(
                    basePath,
                    mb_detect_order(),
                    true
                );
            }
            this->setRawHeader("Content-Description: File Transfer");
            this->setRawHeader("Content-Type: application/octet-stream");
            this->setRawHeader("Content-Transfer-Encoding: binary");
            // According RFC2231 section-7, non-ASCII header param must add a extended one to indicate charset
            if basePathEncoding != "ASCII" {
                let basePath = rawurlencode(basePath);
                this->setRawHeader("Content-Disposition: attachment; filename=" . basePath . "; filename*=". strtolower(basePathEncoding) . "''" . basePath);
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
        this->setContentType("application/json");

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
                // Informational 1xx
                self::STATUS_CONTINUE                             : "Continue",                                           // Information - RFC 7231, 6.2.1
                self::STATUS_SWITCHING_PROTOCOLS                  : "Switching Protocols",                                // Information - RFC 7231, 6.2.2
                self::STATUS_PROCESSING                           : "Processing",                                         // Information - RFC 2518, 10.1
                self::STATUS_EARLY_HINTS                          : "Early Hints",

                // Successful 2xx
                self::STATUS_OK                                   : "OK",                                               // Success - RFC 7231, 6.3.1
                self::STATUS_CREATED                              : "Created",                                          // Success - RFC 7231, 6.3.2
                self::STATUS_ACCEPTED                             : "Accepted",                                         // Success - RFC 7231, 6.3.3
                self::STATUS_NON_AUTHORITATIVE_INFORMATION        : "Non-Authoritative Information",                    // Success - RFC 7231, 6.3.4
                self::STATUS_NO_CONTENT                           : "No Content",                                       // Success - RFC 7231, 6.3.5
                self::STATUS_RESET_CONTENT                        : "Reset Content",                                    // Success - RFC 7231, 6.3.6
                self::STATUS_PARTIAL_CONTENT                      : "Partial Content",                                  // Success - RFC 7233, 4.1
                self::STATUS_MULTI_STATUS                         : "Multi-status",                                     // Success - RFC 4918, 11.1
                self::STATUS_ALREADY_REPORTED                     : "Already Reported",                                 // Success - RFC 5842, 7.1
                self::STATUS_IM_USED                              : "IM Used",                                          // Success - RFC 3229, 10.4.1

                // Redirection 3xx
                self::STATUS_MULTIPLE_CHOICES                     : "Multiple Choices",                                 // Redirection - RFC 7231, 6.4.1
                self::STATUS_MOVED_PERMANENTLY                    : "Moved Permanently",                                // Redirection - RFC 7231, 6.4.2
                self::STATUS_FOUND                                : "Found",                                            // Redirection - RFC 7231, 6.4.3
                self::STATUS_SEE_OTHER                            : "See Other",                                        // Redirection - RFC 7231, 6.4.4
                self::STATUS_NOT_MODIFIED                         : "Not Modified",                                     // Redirection - RFC 7232, 4.1
                self::STATUS_USE_PROXY                            : "Use Proxy",                                        // Redirection - RFC 7231, 6.4.5
                self::STATUS_RESERVED                             : "Switch Proxy",                                     // Redirection - RFC 7231, 6.4.6 (Deprecated)
                self::STATUS_TEMPORARY_REDIRECT                   : "Temporary Redirect",                               // Redirection - RFC 7231, 6.4.7
                self::STATUS_PERMANENT_REDIRECT                   : "Permanent Redirect",                               // Redirection - RFC 7538, 3

                // Client Errors 4xx
                self::STATUS_BAD_REQUEST                          : "Bad Request",                                      // Client Error - RFC 7231, 6.5.1
                self::STATUS_UNAUTHORIZED                         : "Unauthorized",                                     // Client Error - RFC 7235, 3.1
                self::STATUS_PAYMENT_REQUIRED                     : "Payment Required",                                 // Client Error - RFC 7231, 6.5.2
                self::STATUS_FORBIDDEN                            : "Forbidden",                                        // Client Error - RFC 7231, 6.5.3
                self::STATUS_NOT_FOUND                            : "Not Found",                                        // Client Error - RFC 7231, 6.5.4
                self::STATUS_METHOD_NOT_ALLOWED                   : "Method Not Allowed",                               // Client Error - RFC 7231, 6.5.5
                self::STATUS_NOT_ACCEPTABLE                       : "Not Acceptable",                                   // Client Error - RFC 7231, 6.5.6
                self::STATUS_PROXY_AUTHENTICATION_REQUIRED        : "Proxy Authentication Required",                    // Client Error - RFC 7235, 3.2
                self::STATUS_REQUEST_TIMEOUT                      : "Request Time-out",                                 // Client Error - RFC 7231, 6.5.7
                self::STATUS_CONFLICT                             : "Conflict",                                         // Client Error - RFC 7231, 6.5.8
                self::STATUS_GONE                                 : "Gone",                                             // Client Error - RFC 7231, 6.5.9
                self::STATUS_LENGTH_REQUIRED                      : "Length Required",                                  // Client Error - RFC 7231, 6.5.10
                self::STATUS_PRECONDITION_FAILED                  : "Precondition Failed",                              // Client Error - RFC 7232, 4.2
                self::STATUS_PAYLOAD_TOO_LARGE                    : "Request Entity Too Large",                         // Client Error - RFC 7231, 6.5.11
                self::STATUS_URI_TOO_LONG                         : "Request-URI Too Large",                            // Client Error - RFC 7231, 6.5.12
                self::STATUS_UNSUPPORTED_MEDIA_TYPE               : "Unsupported Media Type",                           // Client Error - RFC 7231, 6.5.13
                self::STATUS_RANGE_NOT_SATISFIABLE                : "Requested range not satisfiable",                  // Client Error - RFC 7233, 4.4
                self::STATUS_EXPECTATION_FAILED                   : "Expectation Failed",                               // Client Error - RFC 7231, 6.5.14
                self::STATUS_IM_A_TEAPOT                          : "I'm a teapot",                                     // Client Error - RFC 7168, 2.3.3
                self::STATUS_MISDIRECTED_REQUEST                  : "Misdirected Request",
                self::STATUS_UNPROCESSABLE_ENTITY                 : "Unprocessable Entity",                             // Client Error - RFC 4918, 11.2
                self::STATUS_LOCKED                               : "Locked",                                           // Client Error - RFC 4918, 11.3
                self::STATUS_FAILED_DEPENDENCY                    : "Failed Dependency",                                // Client Error - RFC 4918, 11.4
                self::STATUS_TOO_EARLY                            : "Unordered Collection",
                self::STATUS_UPGRADE_REQUIRED                     : "Upgrade Required",                                 // Client Error - RFC 7231, 6.5.15
                self::STATUS_PRECONDITION_REQUIRED                : "Precondition Required",                            // Client Error - RFC 6585, 3
                self::STATUS_TOO_MANY_REQUESTS                    : "Too Many Requests",                                // Client Error - RFC 6585, 4
                self::STATUS_REQUEST_HEADER_FIELDS_TOO_LARGE      : "Request Header Fields Too Large",                  // Client Error - RFC 6585, 5
                self::STATUS_UNAVAILABLE_FOR_LEGAL_REASONS        : "Unavailable For Legal Reasons",                    // Client Error - RFC 7725, 3

                // Server Errors 5xx
                self::STATUS_INTERNAL_SERVER_ERROR                : "Internal Server Error",                            // Server Error - RFC 7231, 6.6.1
                self::STATUS_NOT_IMPLEMENTED                      : "Not Implemented",                                  // Server Error - RFC 7231, 6.6.2
                self::STATUS_BAD_GATEWAY                          : "Bad Gateway",                                      // Server Error - RFC 7231, 6.6.3
                self::STATUS_SERVICE_UNAVAILABLE                  : "Service Unavailable",                              // Server Error - RFC 7231, 6.6.4
                self::STATUS_GATEWAY_TIMEOUT                      : "Gateway Time-out",                                 // Server Error - RFC 7231, 6.6.5
                self::STATUS_VERSION_NOT_SUPPORTED                : "HTTP Version not supported",                       // Server Error - RFC 7231, 6.6.6
                self::STATUS_VARIANT_ALSO_NEGOTIATES              : "Variant Also Negotiates",                          // Server Error - RFC 2295, 8.1
                self::STATUS_INSUFFICIENT_STORAGE                 : "Insufficient Storage",                             // Server Error - RFC 4918, 11.5
                self::STATUS_LOOP_DETECTED                        : "Loop Detected",                                    // Server Error - RFC 5842, 7.2
                self::STATUS_NOT_EXTENDED                         : "Not Extended",                                     // Server Error - RFC 2774, 7
                self::STATUS_NETWORK_AUTHENTICATION_REQUIRED      : "Network Authentication Required",                  // Server Error - RFC 6585, 6

                // Unofficial
                self::STATUS_THIS_IS_FINE                         : "This is fine",                                     // Unofficial - Apache Web Server
                self::STATUS_PAGE_EXPIRED                         : "Page Expired",                                     // Unofficial - Laravel Framework
                self::STATUS_METHOD_FAILURE                       : "Method Failure",                                   // Unofficial - Spring Framework
                self::STATUS_LOGIN_TIMEOUT                        : "Login Time-out",                                   // Unofficial - IIS
                self::STATUS_NO_RESPONSE                          : "No Response",                                      // Unofficial - nginx
                self::STATUS_RETRY_WITH                           : "Retry With",                                       // Unofficial - IIS
                self::STATUS_BLOCKED_BY_WINDOWS_PARENTAL_CONTROLS : "Blocked by Windows Parental Controls (Microsoft)", // Unofficial - nginx
                self::STATUS_REQUEST_HEADER_TOO_LARGE             : "Request header too large",                         // Unofficial - nginx
                self::STATUS_SSL_CERTIFICATE_ERROR                : "SSL Certificate Error",                            // Unofficial - nginx
                self::STATUS_SSL_CERTIFICATE_REQUIRED             : "SSL Certificate Required",                         // Unofficial - nginx
                self::STATUS_HTTP_REQUEST_SENT_TO_HTTPS_PORT      : "HTTP Request Sent to HTTPS Port",                  // Unofficial - nginx
                self::STATUS_INVALID_TOKEN_ESRI                   : "Invalid Token (Esri)",                             // Unofficial - ESRI
                self::STATUS_CLIENT_CLOSED_REQUEST                : "Client Closed Request",                            // Unofficial - nginx
                self::STATUS_BANDWIDTH_LIMIT_EXCEEDED             : "Bandwidth Limit Exceeded",                         // Unofficial - Apache/cPanel
                self::STATUS_UNKNOWN_ERROR                        : "Unknown Error",                                    // Unofficial - Cloudflare
                self::STATUS_WEB_SERVER_IS_DOWN                   : "Web Server Is Down",                               // Unofficial - Cloudflare
                self::STATUS_CONNECTION_TIMEOUT                   : "Connection Timed Out",                             // Unofficial - Cloudflare
                self::STATUS_ORIGIN_IS_UNREACHABLE                : "Origin Is Unreachable",                            // Unofficial - Cloudflare
                self::STATUS_TIMEOUT_OCCURRED                     : "A Timeout Occurred",                               // Unofficial - Cloudflare
                self::STATUS_SSL_HANDSHAKE_FAILED                 : "SSL Handshake Failed",                             // Unofficial - Cloudflare
                self::STATUS_INVALID_SSL_CERTIFICATE              : "Invalid SSL Certificate",                          // Unofficial - Cloudflare
                self::STATUS_RAILGUN_ERROR                        : "Railgun Error",                                    // Unofficial - Cloudflare
                self::STATUS_ORIGIN_DNS_ERROR                     : "Origin DNS Error",                                 // Unofficial - Cloudflare
                self::STATUS_NETWORK_READ_TIMEOUT_ERROR           : "Network read timeout error",                       // Unofficial
                self::STATUS_NETWORK_CONNECT_TIMEOUT_ERROR        : "Network Connect Timeout Error"                     // Unofficial
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

    /**
     * @todo Remove this when we get traits
     */
    private function getBasename(string! uri, var suffix = null) -> string
    {
	var filename, matches;
        let uri = rtrim(uri, DIRECTORY_SEPARATOR);
        let filename = preg_match(
		"@[^" . preg_quote(DIRECTORY_SEPARATOR, "@") . "]+$@",
		uri,
		matches
        ) ? matches[0] : "";
        if suffix {
		let filename = preg_replace("@" . preg_quote(suffix, "@") . "$@", "", filename);
        }

        return filename;
    }
}
