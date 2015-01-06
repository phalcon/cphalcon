
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/model/behavior/timestampable.h"
#include "mvc/model/behavior.h"
#include "mvc/model/behaviorinterface.h"
#include "mvc/model/exception.h"

#include <Zend/zend_closures.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/string.h"

/**
 * Phalcon\Mvc\Model\Behavior\Timestampable
 *
 * Allows to automatically update a model’s attribute saving the
 * datetime when a record is created or updated
 */
zend_class_entry *phalcon_mvc_model_behavior_timestampable_ce;

PHP_METHOD(Phalcon_Mvc_Model_Behavior_Timestampable, notify);

static const zend_function_entry phalcon_mvc_model_behavior_timestampable_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_Behavior_Timestampable, notify, arginfo_phalcon_mvc_model_behaviorinterface_notify, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\Behavior\Timestampable initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Behavior_Timestampable){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Behavior, Timestampable, mvc_model_behavior_timestampable, phalcon_mvc_model_behavior_ce, phalcon_mvc_model_behavior_timestampable_method_entry, 0);

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

	zval *type, *model, *take_action = NULL, *options = NULL, *timestamp = NULL;
	zval *format, *generator, *field, *single_field = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &type, &model);
	
	/** 
	 * Check if the developer decided to take action here
	 */
	PHALCON_CALL_METHOD(&take_action, this_ptr, "musttakeaction", type);
	if (PHALCON_IS_NOT_TRUE(take_action)) {
		RETURN_MM_NULL();
	}
	
	PHALCON_CALL_METHOD(&options, this_ptr, "getoptions", type);
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
			phalcon_array_fetch_string(&format, options, SL("format"), PH_NOISY);
	
			phalcon_date(timestamp, format, NULL TSRMLS_CC);
		} else if (phalcon_array_isset_string(options, SS("generator"))) {
			/**
			 * A generator is a closure that produce the correct timestamp value
			 */
			PHALCON_OBS_VAR(generator);
			phalcon_array_fetch_string(&generator, options, SL("generator"), PH_NOISY);
			if (Z_TYPE_P(generator) == IS_OBJECT) {
				if (instanceof_function(Z_OBJCE_P(generator), zend_ce_closure TSRMLS_CC)) {
					PHALCON_INIT_NVAR(timestamp);/**/
					PHALCON_CALL_USER_FUNC(timestamp, generator);
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
		phalcon_array_fetch_string(&field, options, SL("field"), PH_NOISY);
	
		/** 
		 * Assign the value to the field, use writeattribute if the property is protected
		 */
		if (unlikely(Z_TYPE_P(field) == IS_ARRAY)) { 
	
			phalcon_is_iterable(field, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HVALUE(single_field);
	
				PHALCON_CALL_METHOD(NULL, model, "writeattribute", single_field, timestamp);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		} else {
			PHALCON_CALL_METHOD(NULL, model, "writeattribute", field, timestamp);
		}
	}
	
	PHALCON_MM_RESTORE();
}
