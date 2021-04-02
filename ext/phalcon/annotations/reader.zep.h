
extern zend_class_entry *phalcon_annotations_reader_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Reader);

PHP_METHOD(Phalcon_Annotations_Reader, parse);
PHP_METHOD(Phalcon_Annotations_Reader, parseDocBlock);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_reader_parse, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_reader_parsedocblock, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, docBlock, IS_STRING, 0)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_reader_method_entry) {
	PHP_ME(Phalcon_Annotations_Reader, parse, arginfo_phalcon_annotations_reader_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Reader, parseDocBlock, arginfo_phalcon_annotations_reader_parsedocblock, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
