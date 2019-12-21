
extern zend_class_entry *phalcon_http_request_fileinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Request_FileInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_fileinterface_geterror, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_fileinterface_geterror, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_fileinterface_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_fileinterface_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_fileinterface_getrealtype, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_fileinterface_getrealtype, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_fileinterface_getsize, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_fileinterface_getsize, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_fileinterface_gettempname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_fileinterface_gettempname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_fileinterface_gettype, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_fileinterface_gettype, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_fileinterface_moveto, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_fileinterface_moveto, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, destination, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, destination)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_request_fileinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getError, arginfo_phalcon_http_request_fileinterface_geterror)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getName, arginfo_phalcon_http_request_fileinterface_getname)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getRealType, arginfo_phalcon_http_request_fileinterface_getrealtype)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getSize, arginfo_phalcon_http_request_fileinterface_getsize)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getTempName, arginfo_phalcon_http_request_fileinterface_gettempname)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getType, arginfo_phalcon_http_request_fileinterface_gettype)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, moveTo, arginfo_phalcon_http_request_fileinterface_moveto)
	PHP_FE_END
};
