
extern zend_class_entry *phalcon_flash_direct_ce;

ZEPHIR_INIT_CLASS(Phalcon_Flash_Direct);

PHP_METHOD(Phalcon_Flash_Direct, message);
PHP_METHOD(Phalcon_Flash_Direct, output);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_direct_message, 0, 2, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_direct_message, 0, 2, IS_STRING, NULL, 1)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_direct_output, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_direct_output, 0, 0, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_direct_output, 0, 0, 0)
#define arginfo_phalcon_flash_direct_output NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, remove, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, remove)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_flash_direct_method_entry) {
	PHP_ME(Phalcon_Flash_Direct, message, arginfo_phalcon_flash_direct_message, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_Direct, output, arginfo_phalcon_flash_direct_output, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
