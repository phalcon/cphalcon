
extern zend_class_entry *phalcon_db_result_pdoresult_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Result_PdoResult);

PHP_METHOD(Phalcon_Db_Result_PdoResult, __construct);
PHP_METHOD(Phalcon_Db_Result_PdoResult, dataSeek);
PHP_METHOD(Phalcon_Db_Result_PdoResult, execute);
PHP_METHOD(Phalcon_Db_Result_PdoResult, fetch);
PHP_METHOD(Phalcon_Db_Result_PdoResult, fetchAll);
PHP_METHOD(Phalcon_Db_Result_PdoResult, fetchArray);
PHP_METHOD(Phalcon_Db_Result_PdoResult, getInternalResult);
PHP_METHOD(Phalcon_Db_Result_PdoResult, numRows);
PHP_METHOD(Phalcon_Db_Result_PdoResult, setFetchMode);
zend_object *zephir_init_properties_Phalcon_Db_Result_PdoResult(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_result_pdoresult___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, result, PDOStatement, 0)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_result_pdoresult_dataseek, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, number, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_result_pdoresult_execute, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_result_pdoresult_fetch, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, fetchStyle, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, cursorOrientation, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, cursorOffset, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_result_pdoresult_fetchall, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, fetchStyle, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, fetchArgument, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctorArgs, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_result_pdoresult_fetcharray, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_result_pdoresult_getinternalresult, 0, 0, PDOStatement, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_result_pdoresult_numrows, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_result_pdoresult_setfetchmode, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, fetchMode, IS_LONG, 0)
	ZEND_ARG_INFO(0, colNoOrClassNameOrObject)
	ZEND_ARG_INFO(0, ctorargs)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_result_pdoresult_zephir_init_properties_phalcon_db_result_pdoresult, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_result_pdoresult_method_entry) {
	PHP_ME(Phalcon_Db_Result_PdoResult, __construct, arginfo_phalcon_db_result_pdoresult___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Result_PdoResult, dataSeek, arginfo_phalcon_db_result_pdoresult_dataseek, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_PdoResult, execute, arginfo_phalcon_db_result_pdoresult_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_PdoResult, fetch, arginfo_phalcon_db_result_pdoresult_fetch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_PdoResult, fetchAll, arginfo_phalcon_db_result_pdoresult_fetchall, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Db_Result_PdoResult, fetchArray, arginfo_phalcon_db_result_pdoresult_fetcharray, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Db_Result_PdoResult, fetchArray, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Db_Result_PdoResult, getInternalResult, arginfo_phalcon_db_result_pdoresult_getinternalresult, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_PdoResult, numRows, arginfo_phalcon_db_result_pdoresult_numrows, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_PdoResult, setFetchMode, arginfo_phalcon_db_result_pdoresult_setfetchmode, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
