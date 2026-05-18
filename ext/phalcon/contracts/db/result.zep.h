
extern zend_class_entry *phalcon_contracts_db_result_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Db_Result);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_contracts_db_result_dataseek, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, number, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_result_execute, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_contracts_db_result_fetch, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_result_fetchall, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_contracts_db_result_fetcharray, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_db_result_getinternalresult, 0, 0, PDOStatement, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_result_numrows, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_db_result_setfetchmode, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, fetchMode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_db_result_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Result, dataSeek, arginfo_phalcon_contracts_db_result_dataseek)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Result, execute, arginfo_phalcon_contracts_db_result_execute)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Result, fetch, arginfo_phalcon_contracts_db_result_fetch)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Result, fetchAll, arginfo_phalcon_contracts_db_result_fetchall)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Result, fetchArray, arginfo_phalcon_contracts_db_result_fetcharray)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Result, getInternalResult, arginfo_phalcon_contracts_db_result_getinternalresult)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Result, numRows, arginfo_phalcon_contracts_db_result_numrows)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Db_Result, setFetchMode, arginfo_phalcon_contracts_db_result_setfetchmode)
	PHP_FE_END
};
