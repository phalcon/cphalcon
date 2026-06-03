
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

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_translate_adapter_abstractadapter_ce, SL("defaultInterpolator"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var InterpolatorFactory
	 */
	zend_declare_property_null(phalcon_translate_adapter_abstractadapter_ce, SL("interpolatorFactory"), ZEND_ACC_PROTECTED);
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
	zval *interpolator, interpolator_sub, *options_param = NULL, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&interpolator_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(interpolator, phalcon_translate_interpolatorfactory_ce)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &interpolator, &options_param);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultInterpolator"), &value);
	zephir_update_property_zval(this_ptr, ZEND_STRL("interpolatorFactory"), interpolator);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the translation string of the given key (alias of method 't')
 *
 * @phpstan-param array<string, string> $placeholders
 *
 * @return string
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
 * Check whether a translation key exists
 *
 * @param mixed $translateKey
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *translateKey, translateKey_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translateKey_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(translateKey)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &translateKey);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, translateKey);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the translation related to the given key
 *
 * @param TKey $translateKey
 *
 * @return TValue|null
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, offsetGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval translateKey_sub;
	zval *translateKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translateKey_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(translateKey)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &translateKey);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "query", NULL, 0, translateKey);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets a translation value
 *
 * @param mixed $offset
 * @param mixed $value
 *
 * @return void
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 132);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Translate/Adapter/AbstractAdapter.zep", 103);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Unsets a translation from the dictionary
 *
 * @param mixed $offset
 *
 * @return void
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 132);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Translate/Adapter/AbstractAdapter.zep", 116);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Returns the translation string of the given key
 *
 * @phpstan-param array<string, string> $placeholders
 *
 * @return string
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
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_AbstractAdapter, replacePlaceholders)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval placeholders;
	zval translation_zv, *placeholders_param = NULL, interpolator, _0, _1;
	zend_string *translation = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&translation_zv);
	ZVAL_UNDEF(&interpolator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&placeholders);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("interpolatorFactory"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("defaultInterpolator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&interpolator, &_0, "newinstance", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&interpolator, "replaceplaceholders", NULL, 0, &translation_zv, &placeholders);
	zephir_check_call_status();
	RETURN_MM();
}

