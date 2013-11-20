
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


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
 * Phalcon\Validation\Message
 *
 * Encapsulates validation info generated in the validation process
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Message) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Validation, Message, phalcon, validation_message, phalcon_validation_message_method_entry, 0);

	zend_declare_property_null(phalcon_validation_message_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_message_ce, SL("_message"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_message_ce, SL("_field"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Validation\Message constructor
 *
 * @param string message
 * @param string field
 * @param string type
 */
PHP_METHOD(Phalcon_Validation_Message, __construct) {

	zval *message_param = NULL, *field = NULL, *type = NULL;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &message_param, &field, &type);

		if (Z_TYPE_P(message_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		message = message_param;

	if (!field || Z_TYPE_P(field) == IS_NULL) {
		field = ZEPHIR_GLOBAL(global_null);
	}
	if (!type || Z_TYPE_P(type) == IS_NULL) {
		type = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("_message"), message TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_field"), field TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets message type
 *
 * @param string $type
 * @return Phalcon\Mvc\Model\Message
 */
PHP_METHOD(Phalcon_Validation_Message, setType) {

	zval *type_param = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

		if (Z_TYPE_P(type_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		type = type_param;



	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns message type
 *
 * @return string
 */
PHP_METHOD(Phalcon_Validation_Message, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Sets verbose message
 *
 * @param string message
 * @return Phalcon\Mvc\Model\Message
 */
PHP_METHOD(Phalcon_Validation_Message, setMessage) {

	zval *message_param = NULL;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

		if (Z_TYPE_P(message_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		message = message_param;



	zephir_update_property_this(this_ptr, SL("_message"), message TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns verbose message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Validation_Message, getMessage) {


	RETURN_MEMBER(this_ptr, "_message");

}

/**
 * Sets field name related to message
 *
 * @param string field
 * @return Phalcon\Mvc\Model\Message
 */
PHP_METHOD(Phalcon_Validation_Message, setField) {

	zval *field_param = NULL;
	zval *field = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);

		if (Z_TYPE_P(field_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		field = field_param;



	zephir_update_property_this(this_ptr, SL("_field"), field TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns field name related to message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Validation_Message, getField) {


	RETURN_MEMBER(this_ptr, "_field");

}

/**
 * Magic __toString method returns verbose message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Validation_Message, __toString) {


	RETURN_MEMBER(this_ptr, "_message");

}

/**
 * Magic __set_state helps to recover messsages from serialization
 *
 * @param  array message
 * @return Phalcon\Mvc\Model\Message
 */
PHP_METHOD(Phalcon_Validation_Message, __set_state) {

	zval *message, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	object_init_ex(return_value, phalcon_validation_message_ce);
	zephir_array_fetch_string(&_0, message, SL("_message"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_string(&_1, message, SL("_field"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_string(&_2, message, SL("_type"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_call_method_p3_noret(return_value, "__construct", _0, _1, _2);
	RETURN_MM();

}

