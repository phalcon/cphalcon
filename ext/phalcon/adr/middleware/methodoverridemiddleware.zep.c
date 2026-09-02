
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
#include "kernel/string.h"
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
 * Thin enabler for the native `_method` override.
 *
 * `Request::getMethod()` already honors `X-HTTP-Method-Override` and, when the
 * parameter-override flag is on, the `_method` field. This middleware only
 * turns that flag on, and only for a `POST` request whose `_method` names a
 * safe verb (`PUT`/`PATCH`/`DELETE`), so `_method` cannot spoof an arbitrary
 * method.
 *
 * @phpstan-import-type adr_allowed_methods from ADRTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Middleware_MethodOverrideMiddleware)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Middleware, MethodOverrideMiddleware, phalcon, adr_middleware_methodoverridemiddleware, phalcon_adr_middleware_methodoverridemiddleware_method_entry, 0);

	/**
	 * @phpstan-var adr_allowed_methods
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 4);
		add_next_index_stringl(&_zc0, SL("DELETE"));
		add_next_index_stringl(&_zc0, SL("PATCH"));
		add_next_index_stringl(&_zc0, SL("PUT"));
		zephir_declare_typed_property(phalcon_adr_middleware_methodoverridemiddleware_ce, SL("allowed"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	zend_class_implements(phalcon_adr_middleware_methodoverridemiddleware_ce, 1, phalcon_contracts_adr_middleware_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Middleware_MethodOverrideMiddleware, __invoke)
{
	zval _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, *next, next_sub, __$true, spoofed, _0, _1, _2$$3, _3$$3, _5$$3, _6$$3, _7$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&next_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&spoofed);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_4$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("allowed", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("phalcon\\contracts\\http\\attributerequest")))
		Z_PARAM_OBJECT_OF_CLASS(next, zephir_get_internal_ce(SL("phalcon\\contracts\\adr\\handler")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &request, &next);
	ZEPHIR_CALL_METHOD(&_0, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "POST");
	if (ZEPHIR_IS_IDENTICAL(&_1, &_0)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "_method");
		ZEPHIR_CALL_METHOD(&_2$$3, request, "getpost", NULL, 0, &_3$$3);
		zephir_check_call_status();
		zephir_cast_to_string(&_4$$3, &_2$$3);
		ZEPHIR_INIT_VAR(&spoofed);
		zephir_fast_strtoupper(&spoofed, &_4$$3);
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_0, 358, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_6$$3, "in_array", NULL, 89, &spoofed, &_5$$3, &__$true);
		zephir_check_call_status();
		if (zephir_is_true(&_6$$3)) {
			ZVAL_BOOL(&_7$$4, 1);
			ZEPHIR_CALL_METHOD(NULL, request, "sethttpmethodparameteroverride", NULL, 0, &_7$$4);
			zephir_check_call_status();
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(next, "__invoke", NULL, 0, request);
	zephir_check_call_status();
	RETURN_MM();
}

