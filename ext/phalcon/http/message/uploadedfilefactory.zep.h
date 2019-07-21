
extern zend_class_entry *phalcon_http_message_uploadedfilefactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_UploadedFileFactory);

PHP_METHOD(Phalcon_Http_Message_UploadedFileFactory, createUploadedFile);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_uploadedfilefactory_createuploadedfile, 0, 1, Psr\\Http\\Message\\UploadedFileInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_uploadedfilefactory_createuploadedfile, 0, 1, IS_OBJECT, "Psr\\Http\\Message\\UploadedFileInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, stream, Psr\\Http\\Message\\StreamInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, size)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, error, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, error)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, clientFilename, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, clientFilename)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, clientMediaType, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, clientMediaType)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_uploadedfilefactory_method_entry) {
	PHP_ME(Phalcon_Http_Message_UploadedFileFactory, createUploadedFile, arginfo_phalcon_http_message_uploadedfilefactory_createuploadedfile, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
