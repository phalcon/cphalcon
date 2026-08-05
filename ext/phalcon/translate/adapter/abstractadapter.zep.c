
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
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
 * @psalm-type TOptions array{
 *     defaultInterpolator?: string
 * }
 *
 * @template TKey of string
 * @template TValue of string
 * @implements ArrayAccess<TKey, TValue>
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_AbstractAdapter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Translate\\Adapter, AbstractAdapter, phalcon, translate_adapter_abstractadapter, phalcon_translate_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_translate_adapter_abstractadapter_ce, SL("defaultInterpolator"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_translate_adapter_abstractadapter_ce, SL("interpolator"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Translate\\Interpolator\\InterpolatorInterface"));
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_translate_adapter_abstractadapter_ce, SL("interpolatorFactory"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Translate\\InterpolatorFactory"));
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_translate_adapter_abstractadapter_ce, SL("triggerError"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	zend_class_implements(phalcon_translate_adapter_abstractadapter_ce, 1, phalcon_translate_adapter_adapterinterface_ce);
	zend_class_implements(phalcon_translate_adapter_abstractadapter_ce, 1, zend_ce_arrayaccess);
	return SUCCESS;
}

/**
 * AbstractAdapter constructor.
 *
 * @param TOptions            $options
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval options;
	zval *interpolatorFactory, interpolatorFactory_sub, *options_param = NULL, __$true, __$false, error, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&interpolatorFactory_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&options);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultInterpolator", 19, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("interpolatorFactory", 19, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("triggerError", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(interpolatorFactory, phalcon_translate_interpolatorfactory_ce)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &interpolatorFactory, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_memory_observe(&value);
	if (!(zephir_array_isset_string_fetch(&value, &options, SL("defaultInterpolator"), 0))) {
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_STRING(&value, "associativeArray");
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 132, &value);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 133, interpolatorFactory);
	zephir_memory_observe(&error);
	if (zephir_array_isset_string_fetch(&error, &options, SL("triggerError"), 0)) {
		if (zephir_get_boolval(&error)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 134, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 134, &__$false);
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the translation string of the given key (alias of method 't')
 *
 * @phpstan-param array<string, string> $placeholders
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, _)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval translateKey_zv, *placeholders_param = NULL;
	zend_string *translateKey = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translateKey_zv);
	ZVAL_UNDEF(&placeholders);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(translateKey)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(placeholders, placeholders_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		placeholders_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&translateKey_zv);
	ZVAL_STR_COPY(&translateKey_zv, translateKey);
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, &translateKey_zv, &placeholders);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Whenever a key is not found this method will be called
 *
 * @throws KeyNotFound
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, notFound)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval index_zv, _0, _1$$3;
	zend_string *index = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("triggerError", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&index_zv);
	ZVAL_STR_COPY(&index_zv, index);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 134, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_translate_exceptions_keynotfound_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 150, &index_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Translate/Adapter/AbstractAdapter.zep", 77);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_STR(zend_string_copy(index));
}

/**
 * Check whether a translation key exists
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &offset);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, offset);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the translation related to the given key
 *
 * @param TKey $offset
 *
 * @return TValue
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval offset_sub;
	zval *offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &offset);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, offset);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets a translation value
 *
 * @throws ImmutableObject
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetSet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub, *value, value_sub, _0;

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(offset)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &offset, &value);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_translate_exceptions_immutableobject_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 151);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Translate/Adapter/AbstractAdapter.zep", 110);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Unsets a translation from the dictionary
 *
 * @throws ImmutableObject
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetUnset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub, _0;

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &offset);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_translate_exceptions_immutableobject_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 151);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Translate/Adapter/AbstractAdapter.zep", 120);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Returns the translation string of the given key
 *
 * @phpstan-param array<string, string> $placeholders
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, t)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval translateKey_zv, *placeholders_param = NULL;
	zend_string *translateKey = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translateKey_zv);
	ZVAL_UNDEF(&placeholders);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(translateKey)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(placeholders, placeholders_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		placeholders_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&translateKey_zv);
	ZVAL_STR_COPY(&translateKey_zv, translateKey);
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, &translateKey_zv, &placeholders);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Replaces placeholders by the values passed
 *
 * @phpstan-param array<string, string> $placeholders
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, replacePlaceholders)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval translation_zv, *placeholders_param = NULL, _0, _4, _1$$3, _2$$3, _3$$3;
	zend_string *translation = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translation_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&placeholders);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("interpolator", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("interpolatorFactory", 19, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("defaultInterpolator", 19, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(translation)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(placeholders, placeholders_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		placeholders_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&translation_zv);
	ZVAL_STR_COPY(&translation_zv, translation);
	if (!placeholders_param) {
		ZEPHIR_INIT_VAR(&placeholders);
		array_init(&placeholders);
	} else {
		zephir_get_arrval(&placeholders, placeholders_param);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 135, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 133, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_2, 132, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2$$3, &_1$$3, "newinstance", NULL, 0, &_3$$3);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 135, &_2$$3);
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 135, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_4, "replaceplaceholders", NULL, 0, &translation_zv, &placeholders);
	zephir_check_call_status();
	RETURN_MM();
}

