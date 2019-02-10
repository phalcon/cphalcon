
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
 * Participant in processing a server request and response.
 *
 * An HTTP middleware component participates in processing an HTTP message:
 * by acting on the request, generating the response, or forwarding the
 * request to a subsequent middleware and possibly acting on its response.
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Server_Middleware) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Server, Middleware, phalcon, http_server_middleware, phalcon_http_server_middleware_method_entry, 0);

	zend_class_implements(phalcon_http_server_middleware_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("psr\\http\\server\\middlewareinterface")));
	return SUCCESS;

}

/**
 * Process an incoming server request.
 *
 * Processes an incoming server request in order to produce a response.
 * If unable to produce the response itself, it may delegate to the provided
 * request handler to do so.
 */
PHP_METHOD(Phalcon_Http_Server_Middleware, process) {

	zval *request, request_sub, *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params(0, 2, 0, &request, &handler);




}

