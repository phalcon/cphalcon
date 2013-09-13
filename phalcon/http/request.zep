
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
						let dependencyInjector = this->_dependencyInjector;
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
						let dependencyInjector = this->_dependencyInjector;
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
						let dependencyInjector = this->_dependencyInjector;
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
			if (https == "off") {
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

}