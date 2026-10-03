
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Describes a model column. It is the attribute form of `@Column`.
 *
 * The parameter names are camelCase, because PSR-12 does not allow
 * snake_case. The metadata strategy reads the two spellings. The default
 * value is `defaultValue` and not `default`, because `default` is a Zephir
 * keyword.
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Models_MetaData_Column)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations\\Models\\MetaData, Column, phalcon, annotations_models_metadata_column, phalcon_annotations_models_metadata_column_method_entry, 0);

	{
		zend_attribute *_za = zephir_add_class_attribute(phalcon_annotations_models_metadata_column_ce, SL("Attribute"), 1);
		zval _zc0;
		ZVAL_LONG(&_zc0, 8);
		zephir_attribute_set_arg(_za, 0, NULL, 0, &_zc0);
	}

	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_annotations_models_metadata_column_ce, SL("allowEmptyString"), ZEND_ACC_PUBLIC);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_annotations_models_metadata_column_ce, SL("column"), ZEND_ACC_PUBLIC);
	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_annotations_models_metadata_column_ce, SL("defaultValue"), ZEND_ACC_PUBLIC);
	/**
	 * @var int|null
	 */
	zend_declare_property_null(phalcon_annotations_models_metadata_column_ce, SL("length"), ZEND_ACC_PUBLIC);
	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_annotations_models_metadata_column_ce, SL("nullable"), ZEND_ACC_PUBLIC);
	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_annotations_models_metadata_column_ce, SL("skipOnInsert"), ZEND_ACC_PUBLIC);
	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_annotations_models_metadata_column_ce, SL("skipOnUpdate"), ZEND_ACC_PUBLIC);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_annotations_models_metadata_column_ce, SL("type"), ZEND_ACC_PUBLIC);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Annotations_Models_MetaData_Column, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool nullable, skipOnInsert, skipOnUpdate, allowEmptyString;
	zend_long length;
	zval column_zv, type_zv, *length_param = NULL, *nullable_param = NULL, *skipOnInsert_param = NULL, *skipOnUpdate_param = NULL, *allowEmptyString_param = NULL, *defaultValue = NULL, defaultValue_sub, __$true, __$false, __$null, _0;
	zend_string *column = NULL, *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_zv);
	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("column", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("type", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("length", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("nullable", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("skipOnInsert", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("skipOnUpdate", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("allowEmptyString", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("defaultValue", 12, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 8)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(column)
		Z_PARAM_STR(type)
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
		Z_PARAM_BOOL(nullable)
		Z_PARAM_BOOL(skipOnInsert)
		Z_PARAM_BOOL(skipOnUpdate)
		Z_PARAM_BOOL(allowEmptyString)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		length_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		nullable_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		skipOnInsert_param = ZEND_CALL_ARG(execute_data, 5);
	}
	if (ZEND_NUM_ARGS() > 5) {
		skipOnUpdate_param = ZEND_CALL_ARG(execute_data, 6);
	}
	if (ZEND_NUM_ARGS() > 6) {
		allowEmptyString_param = ZEND_CALL_ARG(execute_data, 7);
	}
	if (ZEND_NUM_ARGS() > 7) {
		defaultValue = ZEND_CALL_ARG(execute_data, 8);
	}
	if (!column) {
		ZEPHIR_INIT_VAR(&column_zv);
	} else {
		zephir_memory_observe(&column_zv);
	ZVAL_STR_COPY(&column_zv, column);
	}
	if (!type) {
		type = zend_string_init(ZEND_STRL("string"), 0);
		zephir_memory_observe(&type_zv);
		ZVAL_STR(&type_zv, type);
	} else {
		zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (!nullable_param) {
		nullable = 0;
	} else {
		}
	if (!skipOnInsert_param) {
		skipOnInsert = 0;
	} else {
		}
	if (!skipOnUpdate_param) {
		skipOnUpdate = 0;
	} else {
		}
	if (!allowEmptyString_param) {
		allowEmptyString = 0;
	} else {
		}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 408, &column_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 409, &type_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, length);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 410, &_0);
	if (nullable) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 411, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 411, &__$false);
	}
	if (skipOnInsert) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 412, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 412, &__$false);
	}
	if (skipOnUpdate) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 413, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 413, &__$false);
	}
	if (allowEmptyString) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 414, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 414, &__$false);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 415, defaultValue);
	ZEPHIR_MM_RESTORE();
}

