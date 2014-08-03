
extern zend_class_entry *phalcon_registry_ce;

ZEPHIR_INIT_CLASS(Phalcon_Registry);

PHP_METHOD(Phalcon_Registry, offsetExists);
PHP_METHOD(Phalcon_Registry, offsetGet);
PHP_METHOD(Phalcon_Registry, offsetSet);
PHP_METHOD(Phalcon_Registry, offsetUnset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_registry_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_registry_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_registry_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_registry_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_registry_method_entry) {
	PHP_ME(Phalcon_Registry, offsetExists, arginfo_phalcon_registry_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Registry, offsetGet, arginfo_phalcon_registry_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Registry, offsetSet, arginfo_phalcon_registry_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Registry, offsetUnset, arginfo_phalcon_registry_offsetunset, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
