
extern zend_class_entry *phalcon_db_result_pdo_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Result_Pdo);

PHP_METHOD(Phalcon_Db_Result_Pdo, __construct);
PHP_METHOD(Phalcon_Db_Result_Pdo, dataSeek);
PHP_METHOD(Phalcon_Db_Result_Pdo, execute);
PHP_METHOD(Phalcon_Db_Result_Pdo, fetch);
PHP_METHOD(Phalcon_Db_Result_Pdo, fetchAll);
PHP_METHOD(Phalcon_Db_Result_Pdo, fetchArray);
PHP_METHOD(Phalcon_Db_Result_Pdo, getInternalResult);
PHP_METHOD(Phalcon_Db_Result_Pdo, numRows);
PHP_METHOD(Phalcon_Db_Result_Pdo, setFetchMode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_result_pdo___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, result, PDOStatement, 0)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_result_pdo_dataseek, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_result_pdo_dataseek, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_result_pdo_dataseek, 0, 0, 1)
#define arginfo_phalcon_db_result_pdo_dataseek NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, number, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, number)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_result_pdo_execute, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_result_pdo_execute, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_result_pdo_fetch, 0, 0, 0)
	ZEND_ARG_INFO(0, fetchStyle)
	ZEND_ARG_INFO(0, cursorOrientation)
	ZEND_ARG_INFO(0, cursorOffset)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_result_pdo_fetchall, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_result_pdo_fetchall, 0, 0, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, fetchStyle)
	ZEND_ARG_INFO(0, fetchArgument)
	ZEND_ARG_INFO(0, ctorArgs)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_result_pdo_fetcharray, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_result_pdo_getinternalresult, 0, 0, PDOStatement, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_result_pdo_getinternalresult, 0, 0, IS_OBJECT, "PDOStatement", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_result_pdo_numrows, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_result_pdo_numrows, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_result_pdo_setfetchmode, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_result_pdo_setfetchmode, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, fetchMode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, fetchMode)
#endif
	ZEND_ARG_INFO(0, colNoOrClassNameOrObject)
	ZEND_ARG_INFO(0, ctorargs)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_result_pdo_method_entry) {
	PHP_ME(Phalcon_Db_Result_Pdo, __construct, arginfo_phalcon_db_result_pdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Result_Pdo, dataSeek, arginfo_phalcon_db_result_pdo_dataseek, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, execute, arginfo_phalcon_db_result_pdo_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, fetch, arginfo_phalcon_db_result_pdo_fetch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, fetchAll, arginfo_phalcon_db_result_pdo_fetchall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, fetchArray, arginfo_phalcon_db_result_pdo_fetcharray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, getInternalResult, arginfo_phalcon_db_result_pdo_getinternalresult, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, numRows, arginfo_phalcon_db_result_pdo_numrows, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, setFetchMode, arginfo_phalcon_db_result_pdo_setfetchmode, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
