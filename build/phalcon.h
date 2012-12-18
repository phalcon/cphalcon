
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/



zend_class_entry *phalcon_di_injectionawareinterface_ce;

PHALCON_INIT_CLASS(Phalcon_DI_InjectionAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectionawareinterface_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_di_injectionawareinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_DI_InjectionAwareInterface, setDI, arginfo_phalcon_di_injectionawareinterface_setdi)
	PHP_ABSTRACT_ME(Phalcon_DI_InjectionAwareInterface, getDI, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_events_eventsawareinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Events_EventsAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_eventsawareinterface_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_events_eventsawareinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Events_EventsAwareInterface, setEventsManager, arginfo_phalcon_events_eventsawareinterface_seteventsmanager)
	PHP_ABSTRACT_ME(Phalcon_Events_EventsAwareInterface, getEventsManager, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_validatorinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ValidatorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validatorinterface_validate, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_validatorinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ValidatorInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ValidatorInterface, validate, arginfo_phalcon_mvc_model_validatorinterface_validate)
	PHP_FE_END
};



zend_class_entry *phalcon_cache_backendinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_BackendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, frontend)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_start, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_stop, 0, 0, 0)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_setlastkey, 0, 0, 1)
	ZEND_ARG_INFO(0, lastKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_backendinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, __construct, arginfo_phalcon_cache_backendinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, start, arginfo_phalcon_cache_backendinterface_start)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, stop, arginfo_phalcon_cache_backendinterface_stop)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, getFrontend, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, getOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, isFresh, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, isStarted, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, setLastKey, arginfo_phalcon_cache_backendinterface_setlastkey)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, getLastKey, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, get, arginfo_phalcon_cache_backendinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, save, arginfo_phalcon_cache_backendinterface_save)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, delete, arginfo_phalcon_cache_backendinterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, queryKeys, arginfo_phalcon_cache_backendinterface_querykeys)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, exists, arginfo_phalcon_cache_backendinterface_exists)
	PHP_FE_END
};



zend_class_entry *phalcon_cache_frontendinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_FrontendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontendinterface_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontendinterface_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_frontendinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, getLifetime, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, isBuffering, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, start, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, getContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, stop, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, beforeStore, arginfo_phalcon_cache_frontendinterface_beforestore)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, afterRetrieve, arginfo_phalcon_cache_frontendinterface_afterretrieve)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_metadatainterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaDataInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readmetadata, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readmetadataindex, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_writemetadataindex, 0, 0, 3)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readcolumnmap, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readcolumnmapindex, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getprimarykeyattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getnonprimarykeyattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getnotnullattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getdatatypes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getdatatypesnumeric, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getidentityfield, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getbindtypes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getautomaticcreateattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getautomaticupdateattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_setautomaticcreateattributes, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_setautomaticupdateattributes, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getcolumnmap, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getreversecolumnmap, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_hasattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_metadatainterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readMetaData, arginfo_phalcon_mvc_model_metadatainterface_readmetadata)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readMetaDataIndex, arginfo_phalcon_mvc_model_metadatainterface_readmetadataindex)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, writeMetaDataIndex, arginfo_phalcon_mvc_model_metadatainterface_writemetadataindex)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readColumnMap, arginfo_phalcon_mvc_model_metadatainterface_readcolumnmap)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readColumnMapIndex, arginfo_phalcon_mvc_model_metadatainterface_readcolumnmapindex)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getAttributes, arginfo_phalcon_mvc_model_metadatainterface_getattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadatainterface_getprimarykeyattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getNonPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadatainterface_getnonprimarykeyattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getNotNullAttributes, arginfo_phalcon_mvc_model_metadatainterface_getnotnullattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getDataTypes, arginfo_phalcon_mvc_model_metadatainterface_getdatatypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getDataTypesNumeric, arginfo_phalcon_mvc_model_metadatainterface_getdatatypesnumeric)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getIdentityField, arginfo_phalcon_mvc_model_metadatainterface_getidentityfield)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getBindTypes, arginfo_phalcon_mvc_model_metadatainterface_getbindtypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadatainterface_getautomaticcreateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadatainterface_getautomaticupdateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadatainterface_setautomaticcreateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadatainterface_setautomaticupdateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getColumnMap, arginfo_phalcon_mvc_model_metadatainterface_getcolumnmap)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getReverseColumnMap, arginfo_phalcon_mvc_model_metadatainterface_getreversecolumnmap)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, hasAttribute, arginfo_phalcon_mvc_model_metadatainterface_hasattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, isEmpty, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, reset, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, read, arginfo_phalcon_mvc_model_metadatainterface_read)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, write, arginfo_phalcon_mvc_model_metadatainterface_write)
	PHP_FE_END
};



zend_class_entry *phalcon_db_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_update, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_getcolumnlist, 0, 0, 1)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_droptable, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, reference)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_escapeidentifier, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_escapestring, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_bindparams, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_convertboundparams, 0, 0, 2)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, sequenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, __construct, arginfo_phalcon_db_adapterinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, fetchOne, arginfo_phalcon_db_adapterinterface_fetchone)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, fetchAll, arginfo_phalcon_db_adapterinterface_fetchall)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, insert, arginfo_phalcon_db_adapterinterface_insert)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, update, arginfo_phalcon_db_adapterinterface_update)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, delete, arginfo_phalcon_db_adapterinterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getColumnList, arginfo_phalcon_db_adapterinterface_getcolumnlist)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, limit, arginfo_phalcon_db_adapterinterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, tableExists, arginfo_phalcon_db_adapterinterface_tableexists)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, viewExists, arginfo_phalcon_db_adapterinterface_viewexists)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, forUpdate, arginfo_phalcon_db_adapterinterface_forupdate)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, sharedLock, arginfo_phalcon_db_adapterinterface_sharedlock)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, createTable, arginfo_phalcon_db_adapterinterface_createtable)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropTable, arginfo_phalcon_db_adapterinterface_droptable)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, addColumn, arginfo_phalcon_db_adapterinterface_addcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, modifyColumn, arginfo_phalcon_db_adapterinterface_modifycolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropColumn, arginfo_phalcon_db_adapterinterface_dropcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, addIndex, arginfo_phalcon_db_adapterinterface_addindex)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropIndex, arginfo_phalcon_db_adapterinterface_dropindex)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, addPrimaryKey, arginfo_phalcon_db_adapterinterface_addprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropPrimaryKey, arginfo_phalcon_db_adapterinterface_dropprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, addForeignKey, arginfo_phalcon_db_adapterinterface_addforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropForeignKey, arginfo_phalcon_db_adapterinterface_dropforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getColumnDefinition, arginfo_phalcon_db_adapterinterface_getcolumndefinition)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, listTables, arginfo_phalcon_db_adapterinterface_listtables)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getDescriptor, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getConnectionId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getSQLStatement, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getRealSQLStatement, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getSQLVariables, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getSQLBindTypes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getDialectType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getDialect, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, connect, arginfo_phalcon_db_adapterinterface_connect)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, query, arginfo_phalcon_db_adapterinterface_query)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, execute, arginfo_phalcon_db_adapterinterface_execute)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, affectedRows, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, close, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, escapeIdentifier, arginfo_phalcon_db_adapterinterface_escapeidentifier)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, escapeString, arginfo_phalcon_db_adapterinterface_escapestring)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, bindParams, arginfo_phalcon_db_adapterinterface_bindparams)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, convertBoundParams, arginfo_phalcon_db_adapterinterface_convertboundparams)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, lastInsertId, arginfo_phalcon_db_adapterinterface_lastinsertid)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, begin, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, rollback, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, isUnderTransaction, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getInternalHandler, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, describeIndexes, arginfo_phalcon_db_adapterinterface_describeindexes)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, describeReferences, arginfo_phalcon_db_adapterinterface_describereferences)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, tableOptions, arginfo_phalcon_db_adapterinterface_tableoptions)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getDefaultIdValue, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, supportSequences, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, describeColumns, arginfo_phalcon_db_adapterinterface_describecolumns)
	PHP_FE_END
};



zend_class_entry *phalcon_db_dialectinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_DialectInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_select, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_getcolumnlist, 0, 0, 1)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, reference)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_droptable, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_dialectinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, limit, arginfo_phalcon_db_dialectinterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, forUpdate, arginfo_phalcon_db_dialectinterface_forupdate)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, sharedLock, arginfo_phalcon_db_dialectinterface_sharedlock)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, select, arginfo_phalcon_db_dialectinterface_select)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, getColumnList, arginfo_phalcon_db_dialectinterface_getcolumnlist)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, getColumnDefinition, arginfo_phalcon_db_dialectinterface_getcolumndefinition)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, addColumn, arginfo_phalcon_db_dialectinterface_addcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, modifyColumn, arginfo_phalcon_db_dialectinterface_modifycolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropColumn, arginfo_phalcon_db_dialectinterface_dropcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, addIndex, arginfo_phalcon_db_dialectinterface_addindex)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropIndex, arginfo_phalcon_db_dialectinterface_dropindex)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, addPrimaryKey, arginfo_phalcon_db_dialectinterface_addprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropPrimaryKey, arginfo_phalcon_db_dialectinterface_dropprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, addForeignKey, arginfo_phalcon_db_dialectinterface_addforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropForeignKey, arginfo_phalcon_db_dialectinterface_dropforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, createTable, arginfo_phalcon_db_dialectinterface_createtable)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropTable, arginfo_phalcon_db_dialectinterface_droptable)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, tableExists, arginfo_phalcon_db_dialectinterface_tableexists)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, describeColumns, arginfo_phalcon_db_dialectinterface_describecolumns)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, listTables, arginfo_phalcon_db_dialectinterface_listtables)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, describeIndexes, arginfo_phalcon_db_dialectinterface_describeindexes)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, describeReferences, arginfo_phalcon_db_dialectinterface_describereferences)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, tableOptions, arginfo_phalcon_db_dialectinterface_tableoptions)
	PHP_FE_END
};



zend_class_entry *phalcon_paginator_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Paginator_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapterinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapterinterface_setcurrentpage, 0, 0, 1)
	ZEND_ARG_INFO(0, page)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_paginator_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, __construct, arginfo_phalcon_paginator_adapterinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, setCurrentPage, arginfo_phalcon_paginator_adapterinterface_setcurrentpage)
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, getPaginate, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_resultsetinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ResultsetInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_setisfresh, 0, 0, 1)
	ZEND_ARG_INFO(0, isFresh)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_resultsetinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getFirst, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getLast, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, setIsFresh, arginfo_phalcon_mvc_model_resultsetinterface_setisfresh)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, isFresh, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getCache, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_view_engineinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View_EngineInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engineinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, view)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engineinterface_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, partialPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engineinterface_render, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, mustClean)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_view_engineinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_EngineInterface, __construct, arginfo_phalcon_mvc_view_engineinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_EngineInterface, getContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_EngineInterface, partial, arginfo_phalcon_mvc_view_engineinterface_partial)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_EngineInterface, render, arginfo_phalcon_mvc_view_engineinterface_render)
	PHP_FE_END
};



zend_class_entry *phalcon_flashinterface_ce;

PHALCON_INIT_CLASS(Phalcon_FlashInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_success, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_message, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_flashinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, error, arginfo_phalcon_flashinterface_error)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, notice, arginfo_phalcon_flashinterface_notice)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, success, arginfo_phalcon_flashinterface_success)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, warning, arginfo_phalcon_flashinterface_warning)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, message, arginfo_phalcon_flashinterface_message)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_resultinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ResultInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultinterface_setforceexists, 0, 0, 1)
	ZEND_ARG_INFO(0, forceExists)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_resultinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultInterface, setForceExists, arginfo_phalcon_mvc_model_resultinterface_setforceexists)
	PHP_FE_END
};



zend_class_entry *phalcon_dispatcherinterface_ce;

PHALCON_INIT_CLASS(Phalcon_DispatcherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setactionsuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, actionSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setactionname, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setparams, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setparam, 0, 0, 2)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_forward, 0, 0, 1)
	ZEND_ARG_INFO(0, forward)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_dispatcherinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setActionSuffix, arginfo_phalcon_dispatcherinterface_setactionsuffix)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setDefaultNamespace, arginfo_phalcon_dispatcherinterface_setdefaultnamespace)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setDefaultAction, arginfo_phalcon_dispatcherinterface_setdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setActionName, arginfo_phalcon_dispatcherinterface_setactionname)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, getActionName, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setParams, arginfo_phalcon_dispatcherinterface_setparams)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, getParams, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setParam, arginfo_phalcon_dispatcherinterface_setparam)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, getParam, arginfo_phalcon_dispatcherinterface_getparam)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, isFinished, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, getReturnedValue, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, dispatch, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, forward, arginfo_phalcon_dispatcherinterface_forward)
	PHP_FE_END
};



zend_class_entry *phalcon_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Exception);


zend_class_entry *phalcon_di_injectable_ce;

PHALCON_INIT_CLASS(Phalcon_DI_Injectable);

PHP_METHOD(Phalcon_DI_Injectable, setDI);
PHP_METHOD(Phalcon_DI_Injectable, getDI);
PHP_METHOD(Phalcon_DI_Injectable, setEventsManager);
PHP_METHOD(Phalcon_DI_Injectable, getEventsManager);
PHP_METHOD(Phalcon_DI_Injectable, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectable_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectable_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectable___get, 0, 0, 1)
	ZEND_ARG_INFO(0, propertyName)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_di_injectable_method_entry){
	PHP_ME(Phalcon_DI_Injectable, setDI, arginfo_phalcon_di_injectable_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI_Injectable, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI_Injectable, setEventsManager, arginfo_phalcon_di_injectable_seteventsmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI_Injectable, getEventsManager, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI_Injectable, __get, arginfo_phalcon_di_injectable___get, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_queryinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_QueryInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_queryinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_execute, 0, 0, 0)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_queryinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, __construct, arginfo_phalcon_mvc_model_queryinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, parse, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, execute, arginfo_phalcon_mvc_model_queryinterface_execute)
	PHP_FE_END
};



zend_class_entry *phalcon_translate_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Translate_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface__, 0, 0, 1)
	ZEND_ARG_INFO(0, translateKey)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface_query, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_translate_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, __construct, arginfo_phalcon_translate_adapterinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, _, arginfo_phalcon_translate_adapterinterface__)
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, query, arginfo_phalcon_translate_adapterinterface_query)
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, exists, arginfo_phalcon_translate_adapterinterface_exists)
	PHP_FE_END
};



zend_class_entry *phalcon_di_serviceinterface_ce;

PHALCON_INIT_CLASS(Phalcon_DI_ServiceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_setshared, 0, 0, 1)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_setdefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_resolve, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_di_serviceinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, __construct, arginfo_phalcon_di_serviceinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, setShared, arginfo_phalcon_di_serviceinterface_setshared)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, isShared, NULL)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, setDefinition, arginfo_phalcon_di_serviceinterface_setdefinition)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, getDefinition, NULL)
	PHP_ABSTRACT_ME(Phalcon_DI_ServiceInterface, resolve, arginfo_phalcon_di_serviceinterface_resolve)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_di_serviceinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_messageinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MessageInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_setmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_setfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_messageinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, __construct, arginfo_phalcon_mvc_model_messageinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, setType, arginfo_phalcon_mvc_model_messageinterface_settype)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, setMessage, arginfo_phalcon_mvc_model_messageinterface_setmessage)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, getMessage, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, setField, arginfo_phalcon_mvc_model_messageinterface_setfield)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, getField, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, __toString, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_mvc_model_messageinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_transaction_managerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_get, 0, 0, 0)
	ZEND_ARG_INFO(0, autoBegin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, collect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_notifyrollback, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_notifycommit, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_transaction_managerinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, __construct, arginfo_phalcon_mvc_model_transaction_managerinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, has, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, get, arginfo_phalcon_mvc_model_transaction_managerinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollbackPendent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollback, arginfo_phalcon_mvc_model_transaction_managerinterface_rollback)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyRollback, arginfo_phalcon_mvc_model_transaction_managerinterface_notifyrollback)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyCommit, arginfo_phalcon_mvc_model_transaction_managerinterface_notifycommit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, collectTransactions, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_query_statusinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_StatusInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_statusinterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, success)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_query_statusinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, __construct, arginfo_phalcon_mvc_model_query_statusinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, getModel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, success, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_criteriainterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_CriteriaInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_setmodelname, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_bind, 0, 0, 1)
	ZEND_ARG_INFO(0, bindParams)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_where, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_conditions, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_order, 0, 0, 1)
	ZEND_ARG_INFO(0, orderColumns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_forupdate, 0, 0, 0)
	ZEND_ARG_INFO(0, forUpdate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_sharedlock, 0, 0, 0)
	ZEND_ARG_INFO(0, sharedLock)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_frominput, 0, 0, 3)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_criteriainterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, setModelName, arginfo_phalcon_mvc_model_criteriainterface_setmodelname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getModelName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, bind, arginfo_phalcon_mvc_model_criteriainterface_bind)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, where, arginfo_phalcon_mvc_model_criteriainterface_where)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, conditions, arginfo_phalcon_mvc_model_criteriainterface_conditions)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, order, arginfo_phalcon_mvc_model_criteriainterface_order)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, limit, arginfo_phalcon_mvc_model_criteriainterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, forUpdate, arginfo_phalcon_mvc_model_criteriainterface_forupdate)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, sharedLock, arginfo_phalcon_mvc_model_criteriainterface_sharedlock)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getWhere, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getConditions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getLimit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getOrder, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getParams, NULL)
	ZEND_FENTRY(fromInput, NULL, arginfo_phalcon_mvc_model_criteriainterface_frominput, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, execute, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_dispatcherinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_DispatcherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setcontrollersuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setcontrollername, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_dispatcherinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setControllerSuffix, arginfo_phalcon_mvc_dispatcherinterface_setcontrollersuffix)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setDefaultController, arginfo_phalcon_mvc_dispatcherinterface_setdefaultcontroller)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setControllerName, arginfo_phalcon_mvc_dispatcherinterface_setcontrollername)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getControllerName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getLastController, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getActiveController, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_modelinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_ModelInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, managerService)
	ZEND_ARG_INFO(0, dbService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_settransaction, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_dumpresult, 0, 0, 2)
	ZEND_ARG_INFO(0, base)
	ZEND_ARG_INFO(0, result)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_appendmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_save, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_create, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_update, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_writeattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_getrelated, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_modelinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, __construct, arginfo_phalcon_mvc_modelinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setTransaction, arginfo_phalcon_mvc_modelinterface_settransaction)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getSource, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getSchema, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setConnectionService, arginfo_phalcon_mvc_modelinterface_setconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getConnectionService, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getConnection, NULL)
	ZEND_FENTRY(dumpResult, NULL, arginfo_phalcon_mvc_modelinterface_dumpresult, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(find, NULL, arginfo_phalcon_mvc_modelinterface_find, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(findFirst, NULL, arginfo_phalcon_mvc_modelinterface_findfirst, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(query, NULL, arginfo_phalcon_mvc_modelinterface_query, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(count, NULL, arginfo_phalcon_mvc_modelinterface_count, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(sum, NULL, arginfo_phalcon_mvc_modelinterface_sum, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(maximum, NULL, arginfo_phalcon_mvc_modelinterface_maximum, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(minimum, NULL, arginfo_phalcon_mvc_modelinterface_minimum, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(average, NULL, arginfo_phalcon_mvc_modelinterface_average, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, appendMessage, arginfo_phalcon_mvc_modelinterface_appendmessage)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, validationHasFailed, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, save, arginfo_phalcon_mvc_modelinterface_save)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, create, arginfo_phalcon_mvc_modelinterface_create)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, update, arginfo_phalcon_mvc_modelinterface_update)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, delete, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getOperationMade, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, readAttribute, arginfo_phalcon_mvc_modelinterface_readattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, writeAttribute, arginfo_phalcon_mvc_modelinterface_writeattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getRelated, arginfo_phalcon_mvc_modelinterface_getrelated)
	PHP_FE_END
};



zend_class_entry *phalcon_session_baginterface_ce;

PHALCON_INIT_CLASS(Phalcon_Session_BagInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface___set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface___get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_session_baginterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, initialize, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, destroy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, set, arginfo_phalcon_session_baginterface_set)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, get, arginfo_phalcon_session_baginterface_get)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, has, arginfo_phalcon_session_baginterface_has)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, __set, arginfo_phalcon_session_baginterface___set)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, __get, arginfo_phalcon_session_baginterface___get)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, __isset, arginfo_phalcon_session_baginterface___isset)
	PHP_FE_END
};



zend_class_entry *phalcon_session_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Session_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_session_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, __construct, arginfo_phalcon_session_adapterinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, start, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, setOptions, arginfo_phalcon_session_adapterinterface_setoptions)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, getOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, get, arginfo_phalcon_session_adapterinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, set, arginfo_phalcon_session_adapterinterface_set)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, has, arginfo_phalcon_session_adapterinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, remove, arginfo_phalcon_session_adapterinterface_remove)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, getId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, isStarted, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, destroy, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_logger_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_setformat, 0, 0, 1)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_gettypestring, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_setdateformat, 0, 0, 1)
	ZEND_ARG_INFO(0, date)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_log, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_logger_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, setFormat, arginfo_phalcon_logger_adapterinterface_setformat)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, getFormat, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, getTypeString, arginfo_phalcon_logger_adapterinterface_gettypestring)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, setDateFormat, arginfo_phalcon_logger_adapterinterface_setdateformat)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, getDateFormat, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, log, arginfo_phalcon_logger_adapterinterface_log)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, begin, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, rollback, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, close, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, debug, arginfo_phalcon_logger_adapterinterface_debug)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, error, arginfo_phalcon_logger_adapterinterface_error)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, info, arginfo_phalcon_logger_adapterinterface_info)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, notice, arginfo_phalcon_logger_adapterinterface_notice)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, warning, arginfo_phalcon_logger_adapterinterface_warning)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, alert, arginfo_phalcon_logger_adapterinterface_alert)
	PHP_FE_END
};



zend_class_entry *phalcon_escaperinterface_ce;

PHALCON_INIT_CLASS(Phalcon_EscaperInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_setenconding, 0, 0, 1)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_sethtmlquotetype, 0, 0, 1)
	ZEND_ARG_INFO(0, quoteType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapehtml, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapehtmlattr, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapecss, 0, 0, 1)
	ZEND_ARG_INFO(0, css)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapeurl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_escaperinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, setEnconding, arginfo_phalcon_escaperinterface_setenconding)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, getEncoding, NULL)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, setHtmlQuoteType, arginfo_phalcon_escaperinterface_sethtmlquotetype)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeHtml, arginfo_phalcon_escaperinterface_escapehtml)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeHtmlAttr, arginfo_phalcon_escaperinterface_escapehtmlattr)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeCss, arginfo_phalcon_escaperinterface_escapecss)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeUrl, arginfo_phalcon_escaperinterface_escapeurl)
	PHP_FE_END
};



zend_class_entry *phalcon_diinterface_ce;

