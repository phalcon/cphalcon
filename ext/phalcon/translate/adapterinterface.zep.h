
extern zend_class_entry *phalcon_translate_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface_t, 0, 0, 1)
	ZEND_ARG_INFO(0, translateKey)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface_query, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, t, arginfo_phalcon_translate_adapterinterface_t)
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, query, arginfo_phalcon_translate_adapterinterface_query)
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, exists, arginfo_phalcon_translate_adapterinterface_exists)
	PHP_FE_END
};
