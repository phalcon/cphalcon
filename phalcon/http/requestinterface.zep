
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
	public function get(name=null, filters=null, defaultValue=null);

	/**
	 * Gets a variable from the $_POST superglobal applying filters if needed
	 *
	 * @param string name
	 * @param string|array filters
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function getPost(name=null, filters=null, defaultValue=null);

	/**
	 * Gets variable from $_GET superglobal applying filters if needed
	 *
	 * @param string name
	 * @param string|array filters
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function getQuery(name=null, filters=null, defaultValue=null);

	/**
	 * Gets variable from $_SERVER superglobal
	 *
	 * @param string name
	 * @return mixed
	 */
	public function getServer(name);

	/**
	 * Checks whether $_SERVER superglobal has certain index
	 *
	 * @param string name
	 * @return boolean
	 */
	public function has(name);

	/**
	 * Checks whether $_POST superglobal has certain index
	 *
	 * @param string name
	 * @return boolean
	 */
	public function hasPost(name);

	/**
	 * Checks whether $_GET superglobal has certain index
	 *
	 * @param string name
	 * @return boolean
	 */
	public function hasQuery(name);

	/**
	 * Checks whether $_SERVER superglobal has certain index
	 *
	 * @param string name
	 * @return mixed
	 */
	public function hasServer(name);

	/**
	 * Gets HTTP header from request data
	 *
	 * @param string header
	 * @return string
	 */
	public function getHeader(header);

	/**
	 * Gets HTTP schema (http/https)
	 *
	 * @return string
	 */
	public function getScheme();

	/**
	 * Checks whether request has been made using ajax. Checks if $_SERVER['HTTP_X_REQUESTED_WITH'] == 'XMLHttpRequest'
	 *
	 * @return boolean
	 */
	public function isAjax();

	/**
	 * Checks whether request has been made using SOAP
	 *
	 * @return boolean
	 */
	public function isSoapRequested();

	/**
	 * Checks whether request has been made using any secure layer
	 *
	 * @return boolean
	 */
	public function isSecureRequest();

	/**
	 * Gets HTTP raws request body
	 *
	 * @return string
	 */
	public function getRawBody();

	/**
	 * Gets active server address IP
	 *
	 * @return string
	 */
	public function getServerAddress();

	/**
	 * Gets active server name
	 *
	 * @return string
	 */
	public function getServerName();

	/**
	 * Gets information about schema, host and port used by the request
	 *
	 * @return string
	 */
	public function getHttpHost();

	/**
	 * Gets most possibly client IPv4 Address. This methods search in $_SERVER['REMOTE_ADDR'] and optionally in $_SERVER['HTTP_X_FORWARDED_FOR']
	 *
	 * @param boolean trustForwardedHeader
	 * @return string
	 */
	public function getClientAddress(trustForwardedHeader=false);

	/**
	 * Gets HTTP method which request has been made
	 *
	 * @return string
	 */
	public function getMethod();

	/**
	 * Gets HTTP user agent used to made the request
	 *
	 * @return string
	 */
	public function getUserAgent();

	/**
	 * Check if HTTP method match any of the passed methods
	 *
	 * @param string|array methods
	 * @return boolean
	 */
	public function isMethod(methods);

	/**
	 * Checks whether HTTP method is POST. if $_SERVER['REQUEST_METHOD']=='POST'
	 *
	 * @return boolean
	 */
	public function isPost();

	/**
	 *
	 * Checks whether HTTP method is GET. if $_SERVER['REQUEST_METHOD']=='GET'
	 *
	 * @return boolean
	 */
	public function isGet();

	/**
	 * Checks whether HTTP method is PUT. if $_SERVER['REQUEST_METHOD']=='PUT'
	 *
	 * @return boolean
	 */
	public function isPut();

	/**
	 * Checks whether HTTP method is HEAD. if $_SERVER['REQUEST_METHOD']=='HEAD'
	 *
	 * @return boolean
	 */
	public function isHead();

	/**
	 * Checks whether HTTP method is DELETE. if $_SERVER['REQUEST_METHOD']=='DELETE'
	 *
	 * @return boolean
	 */
	public function isDelete();

	/**
	 * Checks whether HTTP method is OPTIONS. if $_SERVER['REQUEST_METHOD']=='OPTIONS'
	 *
	 * @return boolean
	 */
	public function isOptions();

	/**
	 * Checks whether request include attached files
	 *
	 * @param boolean notErrored
	 * @return boolean
	 */
	public function hasFiles(notErrored=false);

	/**
	 * Gets attached files as Phalcon\Http\Request\FileInterface compatible instances
	 *
	 * @param boolean notErrored
	 * @return Phalcon\Http\Request\FileInterface[]
	 */
	public function getUploadedFiles(notErrored=false);

	/**
	 * Gets web page that refers active request. ie: http://www.google.com
	 *
	 * @return string
	 */
	public function getHTTPReferer();

	/**
	 * Gets array with mime/types and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT']
	 *
	 * @return array
	 */
	public function getAcceptableContent();

	/**
	 * Gets best mime/type accepted by the browser/client from $_SERVER['HTTP_ACCEPT']
	 *
	 * @return array
	 */
	public function getBestAccept();

	/**
	 * Gets charsets array and their quality accepted by the browser/client from $_SERVER['HTTP_ACCEPT_CHARSET']
	 *
	 * @return array
	 */
	public function getClientCharsets();

	/**
	 * Gets best charset accepted by the browser/client from $_SERVER['HTTP_ACCEPT_CHARSET']
	 *
	 * @return string
	 */
	public function getBestCharset();

	/**
	 * Gets languages array and their quality accepted by the browser/client from _SERVER['HTTP_ACCEPT_LANGUAGE']
	 *
	 * @return array
	 */
	public function getLanguages();

	/**
	 * Gets best language accepted by the browser/client from $_SERVER['HTTP_ACCEPT_LANGUAGE']
	 *
	 * @return string
	 */
	public function getBestLanguage();

}
