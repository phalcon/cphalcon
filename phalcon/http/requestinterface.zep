
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
	 * @param string name
	 * @param string|array filters
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function get(string! name = null, filters = null, defaultValue = null);

	/**
	 * Gets a variable from the $_POST superglobal applying filters if needed
	 *
	 * @param string name
	 * @param string|array filters
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function getPost(string! name = null, filters = null, defaultValue = null);

	/**
	 * Gets variable from $_GET superglobal applying filters if needed
	 *
	 * @param string name
	 * @param string|array filters
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function getQuery(string! name = null, filters = null, defaultValue = null);

	/**
	 * Gets variable from $_SERVER superglobal
	 *
	 * @param string name
	 * @return mixed
	 */
	public function getServer(string! name);

	/**
	 * Checks whether $_SERVER superglobal has certain index
	 */
	public function has(string! name) -> boolean;

	/**
	 * Checks whether $_POST superglobal has certain index
	 */
	public function hasPost(string! name) -> boolean;

	/**
	 * Checks whether the PUT data has certain index
	 */
	public function hasPut(string! name) -> boolean;

	/**
	 * Checks whether $_GET superglobal has certain index
	 */
	public function hasQuery(string! name) -> boolean;

	/**
	 * Checks whether $_SERVER superglobal has certain index
	 */
	public function hasServer(string! name) -> boolean;

	/**
	 * Gets HTTP header from request data
	 */
	public function getHeader(string! header) -> string;

	/**
	 * Gets HTTP schema (http/https)
	 */
	public function getScheme() -> string;

	/**
	 * Checks whether request has been made using ajax. Checks if $_SERVER['HTTP_X_REQUESTED_WITH'] == 'XMLHttpRequest'
	 */
	public function isAjax() -> boolean;

	/**
	 * Checks whether request has been made using SOAP
	 */
	public function isSoapRequested() -> boolean;

	/**
	 * Checks whether request has been made using any secure layer
	 */
	public function isSecureRequest() -> boolean;

	/**
	 * Gets HTTP raws request body
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
	 * Gets information about schema, host and port used by the request
	 */
	public function getHttpHost() -> string;

	/**
	 * Gets most possibly client IPv4 Address. This methods search in $_SERVER['REMOTE_ADDR'] and optionally in $_SERVER['HTTP_X_FORWARDED_FOR']
	 */
	public function getClientAddress(boolean trustForwardedHeader = false) -> string;

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
	 * @return boolean
	 */
	public function isMethod(methods) -> boolean;

	/**
	 * Checks whether HTTP method is POST. if $_SERVER['REQUEST_METHOD']=='POST'
	 */
	public function isPost() -> boolean;

	/**
	 * Checks whether HTTP method is GET. if $_SERVER['REQUEST_METHOD']=='GET'
	 */
	public function isGet() -> boolean;

	/**
	 * Checks whether HTTP method is PUT. if $_SERVER['REQUEST_METHOD']=='PUT'
	 */
	public function isPut() -> boolean;

	/**
	 * Checks whether HTTP method is HEAD. if $_SERVER['REQUEST_METHOD']=='HEAD'
	 */
	public function isHead() -> boolean;

	/**
	 * Checks whether HTTP method is DELETE. if $_SERVER['REQUEST_METHOD']=='DELETE'
	 */
	public function isDelete() -> boolean;

	/**
	 * Checks whether HTTP method is OPTIONS. if $_SERVER['REQUEST_METHOD']=='OPTIONS'
	 */
	public function isOptions() -> boolean;

	/**
	 * Checks whether request include attached files
	 *
	 * @param boolean onlySuccessful
	 * @return boolean
	 */
	public function hasFiles(onlySuccessful = false);

	/**
	 * Gets attached files as Phalcon\Http\Request\FileInterface compatible instances
	 */
	public function getUploadedFiles(boolean onlySuccessful = false) -> <\Phalcon\Http\Request\FileInterface[]>;

	/**
	 * Gets web page that refers active request. ie: http://www.google.com
	 */
	public function getHTTPReferer() -> string;

	/**
	 * Gets array with mime/types and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT']
	 */
	public function getAcceptableContent() -> array;

	/**
	 * Gets best mime/type accepted by the browser/client from $_SERVER['HTTP_ACCEPT']
	 */
	public function getBestAccept() -> string;

	/**
	 * Gets charsets array and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT_CHARSET']
	 */
	public function getClientCharsets() -> array;

	/**
	 * Gets best charset accepted by the browser/client from $_SERVER['HTTP_ACCEPT_CHARSET']
	 */
	public function getBestCharset() -> string;

	/**
	 * Gets languages array and their quality accepted by the browser/client from _SERVER['HTTP_ACCEPT_LANGUAGE']
	 */
	public function getLanguages() -> array;

	/**
	 * Gets best language accepted by the browser/client from $_SERVER['HTTP_ACCEPT_LANGUAGE']
	 */
	public function getBestLanguage() -> string;

	/**
	 * Gets auth info accepted by the browser/client from $_SERVER['PHP_AUTH_USER']
	 *
	 * @return array
	 */
	public function getBasicAuth();

	/**
	 * Gets auth info accepted by the browser/client from $_SERVER['PHP_AUTH_DIGEST']
	 */
	public function getDigestAuth() -> array;
}
