
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
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "boundModels");

}

/**
 * Array for original values
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getOriginalValues) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "originalValues");

}

/**
 * Phalcon\Mvc\Model\Binder constructor
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, __construct) {

	zval *cache = NULL, cache_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cache_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 0, 1, &cache);

	if (!cache) {
		cache = &cache_sub;
		cache = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("cache"), cache);

}

/**
 * Gets cache instance
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, setCache) {

	zval *cache, cache_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cache_sub);

	zephir_fetch_params(0, 1, 0, &cache);



	zephir_update_property_zval(this_ptr, SL("cache"), cache);
	RETURN_THISW();

}

/**
 * Sets cache instance
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getCache) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cache");

}

/**
 * Bind models into params in proper handler
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, bindToHandler) {

	zend_string *_5$$4;
	zend_ulong _4$$4;
	zend_bool _1;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval cacheKey, methodName;
	zval params;
	zval *handler, handler_sub, *params_param = NULL, *cacheKey_param = NULL, *methodName_param = NULL, paramKey, className, boundModel, paramsCache, paramValue, _0, _2, *_3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&paramKey);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&boundModel);
	ZVAL_UNDEF(&paramsCache);
	ZVAL_UNDEF(&paramValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&cacheKey);
	ZVAL_UNDEF(&methodName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &handler, &params_param, &cacheKey_param, &methodName_param);

	zephir_get_arrval(&params, params_param);
	zephir_get_strval(&cacheKey, cacheKey_param);
	if (!methodName_param) {
		ZEPHIR_INIT_VAR(&methodName);
		ZVAL_STRING(&methodName, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(methodName_param) != IS_STRING && Z_TYPE_P(methodName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'methodName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(methodName_param) == IS_STRING)) {
		zephir_get_strval(&methodName, methodName_param);
	} else {
		ZEPHIR_INIT_VAR(&methodName);
		ZVAL_EMPTY_STRING(&methodName);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("originalValues"), &_0);
	_1 = !((zephir_instance_of_ev(handler, zend_ce_closure TSRMLS_CC)));
	if (_1) {
		_1 = ZEPHIR_IS_STRING_IDENTICAL(&methodName, "");
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "You must specify methodName for handler or pass Closure as handler", "phalcon/mvc/model/binder.zep", 82);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval(this_ptr, SL("boundModels"), &_2);
	ZEPHIR_CALL_METHOD(&paramsCache, this_ptr, "getparamsfromcache", NULL, 0, &cacheKey);
	zephir_check_call_status();
	if (Z_TYPE_P(&paramsCache) == IS_ARRAY) {
		zephir_is_iterable(&paramsCache, 0, "phalcon/mvc/model/binder.zep", 97);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paramsCache), _4$$4, _5$$4, _3$$4)
		{
			ZEPHIR_INIT_NVAR(&paramKey);
			if (_5$$4 != NULL) { 
				ZVAL_STR_COPY(&paramKey, _5$$4);
			} else {
				ZVAL_LONG(&paramKey, _4$$4);
			}
			ZEPHIR_INIT_NVAR(&className);
			ZVAL_COPY(&className, _3$$4);
			ZEPHIR_OBS_NVAR(&paramValue);
			zephir_array_fetch(&paramValue, &params, &paramKey, PH_NOISY, "phalcon/mvc/model/binder.zep", 90 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_6, 0, &paramValue, &className);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("originalValues"), &paramKey, &paramValue TSRMLS_CC);
			zephir_array_update_zval(&params, &paramKey, &boundModel, PH_COPY | PH_SEPARATE);
			zephir_update_property_array(this_ptr, SL("boundModels"), &paramKey, &boundModel TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, findBoundModel) {

	zend_class_entry *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className;
	zval *paramValue, paramValue_sub, *className_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&paramValue_sub);
	ZVAL_UNDEF(&className);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &paramValue, &className_param);

	zephir_get_strval(&className, className_param);


	_0 = zephir_fetch_class(&className TSRMLS_CC);
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
	zval *cacheKey_param = NULL, cache, internalParams, _0, _1, _3;
	zval cacheKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cacheKey);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&internalParams);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cacheKey_param);

	zephir_get_strval(&cacheKey, cacheKey_param);


	ZEPHIR_OBS_VAR(&internalParams);
	zephir_read_property(&_0, this_ptr, SL("internalCache"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&internalParams, &_0, &cacheKey, 0 TSRMLS_CC)) {
		RETURN_CCTOR(&internalParams);
	}
	zephir_read_property(&_1, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cache, &_1);
	_2 = Z_TYPE_P(&cache) == IS_NULL;
	if (!(_2)) {
		ZEPHIR_CALL_METHOD(&_3, &cache, "exists", NULL, 0, &cacheKey);
		zephir_check_call_status();
		_2 = !zephir_is_true(&_3);
	}
	if (_2) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&internalParams, &cache, "get", NULL, 0, &cacheKey);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("internalCache"), &cacheKey, &internalParams TSRMLS_CC);
	RETURN_CCTOR(&internalParams);

}

/**
 * Get modified params for handler using reflection
 */
