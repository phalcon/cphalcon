
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
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelPrefix);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelPrefix);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSource);
PHP_METHOD(Phalcon_Mvc_Model_Manager, isVisibleModelProperty);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSource);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSchema);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSchema);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setConnectionService);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setWriteConnectionService);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setReadConnectionService);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnection);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getWriteConnection);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getConnection);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnectionService);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getWriteConnectionService);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getConnectionService);
PHP_METHOD(Phalcon_Mvc_Model_Manager, notifyEvent);
PHP_METHOD(Phalcon_Mvc_Model_Manager, missingMethod);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBehavior);
PHP_METHOD(Phalcon_Mvc_Model_Manager, keepSnapshots);
PHP_METHOD(Phalcon_Mvc_Model_Manager, isKeepingSnapshots);
PHP_METHOD(Phalcon_Mvc_Model_Manager, useDynamicUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Manager, isUsingDynamicUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasOne);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasOneThrough);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBelongsTo);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasManyToMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsBelongsTo);
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasOne);
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasOneThrough);
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasManyToMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationByAlias);
PHP_METHOD(Phalcon_Mvc_Model_Manager, _mergeFindParameters);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getReusableRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, hasBelongsTo);
PHP_METHOD(Phalcon_Mvc_Model_Manager, hasHasMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, hasHasOne);
PHP_METHOD(Phalcon_Mvc_Model_Manager, hasHasOneThrough);
PHP_METHOD(Phalcon_Mvc_Model_Manager, hasHasManyToMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setReusableRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, clearReusableObjects);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsToRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsTo);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOne);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneThrough);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyToMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneAndHasMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelations);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationsBetween);
PHP_METHOD(Phalcon_Mvc_Model_Manager, createQuery);
PHP_METHOD(Phalcon_Mvc_Model_Manager, executeQuery);
PHP_METHOD(Phalcon_Mvc_Model_Manager, createBuilder);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastQuery);
PHP_METHOD(Phalcon_Mvc_Model_Manager, __destruct);
PHP_METHOD(Phalcon_Mvc_Model_Manager, checkHasRelationship);
zend_object *zephir_init_properties_Phalcon_Mvc_Model_Manager(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_setdi, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_manager_getdi, 0, 0, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_seteventsmanager, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_manager_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_setcustomeventsmanager, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_manager_getcustomeventsmanager, 0, 1, Phalcon\\Events\\ManagerInterface, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_initialize, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_isinitialized, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_manager_getlastinitialized, 0, 0, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_manager_load, 0, 1, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_setmodelprefix, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_getmodelprefix, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_setmodelsource, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, source, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_isvisiblemodelproperty, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_getmodelsource, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_setmodelschema, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_getmodelschema, 0, 1, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_setconnectionservice, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, connectionService, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_setwriteconnectionservice, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, connectionService, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_setreadconnectionservice, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, connectionService, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_manager_getreadconnection, 0, 1, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_manager_getwriteconnection, 0, 1, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_manager_getconnection, 0, 2, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, connectionServices)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_getreadconnectionservice, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_getwriteconnectionservice, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_getconnectionservice, 0, 2, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, connectionServices)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_notifyevent, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_missingmethod, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_addbehavior, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, behavior, Phalcon\\Mvc\\Model\\BehaviorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_keepsnapshots, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, keepSnapshots, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_iskeepingsnapshots, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_usedynamicupdate, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, dynamicUpdate, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_isusingdynamicupdate, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_manager_addhasone, 0, 4, Phalcon\\Mvc\\Model\\RelationInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_TYPE_INFO(0, referencedModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_manager_addhasonethrough, 0, 7, Phalcon\\Mvc\\Model\\RelationInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_TYPE_INFO(0, intermediateModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
	ZEND_ARG_TYPE_INFO(0, referencedModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_manager_addbelongsto, 0, 4, Phalcon\\Mvc\\Model\\RelationInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_TYPE_INFO(0, referencedModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_manager_addhasmany, 0, 4, Phalcon\\Mvc\\Model\\RelationInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_TYPE_INFO(0, referencedModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_manager_addhasmanytomany, 0, 7, Phalcon\\Mvc\\Model\\RelationInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_TYPE_INFO(0, intermediateModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
	ZEND_ARG_TYPE_INFO(0, referencedModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_existsbelongsto, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_existshasmany, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_existshasone, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_existshasonethrough, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_existshasmanytomany, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getrelationbyalias, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager__mergefindparameters, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, findParamsOne)
	ZEND_ARG_INFO(0, findParamsTwo)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getrelationrecords, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, relation, Phalcon\\Mvc\\Model\\RelationInterface, 0)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getreusablerecords, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_hasbelongsto, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_hashasmany, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_hashasone, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_hashasonethrough, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_hashasmanytomany, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_setreusablerecords, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, records)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_clearreusableobjects, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getbelongstorecords, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasmanyrecords, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasonerecords, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_getbelongsto, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasmany, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasone, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasonethrough, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasmanytomany, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasoneandhasmany, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_getrelations, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getrelationsbetween, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, first, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, second, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_manager_createquery, 0, 1, Phalcon\\Mvc\\Model\\QueryInterface, 0)
	ZEND_ARG_TYPE_INFO(0, phql, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_executequery, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, phql, IS_STRING, 0)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, types)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_manager_createbuilder, 0, 0, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_manager_getlastquery, 0, 0, Phalcon\\Mvc\\Model\\QueryInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager___destruct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_manager_checkhasrelationship, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, collection, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_zephir_init_properties_phalcon_mvc_model_manager, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_manager_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Manager, setDI, arginfo_phalcon_mvc_model_manager_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getDI, arginfo_phalcon_mvc_model_manager_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setEventsManager, arginfo_phalcon_mvc_model_manager_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getEventsManager, arginfo_phalcon_mvc_model_manager_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setCustomEventsManager, arginfo_phalcon_mvc_model_manager_setcustomeventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getCustomEventsManager, arginfo_phalcon_mvc_model_manager_getcustomeventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, initialize, arginfo_phalcon_mvc_model_manager_initialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, isInitialized, arginfo_phalcon_mvc_model_manager_isinitialized, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getLastInitialized, arginfo_phalcon_mvc_model_manager_getlastinitialized, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, load, arginfo_phalcon_mvc_model_manager_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setModelPrefix, arginfo_phalcon_mvc_model_manager_setmodelprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getModelPrefix, arginfo_phalcon_mvc_model_manager_getmodelprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setModelSource, arginfo_phalcon_mvc_model_manager_setmodelsource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, isVisibleModelProperty, arginfo_phalcon_mvc_model_manager_isvisiblemodelproperty, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getModelSource, arginfo_phalcon_mvc_model_manager_getmodelsource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setModelSchema, arginfo_phalcon_mvc_model_manager_setmodelschema, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getModelSchema, arginfo_phalcon_mvc_model_manager_getmodelschema, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setConnectionService, arginfo_phalcon_mvc_model_manager_setconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setWriteConnectionService, arginfo_phalcon_mvc_model_manager_setwriteconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setReadConnectionService, arginfo_phalcon_mvc_model_manager_setreadconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getReadConnection, arginfo_phalcon_mvc_model_manager_getreadconnection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getWriteConnection, arginfo_phalcon_mvc_model_manager_getwriteconnection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getConnection, arginfo_phalcon_mvc_model_manager_getconnection, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Manager, getReadConnectionService, arginfo_phalcon_mvc_model_manager_getreadconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getWriteConnectionService, arginfo_phalcon_mvc_model_manager_getwriteconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getConnectionService, arginfo_phalcon_mvc_model_manager_getconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, notifyEvent, arginfo_phalcon_mvc_model_manager_notifyevent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, missingMethod, arginfo_phalcon_mvc_model_manager_missingmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addBehavior, arginfo_phalcon_mvc_model_manager_addbehavior, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, keepSnapshots, arginfo_phalcon_mvc_model_manager_keepsnapshots, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, isKeepingSnapshots, arginfo_phalcon_mvc_model_manager_iskeepingsnapshots, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, useDynamicUpdate, arginfo_phalcon_mvc_model_manager_usedynamicupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, isUsingDynamicUpdate, arginfo_phalcon_mvc_model_manager_isusingdynamicupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addHasOne, arginfo_phalcon_mvc_model_manager_addhasone, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addHasOneThrough, arginfo_phalcon_mvc_model_manager_addhasonethrough, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addBelongsTo, arginfo_phalcon_mvc_model_manager_addbelongsto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addHasMany, arginfo_phalcon_mvc_model_manager_addhasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addHasManyToMany, arginfo_phalcon_mvc_model_manager_addhasmanytomany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, existsBelongsTo, arginfo_phalcon_mvc_model_manager_existsbelongsto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, existsHasMany, arginfo_phalcon_mvc_model_manager_existshasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, existsHasOne, arginfo_phalcon_mvc_model_manager_existshasone, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, existsHasOneThrough, arginfo_phalcon_mvc_model_manager_existshasonethrough, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, existsHasManyToMany, arginfo_phalcon_mvc_model_manager_existshasmanytomany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelationByAlias, arginfo_phalcon_mvc_model_manager_getrelationbyalias, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, _mergeFindParameters, arginfo_phalcon_mvc_model_manager__mergefindparameters, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelationRecords, arginfo_phalcon_mvc_model_manager_getrelationrecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getReusableRecords, arginfo_phalcon_mvc_model_manager_getreusablerecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, hasBelongsTo, arginfo_phalcon_mvc_model_manager_hasbelongsto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, hasHasMany, arginfo_phalcon_mvc_model_manager_hashasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, hasHasOne, arginfo_phalcon_mvc_model_manager_hashasone, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, hasHasOneThrough, arginfo_phalcon_mvc_model_manager_hashasonethrough, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, hasHasManyToMany, arginfo_phalcon_mvc_model_manager_hashasmanytomany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setReusableRecords, arginfo_phalcon_mvc_model_manager_setreusablerecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, clearReusableObjects, arginfo_phalcon_mvc_model_manager_clearreusableobjects, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getBelongsToRecords, arginfo_phalcon_mvc_model_manager_getbelongstorecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasManyRecords, arginfo_phalcon_mvc_model_manager_gethasmanyrecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasOneRecords, arginfo_phalcon_mvc_model_manager_gethasonerecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getBelongsTo, arginfo_phalcon_mvc_model_manager_getbelongsto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasMany, arginfo_phalcon_mvc_model_manager_gethasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasOne, arginfo_phalcon_mvc_model_manager_gethasone, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasOneThrough, arginfo_phalcon_mvc_model_manager_gethasonethrough, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasManyToMany, arginfo_phalcon_mvc_model_manager_gethasmanytomany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasOneAndHasMany, arginfo_phalcon_mvc_model_manager_gethasoneandhasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelations, arginfo_phalcon_mvc_model_manager_getrelations, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelationsBetween, arginfo_phalcon_mvc_model_manager_getrelationsbetween, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, createQuery, arginfo_phalcon_mvc_model_manager_createquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, executeQuery, arginfo_phalcon_mvc_model_manager_executequery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, createBuilder, arginfo_phalcon_mvc_model_manager_createbuilder, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getLastQuery, arginfo_phalcon_mvc_model_manager_getlastquery, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Model_Manager, __destruct, arginfo_phalcon_mvc_model_manager___destruct, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
#else
	PHP_ME(Phalcon_Mvc_Model_Manager, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
#endif
	PHP_ME(Phalcon_Mvc_Model_Manager, checkHasRelationship, arginfo_phalcon_mvc_model_manager_checkhasrelationship, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
