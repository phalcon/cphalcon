
extern zend_class_entry *phalcon_support_debug_reportbuilder_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Debug_ReportBuilder);

PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, build);
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, buildFragment);
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, buildItem);
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, filter);
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, resolveClassLink);
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, resolveFunctionLink);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_support_debug_reportbuilder_build, 0, 7, Phalcon\\Support\\Debug\\Report\\ExceptionReport, 0)
	ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
	ZEND_ARG_ARRAY_INFO(0, blacklist, 0)
	ZEND_ARG_TYPE_INFO(0, showBackTrace, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, showFiles, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, showFileFragment, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_reportbuilder_buildfragment, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, line, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, showFileFragment, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_support_debug_reportbuilder_builditem, 0, 3, Phalcon\\Support\\Debug\\Report\\BacktraceItem, 0)
	ZEND_ARG_ARRAY_INFO(0, trace, 0)
	ZEND_ARG_TYPE_INFO(0, showFiles, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, showFileFragment, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_reportbuilder_filter, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, source, 0)
	ZEND_ARG_ARRAY_INFO(0, blacklist, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_reportbuilder_resolveclasslink, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_reportbuilder_resolvefunctionlink, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, functionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_debug_reportbuilder_method_entry) {
	PHP_ME(Phalcon_Support_Debug_ReportBuilder, build, arginfo_phalcon_support_debug_reportbuilder_build, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug_ReportBuilder, buildFragment, arginfo_phalcon_support_debug_reportbuilder_buildfragment, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Debug_ReportBuilder, buildItem, arginfo_phalcon_support_debug_reportbuilder_builditem, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Debug_ReportBuilder, filter, arginfo_phalcon_support_debug_reportbuilder_filter, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Debug_ReportBuilder, resolveClassLink, arginfo_phalcon_support_debug_reportbuilder_resolveclasslink, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Debug_ReportBuilder, resolveFunctionLink, arginfo_phalcon_support_debug_reportbuilder_resolvefunctionlink, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