PHALCON_INIT_CLASS(Phalcon_DiInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, config)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_setshared, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_attempt, 0, 0, 2)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, config)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_getshared, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_getraw, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_getservice, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_setdefault, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_diinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_DiInterface, set, arginfo_phalcon_diinterface_set)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, setShared, arginfo_phalcon_diinterface_setshared)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, remove, arginfo_phalcon_diinterface_remove)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, attempt, arginfo_phalcon_diinterface_attempt)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, get, arginfo_phalcon_diinterface_get)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, getShared, arginfo_phalcon_diinterface_getshared)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, getRaw, arginfo_phalcon_diinterface_getraw)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, getService, arginfo_phalcon_diinterface_getservice)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, has, arginfo_phalcon_diinterface_has)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, wasFreshInstance, NULL)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, getServices, NULL)
	ZEND_FENTRY(setDefault, NULL, arginfo_phalcon_diinterface_setdefault, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(getDefault, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(reset, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_urlinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_UrlInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_setbaseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, baseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_get, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_path, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_urlinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, setBaseUri, arginfo_phalcon_mvc_urlinterface_setbaseuri)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, getBaseUri, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, setBasePath, arginfo_phalcon_mvc_urlinterface_setbasepath)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, getBasePath, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, get, arginfo_phalcon_mvc_urlinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, path, arginfo_phalcon_mvc_urlinterface_path)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_viewinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_ViewInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setviewsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, viewsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setrenderlevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setmainview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_settemplatebefore, 0, 0, 1)
	ZEND_ARG_INFO(0, templateBefore)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_settemplateafter, 0, 0, 1)
	ZEND_ARG_INFO(0, templateAfter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setparamtoview, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setvar, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_registerengines, 0, 0, 1)
	ZEND_ARG_INFO(0, engines)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_render, 0, 0, 2)
	ZEND_ARG_INFO(0, controllerName)
	ZEND_ARG_INFO(0, actionName)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_pick, 0, 0, 1)
	ZEND_ARG_INFO(0, renderView)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, partialPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_cache, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_viewinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setViewsDir, arginfo_phalcon_mvc_viewinterface_setviewsdir)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getViewsDir, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setBasePath, arginfo_phalcon_mvc_viewinterface_setbasepath)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setRenderLevel, arginfo_phalcon_mvc_viewinterface_setrenderlevel)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setMainView, arginfo_phalcon_mvc_viewinterface_setmainview)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setTemplateBefore, arginfo_phalcon_mvc_viewinterface_settemplatebefore)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, cleanTemplateBefore, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setTemplateAfter, arginfo_phalcon_mvc_viewinterface_settemplateafter)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, cleanTemplateAfter, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setParamToView, arginfo_phalcon_mvc_viewinterface_setparamtoview)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setVar, arginfo_phalcon_mvc_viewinterface_setvar)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getParamsToView, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getControllerName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getActionName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getParams, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, start, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, registerEngines, arginfo_phalcon_mvc_viewinterface_registerengines)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, render, arginfo_phalcon_mvc_viewinterface_render)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, pick, arginfo_phalcon_mvc_viewinterface_pick)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, partial, arginfo_phalcon_mvc_viewinterface_partial)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, finish, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getCache, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, cache, arginfo_phalcon_mvc_viewinterface_cache)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setContent, arginfo_phalcon_mvc_viewinterface_setcontent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getActiveRenderPath, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, disable, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, enable, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, reset, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_routerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_RouterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaults, 0, 0, 1)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addget, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addpost, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addput, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_adddelete, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addhead, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_getroutebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_getroutebyname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_routerinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, setDefaultModule, arginfo_phalcon_mvc_routerinterface_setdefaultmodule)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, setDefaultController, arginfo_phalcon_mvc_routerinterface_setdefaultcontroller)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, setDefaultAction, arginfo_phalcon_mvc_routerinterface_setdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, setDefaults, arginfo_phalcon_mvc_routerinterface_setdefaults)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, handle, arginfo_phalcon_mvc_routerinterface_handle)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, add, arginfo_phalcon_mvc_routerinterface_add)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addGet, arginfo_phalcon_mvc_routerinterface_addget)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addPost, arginfo_phalcon_mvc_routerinterface_addpost)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addPut, arginfo_phalcon_mvc_routerinterface_addput)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addDelete, arginfo_phalcon_mvc_routerinterface_adddelete)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addOptions, arginfo_phalcon_mvc_routerinterface_addoptions)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addHead, arginfo_phalcon_mvc_routerinterface_addhead)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, clear, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getModuleName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getControllerName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getActionName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getParams, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getMatchedRoute, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getMatches, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, wasMatched, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getRoutes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getRouteById, arginfo_phalcon_mvc_routerinterface_getroutebyid)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getRouteByName, arginfo_phalcon_mvc_routerinterface_getroutebyname)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_router_routeinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Router_RouteInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_compilepattern, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_via, 0, 0, 1)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_reconfigure, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_sethttpmethods, 0, 0, 1)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_router_routeinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, __construct, arginfo_phalcon_mvc_router_routeinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, compilePattern, arginfo_phalcon_mvc_router_routeinterface_compilepattern)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, via, arginfo_phalcon_mvc_router_routeinterface_via)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, reConfigure, arginfo_phalcon_mvc_router_routeinterface_reconfigure)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, setName, arginfo_phalcon_mvc_router_routeinterface_setname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, setHttpMethods, arginfo_phalcon_mvc_router_routeinterface_sethttpmethods)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getRouteId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getPattern, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getCompiledPattern, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getPaths, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getHttpMethods, NULL)
	ZEND_FENTRY(reset, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_managerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_initialize, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_isinitialized, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_load, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addhasone, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addbelongsto, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addhasmany, 0, 0, 4)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_existsbelongsto, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_existshasmany, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_existshasone, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getbelongstorecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_INFO(0, record)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasmanyrecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_INFO(0, record)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasonerecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_INFO(0, record)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getbelongsto, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasmany, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasone, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasoneandhasmany, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getrelations, 0, 0, 2)
	ZEND_ARG_INFO(0, first)
	ZEND_ARG_INFO(0, second)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_createquery, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_executequery, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_createbuilder, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_managerinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, initialize, arginfo_phalcon_mvc_model_managerinterface_initialize)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, isInitialized, arginfo_phalcon_mvc_model_managerinterface_isinitialized)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getLastInitialized, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, load, arginfo_phalcon_mvc_model_managerinterface_load)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addHasOne, arginfo_phalcon_mvc_model_managerinterface_addhasone)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addBelongsTo, arginfo_phalcon_mvc_model_managerinterface_addbelongsto)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addHasMany, arginfo_phalcon_mvc_model_managerinterface_addhasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, existsBelongsTo, arginfo_phalcon_mvc_model_managerinterface_existsbelongsto)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, existsHasMany, arginfo_phalcon_mvc_model_managerinterface_existshasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, existsHasOne, arginfo_phalcon_mvc_model_managerinterface_existshasone)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getBelongsToRecords, arginfo_phalcon_mvc_model_managerinterface_getbelongstorecords)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasManyRecords, arginfo_phalcon_mvc_model_managerinterface_gethasmanyrecords)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasOneRecords, arginfo_phalcon_mvc_model_managerinterface_gethasonerecords)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getBelongsTo, arginfo_phalcon_mvc_model_managerinterface_getbelongsto)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasMany, arginfo_phalcon_mvc_model_managerinterface_gethasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasOne, arginfo_phalcon_mvc_model_managerinterface_gethasone)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasOneAndHasMany, arginfo_phalcon_mvc_model_managerinterface_gethasoneandhasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getRelations, arginfo_phalcon_mvc_model_managerinterface_getrelations)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, createQuery, arginfo_phalcon_mvc_model_managerinterface_createquery)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, executeQuery, arginfo_phalcon_mvc_model_managerinterface_executequery)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, createBuilder, arginfo_phalcon_mvc_model_managerinterface_createbuilder)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getLastQuery, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_http_request_fileinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Request_FileInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_fileinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_fileinterface_moveto, 0, 0, 1)
	ZEND_ARG_INFO(0, destination)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_request_fileinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, __construct, arginfo_phalcon_http_request_fileinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getSize, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getTempName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, moveTo, arginfo_phalcon_http_request_fileinterface_moveto)
	PHP_FE_END
};



zend_class_entry *phalcon_acl_roleinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_RoleInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_roleinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_acl_roleinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, __construct, arginfo_phalcon_acl_roleinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, getDescription, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, __toString, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_acl_resourceinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_ResourceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_resourceinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_acl_resourceinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, __construct, arginfo_phalcon_acl_resourceinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, getDescription, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, __toString, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_db_indexinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_IndexInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_indexinterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, indexName)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_indexinterface___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_indexinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, __construct, arginfo_phalcon_db_indexinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, getColumns, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_db_indexinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};



zend_class_entry *phalcon_db_columninterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_ColumnInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, columnName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_columninterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, __construct, arginfo_phalcon_db_columninterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getSchemaName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getSize, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getScale, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isUnsigned, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isNotNull, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isPrimary, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isAutoIncrement, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isNumeric, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isFirst, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getAfterPosition, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getBindType, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_db_columninterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};



zend_class_entry *phalcon_db_referenceinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_ReferenceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_referenceinterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, referenceName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_referenceinterface___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_referenceinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, __construct, arginfo_phalcon_db_referenceinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getSchemaName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedSchema, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getColumns, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedTable, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedColumns, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_db_referenceinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};



zend_class_entry *phalcon_acl_adapterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultAccess)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_addrole, 0, 0, 1)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, accessInherits)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_addinherit, 0, 0, 2)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, roleToInherit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_isrole, 0, 0, 1)
	ZEND_ARG_INFO(0, roleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_isresource, 0, 0, 1)
	ZEND_ARG_INFO(0, resourceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_addresource, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_addresourceaccess, 0, 0, 2)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_dropresourceaccess, 0, 0, 2)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_allow, 0, 0, 3)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_deny, 0, 0, 3)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_isallowed, 0, 0, 3)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, resource)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_acl_adapterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, setDefaultAction, arginfo_phalcon_acl_adapterinterface_setdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getDefaultAction, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, addRole, arginfo_phalcon_acl_adapterinterface_addrole)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, addInherit, arginfo_phalcon_acl_adapterinterface_addinherit)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, isRole, arginfo_phalcon_acl_adapterinterface_isrole)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, isResource, arginfo_phalcon_acl_adapterinterface_isresource)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, addResource, arginfo_phalcon_acl_adapterinterface_addresource)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, addResourceAccess, arginfo_phalcon_acl_adapterinterface_addresourceaccess)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, dropResourceAccess, arginfo_phalcon_acl_adapterinterface_dropresourceaccess)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, allow, arginfo_phalcon_acl_adapterinterface_allow)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, deny, arginfo_phalcon_acl_adapterinterface_deny)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, isAllowed, arginfo_phalcon_acl_adapterinterface_isallowed)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getActiveRole, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getActiveResource, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getActiveAccess, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_events_managerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Events_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_managerinterface_attach, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_managerinterface_dettachall, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_managerinterface_fire, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_managerinterface_getlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_events_managerinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Events_ManagerInterface, attach, arginfo_phalcon_events_managerinterface_attach)
	PHP_ABSTRACT_ME(Phalcon_Events_ManagerInterface, dettachAll, arginfo_phalcon_events_managerinterface_dettachall)
	PHP_ABSTRACT_ME(Phalcon_Events_ManagerInterface, fire, arginfo_phalcon_events_managerinterface_fire)
	PHP_ABSTRACT_ME(Phalcon_Events_ManagerInterface, getListeners, arginfo_phalcon_events_managerinterface_getlisteners)
	PHP_FE_END
};



zend_class_entry *phalcon_http_requestinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Http_RequestInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getpost, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getquery, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_haspost, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_hasquery, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_hasserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getclientaddress, 0, 0, 0)
	ZEND_ARG_INFO(0, trustForwardedHeader)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_ismethod, 0, 0, 1)
	ZEND_ARG_INFO(0, methods)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_requestinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, get, arginfo_phalcon_http_requestinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getPost, arginfo_phalcon_http_requestinterface_getpost)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getQuery, arginfo_phalcon_http_requestinterface_getquery)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServer, arginfo_phalcon_http_requestinterface_getserver)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, has, arginfo_phalcon_http_requestinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasPost, arginfo_phalcon_http_requestinterface_haspost)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasQuery, arginfo_phalcon_http_requestinterface_hasquery)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasServer, arginfo_phalcon_http_requestinterface_hasserver)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHeader, arginfo_phalcon_http_requestinterface_getheader)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getScheme, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isAjax, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isSoapRequested, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isSecureRequest, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getRawBody, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServerAddress, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServerName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHttpHost, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getClientAddress, arginfo_phalcon_http_requestinterface_getclientaddress)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getMethod, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getUserAgent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isMethod, arginfo_phalcon_http_requestinterface_ismethod)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isPost, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isGet, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isPut, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isHead, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isDelete, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasFiles, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getUploadedFiles, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHTTPReferer, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getAcceptableContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestAccept, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getClientCharsets, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestCharset, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getLanguages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestLanguage, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_transactioninterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_TransactionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, autoBegin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_settransactionmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, manager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, rollbackMessage)
	ZEND_ARG_INFO(0, rollbackRecord)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_setisnewtransaction, 0, 0, 1)
	ZEND_ARG_INFO(0, isNew)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_setrollbackonabort, 0, 0, 1)
	ZEND_ARG_INFO(0, rollbackOnAbort)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_setrollbackedrecord, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_transactioninterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, __construct, arginfo_phalcon_mvc_model_transactioninterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, setTransactionManager, arginfo_phalcon_mvc_model_transactioninterface_settransactionmanager)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, begin, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, rollback, arginfo_phalcon_mvc_model_transactioninterface_rollback)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, getConnection, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, setIsNewTransaction, arginfo_phalcon_mvc_model_transactioninterface_setisnewtransaction)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, setRollbackOnAbort, arginfo_phalcon_mvc_model_transactioninterface_setrollbackonabort)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, isManaged, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, isValid, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, setRollbackedRecord, arginfo_phalcon_mvc_model_transactioninterface_setrollbackedrecord)
	PHP_FE_END
};



zend_class_entry *phalcon_filterinterface_ce;

PHALCON_INIT_CLASS(Phalcon_FilterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filterinterface_add, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filterinterface_sanitize, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_filterinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_FilterInterface, add, arginfo_phalcon_filterinterface_add)
	PHP_ABSTRACT_ME(Phalcon_FilterInterface, sanitize, arginfo_phalcon_filterinterface_sanitize)
	PHP_ABSTRACT_ME(Phalcon_FilterInterface, getFilters, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_http_responseinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Http_ResponseInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setstatuscode, 0, 0, 2)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setrawheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setexpires, 0, 0, 1)
	ZEND_ARG_INFO(0, datetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setcontenttype, 0, 0, 1)
	ZEND_ARG_INFO(0, contentType)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_redirect, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, externalRedirect)
	ZEND_ARG_INFO(0, statusCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_appendcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_responseinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setStatusCode, arginfo_phalcon_http_responseinterface_setstatuscode)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, getHeaders, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setHeader, arginfo_phalcon_http_responseinterface_setheader)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setRawHeader, arginfo_phalcon_http_responseinterface_setrawheader)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, resetHeaders, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setExpires, arginfo_phalcon_http_responseinterface_setexpires)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setNotModified, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setContentType, arginfo_phalcon_http_responseinterface_setcontenttype)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, redirect, arginfo_phalcon_http_responseinterface_redirect)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setContent, arginfo_phalcon_http_responseinterface_setcontent)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, appendContent, arginfo_phalcon_http_responseinterface_appendcontent)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, getContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, sendHeaders, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, send, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_http_response_headersinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Response_HeadersInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface_setraw, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_response_headersinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, set, arginfo_phalcon_http_response_headersinterface_set)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, get, arginfo_phalcon_http_response_headersinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, setRaw, arginfo_phalcon_http_response_headersinterface_setraw)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, send, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, reset, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_http_response_headersinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};



zend_class_entry *phalcon_db_adapter_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Adapter);

PHP_METHOD(Phalcon_Db_Adapter, __construct);
PHP_METHOD(Phalcon_Db_Adapter, setEventsManager);
PHP_METHOD(Phalcon_Db_Adapter, getEventsManager);
PHP_METHOD(Phalcon_Db_Adapter, fetchOne);
PHP_METHOD(Phalcon_Db_Adapter, fetchAll);
PHP_METHOD(Phalcon_Db_Adapter, insert);
PHP_METHOD(Phalcon_Db_Adapter, update);
PHP_METHOD(Phalcon_Db_Adapter, delete);
PHP_METHOD(Phalcon_Db_Adapter, getColumnList);
PHP_METHOD(Phalcon_Db_Adapter, limit);
PHP_METHOD(Phalcon_Db_Adapter, tableExists);
PHP_METHOD(Phalcon_Db_Adapter, viewExists);
PHP_METHOD(Phalcon_Db_Adapter, forUpdate);
PHP_METHOD(Phalcon_Db_Adapter, sharedLock);
PHP_METHOD(Phalcon_Db_Adapter, createTable);
PHP_METHOD(Phalcon_Db_Adapter, dropTable);
PHP_METHOD(Phalcon_Db_Adapter, addColumn);
PHP_METHOD(Phalcon_Db_Adapter, modifyColumn);
PHP_METHOD(Phalcon_Db_Adapter, dropColumn);
PHP_METHOD(Phalcon_Db_Adapter, addIndex);
PHP_METHOD(Phalcon_Db_Adapter, dropIndex);
PHP_METHOD(Phalcon_Db_Adapter, addPrimaryKey);
PHP_METHOD(Phalcon_Db_Adapter, dropPrimaryKey);
PHP_METHOD(Phalcon_Db_Adapter, addForeignKey);
PHP_METHOD(Phalcon_Db_Adapter, dropForeignKey);
PHP_METHOD(Phalcon_Db_Adapter, getColumnDefinition);
PHP_METHOD(Phalcon_Db_Adapter, listTables);
PHP_METHOD(Phalcon_Db_Adapter, getDescriptor);
PHP_METHOD(Phalcon_Db_Adapter, getConnectionId);
PHP_METHOD(Phalcon_Db_Adapter, getSQLStatement);
PHP_METHOD(Phalcon_Db_Adapter, getRealSQLStatement);
PHP_METHOD(Phalcon_Db_Adapter, getSQLVariables);
PHP_METHOD(Phalcon_Db_Adapter, getSQLBindTypes);
PHP_METHOD(Phalcon_Db_Adapter, getType);
PHP_METHOD(Phalcon_Db_Adapter, getDialectType);
PHP_METHOD(Phalcon_Db_Adapter, getDialect);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_update, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_getcolumnlist, 0, 0, 1)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_droptable, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, reference)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_adapter_method_entry){
	PHP_ME(Phalcon_Db_Adapter, __construct, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Db_Adapter, setEventsManager, arginfo_phalcon_db_adapter_seteventsmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getEventsManager, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, fetchOne, arginfo_phalcon_db_adapter_fetchone, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, fetchAll, arginfo_phalcon_db_adapter_fetchall, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, insert, arginfo_phalcon_db_adapter_insert, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, update, arginfo_phalcon_db_adapter_update, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, delete, arginfo_phalcon_db_adapter_delete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getColumnList, arginfo_phalcon_db_adapter_getcolumnlist, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, limit, arginfo_phalcon_db_adapter_limit, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, tableExists, arginfo_phalcon_db_adapter_tableexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, viewExists, arginfo_phalcon_db_adapter_viewexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, forUpdate, arginfo_phalcon_db_adapter_forupdate, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, sharedLock, arginfo_phalcon_db_adapter_sharedlock, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, createTable, arginfo_phalcon_db_adapter_createtable, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, dropTable, arginfo_phalcon_db_adapter_droptable, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, addColumn, arginfo_phalcon_db_adapter_addcolumn, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, modifyColumn, arginfo_phalcon_db_adapter_modifycolumn, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, dropColumn, arginfo_phalcon_db_adapter_dropcolumn, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, addIndex, arginfo_phalcon_db_adapter_addindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, dropIndex, arginfo_phalcon_db_adapter_dropindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, addPrimaryKey, arginfo_phalcon_db_adapter_addprimarykey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, dropPrimaryKey, arginfo_phalcon_db_adapter_dropprimarykey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, addForeignKey, arginfo_phalcon_db_adapter_addforeignkey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, dropForeignKey, arginfo_phalcon_db_adapter_dropforeignkey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getColumnDefinition, arginfo_phalcon_db_adapter_getcolumndefinition, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, listTables, arginfo_phalcon_db_adapter_listtables, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getDescriptor, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getConnectionId, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getSQLStatement, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getRealSQLStatement, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getSQLVariables, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getSQLBindTypes, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getType, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getDialectType, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter, getDialect, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_validator_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator);

PHP_METHOD(Phalcon_Mvc_Model_Validator, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Validator, appendMessage);
PHP_METHOD(Phalcon_Mvc_Model_Validator, getMessages);
PHP_METHOD(Phalcon_Mvc_Model_Validator, getOptions);
PHP_METHOD(Phalcon_Mvc_Model_Validator, getOption);
PHP_METHOD(Phalcon_Mvc_Model_Validator, isSetOption);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_validator_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Validator, __construct, arginfo_phalcon_mvc_model_validator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_Validator, appendMessage, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Validator, getMessages, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Validator, getOptions, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Validator, getOption, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Validator, isSetOption, NULL, ZEND_ACC_PROTECTED) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_metadata_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData);

