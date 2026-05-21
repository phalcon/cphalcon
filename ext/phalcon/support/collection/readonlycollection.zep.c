
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * A read only Collection object
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Collection_ReadOnlyCollection)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Support\\Collection, ReadOnlyCollection, phalcon, support_collection_readonlycollection, phalcon_support_collection_ce, phalcon_support_collection_readonlycollection_method_entry, 0);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_support_collection_readonlycollection_ce, SL("constructed"), 0, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * ReadOnlyCollection constructor.
 *
 * @param array<int|string, mixed> $data
 * @param bool                     $insensitive
 * @param bool                     $strictNull
 * @param string|null              $type
 */
PHP_METHOD(Phalcon_Support_Collection_ReadOnlyCollection, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *type = NULL;
	zend_bool insensitive, strictNull;
	zval *data_param = NULL, *insensitive_param = NULL, *strictNull_param = NULL, type_zv, __$true, __$false, _0, _1;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&type_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
		Z_PARAM_BOOL(insensitive)
		Z_PARAM_BOOL(strictNull)
		Z_PARAM_STR_OR_NULL(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 0) {
		data_param = ZEND_CALL_ARG(execute_data, 1);
	}
	if (ZEND_NUM_ARGS() > 1) {
		insensitive_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		strictNull_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}
	if (!insensitive_param) {
		insensitive = 1;
	} else {
		}
	if (!strictNull_param) {
		strictNull = 0;
	} else {
		}
	if (!type) {
		ZEPHIR_INIT_VAR(&type_zv);
	} else {
		zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	}
	if (insensitive) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	if (strictNull) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_support_collection_readonlycollection_ce, getThis(), "__construct", NULL, 0, &data, &_0, &_1, &type_zv);
	zephir_check_call_status();
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("constructed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("constructed"), &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Restores the collection state during unserialization.
 *
 * Temporarily disables the read-only guard so the parent class can restore
 * the collection state. The guard is re-enabled before the method returns.
 *
 * @param array $data
 */
PHP_METHOD(Phalcon_Support_Collection_ReadOnlyCollection, __unserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, __$true, __$false, ex, _0;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_arrval(&data, data_param);
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("constructed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("constructed"), &__$false);
	}

	/* try_start_1: */

		ZEPHIR_CALL_PARENT(NULL, phalcon_support_collection_readonlycollection_ce, getThis(), "__unserialize", NULL, 0, &data);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_0);
		ZVAL_OBJ(&_0, EG(exception));
		Z_ADDREF_P(&_0);
		if (zephir_is_instance_of(&_0, SL("Phalcon\\Support\\Collection\\Throwable"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&ex, &_0);
			if (1) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("constructed"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("constructed"), &__$false);
			}
			zephir_throw_exception_debug(&ex, "phalcon/Support/Collection/ReadOnlyCollection.zep", 64);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * @throws ReadOnlyViolation
 */
PHP_METHOD(Phalcon_Support_Collection_ReadOnlyCollection, clear)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_support_collection_exceptions_readonlyviolation_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Support/Collection/ReadOnlyCollection.zep", 73);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * @throws ReadOnlyViolation
 */
PHP_METHOD(Phalcon_Support_Collection_ReadOnlyCollection, init)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, _0, _1$$3;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &data_param);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("constructed"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_support_collection_exceptions_readonlyviolation_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Support/Collection/ReadOnlyCollection.zep", 82);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_support_collection_readonlycollection_ce, getThis(), "init", NULL, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Delete the element from the collection
 *
 * @param string $element Name of the element
 *
 * @throws ReadOnlyViolation
 */
PHP_METHOD(Phalcon_Support_Collection_ReadOnlyCollection, remove)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval element_zv, _0;
	zend_string *element = NULL;

	ZVAL_UNDEF(&element_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&element_zv);
	ZVAL_STR_COPY(&element_zv, element);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_support_collection_exceptions_readonlyviolation_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Support/Collection/ReadOnlyCollection.zep", 97);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Replaces the collection data with a new array
 *
 * @param array<int|string, mixed> $data
 *
 * @throws ReadOnlyViolation
 */
PHP_METHOD(Phalcon_Support_Collection_ReadOnlyCollection, replace)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, _0;
	zval data;

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_arrval(&data, data_param);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_support_collection_exceptions_readonlyviolation_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Support/Collection/ReadOnlyCollection.zep", 109);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Set an element in the collection
 *
 * @param string $element Name of the element
 * @param mixed  $value   Value to store for the element
 *
 * @throws ReadOnlyViolation
 */
PHP_METHOD(Phalcon_Support_Collection_ReadOnlyCollection, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval element_zv, *value, value_sub, _0;
	zend_string *element = NULL;

	ZVAL_UNDEF(&element_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(element)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&element_zv);
	ZVAL_STR_COPY(&element_zv, element);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_support_collection_exceptions_readonlyviolation_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Support/Collection/ReadOnlyCollection.zep", 122);
	ZEPHIR_MM_RESTORE();
	return;
}

