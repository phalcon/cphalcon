
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
#include "kernel/operators.h"
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
 * Phalcon\Mvc\Model\Behavior
 *
 * This is an optional base class for ORM behaviors
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Behavior)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Behavior, phalcon, mvc_model_behavior, phalcon_mvc_model_behavior_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_behavior_ce, SL("options"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_mvc_model_behavior_ce, 1, phalcon_mvc_model_behaviorinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Behavior
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the behavior options related to an event
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, getOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval eventName_zv, options, eventOptions, _0;
	zend_string *eventName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName_zv);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&eventOptions);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(eventName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!eventName) {
		ZEPHIR_INIT_VAR(&eventName_zv);
	} else {
	zephir_memory_observe(&eventName_zv);
	ZVAL_STR_COPY(&eventName_zv, eventName);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	if (!ZEPHIR_IS_NULL(&eventName_zv)) {
		zephir_memory_observe(&eventOptions);
		if (!(zephir_array_isset_fetch(&eventOptions, &options, &eventName_zv, 0))) {
			RETURN_MM_NULL();
		}
		RETURN_CCTOR(&eventOptions);
	}
	RETURN_CCTOR(&options);
}

/**
 * Acts as fallbacks when a missing method is called on the model
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, missingMethod)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval arguments;
	zend_string *method = NULL;
	zval *model, model_sub, method_zv, *arguments_param = NULL;

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&arguments);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
		Z_PARAM_STR(method)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(arguments, arguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	model = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		arguments_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZVAL_STR(&method_zv, method);
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
		zephir_get_arrval(&arguments, arguments_param);
	}
	RETURN_MM_NULL();
}

/**
 * Checks whether the behavior must take action on certain event
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, mustTakeAction)
{
	zval eventName_zv, _0;
	zend_string *eventName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(eventName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&eventName_zv, eventName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &eventName_zv));
}

/**
 * This method receives the notifications from the EventsManager
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, notify)
{
	zval type_zv, *model, model_sub;
	zend_string *type = NULL;

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&model_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	model = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&type_zv, type);
	RETURN_NULL();
}

