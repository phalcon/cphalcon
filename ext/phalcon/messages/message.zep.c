
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
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Messages\Message
 *
 * Stores a message from various components
 */
ZEPHIR_INIT_CLASS(Phalcon_Messages_Message) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Messages, Message, phalcon, messages_message, phalcon_messages_message_method_entry, 0);

	/**
	 * @var int
	 */
	zend_declare_property_null(phalcon_messages_message_ce, SL("code"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_messages_message_ce, SL("field"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_messages_message_ce, SL("message"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_messages_message_ce, SL("type"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_messages_message_ce, SL("metaData"), ZEND_ACC_PROTECTED);

	phalcon_messages_message_ce->create_object = zephir_init_properties_Phalcon_Messages_Message;

	zend_class_implements(phalcon_messages_message_ce, 1, phalcon_messages_messageinterface_ce);
	zend_class_implements(phalcon_messages_message_ce, 1, zephir_get_internal_ce(SL("jsonserializable")));
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Messages_Message, getCode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "code");

}

/**
 */
PHP_METHOD(Phalcon_Messages_Message, getField) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "field");

}

/**
 */
PHP_METHOD(Phalcon_Messages_Message, getMessage) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "message");

}

/**
 */
PHP_METHOD(Phalcon_Messages_Message, getType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "type");

}

/**
 */
PHP_METHOD(Phalcon_Messages_Message, getMetaData) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "metaData");

}

/**
 * Phalcon\Messages\Message constructor
 */
PHP_METHOD(Phalcon_Messages_Message, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval metaData;
	zend_long code;
	zval *message_param = NULL, *field = NULL, field_sub, *type_param = NULL, *code_param = NULL, *metaData_param = NULL, _0;
	zval message, type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&metaData);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &message_param, &field, &type_param, &code_param, &metaData_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}
	if (!field) {
		field = &field_sub;
		ZEPHIR_INIT_VAR(field);
		ZVAL_STRING(field, "");
	}
	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_STRING(&type, "");
	} else {
		zephir_get_strval(&type, type_param);
	}
	if (!code_param) {
		code = 0;
	} else {
		code = zephir_get_intval(code_param);
	}
	if (!metaData_param) {
		ZEPHIR_INIT_VAR(&metaData);
		array_init(&metaData);
	} else {
		zephir_get_arrval(&metaData, metaData_param);
	}


	zephir_update_property_zval(this_ptr, SL("message"), &message);
	zephir_update_property_zval(this_ptr, SL("field"), field);
	zephir_update_property_zval(this_ptr, SL("type"), &type);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, code);
	zephir_update_property_zval(this_ptr, SL("code"), &_0);
	zephir_update_property_zval(this_ptr, SL("metaData"), &metaData);
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic __toString method returns verbose message
 */
PHP_METHOD(Phalcon_Messages_Message, __toString) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "message");

}

/**
 * Serializes the object for json_encode
 */
PHP_METHOD(Phalcon_Messages_Message, jsonSerialize) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 5, 0);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("field"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("field"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("message"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("message"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("type"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("type"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("code"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("code"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("metaData"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("metaData"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Sets code for the message
 */
PHP_METHOD(Phalcon_Messages_Message, setCode) {

	zval *code_param = NULL, _0;
	zend_long code;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &code_param);

	code = zephir_get_intval(code_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, code);
	zephir_update_property_zval(this_ptr, SL("code"), &_0);
	RETURN_THISW();

}

/**
 * Sets field name related to message
 */
PHP_METHOD(Phalcon_Messages_Message, setField) {

	zval *field, field_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &field);



	zephir_update_property_zval(this_ptr, SL("field"), field);
	RETURN_THISW();

}

/**
 * Sets verbose message
 */
PHP_METHOD(Phalcon_Messages_Message, setMessage) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *message_param = NULL;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}


	zephir_update_property_zval(this_ptr, SL("message"), &message);
	RETURN_THIS();

}

/**
 * Sets message metadata
 */
PHP_METHOD(Phalcon_Messages_Message, setMetaData) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *metaData_param = NULL;
	zval metaData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &metaData_param);

	ZEPHIR_OBS_COPY_OR_DUP(&metaData, metaData_param);


	zephir_update_property_zval(this_ptr, SL("metaData"), &metaData);
	RETURN_THIS();

}

/**
 * Sets message type
 */
PHP_METHOD(Phalcon_Messages_Message, setType) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	zephir_update_property_zval(this_ptr, SL("type"), &type);
	RETURN_THIS();

}

zend_object *zephir_init_properties_Phalcon_Messages_Message(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("metaData"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("metaData"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

