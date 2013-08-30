
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
 * Interface for Phalcon\Http\Response
 */
interface ResponseInterface
{

	/**
	 * Sets the HTTP response code
	 *
	 * @param int code
	 * @param string message
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setStatusCode(code, message);

	/**
	 * Returns headers set by the user
	 *
	 * @return Phalcon\Http\Response\Headers
	 */
	public function getHeaders();

	/**
	 * Overwrites a header in the response
	 *
	 * @param string name
	 * @param string value
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setHeader(name, value);

	/**
	 * Send a raw header to the response
     *
	 * @param string header
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setRawHeader(header);

	/**
	 * Resets all the stablished headers
	 *
     * @return Phalcon\Http\ResponseInterface
	 */
	public function resetHeaders();

	/**
	 * Sets output expire time header
	 *
	 * @param DateTime datetime
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setExpires(datetime);
	/**
	 * Sends a Not-Modified response
	 *
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setNotModified();

	/**
	 * Sets the response content-type mime, optionally the charset
	 *
	 * @param string contentType
	 * @param string charset
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setContentType(contentType, charset=null);

	/**
	 * Redirect by HTTP to another action or URL
	 *
	 * @param string location
	 * @param boolean externalRedirect
	 * @param int statusCode
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function redirect(location=null, externalRedirect=false, statusCode=302);

	/**
	 * Sets HTTP response body
	 *
	 * @param string content
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setContent(content);

	/**
	 * Sets HTTP response body. The parameter is automatically converted to JSON
     *
	 *<code>
	 *	response->setJsonContent(array("status" => "OK"));
	 *</code>
	 *
	 * @param string content
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function setJsonContent(content);

	/**
	 * Appends a string to the HTTP response body
	 *
	 * @param string content
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function appendContent(content);

	/**
	 * Gets the HTTP response body
	 *
	 * @return string
	 */
	public function getContent();

	/**
	 * Sends headers to the client
	 *
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function sendHeaders();

	/**
	 * Sends cookies to the client
	 *
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function sendCookies();

	/**
	 * Prints out HTTP response to the client
	 *
	 * @return Phalcon\Http\ResponseInterface
	 */
	public function send();

	/**
	 * Sets an attached file to be sent at the end of the request
	 *
	 * @param string filePath
	 * @param string attachmentName
	 */
	public function setFileToSend(filePath, attachmentName=null);

}
