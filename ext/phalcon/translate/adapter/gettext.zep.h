
extern zend_class_entry *phalcon_translate_adapter_gettext_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_Gettext);

PHP_METHOD(Phalcon_Translate_Adapter_Gettext, __construct);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, exists);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getCategory);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getDefaultDomain);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getDirectory);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getLocale);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, has);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, nquery);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, query);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, resetDomain);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setDefaultDomain);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setDirectory);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setDomain);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setLocale);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getOptionsDefault);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, prepareOptions);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, phpFunctionExists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, interpolator, Phalcon\\Translate\\InterpolatorFactory, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_gettext_exists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_gettext_getcategory, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_gettext_getdefaultdomain, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_getdirectory, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_gettext_getlocale, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_gettext_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_gettext_nquery, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, msgid1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, msgid2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, placeholders, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, placeholders, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, domain, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_gettext_query, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, translateKey, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, placeholders, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, placeholders, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_gettext_resetdomain, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_gettext_setdefaultdomain, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, domain, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_gettext_setdirectory, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, directory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_gettext_setdomain, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, domain, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_setlocale, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, category, IS_LONG, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, localeArray, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, localeArray, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_gettext_getoptionsdefault, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_gettext_prepareoptions, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_gettext_phpfunctionexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_adapter_gettext_method_entry) {
	PHP_ME(Phalcon_Translate_Adapter_Gettext, __construct, arginfo_phalcon_translate_adapter_gettext___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, exists, arginfo_phalcon_translate_adapter_gettext_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, getCategory, arginfo_phalcon_translate_adapter_gettext_getcategory, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, getDefaultDomain, arginfo_phalcon_translate_adapter_gettext_getdefaultdomain, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Translate_Adapter_Gettext, getDirectory, arginfo_phalcon_translate_adapter_gettext_getdirectory, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Translate_Adapter_Gettext, getDirectory, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Translate_Adapter_Gettext, getLocale, arginfo_phalcon_translate_adapter_gettext_getlocale, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, has, arginfo_phalcon_translate_adapter_gettext_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, nquery, arginfo_phalcon_translate_adapter_gettext_nquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, query, arginfo_phalcon_translate_adapter_gettext_query, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, resetDomain, arginfo_phalcon_translate_adapter_gettext_resetdomain, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, setDefaultDomain, arginfo_phalcon_translate_adapter_gettext_setdefaultdomain, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, setDirectory, arginfo_phalcon_translate_adapter_gettext_setdirectory, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, setDomain, arginfo_phalcon_translate_adapter_gettext_setdomain, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, setLocale, arginfo_phalcon_translate_adapter_gettext_setlocale, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, getOptionsDefault, arginfo_phalcon_translate_adapter_gettext_getoptionsdefault, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, prepareOptions, arginfo_phalcon_translate_adapter_gettext_prepareoptions, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, phpFunctionExists, arginfo_phalcon_translate_adapter_gettext_phpfunctionexists, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
