
extern zend_class_entry *phalcon_db_adapter_pdo_mysql_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Mysql);

PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, addForeignKey);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeIndexes);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeReferences);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, getDsnDefaults);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_mysql_addforeignkey, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, reference, Phalcon\\Db\\ReferenceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_mysql_describecolumns, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_mysql_describeindexes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_mysql_describereferences, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_mysql_getdsndefaults, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_adapter_pdo_mysql_method_entry) {
	PHP_ME(Phalcon_Db_Adapter_Pdo_Mysql, addForeignKey, arginfo_phalcon_db_adapter_pdo_mysql_addforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns, arginfo_phalcon_db_adapter_pdo_mysql_describecolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Mysql, describeIndexes, arginfo_phalcon_db_adapter_pdo_mysql_describeindexes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Mysql, describeReferences, arginfo_phalcon_db_adapter_pdo_mysql_describereferences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Mysql, getDsnDefaults, arginfo_phalcon_db_adapter_pdo_mysql_getdsndefaults, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
