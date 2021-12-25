
extern zend_class_entry *phalcon_mvc_view_engine_volt_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt);

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, callMacro);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, convertEncoding);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getCompiler);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getEventsManager);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getOptions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, isIncluded);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, length);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, preload);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, render);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, setEventsManager);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, setOptions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, slice);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, sort);
zend_object *zephir_init_properties_Phalcon_Mvc_View_Engine_Volt(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_callmacro, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, arguments, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_convertencoding, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, from, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, to, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_getcompiler, 0, 0, Phalcon\\Mvc\\View\\Engine\\Volt\\Compiler, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_getoptions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_isincluded, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, needle)
	ZEND_ARG_INFO(0, haystack)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_length, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, item)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_preload, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_render, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_TYPE_INFO(0, mustClean, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_seteventsmanager, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_slice, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, start, IS_LONG, 0)
	ZEND_ARG_INFO(0, end)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_sort, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_zephir_init_properties_phalcon_mvc_view_engine_volt, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engine_volt_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, callMacro, arginfo_phalcon_mvc_view_engine_volt_callmacro, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, convertEncoding, arginfo_phalcon_mvc_view_engine_volt_convertencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, getCompiler, arginfo_phalcon_mvc_view_engine_volt_getcompiler, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, getEventsManager, arginfo_phalcon_mvc_view_engine_volt_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, getOptions, arginfo_phalcon_mvc_view_engine_volt_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, isIncluded, arginfo_phalcon_mvc_view_engine_volt_isincluded, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, length, arginfo_phalcon_mvc_view_engine_volt_length, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, preload, arginfo_phalcon_mvc_view_engine_volt_preload, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, render, arginfo_phalcon_mvc_view_engine_volt_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, setEventsManager, arginfo_phalcon_mvc_view_engine_volt_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, setOptions, arginfo_phalcon_mvc_view_engine_volt_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, slice, arginfo_phalcon_mvc_view_engine_volt_slice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, sort, arginfo_phalcon_mvc_view_engine_volt_sort, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
