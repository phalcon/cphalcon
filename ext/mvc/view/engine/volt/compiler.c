/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/view/engine/volt/compiler.h"
#include "mvc/view/engine/volt/scanner.h"
#include "mvc/view/engine/volt/volt.h"
#include "mvc/view/exception.h"
#include "diinterface.h"
#include "di/injectionawareinterface.h"
#include "interned-strings.h"

#include <Zend/zend_closures.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/variables.h"

/**
 * Phalcon\Mvc\View\Engine\Volt\Compiler
 *
 * This class reads and compiles Volt templates into PHP plain code
 *
 *<code>
 *	$compiler = new \Phalcon\Mvc\View\Engine\Volt\Compiler();
 *
 *	$compiler->compile('views/partials/header.volt');
 *
 *	require $compiler->getCompiledTemplatePath();
 *</code>
 */
zend_class_entry *phalcon_mvc_view_engine_volt_compiler_ce;

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, __construct);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOption);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOption);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOptions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, fireExtensionEvent);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addExtension);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getExtensions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFunction);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFunctions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFilter);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFilters);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setUniquePrefix);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getUniquePrefix);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, attributeReader);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, functionCall);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveTest);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveFilter);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, expression);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementListOrExtends);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForeach);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForElse);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileIf);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileElseIf);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCache);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileEcho);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileInclude);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSet);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileDo);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileReturn);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileAutoEscape);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileMacro);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCall);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementList);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _compileSource);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileFile);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compile);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getTemplatePath);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, parse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, view)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_fireextensionevent, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_addextension, 0, 0, 1)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_addfunction, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_addfilter, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_setuniqueprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_attributereader, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_functioncall, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_resolvetest, 0, 0, 2)
	ZEND_ARG_INFO(0, test)
	ZEND_ARG_INFO(0, left)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_expression, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileforeach, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileif, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileelseif, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilecache, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileecho, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileinclude, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileset, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compiledo, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilereturn, 0, 0, 1)
	ZEND_ARG_INFO(0, statement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileautoescape, 0, 0, 2)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilemacro, 0, 0, 2)
	ZEND_ARG_INFO(0, statement)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilestring, 0, 0, 1)
	ZEND_ARG_INFO(0, viewCode)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilefile, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, compiledPath)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compile, 0, 0, 1)
	ZEND_ARG_INFO(0, templatePath)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, viewCode)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_view_engine_volt_compiler_method_entry[] = {
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, __construct, arginfo_phalcon_mvc_view_engine_volt_compiler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI, arginfo_phalcon_di_injectionawareinterface_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI, arginfo_phalcon_di_injectionawareinterface_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions, arginfo_phalcon_mvc_view_engine_volt_compiler_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setOption, arginfo_phalcon_mvc_view_engine_volt_compiler_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getOption, arginfo_phalcon_mvc_view_engine_volt_compiler_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, fireExtensionEvent, arginfo_phalcon_mvc_view_engine_volt_compiler_fireextensionevent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, addExtension, arginfo_phalcon_mvc_view_engine_volt_compiler_addextension, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getExtensions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, addFunction, arginfo_phalcon_mvc_view_engine_volt_compiler_addfunction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getFunctions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, addFilter, arginfo_phalcon_mvc_view_engine_volt_compiler_addfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getFilters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setUniquePrefix, arginfo_phalcon_mvc_view_engine_volt_compiler_setuniqueprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getUniquePrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, attributeReader, arginfo_phalcon_mvc_view_engine_volt_compiler_attributereader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, functionCall, arginfo_phalcon_mvc_view_engine_volt_compiler_functioncall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveTest, arginfo_phalcon_mvc_view_engine_volt_compiler_resolvetest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveFilter, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, expression, arginfo_phalcon_mvc_view_engine_volt_compiler_expression, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementListOrExtends, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForeach, arginfo_phalcon_mvc_view_engine_volt_compiler_compileforeach, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForElse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileIf, arginfo_phalcon_mvc_view_engine_volt_compiler_compileif, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileElseIf, arginfo_phalcon_mvc_view_engine_volt_compiler_compileelseif, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCache, arginfo_phalcon_mvc_view_engine_volt_compiler_compilecache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileEcho, arginfo_phalcon_mvc_view_engine_volt_compiler_compileecho, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileInclude, arginfo_phalcon_mvc_view_engine_volt_compiler_compileinclude, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSet, arginfo_phalcon_mvc_view_engine_volt_compiler_compileset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileDo, arginfo_phalcon_mvc_view_engine_volt_compiler_compiledo, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileReturn, arginfo_phalcon_mvc_view_engine_volt_compiler_compilereturn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileAutoEscape, arginfo_phalcon_mvc_view_engine_volt_compiler_compileautoescape, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileMacro, arginfo_phalcon_mvc_view_engine_volt_compiler_compilemacro, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCall, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementList, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, _compileSource, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString, arginfo_phalcon_mvc_view_engine_volt_compiler_compilestring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileFile, arginfo_phalcon_mvc_view_engine_volt_compiler_compilefile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compile, arginfo_phalcon_mvc_view_engine_volt_compiler_compile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getTemplatePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, parse, arginfo_phalcon_mvc_view_engine_volt_compiler_parse, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\View\Engine\Volt\Compiler initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Compiler){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\View\\Engine\\Volt, Compiler, mvc_view_engine_volt_compiler, phalcon_mvc_view_engine_volt_compiler_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_view"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_arrayHelpers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_view_engine_volt_compiler_ce, SL("_level"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_view_engine_volt_compiler_ce, SL("_foreachLevel"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_view_engine_volt_compiler_ce, SL("_blockLevel"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_view_engine_volt_compiler_ce, SL("_exprLevel"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_view_engine_volt_compiler_ce, SL("_extended"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_view_engine_volt_compiler_ce, SL("_autoescape"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_extendedBlocks"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_currentBlock"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_blocks"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_forElsePointers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_loopPointers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_extensions"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_functions"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_macros"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_currentPath"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_compiledTemplatePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_view_engine_volt_compiler_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\View\Engine\Volt\Compiler
 *
 * @param Phalcon\Mvc\ViewInterface $view
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, __construct){

	zval *view = NULL;

	phalcon_fetch_params(0, 0, 1, &view);
	
	if (view && Z_TYPE_P(view) == IS_OBJECT) {
		phalcon_update_property_this(this_ptr, SL("_view"), view TSRMLS_CC);
	}
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_mvc_view_exception_ce, 0);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets the compiler options
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions){

	zval *options;

	phalcon_fetch_params(0, 1, 0, &options);
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, "Options must be an array");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	
}

/**
 * Sets a single compiler option
 *
 * @param string $option
 * @param string $value
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOption){

	zval *option, *value;

	phalcon_fetch_params(0, 2, 0, &option, &value);
	
	phalcon_update_property_array(this_ptr, SL("_options"), option, value TSRMLS_CC);
	
}

/**
 * Returns a compiler's option
 *
 * @param string $option
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOption){

	zval *option, *options, *value;

	phalcon_fetch_params(0, 1, 0, &option);
	
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_fetch(&value, options, option)) {
		RETURN_ZVAL(value, 1, 0);
	}
	
	RETURN_NULL();
}

/**
 * Returns the compiler options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOptions){


	RETURN_MEMBER(this_ptr, "_options");
}

/**
 * Fires an event to registered extensions
 *
 * @param string $name
 * @param array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, fireExtensionEvent){

	zval *name, *arguments = NULL, *extensions;
	zval *call_object = NULL, *status = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &name, &arguments);
	
	if (!arguments) {
		arguments = PHALCON_GLOBAL(z_null);
	}
	
	extensions = phalcon_fetch_nproperty_this(this_ptr, SL("_extensions"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(extensions) == IS_ARRAY) { 
		zval **extension;
		HashTable *h = Z_ARRVAL_P(extensions);
		HashPosition pos;

		for (
			zend_hash_internal_pointer_reset_ex(h, &pos);
			zend_hash_get_current_data_ex(h, (void**)&extension, &pos) == SUCCESS;
			zend_hash_move_forward_ex(h, &pos)
		) {
			/** 
			 * Check if the extension implements the required event name
			 */
			if (phalcon_method_exists(*extension, name TSRMLS_CC) == SUCCESS) {
				PHALCON_INIT_NVAR(status);
				PHALCON_INIT_NVAR(call_object);
				array_init_size(call_object, 2);
				phalcon_array_append(&call_object, *extension, 0);
				phalcon_array_append(&call_object, name, 0);
				if (Z_TYPE_P(arguments) == IS_ARRAY) { 
					PHALCON_CALL_USER_FUNC_ARRAY(status, call_object, arguments);
				} else {
					PHALCON_CALL_USER_FUNC(status, call_object);
				}
	
				/** 
				 * Only string statuses mean the extension processed something
				 */
				if (Z_TYPE_P(status) == IS_STRING) {
					RETURN_CCTOR(status);
				}
			}
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Registers a Volt's extension
 *
 * @param object $extension
 * @return Phalcon\Mvc\View\Engine\Volt\Compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addExtension){

	zval *extension;

	phalcon_fetch_params(0, 1, 0, &extension);

	if (Z_TYPE_P(extension) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, "The extension is not valid");
		return;
	}
	
	/** 
	 * Initialize the extension
	 */
	if (phalcon_method_exists_ex(extension, SS("initialize") TSRMLS_CC) == SUCCESS) {
		PHALCON_MM_GROW();
		PHALCON_CALL_METHOD(NULL, extension, "initialize", this_ptr);
		PHALCON_MM_RESTORE();
	}
	
	phalcon_update_property_array_append(this_ptr, SL("_extensions"), extension TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the list of extensions registered in Volt
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getExtensions){


	RETURN_MEMBER(this_ptr, "_extensions");
}

/**
 * Register a new function in the compiler
 *
 * @param string $name
 * @param Closure|string $definition
 * @return Phalcon\Mvc\View\Engine\Volt\Compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFunction){

	zval **name, **definition;

	phalcon_fetch_params_ex(2, 0, &name, &definition);
	PHALCON_ENSURE_IS_STRING(name);

	phalcon_update_property_array(this_ptr, SL("_functions"), *name, *definition TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Register the user registered functions
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFunctions){


	RETURN_MEMBER(this_ptr, "_functions");
}

/**
 * Register a new filter in the compiler
 *
 * @param string $name
 * @param Closure|string $definition
 * @return Phalcon\Mvc\View\Engine\Volt\Compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFilter){

	zval **name, **definition;

	phalcon_fetch_params_ex(2, 0, &name, &definition);
	PHALCON_ENSURE_IS_STRING(name);
	
	phalcon_update_property_array(this_ptr, SL("_filters"), *name, *definition TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Register the user registered filters
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFilters){


	RETURN_MEMBER(this_ptr, "_filters");
}

/**
 * Set a unique prefix to be used as prefix for compiled variables
 *
 * @param string $prefix
 * @return Phalcon\Mvc\View\Engine\Volt\Compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setUniquePrefix){

	zval *prefix;

	phalcon_fetch_params(0, 1, 0, &prefix);
	
	phalcon_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Return a unique prefix to be used as prefix for compiled variables and contexts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getUniquePrefix){

	zval *prefix = NULL, *parameters, *calculated_prefix = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(prefix);
	phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * If the unique prefix is not set we use a hash using the modified Berstein
	 * algotithm
	 */
	if (!zend_is_true(prefix)) {
		zval *current_path = phalcon_fetch_nproperty_this(this_ptr, SL("_currentPath"), PH_NOISY TSRMLS_CC);
	
		PHALCON_INIT_NVAR(prefix);
		phalcon_unique_path_key(prefix, current_path TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
	}
	
	/** 
	 * The user could use a closure generator
	 */
	if (Z_TYPE_P(prefix) == IS_OBJECT) {
		if (instanceof_function(Z_OBJCE_P(prefix), zend_ce_closure TSRMLS_CC)) {
			PHALCON_INIT_VAR(parameters);
			array_init_size(parameters, 1);
			phalcon_array_append(&parameters, this_ptr, 0);
	
			PHALCON_CALL_FUNCTION(&calculated_prefix, "call_user_func_array", prefix, parameters);
			phalcon_update_property_this(this_ptr, SL("_prefix"), calculated_prefix TSRMLS_CC);
			PHALCON_CPY_WRT(prefix, calculated_prefix);
		}
	}
	
	if (Z_TYPE_P(prefix) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "The unique compilation prefix is invalid");
		return;
	}
	
	RETURN_CCTOR(prefix);
}

/**
 * Resolves attribute reading
 *
 * @param array $expr
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, attributeReader){

	zval *expr, *expr_code, *loop_context, *left, *left_type;
	zval *variable, *prefix = NULL;
	zval *is_service = NULL, *left_code = NULL, *right, *right_type;
	zval *member, *right_code = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &expr);
	
	PHALCON_INIT_VAR(expr_code);
	
	PHALCON_INIT_VAR(loop_context);
	
	PHALCON_OBS_VAR(left);
	phalcon_array_fetch_string(&left, expr, SL("left"), PH_NOISY);
	
	PHALCON_OBS_VAR(left_type);
	phalcon_array_fetch_string(&left_type, left, SL("type"), PH_NOISY);
	if (PHALCON_IS_LONG(left_type, PHVOLT_T_IDENTIFIER)) {
	
		PHALCON_OBS_VAR(variable);
		phalcon_array_fetch_string(&variable, left, SL("value"), PH_NOISY);
	
		/** 
		 * Check if the variable is the loop context
		 */
		if (PHALCON_IS_STRING(variable, "loop")) {
			zval *level = phalcon_fetch_nproperty_this(this_ptr, SL("_foreachLevel"), PH_NOISY TSRMLS_CC);
	
			PHALCON_CALL_METHOD(&prefix, this_ptr, "getuniqueprefix");
			PHALCON_SCONCAT_SVVS(expr_code, "$", prefix, level, "loop");
			phalcon_update_property_array(this_ptr, SL("_loopPointers"), level, level TSRMLS_CC);
		} else {
			/** 
			 * Services registered in the dependency injector container are availables always
			 */
			zval *dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
			if (Z_TYPE_P(dependency_injector) == IS_OBJECT) {
	
				PHALCON_CALL_METHOD(&is_service, dependency_injector, "has", variable);
				if (zend_is_true(is_service)) {
					PHALCON_SCONCAT_SV(expr_code, "$this->", variable);
				} else {
					PHALCON_SCONCAT_SV(expr_code, "$", variable);
				}
			} else {
				PHALCON_SCONCAT_SV(expr_code, "$", variable);
			}
		}
	} else {
		PHALCON_CALL_METHOD(&left_code, this_ptr, "expression", left);
		if (!PHALCON_IS_LONG(left_type, PHVOLT_T_DOT)) {
			if (!PHALCON_IS_LONG(left_type, PHVOLT_T_FCALL)) {
				PHALCON_SCONCAT_SVS(expr_code, "(", left_code, ")");
			} else {
				phalcon_concat_self(&expr_code, left_code TSRMLS_CC);
			}
		} else {
			phalcon_concat_self(&expr_code, left_code TSRMLS_CC);
		}
	}
	
	phalcon_concat_self_str(&expr_code, SL("->") TSRMLS_CC);
	
	PHALCON_OBS_VAR(right);
	phalcon_array_fetch_string(&right, expr, SL("right"), PH_NOISY);
	
	PHALCON_OBS_VAR(right_type);
	phalcon_array_fetch_string(&right_type, right, SL("type"), PH_NOISY);
	if (PHALCON_IS_LONG(right_type, PHVOLT_T_IDENTIFIER)) {
		PHALCON_OBS_VAR(member);
		phalcon_array_fetch_string(&member, right, SL("value"), PH_NOISY);
		phalcon_concat_self(&expr_code, member TSRMLS_CC);
	} else {
		PHALCON_CALL_METHOD(&right_code, this_ptr, "expression", right);
		phalcon_concat_self(&expr_code, right_code TSRMLS_CC);
	}
	
	RETURN_CCTOR(expr_code);
}

