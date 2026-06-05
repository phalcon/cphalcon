
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

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
 * Interface for Phalcon\Http\Response\Headers compatible bags
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Response_HeadersInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Http\\Response, HeadersInterface, phalcon, http_response_headersinterface, phalcon_http_response_headersinterface_method_entry);

	return SUCCESS;
}

/**
 * Gets a header value from the internal bag
 *
 * @param string $name
 *
 * @return string|bool|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_HeadersInterface, get);
/**
 * Checks if a header exists
 *
 * @param string $name
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_HeadersInterface, has);
/**
 * Reset set headers
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_HeadersInterface, reset);
/**
 * Sends the headers to the client
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_HeadersInterface, send);
/**
 * Sets a header to be sent at the end of the request
 *
 * @param string $name
 * @param string $value
 *
 * @return HeadersInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_HeadersInterface, set);
/**
 * Sets a raw header to be sent at the end of the request
 *
 * @param string $header
 *
 * @return HeadersInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Http_Response_HeadersInterface, setRaw);
