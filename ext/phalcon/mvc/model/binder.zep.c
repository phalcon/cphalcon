
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
 * Phalcon\Mvc\Model\Binder
 *
 * This is an class for binding models into params for handler
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Binder)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Binder, phalcon, mvc_model_binder, phalcon_mvc_model_binder_method_entry, 0);

	/**
	 * Array for storing active bound models
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_binder_ce, SL("boundModels"), ZEND_ACC_PROTECTED);
	/**
	 * Cache object used for caching parameters for model binding
	 *
	 * @var AdapterInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_model_binder_ce, SL("cache"), ZEND_ACC_PROTECTED);
	/**
	 * Internal cache for caching parameters for model binding during request
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_binder_ce, SL("internalCache"), ZEND_ACC_PROTECTED);
	/**
	 * Array for original values
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_binder_ce, SL("originalValues"), ZEND_ACC_PROTECTED);
	phalcon_mvc_model_binder_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model_Binder;

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
	zephir_update_property_zval(this_ptr, ZEND_STRL("cache"), cache);
}

/**
 * Bind models into params in proper handler
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, bindToHandler)
{
	zend_ulong _5$$4;
	zend_bool _1, _9$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *cacheKey = NULL, *methodName = NULL, *_6$$4;
	zval params;
	zval *handler, handler_sub, *params_param = NULL, cacheKey_zv, methodName_zv, paramKey, className, boundModel, paramsCache, paramValue, _0, _3, _2$$3, *_4$$4, _8$$4;
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
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&params);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("originalValues"), &_0);
	_1 = !((zephir_is_instance_of(handler, SL("Closure"))));
	if (_1) {
		_1 = ZEPHIR_IS_NULL(&methodName_zv);
	}
	if (UNEXPECTED(_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_model_exceptions_missingmethodname_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Mvc/Model/Binder.zep", 78);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_zval(this_ptr, ZEND_STRL("boundModels"), &_3);
	ZEPHIR_CALL_METHOD(&paramsCache, this_ptr, "getparamsfromcache", NULL, 0, &cacheKey_zv);
	zephir_check_call_status();
	if (Z_TYPE_P(&paramsCache) == IS_ARRAY) {
		zephir_is_iterable(&paramsCache, 0, "phalcon/Mvc/Model/Binder.zep", 93);
		if (Z_TYPE_P(&paramsCache) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paramsCache), _5$$4, _6$$4, _4$$4)
			{
				ZEPHIR_INIT_NVAR(&paramKey);
				if (_6$$4 != NULL) { 
					ZVAL_STR_COPY(&paramKey, _6$$4);
				} else {
					ZVAL_LONG(&paramKey, _5$$4);
				}
				ZEPHIR_INIT_NVAR(&className);
				ZVAL_COPY(&className, _4$$4);
				ZEPHIR_OBS_NVAR(&paramValue);
				zephir_array_fetch(&paramValue, &params, &paramKey, PH_NOISY, "phalcon/Mvc/Model/Binder.zep", 86);
				ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_7, 0, &paramValue, &className);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("originalValues"), &paramKey, &paramValue);
				zephir_array_update_zval(&params, &paramKey, &boundModel, PH_COPY | PH_SEPARATE);
				zephir_update_property_array(this_ptr, SL("boundModels"), &paramKey, &boundModel);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &paramsCache, "rewind", NULL, 0);
			zephir_check_call_status();
			_9$$4 = 1;
			while (1) {
				if (_9$$4) {
					_9$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &paramsCache, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_8$$4, &paramsCache, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_8$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&paramKey, &paramsCache, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&className, &paramsCache, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&paramValue);
					zephir_array_fetch(&paramValue, &params, &paramKey, PH_NOISY, "phalcon/Mvc/Model/Binder.zep", 86);
					ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_7, 0, &paramValue, &className);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("originalValues"), &paramKey, &paramValue);
					zephir_array_update_zval(&params, &paramKey, &boundModel, PH_COPY | PH_SEPARATE);
					zephir_update_property_array(this_ptr, SL("boundModels"), &paramKey, &boundModel);
			}
		}
		ZEPHIR_INIT_NVAR(&className);
		ZEPHIR_INIT_NVAR(&paramKey);
		RETURN_CTOR(&params);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getparamsfromreflection", NULL, 0, handler, &params, &cacheKey_zv, &methodName_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return the active bound models
 *
 * @return array
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(cache, phalcon_cache_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &cache);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cache"), cache);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(_0, "findfirst", NULL, 0, paramValue);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get params classes from cache by key
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getParamsFromCache)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval cacheKey_zv, cache, internalParams, _0, _1, _3;
	zend_string *cacheKey = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cacheKey_zv);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&internalParams);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(cacheKey)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&cacheKey_zv);
	ZVAL_STR_COPY(&cacheKey_zv, cacheKey);
	zephir_memory_observe(&internalParams);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("internalCache"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&internalParams, &_0, &cacheKey_zv, 0)) {
		RETURN_CCTOR(&internalParams);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("cache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cache, &_1);
	_2 = Z_TYPE_P(&cache) == IS_NULL;
	if (!(_2)) {
		ZEPHIR_CALL_METHOD(&_3, &cache, "has", NULL, 0, &cacheKey_zv);
		zephir_check_call_status();
		_2 = !zephir_is_true(&_3);
	}
	if (_2) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&internalParams, &cache, "get", NULL, 0, &cacheKey_zv);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("internalCache"), &cacheKey_zv, &internalParams);
	RETURN_CCTOR(&internalParams);
}

/**
 * Get modified params for handler using reflection
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getParamsFromReflection)
{
	zend_class_entry *_9$$10, *_23$$24;
	zend_bool _18, _4$$5, _19$$19;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL, *_13 = NULL, *_14 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *cacheKey = NULL, *methodName = NULL, *_3;
	zval params, paramsCache;
	zval *handler, handler_sub, *params_param = NULL, cacheKey_zv, methodName_zv, methodParams, reflection, paramKey, methodParam, className, realClasses, boundModel, cache, handlerClass, reflectionClass, paramsKeys, paramValue, _0, *_1, _17, _6$$5, _7$$5, _5$$7, _10$$12, _12$$14, _15$$16, _21$$19, _22$$19, _20$$21, _24$$26, _25$$28, _26$$30;
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
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_22$$19);
	ZVAL_UNDEF(&_20$$21);
	ZVAL_UNDEF(&_24$$26);
	ZVAL_UNDEF(&_25$$28);
	ZVAL_UNDEF(&_26$$30);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&paramsCache);
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
	if (!ZEPHIR_IS_NULL(&methodName_zv)) {
		object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionmethod")));
		ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 0, handler, &methodName_zv);
		zephir_check_call_status();
	} else {
		object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionfunction")));
		ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 249, handler);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("cache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cache, &_0);
	ZEPHIR_CALL_METHOD(&methodParams, &reflection, "getparameters", NULL, 250);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&paramsKeys);
	zephir_array_keys(&paramsKeys, &params);
	zephir_is_iterable(&methodParams, 0, "phalcon/Mvc/Model/Binder.zep", 250);
	if (Z_TYPE_P(&methodParams) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&methodParams), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&paramKey);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&paramKey, _3);
			} else {
				ZVAL_LONG(&paramKey, _2);
			}
			ZEPHIR_INIT_NVAR(&methodParam);
			ZVAL_COPY(&methodParam, _1);
			ZEPHIR_CALL_METHOD(&reflectionClass, &methodParam, "gettype", NULL, 0);
			zephir_check_call_status();
			_4$$5 = !zephir_is_true(&reflectionClass);
			if (!(_4$$5)) {
				_4$$5 = !((zephir_is_instance_of(&reflectionClass, SL("ReflectionNamedType"))));
			}
			if (_4$$5) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&className, &reflectionClass, "getname", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_array_isset_value(&params, &paramKey))) {
				zephir_array_fetch(&_5$$7, &paramsKeys, &paramKey, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Binder.zep", 208);
				ZEPHIR_CPY_WRT(&paramKey, &_5$$7);
			}
			ZEPHIR_INIT_NVAR(&boundModel);
			ZVAL_NULL(&boundModel);
			ZEPHIR_OBS_NVAR(&paramValue);
			zephir_array_fetch(&paramValue, &params, &paramKey, PH_NOISY, "phalcon/Mvc/Model/Binder.zep", 212);
			if (ZEPHIR_IS_STRING(&className, "Phalcon\\Mvc\\Model")) {
				if (Z_TYPE_P(&realClasses) == IS_NULL) {
					if (zephir_instance_of_ev(handler, phalcon_mvc_controller_bindmodelinterface_ce)) {
						ZEPHIR_INIT_NVAR(&handlerClass);
						zephir_get_class(&handlerClass, handler, 0);
						_9$$10 = zephir_fetch_class(&handlerClass);
						ZEPHIR_CALL_CE_STATIC(&realClasses, _9$$10, "getmodelname", NULL, 0);
						zephir_check_call_status();
					} else if (zephir_instance_of_ev(handler, phalcon_mvc_model_binder_bindableinterface_ce)) {
						ZEPHIR_CALL_METHOD(&realClasses, handler, "getmodelname", NULL, 0);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&_10$$12);
						object_init_ex(&_10$$12, phalcon_mvc_model_exceptions_handlermustimplementbindable_ce);
						ZEPHIR_CALL_METHOD(NULL, &_10$$12, "__construct", &_11, 0);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_10$$12, "phalcon/Mvc/Model/Binder.zep", 222);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (Z_TYPE_P(&realClasses) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&className);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&className, &realClasses, &paramKey, 0)))) {
						ZEPHIR_INIT_NVAR(&_12$$14);
						object_init_ex(&_12$$14, phalcon_mvc_model_exceptions_missingmodelclassname_ce);
						ZEPHIR_CALL_METHOD(NULL, &_12$$14, "__construct", &_13, 0, &paramKey);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_12$$14, "phalcon/Mvc/Model/Binder.zep", 228);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_14, 0, &paramValue, &className);
					zephir_check_call_status();
				} else if (Z_TYPE_P(&realClasses) == IS_STRING) {
					ZEPHIR_CPY_WRT(&className, &realClasses);
					ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_14, 0, &paramValue, &className);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_15$$16);
					object_init_ex(&_15$$16, phalcon_mvc_model_exceptions_invalidgetmodelnamereturn_ce);
					ZEPHIR_CALL_METHOD(NULL, &_15$$16, "__construct", &_16, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_15$$16, "phalcon/Mvc/Model/Binder.zep", 236);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZVAL_STRING(&_6$$5, "Phalcon\\Mvc\\Model");
				ZEPHIR_CALL_FUNCTION(&_7$$5, "is_subclass_of", &_8, 0, &className, &_6$$5);
				zephir_check_call_status();
				if (zephir_is_true(&_7$$5)) {
					ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_14, 0, &paramValue, &className);
					zephir_check_call_status();
				}
			}
			if (Z_TYPE_P(&boundModel) != IS_NULL) {
				zephir_update_property_array(this_ptr, SL("originalValues"), &paramKey, &paramValue);
				zephir_array_update_zval(&params, &paramKey, &boundModel, PH_COPY | PH_SEPARATE);
				zephir_update_property_array(this_ptr, SL("boundModels"), &paramKey, &boundModel);
				zephir_array_update_zval(&paramsCache, &paramKey, &className, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &methodParams, "rewind", NULL, 0);
		zephir_check_call_status();
		_18 = 1;
		while (1) {
			if (_18) {
				_18 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &methodParams, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_17, &methodParams, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&paramKey, &methodParams, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&methodParam, &methodParams, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&reflectionClass, &methodParam, "gettype", NULL, 0);
				zephir_check_call_status();
				_19$$19 = !zephir_is_true(&reflectionClass);
				if (!(_19$$19)) {
					_19$$19 = !((zephir_is_instance_of(&reflectionClass, SL("ReflectionNamedType"))));
				}
				if (_19$$19) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&className, &reflectionClass, "getname", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_array_isset_value(&params, &paramKey))) {
					zephir_array_fetch(&_20$$21, &paramsKeys, &paramKey, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Binder.zep", 208);
					ZEPHIR_CPY_WRT(&paramKey, &_20$$21);
				}
				ZEPHIR_INIT_NVAR(&boundModel);
				ZVAL_NULL(&boundModel);
				ZEPHIR_OBS_NVAR(&paramValue);
				zephir_array_fetch(&paramValue, &params, &paramKey, PH_NOISY, "phalcon/Mvc/Model/Binder.zep", 212);
				if (ZEPHIR_IS_STRING(&className, "Phalcon\\Mvc\\Model")) {
					if (Z_TYPE_P(&realClasses) == IS_NULL) {
						if (zephir_instance_of_ev(handler, phalcon_mvc_controller_bindmodelinterface_ce)) {
							ZEPHIR_INIT_NVAR(&handlerClass);
							zephir_get_class(&handlerClass, handler, 0);
							_23$$24 = zephir_fetch_class(&handlerClass);
							ZEPHIR_CALL_CE_STATIC(&realClasses, _23$$24, "getmodelname", NULL, 0);
							zephir_check_call_status();
						} else if (zephir_instance_of_ev(handler, phalcon_mvc_model_binder_bindableinterface_ce)) {
							ZEPHIR_CALL_METHOD(&realClasses, handler, "getmodelname", NULL, 0);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(&_24$$26);
							object_init_ex(&_24$$26, phalcon_mvc_model_exceptions_handlermustimplementbindable_ce);
							ZEPHIR_CALL_METHOD(NULL, &_24$$26, "__construct", &_11, 0);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_24$$26, "phalcon/Mvc/Model/Binder.zep", 222);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					if (Z_TYPE_P(&realClasses) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&className);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&className, &realClasses, &paramKey, 0)))) {
							ZEPHIR_INIT_NVAR(&_25$$28);
							object_init_ex(&_25$$28, phalcon_mvc_model_exceptions_missingmodelclassname_ce);
							ZEPHIR_CALL_METHOD(NULL, &_25$$28, "__construct", &_13, 0, &paramKey);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_25$$28, "phalcon/Mvc/Model/Binder.zep", 228);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_14, 0, &paramValue, &className);
						zephir_check_call_status();
					} else if (Z_TYPE_P(&realClasses) == IS_STRING) {
						ZEPHIR_CPY_WRT(&className, &realClasses);
						ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_14, 0, &paramValue, &className);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&_26$$30);
						object_init_ex(&_26$$30, phalcon_mvc_model_exceptions_invalidgetmodelnamereturn_ce);
						ZEPHIR_CALL_METHOD(NULL, &_26$$30, "__construct", &_16, 0);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_26$$30, "phalcon/Mvc/Model/Binder.zep", 236);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_21$$19);
					ZVAL_STRING(&_21$$19, "Phalcon\\Mvc\\Model");
					ZEPHIR_CALL_FUNCTION(&_22$$19, "is_subclass_of", &_8, 0, &className, &_21$$19);
					zephir_check_call_status();
					if (zephir_is_true(&_22$$19)) {
						ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_14, 0, &paramValue, &className);
						zephir_check_call_status();
					}
				}
				if (Z_TYPE_P(&boundModel) != IS_NULL) {
					zephir_update_property_array(this_ptr, SL("originalValues"), &paramKey, &paramValue);
					zephir_array_update_zval(&params, &paramKey, &boundModel, PH_COPY | PH_SEPARATE);
					zephir_update_property_array(this_ptr, SL("boundModels"), &paramKey, &boundModel);
					zephir_array_update_zval(&paramsCache, &paramKey, &className, PH_COPY | PH_SEPARATE);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&methodParam);
	ZEPHIR_INIT_NVAR(&paramKey);
	if (Z_TYPE_P(&cache) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, &cache, "set", NULL, 0, &cacheKey_zv, &paramsCache);
		zephir_check_call_status();
	}
	zephir_update_property_array(this_ptr, SL("internalCache"), &cacheKey_zv, &paramsCache);
	RETURN_CTOR(&params);
}

zend_object *zephir_init_properties_Phalcon_Mvc_Model_Binder(zend_class_entry *class_type)
{
		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("originalValues"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("originalValues"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("internalCache"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("internalCache"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("boundModels"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("boundModels"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

