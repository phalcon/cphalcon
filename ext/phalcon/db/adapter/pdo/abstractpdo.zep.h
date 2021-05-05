
extern zend_class_entry *phalcon_db_adapter_pdo_abstractpdo_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_AbstractPdo);

PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, __construct);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, affectedRows);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, begin);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, commit);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, close);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, connect);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, convertBoundParams);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, escapeString);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, execute);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, executePrepared);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, getErrorInfo);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, getInternalHandler);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, getTransactionLevel);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, isUnderTransaction);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, lastInsertId);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, prepare);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, query);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, rollback);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, getDsnDefaults);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_AbstractPdo, prepareRealSql);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, descriptor, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_affectedrows, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_begin, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, nesting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_commit, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, nesting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_close, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_connect, 0, 0, _IS_BOOL, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, descriptor, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, descriptor, 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_convertboundparams, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, sql, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, params, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, params, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_escapestring, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_execute, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, sqlStatement, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindTypes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_executeprepared, 0, 3, PDOStatement, 0)
	ZEND_ARG_OBJ_INFO(0, statement, PDOStatement, 0)
	ZEND_ARG_ARRAY_INFO(0, placeholders, 0)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_geterrorinfo, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_getinternalhandler, 0, 0, PDO, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_gettransactionlevel, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_isundertransaction, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, sequenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_prepare, 0, 1, PDOStatement, 0)
	ZEND_ARG_TYPE_INFO(0, sqlStatement, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_query, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, sqlStatement, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
#endif
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, bindTypes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_rollback, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, nesting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_getdsndefaults, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_abstractpdo_preparerealsql, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, statement, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_adapter_pdo_abstractpdo_method_entry) {
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, __construct, arginfo_phalcon_db_adapter_pdo_abstractpdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, affectedRows, arginfo_phalcon_db_adapter_pdo_abstractpdo_affectedrows, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, begin, arginfo_phalcon_db_adapter_pdo_abstractpdo_begin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, commit, arginfo_phalcon_db_adapter_pdo_abstractpdo_commit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, close, arginfo_phalcon_db_adapter_pdo_abstractpdo_close, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, connect, arginfo_phalcon_db_adapter_pdo_abstractpdo_connect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, convertBoundParams, arginfo_phalcon_db_adapter_pdo_abstractpdo_convertboundparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, escapeString, arginfo_phalcon_db_adapter_pdo_abstractpdo_escapestring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, execute, arginfo_phalcon_db_adapter_pdo_abstractpdo_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, executePrepared, arginfo_phalcon_db_adapter_pdo_abstractpdo_executeprepared, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, getErrorInfo, arginfo_phalcon_db_adapter_pdo_abstractpdo_geterrorinfo, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, getErrorInfo, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, getInternalHandler, arginfo_phalcon_db_adapter_pdo_abstractpdo_getinternalhandler, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, getTransactionLevel, arginfo_phalcon_db_adapter_pdo_abstractpdo_gettransactionlevel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, isUnderTransaction, arginfo_phalcon_db_adapter_pdo_abstractpdo_isundertransaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, lastInsertId, arginfo_phalcon_db_adapter_pdo_abstractpdo_lastinsertid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, prepare, arginfo_phalcon_db_adapter_pdo_abstractpdo_prepare, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, query, arginfo_phalcon_db_adapter_pdo_abstractpdo_query, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, rollback, arginfo_phalcon_db_adapter_pdo_abstractpdo_rollback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, getDsnDefaults, arginfo_phalcon_db_adapter_pdo_abstractpdo_getdsndefaults, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Db_Adapter_Pdo_AbstractPdo, prepareRealSql, arginfo_phalcon_db_adapter_pdo_abstractpdo_preparerealsql, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
