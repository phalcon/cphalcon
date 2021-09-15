
extern zend_class_entry *phalcon_db_adapter_pdo_postgresql_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Postgresql);

PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, __construct);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, connect);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, createTable);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeColumns);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeReferences);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, getDefaultIdValue);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, modifyColumn);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, supportSequences);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, useExplicitIdValue);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, getDsnDefaults);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, descriptor, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_connect, 0, 0, IS_VOID, 0)

#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, descriptor, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, descriptor, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_createtable, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_describecolumns, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_describereferences, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_getdefaultidvalue, 0, 0, Phalcon\\Db\\RawValue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_modifycolumn, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tableName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schemaName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_INFO(0, currentColumn, Phalcon\\Db\\ColumnInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_supportsequences, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_useexplicitidvalue, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_getdsndefaults, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_adapter_pdo_postgresql_method_entry) {
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, __construct, arginfo_phalcon_db_adapter_pdo_postgresql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, connect, arginfo_phalcon_db_adapter_pdo_postgresql_connect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, createTable, arginfo_phalcon_db_adapter_pdo_postgresql_createtable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, describeColumns, arginfo_phalcon_db_adapter_pdo_postgresql_describecolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, describeReferences, arginfo_phalcon_db_adapter_pdo_postgresql_describereferences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, getDefaultIdValue, arginfo_phalcon_db_adapter_pdo_postgresql_getdefaultidvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, modifyColumn, arginfo_phalcon_db_adapter_pdo_postgresql_modifycolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, supportSequences, arginfo_phalcon_db_adapter_pdo_postgresql_supportsequences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, useExplicitIdValue, arginfo_phalcon_db_adapter_pdo_postgresql_useexplicitidvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, getDsnDefaults, arginfo_phalcon_db_adapter_pdo_postgresql_getdsndefaults, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
