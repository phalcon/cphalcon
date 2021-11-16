
extern zend_class_entry *phalcon_support_debug_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Debug);

PHP_METHOD(Phalcon_Support_Debug, clearVars);
PHP_METHOD(Phalcon_Support_Debug, debugVar);
PHP_METHOD(Phalcon_Support_Debug, getCssSources);
PHP_METHOD(Phalcon_Support_Debug, getJsSources);
PHP_METHOD(Phalcon_Support_Debug, getVersion);
PHP_METHOD(Phalcon_Support_Debug, halt);
PHP_METHOD(Phalcon_Support_Debug, listen);
PHP_METHOD(Phalcon_Support_Debug, listenExceptions);
PHP_METHOD(Phalcon_Support_Debug, listenLowSeverity);
PHP_METHOD(Phalcon_Support_Debug, onUncaughtException);
PHP_METHOD(Phalcon_Support_Debug, onUncaughtLowSeverity);
PHP_METHOD(Phalcon_Support_Debug, renderHtml);
PHP_METHOD(Phalcon_Support_Debug, setBlacklist);
PHP_METHOD(Phalcon_Support_Debug, setShowBackTrace);
PHP_METHOD(Phalcon_Support_Debug, setShowFileFragment);
PHP_METHOD(Phalcon_Support_Debug, setShowFiles);
PHP_METHOD(Phalcon_Support_Debug, setUri);
PHP_METHOD(Phalcon_Support_Debug, escapeString);
PHP_METHOD(Phalcon_Support_Debug, getArrayDump);
PHP_METHOD(Phalcon_Support_Debug, getVarDump);
PHP_METHOD(Phalcon_Support_Debug, showTraceItem);
PHP_METHOD(Phalcon_Support_Debug, getArrVal);
zend_object *zephir_init_properties_Phalcon_Support_Debug(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_support_debug_clearvars, 0, 0, Phalcon\\Support\\Debug, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_support_debug_debugvar, 0, 1, Phalcon\\Support\\Debug, 0)
	ZEND_ARG_INFO(0, varz)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_getcsssources, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_getjssources, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_getversion, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_halt, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_support_debug_listen, 0, 0, Phalcon\\Support\\Debug, 0)
	ZEND_ARG_TYPE_INFO(0, exceptions, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, lowSeverity, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_support_debug_listenexceptions, 0, 0, Phalcon\\Support\\Debug, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_support_debug_listenlowseverity, 0, 0, Phalcon\\Support\\Debug, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_onuncaughtexception, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_onuncaughtlowseverity, 0, 5, IS_VOID, 0)

	ZEND_ARG_INFO(0, severity)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, line)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderhtml, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_support_debug_setblacklist, 0, 1, Phalcon\\Support\\Debug, 0)
	ZEND_ARG_ARRAY_INFO(0, blacklist, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_support_debug_setshowbacktrace, 0, 1, Phalcon\\Support\\Debug, 0)
	ZEND_ARG_TYPE_INFO(0, showBackTrace, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_support_debug_setshowfilefragment, 0, 1, Phalcon\\Support\\Debug, 0)
	ZEND_ARG_TYPE_INFO(0, showFileFragment, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_support_debug_setshowfiles, 0, 1, Phalcon\\Support\\Debug, 0)
	ZEND_ARG_TYPE_INFO(0, showFiles, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_support_debug_seturi, 0, 1, Phalcon\\Support\\Debug, 0)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_escapestring, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_getarraydump, 0, 1, IS_STRING, 1)
	ZEND_ARG_ARRAY_INFO(0, argument, 0)
	ZEND_ARG_INFO(0, n)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_getvardump, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, variable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_showtraceitem, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, n, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, trace, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_debug_getarrval, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_debug_zephir_init_properties_phalcon_support_debug, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_debug_method_entry) {
	PHP_ME(Phalcon_Support_Debug, clearVars, arginfo_phalcon_support_debug_clearvars, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug, debugVar, arginfo_phalcon_support_debug_debugvar, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug, getCssSources, arginfo_phalcon_support_debug_getcsssources, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug, getJsSources, arginfo_phalcon_support_debug_getjssources, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug, getVersion, arginfo_phalcon_support_debug_getversion, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug, halt, arginfo_phalcon_support_debug_halt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug, listen, arginfo_phalcon_support_debug_listen, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug, listenExceptions, arginfo_phalcon_support_debug_listenexceptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug, listenLowSeverity, arginfo_phalcon_support_debug_listenlowseverity, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug, onUncaughtException, arginfo_phalcon_support_debug_onuncaughtexception, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug, onUncaughtLowSeverity, arginfo_phalcon_support_debug_onuncaughtlowseverity, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug, renderHtml, arginfo_phalcon_support_debug_renderhtml, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug, setBlacklist, arginfo_phalcon_support_debug_setblacklist, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug, setShowBackTrace, arginfo_phalcon_support_debug_setshowbacktrace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug, setShowFileFragment, arginfo_phalcon_support_debug_setshowfilefragment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug, setShowFiles, arginfo_phalcon_support_debug_setshowfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug, setUri, arginfo_phalcon_support_debug_seturi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug, escapeString, arginfo_phalcon_support_debug_escapestring, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_Debug, getArrayDump, arginfo_phalcon_support_debug_getarraydump, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_Debug, getVarDump, arginfo_phalcon_support_debug_getvardump, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_Debug, showTraceItem, arginfo_phalcon_support_debug_showtraceitem, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_Debug, getArrVal, arginfo_phalcon_support_debug_getarrval, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
