
extern zend_class_entry *phalcon_html_helper_input_radiogroup_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_RadioGroup);

PHP_METHOD(Phalcon_Html_Helper_Input_RadioGroup, isChecked);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_radiogroup_ischecked, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_input_radiogroup_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Input_RadioGroup, isChecked, arginfo_phalcon_html_helper_input_radiogroup_ischecked, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
