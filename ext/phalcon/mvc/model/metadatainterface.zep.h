
extern zend_class_entry *phalcon_mvc_model_metadatainterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaDataInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getattributes, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getattributes, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getautomaticcreateattributes, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getautomaticcreateattributes, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getautomaticupdateattributes, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getautomaticupdateattributes, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getbindtypes, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getbindtypes, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getcolumnmap, 0, 1, IS_ARRAY, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getcolumnmap, 0, 1, IS_ARRAY, NULL, 1)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getdefaultvalues, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getdefaultvalues, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getdatatypes, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getdatatypes, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getdatatypesnumeric, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getdatatypesnumeric, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getemptystringattributes, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getemptystringattributes, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getidentityfield, 0, 1, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getidentityfield, 0, 1, IS_STRING, NULL, 1)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getnonprimarykeyattributes, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getnonprimarykeyattributes, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getnotnullattributes, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getnotnullattributes, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getprimarykeyattributes, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getprimarykeyattributes, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getreversecolumnmap, 0, 1, IS_ARRAY, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getreversecolumnmap, 0, 1, IS_ARRAY, NULL, 1)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getstrategy, 0, 0, Phalcon\\Mvc\\Model\\MetaData\\Strategy\\StrategyInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getstrategy, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\Model\\MetaData\\Strategy\\StrategyInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_hasattribute, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_hasattribute, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attribute)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_isempty, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_isempty, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_read, 0, 1, IS_ARRAY, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_read, 0, 1, IS_ARRAY, NULL, 1)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readcolumnmap, 0, 1, IS_ARRAY, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readcolumnmap, 0, 1, IS_ARRAY, NULL, 1)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readcolumnmapindex, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, index)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readmetadata, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readmetadata, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readmetadataindex, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, index)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_reset, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_setautomaticcreateattributes, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_setautomaticupdateattributes, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_setemptystringattributes, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_setemptystringattributes, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_setemptystringattributes, 0, 0, 2)
#define arginfo_phalcon_mvc_model_metadatainterface_setemptystringattributes NULL
#endif

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_writemetadataindex, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, index)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_setstrategy, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, strategy, Phalcon\\Mvc\\Model\\MetaData\\Strategy\\StrategyInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_write, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_write, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_write, 0, 0, 2)
#define arginfo_phalcon_mvc_model_metadatainterface_write NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadatainterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getAttributes, arginfo_phalcon_mvc_model_metadatainterface_getattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadatainterface_getautomaticcreateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadatainterface_getautomaticupdateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getBindTypes, arginfo_phalcon_mvc_model_metadatainterface_getbindtypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getColumnMap, arginfo_phalcon_mvc_model_metadatainterface_getcolumnmap)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getDefaultValues, arginfo_phalcon_mvc_model_metadatainterface_getdefaultvalues)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getDataTypes, arginfo_phalcon_mvc_model_metadatainterface_getdatatypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getDataTypesNumeric, arginfo_phalcon_mvc_model_metadatainterface_getdatatypesnumeric)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getEmptyStringAttributes, arginfo_phalcon_mvc_model_metadatainterface_getemptystringattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getIdentityField, arginfo_phalcon_mvc_model_metadatainterface_getidentityfield)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getNonPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadatainterface_getnonprimarykeyattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getNotNullAttributes, arginfo_phalcon_mvc_model_metadatainterface_getnotnullattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadatainterface_getprimarykeyattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getReverseColumnMap, arginfo_phalcon_mvc_model_metadatainterface_getreversecolumnmap)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getStrategy, arginfo_phalcon_mvc_model_metadatainterface_getstrategy)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, hasAttribute, arginfo_phalcon_mvc_model_metadatainterface_hasattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, isEmpty, arginfo_phalcon_mvc_model_metadatainterface_isempty)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, read, arginfo_phalcon_mvc_model_metadatainterface_read)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readColumnMap, arginfo_phalcon_mvc_model_metadatainterface_readcolumnmap)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readColumnMapIndex, arginfo_phalcon_mvc_model_metadatainterface_readcolumnmapindex)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readMetaData, arginfo_phalcon_mvc_model_metadatainterface_readmetadata)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readMetaDataIndex, arginfo_phalcon_mvc_model_metadatainterface_readmetadataindex)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, reset, arginfo_phalcon_mvc_model_metadatainterface_reset)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadatainterface_setautomaticcreateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadatainterface_setautomaticupdateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, setEmptyStringAttributes, arginfo_phalcon_mvc_model_metadatainterface_setemptystringattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, writeMetaDataIndex, arginfo_phalcon_mvc_model_metadatainterface_writemetadataindex)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, setStrategy, arginfo_phalcon_mvc_model_metadatainterface_setstrategy)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, write, arginfo_phalcon_mvc_model_metadatainterface_write)
	PHP_FE_END
};
