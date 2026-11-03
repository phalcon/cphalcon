
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
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Instead of permanently delete a record it marks the record as deleted
 * changing the value of a flag column
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Behavior_SoftDelete)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Behavior, SoftDelete, phalcon, mvc_model_behavior_softdelete, phalcon_mvc_model_behavior_ce, phalcon_mvc_model_behavior_softdelete_method_entry, 0);

	return SUCCESS;
}

/**
 * Listens for notifications from the models manager
 *
 * @phpstan-return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_SoftDelete, notify)
{
	zend_bool _0, _1, _14, _11$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type_zv, *model, model_sub, options, value, field, updateModel, message, modelsManager, metaData, _2, _3, _4, _13, _15, _16, _5$$7, *_6$$7, _7$$7, *_8$$7, _10$$7, _17$$10, _18$$10;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&updateModel);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&modelsManager);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	model = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&type_zv, "beforeDelete")) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&options, this_ptr, "getOptions", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&value);
	_0 = zephir_array_isset_string_fetch(&value, &options, SL("value"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_behavior_exceptions_missingrequiredoption_ce, "value", "phalcon/Mvc/Model/Behavior/SoftDelete.zep", 44);
		return;
	}
	zephir_memory_observe(&field);
	_1 = zephir_array_isset_string_fetch(&field, &options, SL("field"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_behavior_exceptions_missingrequiredoption_ce, "field", "phalcon/Mvc/Model/Behavior/SoftDelete.zep", 51);
		return;
	}
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_CALL_METHOD(NULL, model, "skipOperation", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, model, "readAttribute", NULL, 0, &field);
	zephir_check_call_status();
	if (ZEPHIR_IS_IDENTICAL(&_3, &value)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&modelsManager, model, "getModelsManager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&updateModel);
	if (zephir_clone(&updateModel, model) == FAILURE) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, &updateModel, "writeAttribute", NULL, 0, &field, &value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &updateModel, "save", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_4))) {
		ZEPHIR_CALL_METHOD(&_5$$7, &updateModel, "getMessages", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&_5$$7) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_7$$7);
			zephir_string_to_char_array(&_7$$7, &_5$$7);
			_6$$7 = &_7$$7;
		} else {
			_6$$7 = &_5$$7;
		}
		zephir_is_iterable(_6$$7, 0, "phalcon/Mvc/Model/Behavior/SoftDelete.zep", 86);
		if (Z_TYPE_P(_6$$7) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_6$$7), _8$$7)
			{
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _8$$7);
				ZEPHIR_CALL_METHOD(NULL, model, "appendMessage", &_9, 0, &message);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _6$$7, "rewind", NULL, 0);
			zephir_check_call_status();
			_11$$7 = 1;
			while (1) {
				if (_11$$7) {
					_11$$7 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _6$$7, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_10$$7, _6$$7, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$7)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&message, _6$$7, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, model, "appendMessage", &_12, 0, &message);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&message);
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(NULL, model, "writeAttribute", NULL, 0, &field, &value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_13, &modelsManager, "isKeepingSnapshots", NULL, 0, model);
	zephir_check_call_status();
	_14 = zephir_is_true(&_13);
	if (_14) {
		ZEPHIR_INIT_VAR(&_16);
		ZVAL_STRING(&_16, "orm.update_snapshot_on_save");
		ZEPHIR_CALL_CE_STATIC(&_15, phalcon_support_settings_ce, "get", NULL, 0, &_16);
		zephir_check_call_status();
		_14 = zephir_is_true(&_15);
	}
	if (_14) {
		ZEPHIR_CALL_METHOD(&metaData, model, "getModelsMetaData", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_17$$10, &updateModel, "getSnapshotData", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, model, "setSnapshotData", NULL, 0, &_17$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_18$$10, &updateModel, "getOldSnapshotData", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, model, "setOldSnapshotData", NULL, 0, &_18$$10);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

