
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */
/**
 * Ensures every request carries an `X-Request-Id`, reusing an incoming one or
 * generating it, exposing it on the request attributes and the response.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Middleware_RequestIdMiddleware)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Middleware, RequestIdMiddleware, phalcon, adr_middleware_requestidmiddleware, phalcon_adr_middleware_requestidmiddleware_method_entry, 0);

	zend_class_implements(phalcon_adr_middleware_requestidmiddleware_ce, 1, phalcon_contracts_adr_middleware_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Middleware_RequestIdMiddleware, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, *next, next_sub, id, response, _0, _3, _1$$3, _2$$3;

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&next_sub);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_contracts_http_attributerequest_ce)
		Z_PARAM_OBJECT_OF_CLASS(next, phalcon_contracts_adr_handler_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &request, &next);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "X-Request-Id");
	ZEPHIR_CALL_METHOD(&id, request, "getheader", NULL, 0, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&id)) {
		ZVAL_LONG(&_1$$3, 16);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "random_bytes", NULL, 315, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&id, "bin2hex", NULL, 316, &_2$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_3, request, "getattributes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "requestId");
	ZEPHIR_CALL_METHOD(NULL, &_3, "set", NULL, 0, &_0, &id);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, next, "__invoke", NULL, 0, request);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "X-Request-Id");
	ZEPHIR_CALL_METHOD(NULL, &response, "setheader", NULL, 0, &_0, &id);
	zephir_check_call_status();
	RETURN_CCTOR(&response);
}