PHP_METHOD(Phalcon_Mvc_Model_MetaData, _initialize);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaData);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaDataIndex);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, writeMetaDataIndex);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readColumnMap);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readColumnMapIndex);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getPrimaryKeyAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNonPrimaryKeyAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNotNullAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypesNumeric);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getIdentityField);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getBindTypes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticCreateAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticUpdateAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticCreateAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticUpdateAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getColumnMap);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getReverseColumnMap);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, hasAttribute);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, isEmpty);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_readmetadata, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_readmetadataindex, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_writemetadataindex, 0, 0, 3)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_readcolumnmap, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_readcolumnmapindex, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getprimarykeyattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getnonprimarykeyattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getnotnullattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getdatatypes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getdatatypesnumeric, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getidentityfield, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getbindtypes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getautomaticcreateattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getautomaticupdateattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_setautomaticcreateattributes, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_setautomaticupdateattributes, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getcolumnmap, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getreversecolumnmap, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_hasattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_metadata_method_entry){
	PHP_ME(Phalcon_Mvc_Model_MetaData, _initialize, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, readMetaData, arginfo_phalcon_mvc_model_metadata_readmetadata, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, readMetaDataIndex, arginfo_phalcon_mvc_model_metadata_readmetadataindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, writeMetaDataIndex, arginfo_phalcon_mvc_model_metadata_writemetadataindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, readColumnMap, arginfo_phalcon_mvc_model_metadata_readcolumnmap, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, readColumnMapIndex, arginfo_phalcon_mvc_model_metadata_readcolumnmapindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getAttributes, arginfo_phalcon_mvc_model_metadata_getattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadata_getprimarykeyattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getNonPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadata_getnonprimarykeyattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getNotNullAttributes, arginfo_phalcon_mvc_model_metadata_getnotnullattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getDataTypes, arginfo_phalcon_mvc_model_metadata_getdatatypes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getDataTypesNumeric, arginfo_phalcon_mvc_model_metadata_getdatatypesnumeric, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getIdentityField, arginfo_phalcon_mvc_model_metadata_getidentityfield, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getBindTypes, arginfo_phalcon_mvc_model_metadata_getbindtypes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadata_getautomaticcreateattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadata_getautomaticupdateattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, setAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadata_setautomaticcreateattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, setAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadata_setautomaticupdateattributes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getColumnMap, arginfo_phalcon_mvc_model_metadata_getcolumnmap, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, getReverseColumnMap, arginfo_phalcon_mvc_model_metadata_getreversecolumnmap, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, hasAttribute, arginfo_phalcon_mvc_model_metadata_hasattribute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, isEmpty, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData, reset, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_cache_backend_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend);

PHP_METHOD(Phalcon_Cache_Backend, __construct);
PHP_METHOD(Phalcon_Cache_Backend, start);
PHP_METHOD(Phalcon_Cache_Backend, stop);
PHP_METHOD(Phalcon_Cache_Backend, getFrontend);
PHP_METHOD(Phalcon_Cache_Backend, getOptions);
PHP_METHOD(Phalcon_Cache_Backend, isFresh);
PHP_METHOD(Phalcon_Cache_Backend, isStarted);
PHP_METHOD(Phalcon_Cache_Backend, setLastKey);
PHP_METHOD(Phalcon_Cache_Backend, getLastKey);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, frontend)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_start, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_stop, 0, 0, 0)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_setlastkey, 0, 0, 1)
	ZEND_ARG_INFO(0, lastKey)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_backend_method_entry){
	PHP_ME(Phalcon_Cache_Backend, __construct, arginfo_phalcon_cache_backend___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Cache_Backend, start, arginfo_phalcon_cache_backend_start, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend, stop, arginfo_phalcon_cache_backend_stop, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend, getFrontend, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend, getOptions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend, isFresh, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend, isStarted, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend, setLastKey, arginfo_phalcon_cache_backend_setlastkey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend, getLastKey, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_dialect_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Dialect);

PHP_METHOD(Phalcon_Db_Dialect, limit);
PHP_METHOD(Phalcon_Db_Dialect, forUpdate);
PHP_METHOD(Phalcon_Db_Dialect, sharedLock);
PHP_METHOD(Phalcon_Db_Dialect, getColumnList);
PHP_METHOD(Phalcon_Db_Dialect, getSqlExpression);
PHP_METHOD(Phalcon_Db_Dialect, getSqlTable);
PHP_METHOD(Phalcon_Db_Dialect, select);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getcolumnlist, 0, 0, 1)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpression, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqltable, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_select, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_dialect_method_entry){
	PHP_ME(Phalcon_Db_Dialect, limit, arginfo_phalcon_db_dialect_limit, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect, forUpdate, arginfo_phalcon_db_dialect_forupdate, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect, sharedLock, arginfo_phalcon_db_dialect_sharedlock, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect, getColumnList, arginfo_phalcon_db_dialect_getcolumnlist, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect, getSqlExpression, arginfo_phalcon_db_dialect_getsqlexpression, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect, getSqlTable, arginfo_phalcon_db_dialect_getsqltable, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect, select, arginfo_phalcon_db_dialect_select, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_adapter_pdo_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo);

PHP_METHOD(Phalcon_Db_Adapter_Pdo, __construct);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, connect);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, executePrepared);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, query);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, execute);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, affectedRows);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, close);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, escapeIdentifier);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, escapeString);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, bindParams);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, convertBoundParams);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, lastInsertId);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, begin);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, rollback);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, commit);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, isUnderTransaction);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, getInternalHandler);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, describeIndexes);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, describeReferences);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, tableOptions);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, getDefaultIdValue);
PHP_METHOD(Phalcon_Db_Adapter_Pdo, supportSequences);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_executeprepared, 0, 0, 3)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_escapeidentifier, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_escapestring, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_bindparams, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_convertboundparams, 0, 0, 2)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, sequenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_adapter_pdo_method_entry){
	PHP_ME(Phalcon_Db_Adapter_Pdo, __construct, arginfo_phalcon_db_adapter_pdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, connect, arginfo_phalcon_db_adapter_pdo_connect, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, executePrepared, arginfo_phalcon_db_adapter_pdo_executeprepared, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, query, arginfo_phalcon_db_adapter_pdo_query, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, execute, arginfo_phalcon_db_adapter_pdo_execute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, affectedRows, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, close, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, escapeIdentifier, arginfo_phalcon_db_adapter_pdo_escapeidentifier, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, escapeString, arginfo_phalcon_db_adapter_pdo_escapestring, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, bindParams, arginfo_phalcon_db_adapter_pdo_bindparams, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, convertBoundParams, arginfo_phalcon_db_adapter_pdo_convertboundparams, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, lastInsertId, arginfo_phalcon_db_adapter_pdo_lastinsertid, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, begin, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, rollback, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, commit, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, isUnderTransaction, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, getInternalHandler, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, describeIndexes, arginfo_phalcon_db_adapter_pdo_describeindexes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, describeReferences, arginfo_phalcon_db_adapter_pdo_describereferences, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, tableOptions, arginfo_phalcon_db_adapter_pdo_tableoptions, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, getDefaultIdValue, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo, supportSequences, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_view_engine_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine);

PHP_METHOD(Phalcon_Mvc_View_Engine, __construct);
PHP_METHOD(Phalcon_Mvc_View_Engine, getContent);
PHP_METHOD(Phalcon_Mvc_View_Engine, partial);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, view)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, partialPath)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_view_engine_method_entry){
	PHP_ME(Phalcon_Mvc_View_Engine, __construct, arginfo_phalcon_mvc_view_engine___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_View_Engine, getContent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine, partial, arginfo_phalcon_mvc_view_engine_partial, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_di_ce;

PHALCON_INIT_CLASS(Phalcon_DI);

PHP_METHOD(Phalcon_DI, __construct);
PHP_METHOD(Phalcon_DI, set);
PHP_METHOD(Phalcon_DI, setShared);
PHP_METHOD(Phalcon_DI, remove);
PHP_METHOD(Phalcon_DI, attempt);
PHP_METHOD(Phalcon_DI, getRaw);
PHP_METHOD(Phalcon_DI, getService);
PHP_METHOD(Phalcon_DI, get);
PHP_METHOD(Phalcon_DI, getShared);
PHP_METHOD(Phalcon_DI, has);
PHP_METHOD(Phalcon_DI, wasFreshInstance);
PHP_METHOD(Phalcon_DI, getServices);
PHP_METHOD(Phalcon_DI, __call);
PHP_METHOD(Phalcon_DI, setDefault);
PHP_METHOD(Phalcon_DI, getDefault);
PHP_METHOD(Phalcon_DI, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, config)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_setshared, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_attempt, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, config)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_getraw, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_getservice, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_getshared, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di___call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_setdefault, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_di_method_entry){
	PHP_ME(Phalcon_DI, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_DI, set, arginfo_phalcon_di_set, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, setShared, arginfo_phalcon_di_setshared, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, remove, arginfo_phalcon_di_remove, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, attempt, arginfo_phalcon_di_attempt, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, getRaw, arginfo_phalcon_di_getraw, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, getService, arginfo_phalcon_di_getservice, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, get, arginfo_phalcon_di_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, getShared, arginfo_phalcon_di_getshared, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, has, arginfo_phalcon_di_has, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, wasFreshInstance, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, getServices, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, __call, arginfo_phalcon_di___call, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI, setDefault, arginfo_phalcon_di_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_DI, getDefault, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_DI, reset, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_resultset_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Resultset);

PHP_METHOD(Phalcon_Mvc_Model_Resultset, next);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, key);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, rewind);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, seek);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, count);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetExists);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetGet);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetSet);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetUnset);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getFirst);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getLast);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, setIsFresh);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, isFresh);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, getCache);
PHP_METHOD(Phalcon_Mvc_Model_Resultset, current);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_seek, 0, 0, 1)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_setisfresh, 0, 0, 1)
	ZEND_ARG_INFO(0, isFresh)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_resultset_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Resultset, next, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, key, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, rewind, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, seek, arginfo_phalcon_mvc_model_resultset_seek, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, count, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, offsetExists, arginfo_phalcon_mvc_model_resultset_offsetexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, offsetGet, arginfo_phalcon_mvc_model_resultset_offsetget, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, offsetSet, arginfo_phalcon_mvc_model_resultset_offsetset, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, offsetUnset, arginfo_phalcon_mvc_model_resultset_offsetunset, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, getFirst, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, getLast, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, setIsFresh, arginfo_phalcon_mvc_model_resultset_setisfresh, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, isFresh, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, getCache, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset, current, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_flash_ce;

PHALCON_INIT_CLASS(Phalcon_Flash);

PHP_METHOD(Phalcon_Flash, __construct);
PHP_METHOD(Phalcon_Flash, setImplicitFlush);
PHP_METHOD(Phalcon_Flash, setAutomaticHtml);
PHP_METHOD(Phalcon_Flash, setCssClasses);
PHP_METHOD(Phalcon_Flash, error);
PHP_METHOD(Phalcon_Flash, notice);
PHP_METHOD(Phalcon_Flash, success);
PHP_METHOD(Phalcon_Flash, warning);
PHP_METHOD(Phalcon_Flash, outputMessage);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, cssClasses)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_setimplicitflush, 0, 0, 1)
	ZEND_ARG_INFO(0, implicitFlush)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_setautomatichtml, 0, 0, 1)
	ZEND_ARG_INFO(0, automaticHtml)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_setcssclasses, 0, 0, 1)
	ZEND_ARG_INFO(0, cssClasses)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_success, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_outputmessage, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_flash_method_entry){
	PHP_ME(Phalcon_Flash, __construct, arginfo_phalcon_flash___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Flash, setImplicitFlush, arginfo_phalcon_flash_setimplicitflush, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Flash, setAutomaticHtml, arginfo_phalcon_flash_setautomatichtml, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Flash, setCssClasses, arginfo_phalcon_flash_setcssclasses, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Flash, error, arginfo_phalcon_flash_error, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Flash, notice, arginfo_phalcon_flash_notice, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Flash, success, arginfo_phalcon_flash_success, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Flash, warning, arginfo_phalcon_flash_warning, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Flash, outputMessage, arginfo_phalcon_flash_outputmessage, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_dispatcher_ce;

PHALCON_INIT_CLASS(Phalcon_Dispatcher);

PHP_METHOD(Phalcon_Dispatcher, __construct);
PHP_METHOD(Phalcon_Dispatcher, setDI);
PHP_METHOD(Phalcon_Dispatcher, getDI);
PHP_METHOD(Phalcon_Dispatcher, setEventsManager);
PHP_METHOD(Phalcon_Dispatcher, getEventsManager);
PHP_METHOD(Phalcon_Dispatcher, setActionSuffix);
PHP_METHOD(Phalcon_Dispatcher, setNamespaceName);
PHP_METHOD(Phalcon_Dispatcher, getNamespaceName);
PHP_METHOD(Phalcon_Dispatcher, setDefaultNamespace);
PHP_METHOD(Phalcon_Dispatcher, getDefaultNamespace);
PHP_METHOD(Phalcon_Dispatcher, setDefaultAction);
PHP_METHOD(Phalcon_Dispatcher, setActionName);
PHP_METHOD(Phalcon_Dispatcher, getActionName);
PHP_METHOD(Phalcon_Dispatcher, setParams);
PHP_METHOD(Phalcon_Dispatcher, getParams);
PHP_METHOD(Phalcon_Dispatcher, setParam);
PHP_METHOD(Phalcon_Dispatcher, getParam);
PHP_METHOD(Phalcon_Dispatcher, isFinished);
PHP_METHOD(Phalcon_Dispatcher, getReturnedValue);
PHP_METHOD(Phalcon_Dispatcher, dispatch);
PHP_METHOD(Phalcon_Dispatcher, forward);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setactionsuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, actionSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setnamespacename, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setactionname, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setparams, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setparam, 0, 0, 2)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_forward, 0, 0, 1)
	ZEND_ARG_INFO(0, forward)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_dispatcher_method_entry){
	PHP_ME(Phalcon_Dispatcher, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Dispatcher, setDI, arginfo_phalcon_dispatcher_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, setEventsManager, arginfo_phalcon_dispatcher_seteventsmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, getEventsManager, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, setActionSuffix, arginfo_phalcon_dispatcher_setactionsuffix, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, setNamespaceName, arginfo_phalcon_dispatcher_setnamespacename, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, getNamespaceName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, setDefaultNamespace, arginfo_phalcon_dispatcher_setdefaultnamespace, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, getDefaultNamespace, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, setDefaultAction, arginfo_phalcon_dispatcher_setdefaultaction, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, setActionName, arginfo_phalcon_dispatcher_setactionname, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, getActionName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, setParams, arginfo_phalcon_dispatcher_setparams, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, getParams, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, setParam, arginfo_phalcon_dispatcher_setparam, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, getParam, arginfo_phalcon_dispatcher_getparam, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, isFinished, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, getReturnedValue, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, dispatch, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Dispatcher, forward, arginfo_phalcon_dispatcher_forward, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_session_adapter_ce;

PHALCON_INIT_CLASS(Phalcon_Session_Adapter);

PHP_METHOD(Phalcon_Session_Adapter, __construct);
PHP_METHOD(Phalcon_Session_Adapter, start);
PHP_METHOD(Phalcon_Session_Adapter, setOptions);
PHP_METHOD(Phalcon_Session_Adapter, getOptions);
PHP_METHOD(Phalcon_Session_Adapter, get);
PHP_METHOD(Phalcon_Session_Adapter, set);
PHP_METHOD(Phalcon_Session_Adapter, has);
PHP_METHOD(Phalcon_Session_Adapter, remove);
PHP_METHOD(Phalcon_Session_Adapter, getId);
PHP_METHOD(Phalcon_Session_Adapter, isStarted);
PHP_METHOD(Phalcon_Session_Adapter, destroy);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_set, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_has, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_session_adapter_method_entry){
	PHP_ME(Phalcon_Session_Adapter, __construct, arginfo_phalcon_session_adapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Session_Adapter, start, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, setOptions, arginfo_phalcon_session_adapter_setoptions, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, getOptions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, get, arginfo_phalcon_session_adapter_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, set, arginfo_phalcon_session_adapter_set, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, has, arginfo_phalcon_session_adapter_has, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, remove, arginfo_phalcon_session_adapter_remove, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, getId, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, isStarted, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Adapter, destroy, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_di_factorydefault_ce;

PHALCON_INIT_CLASS(Phalcon_DI_FactoryDefault);

PHP_METHOD(Phalcon_DI_FactoryDefault, __construct);

PHALCON_INIT_FUNCS(phalcon_di_factorydefault_method_entry){
	PHP_ME(Phalcon_DI_FactoryDefault, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_FE_END
};



zend_class_entry *phalcon_logger_adapter_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Adapter);

PHP_METHOD(Phalcon_Logger_Adapter, setFormat);
PHP_METHOD(Phalcon_Logger_Adapter, getFormat);
PHP_METHOD(Phalcon_Logger_Adapter, _applyFormat);
PHP_METHOD(Phalcon_Logger_Adapter, setDateFormat);
PHP_METHOD(Phalcon_Logger_Adapter, getDateFormat);
PHP_METHOD(Phalcon_Logger_Adapter, getTypeString);
PHP_METHOD(Phalcon_Logger_Adapter, debug);
PHP_METHOD(Phalcon_Logger_Adapter, error);
PHP_METHOD(Phalcon_Logger_Adapter, info);
PHP_METHOD(Phalcon_Logger_Adapter, notice);
PHP_METHOD(Phalcon_Logger_Adapter, warning);
PHP_METHOD(Phalcon_Logger_Adapter, alert);
PHP_METHOD(Phalcon_Logger_Adapter, log);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_setformat, 0, 0, 1)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_setdateformat, 0, 0, 1)
	ZEND_ARG_INFO(0, date)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_gettypestring, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_log, 0, 0, 2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_logger_adapter_method_entry){
	PHP_ME(Phalcon_Logger_Adapter, setFormat, arginfo_phalcon_logger_adapter_setformat, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, getFormat, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, _applyFormat, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Logger_Adapter, setDateFormat, arginfo_phalcon_logger_adapter_setdateformat, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, getDateFormat, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, getTypeString, arginfo_phalcon_logger_adapter_gettypestring, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, debug, arginfo_phalcon_logger_adapter_debug, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, error, arginfo_phalcon_logger_adapter_error, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, info, arginfo_phalcon_logger_adapter_info, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, notice, arginfo_phalcon_logger_adapter_notice, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, warning, arginfo_phalcon_logger_adapter_warning, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, alert, arginfo_phalcon_logger_adapter_alert, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter, log, arginfo_phalcon_logger_adapter_log, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_config_ce;

PHALCON_INIT_CLASS(Phalcon_Config);

PHP_METHOD(Phalcon_Config, __construct);
PHP_METHOD(Phalcon_Config, offsetExists);
PHP_METHOD(Phalcon_Config, get);
PHP_METHOD(Phalcon_Config, offsetGet);
PHP_METHOD(Phalcon_Config, offsetSet);
PHP_METHOD(Phalcon_Config, offsetUnset);
PHP_METHOD(Phalcon_Config, merge);
PHP_METHOD(Phalcon_Config, toArray);
PHP_METHOD(Phalcon_Config, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, arrayConfig)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_merge, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_config_method_entry){
	PHP_ME(Phalcon_Config, __construct, arginfo_phalcon_config___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Config, offsetExists, arginfo_phalcon_config_offsetexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Config, get, arginfo_phalcon_config_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Config, offsetGet, arginfo_phalcon_config_offsetget, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Config, offsetSet, arginfo_phalcon_config_offsetset, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Config, offsetUnset, arginfo_phalcon_config_offsetunset, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Config, merge, arginfo_phalcon_config_merge, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Config, toArray, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Config, __set_state, arginfo_phalcon_config___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_behavior_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Behavior);


zend_class_entry *phalcon_acl_adapter_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_Adapter);

PHP_METHOD(Phalcon_Acl_Adapter, setEventsManager);
PHP_METHOD(Phalcon_Acl_Adapter, getEventsManager);
PHP_METHOD(Phalcon_Acl_Adapter, setDefaultAction);
PHP_METHOD(Phalcon_Acl_Adapter, getDefaultAction);
PHP_METHOD(Phalcon_Acl_Adapter, getActiveRole);
PHP_METHOD(Phalcon_Acl_Adapter, getActiveResource);
PHP_METHOD(Phalcon_Acl_Adapter, getActiveAccess);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultAccess)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_acl_adapter_method_entry){
	PHP_ME(Phalcon_Acl_Adapter, setEventsManager, arginfo_phalcon_acl_adapter_seteventsmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter, getEventsManager, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter, setDefaultAction, arginfo_phalcon_acl_adapter_setdefaultaction, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter, getDefaultAction, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter, getActiveRole, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter, getActiveResource, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter, getActiveAccess, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Exception);


zend_class_entry *phalcon_translate_adapter_ce;

PHALCON_INIT_CLASS(Phalcon_Translate_Adapter);

PHP_METHOD(Phalcon_Translate_Adapter, _);
PHP_METHOD(Phalcon_Translate_Adapter, offsetSet);
PHP_METHOD(Phalcon_Translate_Adapter, offsetExists);
PHP_METHOD(Phalcon_Translate_Adapter, offsetUnset);
PHP_METHOD(Phalcon_Translate_Adapter, offsetGet);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter__, 0, 0, 1)
	ZEND_ARG_INFO(0, translateKey)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, translateKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, traslateKey)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_translate_adapter_method_entry){
	PHP_ME(Phalcon_Translate_Adapter, _, arginfo_phalcon_translate_adapter__, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Translate_Adapter, offsetSet, arginfo_phalcon_translate_adapter_offsetset, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Translate_Adapter, offsetExists, arginfo_phalcon_translate_adapter_offsetexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Translate_Adapter, offsetUnset, arginfo_phalcon_translate_adapter_offsetunset, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Translate_Adapter, offsetGet, arginfo_phalcon_translate_adapter_offsetget, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_tag_ce;

PHALCON_INIT_CLASS(Phalcon_Tag);

PHP_METHOD(Phalcon_Tag, setDI);
PHP_METHOD(Phalcon_Tag, getDI);
PHP_METHOD(Phalcon_Tag, getUrlService);
PHP_METHOD(Phalcon_Tag, getDispatcherService);
PHP_METHOD(Phalcon_Tag, setDefault);
PHP_METHOD(Phalcon_Tag, displayTo);
PHP_METHOD(Phalcon_Tag, getValue);
PHP_METHOD(Phalcon_Tag, resetInput);
PHP_METHOD(Phalcon_Tag, linkTo);
PHP_METHOD(Phalcon_Tag, _inputField);
PHP_METHOD(Phalcon_Tag, textField);
PHP_METHOD(Phalcon_Tag, passwordField);
PHP_METHOD(Phalcon_Tag, hiddenField);
PHP_METHOD(Phalcon_Tag, fileField);
PHP_METHOD(Phalcon_Tag, checkField);
PHP_METHOD(Phalcon_Tag, radioField);
PHP_METHOD(Phalcon_Tag, submitButton);
PHP_METHOD(Phalcon_Tag, selectStatic);
PHP_METHOD(Phalcon_Tag, select);
PHP_METHOD(Phalcon_Tag, textArea);
PHP_METHOD(Phalcon_Tag, form);
PHP_METHOD(Phalcon_Tag, endForm);
PHP_METHOD(Phalcon_Tag, setTitle);
PHP_METHOD(Phalcon_Tag, appendTitle);
PHP_METHOD(Phalcon_Tag, prependTitle);
PHP_METHOD(Phalcon_Tag, getTitle);
PHP_METHOD(Phalcon_Tag, stylesheetLink);
PHP_METHOD(Phalcon_Tag, javascriptInclude);
PHP_METHOD(Phalcon_Tag, image);
PHP_METHOD(Phalcon_Tag, friendlyTitle);
PHP_METHOD(Phalcon_Tag, setDocType);
PHP_METHOD(Phalcon_Tag, getDocType);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setdefault, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_displayto, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_getvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_linkto, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_textfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_passwordfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_hiddenfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_filefield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_checkfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_radiofield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_submitbutton, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_selectstatic, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_select, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_textarea, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_form, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_settitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_appendtitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_prependtitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_stylesheetlink, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_javascriptinclude, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_image, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_friendlytitle, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, separator)
	ZEND_ARG_INFO(0, lowercase)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setdoctype, 0, 0, 1)
	ZEND_ARG_INFO(0, doctype)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_tag_method_entry){
	PHP_ME(Phalcon_Tag, setDI, arginfo_phalcon_tag_setdi, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, getDI, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, getUrlService, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, getDispatcherService, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, setDefault, arginfo_phalcon_tag_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, displayTo, arginfo_phalcon_tag_displayto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, getValue, arginfo_phalcon_tag_getvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, resetInput, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, linkTo, arginfo_phalcon_tag_linkto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, _inputField, NULL, ZEND_ACC_STATIC|ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Tag, textField, arginfo_phalcon_tag_textfield, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, passwordField, arginfo_phalcon_tag_passwordfield, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, hiddenField, arginfo_phalcon_tag_hiddenfield, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, fileField, arginfo_phalcon_tag_filefield, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, checkField, arginfo_phalcon_tag_checkfield, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, radioField, arginfo_phalcon_tag_radiofield, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, submitButton, arginfo_phalcon_tag_submitbutton, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, selectStatic, arginfo_phalcon_tag_selectstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, select, arginfo_phalcon_tag_select, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, textArea, arginfo_phalcon_tag_textarea, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Tag, form, arginfo_phalcon_tag_form, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, endForm, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, setTitle, arginfo_phalcon_tag_settitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, appendTitle, arginfo_phalcon_tag_appendtitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, prependTitle, arginfo_phalcon_tag_prependtitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, getTitle, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, stylesheetLink, arginfo_phalcon_tag_stylesheetlink, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, javascriptInclude, arginfo_phalcon_tag_javascriptinclude, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, image, arginfo_phalcon_tag_image, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, friendlyTitle, arginfo_phalcon_tag_friendlytitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, setDocType, arginfo_phalcon_tag_setdoctype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag, getDocType, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_ce;

PHALCON_INIT_CLASS(Phalcon_Db);


zend_class_entry *phalcon_acl_ce;

PHALCON_INIT_CLASS(Phalcon_Acl);


zend_class_entry *phalcon_cache_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Exception);


zend_class_entry *phalcon_cache_backend_file_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_File);

