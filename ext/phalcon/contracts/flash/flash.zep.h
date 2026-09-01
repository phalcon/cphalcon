
extern zend_class_entry *phalcon_contracts_flash_flash_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Flash_Flash);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_flash_flash_error, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_flash_flash_message, 0, 2, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_flash_flash_notice, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_flash_flash_success, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_flash_flash_warning, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_flash_flash_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Flash_Flash, error, arginfo_phalcon_contracts_flash_flash_error)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Flash_Flash, message, arginfo_phalcon_contracts_flash_flash_message)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Flash_Flash, notice, arginfo_phalcon_contracts_flash_flash_notice)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Flash_Flash, success, arginfo_phalcon_contracts_flash_flash_success)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Flash_Flash, warning, arginfo_phalcon_contracts_flash_flash_warning)
	PHP_FE_END
};
