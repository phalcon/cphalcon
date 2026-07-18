
extern zend_class_entry *phalcon_http_request_bag_abstractbag_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Request_Bag_AbstractBag);

PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, __construct);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, all);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, count);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, get);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, getArray);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, getBool);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, getFloat);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, getInt);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, getIterator);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, getString);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, has);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, offsetExists);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, offsetGet);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, offsetSet);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, offsetUnset);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, remove);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, set);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, normalizeItems);
PHP_METHOD(Phalcon_Http_Request_Bag_AbstractBag, normalizeKey);
zend_object *zephir_init_properties_Phalcon_Http_Request_Bag_AbstractBag(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag___construct, 0, 0, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, items, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_all, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_count, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_get, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_getarray, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, defaultValue, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_getbool, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, defaultValue, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_getfloat, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, defaultValue, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_getint, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, defaultValue, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_getiterator, 0, 0, Traversable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_getstring, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, defaultValue, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_offsetexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_offsetget, 0, 1, IS_MIXED, 0)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_offsetset, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_offsetunset, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_remove, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_normalizeitems, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, items, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_normalizekey, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_bag_abstractbag_zephir_init_properties_phalcon_http_request_bag_abstractbag, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_request_bag_abstractbag_method_entry) {
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, __construct, arginfo_phalcon_http_request_bag_abstractbag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, all, arginfo_phalcon_http_request_bag_abstractbag_all, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, count, arginfo_phalcon_http_request_bag_abstractbag_count, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, get, arginfo_phalcon_http_request_bag_abstractbag_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, getArray, arginfo_phalcon_http_request_bag_abstractbag_getarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, getBool, arginfo_phalcon_http_request_bag_abstractbag_getbool, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, getFloat, arginfo_phalcon_http_request_bag_abstractbag_getfloat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, getInt, arginfo_phalcon_http_request_bag_abstractbag_getint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, getIterator, arginfo_phalcon_http_request_bag_abstractbag_getiterator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, getString, arginfo_phalcon_http_request_bag_abstractbag_getstring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, has, arginfo_phalcon_http_request_bag_abstractbag_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, offsetExists, arginfo_phalcon_http_request_bag_abstractbag_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, offsetGet, arginfo_phalcon_http_request_bag_abstractbag_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, offsetSet, arginfo_phalcon_http_request_bag_abstractbag_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, offsetUnset, arginfo_phalcon_http_request_bag_abstractbag_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, remove, arginfo_phalcon_http_request_bag_abstractbag_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, set, arginfo_phalcon_http_request_bag_abstractbag_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, normalizeItems, arginfo_phalcon_http_request_bag_abstractbag_normalizeitems, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Request_Bag_AbstractBag, normalizeKey, arginfo_phalcon_http_request_bag_abstractbag_normalizekey, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
