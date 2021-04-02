
extern zend_class_entry *phalcon_html_helper_input_textarea_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Textarea);

PHP_METHOD(Phalcon_Html_Helper_Input_Textarea, __toString);

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_textarea___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_input_textarea___tostring, 0, 0, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_input_textarea_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Html_Helper_Input_Textarea, __toString, arginfo_phalcon_html_helper_input_textarea___tostring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Html_Helper_Input_Textarea, __toString, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
