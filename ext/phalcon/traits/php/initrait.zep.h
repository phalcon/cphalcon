
extern zend_class_entry *phalcon_traits_php_initrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_IniTrait);

PHP_METHOD(Phalcon_Traits_Php_IniTrait, phpIniGet);
PHP_METHOD(Phalcon_Traits_Php_IniTrait, phpIniGetBool);
PHP_METHOD(Phalcon_Traits_Php_IniTrait, phpIniGetInt);
PHP_METHOD(Phalcon_Traits_Php_IniTrait, phpParseIniFile);
PHP_METHOD(Phalcon_Traits_Php_IniTrait, staticPhpIniGet);
PHP_METHOD(Phalcon_Traits_Php_IniTrait, staticPhpIniGetBool);
PHP_METHOD(Phalcon_Traits_Php_IniTrait, staticPhpIniGetInt);
PHP_METHOD(Phalcon_Traits_Php_IniTrait, staticPhpParseIniFile);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_initrait_phpiniget, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, defaultValue, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_initrait_phpinigetbool, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, defaultValue, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_initrait_phpinigetint, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, defaultValue, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_traits_php_initrait_phpparseinifile, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, processSections, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, scannerMode, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_initrait_staticphpiniget, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, defaultValue, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_initrait_staticphpinigetbool, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, defaultValue, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_initrait_staticphpinigetint, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, defaultValue, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_traits_php_initrait_staticphpparseinifile, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, processSections, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, scannerMode, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_php_initrait_method_entry) {
	PHP_ME(Phalcon_Traits_Php_IniTrait, phpIniGet, arginfo_phalcon_traits_php_initrait_phpiniget, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Php_IniTrait, phpIniGetBool, arginfo_phalcon_traits_php_initrait_phpinigetbool, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Php_IniTrait, phpIniGetInt, arginfo_phalcon_traits_php_initrait_phpinigetint, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Php_IniTrait, phpParseIniFile, arginfo_phalcon_traits_php_initrait_phpparseinifile, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Php_IniTrait, staticPhpIniGet, arginfo_phalcon_traits_php_initrait_staticphpiniget, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_IniTrait, staticPhpIniGetBool, arginfo_phalcon_traits_php_initrait_staticphpinigetbool, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_IniTrait, staticPhpIniGetInt, arginfo_phalcon_traits_php_initrait_staticphpinigetint, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_IniTrait, staticPhpParseIniFile, arginfo_phalcon_traits_php_initrait_staticphpparseinifile, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
