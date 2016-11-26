
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * Phalcon\Mvc\Model\Behavior
 *
 * This is an optional base class for ORM behaviors
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Behavior) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Behavior, phalcon, mvc_model_behavior, phalcon_mvc_model_behavior_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_mvc_model_behavior_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_behavior_ce TSRMLS_CC, 1, phalcon_mvc_model_behaviorinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Behavior
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, __construct) {

	zval *options = NULL, options_sub, __$null;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 0, 1, &options);

	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("_options"), options);

}

/**
 * Checks whether the behavior must take action on certain event
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, mustTakeAction) {

	zval *eventName_param = NULL, _0;
	zval eventName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

	if (unlikely(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(&eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(&eventName);
		ZVAL_EMPTY_STRING(&eventName);
	}


	zephir_read_property(&_0, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &eventName));

}

/**
 * Returns the behavior options related to an event
 *
 * @param string eventName
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, getOptions) {

	zval *eventName_param = NULL, options, eventOptions;
	zval eventName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&eventOptions);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &eventName_param);

	if (!eventName_param) {
		ZEPHIR_INIT_VAR(&eventName);
		ZVAL_STRING(&eventName, "");
	} else {
	if (unlikely(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(&eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(&eventName);
		ZVAL_EMPTY_STRING(&eventName);
	}
	}


	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&eventName, "")) {
		if (zephir_array_isset_fetch(&eventOptions, &options, &eventName, 1 TSRMLS_CC)) {
			RETURN_CTOR(eventOptions);
		}
		RETURN_MM_NULL();
	}
	RETURN_CTOR(options);

}

/**
 * This method receives the notifications from the EventsManager
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, notify) {

	zval *type_param = NULL, *model, model_sub;
	zval type;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&model_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &model);

	zephir_get_strval(&type, type_param);


	RETURN_MM_NULL();

}

/**
 * Acts as fallbacks when a missing method is called on the model
 *
 * @param \Phalcon\Mvc\ModelInterface model
 * @param string method
 * @param array arguments
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, missingMethod) {

	zval method;
	zval *model, model_sub, *method_param = NULL, *arguments = NULL, arguments_sub, __$null;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&method);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &model, &method_param, &arguments);

	zephir_get_strval(&method, method_param);
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}


	RETURN_MM_NULL();

}

