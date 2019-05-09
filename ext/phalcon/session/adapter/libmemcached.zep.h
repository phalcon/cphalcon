
extern zend_class_entry *phalcon_session_adapter_libmemcached_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Libmemcached);

PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_libmemcached___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Storage\\AdapterFactory, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_adapter_libmemcached_method_entry) {
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, __construct, arginfo_phalcon_session_adapter_libmemcached___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
