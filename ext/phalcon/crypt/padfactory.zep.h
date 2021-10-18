
extern zend_class_entry *phalcon_crypt_padfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Crypt_PadFactory);

PHP_METHOD(Phalcon_Crypt_PadFactory, __construct);
PHP_METHOD(Phalcon_Crypt_PadFactory, newInstance);
PHP_METHOD(Phalcon_Crypt_PadFactory, padNumberToService);
PHP_METHOD(Phalcon_Crypt_PadFactory, getServices);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_padfactory___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, services, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_padfactory_newinstance, 0, 1, Phalcon\\Crypt\\Padding\\PadInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_padfactory_padnumbertoservice, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, number, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_padfactory_getservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_crypt_padfactory_method_entry) {
	PHP_ME(Phalcon_Crypt_PadFactory, __construct, arginfo_phalcon_crypt_padfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Crypt_PadFactory, newInstance, arginfo_phalcon_crypt_padfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_PadFactory, padNumberToService, arginfo_phalcon_crypt_padfactory_padnumbertoservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_PadFactory, getServices, arginfo_phalcon_crypt_padfactory_getservices, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
