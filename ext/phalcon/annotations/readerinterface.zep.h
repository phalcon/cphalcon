
extern zend_class_entry *phalcon_annotations_readerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_ReaderInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_readerinterface_parse, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_readerinterface_parse, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_readerinterface_parsedocblock, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_readerinterface_parsedocblock, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, docBlock, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, docBlock)
#endif
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_readerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Annotations_ReaderInterface, parse, arginfo_phalcon_annotations_readerinterface_parse)
	ZEND_FENTRY(parseDocBlock, NULL, arginfo_phalcon_annotations_readerinterface_parsedocblock, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
