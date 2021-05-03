
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Http\Response
 *
 * Interface for Phalcon\Http\Response
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_ResponseInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Http, ResponseInterface, phalcon, http_responseinterface, phalcon_http_responseinterface_method_entry);

	return SUCCESS;
}

/**
 * Appends a string to the HTTP response body
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, appendContent);
/**
 * Gets the HTTP response body
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, getContent);
/**
 * Returns the status code
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, getStatusCode);
/**
 * Returns headers set by the user
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, getHeaders);
/**
 * Checks if a header exists
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, hasHeader);
/**
 * Checks if the response was already sent
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, isSent);
/**
 * Redirect by HTTP to another action or URL
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, redirect);
/**
 * Resets all the established headers
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, resetHeaders);
/**
 * Sets HTTP response body
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setContent);
/**
 * Sets the response content-length
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setContentLength);
/**
 * Sets the response content-type mime, optionally the charset
 *
 * @param string charset
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setContentType);
/**
 * Sets output expire time header
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setExpires);
/**
 * Sets an attached file to be sent at the end of the request
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setFileToSend);
/**
 * Overwrites a header in the response
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setHeader);
/**
 * Sets HTTP response body. The parameter is automatically converted to JSON
 *
 *```php
 * $response->setJsonContent(
 *     [
 *         "status" => "OK",
 *     ]
 * );
 *```
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setJsonContent);
/**
 * Sends a Not-Modified response
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setNotModified);
/**
 * Send a raw header to the response
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setRawHeader);
/**
 * Sets the HTTP response code
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, setStatusCode);
/**
 * Prints out HTTP response to the client
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, send);
/**
 * Sends cookies to the client
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, sendCookies);
/**
 * Sends headers to the client
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_ResponseInterface, sendHeaders);
