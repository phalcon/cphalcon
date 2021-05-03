
extern zend_class_entry *phalcon_session_adapter_stream_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Stream);

PHP_METHOD(Phalcon_Session_Adapter_Stream, __construct);
PHP_METHOD(Phalcon_Session_Adapter_Stream, destroy);
PHP_METHOD(Phalcon_Session_Adapter_Stream, gc);
PHP_METHOD(Phalcon_Session_Adapter_Stream, open);
PHP_METHOD(Phalcon_Session_Adapter_Stream, read);
PHP_METHOD(Phalcon_Session_Adapter_Stream, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_stream___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_stream_destroy, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_stream_gc, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, maxlifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_stream_open, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, savePath)
	ZEND_ARG_INFO(0, sessionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_stream_read, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_stream_write, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_adapter_stream_method_entry) {
	PHP_ME(Phalcon_Session_Adapter_Stream, __construct, arginfo_phalcon_session_adapter_stream___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Adapter_Stream, destroy, arginfo_phalcon_session_adapter_stream_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Stream, gc, arginfo_phalcon_session_adapter_stream_gc, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Stream, open, arginfo_phalcon_session_adapter_stream_open, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Stream, read, arginfo_phalcon_session_adapter_stream_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Stream, write, arginfo_phalcon_session_adapter_stream_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
