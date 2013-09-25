
extern zend_class_entry *phalcon_cache_frontendinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_FrontendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontendinterface_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontendinterface_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_frontendinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, getLifetime, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, isBuffering, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, start, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, getContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, stop, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, beforeStore, arginfo_phalcon_cache_frontendinterface_beforestore)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, afterRetrieve, arginfo_phalcon_cache_frontendinterface_afterretrieve)
	PHP_FE_END
};
