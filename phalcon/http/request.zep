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

use Phalcon\DiInterface;
use Phalcon\Http\RequestInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Http\Request\Exception;
use Phalcon\Http\Request\File;

/**
 * Phalcon\Http\Request
 *
 * <p>Encapsulates request information for easy and secure access from application controllers.</p>
 *
 * <p>The request object is a simple value object that is passed between the dispatcher and controller classes.
 * It packages the HTTP request environment.</p>
 *
 *<code>
 *	$request = new \Phalcon\Http\Request();
 *	if ($request->isPost() == true) {
 *		if ($request->isAjax() == true) {
 *			echo 'Request was made using POST and AJAX';
 *		}
 *	}
 *</code>
 *
 */
class Request implements RequestInterface, InjectionAwareInterface
{

	protected _dependencyInjector;

	protected _rawBody;

	protected _filter;

	/**
	 * Sets the dependency injector
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the internal dependency injector
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <DiInterface>
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
	 * @param boolean notAllowEmpty
	 * @param boolean noRecursive
	 * @return mixed
	 */
	public function get(string! name = null, filters = null, defaultValue = null, notAllowEmpty = false, noRecursive = false)
	{
		var request, value, filter, dependencyInjector;

		let request = _REQUEST;
		if name !== null {
			if fetch value, request[name] {
				if filters !== null {
					let filter = this->_filter;
					if typeof filter != "object" {
						let dependencyInjector = <DiInterface> this->_dependencyInjector;
						if typeof dependencyInjector != "object" {
							throw new Exception("A dependency injection object is required to access the 'filter' service");
						}
						let filter = <\Phalcon\Filter> dependencyInjector->getShared("filter");
						let this->_filter = filter;
					}

					let value = filter->sanitize(value, filters, noRecursive);

					if (empty(value) && notAllowEmpty === true) || value === false {
						return defaultValue;
					}

					return value;

				} else {

				 	if (empty(value) && notAllowEmpty === true) {
				 		return defaultValue;
				 	}

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
	 * @param boolean notAllowEmpty
	 * @param boolean noRecursive
	 * @return mixed
	 */
	public function getPost(string! name = null, filters = null, defaultValue = null, notAllowEmpty = false, noRecursive = false)
	{
		var post, value, filter, dependencyInjector;

		let post = _POST;
		if name !== null {
			if fetch value, post[name] {
				if filters !== null {
					let filter = this->_filter;
					if typeof filter != "object" {
						let dependencyInjector = <DiInterface> this->_dependencyInjector;
						if typeof dependencyInjector != "object" {
							throw new Exception("A dependency injection object is required to access the 'filter' service");
						}
						let filter = <\Phalcon\Filter> dependencyInjector->getShared("filter");
						let this->_filter = filter;
					}

					let value = filter->sanitize(value, filters, noRecursive);

					if (empty(value) && notAllowEmpty === true) {
						return defaultValue;
					}

					return value;

				} else {
				 	if empty(value) && notAllowEmpty === true {
				 		return defaultValue;
				 	}
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
	 * @param boolean notAllowEmpty
	 * @param boolean noRecursive
	 * @return mixed
	 */
	public function getQuery(string! name = null, filters = null, defaultValue = null, notAllowEmpty = false, noRecursive = false)
	{
		var get, value, filter, dependencyInjector;

		let get = _GET;
		if name !== null {
			if fetch value, get[name] {
				if filters !== null {
					let filter = this->_filter;
					if typeof filter != "object" {
						let dependencyInjector = <DiInterface> this->_dependencyInjector;
						if typeof dependencyInjector != "object" {
							throw new Exception("A dependency injection object is required to access the 'filter' service");
						}
						let filter = <\Phalcon\Filter> dependencyInjector->getShared("filter");
						let this->_filter = filter;
					}

					let value = filter->sanitize(value, filters, noRecursive);

					if (empty(value) && notAllowEmpty === true) {
						return defaultValue;
					}

					return value;

				} else {

					if (empty(value) && notAllowEmpty === true) {
						return defaultValue;
					}

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
	public function has(string! name) -> boolean
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
	public final function hasServer(string! name) -> boolean
	{
		return isset _SERVER[name];
	}

	/**
	 * Gets HTTP header from request data
	 *
	 * @param string header
	 * @return string
	 */
	public final function getHeader(string! header) -> string
	{
		var value, name;

		let name = strtoupper(strtr(header, "-", "_"));

		if fetch value, _SERVER[name] {
			return value;
		} else {
			if fetch value, _SERVER["HTTP_" . name] {
				return value;
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
	 * Checks whether request has been made using ajax
	 *
	 * @return boolean
	 */
	public function isAjax() -> boolean
	{
		return isset _SERVER["HTTP_X_REQUESTED_WITH"] && _SERVER["HTTP_X_REQUESTED_WITH"] === "XMLHttpRequest";
	}

	/**
	 * Checks whether request has been made using SOAP
	 *
	 * @return boolean
	 */
	public function isSoapRequested() -> boolean
	{
		var contentType;

		if isset _SERVER["HTTP_SOAPACTION"] {
			return true;
		} else {
			let contentType = this->getContentType();
			if !empty contentType {
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
	 * @param boolean associative
	 * @return string
	 */
	public function getJsonRawBody(boolean associative = false)
	{
		var rawBody;

		let rawBody = this->getRawBody();
		if typeof rawBody == "string" {
			return json_decode(rawBody, associative);
		}

		return false;
	}

	/**
	 * Gets active server address IP
	 *
	 * @return string
	 */
	public function getServerAddress() -> string
	{
		var serverAddr;

		if fetch serverAddr, _SERVER["SERVER_ADDR"] {
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
		var serverName;

		if fetch serverName, _SERVER["SERVER_NAME"] {
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
	 * Gets HTTP URI which request has been made
	 *
	 * @return string
	 */
	public final function getURI() -> string
	{
		var requestURI;

		if fetch requestURI, _SERVER["REQUEST_URI"] {
			return requestURI;
		}

		return "";
	}

	/**
	 * Gets most possible client IPv4 Address. This method search in _SERVER['REMOTE_ADDR'] and optionally in _SERVER['HTTP_X_FORWARDED_FOR']
	 *
	 * @param boolean trustForwardedHeader
	 * @return string|boolean
	 */
	public function getClientAddress(boolean trustForwardedHeader = false) -> string | boolean
	{
		var address = null;

		/**
		 * Proxies uses this IP
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
	public final function getMethod() -> string
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
			if typeof methods == "array" {
				for method in methods {
					if method == httpMethod {
						return true;
					}
				}
			}
		}
		return false;
	}

	/**
	 * Checks whether HTTP method is POST. if _SERVER["REQUEST_METHOD"]==="POST"
	 *
	 * @return boolean
	 */
	public function isPost() -> boolean
	{
		return this->getMethod() === "POST";
	}

	/**
	 *
	 * Checks whether HTTP method is GET. if _SERVER["REQUEST_METHOD"]==="GET"
	 *
	 * @return boolean
	 */
	public function isGet() -> boolean
	{
		return this->getMethod() === "GET";
	}

	/**
	 * Checks whether HTTP method is PUT. if _SERVER["REQUEST_METHOD"]==="PUT"
	 *
	 * @return boolean
	 */
	public function isPut() -> boolean
	{
		return this->getMethod() === "PUT";
	}

	/**
	 * Checks whether HTTP method is PATCH. if _SERVER["REQUEST_METHOD"]==="PATCH"
	 *
	 * @return boolean
	 */
	public function isPatch() -> boolean
	{
		return this->getMethod() === "PATCH";
	}

	/**
	 * Checks whether HTTP method is HEAD. if _SERVER["REQUEST_METHOD"]==="HEAD"
	 *
	 * @return boolean
	 */
	public function isHead() -> boolean
	{
		return this->getMethod() === "HEAD";
	}

	/**
	 * Checks whether HTTP method is DELETE. if _SERVER["REQUEST_METHOD"]==="DELETE"
	 *
	 * @return boolean
	 */
	public function isDelete() -> boolean
	{
		return this->getMethod() === "DELETE";
	}

	/**
	 * Checks whether HTTP method is OPTIONS. if _SERVER["REQUEST_METHOD"]==="OPTIONS"
	 *
	 * @return boolean
	 */
	public function isOptions() -> boolean
	{
		return this->getMethod() === "OPTIONS";
	}

	/**
	 * Checks whether request include attached files
	 *
	 * @param boolean onlySuccessful
	 * @return boolean
	 */
	public function hasFiles(boolean onlySuccessful = false) -> long
	{
		var files, file, error;
		int numberFiles = 0;

		let files = _FILES;

		if typeof files != "array" {
			return 0;
		}

		for file in files {
			if fetch error, file["error"] {

				if typeof error != "array" {
					if !error || !onlySuccessful {
						let numberFiles++;
					}
				}

				if typeof error == "array" {
					let numberFiles += this->hasFileHelper(error, onlySuccessful);
				}
			}
		}

		return numberFiles;
	}

	private function hasFileHelper(data, boolean onlySuccessful) -> long
	{
		var value;
		int numberFiles = 0;

		if typeof data != "array" {
			return 1;
		}

		for value in data {
			if typeof value != "array" {
				if !value || !onlySuccessful {
					let numberFiles++;
				}
			}

			if typeof value == "array" {
				let numberFiles += this->hasFileHelper(value, onlySuccessful);
			}
		}

		return numberFiles;
	}

	/**
	 * Gets attached files as Phalcon\Http\Request\File instances
	 *
	 * @param boolean notErrored
	 * @return Phalcon\Http\Request\File[]
	 */
	public function getUploadedFiles(boolean notErrored = false) -> <File[]>
	{
		var superFiles, prefix, input, smoothInput, files, file, dataFile;

		let superFiles = _FILES;

		let files = [];

		if (count(superFiles) > 0) {

			for prefix, input in superFiles {
				if (typeof input["name"] == "array") {
					let smoothInput = this->smoothFiles(input["name"], input["type"], input["tmp_name"], input["size"], input["error"], prefix);

					for file in smoothInput {
						if (notErrored == false || file["error"] == UPLOAD_ERR_OK) {
							let dataFile = [
								"name": file["name"],
								"type": file["type"],
								"tmp_name": file["tmp_name"],
								"size": file["size"],
								"error": file["error"]
							];

							let files[] = new File(dataFile, file["key"]);
						}
					}
				} else {
					if (notErrored == false || input["error"] == UPLOAD_ERR_OK) {
						let files[] = new File(input, prefix);
					}
				}
			}
		}

		return files;
	}

	/**
	 * smooth out $_FILES to have plain array with all files uploaded
	 *
	 * @param array names
	 * @param array types
	 * @param array tmp_names
	 * @param array sizes
	 * @param array errors
	 * @return array
	 */
	protected function smoothFiles(array! names, array! types, array! tmp_names, array! sizes, array! errors, string prefix) -> array
	{
		var idx, name, file, files, parentFiles, p;

		let files = [];

		for idx, name in names {
			let p = prefix . "." . idx;

			if typeof name == "string" {

				let files[] = [
					"name": name,
					"type": types[idx],
					"tmp_name": tmp_names[idx],
					"size": sizes[idx],
					"error": errors[idx],
					"key": p
				];
			}

			if typeof name == "array" {
				let parentFiles = this->smoothFiles(names[idx], types[idx], tmp_names[idx], sizes[idx], errors[idx], p);

				for file in parentFiles {
					let files[] = file;
				}
			}
		}

		return files;
	}

	/**
	 * Returns the available headers in the request
	 *
	 * @return array
	 */
	public function getHeaders() -> array
	{
		var name, value, headers, contentHeaders;

		let headers = [];
		let contentHeaders = ["CONTENT_TYPE": true, "CONTENT_LENGTH": true];

		for name, value in _SERVER {
			if starts_with(name, "HTTP_") {
				let name = ucwords(strtolower(str_replace("_", " ", substr(name, 5)))),
					name = str_replace(" ", "-", name);
				let headers[name] = value;
			} elseif isset(contentHeaders[name]) {
				let name = ucwords(strtolower(str_replace("_", " ", name))),
					name = str_replace(" ", "-", name);
				let headers[name] = value;
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
	protected function _getQualityHeader(string! serverIndex, string! name) -> array
	{
		var returnedParts, part, headerParts, headerPart, split;

		let returnedParts = [];
		for part in preg_split("/,\\s*/", this->getServer(serverIndex), -1, PREG_SPLIT_NO_EMPTY) {

			let headerParts = [];
			for headerPart in preg_split("/\s*;\s*/", trim(part), -1, PREG_SPLIT_NO_EMPTY) {
				if strpos(headerPart, "=") !== false {
					let split = explode("=", headerPart, 2);
					if split[0] === "q" {
						let headerParts["quality"] = (double) split[1];
					} else {
						let headerParts[split[0]] = split[1];
					}
				} else {
					let headerParts[name] = headerPart;
					let headerParts["quality"] = 1.0;
				}
			}

			let returnedParts[] = headerParts;
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
	 * Gets content type which request has been made
	 *
	 * @return mixed
	 */
	public function getContentType()
	{
		var contentType;

		if fetch contentType, _SERVER["CONTENT_TYPE"] {
			return contentType;
		} else {
			/**
			 * @see https://bugs.php.net/bug.php?id=66606
			 */
			if fetch contentType, _SERVER["HTTP_CONTENT_TYPE"] {
				return contentType;
			}
		}

		return null;
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
	 * @return string
	 */
	public function getBestAccept() -> string
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
	public function getLanguages() -> array
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
		var auth;

		if isset _SERVER["PHP_AUTH_USER"] && isset _SERVER["PHP_AUTH_PW"] {
			let auth = [];
			let auth["username"] = _SERVER["PHP_AUTH_USER"];
			let auth["password"] = _SERVER["PHP_AUTH_PW"];
			return auth;
		}

		return null;
	}

	/**
	 * Gets auth info accepted by the browser/client from $_SERVER['PHP_AUTH_DIGEST']
	 *
	 * @return array
	 */
	public function getDigestAuth() -> array
	{
		var digest, matches, match;
		array auth;

		let auth = [];
		if fetch digest, _SERVER["PHP_AUTH_DIGEST"] {
			let matches = [];
			if !preg_match_all("#(\\w+)=(['\"]?)([^'\" ,]+)\\2#", digest, matches, 2) {
				return auth;
			}
			if typeof matches == "array" {
				for match in matches {
					let auth[match[1]] = match[3];
				}
			}
		}

		return auth;
	}

}
