
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/object.h"

/**
 * Phalcon\Mvc\Model\Behavior\Timestampable
 *
 * Allows to automatically update a model’s attribute saving the
 * datetime when a record is created or updated
 */


/**
 * Phalcon\Mvc\Model\Behavior\Timestampable initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Behavior_Timestampable){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Behavior, Timestampable, mvc_model_behavior_timestampable, "phalcon\\mvc\\model\\behavior", phalcon_mvc_model_behavior_timestampable_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_behavior_timestampable_ce TSRMLS_CC, 1, phalcon_mvc_model_behaviorinterface_ce);

	return SUCCESS;
}

/**
 * Listens for notifications from the models manager
 *
 * @param string $type
 * @param Phalcon\Mvc\ModelInterface $model
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_Timestampable, notify){

	zval *type, *model, *take_action, *options, *timestamp = NULL;
	zval *format, *generator, *field;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &type, &model) == FAILURE) {
		RETURN_MM_NULL();
	}

	/** 
	 * Check if the developer decided to take action here
	 */
	PHALCON_INIT_VAR(take_action);
	PHALCON_CALL_METHOD_PARAMS_1(take_action, this_ptr, "musttakeaction", type);
	if (PHALCON_IS_NOT_TRUE(take_action)) {
		RETURN_MM_NULL();
	}
	
	PHALCON_INIT_VAR(options);
	PHALCON_CALL_METHOD_PARAMS_1(options, this_ptr, "getoptions", type);
	if (Z_TYPE_P(options) == IS_ARRAY) { 
	
		/** 
		 * The field name is required in this behavior
		 */
		if (!phalcon_array_isset_string(options, SS("field"))) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The option 'field' is required");
			return;
		}
	
		PHALCON_INIT_VAR(timestamp);
		if (phalcon_array_isset_string(options, SS("format"))) {
			/** 
			 * Format is a format for date()
			 */
			PHALCON_OBS_VAR(format);
			phalcon_array_fetch_string(&format, options, SL("format"), PH_NOISY_CC);
	
			PHALCON_CALL_FUNC_PARAMS_1(timestamp, "date", format);
		} else {
			if (phalcon_array_isset_string(options, SS("generator"))) {
	
				/** 
				 * A generator is a closure that produce the correct timestamp value
				 */
				PHALCON_OBS_VAR(generator);
				phalcon_array_fetch_string(&generator, options, SL("generator"), PH_NOISY_CC);
				if (Z_TYPE_P(generator) == IS_OBJECT) {
					if (phalcon_is_instance_of(generator, SL("Closure") TSRMLS_CC)) {
						PHALCON_INIT_NVAR(timestamp);
						PHALCON_CALL_USER_FUNC(timestamp, generator);
					}
				}
			}
		}
	
		/** 
		 * Last resort call time()
		 */
		if (Z_TYPE_P(timestamp) == IS_NULL) {
			PHALCON_INIT_NVAR(timestamp);
			ZVAL_LONG(timestamp, (long) time(NULL));
		}
	
		PHALCON_OBS_VAR(field);
		phalcon_array_fetch_string(&field, options, SL("field"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(model, "writeattribute", field, timestamp);
	}
	
	PHALCON_MM_RESTORE();
}

