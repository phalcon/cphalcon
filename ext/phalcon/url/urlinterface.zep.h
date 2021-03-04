
extern zend_class_entry *phalcon_url_urlinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Url_UrlInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_url_urlinterface_get, 0, 0, IS_STRING, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, args)
	ZEND_ARG_TYPE_INFO(0, local, _IS_BOOL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_url_urlinterface_getbasepath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_url_urlinterface_getbaseuri, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_url_urlinterface_setbasepath, 0, 1, Phalcon\\Url\\UrlInterface, 0)
	ZEND_ARG_TYPE_INFO(0, basePath, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_url_urlinterface_setbaseuri, 0, 1, Phalcon\\Url\\UrlInterface, 0)
	ZEND_ARG_TYPE_INFO(0, baseUri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_url_urlinterface_path, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_url_urlinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Url_UrlInterface, get, arginfo_phalcon_url_urlinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Url_UrlInterface, getBasePath, arginfo_phalcon_url_urlinterface_getbasepath)
	PHP_ABSTRACT_ME(Phalcon_Url_UrlInterface, getBaseUri, arginfo_phalcon_url_urlinterface_getbaseuri)
	PHP_ABSTRACT_ME(Phalcon_Url_UrlInterface, setBasePath, arginfo_phalcon_url_urlinterface_setbasepath)
	PHP_ABSTRACT_ME(Phalcon_Url_UrlInterface, setBaseUri, arginfo_phalcon_url_urlinterface_setbaseuri)
	PHP_ABSTRACT_ME(Phalcon_Url_UrlInterface, path, arginfo_phalcon_url_urlinterface_path)
	PHP_FE_END
};
