
extern zend_class_entry *phalcon_mvc_model_metadata_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData);

PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticCreateAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticUpdateAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getBindTypes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getColumnMap);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDefaultValues);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypesNumeric);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDI);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getEmptyStringAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getIdentityField);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNonPrimaryKeyAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNotNullAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getPrimaryKeyAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getReverseColumnMap);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getStrategy);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, hasAttribute);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, isEmpty);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readColumnMap);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readColumnMapIndex);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaData);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaDataIndex);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, reset);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticCreateAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticUpdateAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setEmptyStringAttributes);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setDI);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, setStrategy);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, write);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, writeMetaDataIndex);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, initialize);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, throwWriteException);
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getArrVal);
zend_object *zephir_init_properties_Phalcon_Mvc_Model_MetaData(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_getattributes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_getautomaticcreateattributes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_getautomaticupdateattributes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_getbindtypes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_getcolumnmap, 0, 1, IS_ARRAY, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_getdefaultvalues, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_getdatatypes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_getdatatypesnumeric, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_metadata_getdi, 0, 0, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_getemptystringattributes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_getidentityfield, 0, 1, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_getnonprimarykeyattributes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_getnotnullattributes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_getprimarykeyattributes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_getreversecolumnmap, 0, 1, IS_ARRAY, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_metadata_getstrategy, 0, 0, Phalcon\\Mvc\\Model\\MetaData\\Strategy\\StrategyInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_hasattribute, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_isempty, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_read, 0, 1, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_readcolumnmap, 0, 1, IS_ARRAY, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_readcolumnmapindex, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_readmetadata, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_readmetadataindex, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_reset, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_setautomaticcreateattributes, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_setautomaticupdateattributes, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_setemptystringattributes, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_setdi, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_setstrategy, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, strategy, Phalcon\\Mvc\\Model\\MetaData\\Strategy\\StrategyInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_write, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_writemetadataindex, 0, 3, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_initialize, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_throwwriteexception, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getarrval, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_zephir_init_properties_phalcon_mvc_model_metadata, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData, getAttributes, arginfo_phalcon_mvc_model_metadata_getattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadata_getautomaticcreateattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadata_getautomaticupdateattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getBindTypes, arginfo_phalcon_mvc_model_metadata_getbindtypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getColumnMap, arginfo_phalcon_mvc_model_metadata_getcolumnmap, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getDefaultValues, arginfo_phalcon_mvc_model_metadata_getdefaultvalues, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getDataTypes, arginfo_phalcon_mvc_model_metadata_getdatatypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getDataTypesNumeric, arginfo_phalcon_mvc_model_metadata_getdatatypesnumeric, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getDI, arginfo_phalcon_mvc_model_metadata_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getEmptyStringAttributes, arginfo_phalcon_mvc_model_metadata_getemptystringattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getIdentityField, arginfo_phalcon_mvc_model_metadata_getidentityfield, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getNonPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadata_getnonprimarykeyattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getNotNullAttributes, arginfo_phalcon_mvc_model_metadata_getnotnullattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadata_getprimarykeyattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getReverseColumnMap, arginfo_phalcon_mvc_model_metadata_getreversecolumnmap, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getStrategy, arginfo_phalcon_mvc_model_metadata_getstrategy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, hasAttribute, arginfo_phalcon_mvc_model_metadata_hasattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, isEmpty, arginfo_phalcon_mvc_model_metadata_isempty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, read, arginfo_phalcon_mvc_model_metadata_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, readColumnMap, arginfo_phalcon_mvc_model_metadata_readcolumnmap, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, readColumnMapIndex, arginfo_phalcon_mvc_model_metadata_readcolumnmapindex, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, readMetaData, arginfo_phalcon_mvc_model_metadata_readmetadata, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, readMetaDataIndex, arginfo_phalcon_mvc_model_metadata_readmetadataindex, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, reset, arginfo_phalcon_mvc_model_metadata_reset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, setAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadata_setautomaticcreateattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, setAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadata_setautomaticupdateattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, setEmptyStringAttributes, arginfo_phalcon_mvc_model_metadata_setemptystringattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, setDI, arginfo_phalcon_mvc_model_metadata_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, setStrategy, arginfo_phalcon_mvc_model_metadata_setstrategy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, write, arginfo_phalcon_mvc_model_metadata_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, writeMetaDataIndex, arginfo_phalcon_mvc_model_metadata_writemetadataindex, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, initialize, arginfo_phalcon_mvc_model_metadata_initialize, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_MetaData, throwWriteException, arginfo_phalcon_mvc_model_metadata_throwwriteexception, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getArrVal, arginfo_phalcon_mvc_model_metadata_getarrval, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
