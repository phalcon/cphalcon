
extern zend_class_entry *phalcon_domain_payload_readableinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Domain_Payload_ReadableInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_domain_payload_readableinterface_getexception, 0, 0, Throwable, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_domain_payload_readableinterface_getexception, 0, 0, IS_OBJECT, "Throwable", 1)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_domain_payload_readableinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_ReadableInterface, getException, arginfo_phalcon_domain_payload_readableinterface_getexception)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_ReadableInterface, getExtras, NULL)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_ReadableInterface, getInput, NULL)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_ReadableInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_ReadableInterface, getOutput, NULL)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_ReadableInterface, getStatus, NULL)
	PHP_FE_END
};
