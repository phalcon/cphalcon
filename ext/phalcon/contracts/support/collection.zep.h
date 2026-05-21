
extern zend_class_entry *phalcon_contracts_support_collection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Support_Collection);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection___get, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection___isset, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection___set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection___unset, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_column, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, propertyOrMethod, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_support_collection_each, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_support_collection_filter, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_first, 0, 0, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_get, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cast, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_getkeys, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, insensitive, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_gettype, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_getvalues, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_init, 0, 0, IS_VOID, 0)

ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, data, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_isempty, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_keys, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, insensitive, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_last, 0, 0, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_support_collection_map, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_reduce, 0, 1, IS_MIXED, 0)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, initial)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_remove, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_replace, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_support_collection_sort, 0, 0, MAY_BE_STATIC)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, order, IS_LONG, 0, "4")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_toarray, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_tojson, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_LONG, 0, "4194383")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_collection_values, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_support_collection_where, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, propertyOrMethod, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_support_collection_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, __get, arginfo_phalcon_contracts_support_collection___get)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, __isset, arginfo_phalcon_contracts_support_collection___isset)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, __set, arginfo_phalcon_contracts_support_collection___set)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, __unset, arginfo_phalcon_contracts_support_collection___unset)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, clear, arginfo_phalcon_contracts_support_collection_clear)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, column, arginfo_phalcon_contracts_support_collection_column)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, each, arginfo_phalcon_contracts_support_collection_each)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, filter, arginfo_phalcon_contracts_support_collection_filter)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, first, arginfo_phalcon_contracts_support_collection_first)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, get, arginfo_phalcon_contracts_support_collection_get)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, getKeys, arginfo_phalcon_contracts_support_collection_getkeys)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, getType, arginfo_phalcon_contracts_support_collection_gettype)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, getValues, arginfo_phalcon_contracts_support_collection_getvalues)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, has, arginfo_phalcon_contracts_support_collection_has)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, init, arginfo_phalcon_contracts_support_collection_init)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, isEmpty, arginfo_phalcon_contracts_support_collection_isempty)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, keys, arginfo_phalcon_contracts_support_collection_keys)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, last, arginfo_phalcon_contracts_support_collection_last)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, map, arginfo_phalcon_contracts_support_collection_map)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, reduce, arginfo_phalcon_contracts_support_collection_reduce)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, remove, arginfo_phalcon_contracts_support_collection_remove)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, replace, arginfo_phalcon_contracts_support_collection_replace)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, set, arginfo_phalcon_contracts_support_collection_set)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, sort, arginfo_phalcon_contracts_support_collection_sort)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, toArray, arginfo_phalcon_contracts_support_collection_toarray)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, toJson, arginfo_phalcon_contracts_support_collection_tojson)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, values, arginfo_phalcon_contracts_support_collection_values)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Collection, where, arginfo_phalcon_contracts_support_collection_where)
	PHP_FE_END
};
