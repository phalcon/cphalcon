
extern zend_class_entry *phalcon_session_adapter_abstractadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_AbstractAdapter);

PHP_METHOD(Phalcon_Session_Adapter_AbstractAdapter, close);
PHP_METHOD(Phalcon_Session_Adapter_AbstractAdapter, destroy);
PHP_METHOD(Phalcon_Session_Adapter_AbstractAdapter, gc);
PHP_METHOD(Phalcon_Session_Adapter_AbstractAdapter, read);
PHP_METHOD(Phalcon_Session_Adapter_AbstractAdapter, open);
PHP_METHOD(Phalcon_Session_Adapter_AbstractAdapter, write);
PHP_METHOD(Phalcon_Session_Adapter_AbstractAdapter, getArrVal);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_abstractadapter_close, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_abstractadapter_destroy, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80100
ZEND_BEGIN_ARG_WITH_TENTATIVE_RETURN_TYPE_MASK_EX(arginfo_phalcon_session_adapter_abstractadapter_gc, 0, 1, MAY_BE_LONG|MAY_BE_FALSE)
    ZEND_ARG_TYPE_INFO(0, maxlifetime, IS_LONG, 0)
ZEND_END_ARG_INFO()
#elif PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_abstractadapter_gc, 0, 0, 1)
    ZEND_ARG_TYPE_INFO(0, maxlifetime, IS_LONG, 0)
ZEND_END_ARG_INFO()
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_abstractadapter_gc, 0, 0, 1)
    ZEND_ARG_INFO(0, maxlifetime)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_abstractadapter_read, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_abstractadapter_open, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, savePath)
	ZEND_ARG_INFO(0, sessionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_abstractadapter_write, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, sessionId)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_abstractadapter_getarrval, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_adapter_abstractadapter_method_entry) {
	PHP_ME(Phalcon_Session_Adapter_AbstractAdapter, close, arginfo_phalcon_session_adapter_abstractadapter_close, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_AbstractAdapter, destroy, arginfo_phalcon_session_adapter_abstractadapter_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_AbstractAdapter, gc, arginfo_phalcon_session_adapter_abstractadapter_gc, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_AbstractAdapter, read, arginfo_phalcon_session_adapter_abstractadapter_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_AbstractAdapter, open, arginfo_phalcon_session_adapter_abstractadapter_open, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_AbstractAdapter, write, arginfo_phalcon_session_adapter_abstractadapter_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_AbstractAdapter, getArrVal, arginfo_phalcon_session_adapter_abstractadapter_getarrval, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
