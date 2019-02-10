
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Handles a server request and produces a response.
 *
 * An HTTP request handler process an HTTP request in order to produce an
 * HTTP response.
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Server_RequestHandler) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Server, RequestHandler, phalcon, http_server_requesthandler, phalcon_http_server_requesthandler_method_entry, 0);

	zend_class_implements(phalcon_http_server_requesthandler_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\server\\requesthandlerinterface")));
	return SUCCESS;

}

/**
 * Handles a request and produces a response.
 *
 * May call other collaborating code to generate the response.
 */
PHP_METHOD(Phalcon_Http_Server_RequestHandler, handle) {

	zval *request, request_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);

	zephir_fetch_params(0, 1, 0, &request);




}

