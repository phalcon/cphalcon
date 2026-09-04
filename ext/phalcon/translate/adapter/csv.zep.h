
extern zend_class_entry *phalcon_translate_adapter_csv_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_Csv);

PHP_METHOD(Phalcon_Translate_Adapter_Csv, __construct);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, exists);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, has);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, query);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, toArray);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, load);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpFclose);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpFgetCsv);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpFileExists);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpFileGetContents);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpFilePutContents);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpFopen);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpFwrite);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpIsDir);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpIsWritable);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpMkdir);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpUnlink);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_csv___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, interpolator, Phalcon\\Translate\\InterpolatorFactory, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_exists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_query, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, translateKey, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, placeholders, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_toarray, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_load, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, enclosure, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, escape, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_phpfclose, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_translate_adapter_csv_phpfgetcsv, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, separator, IS_STRING, 0, "','")
	ZEND_ARG_INFO(0, enclosure)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_phpfileexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_translate_adapter_csv_phpfilegetcontents, 0, 1, MAY_BE_FALSE|MAY_BE_STRING)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, useIncludePath, _IS_BOOL, 0, "false")
	ZEND_ARG_INFO(0, context)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, offset, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_translate_adapter_csv_phpfileputcontents, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flags, IS_LONG, 0, "0")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_csv_phpfopen, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, useIncludePath, _IS_BOOL, 0, "false")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_translate_adapter_csv_phpfwrite, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_INFO(0, handle)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_phpisdir, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_phpiswritable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_phpmkdir, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, directory, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, permissions, IS_LONG, 0, "0777")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, recursive, _IS_BOOL, 0, "false")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_phpunlink, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_adapter_csv_method_entry) {
	PHP_ME(Phalcon_Translate_Adapter_Csv, __construct, arginfo_phalcon_translate_adapter_csv___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_Adapter_Csv, exists, arginfo_phalcon_translate_adapter_csv_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, has, arginfo_phalcon_translate_adapter_csv_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, query, arginfo_phalcon_translate_adapter_csv_query, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, toArray, arginfo_phalcon_translate_adapter_csv_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, load, arginfo_phalcon_translate_adapter_csv_load, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Translate_Adapter_Csv, phpFclose, arginfo_phalcon_translate_adapter_csv_phpfclose, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, phpFgetCsv, arginfo_phalcon_translate_adapter_csv_phpfgetcsv, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, phpFileExists, arginfo_phalcon_translate_adapter_csv_phpfileexists, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, phpFileGetContents, arginfo_phalcon_translate_adapter_csv_phpfilegetcontents, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, phpFilePutContents, arginfo_phalcon_translate_adapter_csv_phpfileputcontents, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, phpFopen, arginfo_phalcon_translate_adapter_csv_phpfopen, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, phpFwrite, arginfo_phalcon_translate_adapter_csv_phpfwrite, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, phpIsDir, arginfo_phalcon_translate_adapter_csv_phpisdir, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, phpIsWritable, arginfo_phalcon_translate_adapter_csv_phpiswritable, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, phpMkdir, arginfo_phalcon_translate_adapter_csv_phpmkdir, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, phpUnlink, arginfo_phalcon_translate_adapter_csv_phpunlink, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
