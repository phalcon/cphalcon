
extern zend_class_entry *phalcon_debug_dump_ce;

ZEPHIR_INIT_CLASS(Phalcon_Debug_Dump);

PHP_METHOD(Phalcon_Debug_Dump, getDetailed);
PHP_METHOD(Phalcon_Debug_Dump, setDetailed);
PHP_METHOD(Phalcon_Debug_Dump, __construct);
PHP_METHOD(Phalcon_Debug_Dump, all);
PHP_METHOD(Phalcon_Debug_Dump, getStyle);
PHP_METHOD(Phalcon_Debug_Dump, setStyles);
PHP_METHOD(Phalcon_Debug_Dump, one);
PHP_METHOD(Phalcon_Debug_Dump, output);
PHP_METHOD(Phalcon_Debug_Dump, variable);
PHP_METHOD(Phalcon_Debug_Dump, variables);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_dump_setdetailed, 0, 0, 1)
	ZEND_ARG_INFO(0, detailed)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_dump___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, styles, 1)
	ZEND_ARG_INFO(0, detailed)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_dump_getstyle, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_dump_setstyles, 0, 0, 0)
	ZEND_ARG_INFO(0, styles)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_dump_one, 0, 0, 1)
	ZEND_ARG_INFO(0, variable)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_dump_output, 0, 0, 1)
	ZEND_ARG_INFO(0, variable)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, tab)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_dump_variable, 0, 0, 1)
	ZEND_ARG_INFO(0, variable)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_debug_dump_method_entry) {
	PHP_ME(Phalcon_Debug_Dump, getDetailed, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug_Dump, setDetailed, arginfo_phalcon_debug_dump_setdetailed, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug_Dump, __construct, arginfo_phalcon_debug_dump___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Debug_Dump, all, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug_Dump, getStyle, arginfo_phalcon_debug_dump_getstyle, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Debug_Dump, setStyles, arginfo_phalcon_debug_dump_setstyles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug_Dump, one, arginfo_phalcon_debug_dump_one, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug_Dump, output, arginfo_phalcon_debug_dump_output, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Debug_Dump, variable, arginfo_phalcon_debug_dump_variable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug_Dump, variables, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
