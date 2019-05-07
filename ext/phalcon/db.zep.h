
extern zend_class_entry *phalcon_db_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db);

PHP_METHOD(Phalcon_Db, setup);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_setup, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_method_entry) {
	PHP_ME(Phalcon_Db, setup, arginfo_phalcon_db_setup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
