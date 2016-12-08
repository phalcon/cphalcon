
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setStatusCode);

/**
 * Returns headers set by the user
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, getHeaders);

/**
 * Overwrites a header in the response
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setHeader);

/**
 * Send a raw header to the response
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setRawHeader);

/**
 * Resets all the established headers
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, resetHeaders);

/**
 * Sets output expire time header
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setExpires);

/**
 * Sends a Not-Modified response
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setNotModified);

/**
 * Sets the response content-type mime, optionally the charset
 *
 * @param string contentType
 * @param string charset
 * @return \Phalcon\Http\ResponseInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setContentType);

/**
 * Sets the response content-length
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setContentLength);

/**
 * Redirect by HTTP to another action or URL
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, redirect);

/**
 * Sets HTTP response body
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setContent);

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
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setJsonContent);

/**
 * Appends a string to the HTTP response body
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, appendContent);

/**
 * Gets the HTTP response body
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, getContent);

/**
 * Sends headers to the client
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, sendHeaders);

/**
 * Sends cookies to the client
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, sendCookies);

/**
 * Prints out HTTP response to the client
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, send);

/**
 * Sets an attached file to be sent at the end of the request
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setFileToSend);

