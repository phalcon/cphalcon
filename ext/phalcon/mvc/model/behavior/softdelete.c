
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"


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
 *
 * @param string type
 * @param Phalcon\Mvc\ModelInterface model
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_SoftDelete, notify) {

	zend_function *_6 = NULL;
	HashTable *_4;
	HashPosition _3;
	zval *type_param = NULL, *model, *options, *value, *field, *updateModel, *message = NULL, *_0, *_1, *_2, **_5;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &model);

		if (Z_TYPE_P(type_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		type = type_param;



	if (ZEPHIR_IS_STRING(type, "beforeDelete")) {
		ZEPHIR_INIT_VAR(options);
		zephir_call_method(options, this_ptr, "getoptions");
		if (!(zephir_array_isset_string_fetch(&value, options, SS("value"), 1 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The option 'value' is required");
			return;
		}
		if (!(zephir_array_isset_string_fetch(&field, options, SS("field"), 1 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The option 'field' is required");
			return;
		}
		zephir_call_method_p1_noret(model, "skipoperation", ZEPHIR_GLOBAL(global_true));
		ZEPHIR_INIT_VAR(_0);
		zephir_call_method_p1(_0, model, "readattribute", field);
		if (!ZEPHIR_IS_EQUAL(_0, value)) {
			ZEPHIR_INIT_VAR(updateModel);
			if (zephir_clone(updateModel, model TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}
			zephir_call_method_p2_noret(updateModel, "writeattribute", field, value);
			ZEPHIR_INIT_VAR(_1);
			zephir_call_method(_1, updateModel, "save");
			if (!(zephir_is_true(_1))) {
				ZEPHIR_INIT_VAR(_2);
				zephir_call_method(_2, updateModel, "getmessages");
				zephir_is_iterable(_2, &_4, &_3, 0, 0);
				for (
					; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
					; zend_hash_move_forward_ex(_4, &_3)
				) {
					ZEPHIR_GET_HVALUE(message, _5);
					zephir_call_method_p1_cache_noret(model, "appendmessage", &_6, message);
				}
				RETURN_MM_BOOL(0);
			}
			zephir_call_method_p2_noret(model, "writeattribute", field, value);
		}
	}
	ZEPHIR_MM_RESTORE();

}

