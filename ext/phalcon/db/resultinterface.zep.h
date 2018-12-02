
extern zend_class_entry *phalcon_db_resultinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_ResultInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_dataseek, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_setfetchmode, 0, 0, 1)
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, colNoOrClassNameOrObject)
	ZEND_ARG_INFO(0, ctorargs)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_resultinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, execute, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetch, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetchArray, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetchAll, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, numRows, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, dataSeek, arginfo_phalcon_db_resultinterface_dataseek)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, setFetchMode, arginfo_phalcon_db_resultinterface_setfetchmode)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, getInternalResult, NULL)
	PHP_FE_END
};
