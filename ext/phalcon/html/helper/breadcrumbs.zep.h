
extern zend_class_entry *phalcon_html_helper_breadcrumbs_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Breadcrumbs);

PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, __construct);
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, __invoke);
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, add);
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, clear);
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, clearAttributes);
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, getAttributes);
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, getSeparator);
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, getTemplate);
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, remove);
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, render);
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, setAttributes);
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, setSeparator);
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, setTemplate);
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, toArray);
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, getLink);
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, processAttributes);
zend_object *zephir_init_properties_Phalcon_Html_Helper_Breadcrumbs(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_breadcrumbs___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, escaper, Phalcon\\Html\\Escaper\\EscaperInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_breadcrumbs___invoke, 0, 0, Phalcon\\Html\\Helper\\Breadcrumbs, 0)
	ZEND_ARG_TYPE_INFO(0, indent, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_breadcrumbs_add, 0, 1, Phalcon\\Html\\Helper\\Breadcrumbs, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, link, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, icon, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_breadcrumbs_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_breadcrumbs_clearattributes, 0, 0, Phalcon\\Html\\Helper\\Breadcrumbs, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_breadcrumbs_getattributes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_breadcrumbs_getseparator, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_breadcrumbs_gettemplate, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_breadcrumbs_remove, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_breadcrumbs_render, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_breadcrumbs_setattributes, 0, 1, Phalcon\\Html\\Helper\\Breadcrumbs, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_breadcrumbs_setseparator, 0, 1, Phalcon\\Html\\Helper\\Breadcrumbs, 0)
	ZEND_ARG_TYPE_INFO(0, separator, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_breadcrumbs_settemplate, 0, 3, Phalcon\\Html\\Helper\\Breadcrumbs, 0)
	ZEND_ARG_TYPE_INFO(0, main, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, line, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, last, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_breadcrumbs_toarray, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_breadcrumbs_getlink, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, template, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, element, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_breadcrumbs_processattributes, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_breadcrumbs_zephir_init_properties_phalcon_html_helper_breadcrumbs, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_breadcrumbs_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Breadcrumbs, __construct, arginfo_phalcon_html_helper_breadcrumbs___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Html_Helper_Breadcrumbs, __invoke, arginfo_phalcon_html_helper_breadcrumbs___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Breadcrumbs, add, arginfo_phalcon_html_helper_breadcrumbs_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Breadcrumbs, clear, arginfo_phalcon_html_helper_breadcrumbs_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Breadcrumbs, clearAttributes, arginfo_phalcon_html_helper_breadcrumbs_clearattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Breadcrumbs, getAttributes, arginfo_phalcon_html_helper_breadcrumbs_getattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Breadcrumbs, getSeparator, arginfo_phalcon_html_helper_breadcrumbs_getseparator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Breadcrumbs, getTemplate, arginfo_phalcon_html_helper_breadcrumbs_gettemplate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Breadcrumbs, remove, arginfo_phalcon_html_helper_breadcrumbs_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Breadcrumbs, render, arginfo_phalcon_html_helper_breadcrumbs_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Breadcrumbs, setAttributes, arginfo_phalcon_html_helper_breadcrumbs_setattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Breadcrumbs, setSeparator, arginfo_phalcon_html_helper_breadcrumbs_setseparator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Breadcrumbs, setTemplate, arginfo_phalcon_html_helper_breadcrumbs_settemplate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Breadcrumbs, toArray, arginfo_phalcon_html_helper_breadcrumbs_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Breadcrumbs, getLink, arginfo_phalcon_html_helper_breadcrumbs_getlink, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Html_Helper_Breadcrumbs, processAttributes, arginfo_phalcon_html_helper_breadcrumbs_processattributes, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
