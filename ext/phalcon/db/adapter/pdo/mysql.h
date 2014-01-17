
extern zend_class_entry *phalcon_db_adapter_pdo_mysql_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Mysql);

PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, escapeIdentifier);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_mysql_escapeidentifier, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_mysql_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_adapter_pdo_mysql_method_entry) {
	PHP_ME(Phalcon_Db_Adapter_Pdo_Mysql, escapeIdentifier, arginfo_phalcon_db_adapter_pdo_mysql_escapeidentifier, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns, arginfo_phalcon_db_adapter_pdo_mysql_describecolumns, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
