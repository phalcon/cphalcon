
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

use Phalcon\Http\Request\FileInterface;

/**
 * Phalcon\Http\RequestInterface
 *
 * Interface for Phalcon\Http\Request
 */
interface RequestInterface
{

	/**
	 * Gets a variable from the $_REQUEST superglobal applying filters if needed
	 *
	 * @param string|array filters
	 * @return mixed
	 */
	public function get(string! name = null, var filters = null, var defaultValue = null);

	/**
	 * Gets a variable from the $_POST superglobal applying filters if needed
	 *
	 * @param string|array filters
	 * @return mixed
	 */
	public function getPost(string! name = null, var filters = null, var defaultValue = null);

	/**
	 * Gets variable from $_GET superglobal applying filters if needed
	 *
	 * @param string|array filters
	 * @return mixed
	 */
	public function getQuery(string! name = null, var filters = null, var defaultValue = null);

	/**
	 * Gets variable from $_SERVER superglobal
	 *
	 * @return mixed
	 */
	public function getServer(string! name);

	/**
	 * Checks whether $_REQUEST superglobal has certain index
	 */
	public function has(string! name) -> bool;

	/**
	 * Checks whether $_POST superglobal has certain index
	 */
	public function hasPost(string! name) -> bool;

	/**
	 * Checks whether the PUT data has certain index
	 */
	public function hasPut(string! name) -> bool;

	/**
	 * Checks whether $_GET superglobal has certain index
	 */
	public function hasQuery(string! name) -> bool;

	/**
	 * Checks whether $_SERVER superglobal has certain index
	 */
	public function hasServer(string! name) -> bool;

	/**
	 * Gets HTTP header from request data
	 */
	public function getHeader(string! header) -> string;

	/**
	 * Gets HTTP schema (http/https)
	 */
	public function getScheme() -> string;

	/**
	 * Checks whether request has been made using ajax. Checks if $_SERVER["HTTP_X_REQUESTED_WITH"] === "XMLHttpRequest"
	 */
	public function isAjax() -> bool;

	/**
	 * Checks whether request has been made using SOAP
	 */
	public function isSoap() -> bool;

	/**
	 * Checks whether request has been made using any secure layer
	 */
	public function isSecure() -> bool;

	/**
	 * Gets HTTP raw request body
	 */
	public function getRawBody() -> string;

	/**
	 * Gets active server address IP
	 */
	public function getServerAddress() -> string;

	/**
	 * Gets active server name
	 */
	public function getServerName() -> string;

	/**
	 * Gets host name used by the request
	 */
	public function getHttpHost() -> string;

	/**
	 * Gets information about the port on which the request is made
	 */
	public function getPort() -> int;

	/**
	 * Gets most possibly client IPv4 Address. This methods searches in
	 * $_SERVER["REMOTE_ADDR"] and optionally in $_SERVER["HTTP_X_FORWARDED_FOR"]
	 */
	public function getClientAddress(bool trustForwardedHeader = false) -> string | bool;

	/**
	 * Gets HTTP method which request has been made
	 */
	public function getMethod() -> string;

	/**
	 * Gets HTTP user agent used to made the request
	 */
	public function getUserAgent() -> string;

	/**
	 * Check if HTTP method match any of the passed methods
	 *
	 * @param string|array methods
	 */
	public function isMethod(methods, bool strict = false) -> bool;

	/**
	 * Checks whether HTTP method is POST. if $_SERVER["REQUEST_METHOD"] === "POST"
	 */
	public function isPost() -> bool;

	/**
	 * Checks whether HTTP method is GET. if $_SERVER["REQUEST_METHOD"] === "GET"
	 */
	public function isGet() -> bool;

	/**
	 * Checks whether HTTP method is PUT. if $_SERVER["REQUEST_METHOD"] === "PUT"
	 */
	public function isPut() -> bool;

	/**
	 * Checks whether HTTP method is HEAD. if $_SERVER["REQUEST_METHOD"] === "HEAD"
	 */
	public function isHead() -> bool;

	/**
	 * Checks whether HTTP method is DELETE. if $_SERVER["REQUEST_METHOD"] === "DELETE"
	 */
	public function isDelete() -> bool;

	/**
	 * Checks whether HTTP method is OPTIONS. if $_SERVER["REQUEST_METHOD"] === "OPTIONS"
	 */
	public function isOptions() -> bool;

	/**
	 * Checks whether HTTP method is PURGE (Squid and Varnish support). if $_SERVER["REQUEST_METHOD"] === "PURGE"
	 */
	public function isPurge() -> bool;

	/**
	 * Checks whether HTTP method is TRACE. if $_SERVER["REQUEST_METHOD"] === "TRACE"
	 */
	public function isTrace() -> bool;

	/**
	 * Checks whether HTTP method is CONNECT. if $_SERVER["REQUEST_METHOD"] === "CONNECT"
	 */
	public function isConnect() -> bool;

	/**
	 * Checks whether request include attached files
	 * TODO: We need to check the name. Not very intuitive
	 */
	public function hasFiles(bool onlySuccessful = false) -> long;

	/**
	 * Gets attached files as Phalcon\Http\Request\FileInterface compatible instances
	 */
	public function getUploadedFiles(bool onlySuccessful = false) -> <FileInterface[]>;

	/**
	 * Gets web page that refers active request. ie: http://www.google.com
	 */
	public function getHTTPReferer() -> string;

	/**
	 * Gets array with mime/types and their quality accepted by the browser/client from $_SERVER["HTTP_ACCEPT"]
	 */
	public function getAcceptableContent() -> array;

	/**
	 * Gets best mime/type accepted by the browser/client from $_SERVER["HTTP_ACCEPT"]
	 */
	public function getBestAccept() -> string;

	/**
	 * Gets charsets array and their quality accepted by the browser/client from $_SERVER["HTTP_ACCEPT_CHARSET"]
	 */
	public function getClientCharsets() -> array;

	/**
	 * Gets best charset accepted by the browser/client from $_SERVER["HTTP_ACCEPT_CHARSET"]
	 */
	public function getBestCharset() -> string;

	/**
	 * Gets languages array and their quality accepted by the browser/client from _SERVER["HTTP_ACCEPT_LANGUAGE"]
	 */
	public function getLanguages() -> array;

	/**
	 * Gets best language accepted by the browser/client from $_SERVER["HTTP_ACCEPT_LANGUAGE"]
	 */
	public function getBestLanguage() -> string;

	/**
	 * Gets auth info accepted by the browser/client from $_SERVER["PHP_AUTH_USER"]
	 */
	public function getBasicAuth() -> array | null;

	/**
	 * Gets auth info accepted by the browser/client from $_SERVER["PHP_AUTH_DIGEST"]
	 */
	public function getDigestAuth() -> array;
}
