
extern zend_class_entry *phalcon_assets_exceptions_collectionnotfound_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Exceptions_CollectionNotFound);

PHP_METHOD(Phalcon_Assets_Exceptions_CollectionNotFound, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_exceptions_collectionnotfound___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, name, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_exceptions_collectionnotfound_method_entry) {
	PHP_ME(Phalcon_Assets_Exceptions_CollectionNotFound, __construct, arginfo_phalcon_assets_exceptions_collectionnotfound___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
