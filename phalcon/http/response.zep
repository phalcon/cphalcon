
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 |          Zamrony P. Juhara <zamronypj@yahoo.com>                       |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Http;

use Phalcon\DiInterface;
use Phalcon\Http\Response\Exception;
use Phalcon\Http\Response\HeadersInterface;
use Phalcon\Http\Response\CookiesInterface;
use Phalcon\Mvc\UrlInterface;
use Phalcon\Mvc\ViewInterface;
use Phalcon\Http\Response\Headers;
use Phalcon\Di\InjectionAwareInterface;

/**
 * Phalcon\Http\Response
 *
 * Part of the HTTP cycle is return responses to the clients.
 * Phalcon\HTTP\Response is the Phalcon component responsible to achieve this task.
 * HTTP responses are usually composed by headers and body.
 *
 *<code>
 * $response = new \Phalcon\Http\Response();
 *
 * $response->setStatusCode(200, "OK");
 * $response->setContent("<html><body>Hello</body></html>");
 *
 * $response->send();
 *</code>
 */
class Response implements ResponseInterface, InjectionAwareInterface
{

	protected _sent = false;

	protected _content;

	protected _headers;

	protected _cookies;

	protected _file;

	protected _dependencyInjector;

	/**
	 * Phalcon\Http\Response constructor
	 */
	public function __construct(content = null, code = null, status = null)
	{
		/**
		 * A Phalcon\Http\Response\Headers bag is temporary used to manage the headers before sent them to the client
		 */
		let this->_headers = new Headers();

		if content !== null {
			let this->_content = content;
		}

		if code !== null {
			this->setStatusCode(code, status);
		}
	}

