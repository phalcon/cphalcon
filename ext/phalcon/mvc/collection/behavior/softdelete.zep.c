
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
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Mvc\Collection\Behavior\SoftDelete
 *
 * Instead of permanently delete a record it marks the record as
 * deleted changing the value of a flag column
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_Behavior_SoftDelete) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Collection\\Behavior, SoftDelete, phalcon, mvc_collection_behavior_softdelete, phalcon_mvc_collection_behavior_ce, phalcon_mvc_collection_behavior_softdelete_method_entry, 0);

	return SUCCESS;

}

/**
 * Listens for notifications from the models manager
 */
PHP_METHOD(Phalcon_Mvc_Collection_Behavior_SoftDelete, notify) {

	HashTable *_5$$7;
	HashPosition _4$$7;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *model, *options = NULL, *value = NULL, *field = NULL, *updateModel = NULL, *message = NULL, *_0$$3, *_1$$3 = NULL, *_2$$6 = NULL, *_3$$7 = NULL, **_6$$7;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &model);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "The option 'value' is required", "phalcon/mvc/collection/behavior/softdelete.zep", 50);
			return;
		}
		ZEPHIR_OBS_VAR(field);
		if (!(zephir_array_isset_string_fetch(&field, options, SS("field"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "The option 'field' is required", "phalcon/mvc/collection/behavior/softdelete.zep", 57);
			return;
		}
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_BOOL(_0$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, model, "skipoperation", NULL, 0, _0$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, model, "readattribute", NULL, 0, field);
		zephir_check_call_status();
		if (!ZEPHIR_IS_EQUAL(_1$$3, value)) {
			ZEPHIR_INIT_VAR(updateModel);
			if (zephir_clone(updateModel, model TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD(NULL, updateModel, "writeattribute", NULL, 0, field, value);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_2$$6, updateModel, "save", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(_2$$6))) {
				ZEPHIR_CALL_METHOD(&_3$$7, updateModel, "getmessages", NULL, 0);
				zephir_check_call_status();
				zephir_is_iterable(_3$$7, &_5$$7, &_4$$7, 0, 0, "phalcon/mvc/collection/behavior/softdelete.zep", 89);
				for (
				  ; zend_hash_get_current_data_ex(_5$$7, (void**) &_6$$7, &_4$$7) == SUCCESS
				  ; zend_hash_move_forward_ex(_5$$7, &_4$$7)
				) {
					ZEPHIR_GET_HVALUE(message, _6$$7);
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

