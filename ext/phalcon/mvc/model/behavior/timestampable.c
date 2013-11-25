
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
 * Phalcon\Mvc\Model\Behavior\Timestampable
 *
 * Allows to automatically update a model’s attribute saving the
 * datetime when a record is created or updated
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Behavior_Timestampable) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Behavior, Timestampable, phalcon, mvc_model_behavior_timestampable, phalcon_mvc_model_behavior_ce, phalcon_mvc_model_behavior_timestampable_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_behavior_timestampable_ce TSRMLS_CC, 1, phalcon_mvc_model_behaviorinterface_ce);

	return SUCCESS;

}

/**
 * Listens for notifications from the models manager
 *
 * @param string type
 * @param Phalcon\Mvc\ModelInterface model
 */
PHP_METHOD(Phalcon_Mvc_Model_Behavior_Timestampable, notify) {

	zend_function *_4 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *type_param = NULL, *model, *options, *timestamp = NULL, *singleField = NULL, *field, *generator, *format, *_0, **_3;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &model);

		if (Z_TYPE_P(type_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		type = type_param;



	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, this_ptr, "musttakeaction", type);
	if (!ZEPHIR_IS_TRUE(_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(options);
	zephir_call_method_p1(options, this_ptr, "getoptions", type);
	if ((Z_TYPE_P(options) == IS_ARRAY)) {
		if (!(zephir_array_isset_string_fetch(&field, options, SS("field"), 1 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The option 'field' is required");
			return;
		}
		ZEPHIR_INIT_VAR(timestamp);
		ZVAL_NULL(timestamp);
		if (zephir_array_isset_string_fetch(&format, options, SS("format"), 1 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(timestamp);
			zephir_call_func_p1(timestamp, "date", format);
		} else {
			if (zephir_array_isset_string_fetch(&generator, options, SS("generator"), 1 TSRMLS_CC)) {
				if ((Z_TYPE_P(generator) == IS_OBJECT)) {
					if (zephir_is_instance_of(generator, SL("Closure") TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(timestamp);
						zephir_call_func_p1(timestamp, "call_user_func", generator);
					}
				}
			}
		}
		if ((Z_TYPE_P(timestamp) == IS_NULL)) {
			ZEPHIR_INIT_NVAR(timestamp);
			zephir_call_func(timestamp, "time");
		}
		if ((Z_TYPE_P(field) == IS_ARRAY)) {
			zephir_is_iterable(field, &_2, &_1, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
				; zend_hash_move_forward_ex(_2, &_1)
			) {
				ZEPHIR_GET_HVALUE(singleField, _3);
				zephir_call_method_p2_cache_noret(model, "writeattribute", &_4, singleField, timestamp);
			}
		} else {
			zephir_call_method_p2_noret(model, "writeattribute", field, timestamp);
		}
	}
	ZEPHIR_MM_RESTORE();

}