PHP_METHOD(Phalcon_Cache_Backend_File, __construct);
PHP_METHOD(Phalcon_Cache_Backend_File, get);
PHP_METHOD(Phalcon_Cache_Backend_File, save);
PHP_METHOD(Phalcon_Cache_Backend_File, delete);
PHP_METHOD(Phalcon_Cache_Backend_File, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_File, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, frontend)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_backend_file_method_entry){
	PHP_ME(Phalcon_Cache_Backend_File, __construct, arginfo_phalcon_cache_backend_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Cache_Backend_File, get, arginfo_phalcon_cache_backend_file_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_File, save, arginfo_phalcon_cache_backend_file_save, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_File, delete, arginfo_phalcon_cache_backend_file_delete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_File, queryKeys, arginfo_phalcon_cache_backend_file_querykeys, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_File, exists, arginfo_phalcon_cache_backend_file_exists, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_cache_backend_apc_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Apc);

PHP_METHOD(Phalcon_Cache_Backend_Apc, get);
PHP_METHOD(Phalcon_Cache_Backend_Apc, save);
PHP_METHOD(Phalcon_Cache_Backend_Apc, delete);
PHP_METHOD(Phalcon_Cache_Backend_Apc, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_Apc, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apc_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apc_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apc_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apc_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apc_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_backend_apc_method_entry){
	PHP_ME(Phalcon_Cache_Backend_Apc, get, arginfo_phalcon_cache_backend_apc_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Apc, save, arginfo_phalcon_cache_backend_apc_save, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Apc, delete, arginfo_phalcon_cache_backend_apc_delete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Apc, queryKeys, arginfo_phalcon_cache_backend_apc_querykeys, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Apc, exists, arginfo_phalcon_cache_backend_apc_exists, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_cache_backend_mongo_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Mongo);

PHP_METHOD(Phalcon_Cache_Backend_Mongo, __construct);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, _getCollection);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, get);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, save);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, delete);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, frontend)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_backend_mongo_method_entry){
	PHP_ME(Phalcon_Cache_Backend_Mongo, __construct, arginfo_phalcon_cache_backend_mongo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Cache_Backend_Mongo, _getCollection, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Cache_Backend_Mongo, get, arginfo_phalcon_cache_backend_mongo_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Mongo, save, arginfo_phalcon_cache_backend_mongo_save, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Mongo, delete, arginfo_phalcon_cache_backend_mongo_delete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Mongo, queryKeys, arginfo_phalcon_cache_backend_mongo_querykeys, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Mongo, exists, arginfo_phalcon_cache_backend_mongo_exists, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_cache_backend_memcache_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Memcache);

PHP_METHOD(Phalcon_Cache_Backend_Memcache, __construct);
PHP_METHOD(Phalcon_Cache_Backend_Memcache, _connect);
PHP_METHOD(Phalcon_Cache_Backend_Memcache, get);
PHP_METHOD(Phalcon_Cache_Backend_Memcache, save);
PHP_METHOD(Phalcon_Cache_Backend_Memcache, delete);
PHP_METHOD(Phalcon_Cache_Backend_Memcache, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_Memcache, exists);
PHP_METHOD(Phalcon_Cache_Backend_Memcache, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, frontend)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_backend_memcache_method_entry){
	PHP_ME(Phalcon_Cache_Backend_Memcache, __construct, arginfo_phalcon_cache_backend_memcache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Cache_Backend_Memcache, _connect, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Cache_Backend_Memcache, get, arginfo_phalcon_cache_backend_memcache_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Memcache, save, arginfo_phalcon_cache_backend_memcache_save, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Memcache, delete, arginfo_phalcon_cache_backend_memcache_delete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Memcache, queryKeys, arginfo_phalcon_cache_backend_memcache_querykeys, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Memcache, exists, arginfo_phalcon_cache_backend_memcache_exists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Backend_Memcache, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR) 
	PHP_FE_END
};



zend_class_entry *phalcon_cache_frontend_output_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_Output);

PHP_METHOD(Phalcon_Cache_Frontend_Output, __construct);
PHP_METHOD(Phalcon_Cache_Frontend_Output, getLifetime);
PHP_METHOD(Phalcon_Cache_Frontend_Output, isBuffering);
PHP_METHOD(Phalcon_Cache_Frontend_Output, start);
PHP_METHOD(Phalcon_Cache_Frontend_Output, getContent);
PHP_METHOD(Phalcon_Cache_Frontend_Output, stop);
PHP_METHOD(Phalcon_Cache_Frontend_Output, beforeStore);
PHP_METHOD(Phalcon_Cache_Frontend_Output, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_output___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontendOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_output_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_output_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_frontend_output_method_entry){
	PHP_ME(Phalcon_Cache_Frontend_Output, __construct, arginfo_phalcon_cache_frontend_output___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Cache_Frontend_Output, getLifetime, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Output, isBuffering, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Output, start, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Output, getContent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Output, stop, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Output, beforeStore, arginfo_phalcon_cache_frontend_output_beforestore, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Output, afterRetrieve, arginfo_phalcon_cache_frontend_output_afterretrieve, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_cache_frontend_data_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_Data);

PHP_METHOD(Phalcon_Cache_Frontend_Data, __construct);
PHP_METHOD(Phalcon_Cache_Frontend_Data, getLifetime);
PHP_METHOD(Phalcon_Cache_Frontend_Data, isBuffering);
PHP_METHOD(Phalcon_Cache_Frontend_Data, start);
PHP_METHOD(Phalcon_Cache_Frontend_Data, getContent);
PHP_METHOD(Phalcon_Cache_Frontend_Data, stop);
PHP_METHOD(Phalcon_Cache_Frontend_Data, beforeStore);
PHP_METHOD(Phalcon_Cache_Frontend_Data, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_data___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontendOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_data_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_data_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_frontend_data_method_entry){
	PHP_ME(Phalcon_Cache_Frontend_Data, __construct, arginfo_phalcon_cache_frontend_data___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Cache_Frontend_Data, getLifetime, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Data, isBuffering, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Data, start, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Data, getContent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Data, stop, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Data, beforeStore, arginfo_phalcon_cache_frontend_data_beforestore, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Data, afterRetrieve, arginfo_phalcon_cache_frontend_data_afterretrieve, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_cache_frontend_base64_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_Base64);

PHP_METHOD(Phalcon_Cache_Frontend_Base64, __construct);
PHP_METHOD(Phalcon_Cache_Frontend_Base64, getLifetime);
PHP_METHOD(Phalcon_Cache_Frontend_Base64, isBuffering);
PHP_METHOD(Phalcon_Cache_Frontend_Base64, start);
PHP_METHOD(Phalcon_Cache_Frontend_Base64, getContent);
PHP_METHOD(Phalcon_Cache_Frontend_Base64, stop);
PHP_METHOD(Phalcon_Cache_Frontend_Base64, beforeStore);
PHP_METHOD(Phalcon_Cache_Frontend_Base64, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_base64___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontendOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_base64_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_base64_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_frontend_base64_method_entry){
	PHP_ME(Phalcon_Cache_Frontend_Base64, __construct, arginfo_phalcon_cache_frontend_base64___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Cache_Frontend_Base64, getLifetime, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Base64, isBuffering, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Base64, start, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Base64, getContent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Base64, stop, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Base64, beforeStore, arginfo_phalcon_cache_frontend_base64_beforestore, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_Base64, afterRetrieve, arginfo_phalcon_cache_frontend_base64_afterretrieve, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_cache_frontend_none_ce;

PHALCON_INIT_CLASS(Phalcon_Cache_Frontend_None);

PHP_METHOD(Phalcon_Cache_Frontend_None, __construct);
PHP_METHOD(Phalcon_Cache_Frontend_None, getLifetime);
PHP_METHOD(Phalcon_Cache_Frontend_None, isBuffering);
PHP_METHOD(Phalcon_Cache_Frontend_None, start);
PHP_METHOD(Phalcon_Cache_Frontend_None, getContent);
PHP_METHOD(Phalcon_Cache_Frontend_None, stop);
PHP_METHOD(Phalcon_Cache_Frontend_None, beforeStore);
PHP_METHOD(Phalcon_Cache_Frontend_None, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_none___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontendOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_none_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_none_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cache_frontend_none_method_entry){
	PHP_ME(Phalcon_Cache_Frontend_None, __construct, arginfo_phalcon_cache_frontend_none___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Cache_Frontend_None, getLifetime, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_None, isBuffering, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_None, start, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_None, getContent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_None, stop, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_None, beforeStore, arginfo_phalcon_cache_frontend_none_beforestore, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Cache_Frontend_None, afterRetrieve, arginfo_phalcon_cache_frontend_none_afterretrieve, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_tag_select_ce;

PHALCON_INIT_CLASS(Phalcon_Tag_Select);

PHP_METHOD(Phalcon_Tag_Select, selectField);
PHP_METHOD(Phalcon_Tag_Select, _optionsFromResultset);
PHP_METHOD(Phalcon_Tag_Select, _optionsFromArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_select_selectfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_tag_select_method_entry){
	PHP_ME(Phalcon_Tag_Select, selectField, arginfo_phalcon_tag_select_selectfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag_Select, _optionsFromResultset, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Tag_Select, _optionsFromArray, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_tag_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Tag_Exception);


zend_class_entry *phalcon_paginator_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Paginator_Exception);


zend_class_entry *phalcon_paginator_adapter_model_ce;

PHALCON_INIT_CLASS(Phalcon_Paginator_Adapter_Model);

PHP_METHOD(Phalcon_Paginator_Adapter_Model, __construct);
PHP_METHOD(Phalcon_Paginator_Adapter_Model, setCurrentPage);
PHP_METHOD(Phalcon_Paginator_Adapter_Model, getPaginate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_model___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_model_setcurrentpage, 0, 0, 1)
	ZEND_ARG_INFO(0, page)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_paginator_adapter_model_method_entry){
	PHP_ME(Phalcon_Paginator_Adapter_Model, __construct, arginfo_phalcon_paginator_adapter_model___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Paginator_Adapter_Model, setCurrentPage, arginfo_phalcon_paginator_adapter_model_setcurrentpage, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Paginator_Adapter_Model, getPaginate, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_paginator_adapter_nativearray_ce;

PHALCON_INIT_CLASS(Phalcon_Paginator_Adapter_NativeArray);

PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, __construct);
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, setCurrentPage);
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, getPaginate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_nativearray___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_nativearray_setcurrentpage, 0, 0, 1)
	ZEND_ARG_INFO(0, page)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_paginator_adapter_nativearray_method_entry){
	PHP_ME(Phalcon_Paginator_Adapter_NativeArray, __construct, arginfo_phalcon_paginator_adapter_nativearray___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Paginator_Adapter_NativeArray, setCurrentPage, arginfo_phalcon_paginator_adapter_nativearray_setcurrentpage, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Paginator_Adapter_NativeArray, getPaginate, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_index_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Index);

PHP_METHOD(Phalcon_Db_Index, __construct);
PHP_METHOD(Phalcon_Db_Index, getName);
PHP_METHOD(Phalcon_Db_Index, getColumns);
PHP_METHOD(Phalcon_Db_Index, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_index___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, indexName)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_index___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_index_method_entry){
	PHP_ME(Phalcon_Db_Index, __construct, arginfo_phalcon_db_index___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Db_Index, getName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Index, getColumns, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Index, __set_state, arginfo_phalcon_db_index___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_column_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Column);

PHP_METHOD(Phalcon_Db_Column, __construct);
PHP_METHOD(Phalcon_Db_Column, getSchemaName);
PHP_METHOD(Phalcon_Db_Column, getName);
PHP_METHOD(Phalcon_Db_Column, getType);
PHP_METHOD(Phalcon_Db_Column, getSize);
PHP_METHOD(Phalcon_Db_Column, getScale);
PHP_METHOD(Phalcon_Db_Column, isUnsigned);
PHP_METHOD(Phalcon_Db_Column, isNotNull);
PHP_METHOD(Phalcon_Db_Column, isPrimary);
PHP_METHOD(Phalcon_Db_Column, isAutoIncrement);
PHP_METHOD(Phalcon_Db_Column, isNumeric);
PHP_METHOD(Phalcon_Db_Column, isFirst);
PHP_METHOD(Phalcon_Db_Column, getAfterPosition);
PHP_METHOD(Phalcon_Db_Column, getBindType);
PHP_METHOD(Phalcon_Db_Column, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_column___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, columnName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_column___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_column_method_entry){
	PHP_ME(Phalcon_Db_Column, __construct, arginfo_phalcon_db_column___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Db_Column, getSchemaName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Column, getName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Column, getType, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Column, getSize, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Column, getScale, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Column, isUnsigned, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Column, isNotNull, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Column, isPrimary, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Column, isAutoIncrement, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Column, isNumeric, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Column, isFirst, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Column, getAfterPosition, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Column, getBindType, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Column, __set_state, arginfo_phalcon_db_column___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_adapter_pdo_mysql_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Mysql);

PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, escapeIdentifier);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_mysql_escapeidentifier, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_mysql_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_adapter_pdo_mysql_method_entry){
	PHP_ME(Phalcon_Db_Adapter_Pdo_Mysql, escapeIdentifier, arginfo_phalcon_db_adapter_pdo_mysql_escapeidentifier, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns, arginfo_phalcon_db_adapter_pdo_mysql_describecolumns, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_adapter_pdo_sqlite_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Sqlite);

PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, connect);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeColumns);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeIndexes);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeReferences);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_adapter_pdo_sqlite_method_entry){
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, connect, arginfo_phalcon_db_adapter_pdo_sqlite_connect, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, describeColumns, arginfo_phalcon_db_adapter_pdo_sqlite_describecolumns, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, describeIndexes, arginfo_phalcon_db_adapter_pdo_sqlite_describeindexes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, describeReferences, arginfo_phalcon_db_adapter_pdo_sqlite_describereferences, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_adapter_pdo_postgresql_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Postgresql);

PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, connect);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeColumns);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, getDefaultIdValue);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, supportSequences);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_adapter_pdo_postgresql_method_entry){
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, connect, arginfo_phalcon_db_adapter_pdo_postgresql_connect, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, describeColumns, arginfo_phalcon_db_adapter_pdo_postgresql_describecolumns, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, getDefaultIdValue, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, supportSequences, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_dialect_mysql_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Dialect_Mysql);

PHP_METHOD(Phalcon_Db_Dialect_Mysql, getColumnDefinition);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addColumn);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, modifyColumn);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropColumn);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addIndex);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropIndex);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, _getTableOptions);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, createTable);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropTable);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableExists);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeColumns);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, listTables);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeIndexes);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeReferences);
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableOptions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, reference)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_droptable, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_dialect_mysql_method_entry){
	PHP_ME(Phalcon_Db_Dialect_Mysql, getColumnDefinition, arginfo_phalcon_db_dialect_mysql_getcolumndefinition, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, addColumn, arginfo_phalcon_db_dialect_mysql_addcolumn, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, modifyColumn, arginfo_phalcon_db_dialect_mysql_modifycolumn, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, dropColumn, arginfo_phalcon_db_dialect_mysql_dropcolumn, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, addIndex, arginfo_phalcon_db_dialect_mysql_addindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, dropIndex, arginfo_phalcon_db_dialect_mysql_dropindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, addPrimaryKey, arginfo_phalcon_db_dialect_mysql_addprimarykey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, dropPrimaryKey, arginfo_phalcon_db_dialect_mysql_dropprimarykey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, addForeignKey, arginfo_phalcon_db_dialect_mysql_addforeignkey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, dropForeignKey, arginfo_phalcon_db_dialect_mysql_dropforeignkey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, _getTableOptions, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, createTable, arginfo_phalcon_db_dialect_mysql_createtable, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, dropTable, arginfo_phalcon_db_dialect_mysql_droptable, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, tableExists, arginfo_phalcon_db_dialect_mysql_tableexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, describeColumns, arginfo_phalcon_db_dialect_mysql_describecolumns, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, listTables, arginfo_phalcon_db_dialect_mysql_listtables, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, describeIndexes, arginfo_phalcon_db_dialect_mysql_describeindexes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, describeReferences, arginfo_phalcon_db_dialect_mysql_describereferences, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Mysql, tableOptions, arginfo_phalcon_db_dialect_mysql_tableoptions, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_dialect_sqlite_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Dialect_Sqlite);

PHP_METHOD(Phalcon_Db_Dialect_Sqlite, getColumnDefinition);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addColumn);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, modifyColumn);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropColumn);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addIndex);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropIndex);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, _getTableOptions);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createTable);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropTable);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, tableExists);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeColumns);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listTables);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndexes);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndex);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeReferences);
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, tableOptions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, reference)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_droptable, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_describeindex, 0, 0, 1)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_dialect_sqlite_method_entry){
	PHP_ME(Phalcon_Db_Dialect_Sqlite, getColumnDefinition, arginfo_phalcon_db_dialect_sqlite_getcolumndefinition, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, addColumn, arginfo_phalcon_db_dialect_sqlite_addcolumn, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, modifyColumn, arginfo_phalcon_db_dialect_sqlite_modifycolumn, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, dropColumn, arginfo_phalcon_db_dialect_sqlite_dropcolumn, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, addIndex, arginfo_phalcon_db_dialect_sqlite_addindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, dropIndex, arginfo_phalcon_db_dialect_sqlite_dropindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, addPrimaryKey, arginfo_phalcon_db_dialect_sqlite_addprimarykey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, dropPrimaryKey, arginfo_phalcon_db_dialect_sqlite_dropprimarykey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, addForeignKey, arginfo_phalcon_db_dialect_sqlite_addforeignkey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, dropForeignKey, arginfo_phalcon_db_dialect_sqlite_dropforeignkey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, _getTableOptions, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, createTable, arginfo_phalcon_db_dialect_sqlite_createtable, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, dropTable, arginfo_phalcon_db_dialect_sqlite_droptable, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, tableExists, arginfo_phalcon_db_dialect_sqlite_tableexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, describeColumns, arginfo_phalcon_db_dialect_sqlite_describecolumns, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, listTables, arginfo_phalcon_db_dialect_sqlite_listtables, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, describeIndexes, arginfo_phalcon_db_dialect_sqlite_describeindexes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, describeIndex, arginfo_phalcon_db_dialect_sqlite_describeindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, describeReferences, arginfo_phalcon_db_dialect_sqlite_describereferences, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Sqlite, tableOptions, arginfo_phalcon_db_dialect_sqlite_tableoptions, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_dialect_postgresql_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Dialect_Postgresql);

PHP_METHOD(Phalcon_Db_Dialect_Postgresql, getColumnDefinition);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addColumn);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, modifyColumn);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropColumn);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addIndex);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropIndex);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropPrimaryKey);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropForeignKey);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, _getTableOptions);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createTable);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropTable);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableExists);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeColumns);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, listTables);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeIndexes);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeReferences);
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableOptions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, reference)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_droptable, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_dialect_postgresql_method_entry){
	PHP_ME(Phalcon_Db_Dialect_Postgresql, getColumnDefinition, arginfo_phalcon_db_dialect_postgresql_getcolumndefinition, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, addColumn, arginfo_phalcon_db_dialect_postgresql_addcolumn, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, modifyColumn, arginfo_phalcon_db_dialect_postgresql_modifycolumn, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropColumn, arginfo_phalcon_db_dialect_postgresql_dropcolumn, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, addIndex, arginfo_phalcon_db_dialect_postgresql_addindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropIndex, arginfo_phalcon_db_dialect_postgresql_dropindex, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, addPrimaryKey, arginfo_phalcon_db_dialect_postgresql_addprimarykey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropPrimaryKey, arginfo_phalcon_db_dialect_postgresql_dropprimarykey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, addForeignKey, arginfo_phalcon_db_dialect_postgresql_addforeignkey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropForeignKey, arginfo_phalcon_db_dialect_postgresql_dropforeignkey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, _getTableOptions, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, createTable, arginfo_phalcon_db_dialect_postgresql_createtable, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropTable, arginfo_phalcon_db_dialect_postgresql_droptable, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, tableExists, arginfo_phalcon_db_dialect_postgresql_tableexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, describeColumns, arginfo_phalcon_db_dialect_postgresql_describecolumns, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, listTables, arginfo_phalcon_db_dialect_postgresql_listtables, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, describeIndexes, arginfo_phalcon_db_dialect_postgresql_describeindexes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, describeReferences, arginfo_phalcon_db_dialect_postgresql_describereferences, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Dialect_Postgresql, tableOptions, arginfo_phalcon_db_dialect_postgresql_tableoptions, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Exception);


zend_class_entry *phalcon_db_profiler_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Profiler);

