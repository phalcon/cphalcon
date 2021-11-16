
extern zend_class_entry *phalcon_support_debug_dump_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Debug_Dump);

PHP_METHOD(Phalcon_Support_Debug_Dump, getDetailed);
PHP_METHOD(Phalcon_Support_Debug_Dump, setDetailed);
PHP_METHOD(Phalcon_Support_Debug_Dump, __construct);
PHP_METHOD(Phalcon_Support_Debug_Dump, all);
PHP_METHOD(Phalcon_Support_Debug_Dump, one);
PHP_METHOD(Phalcon_Support_Debug_Dump, setStyles);
PHP_METHOD(Phalcon_Support_Debug_Dump, toJson);
PHP_METHOD(Phalcon_Support_Debug_Dump, variable);
PHP_METHOD(Phalcon_Support_Debug_Dump, variables);
PHP_METHOD(Phalcon_Support_Debug_Dump, getStyle);
PHP_METHOD(Phalcon_Support_Debug_Dump, output);
PHP_METHOD(Phalcon_Support_Debug_Dump, encode);
zend_object *zephir_init_properties_Phalcon_Support_Debug_Dump(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_dump_getdetailed, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_debug_dump_setdetailed, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, detailed, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_debug_dump___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, styles, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, styles, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, detailed, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_dump_all, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_dump_one, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, variable)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_dump_setstyles, 0, 0, IS_ARRAY, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, styles, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, styles, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_dump_tojson, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, variable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_dump_variable, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, variable)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_dump_variables, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_dump_getstyle, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_dump_output, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, variable)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, tab, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_dump_encode, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_debug_dump_zephir_init_properties_phalcon_support_debug_dump, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_debug_dump_method_entry) {
	PHP_ME(Phalcon_Support_Debug_Dump, getDetailed, arginfo_phalcon_support_debug_dump_getdetailed, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug_Dump, setDetailed, arginfo_phalcon_support_debug_dump_setdetailed, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug_Dump, __construct, arginfo_phalcon_support_debug_dump___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Support_Debug_Dump, all, arginfo_phalcon_support_debug_dump_all, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug_Dump, one, arginfo_phalcon_support_debug_dump_one, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug_Dump, setStyles, arginfo_phalcon_support_debug_dump_setstyles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug_Dump, toJson, arginfo_phalcon_support_debug_dump_tojson, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug_Dump, variable, arginfo_phalcon_support_debug_dump_variable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug_Dump, variables, arginfo_phalcon_support_debug_dump_variables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug_Dump, getStyle, arginfo_phalcon_support_debug_dump_getstyle, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_Debug_Dump, output, arginfo_phalcon_support_debug_dump_output, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_Debug_Dump, encode, arginfo_phalcon_support_debug_dump_encode, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
