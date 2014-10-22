
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

use Phalcon\Http\ResponseInterface;
use Phalcon\Http\Response\Exception;
use Phalcon\Http\Response\HeadersInterface;
use Phalcon\Http\Response\CookiesInterface;
use Phalcon\Mvc\UrlInterface;
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
 *	$response = new \Phalcon\Http\Response();
 *	$response->setStatusCode(200, "OK");
 *	$response->setContent("<html><body>Hello</body></html>");
 *	$response->send();
 *</code>
 */
class Response implements ResponseInterface, InjectionAwareInterface
{

	protected _sent = false;

	protected _content = null;

	protected _headers = null;

	protected _cookies = null;

	protected _file = null;

	protected _dependencyInjector;

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
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<\Phalcon\DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <\Phalcon\DiInterface>
	{
		var dependencyInjector;
		let dependencyInjector = <\Phalcon\DiInterface> this->_dependencyInjector;
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
	 *
	 * @param int code
	 * @param string message
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setStatusCode(int code, string message) -> <ResponseInterface>
	{
		var headers, currentHeadersRaw, key, value;

		let headers = this->getHeaders(),
			currentHeadersRaw = headers->toArray();

		/**
		 * We use HTTP/1.1 instead of HTTP/1.0
		 *
		 * Before that we would like to unset any existing HTTP/x.y headers
		 */
		if typeof currentHeadersRaw == "array" {
			for key, value in currentHeadersRaw {
				if typeof key == "string" && strstr(key, "HTTP/") {
					headers->remove(key);
				}
			}
		}

		headers->setRaw("HTTP/1.1 " . code . " " . message);

		/**
		 * We also define a 'Status' header with the HTTP status
		 */
		headers->set("Status", code . " " . message);

		let this->_headers = headers;
		return this;
	}

	/**
	 * Sets a headers bag for the response externally
	 *
	 * @param Phalcon\Http\Response\HeadersInterface headers
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setHeaders(<HeadersInterface> headers) -> <ResponseInterface>
	{
		let this->_headers = headers;
		return this;
	}

	/**
	 * Returns headers set by the user
	 *
	 * @return Phalcon\Http\Response\HeadersInterface
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
	 *
	 * @param Phalcon\Http\Response\CookiesInterface cookies
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setCookies(<CookiesInterface> cookies) -> <ResponseInterface>
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
	 * @return Phalcon\Http\ResponseInterface
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
	 *	$response->setRawHeader("HTTP/1.1 404 Not Found");
	 *</code>
	 *
	 * @param string header
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setRawHeader(string header) -> <ResponseInterface>
	{
		var headers;
		let headers = this->getHeaders();
		headers->setRaw(header);
		return this;
	}

	/**
	 * Resets all the stablished headers
	 *
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function resetHeaders() -> <ResponseInterface>
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
	 *
	 * @param DateTime datetime
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setExpires(<\DateTime> datetime) -> <ResponseInterface>
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
	 *
	 * @return Phalcon\Http\ResponseInterface
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
	 *	$response->setContentType('application/pdf');
	 *	$response->setContentType('text/plain', 'UTF-8');
	 *</code>
	 *
	 * @param string contentType
	 * @param string charset
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setContentType(string contentType, charset = null) -> <ResponseInterface>
	{
		var headers, name;
		let headers = this->getHeaders();
		let name = "Content-Type";
		if charset === null {
			headers->set(name, contentType);
		} else {
			headers->set(name, contentType . "; charset=" . charset);
		}
		return this;
	}

	/**
	 * Set a custom ETag
	 *
	 *<code>
	 *	$response->setEtag(md5(time()));
	 *</code>
	 *
	 * @param string etag
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setEtag(string etag) -> <ResponseInterface>
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
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function redirect(location = null, externalRedirect = false, int statusCode = 302) -> <ResponseInterface>
	{
		var header, url, dependencyInjector, messages, matched, message;

		let messages = [
			300: "Multiple Choices",
			301: "Moved Permanently",
			302: "Found",
			303: "See Other",
			304: "Not Modified",
			305: "Use Proxy",
			306: "Switch Proxy",
			307: "Temporary Redirect",
			308: "Permanent Redirect"
		];

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

		if !header {
			let dependencyInjector = this->getDI(),
				url = <UrlInterface> dependencyInjector->getShared("url"),
				header = url->get(location);
		}

		/**
		 * The HTTP status is 302 by default, a temporary redirection
		 */
		if statusCode < 300 || statusCode > 308 {
			let statusCode = 302, message = "Redirect";
		} else {
			fetch message, messages[statusCode];
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
	 *
	 * @param string content
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setContent(string content) -> <ResponseInterface>
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
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setJsonContent(var content, jsonOptions = 0) -> <ResponseInterface>
	{
		let this->_content = json_encode(content, jsonOptions);
		return this;
	}

	/**
	 * Appends a string to the HTTP response body
	 *
	 * @param string content
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function appendContent(content) -> <ResponseInterface>
	{
		let this->_content = this->getContent() . content;
		return this;
	}

	/**
	 * Gets the HTTP response body
	 *
	 * @return string
	 */
	public function getContent() -> string
	{
		return this->_content;
	}

	/**
	 * Check if the response is already sent
	 *
	 * @return boolean
	 */
	public function isSent() -> boolean
	{
		return this->_sent;
	}

	/**
	 * Sends headers to the client
	 *
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function sendHeaders() -> <ResponseInterface>
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
	 *
	 * @return Phalcon\Http\ResponseInterface
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
	 *
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function send() -> <ResponseInterface>
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
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setFileToSend(string filePath, attachmentName = null, attachment = true) -> <ResponseInterface>
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