PHP_METHOD(Phalcon_Db_Profiler, __construct);
PHP_METHOD(Phalcon_Db_Profiler, startProfile);
PHP_METHOD(Phalcon_Db_Profiler, stopProfile);
PHP_METHOD(Phalcon_Db_Profiler, getNumberTotalStatements);
PHP_METHOD(Phalcon_Db_Profiler, getTotalElapsedSeconds);
PHP_METHOD(Phalcon_Db_Profiler, getProfiles);
PHP_METHOD(Phalcon_Db_Profiler, reset);
PHP_METHOD(Phalcon_Db_Profiler, getLastProfile);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_startprofile, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_profiler_method_entry){
	PHP_ME(Phalcon_Db_Profiler, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Db_Profiler, startProfile, arginfo_phalcon_db_profiler_startprofile, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Profiler, stopProfile, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Profiler, getNumberTotalStatements, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Profiler, getTotalElapsedSeconds, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Profiler, getProfiles, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Profiler, reset, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Profiler, getLastProfile, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_profiler_item_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Profiler_Item);

PHP_METHOD(Phalcon_Db_Profiler_Item, setSQLStatement);
PHP_METHOD(Phalcon_Db_Profiler_Item, getSQLStatement);
PHP_METHOD(Phalcon_Db_Profiler_Item, setInitialTime);
PHP_METHOD(Phalcon_Db_Profiler_Item, setFinalTime);
PHP_METHOD(Phalcon_Db_Profiler_Item, getInitialTime);
PHP_METHOD(Phalcon_Db_Profiler_Item, getFinalTime);
PHP_METHOD(Phalcon_Db_Profiler_Item, getTotalElapsedSeconds);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setsqlstatement, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setinitialtime, 0, 0, 1)
	ZEND_ARG_INFO(0, initialTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setfinaltime, 0, 0, 1)
	ZEND_ARG_INFO(0, finalTime)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_profiler_item_method_entry){
	PHP_ME(Phalcon_Db_Profiler_Item, setSQLStatement, arginfo_phalcon_db_profiler_item_setsqlstatement, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Profiler_Item, getSQLStatement, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Profiler_Item, setInitialTime, arginfo_phalcon_db_profiler_item_setinitialtime, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Profiler_Item, setFinalTime, arginfo_phalcon_db_profiler_item_setfinaltime, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Profiler_Item, getInitialTime, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Profiler_Item, getFinalTime, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Profiler_Item, getTotalElapsedSeconds, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_rawvalue_ce;

PHALCON_INIT_CLASS(Phalcon_Db_RawValue);

PHP_METHOD(Phalcon_Db_RawValue, __construct);
PHP_METHOD(Phalcon_Db_RawValue, getValue);
PHP_METHOD(Phalcon_Db_RawValue, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_rawvalue___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_rawvalue_method_entry){
	PHP_ME(Phalcon_Db_RawValue, __construct, arginfo_phalcon_db_rawvalue___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Db_RawValue, getValue, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_RawValue, __toString, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_reference_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Reference);

PHP_METHOD(Phalcon_Db_Reference, __construct);
PHP_METHOD(Phalcon_Db_Reference, getName);
PHP_METHOD(Phalcon_Db_Reference, getSchemaName);
PHP_METHOD(Phalcon_Db_Reference, getReferencedSchema);
PHP_METHOD(Phalcon_Db_Reference, getColumns);
PHP_METHOD(Phalcon_Db_Reference, getReferencedTable);
PHP_METHOD(Phalcon_Db_Reference, getReferencedColumns);
PHP_METHOD(Phalcon_Db_Reference, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_reference___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, referenceName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_reference___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_reference_method_entry){
	PHP_ME(Phalcon_Db_Reference, __construct, arginfo_phalcon_db_reference___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Db_Reference, getName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Reference, getSchemaName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Reference, getReferencedSchema, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Reference, getColumns, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Reference, getReferencedTable, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Reference, getReferencedColumns, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Reference, __set_state, arginfo_phalcon_db_reference___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_result_pdo_ce;

PHALCON_INIT_CLASS(Phalcon_Db_Result_Pdo);

PHP_METHOD(Phalcon_Db_Result_Pdo, __construct);
PHP_METHOD(Phalcon_Db_Result_Pdo, execute);
PHP_METHOD(Phalcon_Db_Result_Pdo, fetch);
PHP_METHOD(Phalcon_Db_Result_Pdo, fetchArray);
PHP_METHOD(Phalcon_Db_Result_Pdo, fetchAll);
PHP_METHOD(Phalcon_Db_Result_Pdo, numRows);
PHP_METHOD(Phalcon_Db_Result_Pdo, dataSeek);
PHP_METHOD(Phalcon_Db_Result_Pdo, setFetchMode);
PHP_METHOD(Phalcon_Db_Result_Pdo, getInternalResult);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_result_pdo___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, connection)
	ZEND_ARG_INFO(0, result)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_result_pdo_dataseek, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_result_pdo_setfetchmode, 0, 0, 1)
	ZEND_ARG_INFO(0, fetchMode)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_result_pdo_method_entry){
	PHP_ME(Phalcon_Db_Result_Pdo, __construct, arginfo_phalcon_db_result_pdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Db_Result_Pdo, execute, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Result_Pdo, fetch, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Result_Pdo, fetchArray, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Result_Pdo, fetchAll, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Result_Pdo, numRows, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Result_Pdo, dataSeek, arginfo_phalcon_db_result_pdo_dataseek, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Result_Pdo, setFetchMode, arginfo_phalcon_db_result_pdo_setfetchmode, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Db_Result_Pdo, getInternalResult, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_db_resultinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Db_ResultInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, connection)
	ZEND_ARG_INFO(0, result)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_dataseek, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_setfetchmode, 0, 0, 1)
	ZEND_ARG_INFO(0, fetchMode)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_db_resultinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, __construct, arginfo_phalcon_db_resultinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, execute, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetch, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetchArray, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetchAll, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, numRows, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, dataSeek, arginfo_phalcon_db_resultinterface_dataseek)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, setFetchMode, arginfo_phalcon_db_resultinterface_setfetchmode)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, getInternalResult, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_acl_role_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_Role);

PHP_METHOD(Phalcon_Acl_Role, __construct);
PHP_METHOD(Phalcon_Acl_Role, getName);
PHP_METHOD(Phalcon_Acl_Role, getDescription);
PHP_METHOD(Phalcon_Acl_Role, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_role___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_acl_role_method_entry){
	PHP_ME(Phalcon_Acl_Role, __construct, arginfo_phalcon_acl_role___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Acl_Role, getName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Role, getDescription, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Role, __toString, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_acl_resource_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_Resource);

PHP_METHOD(Phalcon_Acl_Resource, __construct);
PHP_METHOD(Phalcon_Acl_Resource, getName);
PHP_METHOD(Phalcon_Acl_Resource, getDescription);
PHP_METHOD(Phalcon_Acl_Resource, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_resource___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_acl_resource_method_entry){
	PHP_ME(Phalcon_Acl_Resource, __construct, arginfo_phalcon_acl_resource___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Acl_Resource, getName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Resource, getDescription, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Resource, __toString, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_acl_adapter_memory_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_Adapter_Memory);

PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isResource);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResource);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResourceAccess);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropResourceAccess);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _allowOrDeny);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _rebuildAccessList);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_addrole, 0, 0, 1)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, accessInherits)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_addinherit, 0, 0, 2)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, roleToInherit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_isrole, 0, 0, 1)
	ZEND_ARG_INFO(0, roleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_isresource, 0, 0, 1)
	ZEND_ARG_INFO(0, resourceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_addresource, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_addresourceaccess, 0, 0, 2)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_dropresourceaccess, 0, 0, 2)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_allow, 0, 0, 3)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_deny, 0, 0, 3)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_isallowed, 0, 0, 3)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, resource)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_acl_adapter_memory_method_entry){
	PHP_ME(Phalcon_Acl_Adapter_Memory, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, addRole, arginfo_phalcon_acl_adapter_memory_addrole, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, addInherit, arginfo_phalcon_acl_adapter_memory_addinherit, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, isRole, arginfo_phalcon_acl_adapter_memory_isrole, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, isResource, arginfo_phalcon_acl_adapter_memory_isresource, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, addResource, arginfo_phalcon_acl_adapter_memory_addresource, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, addResourceAccess, arginfo_phalcon_acl_adapter_memory_addresourceaccess, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, dropResourceAccess, arginfo_phalcon_acl_adapter_memory_dropresourceaccess, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, _allowOrDeny, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, allow, arginfo_phalcon_acl_adapter_memory_allow, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, deny, arginfo_phalcon_acl_adapter_memory_deny, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, isAllowed, arginfo_phalcon_acl_adapter_memory_isallowed, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, _rebuildAccessList, NULL, ZEND_ACC_PROTECTED) 
	PHP_FE_END
};



zend_class_entry *phalcon_acl_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_Exception);


zend_class_entry *phalcon_kernel_ce;

PHALCON_INIT_CLASS(Phalcon_Kernel);

PHP_METHOD(Phalcon_Kernel, preComputeHashKey);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_kernel_precomputehashkey, 0, 0, 1)
	ZEND_ARG_INFO(0, arrKey)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_kernel_method_entry){
	PHP_ME(Phalcon_Kernel, preComputeHashKey, arginfo_phalcon_kernel_precomputehashkey, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_text_ce;

PHALCON_INIT_CLASS(Phalcon_Text);

PHP_METHOD(Phalcon_Text, camelize);
PHP_METHOD(Phalcon_Text, uncamelize);
PHP_METHOD(Phalcon_Text, increment);
PHP_METHOD(Phalcon_Text, random);
PHP_METHOD(Phalcon_Text, startsWith);
PHP_METHOD(Phalcon_Text, endsWith);
PHP_METHOD(Phalcon_Text, lower);
PHP_METHOD(Phalcon_Text, upper);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_camelize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_uncamelize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_increment, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, separator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_random, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_startswith, 0, 0, 2)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, start)
	ZEND_ARG_INFO(0, ignoreCase)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_endswith, 0, 0, 2)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, start)
	ZEND_ARG_INFO(0, ignoreCase)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_lower, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_upper, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_text_method_entry){
	PHP_ME(Phalcon_Text, camelize, arginfo_phalcon_text_camelize, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Text, uncamelize, arginfo_phalcon_text_uncamelize, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Text, increment, arginfo_phalcon_text_increment, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Text, random, arginfo_phalcon_text_random, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Text, startsWith, arginfo_phalcon_text_startswith, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Text, endsWith, arginfo_phalcon_text_endswith, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Text, lower, arginfo_phalcon_text_lower, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Text, upper, arginfo_phalcon_text_upper, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_security_ce;

PHALCON_INIT_CLASS(Phalcon_Security);

PHP_METHOD(Phalcon_Security, setDI);
PHP_METHOD(Phalcon_Security, getDI);
PHP_METHOD(Phalcon_Security, setRandomBytes);
PHP_METHOD(Phalcon_Security, getRandomBytes);
PHP_METHOD(Phalcon_Security, setWorkFactor);
PHP_METHOD(Phalcon_Security, getWorkFactor);
PHP_METHOD(Phalcon_Security, getSaltBytes);
PHP_METHOD(Phalcon_Security, hash);
PHP_METHOD(Phalcon_Security, checkHash);
PHP_METHOD(Phalcon_Security, isLegacyHash);
PHP_METHOD(Phalcon_Security, getTokenKey);
PHP_METHOD(Phalcon_Security, getToken);
PHP_METHOD(Phalcon_Security, checkToken);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setrandombytes, 0, 0, 1)
	ZEND_ARG_INFO(0, randomBytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setworkfactor, 0, 0, 1)
	ZEND_ARG_INFO(0, workFactor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_hash, 0, 0, 1)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, workFactor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_checkhash, 0, 0, 2)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, passwordHash)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_islegacyhash, 0, 0, 1)
	ZEND_ARG_INFO(0, passwordHash)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_gettokenkey, 0, 0, 0)
	ZEND_ARG_INFO(0, numberBytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_gettoken, 0, 0, 0)
	ZEND_ARG_INFO(0, numberBytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_checktoken, 0, 0, 0)
	ZEND_ARG_INFO(0, tokenKey)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_security_method_entry){
	PHP_ME(Phalcon_Security, setDI, arginfo_phalcon_security_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Security, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Security, setRandomBytes, arginfo_phalcon_security_setrandombytes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Security, getRandomBytes, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Security, setWorkFactor, arginfo_phalcon_security_setworkfactor, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Security, getWorkFactor, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Security, getSaltBytes, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Security, hash, arginfo_phalcon_security_hash, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Security, checkHash, arginfo_phalcon_security_checkhash, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Security, isLegacyHash, arginfo_phalcon_security_islegacyhash, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Security, getTokenKey, arginfo_phalcon_security_gettokenkey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Security, getToken, arginfo_phalcon_security_gettoken, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Security, checkToken, arginfo_phalcon_security_checktoken, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_security_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Security_Exception);


zend_class_entry *phalcon_version_ce;

PHALCON_INIT_CLASS(Phalcon_Version);

PHP_METHOD(Phalcon_Version, _getVersion);
PHP_METHOD(Phalcon_Version, get);
PHP_METHOD(Phalcon_Version, getId);

PHALCON_INIT_FUNCS(phalcon_version_method_entry){
	PHP_ME(Phalcon_Version, _getVersion, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Version, get, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Version, getId, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_session_ce;

PHALCON_INIT_CLASS(Phalcon_Session);


zend_class_entry *phalcon_session_bag_ce;

PHALCON_INIT_CLASS(Phalcon_Session_Bag);

PHP_METHOD(Phalcon_Session_Bag, __construct);
PHP_METHOD(Phalcon_Session_Bag, setDI);
PHP_METHOD(Phalcon_Session_Bag, getDI);
PHP_METHOD(Phalcon_Session_Bag, initialize);
PHP_METHOD(Phalcon_Session_Bag, destroy);
PHP_METHOD(Phalcon_Session_Bag, set);
PHP_METHOD(Phalcon_Session_Bag, __set);
PHP_METHOD(Phalcon_Session_Bag, get);
PHP_METHOD(Phalcon_Session_Bag, __get);
PHP_METHOD(Phalcon_Session_Bag, has);
PHP_METHOD(Phalcon_Session_Bag, __isset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_has, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_session_bag_method_entry){
	PHP_ME(Phalcon_Session_Bag, __construct, arginfo_phalcon_session_bag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Session_Bag, setDI, arginfo_phalcon_session_bag_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Bag, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Bag, initialize, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Bag, destroy, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Bag, set, arginfo_phalcon_session_bag_set, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Bag, __set, arginfo_phalcon_session_bag___set, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Bag, get, arginfo_phalcon_session_bag_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Bag, __get, arginfo_phalcon_session_bag___get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Bag, has, arginfo_phalcon_session_bag_has, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Session_Bag, __isset, arginfo_phalcon_session_bag___isset, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_session_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Session_Exception);


zend_class_entry *phalcon_session_adapter_files_ce;

PHALCON_INIT_CLASS(Phalcon_Session_Adapter_Files);


zend_class_entry *phalcon_filter_ce;

PHALCON_INIT_CLASS(Phalcon_Filter);

PHP_METHOD(Phalcon_Filter, __construct);
PHP_METHOD(Phalcon_Filter, add);
PHP_METHOD(Phalcon_Filter, sanitize);
PHP_METHOD(Phalcon_Filter, _sanitize);
PHP_METHOD(Phalcon_Filter, getFilters);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_add, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_sanitize, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_filter_method_entry){
	PHP_ME(Phalcon_Filter, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Filter, add, arginfo_phalcon_filter_add, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Filter, sanitize, arginfo_phalcon_filter_sanitize, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Filter, _sanitize, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Filter, getFilters, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_di_exception_ce;

PHALCON_INIT_CLASS(Phalcon_DI_Exception);


zend_class_entry *phalcon_di_factorydefault_cli_ce;

PHALCON_INIT_CLASS(Phalcon_DI_FactoryDefault_CLI);

PHP_METHOD(Phalcon_DI_FactoryDefault_CLI, __construct);

PHALCON_INIT_FUNCS(phalcon_di_factorydefault_cli_method_entry){
	PHP_ME(Phalcon_DI_FactoryDefault_CLI, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_FE_END
};



zend_class_entry *phalcon_di_service_ce;

PHALCON_INIT_CLASS(Phalcon_DI_Service);

PHP_METHOD(Phalcon_DI_Service, __construct);
PHP_METHOD(Phalcon_DI_Service, getName);
PHP_METHOD(Phalcon_DI_Service, setShared);
PHP_METHOD(Phalcon_DI_Service, isShared);
PHP_METHOD(Phalcon_DI_Service, setSharedInstance);
PHP_METHOD(Phalcon_DI_Service, setDefinition);
PHP_METHOD(Phalcon_DI_Service, getDefinition);
PHP_METHOD(Phalcon_DI_Service, resolve);
PHP_METHOD(Phalcon_DI_Service, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_setshared, 0, 0, 1)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_setsharedinstance, 0, 0, 1)
	ZEND_ARG_INFO(0, sharedInstance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_setdefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_resolve, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_di_service_method_entry){
	PHP_ME(Phalcon_DI_Service, __construct, arginfo_phalcon_di_service___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_DI_Service, getName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI_Service, setShared, arginfo_phalcon_di_service_setshared, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI_Service, isShared, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI_Service, setSharedInstance, arginfo_phalcon_di_service_setsharedinstance, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI_Service, setDefinition, arginfo_phalcon_di_service_setdefinition, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI_Service, getDefinition, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI_Service, resolve, arginfo_phalcon_di_service_resolve, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_DI_Service, __set_state, arginfo_phalcon_di_service___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_filter_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Filter_Exception);


zend_class_entry *phalcon_flash_direct_ce;

PHALCON_INIT_CLASS(Phalcon_Flash_Direct);

PHP_METHOD(Phalcon_Flash_Direct, message);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_direct_message, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_flash_direct_method_entry){
	PHP_ME(Phalcon_Flash_Direct, message, arginfo_phalcon_flash_direct_message, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_flash_session_ce;

PHALCON_INIT_CLASS(Phalcon_Flash_Session);

PHP_METHOD(Phalcon_Flash_Session, setDI);
PHP_METHOD(Phalcon_Flash_Session, getDI);
PHP_METHOD(Phalcon_Flash_Session, _getSessionMessages);
PHP_METHOD(Phalcon_Flash_Session, _setSessionMessages);
PHP_METHOD(Phalcon_Flash_Session, message);
PHP_METHOD(Phalcon_Flash_Session, getMessages);
PHP_METHOD(Phalcon_Flash_Session, output);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session_message, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session_getmessages, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, remove)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session_output, 0, 0, 0)
	ZEND_ARG_INFO(0, remove)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_flash_session_method_entry){
	PHP_ME(Phalcon_Flash_Session, setDI, arginfo_phalcon_flash_session_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Flash_Session, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Flash_Session, _getSessionMessages, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Flash_Session, _setSessionMessages, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Flash_Session, message, arginfo_phalcon_flash_session_message, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Flash_Session, getMessages, arginfo_phalcon_flash_session_getmessages, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Flash_Session, output, arginfo_phalcon_flash_session_output, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_flash_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Flash_Exception);


zend_class_entry *phalcon_cli_task_ce;

PHALCON_INIT_CLASS(Phalcon_CLI_Task);

PHP_METHOD(Phalcon_CLI_Task, __construct);

PHALCON_INIT_FUNCS(phalcon_cli_task_method_entry){
	PHP_ME(Phalcon_CLI_Task, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR) 
	PHP_FE_END
};



zend_class_entry *phalcon_cli_router_ce;

PHALCON_INIT_CLASS(Phalcon_CLI_Router);

PHP_METHOD(Phalcon_CLI_Router, __construct);
PHP_METHOD(Phalcon_CLI_Router, setDI);
PHP_METHOD(Phalcon_CLI_Router, getDI);
PHP_METHOD(Phalcon_CLI_Router, setDefaultModule);
PHP_METHOD(Phalcon_CLI_Router, setDefaultTask);
PHP_METHOD(Phalcon_CLI_Router, setDefaultAction);
PHP_METHOD(Phalcon_CLI_Router, handle);
PHP_METHOD(Phalcon_CLI_Router, getModuleName);
PHP_METHOD(Phalcon_CLI_Router, getTaskName);
PHP_METHOD(Phalcon_CLI_Router, getActionName);
PHP_METHOD(Phalcon_CLI_Router, getParams);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdefaulttask, 0, 0, 1)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cli_router_method_entry){
	PHP_ME(Phalcon_CLI_Router, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_CLI_Router, setDI, arginfo_phalcon_cli_router_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, setDefaultModule, arginfo_phalcon_cli_router_setdefaultmodule, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, setDefaultTask, arginfo_phalcon_cli_router_setdefaulttask, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, setDefaultAction, arginfo_phalcon_cli_router_setdefaultaction, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, handle, arginfo_phalcon_cli_router_handle, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, getModuleName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, getTaskName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, getActionName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Router, getParams, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_cli_console_ce;

PHALCON_INIT_CLASS(Phalcon_CLI_Console);

PHP_METHOD(Phalcon_CLI_Console, setDI);
PHP_METHOD(Phalcon_CLI_Console, getDI);
PHP_METHOD(Phalcon_CLI_Console, setEventsManager);
PHP_METHOD(Phalcon_CLI_Console, getEventsManager);
PHP_METHOD(Phalcon_CLI_Console, registerModules);
PHP_METHOD(Phalcon_CLI_Console, addModules);
PHP_METHOD(Phalcon_CLI_Console, getModules);
PHP_METHOD(Phalcon_CLI_Console, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_registermodules, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_addmodules, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cli_console_method_entry){
	PHP_ME(Phalcon_CLI_Console, setDI, arginfo_phalcon_cli_console_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Console, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Console, setEventsManager, arginfo_phalcon_cli_console_seteventsmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Console, getEventsManager, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Console, registerModules, arginfo_phalcon_cli_console_registermodules, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Console, addModules, arginfo_phalcon_cli_console_addmodules, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Console, getModules, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Console, handle, arginfo_phalcon_cli_console_handle, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_cli_console_exception_ce;

PHALCON_INIT_CLASS(Phalcon_CLI_Console_Exception);


zend_class_entry *phalcon_cli_dispatcher_ce;

PHALCON_INIT_CLASS(Phalcon_CLI_Dispatcher);

PHP_METHOD(Phalcon_CLI_Dispatcher, setTaskSuffix);
PHP_METHOD(Phalcon_CLI_Dispatcher, setDefaultTask);
PHP_METHOD(Phalcon_CLI_Dispatcher, setTaskName);
PHP_METHOD(Phalcon_CLI_Dispatcher, getTaskName);
PHP_METHOD(Phalcon_CLI_Dispatcher, _throwDispatchException);
PHP_METHOD(Phalcon_CLI_Dispatcher, getLastTask);
PHP_METHOD(Phalcon_CLI_Dispatcher, getActiveTask);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_settasksuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, taskSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_setdefaulttask, 0, 0, 1)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_settaskname, 0, 0, 1)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_cli_dispatcher_method_entry){
	PHP_ME(Phalcon_CLI_Dispatcher, setTaskSuffix, arginfo_phalcon_cli_dispatcher_settasksuffix, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Dispatcher, setDefaultTask, arginfo_phalcon_cli_dispatcher_setdefaulttask, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Dispatcher, setTaskName, arginfo_phalcon_cli_dispatcher_settaskname, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Dispatcher, getTaskName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Dispatcher, _throwDispatchException, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_CLI_Dispatcher, getLastTask, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_CLI_Dispatcher, getActiveTask, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_cli_dispatcher_exception_ce;

PHALCON_INIT_CLASS(Phalcon_CLI_Dispatcher_Exception);


zend_class_entry *phalcon_cli_router_exception_ce;

PHALCON_INIT_CLASS(Phalcon_CLI_Router_Exception);


zend_class_entry *phalcon_loader_ce;

PHALCON_INIT_CLASS(Phalcon_Loader);

PHP_METHOD(Phalcon_Loader, __construct);
PHP_METHOD(Phalcon_Loader, setEventsManager);
PHP_METHOD(Phalcon_Loader, getEventsManager);
PHP_METHOD(Phalcon_Loader, setExtensions);
PHP_METHOD(Phalcon_Loader, getExtensions);
PHP_METHOD(Phalcon_Loader, registerNamespaces);
PHP_METHOD(Phalcon_Loader, getNamespaces);
PHP_METHOD(Phalcon_Loader, registerPrefixes);
PHP_METHOD(Phalcon_Loader, getPrefixes);
PHP_METHOD(Phalcon_Loader, registerDirs);
PHP_METHOD(Phalcon_Loader, getDirs);
PHP_METHOD(Phalcon_Loader, registerClasses);
PHP_METHOD(Phalcon_Loader, getClasses);
PHP_METHOD(Phalcon_Loader, register);
PHP_METHOD(Phalcon_Loader, unregister);
PHP_METHOD(Phalcon_Loader, autoLoad);
PHP_METHOD(Phalcon_Loader, getFoundPath);
PHP_METHOD(Phalcon_Loader, getCheckedPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_setextensions, 0, 0, 1)
	ZEND_ARG_INFO(0, extensions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_registernamespaces, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaces)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_registerprefixes, 0, 0, 1)
	ZEND_ARG_INFO(0, prefixes)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_registerdirs, 0, 0, 1)
	ZEND_ARG_INFO(0, directories)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_registerclasses, 0, 0, 1)
	ZEND_ARG_INFO(0, classes)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_autoload, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_loader_method_entry){
	PHP_ME(Phalcon_Loader, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Loader, setEventsManager, arginfo_phalcon_loader_seteventsmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, getEventsManager, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, setExtensions, arginfo_phalcon_loader_setextensions, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, getExtensions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, registerNamespaces, arginfo_phalcon_loader_registernamespaces, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, getNamespaces, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, registerPrefixes, arginfo_phalcon_loader_registerprefixes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, getPrefixes, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, registerDirs, arginfo_phalcon_loader_registerdirs, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, getDirs, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, registerClasses, arginfo_phalcon_loader_registerclasses, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, getClasses, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, register, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, unregister, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, autoLoad, arginfo_phalcon_loader_autoload, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, getFoundPath, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Loader, getCheckedPath, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_logger_ce;

PHALCON_INIT_CLASS(Phalcon_Logger);


zend_class_entry *phalcon_loader_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Loader_Exception);


zend_class_entry *phalcon_logger_item_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Item);

PHP_METHOD(Phalcon_Logger_Item, __construct);
PHP_METHOD(Phalcon_Logger_Item, getMessage);
PHP_METHOD(Phalcon_Logger_Item, getType);
PHP_METHOD(Phalcon_Logger_Item, getTime);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_item___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, time)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_logger_item_method_entry){
	PHP_ME(Phalcon_Logger_Item, __construct, arginfo_phalcon_logger_item___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Logger_Item, getMessage, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Item, getType, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Item, getTime, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_logger_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Exception);


zend_class_entry *phalcon_logger_adapter_file_ce;

PHALCON_INIT_CLASS(Phalcon_Logger_Adapter_File);

PHP_METHOD(Phalcon_Logger_Adapter_File, __construct);
PHP_METHOD(Phalcon_Logger_Adapter_File, log);
PHP_METHOD(Phalcon_Logger_Adapter_File, begin);
PHP_METHOD(Phalcon_Logger_Adapter_File, commit);
PHP_METHOD(Phalcon_Logger_Adapter_File, rollback);
PHP_METHOD(Phalcon_Logger_Adapter_File, close);
PHP_METHOD(Phalcon_Logger_Adapter_File, __wakeup);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_file_log, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_logger_adapter_file_method_entry){
	PHP_ME(Phalcon_Logger_Adapter_File, __construct, arginfo_phalcon_logger_adapter_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Logger_Adapter_File, log, arginfo_phalcon_logger_adapter_file_log, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter_File, begin, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter_File, commit, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter_File, rollback, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter_File, close, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Logger_Adapter_File, __wakeup, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_config_adapter_ini_ce;

PHALCON_INIT_CLASS(Phalcon_Config_Adapter_Ini);

PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_ini___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_config_adapter_ini_method_entry){
	PHP_ME(Phalcon_Config_Adapter_Ini, __construct, arginfo_phalcon_config_adapter_ini___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_FE_END
};



zend_class_entry *phalcon_config_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Config_Exception);


zend_class_entry *phalcon_translate_ce;

PHALCON_INIT_CLASS(Phalcon_Translate);


zend_class_entry *phalcon_translate_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Translate_Exception);


