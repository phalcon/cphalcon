
extern zend_class_entry *phalcon_db_reference_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Reference);

PHP_METHOD(Phalcon_Db_Reference, __construct);
PHP_METHOD(Phalcon_Db_Reference, getColumns);
PHP_METHOD(Phalcon_Db_Reference, getName);
PHP_METHOD(Phalcon_Db_Reference, getReferencedColumns);
PHP_METHOD(Phalcon_Db_Reference, getReferencedSchema);
PHP_METHOD(Phalcon_Db_Reference, getReferencedTable);
PHP_METHOD(Phalcon_Db_Reference, getSchemaName);
PHP_METHOD(Phalcon_Db_Reference, getOnDelete);
PHP_METHOD(Phalcon_Db_Reference, getOnUpdate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_reference___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_reference_getcolumns, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_reference_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_reference_getreferencedcolumns, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_reference_getreferencedschema, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_reference_getreferencedtable, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_reference_getschemaname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_reference_getondelete, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_reference_getonupdate, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_reference_method_entry) {
	PHP_ME(Phalcon_Db_Reference, __construct, arginfo_phalcon_db_reference___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Reference, getColumns, arginfo_phalcon_db_reference_getcolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getName, arginfo_phalcon_db_reference_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getReferencedColumns, arginfo_phalcon_db_reference_getreferencedcolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getReferencedSchema, arginfo_phalcon_db_reference_getreferencedschema, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getReferencedTable, arginfo_phalcon_db_reference_getreferencedtable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getSchemaName, arginfo_phalcon_db_reference_getschemaname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getOnDelete, arginfo_phalcon_db_reference_getondelete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getOnUpdate, arginfo_phalcon_db_reference_getonupdate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
