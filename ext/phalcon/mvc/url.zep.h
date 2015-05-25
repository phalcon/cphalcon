
extern zend_class_entry *phalcon_mvc_url_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Url);

PHP_METHOD(Phalcon_Mvc_Url, setDI);
PHP_METHOD(Phalcon_Mvc_Url, getDI);
PHP_METHOD(Phalcon_Mvc_Url, setBaseUri);
PHP_METHOD(Phalcon_Mvc_Url, setStaticBaseUri);
PHP_METHOD(Phalcon_Mvc_Url, getBaseUri);
PHP_METHOD(Phalcon_Mvc_Url, getStaticBaseUri);
PHP_METHOD(Phalcon_Mvc_Url, setBasePath);
PHP_METHOD(Phalcon_Mvc_Url, getBasePath);
PHP_METHOD(Phalcon_Mvc_Url, get);
PHP_METHOD(Phalcon_Mvc_Url, getStatic);
PHP_METHOD(Phalcon_Mvc_Url, path);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_setbaseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, baseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_setstaticbaseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, staticBaseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_get, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, args)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_getstatic, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_path, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_url_method_entry) {
	PHP_ME(Phalcon_Mvc_Url, setDI, arginfo_phalcon_mvc_url_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, setBaseUri, arginfo_phalcon_mvc_url_setbaseuri, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, setStaticBaseUri, arginfo_phalcon_mvc_url_setstaticbaseuri, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, getBaseUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, getStaticBaseUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, setBasePath, arginfo_phalcon_mvc_url_setbasepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, getBasePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, get, arginfo_phalcon_mvc_url_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, getStatic, arginfo_phalcon_mvc_url_getstatic, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, path, arginfo_phalcon_mvc_url_path, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
