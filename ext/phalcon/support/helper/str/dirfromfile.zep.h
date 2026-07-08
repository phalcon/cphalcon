
extern zend_class_entry *phalcon_support_helper_str_dirfromfile_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_DirFromFile);

PHP_METHOD(Phalcon_Support_Helper_Str_DirFromFile, __invoke);
PHP_METHOD(Phalcon_Support_Helper_Str_DirFromFile, toDirFromFile);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_dirfromfile___invoke, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_dirfromfile_todirfromfile, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, filesystemSafe, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_str_dirfromfile_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Str_DirFromFile, __invoke, arginfo_phalcon_support_helper_str_dirfromfile___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Helper_Str_DirFromFile, toDirFromFile, arginfo_phalcon_support_helper_str_dirfromfile_todirfromfile, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
