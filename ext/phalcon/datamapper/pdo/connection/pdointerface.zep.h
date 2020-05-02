
extern zend_class_entry *phalcon_datamapper_pdo_connection_pdointerface_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Connection_PdoInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_begintransaction, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_begintransaction, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_commit, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_commit, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_errorcode, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_errorcode, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_errorinfo, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_errorinfo, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_exec, 0, 1, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_exec, 0, 1, IS_LONG, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, statement)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_getattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attribute, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, attribute)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_getavailabledrivers, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_getavailabledrivers, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_intransaction, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_intransaction, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_lastinsertid, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_lastinsertid, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_prepare, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, statement)
#endif
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_query, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statement, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, statement)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_quote, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_quote, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_rollback, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_rollback, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_setattribute, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connection_pdointerface_setattribute, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attribute, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, attribute)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_pdo_connection_pdointerface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_PdoInterface, beginTransaction, arginfo_phalcon_datamapper_pdo_connection_pdointerface_begintransaction)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_PdoInterface, commit, arginfo_phalcon_datamapper_pdo_connection_pdointerface_commit)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_PdoInterface, errorCode, arginfo_phalcon_datamapper_pdo_connection_pdointerface_errorcode)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_PdoInterface, errorInfo, arginfo_phalcon_datamapper_pdo_connection_pdointerface_errorinfo)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_PdoInterface, exec, arginfo_phalcon_datamapper_pdo_connection_pdointerface_exec)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_PdoInterface, getAttribute, arginfo_phalcon_datamapper_pdo_connection_pdointerface_getattribute)
	ZEND_FENTRY(getAvailableDrivers, NULL, arginfo_phalcon_datamapper_pdo_connection_pdointerface_getavailabledrivers, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_PdoInterface, inTransaction, arginfo_phalcon_datamapper_pdo_connection_pdointerface_intransaction)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_PdoInterface, lastInsertId, arginfo_phalcon_datamapper_pdo_connection_pdointerface_lastinsertid)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_PdoInterface, prepare, arginfo_phalcon_datamapper_pdo_connection_pdointerface_prepare)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_PdoInterface, query, arginfo_phalcon_datamapper_pdo_connection_pdointerface_query)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_PdoInterface, quote, arginfo_phalcon_datamapper_pdo_connection_pdointerface_quote)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_PdoInterface, rollBack, arginfo_phalcon_datamapper_pdo_connection_pdointerface_rollback)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_Connection_PdoInterface, setAttribute, arginfo_phalcon_datamapper_pdo_connection_pdointerface_setattribute)
	PHP_FE_END
};