	/**
	 * Sets the dependency injector
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 */
	public function getDI() -> <DiInterface>
	{
		var dependencyInjector;
		let dependencyInjector = <DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			let dependencyInjector = \Phalcon\Di::getDefault();
			if typeof dependencyInjector != "object" {
				throw new Exception("A dependency injection object is required to access the 'url' service");
			}
			let this->_dependencyInjector = dependencyInjector;
		}
		return dependencyInjector;
	}

	/**
	 * Sets the HTTP response code
	 *
	 *<code>
	 * $response->setStatusCode(404, "Not Found");
	 *</code>
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
		if typeof currentHeadersRaw == "array" {
			for key, _ in currentHeadersRaw {
				if typeof key == "string" && strstr(key, "HTTP/") {
					headers->remove(key);
				}
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

			if !isset statusCodes[code] {
				throw new Exception("Non-standard statuscode given without a message");
			}

			let defaultMessage = statusCodes[code],
				message = defaultMessage;
		}

		headers->setRaw("HTTP/1.1 " . code . " " . message);

		/**
		 * We also define a 'Status' header with the HTTP status
		 */
		headers->set("Status", code . " " . message);

		return this;
	}

	/**
	 * Returns the status code
	 *
	 *<code>
	 * echo $response->getStatusCode();
	 *</code>
	 */
	public function getStatusCode() -> int | null
	{
		var statusCode;
		let statusCode = substr(this->getHeaders()->get("Status"), 0, 3);
		return statusCode ? (int) statusCode : null;
	}
	
	/**
	 * Returns the reason phrase
	 *
	 *<code>
	 * echo $response->getReasonPhrase();
	 *</code>
	 */
	public function getReasonPhrase() -> string | null
	{
		var statusReasonPhrase;
		let statusReasonPhrase = substr(this->getHeaders()->get("Status"), 4);
		return statusReasonPhrase ? statusReasonPhrase : null;
	}

	/**
	 * Sets a headers bag for the response externally
	 */
	public function setHeaders(<HeadersInterface> headers) -> <ResponseInterface>
	{
		let this->_headers = headers;
		return this;
	}

	/**
	 * Returns headers set by the user
	 */
	public function getHeaders() -> <HeadersInterface>
	{
		return this->_headers;
	}

	/**
	 * Sets a cookies bag for the response externally
	 */
	public function setCookies(<CookiesInterface> cookies) -> <Response>
	{
		let this->_cookies = cookies;
		return this;
	}

	/**
	 * Returns cookies set by the user
	 *
	 * @return \Phalcon\Http\Response\CookiesInterface
	 */
	public function getCookies() -> <CookiesInterface>
	{
		return this->_cookies;
	}

	/**
	 * Overwrites a header in the response
	 *
	 *<code>
	 * $response->setHeader("Content-Type", "text/plain");
	 *</code>
	 */
	public function setHeader(string name, value) -> <ResponseInterface>
	{
		var headers;
		let headers = this->getHeaders();
		headers->set(name, value);
		return this;
	}

	/**
	 * Send a raw header to the response
	 *
	 *<code>
	 * $response->setRawHeader("HTTP/1.1 404 Not Found");
	 *</code>
	 */
	public function setRawHeader(string header) -> <ResponseInterface>
	{
		var headers;
		let headers = this->getHeaders();
		headers->setRaw(header);
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
	 * Sets an Expires header in the response that allows to use the HTTP cache
	 *
	 *<code>
	 * $this->response->setExpires(
	 *     new DateTime()
	 * );
	 *</code>
	 */
	public function setExpires(<\DateTime> datetime) -> <ResponseInterface>
	{
		var date;

		let date = clone datetime;

		/**
		 * All the expiration times are sent in UTC
		 * Change the timezone to utc
		 */
		date->setTimezone(new \DateTimeZone("UTC"));

		/**
		 * The 'Expires' header set this info
		 */
		this->setHeader("Expires", date->format("D, d M Y H:i:s") . " GMT");
		return this;
	}

	/**
	 * Sets Last-Modified header
	 *
	 *<code>
	 * $this->response->setLastModified(
	 *     new DateTime()
	 * );
	 *</code>
	 */
	public function setLastModified(<\DateTime> datetime) -> <Response>
	{
		var date;

		let date = clone datetime;

		/**
		 * All the Last-Modified times are sent in UTC
		 * Change the timezone to utc
		 */
		date->setTimezone(new \DateTimeZone("UTC"));

		/**
		 * The 'Last-Modified' header sets this info
		 */
		this->setHeader("Last-Modified", date->format("D, d M Y H:i:s") . " GMT");
		return this;
	}

	/**
	 * Sets Cache headers to use HTTP cache
	 *
	 *<code>
	 * $this->response->setCache(60);
	 *</code>
	 */
	public function setCache(int! minutes) -> <Response>
	{
		var date;

		let date = new \DateTime();
		date->modify("+" . minutes . " minutes");

		this->setExpires(date);
		this->setHeader("Cache-Control", "max-age=" . (minutes * 60));

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
	 * Sets the response content-type mime, optionally the charset
	 *
	 *<code>
	 * $response->setContentType("application/pdf");
	 * $response->setContentType("text/plain", "UTF-8");
	 *</code>
	 */
	public function setContentType(string contentType, charset = null) -> <ResponseInterface>
	{
		if charset === null {
			this->setHeader("Content-Type", contentType);
		} else {
			this->setHeader("Content-Type", contentType . "; charset=" . charset);
		}

		return this;
	}

	/**
	 * Sets the response content-length
	 *
	 *<code>
	 * $response->setContentLength(2048);
	 *</code>
	 */
	public function setContentLength(int contentLength) -> <ResponseInterface>
	{
		this->setHeader("Content-Length", contentLength);

		return this;
	}

	/**
	 * Set a custom ETag
	 *
	 *<code>
	 * $response->setEtag(md5(time()));
	 *</code>
	 */
	public function setEtag(string etag) -> <Response>
	{
		this->setHeader("Etag", etag);

		return this;
	}

	/**
	 * Redirect by HTTP to another action or URL
	 *
	 *<code>
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
	 *</code>
	 */
	public function redirect(location = null, boolean externalRedirect = false, int statusCode = 302) -> <ResponseInterface>
	{
		var header, url, dependencyInjector, matched, view;

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

		let dependencyInjector = this->getDI();

		if !header {
			let url = <UrlInterface> dependencyInjector->getShared("url"),
				header = url->get(location);
		}

		if dependencyInjector->has("view") {
			let view = dependencyInjector->getShared("view");
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
	 * Sets HTTP response body
	 *
	 *<code>
	 * $response->setContent("<h1>Hello!</h1>");
	 *</code>
	 */
	public function setContent(string content) -> <ResponseInterface>
	{
		let this->_content = content;
		return this;
	}

	/**
	 * Sets HTTP response body. The parameter is automatically converted to JSON
	 * and also sets default header: Content-Type: "application/json; charset=UTF-8"
	 *
	 *<code>
	 * $response->setJsonContent(
	 *     [
	 *         "status" => "OK",
	 *     ]
	 * );
	 *</code>
	 */
	public function setJsonContent(var content, int jsonOptions = 0, int depth = 512) -> <ResponseInterface>
	{
		this->setContentType("application/json", "UTF-8");
		this->setContent(json_encode(content, jsonOptions, depth));
		return this;
	}

	/**
	 * Appends a string to the HTTP response body
	 */
	public function appendContent(content) -> <ResponseInterface>
	{
		let this->_content = this->getContent() . content;
		return this;
	}

	/**
	 * Gets the HTTP response body
	 */
	public function getContent() -> string
	{
		return this->_content;
	}

	/**
	 * Check if the response is already sent
	 */
	public function isSent() -> boolean
	{
		return this->_sent;
	}

	/**
	 * Sends headers to the client
	 */
	public function sendHeaders() -> <ResponseInterface>
	{
		this->_headers->send();

		return this;
	}

	/**
	 * Sends cookies to the client
	 */
	public function sendCookies() -> <ResponseInterface>
	{
		var cookies;
		let cookies = this->_cookies;
		if typeof cookies == "object" {
			cookies->send();
		}
		return this;
	}

	/**
	 * Prints out HTTP response to the client
	 */
	public function send() -> <ResponseInterface>
	{
		var content, file;

		if this->_sent {
			throw new Exception("Response was already sent");
		}

		this->sendHeaders();

		this->sendCookies();

		/**
		 * Output the response body
		 */
		let content = this->_content;
		if content != null {
			echo content;
		} else {
			let file = this->_file;

			if typeof file == "string" && strlen(file) {
				readfile(file);
			}
		}

		let this->_sent = true;
		return this;
	}

	/**
	 * Sets an attached file to be sent at the end of the request
	 */
	public function setFileToSend(string filePath, attachmentName = null, attachment = true) -> <ResponseInterface>
	{
		var basePath;

		if typeof attachmentName != "string" {
			let basePath = basename(filePath);
		} else {
			let basePath = attachmentName;
		}

		if attachment {
			this->setRawHeader("Content-Description: File Transfer");
			this->setRawHeader("Content-Type: application/octet-stream");
			this->setRawHeader("Content-Disposition: attachment; filename=" . basePath . ";");
			this->setRawHeader("Content-Transfer-Encoding: binary");
		}

		let this->_file = filePath;

		return this;
	}

	/**
	 * Remove a header in the response
	 *
	 *<code>
	 * $response->removeHeader("Expires");
	 *</code>
	 */
	public function removeHeader(string name) -> <Response>
	{
		var headers;
		let headers = this->getHeaders();
		headers->remove(name);
		return this;
	}
}
