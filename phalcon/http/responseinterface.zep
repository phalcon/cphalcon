
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
 |          Zamrony P. Juhara <zamronypj@yahoo.com>                       |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Http;

use Phalcon\Http\Response\HeadersInterface;

/**
 * Phalcon\Http\Response
 *
 * Interface for Phalcon\Http\Response
 */
interface ResponseInterface
{

	/**
	 * Sets the HTTP response code
	 */
	public function setStatusCode(int code, string message = null) -> <ResponseInterface>;

	/**
	 * Returns headers set by the user
	 */
	public function getHeaders() -> <HeadersInterface>;

	/**
	 * Overwrites a header in the response
	 */
	public function setHeader(string name, value) -> <ResponseInterface>;

	/**
	 * Send a raw header to the response
	 */
	public function setRawHeader(string header) -> <ResponseInterface>;

	/**
	 * Resets all the established headers
	 */
	public function resetHeaders() -> <ResponseInterface>;

	/**
	 * Sets output expire time header
	 */
	public function setExpires(<\DateTime> datetime) -> <ResponseInterface>;

	/**
	 * Sends a Not-Modified response
	 */
	public function setNotModified() -> <ResponseInterface>;

	/**
	 * Sets the response content-type mime, optionally the charset
	 *
	 * @param string contentType
	 * @param string charset
	 * @return \Phalcon\Http\ResponseInterface
	 */
	public function setContentType(string contentType, charset = null) -> <ResponseInterface>;

	/**
	 * Sets the response content-length
	 */
	public function setContentLength(int contentLength) -> <ResponseInterface>;

	/**
	 * Redirect by HTTP to another action or URL
	 */
	public function redirect(location = null, boolean externalRedirect = false, int statusCode = 302) -> <ResponseInterface>;

	/**
	 * Sets HTTP response body
	 */
	public function setContent(string content) -> <ResponseInterface>;

	/**
	 * Sets HTTP response body. The parameter is automatically converted to JSON
	 *
	 *<code>
	 * $response->setJsonContent(
	 *     [
	 *         "status" => "OK",
	 *     ]
	 * );
	 *</code>
	 */
	public function setJsonContent(content) -> <ResponseInterface>;

	/**
	 * Appends a string to the HTTP response body
	 */
	public function appendContent(content) -> <ResponseInterface>;

	/**
	 * Gets the HTTP response body
	 */
	public function getContent() -> string;

	/**
	 * Sends headers to the client
	 */
	public function sendHeaders() -> <ResponseInterface>;

	/**
	 * Sends cookies to the client
	 */
	public function sendCookies() -> <ResponseInterface>;

	/**
	 * Prints out HTTP response to the client
	 */
	public function send() -> <ResponseInterface>;

	/**
	 * Sets an attached file to be sent at the end of the request
	 */
	public function setFileToSend(string filePath, attachmentName = null) -> <ResponseInterface>;

}
