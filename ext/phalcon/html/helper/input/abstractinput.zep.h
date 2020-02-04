
extern zend_class_entry *phalcon_html_helper_input_abstractinput_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_AbstractInput);

PHP_METHOD(Phalcon_Html_Helper_Input_AbstractInput, __invoke);
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractInput, __toString);
PHP_METHOD(Phalcon_Html_Helper_Input_AbstractInput, setValue);
zend_object *zephir_init_properties_Phalcon_Html_Helper_Input_AbstractInput(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_input_abstractinput___invoke, 0, 1, Phalcon\\Html\\Helper\\Input\\AbstractInput, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_abstractinput___invoke, 0, 1, IS_OBJECT, "Phalcon\\Html\\Helper\\Input\\AbstractInput", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, value)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_input_abstractinput_setvalue, 0, 0, Phalcon\\Html\\Helper\\Input\\AbstractInput, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_abstractinput_setvalue, 0, 0, IS_OBJECT, "Phalcon\\Html\\Helper\\Input\\AbstractInput", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_input_abstractinput_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Input_AbstractInput, __invoke, arginfo_phalcon_html_helper_input_abstractinput___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Input_AbstractInput, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Input_AbstractInput, setValue, arginfo_phalcon_html_helper_input_abstractinput_setvalue, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
