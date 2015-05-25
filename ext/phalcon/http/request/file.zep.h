
extern zend_class_entry *phalcon_http_request_file_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Request_File);

PHP_METHOD(Phalcon_Http_Request_File, getError);
PHP_METHOD(Phalcon_Http_Request_File, getKey);
PHP_METHOD(Phalcon_Http_Request_File, getExtension);
PHP_METHOD(Phalcon_Http_Request_File, __construct);
PHP_METHOD(Phalcon_Http_Request_File, getSize);
PHP_METHOD(Phalcon_Http_Request_File, getName);
PHP_METHOD(Phalcon_Http_Request_File, getTempName);
PHP_METHOD(Phalcon_Http_Request_File, getType);
PHP_METHOD(Phalcon_Http_Request_File, getRealType);
PHP_METHOD(Phalcon_Http_Request_File, isUploadedFile);
PHP_METHOD(Phalcon_Http_Request_File, moveTo);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_file___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, file, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_file_moveto, 0, 0, 1)
	ZEND_ARG_INFO(0, destination)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_request_file_method_entry) {
	PHP_ME(Phalcon_Http_Request_File, getError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getExtension, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, __construct, arginfo_phalcon_http_request_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Request_File, getSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getTempName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getRealType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, isUploadedFile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, moveTo, arginfo_phalcon_http_request_file_moveto, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
