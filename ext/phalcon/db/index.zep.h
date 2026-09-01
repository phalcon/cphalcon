
extern zend_class_entry *phalcon_db_index_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Index);

PHP_METHOD(Phalcon_Db_Index, __construct);
PHP_METHOD(Phalcon_Db_Index, getColumns);
PHP_METHOD(Phalcon_Db_Index, getDirections);
PHP_METHOD(Phalcon_Db_Index, getName);
PHP_METHOD(Phalcon_Db_Index, getType);
PHP_METHOD(Phalcon_Db_Index, getWhere);
PHP_METHOD(Phalcon_Db_Index, isConcurrent);
PHP_METHOD(Phalcon_Db_Index, isInvisible);
zend_object *zephir_init_properties_Phalcon_Db_Index(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_index___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, columnsOrDefinition, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, type, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_index_getcolumns, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_index_getdirections, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_index_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_index_gettype, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_index_getwhere, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_index_isconcurrent, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_index_isinvisible, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_index_zephir_init_properties_phalcon_db_index, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_index_method_entry) {
	PHP_ME(Phalcon_Db_Index, __construct, arginfo_phalcon_db_index___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Index, getColumns, arginfo_phalcon_db_index_getcolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Index, getDirections, arginfo_phalcon_db_index_getdirections, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Index, getName, arginfo_phalcon_db_index_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Index, getType, arginfo_phalcon_db_index_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Index, getWhere, arginfo_phalcon_db_index_getwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Index, isConcurrent, arginfo_phalcon_db_index_isconcurrent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Index, isInvisible, arginfo_phalcon_db_index_isinvisible, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
