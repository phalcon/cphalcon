
extern zend_class_entry *phalcon_support_registry_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Registry);

PHP_METHOD(Phalcon_Support_Registry, __construct);
PHP_METHOD(Phalcon_Support_Registry, __get);
PHP_METHOD(Phalcon_Support_Registry, __isset);
PHP_METHOD(Phalcon_Support_Registry, __set);
PHP_METHOD(Phalcon_Support_Registry, __unset);
PHP_METHOD(Phalcon_Support_Registry, clear);
PHP_METHOD(Phalcon_Support_Registry, count);
PHP_METHOD(Phalcon_Support_Registry, get);
PHP_METHOD(Phalcon_Support_Registry, getIterator);
PHP_METHOD(Phalcon_Support_Registry, has);
PHP_METHOD(Phalcon_Support_Registry, init);
PHP_METHOD(Phalcon_Support_Registry, jsonSerialize);
PHP_METHOD(Phalcon_Support_Registry, offsetExists);
PHP_METHOD(Phalcon_Support_Registry, offsetGet);
PHP_METHOD(Phalcon_Support_Registry, offsetSet);
PHP_METHOD(Phalcon_Support_Registry, offsetUnset);
PHP_METHOD(Phalcon_Support_Registry, remove);
PHP_METHOD(Phalcon_Support_Registry, serialize);
PHP_METHOD(Phalcon_Support_Registry, set);
PHP_METHOD(Phalcon_Support_Registry, toArray);
PHP_METHOD(Phalcon_Support_Registry, toJson);
PHP_METHOD(Phalcon_Support_Registry, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_registry___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, data, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, data, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_registry___get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry___isset, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry___set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry___unset, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry_count, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_registry_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, cast, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_support_registry_getiterator, 0, 0, Traversable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry_init, 0, 0, IS_VOID, 0)

#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, data, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, data, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry_jsonserialize, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry_offsetexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry_offsetget, 0, 1, IS_MIXED, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_registry_offsetget, 0, 0, 1)
#endif
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry_offsetset, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, element)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry_offsetunset, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry_remove, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry_serialize, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry_set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry_toarray, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry_tojson, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_registry_unserialize, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, serialized)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_registry_method_entry) {
	PHP_ME(Phalcon_Support_Registry, __construct, arginfo_phalcon_support_registry___construct, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Support_Registry, __get, arginfo_phalcon_support_registry___get, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, __isset, arginfo_phalcon_support_registry___isset, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, __set, arginfo_phalcon_support_registry___set, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, __unset, arginfo_phalcon_support_registry___unset, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, clear, arginfo_phalcon_support_registry_clear, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, count, arginfo_phalcon_support_registry_count, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, get, arginfo_phalcon_support_registry_get, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, getIterator, arginfo_phalcon_support_registry_getiterator, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, has, arginfo_phalcon_support_registry_has, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, init, arginfo_phalcon_support_registry_init, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, jsonSerialize, arginfo_phalcon_support_registry_jsonserialize, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, offsetExists, arginfo_phalcon_support_registry_offsetexists, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, offsetGet, arginfo_phalcon_support_registry_offsetget, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, offsetSet, arginfo_phalcon_support_registry_offsetset, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, offsetUnset, arginfo_phalcon_support_registry_offsetunset, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, remove, arginfo_phalcon_support_registry_remove, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, serialize, arginfo_phalcon_support_registry_serialize, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, set, arginfo_phalcon_support_registry_set, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, toArray, arginfo_phalcon_support_registry_toarray, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, toJson, arginfo_phalcon_support_registry_tojson, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Registry, unserialize, arginfo_phalcon_support_registry_unserialize, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
