
extern zend_class_entry *phalcon_mvc_view_engine_volt_compiler_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Compiler);

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, __construct);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOption);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compile);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, view)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compile, 0, 0, 1)
	ZEND_ARG_INFO(0, templatePath)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engine_volt_compiler_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, __construct, arginfo_phalcon_mvc_view_engine_volt_compiler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI, arginfo_phalcon_mvc_view_engine_volt_compiler_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions, arginfo_phalcon_mvc_view_engine_volt_compiler_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setOption, arginfo_phalcon_mvc_view_engine_volt_compiler_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compile, arginfo_phalcon_mvc_view_engine_volt_compiler_compile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
