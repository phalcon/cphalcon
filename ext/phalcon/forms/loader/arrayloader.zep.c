
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
 * For the full copyright and license information, please view the LICENSE.txt
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 799, &definitions);
	ZEPHIR_MM_RESTORE();
}

/**
 * @phpstan-return array<int, array<string, mixed>>
 * @throws Exception
 */
PHP_METHOD(Phalcon_Forms_Loader_ArrayLoader, load)
{
	zend_bool _9;
	zend_string *_5;
	zend_ulong _4;
	zval definition, index, _0, *_1, _2, *_3, _8, _6$$3, _10$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_10$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("definitions", 11, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 799, PH_NOISY_CC | PH_READONLY);
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
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "validatedefinition", &_7, 0, &definition, &_6$$3);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_9 = 1;
		while (1) {
			if (_9) {
				_9 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_8, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&index, _1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&definition, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_LONG(&_10$$4, zephir_get_intval(&index));
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "validatedefinition", &_7, 0, &definition, &_10$$4);
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
	zend_bool _2, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long index, ZEPHIR_LAST_CALL_STATUS;
	zval *definition, definition_sub, *index_param = NULL, _0$$3, _1$$3, _3$$4, _4$$4, _5$$4, _7$$5, _8$$5, _9$$5;

	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Forms/Loader/ArrayLoader.zep", 54);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = !(zephir_array_isset_value_string(definition, SL("type")));
	if (!(_2)) {
		_2 = zephir_isempty_dim_string(definition, SL("type"));
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, phalcon_forms_exceptions_schemaentrymissingkey_ce);
		ZVAL_LONG(&_4$$4, index);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "type");
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 0, &_4$$4, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "phalcon/Forms/Loader/ArrayLoader.zep", 58);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_6 = !(zephir_array_isset_value_string(definition, SL("name")));
	if (!(_6)) {
		_6 = zephir_isempty_dim_string(definition, SL("name"));
	}
	if (_6) {
		ZEPHIR_INIT_VAR(&_7$$5);
		object_init_ex(&_7$$5, phalcon_forms_exceptions_schemaentrymissingkey_ce);
		ZVAL_LONG(&_8$$5, index);
		ZEPHIR_INIT_VAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "name");
		ZEPHIR_CALL_METHOD(NULL, &_7$$5, "__construct", NULL, 0, &_8$$5, &_9$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$5, "phalcon/Forms/Loader/ArrayLoader.zep", 62);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

