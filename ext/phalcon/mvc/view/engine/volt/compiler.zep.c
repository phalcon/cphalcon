
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "Zend/zend_closures.h"
#include "kernel/file.h"
#include "kernel/string.h"
#include "phalcon/mvc/view/engine/volt/scanner.h"
#include "phalcon/mvc/view/engine/volt/volt.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This class reads and compiles Volt templates into PHP plain code
 *
 *```php
 * $compiler = new \Phalcon\Mvc\View\Engine\Volt\Compiler();
 *
 * $compiler->compile("views/partials/header.volt");
 *
 * require $compiler->getCompiledTemplatePath();
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Compiler)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\View\\Engine\\Volt, Compiler, phalcon, mvc_view_engine_volt_compiler, phalcon_mvc_view_engine_volt_compiler_method_entry, 0);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_view_engine_volt_compiler_ce, SL("autoescape"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_view_engine_volt_compiler_ce, SL("blockLevel"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array|null
	 *
	 * TODO: Make array only?
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("blocks"), ZEND_ACC_PROTECTED);
	/**
	 * @var DiInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("container"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("compiledTemplatePath"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("currentBlock"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("currentPath"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_view_engine_volt_compiler_ce, SL("exprLevel"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_view_engine_volt_compiler_ce, SL("extended"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("extensions"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|bool
	 *
	 * TODO: Make it always array
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("extendedBlocks"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("filters"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_view_engine_volt_compiler_ce, SL("foreachLevel"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("forElsePointers"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("functions"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_view_engine_volt_compiler_ce, SL("level"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("loopPointers"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("macros"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("options"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_view_engine_volt_compiler_ce, SL("prefix"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var ViewBaseInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("view"), ZEND_ACC_PROTECTED);
	phalcon_mvc_view_engine_volt_compiler_ce->create_object = zephir_init_properties_Phalcon_Mvc_View_Engine_Volt_Compiler;

	zend_class_implements(phalcon_mvc_view_engine_volt_compiler_ce, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\View\Engine\Volt\Compiler
 *
 * @param ViewBaseInterface|null view
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, __construct)
{
	zval *view = NULL, view_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&view_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(view, phalcon_mvc_viewbaseinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(0, 1, &view);
	if (!view) {
		view = &view_sub;
		view = &__$null;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("view"), view);
}

/**
 * Registers a Volt's extension
 *
 * @var mixed extension
 *
 * @return Compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addExtension)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *extension, extension_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extension_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(extension)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &extension);
	if (UNEXPECTED(Z_TYPE_P(extension) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "The extension is not valid", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 160);
		return;
	}
	if ((zephir_method_exists_ex(extension, ZEND_STRL("initialize")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, extension, "initialize", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	zephir_update_property_array_append(this_ptr, SL("extensions"), extension);
	RETURN_THIS();
}

/**
 * Register a new filter in the compiler
 *
 * @param string name
 * @param mixed definition
 *
 * @return Compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFilter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *definition, definition_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(definition)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &name_param, &definition);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	zephir_update_property_array(this_ptr, SL("filters"), &name, definition);
	RETURN_THIS();
}

/**
 * Register a new function in the compiler
 *
 * @param string name
 * @param mixed definition
 *
 * @return Compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFunction)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *definition, definition_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(definition)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &name_param, &definition);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	zephir_update_property_array(this_ptr, SL("functions"), &name, definition);
	RETURN_THIS();
}

/**
 * Resolves attribute reading
 *
 * @param array expr
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, attributeReader)
{
	zend_bool _4$$5, _9$$8;
	zval exprCode;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, left, leftType, variable, level, leftCode, right, _0, _10, _1$$4, _2$$4, _3$$5, _5$$5, _6$$5, _7$$6, _8$$7, _11$$11, _12$$12;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&leftType);
	ZVAL_UNDEF(&variable);
	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&leftCode);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&exprCode);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(expr)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expr_param);
	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);
	ZEPHIR_INIT_VAR(&exprCode);
	zephir_memory_observe(&left);
	zephir_array_fetch_string(&left, &expr, SL("left"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 219);
	zephir_array_fetch_string(&_0, &left, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 221);
	if (ZEPHIR_IS_LONG(&_0, 265)) {
		zephir_memory_observe(&variable);
		zephir_array_fetch_string(&variable, &left, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 222);
		if (ZEPHIR_IS_STRING(&variable, "loop")) {
			zephir_memory_observe(&level);
			zephir_read_property(&level, this_ptr, ZEND_STRL("foreachLevel"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "getuniqueprefix", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_CONCAT_SVVS(&_2$$4, "$", &_1$$4, &level, "loop");
			zephir_concat_self(&exprCode, &_2$$4);
			zephir_update_property_array(this_ptr, SL("loopPointers"), &level, &level);
		} else {
			zephir_read_property(&_3$$5, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
			_4$$5 = Z_TYPE_P(&_3$$5) != IS_NULL;
			if (_4$$5) {
				zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_6$$5, &_5$$5, "has", NULL, 0, &variable);
				zephir_check_call_status();
				_4$$5 = zephir_is_true(&_6$$5);
			}
			if (_4$$5) {
				ZEPHIR_INIT_VAR(&_7$$6);
				ZEPHIR_CONCAT_SV(&_7$$6, "$this->", &variable);
				zephir_concat_self(&exprCode, &_7$$6);
			} else {
				ZEPHIR_INIT_VAR(&_8$$7);
				ZEPHIR_CONCAT_SV(&_8$$7, "$", &variable);
				zephir_concat_self(&exprCode, &_8$$7);
			}
		}
	} else {
		ZEPHIR_CALL_METHOD(&leftCode, this_ptr, "expression", NULL, 503, &left);
		zephir_check_call_status();
		zephir_memory_observe(&leftType);
		zephir_array_fetch_string(&leftType, &left, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 244);
		_9$$8 = !ZEPHIR_IS_LONG(&leftType, '.');
		if (_9$$8) {
			_9$$8 = !ZEPHIR_IS_LONG(&leftType, 350);
		}
		if (_9$$8) {
			zephir_concat_self(&exprCode, &leftCode);
		} else {
			zephir_concat_self(&exprCode, &leftCode);
		}
	}
	zephir_concat_self_str(&exprCode, "->", sizeof("->") - 1);
	zephir_memory_observe(&right);
	zephir_array_fetch_string(&right, &expr, SL("right"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 255);
	zephir_array_fetch_string(&_10, &right, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 257);
	if (ZEPHIR_IS_LONG(&_10, 265)) {
		zephir_array_fetch_string(&_11$$11, &right, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 258);
		zephir_concat_self(&exprCode, &_11$$11);
	} else {
		ZEPHIR_CALL_METHOD(&_12$$12, this_ptr, "expression", NULL, 503, &right);
		zephir_check_call_status();
		zephir_concat_self(&exprCode, &_12$$12);
	}
	RETURN_CTOR(&exprCode);
}

/**
 * Compiles a template into a file applying the compiler options
 * This method does not return the compiled path if the template was not compiled
 *
 *```php
 * $compiler->compile("views/layouts/main.volt");
 *
 * require $compiler->getCompiledTemplatePath();
 *```
 *
 * @param string templatePath
 * @param bool extendsMode
 *
 * @throws \Phalcon\Mvc\View\Engine\Volt\Exception
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compile)
{
	zval _11$$26;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode, _9, _13;
	zval *templatePath_param = NULL, *extendsMode_param = NULL, __$true, __$false, __$null, blocksCode, compilation, compileAlways, compiledExtension, compiledPath, compiledSeparator, compiledTemplatePath, options, prefix, stat, templateSepPath, _0, _1$$4, _2$$4, _3$$10, _4$$10, _5$$13, _6$$13, _7$$17, _8$$17, _10$$22, _12$$26, _14$$29, _15$$31, _16$$32, _17$$35, _18$$35;
	zval templatePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&templatePath);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&blocksCode);
	ZVAL_UNDEF(&compilation);
	ZVAL_UNDEF(&compileAlways);
	ZVAL_UNDEF(&compiledExtension);
	ZVAL_UNDEF(&compiledPath);
	ZVAL_UNDEF(&compiledSeparator);
	ZVAL_UNDEF(&compiledTemplatePath);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&stat);
	ZVAL_UNDEF(&templateSepPath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$10);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_5$$13);
	ZVAL_UNDEF(&_6$$13);
	ZVAL_UNDEF(&_7$$17);
	ZVAL_UNDEF(&_8$$17);
	ZVAL_UNDEF(&_10$$22);
	ZVAL_UNDEF(&_12$$26);
	ZVAL_UNDEF(&_14$$29);
	ZVAL_UNDEF(&_15$$31);
	ZVAL_UNDEF(&_16$$32);
	ZVAL_UNDEF(&_17$$35);
	ZVAL_UNDEF(&_18$$35);
	ZVAL_UNDEF(&_11$$26);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(templatePath)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &templatePath_param, &extendsMode_param);
	if (UNEXPECTED(Z_TYPE_P(templatePath_param) != IS_STRING && Z_TYPE_P(templatePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'templatePath' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(templatePath_param) == IS_STRING)) {
		zephir_get_strval(&templatePath, templatePath_param);
	} else {
		ZEPHIR_INIT_VAR(&templatePath);
	}
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		}
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("extended"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("extended"), &__$false);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("extendedBlocks"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("extendedBlocks"), &__$false);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("blocks"), &__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("level"), &_0);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("foreachLevel"), &_0);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("blockLevel"), &_0);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("exprLevel"), &_0);
	ZEPHIR_INIT_VAR(&compilation);
	ZVAL_NULL(&compilation);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	zephir_memory_observe(&compileAlways);
	if (!(zephir_array_isset_string_fetch(&compileAlways, &options, SL("always"), 0))) {
		ZEPHIR_OBS_NVAR(&compileAlways);
		if (zephir_array_isset_string_fetch(&compileAlways, &options, SL("compileAlways"), 0)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			ZVAL_STRING(&_1$$4, "The 'compileAlways' option is deprecated. Use 'always' instead.");
			ZVAL_LONG(&_2$$4, 16384);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 7, &_1$$4, &_2$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&compileAlways);
			ZVAL_BOOL(&compileAlways, 0);
		}
	}
	if (UNEXPECTED(((Z_TYPE_P(&compileAlways) == IS_TRUE || Z_TYPE_P(&compileAlways) == IS_FALSE) != 1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'always' must be a bool value", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 319);
		return;
	}
	zephir_memory_observe(&prefix);
	if (!(zephir_array_isset_string_fetch(&prefix, &options, SL("prefix"), 0))) {
		ZEPHIR_INIT_NVAR(&prefix);
		ZVAL_STRING(&prefix, "");
	}
	if (UNEXPECTED(Z_TYPE_P(&prefix) != IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'prefix' must be a string", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 330);
		return;
	}
	zephir_memory_observe(&compiledPath);
	if (!(zephir_array_isset_string_fetch(&compiledPath, &options, SL("path"), 0))) {
		ZEPHIR_OBS_NVAR(&compiledPath);
		if (zephir_array_isset_string_fetch(&compiledPath, &options, SL("compiledPath"), 0)) {
			ZEPHIR_INIT_VAR(&_3$$10);
			ZVAL_STRING(&_3$$10, "The 'compiledPath' option is deprecated. Use 'path' instead.");
			ZVAL_LONG(&_4$$10, 16384);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 7, &_3$$10, &_4$$10);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&compiledPath);
			ZVAL_STRING(&compiledPath, "");
		}
	}
	zephir_memory_observe(&compiledSeparator);
	if (!(zephir_array_isset_string_fetch(&compiledSeparator, &options, SL("separator"), 0))) {
		ZEPHIR_OBS_NVAR(&compiledSeparator);
		if (zephir_array_isset_string_fetch(&compiledSeparator, &options, SL("compiledSeparator"), 0)) {
			ZEPHIR_INIT_VAR(&_5$$13);
			ZVAL_STRING(&_5$$13, "The 'compiledSeparator' option is deprecated. Use 'separator' instead.");
			ZVAL_LONG(&_6$$13, 16384);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 7, &_5$$13, &_6$$13);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&compiledSeparator);
			ZVAL_STRING(&compiledSeparator, "%%");
		}
	}
	if (UNEXPECTED(Z_TYPE_P(&compiledSeparator) != IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'separator' must be a string", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 363);
		return;
	}
	zephir_memory_observe(&compiledExtension);
	if (!(zephir_array_isset_string_fetch(&compiledExtension, &options, SL("extension"), 0))) {
		ZEPHIR_OBS_NVAR(&compiledExtension);
		if (zephir_array_isset_string_fetch(&compiledExtension, &options, SL("compiledExtension"), 0)) {
			ZEPHIR_INIT_VAR(&_7$$17);
			ZVAL_STRING(&_7$$17, "The 'compiledExtension' option is deprecated. Use 'extension' instead.");
			ZVAL_LONG(&_8$$17, 16384);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 7, &_7$$17, &_8$$17);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&compiledExtension);
			ZVAL_STRING(&compiledExtension, ".php");
		}
	}
	if (UNEXPECTED(Z_TYPE_P(&compiledExtension) != IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'extension' must be a string", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 381);
		return;
	}
	zephir_memory_observe(&stat);
	if (!(zephir_array_isset_string_fetch(&stat, &options, SL("stat"), 0))) {
		ZEPHIR_INIT_NVAR(&stat);
		ZVAL_BOOL(&stat, 1);
	}
	_9 = Z_TYPE_P(&compiledPath) == IS_OBJECT;
	if (_9) {
		_9 = zephir_is_instance_of(&compiledPath, SL("Closure"));
	}
	if (Z_TYPE_P(&compiledPath) == IS_STRING) {
		if (!(ZEPHIR_IS_EMPTY(&compiledPath))) {
			ZEPHIR_CALL_FUNCTION(&_10$$22, "realpath", NULL, 75, &templatePath);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&templateSepPath);
			zephir_prepare_virtual_path(&templateSepPath, &_10$$22, &compiledSeparator);
		} else {
			ZEPHIR_CPY_WRT(&templateSepPath, &templatePath);
		}
		ZEPHIR_INIT_VAR(&compiledTemplatePath);
		if (extendsMode) {
			ZEPHIR_CONCAT_VVVVSVV(&compiledTemplatePath, &compiledPath, &prefix, &templateSepPath, &compiledSeparator, "e", &compiledSeparator, &compiledExtension);
		} else {
			ZEPHIR_CONCAT_VVVV(&compiledTemplatePath, &compiledPath, &prefix, &templateSepPath, &compiledExtension);
		}
	} else if (_9) {
		ZEPHIR_INIT_VAR(&_11$$26);
		zephir_create_array(&_11$$26, 3, 0);
		zephir_array_fast_append(&_11$$26, &templatePath);
		zephir_array_fast_append(&_11$$26, &options);
		ZEPHIR_INIT_VAR(&_12$$26);
		ZVAL_BOOL(&_12$$26, extendsMode);
		zephir_array_fast_append(&_11$$26, &_12$$26);
		ZEPHIR_INIT_NVAR(&compiledTemplatePath);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&compiledTemplatePath, &compiledPath, &_11$$26);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&compiledTemplatePath) != IS_STRING)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'path' closure didn't return a valid string", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 434);
			return;
		}
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'path' must be a string or a closure", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 439);
		return;
	}
	_13 = !((zephir_file_exists(&compiledTemplatePath) == SUCCESS));
	if (!(_13)) {
		_13 = zephir_is_true(&compileAlways);
	}
	if (_13) {
		if (extendsMode) {
			ZVAL_BOOL(&_14$$29, 1);
		} else {
			ZVAL_BOOL(&_14$$29, 0);
		}
		ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilefile", NULL, 0, &templatePath, &compiledTemplatePath, &_14$$29);
		zephir_check_call_status();
	} else {
		if (ZEPHIR_IS_TRUE_IDENTICAL(&stat)) {
			ZEPHIR_INIT_VAR(&_15$$31);
			if (zephir_compare_mtime(&templatePath, &compiledTemplatePath)) {
				if (extendsMode) {
					ZVAL_BOOL(&_16$$32, 1);
				} else {
					ZVAL_BOOL(&_16$$32, 0);
				}
				ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilefile", NULL, 0, &templatePath, &compiledTemplatePath, &_16$$32);
				zephir_check_call_status();
			} else {
				if (extendsMode) {
					ZEPHIR_INIT_VAR(&blocksCode);
					zephir_file_get_contents(&blocksCode, &compiledTemplatePath);
					if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&blocksCode))) {
						ZEPHIR_INIT_VAR(&_17$$35);
						object_init_ex(&_17$$35, phalcon_mvc_view_engine_volt_exception_ce);
						ZEPHIR_INIT_VAR(&_18$$35);
						ZEPHIR_CONCAT_SVS(&_18$$35, "Extends compilation file ", &compiledTemplatePath, " could not be opened");
						ZEPHIR_CALL_METHOD(NULL, &_17$$35, "__construct", NULL, 504, &_18$$35);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_17$$35, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 478);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (zephir_is_true(&blocksCode)) {
						ZEPHIR_CALL_FUNCTION(&compilation, "unserialize", NULL, 16, &blocksCode);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&compilation);
						array_init(&compilation);
					}
				}
			}
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("compiledTemplatePath"), &compiledTemplatePath);
	RETURN_CCTOR(&compilation);
}

/**
 * Compiles a "autoescape" statement returning PHP code
 *
 * @param array statement
 * @param bool extendsMode
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileAutoEscape)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, autoescape, oldAutoescape, compilation, _0, _1;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&autoescape);
	ZVAL_UNDEF(&oldAutoescape);
	ZVAL_UNDEF(&compilation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(statement)
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &statement_param, &extendsMode_param);
	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	zephir_memory_observe(&autoescape);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&autoescape, &statement, SL("enable"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 515);
		return;
	}
	zephir_memory_observe(&oldAutoescape);
	zephir_read_property(&oldAutoescape, this_ptr, ZEND_STRL("autoescape"), PH_NOISY_CC);
	zephir_update_property_zval(this_ptr, ZEND_STRL("autoescape"), &autoescape);
	zephir_array_fetch_string(&_0, &statement, SL("block_statements"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 525);
	if (extendsMode) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(&compilation, this_ptr, "statementlist", NULL, 505, &_0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("autoescape"), &oldAutoescape);
	RETURN_CCTOR(&compilation);
}

/**
 * Compiles calls to macros
 *
 * @param array statement
 * @param bool extendsMode
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCall)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL;
	zval statement;

	ZVAL_UNDEF(&statement);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(statement)
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &statement_param, &extendsMode_param);
	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
}

/**
 * Compiles a "case"/"default" clause returning PHP code
 *
 * @param array statement
 * @param bool caseClause
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCase)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool caseClause;
	zval *statement_param = NULL, *caseClause_param = NULL, expr, _2, _0$$4, _1$$4;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(statement)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(caseClause)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &statement_param, &caseClause_param);
	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	if (!caseClause_param) {
		caseClause = 1;
	} else {
		}
	if (UNEXPECTED(caseClause == 0)) {
		RETURN_MM_STRING("<?php default: ?>");
	}
	zephir_memory_observe(&expr);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$4);
		object_init_ex(&_0$$4, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "Corrupt statement");
		ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 504, &_1$$4, &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$4, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 568);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 503, &expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php case ", &_2, ": ?>");
	RETURN_MM();
}

/**
 * Compiles a "do" statement returning PHP code
 *
 * @param array statement
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileDo)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, expr, _0;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(statement)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &statement_param);
	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	zephir_memory_observe(&expr);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 592);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "expression", NULL, 503, &expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php ", &_0, "; ?>");
	RETURN_MM();
}

/**
 * Compiles a {% raw %}`{{` `}}`{% endraw %} statement returning PHP code
 *
 * @param array statement
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileEcho)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, expr, exprCode, name, _2, _7, _0$$3, _1$$3, _3$$4, _5$$4, _4$$5, _6$$6;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&exprCode);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(statement)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &statement_param);
	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	zephir_memory_observe(&expr);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Corrupt statement");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 504, &_1$$3, &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 616);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", NULL, 503, &expr);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, &expr, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 624);
	if (ZEPHIR_IS_LONG(&_2, 350)) {
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "istagfactory", NULL, 506, &expr);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_3$$4)) {
			ZVAL_BOOL(&_4$$5, 1);
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", NULL, 503, &expr, &_4$$5);
			zephir_check_call_status();
		}
		zephir_array_fetch_string(&name, &expr, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 629);
		zephir_array_fetch_string(&_5$$4, &name, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 630);
		if (ZEPHIR_IS_LONG(&_5$$4, 265)) {
			zephir_array_fetch_string(&_6$$6, &name, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 635);
			if (ZEPHIR_IS_STRING(&_6$$6, "super")) {
				RETURN_CCTOR(&exprCode);
			}
		}
	}
	zephir_read_property(&_7, this_ptr, ZEND_STRL("autoescape"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_7)) {
		ZEPHIR_CONCAT_SVS(return_value, "<?= $this->escaper->html(", &exprCode, ") ?>");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "<?= ", &exprCode, " ?>");
	RETURN_MM();
}

/**
 * Compiles a "elseif" statement returning PHP code
 *
 * @param array statement
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileElseIf)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, expr, _2, _0$$3, _1$$3;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(statement)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &statement_param);
	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	zephir_memory_observe(&expr);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Corrupt statement");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 504, &_1$$3, &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 666);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 503, &expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php } elseif (", &_2, ") { ?>");
	RETURN_MM();
}

/**
 * Compiles a template into a file forcing the destination path
 *
 *```php
 * $compiler->compileFile(
 *     "views/layouts/main.volt",
 *     "views/layouts/main.volt.php"
 * );
 *```
 *
 * @param string path
 * @param string compiledPath
 * @param bool extendsMode
 *
 * @throws \Phalcon\Mvc\View\Engine\Volt\Exception
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *path_param = NULL, *compiledPath_param = NULL, *extendsMode_param = NULL, viewCode, compilation, finalCompilation, _4, _5, _0$$4, _2$$5;
	zval path, compiledPath, _1$$4, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&compiledPath);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&viewCode);
	ZVAL_UNDEF(&compilation);
	ZVAL_UNDEF(&finalCompilation);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$5);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(path)
		Z_PARAM_STR(compiledPath)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &path_param, &compiledPath_param, &extendsMode_param);
	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
	}
	if (UNEXPECTED(Z_TYPE_P(compiledPath_param) != IS_STRING && Z_TYPE_P(compiledPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'compiledPath' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(compiledPath_param) == IS_STRING)) {
		zephir_get_strval(&compiledPath, compiledPath_param);
	} else {
		ZEPHIR_INIT_VAR(&compiledPath);
	}
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		}
	if (UNEXPECTED(ZEPHIR_IS_EQUAL(&path, &compiledPath))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Template path and compilation template path cannot be the same", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 699);
		return;
	}
	if (UNEXPECTED(!((zephir_file_exists(&path) == SUCCESS)))) {
		ZEPHIR_INIT_VAR(&_0$$4);
		object_init_ex(&_0$$4, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_SVS(&_1$$4, "Template file ", &path, " does not exist");
		ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 504, &_1$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$4, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 706);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&viewCode);
	zephir_file_get_contents(&viewCode, &path);
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&viewCode))) {
		ZEPHIR_INIT_VAR(&_2$$5);
		object_init_ex(&_2$$5, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$5);
		ZEPHIR_CONCAT_SVS(&_3$$5, "Template file ", &path, " could not be opened");
		ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 504, &_3$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 718);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("currentPath"), &path);
	if (extendsMode) {
		ZVAL_BOOL(&_4, 1);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilesource", NULL, 0, &viewCode, &_4);
	zephir_check_call_status();
	if (Z_TYPE_P(&compilation) == IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&finalCompilation, "serialize", NULL, 15, &compilation);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&finalCompilation, &compilation);
	}
	ZEPHIR_INIT_VAR(&_5);
	zephir_file_put_contents(&_5, &compiledPath, &finalCompilation);
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_5))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Volt directory can't be written", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 739);
		return;
	}
	RETURN_CCTOR(&compilation);
}

/**
 * Compiles a "foreach" intermediate code representation into plain PHP code
 *
 * @param array statement
 * @param bool extendsMode
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForeach)
{
	zval compilation;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, prefix, level, prefixLevel, expr, exprCode, bstatement, type, blockStatements, forElse, code, loopContext, iterator, key, ifExpr, variable, _4, *_0$$4, _1$$4, _2$$7, _3$$10, _5$$11, _6$$11, _7$$11, _8$$11, _9$$11, _10$$11, _11$$11, _12$$11, _13$$11, _14$$13, _15$$14, _16$$15, _17$$15, _18$$17, _19$$17, _20$$17, _21$$17, _22$$17, _23$$17, _24$$18, _25$$22;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&prefixLevel);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&exprCode);
	ZVAL_UNDEF(&bstatement);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&blockStatements);
	ZVAL_UNDEF(&forElse);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&loopContext);
	ZVAL_UNDEF(&iterator);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&ifExpr);
	ZVAL_UNDEF(&variable);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$10);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_22$$17);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&_25$$22);
	ZVAL_UNDEF(&compilation);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(statement)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &statement_param, &extendsMode_param);
	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		}
	if (UNEXPECTED(!(zephir_array_isset_string(&statement, SL("expr"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 764);
		return;
	}
	ZEPHIR_INIT_VAR(&compilation);
	ZEPHIR_INIT_VAR(&forElse);
	ZVAL_NULL(&forElse);
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("foreachLevel")));
	ZEPHIR_CALL_METHOD(&prefix, this_ptr, "getuniqueprefix", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&level);
	zephir_read_property(&level, this_ptr, ZEND_STRL("foreachLevel"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&prefixLevel);
	ZEPHIR_CONCAT_VV(&prefixLevel, &prefix, &level);
	zephir_memory_observe(&expr);
	zephir_array_fetch_string(&expr, &statement, SL("expr"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 782);
	ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", NULL, 503, &expr);
	zephir_check_call_status();
	zephir_memory_observe(&blockStatements);
	zephir_array_fetch_string(&blockStatements, &statement, SL("block_statements"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 788);
	ZEPHIR_INIT_NVAR(&forElse);
	ZVAL_BOOL(&forElse, 0);
	if (Z_TYPE_P(&blockStatements) == IS_ARRAY) {
		zephir_is_iterable(&blockStatements, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 808);
		if (Z_TYPE_P(&blockStatements) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&blockStatements), _0$$4)
			{
				ZEPHIR_INIT_NVAR(&bstatement);
				ZVAL_COPY(&bstatement, _0$$4);
				ZEPHIR_OBS_NVAR(&type);
				if (!(zephir_array_isset_string_fetch(&type, &bstatement, SL("type"), 0))) {
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 321)) {
					ZEPHIR_INIT_NVAR(&_2$$7);
					ZEPHIR_CONCAT_SVS(&_2$$7, "<?php $", &prefixLevel, "iterated = false; ?>");
					zephir_concat_self(&compilation, &_2$$7);
					ZEPHIR_CPY_WRT(&forElse, &prefixLevel);
					zephir_update_property_array(this_ptr, SL("forElsePointers"), &level, &forElse);
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &blockStatements, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$4, &blockStatements, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&bstatement, &blockStatements, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&type);
					if (!(zephir_array_isset_string_fetch(&type, &bstatement, SL("type"), 0))) {
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 321)) {
						ZEPHIR_INIT_NVAR(&_3$$10);
						ZEPHIR_CONCAT_SVS(&_3$$10, "<?php $", &prefixLevel, "iterated = false; ?>");
						zephir_concat_self(&compilation, &_3$$10);
						ZEPHIR_CPY_WRT(&forElse, &prefixLevel);
						zephir_update_property_array(this_ptr, SL("forElsePointers"), &level, &forElse);
						break;
					}
				ZEPHIR_CALL_METHOD(NULL, &blockStatements, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&bstatement);
	}
	if (extendsMode) {
		ZVAL_BOOL(&_4, 1);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	ZEPHIR_CALL_METHOD(&code, this_ptr, "statementlist", NULL, 505, &blockStatements, &_4);
	zephir_check_call_status();
	zephir_memory_observe(&loopContext);
	zephir_read_property(&loopContext, this_ptr, ZEND_STRL("loopPointers"), PH_NOISY_CC);
	if (zephir_array_isset(&loopContext, &level)) {
		ZEPHIR_INIT_VAR(&_5$$11);
		ZEPHIR_CONCAT_SVSVS(&_5$$11, "<?php $", &prefixLevel, "iterator = ", &exprCode, "; ");
		zephir_concat_self(&compilation, &_5$$11);
		ZEPHIR_INIT_VAR(&_6$$11);
		ZEPHIR_CONCAT_SVS(&_6$$11, "$", &prefixLevel, "incr = 0; ");
		zephir_concat_self(&compilation, &_6$$11);
		ZEPHIR_INIT_VAR(&_7$$11);
		ZEPHIR_CONCAT_SVS(&_7$$11, "$", &prefixLevel, "loop = new stdClass(); ");
		zephir_concat_self(&compilation, &_7$$11);
		ZEPHIR_INIT_VAR(&_8$$11);
		ZEPHIR_CONCAT_SVSVS(&_8$$11, "$", &prefixLevel, "loop->self = &$", &prefixLevel, "loop; ");
		zephir_concat_self(&compilation, &_8$$11);
		ZEPHIR_INIT_VAR(&_9$$11);
		ZEPHIR_CONCAT_SVSVS(&_9$$11, "$", &prefixLevel, "loop->length = count($", &prefixLevel, "iterator); ");
		zephir_concat_self(&compilation, &_9$$11);
		ZEPHIR_INIT_VAR(&_10$$11);
		ZEPHIR_CONCAT_SVS(&_10$$11, "$", &prefixLevel, "loop->index = 1; ");
		zephir_concat_self(&compilation, &_10$$11);
		ZEPHIR_INIT_VAR(&_11$$11);
		ZEPHIR_CONCAT_SVS(&_11$$11, "$", &prefixLevel, "loop->index0 = 1; ");
		zephir_concat_self(&compilation, &_11$$11);
		ZEPHIR_INIT_VAR(&_12$$11);
		ZEPHIR_CONCAT_SVSVS(&_12$$11, "$", &prefixLevel, "loop->revindex = $", &prefixLevel, "loop->length; ");
		zephir_concat_self(&compilation, &_12$$11);
		ZEPHIR_INIT_VAR(&_13$$11);
		ZEPHIR_CONCAT_SVSVS(&_13$$11, "$", &prefixLevel, "loop->revindex0 = $", &prefixLevel, "loop->length - 1; ?>");
		zephir_concat_self(&compilation, &_13$$11);
		ZEPHIR_INIT_VAR(&iterator);
		ZEPHIR_CONCAT_SVS(&iterator, "$", &prefixLevel, "iterator");
	} else {
		ZEPHIR_CPY_WRT(&iterator, &exprCode);
	}
	zephir_memory_observe(&variable);
	zephir_array_fetch_string(&variable, &statement, SL("variable"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 838);
	zephir_memory_observe(&key);
	if (zephir_array_isset_string_fetch(&key, &statement, SL("key"), 0)) {
		ZEPHIR_INIT_VAR(&_14$$13);
		ZEPHIR_CONCAT_SVSVSVS(&_14$$13, "<?php foreach (", &iterator, " as $", &key, " => $", &variable, ") { ");
		zephir_concat_self(&compilation, &_14$$13);
	} else {
		ZEPHIR_INIT_VAR(&_15$$14);
		ZEPHIR_CONCAT_SVSVS(&_15$$14, "<?php foreach (", &iterator, " as $", &variable, ") { ");
		zephir_concat_self(&compilation, &_15$$14);
	}
	zephir_memory_observe(&ifExpr);
	if (zephir_array_isset_string_fetch(&ifExpr, &statement, SL("if_expr"), 0)) {
		ZEPHIR_CALL_METHOD(&_16$$15, this_ptr, "expression", NULL, 503, &ifExpr);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_17$$15);
		ZEPHIR_CONCAT_SVS(&_17$$15, "if (", &_16$$15, ") { ?>");
		zephir_concat_self(&compilation, &_17$$15);
	} else {
		zephir_concat_self_str(&compilation, "?>", sizeof("?>") - 1);
	}
	if (zephir_array_isset(&loopContext, &level)) {
		ZEPHIR_INIT_VAR(&_18$$17);
		ZEPHIR_CONCAT_SVSVS(&_18$$17, "<?php $", &prefixLevel, "loop->first = ($", &prefixLevel, "incr == 0); ");
		zephir_concat_self(&compilation, &_18$$17);
		ZEPHIR_INIT_VAR(&_19$$17);
		ZEPHIR_CONCAT_SVSVS(&_19$$17, "$", &prefixLevel, "loop->index = $", &prefixLevel, "incr + 1; ");
		zephir_concat_self(&compilation, &_19$$17);
		ZEPHIR_INIT_VAR(&_20$$17);
		ZEPHIR_CONCAT_SVSVS(&_20$$17, "$", &prefixLevel, "loop->index0 = $", &prefixLevel, "incr; ");
		zephir_concat_self(&compilation, &_20$$17);
		ZEPHIR_INIT_VAR(&_21$$17);
		ZEPHIR_CONCAT_SVSVSVS(&_21$$17, "$", &prefixLevel, "loop->revindex = $", &prefixLevel, "loop->length - $", &prefixLevel, "incr; ");
		zephir_concat_self(&compilation, &_21$$17);
		ZEPHIR_INIT_VAR(&_22$$17);
		ZEPHIR_CONCAT_SVSVSVS(&_22$$17, "$", &prefixLevel, "loop->revindex0 = $", &prefixLevel, "loop->length - ($", &prefixLevel, "incr + 1); ");
		zephir_concat_self(&compilation, &_22$$17);
		ZEPHIR_INIT_VAR(&_23$$17);
		ZEPHIR_CONCAT_SVSVSVS(&_23$$17, "$", &prefixLevel, "loop->last = ($", &prefixLevel, "incr == ($", &prefixLevel, "loop->length - 1)); ?>");
		zephir_concat_self(&compilation, &_23$$17);
	}
	if (Z_TYPE_P(&forElse) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_24$$18);
		ZEPHIR_CONCAT_SVS(&_24$$18, "<?php $", &forElse, "iterated = true; ?>");
		zephir_concat_self(&compilation, &_24$$18);
	}
	zephir_concat_self(&compilation, &code);
	if (zephir_array_isset_string(&statement, SL("if_expr"))) {
		zephir_concat_self_str(&compilation, "<?php } ?>", sizeof("<?php } ?>") - 1);
	}
	if (Z_TYPE_P(&forElse) == IS_STRING) {
		zephir_concat_self_str(&compilation, "<?php } ?>", sizeof("<?php } ?>") - 1);
	} else {
		if (zephir_array_isset(&loopContext, &level)) {
			ZEPHIR_INIT_VAR(&_25$$22);
			ZEPHIR_CONCAT_SVS(&_25$$22, "<?php $", &prefixLevel, "incr++; } ?>");
			zephir_concat_self(&compilation, &_25$$22);
		} else {
			zephir_concat_self_str(&compilation, "<?php } ?>", sizeof("<?php } ?>") - 1);
		}
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("foreachLevel")));
	RETURN_CTOR(&compilation);
}

/**
 * Generates a 'forelse' PHP code
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForElse)
{
	zval level, prefix, _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&level);
	zephir_read_property(&level, this_ptr, ZEND_STRL("foreachLevel"), PH_NOISY_CC);
	zephir_memory_observe(&prefix);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("forElsePointers"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&prefix, &_0, &level, 0))) {
		RETURN_MM_STRING("");
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("loopPointers"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &level)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "<?php $", &prefix, "incr++; } if (!$", &prefix, "iterated) { ?>");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "<?php } if (!$", &prefix, "iterated) { ?>");
	RETURN_MM();
}

/**
 * Compiles a 'if' statement returning PHP code
 *
 * @param array statement
 * @param bool extendsMode
 *
 * @throws \Phalcon\Mvc\View\Engine\Volt\Exception
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileIf)
{
	zval compilation;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, blockStatements, expr, _2, _3, _4, _5, _6, _0$$3, _1$$3, _7$$4, _8$$4, _9$$4;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&blockStatements);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&compilation);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(statement)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &statement_param, &extendsMode_param);
	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		}
	zephir_memory_observe(&expr);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Corrupt statement");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 504, &_1$$3, &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 941);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 503, &expr);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, &statement, SL("true_statements"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 947);
	if (extendsMode) {
		ZVAL_BOOL(&_5, 1);
	} else {
		ZVAL_BOOL(&_5, 0);
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "statementlist", NULL, 505, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SVSV(&_6, "<?php if (", &_2, ") { ?>", &_3);
	zephir_get_strval(&compilation, &_6);
	zephir_memory_observe(&blockStatements);
	if (zephir_array_isset_string_fetch(&blockStatements, &statement, SL("false_statements"), 0)) {
		if (extendsMode) {
			ZVAL_BOOL(&_8$$4, 1);
		} else {
			ZVAL_BOOL(&_8$$4, 0);
		}
		ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "statementlist", NULL, 505, &blockStatements, &_8$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$4);
		ZEPHIR_CONCAT_SV(&_9$$4, "<?php } else { ?>", &_7$$4);
		zephir_concat_self(&compilation, &_9$$4);
	}
	zephir_concat_self_str(&compilation, "<?php } ?>", sizeof("<?php } ?>") - 1);
	RETURN_CTOR(&compilation);
}

/**
 * Compiles a 'include' statement returning PHP code
 *
 * @param array statement
 *
 * @throws \Phalcon\Mvc\View\Engine\Volt\Exception
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileInclude)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, pathExpr, path, subCompiler, finalPath, compilation, params, _0, _3, _1$$5, _2$$6;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&pathExpr);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&subCompiler);
	ZVAL_UNDEF(&finalPath);
	ZVAL_UNDEF(&compilation);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(statement)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &statement_param);
	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	zephir_memory_observe(&pathExpr);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&pathExpr, &statement, SL("path"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 981);
		return;
	}
	zephir_array_fetch_string(&_0, &pathExpr, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 988);
	if (ZEPHIR_IS_LONG(&_0, 260)) {
		if (!(zephir_array_isset_string(&statement, SL("params")))) {
			zephir_memory_observe(&path);
			zephir_array_fetch_string(&path, &pathExpr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 997);
			ZEPHIR_CALL_METHOD(&finalPath, this_ptr, "getfinalpath", NULL, 0, &path);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&subCompiler);
			if (zephir_clone(&subCompiler, this_ptr) == FAILURE) {
				RETURN_MM();
			}
			ZVAL_BOOL(&_1$$5, 0);
			ZEPHIR_CALL_METHOD(&compilation, &subCompiler, "compile", NULL, 0, &finalPath, &_1$$5);
			zephir_check_call_status();
			if (Z_TYPE_P(&compilation) == IS_NULL) {
				ZEPHIR_CALL_METHOD(&_2$$6, &subCompiler, "getcompiledtemplatepath", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&compilation);
				zephir_file_get_contents(&compilation, &_2$$6);
			}
			RETURN_CCTOR(&compilation);
		}
	}
	ZEPHIR_CALL_METHOD(&path, this_ptr, "expression", NULL, 503, &pathExpr);
	zephir_check_call_status();
	zephir_memory_observe(&params);
	if (!(zephir_array_isset_string_fetch(&params, &statement, SL("params"), 0))) {
		ZEPHIR_CONCAT_SVS(return_value, "<?php $this->partial(", &path, "); ?>");
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "expression", NULL, 503, &params);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "<?php $this->partial(", &path, ", ", &_3, "); ?>");
	RETURN_MM();
}

/**
 * Compiles macros
 *
 * @param array statement
 * @param bool extendsMode
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileMacro)
{
	zend_string *_9$$6;
	zend_ulong _8$$6;
	zval code, macroName, _28, _4$$5, _5$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, name, defaultValue, parameters, position, parameter, variableName, blockStatements, _0, _3, _1$$4, _2$$4, *_6$$6, _7$$6, _10$$7, _11$$7, _12$$7, _13$$7, _14$$8, _16$$8, _17$$9, _18$$10, _19$$10, _20$$10, _21$$10, _22$$11, _23$$11, _24$$12, _25$$13, _26$$13, _27$$13;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&parameter);
	ZVAL_UNDEF(&variableName);
	ZVAL_UNDEF(&blockStatements);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&macroName);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(statement)
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &statement_param, &extendsMode_param);
	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	zephir_memory_observe(&name);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&name, &statement, SL("name"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1056);
		return;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("macros"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(zephir_array_isset(&_0, &name))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SVS(&_2$$4, "Macro '", &name, "' is already defined");
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 504, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1063);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("macros"), &name, &name);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVS(&_3, "$this->macros['", &name, "']");
	zephir_get_strval(&macroName, &_3);
	ZEPHIR_INIT_VAR(&code);
	ZVAL_STRING(&code, "<?php ");
	zephir_memory_observe(&parameters);
	if (!(zephir_array_isset_string_fetch(&parameters, &statement, SL("parameters"), 0))) {
		ZEPHIR_INIT_VAR(&_4$$5);
		ZEPHIR_CONCAT_VS(&_4$$5, &macroName, " = function() { ?>");
		zephir_concat_self(&code, &_4$$5);
	} else {
		ZEPHIR_INIT_VAR(&_5$$6);
		ZEPHIR_CONCAT_VS(&_5$$6, &macroName, " = function($__p = null) { ");
		zephir_concat_self(&code, &_5$$6);
		zephir_is_iterable(&parameters, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1100);
		if (Z_TYPE_P(&parameters) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parameters), _8$$6, _9$$6, _6$$6)
			{
				ZEPHIR_INIT_NVAR(&position);
				if (_9$$6 != NULL) { 
					ZVAL_STR_COPY(&position, _9$$6);
				} else {
					ZVAL_LONG(&position, _8$$6);
				}
				ZEPHIR_INIT_NVAR(&parameter);
				ZVAL_COPY(&parameter, _6$$6);
				ZEPHIR_OBS_NVAR(&variableName);
				zephir_array_fetch_string(&variableName, &parameter, SL("variable"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1082);
				ZEPHIR_INIT_NVAR(&_10$$7);
				ZEPHIR_CONCAT_SVS(&_10$$7, "if (isset($__p[", &position, "])) { ");
				zephir_concat_self(&code, &_10$$7);
				ZEPHIR_INIT_NVAR(&_11$$7);
				ZEPHIR_CONCAT_SVSVS(&_11$$7, "$", &variableName, " = $__p[", &position, "];");
				zephir_concat_self(&code, &_11$$7);
				zephir_concat_self_str(&code, " } else { ", sizeof(" } else { ") - 1);
				ZEPHIR_INIT_NVAR(&_12$$7);
				ZEPHIR_CONCAT_SVS(&_12$$7, "if (array_key_exists(\"", &variableName, "\", $__p)) { ");
				zephir_concat_self(&code, &_12$$7);
				ZEPHIR_INIT_NVAR(&_13$$7);
				ZEPHIR_CONCAT_SVSVS(&_13$$7, "$", &variableName, " = $__p[\"", &variableName, "\"];");
				zephir_concat_self(&code, &_13$$7);
				zephir_concat_self_str(&code, " } else { ", sizeof(" } else { ") - 1);
				ZEPHIR_OBS_NVAR(&defaultValue);
				if (EXPECTED(zephir_array_isset_string_fetch(&defaultValue, &parameter, SL("default"), 0))) {
					ZEPHIR_CALL_METHOD(&_14$$8, this_ptr, "expression", &_15, 503, &defaultValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_16$$8);
					ZEPHIR_CONCAT_SVSVS(&_16$$8, "$", &variableName, " = ", &_14$$8, ";");
					zephir_concat_self(&code, &_16$$8);
				} else {
					ZEPHIR_INIT_NVAR(&_17$$9);
					ZEPHIR_CONCAT_SVSVS(&_17$$9, " throw new \\Phalcon\\Mvc\\View\\Exception(\"Macro '", &name, "' was called without parameter: ", &variableName, "\"); ");
					zephir_concat_self(&code, &_17$$9);
				}
				zephir_concat_self_str(&code, " } } ", sizeof(" } } ") - 1);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &parameters, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_7$$6, &parameters, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&position, &parameters, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&parameter, &parameters, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&variableName);
					zephir_array_fetch_string(&variableName, &parameter, SL("variable"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1082);
					ZEPHIR_INIT_NVAR(&_18$$10);
					ZEPHIR_CONCAT_SVS(&_18$$10, "if (isset($__p[", &position, "])) { ");
					zephir_concat_self(&code, &_18$$10);
					ZEPHIR_INIT_NVAR(&_19$$10);
					ZEPHIR_CONCAT_SVSVS(&_19$$10, "$", &variableName, " = $__p[", &position, "];");
					zephir_concat_self(&code, &_19$$10);
					zephir_concat_self_str(&code, " } else { ", sizeof(" } else { ") - 1);
					ZEPHIR_INIT_NVAR(&_20$$10);
					ZEPHIR_CONCAT_SVS(&_20$$10, "if (array_key_exists(\"", &variableName, "\", $__p)) { ");
					zephir_concat_self(&code, &_20$$10);
					ZEPHIR_INIT_NVAR(&_21$$10);
					ZEPHIR_CONCAT_SVSVS(&_21$$10, "$", &variableName, " = $__p[\"", &variableName, "\"];");
					zephir_concat_self(&code, &_21$$10);
					zephir_concat_self_str(&code, " } else { ", sizeof(" } else { ") - 1);
					ZEPHIR_OBS_NVAR(&defaultValue);
					if (EXPECTED(zephir_array_isset_string_fetch(&defaultValue, &parameter, SL("default"), 0))) {
						ZEPHIR_CALL_METHOD(&_22$$11, this_ptr, "expression", &_15, 503, &defaultValue);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_23$$11);
						ZEPHIR_CONCAT_SVSVS(&_23$$11, "$", &variableName, " = ", &_22$$11, ";");
						zephir_concat_self(&code, &_23$$11);
					} else {
						ZEPHIR_INIT_NVAR(&_24$$12);
						ZEPHIR_CONCAT_SVSVS(&_24$$12, " throw new \\Phalcon\\Mvc\\View\\Exception(\"Macro '", &name, "' was called without parameter: ", &variableName, "\"); ");
						zephir_concat_self(&code, &_24$$12);
					}
					zephir_concat_self_str(&code, " } } ", sizeof(" } } ") - 1);
				ZEPHIR_CALL_METHOD(NULL, &parameters, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&parameter);
		ZEPHIR_INIT_NVAR(&position);
		zephir_concat_self_str(&code, " ?>", sizeof(" ?>") - 1);
	}
	zephir_memory_observe(&blockStatements);
	if (zephir_array_isset_string_fetch(&blockStatements, &statement, SL("block_statements"), 0)) {
		if (extendsMode) {
			ZVAL_BOOL(&_26$$13, 1);
		} else {
			ZVAL_BOOL(&_26$$13, 0);
		}
		ZEPHIR_CALL_METHOD(&_25$$13, this_ptr, "statementlist", NULL, 505, &blockStatements, &_26$$13);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_27$$13);
		ZEPHIR_CONCAT_VS(&_27$$13, &_25$$13, "<?php }; ");
		zephir_concat_self(&code, &_27$$13);
	} else {
		zephir_concat_self_str(&code, "<?php }; ", sizeof("<?php }; ") - 1);
	}
	ZEPHIR_INIT_VAR(&_28);
	ZEPHIR_CONCAT_VSVS(&_28, &macroName, " = \\Closure::bind(", &macroName, ", $this); ?>");
	zephir_concat_self(&code, &_28);
	RETURN_CTOR(&code);
}

/**
 * Compiles a "return" statement returning PHP code
 *
 * @throws \Phalcon\Mvc\View\Engine\Volt\Exception
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileReturn)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, expr, _0;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(statement)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &statement_param);
	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	zephir_memory_observe(&expr);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1137);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "expression", NULL, 503, &expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php return ", &_0, "; ?>");
	RETURN_MM();
}

/**
 * Compiles a "set" statement returning PHP code. The method accepts an
 * array produced by the Volt parser and creates the `set` statement in PHP.
 * This method is not particularly useful in development, since it requires
 * advanced knowledge of the Volt parser.
 *
 * ```php
 * <?php
 *
 * use Phalcon\Mvc\View\Engine\Volt\Compiler;
 *
 * $compiler = new Compiler();
 *
 * // {% set a = ['first': 1] %}

 * $source = [
 *     "type" => 306,
 *     "assignments" => [
 *         [
 *             "variable" => [
 *                 "type" => 265,
 *                 "value" => "a",
 *                 "file" => "eval code",
 *                 "line" => 1
 *             ],
 *             "op" => 61,
 *             "expr" => [
 *                 "type" => 360,
 *                 "left" => [
 *                     [
 *                         "expr" => [
 *                             "type" => 258,
 *                             "value" => "1",
 *                             "file" => "eval code",
 *                             "line" => 1
 *                         ],
 *                         "name" => "first",
 *                         "file" => "eval code",
 *                         "line" => 1
 *                     ]
 *                 ],
 *                 "file" => "eval code",
 *                 "line" => 1
 *             ],
 *             "file" => "eval code",
 *             "line" => 1
 *         ]
 *     ]
 * ];
 *
 * echo $compiler->compileSet($source);
 * // <?php $a = ['first' => 1]; ?>";
 * ```
 *
 * @param array $statement
 *
 * @throws \Phalcon\Mvc\View\Engine\Volt\Exception
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSet)
{
	zval compilation;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, assignments, assignment, exprCode, target, *_0, _1, _2$$4, _4$$4, _5$$4, _6$$5, _7$$6, _8$$7, _9$$8, _10$$9, _11$$10, _12$$10, _13$$10, _14$$11, _15$$12, _16$$13, _17$$14, _18$$15;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&assignments);
	ZVAL_UNDEF(&assignment);
	ZVAL_UNDEF(&exprCode);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&compilation);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(statement)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &statement_param);
	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	zephir_memory_observe(&assignments);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&assignments, &statement, SL("assignments"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1214);
		return;
	}
	ZEPHIR_INIT_VAR(&compilation);
	ZVAL_STRING(&compilation, "<?php");
	zephir_is_iterable(&assignments, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1263);
	if (Z_TYPE_P(&assignments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&assignments), _0)
		{
			ZEPHIR_INIT_NVAR(&assignment);
			ZVAL_COPY(&assignment, _0);
			zephir_array_fetch_string(&_2$$4, &assignment, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1225);
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", &_3, 503, &_2$$4);
			zephir_check_call_status();
			zephir_array_fetch_string(&_4$$4, &assignment, SL("variable"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1232);
			ZEPHIR_CALL_METHOD(&target, this_ptr, "expression", &_3, 503, &_4$$4);
			zephir_check_call_status();
			zephir_array_fetch_string(&_5$$4, &assignment, SL("op"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1238);
			do {
				if (ZEPHIR_IS_LONG(&_5$$4, 281)) {
					ZEPHIR_INIT_NVAR(&_6$$5);
					ZEPHIR_CONCAT_SVSVS(&_6$$5, " ", &target, " += ", &exprCode, ";");
					zephir_concat_self(&compilation, &_6$$5);
					break;
				}
				if (ZEPHIR_IS_LONG(&_5$$4, 282)) {
					ZEPHIR_INIT_NVAR(&_7$$6);
					ZEPHIR_CONCAT_SVSVS(&_7$$6, " ", &target, " -= ", &exprCode, ";");
					zephir_concat_self(&compilation, &_7$$6);
					break;
				}
				if (ZEPHIR_IS_LONG(&_5$$4, 283)) {
					ZEPHIR_INIT_NVAR(&_8$$7);
					ZEPHIR_CONCAT_SVSVS(&_8$$7, " ", &target, " *= ", &exprCode, ";");
					zephir_concat_self(&compilation, &_8$$7);
					break;
				}
				if (ZEPHIR_IS_LONG(&_5$$4, 284)) {
					ZEPHIR_INIT_NVAR(&_9$$8);
					ZEPHIR_CONCAT_SVSVS(&_9$$8, " ", &target, " /= ", &exprCode, ";");
					zephir_concat_self(&compilation, &_9$$8);
					break;
				}
				ZEPHIR_INIT_NVAR(&_10$$9);
				ZEPHIR_CONCAT_SVSVS(&_10$$9, " ", &target, " = ", &exprCode, ";");
				zephir_concat_self(&compilation, &_10$$9);
				break;
			} while(0);

		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &assignments, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &assignments, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&assignment, &assignments, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_string(&_11$$10, &assignment, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1225);
				ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", &_3, 503, &_11$$10);
				zephir_check_call_status();
				zephir_array_fetch_string(&_12$$10, &assignment, SL("variable"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1232);
				ZEPHIR_CALL_METHOD(&target, this_ptr, "expression", &_3, 503, &_12$$10);
				zephir_check_call_status();
				zephir_array_fetch_string(&_13$$10, &assignment, SL("op"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1238);
				do {
					if (ZEPHIR_IS_LONG(&_13$$10, 281)) {
						ZEPHIR_INIT_NVAR(&_14$$11);
						ZEPHIR_CONCAT_SVSVS(&_14$$11, " ", &target, " += ", &exprCode, ";");
						zephir_concat_self(&compilation, &_14$$11);
						break;
					}
					if (ZEPHIR_IS_LONG(&_13$$10, 282)) {
						ZEPHIR_INIT_NVAR(&_15$$12);
						ZEPHIR_CONCAT_SVSVS(&_15$$12, " ", &target, " -= ", &exprCode, ";");
						zephir_concat_self(&compilation, &_15$$12);
						break;
					}
					if (ZEPHIR_IS_LONG(&_13$$10, 283)) {
						ZEPHIR_INIT_NVAR(&_16$$13);
						ZEPHIR_CONCAT_SVSVS(&_16$$13, " ", &target, " *= ", &exprCode, ";");
						zephir_concat_self(&compilation, &_16$$13);
						break;
					}
					if (ZEPHIR_IS_LONG(&_13$$10, 284)) {
						ZEPHIR_INIT_NVAR(&_17$$14);
						ZEPHIR_CONCAT_SVSVS(&_17$$14, " ", &target, " /= ", &exprCode, ";");
						zephir_concat_self(&compilation, &_17$$14);
						break;
					}
					ZEPHIR_INIT_NVAR(&_18$$15);
					ZEPHIR_CONCAT_SVSVS(&_18$$15, " ", &target, " = ", &exprCode, ";");
					zephir_concat_self(&compilation, &_18$$15);
					break;
				} while(0);

			ZEPHIR_CALL_METHOD(NULL, &assignments, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&assignment);
	zephir_concat_self_str(&compilation, " ?>", sizeof(" ?>") - 1);
	RETURN_CTOR(&compilation);
}

/**
 * Compiles a template into a string
 *
 *```php
 * echo $compiler->compileString({% raw %}'{{ "hello world" }}'{% endraw %});
 *```
 *
 * @param string viewCode
 * @param bool extendsMode
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *viewCode_param = NULL, *extendsMode_param = NULL, _0, _1;
	zval viewCode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewCode);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(viewCode)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &viewCode_param, &extendsMode_param);
	if (UNEXPECTED(Z_TYPE_P(viewCode_param) != IS_STRING && Z_TYPE_P(viewCode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewCode' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewCode_param) == IS_STRING)) {
		zephir_get_strval(&viewCode, viewCode_param);
	} else {
		ZEPHIR_INIT_VAR(&viewCode);
	}
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "eval code");
	zephir_update_property_zval(this_ptr, ZEND_STRL("currentPath"), &_0);
	if (extendsMode) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "compilesource", NULL, 0, &viewCode, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Compiles a 'switch' statement returning PHP code
 *
 * @param array statement
 * @param bool extendsMode
 *
 * @throws \Phalcon\Mvc\View\Engine\Volt\Exception
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSwitch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, compilation, caseClauses, expr, lines, _2, _0$$3, _1$$3, _3$$4, _4$$5, _5$$5, _6$$5;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&compilation);
	ZVAL_UNDEF(&caseClauses);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(statement)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &statement_param, &extendsMode_param);
	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		}
	zephir_memory_observe(&expr);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Corrupt statement");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 504, &_1$$3, &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1304);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 503, &expr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&compilation);
	ZEPHIR_CONCAT_SVS(&compilation, "<?php switch (", &_2, "): ?>");
	zephir_memory_observe(&caseClauses);
	if (zephir_array_isset_string_fetch(&caseClauses, &statement, SL("case_clauses"), 0)) {
		if (extendsMode) {
			ZVAL_BOOL(&_3$$4, 1);
		} else {
			ZVAL_BOOL(&_3$$4, 0);
		}
		ZEPHIR_CALL_METHOD(&lines, this_ptr, "statementlist", NULL, 505, &caseClauses, &_3$$4);
		zephir_check_call_status();
		if (zephir_fast_strlen_ev(&lines) != 0) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "/(*ANYCRLF)^\\h+|\\h+$|(\\h){2,}/mu");
			ZEPHIR_INIT_VAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "");
			ZEPHIR_CALL_FUNCTION(&_6$$5, "preg_replace", NULL, 41, &_4$$5, &_5$$5, &lines);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&lines, &_6$$5);
		}
		zephir_concat_self(&compilation, &lines);
	}
	zephir_concat_self_str(&compilation, SL("<?php endswitch ?>"));
	RETURN_CCTOR(&compilation);
}

/**
 * Resolves an expression node in an AST volt tree
 *
 * @param array $expr
 * @param bool  $doubleQuotes
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, expression)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_8 = NULL, *_13 = NULL, *_16 = NULL, *_18 = NULL, *_27 = NULL, *_37 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool doubleQuotes;
	zval *expr_param = NULL, *doubleQuotes_param = NULL, end, endCode, exprCode, extensions, items, left, leftCode, name, right, rightCode, singleExpr, singleExprCode, start, startCode, type, _0, _2$$4, *_4$$6, _5$$6, _6$$7, _7$$7, _9$$8, _10$$10, _11$$10, _12$$11, _14$$14, _15$$15, _17$$16, _19$$17, _20$$35, _21$$35, _22$$35, _23$$35, _24$$36, _25$$40, _26$$50, _28$$54, _29$$56, _30$$74, _31$$74, _32$$74, _33$$78, _34$$78, _35$$78, _36$$78;
	zval expr, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&end);
	ZVAL_UNDEF(&endCode);
	ZVAL_UNDEF(&exprCode);
	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&leftCode);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&rightCode);
	ZVAL_UNDEF(&singleExpr);
	ZVAL_UNDEF(&singleExprCode);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&startCode);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_20$$35);
	ZVAL_UNDEF(&_21$$35);
	ZVAL_UNDEF(&_22$$35);
	ZVAL_UNDEF(&_23$$35);
	ZVAL_UNDEF(&_24$$36);
	ZVAL_UNDEF(&_25$$40);
	ZVAL_UNDEF(&_26$$50);
	ZVAL_UNDEF(&_28$$54);
	ZVAL_UNDEF(&_29$$56);
	ZVAL_UNDEF(&_30$$74);
	ZVAL_UNDEF(&_31$$74);
	ZVAL_UNDEF(&_32$$74);
	ZVAL_UNDEF(&_33$$78);
	ZVAL_UNDEF(&_34$$78);
	ZVAL_UNDEF(&_35$$78);
	ZVAL_UNDEF(&_36$$78);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(expr)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(doubleQuotes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &expr_param, &doubleQuotes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);
	if (!doubleQuotes_param) {
		doubleQuotes = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&exprCode);
	ZVAL_NULL(&exprCode);
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("exprLevel")));
	zephir_read_property(&_0, this_ptr, ZEND_STRL("extensions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&extensions, &_0);
	while (1) {
		if (Z_TYPE_P(&extensions) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&_1$$4);
			zephir_create_array(&_1$$4, 1, 0);
			zephir_array_fast_append(&_1$$4, &expr);
			ZEPHIR_INIT_NVAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "resolveExpression");
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "fireextensionevent", &_3, 507, &_2$$4, &_1$$4);
			zephir_check_call_status();
			if (Z_TYPE_P(&exprCode) == IS_STRING) {
				break;
			}
		}
		ZEPHIR_OBS_NVAR(&type);
		if (!(zephir_array_isset_string_fetch(&type, &expr, SL("type"), 0))) {
			ZEPHIR_INIT_NVAR(&items);
			array_init(&items);
			zephir_is_iterable(&expr, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1403);
			if (Z_TYPE_P(&expr) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&expr), _4$$6)
				{
					ZEPHIR_INIT_NVAR(&singleExpr);
					ZVAL_COPY(&singleExpr, _4$$6);
					zephir_array_fetch_string(&_6$$7, &singleExpr, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1392);
					if (doubleQuotes) {
						ZVAL_BOOL(&_7$$7, 1);
					} else {
						ZVAL_BOOL(&_7$$7, 0);
					}
					ZEPHIR_CALL_METHOD(&singleExprCode, this_ptr, "expression", &_8, 503, &_6$$7, &_7$$7);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&name);
					if (zephir_array_isset_string_fetch(&name, &singleExpr, SL("name"), 0)) {
						ZEPHIR_INIT_NVAR(&_9$$8);
						ZEPHIR_CONCAT_SVSV(&_9$$8, "'", &name, "' => ", &singleExprCode);
						zephir_array_append(&items, &_9$$8, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1397);
					} else {
						zephir_array_append(&items, &singleExprCode, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1399);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &expr, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_5$$6, &expr, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_5$$6)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&singleExpr, &expr, "current", NULL, 0);
					zephir_check_call_status();
						zephir_array_fetch_string(&_10$$10, &singleExpr, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1392);
						if (doubleQuotes) {
							ZVAL_BOOL(&_11$$10, 1);
						} else {
							ZVAL_BOOL(&_11$$10, 0);
						}
						ZEPHIR_CALL_METHOD(&singleExprCode, this_ptr, "expression", &_8, 503, &_10$$10, &_11$$10);
						zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&name);
						if (zephir_array_isset_string_fetch(&name, &singleExpr, SL("name"), 0)) {
							ZEPHIR_INIT_NVAR(&_12$$11);
							ZEPHIR_CONCAT_SVSV(&_12$$11, "'", &name, "' => ", &singleExprCode);
							zephir_array_append(&items, &_12$$11, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1397);
						} else {
							zephir_array_append(&items, &singleExprCode, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1399);
						}
					ZEPHIR_CALL_METHOD(NULL, &expr, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&singleExpr);
			ZEPHIR_INIT_NVAR(&exprCode);
			zephir_fast_join_str(&exprCode, SL(", "), &items);
			break;
		}
		if (ZEPHIR_IS_LONG(&type, '.')) {
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "attributereader", &_13, 0, &expr);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_OBS_NVAR(&left);
		if (zephir_array_isset_string_fetch(&left, &expr, SL("left"), 0)) {
			if (doubleQuotes) {
				ZVAL_BOOL(&_14$$14, 1);
			} else {
				ZVAL_BOOL(&_14$$14, 0);
			}
			ZEPHIR_CALL_METHOD(&leftCode, this_ptr, "expression", &_8, 503, &left, &_14$$14);
			zephir_check_call_status();
		}
		if (ZEPHIR_IS_LONG(&type, 311)) {
			zephir_array_fetch_string(&_15$$15, &expr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1429);
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "resolvetest", &_16, 0, &_15$$15, &leftCode);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 124)) {
			zephir_array_fetch_string(&_17$$16, &expr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1441);
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "resolvefilter", &_18, 508, &_17$$16, &leftCode);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_OBS_NVAR(&right);
		if (zephir_array_isset_string_fetch(&right, &expr, SL("right"), 0)) {
			if (doubleQuotes) {
				ZVAL_BOOL(&_19$$17, 1);
			} else {
				ZVAL_BOOL(&_19$$17, 0);
			}
			ZEPHIR_CALL_METHOD(&rightCode, this_ptr, "expression", &_8, 503, &right, &_19$$17);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&exprCode);
		ZVAL_NULL(&exprCode);
		do {
			if (ZEPHIR_IS_LONG(&type, '!')) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SV(&exprCode, "!", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, '*')) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " * ", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, '+')) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " + ", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, '-')) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " - ", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, '/')) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " / ", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 37)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " % ", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, '<')) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " < ", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 61)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " > ", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 62)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " > ", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 126)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " . ", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 278)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVSVS(&exprCode, "pow(", &leftCode, ", ", &rightCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 360)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				if (zephir_array_isset_string(&expr, SL("left"))) {
					ZEPHIR_CONCAT_SVS(&exprCode, "[", &leftCode, "]");
				} else {
					ZVAL_STRING(&exprCode, "[]");
				}
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 258)) {
				ZEPHIR_OBS_NVAR(&exprCode);
				zephir_array_fetch_string(&exprCode, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1512);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 259)) {
				ZEPHIR_OBS_NVAR(&exprCode);
				zephir_array_fetch_string(&exprCode, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1516);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 260)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				if (EXPECTED(doubleQuotes == 0)) {
					ZEPHIR_INIT_NVAR(&_20$$35);
					zephir_array_fetch_string(&_21$$35, &expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1521);
					ZEPHIR_INIT_NVAR(&_22$$35);
					ZVAL_STRING(&_22$$35, "'");
					ZEPHIR_INIT_NVAR(&_23$$35);
					ZVAL_STRING(&_23$$35, "\\'");
					zephir_fast_str_replace(&_20$$35, &_22$$35, &_23$$35, &_21$$35);
					ZEPHIR_CONCAT_SVS(&exprCode, "'", &_20$$35, "'");
				} else {
					zephir_array_fetch_string(&_24$$36, &expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1523);
					ZEPHIR_CONCAT_SVS(&exprCode, "\"", &_24$$36, "\"");
				}
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 261)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZVAL_STRING(&exprCode, "null");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 262)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZVAL_STRING(&exprCode, "false");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 263)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZVAL_STRING(&exprCode, "true");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 265)) {
				zephir_array_fetch_string(&_25$$40, &expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1540);
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SV(&exprCode, "$", &_25$$40);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 266)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " && ", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 267)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " || ", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 270)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " <= ", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 271)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " >= ", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 272)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " == ", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 273)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " != ", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 274)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " === ", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 275)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " !== ", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 276)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVSVS(&exprCode, "range(", &leftCode, ", ", &rightCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 350)) {
				if (doubleQuotes) {
					ZVAL_BOOL(&_26$$50, 1);
				} else {
					ZVAL_BOOL(&_26$$50, 0);
				}
				ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "functioncall", &_27, 0, &expr, &_26$$50);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 356)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVS(&exprCode, "(", &leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 361)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_VSVS(&exprCode, &leftCode, "[", &rightCode, "]");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 365)) {
				ZEPHIR_OBS_NVAR(&start);
				if (zephir_array_isset_string_fetch(&start, &expr, SL("start"), 0)) {
					if (doubleQuotes) {
						ZVAL_BOOL(&_28$$54, 1);
					} else {
						ZVAL_BOOL(&_28$$54, 0);
					}
					ZEPHIR_CALL_METHOD(&startCode, this_ptr, "expression", &_8, 503, &start, &_28$$54);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&startCode);
					ZVAL_STRING(&startCode, "null");
				}
				ZEPHIR_OBS_NVAR(&end);
				if (zephir_array_isset_string_fetch(&end, &expr, SL("end"), 0)) {
					if (doubleQuotes) {
						ZVAL_BOOL(&_29$$56, 1);
					} else {
						ZVAL_BOOL(&_29$$56, 0);
					}
					ZEPHIR_CALL_METHOD(&endCode, this_ptr, "expression", &_8, 503, &end, &_29$$56);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&endCode);
					ZVAL_STRING(&endCode, "null");
				}
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVSVSVS(&exprCode, "$this->slice(", &leftCode, ", ", &startCode, ", ", &endCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 362)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVS(&exprCode, "!isset(", &leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 363)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVS(&exprCode, "isset(", &leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 392)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVS(&exprCode, "!empty(", &leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 386)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVS(&exprCode, "empty(", &leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 393)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVS(&exprCode, "!(((", &leftCode, ") % 2) == 0)");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 387)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVS(&exprCode, "(((", &leftCode, ") % 2) == 0)");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 394)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVS(&exprCode, "!(((", &leftCode, ") % 2) != 0)");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 388)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVS(&exprCode, "(((", &leftCode, ") % 2) != 0)");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 395)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVS(&exprCode, "!is_numeric(", &leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 389)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVS(&exprCode, "is_numeric(", &leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 396)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVS(&exprCode, "!is_scalar(", &leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 390)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVS(&exprCode, "is_scalar(", &leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 397)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVSVS(&exprCode, "!(is_array(", &leftCode, ") || (", &leftCode, ") instanceof Traversable)");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 391)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVSVS(&exprCode, "(is_array(", &leftCode, ") || (", &leftCode, ") instanceof Traversable)");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 309)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVSVS(&exprCode, "$this->isIncluded(", &leftCode, ", ", &rightCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 367)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVSVS(&exprCode, "!$this->isIncluded(", &leftCode, ", ", &rightCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 366)) {
				zephir_array_fetch_string(&_31$$74, &expr, SL("ternary"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1679);
				if (doubleQuotes) {
					ZVAL_BOOL(&_32$$74, 1);
				} else {
					ZVAL_BOOL(&_32$$74, 0);
				}
				ZEPHIR_CALL_METHOD(&_30$$74, this_ptr, "expression", &_8, 503, &_31$$74, &_32$$74);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVSVSVS(&exprCode, "(", &_30$$74, " ? ", &leftCode, " : ", &rightCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 368)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SV(&exprCode, "-", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 369)) {
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SV(&exprCode, "+", &rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 364)) {
				ZEPHIR_OBS_NVAR(&exprCode);
				zephir_array_fetch_string(&exprCode, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1691);
				break;
			}
			ZEPHIR_INIT_NVAR(&_33$$78);
			object_init_ex(&_33$$78, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_34$$78, &expr, SL("file"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1696);
			zephir_array_fetch_string(&_35$$78, &expr, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1697);
			ZEPHIR_INIT_NVAR(&_36$$78);
			ZEPHIR_CONCAT_SVSVSV(&_36$$78, "Unknown expression ", &type, " in ", &_34$$78, " on line ", &_35$$78);
			ZEPHIR_CALL_METHOD(NULL, &_33$$78, "__construct", &_37, 504, &_36$$78);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_33$$78, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1697);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

		break;
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("exprLevel")));
	RETURN_CCTOR(&exprCode);
}

/**
 * Fires an event to registered extensions
 *
 * @param string $name
 * @param array  $arguments
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, fireExtensionEvent)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, _3$$5, _4$$6, _5$$10, _6$$11;
	zval *name_param = NULL, *arguments_param = NULL, extensions, extension, status, _0, *_1, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_6$$11);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(arguments)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &name_param, &arguments_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
		zephir_get_arrval(&arguments, arguments_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("extensions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&extensions, &_0);
	zephir_is_iterable(&extensions, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1745);
	if (Z_TYPE_P(&extensions) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _1)
		{
			ZEPHIR_INIT_NVAR(&extension);
			ZVAL_COPY(&extension, _1);
			if ((zephir_method_exists(&extension, &name)  == SUCCESS)) {
				if (!(ZEPHIR_IS_EMPTY(&arguments))) {
					ZEPHIR_INIT_NVAR(&_3$$5);
					zephir_create_array(&_3$$5, 2, 0);
					zephir_array_fast_append(&_3$$5, &extension);
					zephir_array_fast_append(&_3$$5, &name);
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &_3$$5, &arguments);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_4$$6);
					zephir_create_array(&_4$$6, 2, 0);
					zephir_array_fast_append(&_4$$6, &extension);
					zephir_array_fast_append(&_4$$6, &name);
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC(&status, &_4$$6);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&status) == IS_STRING) {
					RETURN_CCTOR(&status);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &extensions, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &extensions, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&extension, &extensions, "current", NULL, 0);
			zephir_check_call_status();
				if ((zephir_method_exists(&extension, &name)  == SUCCESS)) {
					if (!(ZEPHIR_IS_EMPTY(&arguments))) {
						ZEPHIR_INIT_NVAR(&_5$$10);
						zephir_create_array(&_5$$10, 2, 0);
						zephir_array_fast_append(&_5$$10, &extension);
						zephir_array_fast_append(&_5$$10, &name);
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &_5$$10, &arguments);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&_6$$11);
						zephir_create_array(&_6$$11, 2, 0);
						zephir_array_fast_append(&_6$$11, &extension);
						zephir_array_fast_append(&_6$$11, &name);
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &_6$$11);
						zephir_check_call_status();
					}
					if (Z_TYPE_P(&status) == IS_STRING) {
						RETURN_CCTOR(&status);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &extensions, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&extension);
	ZEPHIR_MM_RESTORE();
}

/**
 * Resolves function intermediate code into PHP function calls
 *
 * @param array $expr
 * @param bool  $doubleQuotes
 *
 * @throws \Phalcon\Mvc\View\Engine\Volt\Exception
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, functionCall)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool doubleQuotes, _9$$5, _15$$5;
	zval *expr_param = NULL, *doubleQuotes_param = NULL, __$true, arguments, arrayHelpers, block, code, currentBlock, definition, escapedCode, exprLevel, extendedBlocks, extensions, funcArguments, functions, method, name, nameExpr, nameType, tagService, _23, _24, _0$$3, _1$$5, _13$$5, _14$$5, _16$$5, _17$$5, _18$$5, _3$$6, _5$$9, _6$$9, _7$$9, _8$$9, _10$$15, _11$$16, _12$$17, _19$$28, _20$$28, _21$$28, _22$$30;
	zval expr, _2$$6, _4$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_4$$12);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&arrayHelpers);
	ZVAL_UNDEF(&block);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&currentBlock);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&escapedCode);
	ZVAL_UNDEF(&exprLevel);
	ZVAL_UNDEF(&extendedBlocks);
	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&funcArguments);
	ZVAL_UNDEF(&functions);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&nameExpr);
	ZVAL_UNDEF(&nameType);
	ZVAL_UNDEF(&tagService);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_10$$15);
	ZVAL_UNDEF(&_11$$16);
	ZVAL_UNDEF(&_12$$17);
	ZVAL_UNDEF(&_19$$28);
	ZVAL_UNDEF(&_20$$28);
	ZVAL_UNDEF(&_21$$28);
	ZVAL_UNDEF(&_22$$30);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(expr)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(doubleQuotes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &expr_param, &doubleQuotes_param);
	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);
	if (!doubleQuotes_param) {
		doubleQuotes = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&code);
	ZVAL_NULL(&code);
	ZEPHIR_INIT_VAR(&funcArguments);
	ZVAL_NULL(&funcArguments);
	zephir_memory_observe(&nameExpr);
	zephir_array_fetch_string(&nameExpr, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1764);
	zephir_memory_observe(&nameType);
	zephir_array_fetch_string(&nameType, &nameExpr, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1765);
	ZEPHIR_OBS_NVAR(&funcArguments);
	if (zephir_array_isset_string_fetch(&funcArguments, &expr, SL("arguments"), 0)) {
		if (doubleQuotes) {
			ZVAL_BOOL(&_0$$3, 1);
		} else {
			ZVAL_BOOL(&_0$$3, 0);
		}
		ZEPHIR_CALL_METHOD(&arguments, this_ptr, "expression", NULL, 503, &funcArguments, &_0$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&arguments);
		ZVAL_STRING(&arguments, "");
	}
	if (ZEPHIR_IS_LONG(&nameType, 265)) {
		zephir_memory_observe(&name);
		zephir_array_fetch_string(&name, &nameExpr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1782);
		zephir_read_property(&_1$$5, this_ptr, ZEND_STRL("extensions"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&extensions, &_1$$5);
		if (Z_TYPE_P(&extensions) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_2$$6);
			zephir_create_array(&_2$$6, 3, 0);
			zephir_array_fast_append(&_2$$6, &name);
			zephir_array_fast_append(&_2$$6, &arguments);
			zephir_array_fast_append(&_2$$6, &funcArguments);
			ZEPHIR_INIT_VAR(&_3$$6);
			ZVAL_STRING(&_3$$6, "compileFunction");
			ZEPHIR_CALL_METHOD(&code, this_ptr, "fireextensionevent", NULL, 507, &_3$$6, &_2$$6);
			zephir_check_call_status();
			if (Z_TYPE_P(&code) == IS_STRING) {
				RETURN_CCTOR(&code);
			}
		}
		zephir_read_property(&_1$$5, this_ptr, ZEND_STRL("functions"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&functions, &_1$$5);
		if (Z_TYPE_P(&functions) == IS_ARRAY) {
			zephir_memory_observe(&definition);
			if (zephir_array_isset_fetch(&definition, &functions, &name, 0)) {
				if (Z_TYPE_P(&definition) == IS_STRING) {
					ZEPHIR_CONCAT_VSVS(return_value, &definition, "(", &arguments, ")");
					RETURN_MM();
				}
				if (Z_TYPE_P(&definition) == IS_OBJECT) {
					if (zephir_is_instance_of(&definition, SL("Closure"))) {
						ZEPHIR_INIT_VAR(&_4$$12);
						zephir_create_array(&_4$$12, 2, 0);
						zephir_array_fast_append(&_4$$12, &arguments);
						zephir_array_fast_append(&_4$$12, &funcArguments);
						ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &definition, &_4$$12);
						zephir_check_call_status();
						RETURN_MM();
					}
				}
				ZEPHIR_INIT_VAR(&_5$$9);
				object_init_ex(&_5$$9, phalcon_mvc_view_engine_volt_exception_ce);
				zephir_array_fetch_string(&_6$$9, &expr, SL("file"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1832);
				zephir_array_fetch_string(&_7$$9, &expr, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1833);
				ZEPHIR_INIT_VAR(&_8$$9);
				ZEPHIR_CONCAT_SVSVSV(&_8$$9, "Invalid definition for user function '", &name, "' in ", &_6$$9, " on line ", &_7$$9);
				ZEPHIR_CALL_METHOD(NULL, &_5$$9, "__construct", NULL, 504, &_8$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$9, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1833);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		_9$$5 = ZEPHIR_IS_STRING(&name, "get_content");
		if (!(_9$$5)) {
			_9$$5 = ZEPHIR_IS_STRING(&name, "content");
		}
		if (_9$$5) {
			RETURN_MM_STRING("$this->getContent()");
		}
		if (ZEPHIR_IS_STRING(&name, "partial")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->partial(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "super")) {
			zephir_read_property(&_10$$15, this_ptr, ZEND_STRL("extendedBlocks"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&extendedBlocks, &_10$$15);
			if (Z_TYPE_P(&extendedBlocks) == IS_ARRAY) {
				zephir_read_property(&_11$$16, this_ptr, ZEND_STRL("currentBlock"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CPY_WRT(&currentBlock, &_11$$16);
				zephir_memory_observe(&block);
				if (zephir_array_isset_fetch(&block, &extendedBlocks, &currentBlock, 0)) {
					zephir_read_property(&_12$$17, this_ptr, ZEND_STRL("exprLevel"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CPY_WRT(&exprLevel, &_12$$17);
					if (Z_TYPE_P(&block) == IS_ARRAY) {
						ZEPHIR_CALL_METHOD(&code, this_ptr, "statementlistorextends", NULL, 509, &block);
						zephir_check_call_status();
						if (ZEPHIR_IS_LONG(&exprLevel, 1)) {
							ZEPHIR_CPY_WRT(&escapedCode, &code);
						} else {
							ZEPHIR_INIT_NVAR(&escapedCode);
							zephir_addslashes(&escapedCode, &code);
						}
					} else {
						if (ZEPHIR_IS_LONG(&exprLevel, 1)) {
							ZEPHIR_CPY_WRT(&escapedCode, &block);
						} else {
							ZEPHIR_INIT_NVAR(&escapedCode);
							zephir_addslashes(&escapedCode, &block);
						}
					}
					if (ZEPHIR_IS_LONG(&exprLevel, 1)) {
						RETURN_CCTOR(&escapedCode);
					}
					ZEPHIR_CONCAT_SVS(return_value, "'", &escapedCode, "'");
					RETURN_MM();
				}
			}
			RETURN_MM_STRING("''");
		}
		if (ZEPHIR_IS_STRING_IDENTICAL(&name, "preload")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->preload(", &arguments, ")");
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_13$$5);
		zephir_camelize(&_13$$5, &name, NULL );
		ZEPHIR_CALL_FUNCTION(&method, "lcfirst", NULL, 77, &_13$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&arrayHelpers);
		zephir_create_array(&arrayHelpers, 16, 0);
		zephir_array_update_string(&arrayHelpers, SL("link_to"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&arrayHelpers, SL("image"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&arrayHelpers, SL("form_legacy"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&arrayHelpers, SL("submit_button"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&arrayHelpers, SL("radio_field"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&arrayHelpers, SL("check_field"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&arrayHelpers, SL("file_field"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&arrayHelpers, SL("hidden_field"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&arrayHelpers, SL("password_field"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&arrayHelpers, SL("text_area"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&arrayHelpers, SL("text_field"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&arrayHelpers, SL("email_field"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&arrayHelpers, SL("date_field"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&arrayHelpers, SL("tel_field"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&arrayHelpers, SL("numeric_field"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&arrayHelpers, SL("image_input"), &__$true, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_14$$5);
		ZVAL_STRING(&_14$$5, "Phalcon\\Tag");
		if ((zephir_method_exists(&_14$$5, &method)  == SUCCESS)) {
			if (zephir_array_isset(&arrayHelpers, &name)) {
				ZEPHIR_CONCAT_SVSVS(return_value, "\\Phalcon\\Tag::", &method, "([", &arguments, "])");
				RETURN_MM();
			}
			ZEPHIR_CONCAT_SVSVS(return_value, "\\Phalcon\\Tag::", &method, "(", &arguments, ")");
			RETURN_MM();
		}
		zephir_read_property(&_1$$5, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		_15$$5 = Z_TYPE_P(&_1$$5) != IS_NULL;
		if (_15$$5) {
			zephir_read_property(&_16$$5, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_18$$5);
			ZVAL_STRING(&_18$$5, "tag");
			ZEPHIR_CALL_METHOD(&_17$$5, &_16$$5, "has", NULL, 0, &_18$$5);
			zephir_check_call_status();
			_15$$5 = ZEPHIR_IS_TRUE_IDENTICAL(&_17$$5);
		}
		if (_15$$5) {
			zephir_read_property(&_19$$28, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_20$$28);
			ZVAL_STRING(&_20$$28, "tag");
			ZEPHIR_CALL_METHOD(&tagService, &_19$$28, "get", NULL, 0, &_20$$28);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_21$$28, &tagService, "has", NULL, 0, &name);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_21$$28)) {
				ZEPHIR_INIT_NVAR(&funcArguments);
				ZVAL_NULL(&funcArguments);
				ZEPHIR_OBS_NVAR(&funcArguments);
				if (zephir_array_isset_string_fetch(&funcArguments, &expr, SL("arguments"), 0)) {
					ZVAL_BOOL(&_22$$30, 1);
					ZEPHIR_CALL_METHOD(&arguments, this_ptr, "expression", NULL, 503, &funcArguments, &_22$$30);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&arguments);
					ZVAL_STRING(&arguments, "");
				}
				ZEPHIR_CONCAT_SVSVS(return_value, "$this->tag->", &name, "(", &arguments, ")");
				RETURN_MM();
			}
		}
		if (ZEPHIR_IS_STRING(&name, "url")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->url->get(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "static_url")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->url->getStatic(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "date")) {
			ZEPHIR_CONCAT_SVS(return_value, "date(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "time")) {
			RETURN_MM_STRING("time()");
		}
		if (ZEPHIR_IS_STRING(&name, "dump")) {
			ZEPHIR_CONCAT_SVS(return_value, "var_dump(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "version")) {
			RETURN_MM_STRING("(new Phalcon\\Support\\Version)->get()");
		}
		if (ZEPHIR_IS_STRING(&name, "version_id")) {
			RETURN_MM_STRING("(new Phalcon\\Support\\Version)->getId()");
		}
		if (ZEPHIR_IS_STRING(&name, "preload")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->preload(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "constant")) {
			ZEPHIR_CONCAT_SVS(return_value, "constant(", &arguments, ")");
			RETURN_MM();
		}
		ZEPHIR_CONCAT_SVSVS(return_value, "$this->callMacro('", &name, "', [", &arguments, "])");
		RETURN_MM();
	}
	if (doubleQuotes) {
		ZVAL_BOOL(&_24, 1);
	} else {
		ZVAL_BOOL(&_24, 0);
	}
	ZEPHIR_CALL_METHOD(&_23, this_ptr, "expression", NULL, 503, &nameExpr, &_24);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVS(return_value, &_23, "(", &arguments, ")");
	RETURN_MM();
}

/**
 * Returns the path to the last compiled template
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath)
{

	RETURN_MEMBER(getThis(), "compiledTemplatePath");
}

/**
 * Returns the internal dependency injector
 *
 * @return DiInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI)
{

	RETURN_MEMBER(getThis(), "container");
}

/**
 * Returns the list of extensions registered in Volt
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getExtensions)
{

	RETURN_MEMBER(getThis(), "extensions");
}

/**
 * Register the user registered filters
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFilters)
{

	RETURN_MEMBER(getThis(), "filters");
}

/**
 * Register the user registered functions
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFunctions)
{

	RETURN_MEMBER(getThis(), "functions");
}

/**
 * Returns a compiler's option
 *
 * @param string option
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOption)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *option_param = NULL, value, _0;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(option)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &option_param);
	if (UNEXPECTED(Z_TYPE_P(option_param) != IS_STRING && Z_TYPE_P(option_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'option' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(option_param) == IS_STRING)) {
		zephir_get_strval(&option, option_param);
	} else {
		ZEPHIR_INIT_VAR(&option);
	}
	zephir_memory_observe(&value);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&value, &_0, &option, 0))) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&value);
}

/**
 * Returns the compiler options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOptions)
{

	RETURN_MEMBER(getThis(), "options");
}

/**
 * Returns the path that is currently being compiled
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getTemplatePath)
{

	RETURN_MEMBER(getThis(), "currentPath");
}

/**
 * Return a unique prefix to be used as prefix for compiled variables and
 * contexts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getUniquePrefix)
{
	zval _7$$5;
	zval _0, _3, _8, _1$$3, _2$$3, _4$$4, _5$$5, _6$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("currentPath"), PH_NOISY_CC | PH_READONLY);
		zephir_unique_path_key(&_1$$3, &_2$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &_1$$3);
	}
	zephir_memory_observe(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC);
	if (Z_TYPE_P(&_3) == IS_OBJECT) {
		zephir_memory_observe(&_4$$4);
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC);
		if (zephir_is_instance_of(&_4$$4, SL("Closure"))) {
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_read_property(&_6$$5, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_7$$5);
			zephir_create_array(&_7$$5, 1, 0);
			zephir_array_fast_append(&_7$$5, this_ptr);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_5$$5, &_6$$5, &_7$$5);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &_5$$5);
		}
	}
	zephir_memory_observe(&_8);
	zephir_read_property(&_8, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC);
	if (UNEXPECTED(Z_TYPE_P(&_8) != IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "The unique compilation prefix is invalid", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2127);
		return;
	}
	RETURN_MM_MEMBER(getThis(), "prefix");
}

/**
 * Parses a Volt template returning its intermediate representation
 *
 *```php
 * print_r(
 *     $compiler->parse("{% raw %}{{ 3 + 2 }}{% endraw %}")
 * );
 *```
 *
 * @param string viewCode
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, parse)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *viewCode_param = NULL, currentPath;
	zval viewCode;

	ZVAL_UNDEF(&viewCode);
	ZVAL_UNDEF(&currentPath);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(viewCode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &viewCode_param);
	if (UNEXPECTED(Z_TYPE_P(viewCode_param) != IS_STRING && Z_TYPE_P(viewCode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewCode' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewCode_param) == IS_STRING)) {
		zephir_get_strval(&viewCode, viewCode_param);
	} else {
		ZEPHIR_INIT_VAR(&viewCode);
	}
	ZEPHIR_INIT_VAR(&currentPath);
	ZVAL_STRING(&currentPath, "eval code");
	ZEPHIR_LAST_CALL_STATUS = phvolt_parse_view(return_value, &viewCode, &currentPath);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolves filter intermediate code into a valid PHP expression
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveTest)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval left;
	zval *test_param = NULL, *left_param = NULL, type, name, testName, _6, _0$$12, _1$$12, _2$$13, _3$$13, _4$$14, _5$$14;
	zval test;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&test);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&testName);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$12);
	ZVAL_UNDEF(&_1$$12);
	ZVAL_UNDEF(&_2$$13);
	ZVAL_UNDEF(&_3$$13);
	ZVAL_UNDEF(&_4$$14);
	ZVAL_UNDEF(&_5$$14);
	ZVAL_UNDEF(&left);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(test)
		Z_PARAM_STR(left)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &test_param, &left_param);
	ZEPHIR_OBS_COPY_OR_DUP(&test, test_param);
	zephir_get_strval(&left, left_param);
	zephir_memory_observe(&type);
	zephir_array_fetch_string(&type, &test, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2161);
	if (ZEPHIR_IS_LONG(&type, 265)) {
		zephir_memory_observe(&name);
		zephir_array_fetch_string(&name, &test, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2167);
		do {
			if (ZEPHIR_IS_STRING(&name, "empty")) {
				ZEPHIR_CONCAT_SVS(return_value, "empty(", &left, ")");
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(&name, "even")) {
				ZEPHIR_CONCAT_SVS(return_value, "(((", &left, ") % 2) == 0)");
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(&name, "odd")) {
				ZEPHIR_CONCAT_SVS(return_value, "(((", &left, ") % 2) != 0)");
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(&name, "numeric")) {
				ZEPHIR_CONCAT_SVS(return_value, "is_numeric(", &left, ")");
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(&name, "scalar")) {
				ZEPHIR_CONCAT_SVS(return_value, "is_scalar(", &left, ")");
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(&name, "iterable")) {
				ZEPHIR_CONCAT_SVSVS(return_value, "(is_array(", &left, ") || (", &left, ") instanceof Traversable)");
				RETURN_MM();
			}
		} while(0);

	}
	if (ZEPHIR_IS_LONG(&type, 350)) {
		zephir_memory_observe(&testName);
		zephir_array_fetch_string(&testName, &test, SL("name"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2190);
		ZEPHIR_OBS_NVAR(&name);
		if (zephir_array_isset_string_fetch(&name, &testName, SL("value"), 0)) {
			do {
				if (ZEPHIR_IS_STRING(&name, "divisibleby")) {
					zephir_array_fetch_string(&_1$$12, &test, SL("arguments"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2195);
					ZEPHIR_CALL_METHOD(&_0$$12, this_ptr, "expression", NULL, 503, &_1$$12);
					zephir_check_call_status();
					ZEPHIR_CONCAT_SVSVS(return_value, "(((", &left, ") % (", &_0$$12, ")) == 0)");
					RETURN_MM();
				}
				if (ZEPHIR_IS_STRING(&name, "sameas")) {
					zephir_array_fetch_string(&_3$$13, &test, SL("arguments"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2197);
					ZEPHIR_CALL_METHOD(&_2$$13, this_ptr, "expression", NULL, 503, &_3$$13);
					zephir_check_call_status();
					ZEPHIR_CONCAT_SVSVS(return_value, "(", &left, ") === (", &_2$$13, ")");
					RETURN_MM();
				}
				if (ZEPHIR_IS_STRING(&name, "type")) {
					zephir_array_fetch_string(&_5$$14, &test, SL("arguments"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2199);
					ZEPHIR_CALL_METHOD(&_4$$14, this_ptr, "expression", NULL, 503, &_5$$14);
					zephir_check_call_status();
					ZEPHIR_CONCAT_SVSVS(return_value, "gettype(", &left, ") === (", &_4$$14, ")");
					RETURN_MM();
				}
			} while(0);

		}
	}
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "expression", NULL, 503, &test);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &left, " == ", &_6);
	RETURN_MM();
}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI)
{
	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &container);
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
}

/**
 * Sets a single compiler option
 *
 * @param mixed value
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOption)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *option_param = NULL, *value, value_sub;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(option)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &option_param, &value);
	if (UNEXPECTED(Z_TYPE_P(option_param) != IS_STRING && Z_TYPE_P(option_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'option' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(option_param) == IS_STRING)) {
		zephir_get_strval(&option, option_param);
	} else {
		ZEPHIR_INIT_VAR(&option);
	}
	zephir_update_property_array(this_ptr, SL("options"), &option, value);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the compiler options
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	ZEPHIR_MM_RESTORE();
}

/**
 * Set a unique prefix to be used as prefix for compiled variables
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setUniquePrefix)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *prefix_param = NULL;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &prefix_param);
	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(&prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(&prefix);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &prefix);
	RETURN_THIS();
}

/**
 * Compiles a Volt source code returning a PHP plain version
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSource)
{
	zend_string *_6$$7;
	zend_ulong _5$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *viewCode_param = NULL, *extendsMode_param = NULL, currentPath, intermediate, extended, finalCompilation, blocks, extendedBlocks, name, block, blockCompilation, localBlock, compilation, options, autoescape, _0, _1, _2$$7, *_3$$7, _4$$7;
	zval viewCode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewCode);
	ZVAL_UNDEF(&currentPath);
	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&extended);
	ZVAL_UNDEF(&finalCompilation);
	ZVAL_UNDEF(&blocks);
	ZVAL_UNDEF(&extendedBlocks);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&block);
	ZVAL_UNDEF(&blockCompilation);
	ZVAL_UNDEF(&localBlock);
	ZVAL_UNDEF(&compilation);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&autoescape);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_4$$7);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(viewCode)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &viewCode_param, &extendsMode_param);
	if (UNEXPECTED(Z_TYPE_P(viewCode_param) != IS_STRING && Z_TYPE_P(viewCode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewCode' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewCode_param) == IS_STRING)) {
		zephir_get_strval(&viewCode, viewCode_param);
	} else {
		ZEPHIR_INIT_VAR(&viewCode);
	}
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("currentPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&currentPath, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		zephir_memory_observe(&autoescape);
		if (zephir_array_isset_string_fetch(&autoescape, &options, SL("autoescape"), 0)) {
			if (UNEXPECTED(((Z_TYPE_P(&autoescape) == IS_TRUE || Z_TYPE_P(&autoescape) == IS_FALSE) != 1))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'autoescape' must be bool", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2268);
				return;
			}
			zephir_update_property_zval(this_ptr, ZEND_STRL("autoescape"), &autoescape);
		}
	}
	ZEPHIR_INIT_VAR(&intermediate);
	ZEPHIR_LAST_CALL_STATUS = phvolt_parse_view(&intermediate, &viewCode, &currentPath);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&intermediate) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Invalid intermediate representation", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2281);
		return;
	}
	if (extendsMode) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_CALL_METHOD(&compilation, this_ptr, "statementlist", NULL, 505, &intermediate, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("extended"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&extended, &_1);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&extended)) {
		ZEPHIR_INIT_VAR(&finalCompilation);
		if (extendsMode == 1) {
			array_init(&finalCompilation);
		} else {
			ZVAL_NULL(&finalCompilation);
		}
		zephir_read_property(&_2$$7, this_ptr, ZEND_STRL("blocks"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&blocks, &_2$$7);
		zephir_read_property(&_2$$7, this_ptr, ZEND_STRL("extendedBlocks"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&extendedBlocks, &_2$$7);
		zephir_is_iterable(&extendedBlocks, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2353);
		if (Z_TYPE_P(&extendedBlocks) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&extendedBlocks), _5$$7, _6$$7, _3$$7)
			{
				ZEPHIR_INIT_NVAR(&name);
				if (_6$$7 != NULL) { 
					ZVAL_STR_COPY(&name, _6$$7);
				} else {
					ZVAL_LONG(&name, _5$$7);
				}
				ZEPHIR_INIT_NVAR(&block);
				ZVAL_COPY(&block, _3$$7);
				if (Z_TYPE_P(&name) == IS_STRING) {
					if (zephir_array_isset(&blocks, &name)) {
						ZEPHIR_OBS_NVAR(&localBlock);
						zephir_array_fetch(&localBlock, &blocks, &name, PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2313);
						zephir_update_property_zval(this_ptr, ZEND_STRL("currentBlock"), &name);
						if (Z_TYPE_P(&localBlock) == IS_NULL) {
							ZEPHIR_INIT_NVAR(&localBlock);
							array_init(&localBlock);
						}
						ZEPHIR_CALL_METHOD(&blockCompilation, this_ptr, "statementlist", NULL, 505, &localBlock);
						zephir_check_call_status();
					} else {
						if (Z_TYPE_P(&block) == IS_ARRAY) {
							ZEPHIR_CALL_METHOD(&blockCompilation, this_ptr, "statementlist", NULL, 505, &block);
							zephir_check_call_status();
						} else {
							ZEPHIR_CPY_WRT(&blockCompilation, &block);
						}
					}
					if (extendsMode) {
						zephir_array_update_zval(&finalCompilation, &name, &blockCompilation, PH_COPY | PH_SEPARATE);
					} else {
						zephir_concat_self(&finalCompilation, &blockCompilation);
					}
				} else {
					if (extendsMode) {
						zephir_array_append(&finalCompilation, &block, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2346);
					} else {
						zephir_concat_self(&finalCompilation, &block);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &extendedBlocks, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$7, &extendedBlocks, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$7)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&name, &extendedBlocks, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&block, &extendedBlocks, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&name) == IS_STRING) {
						if (zephir_array_isset(&blocks, &name)) {
							ZEPHIR_OBS_NVAR(&localBlock);
							zephir_array_fetch(&localBlock, &blocks, &name, PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2313);
							zephir_update_property_zval(this_ptr, ZEND_STRL("currentBlock"), &name);
							if (Z_TYPE_P(&localBlock) == IS_NULL) {
								ZEPHIR_INIT_NVAR(&localBlock);
								array_init(&localBlock);
							}
							ZEPHIR_CALL_METHOD(&blockCompilation, this_ptr, "statementlist", NULL, 505, &localBlock);
							zephir_check_call_status();
						} else {
							if (Z_TYPE_P(&block) == IS_ARRAY) {
								ZEPHIR_CALL_METHOD(&blockCompilation, this_ptr, "statementlist", NULL, 505, &block);
								zephir_check_call_status();
							} else {
								ZEPHIR_CPY_WRT(&blockCompilation, &block);
							}
						}
						if (extendsMode) {
							zephir_array_update_zval(&finalCompilation, &name, &blockCompilation, PH_COPY | PH_SEPARATE);
						} else {
							zephir_concat_self(&finalCompilation, &blockCompilation);
						}
					} else {
						if (extendsMode) {
							zephir_array_append(&finalCompilation, &block, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2346);
						} else {
							zephir_concat_self(&finalCompilation, &block);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &extendedBlocks, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&block);
		ZEPHIR_INIT_NVAR(&name);
		RETURN_CCTOR(&finalCompilation);
	}
	if (extendsMode) {
		RETURN_MM_MEMBER(getThis(), "blocks");
	}
	RETURN_CCTOR(&compilation);
}

/**
 * Gets the final path with VIEW
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFinalPath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, view, viewsDirs, viewsDir, _0, *_1$$4, _2$$4, _3$$5, _4$$7;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&view);
	ZVAL_UNDEF(&viewsDirs);
	ZVAL_UNDEF(&viewsDir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$7);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &path_param);
	zephir_get_strval(&path, path_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&view, &_0);
	if (Z_TYPE_P(&view) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&viewsDirs, &view, "getviewsdir", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&viewsDirs) == IS_ARRAY) {
			zephir_is_iterable(&viewsDirs, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2387);
			if (Z_TYPE_P(&viewsDirs) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&viewsDirs), _1$$4)
				{
					ZEPHIR_INIT_NVAR(&viewsDir);
					ZVAL_COPY(&viewsDir, _1$$4);
					ZEPHIR_INIT_NVAR(&_3$$5);
					ZEPHIR_CONCAT_VV(&_3$$5, &viewsDir, &path);
					if ((zephir_file_exists(&_3$$5) == SUCCESS)) {
						ZEPHIR_CONCAT_VV(return_value, &viewsDir, &path);
						RETURN_MM();
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &viewsDirs, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_2$$4, &viewsDirs, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_2$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&viewsDir, &viewsDirs, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_4$$7);
						ZEPHIR_CONCAT_VV(&_4$$7, &viewsDir, &path);
						if ((zephir_file_exists(&_4$$7) == SUCCESS)) {
							ZEPHIR_CONCAT_VV(return_value, &viewsDir, &path);
							RETURN_MM();
						}
					ZEPHIR_CALL_METHOD(NULL, &viewsDirs, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&viewsDir);
			ZEPHIR_CONCAT_VV(return_value, &viewsDir, &path);
			RETURN_MM();
		} else {
			ZEPHIR_CONCAT_VV(return_value, &viewsDirs, &path);
			RETURN_MM();
		}
	}
	RETURN_CTOR(&path);
}

/**
 * Resolves filter intermediate code into PHP function calls
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveFilter)
{
	zend_bool _21$$30, _26$$41;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval left;
	zval *filter_param = NULL, *left_param = NULL, code, type, functionName, name, file, line, extensions, filters, funcArguments, arguments, definition, _6, _30, _31, _32, _33, _0$$5, _1$$5, _2$$5, _3$$5, _8$$9, _10$$11, _11$$11, _12$$11, _13$$11, _14$$24, _15$$24, _16$$24, _17$$24, _18$$24, _19$$24, _20$$30, _22$$30, _23$$30, _24$$30, _25$$41, _27$$41, _28$$41, _29$$41;
	zval filter, _4$$7, _5$$7, _7$$9, _9$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&functionName);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&funcArguments);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$24);
	ZVAL_UNDEF(&_15$$24);
	ZVAL_UNDEF(&_16$$24);
	ZVAL_UNDEF(&_17$$24);
	ZVAL_UNDEF(&_18$$24);
	ZVAL_UNDEF(&_19$$24);
	ZVAL_UNDEF(&_20$$30);
	ZVAL_UNDEF(&_22$$30);
	ZVAL_UNDEF(&_23$$30);
	ZVAL_UNDEF(&_24$$30);
	ZVAL_UNDEF(&_25$$41);
	ZVAL_UNDEF(&_27$$41);
	ZVAL_UNDEF(&_28$$41);
	ZVAL_UNDEF(&_29$$41);
	ZVAL_UNDEF(&left);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(filter)
		Z_PARAM_STR(left)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &filter_param, &left_param);
	ZEPHIR_OBS_COPY_OR_DUP(&filter, filter_param);
	zephir_get_strval(&left, left_param);
	ZEPHIR_INIT_VAR(&code);
	ZVAL_NULL(&code);
	zephir_memory_observe(&type);
	zephir_array_fetch_string(&type, &filter, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2405);
	if (ZEPHIR_IS_LONG(&type, 265)) {
		zephir_memory_observe(&name);
		zephir_array_fetch_string(&name, &filter, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2411);
	} else {
		if (UNEXPECTED(!ZEPHIR_IS_LONG(&type, 350))) {
			ZEPHIR_INIT_VAR(&_0$$5);
			object_init_ex(&_0$$5, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_1$$5, &filter, SL("file"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2418);
			zephir_array_fetch_string(&_2$$5, &filter, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2419);
			ZEPHIR_INIT_VAR(&_3$$5);
			ZEPHIR_CONCAT_SVSV(&_3$$5, "Unknown filter type in ", &_1$$5, " on line ", &_2$$5);
			ZEPHIR_CALL_METHOD(NULL, &_0$$5, "__construct", NULL, 504, &_3$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_0$$5, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2419);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&functionName);
		zephir_array_fetch_string(&functionName, &filter, SL("name"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2422);
		ZEPHIR_OBS_NVAR(&name);
		zephir_array_fetch_string(&name, &functionName, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2423);
	}
	ZEPHIR_INIT_VAR(&funcArguments);
	ZVAL_NULL(&funcArguments);
	ZEPHIR_INIT_VAR(&arguments);
	ZVAL_NULL(&arguments);
	ZEPHIR_OBS_NVAR(&funcArguments);
	if (zephir_array_isset_string_fetch(&funcArguments, &filter, SL("arguments"), 0)) {
		if (!ZEPHIR_IS_STRING(&name, "default")) {
			zephir_memory_observe(&file);
			zephir_array_fetch_string(&file, &filter, SL("file"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2437);
			zephir_memory_observe(&line);
			zephir_array_fetch_string(&line, &filter, SL("line"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2438);
			ZEPHIR_INIT_VAR(&_4$$7);
			zephir_create_array(&_4$$7, 3, 0);
			ZEPHIR_INIT_VAR(&_5$$7);
			zephir_create_array(&_5$$7, 4, 0);
			add_assoc_long_ex(&_5$$7, SL("type"), 364);
			zephir_array_update_string(&_5$$7, SL("value"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_5$$7, SL("file"), &file, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_5$$7, SL("line"), &line, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4$$7, SL("expr"), &_5$$7, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4$$7, SL("file"), &file, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4$$7, SL("line"), &line, PH_COPY | PH_SEPARATE);
			ZEPHIR_MAKE_REF(&funcArguments);
			ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 270, &funcArguments, &_4$$7);
			ZEPHIR_UNREF(&funcArguments);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&arguments, this_ptr, "expression", NULL, 503, &funcArguments);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&arguments, &left);
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("extensions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&extensions, &_6);
	if (Z_TYPE_P(&extensions) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_7$$9);
		zephir_create_array(&_7$$9, 3, 0);
		zephir_array_fast_append(&_7$$9, &name);
		zephir_array_fast_append(&_7$$9, &arguments);
		zephir_array_fast_append(&_7$$9, &funcArguments);
		ZEPHIR_INIT_VAR(&_8$$9);
		ZVAL_STRING(&_8$$9, "compileFilter");
		ZEPHIR_CALL_METHOD(&code, this_ptr, "fireextensionevent", NULL, 507, &_8$$9, &_7$$9);
		zephir_check_call_status();
		if (Z_TYPE_P(&code) == IS_STRING) {
			RETURN_CCTOR(&code);
		}
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&filters, &_6);
	zephir_memory_observe(&definition);
	if (zephir_array_isset_fetch(&definition, &filters, &name, 0)) {
		if (Z_TYPE_P(&definition) == IS_STRING) {
			ZEPHIR_CONCAT_VSVS(return_value, &definition, "(", &arguments, ")");
			RETURN_MM();
		}
		if (Z_TYPE_P(&definition) == IS_OBJECT) {
			if (zephir_is_instance_of(&definition, SL("Closure"))) {
				ZEPHIR_INIT_VAR(&_9$$14);
				zephir_create_array(&_9$$14, 2, 0);
				zephir_array_fast_append(&_9$$14, &arguments);
				zephir_array_fast_append(&_9$$14, &funcArguments);
				ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &definition, &_9$$14);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
		ZEPHIR_INIT_VAR(&_10$$11);
		object_init_ex(&_10$$11, phalcon_mvc_view_engine_volt_exception_ce);
		zephir_array_fetch_string(&_11$$11, &filter, SL("file"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2512);
		zephir_array_fetch_string(&_12$$11, &filter, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2513);
		ZEPHIR_INIT_VAR(&_13$$11);
		ZEPHIR_CONCAT_SVSVSV(&_13$$11, "Invalid definition for user filter '", &name, "' in ", &_11$$11, " on line ", &_12$$11);
		ZEPHIR_CALL_METHOD(NULL, &_10$$11, "__construct", NULL, 504, &_13$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$11, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2513);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (ZEPHIR_IS_STRING(&name, "abs")) {
			ZEPHIR_CONCAT_SVS(return_value, "abs(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "capitalize")) {
			ZEPHIR_CONCAT_SVS(return_value, "ucwords(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "convert_encoding")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->convertEncoding(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "default")) {
			ZEPHIR_CONCAT_SVSVSVS(return_value, "(empty(", &left, ") ? (", &arguments, ") : (", &left, "))");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "e") || ZEPHIR_IS_STRING(&name, "escape")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->escaper->html(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "escape_attr")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->escaper->attributes(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "escape_css")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->escaper->css(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "escape_js")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->escaper->js(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "format")) {
			ZEPHIR_CONCAT_SVS(return_value, "sprintf(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "join")) {
			zephir_array_fetch_long(&_14$$24, &funcArguments, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2539);
			zephir_array_fetch_string(&_15$$24, &_14$$24, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2539);
			zephir_array_fetch_string(&_16$$24, &_15$$24, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2540);
			zephir_array_fetch_long(&_17$$24, &funcArguments, 0, PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2540);
			zephir_array_fetch_string(&_18$$24, &_17$$24, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2540);
			zephir_array_fetch_string(&_19$$24, &_18$$24, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2540);
			ZEPHIR_CONCAT_SVSVS(return_value, "join('", &_16$$24, "', ", &_19$$24, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "json_encode")) {
			ZEPHIR_CONCAT_SVS(return_value, "json_encode(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "json_decode")) {
			ZEPHIR_CONCAT_SVS(return_value, "json_decode(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "keys")) {
			ZEPHIR_CONCAT_SVS(return_value, "array_keys(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "left_trim")) {
			ZEPHIR_CONCAT_SVS(return_value, "ltrim(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "length")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->length(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "lower") || ZEPHIR_IS_STRING(&name, "lowercase")) {
			zephir_read_property(&_20$$30, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
			_21$$30 = Z_TYPE_P(&_20$$30) != IS_NULL;
			if (_21$$30) {
				zephir_read_property(&_22$$30, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_24$$30);
				ZVAL_STRING(&_24$$30, "helper");
				ZEPHIR_CALL_METHOD(&_23$$30, &_22$$30, "has", NULL, 0, &_24$$30);
				zephir_check_call_status();
				_21$$30 = ZEPHIR_IS_TRUE_IDENTICAL(&_23$$30);
			}
			if (_21$$30) {
				ZEPHIR_CONCAT_SVS(return_value, "$this->helper->lower(", &arguments, ")");
				RETURN_MM();
			} else {
				ZEPHIR_CONCAT_SVS(return_value, "strtolower(", &arguments, ")");
				RETURN_MM();
			}
		}
		if (ZEPHIR_IS_STRING(&name, "right_trim")) {
			ZEPHIR_CONCAT_SVS(return_value, "rtrim(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "nl2br")) {
			ZEPHIR_CONCAT_SVS(return_value, "nl2br(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "slashes")) {
			ZEPHIR_CONCAT_SVS(return_value, "addslashes(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "slice")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->slice(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "sort")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->sort(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "stripslashes")) {
			ZEPHIR_CONCAT_SVS(return_value, "stripslashes(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "striptags")) {
			ZEPHIR_CONCAT_SVS(return_value, "strip_tags(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "trim")) {
			ZEPHIR_CONCAT_SVS(return_value, "trim(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "upper") || ZEPHIR_IS_STRING(&name, "uppercase")) {
			zephir_read_property(&_25$$41, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
			_26$$41 = Z_TYPE_P(&_25$$41) != IS_NULL;
			if (_26$$41) {
				zephir_read_property(&_27$$41, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_29$$41);
				ZVAL_STRING(&_29$$41, "helper");
				ZEPHIR_CALL_METHOD(&_28$$41, &_27$$41, "has", NULL, 0, &_29$$41);
				zephir_check_call_status();
				_26$$41 = ZEPHIR_IS_TRUE_IDENTICAL(&_28$$41);
			}
			if (_26$$41) {
				ZEPHIR_CONCAT_SVS(return_value, "$this->helper->upper(", &arguments, ")");
				RETURN_MM();
			} else {
				ZEPHIR_CONCAT_SVS(return_value, "strtoupper(", &arguments, ")");
				RETURN_MM();
			}
		}
		if (ZEPHIR_IS_STRING(&name, "url_encode")) {
			ZEPHIR_CONCAT_SVS(return_value, "urlencode(", &arguments, ")");
			RETURN_MM();
		}
	} while(0);

	ZEPHIR_INIT_VAR(&_30);
	object_init_ex(&_30, phalcon_mvc_view_engine_volt_exception_ce);
	zephir_array_fetch_string(&_31, &filter, SL("file"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2587);
	zephir_array_fetch_string(&_32, &filter, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2588);
	ZEPHIR_INIT_VAR(&_33);
	ZEPHIR_CONCAT_SVSVSV(&_33, "Unknown filter \"", &name, "\" in ", &_31, " on line ", &_32);
	ZEPHIR_CALL_METHOD(NULL, &_30, "__construct", NULL, 504, &_33);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_30, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2588);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Traverses a statement list compiling each of its nodes
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, statementList)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL, *_15 = NULL, *_17 = NULL, *_20 = NULL, *_22 = NULL, *_27 = NULL, *_29 = NULL, *_31 = NULL, *_35 = NULL, *_37 = NULL, *_40 = NULL, *_42 = NULL, *_44 = NULL, *_47 = NULL, *_49 = NULL, *_52 = NULL, *_55 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode, _1;
	zval *statements_param = NULL, *extendsMode_param = NULL, __$true, __$false, extended, blockMode, compilation, extensions, statement, tempCompilation, type, blockName, blockStatements, blocks, path, finalPath, subCompiler, level, _0, *_2, _3, _4$$7, _5$$7, _6$$7, _7$$7, _10$$8, _12$$10, _13$$11, _14$$11, _16$$12, _18$$13, _19$$13, _21$$14, _23$$15, _24$$15, _25$$16, _26$$16, _28$$17, _30$$18, _32$$19, _33$$24, _34$$24, _36$$25, _38$$26, _39$$27, _41$$28, _43$$29, _45$$30, _46$$30, _48$$33, _50$$34, _51$$34, _53$$35, _54$$35, _56$$37, _57$$37, _58$$37, _59$$37, _60$$40, _61$$40, _62$$40, _63$$40, _65$$41, _66$$43, _67$$44, _68$$44, _69$$45, _70$$46, _71$$46, _72$$47, _73$$48, _74$$48, _75$$49, _76$$49, _77$$50, _78$$51, _79$$52, _80$$57, _81$$57, _82$$58, _83$$59, _84$$60, _85$$61, _86$$62, _87$$63, _88$$63, _89$$66, _90$$67, _91$$67, _92$$68, _93$$68, _94$$70, _95$$70, _96$$70, _97$$70;
	zval statements, _9$$8, _64$$41;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statements);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_64$$41);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&extended);
	ZVAL_UNDEF(&blockMode);
	ZVAL_UNDEF(&compilation);
	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&tempCompilation);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&blockName);
	ZVAL_UNDEF(&blockStatements);
	ZVAL_UNDEF(&blocks);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&finalPath);
	ZVAL_UNDEF(&subCompiler);
	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_32$$19);
	ZVAL_UNDEF(&_33$$24);
	ZVAL_UNDEF(&_34$$24);
	ZVAL_UNDEF(&_36$$25);
	ZVAL_UNDEF(&_38$$26);
	ZVAL_UNDEF(&_39$$27);
	ZVAL_UNDEF(&_41$$28);
	ZVAL_UNDEF(&_43$$29);
	ZVAL_UNDEF(&_45$$30);
	ZVAL_UNDEF(&_46$$30);
	ZVAL_UNDEF(&_48$$33);
	ZVAL_UNDEF(&_50$$34);
	ZVAL_UNDEF(&_51$$34);
	ZVAL_UNDEF(&_53$$35);
	ZVAL_UNDEF(&_54$$35);
	ZVAL_UNDEF(&_56$$37);
	ZVAL_UNDEF(&_57$$37);
	ZVAL_UNDEF(&_58$$37);
	ZVAL_UNDEF(&_59$$37);
	ZVAL_UNDEF(&_60$$40);
	ZVAL_UNDEF(&_61$$40);
	ZVAL_UNDEF(&_62$$40);
	ZVAL_UNDEF(&_63$$40);
	ZVAL_UNDEF(&_65$$41);
	ZVAL_UNDEF(&_66$$43);
	ZVAL_UNDEF(&_67$$44);
	ZVAL_UNDEF(&_68$$44);
	ZVAL_UNDEF(&_69$$45);
	ZVAL_UNDEF(&_70$$46);
	ZVAL_UNDEF(&_71$$46);
	ZVAL_UNDEF(&_72$$47);
	ZVAL_UNDEF(&_73$$48);
	ZVAL_UNDEF(&_74$$48);
	ZVAL_UNDEF(&_75$$49);
	ZVAL_UNDEF(&_76$$49);
	ZVAL_UNDEF(&_77$$50);
	ZVAL_UNDEF(&_78$$51);
	ZVAL_UNDEF(&_79$$52);
	ZVAL_UNDEF(&_80$$57);
	ZVAL_UNDEF(&_81$$57);
	ZVAL_UNDEF(&_82$$58);
	ZVAL_UNDEF(&_83$$59);
	ZVAL_UNDEF(&_84$$60);
	ZVAL_UNDEF(&_85$$61);
	ZVAL_UNDEF(&_86$$62);
	ZVAL_UNDEF(&_87$$63);
	ZVAL_UNDEF(&_88$$63);
	ZVAL_UNDEF(&_89$$66);
	ZVAL_UNDEF(&_90$$67);
	ZVAL_UNDEF(&_91$$67);
	ZVAL_UNDEF(&_92$$68);
	ZVAL_UNDEF(&_93$$68);
	ZVAL_UNDEF(&_94$$70);
	ZVAL_UNDEF(&_95$$70);
	ZVAL_UNDEF(&_96$$70);
	ZVAL_UNDEF(&_97$$70);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(statements)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &statements_param, &extendsMode_param);
	ZEPHIR_OBS_COPY_OR_DUP(&statements, statements_param);
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		}
	if (!(zephir_fast_count_int(&statements))) {
		RETURN_MM_STRING("");
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("extended"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&extended, &_0);
	_1 = zephir_is_true(&extended);
	if (!(_1)) {
		_1 = extendsMode;
	}
	ZEPHIR_INIT_VAR(&blockMode);
	ZVAL_BOOL(&blockMode, _1);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&blockMode)) {
		RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("blockLevel")));
	}
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("level")));
	ZEPHIR_INIT_VAR(&compilation);
	ZVAL_NULL(&compilation);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("extensions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&extensions, &_0);
	zephir_is_iterable(&statements, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2874);
	if (Z_TYPE_P(&statements) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&statements), _2)
		{
			ZEPHIR_INIT_NVAR(&statement);
			ZVAL_COPY(&statement, _2);
			if (UNEXPECTED(Z_TYPE_P(&statement) != IS_ARRAY)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2628);
				return;
			}
			if (UNEXPECTED(!(zephir_array_isset_string(&statement, SL("type"))))) {
				ZEPHIR_INIT_NVAR(&_4$$7);
				object_init_ex(&_4$$7, phalcon_mvc_view_engine_volt_exception_ce);
				zephir_array_fetch_string(&_5$$7, &statement, SL("file"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2636);
				zephir_array_fetch_string(&_6$$7, &statement, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2636);
				ZEPHIR_INIT_NVAR(&_7$$7);
				ZEPHIR_CONCAT_SVSV(&_7$$7, "Invalid statement in ", &_5$$7, " on line ", &_6$$7);
				ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", &_8, 504, &_7$$7, &statement);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_4$$7, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2638);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&extensions) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_9$$8);
				zephir_create_array(&_9$$8, 1, 0);
				zephir_array_fast_append(&_9$$8, &statement);
				ZEPHIR_INIT_NVAR(&_10$$8);
				ZVAL_STRING(&_10$$8, "compileStatement");
				ZEPHIR_CALL_METHOD(&tempCompilation, this_ptr, "fireextensionevent", &_11, 507, &_10$$8, &_9$$8);
				zephir_check_call_status();
				if (Z_TYPE_P(&tempCompilation) == IS_STRING) {
					zephir_concat_self(&compilation, &tempCompilation);
					continue;
				}
			}
			ZEPHIR_OBS_NVAR(&type);
			zephir_array_fetch_string(&type, &statement, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2664);
			do {
				if (ZEPHIR_IS_LONG(&type, 357)) {
					zephir_array_fetch_string(&_12$$10, &statement, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2672);
					zephir_concat_self(&compilation, &_12$$10);
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 300)) {
					if (extendsMode) {
						ZVAL_BOOL(&_14$$11, 1);
					} else {
						ZVAL_BOOL(&_14$$11, 0);
					}
					ZEPHIR_CALL_METHOD(&_13$$11, this_ptr, "compileif", &_15, 0, &statement, &_14$$11);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_13$$11);
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 302)) {
					ZEPHIR_CALL_METHOD(&_16$$12, this_ptr, "compileelseif", &_17, 0, &statement);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_16$$12);
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 411)) {
					if (extendsMode) {
						ZVAL_BOOL(&_19$$13, 1);
					} else {
						ZVAL_BOOL(&_19$$13, 0);
					}
					ZEPHIR_CALL_METHOD(&_18$$13, this_ptr, "compileswitch", &_20, 0, &statement, &_19$$13);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_18$$13);
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 412)) {
					ZEPHIR_CALL_METHOD(&_21$$14, this_ptr, "compilecase", &_22, 0, &statement);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_21$$14);
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 413)) {
					ZVAL_BOOL(&_24$$15, 0);
					ZEPHIR_CALL_METHOD(&_23$$15, this_ptr, "compilecase", &_22, 0, &statement, &_24$$15);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_23$$15);
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 304)) {
					if (extendsMode) {
						ZVAL_BOOL(&_26$$16, 1);
					} else {
						ZVAL_BOOL(&_26$$16, 0);
					}
					ZEPHIR_CALL_METHOD(&_25$$16, this_ptr, "compileforeach", &_27, 0, &statement, &_26$$16);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_25$$16);
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 306)) {
					ZEPHIR_CALL_METHOD(&_28$$17, this_ptr, "compileset", &_29, 0, &statement);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_28$$17);
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 359)) {
					ZEPHIR_CALL_METHOD(&_30$$18, this_ptr, "compileecho", &_31, 0, &statement);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_30$$18);
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 307)) {
					ZEPHIR_OBS_NVAR(&blockName);
					zephir_array_fetch_string(&blockName, &statement, SL("name"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2719);
					ZEPHIR_OBS_NVAR(&blockStatements);
					zephir_array_isset_string_fetch(&blockStatements, &statement, SL("block_statements"), 0);
					zephir_read_property(&_32$$19, this_ptr, ZEND_STRL("blocks"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CPY_WRT(&blocks, &_32$$19);
					if (zephir_is_true(&blockMode)) {
						if (Z_TYPE_P(&blocks) != IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&blocks);
							array_init(&blocks);
						}
						if (Z_TYPE_P(&compilation) != IS_NULL) {
							zephir_array_append(&blocks, &compilation, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2734);
							ZEPHIR_INIT_NVAR(&compilation);
							ZVAL_NULL(&compilation);
						}
						zephir_array_update_zval(&blocks, &blockName, &blockStatements, PH_COPY | PH_SEPARATE);
						zephir_update_property_zval(this_ptr, ZEND_STRL("blocks"), &blocks);
					} else {
						if (Z_TYPE_P(&blockStatements) == IS_ARRAY) {
							if (extendsMode) {
								ZVAL_BOOL(&_34$$24, 1);
							} else {
								ZVAL_BOOL(&_34$$24, 0);
							}
							ZEPHIR_CALL_METHOD(&_33$$24, this_ptr, "statementlist", &_35, 505, &blockStatements, &_34$$24);
							zephir_check_call_status();
							zephir_concat_self(&compilation, &_33$$24);
						}
					}
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 310)) {
					ZEPHIR_OBS_NVAR(&path);
					zephir_array_fetch_string(&path, &statement, SL("path"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2759);
					zephir_array_fetch_string(&_36$$25, &path, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2763);
					ZEPHIR_CALL_METHOD(&finalPath, this_ptr, "getfinalpath", &_37, 0, &_36$$25);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&extended);
					ZVAL_BOOL(&extended, 1);
					ZEPHIR_INIT_NVAR(&subCompiler);
					if (zephir_clone(&subCompiler, this_ptr) == FAILURE) {
						RETURN_MM();
					}
					ZEPHIR_CALL_METHOD(&tempCompilation, &subCompiler, "compile", NULL, 0, &finalPath, &extended);
					zephir_check_call_status();
					if (Z_TYPE_P(&tempCompilation) == IS_NULL) {
						ZEPHIR_CALL_METHOD(&_38$$26, &subCompiler, "getcompiledtemplatepath", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&tempCompilation);
						zephir_file_get_contents(&tempCompilation, &_38$$26);
					}
					if (1) {
						zephir_update_property_zval(this_ptr, ZEND_STRL("extended"), &__$true);
					} else {
						zephir_update_property_zval(this_ptr, ZEND_STRL("extended"), &__$false);
					}
					zephir_update_property_zval(this_ptr, ZEND_STRL("extendedBlocks"), &tempCompilation);
					ZEPHIR_CPY_WRT(&blockMode, &extended);
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 313)) {
					ZEPHIR_CALL_METHOD(&_39$$27, this_ptr, "compileinclude", &_40, 0, &statement);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_39$$27);
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 316)) {
					ZEPHIR_CALL_METHOD(&_41$$28, this_ptr, "compiledo", &_42, 0, &statement);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_41$$28);
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 327)) {
					ZEPHIR_CALL_METHOD(&_43$$29, this_ptr, "compilereturn", &_44, 0, &statement);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_43$$29);
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 317)) {
					if (extendsMode) {
						ZVAL_BOOL(&_46$$30, 1);
					} else {
						ZVAL_BOOL(&_46$$30, 0);
					}
					ZEPHIR_CALL_METHOD(&_45$$30, this_ptr, "compileautoescape", &_47, 0, &statement, &_46$$30);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_45$$30);
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 319)) {
					zephir_concat_self_str(&compilation, SL("<?php continue; ?>"));
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 320)) {
					zephir_concat_self_str(&compilation, SL("<?php break; ?>"));
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 321)) {
					ZEPHIR_CALL_METHOD(&_48$$33, this_ptr, "compileforelse", &_49, 0);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_48$$33);
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 322)) {
					if (extendsMode) {
						ZVAL_BOOL(&_51$$34, 1);
					} else {
						ZVAL_BOOL(&_51$$34, 0);
					}
					ZEPHIR_CALL_METHOD(&_50$$34, this_ptr, "compilemacro", &_52, 0, &statement, &_51$$34);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_50$$34);
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 325)) {
					if (extendsMode) {
						ZVAL_BOOL(&_54$$35, 1);
					} else {
						ZVAL_BOOL(&_54$$35, 0);
					}
					ZEPHIR_CALL_METHOD(&_53$$35, this_ptr, "compilecall", &_55, 0, &statement, &_54$$35);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_53$$35);
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 358)) {
					break;
				}
				ZEPHIR_INIT_NVAR(&_56$$37);
				object_init_ex(&_56$$37, phalcon_mvc_view_engine_volt_exception_ce);
				zephir_array_fetch_string(&_57$$37, &statement, SL("file"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2865);
				zephir_array_fetch_string(&_58$$37, &statement, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2866);
				ZEPHIR_INIT_NVAR(&_59$$37);
				ZEPHIR_CONCAT_SVSVSV(&_59$$37, "Unknown statement ", &type, " in ", &_57$$37, " on line ", &_58$$37);
				ZEPHIR_CALL_METHOD(NULL, &_56$$37, "__construct", &_8, 504, &_59$$37);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_56$$37, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2866);
				ZEPHIR_MM_RESTORE();
				return;
			} while(0);

		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &statements, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &statements, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&statement, &statements, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&statement) != IS_ARRAY)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2628);
					return;
				}
				if (UNEXPECTED(!(zephir_array_isset_string(&statement, SL("type"))))) {
					ZEPHIR_INIT_NVAR(&_60$$40);
					object_init_ex(&_60$$40, phalcon_mvc_view_engine_volt_exception_ce);
					zephir_array_fetch_string(&_61$$40, &statement, SL("file"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2636);
					zephir_array_fetch_string(&_62$$40, &statement, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2636);
					ZEPHIR_INIT_NVAR(&_63$$40);
					ZEPHIR_CONCAT_SVSV(&_63$$40, "Invalid statement in ", &_61$$40, " on line ", &_62$$40);
					ZEPHIR_CALL_METHOD(NULL, &_60$$40, "__construct", &_8, 504, &_63$$40, &statement);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_60$$40, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2638);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&extensions) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_64$$41);
					zephir_create_array(&_64$$41, 1, 0);
					zephir_array_fast_append(&_64$$41, &statement);
					ZEPHIR_INIT_NVAR(&_65$$41);
					ZVAL_STRING(&_65$$41, "compileStatement");
					ZEPHIR_CALL_METHOD(&tempCompilation, this_ptr, "fireextensionevent", &_11, 507, &_65$$41, &_64$$41);
					zephir_check_call_status();
					if (Z_TYPE_P(&tempCompilation) == IS_STRING) {
						zephir_concat_self(&compilation, &tempCompilation);
						continue;
					}
				}
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch_string(&type, &statement, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2664);
				do {
					if (ZEPHIR_IS_LONG(&type, 357)) {
						zephir_array_fetch_string(&_66$$43, &statement, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2672);
						zephir_concat_self(&compilation, &_66$$43);
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 300)) {
						if (extendsMode) {
							ZVAL_BOOL(&_68$$44, 1);
						} else {
							ZVAL_BOOL(&_68$$44, 0);
						}
						ZEPHIR_CALL_METHOD(&_67$$44, this_ptr, "compileif", &_15, 0, &statement, &_68$$44);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_67$$44);
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 302)) {
						ZEPHIR_CALL_METHOD(&_69$$45, this_ptr, "compileelseif", &_17, 0, &statement);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_69$$45);
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 411)) {
						if (extendsMode) {
							ZVAL_BOOL(&_71$$46, 1);
						} else {
							ZVAL_BOOL(&_71$$46, 0);
						}
						ZEPHIR_CALL_METHOD(&_70$$46, this_ptr, "compileswitch", &_20, 0, &statement, &_71$$46);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_70$$46);
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 412)) {
						ZEPHIR_CALL_METHOD(&_72$$47, this_ptr, "compilecase", &_22, 0, &statement);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_72$$47);
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 413)) {
						ZVAL_BOOL(&_74$$48, 0);
						ZEPHIR_CALL_METHOD(&_73$$48, this_ptr, "compilecase", &_22, 0, &statement, &_74$$48);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_73$$48);
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 304)) {
						if (extendsMode) {
							ZVAL_BOOL(&_76$$49, 1);
						} else {
							ZVAL_BOOL(&_76$$49, 0);
						}
						ZEPHIR_CALL_METHOD(&_75$$49, this_ptr, "compileforeach", &_27, 0, &statement, &_76$$49);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_75$$49);
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 306)) {
						ZEPHIR_CALL_METHOD(&_77$$50, this_ptr, "compileset", &_29, 0, &statement);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_77$$50);
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 359)) {
						ZEPHIR_CALL_METHOD(&_78$$51, this_ptr, "compileecho", &_31, 0, &statement);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_78$$51);
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 307)) {
						ZEPHIR_OBS_NVAR(&blockName);
						zephir_array_fetch_string(&blockName, &statement, SL("name"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2719);
						ZEPHIR_OBS_NVAR(&blockStatements);
						zephir_array_isset_string_fetch(&blockStatements, &statement, SL("block_statements"), 0);
						zephir_read_property(&_79$$52, this_ptr, ZEND_STRL("blocks"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CPY_WRT(&blocks, &_79$$52);
						if (zephir_is_true(&blockMode)) {
							if (Z_TYPE_P(&blocks) != IS_ARRAY) {
								ZEPHIR_INIT_NVAR(&blocks);
								array_init(&blocks);
							}
							if (Z_TYPE_P(&compilation) != IS_NULL) {
								zephir_array_append(&blocks, &compilation, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2734);
								ZEPHIR_INIT_NVAR(&compilation);
								ZVAL_NULL(&compilation);
							}
							zephir_array_update_zval(&blocks, &blockName, &blockStatements, PH_COPY | PH_SEPARATE);
							zephir_update_property_zval(this_ptr, ZEND_STRL("blocks"), &blocks);
						} else {
							if (Z_TYPE_P(&blockStatements) == IS_ARRAY) {
								if (extendsMode) {
									ZVAL_BOOL(&_81$$57, 1);
								} else {
									ZVAL_BOOL(&_81$$57, 0);
								}
								ZEPHIR_CALL_METHOD(&_80$$57, this_ptr, "statementlist", &_35, 505, &blockStatements, &_81$$57);
								zephir_check_call_status();
								zephir_concat_self(&compilation, &_80$$57);
							}
						}
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 310)) {
						ZEPHIR_OBS_NVAR(&path);
						zephir_array_fetch_string(&path, &statement, SL("path"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2759);
						zephir_array_fetch_string(&_82$$58, &path, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2763);
						ZEPHIR_CALL_METHOD(&finalPath, this_ptr, "getfinalpath", &_37, 0, &_82$$58);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&extended);
						ZVAL_BOOL(&extended, 1);
						ZEPHIR_INIT_NVAR(&subCompiler);
						if (zephir_clone(&subCompiler, this_ptr) == FAILURE) {
							RETURN_MM();
						}
						ZEPHIR_CALL_METHOD(&tempCompilation, &subCompiler, "compile", NULL, 0, &finalPath, &extended);
						zephir_check_call_status();
						if (Z_TYPE_P(&tempCompilation) == IS_NULL) {
							ZEPHIR_CALL_METHOD(&_83$$59, &subCompiler, "getcompiledtemplatepath", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&tempCompilation);
							zephir_file_get_contents(&tempCompilation, &_83$$59);
						}
						if (1) {
							zephir_update_property_zval(this_ptr, ZEND_STRL("extended"), &__$true);
						} else {
							zephir_update_property_zval(this_ptr, ZEND_STRL("extended"), &__$false);
						}
						zephir_update_property_zval(this_ptr, ZEND_STRL("extendedBlocks"), &tempCompilation);
						ZEPHIR_CPY_WRT(&blockMode, &extended);
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 313)) {
						ZEPHIR_CALL_METHOD(&_84$$60, this_ptr, "compileinclude", &_40, 0, &statement);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_84$$60);
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 316)) {
						ZEPHIR_CALL_METHOD(&_85$$61, this_ptr, "compiledo", &_42, 0, &statement);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_85$$61);
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 327)) {
						ZEPHIR_CALL_METHOD(&_86$$62, this_ptr, "compilereturn", &_44, 0, &statement);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_86$$62);
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 317)) {
						if (extendsMode) {
							ZVAL_BOOL(&_88$$63, 1);
						} else {
							ZVAL_BOOL(&_88$$63, 0);
						}
						ZEPHIR_CALL_METHOD(&_87$$63, this_ptr, "compileautoescape", &_47, 0, &statement, &_88$$63);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_87$$63);
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 319)) {
						zephir_concat_self_str(&compilation, SL("<?php continue; ?>"));
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 320)) {
						zephir_concat_self_str(&compilation, SL("<?php break; ?>"));
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 321)) {
						ZEPHIR_CALL_METHOD(&_89$$66, this_ptr, "compileforelse", &_49, 0);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_89$$66);
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 322)) {
						if (extendsMode) {
							ZVAL_BOOL(&_91$$67, 1);
						} else {
							ZVAL_BOOL(&_91$$67, 0);
						}
						ZEPHIR_CALL_METHOD(&_90$$67, this_ptr, "compilemacro", &_52, 0, &statement, &_91$$67);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_90$$67);
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 325)) {
						if (extendsMode) {
							ZVAL_BOOL(&_93$$68, 1);
						} else {
							ZVAL_BOOL(&_93$$68, 0);
						}
						ZEPHIR_CALL_METHOD(&_92$$68, this_ptr, "compilecall", &_55, 0, &statement, &_93$$68);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_92$$68);
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 358)) {
						break;
					}
					ZEPHIR_INIT_NVAR(&_94$$70);
					object_init_ex(&_94$$70, phalcon_mvc_view_engine_volt_exception_ce);
					zephir_array_fetch_string(&_95$$70, &statement, SL("file"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2865);
					zephir_array_fetch_string(&_96$$70, &statement, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2866);
					ZEPHIR_INIT_NVAR(&_97$$70);
					ZEPHIR_CONCAT_SVSVSV(&_97$$70, "Unknown statement ", &type, " in ", &_95$$70, " on line ", &_96$$70);
					ZEPHIR_CALL_METHOD(NULL, &_94$$70, "__construct", &_8, 504, &_97$$70);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_94$$70, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2866);
					ZEPHIR_MM_RESTORE();
					return;
				} while(0);

			ZEPHIR_CALL_METHOD(NULL, &statements, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&statement);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&blockMode)) {
		zephir_read_property(&level, this_ptr, ZEND_STRL("blockLevel"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_LONG(&level, 1)) {
			if (Z_TYPE_P(&compilation) != IS_NULL) {
				zephir_update_property_array_append(this_ptr, SL("blocks"), &compilation);
			}
		}
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("blockLevel")));
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("level")));
	RETURN_CCTOR(&compilation);
}

/**
 * Compiles a block of statements
 *
 * @param array statements
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, statementListOrExtends)
{
	zend_bool isStatementList = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statements, statements_sub, statement, *_0$$4, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statements_sub);
	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&_1$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(statements)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &statements);
	if (Z_TYPE_P(statements) != IS_ARRAY) {
		RETVAL_ZVAL(statements, 1, 0);
		RETURN_MM();
	}
	isStatementList = 1;
	if (!(zephir_array_isset_string(statements, SL("type")))) {
		zephir_is_iterable(statements, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2923);
		if (Z_TYPE_P(statements) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(statements), _0$$4)
			{
				ZEPHIR_INIT_NVAR(&statement);
				ZVAL_COPY(&statement, _0$$4);
				if (Z_TYPE_P(&statement) != IS_ARRAY) {
					isStatementList = 0;
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, statements, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$4, statements, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&statement, statements, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&statement) != IS_ARRAY) {
						isStatementList = 0;
						break;
					}
				ZEPHIR_CALL_METHOD(NULL, statements, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&statement);
	}
	if (isStatementList) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "statementlist", NULL, 505, statements);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(statements, 1, 0);
	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, isTagFactory)
{
	zend_bool _0$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expression_param = NULL, left, leftValue, name, _1$$6;
	zval expression;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&leftValue);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(expression)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expression_param);
	zephir_get_arrval(&expression, expression_param);
	zephir_memory_observe(&name);
	if (zephir_array_isset_string_fetch(&name, &expression, SL("name"), 0)) {
		zephir_memory_observe(&left);
		if (zephir_array_isset_string_fetch(&left, &name, SL("left"), 0)) {
			zephir_memory_observe(&leftValue);
			if (zephir_array_isset_string_fetch(&leftValue, &left, SL("value"), 0)) {
				RETURN_MM_BOOL((ZEPHIR_IS_STRING_IDENTICAL(&leftValue, "tag")));
			} else {
				_0$$6 = zephir_array_isset_string(&left, SL("name"));
				if (_0$$6) {
					zephir_memory_observe(&_1$$6);
					zephir_array_fetch_string(&_1$$6, &left, SL("name"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2960);
					_0$$6 = Z_TYPE_P(&_1$$6) == IS_ARRAY;
				}
				if (_0$$6) {
					ZEPHIR_RETURN_CALL_METHOD(this_ptr, "istagfactory", NULL, 506, &left);
					zephir_check_call_status();
					RETURN_MM();
				}
			}
		}
	}
	RETURN_MM_BOOL(0);
}

zend_object *zephir_init_properties_Phalcon_Mvc_View_Engine_Volt_Compiler(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _10, _12, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8, _13$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("macros"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("macros"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("loopPointers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("loopPointers"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("functions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("functions"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("forElsePointers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("forElsePointers"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("filters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("filters"), &_11$$8);
		}
		zephir_read_property_ex(&_12, this_ptr, ZEND_STRL("extensions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$9);
			array_init(&_13$$9);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("extensions"), &_13$$9);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

