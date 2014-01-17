
extern zend_class_entry *phalcon_flashinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_FlashInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_success, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_message, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_flashinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, error, arginfo_phalcon_flashinterface_error)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, notice, arginfo_phalcon_flashinterface_notice)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, success, arginfo_phalcon_flashinterface_success)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, warning, arginfo_phalcon_flashinterface_warning)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, message, arginfo_phalcon_flashinterface_message)
	PHP_FE_END
};
