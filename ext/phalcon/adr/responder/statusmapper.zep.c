
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
#include "kernel/array.h"
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
 * Maps a domain `Status` to an HTTP status code.
 *
 * `Status` is the single source of truth: the default map covers every
 * `Status` constant. Any status that is not mapped resolves to 500, never a
 * silent 200. Every entry can be overridden through the constructor.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Responder_StatusMapper)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Responder, StatusMapper, phalcon, adr_responder_statusmapper, phalcon_adr_responder_statusmapper_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_adr_responder_statusmapper_ce, SL("map"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Responder_StatusMapper, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *overrides_param = NULL, _1;
	zval overrides, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&overrides);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("map", 3, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(overrides, overrides_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &overrides_param);
	if (!overrides_param) {
		ZEPHIR_INIT_VAR(&overrides);
		array_init(&overrides);
	} else {
		zephir_get_arrval(&overrides, overrides_param);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 21, 0);
	add_assoc_long_ex(&_0, SL("ACCEPTED"), 202);
	add_assoc_long_ex(&_0, SL("AUTHENTICATED"), 200);
	add_assoc_long_ex(&_0, SL("AUTHORIZED"), 200);
	add_assoc_long_ex(&_0, SL("CREATED"), 201);
	add_assoc_long_ex(&_0, SL("DELETED"), 200);
	add_assoc_long_ex(&_0, SL("ERROR"), 500);
	add_assoc_long_ex(&_0, SL("FAILURE"), 400);
	add_assoc_long_ex(&_0, SL("FOUND"), 200);
	add_assoc_long_ex(&_0, SL("METHOD_NOT_ALLOWED"), 405);
	add_assoc_long_ex(&_0, SL("NOT_ACCEPTED"), 406);
	add_assoc_long_ex(&_0, SL("NOT_AUTHENTICATED"), 401);
	add_assoc_long_ex(&_0, SL("NOT_AUTHORIZED"), 403);
	add_assoc_long_ex(&_0, SL("NOT_CREATED"), 422);
	add_assoc_long_ex(&_0, SL("NOT_DELETED"), 422);
	add_assoc_long_ex(&_0, SL("NOT_FOUND"), 404);
	add_assoc_long_ex(&_0, SL("NOT_UPDATED"), 422);
	add_assoc_long_ex(&_0, SL("NOT_VALID"), 422);
	add_assoc_long_ex(&_0, SL("PROCESSING"), 102);
	add_assoc_long_ex(&_0, SL("SUCCESS"), 200);
	add_assoc_long_ex(&_0, SL("UPDATED"), 200);
	add_assoc_long_ex(&_0, SL("VALID"), 200);
	ZEPHIR_INIT_VAR(&_1);
	zephir_add_function(&_1, &overrides, &_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 327, &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the HTTP status code for the given domain status.
 *
 * An unmapped status resolves to 500 (server error), never a silent 200.
 */
PHP_METHOD(Phalcon_ADR_Responder_StatusMapper, toHttpCode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval status_zv, _0, _1, _2;
	zend_string *status = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&status_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("map", 3, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(status)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&status_zv);
	ZVAL_STR_COPY(&status_zv, status);
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 327, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_1, &status_zv)) {
		zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 327, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_0);
		zephir_array_fetch(&_0, &_2, &status_zv, PH_NOISY, "phalcon/ADR/Responder/StatusMapper.zep", 66);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, 500);
	}
	RETURN_CCTOR(&_0);
}

