
extern zend_class_entry *phalcon_mvc_model_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model);

PHP_METHOD(Phalcon_Mvc_Model, __construct);
PHP_METHOD(Phalcon_Mvc_Model, __call);
PHP_METHOD(Phalcon_Mvc_Model, __callStatic);
PHP_METHOD(Phalcon_Mvc_Model, __get);
PHP_METHOD(Phalcon_Mvc_Model, __isset);
PHP_METHOD(Phalcon_Mvc_Model, __serialize);
PHP_METHOD(Phalcon_Mvc_Model, __set);
PHP_METHOD(Phalcon_Mvc_Model, __unserialize);
PHP_METHOD(Phalcon_Mvc_Model, addBehavior);
PHP_METHOD(Phalcon_Mvc_Model, appendMessage);
PHP_METHOD(Phalcon_Mvc_Model, assign);
PHP_METHOD(Phalcon_Mvc_Model, average);
PHP_METHOD(Phalcon_Mvc_Model, cloneResult);
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMap);
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMapHydrate);
PHP_METHOD(Phalcon_Mvc_Model, collectRelatedToSave);
PHP_METHOD(Phalcon_Mvc_Model, count);
PHP_METHOD(Phalcon_Mvc_Model, create);
PHP_METHOD(Phalcon_Mvc_Model, delete);
PHP_METHOD(Phalcon_Mvc_Model, dump);
PHP_METHOD(Phalcon_Mvc_Model, find);
PHP_METHOD(Phalcon_Mvc_Model, findFirst);
PHP_METHOD(Phalcon_Mvc_Model, fireEvent);
PHP_METHOD(Phalcon_Mvc_Model, fireEventCancel);
PHP_METHOD(Phalcon_Mvc_Model, getChangedFields);
PHP_METHOD(Phalcon_Mvc_Model, getDirtyState);
PHP_METHOD(Phalcon_Mvc_Model, getEventsManager);
PHP_METHOD(Phalcon_Mvc_Model, getMessages);
PHP_METHOD(Phalcon_Mvc_Model, getModelsManager);
PHP_METHOD(Phalcon_Mvc_Model, getModelsMetaData);
PHP_METHOD(Phalcon_Mvc_Model, getOperationMade);
PHP_METHOD(Phalcon_Mvc_Model, getOldSnapshotData);
PHP_METHOD(Phalcon_Mvc_Model, getReadConnection);
PHP_METHOD(Phalcon_Mvc_Model, getReadConnectionService);
PHP_METHOD(Phalcon_Mvc_Model, getRelated);
PHP_METHOD(Phalcon_Mvc_Model, isRelationshipLoaded);
PHP_METHOD(Phalcon_Mvc_Model, getSchema);
PHP_METHOD(Phalcon_Mvc_Model, getSnapshotData);
PHP_METHOD(Phalcon_Mvc_Model, getSource);
PHP_METHOD(Phalcon_Mvc_Model, getUpdatedFields);
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnection);
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnectionService);
PHP_METHOD(Phalcon_Mvc_Model, hasChanged);
PHP_METHOD(Phalcon_Mvc_Model, hasSnapshotData);
PHP_METHOD(Phalcon_Mvc_Model, hasUpdated);
PHP_METHOD(Phalcon_Mvc_Model, jsonSerialize);
PHP_METHOD(Phalcon_Mvc_Model, maximum);
PHP_METHOD(Phalcon_Mvc_Model, minimum);
PHP_METHOD(Phalcon_Mvc_Model, query);
PHP_METHOD(Phalcon_Mvc_Model, readAttribute);
PHP_METHOD(Phalcon_Mvc_Model, refresh);
PHP_METHOD(Phalcon_Mvc_Model, save);
PHP_METHOD(Phalcon_Mvc_Model, doSave);
PHP_METHOD(Phalcon_Mvc_Model, serialize);
PHP_METHOD(Phalcon_Mvc_Model, unserialize);
PHP_METHOD(Phalcon_Mvc_Model, setConnectionService);
PHP_METHOD(Phalcon_Mvc_Model, setDirtyState);
PHP_METHOD(Phalcon_Mvc_Model, setEventsManager);
PHP_METHOD(Phalcon_Mvc_Model, setReadConnectionService);
PHP_METHOD(Phalcon_Mvc_Model, setOldSnapshotData);
PHP_METHOD(Phalcon_Mvc_Model, setSnapshotData);
PHP_METHOD(Phalcon_Mvc_Model, setTransaction);
PHP_METHOD(Phalcon_Mvc_Model, getTransaction);
PHP_METHOD(Phalcon_Mvc_Model, setup);
PHP_METHOD(Phalcon_Mvc_Model, setWriteConnectionService);
PHP_METHOD(Phalcon_Mvc_Model, skipOperation);
PHP_METHOD(Phalcon_Mvc_Model, sum);
PHP_METHOD(Phalcon_Mvc_Model, toArray);
PHP_METHOD(Phalcon_Mvc_Model, update);
PHP_METHOD(Phalcon_Mvc_Model, writeAttribute);
PHP_METHOD(Phalcon_Mvc_Model, checkForeignKeysRestrict);
PHP_METHOD(Phalcon_Mvc_Model, checkForeignKeysReverseCascade);
PHP_METHOD(Phalcon_Mvc_Model, checkForeignKeysReverseRestrict);
PHP_METHOD(Phalcon_Mvc_Model, doLowInsert);
PHP_METHOD(Phalcon_Mvc_Model, doLowUpdate);
PHP_METHOD(Phalcon_Mvc_Model, has);
PHP_METHOD(Phalcon_Mvc_Model, getRelatedRecords);
PHP_METHOD(Phalcon_Mvc_Model, groupResult);
PHP_METHOD(Phalcon_Mvc_Model, invokeFinder);
PHP_METHOD(Phalcon_Mvc_Model, possibleSetter);
PHP_METHOD(Phalcon_Mvc_Model, preSave);
PHP_METHOD(Phalcon_Mvc_Model, preSaveRelatedRecords);
PHP_METHOD(Phalcon_Mvc_Model, postSave);
PHP_METHOD(Phalcon_Mvc_Model, postSaveRelatedRecords);
PHP_METHOD(Phalcon_Mvc_Model, allowEmptyStringValues);
PHP_METHOD(Phalcon_Mvc_Model, cancelOperation);
PHP_METHOD(Phalcon_Mvc_Model, belongsTo);
PHP_METHOD(Phalcon_Mvc_Model, getPreparedQuery);
PHP_METHOD(Phalcon_Mvc_Model, hasMany);
PHP_METHOD(Phalcon_Mvc_Model, hasManyToMany);
PHP_METHOD(Phalcon_Mvc_Model, hasOne);
PHP_METHOD(Phalcon_Mvc_Model, hasOneThrough);
PHP_METHOD(Phalcon_Mvc_Model, keepSnapshots);
PHP_METHOD(Phalcon_Mvc_Model, setSchema);
PHP_METHOD(Phalcon_Mvc_Model, setSource);
PHP_METHOD(Phalcon_Mvc_Model, skipAttributes);
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnCreate);
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnUpdate);
PHP_METHOD(Phalcon_Mvc_Model, useDynamicUpdate);
PHP_METHOD(Phalcon_Mvc_Model, validate);
PHP_METHOD(Phalcon_Mvc_Model, validationHasFailed);
PHP_METHOD(Phalcon_Mvc_Model, caseInsensitiveColumnMap);
PHP_METHOD(Phalcon_Mvc_Model, appendMessagesFrom);
zend_object *zephir_init_properties_Phalcon_Mvc_Model(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 1)
	ZEND_ARG_OBJ_INFO(0, modelsManager, Phalcon\\Mvc\\Model\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___call, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___callstatic, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model___isset, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model___serialize, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___set, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model___unserialize, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_addbehavior, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, behavior, Phalcon\\Mvc\\Model\\BehaviorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_appendmessage, 0, 1, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Messages\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_assign, 0, 1, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, whiteList)
	ZEND_ARG_INFO(0, dataColumnMap)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_average, 0, 0, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, parameters, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_cloneresult, 0, 2, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, base, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_TYPE_INFO(0, dirtyState, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_cloneresultmap, 0, 3, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, base)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_TYPE_INFO(0, dirtyState, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, keepSnapshots, _IS_BOOL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_cloneresultmaphydrate, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_TYPE_INFO(0, hydrationMode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_collectrelatedtosave, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_count, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_create, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_delete, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_dump, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_find, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_findfirst, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_fireevent, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_fireeventcancel, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_getchangedfields, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_getdirtystate, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_getmessages, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_getmodelsmanager, 0, 0, Phalcon\\Mvc\\Model\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_getmodelsmetadata, 0, 0, Phalcon\\Mvc\\Model\\MetaDataInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_getoperationmade, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_getoldsnapshotdata, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_getreadconnection, 0, 0, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_getreadconnectionservice, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_getrelated, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_isrelationshiploaded, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, relationshipAlias, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_getschema, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_getsnapshotdata, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_getsource, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_getupdatedfields, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_getwriteconnection, 0, 0, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_getwriteconnectionservice, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_haschanged, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, fieldName)
	ZEND_ARG_TYPE_INFO(0, allFields, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_hassnapshotdata, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_hasupdated, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, fieldName)
	ZEND_ARG_TYPE_INFO(0, allFields, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_jsonserialize, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_maximum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_minimum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_query, 0, 0, Phalcon\\Mvc\\Model\\CriteriaInterface, 0)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_readattribute, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_refresh, 0, 0, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_save, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_dosave, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, visited, Phalcon\\Support\\Collection\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_serialize, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_setconnectionservice, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, connectionService, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setdirtystate, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, dirtyState, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_setreadconnectionservice, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, connectionService, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setoldsnapshotdata, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, columnMap)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_setsnapshotdata, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, columnMap)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_settransaction, 0, 1, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, transaction, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_gettransaction, 0, 0, Phalcon\\Mvc\\Model\\TransactionInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_setup, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_setwriteconnectionservice, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, connectionService, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_skipoperation, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, skip, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_sum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_toarray, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, columns)
	ZEND_ARG_INFO(0, useGetter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_update, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_writeattribute, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_checkforeignkeysrestrict, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_checkforeignkeysreversecascade, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_checkforeignkeysreverserestrict, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_dolowinsert, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, metaData, Phalcon\\Mvc\\Model\\MetaDataInterface, 0)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, identityField)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_dolowupdate, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, metaData, Phalcon\\Mvc\\Model\\MetaDataInterface, 0)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_INFO(0, table)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_has, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, metaData, Phalcon\\Mvc\\Model\\MetaDataInterface, 0)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_getrelatedrecords, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_groupresult, 0, 2, Phalcon\\Mvc\\Model\\ResultsetInterface, 0)
	ZEND_ARG_TYPE_INFO(0, functionName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_invokefinder, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_possiblesetter, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_presave, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, metaData, Phalcon\\Mvc\\Model\\MetaDataInterface, 0)
	ZEND_ARG_TYPE_INFO(0, exists, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, identityField)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_presaverelatedrecords, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_INFO(0, related)
	ZEND_ARG_OBJ_INFO(0, visited, Phalcon\\Support\\Collection\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_postsave, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, success, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, exists, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_postsaverelatedrecords, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_INFO(0, related)
	ZEND_ARG_OBJ_INFO(0, visited, Phalcon\\Support\\Collection\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_allowemptystringvalues, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_canceloperation, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_belongsto, 0, 3, Phalcon\\Mvc\\Model\\Relation, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_TYPE_INFO(0, referenceModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, referencedFields)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_getpreparedquery, 0, 1, Phalcon\\Mvc\\Model\\QueryInterface, 0)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_hasmany, 0, 3, Phalcon\\Mvc\\Model\\Relation, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_TYPE_INFO(0, referenceModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, referencedFields)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_hasmanytomany, 0, 6, Phalcon\\Mvc\\Model\\Relation, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_TYPE_INFO(0, intermediateModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
	ZEND_ARG_TYPE_INFO(0, referenceModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, referencedFields)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_hasone, 0, 3, Phalcon\\Mvc\\Model\\Relation, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_TYPE_INFO(0, referenceModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, referencedFields)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_hasonethrough, 0, 6, Phalcon\\Mvc\\Model\\Relation, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_TYPE_INFO(0, intermediateModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
	ZEND_ARG_TYPE_INFO(0, referenceModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, referencedFields)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_keepsnapshots, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, keepSnapshot, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_setschema, 0, 1, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, schema, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_setsource, 0, 1, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, source, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_skipattributes, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_skipattributesoncreate, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_skipattributesonupdate, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_usedynamicupdate, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, dynamicUpdate, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_validate, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Filter\\Validation\\ValidationInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_validationhasfailed, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_caseinsensitivecolumnmap, 0, 2, IS_STRING, 0)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_appendmessagesfrom, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_zephir_init_properties_phalcon_mvc_model, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_method_entry) {
	PHP_ME(Phalcon_Mvc_Model, __construct, arginfo_phalcon_mvc_model___construct, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model, __call, arginfo_phalcon_mvc_model___call, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, __callStatic, arginfo_phalcon_mvc_model___callstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, __get, arginfo_phalcon_mvc_model___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, __isset, arginfo_phalcon_mvc_model___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, __serialize, arginfo_phalcon_mvc_model___serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, __set, arginfo_phalcon_mvc_model___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, __unserialize, arginfo_phalcon_mvc_model___unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, addBehavior, arginfo_phalcon_mvc_model_addbehavior, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, appendMessage, arginfo_phalcon_mvc_model_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, assign, arginfo_phalcon_mvc_model_assign, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, average, arginfo_phalcon_mvc_model_average, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, cloneResult, arginfo_phalcon_mvc_model_cloneresult, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, cloneResultMap, arginfo_phalcon_mvc_model_cloneresultmap, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, cloneResultMapHydrate, arginfo_phalcon_mvc_model_cloneresultmaphydrate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, collectRelatedToSave, arginfo_phalcon_mvc_model_collectrelatedtosave, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, count, arginfo_phalcon_mvc_model_count, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, create, arginfo_phalcon_mvc_model_create, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, delete, arginfo_phalcon_mvc_model_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, dump, arginfo_phalcon_mvc_model_dump, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, find, arginfo_phalcon_mvc_model_find, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, findFirst, arginfo_phalcon_mvc_model_findfirst, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, fireEvent, arginfo_phalcon_mvc_model_fireevent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, fireEventCancel, arginfo_phalcon_mvc_model_fireeventcancel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getChangedFields, arginfo_phalcon_mvc_model_getchangedfields, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getDirtyState, arginfo_phalcon_mvc_model_getdirtystate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getEventsManager, arginfo_phalcon_mvc_model_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getMessages, arginfo_phalcon_mvc_model_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getModelsManager, arginfo_phalcon_mvc_model_getmodelsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getModelsMetaData, arginfo_phalcon_mvc_model_getmodelsmetadata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getOperationMade, arginfo_phalcon_mvc_model_getoperationmade, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getOldSnapshotData, arginfo_phalcon_mvc_model_getoldsnapshotdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getReadConnection, arginfo_phalcon_mvc_model_getreadconnection, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getReadConnectionService, arginfo_phalcon_mvc_model_getreadconnectionservice, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getRelated, arginfo_phalcon_mvc_model_getrelated, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, isRelationshipLoaded, arginfo_phalcon_mvc_model_isrelationshiploaded, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getSchema, arginfo_phalcon_mvc_model_getschema, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getSnapshotData, arginfo_phalcon_mvc_model_getsnapshotdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getSource, arginfo_phalcon_mvc_model_getsource, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getUpdatedFields, arginfo_phalcon_mvc_model_getupdatedfields, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getWriteConnection, arginfo_phalcon_mvc_model_getwriteconnection, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getWriteConnectionService, arginfo_phalcon_mvc_model_getwriteconnectionservice, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, hasChanged, arginfo_phalcon_mvc_model_haschanged, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, hasSnapshotData, arginfo_phalcon_mvc_model_hassnapshotdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, hasUpdated, arginfo_phalcon_mvc_model_hasupdated, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, jsonSerialize, arginfo_phalcon_mvc_model_jsonserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, maximum, arginfo_phalcon_mvc_model_maximum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, minimum, arginfo_phalcon_mvc_model_minimum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, query, arginfo_phalcon_mvc_model_query, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, readAttribute, arginfo_phalcon_mvc_model_readattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, refresh, arginfo_phalcon_mvc_model_refresh, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, save, arginfo_phalcon_mvc_model_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, doSave, arginfo_phalcon_mvc_model_dosave, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, serialize, arginfo_phalcon_mvc_model_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, unserialize, arginfo_phalcon_mvc_model_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setConnectionService, arginfo_phalcon_mvc_model_setconnectionservice, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setDirtyState, arginfo_phalcon_mvc_model_setdirtystate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setEventsManager, arginfo_phalcon_mvc_model_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setReadConnectionService, arginfo_phalcon_mvc_model_setreadconnectionservice, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setOldSnapshotData, arginfo_phalcon_mvc_model_setoldsnapshotdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setSnapshotData, arginfo_phalcon_mvc_model_setsnapshotdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setTransaction, arginfo_phalcon_mvc_model_settransaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getTransaction, arginfo_phalcon_mvc_model_gettransaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setup, arginfo_phalcon_mvc_model_setup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, setWriteConnectionService, arginfo_phalcon_mvc_model_setwriteconnectionservice, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, skipOperation, arginfo_phalcon_mvc_model_skipoperation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, sum, arginfo_phalcon_mvc_model_sum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, toArray, arginfo_phalcon_mvc_model_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, update, arginfo_phalcon_mvc_model_update, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, writeAttribute, arginfo_phalcon_mvc_model_writeattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, checkForeignKeysRestrict, arginfo_phalcon_mvc_model_checkforeignkeysrestrict, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, checkForeignKeysReverseCascade, arginfo_phalcon_mvc_model_checkforeignkeysreversecascade, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, checkForeignKeysReverseRestrict, arginfo_phalcon_mvc_model_checkforeignkeysreverserestrict, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, doLowInsert, arginfo_phalcon_mvc_model_dolowinsert, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, doLowUpdate, arginfo_phalcon_mvc_model_dolowupdate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, has, arginfo_phalcon_mvc_model_has, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, getRelatedRecords, arginfo_phalcon_mvc_model_getrelatedrecords, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, groupResult, arginfo_phalcon_mvc_model_groupresult, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, invokeFinder, arginfo_phalcon_mvc_model_invokefinder, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, possibleSetter, arginfo_phalcon_mvc_model_possiblesetter, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, preSave, arginfo_phalcon_mvc_model_presave, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, preSaveRelatedRecords, arginfo_phalcon_mvc_model_presaverelatedrecords, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, postSave, arginfo_phalcon_mvc_model_postsave, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, postSaveRelatedRecords, arginfo_phalcon_mvc_model_postsaverelatedrecords, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, allowEmptyStringValues, arginfo_phalcon_mvc_model_allowemptystringvalues, ZEND_ACC_PROTECTED)
PHP_ME(Phalcon_Mvc_Model, cancelOperation, arginfo_phalcon_mvc_model_canceloperation, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, belongsTo, arginfo_phalcon_mvc_model_belongsto, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, getPreparedQuery, arginfo_phalcon_mvc_model_getpreparedquery, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, hasMany, arginfo_phalcon_mvc_model_hasmany, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, hasManyToMany, arginfo_phalcon_mvc_model_hasmanytomany, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, hasOne, arginfo_phalcon_mvc_model_hasone, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, hasOneThrough, arginfo_phalcon_mvc_model_hasonethrough, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, keepSnapshots, arginfo_phalcon_mvc_model_keepsnapshots, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, setSchema, arginfo_phalcon_mvc_model_setschema, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, setSource, arginfo_phalcon_mvc_model_setsource, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, skipAttributes, arginfo_phalcon_mvc_model_skipattributes, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, skipAttributesOnCreate, arginfo_phalcon_mvc_model_skipattributesoncreate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, skipAttributesOnUpdate, arginfo_phalcon_mvc_model_skipattributesonupdate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, useDynamicUpdate, arginfo_phalcon_mvc_model_usedynamicupdate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, validate, arginfo_phalcon_mvc_model_validate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, validationHasFailed, arginfo_phalcon_mvc_model_validationhasfailed, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, caseInsensitiveColumnMap, arginfo_phalcon_mvc_model_caseinsensitivecolumnmap, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, appendMessagesFrom, arginfo_phalcon_mvc_model_appendmessagesfrom, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
