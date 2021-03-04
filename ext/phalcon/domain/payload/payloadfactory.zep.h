
extern zend_class_entry *phalcon_domain_payload_payloadfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Domain_Payload_PayloadFactory);

PHP_METHOD(Phalcon_Domain_Payload_PayloadFactory, newInstance);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_domain_payload_payloadfactory_newinstance, 0, 0, Phalcon\\Domain\\Payload\\PayloadInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_domain_payload_payloadfactory_method_entry) {
	PHP_ME(Phalcon_Domain_Payload_PayloadFactory, newInstance, arginfo_phalcon_domain_payload_payloadfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
