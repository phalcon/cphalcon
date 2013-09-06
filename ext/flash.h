
extern zend_class_entry *phalcon_flash_ce;

ZEPHIR_INIT_CLASS(Phalcon_Flash);

PHP_METHOD(Phalcon_Flash, __construct);
PHP_METHOD(Phalcon_Flash, setImplicitFlush);
PHP_METHOD(Phalcon_Flash, setAutomaticHtml);
PHP_METHOD(Phalcon_Flash, setCssClasses);
PHP_METHOD(Phalcon_Flash, error);
PHP_METHOD(Phalcon_Flash, notice);
PHP_METHOD(Phalcon_Flash, success);
PHP_METHOD(Phalcon_Flash, warning);
PHP_METHOD(Phalcon_Flash, outputMessage);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, cssClasses)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_setImplicitFlush, 0, 0, 0)
	ZEND_ARG_INFO(0, implicitFlush)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_setAutomaticHtml, 0, 0, 0)
	ZEND_ARG_INFO(0, automaticHtml)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_setCssClasses, 0, 0, 0)
	ZEND_ARG_INFO(0, cssClasses)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_error, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_notice, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_success, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_warning, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_outputMessage, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_flash_method_entry) {
	PHP_ME(Phalcon_Flash, __construct, arginfo_phalcon_flash___construct, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, setImplicitFlush, arginfo_phalcon_flash_setImplicitFlush, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, setAutomaticHtml, arginfo_phalcon_flash_setAutomaticHtml, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, setCssClasses, arginfo_phalcon_flash_setCssClasses, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, error, arginfo_phalcon_flash_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, notice, arginfo_phalcon_flash_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, success, arginfo_phalcon_flash_success, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, warning, arginfo_phalcon_flash_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, outputMessage, arginfo_phalcon_flash_outputMessage, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
