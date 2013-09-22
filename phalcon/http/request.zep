
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
 * Phalcon\Http\Request
 *
 * <p>Encapsulates request information for easy and secure access from application controllers.</p>
 *
 * <p>The request object is a simple value object that is passed between the dispatcher and controller classes.
 * It packages the HTTP request environment.</p>
 *
 *<code>
 *	$request = new Phalcon\Http\Request();
 *	if ($request->isPost() == true) {
 *		if ($request->isAjax() == true) {
 *			echo 'Request was made using POST and AJAX';
 *		}
 *	}
 *</code>
 *
 */
class Request implements Phalcon\Http\RequestInterface, Phalcon\Di\InjectionAwareInterface
{

	protected _dependencyInjector;

	protected _rawBody;

	protected _filter;

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
	public function getDI()
	{
		return this->_dependencyInjector;
	}

	/**
	 * Gets a variable from the $_REQUEST superglobal applying filters if needed.
	 * If no parameters are given the $_REQUEST superglobal is returned
	 *
	 *<code>
	 *	//Returns value from $_REQUEST["user_email"] without sanitizing
	 *	$userEmail = $request->get("user_email");
	 *
	 *	//Returns value from $_REQUEST["user_email"] with sanitizing
	 *	$userEmail = $request->get("user_email", "email");
	 *</code>
	 *
	 * @param string name
	 * @param string|array filters
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function get(name=null, filters=null, defaultValue=null)
	{
		var request, value, filter, dependencyInjector;

		let request = _REQUEST;
		if name !== null {
			if fetch value, request[name] {
				if filters !== null {
					let filter = this->_filter;
					if typeof filter != "object" {
						let dependencyInjector = <Phalcon\Di> this->_dependencyInjector;
						if typeof dependencyInjector != "object" {
							throw new Phalcon\Http\Request\Exception("A dependency injection object is required to access the 'filter' service");
						}
						let filter = dependencyInjector->getShared("filter");
						let this->_filter = filter;
					}
					return filter->sanitize(value, filters);
				} else {
					return value;
				}
			}
			return defaultValue;
		}
		return request;
	}

	/**
	 * Gets a variable from the $_POST superglobal applying filters if needed
	 * If no parameters are given the $_POST superglobal is returned
	 *
	 *<code>
	 *	//Returns value from $_POST["user_email"] without sanitizing
	 *	$userEmail = $request->getPost("user_email");
	 *
	 *	//Returns value from $_POST["user_email"] with sanitizing
	 *	$userEmail = $request->getPost("user_email", "email");
	 *</code>
	 *
	 * @param string name
	 * @param string|array filters
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function getPost(name=null, filters=null, defaultValue=null)
	{
		var post, value, filter, dependencyInjector;

		let post = _POST;
		if name !== null {
			if fetch value, post[name] {
				if filters !== null {
					let filter = this->_filter;
					if typeof filter != "object" {
						let dependencyInjector = <Phalcon\Di> this->_dependencyInjector;
						if typeof dependencyInjector != "object" {
							throw new Phalcon\Http\Request\Exception("A dependency injection object is required to access the 'filter' service");
						}
						let filter = dependencyInjector->getShared("filter");
						let this->_filter = filter;
					}
					return filter->sanitize(value, filters);
				} else {
					return value;
				}
			}
			return defaultValue;
		}
		return post;
	}

	/**
	 * Gets variable from $_GET superglobal applying filters if needed
	 * If no parameters are given the $_GET superglobal is returned
     *
	 *<code>
	 *	//Returns value from $_GET["id"] without sanitizing
	 *	$id = $request->getQuery("id");
	 *
	 *	//Returns value from $_GET["id"] with sanitizing
	 *	$id = $request->getQuery("id", "int");
     *
	 *	//Returns value from $_GET["id"] with a default value
	 *	$id = $request->getQuery("id", null, 150);
	 *</code>
	 *
	 * @param string name
	 * @param string|array filters
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function getQuery(name=null, filters=null, defaultValue=null)
	{
		var get, value, filter, dependencyInjector;

		let get = _GET;
		if name !== null {
			if fetch value, get[name] {
				if filters !== null {
					let filter = this->_filter;
					if typeof filter != "object" {
						let dependencyInjector = <Phalcon\Di> this->_dependencyInjector;
						if typeof dependencyInjector != "object" {
							throw new Phalcon\Http\Request\Exception("A dependency injection object is required to access the 'filter' service");
						}
						let filter = dependencyInjector->getShared("filter");
						let this->_filter = filter;
					}
					return filter->sanitize(value, filters);
				} else {
					return value;
				}
			}
			return defaultValue;
		}
		return get;
	}

	/**
	 * Gets variable from $_SERVER superglobal
	 *
	 * @param string name
	 * @return mixed
	 */
	public function getServer(name)
	{
		var serverValue;

		if fetch serverValue, _SERVER[name] {
			return serverValue;
		}
		return null;
	}

