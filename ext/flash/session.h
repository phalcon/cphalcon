
extern zend_class_entry *phalcon_flash_session_ce;

ZEPHIR_INIT_CLASS(Phalcon_Flash_Session);

PHP_METHOD(Phalcon_Flash_Session, setDI);
PHP_METHOD(Phalcon_Flash_Session, getDI);
PHP_METHOD(Phalcon_Flash_Session, _getSessionMessages);
PHP_METHOD(Phalcon_Flash_Session, _setSessionMessages);
PHP_METHOD(Phalcon_Flash_Session, message);
PHP_METHOD(Phalcon_Flash_Session, getMessages);
PHP_METHOD(Phalcon_Flash_Session, output);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session_setDI, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session__getSessionMessages, 0, 0, 0)
	ZEND_ARG_INFO(0, remove)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session__setSessionMessages, 0, 0, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session_message, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session_getMessages, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, remove)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session_output, 0, 0, 0)
	ZEND_ARG_INFO(0, remove)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_flash_session_method_entry) {
	PHP_ME(Phalcon_Flash_Session, setDI, arginfo_phalcon_flash_session_setDI, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_Session, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_Session, _getSessionMessages, arginfo_phalcon_flash_session__getSessionMessages, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Flash_Session, _setSessionMessages, arginfo_phalcon_flash_session__setSessionMessages, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Flash_Session, message, arginfo_phalcon_flash_session_message, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_Session, getMessages, arginfo_phalcon_flash_session_getMessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_Session, output, arginfo_phalcon_flash_session_output, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
