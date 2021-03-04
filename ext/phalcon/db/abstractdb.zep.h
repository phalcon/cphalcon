
extern zend_class_entry *phalcon_db_abstractdb_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_AbstractDb);

PHP_METHOD(Phalcon_Db_AbstractDb, setup);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_abstractdb_setup, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_abstractdb_method_entry) {
	PHP_ME(Phalcon_Db_AbstractDb, setup, arginfo_phalcon_db_abstractdb_setup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