zend_class_entry *phalcon_translate_adapter_nativearray_ce;

PHALCON_INIT_CLASS(Phalcon_Translate_Adapter_NativeArray);

PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, __construct);
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, query);
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_nativearray___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_nativearray_query, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_nativearray_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_translate_adapter_nativearray_method_entry){
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, __construct, arginfo_phalcon_translate_adapter_nativearray___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, query, arginfo_phalcon_translate_adapter_nativearray_query, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, exists, arginfo_phalcon_translate_adapter_nativearray_exists, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_escaper_ce;

PHALCON_INIT_CLASS(Phalcon_Escaper);

PHP_METHOD(Phalcon_Escaper, setEnconding);
PHP_METHOD(Phalcon_Escaper, getEncoding);
PHP_METHOD(Phalcon_Escaper, setHtmlQuoteType);
PHP_METHOD(Phalcon_Escaper, escapeHtml);
PHP_METHOD(Phalcon_Escaper, escapeHtmlAttr);
PHP_METHOD(Phalcon_Escaper, cssSanitize);
PHP_METHOD(Phalcon_Escaper, escapeCss);
PHP_METHOD(Phalcon_Escaper, escapeUrl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_setenconding, 0, 0, 1)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_sethtmlquotetype, 0, 0, 1)
	ZEND_ARG_INFO(0, quoteType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_escapehtml, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_escapehtmlattr, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_csssanitize, 0, 0, 1)
	ZEND_ARG_INFO(0, matches)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_escapecss, 0, 0, 1)
	ZEND_ARG_INFO(0, css)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_escapeurl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_escaper_method_entry){
	PHP_ME(Phalcon_Escaper, setEnconding, arginfo_phalcon_escaper_setenconding, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Escaper, getEncoding, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Escaper, setHtmlQuoteType, arginfo_phalcon_escaper_sethtmlquotetype, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Escaper, escapeHtml, arginfo_phalcon_escaper_escapehtml, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Escaper, escapeHtmlAttr, arginfo_phalcon_escaper_escapehtmlattr, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Escaper, cssSanitize, arginfo_phalcon_escaper_csssanitize, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Escaper, escapeCss, arginfo_phalcon_escaper_escapecss, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Escaper, escapeUrl, arginfo_phalcon_escaper_escapeurl, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_escaper_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Escaper_Exception);


zend_class_entry *phalcon_http_cookie_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Cookie);

PHP_METHOD(Phalcon_Http_Cookie, __construct);
PHP_METHOD(Phalcon_Http_Cookie, setDI);
PHP_METHOD(Phalcon_Http_Cookie, getDI);
PHP_METHOD(Phalcon_Http_Cookie, setValue);
PHP_METHOD(Phalcon_Http_Cookie, getValue);
PHP_METHOD(Phalcon_Http_Cookie, setExpiration);
PHP_METHOD(Phalcon_Http_Cookie, getExpiration);
PHP_METHOD(Phalcon_Http_Cookie, setPath);
PHP_METHOD(Phalcon_Http_Cookie, getPath);
PHP_METHOD(Phalcon_Http_Cookie, setSecure);
PHP_METHOD(Phalcon_Http_Cookie, getSecure);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_getvalue, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setexpiration, 0, 0, 1)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setsecure, 0, 0, 1)
	ZEND_ARG_INFO(0, secure)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_cookie_method_entry){
	PHP_ME(Phalcon_Http_Cookie, __construct, arginfo_phalcon_http_cookie___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Http_Cookie, setDI, arginfo_phalcon_http_cookie_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Cookie, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Cookie, setValue, arginfo_phalcon_http_cookie_setvalue, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Cookie, getValue, arginfo_phalcon_http_cookie_getvalue, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Cookie, setExpiration, arginfo_phalcon_http_cookie_setexpiration, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Cookie, getExpiration, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Cookie, setPath, arginfo_phalcon_http_cookie_setpath, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Cookie, getPath, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Cookie, setSecure, arginfo_phalcon_http_cookie_setsecure, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Cookie, getSecure, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_http_request_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Request);

PHP_METHOD(Phalcon_Http_Request, setDI);
PHP_METHOD(Phalcon_Http_Request, getDI);
PHP_METHOD(Phalcon_Http_Request, get);
PHP_METHOD(Phalcon_Http_Request, getPost);
PHP_METHOD(Phalcon_Http_Request, getQuery);
PHP_METHOD(Phalcon_Http_Request, getServer);
PHP_METHOD(Phalcon_Http_Request, has);
PHP_METHOD(Phalcon_Http_Request, hasPost);
PHP_METHOD(Phalcon_Http_Request, hasQuery);
PHP_METHOD(Phalcon_Http_Request, hasServer);
PHP_METHOD(Phalcon_Http_Request, getHeader);
PHP_METHOD(Phalcon_Http_Request, getScheme);
PHP_METHOD(Phalcon_Http_Request, isAjax);
PHP_METHOD(Phalcon_Http_Request, isSoapRequested);
PHP_METHOD(Phalcon_Http_Request, isSecureRequest);
PHP_METHOD(Phalcon_Http_Request, getRawBody);
PHP_METHOD(Phalcon_Http_Request, getServerAddress);
PHP_METHOD(Phalcon_Http_Request, getServerName);
PHP_METHOD(Phalcon_Http_Request, getHttpHost);
PHP_METHOD(Phalcon_Http_Request, getClientAddress);
PHP_METHOD(Phalcon_Http_Request, getMethod);
PHP_METHOD(Phalcon_Http_Request, getUserAgent);
PHP_METHOD(Phalcon_Http_Request, isMethod);
PHP_METHOD(Phalcon_Http_Request, isPost);
PHP_METHOD(Phalcon_Http_Request, isGet);
PHP_METHOD(Phalcon_Http_Request, isPut);
PHP_METHOD(Phalcon_Http_Request, isHead);
PHP_METHOD(Phalcon_Http_Request, isDelete);
PHP_METHOD(Phalcon_Http_Request, isOptions);
PHP_METHOD(Phalcon_Http_Request, hasFiles);
PHP_METHOD(Phalcon_Http_Request, getUploadedFiles);
PHP_METHOD(Phalcon_Http_Request, getHTTPReferer);
PHP_METHOD(Phalcon_Http_Request, _getQualityHeader);
PHP_METHOD(Phalcon_Http_Request, _getBestQuality);
PHP_METHOD(Phalcon_Http_Request, getAcceptableContent);
PHP_METHOD(Phalcon_Http_Request, getBestAccept);
PHP_METHOD(Phalcon_Http_Request, getClientCharsets);
PHP_METHOD(Phalcon_Http_Request, getBestCharset);
PHP_METHOD(Phalcon_Http_Request, getLanguages);
PHP_METHOD(Phalcon_Http_Request, getBestLanguage);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getpost, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getquery, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_haspost, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_hasquery, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_hasserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getclientaddress, 0, 0, 0)
	ZEND_ARG_INFO(0, trustForwardedHeader)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_ismethod, 0, 0, 1)
	ZEND_ARG_INFO(0, methods)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_request_method_entry){
	PHP_ME(Phalcon_Http_Request, setDI, arginfo_phalcon_http_request_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, get, arginfo_phalcon_http_request_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getPost, arginfo_phalcon_http_request_getpost, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getQuery, arginfo_phalcon_http_request_getquery, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getServer, arginfo_phalcon_http_request_getserver, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, has, arginfo_phalcon_http_request_has, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, hasPost, arginfo_phalcon_http_request_haspost, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, hasQuery, arginfo_phalcon_http_request_hasquery, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, hasServer, arginfo_phalcon_http_request_hasserver, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getHeader, arginfo_phalcon_http_request_getheader, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getScheme, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, isAjax, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, isSoapRequested, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, isSecureRequest, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getRawBody, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getServerAddress, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getServerName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getHttpHost, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getClientAddress, arginfo_phalcon_http_request_getclientaddress, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getMethod, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getUserAgent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, isMethod, arginfo_phalcon_http_request_ismethod, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, isPost, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, isGet, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, isPut, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, isHead, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, isDelete, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, isOptions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, hasFiles, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getUploadedFiles, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getHTTPReferer, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, _getQualityHeader, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Http_Request, _getBestQuality, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Http_Request, getAcceptableContent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getBestAccept, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getClientCharsets, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getBestCharset, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getLanguages, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request, getBestLanguage, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_http_response_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Response);

PHP_METHOD(Phalcon_Http_Response, setDI);
PHP_METHOD(Phalcon_Http_Response, getDI);
PHP_METHOD(Phalcon_Http_Response, setStatusCode);
PHP_METHOD(Phalcon_Http_Response, setHeaders);
PHP_METHOD(Phalcon_Http_Response, getHeaders);
PHP_METHOD(Phalcon_Http_Response, setCookies);
PHP_METHOD(Phalcon_Http_Response, getCookies);
PHP_METHOD(Phalcon_Http_Response, setHeader);
PHP_METHOD(Phalcon_Http_Response, setRawHeader);
PHP_METHOD(Phalcon_Http_Response, resetHeaders);
PHP_METHOD(Phalcon_Http_Response, setExpires);
PHP_METHOD(Phalcon_Http_Response, setNotModified);
PHP_METHOD(Phalcon_Http_Response, setContentType);
PHP_METHOD(Phalcon_Http_Response, redirect);
PHP_METHOD(Phalcon_Http_Response, setContent);
PHP_METHOD(Phalcon_Http_Response, appendContent);
PHP_METHOD(Phalcon_Http_Response, getContent);
PHP_METHOD(Phalcon_Http_Response, isSent);
PHP_METHOD(Phalcon_Http_Response, sendHeaders);
PHP_METHOD(Phalcon_Http_Response, send);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setstatuscode, 0, 0, 2)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setheaders, 0, 0, 1)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setcookies, 0, 0, 1)
	ZEND_ARG_INFO(0, cookies)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setrawheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setexpires, 0, 0, 1)
	ZEND_ARG_INFO(0, datetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setcontenttype, 0, 0, 1)
	ZEND_ARG_INFO(0, contentType)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_redirect, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, externalRedirect)
	ZEND_ARG_INFO(0, statusCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_appendcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_response_method_entry){
	PHP_ME(Phalcon_Http_Response, setDI, arginfo_phalcon_http_response_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, setStatusCode, arginfo_phalcon_http_response_setstatuscode, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, setHeaders, arginfo_phalcon_http_response_setheaders, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, getHeaders, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, setCookies, arginfo_phalcon_http_response_setcookies, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, getCookies, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, setHeader, arginfo_phalcon_http_response_setheader, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, setRawHeader, arginfo_phalcon_http_response_setrawheader, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, resetHeaders, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, setExpires, arginfo_phalcon_http_response_setexpires, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, setNotModified, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, setContentType, arginfo_phalcon_http_response_setcontenttype, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, redirect, arginfo_phalcon_http_response_redirect, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, setContent, arginfo_phalcon_http_response_setcontent, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, appendContent, arginfo_phalcon_http_response_appendcontent, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, getContent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, isSent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, sendHeaders, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response, send, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_http_cookie_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Cookie_Exception);


zend_class_entry *phalcon_http_request_file_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Request_File);

