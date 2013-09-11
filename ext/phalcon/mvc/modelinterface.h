
extern zend_class_entry *phalcon_mvc_modelinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_ModelInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, modelsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_settransaction, 0, 0, 0)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setconnectionservice, 0, 0, 0)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setwriteconnectionservice, 0, 0, 0)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setreadconnectionservice, 0, 0, 0)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_assign, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, columnMap)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_cloneresultmap, 0, 0, 0)
	ZEND_ARG_INFO(0, base)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_INFO(0, dirtyState)
	ZEND_ARG_INFO(0, keepSnapshots)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_cloneresult, 0, 0, 0)
	ZEND_ARG_INFO(0, base)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, dirtyState)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_cloneresultmaphydrate, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
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
	ZEND_ARG_INFO(0, dependencyInjector)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_fireevent, 0, 0, 0)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_fireeventcancel, 0, 0, 0)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_appendmessage, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_readattribute, 0, 0, 0)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_writeattribute, 0, 0, 0)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_getrelated, 0, 0, 0)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_modelinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, __construct, arginfo_phalcon_mvc_modelinterface___construct)
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
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, assign, arginfo_phalcon_mvc_modelinterface_assign)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, cloneResultMap, arginfo_phalcon_mvc_modelinterface_cloneresultmap)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, cloneResult, arginfo_phalcon_mvc_modelinterface_cloneresult)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, cloneResultMapHydrate, arginfo_phalcon_mvc_modelinterface_cloneresultmaphydrate)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, find, arginfo_phalcon_mvc_modelinterface_find)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, findFirst, arginfo_phalcon_mvc_modelinterface_findfirst)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, query, arginfo_phalcon_mvc_modelinterface_query)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, count, arginfo_phalcon_mvc_modelinterface_count)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, sum, arginfo_phalcon_mvc_modelinterface_sum)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, maximum, arginfo_phalcon_mvc_modelinterface_maximum)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, minimum, arginfo_phalcon_mvc_modelinterface_minimum)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, average, arginfo_phalcon_mvc_modelinterface_average)
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
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, readAttribute, arginfo_phalcon_mvc_modelinterface_readattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, writeAttribute, arginfo_phalcon_mvc_modelinterface_writeattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getRelated, arginfo_phalcon_mvc_modelinterface_getrelated)
	PHP_FE_END
};
