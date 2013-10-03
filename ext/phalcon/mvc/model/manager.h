
extern zend_class_entry *phalcon_mvc_model_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Manager);

PHP_METHOD(Phalcon_Mvc_Model_Manager, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setEventsManager);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getEventsManager);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setCustomEventsManager);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getCustomEventsManager);
PHP_METHOD(Phalcon_Mvc_Model_Manager, initialize);
PHP_METHOD(Phalcon_Mvc_Model_Manager, isInitialized);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastInitialized);
PHP_METHOD(Phalcon_Mvc_Model_Manager, load);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSource);
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
PHP_METHOD(Phalcon_Mvc_Model_Manager, notifyEvent);
PHP_METHOD(Phalcon_Mvc_Model_Manager, missingMethod);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBehavior);
PHP_METHOD(Phalcon_Mvc_Model_Manager, keepSnapshots);
PHP_METHOD(Phalcon_Mvc_Model_Manager, isKeepingSnapshots);
PHP_METHOD(Phalcon_Mvc_Model_Manager, useDynamicUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Manager, isUsingDynamicUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasOne);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBelongsTo);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasManyToMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsBelongsTo);
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasOne);
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasManyToMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationByAlias);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReusableRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setReusableRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, clearReusableObjects);
PHP_METHOD(Phalcon_Mvc_Model_Manager, createBuilder);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setcustomeventsmanager, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getcustomeventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setmodelsource, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, source)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_notifyevent, 0, 0, 2)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_missingmethod, 0, 0, 3)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_addbehavior, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, behavior)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_keepsnapshots, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, keepSnapshots)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_iskeepingsnapshots, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_usedynamicupdate, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, dynamicUpdate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_isusingdynamicupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_addhasone, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_addbelongsto, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_addhasmany, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_addhasmanytomany, 0, 0, 7)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, intermediateModel)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_existsbelongsto, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_existshasmany, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_existshasone, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_existshasmanytomany, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getrelationbyalias, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getrelationrecords, 0, 0, 3)
	ZEND_ARG_INFO(0, relation)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, record)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getreusablerecords, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setreusablerecords, 0, 0, 3)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, records)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_createbuilder, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_manager_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Manager, setDI, arginfo_phalcon_mvc_model_manager_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setEventsManager, arginfo_phalcon_mvc_model_manager_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setCustomEventsManager, arginfo_phalcon_mvc_model_manager_setcustomeventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getCustomEventsManager, arginfo_phalcon_mvc_model_manager_getcustomeventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, initialize, arginfo_phalcon_mvc_model_manager_initialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, isInitialized, arginfo_phalcon_mvc_model_manager_isinitialized, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getLastInitialized, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, load, arginfo_phalcon_mvc_model_manager_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setModelSource, arginfo_phalcon_mvc_model_manager_setmodelsource, ZEND_ACC_PUBLIC)
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
	PHP_ME(Phalcon_Mvc_Model_Manager, notifyEvent, arginfo_phalcon_mvc_model_manager_notifyevent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, missingMethod, arginfo_phalcon_mvc_model_manager_missingmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addBehavior, arginfo_phalcon_mvc_model_manager_addbehavior, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, keepSnapshots, arginfo_phalcon_mvc_model_manager_keepsnapshots, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, isKeepingSnapshots, arginfo_phalcon_mvc_model_manager_iskeepingsnapshots, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, useDynamicUpdate, arginfo_phalcon_mvc_model_manager_usedynamicupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, isUsingDynamicUpdate, arginfo_phalcon_mvc_model_manager_isusingdynamicupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addHasOne, arginfo_phalcon_mvc_model_manager_addhasone, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addBelongsTo, arginfo_phalcon_mvc_model_manager_addbelongsto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addHasMany, arginfo_phalcon_mvc_model_manager_addhasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addHasManyToMany, arginfo_phalcon_mvc_model_manager_addhasmanytomany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, existsBelongsTo, arginfo_phalcon_mvc_model_manager_existsbelongsto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, existsHasMany, arginfo_phalcon_mvc_model_manager_existshasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, existsHasOne, arginfo_phalcon_mvc_model_manager_existshasone, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, existsHasManyToMany, arginfo_phalcon_mvc_model_manager_existshasmanytomany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelationByAlias, arginfo_phalcon_mvc_model_manager_getrelationbyalias, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelationRecords, arginfo_phalcon_mvc_model_manager_getrelationrecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getReusableRecords, arginfo_phalcon_mvc_model_manager_getreusablerecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setReusableRecords, arginfo_phalcon_mvc_model_manager_setreusablerecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, clearReusableObjects, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, createBuilder, arginfo_phalcon_mvc_model_manager_createbuilder, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
