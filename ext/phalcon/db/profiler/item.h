
extern zend_class_entry *phalcon_db_profiler_item_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Profiler_Item);

PHP_METHOD(Phalcon_Db_Profiler_Item, setSQLStatement);
PHP_METHOD(Phalcon_Db_Profiler_Item, getSQLStatement);
PHP_METHOD(Phalcon_Db_Profiler_Item, setInitialTime);
PHP_METHOD(Phalcon_Db_Profiler_Item, setFinalTime);
PHP_METHOD(Phalcon_Db_Profiler_Item, getInitialTime);
PHP_METHOD(Phalcon_Db_Profiler_Item, getFinalTime);
PHP_METHOD(Phalcon_Db_Profiler_Item, getTotalElapsedSeconds);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setsqlstatement, 0, 0, 0)
	ZEND_ARG_INFO(0, sqlStatement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setinitialtime, 0, 0, 0)
	ZEND_ARG_INFO(0, initialTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setfinaltime, 0, 0, 0)
	ZEND_ARG_INFO(0, finalTime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_profiler_item_method_entry) {
	PHP_ME(Phalcon_Db_Profiler_Item, setSQLStatement, arginfo_phalcon_db_profiler_item_setsqlstatement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getSQLStatement, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, setInitialTime, arginfo_phalcon_db_profiler_item_setinitialtime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, setFinalTime, arginfo_phalcon_db_profiler_item_setfinaltime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getInitialTime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getFinalTime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getTotalElapsedSeconds, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
