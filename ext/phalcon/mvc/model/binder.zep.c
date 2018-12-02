
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * Phalcon\Mvc\Model\Binding
 *
 * This is an class for binding models into params for handler
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Binder) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Binder, phalcon, mvc_model_binder, phalcon_mvc_model_binder_method_entry, 0);

	/**
	 * Array for storing active bound models
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_binder_ce, SL("boundModels"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Cache object used for caching parameters for model binding
	 */
	zend_declare_property_null(phalcon_mvc_model_binder_ce, SL("cache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Internal cache for caching parameters for model binding during request
	 */
	zend_declare_property_null(phalcon_mvc_model_binder_ce, SL("internalCache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Array for original values
	 */
	zend_declare_property_null(phalcon_mvc_model_binder_ce, SL("originalValues"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_mvc_model_binder_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model_Binder;

	zend_class_implements(phalcon_mvc_model_binder_ce TSRMLS_CC, 1, phalcon_mvc_model_binderinterface_ce);
	return SUCCESS;

}

/**
 * Array for storing active bound models
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getBoundModels) {

	

	RETURN_MEMBER(getThis(), "boundModels");

}

/**
 * Array for original values
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getOriginalValues) {

	

	RETURN_MEMBER(getThis(), "originalValues");

}

/**
 * Phalcon\Mvc\Model\Binder constructor
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, __construct) {

	zval *cache = NULL;

	zephir_fetch_params(0, 0, 1, &cache);

	if (!cache) {
		cache = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(getThis(), SL("cache"), cache TSRMLS_CC);

}

/**
 * Gets cache instance
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, setCache) {

	zval *cache;

	zephir_fetch_params(0, 1, 0, &cache);



	zephir_update_property_this(getThis(), SL("cache"), cache TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets cache instance
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getCache) {

	

	RETURN_MEMBER(getThis(), "cache");

}

/**
 * Bind models into params in proper handler
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, bindToHandler) {

	HashTable *_4$$4;
	HashPosition _3$$4;
	zend_bool _1;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cacheKey = NULL;
	zval *params = NULL;
	zval *handler, *params_param = NULL, *cacheKey_param = NULL, *methodName = NULL, *paramKey = NULL, *className = NULL, *boundModel = NULL, *paramsCache = NULL, *paramValue = NULL, *_0, *_2$$3, **_5$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &handler, &params_param, &cacheKey_param, &methodName);

	zephir_get_arrval(params, params_param);
	zephir_get_strval(cacheKey, cacheKey_param);
	if (!methodName) {
		methodName = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(getThis(), SL("originalValues"), _0 TSRMLS_CC);
	_1 = zephir_instance_of_ev(handler, zend_ce_closure TSRMLS_CC);
	if (!(_1)) {
		_1 = Z_TYPE_P(methodName) != IS_NULL;
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_2$$3);
		array_init(_2$$3);
		zephir_update_property_this(getThis(), SL("boundModels"), _2$$3 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&paramsCache, this_ptr, "getparamsfromcache", NULL, 0, cacheKey);
		zephir_check_call_status();
		if (Z_TYPE_P(paramsCache) == IS_ARRAY) {
			zephir_is_iterable(paramsCache, &_4$$4, &_3$$4, 0, 0, "phalcon/mvc/model/binder.zep", 103);
			for (
			  ; zend_hash_get_current_data_ex(_4$$4, (void**) &_5$$4, &_3$$4) == SUCCESS
			  ; zend_hash_move_forward_ex(_4$$4, &_3$$4)
			) {
				ZEPHIR_GET_HMKEY(paramKey, _4$$4, _3$$4);
				ZEPHIR_GET_HVALUE(className, _5$$4);
				ZEPHIR_OBS_NVAR(paramValue);
				zephir_array_fetch(&paramValue, params, paramKey, PH_NOISY, "phalcon/mvc/model/binder.zep", 96 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_6, 0, paramValue, className);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("originalValues"), paramKey, paramValue TSRMLS_CC);
				zephir_array_update_zval(&params, paramKey, &boundModel, PH_COPY | PH_SEPARATE);
				zephir_update_property_array(this_ptr, SL("boundModels"), paramKey, boundModel TSRMLS_CC);
			}
			RETURN_CTOR(params);
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getparamsfromreflection", NULL, 0, handler, params, cacheKey, methodName);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "You must specify methodName for handler or pass Closure as handler", "phalcon/mvc/model/binder.zep", 108);
	return;

}

/**
 * Find the model by param value.
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, findBoundModel) {

	zend_class_entry *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className = NULL;
	zval *paramValue, *className_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &paramValue, &className_param);

	zephir_get_strval(className, className_param);


	_0 = zephir_fetch_class(className TSRMLS_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC(_0, "findfirst", NULL, 0, paramValue);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Get params classes from cache by key
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getParamsFromCache) {

	zend_bool _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cacheKey_param = NULL, *cache = NULL, *internalParams = NULL, *_0, *_1, *_3 = NULL;
	zval *cacheKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cacheKey_param);

	zephir_get_strval(cacheKey, cacheKey_param);


	ZEPHIR_OBS_VAR(internalParams);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("internalCache"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&internalParams, _0, cacheKey, 0 TSRMLS_CC)) {
		RETURN_CCTOR(internalParams);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("cache"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(cache, _1);
	_2 = Z_TYPE_P(cache) != IS_NULL;
	if (_2) {
		ZEPHIR_CALL_METHOD(&_3, cache, "exists", NULL, 0, cacheKey);
		zephir_check_call_status();
		_2 = zephir_is_true(_3);
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(&internalParams, cache, "get", NULL, 0, cacheKey);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("internalCache"), cacheKey, internalParams TSRMLS_CC);
		RETURN_CCTOR(internalParams);
	}
	RETURN_MM_NULL();

}

/**
 * Get modified params for handler using reflection
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getParamsFromReflection) {

	zend_class_entry *_8$$10;
	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_7 = NULL, *_9 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cacheKey = NULL;
	zval *params = NULL;
	zval *handler, *params_param = NULL, *cacheKey_param = NULL, *methodName, *methodParams = NULL, *reflection = NULL, *paramKey = NULL, *methodParam = NULL, *paramsCache = NULL, *className = NULL, *realClasses = NULL, *boundModel = NULL, *cache = NULL, *handlerClass = NULL, *reflectionClass = NULL, *paramsKeys = NULL, *paramValue = NULL, *_0, **_3, *_4$$7, _5$$5 = zval_used_for_init, *_6$$5 = NULL, *_10$$15 = NULL, *_11$$15 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &handler, &params_param, &cacheKey_param, &methodName);

	zephir_get_arrval(params, params_param);
	zephir_get_strval(cacheKey, cacheKey_param);


	ZEPHIR_INIT_VAR(realClasses);
	ZVAL_NULL(realClasses);
	ZEPHIR_INIT_VAR(paramsCache);
	array_init(paramsCache);
	ZEPHIR_INIT_VAR(reflection);
	if (Z_TYPE_P(methodName) != IS_NULL) {
		object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionmethod") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", NULL, 342, handler, methodName);
		zephir_check_call_status();
	} else {
		object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionfunction") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", NULL, 87, handler);
		zephir_check_call_status();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("cache"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(cache, _0);
	ZEPHIR_CALL_METHOD(&methodParams, reflection, "getparameters", NULL, 88);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(paramsKeys);
	zephir_array_keys(paramsKeys, params TSRMLS_CC);
	zephir_is_iterable(methodParams, &_2, &_1, 0, 0, "phalcon/mvc/model/binder.zep", 209);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(paramKey, _2, _1);
		ZEPHIR_GET_HVALUE(methodParam, _3);
		ZEPHIR_CALL_METHOD(&reflectionClass, methodParam, "getclass", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(reflectionClass))) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&className, reflectionClass, "getname", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_array_isset(params, paramKey))) {
			zephir_array_fetch(&_4$$7, paramsKeys, paramKey, PH_NOISY | PH_READONLY, "phalcon/mvc/model/binder.zep", 169 TSRMLS_CC);
			ZEPHIR_CPY_WRT(paramKey, _4$$7);
		}
		ZEPHIR_INIT_NVAR(boundModel);
		ZVAL_NULL(boundModel);
		ZEPHIR_OBS_NVAR(paramValue);
		zephir_array_fetch(&paramValue, params, paramKey, PH_NOISY, "phalcon/mvc/model/binder.zep", 172 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_5$$5);
		ZVAL_STRING(&_5$$5, "Phalcon\\Mvc\\Model", 0);
		ZEPHIR_CALL_FUNCTION(&_6$$5, "is_subclass_of", &_7, 343, className, &_5$$5);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(className, "Phalcon\\Mvc\\Model")) {
			if (Z_TYPE_P(realClasses) == IS_NULL) {
				if (zephir_instance_of_ev(handler, phalcon_mvc_controller_bindmodelinterface_ce TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(handlerClass);
					zephir_get_class(handlerClass, handler, 0 TSRMLS_CC);
					_8$$10 = zephir_fetch_class(handlerClass TSRMLS_CC);
					ZEPHIR_CALL_CE_STATIC(&realClasses, _8$$10, "getmodelname", NULL, 0);
					zephir_check_call_status();
				} else if (zephir_instance_of_ev(handler, phalcon_mvc_model_binder_bindableinterface_ce TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&realClasses, handler, "getmodelname", NULL, 0);
					zephir_check_call_status();
				} else {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Handler must implement Phalcon\\Mvc\\Model\\Binder\\BindableInterface in order to use Phalcon\\Mvc\\Model as parameter", "phalcon/mvc/model/binder.zep", 182);
					return;
				}
			}
			if (Z_TYPE_P(realClasses) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(className);
				if (zephir_array_isset_fetch(&className, realClasses, paramKey, 0 TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_9, 0, paramValue, className);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(_10$$15);
					object_init_ex(_10$$15, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_11$$15);
					ZEPHIR_CONCAT_SVS(_11$$15, "You should provide model class name for ", paramKey, " parameter");
					ZEPHIR_CALL_METHOD(NULL, _10$$15, "__construct", &_12, 9, _11$$15);
					zephir_check_call_status();
					zephir_throw_exception_debug(_10$$15, "phalcon/mvc/model/binder.zep", 189 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (Z_TYPE_P(realClasses) == IS_STRING) {
				ZEPHIR_CPY_WRT(className, realClasses);
				ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_9, 0, paramValue, className);
				zephir_check_call_status();
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "getModelName should return array or string", "phalcon/mvc/model/binder.zep", 195);
				return;
			}
		} else if (zephir_is_true(_6$$5)) {
			ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_9, 0, paramValue, className);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(boundModel) != IS_NULL) {
			zephir_update_property_array(this_ptr, SL("originalValues"), paramKey, paramValue TSRMLS_CC);
			zephir_array_update_zval(&params, paramKey, &boundModel, PH_COPY | PH_SEPARATE);
			zephir_update_property_array(this_ptr, SL("boundModels"), paramKey, boundModel TSRMLS_CC);
			zephir_array_update_zval(&paramsCache, paramKey, &className, PH_COPY | PH_SEPARATE);
		}
	}
	if (Z_TYPE_P(cache) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, cache, "save", NULL, 0, cacheKey, paramsCache);
		zephir_check_call_status();
	}
	zephir_update_property_array(this_ptr, SL("internalCache"), cacheKey, paramsCache TSRMLS_CC);
	RETURN_CTOR(params);

}

zend_object_value zephir_init_properties_Phalcon_Mvc_Model_Binder(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_4, *_1$$3, *_3$$4, *_5$$5;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("originalValues"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("originalValues"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("internalCache"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(getThis(), SL("internalCache"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("boundModels"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(getThis(), SL("boundModels"), _5$$5 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

