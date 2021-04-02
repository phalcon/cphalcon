
extern zend_class_entry *phalcon_domain_payload_status_ce;

ZEPHIR_INIT_CLASS(Phalcon_Domain_Payload_Status);

PHP_METHOD(Phalcon_Domain_Payload_Status, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_domain_payload_status___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_domain_payload_status_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Domain_Payload_Status, __construct, arginfo_phalcon_domain_payload_status___construct, ZEND_ACC_FINAL|ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
#else
	PHP_ME(Phalcon_Domain_Payload_Status, __construct, NULL, ZEND_ACC_FINAL|ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
#endif
	PHP_FE_END
};