	/**
	 * Checks whether $_REQUEST superglobal has certain index
	 *
	 * @param string name
	 * @return boolean
	 */
	public function has(name)
	{
		return isset _REQUEST[name];
	}

	/**
	 * Checks whether $_POST superglobal has certain index
	 *
	 * @param string $name
	 * @return boolean
	 */
	public function hasPost(name)
	{
		return isset _POST[name];
	}

	/**
	 * Checks whether $_GET superglobal has certain index
	 *
	 * @param string name
	 * @return boolean
	 */
	public function hasQuery(name)
	{
		return isset _GET[name];
	}

	/**
	 * Checks whether $_SERVER superglobal has certain index
	 *
	 * @param string name
	 * @return mixed
	 */
	public function hasServer(name)
	{
		return isset _SERVER[name];
	}

	/**
	 * Gets HTTP header from request data
	 *
	 * @param string header
	 * @return string
	 */
	public function getHeader(header)
	{
		var serverValue, headerValue;

		if fetch serverValue, _SERVER[header] {
			return serverValue;
		} else {
			if fetch headerValue, _SERVER["HTTP_" . header] {
				return headerValue;
			}
		}
		return "";
	}

	/**
	 * Gets HTTP schema (http/https)
	 *
	 * @return string
	 */
	public function getScheme()
	{
		var https, scheme;

		let https = this->getServer("HTTPS");
		if https {
			if https == "off" {
				let scheme = "http";
			} else {
				let scheme = "https";
			}
		} else {
			let scheme = "http";
		}
		return scheme;
	}

	/**
	 * Checks whether request has been made using ajax. Checks if $_SERVER['HTTP_X_REQUESTED_WITH']=='XMLHttpRequest'
	 *
	 * @return boolean
	 */
	public function isAjax()
	{
		return this->getHeader("HTTP_X_REQUESTED_WITH") == "XMLHttpRequest";
	}

	/**
	 * Checks whether request has been made using SOAP
	 *
	 * @return boolean
	 */
	public function isSoapRequested()
	{
		var server, contentType;

		let server = _SERVER;
		if isset server["HTTP_SOAPACTION"] {
			return true;
		} else {
			if fetch contentType, server["CONTENT_TYPE"] {
				return memstr(contentType, "application/soap+xml");
			}
		}
		return false;
	}

	/**
	 * Checks whether request has been made using any secure layer
	 *
	 * @return boolean
	 */
	public function isSecureRequest()
	{

	}

	/**
	 * Gets HTTP raw request body
	 *
	 * @return string
	 */
	public function getRawBody()
	{

	}

	/**
	 * Gets decoded JSON HTTP raw request body
	 *
	 * @return string
	 */
	public function getJsonRawBody()
	{

	}

	/**
	 * Gets active server address IP
	 *
	 * @return string
	 */
	public function getServerAddress()
	{

	}

	/**
	 * Gets active server name
	 *
	 * @return string
	 */
	public function getServerName()
	{

	}

	/**
	 * Gets information about schema, host and port used by the request
	 *
	 * @return string
	 */
	public function getHttpHost()
	{


	}

	/**
	 * Gets most possible client IPv4 Address. This method search in _SERVER['REMOTE_ADDR'] and optionally in _SERVER['HTTP_X_FORWARDED_FOR']
	 *
	 * @param boolean trustForwardedHeader
	 * @return string
	 */
	public function getClientAddress(trustForwardedHeader=false)
	{

	}

	/**
	 * Gets HTTP method which request has been made
	 *
	 * @return string
	 */
	public function getMethod()
	{

	}

	/**
	 * Gets HTTP user agent used to made the request
	 *
	 * @return string
	 */
	public function getUserAgent()
	{

	}

