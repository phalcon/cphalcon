
extern zend_class_entry *phalcon_traits_php_filetrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_FileTrait);

PHP_METHOD(Phalcon_Traits_Php_FileTrait, phpFclose);
PHP_METHOD(Phalcon_Traits_Php_FileTrait, phpFgetCsv);
PHP_METHOD(Phalcon_Traits_Php_FileTrait, phpFileExists);
PHP_METHOD(Phalcon_Traits_Php_FileTrait, phpFileGetContents);
PHP_METHOD(Phalcon_Traits_Php_FileTrait, phpFilePutContents);
PHP_METHOD(Phalcon_Traits_Php_FileTrait, phpFopen);
PHP_METHOD(Phalcon_Traits_Php_FileTrait, phpFwrite);
PHP_METHOD(Phalcon_Traits_Php_FileTrait, phpIsWritable);
PHP_METHOD(Phalcon_Traits_Php_FileTrait, phpUnlink);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_filetrait_phpfclose, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_traits_php_filetrait_phpfgetcsv, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, separator, IS_STRING, 0, "','")
	ZEND_ARG_INFO(0, enclosure)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_filetrait_phpfileexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_traits_php_filetrait_phpfilegetcontents, 0, 1, MAY_BE_FALSE|MAY_BE_STRING)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_traits_php_filetrait_phpfileputcontents, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flags, IS_LONG, 0, "0")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_filetrait_phpfopen, 0, 2, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_traits_php_filetrait_phpfwrite, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_INFO(0, handle)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_filetrait_phpiswritable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_filetrait_phpunlink, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_php_filetrait_method_entry) {
	PHP_ME(Phalcon_Traits_Php_FileTrait, phpFclose, arginfo_phalcon_traits_php_filetrait_phpfclose, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Php_FileTrait, phpFgetCsv, arginfo_phalcon_traits_php_filetrait_phpfgetcsv, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Php_FileTrait, phpFileExists, arginfo_phalcon_traits_php_filetrait_phpfileexists, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Php_FileTrait, phpFileGetContents, arginfo_phalcon_traits_php_filetrait_phpfilegetcontents, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Php_FileTrait, phpFilePutContents, arginfo_phalcon_traits_php_filetrait_phpfileputcontents, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Php_FileTrait, phpFopen, arginfo_phalcon_traits_php_filetrait_phpfopen, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Php_FileTrait, phpFwrite, arginfo_phalcon_traits_php_filetrait_phpfwrite, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Php_FileTrait, phpIsWritable, arginfo_phalcon_traits_php_filetrait_phpiswritable, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Php_FileTrait, phpUnlink, arginfo_phalcon_traits_php_filetrait_phpunlink, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
