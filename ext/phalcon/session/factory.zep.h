
extern zend_class_entry *phalcon_session_factory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Factory);

PHP_METHOD(Phalcon_Session_Factory, load);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_session_factory_load, 0, 1, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_factory_load, 0, 1, IS_OBJECT, "NULL", 0)
#endif
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_factory_method_entry) {
	PHP_ME(Phalcon_Session_Factory, load, arginfo_phalcon_session_factory_load, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
