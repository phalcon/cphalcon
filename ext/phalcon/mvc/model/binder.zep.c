
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
#include "kernel/memory.h"
#include "Zend/zend_closures.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
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
 * This is a class for binding models into params for handler
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Binder)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Binder, phalcon, mvc_model_binder, phalcon_mvc_model_binder_method_entry, 0);

	/**
	 * Array for storing active bound models
	 *
	 * @phpstan-var array<array-key, ModelInterface>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_binder_ce, SL("boundModels"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Cache object used for caching parameters for model binding
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_mvc_model_binder_ce, SL("cache"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Cache\\Adapter\\AdapterInterface"));
	}

	/**
	 * Internal cache for caching parameters for model binding during request
	 *
	 * @phpstan-var array<string, array<array-key, string>>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_binder_ce, SL("internalCache"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Array for original values
	 *
	 * @phpstan-var array<array-key, mixed>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_binder_ce, SL("originalValues"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	zend_class_implements(phalcon_mvc_model_binder_ce, 1, phalcon_mvc_model_binderinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Binder constructor
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, __construct)
{
	zval *cache = NULL, cache_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cache_sub);
	ZVAL_NULL(&__$null);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("cache", 5, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(cache, phalcon_cache_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(0, 1, &cache);
	if (!cache) {
		cache = &cache_sub;
		cache = &__$null;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1030, cache);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
}

/**
 * Bind models into params in proper handler
 *
 * @phpstan-param array<array-key, mixed> $params
 * @phpstan-return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, bindToHandler)
{
	zend_ulong _7$$4;
	zend_bool _1, _10$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *cacheKey = NULL, *methodName = NULL, *_8$$4;
	zval params;
	zval *handler, handler_sub, *params_param = NULL, cacheKey_zv, methodName_zv, paramKey, className, boundModel, paramsCache, paramValue, _0, _3, _2$$3, *_4$$4, _5$$4, *_6$$4, _9$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&cacheKey_zv);
	ZVAL_UNDEF(&methodName_zv);
	ZVAL_UNDEF(&paramKey);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&boundModel);
	ZVAL_UNDEF(&paramsCache);
	ZVAL_UNDEF(&paramValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&params);
	ZEND_TLS zephir_method_cache _zephir_call_cache[10];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("originalValues", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("boundModels", 11, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_OBJECT(handler)
		ZEPHIR_Z_PARAM_ARRAY(params, params_param)
		Z_PARAM_STR(cacheKey)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(methodName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 1);
	params_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_get_arrval(&params, params_param);
	zephir_memory_observe(&cacheKey_zv);
	ZVAL_STR_COPY(&cacheKey_zv, cacheKey);
	if (!methodName) {
		ZEPHIR_INIT_VAR(&methodName_zv);
	} else {
		zephir_memory_observe(&methodName_zv);
	ZVAL_STR_COPY(&methodName_zv, methodName);
	}
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1031, &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = !((zephir_is_instance_of(handler, SL("Closure"))));
	if (_1) {
		_1 = Z_TYPE_P(&methodName_zv) == IS_NULL;
	}
	if (UNEXPECTED(_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_model_exceptions_missingmethodname_ce);
		zephir_constructor_start(&_2$$3);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_constructor_finish(&_2$$3);
		zephir_throw_exception_debug(&_2$$3, "phalcon/Mvc/Model/Binder.zep", 79);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1032, &_3);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&paramsCache, this_ptr, "getParamsFromCache", &_zephir_call_cache[1], &cacheKey_zv);
	zephir_check_call_status();
	if (Z_TYPE_P(&paramsCache) == IS_ARRAY) {
		if (Z_TYPE_P(&paramsCache) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_5$$4);
			zephir_string_to_char_array(&_5$$4, &paramsCache);
			_4$$4 = &_5$$4;
		} else {
			_4$$4 = &paramsCache;
		}
		zephir_is_iterable(_4$$4, 0, "phalcon/Mvc/Model/Binder.zep", 94);
		if (Z_TYPE_P(_4$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_4$$4), _7$$4, _8$$4, _6$$4)
			{
				ZEPHIR_INIT_NVAR(&paramKey);
				if (_8$$4 != NULL) { 
					ZVAL_STR_COPY(&paramKey, _8$$4);
				} else {
					ZVAL_LONG(&paramKey, _7$$4);
				}
				ZEPHIR_INIT_NVAR(&className);
				ZVAL_COPY(&className, _6$$4);
				ZEPHIR_OBS_NVAR(&paramValue);
				zephir_array_fetch(&paramValue, &params, &paramKey, PH_NOISY, "phalcon/Mvc/Model/Binder.zep", 87);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&boundModel, this_ptr, "findBoundModel", &_zephir_call_cache[2], &paramValue, &className);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("originalValues"), &paramKey, &paramValue);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&params, &paramKey, &boundModel, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_update_property_array(this_ptr, SL("boundModels"), &paramKey, &boundModel);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _4$$4, "rewind", &_zephir_call_cache[3]);
			zephir_check_call_status();
			_10$$4 = 1;
			while (1) {
				if (_10$$4) {
					_10$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _4$$4, "next", &_zephir_call_cache[4]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_9$$4, _4$$4, "valid", &_zephir_call_cache[5]);
				zephir_check_call_status();
				if (!zend_is_true(&_9$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&paramKey, _4$$4, "key", &_zephir_call_cache[6]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&className, _4$$4, "current", &_zephir_call_cache[7]);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&paramValue);
					zephir_array_fetch(&paramValue, &params, &paramKey, PH_NOISY, "phalcon/Mvc/Model/Binder.zep", 87);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&boundModel, this_ptr, "findBoundModel", &_zephir_call_cache[8], &paramValue, &className);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("originalValues"), &paramKey, &paramValue);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&params, &paramKey, &boundModel, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_update_property_array(this_ptr, SL("boundModels"), &paramKey, &boundModel);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		RETURN_CTOR(&params);
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getParamsFromReflection", &_zephir_call_cache[9], handler, &params, &cacheKey_zv, &methodName_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return the active bound models
 *
 * @return array
 *
 * @phpstan-return array<array-key, ModelInterface>
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getBoundModels)
{

	RETURN_MEMBER_TYPED(getThis(), "boundModels", IS_ARRAY);
}

/**
 * Sets cache instance
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getCache)
{

	RETURN_MEMBER(getThis(), "cache");
}

/**
 * Return the array for original values
 *
 * @return array
 *
 * @phpstan-return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getOriginalValues)
{

	RETURN_MEMBER_TYPED(getThis(), "originalValues", IS_ARRAY);
}

/**
 * Gets cache instance
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, setCache)
{
	zval *cache, cache_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cache_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("cache", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(cache, phalcon_cache_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &cache);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1030, cache);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_THISW();
}

/**
 * Find the model by param value.
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, findBoundModel)
{
	zend_class_entry *_0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *className = NULL;
	zval *paramValue, paramValue_sub, className_zv;

	ZVAL_UNDEF(&paramValue_sub);
	ZVAL_UNDEF(&className_zv);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(paramValue)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	paramValue = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	_0 = zephir_fetch_class(&className_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_CE_STATIC_THIS_CACHED(_0, getThis(), "findFirst", &_zephir_call_cache[0], paramValue);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get params classes from cache by key
 *
 * @phpstan-return array<array-key, string>|null
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getParamsFromCache)
{
	zend_bool _1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval cacheKey_zv, cache, internalParams, _0, _2, _4;
	zend_string *cacheKey = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cacheKey_zv);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&internalParams);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("internalCache", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("cache", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(cacheKey)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&cacheKey_zv);
	ZVAL_STR_COPY(&cacheKey_zv, cacheKey);
	zephir_memory_observe(&internalParams);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1033, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_fetch(&internalParams, &_0, &cacheKey_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		RETURN_CCTOR(&internalParams);
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 1030, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&cache, &_2);
	_3 = Z_TYPE_P(&cache) == IS_NULL;
	if (!(_3)) {
		ZEPHIR_CALL_METHOD_CACHED(&_4, &cache, "has", &_zephir_call_cache[0], &cacheKey_zv);
		zephir_check_call_status();
		_3 = !zephir_is_true(&_4);
	}
	if (_3) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD_CACHED(&internalParams, &cache, "get", &_zephir_call_cache[1], &cacheKey_zv);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("internalCache"), &cacheKey_zv, &internalParams);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&internalParams);
}

/**
 * Get modified params for handler using reflection
 *
 * @phpstan-param array<array-key, mixed> $params
 * @phpstan-return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getParamsFromReflection)
{
	zend_class_entry *_14$$10, *_26$$24;
	zend_bool _20, _8$$5, _9$$5, _16$$13, _21$$19, _22$$19, _28$$27;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *cacheKey = NULL, *methodName = NULL, *_7;
	zval params, paramsCache;
	zval *handler, handler_sub, *params_param = NULL, cacheKey_zv, methodName_zv, methodParams, reflection, paramKey, methodParam, className, realClasses, boundModel, cache, handlerClass, reflectionClass, paramsKeys, paramValue, _2, *_3, _4, *_5, _19, _0$$3, _1$$4, _11$$5, _12$$5, _10$$7, _15$$12, _17$$14, _18$$16, _24$$19, _25$$19, _23$$21, _27$$26, _29$$28, _30$$30;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&cacheKey_zv);
	ZVAL_UNDEF(&methodName_zv);
	ZVAL_UNDEF(&methodParams);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&paramKey);
	ZVAL_UNDEF(&methodParam);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&realClasses);
	ZVAL_UNDEF(&boundModel);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&handlerClass);
	ZVAL_UNDEF(&reflectionClass);
	ZVAL_UNDEF(&paramsKeys);
	ZVAL_UNDEF(&paramValue);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_18$$16);
	ZVAL_UNDEF(&_24$$19);
	ZVAL_UNDEF(&_25$$19);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&_27$$26);
	ZVAL_UNDEF(&_29$$28);
	ZVAL_UNDEF(&_30$$30);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&paramsCache);
	ZEND_TLS zephir_method_cache _zephir_call_cache[29];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("cache", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT(handler)
		ZEPHIR_Z_PARAM_ARRAY(params, params_param)
		Z_PARAM_STR(cacheKey)
		Z_PARAM_STR(methodName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handler = ZEND_CALL_ARG(execute_data, 1);
	params_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_get_arrval(&params, params_param);
	zephir_memory_observe(&cacheKey_zv);
	ZVAL_STR_COPY(&cacheKey_zv, cacheKey);
	zephir_memory_observe(&methodName_zv);
	ZVAL_STR_COPY(&methodName_zv, methodName);
	ZEPHIR_INIT_VAR(&realClasses);
	ZVAL_NULL(&realClasses);
	ZEPHIR_INIT_VAR(&paramsCache);
	array_init(&paramsCache);
	ZEPHIR_INIT_VAR(&reflection);
	if (Z_TYPE_P(&methodName_zv) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, zephir_get_internal_ce(SL("reflectionmethod")));
		zephir_constructor_start(&_0$$3);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[0], handler, &methodName_zv);
		zephir_check_call_status();
		zephir_constructor_finish(&_0$$3);
		ZEPHIR_CPY_WRT(&reflection, &_0$$3);
		ZEPHIR_INIT_NVAR(&_0$$3);
	} else {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, zephir_get_internal_ce(SL("reflectionfunction")));
		zephir_constructor_start(&_1$$4);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$4, "__construct", &_zephir_call_cache[1], handler);
		zephir_check_call_status();
		zephir_constructor_finish(&_1$$4);
		ZEPHIR_CPY_WRT(&reflection, &_1$$4);
		ZEPHIR_INIT_NVAR(&_1$$4);
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 1030, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&cache, &_2);
	ZEPHIR_CALL_METHOD_CACHED(&methodParams, &reflection, "getParameters", &_zephir_call_cache[2]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&paramsKeys);
	zephir_array_keys(&paramsKeys, &params);
	if (Z_TYPE_P(&methodParams) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &methodParams);
		_3 = &_4;
	} else {
		_3 = &methodParams;
	}
	zephir_is_iterable(_3, 0, "phalcon/Mvc/Model/Binder.zep", 260);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_3), _6, _7, _5)
		{
			ZEPHIR_INIT_NVAR(&paramKey);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&paramKey, _7);
			} else {
				ZVAL_LONG(&paramKey, _6);
			}
			ZEPHIR_INIT_NVAR(&methodParam);
			ZVAL_COPY(&methodParam, _5);
			ZEPHIR_CALL_METHOD_CACHED(&reflectionClass, &methodParam, "getType", &_zephir_call_cache[3]);
			zephir_check_call_status();
			_8$$5 = !zephir_is_true(&reflectionClass);
			if (!(_8$$5)) {
				_8$$5 = !((zephir_is_instance_of(&reflectionClass, SL("ReflectionNamedType"))));
			}
			if (_8$$5) {
				continue;
			}
			ZEPHIR_CALL_METHOD_CACHED(&className, &reflectionClass, "getName", &_zephir_call_cache[4]);
			zephir_check_call_status();
			_9$$5 = zephir_array_isset_value(&params, &paramKey);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_9$$5)) {
				ZEPHIR_OBS_NVAR(&_10$$7);
				zephir_array_fetch(&_10$$7, &paramsKeys, &paramKey, PH_NOISY, "phalcon/Mvc/Model/Binder.zep", 218);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(&paramKey, &_10$$7);
			}
			ZEPHIR_INIT_NVAR(&boundModel);
			ZVAL_NULL(&boundModel);
			ZEPHIR_OBS_NVAR(&paramValue);
			zephir_array_fetch(&paramValue, &params, &paramKey, PH_NOISY, "phalcon/Mvc/Model/Binder.zep", 222);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_STRING(&className, "Phalcon\\Mvc\\Model")) {
				if (Z_TYPE_P(&realClasses) == IS_NULL) {
					if (zephir_instance_of_ev(handler, phalcon_mvc_controller_bindmodelinterface_ce)) {
						ZEPHIR_INIT_NVAR(&handlerClass);
						zephir_get_class(&handlerClass, handler, 0);
						_14$$10 = zephir_fetch_class(&handlerClass);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_CE_STATIC_THIS_CACHED(&realClasses, _14$$10, getThis(), "getModelName", &_zephir_call_cache[5]);
						zephir_check_call_status();
					} else if (zephir_instance_of_ev(handler, phalcon_mvc_model_binder_bindableinterface_ce)) {
						ZEPHIR_CALL_METHOD_CACHED(&realClasses, handler, "getModelName", &_zephir_call_cache[6]);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&_15$$12);
						object_init_ex(&_15$$12, phalcon_mvc_model_exceptions_handlermustimplementbindable_ce);
						zephir_constructor_start(&_15$$12);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_15$$12, "__construct", &_zephir_call_cache[7]);
						zephir_check_call_status();
						zephir_constructor_finish(&_15$$12);
						zephir_throw_exception_debug(&_15$$12, "phalcon/Mvc/Model/Binder.zep", 232);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (Z_TYPE_P(&realClasses) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&className);
					_16$$13 = zephir_array_isset_fetch(&className, &realClasses, &paramKey, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_16$$13))) {
						ZEPHIR_INIT_NVAR(&_17$$14);
						object_init_ex(&_17$$14, phalcon_mvc_model_exceptions_missingmodelclassname_ce);
						zephir_constructor_start(&_17$$14);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_17$$14, "__construct", &_zephir_call_cache[8], &paramKey);
						zephir_check_call_status();
						zephir_constructor_finish(&_17$$14);
						zephir_throw_exception_debug(&_17$$14, "phalcon/Mvc/Model/Binder.zep", 238);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&boundModel, this_ptr, "findBoundModel", &_zephir_call_cache[9], &paramValue, &className);
					zephir_check_call_status();
				} else if (Z_TYPE_P(&realClasses) == IS_STRING) {
					ZEPHIR_CPY_WRT(&className, &realClasses);
					ZEPHIR_CALL_METHOD_CACHED(&boundModel, this_ptr, "findBoundModel", &_zephir_call_cache[10], &paramValue, &className);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_18$$16);
					object_init_ex(&_18$$16, phalcon_mvc_model_exceptions_invalidgetmodelnamereturn_ce);
					zephir_constructor_start(&_18$$16);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_18$$16, "__construct", &_zephir_call_cache[11]);
					zephir_check_call_status();
					zephir_constructor_finish(&_18$$16);
					zephir_throw_exception_debug(&_18$$16, "phalcon/Mvc/Model/Binder.zep", 246);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZVAL_STRING(&_11$$5, "Phalcon\\Mvc\\Model");
				ZEPHIR_CALL_FUNCTION(&_12$$5, "is_subclass_of", &_13, 41, &className, &_11$$5);
				zephir_check_call_status();
				if (zephir_is_true(&_12$$5)) {
					ZEPHIR_CALL_METHOD_CACHED(&boundModel, this_ptr, "findBoundModel", &_zephir_call_cache[12], &paramValue, &className);
					zephir_check_call_status();
				}
			}
			if (Z_TYPE_P(&boundModel) != IS_NULL) {
				zephir_update_property_array(this_ptr, SL("originalValues"), &paramKey, &paramValue);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&params, &paramKey, &boundModel, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_update_property_array(this_ptr, SL("boundModels"), &paramKey, &boundModel);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&paramsCache, &paramKey, &className, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "rewind", &_zephir_call_cache[13]);
		zephir_check_call_status();
		_20 = 1;
		while (1) {
			if (_20) {
				_20 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "next", &_zephir_call_cache[14]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_19, _3, "valid", &_zephir_call_cache[15]);
			zephir_check_call_status();
			if (!zend_is_true(&_19)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&paramKey, _3, "key", &_zephir_call_cache[16]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&methodParam, _3, "current", &_zephir_call_cache[17]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&reflectionClass, &methodParam, "getType", &_zephir_call_cache[18]);
				zephir_check_call_status();
				_21$$19 = !zephir_is_true(&reflectionClass);
				if (!(_21$$19)) {
					_21$$19 = !((zephir_is_instance_of(&reflectionClass, SL("ReflectionNamedType"))));
				}
				if (_21$$19) {
					continue;
				}
				ZEPHIR_CALL_METHOD_CACHED(&className, &reflectionClass, "getName", &_zephir_call_cache[19]);
				zephir_check_call_status();
				_22$$19 = zephir_array_isset_value(&params, &paramKey);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_22$$19)) {
					ZEPHIR_OBS_NVAR(&_23$$21);
					zephir_array_fetch(&_23$$21, &paramsKeys, &paramKey, PH_NOISY, "phalcon/Mvc/Model/Binder.zep", 218);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&paramKey, &_23$$21);
				}
				ZEPHIR_INIT_NVAR(&boundModel);
				ZVAL_NULL(&boundModel);
				ZEPHIR_OBS_NVAR(&paramValue);
				zephir_array_fetch(&paramValue, &params, &paramKey, PH_NOISY, "phalcon/Mvc/Model/Binder.zep", 222);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_STRING(&className, "Phalcon\\Mvc\\Model")) {
					if (Z_TYPE_P(&realClasses) == IS_NULL) {
						if (zephir_instance_of_ev(handler, phalcon_mvc_controller_bindmodelinterface_ce)) {
							ZEPHIR_INIT_NVAR(&handlerClass);
							zephir_get_class(&handlerClass, handler, 0);
							_26$$24 = zephir_fetch_class(&handlerClass);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_CE_STATIC_THIS_CACHED(&realClasses, _26$$24, getThis(), "getModelName", &_zephir_call_cache[20]);
							zephir_check_call_status();
						} else if (zephir_instance_of_ev(handler, phalcon_mvc_model_binder_bindableinterface_ce)) {
							ZEPHIR_CALL_METHOD_CACHED(&realClasses, handler, "getModelName", &_zephir_call_cache[21]);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(&_27$$26);
							object_init_ex(&_27$$26, phalcon_mvc_model_exceptions_handlermustimplementbindable_ce);
							zephir_constructor_start(&_27$$26);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_27$$26, "__construct", &_zephir_call_cache[22]);
							zephir_check_call_status();
							zephir_constructor_finish(&_27$$26);
							zephir_throw_exception_debug(&_27$$26, "phalcon/Mvc/Model/Binder.zep", 232);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					if (Z_TYPE_P(&realClasses) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&className);
						_28$$27 = zephir_array_isset_fetch(&className, &realClasses, &paramKey, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(!(_28$$27))) {
							ZEPHIR_INIT_NVAR(&_29$$28);
							object_init_ex(&_29$$28, phalcon_mvc_model_exceptions_missingmodelclassname_ce);
							zephir_constructor_start(&_29$$28);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_29$$28, "__construct", &_zephir_call_cache[23], &paramKey);
							zephir_check_call_status();
							zephir_constructor_finish(&_29$$28);
							zephir_throw_exception_debug(&_29$$28, "phalcon/Mvc/Model/Binder.zep", 238);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(&boundModel, this_ptr, "findBoundModel", &_zephir_call_cache[24], &paramValue, &className);
						zephir_check_call_status();
					} else if (Z_TYPE_P(&realClasses) == IS_STRING) {
						ZEPHIR_CPY_WRT(&className, &realClasses);
						ZEPHIR_CALL_METHOD_CACHED(&boundModel, this_ptr, "findBoundModel", &_zephir_call_cache[25], &paramValue, &className);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&_30$$30);
						object_init_ex(&_30$$30, phalcon_mvc_model_exceptions_invalidgetmodelnamereturn_ce);
						zephir_constructor_start(&_30$$30);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_30$$30, "__construct", &_zephir_call_cache[26]);
						zephir_check_call_status();
						zephir_constructor_finish(&_30$$30);
						zephir_throw_exception_debug(&_30$$30, "phalcon/Mvc/Model/Binder.zep", 246);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_24$$19);
					ZVAL_STRING(&_24$$19, "Phalcon\\Mvc\\Model");
					ZEPHIR_CALL_FUNCTION(&_25$$19, "is_subclass_of", &_13, 41, &className, &_24$$19);
					zephir_check_call_status();
					if (zephir_is_true(&_25$$19)) {
						ZEPHIR_CALL_METHOD_CACHED(&boundModel, this_ptr, "findBoundModel", &_zephir_call_cache[27], &paramValue, &className);
						zephir_check_call_status();
					}
				}
				if (Z_TYPE_P(&boundModel) != IS_NULL) {
					zephir_update_property_array(this_ptr, SL("originalValues"), &paramKey, &paramValue);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&params, &paramKey, &boundModel, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_update_property_array(this_ptr, SL("boundModels"), &paramKey, &boundModel);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&paramsCache, &paramKey, &className, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	if (Z_TYPE_P(&cache) != IS_NULL) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &cache, "set", &_zephir_call_cache[28], &cacheKey_zv, &paramsCache);
		zephir_check_call_status();
	}
	zephir_update_property_array(this_ptr, SL("internalCache"), &cacheKey_zv, &paramsCache);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&params);
}

