
extern zend_class_entry *phalcon_db_reference_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Reference);

PHP_METHOD(Phalcon_Db_Reference, getName);
PHP_METHOD(Phalcon_Db_Reference, getSchemaName);
PHP_METHOD(Phalcon_Db_Reference, getReferencedSchema);
PHP_METHOD(Phalcon_Db_Reference, getReferencedTable);
PHP_METHOD(Phalcon_Db_Reference, getColumns);
PHP_METHOD(Phalcon_Db_Reference, getReferencedColumns);
PHP_METHOD(Phalcon_Db_Reference, getOnDelete);
PHP_METHOD(Phalcon_Db_Reference, getOnUpdate);
PHP_METHOD(Phalcon_Db_Reference, __construct);
PHP_METHOD(Phalcon_Db_Reference, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_reference___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_reference___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_reference_method_entry) {
	PHP_ME(Phalcon_Db_Reference, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getSchemaName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getReferencedSchema, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getReferencedTable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getColumns, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getReferencedColumns, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getOnDelete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getOnUpdate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, __construct, arginfo_phalcon_db_reference___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Reference, __set_state, arginfo_phalcon_db_reference___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
