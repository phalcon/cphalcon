
extern zend_class_entry *phalcon_db_index_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Index);

PHP_METHOD(Phalcon_Db_Index, getName);
PHP_METHOD(Phalcon_Db_Index, getColumns);
PHP_METHOD(Phalcon_Db_Index, getType);
PHP_METHOD(Phalcon_Db_Index, __construct);
PHP_METHOD(Phalcon_Db_Index, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_index___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, columns, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_index___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_index_method_entry) {
	PHP_ME(Phalcon_Db_Index, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Index, getColumns, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Index, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Index, __construct, arginfo_phalcon_db_index___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Index, __set_state, arginfo_phalcon_db_index___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
