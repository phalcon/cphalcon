
extern zend_class_entry *phalcon_domain_payload_readableinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Domain_Payload_ReadableInterface);

ZEPHIR_INIT_FUNCS(phalcon_domain_payload_readableinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_ReadableInterface, getStatus, NULL)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_ReadableInterface, getInput, NULL)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_ReadableInterface, getOutput, NULL)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_ReadableInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Domain_Payload_ReadableInterface, getExtras, NULL)
	PHP_FE_END
};
