
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
#include "kernel/time.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
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
 * Adds an `X-Response-Time` header measuring how long the rest of the pipeline
 * took to produce the response.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Middleware_TimingMiddleware)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Middleware, TimingMiddleware, phalcon, adr_middleware_timingmiddleware, phalcon_adr_middleware_timingmiddleware_method_entry, 0);

	zend_class_implements(phalcon_adr_middleware_timingmiddleware_ce, 1, phalcon_contracts_adr_middleware_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Middleware_TimingMiddleware, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, *next, next_sub, __$true, start, response, elapsed, _0, _1, _2;

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&next_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&elapsed);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_contracts_http_attributerequest_ce)
		Z_PARAM_OBJECT_OF_CLASS(next, phalcon_contracts_adr_handler_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &request, &next);
	ZEPHIR_INIT_VAR(&start);
	zephir_microtime(&start, &__$true);
	ZEPHIR_CALL_METHOD(&response, next, "__invoke", NULL, 0, request);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_microtime(&_0, &__$true);
	ZEPHIR_INIT_VAR(&_1);
	zephir_sub_function(&_1, &_0, &start);
	ZEPHIR_INIT_VAR(&elapsed);
	ZVAL_DOUBLE(&elapsed, (zephir_get_numberval(&_1) * 1000.0));
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "%.2fms");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 146, &_0, &elapsed);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "X-Response-Time");
	ZEPHIR_CALL_METHOD(NULL, &response, "setheader", NULL, 0, &_0, &_2);
	zephir_check_call_status();
	RETURN_CCTOR(&response);
}

