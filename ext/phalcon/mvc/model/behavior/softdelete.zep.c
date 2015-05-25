
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Mvc\Model\Behavior\SoftDelete
 *
 * Instead of permanently delete a record it marks the record as
 * deleted changing the value of a flag column
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Behavior_SoftDelete) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Behavior, SoftDelete, phalcon, mvc_model_behavior_softdelete, phalcon_mvc_model_behavior_ce, phalcon_mvc_model_behavior_softdelete_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_behavior_softdelete_ce TSRMLS_CC, 1, phalcon_mvc_model_behaviorinterface_ce);
	return SUCCESS;

}

/**
 * Listens for notifications from the models manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_SoftDelete, notify) {

	zephir_fcall_cache_entry *_7 = NULL;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *model, *options = NULL, *value, *field, *updateModel, *message = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL, **_6;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &model);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}


	if (ZEPHIR_IS_STRING(type, "beforeDelete")) {
		ZEPHIR_CALL_METHOD(&options, this_ptr, "getoptions", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(value);
		if (!(zephir_array_isset_string_fetch(&value, options, SS("value"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The option 'value' is required", "phalcon/mvc/model/behavior/softdelete.zep", 51);
			return;
		}
		ZEPHIR_OBS_VAR(field);
		if (!(zephir_array_isset_string_fetch(&field, options, SS("field"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The option 'field' is required", "phalcon/mvc/model/behavior/softdelete.zep", 58);
			return;
		}
		ZEPHIR_INIT_VAR(_0);
		ZVAL_BOOL(_0, 1);
		ZEPHIR_CALL_METHOD(NULL, model, "skipoperation", NULL, 0, _0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1, model, "readattribute", NULL, 0, field);
		zephir_check_call_status();
		if (!ZEPHIR_IS_EQUAL(_1, value)) {
			ZEPHIR_INIT_VAR(updateModel);
			if (zephir_clone(updateModel, model TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD(NULL, updateModel, "writeattribute", NULL, 0, field, value);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_2, updateModel, "save", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(_2))) {
				ZEPHIR_CALL_METHOD(&_3, updateModel, "getmessages", NULL, 0);
				zephir_check_call_status();
				zephir_is_iterable(_3, &_5, &_4, 0, 0, "phalcon/mvc/model/behavior/softdelete.zep", 90);
				for (
				  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
				  ; zephir_hash_move_forward_ex(_5, &_4)
				) {
					ZEPHIR_GET_HVALUE(message, _6);
					ZEPHIR_CALL_METHOD(NULL, model, "appendmessage", &_7, 0, message);
					zephir_check_call_status();
				}
				RETURN_MM_BOOL(0);
			}
			ZEPHIR_CALL_METHOD(NULL, model, "writeattribute", NULL, 0, field, value);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

