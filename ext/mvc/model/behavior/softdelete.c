
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

#include "mvc/model/behavior/softdelete.h"
#include "mvc/model/behavior.h"
#include "mvc/model/behaviorinterface.h"
#include "mvc/model/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/object.h"

/**
 * Phalcon\Mvc\Model\Behavior\SoftDelete
 *
 * Instead of permanently delete a record it marks the record as
 * deleted changing the value of a flag column
 */
zend_class_entry *phalcon_mvc_model_behavior_softdelete_ce;

PHP_METHOD(Phalcon_Mvc_Model_Behavior_SoftDelete, notify);

static const zend_function_entry phalcon_mvc_model_behavior_softdelete_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_Behavior_SoftDelete, notify, arginfo_phalcon_mvc_model_behaviorinterface_notify, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\Behavior\SoftDelete initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Behavior_SoftDelete){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Behavior, SoftDelete, mvc_model_behavior_softdelete, phalcon_mvc_model_behavior_ce, phalcon_mvc_model_behavior_softdelete_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_behavior_softdelete_ce TSRMLS_CC, 1, phalcon_mvc_model_behaviorinterface_ce);

	return SUCCESS;
}

/**
 * Listens for notifications from the models manager
 *
 * @param string $type
 * @param Phalcon\Mvc\ModelInterface $model
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_SoftDelete, notify){

	zval *type, *model, *options = NULL, *value, *field, *actual_value = NULL;
	zval *update_model, *status = NULL, *messages = NULL, *message = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &type, &model);
	
	if (PHALCON_IS_STRING(type, "beforeDelete")) {
		PHALCON_CALL_METHOD(&options, this_ptr, "getoptions");
		if (!phalcon_array_isset_string(options, SS("value"))) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The option 'value' is required");
			return;
		}
	
		if (!phalcon_array_isset_string(options, SS("field"))) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The option 'field' is required");
			return;
		}
	
		/** 
		 * Skip the current operation
		 */
		PHALCON_CALL_METHOD(NULL, model, "skipoperation", PHALCON_GLOBAL(z_true));
	
		/** 
		 * 'value' is the value to be updated instead of delete the record
		 */
		PHALCON_OBS_VAR(value);
		phalcon_array_fetch_string(&value, options, SL("value"), PH_NOISY);
	
		/** 
		 * 'field' is the attribute to be updated instead of delete the record
		 */
		PHALCON_OBS_VAR(field);
		phalcon_array_fetch_string(&field, options, SL("field"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&actual_value, model, "readattribute", field);
	
		/** 
		 * If the record is already flagged as 'deleted' we don't delete it again
		 */
		if (!PHALCON_IS_EQUAL(actual_value, value)) {
	
			/** 
			 * Clone the current model to make a clean new operation
			 */
			PHALCON_INIT_VAR(update_model);
			if (phalcon_clone(update_model, model TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}

			PHALCON_CALL_METHOD(NULL, update_model, "writeattribute", field, value);
	
			/** 
			 * Update the cloned model
			 */
			PHALCON_CALL_METHOD(&status, update_model, "save");
			if (!zend_is_true(status)) {
	
				/** 
				 * Transfer the messages from the cloned model to the original model
				 */
				PHALCON_CALL_METHOD(&messages, update_model, "getmessages");
	
				phalcon_is_iterable(messages, &ah0, &hp0, 0, 0);
	
				while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
					PHALCON_GET_HVALUE(message);
	
					PHALCON_CALL_METHOD(NULL, model, "appendmessage", message);
	
					zend_hash_move_forward_ex(ah0, &hp0);
				}
	
				RETURN_MM_FALSE;
			}
	
			/** 
			 * Update the original model too
			 */
			PHALCON_CALL_METHOD(NULL, model, "writeattribute", field, value);
		}
	}
	
	PHALCON_MM_RESTORE();
}

