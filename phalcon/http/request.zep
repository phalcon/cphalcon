
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
	public function getDI() -> <Phalcon\DiInterface>
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
	public function get(string! name=null, filters=null, defaultValue=null)
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
						let filter = <Phalcon\Filter> dependencyInjector->getShared("filter");
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
	public function getPost(string! name=null, filters=null, defaultValue=null)
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
						let filter = <Phalcon\Filter> dependencyInjector->getShared("filter");
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
	public function getQuery(string! name=null, filters=null, defaultValue=null)
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
						let filter = <Phalcon\Filter> dependencyInjector->getShared("filter");
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
	public function getServer(string! name)
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
	public function has(string! name)
	{
		return isset _REQUEST[name];
	}

	/**
	 * Checks whether $_POST superglobal has certain index
	 *
	 * @param string $name
	 * @return boolean
	 */
	public function hasPost(string! name) -> boolean
	{
		return isset _POST[name];
	}

	/**
	 * Checks whether $_GET superglobal has certain index
	 *
	 * @param string name
	 * @return boolean
	 */
	public function hasQuery(string! name) -> boolean
	{
		return isset _GET[name];
	}

	/**
	 * Checks whether $_SERVER superglobal has certain index
	 *
	 * @param string name
	 * @return boolean
	 */
	public function hasServer(string! name) -> boolean
	{
		return isset _SERVER[name];
	}

	/**
	 * Gets HTTP header from request data
	 *
	 * @param string header
	 * @return string
	 */
	public function getHeader(string! header) -> string
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
	public function getScheme() -> string
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
	public function isAjax() -> boolean
	{
		return this->getHeader("HTTP_X_REQUESTED_WITH") == "XMLHttpRequest";
	}

	/**
	 * Checks whether request has been made using SOAP
	 *
	 * @return boolean
	 */
	public function isSoapRequested() -> boolean
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
	public function isSecureRequest() -> boolean
	{
		return this->getScheme() === "https";
	}

	/**
	 * Gets HTTP raw request body
	 *
	 * @return string
	 */
	public function getRawBody() -> string
	{
		var rawBody, contents;

		let rawBody = this->_rawBody;
		if empty rawBody {

			let contents = file_get_contents("php://input");

			/**
			 * We need store the read raw body because it can't be read again
			 */
			let this->_rawBody = contents;
			return contents;
		}
		return rawBody;
	}

	/**
	 * Gets decoded JSON HTTP raw request body
	 *
	 * @return string
	 */
	public function getJsonRawBody()
	{
		var rawBody;

		let rawBody = this->getRawBody();
		if typeof rawBody == "string" {
			return json_decode(rawBody);
		}
	}

	/**
	 * Gets active server address IP
	 *
	 * @return string
	 */
	public function getServerAddress() -> string
	{
		var server, serverAddr;

		let server = _SERVER;
		if fetch serverAddr, server["SERVER_ADDR"] {
			return serverAddr;
		}
		return gethostbyname("localhost");
	}

	/**
	 * Gets active server name
	 *
	 * @return string
	 */
	public function getServerName() -> string
	{
		var server, serverName;

		let server = _SERVER;
		if fetch serverName, server["SERVER_NAME"] {
			return serverName;
		}

		return "localhost";
	}

	/**
	 * Gets information about schema, host and port used by the request
	 *
	 * @return string
	 */
	public function getHttpHost() -> string
	{
		var httpHost, scheme, name, port;

		/**
		 * Get the server name from _SERVER['HTTP_HOST']
		 */
		let httpHost = this->getServer("HTTP_HOST");
		if httpHost {
			return httpHost;
		}

		/**
		 * Get current scheme
		 */
		let scheme = this->getScheme();

		/**
		 * Get the server name from _SERVER['SERVER_NAME']
		 */
		let name = this->getServer("SERVER_NAME");

		/**
		 * Get the server port from _SERVER['SERVER_PORT']
		 */
		let port = this->getServer("SERVER_PORT");

		/**
		 * If is standard http we return the server name only
		 */
		if scheme == "http" && port == 80  {
			return name;
		}

		/**
		 * If is standard secure http we return the server name only
		 */
		if scheme == "https" && port == "443" {
			return name;
		}

		return name . ":" . port;

	}

	/**
	 * Gets most possible client IPv4 Address. This method search in _SERVER['REMOTE_ADDR'] and optionally in _SERVER['HTTP_X_FORWARDED_FOR']
	 *
	 * @param boolean trustForwardedHeader
	 * @return string|boolean
	 */
	public function getClientAddress(boolean trustForwardedHeader=false) -> string | boolean
	{
		var address;

		let address = null;

		/**
		 * Proxies uses this IP</comment>
		 */
		if trustForwardedHeader {
			fetch address, _SERVER["HTTP_X_FORWARDED_FOR"];
		}

		if address === null {
			fetch address, _SERVER["REMOTE_ADDR"];
		}

		if typeof address == "string" {
			if memstr(address, ",") {
				/**
				 * The client address has multiples parts, only return the first part
				 */
				return explode(",", address)[0];
			}
			return address;
		}

		return false;
	}

	/**
	 * Gets HTTP method which request has been made
	 *
	 * @return string
	 */
	public function getMethod() -> string
	{
		var requestMethod;

		if fetch requestMethod, _SERVER["REQUEST_METHOD"] {
			return requestMethod;
		}
		return "";
	}

	/**
	 * Gets HTTP user agent used to made the request
	 *
	 * @return string
	 */
	public function getUserAgent() -> string
	{
		var userAgent;

		if fetch userAgent, _SERVER["HTTP_USER_AGENT"] {
			return userAgent;
		}
		return "";
	}

	/**
	 * Check if HTTP method match any of the passed methods
	 *
	 * @param string|array methods
	 * @return boolean
	 */
	public function isMethod(var methods) -> boolean
	{
		var httpMethod, method;

		let httpMethod = this->getMethod();
		if typeof methods == "string" {
			return methods == httpMethod;
		} else {
			for method in methods {
				if method == httpMethod {
					return true;
				}
			}
		}
		return false;
	}

	/**
	 * Checks whether HTTP method is POST. if _SERVER["REQUEST_METHOD"]=="POST"
	 *
	 * @return boolean
	 */
	public function isPost() -> boolean
	{
		return this->getMethod() == "POST";
	}

	/**
	 *
	 * Checks whether HTTP method is GET. if _SERVER["REQUEST_METHOD"]=="GET"
	 *
	 * @return boolean
	 */
	public function isGet() -> boolean
	{
		return this->getMethod() == "GET";
	}

	/**
	 * Checks whether HTTP method is PUT. if _SERVER["REQUEST_METHOD"]=="PUT"
	 *
	 * @return boolean
	 */
	public function isPut() -> boolean
	{
		return this->getMethod() == "PUT";
	}

	/**
	 * Checks whether HTTP method is PATCH. if _SERVER["REQUEST_METHOD"]=="PATCH"
	 *
	 * @return boolean
	 */
	public function isPatch() -> boolean
	{
		return this->getMethod() == "PATCH";
	}

	/**
	 * Checks whether HTTP method is HEAD. if _SERVER["REQUEST_METHOD"]=="HEAD"
	 *
	 * @return boolean
	 */
	public function isHead() -> boolean
	{
		return this->getMethod() == "HEAD";
	}

	/**
	 * Checks whether HTTP method is DELETE. if _SERVER["REQUEST_METHOD"]=="DELETE"
	 *
	 * @return boolean
	 */
	public function isDelete() -> boolean
	{
		return this->getMethod() == "DELETE";
	}

	/**
	 * Checks whether HTTP method is OPTIONS. if _SERVER["REQUEST_METHOD"]=="OPTIONS"
	 *
	 * @return boolean
	 */
	public function isOptions() -> boolean
	{
		return this->getMethod() == "OPTIONS";
	}

	/**
	 * Checks whether request include attached files
	 *
	 * @return boolean
	 */
	public function hasFiles(boolean notErrored=false) -> boolean
	{
		var files, file, error;
		int numberFiles;

		let files = _FILES;
		if notErrored {
			return count(files) > 0;
		} else {
			let numberFiles = 0;
			for file in files {
				if !fetch error, file["error"] {
					let error = true;
				}
				if !error {
					let numberFiles++;
				}
			}
		}
		return numberFiles > 0;
	}

	/**
	 * Gets attached files as Phalcon\Http\Request\File instances
	 *
	 * @param boolean notErrored
	 * @return Phalcon\Http\Request\File[]
	 */
	public function getUploadedFiles(boolean notErrored=false) -> <Phalcon\Http\Request\File[]>
	{
		var files, superFiles, file, error;

		let superFiles = _FILES;
		if count(superFiles) {
			let files = [];
			for file in superFiles {
				if notErrored {
					if !fetch error, file["error"] {
						let error = true;
					}
					if !error {
						let files[] = new Phalcon\Http\Request\File(file);
					}
				} else {
					let files[] = new Phalcon\Http\Request\File(file);
				}
			}
			return files;
		}
		return [];
	}

	/**
	 * Returns the available headers in the request
	 *
	 * @return array
	 */
	public function getHeaders() -> boolean
	{
		var headers, key, value;

		let headers = [];
		for key, value in _SERVER {
			if starts_with(key, "HTTP_") {
				let headers[str_replace("HTTP_", "", key)] = value;
			}
		}
		return headers;
	}

	/**
	 * Gets web page that refers active request. ie: http://www.google.com
	 *
	 * @return string
	 */
	public function getHTTPReferer() -> string
	{
		var httpReferer;

		if fetch httpReferer, _SERVER["HTTP_REFERER"] {
			return httpReferer;
		}
		return "";
	}

	/**
	 * Process a request header and return an array of values with their qualities
	 *
	 * @param string serverIndex
	 * @param string name
	 * @return array
	 */
	protected function _getQualityHeader(string! serverIndex, string! name) -> string
	{
		double quality;
		var returnedParts, part, headerParts, qualityPart;

		let returnedParts = [];
		for part in preg_split("/,\\s*/", this->getServer(serverIndex)) {

			let headerParts = explode(";", part);
			if fetch qualityPart, headerParts[1] {
				let quality = (double) substr(qualityPart, 2);
			} else {
				let quality = 1.0;
			}

			let returnedParts[] = [
				name      : headerParts[0],
				"quality" : quality
			];;
		}
		return returnedParts;
	}

	/**
	 * Process a request header and return the one with best quality
	 *
	 * @param array qualityParts
	 * @param string name
	 * @return string
	 */
	protected function _getBestQuality(qualityParts, string! name) -> string
	{
		int i;
		double quality, acceptQuality;
		var selectedName, accept;

		let i = 0,
			quality = 0.0,
			selectedName = "";

		for accept in qualityParts {
			if i == 0 {
				let quality = (double) accept["quality"],
					selectedName = accept[name];
			} else {
				let acceptQuality = (double) accept["quality"];
				if acceptQuality > quality {
					let quality = acceptQuality,
						selectedName = accept[name];
				}
			}
			let i++;
		}
		return selectedName;
	}

	/**
	 * Gets array with mime/types and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT"]
	 *
	 * @return array
	 */
	public function getAcceptableContent()
	{
		return this->_getQualityHeader("HTTP_ACCEPT", "accept");
	}

	/**
	 * Gets best mime/type accepted by the browser/client from _SERVER["HTTP_ACCEPT"]
	 *
	 * @return array
	 */
	public function getBestAccept()
	{
		return this->_getBestQuality(this->getAcceptableContent(), "accept");
	}

	/**
	 * Gets charsets array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_CHARSET"]
	 *
	 * @return array
	 */
	public function getClientCharsets()
	{
		return this->_getQualityHeader("HTTP_ACCEPT_CHARSET", "charset");
	}

	/**
	 * Gets best charset accepted by the browser/client from _SERVER["HTTP_ACCEPT_CHARSET"]
	 *
	 * @return string
	 */
	public function getBestCharset() -> string
	{
		return this->_getBestQuality(this->getClientCharsets(), "charset");
	}

	/**
	 * Gets languages array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
	 *
	 * @return array
	 */
	public function getLanguages()
	{
		return this->_getQualityHeader("HTTP_ACCEPT_LANGUAGE", "language");
	}

	/**
	 * Gets best language accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
	 *
	 * @return string
	 */
	public function getBestLanguage() -> string
	{
		return this->_getBestQuality(this->getLanguages(), "language");
	}

	
	/**
	 * Gets auth info accepted by the browser/client from $_SERVER['PHP_AUTH_USER']
	 *
	 * @return array
	 */
	public function getBasicAuth()
	{
		var auth, username, password;

		if isset _SERVER["PHP_AUTH_USER"] && isset _SERVER["PHP_AUTH_PW"] {
			let auth = [];
			let auth["username"] = _SERVER["PHP_AUTH_USER"];
			let auth["password"] = _SERVER["PHP_AUTH_PW"];
		}

		return auth;
	}

	/**
	 * Gets auth info accepted by the browser/client from $_SERVER['PHP_AUTH_DIGEST']
	 *
	 * @return array
	 */
	public function getDigestAuth()
	{
		var auth, digest, matchs, match;

		if fetch digest, _SERVER["PHP_AUTH_USER"] {
			if !preg_match_all("#(\w+)=(['\"]?)([^'\" ,]+)\2#", digest, matchs, 2) {
				return auth;
			}

			if typeof matchs == array {
				let auth = [];
				for match in matchs {
					let auth[match[1]] = match[3];
				}
			}
		}

		return auth;
	}

}
