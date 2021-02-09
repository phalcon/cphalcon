
extern zend_class_entry *phalcon_db_resultinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_ResultInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_dataseek, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, number, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, number)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_resultinterface_execute, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_resultinterface_execute, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_fetch, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_resultinterface_fetchall, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_resultinterface_fetchall, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_fetcharray, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_resultinterface_getinternalresult, 0, 0, PDOStatement, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_resultinterface_getinternalresult, 0, 0, IS_OBJECT, "PDOStatement", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_resultinterface_numrows, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_resultinterface_numrows, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_resultinterface_setfetchmode, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_resultinterface_setfetchmode, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, fetchMode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, fetchMode)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_resultinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, dataSeek, arginfo_phalcon_db_resultinterface_dataseek)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, execute, arginfo_phalcon_db_resultinterface_execute)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetch, arginfo_phalcon_db_resultinterface_fetch)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetchAll, arginfo_phalcon_db_resultinterface_fetchall)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetchArray, arginfo_phalcon_db_resultinterface_fetcharray)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, getInternalResult, arginfo_phalcon_db_resultinterface_getinternalresult)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, numRows, arginfo_phalcon_db_resultinterface_numrows)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, setFetchMode, arginfo_phalcon_db_resultinterface_setfetchmode)
	PHP_FE_END
};
