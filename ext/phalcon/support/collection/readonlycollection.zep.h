
extern zend_class_entry *phalcon_support_collection_readonlycollection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Collection_ReadOnlyCollection);

PHP_METHOD(Phalcon_Support_Collection_ReadOnlyCollection, __construct);
PHP_METHOD(Phalcon_Support_Collection_ReadOnlyCollection, __unserialize);
PHP_METHOD(Phalcon_Support_Collection_ReadOnlyCollection, clear);
PHP_METHOD(Phalcon_Support_Collection_ReadOnlyCollection, init);
PHP_METHOD(Phalcon_Support_Collection_ReadOnlyCollection, remove);
PHP_METHOD(Phalcon_Support_Collection_ReadOnlyCollection, replace);
PHP_METHOD(Phalcon_Support_Collection_ReadOnlyCollection, set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_collection_readonlycollection___construct, 0, 0, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, data, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, insensitive, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, strictNull, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, type, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_readonlycollection___unserialize, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_readonlycollection_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_readonlycollection_init, 0, 0, IS_VOID, 0)

ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, data, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_readonlycollection_remove, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_readonlycollection_replace, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_readonlycollection_set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_collection_readonlycollection_method_entry) {
	PHP_ME(Phalcon_Support_Collection_ReadOnlyCollection, __construct, arginfo_phalcon_support_collection_readonlycollection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Support_Collection_ReadOnlyCollection, __unserialize, arginfo_phalcon_support_collection_readonlycollection___unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection_ReadOnlyCollection, clear, arginfo_phalcon_support_collection_readonlycollection_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection_ReadOnlyCollection, init, arginfo_phalcon_support_collection_readonlycollection_init, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection_ReadOnlyCollection, remove, arginfo_phalcon_support_collection_readonlycollection_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection_ReadOnlyCollection, replace, arginfo_phalcon_support_collection_readonlycollection_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection_ReadOnlyCollection, set, arginfo_phalcon_support_collection_readonlycollection_set, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
