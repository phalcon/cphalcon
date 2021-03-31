
extern zend_class_entry *phalcon_di_abstractinjectionaware_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_AbstractInjectionAware);

PHP_METHOD(Phalcon_Di_AbstractInjectionAware, getDI);
PHP_METHOD(Phalcon_Di_AbstractInjectionAware, setDI);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_abstractinjectionaware_getdi, 0, 0, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_abstractinjectionaware_setdi, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_abstractinjectionaware_method_entry) {
	PHP_ME(Phalcon_Di_AbstractInjectionAware, getDI, arginfo_phalcon_di_abstractinjectionaware_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_AbstractInjectionAware, setDI, arginfo_phalcon_di_abstractinjectionaware_setdi, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
