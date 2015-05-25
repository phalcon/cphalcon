
extern zend_class_entry *phalcon_debug_ce;

ZEPHIR_INIT_CLASS(Phalcon_Debug);

PHP_METHOD(Phalcon_Debug, setUri);
PHP_METHOD(Phalcon_Debug, setShowBackTrace);
PHP_METHOD(Phalcon_Debug, setShowFiles);
PHP_METHOD(Phalcon_Debug, setShowFileFragment);
PHP_METHOD(Phalcon_Debug, listen);
PHP_METHOD(Phalcon_Debug, listenExceptions);
PHP_METHOD(Phalcon_Debug, listenLowSeverity);
PHP_METHOD(Phalcon_Debug, halt);
PHP_METHOD(Phalcon_Debug, debugVar);
PHP_METHOD(Phalcon_Debug, clearVars);
PHP_METHOD(Phalcon_Debug, _escapeString);
PHP_METHOD(Phalcon_Debug, _getArrayDump);
PHP_METHOD(Phalcon_Debug, _getVarDump);
PHP_METHOD(Phalcon_Debug, getMajorVersion);
PHP_METHOD(Phalcon_Debug, getVersion);
PHP_METHOD(Phalcon_Debug, getCssSources);
PHP_METHOD(Phalcon_Debug, getJsSources);
PHP_METHOD(Phalcon_Debug, showTraceItem);
PHP_METHOD(Phalcon_Debug, onUncaughtLowSeverity);
PHP_METHOD(Phalcon_Debug, onUncaughtException);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_seturi, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_setshowbacktrace, 0, 0, 1)
	ZEND_ARG_INFO(0, showBackTrace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_setshowfiles, 0, 0, 1)
	ZEND_ARG_INFO(0, showFiles)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_setshowfilefragment, 0, 0, 1)
	ZEND_ARG_INFO(0, showFileFragment)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_listen, 0, 0, 0)
	ZEND_ARG_INFO(0, exceptions)
	ZEND_ARG_INFO(0, lowSeverity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_debugvar, 0, 0, 1)
	ZEND_ARG_INFO(0, varz)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug__escapestring, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug__getarraydump, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, argument, 0)
	ZEND_ARG_INFO(0, n)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug__getvardump, 0, 0, 1)
	ZEND_ARG_INFO(0, variable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_showtraceitem, 0, 0, 2)
	ZEND_ARG_INFO(0, n)
	ZEND_ARG_ARRAY_INFO(0, trace, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_onuncaughtlowseverity, 0, 0, 4)
	ZEND_ARG_INFO(0, severity)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_onuncaughtexception, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, exception, Exception, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_debug_method_entry) {
	PHP_ME(Phalcon_Debug, setUri, arginfo_phalcon_debug_seturi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, setShowBackTrace, arginfo_phalcon_debug_setshowbacktrace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, setShowFiles, arginfo_phalcon_debug_setshowfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, setShowFileFragment, arginfo_phalcon_debug_setshowfilefragment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, listen, arginfo_phalcon_debug_listen, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, listenExceptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, listenLowSeverity, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, halt, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, debugVar, arginfo_phalcon_debug_debugvar, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, clearVars, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, _escapeString, arginfo_phalcon_debug__escapestring, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Debug, _getArrayDump, arginfo_phalcon_debug__getarraydump, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Debug, _getVarDump, arginfo_phalcon_debug__getvardump, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Debug, getMajorVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, getVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, getCssSources, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, getJsSources, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, showTraceItem, arginfo_phalcon_debug_showtraceitem, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Debug, onUncaughtLowSeverity, arginfo_phalcon_debug_onuncaughtlowseverity, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, onUncaughtException, arginfo_phalcon_debug_onuncaughtexception, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
