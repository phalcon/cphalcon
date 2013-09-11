
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

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
 * Phalcon\Http\Response\HeadersInterface
 *
 * Interface for Phalcon\Http\Response\Headers compatible bags
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Response_HeadersInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Http\\Response, HeadersInterface, phalcon, http_response_headersinterface, phalcon_http_response_headersinterface_method_entry);


	return SUCCESS;

}

/**
 * Sets a header to be sent at the end of the request
 *
 * @param string name
 * @param string value
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_HeadersInterface, set);

/**
 * Gets a header value from the internal bag
 *
 * @param string name
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_HeadersInterface, get);

/**
 * Sets a raw header to be sent at the end of the request
 *
 * @param string header
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_HeadersInterface, setRaw);

/**
 * Sends the headers to the client
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_HeadersInterface, send);

/**
 * Reset set headers
 *
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_HeadersInterface, reset);

/**
 * Restore a Phalcon\Http\Response\Headers object
 *
 * @param array data
 * @return Phalcon\Http\Response\HeadersInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_HeadersInterface, __set_state);

