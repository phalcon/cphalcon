
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

/**
 * Phalcon\Http\Response
 *
 * Part of the HTTP cycle is return responses to the clients.
 * Phalcon\HTTP\Response is the Phalcon component responsible to achieve this task.
 * HTTP responses are usually composed by headers and body.
 *
 *<code>
 *	$response = new Phalcon\Http\Response();
 *	$response->setStatusCode(200, "OK");
 *	$response->setContent("<html><body>Hello</body></html>");
 *	$response->send();
 *</code>
 */
class Response implements Phalcon\Http\ResponseInterface, Phalcon\Di\InjectionAwareInterface
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
	public function __construct(content=null, code=null, status=null)
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
	public function setDI(<Phalcon\DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <Phalcon\DiInterface>
	{
		var dependencyInjector;
		let dependencyInjector = <Phalcon\DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector == "object" {
			let dependencyInjector = Phalcon\DI::getDefault();
			if typeof dependencyInjector != "object" {
				throw new Phalcon\Http\Request\Exception("A dependency injection object is required to access the 'url' service");
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
	public function setStatusCode(string code, string message) -> <Phalcon\Http\ResponseInterface>
	{
		var headers;

		let headers = this->getHeaders();

		/**
		 * We use HTTP/1.1 instead of HTTP/1.0
		 */
		headers->setRaw("HTTP/1.1 " . code . " " . message);

		/**
		 * We also define a 'Status' header with the HTTP status
		 */
		headers->set(code . " " . message, "Status");

		let this->_headers = headers;
		return this;
	}

	/**
	 * Sets a headers bag for the response externally
	 *
	 * @param Phalcon\Http\Response\HeadersInterface headers
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setHeaders(headers)
	{
		let this->_headers = headers;
		return this;
	}

	/**
	 * Returns headers set by the user
	 *
	 * @return Phalcon\Http\Response\HeadersInterface
	 */
	public function getHeaders() -> <Phalcon\Http\Response\HeadersInterface>
	{
		var headers;
		let headers = this->_headers;
		if headers === null {
			/**
			 * A Phalcon\Http\Response\Headers bag is temporary used to manage the headers before sent them to the client
			 */
			let headers = new Phalcon\Http\Response\Headers(),
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
	public function setCookies(<Phalcon\Http\Response\CookiesInterface> cookies) -> <Phalcon\Http\ResponseInterface>
	{
		if typeof cookies != "object" {
			throw new Phalcon\Http\Response\Exception("The cookies bag is not valid");
		}
		let this->_cookies = cookies;
		return this;
	}

	/**
	 * Returns coookies set by the user
	 *
	 * @return Phalcon\Http\Response\CookiesInterface
	 */
	public function getCookies() -> <Phalcon\Http\Response\CookiesInterface>
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
	public function setHeader(string name, value) -> <Phalcon\Http\ResponseInterface>
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
	 *	response->setRawHeader("HTTP/1.1 404 Not Found");
	 *</code>
	 *
	 * @param string header
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setRawHeader(string header) -> <Phalcon\Http\ResponseInterface>
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
	public function resetHeaders() -> <Phalcon\Http\ResponseInterface>
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
	public function setExpires(<DateTime> datetime) -> <Phalcon\Http\ResponseInterface>
	{
		var headers, date, timezone;

		let headers = this->getHeaders(),
			date = clone datetime;

		/**
		 * All the expiration times are sent in UTC
		 * Change the timezone to utc
		 */
		date->setTimezone(new DateTimeZone("UTC"));

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
	public function setNotModified() -> <Phalcon\Http\ResponseInterface>
	{
		this->setStatusCode("Not modified", 304);
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
	public function setContentType(string contentType, charset=null) -> <Phalcon\Http\ResponseInterface>
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
	public function setEtag(string etag) -> <Phalcon\Http\ResponseInterface>
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
	public function redirect(location=null, externalRedirect=false, statusCode=302) -> <Phalcon\Http\ResponseInterface>
	{
		var header, url, dependencyInjector;

		if externalRedirect {
			let header = location;
		} else {
			let dependencyInjector = this->getDI(),
				url = <Phalcon\Mvc\UrlInterface> dependencyInjector->getShared("url"),
				header = url->get(location);
		}

		/**
		 * The HTTP status is 302 by default, a temporary redirection
		 */
		this->setStatusCode(statusCode, "Redirect");

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
	public function setContent(string content) -> <Phalcon\Http\ResponseInterface>
	{
		let this->_content = content;
		return this;
	}

	/**
	 * Sets HTTP response body. The parameter is automatically converted to JSON
	 *
	 *<code>
	 *	response->setJsonContent(array("status" => "OK"));
	 *</code>
	 *
	 * @param mixed content
	 * @param int jsonOptions
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setJsonContent(var content, jsonOptions=0) -> <Phalcon\Http\ResponseInterface>
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
	public function appendContent(content) -> <Phalcon\Http\ResponseInterface>
	{
		//let this->_content .= content;
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
	public function sendHeaders() -> <Phalcon\Http\ResponseInterface>
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
	public function sendCookies() -> <Phalcon\Http\ResponseInterface>
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
	public function send() -> <Phalcon\Http\ResponseInterface>
	{
		var headers, cookies;

		if this->_sent {
			throw new Phalcon\Http\Response\Exception("Response was already sent");
		}

		/**
		 * Send headers
		 */
		let headers = this->_headers;
		if typeof cookies == "object" {
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
		echo this->_content;

		let this->_sent = true;
		return this;
	}

	/**
	 * Sets an attached file to be sent at the end of the request
	 *
	 * @param string filePath
	 * @param string attachmentName
	 * @return <Phalcon\Http\ResponseInterface>
	 */
	public function setFileToSend(string filePath, attachmentName=null) -> <Phalcon\Http\ResponseInterface>
	{
		var basePath, headers;

		if typeof attachmentName == "string" {
			let basePath = basename(filePath);
		} else {
			let basePath = attachmentName;
		}

		let headers = this->getHeaders();

		headers->setRaw("Content-Description: File Transfer");
		headers->setRaw("Content-Disposition: attachment; filename=" . basePath);
		headers->setRaw("Content-Transfer-Encoding: binary");

		let this->_file = filePath;

		return this;
	}

}