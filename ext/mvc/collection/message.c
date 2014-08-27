
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/collection/message.h"
#include "mvc/collection/messageinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"

#include "internal/arginfo.h"

/**
 * Phalcon\Mvc\Collection\Message
 *
 * Encapsulates validation info generated before save/delete records fails
 *
 *<code>
 *	use Phalcon\Mvc\Collection\Message as Message;
 *
 *  class Robots extends Phalcon\Mvc\Collection
 *  {
 *
 *    public function beforeSave()
 *    {
 *      if ($this->name == 'Peter') {
 *        $text = "A robot cannot be named Peter";
 *        $field = "name";
 *        $type = "InvalidValue";
 *        $code = 103;
 *        $message = new Message($text, $field, $type, $code);
 *        $this->appendMessage($message);
 *     }
 *   }
 *
 * }
 * </code>
 *
 */
zend_class_entry *phalcon_mvc_collection_message_ce;

PHP_METHOD(Phalcon_Mvc_Collection_Message, __construct);
PHP_METHOD(Phalcon_Mvc_Collection_Message, setType);
PHP_METHOD(Phalcon_Mvc_Collection_Message, getType);
PHP_METHOD(Phalcon_Mvc_Collection_Message, setCode);
PHP_METHOD(Phalcon_Mvc_Collection_Message, getCode);
PHP_METHOD(Phalcon_Mvc_Collection_Message, setMessage);
PHP_METHOD(Phalcon_Mvc_Collection_Message, getMessage);
PHP_METHOD(Phalcon_Mvc_Collection_Message, setField);
PHP_METHOD(Phalcon_Mvc_Collection_Message, getField);
PHP_METHOD(Phalcon_Mvc_Collection_Message, setCollection);
PHP_METHOD(Phalcon_Mvc_Collection_Message, getCollection);
PHP_METHOD(Phalcon_Mvc_Collection_Message, __toString);
PHP_METHOD(Phalcon_Mvc_Collection_Message, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_message___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_message_setcollection, 0, 0, 1)
	ZEND_ARG_INFO(0, collection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_message_setcode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_collection_message_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Collection_Message, __construct, arginfo_phalcon_mvc_collection_message___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Collection_Message, setType, arginfo_phalcon_mvc_collection_messageinterface_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Message, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Message, setCode, arginfo_phalcon_mvc_collection_message_setcode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Message, getCode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Message, setMessage, arginfo_phalcon_mvc_collection_messageinterface_setmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Message, getMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Message, setField, arginfo_phalcon_mvc_collection_messageinterface_setfield, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Message, getField, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Message, setCollection, arginfo_phalcon_mvc_collection_message_setcollection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Message, getCollection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Message, __toString, arginfo___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Message, __set_state, arginfo___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Collection\Message initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_Message){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Collection, Message, mvc_collection_message, phalcon_mvc_collection_message_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_collection_message_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_message_ce, SL("_message"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_message_ce, SL("_field"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_message_ce, SL("_collection"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_collection_message_ce, SL("_code"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_collection_message_ce TSRMLS_CC, 1, phalcon_mvc_collection_messageinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Collection\Message constructor
 *
 * @param string $message
 * @param string $field
 * @param string $type
 * @param Phalcon\Mvc\CollectionInterface $collection
 */
PHP_METHOD(Phalcon_Mvc_Collection_Message, __construct){

	zval *message, *field = NULL, *type = NULL, *collection = NULL, *code = NULL;

	phalcon_fetch_params(0, 1, 4, &message, &field, &type, &code, &collection);
	
	if (!field) {
		field = PHALCON_GLOBAL(z_null);
	}
	
	if (!type) {
		type = PHALCON_GLOBAL(z_null);
	}
	
	if (!collection) {
		collection = PHALCON_GLOBAL(z_null);
	}

	if (!code) {
		code = PHALCON_GLOBAL(z_zero);
	}
	
	phalcon_update_property_this(this_ptr, SL("_message"), message TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_field"), field TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	if (Z_TYPE_P(collection) == IS_OBJECT) {
		phalcon_update_property_this(this_ptr, SL("_collection"), collection TSRMLS_CC);
	}
	phalcon_update_property_this(this_ptr, SL("_code"), code TSRMLS_CC);
}

/**
 * Sets message type
 *
 * @param string $type
 * @return Phalcon\Mvc\Collection\Message
 */
PHP_METHOD(Phalcon_Mvc_Collection_Message, setType){

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
PHP_METHOD(Phalcon_Mvc_Collection_Message, getType){


	RETURN_MEMBER(this_ptr, "_type");
}

/**
 * Sets message code
 *
 * @param string $code
 * @return Phalcon\Mvc\Collection\Message
 */
PHP_METHOD(Phalcon_Mvc_Collection_Message, setCode){

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
PHP_METHOD(Phalcon_Mvc_Collection_Message, getCode){

	RETURN_MEMBER(this_ptr, "_code");
}

/**
 * Sets verbose message
 *
 * @param string $message
 * @return Phalcon\Mvc\Collection\Message
 */
PHP_METHOD(Phalcon_Mvc_Collection_Message, setMessage){

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
PHP_METHOD(Phalcon_Mvc_Collection_Message, getMessage){


	RETURN_MEMBER(this_ptr, "_message");
}

/**
 * Sets field name related to message
 *
 * @param string $field
 * @return Phalcon\Mvc\Collection\Message
 */
PHP_METHOD(Phalcon_Mvc_Collection_Message, setField){

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
PHP_METHOD(Phalcon_Mvc_Collection_Message, getField){


	RETURN_MEMBER(this_ptr, "_field");
}

/**
 * Set the collection who generates the message
 *
 * @param Phalcon\Mvc\CollectionInterface $collection
 * @return Phalcon\Mvc\Collection\Message
 */
PHP_METHOD(Phalcon_Mvc_Collection_Message, setCollection){

	zval *collection;

	phalcon_fetch_params(0, 1, 0, &collection);
	
	phalcon_update_property_this(this_ptr, SL("_collection"), collection TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the collection that produced the message
 *
 * @return Phalcon\Mvc\CollectionInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection_Message, getCollection){


	RETURN_MEMBER(this_ptr, "_collection");
}

/**
 * Magic __toString method returns verbose message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Collection_Message, __toString){


	RETURN_MEMBER(this_ptr, "_message");
}

/**
 * Magic __set_state helps to re-build messages variable exporting
 *
 * @param array $message
 * @return Phalcon\Mvc\Collection\Message
 */
PHP_METHOD(Phalcon_Mvc_Collection_Message, __set_state){

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

	object_init_ex(return_value, phalcon_mvc_collection_message_ce);
	PHALCON_CALL_METHOD(NULL, return_value, "__construct", message_text, field, type, code);
	
	RETURN_MM();
}

