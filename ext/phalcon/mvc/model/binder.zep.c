
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
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
 * Array for storing active bound models
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getBoundModels)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "boundModels");
}

/**
 * Array for original values
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getOriginalValues)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "originalValues");
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(cache, phalcon_cache_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	zend_string *_6$$4;
	zend_ulong _5$$4;
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval cacheKey, methodName;
	zval params;
	zval *handler, handler_sub, *params_param = NULL, *cacheKey_param = NULL, *methodName_param = NULL, paramKey, className, boundModel, paramsCache, paramValue, _0, _2, *_3$$4, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&paramKey);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&boundModel);
	ZVAL_UNDEF(&paramsCache);
	ZVAL_UNDEF(&paramValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&cacheKey);
	ZVAL_UNDEF(&methodName);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_OBJECT(handler)
		Z_PARAM_ARRAY(params)
		Z_PARAM_STR(cacheKey)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(methodName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &handler, &params_param, &cacheKey_param, &methodName_param);
	zephir_get_arrval(&params, params_param);
	zephir_get_strval(&cacheKey, cacheKey_param);
	if (!methodName_param) {
		ZEPHIR_INIT_VAR(&methodName);
	} else {
	if (UNEXPECTED(Z_TYPE_P(methodName_param) != IS_STRING && Z_TYPE_P(methodName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'methodName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(methodName_param) == IS_STRING)) {
		zephir_get_strval(&methodName, methodName_param);
	} else {
		ZEPHIR_INIT_VAR(&methodName);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("originalValues"), &_0);
	_1 = !((zephir_is_instance_of(handler, SL("Closure"))));
	if (_1) {
		_1 = ZEPHIR_IS_NULL(&methodName);
	}
	if (UNEXPECTED(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "You must specify methodName for handler or pass Closure as handler", "phalcon/Mvc/Model/Binder.zep", 75);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("boundModels"), &_2);
	ZEPHIR_CALL_METHOD(&paramsCache, this_ptr, "getparamsfromcache", NULL, 0, &cacheKey);
	zephir_check_call_status();
	if (Z_TYPE_P(&paramsCache) == IS_ARRAY) {
		zephir_is_iterable(&paramsCache, 0, "phalcon/Mvc/Model/Binder.zep", 90);
		if (Z_TYPE_P(&paramsCache) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paramsCache), _5$$4, _6$$4, _3$$4)
			{
				ZEPHIR_INIT_NVAR(&paramKey);
				if (_6$$4 != NULL) { 
					ZVAL_STR_COPY(&paramKey, _6$$4);
				} else {
					ZVAL_LONG(&paramKey, _5$$4);
				}
				ZEPHIR_INIT_NVAR(&className);
				ZVAL_COPY(&className, _3$$4);
				ZEPHIR_OBS_NVAR(&paramValue);
				zephir_array_fetch(&paramValue, &params, &paramKey, PH_NOISY, "phalcon/Mvc/Model/Binder.zep", 83);
				ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_7, 0, &paramValue, &className);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("originalValues"), &paramKey, &paramValue);
				zephir_array_update_zval(&params, &paramKey, &boundModel, PH_COPY | PH_SEPARATE);
				zephir_update_property_array(this_ptr, SL("boundModels"), &paramKey, &boundModel);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &paramsCache, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$4, &paramsCache, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&paramKey, &paramsCache, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&className, &paramsCache, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&paramValue);
					zephir_array_fetch(&paramValue, &params, &paramKey, PH_NOISY, "phalcon/Mvc/Model/Binder.zep", 83);
					ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_7, 0, &paramValue, &className);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("originalValues"), &paramKey, &paramValue);
					zephir_array_update_zval(&params, &paramKey, &boundModel, PH_COPY | PH_SEPARATE);
					zephir_update_property_array(this_ptr, SL("boundModels"), &paramKey, &boundModel);
				ZEPHIR_CALL_METHOD(NULL, &paramsCache, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&className);
		ZEPHIR_INIT_NVAR(&paramKey);
		RETURN_CTOR(&params);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getparamsfromreflection", NULL, 0, handler, &params, &cacheKey, &methodName);
	zephir_check_call_status();
	RETURN_MM();
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
	zval className;
	zval *paramValue, paramValue_sub, *className_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&paramValue_sub);
	ZVAL_UNDEF(&className);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(paramValue)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &paramValue, &className_param);
	zephir_get_strval(&className, className_param);


	_0 = zephir_fetch_class(&className);
	ZEPHIR_RETURN_CALL_CE_STATIC(_0, "findfirst", NULL, 0, paramValue);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets cache instance
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getCache)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "cache");
}

/**
 * Get params classes from cache by key
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getParamsFromCache)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cacheKey_param = NULL, cache, internalParams, _0, _1, _3;
	zval cacheKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cacheKey);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&internalParams);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(cacheKey)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cacheKey_param);
	zephir_get_strval(&cacheKey, cacheKey_param);


	ZEPHIR_OBS_VAR(&internalParams);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("internalCache"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&internalParams, &_0, &cacheKey, 0)) {
		RETURN_CCTOR(&internalParams);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("cache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cache, &_1);
	_2 = Z_TYPE_P(&cache) == IS_NULL;
	if (!(_2)) {
		ZEPHIR_CALL_METHOD(&_3, &cache, "has", NULL, 0, &cacheKey);
		zephir_check_call_status();
		_2 = !zephir_is_true(&_3);
	}
	if (_2) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&internalParams, &cache, "get", NULL, 0, &cacheKey);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("internalCache"), &cacheKey, &internalParams);
	RETURN_CCTOR(&internalParams);
}

/**
 * Get modified params for handler using reflection
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getParamsFromReflection)
{
	zend_class_entry *_9$$10, *_17$$24;
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_12 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval cacheKey, methodName;
	zval params, paramsCache;
	zval *handler, handler_sub, *params_param = NULL, *cacheKey_param = NULL, *methodName_param = NULL, methodParams, reflection, paramKey, methodParam, className, realClasses, boundModel, cache, handlerClass, reflectionClass, paramsKeys, paramValue, _0, *_1, _2, _5$$7, _6$$5, _7$$5, _10$$14, _11$$14, _14$$21, _15$$19, _16$$19, _18$$28, _19$$28;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_14$$21);
	ZVAL_UNDEF(&_15$$19);
	ZVAL_UNDEF(&_16$$19);
	ZVAL_UNDEF(&_18$$28);
	ZVAL_UNDEF(&_19$$28);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&paramsCache);
	ZVAL_UNDEF(&cacheKey);
	ZVAL_UNDEF(&methodName);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT(handler)
		Z_PARAM_ARRAY(params)
		Z_PARAM_STR(cacheKey)
		Z_PARAM_STR(methodName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &handler, &params_param, &cacheKey_param, &methodName_param);
	zephir_get_arrval(&params, params_param);
	zephir_get_strval(&cacheKey, cacheKey_param);
	if (UNEXPECTED(Z_TYPE_P(methodName_param) != IS_STRING && Z_TYPE_P(methodName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'methodName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(methodName_param) == IS_STRING)) {
		zephir_get_strval(&methodName, methodName_param);
	} else {
		ZEPHIR_INIT_VAR(&methodName);
	}


	ZEPHIR_INIT_VAR(&realClasses);
	ZVAL_NULL(&realClasses);
	ZEPHIR_INIT_VAR(&paramsCache);
	array_init(&paramsCache);
	ZEPHIR_INIT_VAR(&reflection);
	if (!ZEPHIR_IS_NULL(&methodName)) {
		object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionmethod")));
		ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 0, handler, &methodName);
		zephir_check_call_status();
	} else {
		object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionfunction")));
		ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 168, handler);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("cache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cache, &_0);
	ZEPHIR_CALL_METHOD(&methodParams, &reflection, "getparameters", NULL, 169);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&paramsKeys);
	zephir_array_keys(&paramsKeys, &params);
	zephir_is_iterable(&methodParams, 0, "phalcon/Mvc/Model/Binder.zep", 223);
	if (Z_TYPE_P(&methodParams) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&methodParams), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&paramKey);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&paramKey, _4);
			} else {
				ZVAL_LONG(&paramKey, _3);
			}
			ZEPHIR_INIT_NVAR(&methodParam);
			ZVAL_COPY(&methodParam, _1);
			ZEPHIR_CALL_METHOD(&reflectionClass, &methodParam, "getclass", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&reflectionClass))) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&className, &reflectionClass, "getname", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_array_isset(&params, &paramKey))) {
				zephir_array_fetch(&_5$$7, &paramsKeys, &paramKey, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Binder.zep", 175);
				ZEPHIR_CPY_WRT(&paramKey, &_5$$7);
			}
			ZEPHIR_INIT_NVAR(&boundModel);
			ZVAL_NULL(&boundModel);
			ZEPHIR_OBS_NVAR(&paramValue);
			zephir_array_fetch(&paramValue, &params, &paramKey, PH_NOISY, "phalcon/Mvc/Model/Binder.zep", 179);
			ZEPHIR_INIT_NVAR(&_6$$5);
			ZVAL_STRING(&_6$$5, "Phalcon\\Mvc\\Model");
			ZEPHIR_CALL_FUNCTION(&_7$$5, "is_subclass_of", &_8, 0, &className, &_6$$5);
			zephir_check_call_status();
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
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Handler must implement Phalcon\\Mvc\\Model\\Binder\\BindableInterface in order to use Phalcon\\Mvc\\Model as parameter", "phalcon/Mvc/Model/Binder.zep", 191);
						return;
					}
				}
				if (Z_TYPE_P(&realClasses) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&className);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&className, &realClasses, &paramKey, 0)))) {
						ZEPHIR_INIT_NVAR(&_10$$14);
						object_init_ex(&_10$$14, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_NVAR(&_11$$14);
						ZEPHIR_CONCAT_SVS(&_11$$14, "You should provide model class name for ", &paramKey, " parameter");
						ZEPHIR_CALL_METHOD(NULL, &_10$$14, "__construct", &_12, 31, &_11$$14);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_10$$14, "phalcon/Mvc/Model/Binder.zep", 199);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_13, 0, &paramValue, &className);
					zephir_check_call_status();
				} else if (Z_TYPE_P(&realClasses) == IS_STRING) {
					ZEPHIR_CPY_WRT(&className, &realClasses);
					ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_13, 0, &paramValue, &className);
					zephir_check_call_status();
				} else {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "getModelName should return array or string", "phalcon/Mvc/Model/Binder.zep", 209);
					return;
				}
			} else if (zephir_is_true(&_7$$5)) {
				ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_13, 0, &paramValue, &className);
				zephir_check_call_status();
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
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &methodParams, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&paramKey, &methodParams, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&methodParam, &methodParams, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&reflectionClass, &methodParam, "getclass", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(&reflectionClass))) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&className, &reflectionClass, "getname", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_array_isset(&params, &paramKey))) {
					zephir_array_fetch(&_14$$21, &paramsKeys, &paramKey, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Binder.zep", 175);
					ZEPHIR_CPY_WRT(&paramKey, &_14$$21);
				}
				ZEPHIR_INIT_NVAR(&boundModel);
				ZVAL_NULL(&boundModel);
				ZEPHIR_OBS_NVAR(&paramValue);
				zephir_array_fetch(&paramValue, &params, &paramKey, PH_NOISY, "phalcon/Mvc/Model/Binder.zep", 179);
				ZEPHIR_INIT_NVAR(&_15$$19);
				ZVAL_STRING(&_15$$19, "Phalcon\\Mvc\\Model");
				ZEPHIR_CALL_FUNCTION(&_16$$19, "is_subclass_of", &_8, 0, &className, &_15$$19);
				zephir_check_call_status();
				if (ZEPHIR_IS_STRING(&className, "Phalcon\\Mvc\\Model")) {
					if (Z_TYPE_P(&realClasses) == IS_NULL) {
						if (zephir_instance_of_ev(handler, phalcon_mvc_controller_bindmodelinterface_ce)) {
							ZEPHIR_INIT_NVAR(&handlerClass);
							zephir_get_class(&handlerClass, handler, 0);
							_17$$24 = zephir_fetch_class(&handlerClass);
							ZEPHIR_CALL_CE_STATIC(&realClasses, _17$$24, "getmodelname", NULL, 0);
							zephir_check_call_status();
						} else if (zephir_instance_of_ev(handler, phalcon_mvc_model_binder_bindableinterface_ce)) {
							ZEPHIR_CALL_METHOD(&realClasses, handler, "getmodelname", NULL, 0);
							zephir_check_call_status();
						} else {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Handler must implement Phalcon\\Mvc\\Model\\Binder\\BindableInterface in order to use Phalcon\\Mvc\\Model as parameter", "phalcon/Mvc/Model/Binder.zep", 191);
							return;
						}
					}
					if (Z_TYPE_P(&realClasses) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&className);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&className, &realClasses, &paramKey, 0)))) {
							ZEPHIR_INIT_NVAR(&_18$$28);
							object_init_ex(&_18$$28, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_NVAR(&_19$$28);
							ZEPHIR_CONCAT_SVS(&_19$$28, "You should provide model class name for ", &paramKey, " parameter");
							ZEPHIR_CALL_METHOD(NULL, &_18$$28, "__construct", &_12, 31, &_19$$28);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_18$$28, "phalcon/Mvc/Model/Binder.zep", 199);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_13, 0, &paramValue, &className);
						zephir_check_call_status();
					} else if (Z_TYPE_P(&realClasses) == IS_STRING) {
						ZEPHIR_CPY_WRT(&className, &realClasses);
						ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_13, 0, &paramValue, &className);
						zephir_check_call_status();
					} else {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "getModelName should return array or string", "phalcon/Mvc/Model/Binder.zep", 209);
						return;
					}
				} else if (zephir_is_true(&_16$$19)) {
					ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_13, 0, &paramValue, &className);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&boundModel) != IS_NULL) {
					zephir_update_property_array(this_ptr, SL("originalValues"), &paramKey, &paramValue);
					zephir_array_update_zval(&params, &paramKey, &boundModel, PH_COPY | PH_SEPARATE);
					zephir_update_property_array(this_ptr, SL("boundModels"), &paramKey, &boundModel);
					zephir_array_update_zval(&paramsCache, &paramKey, &className, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &methodParams, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&methodParam);
	ZEPHIR_INIT_NVAR(&paramKey);
	if (Z_TYPE_P(&cache) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, &cache, "set", NULL, 0, &cacheKey, &paramsCache);
		zephir_check_call_status();
	}
	zephir_update_property_array(this_ptr, SL("internalCache"), &cacheKey, &paramsCache);
	RETURN_CTOR(&params);
}

/**
 * Gets cache instance
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, setCache)
{
	zval *cache, cache_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cache_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(cache, phalcon_cache_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &cache);


	zephir_update_property_zval(this_ptr, ZEND_STRL("cache"), cache);
	RETURN_THISW();
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
	

		ZEPHIR_MM_GROW();
	
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