/**
 * Resolves function intermediate code into PHP function calls
 *
 * @param array $expr
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, functionCall){

	zval *expr, *code = NULL, *func_arguments = NULL, *arguments = NULL;
	zval *name_expr, *name_type, *name = NULL;
	zval *event;
	zval *line = NULL, *file = NULL, *exception_message = NULL;
	zval *block, *escaped_code = NULL, *camelized;
	zval *method, *class_name, *array_helpers = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &expr);
	
	/** 
	 * Valid filters are always arrays
	 */
	if (Z_TYPE_P(expr) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted function call");
		return;
	}
	
	PHALCON_INIT_VAR(code);
	
	if (phalcon_array_isset_string(expr, SS("arguments"))) {
		PHALCON_OBS_VAR(func_arguments);
		phalcon_array_fetch_string(&func_arguments, expr, SL("arguments"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&arguments, this_ptr, "expression", func_arguments);
	} else {
		PHALCON_INIT_VAR(func_arguments);
		PHALCON_INIT_VAR(arguments);
		ZVAL_EMPTY_STRING(arguments);
	}
	
	PHALCON_OBS_VAR(name_expr);
	phalcon_array_fetch_string(&name_expr, expr, SL("name"), PH_NOISY);
	
	PHALCON_OBS_VAR(name_type);
	phalcon_array_fetch_string(&name_type, name_expr, SL("type"), PH_NOISY);
	
	/** 
	 * Check if it's a single function
	 */
	if (PHALCON_IS_LONG(name_type, PHVOLT_T_IDENTIFIER)) {
		zval *extensions, *functions, *macros;

		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_string(&name, name_expr, SL("value"), PH_NOISY);
	
		/** 
		 * Check if any of the registered extensions provide compilation for this function
		 */
		extensions = phalcon_fetch_nproperty_this(this_ptr, SL("_extensions"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(extensions) == IS_ARRAY) { 
			zval *fire_arguments;

			PHALCON_INIT_VAR(event);
			ZVAL_STRING(event, "compileFunction", 1);
	
			PHALCON_ALLOC_GHOST_ZVAL(fire_arguments);
			array_init_size(fire_arguments, 3);
			phalcon_array_append(&fire_arguments, name, 0);
			phalcon_array_append(&fire_arguments, arguments, 0);
			phalcon_array_append(&fire_arguments, func_arguments, 0);
	
			PHALCON_CALL_METHOD(&code, this_ptr, "fireextensionevent", event, fire_arguments);
			if (Z_TYPE_P(code) == IS_STRING) {
				RETURN_CCTOR(code);
			}
		}
	
		/** 
		 * Check if it's a user defined function
		 */
		functions = phalcon_fetch_nproperty_this(this_ptr, SL("_functions"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(functions) == IS_ARRAY) { 
			zval *definition;

			if (phalcon_array_isset_fetch(&definition, functions, name)) {
				/** 
				 * Use the string as function
				 */
				if (Z_TYPE_P(definition) == IS_STRING) {
					PHALCON_CONCAT_VSVS(return_value, definition, "(", arguments, ")");
					RETURN_MM();
				}
	
				/** 
				 * Execute the function closure returning the compiled definition
				 */
				if (Z_TYPE_P(definition) == IS_OBJECT) {
					if (instanceof_function(Z_OBJCE_P(definition), zend_ce_closure TSRMLS_CC)) {
						zval *parameters;

						PHALCON_ALLOC_GHOST_ZVAL(parameters);
						array_init_size(parameters, 2);
						phalcon_array_append(&parameters, arguments, 0);
						phalcon_array_append(&parameters, func_arguments, 0);
						PHALCON_RETURN_CALL_FUNCTION("call_user_func_array", definition, parameters);
						RETURN_MM();
					}
				}
	
				PHALCON_OBS_VAR(line);
				phalcon_array_fetch_string(&line, expr, SL("line"), PH_NOISY);
	
				PHALCON_OBS_VAR(file);
				phalcon_array_fetch_string(&file, expr, SL("file"), PH_NOISY);
	
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVSVSV(exception_message, "Invalid definition for user function '", name, "' in ", file, " on line ", line);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
				return;
			}
		}
	
		macros = phalcon_fetch_nproperty_this(this_ptr, SL("_macros"), PH_NOISY TSRMLS_CC);
	
		/** 
		 * Check if the function name is a macro
		 */
		if (phalcon_array_isset(macros, name)) {
			PHALCON_CONCAT_SVSVS(return_value, "vmacro_", name, "(array(", arguments, "))");
			RETURN_MM();
		}
	
		/** 
		 * This function includes the previous rendering stage
		 */
		if (PHALCON_IS_STRING(name, "get_content") || PHALCON_IS_STRING(name, "content")) {
			RETURN_MM_STRING("$this->getContent()", 1);
		}
	
		/** 
		 * This function includes views of volt or others template engines dynamically
		 */
		if (PHALCON_IS_STRING(name, "partial")) {
			PHALCON_CONCAT_SVS(return_value, "$this->partial(", arguments, ")");
			RETURN_MM();
		}
	
		/** 
		 * This function embeds the parent block in the current block
		 */
		if (PHALCON_IS_STRING(name, "super")) {
			zval *extended_blocks = phalcon_fetch_nproperty_this(this_ptr, SL("_extendedBlocks"), PH_NOISY TSRMLS_CC);
			if (Z_TYPE_P(extended_blocks) == IS_ARRAY) { 
				zval *current_block = phalcon_fetch_nproperty_this(this_ptr, SL("_currentBlock"), PH_NOISY TSRMLS_CC);
				if (phalcon_array_isset(extended_blocks, current_block)) {
					zval *expr_level = phalcon_fetch_nproperty_this(this_ptr, SL("_exprLevel"), PH_NOISY TSRMLS_CC);
	
					PHALCON_OBS_VAR(block);
					phalcon_array_fetch(&block, extended_blocks, current_block, PH_NOISY);
					if (Z_TYPE_P(block) == IS_ARRAY) { 
	
						PHALCON_CALL_METHOD(&code, this_ptr, "_statementlistorextends", block);
						if (PHALCON_IS_LONG(expr_level, 1)) {
							PHALCON_CPY_WRT(escaped_code, code);
						} else {
							PHALCON_INIT_NVAR(escaped_code);
							phalcon_addslashes(escaped_code, code TSRMLS_CC);
						}
					} else {
						if (PHALCON_IS_LONG(expr_level, 1)) {
							PHALCON_CPY_WRT(escaped_code, block);
						} else {
							PHALCON_INIT_NVAR(escaped_code);
							phalcon_addslashes(escaped_code, block TSRMLS_CC);
						}
					}
	
					/** 
					 * If the super() is the first level we don't escape it
					 */
					if (PHALCON_IS_LONG(expr_level, 1)) {
						RETURN_CCTOR(escaped_code);
					}
	
					PHALCON_CONCAT_SVS(return_value, "'", escaped_code, "'");
	
					RETURN_MM();
				}
			}
	
			RETURN_MM_STRING("''", 1);
		}
	
		PHALCON_INIT_VAR(camelized);
		phalcon_camelize(camelized, name);
	
		PHALCON_INIT_VAR(method);
		phalcon_lcfirst(method, camelized);
	
		PHALCON_INIT_VAR(class_name);
		ZVAL_STRING(class_name, "Phalcon\\Tag", 1);
	
		/** 
		 * Check if it's a method in Phalcon\Tag
		 */
		if (phalcon_method_exists(class_name, method TSRMLS_CC) == SUCCESS) {

			PHALCON_OBS_VAR(array_helpers);
			phalcon_read_property_this(&array_helpers, this_ptr, SL("_arrayHelpers"), PH_NOISY TSRMLS_CC);
			if (Z_TYPE_P(array_helpers) != IS_ARRAY) { 
				PHALCON_INIT_NVAR(array_helpers);
				array_init_size(array_helpers, 16);
				add_assoc_bool_ex(array_helpers, SS("link_to"), 1);
				add_assoc_bool_ex(array_helpers, SS("image"), 1);
				add_assoc_bool_ex(array_helpers, SS("form"), 1);
				add_assoc_bool_ex(array_helpers, SS("select"), 1);
				add_assoc_bool_ex(array_helpers, SS("select_static"), 1);
				add_assoc_bool_ex(array_helpers, SS("submit_button"), 1);
				add_assoc_bool_ex(array_helpers, SS("radio_field"), 1);
				add_assoc_bool_ex(array_helpers, SS("check_field"), 1);
				add_assoc_bool_ex(array_helpers, SS("file_field"), 1);
				add_assoc_bool_ex(array_helpers, SS("hidden_field"), 1);
				add_assoc_bool_ex(array_helpers, SS("password_field"), 1);
				add_assoc_bool_ex(array_helpers, SS("text_area"), 1);
				add_assoc_bool_ex(array_helpers, SS("text_field"), 1);
				add_assoc_bool_ex(array_helpers, SS("date_field"), 1);
				add_assoc_bool_ex(array_helpers, SS("numeric_field"), 1);
				add_assoc_bool_ex(array_helpers, SS("email_field"), 1);
				phalcon_update_property_this(this_ptr, SL("_arrayHelpers"), array_helpers TSRMLS_CC);
			}
	
			if (phalcon_array_isset(array_helpers, name)) {
				PHALCON_CONCAT_SVSVS(return_value, "$this->tag->", method, "(array(", arguments, "))");
				RETURN_MM();
			}
	
			PHALCON_CONCAT_SVSVS(return_value, "$this->tag->", method, "(", arguments, ")");
	
			RETURN_MM();
		}
	
		/** 
		 * Get a dynamic URL
		 */
		if (PHALCON_IS_STRING(name, "url")) {
			PHALCON_CONCAT_SVS(return_value, "$this->url->get(", arguments, ")");
			RETURN_MM();
		}
	
		/** 
		 * Get a static URL
		 */
		if (PHALCON_IS_STRING(name, "static_url")) {
			PHALCON_CONCAT_SVS(return_value, "$this->url->getStatic(", arguments, ")");
			RETURN_MM();
		}
	
		if (PHALCON_IS_STRING(name, "date")) {
			PHALCON_CONCAT_SVS(return_value, "date(", arguments, ")");
			RETURN_MM();
		}
	
		if (PHALCON_IS_STRING(name, "time")) {
			RETVAL_STRING("time()", 1);
			RETURN_MM();
		}
	
		if (PHALCON_IS_STRING(name, "dump")) {
			PHALCON_CONCAT_SVS(return_value, "var_dump(", arguments, ")");
			RETURN_MM();
		}
	
		if (PHALCON_IS_STRING(name, "version")) {
			RETURN_MM_STRING("Phalcon\\Version::get()", 1);
		}
	
		if (PHALCON_IS_STRING(name, "version_id")) {
			RETURN_MM_STRING("Phalcon\\Version::getId()", 1);
		}
	
		/** 
		 * Read PHP constants in templates
		 */
		if (PHALCON_IS_STRING(name, "constant")) {
			PHALCON_CONCAT_SVS(return_value, "constant(", arguments, ")");
			RETURN_MM();
		}
	
		/** 
		 * The function doesn't exist throw an exception
		 */
		PHALCON_OBS_NVAR(line);
		phalcon_array_fetch_string(&line, expr, SL("line"), PH_NOISY);
	
		PHALCON_OBS_NVAR(file);
		phalcon_array_fetch_string(&file, expr, SL("file"), PH_NOISY);
	
		PHALCON_INIT_NVAR(exception_message);
		PHALCON_CONCAT_SVSVSV(exception_message, "Undefined function '", name, "' in ", file, " on line ", line);
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
		return;
	}
	
	PHALCON_CALL_METHOD(&name, this_ptr, "expression", name_expr);
	PHALCON_CONCAT_VSVS(return_value, name, "(", arguments, ")");
	
	RETURN_MM();
}

/**
 * Resolves filter intermediate code into a valid PHP expression
 *
 * @param array $test
 * @param string $left
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveTest){

	zval *test, *left, *type, *name = NULL, *test_name, *test_arguments = NULL;
	zval *arguments = NULL, *right_code = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &test, &left);
	
	/** 
	 * Valid tests are always arrays
	 */
	if (Z_TYPE_P(test) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted test");
		return;
	}
	
	PHALCON_OBS_VAR(type);
	phalcon_array_fetch_string(&type, test, SL("type"), PH_NOISY);
	
	/** 
	 * Check if right part is a single identifier
	 */
	if (PHALCON_IS_LONG(type, PHVOLT_T_IDENTIFIER)) {
	
		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_string(&name, test, SL("value"), PH_NOISY);
	
		/** 
		 * Empty uses the PHP's empty operator
		 */
		if (PHALCON_IS_STRING(name, "empty")) {
			PHALCON_CONCAT_SVS(return_value, "empty(", left, ")");
			RETURN_MM();
		}
	
		/** 
		 * Check if a value is even
		 */
		if (PHALCON_IS_STRING(name, "even")) {
			PHALCON_CONCAT_SVS(return_value, "(((", left, ") % 2) == 0)");
			RETURN_MM();
		}
	
		/** 
		 * Check if a value is odd
		 */
		if (PHALCON_IS_STRING(name, "odd")) {
			PHALCON_CONCAT_SVS(return_value, "(((", left, ") % 2) != 0)");
			RETURN_MM();
		}
	
		/** 
		 * Check if a value is numeric
		 */
		if (PHALCON_IS_STRING(name, "numeric")) {
			PHALCON_CONCAT_SVS(return_value, "is_numeric(", left, ")");
			RETURN_MM();
		}
	
		/** 
		 * Check if a value is scalar
		 */
		if (PHALCON_IS_STRING(name, "scalar")) {
			PHALCON_CONCAT_SVS(return_value, "is_scalar(", left, ")");
			RETURN_MM();
		}
	
		/** 
		 * Check if a value is iterable
		 */
		if (PHALCON_IS_STRING(name, "iterable")) {
			PHALCON_CONCAT_SVSVS(return_value, "(is_array(", left, ") || (", left, ") instanceof Traversable)");
			RETURN_MM();
		}
	}
	
	/** 
	 * Check if right part is a function call
	 */
	if (PHALCON_IS_LONG(type, PHVOLT_T_FCALL)) {
	
		PHALCON_OBS_VAR(test_name);
		phalcon_array_fetch_string(&test_name, test, SL("name"), PH_NOISY);
		if (phalcon_array_isset_string(test_name, SS("value"))) {
	
			/** 
			 * Checks if a value is divisible by other
			 */
			PHALCON_OBS_NVAR(name);
			phalcon_array_fetch_string(&name, test_name, SL("value"), PH_NOISY);
			if (PHALCON_IS_STRING(name, "divisibleby")) {
				PHALCON_OBS_VAR(test_arguments);
				phalcon_array_fetch_string(&test_arguments, test, SL("arguments"), PH_NOISY);
	
				PHALCON_CALL_METHOD(&arguments, this_ptr, "expression", test_arguments);
				PHALCON_CONCAT_SVSVS(return_value, "(((", left, ") % (", arguments, ")) == 0)");
				RETURN_MM();
			}
	
			/** 
			 * Checks if a value is equals to other
			 */
			if (PHALCON_IS_STRING(name, "sameas")) {
				PHALCON_OBS_NVAR(test_arguments);
				phalcon_array_fetch_string(&test_arguments, test, SL("arguments"), PH_NOISY);
	
				PHALCON_CALL_METHOD(&arguments, this_ptr, "expression", test_arguments);
				PHALCON_CONCAT_SVSVS(return_value, "(", left, ") === (", arguments, ")");
				RETURN_MM();
			}
	
			/** 
			 * Checks if a variable match a type
			 */
			if (PHALCON_IS_STRING(name, "type")) {
				PHALCON_OBS_NVAR(test_arguments);
				phalcon_array_fetch_string(&test_arguments, test, SL("arguments"), PH_NOISY);
	
				PHALCON_CALL_METHOD(&arguments, this_ptr, "expression", test_arguments);
				PHALCON_CONCAT_SVSVS(return_value, "gettype(", left, ") === (", arguments, ")");
				RETURN_MM();
			}
		}
	}
	
	/** 
	 * Fall back to the equals operator
	 */
	PHALCON_CALL_METHOD(&right_code, this_ptr, "expression", test);
	PHALCON_CONCAT_VSV(return_value, left, " == ", right_code);
	
	RETURN_MM();
}

/**
 * Resolves filter intermediate code into PHP function calls
 *
 * @param array $filter
 * @param string $left
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveFilter){

	zval *filter, *left, *code = NULL, *type, *name = NULL, *function_name;
	zval *line = NULL, *file = NULL, *exception_message = NULL, *func_arguments = NULL;
	zval *arguments = NULL, *resolved_expr, *resolved_param;
	zval *extensions, *event, *fire_arguments, *filters;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &filter, &left);
	
	/** 
	 * Valid filters are always arrays
	 */
	if (Z_TYPE_P(filter) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted filter");
		return;
	}
	
	PHALCON_INIT_VAR(code);
	
	PHALCON_OBS_VAR(type);
	phalcon_array_fetch_string(&type, filter, SL("type"), PH_NOISY);
	
	/** 
	 * Check if the filter is a single identifier
	 */
	if (PHALCON_IS_LONG(type, PHVOLT_T_IDENTIFIER)) {
		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_string(&name, filter, SL("value"), PH_NOISY);
	} else if (PHALCON_IS_LONG(type, PHVOLT_T_FCALL)) {
		PHALCON_OBS_VAR(function_name);
		phalcon_array_fetch_string(&function_name, filter, SL("name"), PH_NOISY);

		PHALCON_OBS_NVAR(name);
		phalcon_array_fetch_string(&name, function_name, SL("value"), PH_NOISY);
	} else {
		/**
		 * Unknown filter throw an exception
		 */
		PHALCON_OBS_VAR(line);
		phalcon_array_fetch_string(&line, filter, SL("line"), PH_NOISY);

		PHALCON_OBS_VAR(file);
		phalcon_array_fetch_string(&file, filter, SL("file"), PH_NOISY);

		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVSV(exception_message, "Unknown filter type in ", file, " on line ", line);
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
		return;
	}
	
	PHALCON_INIT_VAR(func_arguments);
	
	PHALCON_INIT_VAR(arguments);
	
	/** 
	 * Resolve arguments
	 */
	if (phalcon_array_isset_string(filter, SS("arguments"))) {
	
		PHALCON_OBS_NVAR(file);
		phalcon_array_fetch_string(&file, filter, SL("file"), PH_NOISY);
	
		PHALCON_OBS_NVAR(line);
		phalcon_array_fetch_string(&line, filter, SL("line"), PH_NOISY);
	
		PHALCON_OBS_NVAR(func_arguments);
		phalcon_array_fetch_string(&func_arguments, filter, SL("arguments"), PH_NOISY);
	
		/** 
		 * 'default' filter is not the first argument, improve this!
		 */
		if (!PHALCON_IS_STRING(name, "default")) {
			PHALCON_INIT_VAR(resolved_expr);
			array_init_size(resolved_expr, 4);
			add_assoc_long_ex(resolved_expr, ISS(type), PHVOLT_T_RESOLVED_EXPR);
			phalcon_array_update_string(&resolved_expr, ISL(value), left, PH_COPY);
			phalcon_array_update_string(&resolved_expr, ISL(file), file, PH_COPY);
			phalcon_array_update_string(&resolved_expr, ISL(line), line, PH_COPY);
	
			PHALCON_INIT_VAR(resolved_param);
			array_init_size(resolved_param, 3);
			phalcon_array_update_string(&resolved_param, ISL(expr), resolved_expr, PH_COPY);
			phalcon_array_update_string(&resolved_param, ISL(file), file, PH_COPY);
			phalcon_array_update_string(&resolved_param, ISL(line), line, PH_COPY);
	
			phalcon_array_unshift(func_arguments, resolved_param TSRMLS_CC);
		}
	
		PHALCON_CALL_METHOD(&arguments, this_ptr, "expression", func_arguments);
	} else {
		PHALCON_CPY_WRT(arguments, left);
	}
	
	/** 
	 * Check if any of the registered extensions provide compilation for this filter
	 */
	extensions = phalcon_fetch_nproperty_this(this_ptr, SL("_extensions"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(extensions) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(event);
		ZVAL_STRING(event, "compileFilter", 1);
	
		PHALCON_INIT_VAR(fire_arguments);
		array_init_size(fire_arguments, 3);
		phalcon_array_append(&fire_arguments, name, 0);
		phalcon_array_append(&fire_arguments, arguments, 0);
		phalcon_array_append(&fire_arguments, func_arguments, 0);
	
		PHALCON_CALL_METHOD(&code, this_ptr, "fireextensionevent", event, fire_arguments);
		if (Z_TYPE_P(code) == IS_STRING) {
			RETURN_CCTOR(code);
		}
	}
	
	/** 
	 * Check if it's a user defined filter
	 */
	filters = phalcon_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(filters) == IS_ARRAY) { 
		zval *definition;

		if (phalcon_array_isset_fetch(&definition, filters, name)) {
			/** 
			 * The definition is a string
			 */
			if (Z_TYPE_P(definition) == IS_STRING) {
				PHALCON_CONCAT_VSVS(return_value, definition, "(", arguments, ")");
				RETURN_MM();
			}
	
			/** 
			 * The definition is a closure
			 */
			if (Z_TYPE_P(definition) == IS_OBJECT) {
				if (instanceof_function(Z_OBJCE_P(definition), zend_ce_closure TSRMLS_CC)) {
					zval *parameters;

					PHALCON_ALLOC_GHOST_ZVAL(parameters);
					array_init_size(parameters, 2);
					phalcon_array_append(&parameters, arguments, 0);
					phalcon_array_append(&parameters, func_arguments, 0);
					PHALCON_RETURN_CALL_FUNCTION("call_user_func_array", definition, parameters);
					RETURN_MM();
				}
			}
	
			/** 
			 * Invalid filter definition throw an exception
			 */
			PHALCON_OBS_NVAR(line);
			phalcon_array_fetch_string(&line, filter, SL("line"), PH_NOISY);
	
			PHALCON_OBS_NVAR(file);
			phalcon_array_fetch_string(&file, filter, SL("file"), PH_NOISY);
	
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVSVSV(exception_message, "Invalid definition for user filter '", name, "' in ", file, " on line ", line);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
			return;
		}
	}
	
	/** 
	 * 'length' uses the length method implemented in the Volt adapter
	 */
	if (PHALCON_IS_STRING(name, "length")) {
		PHALCON_CONCAT_SVS(return_value, "$this->length(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'e' filter uses the escaper component
	 */
	if (PHALCON_IS_STRING(name, "e")) {
		PHALCON_CONCAT_SVS(return_value, "$this->escaper->escapeHtml(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'escape' filter uses the escaper component
	 */
	if (PHALCON_IS_STRING(name, "escape")) {
		PHALCON_CONCAT_SVS(return_value, "$this->escaper->escapeHtml(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'escapecss' filter uses the escaper component to filter css
	 */
	if (PHALCON_IS_STRING(name, "escape_css")) {
		PHALCON_CONCAT_SVS(return_value, "$this->escaper->escapeCss(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'escapejs' filter uses the escaper component to escape javascript
	 */
	if (PHALCON_IS_STRING(name, "escape_js")) {
		PHALCON_CONCAT_SVS(return_value, "$this->escaper->escapeJs(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'escapeattr' filter uses the escaper component to escape html attributes
	 */
	if (PHALCON_IS_STRING(name, "escape_attr")) {
		PHALCON_CONCAT_SVS(return_value, "$this->escaper->escapeHtmlAttr(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'trim' calls the "trim" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "trim")) {
		PHALCON_CONCAT_SVS(return_value, "trim(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'left_trim' calls the "ltrim" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "left_trim")) {
		PHALCON_CONCAT_SVS(return_value, "ltrim(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'right_trim' calls the "rtrim" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "right_trim")) {
		PHALCON_CONCAT_SVS(return_value, "rtrim(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'striptags' calls the "strip_tags" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "striptags")) {
		PHALCON_CONCAT_SVS(return_value, "strip_tags(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'urlencode' calls the "urlencode" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "url_encode")) {
		PHALCON_CONCAT_SVS(return_value, "urlencode(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'slashes' calls the "addslashes" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "slashes")) {
		PHALCON_CONCAT_SVS(return_value, "addslashes(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'stripslashes' calls the "stripslashes" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "stripslashes")) {
		PHALCON_CONCAT_SVS(return_value, "stripslashes(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'nl2br' calls the "nl2br" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "nl2br")) {
		PHALCON_CONCAT_SVS(return_value, "nl2br(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'keys' uses calls the "array_keys" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "keys")) {
		PHALCON_CONCAT_SVS(return_value, "array_keys(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'join' uses calls the "join" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "join")) {
		PHALCON_CONCAT_SVS(return_value, "join(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'lowercase' calls the "strtolower" function or "mb_strtolower" if the mbstring
	 * extension is loaded
	 */
	if (PHALCON_IS_STRING(name, "lowercase")) {
		PHALCON_CONCAT_SVS(return_value, "Phalcon\\Text::lower(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'lowercase' calls the "strtolower" function or "mb_strtolower" if the mbstring
	 * extension is loaded
	 */
	if (PHALCON_IS_STRING(name, "lower")) {
		PHALCON_CONCAT_SVS(return_value, "Phalcon\\Text::lower(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'uppercase' calls the "strtouppwer" function or "mb_strtoupper" if the mbstring
	 * extension is loaded
	 */
	if (PHALCON_IS_STRING(name, "uppercase")) {
		PHALCON_CONCAT_SVS(return_value, "Phalcon\\Text::upper(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'uppercase' calls the "strtouppwer" function or "mb_strtoupper" if the mbstring
	 * extension is loaded
	 */
	if (PHALCON_IS_STRING(name, "upper")) {
		PHALCON_CONCAT_SVS(return_value, "Phalcon\\Text::upper(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'capitalize' filter calls 'ucwords'
	 */
	if (PHALCON_IS_STRING(name, "capitalize")) {
		PHALCON_CONCAT_SVS(return_value, "ucwords(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'sort' calls 'sort' method in the engine adapter
	 */
	if (PHALCON_IS_STRING(name, "sort")) {
		PHALCON_CONCAT_SVS(return_value, "$this->sort(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'json_encode' calls the "json_encode" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "json_encode")) {
		PHALCON_CONCAT_SVS(return_value, "json_encode(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'json_decode' calls the "json_decode" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "json_decode")) {
		PHALCON_CONCAT_SVS(return_value, "json_decode(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'format' calls the "sprintf" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "format")) {
		PHALCON_CONCAT_SVS(return_value, "sprintf(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'abs' calls the "abs" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "abs")) {
		PHALCON_CONCAT_SVS(return_value, "abs(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'slice' slices string/arrays/traversable objects
	 */
	if (PHALCON_IS_STRING(name, "slice")) {
		PHALCON_CONCAT_SVS(return_value, "$this->slice(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * 'default' checks if a variable is empty
	 */
	if (PHALCON_IS_STRING(name, "default")) {
		PHALCON_CONCAT_SVSVSVS(return_value, "(empty(", left, ") ? (", arguments, ") : (", left, "))");
		RETURN_MM();
	}
	
	/** 
	 * This function uses mbstring or iconv to convert strings from one chartset to
	 * another
	 */
	if (PHALCON_IS_STRING(name, "convert_encoding")) {
		PHALCON_CONCAT_SVS(return_value, "$this->convertEncoding(", arguments, ")");
		RETURN_MM();
	}
	
	/** 
	 * Unknown filter throw an exception
	 */
	PHALCON_OBS_NVAR(line);
	phalcon_array_fetch_string(&line, filter, SL("line"), PH_NOISY);
	
	PHALCON_OBS_NVAR(file);
	phalcon_array_fetch_string(&file, filter, SL("file"), PH_NOISY);
	
	PHALCON_INIT_NVAR(exception_message);
	PHALCON_CONCAT_SVSVSV(exception_message, "Unknown filter \"", name, "\" in ", file, " on line ", line);
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
	return;
}

/**
 * Resolves an expression node in an AST volt tree
 *
 * @param array $expr
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, expression){

	zval *expr, *expr_code = NULL, *extensions, *event = NULL, *fire_arguments = NULL;
	zval *items = NULL, *single_expr = NULL, *single_expr_expr = NULL;
	zval *single_expr_code = NULL, *parameter = NULL, *type = NULL;
	zval *left = NULL, *left_code = NULL, *right_code = NULL, *right = NULL, *value = NULL;
	zval *single_quote = NULL, *escaped_quoute = NULL, *escaped_string = NULL;
	zval *start_code = NULL, *end_code = NULL, *ternary = NULL;
	zval *ternary_code = NULL, *line = NULL, *file = NULL, *exception_message = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &expr);
	
	/** 
	 * Valid expressions are always arrays
	 */
	if (Z_TYPE_P(expr) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted expression");
		return;
	}
	
	PHALCON_INIT_VAR(expr_code);
	phalcon_property_incr(this_ptr, SL("_exprLevel") TSRMLS_CC);
	
	/** 
	 * Check if any of the registered extensions provide compilation for this
	 * expression
	 */
	extensions = phalcon_fetch_nproperty_this(this_ptr, SL("_extensions"), PH_NOISY TSRMLS_CC);
	
	while (1) {
	
		if (Z_TYPE_P(extensions) == IS_ARRAY) { 
	
			PHALCON_INIT_NVAR(event);
			ZVAL_STRING(event, "resolveExpression", 1);
	
			PHALCON_INIT_NVAR(fire_arguments);
			array_init_size(fire_arguments, 1);
			phalcon_array_append(&fire_arguments, expr, 0);
	
			PHALCON_CALL_METHOD(&expr_code, this_ptr, "fireextensionevent", event, fire_arguments);
			if (Z_TYPE_P(expr_code) == IS_STRING) {
				break;
			}
		}

		if (!phalcon_array_isset_string_fetch(&type, expr, SS("type"))) {
	
			PHALCON_INIT_NVAR(items);
			array_init(items);
	
			phalcon_is_iterable(expr, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
				zval *name;

				PHALCON_GET_HVALUE(single_expr);
	
				PHALCON_OBS_NVAR(single_expr_expr);
				phalcon_array_fetch_string(&single_expr_expr, single_expr, SL("expr"), PH_NOISY);
	
				PHALCON_CALL_METHOD(&single_expr_code, this_ptr, "expression", single_expr_expr);
				if (phalcon_array_isset_string_fetch(&name, single_expr, SS("name"))) {
					PHALCON_INIT_NVAR(parameter);
					PHALCON_CONCAT_SVSV(parameter, "'", name, "' => ", single_expr_code);
					phalcon_array_append(&items, parameter, PH_SEPARATE);
				} else {
					phalcon_array_append(&items, single_expr_code, PH_SEPARATE);
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
			PHALCON_INIT_NVAR(expr_code);
			phalcon_fast_join_str(expr_code, SL(", "), items TSRMLS_CC);
			break;
		}
	
		/** 
		 * Attribute reading needs special handling
		 */
		if (PHALCON_IS_LONG(type, PHVOLT_T_DOT)) {
			PHALCON_CALL_METHOD(&expr_code, this_ptr, "attributereader", expr);
			break;
		}
	
		/** 
		 * Left part of expression is always resolved
		 */
		PHALCON_INIT_NVAR(left_code);
		if (phalcon_array_isset_string_fetch(&left, expr, SS("left"))) {
			PHALCON_CALL_METHOD(&left_code, this_ptr, "expression", left);
		}
	
		/** 
		 * Operator 'is' also needs special handling
		 */
		if (PHALCON_IS_LONG(type, PHVOLT_T_IS)) {
			PHALCON_OBS_NVAR(right_code);
			phalcon_array_fetch_string(&right_code, expr, SL("right"), PH_NOISY);
	
			PHALCON_CALL_METHOD(&expr_code, this_ptr, "resolvetest", right_code, left_code);
			break;
		}
	
		/** 
		 * We don't resolve the right expression for filters
		 */
		if (PHALCON_IS_LONG(type, 124)) { /* FIXME there is no constant equal to 124 in scanner.h */
			PHALCON_OBS_NVAR(right_code);
			phalcon_array_fetch_string(&right_code, expr, SL("right"), PH_NOISY);
	
			PHALCON_CALL_METHOD(&expr_code, this_ptr, "resolvefilter", right_code, left_code);
			break;
		}
	
		/** 
		 * From here, right part of expression is always resolved
		 */
		PHALCON_INIT_NVAR(right_code);
		if (phalcon_array_isset_string_fetch(&right, expr, SS("right"))) {
			PHALCON_CALL_METHOD(&right_code, this_ptr, "expression", right);
		}
	
		PHALCON_INIT_NVAR(expr_code);
		switch (phalcon_get_intval(type)) {
	
			case PHVOLT_T_NOT:
				PHALCON_CONCAT_SV(expr_code, "!", right_code);
				break;
	
			case PHVOLT_T_MUL:
				PHALCON_CONCAT_VSV(expr_code, left_code, " * ", right_code);
				break;
	
			case PHVOLT_T_ADD:
				PHALCON_CONCAT_VSV(expr_code, left_code, " + ", right_code);
				break;
	
			case PHVOLT_T_SUB:
				PHALCON_CONCAT_VSV(expr_code, left_code, " - ", right_code);
				break;
	
			case PHVOLT_T_DIV:
				PHALCON_CONCAT_VSV(expr_code, left_code, " / ", right_code);
				break;
	
			case PHVOLT_T_MOD:
				PHALCON_CONCAT_VSV(expr_code, left_code, " % ", right_code);
				break;
	
			case PHVOLT_T_LESS:
				PHALCON_CONCAT_VSV(expr_code, left_code, " < ", right_code);
				break;
	
			case PHVOLT_T_ASSIGN:
				PHALCON_CONCAT_VSV(expr_code, left_code, " > ", right_code); /* FIXME really >? */
				break;
	
			case PHVOLT_T_GREATER:
				PHALCON_CONCAT_VSV(expr_code, left_code, " > ", right_code);
				break;
	
			case 126: /* FIXME no such constant*/
				PHALCON_CONCAT_VSV(expr_code, left_code, " . ", right_code);
				break;
	
			case PHVOLT_T_POW:
				PHALCON_CONCAT_SVSVS(expr_code, "pow(", left_code, ", ", right_code, ")");
				break;
	
			case PHVOLT_T_ARRAY:
				if (phalcon_array_isset_string(expr, SS("left"))) {
					PHALCON_CONCAT_SVS(expr_code, "array(", left_code, ")");
				} else {
					ZVAL_STRING(expr_code, "array()", 1);
				}
				break;
	
			case PHVOLT_T_INTEGER:
			case PHVOLT_T_DOUBLE:
			case PHVOLT_T_RESOLVED_EXPR:
				PHALCON_OBS_NVAR(expr_code);
				phalcon_array_fetch_string(&expr_code, expr, SL("value"), PH_NOISY);
				break;
	
			case PHVOLT_T_STRING:
				PHALCON_OBS_NVAR(value);
				phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY);
	
				PHALCON_INIT_NVAR(single_quote);
				ZVAL_STRING(single_quote, "'", 1);
	
				PHALCON_INIT_NVAR(escaped_quoute);
				ZVAL_STRING(escaped_quoute, "\\'", 1);
	
				PHALCON_INIT_NVAR(escaped_string);
				phalcon_fast_str_replace(escaped_string, single_quote, escaped_quoute, value);
	
				PHALCON_CONCAT_SVS(expr_code, "'", escaped_string, "'");
				break;
	
			case PHVOLT_T_NULL:
				ZVAL_STRING(expr_code, "null", 1);
				break;
	
			case PHVOLT_T_FALSE:
				ZVAL_STRING(expr_code, "false", 1);
				break;
	
			case PHVOLT_T_TRUE:
				ZVAL_STRING(expr_code, "true", 1);
				break;
	
			case PHVOLT_T_IDENTIFIER:
				PHALCON_OBS_NVAR(value);
				phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY);
	
				PHALCON_CONCAT_SV(expr_code, "$", value);
				break;
	
			case PHVOLT_T_AND:
				PHALCON_CONCAT_VSV(expr_code, left_code, " && ", right_code);
				break;
	
			case PHVOLT_T_OR:
				PHALCON_CONCAT_VSV(expr_code, left_code, " || ", right_code);
				break;
	
			case PHVOLT_T_LESSEQUAL:
				PHALCON_CONCAT_VSV(expr_code, left_code, " <= ", right_code);
				break;
	
			case PHVOLT_T_GREATEREQUAL:
				PHALCON_CONCAT_VSV(expr_code, left_code, " >= ", right_code);
				break;
	
			case PHVOLT_T_EQUALS:
				PHALCON_CONCAT_VSV(expr_code, left_code, " == ", right_code);
				break;
	
			case PHVOLT_T_NOTEQUALS:
				PHALCON_CONCAT_VSV(expr_code, left_code, " != ", right_code);
				break;
	
			case PHVOLT_T_IDENTICAL:
				PHALCON_CONCAT_VSV(expr_code, left_code, " === ", right_code);
				break;
	
			case PHVOLT_T_NOTIDENTICAL:
				PHALCON_CONCAT_VSV(expr_code, left_code, " !== ", right_code);
				break;
	
			case PHVOLT_T_RANGE:
				PHALCON_CONCAT_SVSVS(expr_code, "range(", left_code, ", ", right_code, ")");
				break;
	
			case PHVOLT_T_FCALL:
				PHALCON_CALL_METHOD(&expr_code, this_ptr, "functioncall", expr);
				break;
	
			case PHVOLT_T_ENCLOSED:
				PHALCON_CONCAT_SVS(expr_code, "(", left_code, ")");
				break;
	
			case PHVOLT_T_ARRAYACCESS:
				PHALCON_CONCAT_VSVS(expr_code, left_code, "[", right_code, "]");
				break;
	
			case PHVOLT_T_SLICE: {
				zval *start, *end;
				/** 
				 * Evaluate the start part of the slice
				 */
				PHALCON_INIT_NVAR(start_code);
				if (phalcon_array_isset_string_fetch(&start, expr, SS("start"))) {
					PHALCON_CALL_METHOD(&start_code, this_ptr, "expression", start);
				} else {
					ZVAL_STRING(start_code, "null", 1);
				}
	
				/** 
				 * Evaluate the end part of the slice
				 */
				PHALCON_INIT_NVAR(end_code);
				if (phalcon_array_isset_string_fetch(&end, expr, SS("end"))) {
					PHALCON_CALL_METHOD(&end_code, this_ptr, "expression", end);
				} else {
					ZVAL_STRING(end_code, "null", 1);
				}
	
				PHALCON_CONCAT_SVSVSVS(expr_code, "$this->slice(", left_code, ", ", start_code, ", ", end_code, ")");
				break;
			}
	
			case PHVOLT_T_NOT_ISSET:
				PHALCON_CONCAT_SVS(expr_code, "!isset(", left_code, ")");
				break;
	
			case PHVOLT_T_ISSET:
				PHALCON_CONCAT_SVS(expr_code, "isset(", left_code, ")");
				break;
	
			case PHVOLT_T_IN:
				PHALCON_CONCAT_SVSVS(expr_code, "$this->isIncluded(", left_code, ", ", right_code, ")");
				break;
	
			case PHVOLT_T_NOT_IN:
				PHALCON_CONCAT_SVSVS(expr_code, "!$this->isIncluded(", left_code, ", ", right_code, ")");
				break;
	
			case PHVOLT_T_TERNARY:
				PHALCON_OBS_NVAR(ternary);
				phalcon_array_fetch_string(&ternary, expr, SL("ternary"), PH_NOISY);
	
				PHALCON_CALL_METHOD(&ternary_code, this_ptr, "expression", ternary);
	
				PHALCON_CONCAT_SVSVSVS(expr_code, "(", ternary_code, " ? ", left_code, " : ", right_code, ")");
				break;
	
			case PHVOLT_T_MINUS:
				PHALCON_CONCAT_SV(expr_code, "-", right_code);
				break;
	
			case PHVOLT_T_PLUS:
				PHALCON_CONCAT_SV(expr_code, "+", right_code);
				break;
	
			default:
				PHALCON_OBS_NVAR(line);
				phalcon_array_fetch_string(&line, expr, SL("line"), PH_NOISY);
	
				PHALCON_OBS_NVAR(file);
				phalcon_array_fetch_string(&file, expr, SL("file"), PH_NOISY);
	
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVSVSV(exception_message, "Unknown expression ", type, " in ", file, " on line ", line);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
				return;
	
		}
		break;
	}

	phalcon_property_decr(this_ptr, SL("_exprLevel") TSRMLS_CC);
	RETURN_CCTOR(expr_code);
}

/**
 * Compiles a block of statements
 *
 * @param array $statements
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementListOrExtends){

	zval *statements, *is_statement_list = NULL, *statement = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &statements);
	
	/** 
	 * Resolve the statement list as normal
	 */
	if (Z_TYPE_P(statements) != IS_ARRAY) { 
		RETURN_CCTOR(statements);
	}
	
	/** 
	 * If all elements in the statement list are arrays we resolve this as a
	 * statementList
	 */
	PHALCON_INIT_VAR(is_statement_list);
	ZVAL_TRUE(is_statement_list);
	if (!phalcon_array_isset_string(statements, SS("type"))) {
	
		phalcon_is_iterable(statements, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(statement);
	
			if (Z_TYPE_P(statement) != IS_ARRAY) { 
				ZVAL_FALSE(is_statement_list);
				break;
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	/** 
	 * Resolve the statement list as normal
	 */
	if (PHALCON_IS_TRUE(is_statement_list)) {
		PHALCON_RETURN_CALL_METHOD(this_ptr, "_statementlist", statements);
		RETURN_MM();
	}
	
	/** 
	 * Is an array but not a statement list?
	 */
	RETURN_CCTOR(statements);
}

/**
 * Compiles a 'foreach' intermediate code representation into plain PHP code
 *
 * @param array $statement
 * @param boolean $extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForeach){

	zval *statement, *extends_mode = NULL, *compilation;
	zval *prefix = NULL, *level, *prefix_level, *expr, *expr_code = NULL;
	zval *block_statements, *for_else = NULL, *bstatement = NULL;
	zval *type = NULL, *code = NULL, *loop_context, *iterator = NULL, *variable;
	zval *key, *if_expr, *if_expr_code = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &statement, &extends_mode);
	
	if (!extends_mode) {
		extends_mode = PHALCON_GLOBAL(z_false);
	}
	
	/** 
	 * A valid expression is required
	 */
	if (!phalcon_array_isset_string(statement, SS("expr"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	
	PHALCON_INIT_VAR(compilation);
	phalcon_property_incr(this_ptr, SL("_foreachLevel") TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&prefix, this_ptr, "getuniqueprefix");
	
	level = phalcon_fetch_nproperty_this(this_ptr, SL("_foreachLevel"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * prefix_level is used to prefix every temporal variable
	 */
	PHALCON_INIT_VAR(prefix_level);
	PHALCON_CONCAT_VV(prefix_level, prefix, level);
	
	/** 
	 * Evaluate common expressions
	 */
	PHALCON_OBS_VAR(expr);
	phalcon_array_fetch_string(&expr, statement, SL("expr"), PH_NOISY);
	
	PHALCON_CALL_METHOD(&expr_code, this_ptr, "expression", expr);
	
	/** 
	 * Process the block statements
	 */
	PHALCON_OBS_VAR(block_statements);
	phalcon_array_fetch_string(&block_statements, statement, SL("block_statements"), PH_NOISY);
	
	PHALCON_INIT_VAR(for_else);
	ZVAL_BOOL(for_else, 0);
	if (Z_TYPE_P(block_statements) == IS_ARRAY) { 
	
		phalcon_is_iterable(block_statements, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(bstatement);
	
			if (Z_TYPE_P(bstatement) != IS_ARRAY) { 
				break;
			}
	
			/** 
			 * Check if the statement is valid
			 */
			if (!phalcon_array_isset_string(bstatement, SS("type"))) {
				break;
			}
	
			PHALCON_OBS_NVAR(type);
			phalcon_array_fetch_string(&type, bstatement, SL("type"), PH_NOISY);
			if (PHALCON_IS_LONG(type, PHVOLT_T_ELSEFOR)) {
				PHALCON_SCONCAT_SVS(compilation, "<?php $", prefix_level, "iterated = false; ?>");
				PHALCON_CPY_WRT(for_else, prefix_level);
				phalcon_update_property_array(this_ptr, SL("_forElsePointers"), level, for_else TSRMLS_CC);
				break;
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	/** 
	 * Process statements block
	 */
	PHALCON_CALL_METHOD(&code, this_ptr, "_statementlist", block_statements, extends_mode);
	
	PHALCON_OBS_VAR(loop_context);
	phalcon_read_property_this(&loop_context, this_ptr, SL("_loopPointers"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Generate the loop context for the 'foreach'
	 */
	if (phalcon_array_isset(loop_context, level)) {
		PHALCON_SCONCAT_SVSVS(compilation, "<?php $", prefix_level, "iterator = ", expr_code, "; ");
		PHALCON_SCONCAT_SVS(compilation, "$", prefix_level, "incr = 0; ");
		PHALCON_SCONCAT_SVS(compilation, "$", prefix_level, "loop = new stdClass(); ");
		PHALCON_SCONCAT_SVSVS(compilation, "$", prefix_level, "loop->length = count($", prefix_level, "iterator); ");
		PHALCON_SCONCAT_SVS(compilation, "$", prefix_level, "loop->index = 1; ");
		PHALCON_SCONCAT_SVS(compilation, "$", prefix_level, "loop->index0 = 1; ");
		PHALCON_SCONCAT_SVSVS(compilation, "$", prefix_level, "loop->revindex = $", prefix_level, "loop->length; ");
		PHALCON_SCONCAT_SVSVS(compilation, "$", prefix_level, "loop->revindex0 = $", prefix_level, "loop->length - 1; ?>");
	
		PHALCON_INIT_VAR(iterator);
		PHALCON_CONCAT_SVS(iterator, "$", prefix_level, "iterator");
	} else {
		PHALCON_CPY_WRT(iterator, expr_code);
	}
	
	/** 
	 * Foreach statement
	 */
	PHALCON_OBS_VAR(variable);
	phalcon_array_fetch_string(&variable, statement, SL("variable"), PH_NOISY);
	
	/** 
	 * Check if a 'key' variable needs to be calculated
	 */
	if (phalcon_array_isset_string(statement, SS("key"))) {
		PHALCON_OBS_VAR(key);
		phalcon_array_fetch_string(&key, statement, SL("key"), PH_NOISY);
		PHALCON_SCONCAT_SVSVSVS(compilation, "<?php foreach (", iterator, " as $", key, " => $", variable, ") { ");
	} else {
		PHALCON_SCONCAT_SVSVS(compilation, "<?php foreach (", iterator, " as $", variable, ") { ");
	}
	
	/** 
	 * Check for an 'if' expr in the block
	 */
	if (phalcon_array_isset_string_fetch(&if_expr, statement, SS("if_expr"))) {
		PHALCON_CALL_METHOD(&if_expr_code, this_ptr, "expression", if_expr);
		PHALCON_SCONCAT_SVS(compilation, "if (", if_expr_code, ") { ?>");
	} else {
		phalcon_concat_self_str(&compilation, SL("?>") TSRMLS_CC);
	}
	
	/** 
	 * Generate the loop context inside the cycle
	 */
	if (phalcon_array_isset(loop_context, level)) {
		PHALCON_SCONCAT_SVSVS(compilation, "<?php $", prefix_level, "loop->first = ($", prefix_level, "incr == 0); ");
		PHALCON_SCONCAT_SVSVS(compilation, "$", prefix_level, "loop->index = $", prefix_level, "incr + 1; ");
		PHALCON_SCONCAT_SVSVS(compilation, "$", prefix_level, "loop->index0 = $", prefix_level, "incr; ");
		PHALCON_SCONCAT_SVSVSVS(compilation, "$", prefix_level, "loop->revindex = $", prefix_level, "loop->length - $", prefix_level, "incr; ");
		PHALCON_SCONCAT_SVSVSVS(compilation, "$", prefix_level, "loop->revindex0 = $", prefix_level, "loop->length - ($", prefix_level, "incr + 1); ");
		PHALCON_SCONCAT_SVSVSVS(compilation, "$", prefix_level, "loop->last = ($", prefix_level, "incr == ($", prefix_level, "loop->length - 1)); ?>");
	}
	
	/** 
	 * Update the forelse var if it's iterated at least one time
	 */
	if (Z_TYPE_P(for_else) == IS_STRING) {
		PHALCON_SCONCAT_SVS(compilation, "<?php $", for_else, "iterated = true; ?>");
	}
	
	/** 
	 * Append the internal block compilation
	 */
	phalcon_concat_self(&compilation, code TSRMLS_CC);
	if (phalcon_array_isset_string(statement, SS("if_expr"))) {
		phalcon_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
	}
	
	if (Z_TYPE_P(for_else) == IS_STRING) {
		phalcon_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
	} else if (phalcon_array_isset(loop_context, level)) {
		PHALCON_SCONCAT_SVS(compilation, "<?php $", prefix_level, "incr++; } ?>");
	} else {
		phalcon_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
	}
	
	phalcon_property_decr(this_ptr, SL("_foreachLevel") TSRMLS_CC);
	
	RETURN_CTOR(compilation);
}

/**
 * Generates a 'forelse' PHP code
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForElse){

	zval *level, *for_else_pointers, *prefix, *loop_context;
	zval *compilation = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(level);
	phalcon_read_property_this(&level, this_ptr, SL("_foreachLevel"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(for_else_pointers);
	phalcon_read_property_this(&for_else_pointers, this_ptr, SL("_forElsePointers"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset(for_else_pointers, level)) {
	
		PHALCON_OBS_VAR(prefix);
		phalcon_array_fetch(&prefix, for_else_pointers, level, PH_NOISY);
	
		PHALCON_OBS_VAR(loop_context);
		phalcon_read_property_this(&loop_context, this_ptr, SL("_loopPointers"), PH_NOISY TSRMLS_CC);
		if (phalcon_array_isset(loop_context, level)) {
			PHALCON_INIT_VAR(compilation);
			PHALCON_CONCAT_SVSVS(compilation, "<?php $", prefix, "incr++; } if (!$", prefix, "iterated) { ?>");
		} else {
			PHALCON_INIT_NVAR(compilation);
			PHALCON_CONCAT_SVS(compilation, "<?php } if (!$", prefix, "iterated) { ?>");
		}
	
		RETURN_CTOR(compilation);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Compiles a 'if' statement returning PHP code
 *
 * @param array $statement
 * @param boolean $extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileIf){

	zval *statement, *extends_mode = NULL, *compilation;
	zval *expr, *expr_code = NULL, *block_statements = NULL, *code = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &statement, &extends_mode);
	
	if (!extends_mode) {
		extends_mode = PHALCON_GLOBAL(z_false);
	}
	
	PHALCON_INIT_VAR(compilation);
	
	/** 
	 * A valid expression is required
	 */
	if (!phalcon_array_isset_string(statement, SS("expr"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	
	PHALCON_OBS_VAR(expr);
	phalcon_array_fetch_string(&expr, statement, SL("expr"), PH_NOISY);
	
	PHALCON_CALL_METHOD(&expr_code, this_ptr, "expression", expr);
	
	/** 
	 * 'If' statement
	 */
	PHALCON_SCONCAT_SVS(compilation, "<?php if (", expr_code, ") { ?>");
	if (phalcon_array_isset_string_fetch(&block_statements, statement, SS("true_statements"))) {
		/**
		 * Process statements in the 'true' block
		 */
		PHALCON_CALL_METHOD(&code, this_ptr, "_statementlist", block_statements, extends_mode);
		phalcon_concat_self(&compilation, code TSRMLS_CC);
	}
	
	/** 
	 * Check for a 'else'/'elseif' block
	 */
	if (phalcon_array_isset_string_fetch(&block_statements, statement, SS("false_statements"))) {
		phalcon_concat_self_str(&compilation, SL("<?php } else { ?>") TSRMLS_CC);
	
		/** 
		 * Process statements in the 'false' block
		 */
		PHALCON_CALL_METHOD(&code, this_ptr, "_statementlist", block_statements, extends_mode);
		phalcon_concat_self(&compilation, code TSRMLS_CC);
	}
	
	phalcon_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
	
	RETURN_CCTOR(compilation);
}

/**
 * Compiles a 'elseif' statement returning PHP code
 *
 * @param array $statement
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileElseIf){

	zval *statement, *expr, *expr_code = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &statement);
	
	/** 
	 * A valid expression is required
	 */
	if (!phalcon_array_isset_string(statement, SS("expr"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	
	PHALCON_OBS_VAR(expr);
	phalcon_array_fetch_string(&expr, statement, SL("expr"), PH_NOISY);
	
	PHALCON_CALL_METHOD(&expr_code, this_ptr, "expression", expr);
	
	/** 
	 * 'elseif' statement
	 */
	PHALCON_CONCAT_SVS(return_value, "<?php } elseif (", expr_code, ") { ?>");
	RETURN_MM();
}

/**
 * Compiles a 'cache' statement returning PHP code
 *
 * @param array $statement
 * @param boolean $extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCache){

	zval *statement, *extends_mode = NULL, *compilation;
	zval *expr, *expr_code = NULL, *lifetime = NULL, *block_statements;
	zval *code = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &statement, &extends_mode);
	
	if (!extends_mode) {
		extends_mode = PHALCON_GLOBAL(z_false);
	}
	
	/** 
	 * A valid expression is required
	 */
	if (!phalcon_array_isset_string(statement, SS("expr"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	
	PHALCON_INIT_VAR(compilation);
	
	PHALCON_OBS_VAR(expr);
	phalcon_array_fetch_string(&expr, statement, SL("expr"), PH_NOISY);
	
	/** 
	 * Evaluate common expressions
	 */
	PHALCON_CALL_METHOD(&expr_code, this_ptr, "expression", expr);
	
	/** 
	 * Cache statement
	 */
	PHALCON_SCONCAT_SVS(compilation, "<?php $_cache[", expr_code, "] = $this->di->get('viewCache'); ");
	if (phalcon_array_isset_string_fetch(&lifetime, statement, SS("lifetime"))) {
		PHALCON_SCONCAT_SVS(compilation, "$_cacheKey[", expr_code, "]");
		PHALCON_SCONCAT_SVSVSVS(compilation, " = $_cache[", expr_code, "]->start(", expr_code, ", ", lifetime, "); ");
	} else {
		PHALCON_SCONCAT_SVSVSVS(compilation, "$_cacheKey[", expr_code, "] = $_cache[", expr_code, "]->start(", expr_code, "); ");
	}
	
	PHALCON_SCONCAT_SVS(compilation, "if ($_cacheKey[", expr_code, "] === null) { ?>");
	/** 
	 * Get the code in the block
	 */
	PHALCON_OBS_VAR(block_statements);
	phalcon_array_fetch_string(&block_statements, statement, SL("block_statements"), PH_NOISY);
	
	PHALCON_CALL_METHOD(&code, this_ptr, "_statementlist", block_statements, extends_mode);
	phalcon_concat_self(&compilation, code TSRMLS_CC);
	
	/** 
	 * Check if the cache has a lifetime
	 */
	if (phalcon_array_isset_string_fetch(&lifetime, statement, SS("lifetime"))) {
		PHALCON_SCONCAT_SVSVSVS(compilation, "<?php $_cache[", expr_code, "]->save(", expr_code, ", null, ", lifetime, "); ");
		PHALCON_SCONCAT_SVS(compilation, "} else { echo $_cacheKey[", expr_code, "]; } ?>");
	} else {
		PHALCON_SCONCAT_SVSVSVS(compilation, "<?php $_cache[", expr_code, "]->save(", expr_code, "); } else { echo $_cacheKey[", expr_code, "]; } ?>");
	}
	
	RETURN_CCTOR(compilation);
}

/**
 * Compiles a '{{' '}}' statement returning PHP code
 *
 * @param array $statement
 * @param boolean $extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileEcho){

	zval *statement, *compilation, *expr, *expr_code = NULL;
	zval *expr_type, *name, *name_type, *name_value;
	zval *autoescape;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &statement);
	
	/** 
	 * A valid expression is required
	 */
	if (!phalcon_array_isset_string(statement, SS("expr"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	
	PHALCON_INIT_VAR(compilation);
	
	/** 
	 * Evaluate common expressions
	 */
	PHALCON_OBS_VAR(expr);
	phalcon_array_fetch_string(&expr, statement, SL("expr"), PH_NOISY);
	
	PHALCON_CALL_METHOD(&expr_code, this_ptr, "expression", expr);
	
	PHALCON_OBS_VAR(expr_type);
	phalcon_array_fetch_string(&expr_type, expr, SL("type"), PH_NOISY);
	if (PHALCON_IS_LONG(expr_type, PHVOLT_T_FCALL)) {
	
		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_string(&name, expr, SL("name"), PH_NOISY);
	
		PHALCON_OBS_VAR(name_type);
		phalcon_array_fetch_string(&name_type, name, SL("type"), PH_NOISY);
		if (PHALCON_IS_LONG(name_type, PHVOLT_T_IDENTIFIER)) {
	
			PHALCON_OBS_VAR(name_value);
			phalcon_array_fetch_string(&name_value, name, SL("value"), PH_NOISY);
	
			/** 
			 * super() is a function however the return of this function must be output as it
			 * is
			 */
			if (PHALCON_IS_STRING(name_value, "super")) {
				RETURN_CCTOR(expr_code);
			}
		}
	}
	
	/** 
	 * Echo statement
	 */
	autoescape = phalcon_fetch_nproperty_this(this_ptr, SL("_autoescape"), PH_NOISY TSRMLS_CC);
	if (zend_is_true(autoescape)) {
		PHALCON_SCONCAT_SVS(compilation, "<?php echo $this->escaper->escapeHtml(", expr_code, "); ?>");
	} else {
		PHALCON_SCONCAT_SVS(compilation, "<?php echo ", expr_code, "; ?>");
	}
	
	RETURN_CCTOR(compilation);
}

/**
 * Compiles a 'include' statement returning PHP code
 *
 * @param array $statement
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileInclude){

	zval *statement, *path_expr, *expr_type, *path = NULL;
	zval *view, *views_dir = NULL, *final_path = NULL, *extended;
	zval *sub_compiler, *compilation = NULL, *compiled_path = NULL;
	zval *expr_params, *params = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &statement);
	
	/** 
	 * A valid expression is required
	 */
	if (!phalcon_array_isset_string(statement, SS("path"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	
	/** 
	 * Include statement
	 */
	PHALCON_OBS_VAR(path_expr);
	phalcon_array_fetch_string(&path_expr, statement, SL("path"), PH_NOISY);
	
	/** 
	 * Check if the expression is a string
	 */
	PHALCON_OBS_VAR(expr_type);
	phalcon_array_fetch_string(&expr_type, path_expr, SL("type"), PH_NOISY);
	
	/** 
	 * If the path is an string try to make an static compilation
	 */
	if (PHALCON_IS_LONG(expr_type, 260)) {
	
		/** 
		 * Static compilation cannot be performed if the user passed extra parameters
		 */
		if (!phalcon_array_isset_string(statement, SS("params"))) {
	
			/** 
			 * Get the static path
			 */
			PHALCON_OBS_VAR(path);
			phalcon_array_fetch_string(&path, path_expr, SL("value"), PH_NOISY);
	
			PHALCON_OBS_VAR(view);
			phalcon_read_property_this(&view, this_ptr, SL("_view"), PH_NOISY TSRMLS_CC);
			if (Z_TYPE_P(view) == IS_OBJECT) {
				PHALCON_CALL_METHOD(&views_dir, view, "getviewsdir");
	
				PHALCON_INIT_VAR(final_path);
				PHALCON_CONCAT_VV(final_path, views_dir, path);
			} else {
				PHALCON_CPY_WRT(final_path, path);
			}
	
			PHALCON_INIT_VAR(extended);
			ZVAL_BOOL(extended, 0);
	
			/** 
			 * Clone the original compiler
			 */
			PHALCON_INIT_VAR(sub_compiler);
			if (phalcon_clone(sub_compiler, this_ptr TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}
	
			/** 
			 * Perform a subcompilation of the included file
			 */
			PHALCON_CALL_METHOD(&compilation, sub_compiler, "compile", final_path, extended);
	
			/** 
			 * If the compilation doesn't return anything we include the compiled path
			 */
			if (Z_TYPE_P(compilation) == IS_NULL) {
				PHALCON_CALL_METHOD(&compiled_path, sub_compiler, "getcompiledtemplatepath");
	
				/** 
				 * Use file-get-contents to respect the openbase_dir directive
				 */
				PHALCON_INIT_NVAR(compilation);
				phalcon_file_get_contents(compilation, compiled_path TSRMLS_CC);
			}
	
			RETURN_CCTOR(compilation);
		}
	}
	
	/** 
	 * Resolve the path's expression
	 */
	PHALCON_CALL_METHOD(&path, this_ptr, "expression", path_expr);
	if (!phalcon_array_isset_string(statement, SS("params"))) {
		PHALCON_CONCAT_SVS(return_value, "<?php $this->partial(", path, "); ?>");
		RETURN_MM();
	}
	
	PHALCON_OBS_VAR(expr_params);
	phalcon_array_fetch_string(&expr_params, statement, SL("params"), PH_NOISY);
	
	PHALCON_CALL_METHOD(&params, this_ptr, "expression", expr_params);
	PHALCON_CONCAT_SVSVS(return_value, "<?php $this->partial(", path, ", ", params, "); ?>");
	
	RETURN_MM();
}

/**
 * Compiles a 'set' statement returning PHP code
 *
 * @param array $statement
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSet){

	zval *statement, *compilation, *assignments;
	zval *assignment = NULL, *expr = NULL, *expr_code = NULL, *variable = NULL;
	zval *op = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &statement);
	
	/** 
	 * A valid assigment list is required
	 */
	if (!phalcon_array_isset_string(statement, SS("assignments"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	
	PHALCON_INIT_VAR(compilation);
	ZVAL_STRING(compilation, "<?php", 1);
	
	/** 
	 * A single set can have several assigments
	 */
	PHALCON_OBS_VAR(assignments);
	phalcon_array_fetch_string(&assignments, statement, SL("assignments"), PH_NOISY);
	
	phalcon_is_iterable(assignments, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(assignment);
	
		PHALCON_OBS_NVAR(expr);
		phalcon_array_fetch_string(&expr, assignment, SL("expr"), PH_NOISY);
	
		PHALCON_CALL_METHOD(&expr_code, this_ptr, "expression", expr);
	
		/** 
		 * Set statement
		 */
		PHALCON_OBS_NVAR(variable);
		phalcon_array_fetch_string(&variable, assignment, SL("variable"), PH_NOISY);
	
		/** 
		 * Assignment operator
		 */
		PHALCON_OBS_NVAR(op);
		phalcon_array_fetch_string(&op, assignment, SL("op"), PH_NOISY);
	
		/** 
		 * Generate the right operator
		 */
	
		switch (phalcon_get_intval(op)) {
	
			case 281:
				PHALCON_SCONCAT_SVSVS(compilation, " $", variable, " += ", expr_code, ";");
				break;
	
			case 282:
				PHALCON_SCONCAT_SVSVS(compilation, " $", variable, " -= ", expr_code, ";");
				break;
	
			case 283:
				PHALCON_SCONCAT_SVSVS(compilation, " $", variable, " *= ", expr_code, ";");
				break;
	
			case 284:
				PHALCON_SCONCAT_SVSVS(compilation, " $", variable, " /= ", expr_code, ";");
				break;
	
			default:
				PHALCON_SCONCAT_SVSVS(compilation, " $", variable, " = ", expr_code, ";");
				break;
	
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	phalcon_concat_self_str(&compilation, SL(" ?>") TSRMLS_CC);
	
	RETURN_CTOR(compilation);
}

/**
 * Compiles a 'do' statement returning PHP code
 *
 * @param array $statement
 * @param boolean $extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileDo){

	zval *statement, *expr, *expr_code = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &statement);
	
	/** 
	 * A valid expression is required
	 */
	if (!phalcon_array_isset_string(statement, SS("expr"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	
	PHALCON_OBS_VAR(expr);
	phalcon_array_fetch_string(&expr, statement, SL("expr"), PH_NOISY);
	
	PHALCON_CALL_METHOD(&expr_code, this_ptr, "expression", expr);
	
	/** 
	 * 'Do' statement
	 */
	PHALCON_CONCAT_SVS(return_value, "<?php ", expr_code, "; ?>");
	
	RETURN_MM();
}

/**
 * Compiles a 'return' statement returning PHP code
 *
 * @param array $statement
 * @param boolean $extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileReturn){

	zval *statement, *expr, *expr_code = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &statement);
	
	/** 
	 * A valid expression is required
	 */
	if (!phalcon_array_isset_string(statement, SS("expr"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	
	PHALCON_OBS_VAR(expr);
	phalcon_array_fetch_string(&expr, statement, SL("expr"), PH_NOISY);
	
	PHALCON_CALL_METHOD(&expr_code, this_ptr, "expression", expr);
	PHALCON_CONCAT_SVS(return_value, "<?php return ", expr_code, "; ?>");
	
	RETURN_MM();
}

/**
 * Compiles a 'autoescape' statement returning PHP code
 *
 * @param array $statement
 * @param boolean $extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileAutoEscape){

	zval *statement, *extends_mode, *old_autoescape;
	zval *autoescape, *block_statements;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &statement, &extends_mode);
	
	/** 
	 * A valid option is required
	 */
	if (!phalcon_array_isset_string(statement, SS("enable"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	
	/** 
	 * 'autoescape' mode
	 */
	PHALCON_OBS_VAR(old_autoescape);
	phalcon_read_property_this(&old_autoescape, this_ptr, SL("_autoescape"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(autoescape);
	phalcon_array_fetch_string(&autoescape, statement, SL("enable"), PH_NOISY);
	phalcon_update_property_this(this_ptr, SL("_autoescape"), autoescape TSRMLS_CC);
	
	PHALCON_OBS_VAR(block_statements);
	phalcon_array_fetch_string(&block_statements, statement, SL("block_statements"), PH_NOISY);
	
	PHALCON_RETURN_CALL_METHOD(this_ptr, "_statementlist", block_statements, extends_mode);
	phalcon_update_property_this(this_ptr, SL("_autoescape"), old_autoescape TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Compiles macros
 *
 * @param array $statement
 * @param boolean $extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileMacro){

	zval *statement, *extends_mode, *name, *macros;
	zval *exception_message, *code, *parameters;
	zval *parameter = NULL, *position = NULL, *variable_name = NULL, *block_statements;
	zval *block_code = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &statement, &extends_mode);
	
	/** 
	 * A valid name is required
	 */
	if (!phalcon_array_isset_string(statement, SS("name"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	
	PHALCON_OBS_VAR(name);
	phalcon_array_fetch_string(&name, statement, SL("name"), PH_NOISY);
	
	PHALCON_OBS_VAR(macros);
	phalcon_read_property_this(&macros, this_ptr, SL("_macros"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Check if the macro is already defined
	 */
	if (phalcon_array_isset(macros, name)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Macro \"", name, "\" is already defined");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
		return;
	} else {
		/** 
		 * Register the macro
		 */
		phalcon_update_property_array(this_ptr, SL("_macros"), name, name TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<?php function vmacro_", 1);
	if (!phalcon_array_isset_string(statement, SS("parameters"))) {
		PHALCON_SCONCAT_VS(code, name, "() { ?>");
	} else {
		/** 
		 * Parameters are always received as an array
		 */
		PHALCON_SCONCAT_VS(code, name, "($__p) { ");
	
		PHALCON_OBS_VAR(parameters);
		phalcon_array_fetch_string(&parameters, statement, SL("parameters"), PH_NOISY);
	
		phalcon_is_iterable(parameters, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(position, ah0, hp0);
			PHALCON_GET_HVALUE(parameter);
	
			PHALCON_OBS_NVAR(variable_name);
			phalcon_array_fetch_string(&variable_name, parameter, SL("variable"), PH_NOISY);
			PHALCON_SCONCAT_SVS(code, "if (isset($__p[", position, "])) { ");
			PHALCON_SCONCAT_SVSVS(code, "$", variable_name, " = $__p[", position, "];");
			phalcon_concat_self_str(&code, SL(" } else { ") TSRMLS_CC);
			PHALCON_SCONCAT_SVS(code, "if (isset($__p['", variable_name, "'])) { ");
			PHALCON_SCONCAT_SVSVS(code, "$", variable_name, " = $__p['", variable_name, "'];");
			phalcon_concat_self_str(&code, SL(" } else { ") TSRMLS_CC);
			PHALCON_SCONCAT_SVSVS(code, " throw new \\Phalcon\\Mvc\\View\\Exception(\"Macro ", name, " was called without parameter: ", variable_name, "\"); ");
			phalcon_concat_self_str(&code, SL(" } } ") TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		phalcon_concat_self_str(&code, SL(" ?>") TSRMLS_CC);
	}
	
	/** 
	 * Block statements are allowed
	 */
	if (phalcon_array_isset_string(statement, SS("block_statements"))) {
		/** 
		 * Get block statements
		 */
		PHALCON_OBS_VAR(block_statements);
		phalcon_array_fetch_string(&block_statements, statement, SL("block_statements"), PH_NOISY);
	
		/** 
		 * Process statements block
		 */
		PHALCON_CALL_METHOD(&block_code, this_ptr, "_statementlist", block_statements, extends_mode);
		PHALCON_SCONCAT_VS(code, block_code, "<?php } ?>");
	} else {
		phalcon_concat_self_str(&code, SL("<?php } ?>") TSRMLS_CC);
	}
	
	RETURN_CTOR(code);
}

/**
 * Compiles calls to macros
 *
 * @param array $statement
 * @param boolean $extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCall){


	
}

/**
 * Traverses a statement list compiling each of its nodes
 *
 * @param array $statement
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementList){

	zval *statements, *extends_mode = NULL, *extended = NULL, *block_mode = NULL;
	zval *compilation = NULL, *extensions, *statement = NULL, *line = NULL;
	zval *file = NULL, *exception_message = NULL, *event = NULL, *fire_arguments = NULL;
	zval *temp_compilation = NULL, *type = NULL, *block_name = NULL, *block_statements = NULL;
	zval *blocks = NULL, *code = NULL, *path = NULL, *view = NULL, *views_dir = NULL, *final_path = NULL;
	zval *sub_compiler = NULL, *compiled_path = NULL, *level;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &statements, &extends_mode);
	
	if (!extends_mode) {
		extends_mode = PHALCON_GLOBAL(z_false);
	}
	
	/** 
	 * Nothing to compile
	 */
	if (!phalcon_fast_count_ev(statements TSRMLS_CC)) {
		RETURN_MM_EMPTY_STRING();
	}
	
	/** 
	 * Increase the statement recursion level in extends mode
	 */
	PHALCON_OBS_VAR(extended);
	phalcon_read_property_this(&extended, this_ptr, SL("_extended"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(block_mode);
	ZVAL_BOOL(block_mode, zend_is_true(extended) || zend_is_true(extends_mode));
	if (PHALCON_IS_TRUE(block_mode)) {
		phalcon_property_incr(this_ptr, SL("_blockLevel") TSRMLS_CC);
	}
	
	phalcon_property_incr(this_ptr, SL("_level") TSRMLS_CC);
	
	PHALCON_INIT_VAR(compilation);
	
	PHALCON_OBS_VAR(extensions);
	phalcon_read_property_this(&extensions, this_ptr, SL("_extensions"), PH_NOISY TSRMLS_CC);
	
	phalcon_is_iterable(statements, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(statement);
	
		/** 
		 * All statements must be arrays
		 */
		if (Z_TYPE_P(statement) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
			return;
		}
	
		/** 
		 * Check if the statement is valid
		 */
		if (!phalcon_array_isset_string(statement, SS("type"))) {
			PHALCON_OBS_NVAR(line);
			phalcon_array_fetch_string(&line, statement, SL("line"), PH_NOISY);
	
			PHALCON_OBS_NVAR(file);
			phalcon_array_fetch_string(&file, statement, SL("file"), PH_NOISY);
	
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVSV(exception_message, "Invalid statement in ", file, " on line ", line);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * Check if extensions have implemented custom compilation for this statement
		 */
		if (Z_TYPE_P(extensions) == IS_ARRAY) { 
	
			PHALCON_INIT_NVAR(event);
			ZVAL_STRING(event, "compileStatement", 1);
	
			PHALCON_INIT_NVAR(fire_arguments);
			array_init_size(fire_arguments, 1);
			phalcon_array_append(&fire_arguments, statement, PH_SEPARATE);
	
			PHALCON_CALL_METHOD(&temp_compilation, this_ptr, "fireextensionevent", event, fire_arguments);
			if (Z_TYPE_P(temp_compilation) == IS_STRING) {
				phalcon_concat_self(&compilation, temp_compilation TSRMLS_CC);
				zend_hash_move_forward_ex(ah0, &hp0);
				continue;
			}
		}
	
		/** 
		 * Get the statement type
		 */
		PHALCON_OBS_NVAR(type);
		phalcon_array_fetch_string(&type, statement, SL("type"), PH_NOISY);
	
		/** 
		 * Compile the statement according to the statement's type
		 */
	
		switch (phalcon_get_intval(type)) {
	
			case 357:
				/** 
				 * Raw output statement
				 */
				PHALCON_OBS_NVAR(temp_compilation);
				phalcon_array_fetch_string(&temp_compilation, statement, SL("value"), PH_NOISY);
				phalcon_concat_self(&compilation, temp_compilation TSRMLS_CC);
				break;
	
			case 300:
				PHALCON_CALL_METHOD(&temp_compilation, this_ptr, "compileif", statement, extends_mode);
				phalcon_concat_self(&compilation, temp_compilation TSRMLS_CC);
				break;
	
			case 302:
				PHALCON_CALL_METHOD(&temp_compilation, this_ptr, "compileelseif", statement);
				phalcon_concat_self(&compilation, temp_compilation TSRMLS_CC);
				break;
	
			case 304:
				PHALCON_CALL_METHOD(&temp_compilation, this_ptr, "compileforeach", statement, extends_mode);
				phalcon_concat_self(&compilation, temp_compilation TSRMLS_CC);
				break;
	
			case 306:
				PHALCON_CALL_METHOD(&temp_compilation, this_ptr, "compileset", statement);
				phalcon_concat_self(&compilation, temp_compilation TSRMLS_CC);
				break;
	
			case 359:
				PHALCON_CALL_METHOD(&temp_compilation, this_ptr, "compileecho", statement);
				phalcon_concat_self(&compilation, temp_compilation TSRMLS_CC);
				break;
	
			case 307:
				/** 
				 * Block statement
				 */
				PHALCON_OBS_NVAR(block_name);
				phalcon_array_fetch_string(&block_name, statement, SL("name"), PH_NOISY);
				if (phalcon_array_isset_string(statement, SS("block_statements"))) {
					PHALCON_OBS_NVAR(block_statements);
					phalcon_array_fetch_string(&block_statements, statement, SL("block_statements"), PH_NOISY);
				} else {
					PHALCON_INIT_NVAR(block_statements);
				}
	
				PHALCON_OBS_NVAR(blocks);
				phalcon_read_property_this(&blocks, this_ptr, SL("_blocks"), PH_NOISY TSRMLS_CC);
				if (zend_is_true(block_mode)) {
					if (Z_TYPE_P(blocks) != IS_ARRAY) { 
						PHALCON_INIT_NVAR(blocks);
						array_init(blocks);
					}
	
					/** 
					 * Create a unamed block
					 */
					if (Z_TYPE_P(compilation) != IS_NULL) {
						phalcon_array_append(&blocks, compilation, PH_SEPARATE);
	
						PHALCON_INIT_NVAR(compilation);
					}
	
					/** 
					 * In extends mode we add the block statements to the blocks variable
					 */
					phalcon_array_update_zval(&blocks, block_name, block_statements, PH_COPY | PH_SEPARATE);
					phalcon_update_property_this(this_ptr, SL("_blocks"), blocks TSRMLS_CC);
				} else {
					if (Z_TYPE_P(block_statements) == IS_ARRAY) { 
						PHALCON_CALL_METHOD(&code, this_ptr, "_statementlist", block_statements, extends_mode);
						phalcon_concat_self(&compilation, code TSRMLS_CC);
					}
				}
	
				break;
	
			case 310:
				/** 
				 * Extends statement
				 */
				PHALCON_OBS_NVAR(path);
				phalcon_array_fetch_string(&path, statement, SL("path"), PH_NOISY);
	
				PHALCON_OBS_NVAR(view);
				phalcon_read_property_this(&view, this_ptr, SL("_view"), PH_NOISY TSRMLS_CC);
				if (Z_TYPE_P(view) == IS_OBJECT) {
					PHALCON_CALL_METHOD(&views_dir, view, "getviewsdir");
	
					PHALCON_INIT_NVAR(final_path);
					PHALCON_CONCAT_VV(final_path, views_dir, path);
				} else {
					PHALCON_CPY_WRT(final_path, path);
				}
	
				PHALCON_INIT_NVAR(extended);
				ZVAL_BOOL(extended, 1);
	
				/** 
				 * Perform a subcompilation of the extended file
				 */
				PHALCON_INIT_NVAR(sub_compiler);
				if (phalcon_clone(sub_compiler, this_ptr TSRMLS_CC) == FAILURE) {
					RETURN_MM();
				}
	
				PHALCON_CALL_METHOD(&temp_compilation, sub_compiler, "compile", final_path, extended);
	
				/** 
				 * If the compilation doesn't return anything we include the compiled path
				 */
				if (Z_TYPE_P(temp_compilation) == IS_NULL) {
					PHALCON_CALL_METHOD(&compiled_path, sub_compiler, "getcompiledtemplatepath");
	
					PHALCON_INIT_NVAR(temp_compilation);
					phalcon_file_get_contents(temp_compilation, compiled_path TSRMLS_CC);
				}
	
				phalcon_update_property_bool(this_ptr, SL("_extended"), 1 TSRMLS_CC);
				phalcon_update_property_this(this_ptr, SL("_extendedBlocks"), temp_compilation TSRMLS_CC);
				PHALCON_CPY_WRT(block_mode, extended);
				break;
	
			case 313:
				PHALCON_CALL_METHOD(&temp_compilation, this_ptr, "compileinclude", statement);
				phalcon_concat_self(&compilation, temp_compilation TSRMLS_CC);
				break;
	
			case 314:
				PHALCON_CALL_METHOD(&temp_compilation, this_ptr, "compilecache", statement, extends_mode);
				phalcon_concat_self(&compilation, temp_compilation TSRMLS_CC);
				break;
	
			case 316:
				PHALCON_CALL_METHOD(&temp_compilation, this_ptr, "compiledo", statement);
				phalcon_concat_self(&compilation, temp_compilation TSRMLS_CC);
				break;
	
			case 327:
				PHALCON_CALL_METHOD(&temp_compilation, this_ptr, "compilereturn", statement);
				phalcon_concat_self(&compilation, temp_compilation TSRMLS_CC);
				break;
	
			case 317:
				PHALCON_CALL_METHOD(&temp_compilation, this_ptr, "compileautoescape", statement, extends_mode);
				phalcon_concat_self(&compilation, temp_compilation TSRMLS_CC);
				break;
	
			case 319:
				/** 
				 * 'Continue' statement
				 */
				phalcon_concat_self_str(&compilation, SL("<?php continue; ?>") TSRMLS_CC);
				break;
	
			case 320:
				/** 
				 * 'Break' statement
				 */
				phalcon_concat_self_str(&compilation, SL("<?php break; ?>") TSRMLS_CC);
				break;
	
			case 321:
				/** 
				 * 'Forelse' condition
				 */
				PHALCON_CALL_METHOD(&temp_compilation, this_ptr, "compileforelse");
				phalcon_concat_self(&compilation, temp_compilation TSRMLS_CC);
				break;
	
			case 322:
				/** 
				 * Define a macro
				 */
				PHALCON_CALL_METHOD(&temp_compilation, this_ptr, "compilemacro", statement, extends_mode);
				phalcon_concat_self(&compilation, temp_compilation TSRMLS_CC);
				break;
	
			case 325:
				/** 
				 * 'Call' statement
				 */
				PHALCON_CALL_METHOD(&temp_compilation, this_ptr, "compilecall", statement, extends_mode);
				phalcon_concat_self(&compilation, temp_compilation TSRMLS_CC);
				break;
	
			case 358:
				/** 
				 * Empty statement
				 */
				break;
	
			default:
				PHALCON_OBS_NVAR(line);
				phalcon_array_fetch_string(&line, statement, SL("line"), PH_NOISY);
	
				PHALCON_OBS_NVAR(file);
				phalcon_array_fetch_string(&file, statement, SL("file"), PH_NOISY);
	
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVSVSV(exception_message, "Unknown statement ", type, " in ", file, " on line ", line);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
				return;
	
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Reduce the statement level nesting
	 */
	if (PHALCON_IS_TRUE(block_mode)) {
	
		PHALCON_OBS_VAR(level);
		phalcon_read_property_this(&level, this_ptr, SL("_blockLevel"), PH_NOISY TSRMLS_CC);
		if (PHALCON_IS_LONG(level, 1)) {
	
			if (Z_TYPE_P(compilation) != IS_NULL) {
				phalcon_update_property_array_append(this_ptr, SL("_blocks"), compilation TSRMLS_CC);
			}
		}
	
		phalcon_property_decr(this_ptr, SL("_blockLevel") TSRMLS_CC);
	}
	
	phalcon_property_decr(this_ptr, SL("_level") TSRMLS_CC);
	
	RETURN_CCTOR(compilation);
}

/**
 * Compiles a Volt source code returning a PHP plain version
 *
 * @param string $viewCode
 * @param boolean $extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _compileSource){

	zval *view_code, *extends_mode = NULL, *current_path;
	zval *intermediate, *compilation = NULL, *extended;
	zval *final_compilation = NULL, *blocks = NULL, *extended_blocks;
	zval *block = NULL, *name = NULL, *local_block = NULL, *block_compilation = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &view_code, &extends_mode);
	
	if (!extends_mode) {
		extends_mode = PHALCON_GLOBAL(z_false);
	}
	
	PHALCON_OBS_VAR(current_path);
	phalcon_read_property_this(&current_path, this_ptr, SL("_currentPath"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(intermediate);
	if (phvolt_parse_view(intermediate, view_code, current_path TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	
	/** 
	 * The parsing must return a valid array
	 */
	if (Z_TYPE_P(intermediate) == IS_ARRAY) { 
		PHALCON_CALL_METHOD(&compilation, this_ptr, "_statementlist", intermediate, extends_mode);
	
		/** 
		 * Check if the template is extending another
		 */
		PHALCON_OBS_VAR(extended);
		phalcon_read_property_this(&extended, this_ptr, SL("_extended"), PH_NOISY TSRMLS_CC);
		if (PHALCON_IS_TRUE(extended)) {
	
			/** 
			 * Multiple-Inheritance is allowed
			 */
			if (PHALCON_IS_TRUE(extends_mode)) {
				PHALCON_INIT_VAR(final_compilation);
				array_init(final_compilation);
			} else {
				PHALCON_INIT_NVAR(final_compilation);
			}
	
			PHALCON_OBS_VAR(blocks);
			phalcon_read_property_this(&blocks, this_ptr, SL("_blocks"), PH_NOISY TSRMLS_CC);
	
			PHALCON_OBS_VAR(extended_blocks);
			phalcon_read_property_this(&extended_blocks, this_ptr, SL("_extendedBlocks"), PH_NOISY TSRMLS_CC);
	
			phalcon_is_iterable(extended_blocks, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HKEY(name, ah0, hp0);
				PHALCON_GET_HVALUE(block);
	
				/** 
				 * If name is a string then is a block name
				 */
				if (Z_TYPE_P(name) == IS_STRING) {
					if (Z_TYPE_P(block) == IS_ARRAY) { 
						if (phalcon_array_isset(blocks, name)) {
							/** 
							 * The block is set in the local template
							 */
							PHALCON_OBS_NVAR(local_block);
							phalcon_array_fetch(&local_block, blocks, name, PH_NOISY);
							phalcon_update_property_this(this_ptr, SL("_currentBlock"), name TSRMLS_CC);
	
							PHALCON_CALL_METHOD(&block_compilation, this_ptr, "_statementlist", local_block);
						} else {
							/** 
							 * The block is not set local only in the extended template
							 */
							PHALCON_CALL_METHOD(&block_compilation, this_ptr, "_statementlist", block);
						}
					} else {
						if (phalcon_array_isset(blocks, name)) {
							/** 
							 * The block is set in the local template
							 */
							PHALCON_OBS_NVAR(local_block);
							phalcon_array_fetch(&local_block, blocks, name, PH_NOISY);
							phalcon_update_property_this(this_ptr, SL("_currentBlock"), name TSRMLS_CC);
	
							PHALCON_CALL_METHOD(&block_compilation, this_ptr, "_statementlist", local_block);
						} else {
							PHALCON_CPY_WRT(block_compilation, block);
						}
					}
					if (PHALCON_IS_TRUE(extends_mode)) {
						phalcon_array_update_zval(&final_compilation, name, block_compilation, PH_COPY | PH_SEPARATE);
					} else {
						phalcon_concat_self(&final_compilation, block_compilation TSRMLS_CC);
					}
				} else {
					/** 
					 * Here the block is an already compiled text
					 */
					if (PHALCON_IS_TRUE(extends_mode)) {
						phalcon_array_append(&final_compilation, block, PH_SEPARATE);
					} else {
						phalcon_concat_self(&final_compilation, block TSRMLS_CC);
					}
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
			RETURN_CCTOR(final_compilation);
		}
	
		if (PHALCON_IS_TRUE(extends_mode)) {
			/** 
			 * In extends mode we return the template blocks instead of the compilation
			 */
			PHALCON_OBS_NVAR(blocks);
			phalcon_read_property_this(&blocks, this_ptr, SL("_blocks"), PH_NOISY TSRMLS_CC);
			RETURN_CCTOR(blocks);
		}
	
		RETURN_CCTOR(compilation);
	}
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Invalid intermediate representation");
	return;
}

/**
 * Compiles a template into a string
 *
 *<code>
 * echo $compiler->compileString('{{ "hello world" }}');
 *</code>
 *
 * @param string $viewCode
 * @param boolean $extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString){

	zval *view_code, *extends_mode = NULL, *current_path;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &view_code, &extends_mode);
	
	if (!extends_mode) {
		extends_mode = PHALCON_GLOBAL(z_false);
	}
	
	if (Z_TYPE_P(view_code) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "The code must be string");
		return;
	}
	
	PHALCON_INIT_VAR(current_path);
	ZVAL_STRING(current_path, "eval code", 1);
	phalcon_update_property_this(this_ptr, SL("_currentPath"), current_path TSRMLS_CC);
	PHALCON_RETURN_CALL_METHOD(this_ptr, "_compilesource", view_code, extends_mode);
	RETURN_MM();
}

/**
 * Compiles a template into a file forcing the destination path
 *
 *<code>
 *	$compiler->compile('views/layouts/main.volt', 'views/layouts/main.volt.php');
 *</code>
 *
 * @param string $path
 * @param string $compiledPath
 * @param boolean $extendsMode
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileFile){

	zval *path, *compiled_path, *extends_mode = NULL, *exception_message = NULL;
	zval *view_code, *compilation = NULL, *final_compilation = NULL;
	zval *status;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &path, &compiled_path, &extends_mode);
	
	if (!extends_mode) {
		extends_mode = PHALCON_GLOBAL(z_false);
	}
	
	if (PHALCON_IS_EQUAL(path, compiled_path)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Template path and compilation template path cannot be the same");
		return;
	}
	
	/** 
	 * Check if the template exists
	 */
	if (phalcon_file_exists(path TSRMLS_CC) == FAILURE) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Template file ", path, " does not exist");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
		return;
	}
	
	/** 
	 * Always use file_get_contents instead of read the file directly, this respect the
	 * open_basedir directive
	 */
	PHALCON_INIT_VAR(view_code);
	phalcon_file_get_contents(view_code, path TSRMLS_CC);
	if (PHALCON_IS_FALSE(view_code)) {
		PHALCON_INIT_NVAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Template file ", path, " could not be opened");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
		return;
	}
	
	phalcon_update_property_this(this_ptr, SL("_currentPath"), path TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&compilation, this_ptr, "_compilesource", view_code, extends_mode);
	
	/** 
	 * We store the file serialized if it's an array of blocks
	 */
	if (Z_TYPE_P(compilation) == IS_ARRAY) { 
		PHALCON_INIT_VAR(final_compilation);
		phalcon_serialize(final_compilation, &compilation TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(final_compilation, compilation);
	}
	
	/** 
	 * Always use file_put_contents to write files instead of write the file directly,
	 * this respect the open_basedir directive
	 */
	PHALCON_INIT_VAR(status);
	phalcon_file_put_contents(status, compiled_path, final_compilation TSRMLS_CC);
	if (PHALCON_IS_FALSE(status)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Volt directory can't be written");
		return;
	}
	
	RETURN_CCTOR(compilation);
}

/**
 * Compiles a template into a file applying the compiler options
 * This method does not return the compiled path if the template was not compiled
 *
 *<code>
 *	$compiler->compile('views/layouts/main.volt');
 *	require $compiler->getCompiledTemplatePath();
 *</code>
 *
 * @param string $templatePath
 * @param boolean $extendsMode
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compile){

	zval *template_path, *extends_mode = NULL;
	zval *stat = NULL, *compile_always = NULL, *compiled_path = NULL;
	zval *prefix = NULL, *compiled_separator = NULL, *compiled_extension = NULL;
	zval *compilation = NULL, *options, *real_template_path;
	zval *template_sep_path = NULL, *compiled_template_path = NULL;
	zval *params, *real_compiled_path = NULL, *blocks_code;
	zval *exception_message = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &template_path, &extends_mode);
	
	if (!extends_mode) {
		extends_mode = PHALCON_GLOBAL(z_false);
	}
	
	/** 
	 * Re-initialize some properties already initialized when the object is cloned
	 */
	phalcon_update_property_this(this_ptr, SL("_extended"), PHALCON_GLOBAL(z_false) TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_extendedBlocks"), PHALCON_GLOBAL(z_false) TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_blocks"), PHALCON_GLOBAL(z_null) TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_level"), PHALCON_GLOBAL(z_zero) TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_foreachLevel"), PHALCON_GLOBAL(z_zero) TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_blockLevel"), PHALCON_GLOBAL(z_zero) TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_exprLevel"), PHALCON_GLOBAL(z_zero) TSRMLS_CC);
	
	PHALCON_INIT_VAR(stat);
	ZVAL_BOOL(stat, 1);
	
	PHALCON_INIT_VAR(compile_always);
	ZVAL_FALSE(compile_always);

	PHALCON_INIT_VAR(compiled_path);
	ZVAL_EMPTY_STRING(compiled_path);
	PHALCON_CPY_WRT(prefix, PHALCON_GLOBAL(z_null));
	
	PHALCON_INIT_VAR(compiled_separator);
	ZVAL_STRING(compiled_separator, "%%", 1);
	
	PHALCON_INIT_VAR(compiled_extension);
	ZVAL_STRING(compiled_extension, ".php", 1);
	PHALCON_CPY_WRT(compilation, PHALCON_GLOBAL(z_null));
	
	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(options) == IS_ARRAY) { 
	
		/** 
		 * This makes that templates will be compiled always
		 */
		if (phalcon_array_isset_string(options, SS("compileAlways"))) {
	
			PHALCON_OBS_NVAR(compile_always);
			phalcon_array_fetch_string(&compile_always, options, SL("compileAlways"), PH_NOISY);
			if (Z_TYPE_P(compile_always) != IS_BOOL) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compileAlways must be a bool value");
				return;
			}
		}
	
		/** 
		 * Prefix is prepended to the template name
		 */
		if (phalcon_array_isset_string(options, SS("prefix"))) {
	
			PHALCON_OBS_NVAR(prefix);
			phalcon_array_fetch_string(&prefix, options, SL("prefix"), PH_NOISY);
			if (Z_TYPE_P(prefix) != IS_STRING) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "prefix must be a string");
				return;
			}
		}
	
		/** 
		 * Compiled path is a directory where the compiled templates will be located
		 */
		if (phalcon_array_isset_string(options, SS("compiledPath"))) {
	
			PHALCON_OBS_NVAR(compiled_path);
			phalcon_array_fetch_string(&compiled_path, options, SL("compiledPath"), PH_NOISY);
			if (Z_TYPE_P(compiled_path) != IS_STRING) {
				if (Z_TYPE_P(compiled_path) != IS_OBJECT) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compiledPath must be a string or a closure");
					return;
				}
			}
		}
	
		/** 
		 * There is no compiled separator by default
		 */
		if (phalcon_array_isset_string(options, SS("compiledSeparator"))) {
	
			PHALCON_OBS_NVAR(compiled_separator);
			phalcon_array_fetch_string(&compiled_separator, options, SL("compiledSeparator"), PH_NOISY);
			if (Z_TYPE_P(compiled_separator) != IS_STRING) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compiledSeparator must be a string");
				return;
			}
		}
	
		/** 
		 * By default the compile extension is .php
		 */
		if (phalcon_array_isset_string(options, SS("compiledExtension"))) {
	
			PHALCON_OBS_NVAR(compiled_extension);
			phalcon_array_fetch_string(&compiled_extension, options, SL("compiledExtension"), PH_NOISY);
			if (Z_TYPE_P(compiled_extension) != IS_STRING) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compiledExtension must be a string");
				return;
			}
		}
	
		/** 
		 * Stat option assumes the compilation of the file
		 */
		if (phalcon_array_isset_string(options, SS("stat"))) {
			PHALCON_OBS_NVAR(stat);
			phalcon_array_fetch_string(&stat, options, SL("stat"), PH_NOISY);
		}
	}
	
	if (Z_TYPE_P(compiled_path) == IS_STRING) {
	
		/** 
		 * Calculate the template realpath's
		 */
		if (PHALCON_IS_NOT_EMPTY(compiled_path)) {
			PHALCON_INIT_VAR(real_template_path);
			phalcon_realpath(real_template_path, template_path TSRMLS_CC);
	
			/** 
			 * Create the virtual path replacing the directory separator by the compiled
			 * separator
			 */
			PHALCON_INIT_VAR(template_sep_path);
			phalcon_prepare_virtual_path(template_sep_path, real_template_path, compiled_separator TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(template_sep_path, template_path);
		}
	
		/** 
		 * In extends mode we add an additional 'e' suffix to the file
		 */
		PHALCON_INIT_VAR(compiled_template_path);
		if (PHALCON_IS_TRUE(extends_mode)) {
			PHALCON_CONCAT_VVVVSVV(compiled_template_path, compiled_path, prefix, template_sep_path, compiled_separator, "e", compiled_separator, compiled_extension);
		} else {
			PHALCON_CONCAT_VVVV(compiled_template_path, compiled_path, prefix, template_sep_path, compiled_extension);
		}
	} else {
		/** 
		 * A closure can dynamically compile the path
		 */
		if (Z_TYPE_P(compiled_path) == IS_OBJECT) {
			if (instanceof_function(Z_OBJCE_P(compiled_path), zend_ce_closure TSRMLS_CC)) {
	
				PHALCON_INIT_VAR(params);
				array_init_size(params, 3);
				phalcon_array_append(&params, template_path, 0);
				phalcon_array_append(&params, options, 0);
				phalcon_array_append(&params, extends_mode, 0);
	
				PHALCON_INIT_NVAR(compiled_template_path);/**/
				PHALCON_CALL_USER_FUNC_ARRAY(compiled_template_path, compiled_path, params);
	
				/** 
				 * The closure must return a valid path
				 */
				if (Z_TYPE_P(compiled_template_path) != IS_STRING) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compiledPath closure didn't return a valid string");
					return;
				}
			} else {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compiledPath must be a string or a closure");
				return;
			}
		}
	}
	
	/** 
	 * Use the real path to avoid collisions
	 */
	PHALCON_CPY_WRT(real_compiled_path, compiled_template_path);
	if (zend_is_true(compile_always)) {
		/** 
		 * Compile always must be used only in the development stage
		 */
		PHALCON_CALL_METHOD(&compilation, this_ptr, "compilefile", template_path, real_compiled_path, extends_mode);
	} else {
		if (PHALCON_IS_TRUE(stat)) {
	
			if (phalcon_file_exists(compiled_template_path TSRMLS_CC) == SUCCESS) {
	
				/** 
				 * Compare modification timestamps to check if the file needs to be recompiled
				 */
				if (phalcon_compare_mtime(template_path, real_compiled_path TSRMLS_CC)) {
					PHALCON_CALL_METHOD(&compilation, this_ptr, "compilefile", template_path, real_compiled_path, extends_mode);
				} else {
					if (PHALCON_IS_TRUE(extends_mode)) {
	
						/** 
						 * In extends mode we read the file that must contains a serialized array of blocks
						 */
						PHALCON_INIT_VAR(blocks_code);
						phalcon_file_get_contents(blocks_code, real_compiled_path TSRMLS_CC);
						if (PHALCON_IS_FALSE(blocks_code)) {
							PHALCON_INIT_VAR(exception_message);
							PHALCON_CONCAT_SVS(exception_message, "Extends compilation file ", real_compiled_path, " could not be opened");
							PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
							return;
						}
	
						/** 
						 * Unserialize the array blocks code
						 */
						if (zend_is_true(blocks_code)) {
							PHALCON_INIT_NVAR(compilation);
							phalcon_unserialize(compilation, blocks_code TSRMLS_CC);
						} else {
							PHALCON_INIT_NVAR(compilation);
							array_init(compilation);
						}
					}
				}
			} else {
				/** 
				 * The file doesn't exist so we compile the php version for the first time
				 */
				PHALCON_CALL_METHOD(&compilation, this_ptr, "compilefile", template_path, real_compiled_path, extends_mode);
			}
		} else {
			/** 
			 * Stat is off but the compiled file doesn't exist
			 */
			if (phalcon_file_exists(real_compiled_path TSRMLS_CC) == FAILURE) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Compiled template file ", real_compiled_path, " does not exist");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
				return;
			}
		}
	}
	
	phalcon_update_property_this(this_ptr, SL("_compiledTemplatePath"), real_compiled_path TSRMLS_CC);
	
	RETURN_CCTOR(compilation);
}

/**
 * Returns the path that is currently being compiled
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getTemplatePath){


	RETURN_MEMBER(this_ptr, "_currentPath");
}

/**
 * Returns the path to the last compiled template
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath){


	RETURN_MEMBER(this_ptr, "_compiledTemplatePath");
}

/**
 * Parses a Volt template returning its intermediate representation
 *
 *<code>
 *	print_r($compiler->parse('{{ 3 + 2 }}'));
 *</code>
 *
 * @param string $viewCode
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, parse){

	zval *view_code, *current_path;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &view_code);
	
	PHALCON_INIT_VAR(current_path);
	ZVAL_STRING(current_path, "eval code", 1);
	if (phvolt_parse_view(return_value, view_code, current_path TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	RETURN_MM();
}
