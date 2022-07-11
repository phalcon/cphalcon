
extern zend_class_entry *phalcon_mvc_model_managerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ManagerInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addbehavior, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, behavior, Phalcon\\Mvc\\Model\\BehaviorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addbelongsto, 0, 4, Phalcon\\Mvc\\Model\\RelationInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_TYPE_INFO(0, referencedModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, referencedFields)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addhasmany, 0, 4, Phalcon\\Mvc\\Model\\RelationInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_TYPE_INFO(0, referencedModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, referencedFields)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addhasone, 0, 4, Phalcon\\Mvc\\Model\\RelationInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_TYPE_INFO(0, referencedModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, referencedFields)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addhasonethrough, 0, 7, Phalcon\\Mvc\\Model\\RelationInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_TYPE_INFO(0, intermediateModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
	ZEND_ARG_TYPE_INFO(0, referencedModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, referencedFields)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addhasmanytomany, 0, 7, Phalcon\\Mvc\\Model\\RelationInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_TYPE_INFO(0, intermediateModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
	ZEND_ARG_TYPE_INFO(0, referencedModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, referencedFields)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_createbuilder, 0, 0, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_createquery, 0, 1, Phalcon\\Mvc\\Model\\QueryInterface, 0)
	ZEND_ARG_TYPE_INFO(0, phql, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_executequery, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, phql, IS_STRING, 0)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, types)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getbelongsto, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getbelongstorecords, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getbuilder, 0, 0, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasmany, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasmanyrecords, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasmanytomany, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasone, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasonethrough, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasoneandhasmany, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasonerecords, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getlastinitialized, 0, 0, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getlastquery, 0, 0, Phalcon\\Mvc\\Model\\QueryInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getmodelschema, 0, 1, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getmodelsource, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getreadconnection, 0, 1, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getreadconnectionservice, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getrelationbyalias, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getrelationrecords, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, relation, Phalcon\\Mvc\\Model\\RelationInterface, 0)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getrelations, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getrelationsbetween, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, first, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, second, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getwriteconnection, 0, 1, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getwriteconnectionservice, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_hasbelongsto, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_hashasmany, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_hashasone, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_hashasonethrough, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_hashasmanytomany, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelRelation, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_load, 0, 1, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_initialize, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_isinitialized, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_iskeepingsnapshots, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_isusingdynamicupdate, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_isvisiblemodelproperty, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_keepsnapshots, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, keepSnapshots, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_missingmethod, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_notifyevent, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_setconnectionservice, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, connectionService, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_setreadconnectionservice, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, connectionService, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_setmodelschema, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_setmodelsource, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, source, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_setwriteconnectionservice, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, connectionService, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_usedynamicupdate, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, dynamicUpdate, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_managerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addBehavior, arginfo_phalcon_mvc_model_managerinterface_addbehavior)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addBelongsTo, arginfo_phalcon_mvc_model_managerinterface_addbelongsto)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addHasMany, arginfo_phalcon_mvc_model_managerinterface_addhasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addHasOne, arginfo_phalcon_mvc_model_managerinterface_addhasone)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addHasOneThrough, arginfo_phalcon_mvc_model_managerinterface_addhasonethrough)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addHasManyToMany, arginfo_phalcon_mvc_model_managerinterface_addhasmanytomany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, createBuilder, arginfo_phalcon_mvc_model_managerinterface_createbuilder)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, createQuery, arginfo_phalcon_mvc_model_managerinterface_createquery)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, executeQuery, arginfo_phalcon_mvc_model_managerinterface_executequery)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getBelongsTo, arginfo_phalcon_mvc_model_managerinterface_getbelongsto)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getBelongsToRecords, arginfo_phalcon_mvc_model_managerinterface_getbelongstorecords)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getBuilder, arginfo_phalcon_mvc_model_managerinterface_getbuilder)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasMany, arginfo_phalcon_mvc_model_managerinterface_gethasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasManyRecords, arginfo_phalcon_mvc_model_managerinterface_gethasmanyrecords)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasManyToMany, arginfo_phalcon_mvc_model_managerinterface_gethasmanytomany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasOne, arginfo_phalcon_mvc_model_managerinterface_gethasone)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasOneThrough, arginfo_phalcon_mvc_model_managerinterface_gethasonethrough)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasOneAndHasMany, arginfo_phalcon_mvc_model_managerinterface_gethasoneandhasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasOneRecords, arginfo_phalcon_mvc_model_managerinterface_gethasonerecords)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getLastInitialized, arginfo_phalcon_mvc_model_managerinterface_getlastinitialized)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getLastQuery, arginfo_phalcon_mvc_model_managerinterface_getlastquery)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getModelSchema, arginfo_phalcon_mvc_model_managerinterface_getmodelschema)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getModelSource, arginfo_phalcon_mvc_model_managerinterface_getmodelsource)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getReadConnection, arginfo_phalcon_mvc_model_managerinterface_getreadconnection)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getReadConnectionService, arginfo_phalcon_mvc_model_managerinterface_getreadconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getRelationByAlias, arginfo_phalcon_mvc_model_managerinterface_getrelationbyalias)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getRelationRecords, arginfo_phalcon_mvc_model_managerinterface_getrelationrecords)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getRelations, arginfo_phalcon_mvc_model_managerinterface_getrelations)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getRelationsBetween, arginfo_phalcon_mvc_model_managerinterface_getrelationsbetween)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getWriteConnection, arginfo_phalcon_mvc_model_managerinterface_getwriteconnection)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getWriteConnectionService, arginfo_phalcon_mvc_model_managerinterface_getwriteconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, hasBelongsTo, arginfo_phalcon_mvc_model_managerinterface_hasbelongsto)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, hasHasMany, arginfo_phalcon_mvc_model_managerinterface_hashasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, hasHasOne, arginfo_phalcon_mvc_model_managerinterface_hashasone)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, hasHasOneThrough, arginfo_phalcon_mvc_model_managerinterface_hashasonethrough)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, hasHasManyToMany, arginfo_phalcon_mvc_model_managerinterface_hashasmanytomany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, load, arginfo_phalcon_mvc_model_managerinterface_load)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, initialize, arginfo_phalcon_mvc_model_managerinterface_initialize)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, isInitialized, arginfo_phalcon_mvc_model_managerinterface_isinitialized)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, isKeepingSnapshots, arginfo_phalcon_mvc_model_managerinterface_iskeepingsnapshots)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, isUsingDynamicUpdate, arginfo_phalcon_mvc_model_managerinterface_isusingdynamicupdate)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, isVisibleModelProperty, arginfo_phalcon_mvc_model_managerinterface_isvisiblemodelproperty)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, keepSnapshots, arginfo_phalcon_mvc_model_managerinterface_keepsnapshots)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, missingMethod, arginfo_phalcon_mvc_model_managerinterface_missingmethod)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, notifyEvent, arginfo_phalcon_mvc_model_managerinterface_notifyevent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, setConnectionService, arginfo_phalcon_mvc_model_managerinterface_setconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, setReadConnectionService, arginfo_phalcon_mvc_model_managerinterface_setreadconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, setModelSchema, arginfo_phalcon_mvc_model_managerinterface_setmodelschema)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, setModelSource, arginfo_phalcon_mvc_model_managerinterface_setmodelsource)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, setWriteConnectionService, arginfo_phalcon_mvc_model_managerinterface_setwriteconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, useDynamicUpdate, arginfo_phalcon_mvc_model_managerinterface_usedynamicupdate)
	PHP_FE_END
};