PHP_METHOD(Phalcon_Mvc_Model_Binder, getParamsFromReflection) {

	zend_class_entry *_8$$10;
	zend_string *_3;
	zend_ulong _2;
	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval cacheKey, methodName;
	zval params;
	zval *handler, handler_sub, *params_param = NULL, *cacheKey_param = NULL, *methodName_param = NULL, methodParams, reflection, paramKey, methodParam, paramsCache, className, realClasses, boundModel, cache, handlerClass, reflectionClass, paramsKeys, paramValue, _0, *_1, _4$$7, _5$$5, _6$$5, _9$$14, _10$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&methodParams);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&paramKey);
	ZVAL_UNDEF(&methodParam);
	ZVAL_UNDEF(&paramsCache);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&realClasses);
	ZVAL_UNDEF(&boundModel);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&handlerClass);
	ZVAL_UNDEF(&reflectionClass);
	ZVAL_UNDEF(&paramsKeys);
	ZVAL_UNDEF(&paramValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&cacheKey);
	ZVAL_UNDEF(&methodName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &handler, &params_param, &cacheKey_param, &methodName_param);

	zephir_get_arrval(&params, params_param);
	zephir_get_strval(&cacheKey, cacheKey_param);
	if (UNEXPECTED(Z_TYPE_P(methodName_param) != IS_STRING && Z_TYPE_P(methodName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'methodName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(methodName_param) == IS_STRING)) {
		zephir_get_strval(&methodName, methodName_param);
	} else {
		ZEPHIR_INIT_VAR(&methodName);
		ZVAL_EMPTY_STRING(&methodName);
	}


	ZEPHIR_INIT_VAR(&realClasses);
	ZVAL_NULL(&realClasses);
	ZEPHIR_INIT_VAR(&paramsCache);
	array_init(&paramsCache);
	ZEPHIR_INIT_VAR(&reflection);
	if (!ZEPHIR_IS_STRING(&methodName, "")) {
		object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionmethod")));
		ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 328, handler, &methodName);
		zephir_check_call_status();
	} else {
		object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionfunction")));
		ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 76, handler);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cache, &_0);
	ZEPHIR_CALL_METHOD(&methodParams, &reflection, "getparameters", NULL, 77);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&paramsKeys);
	zephir_array_keys(&paramsKeys, &params TSRMLS_CC);
	zephir_is_iterable(&methodParams, 0, "phalcon/mvc/model/binder.zep", 207);
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
		ZEPHIR_CALL_METHOD(&reflectionClass, &methodParam, "getclass", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&reflectionClass))) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&className, &reflectionClass, "getname", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_array_isset(&params, &paramKey))) {
			zephir_array_fetch(&_4$$7, &paramsKeys, &paramKey, PH_NOISY | PH_READONLY, "phalcon/mvc/model/binder.zep", 165 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&paramKey, &_4$$7);
		}
		ZEPHIR_INIT_NVAR(&boundModel);
		ZVAL_NULL(&boundModel);
		ZEPHIR_OBS_NVAR(&paramValue);
		zephir_array_fetch(&paramValue, &params, &paramKey, PH_NOISY, "phalcon/mvc/model/binder.zep", 169 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "Phalcon\\Mvc\\Model");
		ZEPHIR_CALL_FUNCTION(&_6$$5, "is_subclass_of", &_7, 329, &className, &_5$$5);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(&className, "Phalcon\\Mvc\\Model")) {
			if (Z_TYPE_P(&realClasses) == IS_NULL) {
				if (zephir_instance_of_ev(handler, phalcon_mvc_controller_bindmodelinterface_ce TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(&handlerClass);
					zephir_get_class(&handlerClass, handler, 0 TSRMLS_CC);
					_8$$10 = zephir_fetch_class(&handlerClass TSRMLS_CC);
					ZEPHIR_CALL_CE_STATIC(&realClasses, _8$$10, "getmodelname", NULL, 0);
					zephir_check_call_status();
				} else if (zephir_instance_of_ev(handler, phalcon_mvc_model_binder_bindableinterface_ce TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&realClasses, handler, "getmodelname", NULL, 0);
					zephir_check_call_status();
				} else {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Handler must implement Phalcon\\Mvc\\Model\\Binder\\BindableInterface in order to use Phalcon\\Mvc\\Model as parameter", "phalcon/mvc/model/binder.zep", 179);
					return;
				}
			}
			if (Z_TYPE_P(&realClasses) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&className);
				if (!(zephir_array_isset_fetch(&className, &realClasses, &paramKey, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(&_9$$14);
					object_init_ex(&_9$$14, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_10$$14);
					ZEPHIR_CONCAT_SVS(&_10$$14, "You should provide model class name for ", &paramKey, " parameter");
					ZEPHIR_CALL_METHOD(NULL, &_9$$14, "__construct", &_11, 4, &_10$$14);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_9$$14, "phalcon/mvc/model/binder.zep", 185 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_12, 0, &paramValue, &className);
				zephir_check_call_status();
			} else if (Z_TYPE_P(&realClasses) == IS_STRING) {
				ZEPHIR_CPY_WRT(&className, &realClasses);
				ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_12, 0, &paramValue, &className);
				zephir_check_call_status();
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "getModelName should return array or string", "phalcon/mvc/model/binder.zep", 193);
				return;
			}
		} else if (zephir_is_true(&_6$$5)) {
			ZEPHIR_CALL_METHOD(&boundModel, this_ptr, "findboundmodel", &_12, 0, &paramValue, &className);
			zephir_check_call_status();
		}
		if (Z_TYPE_P(&boundModel) != IS_NULL) {
			zephir_update_property_array(this_ptr, SL("originalValues"), &paramKey, &paramValue TSRMLS_CC);
			zephir_array_update_zval(&params, &paramKey, &boundModel, PH_COPY | PH_SEPARATE);
			zephir_update_property_array(this_ptr, SL("boundModels"), &paramKey, &boundModel TSRMLS_CC);
			zephir_array_update_zval(&paramsCache, &paramKey, &className, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&methodParam);
	ZEPHIR_INIT_NVAR(&paramKey);
	if (Z_TYPE_P(&cache) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, &cache, "save", NULL, 0, &cacheKey, &paramsCache);
		zephir_check_call_status();
	}
	zephir_update_property_array(this_ptr, SL("internalCache"), &cacheKey, &paramsCache TSRMLS_CC);
	RETURN_CTOR(&params);

}

zend_object *zephir_init_properties_Phalcon_Mvc_Model_Binder(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
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
		zephir_read_property(&_0, this_ptr, SL("originalValues"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("originalValues"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("internalCache"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("internalCache"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("boundModels"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("boundModels"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

