
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
/**
 * Phalcon\Http\Response
 *
 * Interface for Phalcon\Http\Response
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_ResponseInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Http, ResponseInterface, phalcon, http_responseinterface, phalcon_http_responseinterface_method_entry);


	return SUCCESS;

}

/**
 * Sets the HTTP response code
 *
 * @param int code
 * @param string message
 * @return Phalcon\Http\ResponseInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setStatusCode);

/**
 * Returns headers set by the user
 *
 * @return Phalcon\Http\Response\Headers
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, getHeaders);

/**
 * Overwrites a header in the response
 *
 * @param string name
 * @param string value
 * @return Phalcon\Http\ResponseInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setHeader);

/**
 * Send a raw header to the response
 *
 * @param string header
 * @return Phalcon\Http\ResponseInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setRawHeader);

/**
 * Resets all the stablished headers
 *
 * @return Phalcon\Http\ResponseInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, resetHeaders);

/**
 * Sets output expire time header
 *
 * @param DateTime datetime
 * @return Phalcon\Http\ResponseInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setExpires);

/**
 * Sends a Not-Modified response
 *
 * @return Phalcon\Http\ResponseInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setNotModified);

/**
 * Sets the response content-type mime, optionally the charset
 *
 * @param string contentType
 * @param string charset
 * @return Phalcon\Http\ResponseInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setContentType);

/**
 * Redirect by HTTP to another action or URL
 *
 * @param string location
 * @param boolean externalRedirect
 * @param int statusCode
 * @return Phalcon\Http\ResponseInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, redirect);

/**
 * Sets HTTP response body
 *
 * @param string content
 * @return Phalcon\Http\ResponseInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setContent);

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
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setJsonContent);

/**
 * Appends a string to the HTTP response body
 *
 * @param string content
 * @return Phalcon\Http\ResponseInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, appendContent);

/**
 * Gets the HTTP response body
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, getContent);

/**
 * Sends headers to the client
 *
 * @return Phalcon\Http\ResponseInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, sendHeaders);

/**
 * Sends cookies to the client
 *
 * @return Phalcon\Http\ResponseInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, sendCookies);

/**
 * Prints out HTTP response to the client
 *
 * @return Phalcon\Http\ResponseInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, send);

/**
 * Sets an attached file to be sent at the end of the request
 *
 * @param string filePath
 * @param string attachmentName
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setFileToSend);

