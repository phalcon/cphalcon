
extern zend_class_entry *phalcon_http_request_file_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Request_File);

PHP_METHOD(Phalcon_Http_Request_File, getError);
PHP_METHOD(Phalcon_Http_Request_File, getExtension);
PHP_METHOD(Phalcon_Http_Request_File, getKey);
PHP_METHOD(Phalcon_Http_Request_File, __construct);
PHP_METHOD(Phalcon_Http_Request_File, getName);
PHP_METHOD(Phalcon_Http_Request_File, getRealType);
PHP_METHOD(Phalcon_Http_Request_File, getSize);
PHP_METHOD(Phalcon_Http_Request_File, getTempName);
PHP_METHOD(Phalcon_Http_Request_File, getType);
PHP_METHOD(Phalcon_Http_Request_File, isUploadedFile);
PHP_METHOD(Phalcon_Http_Request_File, moveTo);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_file_geterror, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_file_getextension, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_file_getkey, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_file___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, file, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_file_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_file_getrealtype, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_file_getsize, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_file_gettempname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_file_gettype, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_file_isuploadedfile, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_file_moveto, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, destination, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_request_file_method_entry) {
	PHP_ME(Phalcon_Http_Request_File, getError, arginfo_phalcon_http_request_file_geterror, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getExtension, arginfo_phalcon_http_request_file_getextension, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getKey, arginfo_phalcon_http_request_file_getkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, __construct, arginfo_phalcon_http_request_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Request_File, getName, arginfo_phalcon_http_request_file_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getRealType, arginfo_phalcon_http_request_file_getrealtype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getSize, arginfo_phalcon_http_request_file_getsize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getTempName, arginfo_phalcon_http_request_file_gettempname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getType, arginfo_phalcon_http_request_file_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, isUploadedFile, arginfo_phalcon_http_request_file_isuploadedfile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, moveTo, arginfo_phalcon_http_request_file_moveto, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
