
extern zend_class_entry *phalcon_html_helper_input_checkbox_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Checkbox);

PHP_METHOD(Phalcon_Html_Helper_Input_Checkbox, __construct);
PHP_METHOD(Phalcon_Html_Helper_Input_Checkbox, __toString);
PHP_METHOD(Phalcon_Html_Helper_Input_Checkbox, label);
PHP_METHOD(Phalcon_Html_Helper_Input_Checkbox, processChecked);
PHP_METHOD(Phalcon_Html_Helper_Input_Checkbox, processUnchecked);
zend_object *zephir_init_properties_Phalcon_Html_Helper_Input_Checkbox(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_input_checkbox___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, escaper, Phalcon\\Escaper\\EscaperInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_input_checkbox_label, 0, 0, Phalcon\\Html\\Helper\\Input\\Checkbox, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_checkbox_label, 0, 0, IS_OBJECT, "Phalcon\\Html\\Helper\\Input\\Checkbox", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_checkbox_processchecked, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_checkbox_processchecked, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_phalcon_html_helper_input_checkbox_processchecked NULL
#endif

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_checkbox_processunchecked, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_checkbox_processunchecked, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_input_checkbox_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Input_Checkbox, __construct, arginfo_phalcon_html_helper_input_checkbox___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Html_Helper_Input_Checkbox, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Input_Checkbox, label, arginfo_phalcon_html_helper_input_checkbox_label, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Input_Checkbox, processChecked, arginfo_phalcon_html_helper_input_checkbox_processchecked, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Html_Helper_Input_Checkbox, processUnchecked, arginfo_phalcon_html_helper_input_checkbox_processunchecked, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
