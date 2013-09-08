
extern zend_class_entry *phalcon_http_request_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Request);

PHP_METHOD(Phalcon_Http_Request, setDI);
PHP_METHOD(Phalcon_Http_Request, getDI);
PHP_METHOD(Phalcon_Http_Request, get);
PHP_METHOD(Phalcon_Http_Request, getPost);
PHP_METHOD(Phalcon_Http_Request, getQuery);
PHP_METHOD(Phalcon_Http_Request, getServer);
PHP_METHOD(Phalcon_Http_Request, has);
PHP_METHOD(Phalcon_Http_Request, hasPost);
PHP_METHOD(Phalcon_Http_Request, hasQuery);
PHP_METHOD(Phalcon_Http_Request, hasServer);
PHP_METHOD(Phalcon_Http_Request, getHeader);
PHP_METHOD(Phalcon_Http_Request, getScheme);
PHP_METHOD(Phalcon_Http_Request, isAjax);
PHP_METHOD(Phalcon_Http_Request, isSoapRequested);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_setdi, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getpost, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getquery, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getserver, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_has, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_haspost, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_hasquery, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_hasserver, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getheader, 0, 0, 0)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_request_method_entry) {
	PHP_ME(Phalcon_Http_Request, setDI, arginfo_phalcon_http_request_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, get, arginfo_phalcon_http_request_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getPost, arginfo_phalcon_http_request_getpost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getQuery, arginfo_phalcon_http_request_getquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getServer, arginfo_phalcon_http_request_getserver, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, has, arginfo_phalcon_http_request_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasPost, arginfo_phalcon_http_request_haspost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasQuery, arginfo_phalcon_http_request_hasquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasServer, arginfo_phalcon_http_request_hasserver, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getHeader, arginfo_phalcon_http_request_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getScheme, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isAjax, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isSoapRequested, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
