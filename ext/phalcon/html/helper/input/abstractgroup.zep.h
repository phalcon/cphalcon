
extern zend_class_entry *phalcon_html_helper_input_abstractgroup_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_AbstractGroup);

PHP_METHOD(Phalcon_Html_Helper_Input_AbstractGroup, __invoke);
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractGroup, __toString);
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractGroup, isChecked);
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractGroup, renderItem);
zend_object *zephir_init_properties_Phalcon_Html_Helper_Input_AbstractGroup(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_html_helper_input_abstractgroup___invoke, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
	ZEND_ARG_INFO(0, checked)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_abstractgroup___tostring, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_abstractgroup_ischecked, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_abstractgroup_renderitem, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_input_abstractgroup_zephir_init_properties_phalcon_html_helper_input_abstractgroup, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_input_abstractgroup_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Input_AbstractGroup, __invoke, arginfo_phalcon_html_helper_input_abstractgroup___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Input_AbstractGroup, __toString, arginfo_phalcon_html_helper_input_abstractgroup___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Input_AbstractGroup, isChecked, arginfo_phalcon_html_helper_input_abstractgroup_ischecked, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Helper_Input_AbstractGroup, renderItem, arginfo_phalcon_html_helper_input_abstractgroup_renderitem, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
