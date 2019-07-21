
extern zend_class_entry *phalcon_http_message_stream_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_Stream);

PHP_METHOD(Phalcon_Http_Message_Stream, __construct);
PHP_METHOD(Phalcon_Http_Message_Stream, __destruct);
PHP_METHOD(Phalcon_Http_Message_Stream, __toString);
PHP_METHOD(Phalcon_Http_Message_Stream, close);
PHP_METHOD(Phalcon_Http_Message_Stream, detach);
PHP_METHOD(Phalcon_Http_Message_Stream, eof);
PHP_METHOD(Phalcon_Http_Message_Stream, getContents);
PHP_METHOD(Phalcon_Http_Message_Stream, getMetadata);
PHP_METHOD(Phalcon_Http_Message_Stream, getSize);
PHP_METHOD(Phalcon_Http_Message_Stream, isReadable);
PHP_METHOD(Phalcon_Http_Message_Stream, isSeekable);
PHP_METHOD(Phalcon_Http_Message_Stream, isWritable);
PHP_METHOD(Phalcon_Http_Message_Stream, read);
PHP_METHOD(Phalcon_Http_Message_Stream, rewind);
PHP_METHOD(Phalcon_Http_Message_Stream, seek);
PHP_METHOD(Phalcon_Http_Message_Stream, setStream);
PHP_METHOD(Phalcon_Http_Message_Stream, tell);
PHP_METHOD(Phalcon_Http_Message_Stream, write);
PHP_METHOD(Phalcon_Http_Message_Stream, checkHandle);
PHP_METHOD(Phalcon_Http_Message_Stream, checkReadable);
PHP_METHOD(Phalcon_Http_Message_Stream, checkSeekable);
PHP_METHOD(Phalcon_Http_Message_Stream, checkWritable);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_stream___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, stream)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, mode)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream___tostring, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_eof, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_eof, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_getcontents, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_getcontents, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_stream_getmetadata, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_getsize, 0, 0, IS_LONG, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_getsize, 0, 0, IS_LONG, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_isreadable, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_isreadable, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_isseekable, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_isseekable, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_iswritable, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_iswritable, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_read, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_read, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_stream_seek, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, whence)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_stream_setstream, 0, 0, 1)
	ZEND_ARG_INFO(0, stream)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, mode)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_tell, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_tell, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_write, 0, 1, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_stream_write, 0, 1, IS_LONG, NULL, 0)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_stream_method_entry) {
	PHP_ME(Phalcon_Http_Message_Stream, __construct, arginfo_phalcon_http_message_stream___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Message_Stream, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Phalcon_Http_Message_Stream, __toString, arginfo_phalcon_http_message_stream___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream, detach, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream, eof, arginfo_phalcon_http_message_stream_eof, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream, getContents, arginfo_phalcon_http_message_stream_getcontents, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream, getMetadata, arginfo_phalcon_http_message_stream_getmetadata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream, getSize, arginfo_phalcon_http_message_stream_getsize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream, isReadable, arginfo_phalcon_http_message_stream_isreadable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream, isSeekable, arginfo_phalcon_http_message_stream_isseekable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream, isWritable, arginfo_phalcon_http_message_stream_iswritable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream, read, arginfo_phalcon_http_message_stream_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream, seek, arginfo_phalcon_http_message_stream_seek, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream, setStream, arginfo_phalcon_http_message_stream_setstream, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream, tell, arginfo_phalcon_http_message_stream_tell, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream, write, arginfo_phalcon_http_message_stream_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_Stream, checkHandle, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Stream, checkReadable, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Stream, checkSeekable, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_Stream, checkWritable, NULL, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
