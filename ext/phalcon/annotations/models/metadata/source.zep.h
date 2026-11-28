
extern zend_class_entry *phalcon_annotations_models_metadata_source_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Models_MetaData_Source);

PHP_METHOD(Phalcon_Annotations_Models_MetaData_Source, __construct);
PHP_METHOD(Phalcon_Annotations_Models_MetaData_Source, getTable);
PHP_METHOD(Phalcon_Annotations_Models_MetaData_Source, getTableFromAdapter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_models_metadata_source___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, table, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_models_metadata_source_gettable, 0, 1, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, annotations, Phalcon\\Annotations\\Collection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_models_metadata_source_gettablefromadapter, 0, 2, IS_STRING, 1)
	ZEND_ARG_INFO(0, adapter)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_models_metadata_source_method_entry) {
	PHP_ME(Phalcon_Annotations_Models_MetaData_Source, __construct, arginfo_phalcon_annotations_models_metadata_source___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Annotations_Models_MetaData_Source, getTable, arginfo_phalcon_annotations_models_metadata_source_gettable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Annotations_Models_MetaData_Source, getTableFromAdapter, arginfo_phalcon_annotations_models_metadata_source_gettablefromadapter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
