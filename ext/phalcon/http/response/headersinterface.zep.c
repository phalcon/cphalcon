
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_HeadersInterface, send);

/**
 * Reset set headers
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_HeadersInterface, reset);

/**
 * Restore a Phalcon\Http\Response\Headers object
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_HeadersInterface, __set_state);

