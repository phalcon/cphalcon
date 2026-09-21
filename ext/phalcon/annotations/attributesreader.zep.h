
extern zend_class_entry *phalcon_annotations_attributesreader_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_AttributesReader);

PHP_METHOD(Phalcon_Annotations_AttributesReader, parse);
PHP_METHOD(Phalcon_Annotations_AttributesReader, buildArguments);
PHP_METHOD(Phalcon_Annotations_AttributesReader, buildNodes);
PHP_METHOD(Phalcon_Annotations_AttributesReader, resolveName);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_attributesreader_parse, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_attributesreader_buildarguments, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, attributeArguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_attributesreader_buildnodes, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, line, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_attributesreader_resolvename, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_attributesreader_method_entry) {
	PHP_ME(Phalcon_Annotations_AttributesReader, parse, arginfo_phalcon_annotations_attributesreader_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_AttributesReader, buildArguments, arginfo_phalcon_annotations_attributesreader_buildarguments, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Annotations_AttributesReader, buildNodes, arginfo_phalcon_annotations_attributesreader_buildnodes, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Annotations_AttributesReader, resolveName, arginfo_phalcon_annotations_attributesreader_resolvename, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
