
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
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Http;

use Phalcon\DiInterface;
use Phalcon\FilterInterface;
use Phalcon\Http\Request\File;
use Phalcon\Http\Request\Exception;
use Phalcon\Events\ManagerInterface;
use Phalcon\Di\InjectionAwareInterface;

/**
 * Phalcon\Http\Request
 *
 * Encapsulates request information for easy and secure access from application controllers.
 *
 * The request object is a simple value object that is passed between the dispatcher and controller classes.
 * It packages the HTTP request environment.
 *
 *<code>
 * use Phalcon\Http\Request;
 *
 * $request = new Request();
 *
 * if ($request->isPost() && $request->isAjax()) {
 *     echo "Request was made using POST and AJAX";
 * }
 *
 * $request->getServer("HTTP_HOST"); // Retrieve SERVER variables
 * $request->getMethod();            // GET, POST, PUT, DELETE, HEAD, OPTIONS, PATCH, PURGE, TRACE, CONNECT
 * $request->getLanguages();         // An array of languages the client accepts
 *</code>
 */
class Request implements RequestInterface, InjectionAwareInterface
{

	protected _dependencyInjector;

	protected _rawBody;

	protected _filter;

	protected _putCache;

	protected _httpMethodParameterOverride = false { get, set };

	protected _strictHostCheck = false;

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
		return this->_dependencyInjector;
	}

	/**
	 * Gets a variable from the $_REQUEST superglobal applying filters if needed.
	 * If no parameters are given the $_REQUEST superglobal is returned
	 *
	 *<code>
	 * // Returns value from $_REQUEST["user_email"] without sanitizing
	 * $userEmail = $request->get("user_email");
	 *
	 * // Returns value from $_REQUEST["user_email"] with sanitizing
	 * $userEmail = $request->get("user_email", "email");
	 *</code>
	 */
	public function get(string! name = null, var filters = null, var defaultValue = null, boolean notAllowEmpty = false, boolean noRecursive = false) -> var
	{
		return this->getHelper(_REQUEST, name, filters, defaultValue, notAllowEmpty, noRecursive);
	}

	/**
	 * Gets a variable from the $_POST superglobal applying filters if needed
	 * If no parameters are given the $_POST superglobal is returned
	 *
	 *<code>
	 * // Returns value from $_POST["user_email"] without sanitizing
	 * $userEmail = $request->getPost("user_email");
	 *
	 * // Returns value from $_POST["user_email"] with sanitizing
	 * $userEmail = $request->getPost("user_email", "email");
	 *</code>
	 */
	public function getPost(string! name = null, var filters = null, var defaultValue = null, boolean notAllowEmpty = false, boolean noRecursive = false) -> var
	{
		return this->getHelper(_POST, name, filters, defaultValue, notAllowEmpty, noRecursive);
	}

	/**
	 * Gets a variable from put request
	 *
	 *<code>
	 * // Returns value from $_PUT["user_email"] without sanitizing
	 * $userEmail = $request->getPut("user_email");
	 *
	 * // Returns value from $_PUT["user_email"] with sanitizing
	 * $userEmail = $request->getPut("user_email", "email");
	 *</code>
	 */
	public function getPut(string! name = null, var filters = null, var defaultValue = null, boolean notAllowEmpty = false, boolean noRecursive = false) -> var
	{
		var put, contentType;

		let put = this->_putCache;

		if typeof put != "array" {
			let contentType = this->getContentType();
			if typeof contentType == "string" && stripos(contentType, "json") != false {
				let put = this->getJsonRawBody(true);
				if (typeof put != "array") {
					let put = [];
				}
			} else {
				let put = [];
				parse_str(this->getRawBody(), put);
			}

			let this->_putCache = put;
		}

		return this->getHelper(put, name, filters, defaultValue, notAllowEmpty, noRecursive);
	}

	/**
	 * Gets variable from $_GET superglobal applying filters if needed
	 * If no parameters are given the $_GET superglobal is returned
	 *
	 *<code>
	 * // Returns value from $_GET["id"] without sanitizing
	 * $id = $request->getQuery("id");
	 *
	 * // Returns value from $_GET["id"] with sanitizing
	 * $id = $request->getQuery("id", "int");
	 *
	 * // Returns value from $_GET["id"] with a default value
	 * $id = $request->getQuery("id", null, 150);
	 *</code>
	 */
	public function getQuery(string! name = null, var filters = null, var defaultValue = null, boolean notAllowEmpty = false, boolean noRecursive = false) -> var
	{
		return this->getHelper(_GET, name, filters, defaultValue, notAllowEmpty, noRecursive);
	}

	/**
	 * Helper to get data from superglobals, applying filters if needed.
	 * If no parameters are given the superglobal is returned.
	 */
	protected final function getHelper(array source, string! name = null, var filters = null, var defaultValue = null, boolean notAllowEmpty = false, boolean noRecursive = false) -> var
	{
		var value, filter, dependencyInjector;

		if name === null {
			return source;
		}

		if !fetch value, source[name] {
			return defaultValue;
		}

		if filters !== null {
			let filter = this->_filter;
			if typeof filter != "object" {
				let dependencyInjector = <DiInterface> this->_dependencyInjector;
				if typeof dependencyInjector != "object" {
					throw new Exception("A dependency injection object is required to access the 'filter' service");
				}
				let filter = <FilterInterface> dependencyInjector->getShared("filter");
				let this->_filter = filter;
			}

			let value = filter->sanitize(value, filters, noRecursive);
		}

		if empty value && notAllowEmpty === true {
			return defaultValue;
		}

		return value;
	}

	/**
	 * Gets variable from $_SERVER superglobal
	 */
	public function getServer(string! name) -> string | null
	{
		var serverValue;

		if fetch serverValue, _SERVER[name] {
			return serverValue;
		}
		return null;
	}

	/**
	 * Checks whether $_REQUEST superglobal has certain index
	 */
	public function has(string! name) -> boolean
	{
		return isset _REQUEST[name];
	}

	/**
	 * Checks whether $_POST superglobal has certain index
	 */
	public function hasPost(string! name) -> boolean
	{
		return isset _POST[name];
	}

	/**
	 * Checks whether the PUT data has certain index
	 */
	public function hasPut(string! name) -> boolean
	{
		var put;

		let put = this->getPut();

		return isset put[name];
	}

	/**
	 * Checks whether $_GET superglobal has certain index
	 */
	public function hasQuery(string! name) -> boolean
	{
		return isset _GET[name];
	}

	/**
	 * Checks whether $_SERVER superglobal has certain index
	 */
	public final function hasServer(string! name) -> boolean
	{
		return isset _SERVER[name];
	}

    /**
     * Checks whether headers has certain index
     */
    public final function hasHeader(string! header) -> boolean
    {
        var name;

        let name = strtoupper(strtr(header, "-", "_"));

        if isset _SERVER[name] {
            return true;
        }

        if isset _SERVER["HTTP_" . name] {
            return true;
        }

        return false;
    }

	/**
	 * Gets HTTP header from request data
	 */
	public final function getHeader(string! header) -> string
	{
		var value, name;

		let name = strtoupper(strtr(header, "-", "_"));

		if fetch value, _SERVER[name] {
			return value;
		}

		if fetch value, _SERVER["HTTP_" . name] {
			return value;
		}

		return "";
	}

	/**
	 * Gets HTTP schema (http/https)
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
	 */
	public function isAjax() -> boolean
	{
		return isset _SERVER["HTTP_X_REQUESTED_WITH"] && _SERVER["HTTP_X_REQUESTED_WITH"] === "XMLHttpRequest";
	}

	/**
	 * Checks whether request has been made using SOAP
	 */
	public function isSoap() -> boolean
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
	 * Alias of isSoap(). It will be deprecated in future versions
	 */
	deprecated public function isSoapRequested() -> boolean
	{
		return this->isSoap();
	}

	/**
	 * Checks whether request has been made using any secure layer
	 */
	public function isSecure() -> boolean
	{
		return this->getScheme() === "https";
	}

	/**
	 * Alias of isSecure(). It will be deprecated in future versions
	 */
	deprecated public function isSecureRequest() -> boolean
	{
		return this->isSecure();
	}

	/**
	 * Gets HTTP raw request body
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
	 */
	public function getJsonRawBody(boolean associative = false) -> <\stdClass> | array | boolean
	{
		var rawBody, data;

		let rawBody = this->getRawBody();
		if empty rawBody {
			return false;
		}

		let data = json_decode(rawBody, associative);

		if json_last_error() !== JSON_ERROR_NONE {
			return false;
		}

		return data;
	}

	/**
	 * Gets active server address IP
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
	 * Gets host name used by the request.
	 *
	 * `Request::getHttpHost` trying to find host name in following order:
	 *
	 * - `$_SERVER["HTTP_HOST"]`
	 * - `$_SERVER["SERVER_NAME"]`
	 * - `$_SERVER["SERVER_ADDR"]`
	 *
	 * Optionally `Request::getHttpHost` validates and clean host name.
	 * The `Request::$_strictHostCheck` can be used to validate host name.
	 *
	 * Note: validation and cleaning have a negative performance impact because
	 * they use regular expressions.
	 *
	 * <code>
	 * use Phalcon\Http\Request;
	 *
	 * $request = new Request;
	 *
	 * $_SERVER["HTTP_HOST"] = "example.com";
	 * $request->getHttpHost(); // example.com
	 *
	 * $_SERVER["HTTP_HOST"] = "example.com:8080";
	 * $request->getHttpHost(); // example.com:8080
	 *
	 * $request->setStrictHostCheck(true);
	 * $_SERVER["HTTP_HOST"] = "ex=am~ple.com";
	 * $request->getHttpHost(); // UnexpectedValueException
	 *
	 * $_SERVER["HTTP_HOST"] = "ExAmPlE.com";
	 * $request->getHttpHost(); // example.com
	 * </code>
	 */
	public function getHttpHost() -> string
	{
		var host, strict;

		let strict = this->_strictHostCheck;

		/**
		 * Get the server name from $_SERVER["HTTP_HOST"]
		 */
		let host = this->getServer("HTTP_HOST");
		if !host {

			/**
			 * Get the server name from $_SERVER["SERVER_NAME"]
			 */
			let host = this->getServer("SERVER_NAME");
			if !host {
				/**
				 * Get the server address from $_SERVER["SERVER_ADDR"]
				 */
				let host = this->getServer("SERVER_ADDR");
			}
		}

		if host && strict {
			/**
			 * Cleanup. Force lowercase as per RFC 952/2181
			 */
			let host = strtolower(trim(host));
			if memstr(host, ":") {
				let host = preg_replace("/:[[:digit:]]+$/", "", host);
			}

			/**
			 * Host may contain only the ASCII letters 'a' through 'z' (in a case-insensitive manner),
			 * the digits '0' through '9', and the hyphen ('-') as per RFC 952/2181
			 */
			if "" !== preg_replace("/[a-z0-9-]+\.?/", "", host) {
				throw new \UnexpectedValueException("Invalid host " . host);
			}
		}

		return (string) host;
	}

	/**
	 * Sets if the `Request::getHttpHost` method must be use strict validation of host name or not
	 */
	public function setStrictHostCheck(bool flag = true) -> <Request>
	{
		let this->_strictHostCheck = flag;

		return this;
	}

	/**
	 * Checks if the `Request::getHttpHost` method will be use strict validation of host name or not
	 */
	public function isStrictHostCheck() -> boolean
	{
		return this->_strictHostCheck;
	}

	/**
	 * Gets information about the port on which the request is made.
	 */
	public function getPort() -> int
	{
		var host, pos;

		/**
		 * Get the server name from $_SERVER["HTTP_HOST"]
		 */
		let host = this->getServer("HTTP_HOST");
		if host {
			if memstr(host, ":") {
				let pos = strrpos(host, ":");

				if false !== pos {
					return (int) substr(host, pos + 1);
				}
			}

			return "https" === $this->getScheme() ? 443 : 80;
		}

		return (int) this->getServer("SERVER_PORT");
	}

	/**
	 * Gets HTTP URI which request has been made
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
	 * Gets most possible client IPv4 Address. This method searches in
	 * $_SERVER["REMOTE_ADDR"] and optionally in $_SERVER["HTTP_X_FORWARDED_FOR"]
	 */
	public function getClientAddress(boolean trustForwardedHeader = false) -> string | boolean
	{
		var address = null;

		/**
		 * Proxies uses this IP
		 */
		if trustForwardedHeader {
			fetch address, _SERVER["HTTP_X_FORWARDED_FOR"];
			if address === null {
				fetch address, _SERVER["HTTP_CLIENT_IP"];
			}
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
	 * If the X-HTTP-Method-Override header is set, and if the method is a POST,
	 * then it is used to determine the "real" intended HTTP method.
	 *
	 * The _method request parameter can also be used to determine the HTTP method,
	 * but only if setHttpMethodParameterOverride(true) has been called.
	 *
	 * The method is always an uppercased string.
	 */
	public final function getMethod() -> string
	{
		var overridedMethod, spoofedMethod, requestMethod;
		string returnMethod = "";

		if likely fetch requestMethod, _SERVER["REQUEST_METHOD"] {
			let returnMethod = strtoupper(requestMethod);
		} else {
			return "GET";
		}

		if "POST" === returnMethod {
			let overridedMethod = this->getHeader("X-HTTP-METHOD-OVERRIDE");
			if !empty overridedMethod {
				let returnMethod = strtoupper(overridedMethod);
			} elseif this->_httpMethodParameterOverride {
				if fetch spoofedMethod, _REQUEST["_method"] {
					let returnMethod = strtoupper(spoofedMethod);
				}
			}
		}

		if !this->isValidHttpMethod(returnMethod) {
			return "GET";
		}

		return returnMethod;
	}

	/**
	 * Gets HTTP user agent used to made the request
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
	 * Checks if a method is a valid HTTP method
	 */
	public function isValidHttpMethod(string method) -> boolean
	{
		switch strtoupper(method) {
			case "GET":
			case "POST":
			case "PUT":
			case "DELETE":
			case "HEAD":
			case "OPTIONS":
			case "PATCH":
			case "PURGE": // Squid and Varnish support
			case "TRACE":
			case "CONNECT":
				return true;
		}

		return false;
	}

	/**
	 * Check if HTTP method match any of the passed methods
	 * When strict is true it checks if validated methods are real HTTP methods
	 */
	public function isMethod(var methods, boolean strict = false) -> boolean
	{
		var httpMethod, method;

		let httpMethod = this->getMethod();

		if typeof methods == "string" {
			if strict && !this->isValidHttpMethod(methods) {
				throw new Exception("Invalid HTTP method: " . methods);
			}
			return methods == httpMethod;
		}

		if typeof methods == "array" {
			for method in methods {
				if this->isMethod(method, strict) {
					return true;
				}
			}

			return false;
		}

		if strict {
			throw new Exception("Invalid HTTP method: non-string");
		}

		return false;
	}

	/**
	 * Checks whether HTTP method is POST. if _SERVER["REQUEST_METHOD"]==="POST"
	 */
	public function isPost() -> boolean
	{
		return this->getMethod() === "POST";
	}

	/**
	 * Checks whether HTTP method is GET. if _SERVER["REQUEST_METHOD"]==="GET"
	 */
	public function isGet() -> boolean
	{
		return this->getMethod() === "GET";
	}

	/**
	 * Checks whether HTTP method is PUT. if _SERVER["REQUEST_METHOD"]==="PUT"
	 */
	public function isPut() -> boolean
	{
		return this->getMethod() === "PUT";
	}

	/**
	 * Checks whether HTTP method is PATCH. if _SERVER["REQUEST_METHOD"]==="PATCH"
	 */
	public function isPatch() -> boolean
	{
		return this->getMethod() === "PATCH";
	}

	/**
	 * Checks whether HTTP method is HEAD. if _SERVER["REQUEST_METHOD"]==="HEAD"
	 */
	public function isHead() -> boolean
	{
		return this->getMethod() === "HEAD";
	}

	/**
	 * Checks whether HTTP method is DELETE. if _SERVER["REQUEST_METHOD"]==="DELETE"
	 */
	public function isDelete() -> boolean
	{
		return this->getMethod() === "DELETE";
	}

	/**
	 * Checks whether HTTP method is OPTIONS. if _SERVER["REQUEST_METHOD"]==="OPTIONS"
	 */
	public function isOptions() -> boolean
	{
		return this->getMethod() === "OPTIONS";
	}

	/**
	 * Checks whether HTTP method is PURGE (Squid and Varnish support). if _SERVER["REQUEST_METHOD"]==="PURGE"
	 */
	public function isPurge() -> boolean
	{
		return this->getMethod() === "PURGE";
	}

	/**
	 * Checks whether HTTP method is TRACE. if _SERVER["REQUEST_METHOD"]==="TRACE"
	 */
	public function isTrace() -> boolean
	{
		return this->getMethod() === "TRACE";
	}

	/**
	 * Checks whether HTTP method is CONNECT. if _SERVER["REQUEST_METHOD"]==="CONNECT"
	 */
	public function isConnect() -> boolean
	{
		return this->getMethod() === "CONNECT";
	}

	/**
	 * Checks whether request include attached files
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

	/**
	 * Recursively counts file in an array of files
	 */
	protected final function hasFileHelper(var data, boolean onlySuccessful) -> long
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
	 */
	public function getUploadedFiles(boolean onlySuccessful = false) -> <\Phalcon\Http\Request\FileInterface[]>
	{
		var superFiles, prefix, input, smoothInput, file, dataFile;
		array files = [];

		let superFiles = _FILES;

		if count(superFiles) > 0 {

			for prefix, input in superFiles {
				if typeof input["name"] == "array" {
					let smoothInput = this->smoothFiles(
						input["name"],
						input["type"],
						input["tmp_name"],
						input["size"],
						input["error"],
						prefix
					);

					for file in smoothInput {
						if onlySuccessful == false || file["error"] == UPLOAD_ERR_OK {
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
					if onlySuccessful == false || input["error"] == UPLOAD_ERR_OK {
						let files[] = new File(input, prefix);
					}
				}
			}
		}

		return files;
	}

	/**
	 * Smooth out $_FILES to have plain array with all files uploaded
	 */
	protected final function smoothFiles(array! names, array! types, array! tmp_names, array! sizes, array! errors, string prefix) -> array
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
				let parentFiles = this->smoothFiles(
					names[idx],
					types[idx],
					tmp_names[idx],
					sizes[idx],
					errors[idx],
					p
				);

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
	 * <code>
	 * $_SERVER = [
	 *     "PHP_AUTH_USER" => "phalcon",
	 *     "PHP_AUTH_PW"   => "secret",
	 * ];
	 *
	 * $headers = $request->getHeaders();
	 *
	 * echo $headers["Authorization"]; // Basic cGhhbGNvbjpzZWNyZXQ=
	 * </code>
	 */
	public function getHeaders() -> array
	{
		var name, value, authHeaders;

		array headers = [];
		array contentHeaders = ["CONTENT_TYPE": true, "CONTENT_LENGTH": true, "CONTENT_MD5": true];

		for name, value in _SERVER {
			// Note: The starts_with uses case insensitive search here
			if starts_with(name, "HTTP_") {
				let name = ucwords(strtolower(str_replace("_", " ", substr(name, 5)))),
					name = str_replace(" ", "-", name);
				let headers[name] = value;

				continue;
			}

			// The "CONTENT_" headers are not prefixed with "HTTP_".
			let name = strtoupper(name);
			if isset contentHeaders[name] {
				let name = ucwords(strtolower(str_replace("_", " ", name))),
					name = str_replace(" ", "-", name);
				let headers[name] = value;
			}
		}

		let authHeaders = this->resolveAuthorizationHeaders();

		// Protect for future (child classes) changes
		if typeof authHeaders === "array" {
			let headers = array_merge(headers, authHeaders);
		}

		return headers;
	}

	/**
	 * Resolve authorization headers.
	 */
	protected function resolveAuthorizationHeaders() -> array
	{
		var resolved, eventsManager, hasEventsManager, dependencyInjector, exploded, digest, authHeader = null;
		array headers = [];

		let dependencyInjector = <DiInterface> this->getDI();

		// TODO: Make Request implements EventsAwareInterface for v4.0.0
		if typeof dependencyInjector === "object" {
			let hasEventsManager = (bool) dependencyInjector->has("eventsManager");
			if hasEventsManager {
				let eventsManager = <ManagerInterface> dependencyInjector->getShared("eventsManager");
			}
		}

		if hasEventsManager && typeof eventsManager === "object" {
			let resolved = eventsManager->fire(
				"request:beforeAuthorizationResolve",
				this,
				["server": _SERVER]
			);

			if typeof resolved === "array" {
				let headers = array_merge(headers, resolved);
			}
		}

		if isset _SERVER["PHP_AUTH_USER"] && isset _SERVER["PHP_AUTH_PW"] {
			let headers["Php-Auth-User"] = _SERVER["PHP_AUTH_USER"],
				headers["Php-Auth-Pw"] = _SERVER["PHP_AUTH_PW"];
		} else {
			if isset _SERVER["HTTP_AUTHORIZATION"] {
				let authHeader = _SERVER["HTTP_AUTHORIZATION"];
			} elseif isset _SERVER["REDIRECT_HTTP_AUTHORIZATION"] {
				let authHeader = _SERVER["REDIRECT_HTTP_AUTHORIZATION"];
			}

			if authHeader {
				if stripos(authHeader, "basic ") === 0 {
					let exploded = explode(":", base64_decode(substr(authHeader, 6)), 2);
					if count(exploded) == 2 {
						let headers["Php-Auth-User"] = exploded[0],
							headers["Php-Auth-Pw"]   = exploded[1];
					}
				} elseif stripos(authHeader, "digest ") === 0 && !fetch digest, _SERVER["PHP_AUTH_DIGEST"] {
					let headers["Php-Auth-Digest"] = authHeader;
				} elseif stripos(authHeader, "bearer ") === 0 {
					let headers["Authorization"] = authHeader;
				}
			}
		}

		if !isset headers["Authorization"] {
			if isset headers["Php-Auth-User"] {
				let headers["Authorization"] = "Basic " . base64_encode(headers["Php-Auth-User"] . ":" . headers["Php-Auth-Pw"]);
			} elseif fetch digest, headers["Php-Auth-Digest"] {
				let headers["Authorization"] = digest;
			}
		}

		if hasEventsManager && typeof eventsManager === "object" {
			let resolved = eventsManager->fire(
				"request:afterAuthorizationResolve",
				this,
				["headers": headers, "server": _SERVER]
			);

			if typeof resolved === "array" {
				let headers = array_merge(headers, resolved);
			}

		}

		return headers;
	}

	/**
	 * Gets web page that refers active request. ie: http://www.google.com
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
	 * Process a request header and return the one with best quality
	 */
	protected final function _getBestQuality(array qualityParts, string! name) -> string
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
	 */
	public function getContentType() -> string | null
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
	 * Gets an array with mime/types and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT"]
	 */
	public function getAcceptableContent() -> array
	{
		return this->_getQualityHeader("HTTP_ACCEPT", "accept");
	}

	/**
	 * Gets best mime/type accepted by the browser/client from _SERVER["HTTP_ACCEPT"]
	 */
	public function getBestAccept() -> string
	{
		return this->_getBestQuality(this->getAcceptableContent(), "accept");
	}

	/**
	 * Gets a charsets array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_CHARSET"]
	 */
	public function getClientCharsets() -> array
	{
		return this->_getQualityHeader("HTTP_ACCEPT_CHARSET", "charset");
	}

	/**
	 * Gets best charset accepted by the browser/client from _SERVER["HTTP_ACCEPT_CHARSET"]
	 */
	public function getBestCharset() -> string
	{
		return this->_getBestQuality(this->getClientCharsets(), "charset");
	}

	/**
	 * Gets languages array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
	 */
	public function getLanguages() -> array
	{
		return this->_getQualityHeader("HTTP_ACCEPT_LANGUAGE", "language");
	}

	/**
	 * Gets best language accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
	 */
	public function getBestLanguage() -> string
	{
		return this->_getBestQuality(this->getLanguages(), "language");
	}

	/**
	 * Gets auth info accepted by the browser/client from $_SERVER["PHP_AUTH_USER"]
	 */
	public function getBasicAuth() -> array | null
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
	 * Gets auth info accepted by the browser/client from $_SERVER["PHP_AUTH_DIGEST"]
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

	/**
	 * Process a request header and return an array of values with their qualities
	 */
	protected final function _getQualityHeader(string! serverIndex, string! name) -> array
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
}
