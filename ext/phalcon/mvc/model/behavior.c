
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
#include "kernel/operators.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Mvc\Model\Behavior
 *
 * This is an optional base class for ORM behaviors
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Behavior) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Behavior, phalcon, mvc_model_behavior, phalcon_mvc_model_behavior_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_behavior_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Behavior
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, __construct) {

	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	}


	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks whether the behavior must take action on certain event
 *
 * @param string eventName
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, mustTakeAction) {

	zval *eventName, *options;

	zephir_fetch_params(0, 1, 0, &eventName);



	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(options, eventName));

}

/**
 * Returns the behavior options related to an event
 *
 * @param string eventName
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, getOptions) {

	zval *eventName_param = NULL, *options, *eventOptions;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &eventName_param);

	if (!eventName_param) {
		ZEPHIR_INIT_VAR(eventName);
		ZVAL_EMPTY_STRING(eventName);
	} else {
		zephir_get_strval(eventName, eventName_param);
	}


	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!ZEPHIR_IS_STRING(eventName, "")) {
		if (zephir_array_isset_fetch(&eventOptions, options, eventName, 1 TSRMLS_CC)) {
			ZEPHIR_MM_RESTORE();
			RETURN_ZVAL(eventOptions, 1, 0);
		}
		RETURN_MM_NULL();
	}
	ZEPHIR_MM_RESTORE();
	RETURN_ZVAL(options, 1, 0);

}

/**
 * This method receives the notifications from the EventsManager
 *
 * @param string type
 * @param Phalcon\Mvc\ModelInterface model
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, notify) {

	zval *type_param = NULL, *model;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &model);

		zephir_get_strval(type, type_param);


	RETURN_MM_NULL();

}

/**
 * Acts as fallbacks when a missing method is called on the model
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param string method
 * @param array arguments
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, missingMethod) {

	zval *method = NULL;
	zval *model, *method_param = NULL, *arguments = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &model, &method_param, &arguments);

		zephir_get_strval(method, method_param);
	if (!arguments) {
		ZEPHIR_CPY_WRT(arguments, ZEPHIR_GLOBAL(global_null));
	}


	RETURN_MM_NULL();

}

