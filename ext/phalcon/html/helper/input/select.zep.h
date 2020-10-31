
extern zend_class_entry *phalcon_html_helper_input_select_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Select);

PHP_METHOD(Phalcon_Html_Helper_Input_Select, add);
PHP_METHOD(Phalcon_Html_Helper_Input_Select, addPlaceholder);
PHP_METHOD(Phalcon_Html_Helper_Input_Select, optGroup);
PHP_METHOD(Phalcon_Html_Helper_Input_Select, selected);
PHP_METHOD(Phalcon_Html_Helper_Input_Select, getTag);
PHP_METHOD(Phalcon_Html_Helper_Input_Select, optGroupEnd);
PHP_METHOD(Phalcon_Html_Helper_Input_Select, optGroupStart);
PHP_METHOD(Phalcon_Html_Helper_Input_Select, processValue);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_input_select_add, 0, 1, Phalcon\\Html\\Helper\\Input\\Select, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_select_add, 0, 1, IS_OBJECT, "Phalcon\\Html\\Helper\\Input\\Select", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, value)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, raw, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, raw)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_input_select_addplaceholder, 0, 1, Phalcon\\Html\\Helper\\Input\\Select, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_select_addplaceholder, 0, 1, IS_OBJECT, "Phalcon\\Html\\Helper\\Input\\Select", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, raw, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, raw)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_input_select_optgroup, 0, 0, Phalcon\\Html\\Helper\\Input\\Select, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_select_optgroup, 0, 0, IS_OBJECT, "Phalcon\\Html\\Helper\\Input\\Select", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, label)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_input_select_selected, 0, 1, Phalcon\\Html\\Helper\\Input\\Select, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_select_selected, 0, 1, IS_OBJECT, "Phalcon\\Html\\Helper\\Input\\Select", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, selected, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, selected)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_select_gettag, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_select_gettag, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_select_optgroupend, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_select_optgroupend, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_select_optgroupstart, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_select_optgroupstart, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, label)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_select_processvalue, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_input_select_processvalue, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_input_select_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Input_Select, add, arginfo_phalcon_html_helper_input_select_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Input_Select, addPlaceholder, arginfo_phalcon_html_helper_input_select_addplaceholder, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Input_Select, optGroup, arginfo_phalcon_html_helper_input_select_optgroup, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Input_Select, selected, arginfo_phalcon_html_helper_input_select_selected, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Input_Select, getTag, arginfo_phalcon_html_helper_input_select_gettag, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Helper_Input_Select, optGroupEnd, arginfo_phalcon_html_helper_input_select_optgroupend, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Helper_Input_Select, optGroupStart, arginfo_phalcon_html_helper_input_select_optgroupstart, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Helper_Input_Select, processValue, arginfo_phalcon_html_helper_input_select_processvalue, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
