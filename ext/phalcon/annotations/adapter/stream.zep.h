
extern zend_class_entry *phalcon_annotations_adapter_stream_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Stream);

PHP_METHOD(Phalcon_Annotations_Adapter_Stream, __construct);
PHP_METHOD(Phalcon_Annotations_Adapter_Stream, read);
PHP_METHOD(Phalcon_Annotations_Adapter_Stream, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_stream___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_stream_read, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_stream_write, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, data, Phalcon\\Annotations\\Reflection, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_adapter_stream_method_entry) {
	PHP_ME(Phalcon_Annotations_Adapter_Stream, __construct, arginfo_phalcon_annotations_adapter_stream___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Annotations_Adapter_Stream, read, arginfo_phalcon_annotations_adapter_stream_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_Stream, write, arginfo_phalcon_annotations_adapter_stream_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
