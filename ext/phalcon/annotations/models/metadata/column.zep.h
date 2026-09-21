
extern zend_class_entry *phalcon_annotations_models_metadata_column_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Models_MetaData_Column);

PHP_METHOD(Phalcon_Annotations_Models_MetaData_Column, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_models_metadata_column___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, column, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, type, IS_STRING, 0, "'string'")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, nullable, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, skipOnInsert, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, skipOnUpdate, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, allowEmptyString, _IS_BOOL, 0, "false")
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_models_metadata_column_method_entry) {
	PHP_ME(Phalcon_Annotations_Models_MetaData_Column, __construct, arginfo_phalcon_annotations_models_metadata_column___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
