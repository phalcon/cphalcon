
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

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Validation\Message
 *
 * Encapsulates validation info generated in the validation process
 */


/**
 * Phalcon\Validation\Message initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_Message){

	PHALCON_REGISTER_CLASS(Phalcon\\Validation, Message, validation_message, phalcon_validation_message_method_entry, 0);

	zend_declare_property_null(phalcon_validation_message_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_message_ce, SL("_message"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_message_ce, SL("_field"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_validation_message_ce, SL("_code"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Validation\Message constructor
 *
 * @param string $message
 * @param string $field
 * @param string $type
 * @param int    $code
 */
PHP_METHOD(Phalcon_Validation_Message, __construct){

	zval *message, *field = NULL, *type = NULL, *code = NULL;

	phalcon_fetch_params(0, 1, 3, &message, &field, &type, &code);
	
	if (!field) {
		field = PHALCON_GLOBAL(z_null);
	}
	
	if (!type) {
		type = PHALCON_GLOBAL(z_null);
	}

	if (!code) {
		code = PHALCON_GLOBAL(z_zero);
	}
	
	phalcon_update_property_this(this_ptr, SL("_message"), message TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_field"), field TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_code"), code TSRMLS_CC);
}

/**
 * Sets message type
 *
 * @param string $type
 * @return Phalcon\Validation\Message
 */
PHP_METHOD(Phalcon_Validation_Message, setType){

	zval *type;

	phalcon_fetch_params(0, 1, 0, &type);
	
	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns message type
 *
 * @return string
 */
PHP_METHOD(Phalcon_Validation_Message, getType){


	RETURN_MEMBER(this_ptr, "_type");
}

/**
 * Sets message code
 *
 * @param string $code
 * @return Phalcon\Validation\Message
 */
PHP_METHOD(Phalcon_Validation_Message, setCode){

	zval *code;

	phalcon_fetch_params(0, 1, 0, &code);

	phalcon_update_property_this(this_ptr, SL("_code"), code TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns message code
 *
 * @return string
 */
PHP_METHOD(Phalcon_Validation_Message, getCode){

	RETURN_MEMBER(this_ptr, "_code");
}

/**
 * Sets verbose message
 *
 * @param string $message
 * @return Phalcon\Validation\Message
 */
PHP_METHOD(Phalcon_Validation_Message, setMessage){

	zval *message;

	phalcon_fetch_params(0, 1, 0, &message);
	
	phalcon_update_property_this(this_ptr, SL("_message"), message TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns verbose message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Validation_Message, getMessage){


	RETURN_MEMBER(this_ptr, "_message");
}

/**
 * Sets field name related to message
 *
 * @param string $field
 * @return Phalcon\Validation\Message
 */
PHP_METHOD(Phalcon_Validation_Message, setField){

	zval *field;

	phalcon_fetch_params(0, 1, 0, &field);
	
	phalcon_update_property_this(this_ptr, SL("_field"), field TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns field name related to message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Validation_Message, getField){


	RETURN_MEMBER(this_ptr, "_field");
}

/**
 * Magic __toString method returns verbose message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Validation_Message, __toString){


	RETURN_MEMBER(this_ptr, "_message");
}

/**
 * Magic __set_state helps to recover messsages from serialization
 *
 * @param array $message
 * @return Phalcon\Validation\Message
 */
PHP_METHOD(Phalcon_Validation_Message, __set_state){

	zval *message, *message_text, *field, *type, *code;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &message);
	
	PHALCON_OBS_VAR(message_text);
	phalcon_array_fetch_string(&message_text, message, SL("_message"), PH_NOISY);
	
	PHALCON_OBS_VAR(field);
	phalcon_array_fetch_string(&field, message, SL("_field"), PH_NOISY);
	
	PHALCON_OBS_VAR(type);
	phalcon_array_fetch_string(&type, message, SL("_type"), PH_NOISY);

    PHALCON_OBS_VAR(code);
    phalcon_array_fetch_string(&code, message, SL("_code"), PH_NOISY);

	object_init_ex(return_value, phalcon_validation_message_ce);
	phalcon_call_method_p4_noret(return_value, "__construct", message_text, field, type, code);
	
	RETURN_MM();
}

