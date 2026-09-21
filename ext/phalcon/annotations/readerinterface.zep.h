
extern zend_class_entry *phalcon_annotations_readerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_ReaderInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_readerinterface_parse, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_readerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Annotations_ReaderInterface, parse, arginfo_phalcon_annotations_readerinterface_parse)
	PHP_FE_END
};
