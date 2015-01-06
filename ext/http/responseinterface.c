
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

#include "http/responseinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_http_responseinterface_ce;

static const zend_function_entry phalcon_http_responseinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setStatusCode, arginfo_phalcon_http_responseinterface_setstatuscode)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, getHeaders, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setHeader, arginfo_phalcon_http_responseinterface_setheader)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setRawHeader, arginfo_phalcon_http_responseinterface_setrawheader)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, resetHeaders, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setExpires, arginfo_phalcon_http_responseinterface_setexpires)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setNotModified, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setContentType, arginfo_phalcon_http_responseinterface_setcontenttype)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, redirect, arginfo_phalcon_http_responseinterface_redirect)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setContent, arginfo_phalcon_http_responseinterface_setcontent)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setJsonContent, arginfo_phalcon_http_responseinterface_setjsoncontent)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, appendContent, arginfo_phalcon_http_responseinterface_appendcontent)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, getContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, sendHeaders, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, sendCookies, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, send, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setFileToSend, arginfo_phalcon_http_responseinterface_setfiletosend)
	PHP_FE_END
};

/**
 * Phalcon\Http\ResponseInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_ResponseInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Http, ResponseInterface, http_responseinterface, phalcon_http_responseinterface_method_entry);

	return SUCCESS;
}

/**
 * Sets the HTTP response code
 *
 * @param int $code
 * @param string $message
 * @return Phalcon\Http\ResponseInterface
 */
PHALCON_DOC_METHOD(Phalcon_Http_ResponseInterface, setStatusCode);

/**
 * Returns headers set by the user
 *
 * @return Phalcon\Http\Response\Headers
 */
PHALCON_DOC_METHOD(Phalcon_Http_ResponseInterface, getHeaders);

/**
 * Overwrites a header in the response
 *
 * @param string $name
 * @param string $value
 * @return Phalcon\Http\ResponseInterface
 */
PHALCON_DOC_METHOD(Phalcon_Http_ResponseInterface, setHeader);

/**
 * Send a raw header to the response
 *
 * @param string $header
 * @return Phalcon\Http\ResponseInterface
 */
PHALCON_DOC_METHOD(Phalcon_Http_ResponseInterface, setRawHeader);

/**
 * Resets all the stablished headers
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHALCON_DOC_METHOD(Phalcon_Http_ResponseInterface, resetHeaders);

/**
 * Sets output expire time header
 *
 * @param DateTime $datetime
 * @return Phalcon\Http\ResponseInterface
 */
PHALCON_DOC_METHOD(Phalcon_Http_ResponseInterface, setExpires);

/**
 * Sends a Not-Modified response
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHALCON_DOC_METHOD(Phalcon_Http_ResponseInterface, setNotModified);

/**
 * Sets the response content-type mime, optionally the charset
 *
 * @param string $contentType
 * @param string $charset
 * @return Phalcon\Http\ResponseInterface
 */
PHALCON_DOC_METHOD(Phalcon_Http_ResponseInterface, setContentType);

/**
 * Redirect by HTTP to another action or URL
 *
 * @param string $location
 * @param boolean $externalRedirect
 * @param int $statusCode
 * @return Phalcon\Http\ResponseInterface
 */
PHALCON_DOC_METHOD(Phalcon_Http_ResponseInterface, redirect);

/**
 * Sets HTTP response body
 *
 * @param string $content
 * @return Phalcon\Http\ResponseInterface
 */
PHALCON_DOC_METHOD(Phalcon_Http_ResponseInterface, setContent);

/**
 * Sets HTTP response body. The parameter is automatically converted to JSON
 *
 *<code>
 *	$response->setJsonContent(array("status" => "OK"));
 *</code>
 *
 * @param string $content
 * @return Phalcon\Http\ResponseInterface
 */
PHALCON_DOC_METHOD(Phalcon_Http_ResponseInterface, setJsonContent);

/**
 * Appends a string to the HTTP response body
 *
 * @param string $content
 * @return Phalcon\Http\ResponseInterface
 */
PHALCON_DOC_METHOD(Phalcon_Http_ResponseInterface, appendContent);

/**
 * Gets the HTTP response body
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Http_ResponseInterface, getContent);

/**
 * Sends headers to the client
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHALCON_DOC_METHOD(Phalcon_Http_ResponseInterface, sendHeaders);

/**
 * Sends cookies to the client
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHALCON_DOC_METHOD(Phalcon_Http_ResponseInterface, sendCookies);

/**
 * Prints out HTTP response to the client
 *
 * @return Phalcon\Http\ResponseInterface
 */
PHALCON_DOC_METHOD(Phalcon_Http_ResponseInterface, send);

/**
 * Sets an attached file to be sent at the end of the request
 *
 * @param string $filePath
 * @param string $attachmentName
 */
PHALCON_DOC_METHOD(Phalcon_Http_ResponseInterface, setFileToSend);