PHP_METHOD(Phalcon_Http_Request_File, __construct);
PHP_METHOD(Phalcon_Http_Request_File, getSize);
PHP_METHOD(Phalcon_Http_Request_File, getName);
PHP_METHOD(Phalcon_Http_Request_File, getTempName);
PHP_METHOD(Phalcon_Http_Request_File, moveTo);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_file_moveto, 0, 0, 1)
	ZEND_ARG_INFO(0, destination)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_request_file_method_entry){
	PHP_ME(Phalcon_Http_Request_File, __construct, arginfo_phalcon_http_request_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Http_Request_File, getSize, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request_File, getName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request_File, getTempName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Request_File, moveTo, arginfo_phalcon_http_request_file_moveto, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_http_response_cookies_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Response_Cookies);

PHP_METHOD(Phalcon_Http_Response_Cookies, __construct);
PHP_METHOD(Phalcon_Http_Response_Cookies, setDI);
PHP_METHOD(Phalcon_Http_Response_Cookies, getDI);
PHP_METHOD(Phalcon_Http_Response_Cookies, set);
PHP_METHOD(Phalcon_Http_Response_Cookies, get);
PHP_METHOD(Phalcon_Http_Response_Cookies, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookies_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookies_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookies_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_response_cookies_method_entry){
	PHP_ME(Phalcon_Http_Response_Cookies, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Http_Response_Cookies, setDI, arginfo_phalcon_http_response_cookies_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Cookies, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Cookies, set, arginfo_phalcon_http_response_cookies_set, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Cookies, get, arginfo_phalcon_http_response_cookies_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Cookies, reset, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_http_response_headers_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Response_Headers);

PHP_METHOD(Phalcon_Http_Response_Headers, __construct);
PHP_METHOD(Phalcon_Http_Response_Headers, set);
PHP_METHOD(Phalcon_Http_Response_Headers, get);
PHP_METHOD(Phalcon_Http_Response_Headers, setRaw);
PHP_METHOD(Phalcon_Http_Response_Headers, send);
PHP_METHOD(Phalcon_Http_Response_Headers, reset);
PHP_METHOD(Phalcon_Http_Response_Headers, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers_setraw, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_http_response_headers_method_entry){
	PHP_ME(Phalcon_Http_Response_Headers, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Http_Response_Headers, set, arginfo_phalcon_http_response_headers_set, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Headers, get, arginfo_phalcon_http_response_headers_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Headers, setRaw, arginfo_phalcon_http_response_headers_setraw, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Headers, send, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Headers, reset, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Http_Response_Headers, __set_state, arginfo_phalcon_http_response_headers___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_http_request_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Request_Exception);


zend_class_entry *phalcon_http_response_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Http_Response_Exception);


zend_class_entry *phalcon_mvc_micro_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Micro);

PHP_METHOD(Phalcon_Mvc_Micro, __construct);
PHP_METHOD(Phalcon_Mvc_Micro, setDI);
PHP_METHOD(Phalcon_Mvc_Micro, map);
PHP_METHOD(Phalcon_Mvc_Micro, get);
PHP_METHOD(Phalcon_Mvc_Micro, post);
PHP_METHOD(Phalcon_Mvc_Micro, put);
PHP_METHOD(Phalcon_Mvc_Micro, head);
PHP_METHOD(Phalcon_Mvc_Micro, delete);
PHP_METHOD(Phalcon_Mvc_Micro, options);
PHP_METHOD(Phalcon_Mvc_Micro, notFound);
PHP_METHOD(Phalcon_Mvc_Micro, getRouter);
PHP_METHOD(Phalcon_Mvc_Micro, getService);
PHP_METHOD(Phalcon_Mvc_Micro, getSharedService);
PHP_METHOD(Phalcon_Mvc_Micro, handle);
PHP_METHOD(Phalcon_Mvc_Micro, setActiveHandler);
PHP_METHOD(Phalcon_Mvc_Micro, getActiveHandler);
PHP_METHOD(Phalcon_Mvc_Micro, getReturnedValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_map, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_get, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_post, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_put, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_head, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_delete, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_options, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_notfound, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_getservice, 0, 0, 1)
	ZEND_ARG_INFO(0, serviceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_getsharedservice, 0, 0, 1)
	ZEND_ARG_INFO(0, serviceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_setactivehandler, 0, 0, 1)
	ZEND_ARG_INFO(0, activeHandler)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_micro_method_entry){
	PHP_ME(Phalcon_Mvc_Micro, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Micro, setDI, arginfo_phalcon_mvc_micro_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro, map, arginfo_phalcon_mvc_micro_map, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro, get, arginfo_phalcon_mvc_micro_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro, post, arginfo_phalcon_mvc_micro_post, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro, put, arginfo_phalcon_mvc_micro_put, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro, head, arginfo_phalcon_mvc_micro_head, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro, delete, arginfo_phalcon_mvc_micro_delete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro, options, arginfo_phalcon_mvc_micro_options, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro, notFound, arginfo_phalcon_mvc_micro_notfound, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro, getRouter, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro, getService, arginfo_phalcon_mvc_micro_getservice, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro, getSharedService, arginfo_phalcon_mvc_micro_getsharedservice, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro, handle, arginfo_phalcon_mvc_micro_handle, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro, setActiveHandler, arginfo_phalcon_mvc_micro_setactivehandler, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro, getActiveHandler, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Micro, getReturnedValue, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_view_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View);

PHP_METHOD(Phalcon_Mvc_View, __construct);
PHP_METHOD(Phalcon_Mvc_View, setViewsDir);
PHP_METHOD(Phalcon_Mvc_View, getViewsDir);
PHP_METHOD(Phalcon_Mvc_View, setLayoutsDir);
PHP_METHOD(Phalcon_Mvc_View, getLayoutsDir);
PHP_METHOD(Phalcon_Mvc_View, setBasePath);
PHP_METHOD(Phalcon_Mvc_View, setRenderLevel);
PHP_METHOD(Phalcon_Mvc_View, setMainView);
PHP_METHOD(Phalcon_Mvc_View, setTemplateBefore);
PHP_METHOD(Phalcon_Mvc_View, cleanTemplateBefore);
PHP_METHOD(Phalcon_Mvc_View, setTemplateAfter);
PHP_METHOD(Phalcon_Mvc_View, cleanTemplateAfter);
PHP_METHOD(Phalcon_Mvc_View, setParamToView);
PHP_METHOD(Phalcon_Mvc_View, setVar);
PHP_METHOD(Phalcon_Mvc_View, getVar);
PHP_METHOD(Phalcon_Mvc_View, getParamsToView);
PHP_METHOD(Phalcon_Mvc_View, getControllerName);
PHP_METHOD(Phalcon_Mvc_View, getActionName);
PHP_METHOD(Phalcon_Mvc_View, getParams);
PHP_METHOD(Phalcon_Mvc_View, start);
PHP_METHOD(Phalcon_Mvc_View, _loadTemplateEngines);
PHP_METHOD(Phalcon_Mvc_View, _engineRender);
PHP_METHOD(Phalcon_Mvc_View, registerEngines);
PHP_METHOD(Phalcon_Mvc_View, render);
PHP_METHOD(Phalcon_Mvc_View, pick);
PHP_METHOD(Phalcon_Mvc_View, partial);
PHP_METHOD(Phalcon_Mvc_View, finish);
PHP_METHOD(Phalcon_Mvc_View, _createCache);
PHP_METHOD(Phalcon_Mvc_View, getCache);
PHP_METHOD(Phalcon_Mvc_View, cache);
PHP_METHOD(Phalcon_Mvc_View, setContent);
PHP_METHOD(Phalcon_Mvc_View, getContent);
PHP_METHOD(Phalcon_Mvc_View, getActiveRenderPath);
PHP_METHOD(Phalcon_Mvc_View, disable);
PHP_METHOD(Phalcon_Mvc_View, enable);
PHP_METHOD(Phalcon_Mvc_View, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setviewsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, viewsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setlayoutsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, layoutsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setrenderlevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setmainview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_settemplatebefore, 0, 0, 1)
	ZEND_ARG_INFO(0, templateBefore)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_settemplateafter, 0, 0, 1)
	ZEND_ARG_INFO(0, templateAfter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setparamtoview, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setvar, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_getvar, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_registerengines, 0, 0, 1)
	ZEND_ARG_INFO(0, engines)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_render, 0, 0, 2)
	ZEND_ARG_INFO(0, controllerName)
	ZEND_ARG_INFO(0, actionName)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_pick, 0, 0, 1)
	ZEND_ARG_INFO(0, renderView)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, partialPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_cache, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_view_method_entry){
	PHP_ME(Phalcon_Mvc_View, __construct, arginfo_phalcon_mvc_view___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_View, setViewsDir, arginfo_phalcon_mvc_view_setviewsdir, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, getViewsDir, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, setLayoutsDir, arginfo_phalcon_mvc_view_setlayoutsdir, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, getLayoutsDir, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, setBasePath, arginfo_phalcon_mvc_view_setbasepath, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, setRenderLevel, arginfo_phalcon_mvc_view_setrenderlevel, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, setMainView, arginfo_phalcon_mvc_view_setmainview, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, setTemplateBefore, arginfo_phalcon_mvc_view_settemplatebefore, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, cleanTemplateBefore, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, setTemplateAfter, arginfo_phalcon_mvc_view_settemplateafter, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, cleanTemplateAfter, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, setParamToView, arginfo_phalcon_mvc_view_setparamtoview, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, setVar, arginfo_phalcon_mvc_view_setvar, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, getVar, arginfo_phalcon_mvc_view_getvar, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, getParamsToView, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, getControllerName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, getActionName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, getParams, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, start, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, _loadTemplateEngines, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_View, _engineRender, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_View, registerEngines, arginfo_phalcon_mvc_view_registerengines, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, render, arginfo_phalcon_mvc_view_render, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, pick, arginfo_phalcon_mvc_view_pick, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, partial, arginfo_phalcon_mvc_view_partial, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, finish, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, _createCache, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_View, getCache, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, cache, arginfo_phalcon_mvc_view_cache, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, setContent, arginfo_phalcon_mvc_view_setcontent, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, getContent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, getActiveRenderPath, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, disable, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, enable, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, reset, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_url_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Url);

PHP_METHOD(Phalcon_Mvc_Url, setDI);
PHP_METHOD(Phalcon_Mvc_Url, getDI);
PHP_METHOD(Phalcon_Mvc_Url, setBaseUri);
PHP_METHOD(Phalcon_Mvc_Url, getBaseUri);
PHP_METHOD(Phalcon_Mvc_Url, setBasePath);
PHP_METHOD(Phalcon_Mvc_Url, getBasePath);
PHP_METHOD(Phalcon_Mvc_Url, get);
PHP_METHOD(Phalcon_Mvc_Url, path);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_setbaseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, baseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_get, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_path, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_url_method_entry){
	PHP_ME(Phalcon_Mvc_Url, setDI, arginfo_phalcon_mvc_url_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Url, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Url, setBaseUri, arginfo_phalcon_mvc_url_setbaseuri, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Url, getBaseUri, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Url, setBasePath, arginfo_phalcon_mvc_url_setbasepath, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Url, getBasePath, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Url, get, arginfo_phalcon_mvc_url_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Url, path, arginfo_phalcon_mvc_url_path, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model);

PHP_METHOD(Phalcon_Mvc_Model, __construct);
PHP_METHOD(Phalcon_Mvc_Model, setDI);
PHP_METHOD(Phalcon_Mvc_Model, getDI);
PHP_METHOD(Phalcon_Mvc_Model, setEventsManager);
PHP_METHOD(Phalcon_Mvc_Model, getEventsManager);
PHP_METHOD(Phalcon_Mvc_Model, setTransaction);
PHP_METHOD(Phalcon_Mvc_Model, setSource);
PHP_METHOD(Phalcon_Mvc_Model, getSource);
PHP_METHOD(Phalcon_Mvc_Model, setSchema);
PHP_METHOD(Phalcon_Mvc_Model, getSchema);
PHP_METHOD(Phalcon_Mvc_Model, setConnectionService);
PHP_METHOD(Phalcon_Mvc_Model, getConnectionService);
PHP_METHOD(Phalcon_Mvc_Model, setForceExists);
PHP_METHOD(Phalcon_Mvc_Model, getConnection);
PHP_METHOD(Phalcon_Mvc_Model, dumpResultMap);
PHP_METHOD(Phalcon_Mvc_Model, dumpResult);
PHP_METHOD(Phalcon_Mvc_Model, find);
PHP_METHOD(Phalcon_Mvc_Model, findFirst);
PHP_METHOD(Phalcon_Mvc_Model, query);
PHP_METHOD(Phalcon_Mvc_Model, _exists);
PHP_METHOD(Phalcon_Mvc_Model, _groupResult);
PHP_METHOD(Phalcon_Mvc_Model, count);
PHP_METHOD(Phalcon_Mvc_Model, sum);
PHP_METHOD(Phalcon_Mvc_Model, maximum);
PHP_METHOD(Phalcon_Mvc_Model, minimum);
PHP_METHOD(Phalcon_Mvc_Model, average);
PHP_METHOD(Phalcon_Mvc_Model, _callEvent);
PHP_METHOD(Phalcon_Mvc_Model, _callEventCancel);
PHP_METHOD(Phalcon_Mvc_Model, _cancelOperation);
PHP_METHOD(Phalcon_Mvc_Model, appendMessage);
PHP_METHOD(Phalcon_Mvc_Model, validate);
PHP_METHOD(Phalcon_Mvc_Model, validationHasFailed);
PHP_METHOD(Phalcon_Mvc_Model, getMessages);
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeys);
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverse);
PHP_METHOD(Phalcon_Mvc_Model, _preSave);
PHP_METHOD(Phalcon_Mvc_Model, _postSave);
PHP_METHOD(Phalcon_Mvc_Model, _doLowInsert);
PHP_METHOD(Phalcon_Mvc_Model, _doLowUpdate);
PHP_METHOD(Phalcon_Mvc_Model, save);
PHP_METHOD(Phalcon_Mvc_Model, create);
PHP_METHOD(Phalcon_Mvc_Model, update);
PHP_METHOD(Phalcon_Mvc_Model, delete);
PHP_METHOD(Phalcon_Mvc_Model, getOperationMade);
PHP_METHOD(Phalcon_Mvc_Model, readAttribute);
PHP_METHOD(Phalcon_Mvc_Model, writeAttribute);
PHP_METHOD(Phalcon_Mvc_Model, skipAttributes);
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnCreate);
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnUpdate);
PHP_METHOD(Phalcon_Mvc_Model, hasOne);
PHP_METHOD(Phalcon_Mvc_Model, belongsTo);
PHP_METHOD(Phalcon_Mvc_Model, hasMany);
PHP_METHOD(Phalcon_Mvc_Model, getRelated);
PHP_METHOD(Phalcon_Mvc_Model, _getRelatedRecords);
PHP_METHOD(Phalcon_Mvc_Model, __call);
PHP_METHOD(Phalcon_Mvc_Model, serialize);
PHP_METHOD(Phalcon_Mvc_Model, unserialize);
PHP_METHOD(Phalcon_Mvc_Model, dump);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, managerService)
	ZEND_ARG_INFO(0, dbService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_settransaction, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setforceexists, 0, 0, 1)
	ZEND_ARG_INFO(0, forceExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_dumpresultmap, 0, 0, 3)
	ZEND_ARG_INFO(0, base)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_INFO(0, forceExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_dumpresult, 0, 0, 2)
	ZEND_ARG_INFO(0, base)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, forceExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_find, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_findfirst, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_count, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_sum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_maximum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_minimum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_average, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_appendmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_save, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_create, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_update, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_writeattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_getrelated, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_method_entry){
	PHP_ME(Phalcon_Mvc_Model, __construct, arginfo_phalcon_mvc_model___construct, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model, setDI, arginfo_phalcon_mvc_model_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, setEventsManager, arginfo_phalcon_mvc_model_seteventsmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, getEventsManager, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, setTransaction, arginfo_phalcon_mvc_model_settransaction, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, setSource, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, getSource, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, setSchema, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, getSchema, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, setConnectionService, arginfo_phalcon_mvc_model_setconnectionservice, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, getConnectionService, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, setForceExists, arginfo_phalcon_mvc_model_setforceexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, getConnection, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, dumpResultMap, arginfo_phalcon_mvc_model_dumpresultmap, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, dumpResult, arginfo_phalcon_mvc_model_dumpresult, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, find, arginfo_phalcon_mvc_model_find, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, findFirst, arginfo_phalcon_mvc_model_findfirst, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, query, arginfo_phalcon_mvc_model_query, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, _exists, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, _groupResult, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, count, arginfo_phalcon_mvc_model_count, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, sum, arginfo_phalcon_mvc_model_sum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, maximum, arginfo_phalcon_mvc_model_maximum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, minimum, arginfo_phalcon_mvc_model_minimum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, average, arginfo_phalcon_mvc_model_average, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model, _callEvent, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, _callEventCancel, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, _cancelOperation, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, appendMessage, arginfo_phalcon_mvc_model_appendmessage, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, validate, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, validationHasFailed, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, getMessages, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, _checkForeignKeys, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, _checkForeignKeysReverse, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, _preSave, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, _postSave, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, _doLowInsert, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, _doLowUpdate, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, save, arginfo_phalcon_mvc_model_save, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, create, arginfo_phalcon_mvc_model_create, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, update, arginfo_phalcon_mvc_model_update, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, delete, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, getOperationMade, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, readAttribute, arginfo_phalcon_mvc_model_readattribute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, writeAttribute, arginfo_phalcon_mvc_model_writeattribute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, skipAttributes, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, skipAttributesOnCreate, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, skipAttributesOnUpdate, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, hasOne, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, belongsTo, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, hasMany, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, getRelated, arginfo_phalcon_mvc_model_getrelated, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, _getRelatedRecords, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model, __call, arginfo_phalcon_mvc_model___call, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, serialize, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, unserialize, arginfo_phalcon_mvc_model_unserialize, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model, dump, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_router_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Router);

PHP_METHOD(Phalcon_Mvc_Router, __construct);
PHP_METHOD(Phalcon_Mvc_Router, setDI);
PHP_METHOD(Phalcon_Mvc_Router, getDI);
PHP_METHOD(Phalcon_Mvc_Router, _getRewriteUri);
PHP_METHOD(Phalcon_Mvc_Router, removeExtraSlashes);
PHP_METHOD(Phalcon_Mvc_Router, setDefaultNamespace);
PHP_METHOD(Phalcon_Mvc_Router, setDefaultModule);
PHP_METHOD(Phalcon_Mvc_Router, setDefaultController);
PHP_METHOD(Phalcon_Mvc_Router, setDefaultAction);
PHP_METHOD(Phalcon_Mvc_Router, setDefaults);
PHP_METHOD(Phalcon_Mvc_Router, handle);
PHP_METHOD(Phalcon_Mvc_Router, add);
PHP_METHOD(Phalcon_Mvc_Router, addGet);
PHP_METHOD(Phalcon_Mvc_Router, addPost);
PHP_METHOD(Phalcon_Mvc_Router, addPut);
PHP_METHOD(Phalcon_Mvc_Router, addDelete);
PHP_METHOD(Phalcon_Mvc_Router, addOptions);
PHP_METHOD(Phalcon_Mvc_Router, addHead);
PHP_METHOD(Phalcon_Mvc_Router, clear);
PHP_METHOD(Phalcon_Mvc_Router, getNamespaceName);
PHP_METHOD(Phalcon_Mvc_Router, getModuleName);
PHP_METHOD(Phalcon_Mvc_Router, getControllerName);
PHP_METHOD(Phalcon_Mvc_Router, getActionName);
PHP_METHOD(Phalcon_Mvc_Router, getParams);
PHP_METHOD(Phalcon_Mvc_Router, getMatchedRoute);
PHP_METHOD(Phalcon_Mvc_Router, getMatches);
PHP_METHOD(Phalcon_Mvc_Router, wasMatched);
PHP_METHOD(Phalcon_Mvc_Router, getRoutes);
PHP_METHOD(Phalcon_Mvc_Router, getRouteById);
PHP_METHOD(Phalcon_Mvc_Router, getRouteByName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultRoutes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_removeextraslashes, 0, 0, 1)
	ZEND_ARG_INFO(0, remove)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdefaults, 0, 0, 1)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_addget, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_addpost, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_addput, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_adddelete, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_addoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_addhead, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_getroutebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_getroutebyname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_router_method_entry){
	PHP_ME(Phalcon_Mvc_Router, __construct, arginfo_phalcon_mvc_router___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Router, setDI, arginfo_phalcon_mvc_router_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, _getRewriteUri, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Router, removeExtraSlashes, arginfo_phalcon_mvc_router_removeextraslashes, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, setDefaultNamespace, arginfo_phalcon_mvc_router_setdefaultnamespace, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, setDefaultModule, arginfo_phalcon_mvc_router_setdefaultmodule, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, setDefaultController, arginfo_phalcon_mvc_router_setdefaultcontroller, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, setDefaultAction, arginfo_phalcon_mvc_router_setdefaultaction, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, setDefaults, arginfo_phalcon_mvc_router_setdefaults, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, handle, arginfo_phalcon_mvc_router_handle, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, add, arginfo_phalcon_mvc_router_add, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, addGet, arginfo_phalcon_mvc_router_addget, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, addPost, arginfo_phalcon_mvc_router_addpost, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, addPut, arginfo_phalcon_mvc_router_addput, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, addDelete, arginfo_phalcon_mvc_router_adddelete, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, addOptions, arginfo_phalcon_mvc_router_addoptions, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, addHead, arginfo_phalcon_mvc_router_addhead, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, clear, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getNamespaceName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getModuleName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getControllerName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getActionName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getParams, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getMatchedRoute, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getMatches, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, wasMatched, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getRoutes, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getRouteById, arginfo_phalcon_mvc_router_getroutebyid, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router, getRouteByName, arginfo_phalcon_mvc_router_getroutebyname, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_application_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Application);

PHP_METHOD(Phalcon_Mvc_Application, registerModules);
PHP_METHOD(Phalcon_Mvc_Application, getModules);
PHP_METHOD(Phalcon_Mvc_Application, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application_registermodules, 0, 0, 1)
	ZEND_ARG_INFO(0, modules)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_application_method_entry){
	PHP_ME(Phalcon_Mvc_Application, registerModules, arginfo_phalcon_mvc_application_registermodules, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Application, getModules, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Application, handle, arginfo_phalcon_mvc_application_handle, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_application_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Application_Exception);


zend_class_entry *phalcon_mvc_controller_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Controller);

PHP_METHOD(Phalcon_Mvc_Controller, __construct);

PHALCON_INIT_FUNCS(phalcon_mvc_controller_method_entry){
	PHP_ME(Phalcon_Mvc_Controller, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_collection_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Collection);

PHP_METHOD(Phalcon_Mvc_Collection, __construct);
PHP_METHOD(Phalcon_Mvc_Collection, setId);
PHP_METHOD(Phalcon_Mvc_Collection, getId);
PHP_METHOD(Phalcon_Mvc_Collection, setDI);
PHP_METHOD(Phalcon_Mvc_Collection, getDI);
PHP_METHOD(Phalcon_Mvc_Collection, setEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection, getEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection, getReservedAttributes);
PHP_METHOD(Phalcon_Mvc_Collection, setSource);
PHP_METHOD(Phalcon_Mvc_Collection, getSource);
PHP_METHOD(Phalcon_Mvc_Collection, setConnectionService);
PHP_METHOD(Phalcon_Mvc_Collection, getConnection);
PHP_METHOD(Phalcon_Mvc_Collection, readAttribute);
PHP_METHOD(Phalcon_Mvc_Collection, writeAttribute);
PHP_METHOD(Phalcon_Mvc_Collection, dumpResult);
PHP_METHOD(Phalcon_Mvc_Collection, _getResultset);
PHP_METHOD(Phalcon_Mvc_Collection, _preSave);
PHP_METHOD(Phalcon_Mvc_Collection, _postSave);
PHP_METHOD(Phalcon_Mvc_Collection, validate);
PHP_METHOD(Phalcon_Mvc_Collection, validationHasFailed);
PHP_METHOD(Phalcon_Mvc_Collection, _callEvent);
PHP_METHOD(Phalcon_Mvc_Collection, _callEventCancel);
PHP_METHOD(Phalcon_Mvc_Collection, _cancelOperation);
PHP_METHOD(Phalcon_Mvc_Collection, _exists);
PHP_METHOD(Phalcon_Mvc_Collection, getMessages);
PHP_METHOD(Phalcon_Mvc_Collection, appendMessage);
PHP_METHOD(Phalcon_Mvc_Collection, save);
PHP_METHOD(Phalcon_Mvc_Collection, findById);
PHP_METHOD(Phalcon_Mvc_Collection, findFirst);
PHP_METHOD(Phalcon_Mvc_Collection, find);
PHP_METHOD(Phalcon_Mvc_Collection, count);
PHP_METHOD(Phalcon_Mvc_Collection, delete);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_seteventsmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, eventsManager)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_appendmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_findbyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_findfirst, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_find, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_count, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_collection_method_entry){
	PHP_ME(Phalcon_Mvc_Collection, __construct, arginfo_phalcon_mvc_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Collection, setId, arginfo_phalcon_mvc_collection_setid, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, getId, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, setDI, arginfo_phalcon_mvc_collection_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, setEventsManager, arginfo_phalcon_mvc_collection_seteventsmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, getEventsManager, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, getReservedAttributes, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, setSource, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Collection, getSource, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, setConnectionService, arginfo_phalcon_mvc_collection_setconnectionservice, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, getConnection, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, readAttribute, arginfo_phalcon_mvc_collection_readattribute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, writeAttribute, arginfo_phalcon_mvc_collection_writeattribute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, dumpResult, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Collection, _getResultset, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Collection, _preSave, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Collection, _postSave, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Collection, validate, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Collection, validationHasFailed, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, _callEvent, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Collection, _callEventCancel, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Collection, _cancelOperation, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Collection, _exists, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Collection, getMessages, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, appendMessage, arginfo_phalcon_mvc_collection_appendmessage, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, save, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection, findById, arginfo_phalcon_mvc_collection_findbyid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Collection, findFirst, arginfo_phalcon_mvc_collection_findfirst, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Collection, find, arginfo_phalcon_mvc_collection_find, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Collection, count, arginfo_phalcon_mvc_collection_count, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Collection, delete, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_collection_manager_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_Manager);

PHP_METHOD(Phalcon_Mvc_Collection_Manager, __construct);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, isInitialized);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, initialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_isinitialized, 0, 0, 1)
	ZEND_ARG_INFO(0, collection)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_collection_manager_method_entry){
	PHP_ME(Phalcon_Mvc_Collection_Manager, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Collection_Manager, isInitialized, arginfo_phalcon_mvc_collection_manager_isinitialized, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Collection_Manager, initialize, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_collection_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_Exception);


zend_class_entry *phalcon_mvc_controllerinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_ControllerInterface);


zend_class_entry *phalcon_mvc_dispatcher_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Dispatcher);

PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerSuffix);
PHP_METHOD(Phalcon_Mvc_Dispatcher, setDefaultController);
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerName);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerName);
PHP_METHOD(Phalcon_Mvc_Dispatcher, _throwDispatchException);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getLastController);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getActiveController);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher_setcontrollersuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher_setcontrollername, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_dispatcher_method_entry){
	PHP_ME(Phalcon_Mvc_Dispatcher, setControllerSuffix, arginfo_phalcon_mvc_dispatcher_setcontrollersuffix, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Dispatcher, setDefaultController, arginfo_phalcon_mvc_dispatcher_setdefaultcontroller, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Dispatcher, setControllerName, arginfo_phalcon_mvc_dispatcher_setcontrollername, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Dispatcher, getControllerName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Dispatcher, _throwDispatchException, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Dispatcher, getLastController, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Dispatcher, getActiveController, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_dispatcher_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Dispatcher_Exception);


zend_class_entry *phalcon_mvc_model_row_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Row);

PHP_METHOD(Phalcon_Mvc_Model_Row, setForceExists);
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetExists);
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetGet);
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetSet);
PHP_METHOD(Phalcon_Mvc_Model_Row, offsetUnset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_row_setforceexists, 0, 0, 1)
	ZEND_ARG_INFO(0, forceExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_row_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_row_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_row_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_row_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_row_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Row, setForceExists, arginfo_phalcon_mvc_model_row_setforceexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Row, offsetExists, arginfo_phalcon_mvc_model_row_offsetexists, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Row, offsetGet, arginfo_phalcon_mvc_model_row_offsetget, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Row, offsetSet, arginfo_phalcon_mvc_model_row_offsetset, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Row, offsetUnset, arginfo_phalcon_mvc_model_row_offsetunset, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_query_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query);

PHP_METHOD(Phalcon_Mvc_Model_Query, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Query, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Query, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getQualified);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getCallArgument);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getFunctionCall);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getExpression);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getSelectColumn);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getTable);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoin);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoinType);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoins);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getOrderClause);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getGroupClause);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareSelect);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareInsert);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareDelete);
PHP_METHOD(Phalcon_Mvc_Model_Query, parse);
PHP_METHOD(Phalcon_Mvc_Model_Query, cache);
PHP_METHOD(Phalcon_Mvc_Model_Query, getCacheOptions);
PHP_METHOD(Phalcon_Mvc_Model_Query, getCache);
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeSelect);
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeInsert);
PHP_METHOD(Phalcon_Mvc_Model_Query, _getRelatedRecords);
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeDelete);
PHP_METHOD(Phalcon_Mvc_Model_Query, execute);
PHP_METHOD(Phalcon_Mvc_Model_Query, setType);
PHP_METHOD(Phalcon_Mvc_Model_Query, getType);
PHP_METHOD(Phalcon_Mvc_Model_Query, setIntermediate);
PHP_METHOD(Phalcon_Mvc_Model_Query, getIntermediate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, phql)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_cache, 0, 0, 1)
	ZEND_ARG_INFO(0, cacheOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_execute, 0, 0, 0)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setintermediate, 0, 0, 1)
	ZEND_ARG_INFO(0, intermediate)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_query_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Query, __construct, arginfo_phalcon_mvc_model_query___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_Query, setDI, arginfo_phalcon_mvc_model_query_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getQualified, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getCallArgument, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getFunctionCall, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getExpression, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getSelectColumn, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getTable, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getJoin, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getJoinType, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getJoins, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getOrderClause, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getGroupClause, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareSelect, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareInsert, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareUpdate, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareDelete, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, parse, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, cache, arginfo_phalcon_mvc_model_query_cache, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, getCacheOptions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, getCache, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, _executeSelect, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _executeInsert, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _getRelatedRecords, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _executeUpdate, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, _executeDelete, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Query, execute, arginfo_phalcon_mvc_model_query_execute, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, setType, arginfo_phalcon_mvc_model_query_settype, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, getType, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, setIntermediate, arginfo_phalcon_mvc_model_query_setintermediate, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query, getIntermediate, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_micro_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Micro_Exception);


zend_class_entry *phalcon_mvc_model_relation_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Relation);

PHP_METHOD(Phalcon_Mvc_Model_Relation, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getType);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedModel);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getFields);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedFields);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getOptions);
PHP_METHOD(Phalcon_Mvc_Model_Relation, isForeingKey);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getForeignKey);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relation___construct, 0, 0, 4)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_relation_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Relation, __construct, arginfo_phalcon_mvc_model_relation___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_Relation, getType, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Relation, getReferencedModel, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Relation, getFields, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Relation, getReferencedFields, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Relation, getOptions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Relation, isForeingKey, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Relation, getForeignKey, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_criteria_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Criteria);

PHP_METHOD(Phalcon_Mvc_Model_Criteria, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setModelName);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getModelName);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bind);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, where);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, conditions);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, order);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, limit);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, forUpdate);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, sharedLock);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getWhere);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getConditions);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getLimit);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getOrder);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getParams);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, fromInput);
PHP_METHOD(Phalcon_Mvc_Model_Criteria, execute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_setmodelname, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_bind, 0, 0, 1)
	ZEND_ARG_INFO(0, bindParams)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_where, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_conditions, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_order, 0, 0, 1)
	ZEND_ARG_INFO(0, orderColumns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_forupdate, 0, 0, 0)
	ZEND_ARG_INFO(0, forUpdate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_sharedlock, 0, 0, 0)
	ZEND_ARG_INFO(0, sharedLock)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_frominput, 0, 0, 3)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_criteria_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Criteria, setDI, arginfo_phalcon_mvc_model_criteria_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Criteria, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Criteria, setModelName, arginfo_phalcon_mvc_model_criteria_setmodelname, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Criteria, getModelName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Criteria, bind, arginfo_phalcon_mvc_model_criteria_bind, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Criteria, where, arginfo_phalcon_mvc_model_criteria_where, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Criteria, conditions, arginfo_phalcon_mvc_model_criteria_conditions, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Criteria, order, arginfo_phalcon_mvc_model_criteria_order, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Criteria, limit, arginfo_phalcon_mvc_model_criteria_limit, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Criteria, forUpdate, arginfo_phalcon_mvc_model_criteria_forupdate, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Criteria, sharedLock, arginfo_phalcon_mvc_model_criteria_sharedlock, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Criteria, getWhere, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Criteria, getConditions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Criteria, getLimit, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Criteria, getOrder, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Criteria, getParams, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Criteria, fromInput, arginfo_phalcon_mvc_model_criteria_frominput, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_ME(Phalcon_Mvc_Model_Criteria, execute, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_message_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Message);

