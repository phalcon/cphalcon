
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
#include "ext/json/php_json.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Messages_Message)
{
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
	zend_class_implements(phalcon_messages_message_ce, 1, php_json_serializable_ce);
	return SUCCESS;
}

/**
 * Phalcon\Messages\Message constructor
 */
PHP_METHOD(Phalcon_Messages_Message, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval metaData;
	zend_long code;
	zval message_zv, *field = NULL, field_sub, type_zv, *code_param = NULL, *metaData_param = NULL, _0;
	zend_string *message = NULL, *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&metaData);
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(field)
		Z_PARAM_STR(type)
		Z_PARAM_LONG(code)
		ZEPHIR_Z_PARAM_ARRAY(metaData, metaData_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		field = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 3) {
		code_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		metaData_param = ZEND_CALL_ARG(execute_data, 5);
	}
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	if (!field) {
		field = &field_sub;
		ZEPHIR_INIT_VAR(field);
		ZVAL_STRING(field, "");
	}
	if (!type) {
		type = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&type_zv);
		ZVAL_STR(&type_zv, type);
	} else {
		zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	}
	if (!code_param) {
		code = 0;
	} else {
		}
	if (!metaData_param) {
		ZEPHIR_INIT_VAR(&metaData);
		array_init(&metaData);
	} else {
		zephir_get_arrval(&metaData, metaData_param);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("message"), &message_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("field"), field);
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, code);
	zephir_update_property_zval(this_ptr, ZEND_STRL("code"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("metaData"), &metaData);
	ZEPHIR_MM_RESTORE();
}

/**
 * Magic __toString method returns verbose message
 */
PHP_METHOD(Phalcon_Messages_Message, __toString)
{

	RETURN_MEMBER(getThis(), "message");
}

/**
 * @return int
 */
PHP_METHOD(Phalcon_Messages_Message, getCode)
{

	RETURN_MEMBER(getThis(), "code");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Messages_Message, getField)
{

	RETURN_MEMBER(getThis(), "field");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Messages_Message, getMessage)
{

	RETURN_MEMBER(getThis(), "message");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Messages_Message, getType)
{

	RETURN_MEMBER(getThis(), "type");
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Messages_Message, getMetaData)
{

	RETURN_MEMBER(getThis(), "metaData");
}

/**
 * Serializes the object for json_encode
 */
PHP_METHOD(Phalcon_Messages_Message, jsonSerialize)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_create_array(return_value, 5, 0);
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("field"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("field"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("message"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("message"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("type"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("type"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("code"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("code"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("metaData"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("metaData"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Sets code for the message
 */
PHP_METHOD(Phalcon_Messages_Message, setCode)
{
	zval *code_param = NULL, _0;
	zend_long code;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(code)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &code_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, code);
	zephir_update_property_zval(this_ptr, ZEND_STRL("code"), &_0);
	RETURN_THISW();
}

/**
 * Sets field name related to message
 */
PHP_METHOD(Phalcon_Messages_Message, setField)
{
	zval *field, field_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &field);
	zephir_update_property_zval(this_ptr, ZEND_STRL("field"), field);
	RETURN_THISW();
}

/**
 * Sets verbose message
 */
PHP_METHOD(Phalcon_Messages_Message, setMessage)
{
	zval message_zv;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&message_zv, message);
	zephir_update_property_zval(this_ptr, ZEND_STRL("message"), &message_zv);
	RETURN_THISW();
}

/**
 * Sets message metadata
 */
PHP_METHOD(Phalcon_Messages_Message, setMetaData)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *metaData_param = NULL;
	zval metaData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(metaData, metaData_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &metaData_param);
	ZEPHIR_OBS_COPY_OR_DUP(&metaData, metaData_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("metaData"), &metaData);
	RETURN_THIS();
}

/**
 * Sets message type
 */
PHP_METHOD(Phalcon_Messages_Message, setType)
{
	zval type_zv;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&type_zv, type);
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type_zv);
	RETURN_THISW();
}

zend_object *zephir_init_properties_Phalcon_Messages_Message(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("metaData"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("metaData"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

