
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "Zend/zend_closures.h"
#include "kernel/object.h"
#include "kernel/time.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Mvc\Collection\Behavior\Timestampable
 *
 * Allows to automatically update a model’s attribute saving the
 * datetime when a record is created or updated
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_Behavior_Timestampable) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Collection\\Behavior, Timestampable, phalcon, mvc_collection_behavior_timestampable, phalcon_mvc_collection_behavior_ce, phalcon_mvc_collection_behavior_timestampable_method_entry, 0);

	zend_class_implements(phalcon_mvc_collection_behavior_timestampable_ce TSRMLS_CC, 1, phalcon_mvc_collection_behaviorinterface_ce);
	return SUCCESS;

}

/**
 * Listens for notifications from the models manager
 */
PHP_METHOD(Phalcon_Mvc_Collection_Behavior_Timestampable, notify) {

	zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *model, *options = NULL, *timestamp = NULL, *singleField = NULL, *field, *generator, *format, *_0 = NULL, **_3;
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "musttakeaction", NULL, 0, type);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&options, this_ptr, "getoptions", NULL, 0, type);
	zephir_check_call_status();
	if (Z_TYPE_P(options) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(field);
		if (!(zephir_array_isset_string_fetch(&field, options, SS("field"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "The option 'field' is required", "phalcon/mvc/collection/behavior/timestampable.zep", 57);
			return;
		}
		ZEPHIR_INIT_VAR(timestamp);
		ZVAL_NULL(timestamp);
		ZEPHIR_OBS_VAR(format);
		if (zephir_array_isset_string_fetch(&format, options, SS("format"), 0 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&timestamp, "date", NULL, 286, format);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_VAR(generator);
			if (zephir_array_isset_string_fetch(&generator, options, SS("generator"), 0 TSRMLS_CC)) {
				if (Z_TYPE_P(generator) == IS_OBJECT) {
					if (zephir_instance_of_ev(generator, zend_ce_closure TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(timestamp);
						ZEPHIR_CALL_USER_FUNC(timestamp, generator);
						zephir_check_call_status();
					}
				}
			}
		}
		if (Z_TYPE_P(timestamp) == IS_NULL) {
			ZEPHIR_INIT_NVAR(timestamp);
			zephir_time(timestamp);
		}
		if (Z_TYPE_P(field) == IS_ARRAY) {
			zephir_is_iterable(field, &_2, &_1, 0, 0, "phalcon/mvc/collection/behavior/timestampable.zep", 95);
			for (
			  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			  ; zephir_hash_move_forward_ex(_2, &_1)
			) {
				ZEPHIR_GET_HVALUE(singleField, _3);
				ZEPHIR_CALL_METHOD(NULL, model, "writeattribute", &_4, 0, singleField, timestamp);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CALL_METHOD(NULL, model, "writeattribute", NULL, 0, field, timestamp);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

