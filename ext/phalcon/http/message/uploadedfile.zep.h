
extern zend_class_entry *phalcon_http_message_uploadedfile_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_UploadedFile);

PHP_METHOD(Phalcon_Http_Message_UploadedFile, getClientFilename);
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getClientMediaType);
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getError);
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getSize);
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getStream);
PHP_METHOD(Phalcon_Http_Message_UploadedFile, moveTo);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_getclientfilename, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_getclientfilename, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_getclientmediatype, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_getclientmediatype, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_geterror, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_geterror, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_getsize, 0, 0, IS_LONG, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_getsize, 0, 0, IS_LONG, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_uploadedfile_getstream, 0, 0, Phalcon\\Http\\Message\\StreamInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_getstream, 0, 0, IS_OBJECT, "Phalcon\\Http\\Message\\StreamInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_uploadedfile_moveto, 0, 0, 1)
	ZEND_ARG_INFO(0, targetPath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_uploadedfile_method_entry) {
	PHP_ME(Phalcon_Http_Message_UploadedFile, getClientFilename, arginfo_phalcon_http_message_uploadedfile_getclientfilename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_UploadedFile, getClientMediaType, arginfo_phalcon_http_message_uploadedfile_getclientmediatype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_UploadedFile, getError, arginfo_phalcon_http_message_uploadedfile_geterror, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_UploadedFile, getSize, arginfo_phalcon_http_message_uploadedfile_getsize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_UploadedFile, getStream, arginfo_phalcon_http_message_uploadedfile_getstream, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_UploadedFile, moveTo, arginfo_phalcon_http_message_uploadedfile_moveto, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
