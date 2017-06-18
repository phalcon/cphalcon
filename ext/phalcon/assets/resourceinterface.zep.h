
extern zend_class_entry *phalcon_assets_resourceinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_ResourceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resourceinterface_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resourceinterface_setfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resourceinterface_setattributes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_resourceinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Assets_ResourceInterface, setType, arginfo_phalcon_assets_resourceinterface_settype)
	PHP_ABSTRACT_ME(Phalcon_Assets_ResourceInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Assets_ResourceInterface, setFilter, arginfo_phalcon_assets_resourceinterface_setfilter)
	PHP_ABSTRACT_ME(Phalcon_Assets_ResourceInterface, getFilter, NULL)
	PHP_ABSTRACT_ME(Phalcon_Assets_ResourceInterface, setAttributes, arginfo_phalcon_assets_resourceinterface_setattributes)
	PHP_ABSTRACT_ME(Phalcon_Assets_ResourceInterface, getAttributes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Assets_ResourceInterface, getResourceKey, NULL)
	PHP_FE_END
};
