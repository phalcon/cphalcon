
extern zend_class_entry *phalcon_mvc_model_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Manager);

PHP_METHOD(Phalcon_Mvc_Model_Manager, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setEventsManager);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getEventsManager);
PHP_METHOD(Phalcon_Mvc_Model_Manager, initialize);
PHP_METHOD(Phalcon_Mvc_Model_Manager, isInitialized);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastInitialized);
PHP_METHOD(Phalcon_Mvc_Model_Manager, load);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSource);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSchema);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSchema);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setConnectionService);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setWriteConnectionService);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setReadConnectionService);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnection);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getWriteConnection);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnectionService);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getWriteConnectionService);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationByAlias);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_initialize, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_isinitialized, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_load, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, newInstance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getmodelsource, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setmodelschema, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getmodelschema, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setconnectionservice, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setwriteconnectionservice, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setreadconnectionservice, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getreadconnection, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getwriteconnection, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getreadconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getwriteconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getrelationbyalias, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_manager_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Manager, setDI, arginfo_phalcon_mvc_model_manager_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setEventsManager, arginfo_phalcon_mvc_model_manager_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, initialize, arginfo_phalcon_mvc_model_manager_initialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, isInitialized, arginfo_phalcon_mvc_model_manager_isinitialized, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getLastInitialized, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, load, arginfo_phalcon_mvc_model_manager_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getModelSource, arginfo_phalcon_mvc_model_manager_getmodelsource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setModelSchema, arginfo_phalcon_mvc_model_manager_setmodelschema, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getModelSchema, arginfo_phalcon_mvc_model_manager_getmodelschema, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setConnectionService, arginfo_phalcon_mvc_model_manager_setconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setWriteConnectionService, arginfo_phalcon_mvc_model_manager_setwriteconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setReadConnectionService, arginfo_phalcon_mvc_model_manager_setreadconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getReadConnection, arginfo_phalcon_mvc_model_manager_getreadconnection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getWriteConnection, arginfo_phalcon_mvc_model_manager_getwriteconnection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getReadConnectionService, arginfo_phalcon_mvc_model_manager_getreadconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getWriteConnectionService, arginfo_phalcon_mvc_model_manager_getwriteconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelationByAlias, arginfo_phalcon_mvc_model_manager_getrelationbyalias, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
