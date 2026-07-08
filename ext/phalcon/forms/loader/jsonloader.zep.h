
extern zend_class_entry *phalcon_forms_loader_jsonloader_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Loader_JsonLoader);

PHP_METHOD(Phalcon_Forms_Loader_JsonLoader, __construct);
PHP_METHOD(Phalcon_Forms_Loader_JsonLoader, load);
PHP_METHOD(Phalcon_Forms_Loader_JsonLoader, phpFclose);
PHP_METHOD(Phalcon_Forms_Loader_JsonLoader, phpFgetCsv);
PHP_METHOD(Phalcon_Forms_Loader_JsonLoader, phpFileExists);
PHP_METHOD(Phalcon_Forms_Loader_JsonLoader, phpFileGetContents);
PHP_METHOD(Phalcon_Forms_Loader_JsonLoader, phpFilePutContents);
PHP_METHOD(Phalcon_Forms_Loader_JsonLoader, phpFopen);
PHP_METHOD(Phalcon_Forms_Loader_JsonLoader, phpFwrite);
PHP_METHOD(Phalcon_Forms_Loader_JsonLoader, phpIsWritable);
PHP_METHOD(Phalcon_Forms_Loader_JsonLoader, phpUnlink);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_loader_jsonloader___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, source, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_loader_jsonloader_load, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_loader_jsonloader_phpfclose, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_forms_loader_jsonloader_phpfgetcsv, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, separator, IS_STRING, 0, "','")
	ZEND_ARG_INFO(0, enclosure)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_loader_jsonloader_phpfileexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_forms_loader_jsonloader_phpfilegetcontents, 0, 1, MAY_BE_FALSE|MAY_BE_STRING)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, useIncludePath, _IS_BOOL, 0, "false")
	ZEND_ARG_INFO(0, context)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, offset, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_forms_loader_jsonloader_phpfileputcontents, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flags, IS_LONG, 0, "0")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_loader_jsonloader_phpfopen, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, useIncludePath, _IS_BOOL, 0, "false")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_forms_loader_jsonloader_phpfwrite, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_INFO(0, handle)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_loader_jsonloader_phpiswritable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_forms_loader_jsonloader_phpunlink, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_loader_jsonloader_method_entry) {
	PHP_ME(Phalcon_Forms_Loader_JsonLoader, __construct, arginfo_phalcon_forms_loader_jsonloader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Loader_JsonLoader, load, arginfo_phalcon_forms_loader_jsonloader_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Loader_JsonLoader, phpFclose, arginfo_phalcon_forms_loader_jsonloader_phpfclose, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Forms_Loader_JsonLoader, phpFgetCsv, arginfo_phalcon_forms_loader_jsonloader_phpfgetcsv, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Forms_Loader_JsonLoader, phpFileExists, arginfo_phalcon_forms_loader_jsonloader_phpfileexists, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Forms_Loader_JsonLoader, phpFileGetContents, arginfo_phalcon_forms_loader_jsonloader_phpfilegetcontents, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Forms_Loader_JsonLoader, phpFilePutContents, arginfo_phalcon_forms_loader_jsonloader_phpfileputcontents, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Forms_Loader_JsonLoader, phpFopen, arginfo_phalcon_forms_loader_jsonloader_phpfopen, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Forms_Loader_JsonLoader, phpFwrite, arginfo_phalcon_forms_loader_jsonloader_phpfwrite, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Forms_Loader_JsonLoader, phpIsWritable, arginfo_phalcon_forms_loader_jsonloader_phpiswritable, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Forms_Loader_JsonLoader, phpUnlink, arginfo_phalcon_forms_loader_jsonloader_phpunlink, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
