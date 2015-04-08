
extern zend_class_entry *phalcon_mvc_view_engine_markdown_compiler_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Markdown_Compiler);

PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, __construct);
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, setDI);
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, getDI);
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, setOptions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, setOption);
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, getOption);
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, getOptions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, _compileSource);
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, compileString);
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, compileFile);
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, compile);
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, getTemplatePath);
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, getCompiledTemplatePath);
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, parse);
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, getCompiled);
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, getToc);
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, getMeta);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_markdown_compiler___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, view)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_markdown_compiler_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_markdown_compiler_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_markdown_compiler_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_markdown_compiler_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_markdown_compiler__compilesource, 0, 0, 1)
	ZEND_ARG_INFO(0, viewCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_markdown_compiler_compilestring, 0, 0, 1)
	ZEND_ARG_INFO(0, viewCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_markdown_compiler_compilefile, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, compiledPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_markdown_compiler_compile, 0, 0, 1)
	ZEND_ARG_INFO(0, templatePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_markdown_compiler_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, viewCode)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engine_markdown_compiler_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Engine_Markdown_Compiler, __construct, arginfo_phalcon_mvc_view_engine_markdown_compiler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_View_Engine_Markdown_Compiler, setDI, arginfo_phalcon_mvc_view_engine_markdown_compiler_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Markdown_Compiler, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Markdown_Compiler, setOptions, arginfo_phalcon_mvc_view_engine_markdown_compiler_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Markdown_Compiler, setOption, arginfo_phalcon_mvc_view_engine_markdown_compiler_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Markdown_Compiler, getOption, arginfo_phalcon_mvc_view_engine_markdown_compiler_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Markdown_Compiler, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Markdown_Compiler, _compileSource, arginfo_phalcon_mvc_view_engine_markdown_compiler__compilesource, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Engine_Markdown_Compiler, compileString, arginfo_phalcon_mvc_view_engine_markdown_compiler_compilestring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Markdown_Compiler, compileFile, arginfo_phalcon_mvc_view_engine_markdown_compiler_compilefile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Markdown_Compiler, compile, arginfo_phalcon_mvc_view_engine_markdown_compiler_compile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Markdown_Compiler, getTemplatePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Markdown_Compiler, getCompiledTemplatePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Markdown_Compiler, parse, arginfo_phalcon_mvc_view_engine_markdown_compiler_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Markdown_Compiler, getCompiled, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Markdown_Compiler, getToc, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Markdown_Compiler, getMeta, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
