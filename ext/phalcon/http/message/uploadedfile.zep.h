
extern zend_class_entry *phalcon_http_message_uploadedfile_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_UploadedFile);

PHP_METHOD(Phalcon_Http_Message_UploadedFile, getClientFilename);
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getClientMediaType);
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getError);
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getSize);
PHP_METHOD(Phalcon_Http_Message_UploadedFile, __construct);
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getStream);
PHP_METHOD(Phalcon_Http_Message_UploadedFile, moveTo);
PHP_METHOD(Phalcon_Http_Message_UploadedFile, checkError);
PHP_METHOD(Phalcon_Http_Message_UploadedFile, checkStream);
PHP_METHOD(Phalcon_Http_Message_UploadedFile, getErrorDescription);
PHP_METHOD(Phalcon_Http_Message_UploadedFile, storeFile);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_getclientfilename, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_getclientmediatype, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_geterror, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_getsize, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_uploadedfile___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, error, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, clientFilename, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, clientMediaType, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_uploadedfile_getstream, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_moveto, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, targetPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_checkerror, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, error, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_checkstream, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_TYPE_INFO(0, error, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_geterrordescription, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, error, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfile_storefile, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, targetPath, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_uploadedfile_method_entry) {
	PHP_ME(Phalcon_Http_Message_UploadedFile, getClientFilename, arginfo_phalcon_http_message_uploadedfile_getclientfilename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_UploadedFile, getClientMediaType, arginfo_phalcon_http_message_uploadedfile_getclientmediatype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_UploadedFile, getError, arginfo_phalcon_http_message_uploadedfile_geterror, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_UploadedFile, getSize, arginfo_phalcon_http_message_uploadedfile_getsize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_UploadedFile, __construct, arginfo_phalcon_http_message_uploadedfile___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Http_Message_UploadedFile, getStream, arginfo_phalcon_http_message_uploadedfile_getstream, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Http_Message_UploadedFile, getStream, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Http_Message_UploadedFile, moveTo, arginfo_phalcon_http_message_uploadedfile_moveto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_UploadedFile, checkError, arginfo_phalcon_http_message_uploadedfile_checkerror, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_UploadedFile, checkStream, arginfo_phalcon_http_message_uploadedfile_checkstream, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_UploadedFile, getErrorDescription, arginfo_phalcon_http_message_uploadedfile_geterrordescription, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Http_Message_UploadedFile, storeFile, arginfo_phalcon_http_message_uploadedfile_storefile, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
