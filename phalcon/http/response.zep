
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
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
use Phalcon\Mvc\ViewInterface;

/**
 * Phalcon\Http\Response
 *
 * Part of the HTTP cycle is return responses to the clients.
 * Phalcon\HTTP\Response is the Phalcon component responsible to achieve this task.
 * HTTP responses are usually composed by headers and body.
 *
 *<code>
 *	$response = new \Phalcon\Http\Response();
 *	$response->setStatusCode(200, "OK");
 *	$response->setContent("<html><body>Hello</body></html>");
 *	$response->send();
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

	protected _statusCodes;

	/**
	 * Phalcon\Http\Response constructor
	 *
	 * @param string content
	 * @param int code
	 * @param string status
	 */
	public function __construct(content = null, code = null, status = null)
	{
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
	 *	$response->setStatusCode(404, "Not Found");
	 *</code>
	 */
	public function setStatusCode(int code, string message = null) -> <Response>
	{
		var headers, currentHeadersRaw, key, defaultMessage;

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

			if typeof this->_statusCodes != "array" {
				let this->_statusCodes = [
					// INFORMATIONAL CODES
					100 : "Continue",
					101 : "Switching Protocols",
					102 : "Processing",
					// SUCCESS CODES
					200 : "OK",
					201 : "Created",
					202 : "Accepted",
					203 : "Non-Authoritative Information",
					204 : "No Content",
					205 : "Reset Content",
					206 : "Partial Content",
					207 : "Multi-status",
					208 : "Already Reported",
					// REDIRECTION CODES
					300 : "Multiple Choices",
					301 : "Moved Permanently",
					302 : "Found",
					303 : "See Other",
					304 : "Not Modified",
					305 : "Use Proxy",
					306 : "Switch Proxy", // Deprecated
					307 : "Temporary Redirect",
					// CLIENT ERROR
					400 : "Bad Request",
					401 : "Unauthorized",
					402 : "Payment Required",
					403 : "Forbidden",
					404 : "Not Found",
					405 : "Method Not Allowed",
					406 : "Not Acceptable",
					407 : "Proxy Authentication Required",
					408 : "Request Time-out",
					409 : "Conflict",
					410 : "Gone",
					411 : "Length Required",
					412 : "Precondition Failed",
					413 : "Request Entity Too Large",
					414 : "Request-URI Too Large",
					415 : "Unsupported Media Type",
					416 : "Requested range not satisfiable",
					417 : "Expectation Failed",
					418 : "I'm a teapot",
					422 : "Unprocessable Entity",
					423 : "Locked",
					424 : "Failed Dependency",
					425 : "Unordered Collection",
					426 : "Upgrade Required",
					428 : "Precondition Required",
					429 : "Too Many Requests",
					431 : "Request Header Fields Too Large",
					// SERVER ERROR
					500 : "Internal Server Error",
					501 : "Not Implemented",
					502 : "Bad Gateway",
					503 : "Service Unavailable",
					504 : "Gateway Time-out",
					505 : "HTTP Version not supported",
					506 : "Variant Also Negotiates",
					507 : "Insufficient Storage",
					508 : "Loop Detected",
					511 : "Network Authentication Required"
				];
			}

			if !isset this->_statusCodes[code] {
				throw new Exception("Non-standard statuscode given without a message");
			}

			let defaultMessage = this->_statusCodes[code],
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
	 *	print_r($response->getStatusCode());
	 *</code>
	 */
	public function getStatusCode() -> array
	{
		return this->getHeaders()->get("Status");
	}

	/**
	 * Sets a headers bag for the response externally
	 */
	public function setHeaders(<HeadersInterface> headers) -> <Response>
	{
		let this->_headers = headers;
		return this;
	}

	/**
	 * Returns headers set by the user
	 */
	public function getHeaders() -> <HeadersInterface>
	{
		var headers;
		let headers = this->_headers;
		if headers === null {
			/**
			 * A Phalcon\Http\Response\Headers bag is temporary used to manage the headers before sent them to the client
			 */
			let headers = new Headers(),
				this->_headers = headers;
		}
		return headers;
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
	 * Returns coookies set by the user
	 *
	 * @return Phalcon\Http\Response\CookiesInterface
	 */
	public function getCookies() -> <CookiesInterface>
	{
		return this->_cookies;
	}

	/**
	 * Overwrites a header in the response
	 *
	 *<code>
	 *	$response->setHeader("Content-Type", "text/plain");
	 *</code>
	 *
	 * @param string name
	 * @param string value
	 * @return Phalcon\Http\Response
	 */
	public function setHeader(string name, value) -> <Response>
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
	 *	$response->setRawHeader("HTTP/1.1 404 Not Found");
	 *</code>
	 */
	public function setRawHeader(string header) -> <Response>
	{
		var headers;
		let headers = this->getHeaders();
		headers->setRaw(header);
		return this;
	}

	/**
	 * Resets all the stablished headers
	 */
	public function resetHeaders() -> <Response>
	{
		var headers;
		let headers = this->getHeaders();
		headers->reset();
		return this;
	}

	/**
	 * Sets a Expires header to use HTTP cache
	 *
	 *<code>
	 *	$this->response->setExpires(new DateTime());
	 *</code>
	 */
	public function setExpires(<\DateTime> datetime) -> <Response>
	{
		var headers, date;

		let headers = this->getHeaders(),
			date = clone datetime;

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
	 * Sends a Not-Modified response
	 */
	public function setNotModified() -> <Response>
	{
		this->setStatusCode(304, "Not modified");
		return this;
	}

	/**
	 * Sets the response content-type mime, optionally the charset
	 *
	 *<code>
	 *	$response->setContentType('application/pdf');
	 *	$response->setContentType('text/plain', 'UTF-8');
	 *</code>
	 *
	 * @param string contentType
	 * @param string charset
	 * @return Phalcon\Http\Response
	 */
	public function setContentType(string contentType, charset = null) -> <Response>
	{
		var headers;
		let headers = this->getHeaders();
		if charset === null {
			headers->set("Content-Type", contentType);
		} else {
			headers->set("Content-Type", contentType . "; charset=" . charset);
		}
		return this;
	}

	/**
	 * Set a custom ETag
	 *
	 *<code>
	 *	$response->setEtag(md5(time()));
	 *</code>
	 */
	public function setEtag(string etag) -> <Response>
	{
		var headers;
		let headers = this->getHeaders();
		headers->set("Etag", etag);
		return this;
	}

	/**
	 * Redirect by HTTP to another action or URL
	 *
	 *<code>
	 *  //Using a string redirect (internal/external)
	 *	$response->redirect("posts/index");
	 *	$response->redirect("http://en.wikipedia.org", true);
	 *	$response->redirect("http://www.example.com/new-location", true, 301);
	 *
	 *	//Making a redirection based on a named route
	 *	$response->redirect(array(
	 *		"for" => "index-lang",
	 *		"lang" => "jp",
	 *		"controller" => "index"
	 *	));
	 *</code>
	 *
	 * @param string|array location
	 * @param boolean externalRedirect
	 * @param int statusCode
	 * @return Phalcon\Http\Response
	 */
	public function redirect(location = null, boolean externalRedirect = false, int statusCode = 302) -> <Response>
	{
		var header, url, dependencyInjector, matched, message, view;

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
			let statusCode = 302,
				message = this->_statusCodes[302];
		} else {
			fetch message, this->_statusCodes[statusCode];
		}

		this->setStatusCode(statusCode, message);

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
	 *	response->setContent("<h1>Hello!</h1>");
	 *</code>
	 */
	public function setContent(string content) -> <Response>
	{
		let this->_content = content;
		return this;
	}

	/**
	 * Sets HTTP response body. The parameter is automatically converted to JSON
	 *
	 *<code>
	 *	$response->setJsonContent(array("status" => "OK"));
	 *</code>
	 *
	 * @param mixed content
	 * @param int jsonOptions
	 * @return Phalcon\Http\Response
	 */
	public function setJsonContent(var content, jsonOptions = 0) -> <Response>
	{
		let this->_content = json_encode(content, jsonOptions);
		return this;
	}

	/**
	 * Appends a string to the HTTP response body
	 *
	 * @param string content
	 * @return Phalcon\Http\Response
	 */
	public function appendContent(content) -> <Response>
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
	public function sendHeaders() -> <Response>
	{
		var headers;
		let headers = this->_headers;
		if typeof headers == "object" {
			headers->send();
		}
		return this;
	}

	/**
	 * Sends cookies to the client
	 */
	public function sendCookies() -> <Response>
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
	public function send() -> <Response>
	{
		var headers, cookies, content, file;

		if this->_sent {
			throw new Exception("Response was already sent");
		}

		/**
		 * Send headers
		 */
		let headers = this->_headers;
		if typeof headers == "object" {
			headers->send();
		}

		/**
		 * Send Cookies/comment>
		 */
		let cookies = this->_cookies;
		if typeof cookies == "object" {
			cookies->send();
		}

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
	 *
	 * @param string filePath
	 * @param string attachmentName
	 * @return Phalcon\Http\Response
	 */
	public function setFileToSend(string filePath, attachmentName = null, attachment = true) -> <Response>
	{
		var basePath, headers;

		if typeof attachmentName != "string" {
			let basePath = basename(filePath);
		} else {
			let basePath = attachmentName;
		}

		if attachment {
			let headers = this->getHeaders();

			headers->setRaw("Content-Description: File Transfer");
			headers->setRaw("Content-Type: application/octet-stream");
			headers->setRaw("Content-Disposition: attachment; filename=" . basePath);
			headers->setRaw("Content-Transfer-Encoding: binary");
		}

		let this->_file = filePath;

		return this;
	}
}
