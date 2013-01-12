
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/array.h"

/**
 * Phalcon\Mvc\Model\Behavior
 *
 * This is an optional base class for ORM behaviors
 */


/**
 * Phalcon\Mvc\Model\Behavior initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Behavior){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Behavior, mvc_model_behavior, phalcon_mvc_model_behavior_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_mvc_model_behavior_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Behavior
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, __construct){

	zval *options = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_options"), options TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks whether the behavior must take action on certain event
 *
 * @param string $eventName
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, mustTakeAction){

	zval *event_name, *options;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &event_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(options);
	phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (phalcon_array_isset(options, event_name)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Returns the behavior options related to an event
 *
 * @param string $eventName
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, getOptions){

	zval *event_name = NULL, *options, *event_options;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &event_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!event_name) {
		PHALCON_INIT_VAR(event_name);
	}
	
	PHALCON_OBS_VAR(options);
	phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(event_name) != IS_NULL) {
		if (phalcon_array_isset(options, event_name)) {
			PHALCON_OBS_VAR(event_options);
			phalcon_array_fetch(&event_options, options, event_name, PH_NOISY_CC);
			RETURN_CCTOR(event_options);
		}
		RETURN_MM_NULL();
	}
	
	
	RETURN_CCTOR(options);
}

/**
 * This method receives the notifications from the EventsManager
 *
 * @param string $type
 * @param Phalcon\Mvc\ModelInterface $model
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, notify){

	zval *type, *model;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &type, &model) == FAILURE) {
		RETURN_NULL();
	}

	RETURN_NULL();
}

/**
 * Acts as fallbacks when a missing method is called on the model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param string $method
 * @param array $arguments
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior, missingMethod){

	zval *model, *method, *arguments = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &model, &method, &arguments) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!arguments) {
		PHALCON_INIT_VAR(arguments);
	}
	
	RETURN_MM_NULL();
}

