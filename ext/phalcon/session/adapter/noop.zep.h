
extern zend_class_entry *phalcon_session_adapter_noop_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Noop);

PHP_METHOD(Phalcon_Session_Adapter_Noop, __construct);
PHP_METHOD(Phalcon_Session_Adapter_Noop, close);
PHP_METHOD(Phalcon_Session_Adapter_Noop, destroy);
PHP_METHOD(Phalcon_Session_Adapter_Noop, gc);
PHP_METHOD(Phalcon_Session_Adapter_Noop, read);
PHP_METHOD(Phalcon_Session_Adapter_Noop, open);
PHP_METHOD(Phalcon_Session_Adapter_Noop, write);
PHP_METHOD(Phalcon_Session_Adapter_Noop, getPrefixedName);
zend_object *zephir_init_properties_Phalcon_Session_Adapter_Noop(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_noop___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_close, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_close, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_destroy, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_destroy, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_gc, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_gc, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, maxlifetime)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_read, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_read, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_open, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_open, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, savePath)
	ZEND_ARG_INFO(0, sessionName)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_write, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_write, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_getprefixedname, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_noop_getprefixedname, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_noop_zephir_init_properties_phalcon_session_adapter_noop, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_adapter_noop_method_entry) {
	PHP_ME(Phalcon_Session_Adapter_Noop, __construct, arginfo_phalcon_session_adapter_noop___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Adapter_Noop, close, arginfo_phalcon_session_adapter_noop_close, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Noop, destroy, arginfo_phalcon_session_adapter_noop_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Noop, gc, arginfo_phalcon_session_adapter_noop_gc, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Noop, read, arginfo_phalcon_session_adapter_noop_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Noop, open, arginfo_phalcon_session_adapter_noop_open, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Noop, write, arginfo_phalcon_session_adapter_noop_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Noop, getPrefixedName, arginfo_phalcon_session_adapter_noop_getprefixedname, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
