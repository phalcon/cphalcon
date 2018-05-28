
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
 * Phalcon\Mvc\Model\Behavior\SoftDelete
 *
 * Instead of permanently delete a record it marks the record as
 * deleted changing the value of a flag column
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Behavior_SoftDelete) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Behavior, SoftDelete, phalcon, mvc_model_behavior_softdelete, phalcon_mvc_model_behavior_ce, phalcon_mvc_model_behavior_softdelete_method_entry, 0);

	return SUCCESS;

}

/**
 * Listens for notifications from the models manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_SoftDelete, notify) {

	zend_bool _7$$6;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *model, model_sub, options, value, field, updateModel, message, modelsManager, metaData, _0$$3, _1$$3, _2$$6, _6$$6, _3$$7, *_4$$7, _8$$9, _9$$9;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&updateModel);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&modelsManager);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &model);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	if (ZEPHIR_IS_STRING(&type, "beforeDelete")) {
		ZEPHIR_CALL_METHOD(&options, this_ptr, "getoptions", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&value);
		if (!(zephir_array_isset_string_fetch(&value, &options, SL("value"), 0))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The option 'value' is required", "phalcon/mvc/model/behavior/softdelete.zep", 50);
			return;
		}
		ZEPHIR_OBS_VAR(&field);
		if (!(zephir_array_isset_string_fetch(&field, &options, SL("field"), 0))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The option 'field' is required", "phalcon/mvc/model/behavior/softdelete.zep", 57);
			return;
		}
		ZVAL_BOOL(&_0$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, model, "skipoperation", NULL, 0, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, model, "readattribute", NULL, 0, &field);
		zephir_check_call_status();
		if (!ZEPHIR_IS_EQUAL(&_1$$3, &value)) {
			ZEPHIR_CALL_METHOD(&modelsManager, model, "getmodelsmanager", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&updateModel);
			if (zephir_clone(&updateModel, model TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD(NULL, &updateModel, "writeattribute", NULL, 0, &field, &value);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_2$$6, &updateModel, "save", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_2$$6))) {
				ZEPHIR_CALL_METHOD(&_3$$7, &updateModel, "getmessages", NULL, 0);
				zephir_check_call_status();
				zephir_is_iterable(&_3$$7, 0, "phalcon/mvc/model/behavior/softdelete.zep", 91);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3$$7), _4$$7)
				{
					ZEPHIR_INIT_NVAR(&message);
					ZVAL_COPY(&message, _4$$7);
					ZEPHIR_CALL_METHOD(NULL, model, "appendmessage", &_5, 0, &message);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&message);
				RETURN_MM_BOOL(0);
			}
			ZEPHIR_CALL_METHOD(NULL, model, "writeattribute", NULL, 0, &field, &value);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6$$6, &modelsManager, "iskeepingsnapshots", NULL, 0, model);
			zephir_check_call_status();
			_7$$6 = zephir_is_true(&_6$$6);
			if (_7$$6) {
				_7$$6 = ZEPHIR_GLOBAL(orm).update_snapshot_on_save;
			}
			if (_7$$6) {
				ZEPHIR_CALL_METHOD(&metaData, model, "getmodelsmetadata", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$9, &updateModel, "getsnapshotdata", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, model, "setsnapshotdata", NULL, 0, &_8$$9);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_9$$9, &updateModel, "getoldsnapshotdata", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, model, "setoldsnapshotdata", NULL, 0, &_9$$9);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

