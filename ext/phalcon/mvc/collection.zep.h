
extern zend_class_entry *phalcon_mvc_collection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection);

PHP_METHOD(Phalcon_Mvc_Collection, __construct);
PHP_METHOD(Phalcon_Mvc_Collection, setId);
PHP_METHOD(Phalcon_Mvc_Collection, getId);
PHP_METHOD(Phalcon_Mvc_Collection, setDI);
PHP_METHOD(Phalcon_Mvc_Collection, getDI);
PHP_METHOD(Phalcon_Mvc_Collection, setEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection, getEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection, getCollectionManager);
PHP_METHOD(Phalcon_Mvc_Collection, getReservedAttributes);
PHP_METHOD(Phalcon_Mvc_Collection, useImplicitObjectIds);
PHP_METHOD(Phalcon_Mvc_Collection, setSource);
PHP_METHOD(Phalcon_Mvc_Collection, getSource);
PHP_METHOD(Phalcon_Mvc_Collection, setConnectionService);
PHP_METHOD(Phalcon_Mvc_Collection, getConnectionService);
PHP_METHOD(Phalcon_Mvc_Collection, getConnection);
PHP_METHOD(Phalcon_Mvc_Collection, readAttribute);
PHP_METHOD(Phalcon_Mvc_Collection, writeAttribute);
PHP_METHOD(Phalcon_Mvc_Collection, cloneResult);
PHP_METHOD(Phalcon_Mvc_Collection, _getResultset);
PHP_METHOD(Phalcon_Mvc_Collection, _getGroupResultset);
PHP_METHOD(Phalcon_Mvc_Collection, _preSave);
PHP_METHOD(Phalcon_Mvc_Collection, _postSave);
PHP_METHOD(Phalcon_Mvc_Collection, validate);
PHP_METHOD(Phalcon_Mvc_Collection, validationHasFailed);
PHP_METHOD(Phalcon_Mvc_Collection, fireEvent);
PHP_METHOD(Phalcon_Mvc_Collection, fireEventCancel);
PHP_METHOD(Phalcon_Mvc_Collection, _cancelOperation);
PHP_METHOD(Phalcon_Mvc_Collection, _exists);
PHP_METHOD(Phalcon_Mvc_Collection, getMessages);
PHP_METHOD(Phalcon_Mvc_Collection, appendMessage);
PHP_METHOD(Phalcon_Mvc_Collection, save);
PHP_METHOD(Phalcon_Mvc_Collection, findById);
PHP_METHOD(Phalcon_Mvc_Collection, findFirst);
PHP_METHOD(Phalcon_Mvc_Collection, find);
PHP_METHOD(Phalcon_Mvc_Collection, count);
PHP_METHOD(Phalcon_Mvc_Collection, aggregate);
PHP_METHOD(Phalcon_Mvc_Collection, summatory);
PHP_METHOD(Phalcon_Mvc_Collection, delete);
PHP_METHOD(Phalcon_Mvc_Collection, toArray);
PHP_METHOD(Phalcon_Mvc_Collection, serialize);
PHP_METHOD(Phalcon_Mvc_Collection, unserialize);
PHP_METHOD(Phalcon_Mvc_Collection, addBehavior);
PHP_METHOD(Phalcon_Mvc_Collection, skipOperation);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
	ZEND_ARG_OBJ_INFO(0, modelsManager, Phalcon\\Mvc\\Collection\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Mvc\\Collection\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_useimplicitobjectids, 0, 0, 1)
	ZEND_ARG_INFO(0, useImplicitObjectIds)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_setsource, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_setconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_writeattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_cloneresult, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, document, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection__getresultset, 0, 0, 4)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_INFO(0, connection)
	ZEND_ARG_INFO(0, unique)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection__getgroupresultset, 0, 0, 3)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Mvc\\Collection, 0)
	ZEND_ARG_INFO(0, connection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection__presave, 0, 0, 3)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, disableEvents)
	ZEND_ARG_INFO(0, exists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection__postsave, 0, 0, 3)
	ZEND_ARG_INFO(0, disableEvents)
	ZEND_ARG_INFO(0, success)
	ZEND_ARG_INFO(0, exists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_validate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Mvc\\Model\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_fireevent, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_fireeventcancel, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection__canceloperation, 0, 0, 1)
	ZEND_ARG_INFO(0, disableEvents)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection__exists, 0, 0, 1)
	ZEND_ARG_INFO(0, collection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_appendmessage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Mvc\\Model\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_findbyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_findfirst, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_find, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_count, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_aggregate, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_summatory, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, finalize)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_addbehavior, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, behavior, Phalcon\\Mvc\\Collection\\BehaviorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_skipoperation, 0, 0, 1)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collection_method_entry) {
	PHP_ME(Phalcon_Mvc_Collection, __construct, arginfo_phalcon_mvc_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Collection, setId, arginfo_phalcon_mvc_collection_setid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, setDI, arginfo_phalcon_mvc_collection_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, setEventsManager, arginfo_phalcon_mvc_collection_seteventsmanager, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, getEventsManager, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, getCollectionManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, getReservedAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, useImplicitObjectIds, arginfo_phalcon_mvc_collection_useimplicitobjectids, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, setSource, arginfo_phalcon_mvc_collection_setsource, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, getSource, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, setConnectionService, arginfo_phalcon_mvc_collection_setconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, getConnectionService, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, getConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, readAttribute, arginfo_phalcon_mvc_collection_readattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, writeAttribute, arginfo_phalcon_mvc_collection_writeattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, cloneResult, arginfo_phalcon_mvc_collection_cloneresult, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, _getResultset, arginfo_phalcon_mvc_collection__getresultset, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, _getGroupResultset, arginfo_phalcon_mvc_collection__getgroupresultset, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, _preSave, arginfo_phalcon_mvc_collection__presave, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Collection, _postSave, arginfo_phalcon_mvc_collection__postsave, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Collection, validate, arginfo_phalcon_mvc_collection_validate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, validationHasFailed, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, fireEvent, arginfo_phalcon_mvc_collection_fireevent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, fireEventCancel, arginfo_phalcon_mvc_collection_fireeventcancel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, _cancelOperation, arginfo_phalcon_mvc_collection__canceloperation, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, _exists, arginfo_phalcon_mvc_collection__exists, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, appendMessage, arginfo_phalcon_mvc_collection_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, save, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, findById, arginfo_phalcon_mvc_collection_findbyid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, findFirst, arginfo_phalcon_mvc_collection_findfirst, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, find, arginfo_phalcon_mvc_collection_find, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, count, arginfo_phalcon_mvc_collection_count, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, aggregate, arginfo_phalcon_mvc_collection_aggregate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, summatory, arginfo_phalcon_mvc_collection_summatory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, delete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, unserialize, arginfo_phalcon_mvc_collection_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, addBehavior, arginfo_phalcon_mvc_collection_addbehavior, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, skipOperation, arginfo_phalcon_mvc_collection_skipoperation, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
