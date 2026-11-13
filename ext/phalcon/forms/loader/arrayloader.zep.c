
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Supplies form element definitions from a PHP array.
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Loader_ArrayLoader)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Forms\\Loader, ArrayLoader, phalcon, forms_loader_arrayloader, phalcon_forms_loader_arrayloader_method_entry, 0);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_forms_loader_arrayloader_ce, SL("definitions"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	zend_class_implements(phalcon_forms_loader_arrayloader_ce, 1, phalcon_contracts_forms_schema_ce);
	return SUCCESS;
}

/**
 * @param array $definitions
 */
PHP_METHOD(Phalcon_Forms_Loader_ArrayLoader, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *definitions_param = NULL;
	zval definitions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definitions);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("definitions", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(definitions, definitions_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &definitions_param);
	zephir_get_arrval(&definitions, definitions_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 816, &definitions);
	ZEPHIR_MM_RESTORE();
}

/**
 * @phpstan-return array<int, array<string, mixed>>
 * @throws Exception
 */
PHP_METHOD(Phalcon_Forms_Loader_ArrayLoader, load)
{
	zend_bool _8;
	zend_string *_5;
	zend_ulong _4;
	zval definition, index, _0, *_1, _2, *_3, _7, _6$$3, _9$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("definitions", 11, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 816, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Forms/Loader/ArrayLoader.zep", 45);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&index);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&index, _5);
			} else {
				ZVAL_LONG(&index, _4);
			}
			ZEPHIR_INIT_NVAR(&definition);
			ZVAL_COPY(&definition, _3);
			ZVAL_LONG(&_6$$3, zephir_get_intval(&index));
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "validateDefinition", &_zephir_call_cache[0], &definition, &_6$$3);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_7, _1, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&index, _1, "key", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&definition, _1, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				ZVAL_LONG(&_9$$4, zephir_get_intval(&index));
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "validateDefinition", &_zephir_call_cache[6], &definition, &_9$$4);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&definition);
	ZEPHIR_INIT_NVAR(&index);
	RETURN_MM_MEMBER_TYPED(getThis(), "definitions", IS_ARRAY);
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Forms_Loader_ArrayLoader, validateDefinition)
{
	zend_bool _2, _3, _4, _8, _9, _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long index, ZEPHIR_LAST_CALL_STATUS;
	zval *definition, definition_sub, *index_param = NULL, _0$$3, _1$$3, _5$$4, _6$$4, _7$$4, _11$$5, _12$$5, _13$$5;

	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(definition)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &definition, &index_param);
	if (Z_TYPE_P(definition) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_forms_exceptions_schemaentrynotarray_ce);
		ZVAL_LONG(&_1$$3, index);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[0], &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Forms/Loader/ArrayLoader.zep", 54);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = zephir_array_isset_value_string(definition, SL("type"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = !(_2);
	if (!(_3)) {
		_4 = zephir_isempty_dim_string(definition, SL("type"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_3 = _4;
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, phalcon_forms_exceptions_schemaentrymissingkey_ce);
		ZVAL_LONG(&_6$$4, index);
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "type");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_5$$4, "__construct", &_zephir_call_cache[1], &_6$$4, &_7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$4, "phalcon/Forms/Loader/ArrayLoader.zep", 58);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_8 = zephir_array_isset_value_string(definition, SL("name"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_9 = !(_8);
	if (!(_9)) {
		_10 = zephir_isempty_dim_string(definition, SL("name"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_9 = _10;
	}
	if (_9) {
		ZEPHIR_INIT_VAR(&_11$$5);
		object_init_ex(&_11$$5, phalcon_forms_exceptions_schemaentrymissingkey_ce);
		ZVAL_LONG(&_12$$5, index);
		ZEPHIR_INIT_VAR(&_13$$5);
		ZVAL_STRING(&_13$$5, "name");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_11$$5, "__construct", &_zephir_call_cache[2], &_12$$5, &_13$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$5, "phalcon/Forms/Loader/ArrayLoader.zep", 62);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

