
extern zend_class_entry *phalcon_mvc_model_message_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Message);

PHP_METHOD(Phalcon_Mvc_Model_Message, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Message, setType);
PHP_METHOD(Phalcon_Mvc_Model_Message, getType);
PHP_METHOD(Phalcon_Mvc_Model_Message, setMessage);
PHP_METHOD(Phalcon_Mvc_Model_Message, getMessage);
PHP_METHOD(Phalcon_Mvc_Model_Message, setField);
PHP_METHOD(Phalcon_Mvc_Model_Message, getField);
PHP_METHOD(Phalcon_Mvc_Model_Message, setModel);
PHP_METHOD(Phalcon_Mvc_Model_Message, getModel);
PHP_METHOD(Phalcon_Mvc_Model_Message, __toString);
PHP_METHOD(Phalcon_Mvc_Model_Message, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_message___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_message_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_message_setmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_message_setfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_message_setmodel, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_message___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, message, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_message_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Message, __construct, arginfo_phalcon_mvc_model_message___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Message, setType, arginfo_phalcon_mvc_model_message_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, setMessage, arginfo_phalcon_mvc_model_message_setmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, getMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, setField, arginfo_phalcon_mvc_model_message_setfield, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, getField, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, setModel, arginfo_phalcon_mvc_model_message_setmodel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, getModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, __set_state, arginfo_phalcon_mvc_model_message___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
