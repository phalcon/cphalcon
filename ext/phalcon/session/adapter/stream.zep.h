
extern zend_class_entry *phalcon_session_adapter_stream_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Stream);

PHP_METHOD(Phalcon_Session_Adapter_Stream, __construct);
PHP_METHOD(Phalcon_Session_Adapter_Stream, destroy);
PHP_METHOD(Phalcon_Session_Adapter_Stream, gc);
PHP_METHOD(Phalcon_Session_Adapter_Stream, open);
PHP_METHOD(Phalcon_Session_Adapter_Stream, read);
PHP_METHOD(Phalcon_Session_Adapter_Stream, write);
PHP_METHOD(Phalcon_Session_Adapter_Stream, getArrVal);
PHP_METHOD(Phalcon_Session_Adapter_Stream, getDirSeparator);
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpFileExists);
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpFileGetContents);
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpFilePutContents);
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpFopen);
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpIniGet);
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpIsWritable);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_stream___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_stream_destroy, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_stream_gc, 0, 0, 1)
	ZEND_ARG_INFO(0, maxlifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_stream_open, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, savePath)
	ZEND_ARG_INFO(0, sessionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_stream_read, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_stream_write, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, sessionId)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_stream_getarrval, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, cast, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_stream_getdirseparator, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, directory, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_stream_phpfileexists, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_stream_phpfilegetcontents, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_stream_phpfileputcontents, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_stream_phpfopen, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_stream_phpiniget, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, varname, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_stream_phpiswritable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_adapter_stream_method_entry) {
	PHP_ME(Phalcon_Session_Adapter_Stream, __construct, arginfo_phalcon_session_adapter_stream___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Adapter_Stream, destroy, arginfo_phalcon_session_adapter_stream_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Stream, gc, arginfo_phalcon_session_adapter_stream_gc, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Stream, open, arginfo_phalcon_session_adapter_stream_open, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Stream, read, arginfo_phalcon_session_adapter_stream_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Stream, write, arginfo_phalcon_session_adapter_stream_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Stream, getArrVal, arginfo_phalcon_session_adapter_stream_getarrval, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Session_Adapter_Stream, getDirSeparator, arginfo_phalcon_session_adapter_stream_getdirseparator, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Session_Adapter_Stream, phpFileExists, arginfo_phalcon_session_adapter_stream_phpfileexists, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Session_Adapter_Stream, phpFileGetContents, arginfo_phalcon_session_adapter_stream_phpfilegetcontents, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Session_Adapter_Stream, phpFilePutContents, arginfo_phalcon_session_adapter_stream_phpfileputcontents, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Session_Adapter_Stream, phpFopen, arginfo_phalcon_session_adapter_stream_phpfopen, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Session_Adapter_Stream, phpIniGet, arginfo_phalcon_session_adapter_stream_phpiniget, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Session_Adapter_Stream, phpIsWritable, arginfo_phalcon_session_adapter_stream_phpiswritable, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
