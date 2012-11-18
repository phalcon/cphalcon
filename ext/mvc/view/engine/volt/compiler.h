
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_mvc_view_engine_volt_compiler_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Compiler);

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _functionCall);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _filter);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _expression);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementList);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _compileSource);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compile);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, parse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler__expression, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, extendsMode)
	ZEND_ARG_INFO(0, prependDollar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilestring, 0, 0, 1)
	ZEND_ARG_INFO(0, viewCode)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compile, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, compiledPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, viewCode)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_view_engine_volt_compiler_method_entry){
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI, arginfo_phalcon_mvc_view_engine_volt_compiler_setdi, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, _functionCall, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, _filter, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, _expression, arginfo_phalcon_mvc_view_engine_volt_compiler__expression, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementList, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, _compileSource, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString, arginfo_phalcon_mvc_view_engine_volt_compiler_compilestring, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compile, arginfo_phalcon_mvc_view_engine_volt_compiler_compile, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, parse, arginfo_phalcon_mvc_view_engine_volt_compiler_parse, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