PHP_METHOD(Phalcon_Mvc_Model_Message, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Message, setType);
PHP_METHOD(Phalcon_Mvc_Model_Message, getType);
PHP_METHOD(Phalcon_Mvc_Model_Message, setMessage);
PHP_METHOD(Phalcon_Mvc_Model_Message, getMessage);
PHP_METHOD(Phalcon_Mvc_Model_Message, setField);
PHP_METHOD(Phalcon_Mvc_Model_Message, getField);
PHP_METHOD(Phalcon_Mvc_Model_Message, __toString);
PHP_METHOD(Phalcon_Mvc_Model_Message, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_message___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_message_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_message_setmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_message_setfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_message___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_message_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Message, __construct, arginfo_phalcon_mvc_model_message___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_Message, setType, arginfo_phalcon_mvc_model_message_settype, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Message, getType, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Message, setMessage, arginfo_phalcon_mvc_model_message_setmessage, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Message, getMessage, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Message, setField, arginfo_phalcon_mvc_model_message_setfield, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Message, getField, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Message, __toString, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Message, __set_state, arginfo_phalcon_mvc_model_message___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_manager_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Manager);

PHP_METHOD(Phalcon_Mvc_Model_Manager, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Manager, setEventsManager);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getEventsManager);
PHP_METHOD(Phalcon_Mvc_Model_Manager, initialize);
PHP_METHOD(Phalcon_Mvc_Model_Manager, isInitialized);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastInitialized);
PHP_METHOD(Phalcon_Mvc_Model_Manager, load);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasOne);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBelongsTo);
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsBelongsTo);
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasOne);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationByAlias);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsToRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneRecords);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsTo);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOne);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneAndHasMany);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelations);
PHP_METHOD(Phalcon_Mvc_Model_Manager, createQuery);
PHP_METHOD(Phalcon_Mvc_Model_Manager, executeQuery);
PHP_METHOD(Phalcon_Mvc_Model_Manager, createBuilder);
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastQuery);

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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getbelongstorecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_INFO(0, record)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasmanyrecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_INFO(0, record)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasonerecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_INFO(0, record)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getbelongsto, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasmany, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasone, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasoneandhasmany, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getrelations, 0, 0, 2)
	ZEND_ARG_INFO(0, first)
	ZEND_ARG_INFO(0, second)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_createquery, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_executequery, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_createbuilder, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_manager_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Manager, setDI, arginfo_phalcon_mvc_model_manager_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, setEventsManager, arginfo_phalcon_mvc_model_manager_seteventsmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, getEventsManager, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, initialize, arginfo_phalcon_mvc_model_manager_initialize, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, isInitialized, arginfo_phalcon_mvc_model_manager_isinitialized, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, getLastInitialized, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, load, arginfo_phalcon_mvc_model_manager_load, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, addHasOne, arginfo_phalcon_mvc_model_manager_addhasone, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, addBelongsTo, arginfo_phalcon_mvc_model_manager_addbelongsto, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, addHasMany, arginfo_phalcon_mvc_model_manager_addhasmany, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, existsBelongsTo, arginfo_phalcon_mvc_model_manager_existsbelongsto, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, existsHasMany, arginfo_phalcon_mvc_model_manager_existshasmany, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, existsHasOne, arginfo_phalcon_mvc_model_manager_existshasone, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelationByAlias, arginfo_phalcon_mvc_model_manager_getrelationbyalias, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelationRecords, arginfo_phalcon_mvc_model_manager_getrelationrecords, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, getBelongsToRecords, arginfo_phalcon_mvc_model_manager_getbelongstorecords, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasManyRecords, arginfo_phalcon_mvc_model_manager_gethasmanyrecords, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasOneRecords, arginfo_phalcon_mvc_model_manager_gethasonerecords, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, getBelongsTo, arginfo_phalcon_mvc_model_manager_getbelongsto, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasMany, arginfo_phalcon_mvc_model_manager_gethasmany, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasOne, arginfo_phalcon_mvc_model_manager_gethasone, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasOneAndHasMany, arginfo_phalcon_mvc_model_manager_gethasoneandhasmany, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelations, arginfo_phalcon_mvc_model_manager_getrelations, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, createQuery, arginfo_phalcon_mvc_model_manager_createquery, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, executeQuery, arginfo_phalcon_mvc_model_manager_executequery, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, createBuilder, arginfo_phalcon_mvc_model_manager_createbuilder, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Manager, getLastQuery, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_transaction_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction);

PHP_METHOD(Phalcon_Mvc_Model_Transaction, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setTransactionManager);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, begin);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, commit);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, rollback);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, getConnection);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setIsNewTransaction);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackOnAbort);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, isManaged);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, getMessages);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, isValid);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackedRecord);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, autoBegin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_settransactionmanager, 0, 0, 1)
	ZEND_ARG_INFO(0, manager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, rollbackMessage)
	ZEND_ARG_INFO(0, rollbackRecord)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_setisnewtransaction, 0, 0, 1)
	ZEND_ARG_INFO(0, isNew)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_setrollbackonabort, 0, 0, 1)
	ZEND_ARG_INFO(0, rollbackOnAbort)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_setrollbackedrecord, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_transaction_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Transaction, __construct, arginfo_phalcon_mvc_model_transaction___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_Transaction, setTransactionManager, arginfo_phalcon_mvc_model_transaction_settransactionmanager, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction, begin, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction, commit, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction, rollback, arginfo_phalcon_mvc_model_transaction_rollback, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction, getConnection, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction, setIsNewTransaction, arginfo_phalcon_mvc_model_transaction_setisnewtransaction, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction, setRollbackOnAbort, arginfo_phalcon_mvc_model_transaction_setrollbackonabort, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction, isManaged, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction, getMessages, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction, isValid, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction, setRollbackedRecord, arginfo_phalcon_mvc_model_transaction_setrollbackedrecord, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_query_lang_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_Lang);

PHP_METHOD(Phalcon_Mvc_Model_Query_Lang, parsePHQL);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_lang_parsephql, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_query_lang_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Query_Lang, parsePHQL, arginfo_phalcon_mvc_model_query_lang_parsephql, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_metadata_apc_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Apc);

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_apc___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_apc_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_apc_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_metadata_apc_method_entry){
	PHP_ME(Phalcon_Mvc_Model_MetaData_Apc, __construct, arginfo_phalcon_mvc_model_metadata_apc___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_MetaData_Apc, read, arginfo_phalcon_mvc_model_metadata_apc_read, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData_Apc, write, arginfo_phalcon_mvc_model_metadata_apc_write, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_query_status_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_Status);

PHP_METHOD(Phalcon_Mvc_Model_Query_Status, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getModel);
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getMessages);
PHP_METHOD(Phalcon_Mvc_Model_Query_Status, success);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_status___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, success)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_query_status_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Query_Status, __construct, arginfo_phalcon_mvc_model_query_status___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_Query_Status, getModel, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Status, getMessages, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Status, success, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_metadata_files_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Files);

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_files___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_files_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_files_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_metadata_files_method_entry){
	PHP_ME(Phalcon_Mvc_Model_MetaData_Files, __construct, arginfo_phalcon_mvc_model_metadata_files___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_MetaData_Files, read, arginfo_phalcon_mvc_model_metadata_files_read, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData_Files, write, arginfo_phalcon_mvc_model_metadata_files_write, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_query_builder_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_Builder);

PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, columns);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getColumns);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, from);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, addFrom);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getFrom);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, join);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, where);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getWhere);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orderBy);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getOrderBy);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, having);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getHaving);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, limit);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getLimit);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, groupBy);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getGroupBy);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getPhql);
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getQuery);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_columns, 0, 0, 1)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_from, 0, 0, 1)
	ZEND_ARG_INFO(0, models)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_addfrom, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_join, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_where, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, orderBy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_having, 0, 0, 1)
	ZEND_ARG_INFO(0, having)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_groupby, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_query_builder_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, __construct, arginfo_phalcon_mvc_model_query_builder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, setDI, arginfo_phalcon_mvc_model_query_builder_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, columns, arginfo_phalcon_mvc_model_query_builder_columns, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getColumns, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, from, arginfo_phalcon_mvc_model_query_builder_from, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, addFrom, arginfo_phalcon_mvc_model_query_builder_addfrom, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getFrom, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, join, arginfo_phalcon_mvc_model_query_builder_join, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, where, arginfo_phalcon_mvc_model_query_builder_where, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getWhere, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, orderBy, arginfo_phalcon_mvc_model_query_builder_orderby, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getOrderBy, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, having, arginfo_phalcon_mvc_model_query_builder_having, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getHaving, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, limit, arginfo_phalcon_mvc_model_query_builder_limit, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getLimit, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, groupBy, arginfo_phalcon_mvc_model_query_builder_groupby, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getGroupBy, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getPhql, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getQuery, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_validator_regex_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Regex);

PHP_METHOD(Phalcon_Mvc_Model_Validator_Regex, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_regex_validate, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_validator_regex_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Validator_Regex, validate, arginfo_phalcon_mvc_model_validator_regex_validate, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_metadata_session_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Session);

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_session___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_session_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_session_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_metadata_session_method_entry){
	PHP_ME(Phalcon_Mvc_Model_MetaData_Session, __construct, arginfo_phalcon_mvc_model_metadata_session___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_MetaData_Session, read, arginfo_phalcon_mvc_model_metadata_session_read, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData_Session, write, arginfo_phalcon_mvc_model_metadata_session_write, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_metadata_memory_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Memory);

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memory, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memory, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memory, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_memory___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_memory_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_memory_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, metaData)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_metadata_memory_method_entry){
	PHP_ME(Phalcon_Mvc_Model_MetaData_Memory, __construct, arginfo_phalcon_mvc_model_metadata_memory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_MetaData_Memory, read, arginfo_phalcon_mvc_model_metadata_memory_read, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_MetaData_Memory, write, arginfo_phalcon_mvc_model_metadata_memory_write, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_resultset_simple_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Simple);

PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, valid);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, serialize);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_simple___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, result)
	ZEND_ARG_INFO(0, cache)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_simple_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_resultset_simple_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, __construct, arginfo_phalcon_mvc_model_resultset_simple___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, valid, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, serialize, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, unserialize, arginfo_phalcon_mvc_model_resultset_simple_unserialize, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_resultset_complex_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Complex);

PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, valid);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, serialize);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_complex___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, columnsTypes)
	ZEND_ARG_INFO(0, result)
	ZEND_ARG_INFO(0, cache)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_complex_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_resultset_complex_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, __construct, arginfo_phalcon_mvc_model_resultset_complex___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, valid, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, serialize, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, unserialize, arginfo_phalcon_mvc_model_resultset_complex_unserialize, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_validator_email_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Email);

PHP_METHOD(Phalcon_Mvc_Model_Validator_Email, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_email_validate, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_validator_email_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Validator_Email, validate, arginfo_phalcon_mvc_model_validator_email_validate, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_validator_presenceof_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_PresenceOf);

PHP_METHOD(Phalcon_Mvc_Model_Validator_PresenceOf, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_presenceof_validate, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_validator_presenceof_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Validator_PresenceOf, validate, arginfo_phalcon_mvc_model_validator_presenceof_validate, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_transaction_failed_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Failed);

PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, getRecordMessages);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, getRecord);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_failed___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_transaction_failed_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Transaction_Failed, __construct, arginfo_phalcon_mvc_model_transaction_failed___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Failed, getRecordMessages, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Failed, getRecord, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_transaction_manager_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Manager);

PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, has);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, get);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollbackPendent);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, commit);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollback);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyRollback);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyCommit);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, _collectTransaction);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, collectTransactions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_get, 0, 0, 0)
	ZEND_ARG_INFO(0, autoBegin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, collect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_notifyrollback, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_notifycommit, 0, 0, 1)
	ZEND_ARG_INFO(0, transaction)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_transaction_manager_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, __construct, arginfo_phalcon_mvc_model_transaction_manager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, setDI, arginfo_phalcon_mvc_model_transaction_manager_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, has, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, get, arginfo_phalcon_mvc_model_transaction_manager_get, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, rollbackPendent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, commit, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, rollback, arginfo_phalcon_mvc_model_transaction_manager_rollback, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, notifyRollback, arginfo_phalcon_mvc_model_transaction_manager_notifyrollback, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, notifyCommit, arginfo_phalcon_mvc_model_transaction_manager_notifycommit, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, _collectTransaction, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, collectTransactions, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_validator_uniqueness_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Uniqueness);

PHP_METHOD(Phalcon_Mvc_Model_Validator_Uniqueness, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_uniqueness_validate, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_validator_uniqueness_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Validator_Uniqueness, validate, arginfo_phalcon_mvc_model_validator_uniqueness_validate, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_behavior_timestampable_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Behavior_Timestampable);


zend_class_entry *phalcon_mvc_model_query_builderinterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_BuilderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_columns, 0, 0, 1)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_from, 0, 0, 1)
	ZEND_ARG_INFO(0, models)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_addfrom, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_join, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_where, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, orderBy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_having, 0, 0, 1)
	ZEND_ARG_INFO(0, having)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_groupby, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_query_builderinterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, __construct, arginfo_phalcon_mvc_model_query_builderinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, setDI, arginfo_phalcon_mvc_model_query_builderinterface_setdi)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getDI, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, columns, arginfo_phalcon_mvc_model_query_builderinterface_columns)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getColumns, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, from, arginfo_phalcon_mvc_model_query_builderinterface_from)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, addFrom, arginfo_phalcon_mvc_model_query_builderinterface_addfrom)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getFrom, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, join, arginfo_phalcon_mvc_model_query_builderinterface_join)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, where, arginfo_phalcon_mvc_model_query_builderinterface_where)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getWhere, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, orderBy, arginfo_phalcon_mvc_model_query_builderinterface_orderby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getOrderBy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, having, arginfo_phalcon_mvc_model_query_builderinterface_having)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getHaving, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, limit, arginfo_phalcon_mvc_model_query_builderinterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getLimit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, groupBy, arginfo_phalcon_mvc_model_query_builderinterface_groupby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getGroupBy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getPhql, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getQuery, NULL)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_transaction_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Exception);


zend_class_entry *phalcon_mvc_model_validator_exclusionin_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Exclusionin);

PHP_METHOD(Phalcon_Mvc_Model_Validator_Exclusionin, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_exclusionin_validate, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_validator_exclusionin_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Validator_Exclusionin, validate, arginfo_phalcon_mvc_model_validator_exclusionin_validate, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_validator_numericality_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Numericality);

PHP_METHOD(Phalcon_Mvc_Model_Validator_Numericality, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_numericality_validate, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_validator_numericality_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Validator_Numericality, validate, arginfo_phalcon_mvc_model_validator_numericality_validate, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_validator_stringlength_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_StringLength);

PHP_METHOD(Phalcon_Mvc_Model_Validator_StringLength, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_stringlength_validate, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_validator_stringlength_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Validator_StringLength, validate, arginfo_phalcon_mvc_model_validator_stringlength_validate, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_model_validator_inclusionin_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Validator_Inclusionin);

PHP_METHOD(Phalcon_Mvc_Model_Validator_Inclusionin, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_inclusionin_validate, 0, 0, 1)
	ZEND_ARG_INFO(0, record)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_model_validator_inclusionin_method_entry){
	PHP_ME(Phalcon_Mvc_Model_Validator_Inclusionin, validate, arginfo_phalcon_mvc_model_validator_inclusionin_validate, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_moduledefinitioninterface_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_ModuleDefinitionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_moduledefinitioninterface_registerservices, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_moduledefinitioninterface_method_entry){
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModuleDefinitionInterface, registerAutoloaders, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModuleDefinitionInterface, registerServices, arginfo_phalcon_mvc_moduledefinitioninterface_registerservices)
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_router_route_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Router_Route);

PHP_METHOD(Phalcon_Mvc_Router_Route, __construct);
PHP_METHOD(Phalcon_Mvc_Router_Route, compilePattern);
PHP_METHOD(Phalcon_Mvc_Router_Route, via);
PHP_METHOD(Phalcon_Mvc_Router_Route, reConfigure);
PHP_METHOD(Phalcon_Mvc_Router_Route, getName);
PHP_METHOD(Phalcon_Mvc_Router_Route, setName);
PHP_METHOD(Phalcon_Mvc_Router_Route, setHttpMethods);
PHP_METHOD(Phalcon_Mvc_Router_Route, getRouteId);
PHP_METHOD(Phalcon_Mvc_Router_Route, getPattern);
PHP_METHOD(Phalcon_Mvc_Router_Route, getCompiledPattern);
PHP_METHOD(Phalcon_Mvc_Router_Route, getPaths);
PHP_METHOD(Phalcon_Mvc_Router_Route, getReversedPaths);
PHP_METHOD(Phalcon_Mvc_Router_Route, getHttpMethods);
PHP_METHOD(Phalcon_Mvc_Router_Route, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_compilepattern, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_via, 0, 0, 1)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_reconfigure, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_sethttpmethods, 0, 0, 1)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_router_route_method_entry){
	PHP_ME(Phalcon_Mvc_Router_Route, __construct, arginfo_phalcon_mvc_router_route___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_Router_Route, compilePattern, arginfo_phalcon_mvc_router_route_compilepattern, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Route, via, arginfo_phalcon_mvc_router_route_via, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Route, reConfigure, arginfo_phalcon_mvc_router_route_reconfigure, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Route, getName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Route, setName, arginfo_phalcon_mvc_router_route_setname, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Route, setHttpMethods, arginfo_phalcon_mvc_router_route_sethttpmethods, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Route, getRouteId, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Route, getPattern, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Route, getCompiledPattern, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Route, getPaths, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Route, getReversedPaths, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Route, getHttpMethods, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_Router_Route, reset, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_router_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Router_Exception);


zend_class_entry *phalcon_mvc_user_module_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_User_Module);


zend_class_entry *phalcon_mvc_user_plugin_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_User_Plugin);


zend_class_entry *phalcon_mvc_url_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Url_Exception);


zend_class_entry *phalcon_mvc_user_component_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_User_Component);


zend_class_entry *phalcon_mvc_view_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View_Exception);


zend_class_entry *phalcon_mvc_view_engine_php_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine_Php);

PHP_METHOD(Phalcon_Mvc_View_Engine_Php, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_php_render, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, mustClean)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_view_engine_php_method_entry){
	PHP_ME(Phalcon_Mvc_View_Engine_Php, render, arginfo_phalcon_mvc_view_engine_php_render, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_view_engine_volt_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt);

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, setOptions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getOptions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getCompiler);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, render);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, length);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, converEncoding);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_render, 0, 0, 2)
	ZEND_ARG_INFO(0, templatePath)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, mustClean)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_length, 0, 0, 1)
	ZEND_ARG_INFO(0, item)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_converencoding, 0, 0, 3)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, to)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_view_engine_volt_method_entry){
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, setOptions, arginfo_phalcon_mvc_view_engine_volt_setoptions, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, getOptions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, getCompiler, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, render, arginfo_phalcon_mvc_view_engine_volt_render, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, length, arginfo_phalcon_mvc_view_engine_volt_length, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, converEncoding, arginfo_phalcon_mvc_view_engine_volt_converencoding, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_mvc_view_engine_volt_compiler_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Compiler);

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, __construct);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOptions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFunction);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFunctions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFilter);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFilters);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, attributeReader);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, functionCall);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveTest);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveFilter);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, expression);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementListOrExtends);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementList);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _compileSource);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileFile);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compile);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, parse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, view)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_addfunction, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_addfilter, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_attributereader, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_functioncall, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_resolvetest, 0, 0, 2)
	ZEND_ARG_INFO(0, test)
	ZEND_ARG_INFO(0, left)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_expression, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilestring, 0, 0, 1)
	ZEND_ARG_INFO(0, viewCode)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilefile, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, compiledPath)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compile, 0, 0, 1)
	ZEND_ARG_INFO(0, templatePath)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, viewCode)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_view_engine_volt_compiler_method_entry){
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, __construct, arginfo_phalcon_mvc_view_engine_volt_compiler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions, arginfo_phalcon_mvc_view_engine_volt_compiler_setoptions, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getOptions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI, arginfo_phalcon_mvc_view_engine_volt_compiler_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, addFunction, arginfo_phalcon_mvc_view_engine_volt_compiler_addfunction, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getFunctions, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, addFilter, arginfo_phalcon_mvc_view_engine_volt_compiler_addfilter, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getFilters, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, attributeReader, arginfo_phalcon_mvc_view_engine_volt_compiler_attributereader, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, functionCall, arginfo_phalcon_mvc_view_engine_volt_compiler_functioncall, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveTest, arginfo_phalcon_mvc_view_engine_volt_compiler_resolvetest, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveFilter, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, expression, arginfo_phalcon_mvc_view_engine_volt_compiler_expression, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementListOrExtends, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementList, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, _compileSource, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString, arginfo_phalcon_mvc_view_engine_volt_compiler_compilestring, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileFile, arginfo_phalcon_mvc_view_engine_volt_compiler_compilefile, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compile, arginfo_phalcon_mvc_view_engine_volt_compiler_compile, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, parse, arginfo_phalcon_mvc_view_engine_volt_compiler_parse, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_events_event_ce;

PHALCON_INIT_CLASS(Phalcon_Events_Event);

PHP_METHOD(Phalcon_Events_Event, __construct);
PHP_METHOD(Phalcon_Events_Event, setType);
PHP_METHOD(Phalcon_Events_Event, getType);
PHP_METHOD(Phalcon_Events_Event, getSource);
PHP_METHOD(Phalcon_Events_Event, setData);
PHP_METHOD(Phalcon_Events_Event, getData);
PHP_METHOD(Phalcon_Events_Event, setCancelable);
PHP_METHOD(Phalcon_Events_Event, getCancelable);
PHP_METHOD(Phalcon_Events_Event, stop);
PHP_METHOD(Phalcon_Events_Event, isStopped);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_event___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, cancelable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_event_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, eventType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_event_setdata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_event_setcancelable, 0, 0, 1)
	ZEND_ARG_INFO(0, cancelable)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_events_event_method_entry){
	PHP_ME(Phalcon_Events_Event, __construct, arginfo_phalcon_events_event___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Events_Event, setType, arginfo_phalcon_events_event_settype, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Event, getType, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Event, getSource, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Event, setData, arginfo_phalcon_events_event_setdata, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Event, getData, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Event, setCancelable, arginfo_phalcon_events_event_setcancelable, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Event, getCancelable, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Event, stop, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Event, isStopped, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_events_manager_ce;

PHALCON_INIT_CLASS(Phalcon_Events_Manager);

PHP_METHOD(Phalcon_Events_Manager, attach);
PHP_METHOD(Phalcon_Events_Manager, dettachAll);
PHP_METHOD(Phalcon_Events_Manager, fire);
PHP_METHOD(Phalcon_Events_Manager, hasListeners);
PHP_METHOD(Phalcon_Events_Manager, getListeners);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_attach, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_dettachall, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_fire, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, cancelable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_haslisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_getlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_events_manager_method_entry){
	PHP_ME(Phalcon_Events_Manager, attach, arginfo_phalcon_events_manager_attach, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, dettachAll, arginfo_phalcon_events_manager_dettachall, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, fire, arginfo_phalcon_events_manager_fire, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, hasListeners, arginfo_phalcon_events_manager_haslisteners, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Events_Manager, getListeners, arginfo_phalcon_events_manager_getlisteners, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};



zend_class_entry *phalcon_events_exception_ce;

PHALCON_INIT_CLASS(Phalcon_Events_Exception);
