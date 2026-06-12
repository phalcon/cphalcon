
extern zend_class_entry *phalcon_session_adapter_redis_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Redis);

PHP_METHOD(Phalcon_Session_Adapter_Redis, __construct);
PHP_METHOD(Phalcon_Session_Adapter_Redis, close);
PHP_METHOD(Phalcon_Session_Adapter_Redis, destroy);
PHP_METHOD(Phalcon_Session_Adapter_Redis, read);
PHP_METHOD(Phalcon_Session_Adapter_Redis, acquireLock);
PHP_METHOD(Phalcon_Session_Adapter_Redis, releaseLock);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_redis___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Storage\\AdapterFactory, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_close, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_destroy, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_read, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_acquirelock, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_redis_releaselock, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_adapter_redis_method_entry) {
	PHP_ME(Phalcon_Session_Adapter_Redis, __construct, arginfo_phalcon_session_adapter_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Adapter_Redis, close, arginfo_phalcon_session_adapter_redis_close, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Redis, destroy, arginfo_phalcon_session_adapter_redis_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Redis, read, arginfo_phalcon_session_adapter_redis_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Redis, acquireLock, arginfo_phalcon_session_adapter_redis_acquirelock, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Session_Adapter_Redis, releaseLock, arginfo_phalcon_session_adapter_redis_releaselock, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
