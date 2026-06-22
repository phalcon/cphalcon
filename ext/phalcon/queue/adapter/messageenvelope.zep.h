
extern zend_class_entry *phalcon_queue_adapter_messageenvelope_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_MessageEnvelope);

PHP_METHOD(Phalcon_Queue_Adapter_MessageEnvelope, decode);
PHP_METHOD(Phalcon_Queue_Adapter_MessageEnvelope, encode);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_messageenvelope_decode, 0, 1, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(0, payload, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_messageenvelope_encode, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_messageenvelope_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_MessageEnvelope, decode, arginfo_phalcon_queue_adapter_messageenvelope_decode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Queue_Adapter_MessageEnvelope, encode, arginfo_phalcon_queue_adapter_messageenvelope_encode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
