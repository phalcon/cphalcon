
extern zend_class_entry *phalcon_db_adapter_pdo_postgresql_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Postgresql);

PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, connect);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeColumns);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, createTable);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, modifyColumn);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, useExplicitIdValue);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, getDefaultIdValue);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, supportSequences);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_INFO(0, currentColumn, Phalcon\\Db\\ColumnInterface, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_adapter_pdo_postgresql_method_entry) {
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, connect, arginfo_phalcon_db_adapter_pdo_postgresql_connect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, describeColumns, arginfo_phalcon_db_adapter_pdo_postgresql_describecolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, createTable, arginfo_phalcon_db_adapter_pdo_postgresql_createtable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, modifyColumn, arginfo_phalcon_db_adapter_pdo_postgresql_modifycolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, useExplicitIdValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, getDefaultIdValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, supportSequences, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
