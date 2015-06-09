
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * Phalcon\Mvc\Model\Message
 *
 * Encapsulates validation info generated before save/delete records fails
 *
 *<code>
 *	use Phalcon\Mvc\Model\Message as Message;
 *
 *  class Robots extends \Phalcon\Mvc\Model
 *  {
 *
 *    public function beforeSave()
 *    {
 *      if (this->name == 'Peter') {
 *        text = "A robot cannot be named Peter";
 *        field = "name";
 *        type = "InvalidValue";
 *        message = new Message(text, field, type);
 *        this->appendMessage(message);
 *     }
 *   }
 *
 * }
 * </code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Message) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Message, phalcon, mvc_model_message, phalcon_mvc_model_message_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_message"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_field"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_model"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_message_ce TSRMLS_CC, 1, phalcon_mvc_model_messageinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Message constructor
 *
 * @param string message
 * @param string|array field
 * @param string type
 * @param Phalcon\Mvc\ModelInterface model
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, __construct) {

	zval *message_param = NULL, *field = NULL, *type = NULL, *model = NULL;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &message_param, &field, &type, &model);

	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!field) {
		field = ZEPHIR_GLOBAL(global_null);
	}
	if (!type) {
		type = ZEPHIR_GLOBAL(global_null);
	}
	if (!model) {
		model = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("_message"), message TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_field"), field TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	if (Z_TYPE_P(model) == IS_OBJECT) {
		zephir_update_property_this(this_ptr, SL("_model"), model TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets message type
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, setType) {

	zval *type_param = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

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


	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns message type
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Sets verbose message
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, setMessage) {

	zval *message_param = NULL;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}


	zephir_update_property_this(this_ptr, SL("_message"), message TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns verbose message
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, getMessage) {


	RETURN_MEMBER(this_ptr, "_message");

}

/**
 * Sets field name related to message
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, setField) {

	zval *field;

	zephir_fetch_params(0, 1, 0, &field);



	zephir_update_property_this(this_ptr, SL("_field"), field TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns field name related to message
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, getField) {


	RETURN_MEMBER(this_ptr, "_field");

}

/**
 * Set the model who generates the message
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, setModel) {

	zval *model;

	zephir_fetch_params(0, 1, 0, &model);



	zephir_update_property_this(this_ptr, SL("_model"), model TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the model that produced the message
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, getModel) {


	RETURN_MEMBER(this_ptr, "_model");

}

/**
 * Magic __toString method returns verbose message
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, __toString) {


	RETURN_MEMBER(this_ptr, "_message");

}

/**
 * Magic __set_state helps to re-build messages variable exporting
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, __set_state) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0, *_1, *_2;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	message = message_param;



	object_init_ex(return_value, phalcon_mvc_model_message_ce);
	zephir_array_fetch_string(&_0, message, SL("_message"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/message.zep", 161 TSRMLS_CC);
	zephir_array_fetch_string(&_1, message, SL("_field"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/message.zep", 161 TSRMLS_CC);
	zephir_array_fetch_string(&_2, message, SL("_type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/message.zep", 161 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 296, _0, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

