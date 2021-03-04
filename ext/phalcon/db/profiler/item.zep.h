
extern zend_class_entry *phalcon_db_profiler_item_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Profiler_Item);

PHP_METHOD(Phalcon_Db_Profiler_Item, setFinalTime);
PHP_METHOD(Phalcon_Db_Profiler_Item, getFinalTime);
PHP_METHOD(Phalcon_Db_Profiler_Item, setInitialTime);
PHP_METHOD(Phalcon_Db_Profiler_Item, getInitialTime);
PHP_METHOD(Phalcon_Db_Profiler_Item, setSqlBindTypes);
PHP_METHOD(Phalcon_Db_Profiler_Item, getSqlBindTypes);
PHP_METHOD(Phalcon_Db_Profiler_Item, setSqlStatement);
PHP_METHOD(Phalcon_Db_Profiler_Item, getSqlStatement);
PHP_METHOD(Phalcon_Db_Profiler_Item, setSqlVariables);
PHP_METHOD(Phalcon_Db_Profiler_Item, getSqlVariables);
PHP_METHOD(Phalcon_Db_Profiler_Item, getTotalElapsedSeconds);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setfinaltime, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, finalTime, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_profiler_item_getfinaltime, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setinitialtime, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, initialTime, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_profiler_item_getinitialtime, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setsqlbindtypes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, sqlBindTypes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_profiler_item_getsqlbindtypes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setsqlstatement, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, sqlStatement, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_profiler_item_getsqlstatement, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setsqlvariables, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, sqlVariables, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_profiler_item_getsqlvariables, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_profiler_item_gettotalelapsedseconds, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_profiler_item_method_entry) {
	PHP_ME(Phalcon_Db_Profiler_Item, setFinalTime, arginfo_phalcon_db_profiler_item_setfinaltime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getFinalTime, arginfo_phalcon_db_profiler_item_getfinaltime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, setInitialTime, arginfo_phalcon_db_profiler_item_setinitialtime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getInitialTime, arginfo_phalcon_db_profiler_item_getinitialtime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, setSqlBindTypes, arginfo_phalcon_db_profiler_item_setsqlbindtypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getSqlBindTypes, arginfo_phalcon_db_profiler_item_getsqlbindtypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, setSqlStatement, arginfo_phalcon_db_profiler_item_setsqlstatement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getSqlStatement, arginfo_phalcon_db_profiler_item_getsqlstatement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, setSqlVariables, arginfo_phalcon_db_profiler_item_setsqlvariables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getSqlVariables, arginfo_phalcon_db_profiler_item_getsqlvariables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getTotalElapsedSeconds, arginfo_phalcon_db_profiler_item_gettotalelapsedseconds, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
