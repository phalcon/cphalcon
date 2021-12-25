
extern zend_class_entry *phalcon_mvc_view_engine_volt_compiler_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Compiler);

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, __construct);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addExtension);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFilter);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFunction);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, attributeReader);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compile);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileAutoEscape);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCall);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCase);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileDo);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileEcho);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileElseIf);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileFile);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForeach);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForElse);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileIf);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileInclude);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileMacro);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileReturn);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSet);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSwitch);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, expression);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, fireExtensionEvent);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, functionCall);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getExtensions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFilters);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFunctions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOption);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOptions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getTemplatePath);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getUniquePrefix);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, parse);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveTest);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOption);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setUniquePrefix);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSource);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFinalPath);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveFilter);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, statementList);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, statementListOrExtends);
zend_object *zephir_init_properties_Phalcon_Mvc_View_Engine_Volt_Compiler(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, view, Phalcon\\Mvc\\ViewBaseInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_addextension, 0, 1, Phalcon\\Mvc\\View\\Engine\\Volt\\Compiler, 0)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_addfilter, 0, 2, Phalcon\\Mvc\\View\\Engine\\Volt\\Compiler, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_addfunction, 0, 2, Phalcon\\Mvc\\View\\Engine\\Volt\\Compiler, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_attributereader, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compile, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, templatePath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, extendsMode, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileautoescape, 0, 2, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
	ZEND_ARG_TYPE_INFO(0, extendsMode, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilecall, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
	ZEND_ARG_TYPE_INFO(0, extendsMode, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilecase, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
	ZEND_ARG_TYPE_INFO(0, caseClause, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compiledo, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileecho, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileelseif, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilefile, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, compiledPath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, extendsMode, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileforeach, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
	ZEND_ARG_TYPE_INFO(0, extendsMode, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileforelse, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileif, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
	ZEND_ARG_TYPE_INFO(0, extendsMode, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileinclude, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilemacro, 0, 2, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
	ZEND_ARG_TYPE_INFO(0, extendsMode, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilereturn, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileset, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilestring, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewCode, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, extendsMode, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileswitch, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
	ZEND_ARG_TYPE_INFO(0, extendsMode, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_expression, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_fireextensionevent, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, arguments, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_functioncall, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_getcompiledtemplatepath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_getdi, 0, 0, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_getextensions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_getfilters, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_getfunctions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_getoption, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, option, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_getoptions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_gettemplatepath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_getuniqueprefix, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_parse, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, viewCode, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_resolvetest, 0, 2, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, test, 0)
	ZEND_ARG_TYPE_INFO(0, left, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_setdi, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_setoption, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, option, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_setuniqueprefix, 0, 1, Phalcon\\Mvc\\View\\Engine\\Volt\\Compiler, 0)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilesource, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewCode, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, extendsMode, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_getfinalpath, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_resolvefilter, 0, 2, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, filter, 0)
	ZEND_ARG_TYPE_INFO(0, left, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_statementlist, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, statements, 0)
	ZEND_ARG_TYPE_INFO(0, extendsMode, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_statementlistorextends, 0, 0, 1)
	ZEND_ARG_INFO(0, statements)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_zephir_init_properties_phalcon_mvc_view_engine_volt_compiler, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engine_volt_compiler_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, __construct, arginfo_phalcon_mvc_view_engine_volt_compiler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, addExtension, arginfo_phalcon_mvc_view_engine_volt_compiler_addextension, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, addFilter, arginfo_phalcon_mvc_view_engine_volt_compiler_addfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, addFunction, arginfo_phalcon_mvc_view_engine_volt_compiler_addfunction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, attributeReader, arginfo_phalcon_mvc_view_engine_volt_compiler_attributereader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compile, arginfo_phalcon_mvc_view_engine_volt_compiler_compile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileAutoEscape, arginfo_phalcon_mvc_view_engine_volt_compiler_compileautoescape, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCall, arginfo_phalcon_mvc_view_engine_volt_compiler_compilecall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCase, arginfo_phalcon_mvc_view_engine_volt_compiler_compilecase, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileDo, arginfo_phalcon_mvc_view_engine_volt_compiler_compiledo, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileEcho, arginfo_phalcon_mvc_view_engine_volt_compiler_compileecho, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileElseIf, arginfo_phalcon_mvc_view_engine_volt_compiler_compileelseif, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileFile, arginfo_phalcon_mvc_view_engine_volt_compiler_compilefile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForeach, arginfo_phalcon_mvc_view_engine_volt_compiler_compileforeach, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForElse, arginfo_phalcon_mvc_view_engine_volt_compiler_compileforelse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileIf, arginfo_phalcon_mvc_view_engine_volt_compiler_compileif, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileInclude, arginfo_phalcon_mvc_view_engine_volt_compiler_compileinclude, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileMacro, arginfo_phalcon_mvc_view_engine_volt_compiler_compilemacro, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileReturn, arginfo_phalcon_mvc_view_engine_volt_compiler_compilereturn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSet, arginfo_phalcon_mvc_view_engine_volt_compiler_compileset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString, arginfo_phalcon_mvc_view_engine_volt_compiler_compilestring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSwitch, arginfo_phalcon_mvc_view_engine_volt_compiler_compileswitch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, expression, arginfo_phalcon_mvc_view_engine_volt_compiler_expression, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, fireExtensionEvent, arginfo_phalcon_mvc_view_engine_volt_compiler_fireextensionevent, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, functionCall, arginfo_phalcon_mvc_view_engine_volt_compiler_functioncall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath, arginfo_phalcon_mvc_view_engine_volt_compiler_getcompiledtemplatepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI, arginfo_phalcon_mvc_view_engine_volt_compiler_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getExtensions, arginfo_phalcon_mvc_view_engine_volt_compiler_getextensions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getFilters, arginfo_phalcon_mvc_view_engine_volt_compiler_getfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getFunctions, arginfo_phalcon_mvc_view_engine_volt_compiler_getfunctions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getOption, arginfo_phalcon_mvc_view_engine_volt_compiler_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getOptions, arginfo_phalcon_mvc_view_engine_volt_compiler_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getTemplatePath, arginfo_phalcon_mvc_view_engine_volt_compiler_gettemplatepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getUniquePrefix, arginfo_phalcon_mvc_view_engine_volt_compiler_getuniqueprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, parse, arginfo_phalcon_mvc_view_engine_volt_compiler_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveTest, arginfo_phalcon_mvc_view_engine_volt_compiler_resolvetest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI, arginfo_phalcon_mvc_view_engine_volt_compiler_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setOption, arginfo_phalcon_mvc_view_engine_volt_compiler_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions, arginfo_phalcon_mvc_view_engine_volt_compiler_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setUniquePrefix, arginfo_phalcon_mvc_view_engine_volt_compiler_setuniqueprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSource, arginfo_phalcon_mvc_view_engine_volt_compiler_compilesource, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getFinalPath, arginfo_phalcon_mvc_view_engine_volt_compiler_getfinalpath, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveFilter, arginfo_phalcon_mvc_view_engine_volt_compiler_resolvefilter, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, statementList, arginfo_phalcon_mvc_view_engine_volt_compiler_statementlist, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, statementListOrExtends, arginfo_phalcon_mvc_view_engine_volt_compiler_statementlistorextends, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_FE_END
};
