
extern zend_class_entry *phalcon_support_collection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Collection);

PHP_METHOD(Phalcon_Support_Collection, __construct);
PHP_METHOD(Phalcon_Support_Collection, __get);
PHP_METHOD(Phalcon_Support_Collection, __isset);
PHP_METHOD(Phalcon_Support_Collection, __set);
PHP_METHOD(Phalcon_Support_Collection, __unset);
PHP_METHOD(Phalcon_Support_Collection, clear);
PHP_METHOD(Phalcon_Support_Collection, count);
PHP_METHOD(Phalcon_Support_Collection, get);
PHP_METHOD(Phalcon_Support_Collection, getIterator);
PHP_METHOD(Phalcon_Support_Collection, getKeys);
PHP_METHOD(Phalcon_Support_Collection, getValues);
PHP_METHOD(Phalcon_Support_Collection, has);
PHP_METHOD(Phalcon_Support_Collection, init);
PHP_METHOD(Phalcon_Support_Collection, jsonSerialize);
PHP_METHOD(Phalcon_Support_Collection, offsetExists);
PHP_METHOD(Phalcon_Support_Collection, offsetGet);
PHP_METHOD(Phalcon_Support_Collection, offsetSet);
PHP_METHOD(Phalcon_Support_Collection, offsetUnset);
PHP_METHOD(Phalcon_Support_Collection, remove);
PHP_METHOD(Phalcon_Support_Collection, set);
PHP_METHOD(Phalcon_Support_Collection, serialize);
PHP_METHOD(Phalcon_Support_Collection, toArray);
PHP_METHOD(Phalcon_Support_Collection, toJson);
PHP_METHOD(Phalcon_Support_Collection, unserialize);
PHP_METHOD(Phalcon_Support_Collection, setData);
zend_object *zephir_init_properties_Phalcon_Support_Collection(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_collection___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, data, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, data, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, insensitive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_collection___get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection___isset, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection___set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection___unset, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_count, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_collection_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, cast, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_support_collection_getiterator, 0, 0, Traversable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_getkeys, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, insensitive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_getvalues, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_init, 0, 0, IS_VOID, 0)

#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, data, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, data, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_jsonserialize, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_offsetexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_collection_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_offsetset, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, element)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_offsetunset, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_remove, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_serialize, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_toarray, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_tojson, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_unserialize, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, serialized)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_setdata, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_collection_zephir_init_properties_phalcon_support_collection, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_collection_method_entry) {
	PHP_ME(Phalcon_Support_Collection, __construct, arginfo_phalcon_support_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Support_Collection, __get, arginfo_phalcon_support_collection___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, __isset, arginfo_phalcon_support_collection___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, __set, arginfo_phalcon_support_collection___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, __unset, arginfo_phalcon_support_collection___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, clear, arginfo_phalcon_support_collection_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, count, arginfo_phalcon_support_collection_count, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, get, arginfo_phalcon_support_collection_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, getIterator, arginfo_phalcon_support_collection_getiterator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, getKeys, arginfo_phalcon_support_collection_getkeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, getValues, arginfo_phalcon_support_collection_getvalues, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, has, arginfo_phalcon_support_collection_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, init, arginfo_phalcon_support_collection_init, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, jsonSerialize, arginfo_phalcon_support_collection_jsonserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, offsetExists, arginfo_phalcon_support_collection_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, offsetGet, arginfo_phalcon_support_collection_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, offsetSet, arginfo_phalcon_support_collection_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, offsetUnset, arginfo_phalcon_support_collection_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, remove, arginfo_phalcon_support_collection_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, set, arginfo_phalcon_support_collection_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, serialize, arginfo_phalcon_support_collection_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, toArray, arginfo_phalcon_support_collection_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, toJson, arginfo_phalcon_support_collection_tojson, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, unserialize, arginfo_phalcon_support_collection_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection, setData, arginfo_phalcon_support_collection_setdata, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
