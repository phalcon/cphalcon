
extern zend_class_entry *phalcon_html_breadcrumbs_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Breadcrumbs);

PHP_METHOD(Phalcon_Html_Breadcrumbs, getSeparator);
PHP_METHOD(Phalcon_Html_Breadcrumbs, setSeparator);
PHP_METHOD(Phalcon_Html_Breadcrumbs, add);
PHP_METHOD(Phalcon_Html_Breadcrumbs, clear);
PHP_METHOD(Phalcon_Html_Breadcrumbs, remove);
PHP_METHOD(Phalcon_Html_Breadcrumbs, render);
PHP_METHOD(Phalcon_Html_Breadcrumbs, toArray);
zend_object *zephir_init_properties_Phalcon_Html_Breadcrumbs(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_breadcrumbs_getseparator, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_breadcrumbs_setseparator, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, separator, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_breadcrumbs_add, 0, 1, Phalcon\\Html\\Breadcrumbs, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, link, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_breadcrumbs_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_breadcrumbs_remove, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, link, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_breadcrumbs_render, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_breadcrumbs_toarray, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_breadcrumbs_zephir_init_properties_phalcon_html_breadcrumbs, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_breadcrumbs_method_entry) {
	PHP_ME(Phalcon_Html_Breadcrumbs, getSeparator, arginfo_phalcon_html_breadcrumbs_getseparator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Breadcrumbs, setSeparator, arginfo_phalcon_html_breadcrumbs_setseparator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Breadcrumbs, add, arginfo_phalcon_html_breadcrumbs_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Breadcrumbs, clear, arginfo_phalcon_html_breadcrumbs_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Breadcrumbs, remove, arginfo_phalcon_html_breadcrumbs_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Breadcrumbs, render, arginfo_phalcon_html_breadcrumbs_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Breadcrumbs, toArray, arginfo_phalcon_html_breadcrumbs_toarray, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
