
extern zend_class_entry *phalcon_translate_adapter_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_AdapterInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_adapterinterface_exists, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_adapterinterface_exists, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, index, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, index)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_adapterinterface_query, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_adapterinterface_query, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, translateKey, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, translateKey)
#endif
	ZEND_ARG_ARRAY_INFO(0, placeholders, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_adapterinterface_t, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_adapterinterface_t, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, translateKey, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, translateKey)
#endif
	ZEND_ARG_ARRAY_INFO(0, placeholders, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_adapter_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Translate_Adapter_AdapterInterface, exists, arginfo_phalcon_translate_adapter_adapterinterface_exists)
	PHP_ABSTRACT_ME(Phalcon_Translate_Adapter_AdapterInterface, query, arginfo_phalcon_translate_adapter_adapterinterface_query)
	PHP_ABSTRACT_ME(Phalcon_Translate_Adapter_AdapterInterface, t, arginfo_phalcon_translate_adapter_adapterinterface_t)
	PHP_FE_END
};
