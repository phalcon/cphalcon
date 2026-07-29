
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
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
 * Emits a response through the SAPI (headers + body via `Response::send()`).
 * Refuses to emit once headers have already been sent.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Emitter_SapiEmitter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Emitter, SapiEmitter, phalcon, adr_emitter_sapiemitter, phalcon_adr_emitter_sapiemitter_method_entry, 0);

	zend_class_implements(phalcon_adr_emitter_sapiemitter_ce, 1, phalcon_contracts_adr_emitter_emitter_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Emitter_SapiEmitter, emit)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *response, response_sub, _0, _1$$3;

	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(response, phalcon_http_responseinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &response);
	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 217);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_adr_exceptions_headersalreadysent_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 312);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/ADR/Emitter/SapiEmitter.zep", 29);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, response, "send", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

