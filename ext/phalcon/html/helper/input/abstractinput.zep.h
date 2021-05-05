
extern zend_class_entry *phalcon_html_helper_input_abstractinput_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_AbstractInput);

PHP_METHOD(Phalcon_Html_Helper_Input_AbstractInput, __invoke);
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractInput, __toString);
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractInput, setValue);
zend_object *zephir_init_properties_Phalcon_Html_Helper_Input_AbstractInput(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_input_abstractinput___invoke, 0, 1, Phalcon\\Html\\Helper\\Input\\AbstractInput, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 1)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_abstractinput___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_input_abstractinput___tostring, 0, 0, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_input_abstractinput_setvalue, 0, 0, Phalcon\\Html\\Helper\\Input\\AbstractInput, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_input_abstractinput_zephir_init_properties_phalcon_html_helper_input_abstractinput, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_input_abstractinput_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Input_AbstractInput, __invoke, arginfo_phalcon_html_helper_input_abstractinput___invoke, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Html_Helper_Input_AbstractInput, __toString, arginfo_phalcon_html_helper_input_abstractinput___tostring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Html_Helper_Input_AbstractInput, __toString, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Html_Helper_Input_AbstractInput, setValue, arginfo_phalcon_html_helper_input_abstractinput_setvalue, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
