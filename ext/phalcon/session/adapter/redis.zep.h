
extern zend_class_entry *phalcon_session_adapter_redis_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Redis);

PHP_METHOD(Phalcon_Session_Adapter_Redis, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_redis___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Storage\\AdapterFactory, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_adapter_redis_method_entry) {
	PHP_ME(Phalcon_Session_Adapter_Redis, __construct, arginfo_phalcon_session_adapter_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
