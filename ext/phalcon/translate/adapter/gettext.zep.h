
extern zend_class_entry *phalcon_translate_adapter_gettext_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_Gettext);

PHP_METHOD(Phalcon_Translate_Adapter_Gettext, __construct);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, query);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, exists);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, nquery);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setDomain);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, resetDomain);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setDefaultDomain);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getDefaultDomain);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setDirectory);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getDirectory);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setLocale);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getLocale);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getCategory);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, prepareOptions);
PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getOptionsDefault);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_query, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_nquery, 0, 0, 3)
	ZEND_ARG_INFO(0, msgid1)
	ZEND_ARG_INFO(0, msgid2)
	ZEND_ARG_INFO(0, count)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_setdomain, 0, 0, 1)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_setdefaultdomain, 0, 0, 1)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_setdirectory, 0, 0, 1)
	ZEND_ARG_INFO(0, directory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_getdirectory, 0, 0, 1)
	ZEND_ARG_INFO(0, directory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_setlocale, 0, 0, 2)
	ZEND_ARG_INFO(0, category)
	ZEND_ARG_INFO(0, locale)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_prepareoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_adapter_gettext_method_entry) {
	PHP_ME(Phalcon_Translate_Adapter_Gettext, __construct, arginfo_phalcon_translate_adapter_gettext___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, query, arginfo_phalcon_translate_adapter_gettext_query, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, exists, arginfo_phalcon_translate_adapter_gettext_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, nquery, arginfo_phalcon_translate_adapter_gettext_nquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, setDomain, arginfo_phalcon_translate_adapter_gettext_setdomain, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, resetDomain, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, setDefaultDomain, arginfo_phalcon_translate_adapter_gettext_setdefaultdomain, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, getDefaultDomain, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, setDirectory, arginfo_phalcon_translate_adapter_gettext_setdirectory, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, getDirectory, arginfo_phalcon_translate_adapter_gettext_getdirectory, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, setLocale, arginfo_phalcon_translate_adapter_gettext_setlocale, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, getLocale, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, getCategory, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, prepareOptions, arginfo_phalcon_translate_adapter_gettext_prepareoptions, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, getOptionsDefault, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
