
extern zend_class_entry *phalcon_support_collection_readonlycollection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Collection_ReadOnlyCollection);

PHP_METHOD(Phalcon_Support_Collection_ReadOnlyCollection, remove);
PHP_METHOD(Phalcon_Support_Collection_ReadOnlyCollection, set);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_readonlycollection_remove, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_collection_readonlycollection_set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_collection_readonlycollection_method_entry) {
	PHP_ME(Phalcon_Support_Collection_ReadOnlyCollection, remove, arginfo_phalcon_support_collection_readonlycollection_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Collection_ReadOnlyCollection, set, arginfo_phalcon_support_collection_readonlycollection_set, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
