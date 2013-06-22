
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


/**
 * Phalcon\Mvc\Model\Behavior\SoftDelete initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Behavior_SoftDelete){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Behavior, SoftDelete, mvc_model_behavior_softdelete, "phalcon\\mvc\\model\\behavior", phalcon_mvc_model_behavior_softdelete_method_entry, 0);

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

	zval *type, *model, *options, *skip, *value, *field, *actual_value;
	zval *update_model, *status, *messages, *message = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &type, &model);
	
	if (PHALCON_IS_STRING(type, "beforeDelete")) {
	
		PHALCON_INIT_VAR(options);
		phalcon_call_method(options, this_ptr, "getoptions");
		if (!phalcon_array_isset_string(options, SS("value"))) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The option 'value' is required");
			return;
		}
	
		if (!phalcon_array_isset_string(options, SS("field"))) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The option 'field' is required");
			return;
		}
	
		PHALCON_INIT_VAR(skip);
		ZVAL_BOOL(skip, 1);
	
		/** 
		 * Skip the current operation
		 */
		phalcon_call_method_p1_noret(model, "skipoperation", skip);
	
		/** 
		 * 'value' is the value to be updated instead of delete the record
		 */
		PHALCON_OBS_VAR(value);
		phalcon_array_fetch_string(&value, options, SL("value"), PH_NOISY_CC);
	
		/** 
		 * 'field' is the attribute to be updated instead of delete the record
		 */
		PHALCON_OBS_VAR(field);
		phalcon_array_fetch_string(&field, options, SL("field"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(actual_value);
		phalcon_call_method_p1(actual_value, model, "readattribute", field);
	
		/** 
		 * If the record is already flagged as 'deleted' we don't delete it again
		 */
		if (!PHALCON_IS_EQUAL(actual_value, value)) {
	
			/** 
			 * Clone the current model to make a clean new operation
			 */
			PHALCON_INIT_VAR(update_model);
			if (phalcon_clone(update_model, model TSRMLS_CC) == FAILURE) {
				return;
			}
			phalcon_call_method_p2_noret(update_model, "writeattribute", field, value);
	
			/** 
			 * Update the cloned model
			 */
			PHALCON_INIT_VAR(status);
			phalcon_call_method(status, update_model, "save");
			if (!zend_is_true(status)) {
	
				/** 
				 * Transfer the messages from the cloned model to the original model
				 */
				PHALCON_INIT_VAR(messages);
				phalcon_call_method(messages, update_model, "getmessages");
	
				phalcon_is_iterable(messages, &ah0, &hp0, 0, 0);
	
				while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
					PHALCON_GET_HVALUE(message);
	
					phalcon_call_method_p1_noret(model, "appendmessage", message);
	
					zend_hash_move_forward_ex(ah0, &hp0);
				}
	
				RETURN_MM_FALSE;
			}
	
			/** 
			 * Update the original model too
			 */
			phalcon_call_method_p2_noret(model, "writeattribute", field, value);
		}
	}
	
	PHALCON_MM_RESTORE();
}

