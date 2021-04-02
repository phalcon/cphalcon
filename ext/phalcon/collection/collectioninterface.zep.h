
extern zend_class_entry *phalcon_collection_collectioninterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Collection_CollectionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_collection_collectioninterface___get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collectioninterface___isset, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collectioninterface___set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collectioninterface___unset, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collectioninterface_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_collection_collectioninterface_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, cast, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collectioninterface_getkeys, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, insensitive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collectioninterface_getvalues, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collectioninterface_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collectioninterface_init, 0, 0, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collectioninterface_remove, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collectioninterface_set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collectioninterface_toarray, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_collection_collectioninterface_tojson, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_collection_collectioninterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Collection_CollectionInterface, __get, arginfo_phalcon_collection_collectioninterface___get)
	PHP_ABSTRACT_ME(Phalcon_Collection_CollectionInterface, __isset, arginfo_phalcon_collection_collectioninterface___isset)
	PHP_ABSTRACT_ME(Phalcon_Collection_CollectionInterface, __set, arginfo_phalcon_collection_collectioninterface___set)
	PHP_ABSTRACT_ME(Phalcon_Collection_CollectionInterface, __unset, arginfo_phalcon_collection_collectioninterface___unset)
	PHP_ABSTRACT_ME(Phalcon_Collection_CollectionInterface, clear, arginfo_phalcon_collection_collectioninterface_clear)
	PHP_ABSTRACT_ME(Phalcon_Collection_CollectionInterface, get, arginfo_phalcon_collection_collectioninterface_get)
	PHP_ABSTRACT_ME(Phalcon_Collection_CollectionInterface, getKeys, arginfo_phalcon_collection_collectioninterface_getkeys)
	PHP_ABSTRACT_ME(Phalcon_Collection_CollectionInterface, getValues, arginfo_phalcon_collection_collectioninterface_getvalues)
	PHP_ABSTRACT_ME(Phalcon_Collection_CollectionInterface, has, arginfo_phalcon_collection_collectioninterface_has)
	PHP_ABSTRACT_ME(Phalcon_Collection_CollectionInterface, init, arginfo_phalcon_collection_collectioninterface_init)
	PHP_ABSTRACT_ME(Phalcon_Collection_CollectionInterface, remove, arginfo_phalcon_collection_collectioninterface_remove)
	PHP_ABSTRACT_ME(Phalcon_Collection_CollectionInterface, set, arginfo_phalcon_collection_collectioninterface_set)
	PHP_ABSTRACT_ME(Phalcon_Collection_CollectionInterface, toArray, arginfo_phalcon_collection_collectioninterface_toarray)
	PHP_ABSTRACT_ME(Phalcon_Collection_CollectionInterface, toJson, arginfo_phalcon_collection_collectioninterface_tojson)
	PHP_FE_END
};
