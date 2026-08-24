
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
use Phalcon\Di\Di;
use Phalcon\Di\DiInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Events\Traits\EventsAwareTrait;
use Phalcon\Http\Message\ResponseStatusCodeInterface;
use Phalcon\Http\Response\CookiesInterface;
use Phalcon\Http\Response\Exception;
use Phalcon\Http\Response\Exceptions\NonStandardStatusCodeRequiresMessage;
use Phalcon\Http\Response\Exceptions\ResponseAlreadySent;
use Phalcon\Http\Response\Exceptions\UrlServiceUnavailable;
use Phalcon\Http\Response\Headers;
use Phalcon\Http\Response\HeadersInterface;
use Phalcon\Http\Traits\StatusPhrasesTrait;
use Phalcon\Mvc\Url\UrlInterface;
use Phalcon\Mvc\ViewInterface;
use Phalcon\Support\Helper\File\Basename;
use Phalcon\Support\Helper\Json\Encode;
use Phalcon\Traits\Php\InfoTrait;
use Phalcon\Traits\Php\UrlTrait;

/**
 * Part of the HTTP cycle is return responses to the clients.
 * Phalcon\HTTP\Response is the Phalcon component responsible to achieve this
 * task. HTTP responses are usually composed by headers and body.
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
    use EventsAwareTrait;
    use InfoTrait;
    use StatusPhrasesTrait;
    use UrlTrait;

    protected ?<DiInterface> container = null;
    protected ?string content = null;
    protected ?<CookiesInterface> cookies = null;
    protected <Encode> encode;
    protected ?string file = null;
    protected <Headers> headers;
    protected bool sent = false;
    /**
     * Constructor
     *
     * @throws Exception
     */
    public function __construct(string content = null, code = null, status = null)
    {
        // A Phalcon\Http\Response\Headers bag is temporary used to manage
        // the headers before sent them to the client
        let this->headers = new Headers(),
            this->encode  = new Encode();

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

        if container === null {
            let container = Di::getDefault();

            if container === null {
                throw new UrlServiceUnavailable();
            }

            let this->container = container;
        }

        return container;
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

        let statusReasonPhrase = substr((string) this->headers->get("Status"), 4);

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

        let statusCode = substr((string) this->headers->get("Status"), 0, 3);

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
     * $response->redirect("https://en.wikipedia.org", true);
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
        var header, url, container, view;

        if !location {
            let location = "";
        }

        if externalRedirect {
            let header = location;
        } else {
            /**
             * A local redirect (externalRedirect = false) must not honor an
             * absolute or protocol-relative target, otherwise a request-derived
             * value such as "//evil.tld" or "http://evil.tld" becomes an open
             * redirect (CWE-601). Drop such a target and route through the local
             * url service instead.
             */
            if typeof location == "string" &&
                preg_match("~^(?:[a-z][a-z0-9+.\\-]*:|//)~i", location) {
                let location = "";
            }

            let header = null;
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
        this->headers->remove(name);

        return this;
    }

    /**
     * Resets all the established headers
     */
    public function resetHeaders() -> <ResponseInterface>
    {
        this->headers->reset();

        return this;
    }

    /**
     * Prints out HTTP response to the client
     */
    public function send() -> <ResponseInterface>
    {
        var content, file;

        if unlikely this->sent {
            throw new ResponseAlreadySent();
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
        var eventsManager, headers, result;

        let headers       = this->headers,
            eventsManager = this->eventsManager;

        if this->fireManagerEvent("response:beforeSendHeaders") === false {
            return false; 
        }

        /**
         * Send headers
         */
        let result = headers->send();

        if true === result  {
            this->fireManagerEvent("response:afterSendHeaders");
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
    public function setCache( int minutes) -> <ResponseInterface>
    {
        var date;

        let date = new DateTime();

        date->modify("+" . minutes . " minutes");

        this->setExpires(date);
        this->setHeader("Cache-Control", "max-age=" . (minutes * 60));

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
    public function setContentType(
        string contentType,
        string charset = null
    ) -> <ResponseInterface> {
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
        date->setTimezone(new DateTimeZone("UTC"));

        /**
         * The 'Expires' header set this info
         */
        this->setHeader("Expires", date->format("D, d M Y H:i:s") . " GMT");

        return this;
    }

    /**
     * Sets an attached file to be sent at the end of the request
     */
    public function setFileToSend(
        string filePath,
        var attachmentName = null,
        bool attachment = true
    ) -> <ResponseInterface> {
        var basePath;
        var basePathEncoding = "ASCII";

        if typeof attachmentName != "string" {
            let basePath = (new Basename())->__invoke(filePath);
        } else {
            let basePath = attachmentName;
        }
        if attachment {
            // mbstring is a non-default extension
            if this->phpFunctionExists("mb_detect_encoding") {
                let basePathEncoding = mb_detect_encoding(
                    basePath,
                    mb_detect_order(),
                    true
                );
            }
            this->setRawHeader("Content-Description: File Transfer");
            this->setRawHeader("Content-Type: application/octet-stream");
            this->setRawHeader("Content-Transfer-Encoding: binary");
            // According RFC2231 section-7, non-ASCII header param must add a
            // extended one to indicate charset
            if basePathEncoding != "ASCII" {
                let basePath = this->phpRawUrlEncode(basePath);
                this->setRawHeader(
                    "Content-Disposition: attachment; filename=" 
                    . basePath 
                    . "; filename*="
                    . strtolower(basePathEncoding) 
                    . "''" . basePath
                );
            } else {
                // According RFC2045 section-5.1, header param value contains
                // special chars must be as quoted-string. Always quote value
                // is accepted because the special chars is a large list.
                // According RFC822 appendix-D, CR "\" <"> must to be quoted
                // in syntax rule of quoted-string
                let basePath = addcslashes(basePath, "\15\17\\\"");
                this->setRawHeader(
                    "Content-Disposition: attachment; filename=\"" 
                    . basePath . "\""
                );
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
        this->headers->set(name, value);

        return this;
    }

    /**
     * Sets a headers bag for the response externally
     */
    public function setHeaders(<HeadersInterface> headers) -> <ResponseInterface>
    {
        var data, name, value;

        let data = headers->toArray();

        for name, value in data {
            this->headers->set(name, (string) value);
        }

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
    public function setJsonContent(
        var content,
        int jsonOptions = 0,
        int depth = 512
    ) -> <ResponseInterface> {
        this->setContentType("application/json");

        this->setContent(this->encode->__invoke(content, jsonOptions, depth));

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
        date->setTimezone(new DateTimeZone("UTC"));

        /**
         * The 'Last-Modified' header sets this info
         */
        this->setHeader("Last-Modified", date->format("D, d M Y H:i:s") . " GMT");

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
     * Send a raw header to the response
     *
     *```php
     * $response->setRawHeader("HTTP/1.1 404 Not Found");
     *```
     */
    public function setRawHeader(string header) -> <ResponseInterface>
    {
        this->headers->setRaw(header);

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
        var currentHeadersRaw, key, statusCodes, defaultMessage;

        let currentHeadersRaw = this->headers->toArray();

        /**
         * We use HTTP/1.1 instead of HTTP/1.0
         *
         * Before that we would like to unset any existing HTTP/x.y headers
         */
        for key, _ in currentHeadersRaw {
            if typeof key == "string" && strstr(key, "HTTP/") {
                this->headers->remove(key);
            }
        }

        // if an empty message is given we try and grab the default for this
        // status code. If a default does not exist, stop here.
        if message === null {
            // See: https://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml
            let statusCodes = this->getPhrases();

            if unlikely !isset statusCodes[code] {
                throw new NonStandardStatusCodeRequiresMessage();
            }

            let defaultMessage = statusCodes[code],
                message        = defaultMessage;
        }

        this->headers->setRaw("HTTP/1.1 " . code . " " . message);

        /**
         * We also define a 'Status' header with the HTTP status
         */
        this->headers->set("Status", code . " " . message);

        return this;
    }
}
