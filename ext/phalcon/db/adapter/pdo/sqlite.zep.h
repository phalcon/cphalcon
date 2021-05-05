
extern zend_class_entry *phalcon_db_adapter_pdo_sqlite_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Sqlite);

PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, __construct);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, connect);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeColumns);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeIndexes);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeReferences);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, getDefaultValue);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, useExplicitIdValue);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, supportsDefaultValue);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, getDsnDefaults);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, descriptor, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_connect, 0, 0, _IS_BOOL, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, descriptor, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, descriptor, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_describecolumns, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_describeindexes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_describereferences, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_getdefaultvalue, 0, 0, Phalcon\\Db\\RawValue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_useexplicitidvalue, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_supportsdefaultvalue, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_getdsndefaults, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_adapter_pdo_sqlite_method_entry) {
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, __construct, arginfo_phalcon_db_adapter_pdo_sqlite___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, connect, arginfo_phalcon_db_adapter_pdo_sqlite_connect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, describeColumns, arginfo_phalcon_db_adapter_pdo_sqlite_describecolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, describeIndexes, arginfo_phalcon_db_adapter_pdo_sqlite_describeindexes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, describeReferences, arginfo_phalcon_db_adapter_pdo_sqlite_describereferences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, getDefaultValue, arginfo_phalcon_db_adapter_pdo_sqlite_getdefaultvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, useExplicitIdValue, arginfo_phalcon_db_adapter_pdo_sqlite_useexplicitidvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, supportsDefaultValue, arginfo_phalcon_db_adapter_pdo_sqlite_supportsdefaultvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, getDsnDefaults, arginfo_phalcon_db_adapter_pdo_sqlite_getdsndefaults, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
