
extern zend_class_entry *phalcon_session_adapter_redis_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Redis);

PHP_METHOD(Phalcon_Session_Adapter_Redis, __construct);
PHP_METHOD(Phalcon_Session_Adapter_Redis, destroy);
PHP_METHOD(Phalcon_Session_Adapter_Redis, read);
PHP_METHOD(Phalcon_Session_Adapter_Redis, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_redis___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_destroy, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_destroy, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_read, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_read, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_write, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_write, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_adapter_redis_method_entry) {
	PHP_ME(Phalcon_Session_Adapter_Redis, __construct, arginfo_phalcon_session_adapter_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Adapter_Redis, destroy, arginfo_phalcon_session_adapter_redis_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Redis, read, arginfo_phalcon_session_adapter_redis_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Redis, write, arginfo_phalcon_session_adapter_redis_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
