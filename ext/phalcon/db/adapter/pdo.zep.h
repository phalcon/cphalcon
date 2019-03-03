
extern zend_class_entry *phalcon_db_adapter_pdo_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo);

PHP_METHOD(Phalcon_Db_Adapter_Pdo, getDsnDefaults);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, __construct);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, affectedRows);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, begin);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, commit);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, close);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, connect);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, convertBoundParams);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, escapeString);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, execute);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, executePrepared);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, getErrorInfo);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, getInternalHandler);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, getTransactionLevel);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, isUnderTransaction);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, lastInsertId);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, prepare);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, query);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, rollback);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_getdsndefaults, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_getdsndefaults, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, descriptor, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_affectedrows, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_affectedrows, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_begin, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_begin, 0, 0, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, nesting, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, nesting)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_commit, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_commit, 0, 0, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, nesting, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, nesting)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_close, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_close, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_connect, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_connect, 0, 0, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, descriptor, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_convertboundparams, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_convertboundparams, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sql, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sql)
#endif
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_escapestring, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_escapestring, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, str)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_execute, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_execute, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sqlStatement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sqlStatement)
#endif
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_pdo_executeprepared, 0, 3, PDOStatement, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_executeprepared, 0, 3, IS_OBJECT, "PDOStatement", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, statement, PDOStatement, 0)
	ZEND_ARG_ARRAY_INFO(0, placeholders, 0)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_pdo_getinternalhandler, 0, 0, Pdo, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_getinternalhandler, 0, 0, IS_OBJECT, "Pdo", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_gettransactionlevel, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_gettransactionlevel, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_isundertransaction, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_isundertransaction, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, sequenceName)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_pdo_prepare, 0, 1, PDOStatement, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_prepare, 0, 1, IS_OBJECT, "PDOStatement", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sqlStatement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sqlStatement)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_query, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sqlStatement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sqlStatement)
#endif
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_rollback, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdo_rollback, 0, 0, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, nesting, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, nesting)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_adapter_pdo_method_entry) {
	PHP_ME(Phalcon_Db_Adapter_Pdo, getDsnDefaults, arginfo_phalcon_db_adapter_pdo_getdsndefaults, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Db_Adapter_Pdo, __construct, arginfo_phalcon_db_adapter_pdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Adapter_Pdo, affectedRows, arginfo_phalcon_db_adapter_pdo_affectedrows, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, begin, arginfo_phalcon_db_adapter_pdo_begin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, commit, arginfo_phalcon_db_adapter_pdo_commit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, close, arginfo_phalcon_db_adapter_pdo_close, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, connect, arginfo_phalcon_db_adapter_pdo_connect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, convertBoundParams, arginfo_phalcon_db_adapter_pdo_convertboundparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, escapeString, arginfo_phalcon_db_adapter_pdo_escapestring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, execute, arginfo_phalcon_db_adapter_pdo_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, executePrepared, arginfo_phalcon_db_adapter_pdo_executeprepared, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, getErrorInfo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, getInternalHandler, arginfo_phalcon_db_adapter_pdo_getinternalhandler, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, getTransactionLevel, arginfo_phalcon_db_adapter_pdo_gettransactionlevel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, isUnderTransaction, arginfo_phalcon_db_adapter_pdo_isundertransaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, lastInsertId, arginfo_phalcon_db_adapter_pdo_lastinsertid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, prepare, arginfo_phalcon_db_adapter_pdo_prepare, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, query, arginfo_phalcon_db_adapter_pdo_query, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, rollback, arginfo_phalcon_db_adapter_pdo_rollback, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