	/**
	 * Check if HTTP method match any of the passed methods
	 *
	 * @param string|array methods
	 * @return boolean
	 */
	public function isMethod(methods)
	{

	}

	/**
	 * Checks whether HTTP method is POST. if _SERVER["REQUEST_METHOD"]=="POST"
	 *
	 * @return boolean
	 */
	public function isPost()
	{
		return this->getMethod() == "POST";
	}

	/**
	 *
	 * Checks whether HTTP method is GET. if _SERVER["REQUEST_METHOD"]=="GET"
	 *
	 * @return boolean
	 */
	public function isGet()
	{
		return this->getMethod() == "GET";
	}

	/**
	 * Checks whether HTTP method is PUT. if _SERVER["REQUEST_METHOD"]=="PUT"
	 *
	 * @return boolean
	 */
	public function isPut()
	{
		return this->getMethod() == "PUT";
	}

	/**
	 * Checks whether HTTP method is PATCH. if _SERVER["REQUEST_METHOD"]=="PATCH"
	 *
	 * @return boolean
	 */
	public function isPatch()
	{
		return this->getMethod() == "PATCH";
	}

	/**
	 * Checks whether HTTP method is HEAD. if _SERVER["REQUEST_METHOD"]=="HEAD"
	 *
	 * @return boolean
	 */
	public function isHead(){
		return this->getMethod() == "HEAD";
	}

	/**
	 * Checks whether HTTP method is DELETE. if _SERVER["REQUEST_METHOD"]=="DELETE"
	 *
	 * @return boolean
	 */
	public function isDelete()
	{
		return this->getMethod() == "DELETE";
	}

	/**
	 * Checks whether HTTP method is OPTIONS. if _SERVER["REQUEST_METHOD"]=="OPTIONS"
	 *
	 * @return boolean
	 */
	public function isOptions()
	{
		return this->getMethod() == "OPTIONS";
	}

	/**
	 * Checks whether request include attached files
	 *
	 * @return boolean
	 */
	public function hasFiles(notErrored=false)
	{

	}

	/**
	 * Gets attached files as Phalcon\Http\Request\File instances
	 *
	 * @param boolean notErrored
	 * @return Phalcon\Http\Request\File[]
	 */
	public function getUploadedFiles(notErrored=false)
	{
	}

	/**
	 * Returns the available headers in the request
	 *
	 * @return array
	 */
	public function getHeaders()
	{

	}

	/**
	 * Gets web page that refers active request. ie: http://www.google.com
	 *
	 * @return string
	 */
	public function getHTTPReferer()
	{

	}

	/**
	 * Process a request header and return an array of values with their qualities
	 *
	 * @param string serverIndex
	 * @param string name
	 * @return array
	 */
	protected function _getQualityHeader(serverIndex, name)
	{

	}

	/**
	 * Process a request header and return the one with best quality
	 *
	 * @param array qualityParts
	 * @param string name
	 * @return string
	 */
	protected function _getBestQuality(qualityParts, name)
	{

	}

	/**
	 * Gets array with mime/types and their quality accepted by the browser/client from _SERVER['HTTP_ACCEPT']
	 *
	 * @return array
	 */
	public function getAcceptableContent()
	{

	}

	/**
	 * Gets best mime/type accepted by the browser/client from _SERVER['HTTP_ACCEPT']
	 *
	 * @return array
	 */
	public function getBestAccept()
	{

	}

	/**
	 * Gets charsets array and their quality accepted by the browser/client from _SERVER['HTTP_ACCEPT_CHARSET']
	 *
	 * @return array
	 */
	public function getClientCharsets()
	{

	}

	/**
	 * Gets best charset accepted by the browser/client from _SERVER['HTTP_ACCEPT_CHARSET']
	 *
	 * @return string
	 */
	public function getBestCharset()
	{

	}

	/**
	 * Gets languages array and their quality accepted by the browser/client from _SERVER['HTTP_ACCEPT_LANGUAGE']
	 *
	 * @return array
	 */
	public function getLanguages()
	{

	}

	/**
	 * Gets best language accepted by the browser/client from _SERVER['HTTP_ACCEPT_LANGUAGE']
	 *
	 * @return string
	 */
	public function getBestLanguage()
	{

	}

}