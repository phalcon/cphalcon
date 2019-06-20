
extern zend_class_entry *phalcon_collection_collection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Collection_Collection);

PHP_METHOD(Phalcon_Collection_Collection, __construct);
PHP_METHOD(Phalcon_Collection_Collection, __get);
PHP_METHOD(Phalcon_Collection_Collection, __isset);
PHP_METHOD(Phalcon_Collection_Collection, __set);
PHP_METHOD(Phalcon_Collection_Collection, __unset);
PHP_METHOD(Phalcon_Collection_Collection, clear);
PHP_METHOD(Phalcon_Collection_Collection, count);
PHP_METHOD(Phalcon_Collection_Collection, get);
PHP_METHOD(Phalcon_Collection_Collection, getIterator);
PHP_METHOD(Phalcon_Collection_Collection, has);
PHP_METHOD(Phalcon_Collection_Collection, init);
PHP_METHOD(Phalcon_Collection_Collection, jsonSerialize);
PHP_METHOD(Phalcon_Collection_Collection, offsetExists);
PHP_METHOD(Phalcon_Collection_Collection, offsetGet);
PHP_METHOD(Phalcon_Collection_Collection, offsetSet);
PHP_METHOD(Phalcon_Collection_Collection, offsetUnset);
PHP_METHOD(Phalcon_Collection_Collection, remove);
PHP_METHOD(Phalcon_Collection_Collection, set);
PHP_METHOD(Phalcon_Collection_Collection, serialize);
PHP_METHOD(Phalcon_Collection_Collection, toArray);
PHP_METHOD(Phalcon_Collection_Collection, toJson);
PHP_METHOD(Phalcon_Collection_Collection, unserialize);
PHP_METHOD(Phalcon_Collection_Collection, setData);
zend_object *zephir_init_properties_Phalcon_Collection_Collection(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_collection_collection___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, insensitive, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, insensitive)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_collection_collection___get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collection___isset, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collection___isset, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_collection_collection___set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_collection_collection___unset, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collection_count, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collection_count, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_collection_collection_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_collection_collection_getiterator, 0, 0, Traversable, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collection_getiterator, 0, 0, IS_OBJECT, "Traversable", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collection_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collection_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_collection_collection_init, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collection_jsonserialize, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collection_jsonserialize, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collection_offsetexists, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collection_offsetexists, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_collection_collection_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_collection_collection_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, element)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_collection_collection_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_collection_collection_remove, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_collection_collection_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collection_serialize, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collection_serialize, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collection_toarray, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collection_toarray, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collection_tojson, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collection_tojson, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, options)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_collection_collection_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, serialized)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_collection_collection_setdata, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_collection_collection_method_entry) {
	PHP_ME(Phalcon_Collection_Collection, __construct, arginfo_phalcon_collection_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Collection_Collection, __get, arginfo_phalcon_collection_collection___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, __isset, arginfo_phalcon_collection_collection___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, __set, arginfo_phalcon_collection_collection___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, __unset, arginfo_phalcon_collection_collection___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, count, arginfo_phalcon_collection_collection_count, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, get, arginfo_phalcon_collection_collection_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, getIterator, arginfo_phalcon_collection_collection_getiterator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, has, arginfo_phalcon_collection_collection_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, init, arginfo_phalcon_collection_collection_init, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, jsonSerialize, arginfo_phalcon_collection_collection_jsonserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, offsetExists, arginfo_phalcon_collection_collection_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, offsetGet, arginfo_phalcon_collection_collection_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, offsetSet, arginfo_phalcon_collection_collection_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, offsetUnset, arginfo_phalcon_collection_collection_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, remove, arginfo_phalcon_collection_collection_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, set, arginfo_phalcon_collection_collection_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, serialize, arginfo_phalcon_collection_collection_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, toArray, arginfo_phalcon_collection_collection_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, toJson, arginfo_phalcon_collection_collection_tojson, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, unserialize, arginfo_phalcon_collection_collection_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Collection_Collection, setData, arginfo_phalcon_collection_collection_setdata, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
