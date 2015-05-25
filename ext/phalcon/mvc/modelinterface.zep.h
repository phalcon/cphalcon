
extern zend_class_entry *phalcon_mvc_modelinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_ModelInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_settransaction, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, transaction, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setwriteconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setreadconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setdirtystate, 0, 0, 1)
	ZEND_ARG_INFO(0, dirtyState)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_assign, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, dataColumnMap)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_cloneresultmap, 0, 0, 3)
	ZEND_ARG_INFO(0, base)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_INFO(0, dirtyState)
	ZEND_ARG_INFO(0, keepSnapshots)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_cloneresult, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, base, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, dirtyState)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_cloneresultmaphydrate, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_INFO(0, hydrationMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_find, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_findfirst, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_query, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_count, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_sum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_maximum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_minimum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_average, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_fireevent, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_fireeventcancel, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_appendmessage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Mvc\\Model\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_save, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_create, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_update, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_skipoperation, 0, 0, 1)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_writeattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_getrelated, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setsnapshotdata, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, columnMap)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_modelinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setTransaction, arginfo_phalcon_mvc_modelinterface_settransaction)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getSource, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getSchema, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setConnectionService, arginfo_phalcon_mvc_modelinterface_setconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setWriteConnectionService, arginfo_phalcon_mvc_modelinterface_setwriteconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setReadConnectionService, arginfo_phalcon_mvc_modelinterface_setreadconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getReadConnectionService, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getWriteConnectionService, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getReadConnection, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getWriteConnection, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setDirtyState, arginfo_phalcon_mvc_modelinterface_setdirtystate)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getDirtyState, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, assign, arginfo_phalcon_mvc_modelinterface_assign)
	ZEND_FENTRY(cloneResultMap, NULL, arginfo_phalcon_mvc_modelinterface_cloneresultmap, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(cloneResult, NULL, arginfo_phalcon_mvc_modelinterface_cloneresult, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(cloneResultMapHydrate, NULL, arginfo_phalcon_mvc_modelinterface_cloneresultmaphydrate, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(find, NULL, arginfo_phalcon_mvc_modelinterface_find, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(findFirst, NULL, arginfo_phalcon_mvc_modelinterface_findfirst, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(query, NULL, arginfo_phalcon_mvc_modelinterface_query, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(count, NULL, arginfo_phalcon_mvc_modelinterface_count, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(sum, NULL, arginfo_phalcon_mvc_modelinterface_sum, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(maximum, NULL, arginfo_phalcon_mvc_modelinterface_maximum, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(minimum, NULL, arginfo_phalcon_mvc_modelinterface_minimum, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(average, NULL, arginfo_phalcon_mvc_modelinterface_average, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, fireEvent, arginfo_phalcon_mvc_modelinterface_fireevent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, fireEventCancel, arginfo_phalcon_mvc_modelinterface_fireeventcancel)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, appendMessage, arginfo_phalcon_mvc_modelinterface_appendmessage)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, validationHasFailed, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, save, arginfo_phalcon_mvc_modelinterface_save)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, create, arginfo_phalcon_mvc_modelinterface_create)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, update, arginfo_phalcon_mvc_modelinterface_update)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, delete, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getOperationMade, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, refresh, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, skipOperation, arginfo_phalcon_mvc_modelinterface_skipoperation)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, readAttribute, arginfo_phalcon_mvc_modelinterface_readattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, writeAttribute, arginfo_phalcon_mvc_modelinterface_writeattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getRelated, arginfo_phalcon_mvc_modelinterface_getrelated)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setSnapshotData, arginfo_phalcon_mvc_modelinterface_setsnapshotdata)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, reset, NULL)
	PHP_FE_END
};
