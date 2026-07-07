
extern zend_class_entry *phalcon_annotations_adapter_stream_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Stream);

PHP_METHOD(Phalcon_Annotations_Adapter_Stream, __construct);
PHP_METHOD(Phalcon_Annotations_Adapter_Stream, read);
PHP_METHOD(Phalcon_Annotations_Adapter_Stream, write);
PHP_METHOD(Phalcon_Annotations_Adapter_Stream, phpFclose);
PHP_METHOD(Phalcon_Annotations_Adapter_Stream, phpFgetCsv);
PHP_METHOD(Phalcon_Annotations_Adapter_Stream, phpFileExists);
PHP_METHOD(Phalcon_Annotations_Adapter_Stream, phpFileGetContents);
PHP_METHOD(Phalcon_Annotations_Adapter_Stream, phpFilePutContents);
PHP_METHOD(Phalcon_Annotations_Adapter_Stream, phpFopen);
PHP_METHOD(Phalcon_Annotations_Adapter_Stream, phpFwrite);
PHP_METHOD(Phalcon_Annotations_Adapter_Stream, phpIsWritable);
PHP_METHOD(Phalcon_Annotations_Adapter_Stream, phpUnlink);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_stream___construct, 0, 0, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_TYPE_MASK_EX(arginfo_phalcon_annotations_adapter_stream_read, 0, 1, Phalcon\\Annotations\\Reflection, MAY_BE_BOOL|MAY_BE_LONG)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_stream_write, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, data, Phalcon\\Annotations\\Reflection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_stream_phpfclose, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_annotations_adapter_stream_phpfgetcsv, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, separator, IS_STRING, 0, "','")
	ZEND_ARG_INFO(0, enclosure)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_stream_phpfileexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_annotations_adapter_stream_phpfilegetcontents, 0, 1, MAY_BE_FALSE|MAY_BE_STRING)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_annotations_adapter_stream_phpfileputcontents, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flags, IS_LONG, 0, "0")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_stream_phpfopen, 0, 2, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_annotations_adapter_stream_phpfwrite, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_INFO(0, handle)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_stream_phpiswritable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_annotations_adapter_stream_phpunlink, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_adapter_stream_method_entry) {
	PHP_ME(Phalcon_Annotations_Adapter_Stream, __construct, arginfo_phalcon_annotations_adapter_stream___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Annotations_Adapter_Stream, read, arginfo_phalcon_annotations_adapter_stream_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_Stream, write, arginfo_phalcon_annotations_adapter_stream_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_Stream, phpFclose, arginfo_phalcon_annotations_adapter_stream_phpfclose, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Annotations_Adapter_Stream, phpFgetCsv, arginfo_phalcon_annotations_adapter_stream_phpfgetcsv, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Annotations_Adapter_Stream, phpFileExists, arginfo_phalcon_annotations_adapter_stream_phpfileexists, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Annotations_Adapter_Stream, phpFileGetContents, arginfo_phalcon_annotations_adapter_stream_phpfilegetcontents, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Annotations_Adapter_Stream, phpFilePutContents, arginfo_phalcon_annotations_adapter_stream_phpfileputcontents, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Annotations_Adapter_Stream, phpFopen, arginfo_phalcon_annotations_adapter_stream_phpfopen, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Annotations_Adapter_Stream, phpFwrite, arginfo_phalcon_annotations_adapter_stream_phpfwrite, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Annotations_Adapter_Stream, phpIsWritable, arginfo_phalcon_annotations_adapter_stream_phpiswritable, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Annotations_Adapter_Stream, phpUnlink, arginfo_phalcon_annotations_adapter_stream_phpunlink, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
