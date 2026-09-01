
extern zend_class_entry *phalcon_contracts_db_index_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Db_Index);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_index_getcolumns, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_index_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_index_gettype, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_db_index_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Index, getColumns, arginfo_phalcon_contracts_db_index_getcolumns)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Index, getName, arginfo_phalcon_contracts_db_index_getname)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Index, getType, arginfo_phalcon_contracts_db_index_gettype)
	PHP_FE_END
};
