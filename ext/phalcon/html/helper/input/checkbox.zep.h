
extern zend_class_entry *phalcon_html_helper_input_checkbox_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Checkbox);

PHP_METHOD(Phalcon_Html_Helper_Input_Checkbox, __construct);
PHP_METHOD(Phalcon_Html_Helper_Input_Checkbox, __toString);
PHP_METHOD(Phalcon_Html_Helper_Input_Checkbox, label);
PHP_METHOD(Phalcon_Html_Helper_Input_Checkbox, processChecked);
PHP_METHOD(Phalcon_Html_Helper_Input_Checkbox, processUnchecked);
zend_object *zephir_init_properties_Phalcon_Html_Helper_Input_Checkbox(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_input_checkbox___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, escaper, Phalcon\\Escaper\\EscaperInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_checkbox___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_input_checkbox___tostring, 0, 0, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_input_checkbox_label, 0, 0, Phalcon\\Html\\Helper\\Input\\Checkbox, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_checkbox_processchecked, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_checkbox_processunchecked, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_input_checkbox_zephir_init_properties_phalcon_html_helper_input_checkbox, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_input_checkbox_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Input_Checkbox, __construct, arginfo_phalcon_html_helper_input_checkbox___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Html_Helper_Input_Checkbox, __toString, arginfo_phalcon_html_helper_input_checkbox___tostring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Html_Helper_Input_Checkbox, __toString, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Html_Helper_Input_Checkbox, label, arginfo_phalcon_html_helper_input_checkbox_label, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Input_Checkbox, processChecked, arginfo_phalcon_html_helper_input_checkbox_processchecked, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Html_Helper_Input_Checkbox, processUnchecked, arginfo_phalcon_html_helper_input_checkbox_processunchecked, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
