
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
#include "kernel/array.h"
#include "kernel/operators.h"
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
 * For the full copyright and license information, please view the LICENSE
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
 *
 * @phpstan-import-type mvc_volt_node from MvcTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Compiler)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\View\\Engine\\Volt, Compiler, phalcon, mvc_view_engine_volt_compiler, phalcon_mvc_view_engine_volt_compiler_method_entry, 0);

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_mvc_view_engine_volt_compiler_ce, SL("autoescape"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_mvc_view_engine_volt_compiler_ce, SL("blockLevel"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * @var array|null
	 *
	 * TODO: Make array only?
	 *
	 * @phpstan-var array<array-key, mixed>|null
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("blocks"), ZEND_ACC_PROTECTED);
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_mvc_view_engine_volt_compiler_ce, SL("container"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Di\\DiInterface"));
	}

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
	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_mvc_view_engine_volt_compiler_ce, SL("exprLevel"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_mvc_view_engine_volt_compiler_ce, SL("extended"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * @var array|bool
	 *
	 * TODO: Make it always array
	 *
	 * @phpstan-var array<array-key, mixed>|bool|string
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("extendedBlocks"), ZEND_ACC_PROTECTED);
	/**
	 * @phpstan-var list<object>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_view_engine_volt_compiler_ce, SL("extensions"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var array<string, mixed>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_view_engine_volt_compiler_ce, SL("filters"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_mvc_view_engine_volt_compiler_ce, SL("foreachLevel"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * @phpstan-var array<int, string>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_view_engine_volt_compiler_ce, SL("forElsePointers"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var array<string, mixed>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_view_engine_volt_compiler_ce, SL("functions"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_mvc_view_engine_volt_compiler_ce, SL("level"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * @phpstan-var array<int, int>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_view_engine_volt_compiler_ce, SL("loopPointers"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var array<string, string>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_view_engine_volt_compiler_ce, SL("macros"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var array<string, mixed>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_view_engine_volt_compiler_ce, SL("options"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @var string
	 *
	 * @phpstan-var Closure|string
	 */
	zend_declare_property_string(phalcon_mvc_view_engine_volt_compiler_ce, SL("prefix"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var ViewBaseInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("view"), ZEND_ACC_PROTECTED);
	/**
	 * The virtual path of each template path (see compile())
	 *
	 * @phpstan-var array<string, string>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_view_engine_volt_compiler_ce, SL("virtualPaths"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("view", 4, 1);
	}

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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1214, view);
}

/**
 * Registers a Volt's extension
 *
 * @var mixed extension
 *
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addExtension)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *extension, extension_sub, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extension_sub);
	ZVAL_UNDEF(&_0$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(extension)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &extension);
	if (UNEXPECTED(Z_TYPE_P(extension) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_view_engine_volt_exceptions_invalidextension_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 181);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if ((zephir_method_exists_ex(extension, ZEND_STRL("initialize")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, extension, "initialize", &_zephir_call_cache[1], this_ptr);
		zephir_check_call_status();
	}
	zephir_update_property_array_append(this_ptr, SL("extensions"), extension);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();
}

/**
 * Register a new filter in the compiler
 *
 * @param string name
 * @param mixed definition
 *
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFilter)
{
	zval name_zv, *definition, definition_sub;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&definition_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(definition)
	ZEND_PARSE_PARAMETERS_END();
	definition = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("filters"), &name_zv, definition);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_THISW();
}

/**
 * Register a new function in the compiler
 *
 * @param string name
 * @param mixed definition
 *
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFunction)
{
	zval name_zv, *definition, definition_sub;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&definition_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(definition)
	ZEND_PARSE_PARAMETERS_END();
	definition = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("functions"), &name_zv, definition);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_THISW();
}

/**
 * Resolves attribute reading
 *
 * @param array expr
 *
 * @return string
 *
 * @phpstan-param mvc_volt_node $expr
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("foreachLevel", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(expr, expr_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expr_param);
	zephir_get_arrval(&expr, expr_param);
	ZEPHIR_INIT_VAR(&exprCode);
	ZVAL_STRING(&exprCode, "");
	zephir_memory_observe(&left);
	zephir_array_fetch_string(&left, &expr, SL("left"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 242);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_0);
	zephir_array_fetch_string(&_0, &left, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 244);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG(&_0, 265)) {
		zephir_memory_observe(&variable);
		zephir_array_fetch_string(&variable, &left, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 245);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_STRING(&variable, "loop")) {
			zephir_memory_observe(&level);
			zephir_read_property_cached(&level, this_ptr, _zephir_prop_0, 1215, PH_NOISY_CC);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_1$$4, this_ptr, "getUniquePrefix", &_zephir_call_cache[0]);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_CONCAT_SVVS(&_2$$4, "$", &_1$$4, &level, "loop");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_concat_self(&exprCode, &_2$$4);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_update_property_array(this_ptr, SL("loopPointers"), &level, &level);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			zephir_read_property_cached(&_3$$5, this_ptr, _zephir_prop_1, 1216, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_4$$5 = Z_TYPE_P(&_3$$5) != IS_NULL;
			if (_4$$5) {
				zephir_read_property_cached(&_5$$5, this_ptr, _zephir_prop_1, 1216, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_6$$5, &_5$$5, "has", &_zephir_call_cache[1], &variable);
				zephir_check_call_status();
				_4$$5 = zephir_is_true(&_6$$5);
			}
			if (_4$$5) {
				ZEPHIR_INIT_VAR(&_7$$6);
				ZEPHIR_CONCAT_SV(&_7$$6, "$this->", &variable);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&exprCode, &_7$$6);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_INIT_VAR(&_8$$7);
				ZEPHIR_CONCAT_SV(&_8$$7, "$", &variable);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&exprCode, &_8$$7);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	} else {
		ZEPHIR_CALL_METHOD_CACHED(&leftCode, this_ptr, "expression", &_zephir_call_cache[2], &left);
		zephir_check_call_status();
		zephir_memory_observe(&leftType);
		zephir_array_fetch_string(&leftType, &left, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 267);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_9$$8 = !ZEPHIR_IS_LONG(&leftType, '.');
		if (_9$$8) {
			_9$$8 = !ZEPHIR_IS_LONG(&leftType, 350);
		}
		if (_9$$8) {
			zephir_concat_self(&exprCode, &leftCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			zephir_concat_self(&exprCode, &leftCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_concat_self_str(&exprCode, "->", sizeof("->") - 1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&right);
	zephir_array_fetch_string(&right, &expr, SL("right"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 278);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_10);
	zephir_array_fetch_string(&_10, &right, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 280);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG(&_10, 265)) {
		zephir_memory_observe(&_11$$11);
		zephir_array_fetch_string(&_11$$11, &right, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 281);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&exprCode, &_11$$11);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CALL_METHOD_CACHED(&_12$$12, this_ptr, "expression", &_zephir_call_cache[3], &right);
		zephir_check_call_status();
		zephir_concat_self(&exprCode, &_12$$12);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
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
	zval _35$$28, _46$$37;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_bool extendsMode, _1, _9, _13, _17, _24, _31, _32, _40, _2$$3, _14$$9, _18$$12, _25$$16, _34$$22, _42$$32;
	zval templatePath_zv, *extendsMode_param = NULL, __$false, blocksCode, compilation, compileAlways, compiledExtension, compiledPath, compiledSeparator, options, prefix, realTemplatePath, stat, templateSepPath, compiledTemplatePath, _0, _39, _3$$4, _4$$4, _6$$6, _7$$6, _8$$6, _10$$8, _11$$8, _12$$8, _15$$10, _16$$10, _19$$13, _20$$13, _21$$15, _22$$15, _23$$15, _26$$17, _27$$17, _28$$19, _29$$19, _30$$19, _33$$22, _36$$28, _37$$29, _38$$30, _41$$31, _43$$32, _44$$33, _45$$36, _47$$38;
	zend_string *templatePath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&templatePath_zv);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&blocksCode);
	ZVAL_UNDEF(&compilation);
	ZVAL_UNDEF(&compileAlways);
	ZVAL_UNDEF(&compiledExtension);
	ZVAL_UNDEF(&compiledPath);
	ZVAL_UNDEF(&compiledSeparator);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&realTemplatePath);
	ZVAL_UNDEF(&stat);
	ZVAL_UNDEF(&templateSepPath);
	ZVAL_UNDEF(&compiledTemplatePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_30$$19);
	ZVAL_UNDEF(&_33$$22);
	ZVAL_UNDEF(&_36$$28);
	ZVAL_UNDEF(&_37$$29);
	ZVAL_UNDEF(&_38$$30);
	ZVAL_UNDEF(&_41$$31);
	ZVAL_UNDEF(&_43$$32);
	ZVAL_UNDEF(&_44$$33);
	ZVAL_UNDEF(&_45$$36);
	ZVAL_UNDEF(&_47$$38);
	ZVAL_UNDEF(&_35$$28);
	ZVAL_UNDEF(&_46$$37);
	ZEND_TLS zephir_method_cache _zephir_call_cache[12];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("virtualPaths", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("compiledTemplatePath", 20, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(templatePath)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		extendsMode_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&templatePath_zv);
	ZVAL_STR_COPY(&templatePath_zv, templatePath);
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&compiledTemplatePath);
	ZVAL_STRING(&compiledTemplatePath, "");
	ZEPHIR_INIT_VAR(&compilation);
	ZVAL_NULL(&compilation);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1217, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&options, &_0);
	zephir_memory_observe(&compileAlways);
	_1 = zephir_array_isset_string_fetch(&compileAlways, &options, SL("always"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		ZEPHIR_OBS_NVAR(&compileAlways);
		_2$$3 = zephir_array_isset_string_fetch(&compileAlways, &options, SL("compileAlways"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_2$$3) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "The 'compileAlways' option is deprecated. Use 'always' instead.");
			ZVAL_LONG(&_4$$4, 16384);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", &_5, 8, &_3$$4, &_4$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&compileAlways);
			ZVAL_BOOL(&compileAlways, 0);
		}
	}
	if (UNEXPECTED(((Z_TYPE_P(&compileAlways) == IS_TRUE || Z_TYPE_P(&compileAlways) == IS_FALSE) != 1))) {
		ZEPHIR_INIT_VAR(&_6$$6);
		object_init_ex(&_6$$6, phalcon_mvc_view_engine_volt_exceptions_invalidoptiontype_ce);
		ZEPHIR_INIT_VAR(&_7$$6);
		ZVAL_STRING(&_7$$6, "always");
		ZEPHIR_INIT_VAR(&_8$$6);
		ZVAL_STRING(&_8$$6, "bool value");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$6, "__construct", &_zephir_call_cache[0], &_7$$6, &_8$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$6, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 330);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&prefix);
	_9 = zephir_array_isset_string_fetch(&prefix, &options, SL("prefix"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_9)) {
		ZEPHIR_INIT_NVAR(&prefix);
		ZVAL_STRING(&prefix, "");
	}
	if (UNEXPECTED(Z_TYPE_P(&prefix) != IS_STRING)) {
		ZEPHIR_INIT_VAR(&_10$$8);
		object_init_ex(&_10$$8, phalcon_mvc_view_engine_volt_exceptions_invalidoptiontype_ce);
		ZEPHIR_INIT_VAR(&_11$$8);
		ZVAL_STRING(&_11$$8, "prefix");
		ZEPHIR_INIT_VAR(&_12$$8);
		ZVAL_STRING(&_12$$8, "string");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_10$$8, "__construct", &_zephir_call_cache[1], &_11$$8, &_12$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$8, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 341);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&compiledPath);
	_13 = zephir_array_isset_string_fetch(&compiledPath, &options, SL("path"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_13)) {
		ZEPHIR_OBS_NVAR(&compiledPath);
		_14$$9 = zephir_array_isset_string_fetch(&compiledPath, &options, SL("compiledPath"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_14$$9) {
			ZEPHIR_INIT_VAR(&_15$$10);
			ZVAL_STRING(&_15$$10, "The 'compiledPath' option is deprecated. Use 'path' instead.");
			ZVAL_LONG(&_16$$10, 16384);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", &_5, 8, &_15$$10, &_16$$10);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&compiledPath);
			ZVAL_STRING(&compiledPath, "");
		}
	}
	zephir_memory_observe(&compiledSeparator);
	_17 = zephir_array_isset_string_fetch(&compiledSeparator, &options, SL("separator"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_17)) {
		ZEPHIR_OBS_NVAR(&compiledSeparator);
		_18$$12 = zephir_array_isset_string_fetch(&compiledSeparator, &options, SL("compiledSeparator"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_18$$12) {
			ZEPHIR_INIT_VAR(&_19$$13);
			ZVAL_STRING(&_19$$13, "The 'compiledSeparator' option is deprecated. Use 'separator' instead.");
			ZVAL_LONG(&_20$$13, 16384);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", &_5, 8, &_19$$13, &_20$$13);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&compiledSeparator);
			ZVAL_STRING(&compiledSeparator, "%%");
		}
	}
	if (UNEXPECTED(Z_TYPE_P(&compiledSeparator) != IS_STRING)) {
		ZEPHIR_INIT_VAR(&_21$$15);
		object_init_ex(&_21$$15, phalcon_mvc_view_engine_volt_exceptions_invalidoptiontype_ce);
		ZEPHIR_INIT_VAR(&_22$$15);
		ZVAL_STRING(&_22$$15, "separator");
		ZEPHIR_INIT_VAR(&_23$$15);
		ZVAL_STRING(&_23$$15, "string");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_21$$15, "__construct", &_zephir_call_cache[2], &_22$$15, &_23$$15);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_21$$15, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 374);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&compiledExtension);
	_24 = zephir_array_isset_string_fetch(&compiledExtension, &options, SL("extension"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_24)) {
		ZEPHIR_OBS_NVAR(&compiledExtension);
		_25$$16 = zephir_array_isset_string_fetch(&compiledExtension, &options, SL("compiledExtension"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_25$$16) {
			ZEPHIR_INIT_VAR(&_26$$17);
			ZVAL_STRING(&_26$$17, "The 'compiledExtension' option is deprecated. Use 'extension' instead.");
			ZVAL_LONG(&_27$$17, 16384);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", &_5, 8, &_26$$17, &_27$$17);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&compiledExtension);
			ZVAL_STRING(&compiledExtension, ".php");
		}
	}
	if (UNEXPECTED(Z_TYPE_P(&compiledExtension) != IS_STRING)) {
		ZEPHIR_INIT_VAR(&_28$$19);
		object_init_ex(&_28$$19, phalcon_mvc_view_engine_volt_exceptions_invalidoptiontype_ce);
		ZEPHIR_INIT_VAR(&_29$$19);
		ZVAL_STRING(&_29$$19, "extension");
		ZEPHIR_INIT_VAR(&_30$$19);
		ZVAL_STRING(&_30$$19, "string");
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_28$$19, "__construct", &_zephir_call_cache[3], &_29$$19, &_30$$19);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_28$$19, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 392);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&stat);
	_31 = zephir_array_isset_string_fetch(&stat, &options, SL("stat"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_31)) {
		ZEPHIR_INIT_NVAR(&stat);
		ZVAL_BOOL(&stat, 1);
	}
	if (Z_TYPE_P(&compiledPath) == IS_STRING) {
		if (!(ZEPHIR_IS_EMPTY(&compiledPath))) {
			zephir_memory_observe(&templateSepPath);
			zephir_read_property_cached(&_33$$22, this_ptr, _zephir_prop_1, 1218, PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_34$$22 = zephir_array_isset_fetch(&templateSepPath, &_33$$22, &templatePath_zv, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_34$$22)) {
				ZEPHIR_CALL_FUNCTION(&realTemplatePath, "realpath", NULL, 42, &templatePath_zv);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&templateSepPath);
				zephir_prepare_virtual_path(&templateSepPath, &realTemplatePath, &compiledSeparator);
				if (Z_TYPE_P(&realTemplatePath) == IS_STRING) {
					zephir_update_property_array(this_ptr, SL("virtualPaths"), &templatePath_zv, &templateSepPath);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		} else {
			ZEPHIR_CPY_WRT(&templateSepPath, &templatePath_zv);
		}
		ZEPHIR_INIT_NVAR(&compiledTemplatePath);
		if (extendsMode) {
			ZEPHIR_CONCAT_VVVVSVV(&compiledTemplatePath, &compiledPath, &prefix, &templateSepPath, &compiledSeparator, "e", &compiledSeparator, &compiledExtension);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CONCAT_VVVV(&compiledTemplatePath, &compiledPath, &prefix, &templateSepPath, &compiledExtension);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		_32 = Z_TYPE_P(&compiledPath) == IS_OBJECT;
		if (_32) {
			_32 = zephir_is_instance_of(&compiledPath, SL("Closure"));
		}
		if (_32) {
			ZEPHIR_INIT_VAR(&_35$$28);
			zephir_create_array(&_35$$28, 3, 0);
			zephir_array_fast_append(&_35$$28, &templatePath_zv);
			zephir_array_fast_append(&_35$$28, &options);
			ZEPHIR_INIT_VAR(&_36$$28);
			ZVAL_BOOL(&_36$$28, extendsMode);
			zephir_array_fast_append(&_35$$28, &_36$$28);
			ZEPHIR_INIT_NVAR(&compiledTemplatePath);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&compiledTemplatePath, &compiledPath, &_35$$28);
			zephir_check_call_status();
			if (UNEXPECTED(Z_TYPE_P(&compiledTemplatePath) != IS_STRING)) {
				ZEPHIR_INIT_VAR(&_37$$29);
				object_init_ex(&_37$$29, phalcon_mvc_view_engine_volt_exceptions_invalidpathclosurereturn_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_37$$29, "__construct", &_zephir_call_cache[4]);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_37$$29, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 451);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_INIT_VAR(&_38$$30);
			object_init_ex(&_38$$30, phalcon_mvc_view_engine_volt_exceptions_invalidpathtype_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_38$$30, "__construct", &_zephir_call_cache[5]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_38$$30, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 454);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_39, this_ptr, "phpFileExists", &_zephir_call_cache[6], &compiledTemplatePath);
	zephir_check_call_status();
	_40 = !zephir_is_true(&_39);
	if (!(_40)) {
		_40 = zephir_is_true(&compileAlways);
	}
	if (_40) {
		if (extendsMode) {
			ZVAL_BOOL(&_41$$31, 1);
		} else {
			ZVAL_BOOL(&_41$$31, 0);
		}
		ZEPHIR_CALL_METHOD_CACHED(&compilation, this_ptr, "compileFile", &_zephir_call_cache[7], &templatePath_zv, &compiledTemplatePath, &_41$$31);
		zephir_check_call_status();
	} else {
		_42$$32 = ZEPHIR_IS_TRUE_IDENTICAL(&stat);
		if (_42$$32) {
			ZEPHIR_INIT_VAR(&_43$$32);
			_42$$32 = zephir_compare_mtime(&templatePath_zv, &compiledTemplatePath);
		}
		if (_42$$32) {
			if (extendsMode) {
				ZVAL_BOOL(&_44$$33, 1);
			} else {
				ZVAL_BOOL(&_44$$33, 0);
			}
			ZEPHIR_CALL_METHOD_CACHED(&compilation, this_ptr, "compileFile", &_zephir_call_cache[8], &templatePath_zv, &compiledTemplatePath, &_44$$33);
			zephir_check_call_status();
		} else {
			if (extendsMode) {
				ZEPHIR_CALL_METHOD_CACHED(&blocksCode, this_ptr, "phpFileGetContents", &_zephir_call_cache[9], &compiledTemplatePath);
				zephir_check_call_status();
				if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&blocksCode))) {
					ZEPHIR_INIT_VAR(&_45$$36);
					object_init_ex(&_45$$36, phalcon_mvc_view_engine_volt_exceptions_cannotopencompiledfile_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_45$$36, "__construct", &_zephir_call_cache[10], &compiledTemplatePath);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_45$$36, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 490);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(&blocksCode)) {
					ZEPHIR_INIT_VAR(&_46$$37);
					zephir_create_array(&_46$$37, 1, 0);
					zephir_array_update_string(&_46$$37, SL("allowed_classes"), &__$false, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_FUNCTION(&compilation, "unserialize", NULL, 17, &blocksCode, &_46$$37);
					zephir_check_call_status();
					if (Z_TYPE_P(&compilation) != IS_ARRAY) {
						if (extendsMode) {
							ZVAL_BOOL(&_47$$38, 1);
						} else {
							ZVAL_BOOL(&_47$$38, 0);
						}
						ZEPHIR_CALL_METHOD_CACHED(&compilation, this_ptr, "compileFile", &_zephir_call_cache[11], &templatePath_zv, &compiledTemplatePath, &_47$$38);
						zephir_check_call_status();
					}
				} else {
					ZEPHIR_INIT_NVAR(&compilation);
					array_init(&compilation);
				}
			}
		}
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1219, &compiledTemplatePath);
	RETURN_CCTOR(&compilation);
}

/**
 * Compiles a "autoescape" statement returning PHP code
 *
 * @param array statement
 * @param bool extendsMode
 *
 * @return string
 *
 * @phpstan-param mvc_volt_node $statement
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileAutoEscape)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode, _0;
	zval *statement_param = NULL, *extendsMode_param = NULL, autoescape, oldAutoescape, compilation, _2, _3, _1$$3;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&autoescape);
	ZVAL_UNDEF(&oldAutoescape);
	ZVAL_UNDEF(&compilation);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("autoescape", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(statement, statement_param)
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &statement_param, &extendsMode_param);
	zephir_get_arrval(&statement, statement_param);
	zephir_memory_observe(&autoescape);
	_0 = zephir_array_isset_string_fetch(&autoescape, &statement, SL("enable"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_view_engine_volt_exceptions_corruptedstatement_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 540);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&oldAutoescape);
	zephir_read_property_cached(&oldAutoescape, this_ptr, _zephir_prop_0, 1220, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1220, &autoescape);
	zephir_array_fetch_string(&_2, &statement, SL("block_statements"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 550);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (extendsMode) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_CALL_METHOD_CACHED(&compilation, this_ptr, "statementList", &_zephir_call_cache[1], &_2, &_3);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1220, &oldAutoescape);
	RETURN_CCTOR(&compilation);
}

/**
 * Compiles calls to macros
 *
 * @param array statement
 * @param bool extendsMode
 *
 * @phpstan-param mvc_volt_node $statement
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCall)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, _0, _1, _3, _4;
	zval statement;

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(statement, statement_param)
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &statement_param, &extendsMode_param);
	zephir_get_arrval(&statement, statement_param);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_mvc_view_engine_volt_exceptions_callnotsupported_ce);
	zephir_memory_observe(&_1);
	zephir_array_fetch_string(&_1, &statement, SL("file"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 572);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_cast_to_string(&_2, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_3);
	zephir_array_fetch_string(&_3, &statement, SL("line"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 574);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_LONG(&_4, zephir_get_intval(&_3));
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0], &_2, &_4);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 574);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Compiles a "case"/"default" clause returning PHP code
 *
 * @param array statement
 * @param bool caseClause
 *
 * @return string
 *
 * @phpstan-param mvc_volt_node $statement
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCase)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool caseClause, _0;
	zval *statement_param = NULL, *caseClause_param = NULL, expr, _2, _1$$4;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(statement, statement_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(caseClause)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &statement_param, &caseClause_param);
	zephir_get_arrval(&statement, statement_param);
	if (!caseClause_param) {
		caseClause = 1;
	} else {
		}
	if (UNEXPECTED(caseClause == 0)) {
		RETURN_MM_STRING("<?php default: ?>");
	}
	zephir_memory_observe(&expr);
	_0 = zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_view_engine_volt_exceptions_corruptedstatementwithdata_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$4, "__construct", &_zephir_call_cache[0], &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 602);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "expression", &_zephir_call_cache[1], &expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php case ", &_2, ": ?>");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Compiles a "do" statement returning PHP code
 *
 * @phpstan-param mvc_volt_node $statement
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileDo)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, expr, _2, _1$$3;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(statement, statement_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &statement_param);
	zephir_get_arrval(&statement, statement_param);
	zephir_memory_observe(&expr);
	_0 = zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_view_engine_volt_exceptions_corruptedstatement_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 626);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "expression", &_zephir_call_cache[1], &expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php ", &_2, "; ?>");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Compiles a `{{` `}}` statement returning PHP code
 *
 * @phpstan-param mvc_volt_node $statement
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileEcho)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, expr, exprCode, name, _2, _7, _1$$3, _3$$4, _5$$4, _4$$5, _6$$6;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&exprCode);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("autoescape", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(statement, statement_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &statement_param);
	zephir_get_arrval(&statement, statement_param);
	zephir_memory_observe(&expr);
	_0 = zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_view_engine_volt_exceptions_corruptedstatementwithdata_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0], &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 650);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&exprCode, this_ptr, "expression", &_zephir_call_cache[1], &expr);
	zephir_check_call_status();
	zephir_memory_observe(&_2);
	zephir_array_fetch_string(&_2, &expr, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 658);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG(&_2, 350)) {
		ZEPHIR_CALL_METHOD_CACHED(&_3$$4, this_ptr, "isTagFactory", &_zephir_call_cache[2], &expr);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_3$$4)) {
			ZVAL_BOOL(&_4$$5, 1);
			ZEPHIR_CALL_METHOD_CACHED(&exprCode, this_ptr, "expression", &_zephir_call_cache[3], &expr, &_4$$5);
			zephir_check_call_status();
		}
		zephir_memory_observe(&name);
		zephir_array_fetch_string(&name, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 663);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_5$$4);
		zephir_array_fetch_string(&_5$$4, &name, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 664);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(&_5$$4, 265)) {
			zephir_memory_observe(&_6$$6);
			zephir_array_fetch_string(&_6$$6, &name, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 669);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_STRING(&_6$$6, "super")) {
				RETURN_CCTOR(&exprCode);
			}
		}
	}
	zephir_read_property_cached(&_7, this_ptr, _zephir_prop_0, 1220, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(&_7)) {
		ZEPHIR_CONCAT_SVS(return_value, "<?= $this->escaper->html(", &exprCode, ") ?>");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "<?= ", &exprCode, " ?>");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Compiles a "elseif" statement returning PHP code
 *
 * @phpstan-param mvc_volt_node $statement
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileElseIf)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, expr, _2, _1$$3;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(statement, statement_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &statement_param);
	zephir_get_arrval(&statement, statement_param);
	zephir_memory_observe(&expr);
	_0 = zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_view_engine_volt_exceptions_corruptedstatementwithdata_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0], &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 700);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "expression", &_zephir_call_cache[1], &expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php } elseif (", &_2, ") { ?>");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
 *
 * @phpstan-return array<array-key, mixed>|string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode, _0;
	zval path_zv, compiledPath_zv, *extendsMode_param = NULL, viewCode, compilation, finalCompilation, _2, _5, _6, _1$$3, _3$$4, _4$$5, _7$$8;
	zend_string *path = NULL, *compiledPath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&compiledPath_zv);
	ZVAL_UNDEF(&viewCode);
	ZVAL_UNDEF(&compilation);
	ZVAL_UNDEF(&finalCompilation);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7$$8);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("currentPath", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(path)
		Z_PARAM_STR(compiledPath)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		extendsMode_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	zephir_memory_observe(&compiledPath_zv);
	ZVAL_STR_COPY(&compiledPath_zv, compiledPath);
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		}
	_0 = ZEPHIR_IS_EQUAL(&path_zv, &compiledPath_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_view_engine_volt_exceptions_templatepathcollision_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 733);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "phpFileExists", &_zephir_call_cache[1], &path_zv);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_2))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, phalcon_mvc_view_engine_volt_exceptions_templatefilenotfound_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_3$$4, "__construct", &_zephir_call_cache[2], &path_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 740);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&viewCode, this_ptr, "phpFileGetContents", &_zephir_call_cache[3], &path_zv);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&viewCode))) {
		ZEPHIR_INIT_VAR(&_4$$5);
		object_init_ex(&_4$$5, phalcon_mvc_view_engine_volt_exceptions_templatefilenotopenable_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$5, "__construct", &_zephir_call_cache[4], &path_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$5, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 750);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1221, &path_zv);
	if (extendsMode) {
		ZVAL_BOOL(&_5, 1);
	} else {
		ZVAL_BOOL(&_5, 0);
	}
	ZEPHIR_CALL_METHOD_CACHED(&compilation, this_ptr, "compileSource", &_zephir_call_cache[5], &viewCode, &_5);
	zephir_check_call_status();
	if (Z_TYPE_P(&compilation) == IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&finalCompilation, "serialize", NULL, 13, &compilation);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&finalCompilation, &compilation);
	}
	ZEPHIR_CALL_METHOD_CACHED(&_6, this_ptr, "phpFilePutContents", &_zephir_call_cache[6], &compiledPath_zv, &finalCompilation);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_6))) {
		ZEPHIR_INIT_VAR(&_7$$8);
		object_init_ex(&_7$$8, phalcon_mvc_view_engine_volt_exceptions_voltdirectorynotwritable_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_7$$8, "__construct", &_zephir_call_cache[7]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$8, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 771);
		ZEPHIR_MM_RESTORE();
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
 *
 * @phpstan-param mvc_volt_node $statement
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForeach)
{
	zval compilation;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode, _0, _12, _22, _25, _28, _36, _8$$4, _5$$5, _9$$8, _37$$21;
	zval *statement_param = NULL, *extendsMode_param = NULL, prefix, level, prefixLevel, expr, exprCode, bstatement, type, blockStatements, forElse, code, loopContext, iterator, key, ifExpr, variable, _11, _1$$3, *_2$$4, _3$$4, *_4$$4, _7$$4, _6$$7, _10$$10, _13$$11, _14$$11, _15$$11, _16$$11, _17$$11, _18$$11, _19$$11, _20$$11, _21$$11, _23$$13, _24$$14, _26$$15, _27$$15, _29$$17, _30$$17, _31$$17, _32$$17, _33$$17, _34$$17, _35$$18, _38$$22;
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
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_29$$17);
	ZVAL_UNDEF(&_30$$17);
	ZVAL_UNDEF(&_31$$17);
	ZVAL_UNDEF(&_32$$17);
	ZVAL_UNDEF(&_33$$17);
	ZVAL_UNDEF(&_34$$17);
	ZVAL_UNDEF(&_35$$18);
	ZVAL_UNDEF(&_38$$22);
	ZVAL_UNDEF(&compilation);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("foreachLevel", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("loopPointers", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(statement, statement_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &statement_param, &extendsMode_param);
	zephir_get_arrval(&statement, statement_param);
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		}
	_0 = zephir_array_isset_value_string(&statement, SL("expr"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_view_engine_volt_exceptions_corruptedstatement_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 798);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&compilation);
	ZVAL_STRING(&compilation, "");
	ZEPHIR_INIT_VAR(&forElse);
	ZVAL_NULL(&forElse);
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("foreachLevel")));
	ZEPHIR_CALL_METHOD_CACHED(&prefix, this_ptr, "getUniquePrefix", &_zephir_call_cache[1]);
	zephir_check_call_status();
	zephir_memory_observe(&level);
	zephir_read_property_cached(&level, this_ptr, _zephir_prop_0, 1215, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&prefixLevel);
	ZEPHIR_CONCAT_VV(&prefixLevel, &prefix, &level);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&expr);
	zephir_array_fetch_string(&expr, &statement, SL("expr"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 816);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&exprCode, this_ptr, "expression", &_zephir_call_cache[2], &expr);
	zephir_check_call_status();
	zephir_memory_observe(&blockStatements);
	zephir_array_fetch_string(&blockStatements, &statement, SL("block_statements"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 822);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&forElse);
	ZVAL_BOOL(&forElse, 0);
	if (Z_TYPE_P(&blockStatements) == IS_ARRAY) {
		if (Z_TYPE_P(&blockStatements) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_string_to_char_array(&_3$$4, &blockStatements);
			_2$$4 = &_3$$4;
		} else {
			_2$$4 = &blockStatements;
		}
		zephir_is_iterable(_2$$4, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 842);
		if (Z_TYPE_P(_2$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2$$4), _4$$4)
			{
				ZEPHIR_INIT_NVAR(&bstatement);
				ZVAL_COPY(&bstatement, _4$$4);
				ZEPHIR_OBS_NVAR(&type);
				_5$$5 = zephir_array_isset_string_fetch(&type, &bstatement, SL("type"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_5$$5)) {
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 321)) {
					ZEPHIR_INIT_NVAR(&_6$$7);
					ZEPHIR_CONCAT_SVS(&_6$$7, "<?php $", &prefixLevel, "iterated = false; ?>");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&compilation, &_6$$7);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&forElse, &prefixLevel);
					zephir_update_property_array(this_ptr, SL("forElsePointers"), &level, &forElse);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _2$$4, "rewind", &_zephir_call_cache[3]);
			zephir_check_call_status();
			_8$$4 = 1;
			while (1) {
				if (_8$$4) {
					_8$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _2$$4, "next", &_zephir_call_cache[4]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_7$$4, _2$$4, "valid", &_zephir_call_cache[5]);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&bstatement, _2$$4, "current", &_zephir_call_cache[6]);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&type);
					_9$$8 = zephir_array_isset_string_fetch(&type, &bstatement, SL("type"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_9$$8)) {
						break;
					}
					if (ZEPHIR_IS_LONG(&type, 321)) {
						ZEPHIR_INIT_NVAR(&_10$$10);
						ZEPHIR_CONCAT_SVS(&_10$$10, "<?php $", &prefixLevel, "iterated = false; ?>");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&compilation, &_10$$10);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CPY_WRT(&forElse, &prefixLevel);
						zephir_update_property_array(this_ptr, SL("forElsePointers"), &level, &forElse);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						break;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&bstatement);
	}
	if (extendsMode) {
		ZVAL_BOOL(&_11, 1);
	} else {
		ZVAL_BOOL(&_11, 0);
	}
	ZEPHIR_CALL_METHOD_CACHED(&code, this_ptr, "statementList", &_zephir_call_cache[7], &blockStatements, &_11);
	zephir_check_call_status();
	zephir_memory_observe(&loopContext);
	zephir_read_property_cached(&loopContext, this_ptr, _zephir_prop_1, 1222, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_12 = zephir_array_isset_value(&loopContext, &level);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_12) {
		ZEPHIR_INIT_VAR(&_13$$11);
		ZEPHIR_CONCAT_SVSVS(&_13$$11, "<?php $", &prefixLevel, "iterator = ", &exprCode, "; ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_13$$11);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_14$$11);
		ZEPHIR_CONCAT_SVS(&_14$$11, "$", &prefixLevel, "incr = 0; ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_14$$11);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_15$$11);
		ZEPHIR_CONCAT_SVS(&_15$$11, "$", &prefixLevel, "loop = new stdClass(); ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_15$$11);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_16$$11);
		ZEPHIR_CONCAT_SVSVS(&_16$$11, "$", &prefixLevel, "loop->self = &$", &prefixLevel, "loop; ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_16$$11);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_17$$11);
		ZEPHIR_CONCAT_SVSVS(&_17$$11, "$", &prefixLevel, "loop->length = count($", &prefixLevel, "iterator); ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_17$$11);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_18$$11);
		ZEPHIR_CONCAT_SVS(&_18$$11, "$", &prefixLevel, "loop->index = 1; ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_18$$11);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_19$$11);
		ZEPHIR_CONCAT_SVS(&_19$$11, "$", &prefixLevel, "loop->index0 = 1; ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_19$$11);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_20$$11);
		ZEPHIR_CONCAT_SVSVS(&_20$$11, "$", &prefixLevel, "loop->revindex = $", &prefixLevel, "loop->length; ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_20$$11);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_21$$11);
		ZEPHIR_CONCAT_SVSVS(&_21$$11, "$", &prefixLevel, "loop->revindex0 = $", &prefixLevel, "loop->length - 1; ?>");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_21$$11);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&iterator);
		ZEPHIR_CONCAT_SVS(&iterator, "$", &prefixLevel, "iterator");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CPY_WRT(&iterator, &exprCode);
	}
	zephir_memory_observe(&variable);
	zephir_array_fetch_string(&variable, &statement, SL("variable"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 872);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&key);
	_22 = zephir_array_isset_string_fetch(&key, &statement, SL("key"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_22) {
		ZEPHIR_INIT_VAR(&_23$$13);
		ZEPHIR_CONCAT_SVSVSVS(&_23$$13, "<?php foreach (", &iterator, " as $", &key, " => $", &variable, ") { ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_23$$13);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(&_24$$14);
		ZEPHIR_CONCAT_SVSVS(&_24$$14, "<?php foreach (", &iterator, " as $", &variable, ") { ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_24$$14);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&ifExpr);
	_25 = zephir_array_isset_string_fetch(&ifExpr, &statement, SL("if_expr"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_25) {
		ZEPHIR_CALL_METHOD_CACHED(&_26$$15, this_ptr, "expression", &_zephir_call_cache[8], &ifExpr);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_27$$15);
		ZEPHIR_CONCAT_SVS(&_27$$15, "if (", &_26$$15, ") { ?>");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_27$$15);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		zephir_concat_self_str(&compilation, "?>", sizeof("?>") - 1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_28 = zephir_array_isset_value(&loopContext, &level);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_28) {
		ZEPHIR_INIT_VAR(&_29$$17);
		ZEPHIR_CONCAT_SVSVS(&_29$$17, "<?php $", &prefixLevel, "loop->first = ($", &prefixLevel, "incr == 0); ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_29$$17);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_30$$17);
		ZEPHIR_CONCAT_SVSVS(&_30$$17, "$", &prefixLevel, "loop->index = $", &prefixLevel, "incr + 1; ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_30$$17);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_31$$17);
		ZEPHIR_CONCAT_SVSVS(&_31$$17, "$", &prefixLevel, "loop->index0 = $", &prefixLevel, "incr; ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_31$$17);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_32$$17);
		ZEPHIR_CONCAT_SVSVSVS(&_32$$17, "$", &prefixLevel, "loop->revindex = $", &prefixLevel, "loop->length - $", &prefixLevel, "incr; ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_32$$17);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_33$$17);
		ZEPHIR_CONCAT_SVSVSVS(&_33$$17, "$", &prefixLevel, "loop->revindex0 = $", &prefixLevel, "loop->length - ($", &prefixLevel, "incr + 1); ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_33$$17);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_34$$17);
		ZEPHIR_CONCAT_SVSVSVS(&_34$$17, "$", &prefixLevel, "loop->last = ($", &prefixLevel, "incr == ($", &prefixLevel, "loop->length - 1)); ?>");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_34$$17);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(&forElse) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_35$$18);
		ZEPHIR_CONCAT_SVS(&_35$$18, "<?php $", &forElse, "iterated = true; ?>");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_35$$18);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_concat_self(&compilation, &code);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_36 = zephir_array_isset_value_string(&statement, SL("if_expr"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_36) {
		zephir_concat_self_str(&compilation, "<?php } ?>", sizeof("<?php } ?>") - 1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(&forElse) == IS_STRING) {
		zephir_concat_self_str(&compilation, "<?php } ?>", sizeof("<?php } ?>") - 1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		_37$$21 = zephir_array_isset_value(&loopContext, &level);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_37$$21) {
			ZEPHIR_INIT_VAR(&_38$$22);
			ZEPHIR_CONCAT_SVS(&_38$$22, "<?php $", &prefixLevel, "incr++; } ?>");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_concat_self(&compilation, &_38$$22);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			zephir_concat_self_str(&compilation, "<?php } ?>", sizeof("<?php } ?>") - 1);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
	zend_bool _1, _3;
	zval level, prefix, _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("foreachLevel", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("forElsePointers", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("loopPointers", 12, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&level);
	zephir_read_property_cached(&level, this_ptr, _zephir_prop_0, 1215, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&prefix);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1223, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_fetch(&prefix, &_0, &level, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		RETURN_MM_STRING("");
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_2, 1222, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_array_isset_value(&_2, &level);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		ZEPHIR_CONCAT_SVSVS(return_value, "<?php $", &prefix, "incr++; } if (!$", &prefix, "iterated) { ?>");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "<?php } if (!$", &prefix, "iterated) { ?>");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
 *
 * @phpstan-param mvc_volt_node $statement
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileIf)
{
	zval compilation;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode, _0, _7;
	zval *statement_param = NULL, *extendsMode_param = NULL, blockStatements, expr, _2, _3, _4, _5, _6, _1$$3, _8$$4, _9$$4, _10$$4;
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
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&compilation);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(statement, statement_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &statement_param, &extendsMode_param);
	zephir_get_arrval(&statement, statement_param);
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		}
	zephir_memory_observe(&expr);
	_0 = zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_view_engine_volt_exceptions_corruptedstatementwithdata_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0], &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 977);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "expression", &_zephir_call_cache[1], &expr);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, &statement, SL("true_statements"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 983);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (extendsMode) {
		ZVAL_BOOL(&_5, 1);
	} else {
		ZVAL_BOOL(&_5, 0);
	}
	ZEPHIR_CALL_METHOD_CACHED(&_3, this_ptr, "statementList", &_zephir_call_cache[2], &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SVSV(&_6, "<?php if (", &_2, ") { ?>", &_3);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&compilation, &_6);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&blockStatements);
	_7 = zephir_array_isset_string_fetch(&blockStatements, &statement, SL("false_statements"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_7) {
		if (extendsMode) {
			ZVAL_BOOL(&_9$$4, 1);
		} else {
			ZVAL_BOOL(&_9$$4, 0);
		}
		ZEPHIR_CALL_METHOD_CACHED(&_8$$4, this_ptr, "statementList", &_zephir_call_cache[3], &blockStatements, &_9$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$4);
		ZEPHIR_CONCAT_SV(&_10$$4, "<?php } else { ?>", &_8$$4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&compilation, &_10$$4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_concat_self_str(&compilation, "<?php } ?>", sizeof("<?php } ?>") - 1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&compilation);
}

/**
 * Compiles a 'include' statement returning PHP code
 *
 * @param array statement
 *
 * @throws \Phalcon\Mvc\View\Engine\Volt\Exception
 * @return string
 *
 * @phpstan-param mvc_volt_node $statement
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileInclude)
{
	zend_bool _0, _6, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, pathExpr, path, subCompiler, finalPath, compilation, params, _2, _7, _1$$3, _4$$5, _5$$6;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&pathExpr);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&subCompiler);
	ZVAL_UNDEF(&finalPath);
	ZVAL_UNDEF(&compilation);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(statement, statement_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &statement_param);
	zephir_get_arrval(&statement, statement_param);
	zephir_memory_observe(&pathExpr);
	_0 = zephir_array_isset_string_fetch(&pathExpr, &statement, SL("path"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_view_engine_volt_exceptions_corruptedstatement_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1019);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_2);
	zephir_array_fetch_string(&_2, &pathExpr, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1026);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG(&_2, 260)) {
		_3$$4 = zephir_array_isset_value_string(&statement, SL("params"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(_3$$4)) {
			zephir_memory_observe(&path);
			zephir_array_fetch_string(&path, &pathExpr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1035);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&finalPath, this_ptr, "getFinalPath", &_zephir_call_cache[1], &path);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&subCompiler);
			if (zephir_clone(&subCompiler, this_ptr) == FAILURE) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_BOOL(&_4$$5, 0);
			ZEPHIR_CALL_METHOD_CACHED(&compilation, &subCompiler, "compile", &_zephir_call_cache[2], &finalPath, &_4$$5);
			zephir_check_call_status();
			if (Z_TYPE_P(&compilation) == IS_NULL) {
				ZEPHIR_CALL_METHOD_CACHED(&_5$$6, &subCompiler, "getCompiledTemplatePath", &_zephir_call_cache[3]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&compilation, this_ptr, "phpFileGetContents", &_zephir_call_cache[4], &_5$$6);
				zephir_check_call_status();
			}
			RETURN_CCTOR(&compilation);
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&path, this_ptr, "expression", &_zephir_call_cache[5], &pathExpr);
	zephir_check_call_status();
	zephir_memory_observe(&params);
	_6 = zephir_array_isset_string_fetch(&params, &statement, SL("params"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_6)) {
		ZEPHIR_CONCAT_SVS(return_value, "<?php $this->partial(", &path, "); ?>");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD_CACHED(&_7, this_ptr, "expression", &_zephir_call_cache[6], &params);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "<?php $this->partial(", &path, ", ", &_7, "); ?>");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Compiles macros
 *
 * @phpstan-param mvc_volt_node $statement
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileMacro)
{
	zend_string *_13$$6;
	zend_ulong _12$$6;
	zval code, macroName, _36, _7$$5, _8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode, _0, _3, _6, _32, _23$$6, _18$$7, _28$$10;
	zval *statement_param = NULL, *extendsMode_param = NULL, name, defaultValue, parameters, position, parameter, variableName, blockStatements, _2, _5, _1$$3, _4$$4, *_9$$6, _10$$6, *_11$$6, _22$$6, _14$$7, _15$$7, _16$$7, _17$$7, _19$$8, _20$$8, _21$$9, _24$$10, _25$$10, _26$$10, _27$$10, _29$$11, _30$$11, _31$$12, _33$$13, _34$$13, _35$$13;
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&macroName);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZEND_TLS zephir_method_cache _zephir_call_cache[10];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("macros", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(statement, statement_param)
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &statement_param, &extendsMode_param);
	zephir_get_arrval(&statement, statement_param);
	zephir_memory_observe(&name);
	_0 = zephir_array_isset_string_fetch(&name, &statement, SL("name"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_view_engine_volt_exceptions_corruptedstatement_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1093);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 1224, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_array_isset_value(&_2, &name);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(_3)) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_mvc_view_engine_volt_exceptions_macroalreadydefined_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$4, "__construct", &_zephir_call_cache[1], &name);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1100);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("macros"), &name, &name);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SVS(&_5, "$this->macros['", &name, "']");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&macroName, &_5);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&code);
	ZVAL_STRING(&code, "<?php ");
	zephir_memory_observe(&parameters);
	_6 = zephir_array_isset_string_fetch(&parameters, &statement, SL("parameters"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_6)) {
		ZEPHIR_INIT_VAR(&_7$$5);
		ZEPHIR_CONCAT_VS(&_7$$5, &macroName, " = function() { ?>");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&code, &_7$$5);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(&_8$$6);
		ZEPHIR_CONCAT_VS(&_8$$6, &macroName, " = function($__p = null) { ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&code, &_8$$6);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&parameters) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_10$$6);
			zephir_string_to_char_array(&_10$$6, &parameters);
			_9$$6 = &_10$$6;
		} else {
			_9$$6 = &parameters;
		}
		zephir_is_iterable(_9$$6, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1137);
		if (Z_TYPE_P(_9$$6) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_9$$6), _12$$6, _13$$6, _11$$6)
			{
				ZEPHIR_INIT_NVAR(&position);
				if (_13$$6 != NULL) { 
					ZVAL_STR_COPY(&position, _13$$6);
				} else {
					ZVAL_LONG(&position, _12$$6);
				}
				ZEPHIR_INIT_NVAR(&parameter);
				ZVAL_COPY(&parameter, _11$$6);
				ZEPHIR_OBS_NVAR(&variableName);
				zephir_array_fetch_string(&variableName, &parameter, SL("variable"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1119);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_14$$7);
				ZEPHIR_CONCAT_SVS(&_14$$7, "if (isset($__p[", &position, "])) { ");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&code, &_14$$7);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_15$$7);
				ZEPHIR_CONCAT_SVSVS(&_15$$7, "$", &variableName, " = $__p[", &position, "];");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&code, &_15$$7);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self_str(&code, " } else { ", sizeof(" } else { ") - 1);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_16$$7);
				ZEPHIR_CONCAT_SVS(&_16$$7, "if (array_key_exists(\"", &variableName, "\", $__p)) { ");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&code, &_16$$7);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_17$$7);
				ZEPHIR_CONCAT_SVSVS(&_17$$7, "$", &variableName, " = $__p[\"", &variableName, "\"];");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&code, &_17$$7);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self_str(&code, " } else { ", sizeof(" } else { ") - 1);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&defaultValue);
				_18$$7 = zephir_array_isset_string_fetch(&defaultValue, &parameter, SL("default"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (EXPECTED(_18$$7)) {
					ZEPHIR_CALL_METHOD_CACHED(&_19$$8, this_ptr, "expression", &_zephir_call_cache[2], &defaultValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_20$$8);
					ZEPHIR_CONCAT_SVSVS(&_20$$8, "$", &variableName, " = ", &_19$$8, ";");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_20$$8);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_21$$9);
					ZEPHIR_CONCAT_SVSVS(&_21$$9, " throw new \\Phalcon\\Mvc\\View\\Exception(\"Macro '", &name, "' was called without parameter: ", &variableName, "\"); ");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_21$$9);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_concat_self_str(&code, " } } ", sizeof(" } } ") - 1);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$6, "rewind", &_zephir_call_cache[3]);
			zephir_check_call_status();
			_23$$6 = 1;
			while (1) {
				if (_23$$6) {
					_23$$6 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$6, "next", &_zephir_call_cache[4]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_22$$6, _9$$6, "valid", &_zephir_call_cache[5]);
				zephir_check_call_status();
				if (!zend_is_true(&_22$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&position, _9$$6, "key", &_zephir_call_cache[6]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&parameter, _9$$6, "current", &_zephir_call_cache[7]);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&variableName);
					zephir_array_fetch_string(&variableName, &parameter, SL("variable"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1119);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_24$$10);
					ZEPHIR_CONCAT_SVS(&_24$$10, "if (isset($__p[", &position, "])) { ");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_24$$10);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_25$$10);
					ZEPHIR_CONCAT_SVSVS(&_25$$10, "$", &variableName, " = $__p[", &position, "];");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_25$$10);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self_str(&code, " } else { ", sizeof(" } else { ") - 1);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_26$$10);
					ZEPHIR_CONCAT_SVS(&_26$$10, "if (array_key_exists(\"", &variableName, "\", $__p)) { ");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_26$$10);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_27$$10);
					ZEPHIR_CONCAT_SVSVS(&_27$$10, "$", &variableName, " = $__p[\"", &variableName, "\"];");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&code, &_27$$10);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self_str(&code, " } else { ", sizeof(" } else { ") - 1);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&defaultValue);
					_28$$10 = zephir_array_isset_string_fetch(&defaultValue, &parameter, SL("default"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (EXPECTED(_28$$10)) {
						ZEPHIR_CALL_METHOD_CACHED(&_29$$11, this_ptr, "expression", &_zephir_call_cache[8], &defaultValue);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_30$$11);
						ZEPHIR_CONCAT_SVSVS(&_30$$11, "$", &variableName, " = ", &_29$$11, ";");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&code, &_30$$11);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_31$$12);
						ZEPHIR_CONCAT_SVSVS(&_31$$12, " throw new \\Phalcon\\Mvc\\View\\Exception(\"Macro '", &name, "' was called without parameter: ", &variableName, "\"); ");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&code, &_31$$12);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					zephir_concat_self_str(&code, " } } ", sizeof(" } } ") - 1);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&parameter);
		ZEPHIR_INIT_NVAR(&position);
		zephir_concat_self_str(&code, " ?>", sizeof(" ?>") - 1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&blockStatements);
	_32 = zephir_array_isset_string_fetch(&blockStatements, &statement, SL("block_statements"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_32) {
		if (extendsMode) {
			ZVAL_BOOL(&_34$$13, 1);
		} else {
			ZVAL_BOOL(&_34$$13, 0);
		}
		ZEPHIR_CALL_METHOD_CACHED(&_33$$13, this_ptr, "statementList", &_zephir_call_cache[9], &blockStatements, &_34$$13);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_35$$13);
		ZEPHIR_CONCAT_VS(&_35$$13, &_33$$13, "<?php }; ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&code, &_35$$13);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		zephir_concat_self_str(&code, "<?php }; ", sizeof("<?php }; ") - 1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_36);
	ZEPHIR_CONCAT_VSVS(&_36, &macroName, " = \\Closure::bind(", &macroName, ", $this); ?>");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_concat_self(&code, &_36);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&code);
}

/**
 * Compiles a "return" statement returning PHP code
 *
 * @phpstan-param mvc_volt_node $statement
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileReturn)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, expr, _2, _1$$3;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(statement, statement_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &statement_param);
	zephir_get_arrval(&statement, statement_param);
	zephir_memory_observe(&expr);
	_0 = zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_view_engine_volt_exceptions_corruptedstatement_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1175);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "expression", &_zephir_call_cache[1], &expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php return ", &_2, "; ?>");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
 * @phpstan-param mvc_volt_node $statement
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSet)
{
	zend_bool _0, _14;
	zval compilation;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, assignments, assignment, exprCode, target, *_2, _3, *_4, _13, _1$$3, _5$$4, _6$$4, _7$$4, _8$$5, _9$$6, _10$$7, _11$$8, _12$$9, _15$$10, _16$$10, _17$$10, _18$$11, _19$$12, _20$$13, _21$$14, _22$$15;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&assignments);
	ZVAL_UNDEF(&assignment);
	ZVAL_UNDEF(&exprCode);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&compilation);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(statement, statement_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &statement_param);
	zephir_get_arrval(&statement, statement_param);
	zephir_memory_observe(&assignments);
	_0 = zephir_array_isset_string_fetch(&assignments, &statement, SL("assignments"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_view_engine_volt_exceptions_corruptedstatement_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1250);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&compilation);
	ZVAL_STRING(&compilation, "<?php");
	if (Z_TYPE_P(&assignments) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, &assignments);
		_2 = &_3;
	} else {
		_2 = &assignments;
	}
	zephir_is_iterable(_2, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1299);
	if (Z_TYPE_P(_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2), _4)
		{
			ZEPHIR_INIT_NVAR(&assignment);
			ZVAL_COPY(&assignment, _4);
			ZEPHIR_OBS_NVAR(&_5$$4);
			zephir_array_fetch_string(&_5$$4, &assignment, SL("expr"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1261);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&exprCode, this_ptr, "expression", &_zephir_call_cache[1], &_5$$4);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&_6$$4);
			zephir_array_fetch_string(&_6$$4, &assignment, SL("variable"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1268);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&target, this_ptr, "expression", &_zephir_call_cache[2], &_6$$4);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&_7$$4);
			zephir_array_fetch_string(&_7$$4, &assignment, SL("op"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1274);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_LONG(&_7$$4, 281)) { goto zephir_switch_0_clause_0; }
			if (ZEPHIR_IS_LONG(&_7$$4, 282)) { goto zephir_switch_0_clause_1; }
			if (ZEPHIR_IS_LONG(&_7$$4, 283)) { goto zephir_switch_0_clause_2; }
			if (ZEPHIR_IS_LONG(&_7$$4, 284)) { goto zephir_switch_0_clause_3; }
			goto zephir_switch_0_clause_4;
			zephir_switch_0_clause_0: ;
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZEPHIR_CONCAT_SVSVS(&_8$$5, " ", &target, " += ", &exprCode, ";");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&compilation, &_8$$5);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_1: ;
				ZEPHIR_INIT_NVAR(&_9$$6);
				ZEPHIR_CONCAT_SVSVS(&_9$$6, " ", &target, " -= ", &exprCode, ";");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&compilation, &_9$$6);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_2: ;
				ZEPHIR_INIT_NVAR(&_10$$7);
				ZEPHIR_CONCAT_SVSVS(&_10$$7, " ", &target, " *= ", &exprCode, ";");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&compilation, &_10$$7);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_3: ;
				ZEPHIR_INIT_NVAR(&_11$$8);
				ZEPHIR_CONCAT_SVSVS(&_11$$8, " ", &target, " /= ", &exprCode, ";");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&compilation, &_11$$8);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_4: ;
				ZEPHIR_INIT_NVAR(&_12$$9);
				ZEPHIR_CONCAT_SVSVS(&_12$$9, " ", &target, " = ", &exprCode, ";");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&compilation, &_12$$9);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_end: ;

		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _2, "rewind", &_zephir_call_cache[3]);
		zephir_check_call_status();
		_14 = 1;
		while (1) {
			if (_14) {
				_14 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _2, "next", &_zephir_call_cache[4]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_13, _2, "valid", &_zephir_call_cache[5]);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&assignment, _2, "current", &_zephir_call_cache[6]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_15$$10);
				zephir_array_fetch_string(&_15$$10, &assignment, SL("expr"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1261);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&exprCode, this_ptr, "expression", &_zephir_call_cache[7], &_15$$10);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_16$$10);
				zephir_array_fetch_string(&_16$$10, &assignment, SL("variable"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1268);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&target, this_ptr, "expression", &_zephir_call_cache[8], &_16$$10);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_17$$10);
				zephir_array_fetch_string(&_17$$10, &assignment, SL("op"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1274);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_LONG(&_17$$10, 281)) { goto zephir_switch_1_clause_0; }
				if (ZEPHIR_IS_LONG(&_17$$10, 282)) { goto zephir_switch_1_clause_1; }
				if (ZEPHIR_IS_LONG(&_17$$10, 283)) { goto zephir_switch_1_clause_2; }
				if (ZEPHIR_IS_LONG(&_17$$10, 284)) { goto zephir_switch_1_clause_3; }
				goto zephir_switch_1_clause_4;
				zephir_switch_1_clause_0: ;
					ZEPHIR_INIT_NVAR(&_18$$11);
					ZEPHIR_CONCAT_SVSVS(&_18$$11, " ", &target, " += ", &exprCode, ";");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&compilation, &_18$$11);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_1: ;
					ZEPHIR_INIT_NVAR(&_19$$12);
					ZEPHIR_CONCAT_SVSVS(&_19$$12, " ", &target, " -= ", &exprCode, ";");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&compilation, &_19$$12);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_2: ;
					ZEPHIR_INIT_NVAR(&_20$$13);
					ZEPHIR_CONCAT_SVSVS(&_20$$13, " ", &target, " *= ", &exprCode, ";");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&compilation, &_20$$13);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_3: ;
					ZEPHIR_INIT_NVAR(&_21$$14);
					ZEPHIR_CONCAT_SVSVS(&_21$$14, " ", &target, " /= ", &exprCode, ";");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&compilation, &_21$$14);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_4: ;
					ZEPHIR_INIT_NVAR(&_22$$15);
					ZEPHIR_CONCAT_SVSVS(&_22$$15, " ", &target, " = ", &exprCode, ";");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&compilation, &_22$$15);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_end: ;

		}
	}
	ZEPHIR_INIT_NVAR(&assignment);
	zephir_concat_self_str(&compilation, " ?>", sizeof(" ?>") - 1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&compilation);
}

/**
 * Compiles a template into a string
 *
 *```php
 * echo $compiler->compileString('{{ "hello world" }}');
 *```
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval viewCode_zv, *extendsMode_param = NULL, _0, _1;
	zend_string *viewCode = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewCode_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("currentPath", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(viewCode)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		extendsMode_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&viewCode_zv);
	ZVAL_STR_COPY(&viewCode_zv, viewCode);
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "eval code");
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1221, &_0);
	if (extendsMode) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "compileSource", &_zephir_call_cache[0], &viewCode_zv, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Compiles a 'switch' statement returning PHP code
 *
 * @phpstan-param mvc_volt_node $statement
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSwitch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode, _0, _3;
	zval *statement_param = NULL, *extendsMode_param = NULL, compilation, caseClauses, expr, lines, _2, _1$$3, _4$$4, _5$$5, _6$$5, _7$$5;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&compilation);
	ZVAL_UNDEF(&caseClauses);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(statement, statement_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &statement_param, &extendsMode_param);
	zephir_get_arrval(&statement, statement_param);
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		}
	zephir_memory_observe(&expr);
	_0 = zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_view_engine_volt_exceptions_corruptedstatementwithdata_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0], &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1335);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "expression", &_zephir_call_cache[1], &expr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&compilation);
	ZEPHIR_CONCAT_SVS(&compilation, "<?php switch (", &_2, "): ?>");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&caseClauses);
	_3 = zephir_array_isset_string_fetch(&caseClauses, &statement, SL("case_clauses"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		if (extendsMode) {
			ZVAL_BOOL(&_4$$4, 1);
		} else {
			ZVAL_BOOL(&_4$$4, 0);
		}
		ZEPHIR_CALL_METHOD_CACHED(&lines, this_ptr, "statementList", &_zephir_call_cache[2], &caseClauses, &_4$$4);
		zephir_check_call_status();
		if (zephir_fast_strlen_ev(&lines) != 0) {
			ZEPHIR_INIT_VAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "/(*ANYCRLF)^\\h+|\\h+$|(\\h){2,}/mu");
			ZEPHIR_INIT_VAR(&_6$$5);
			ZVAL_STRING(&_6$$5, "");
			ZEPHIR_CALL_FUNCTION(&_7$$5, "preg_replace", NULL, 2, &_5$$5, &_6$$5, &lines);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&lines, &_7$$5);
		}
		zephir_concat_self(&compilation, &lines);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_concat_self_str(&compilation, SL("<?php endswitch ?>"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&compilation);
}

/**
 * Resolves an expression node in an AST volt tree
 *
 * @phpstan-param mvc_volt_node $expr
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, expression)
{
	zval _48$$78;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool doubleQuotes, _3$$3, _22$$3, _26$$3, _14$$6, _7$$7, _17$$10, _28$$29, _39$$53, _41$$53;
	zval *expr_param = NULL, *doubleQuotes_param = NULL, end, endCode, extensions, items, left, name, right, singleExpr, singleExprCode, start, startCode, type, exprCode, leftCode, rightCode, _0, _2$$4, *_4$$6, _13$$6, _5$$7, _6$$7, _8$$8, _9$$8, _10$$8, _12$$8, _15$$10, _16$$10, _18$$11, _19$$11, _20$$11, _21$$11, _23$$14, _24$$15, _25$$16, _27$$17, _29$$35, _30$$35, _31$$35, _32$$35, _33$$36, _34$$36, _35$$36, _36$$36, _37$$40, _38$$50, _40$$54, _42$$56, _43$$74, _44$$74, _45$$74, _46$$78, _47$$78, _49$$78, _50$$78, _51$$78;
	zval expr, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&end);
	ZVAL_UNDEF(&endCode);
	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&singleExpr);
	ZVAL_UNDEF(&singleExprCode);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&startCode);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&exprCode);
	ZVAL_UNDEF(&leftCode);
	ZVAL_UNDEF(&rightCode);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_29$$35);
	ZVAL_UNDEF(&_30$$35);
	ZVAL_UNDEF(&_31$$35);
	ZVAL_UNDEF(&_32$$35);
	ZVAL_UNDEF(&_33$$36);
	ZVAL_UNDEF(&_34$$36);
	ZVAL_UNDEF(&_35$$36);
	ZVAL_UNDEF(&_36$$36);
	ZVAL_UNDEF(&_37$$40);
	ZVAL_UNDEF(&_38$$50);
	ZVAL_UNDEF(&_40$$54);
	ZVAL_UNDEF(&_42$$56);
	ZVAL_UNDEF(&_43$$74);
	ZVAL_UNDEF(&_44$$74);
	ZVAL_UNDEF(&_45$$74);
	ZVAL_UNDEF(&_46$$78);
	ZVAL_UNDEF(&_47$$78);
	ZVAL_UNDEF(&_49$$78);
	ZVAL_UNDEF(&_50$$78);
	ZVAL_UNDEF(&_51$$78);
	ZVAL_UNDEF(&_48$$78);
	ZEND_TLS zephir_method_cache _zephir_call_cache[17];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("extensions", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(expr, expr_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(doubleQuotes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &expr_param, &doubleQuotes_param);
	zephir_get_arrval(&expr, expr_param);
	if (!doubleQuotes_param) {
		doubleQuotes = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&exprCode);
	ZVAL_NULL(&exprCode);
	ZEPHIR_INIT_VAR(&leftCode);
	ZVAL_STRING(&leftCode, "");
	ZEPHIR_INIT_VAR(&rightCode);
	ZVAL_STRING(&rightCode, "");
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("exprLevel")));
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1225, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&extensions, &_0);
	while (1) {
		if (!(ZEPHIR_IS_EMPTY(&extensions))) {
			ZEPHIR_INIT_NVAR(&_1$$4);
			zephir_create_array(&_1$$4, 1, 0);
			zephir_array_fast_append(&_1$$4, &expr);
			ZEPHIR_INIT_NVAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "resolveExpression");
			ZEPHIR_CALL_METHOD_CACHED(&exprCode, this_ptr, "fireExtensionEvent", &_zephir_call_cache[0], &_2$$4, &_1$$4);
			zephir_check_call_status();
			if (Z_TYPE_P(&exprCode) == IS_STRING) {
				break;
			}
		}
		ZEPHIR_OBS_NVAR(&type);
		_3$$3 = zephir_array_isset_string_fetch(&type, &expr, SL("type"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(_3$$3)) {
			ZEPHIR_INIT_NVAR(&items);
			array_init(&items);
			zephir_is_iterable(&expr, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1451);
			if (Z_TYPE_P(&expr) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&expr), _4$$6)
				{
					ZEPHIR_INIT_NVAR(&singleExpr);
					ZVAL_COPY(&singleExpr, _4$$6);
					ZEPHIR_OBS_NVAR(&_5$$7);
					zephir_array_fetch_string(&_5$$7, &singleExpr, SL("expr"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1425);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (doubleQuotes) {
						ZVAL_BOOL(&_6$$7, 1);
					} else {
						ZVAL_BOOL(&_6$$7, 0);
					}
					ZEPHIR_CALL_METHOD_CACHED(&singleExprCode, this_ptr, "expression", &_zephir_call_cache[1], &_5$$7, &_6$$7);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&name);
					_7$$7 = zephir_array_isset_string_fetch(&name, &singleExpr, SL("name"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_7$$7) {
						ZEPHIR_INIT_NVAR(&_8$$8);
						ZEPHIR_INIT_NVAR(&_8$$8);
						zephir_create_closure_ex(&_8$$8, NULL, phalcon_95__closure_ce, SL("__invoke"));
						ZEPHIR_INIT_NVAR(&_9$$8);
						ZVAL_STRING(&_9$$8, "/\\\\.|'/s");
						ZEPHIR_CALL_FUNCTION(&_10$$8, "preg_replace_callback", &_11, 227, &_9$$8, &_8$$8, &name);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_12$$8);
						ZEPHIR_CONCAT_SVSV(&_12$$8, "'", &_10$$8, "' => ", &singleExprCode);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&items, &_12$$8, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1445);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						zephir_array_append(&items, &singleExprCode, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1447);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &expr, "rewind", &_zephir_call_cache[2]);
				zephir_check_call_status();
				_14$$6 = 1;
				while (1) {
					if (_14$$6) {
						_14$$6 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, &expr, "next", &_zephir_call_cache[3]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_13$$6, &expr, "valid", &_zephir_call_cache[4]);
					zephir_check_call_status();
					if (!zend_is_true(&_13$$6)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&singleExpr, &expr, "current", &_zephir_call_cache[5]);
					zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&_15$$10);
						zephir_array_fetch_string(&_15$$10, &singleExpr, SL("expr"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1425);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (doubleQuotes) {
							ZVAL_BOOL(&_16$$10, 1);
						} else {
							ZVAL_BOOL(&_16$$10, 0);
						}
						ZEPHIR_CALL_METHOD_CACHED(&singleExprCode, this_ptr, "expression", &_zephir_call_cache[6], &_15$$10, &_16$$10);
						zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&name);
						_17$$10 = zephir_array_isset_string_fetch(&name, &singleExpr, SL("name"), 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_17$$10) {
							ZEPHIR_INIT_NVAR(&_18$$11);
							ZEPHIR_INIT_NVAR(&_18$$11);
							zephir_create_closure_ex(&_18$$11, NULL, phalcon_96__closure_ce, SL("__invoke"));
							ZEPHIR_INIT_NVAR(&_19$$11);
							ZVAL_STRING(&_19$$11, "/\\\\.|'/s");
							ZEPHIR_CALL_FUNCTION(&_20$$11, "preg_replace_callback", &_11, 227, &_19$$11, &_18$$11, &name);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_21$$11);
							ZEPHIR_CONCAT_SVSV(&_21$$11, "'", &_20$$11, "' => ", &singleExprCode);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&items, &_21$$11, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1445);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							zephir_array_append(&items, &singleExprCode, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1447);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
				}
			}
			ZEPHIR_INIT_NVAR(&singleExpr);
			ZEPHIR_INIT_NVAR(&exprCode);
			zephir_fast_join_str(&exprCode, SL(", "), &items);
			break;
		}
		if (ZEPHIR_IS_LONG(&type, '.')) {
			ZEPHIR_CALL_METHOD_CACHED(&exprCode, this_ptr, "attributeReader", &_zephir_call_cache[7], &expr);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_OBS_NVAR(&left);
		_22$$3 = zephir_array_isset_string_fetch(&left, &expr, SL("left"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_22$$3) {
			if (doubleQuotes) {
				ZVAL_BOOL(&_23$$14, 1);
			} else {
				ZVAL_BOOL(&_23$$14, 0);
			}
			ZEPHIR_CALL_METHOD_CACHED(&leftCode, this_ptr, "expression", &_zephir_call_cache[8], &left, &_23$$14);
			zephir_check_call_status();
		}
		if (ZEPHIR_IS_LONG(&type, 311)) {
			ZEPHIR_OBS_NVAR(&_24$$15);
			zephir_array_fetch_string(&_24$$15, &expr, SL("right"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1477);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&exprCode, this_ptr, "resolveTest", &_zephir_call_cache[9], &_24$$15, &leftCode);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 124)) {
			ZEPHIR_OBS_NVAR(&_25$$16);
			zephir_array_fetch_string(&_25$$16, &expr, SL("right"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1489);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&exprCode, this_ptr, "resolveFilter", &_zephir_call_cache[10], &_25$$16, &leftCode);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_OBS_NVAR(&right);
		_26$$3 = zephir_array_isset_string_fetch(&right, &expr, SL("right"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_26$$3) {
			if (doubleQuotes) {
				ZVAL_BOOL(&_27$$17, 1);
			} else {
				ZVAL_BOOL(&_27$$17, 0);
			}
			ZEPHIR_CALL_METHOD_CACHED(&rightCode, this_ptr, "expression", &_zephir_call_cache[11], &right, &_27$$17);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&exprCode);
		ZVAL_NULL(&exprCode);
		if (ZEPHIR_IS_LONG(&type, '!')) { goto zephir_switch_0_clause_0; }
		if (ZEPHIR_IS_LONG(&type, '*')) { goto zephir_switch_0_clause_1; }
		if (ZEPHIR_IS_LONG(&type, '+')) { goto zephir_switch_0_clause_2; }
		if (ZEPHIR_IS_LONG(&type, '-')) { goto zephir_switch_0_clause_3; }
		if (ZEPHIR_IS_LONG(&type, '/')) { goto zephir_switch_0_clause_4; }
		if (ZEPHIR_IS_LONG(&type, 37)) { goto zephir_switch_0_clause_5; }
		if (ZEPHIR_IS_LONG(&type, '<')) { goto zephir_switch_0_clause_6; }
		if (ZEPHIR_IS_LONG(&type, 61)) { goto zephir_switch_0_clause_7; }
		if (ZEPHIR_IS_LONG(&type, 62)) { goto zephir_switch_0_clause_8; }
		if (ZEPHIR_IS_LONG(&type, 126)) { goto zephir_switch_0_clause_9; }
		if (ZEPHIR_IS_LONG(&type, 278)) { goto zephir_switch_0_clause_10; }
		if (ZEPHIR_IS_LONG(&type, 360)) { goto zephir_switch_0_clause_11; }
		if (ZEPHIR_IS_LONG(&type, 258)) { goto zephir_switch_0_clause_12; }
		if (ZEPHIR_IS_LONG(&type, 259)) { goto zephir_switch_0_clause_13; }
		if (ZEPHIR_IS_LONG(&type, 260)) { goto zephir_switch_0_clause_14; }
		if (ZEPHIR_IS_LONG(&type, 261)) { goto zephir_switch_0_clause_15; }
		if (ZEPHIR_IS_LONG(&type, 262)) { goto zephir_switch_0_clause_16; }
		if (ZEPHIR_IS_LONG(&type, 263)) { goto zephir_switch_0_clause_17; }
		if (ZEPHIR_IS_LONG(&type, 265)) { goto zephir_switch_0_clause_18; }
		if (ZEPHIR_IS_LONG(&type, 266)) { goto zephir_switch_0_clause_19; }
		if (ZEPHIR_IS_LONG(&type, 267)) { goto zephir_switch_0_clause_20; }
		if (ZEPHIR_IS_LONG(&type, 270)) { goto zephir_switch_0_clause_21; }
		if (ZEPHIR_IS_LONG(&type, 271)) { goto zephir_switch_0_clause_22; }
		if (ZEPHIR_IS_LONG(&type, 272)) { goto zephir_switch_0_clause_23; }
		if (ZEPHIR_IS_LONG(&type, 273)) { goto zephir_switch_0_clause_24; }
		if (ZEPHIR_IS_LONG(&type, 274)) { goto zephir_switch_0_clause_25; }
		if (ZEPHIR_IS_LONG(&type, 275)) { goto zephir_switch_0_clause_26; }
		if (ZEPHIR_IS_LONG(&type, 276)) { goto zephir_switch_0_clause_27; }
		if (ZEPHIR_IS_LONG(&type, 350)) { goto zephir_switch_0_clause_28; }
		if (ZEPHIR_IS_LONG(&type, 356)) { goto zephir_switch_0_clause_29; }
		if (ZEPHIR_IS_LONG(&type, 361)) { goto zephir_switch_0_clause_30; }
		if (ZEPHIR_IS_LONG(&type, 365)) { goto zephir_switch_0_clause_31; }
		if (ZEPHIR_IS_LONG(&type, 362)) { goto zephir_switch_0_clause_32; }
		if (ZEPHIR_IS_LONG(&type, 363)) { goto zephir_switch_0_clause_33; }
		if (ZEPHIR_IS_LONG(&type, 392)) { goto zephir_switch_0_clause_34; }
		if (ZEPHIR_IS_LONG(&type, 386)) { goto zephir_switch_0_clause_35; }
		if (ZEPHIR_IS_LONG(&type, 393)) { goto zephir_switch_0_clause_36; }
		if (ZEPHIR_IS_LONG(&type, 387)) { goto zephir_switch_0_clause_37; }
		if (ZEPHIR_IS_LONG(&type, 394)) { goto zephir_switch_0_clause_38; }
		if (ZEPHIR_IS_LONG(&type, 388)) { goto zephir_switch_0_clause_39; }
		if (ZEPHIR_IS_LONG(&type, 395)) { goto zephir_switch_0_clause_40; }
		if (ZEPHIR_IS_LONG(&type, 389)) { goto zephir_switch_0_clause_41; }
		if (ZEPHIR_IS_LONG(&type, 396)) { goto zephir_switch_0_clause_42; }
		if (ZEPHIR_IS_LONG(&type, 390)) { goto zephir_switch_0_clause_43; }
		if (ZEPHIR_IS_LONG(&type, 397)) { goto zephir_switch_0_clause_44; }
		if (ZEPHIR_IS_LONG(&type, 391)) { goto zephir_switch_0_clause_45; }
		if (ZEPHIR_IS_LONG(&type, 309)) { goto zephir_switch_0_clause_46; }
		if (ZEPHIR_IS_LONG(&type, 367)) { goto zephir_switch_0_clause_47; }
		if (ZEPHIR_IS_LONG(&type, 366)) { goto zephir_switch_0_clause_48; }
		if (ZEPHIR_IS_LONG(&type, 368)) { goto zephir_switch_0_clause_49; }
		if (ZEPHIR_IS_LONG(&type, 369)) { goto zephir_switch_0_clause_50; }
		if (ZEPHIR_IS_LONG(&type, 364)) { goto zephir_switch_0_clause_51; }
		goto zephir_switch_0_clause_52;
		zephir_switch_0_clause_0: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SV(&exprCode, "!", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_1: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " * ", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_2: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " + ", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_3: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " - ", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_4: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " / ", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_5: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " % ", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_6: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " < ", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_7: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " > ", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_8: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " > ", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_9: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " . ", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_10: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVSVS(&exprCode, "pow(", &leftCode, ", ", &rightCode, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_11: ;
			_28$$29 = zephir_array_isset_value_string(&expr, SL("left"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&exprCode);
			if (_28$$29) {
				ZEPHIR_CONCAT_SVS(&exprCode, "[", &leftCode, "]");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZVAL_STRING(&exprCode, "[]");
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_12: ;
			ZEPHIR_OBS_NVAR(&exprCode);
			zephir_array_fetch_string(&exprCode, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1560);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_13: ;
			ZEPHIR_OBS_NVAR(&exprCode);
			zephir_array_fetch_string(&exprCode, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1564);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_14: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			if (EXPECTED(doubleQuotes == 0)) {
				ZEPHIR_INIT_NVAR(&_29$$35);
				ZEPHIR_INIT_NVAR(&_29$$35);
				zephir_create_closure_ex(&_29$$35, NULL, phalcon_97__closure_ce, SL("__invoke"));
				ZEPHIR_OBS_NVAR(&_30$$35);
				zephir_array_fetch_string(&_30$$35, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1583);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_31$$35);
				ZVAL_STRING(&_31$$35, "/\\\\.|'/s");
				ZEPHIR_CALL_FUNCTION(&_32$$35, "preg_replace_callback", &_11, 227, &_31$$35, &_29$$35, &_30$$35);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVS(&exprCode, "'", &_32$$35, "'");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_INIT_NVAR(&_33$$36);
				ZEPHIR_INIT_NVAR(&_33$$36);
				zephir_create_closure_ex(&_33$$36, NULL, phalcon_98__closure_ce, SL("__invoke"));
				ZEPHIR_OBS_NVAR(&_34$$36);
				zephir_array_fetch_string(&_34$$36, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1603);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_35$$36);
				ZVAL_STRING(&_35$$36, "/\\\\.|[\"$]/s");
				ZEPHIR_CALL_FUNCTION(&_36$$36, "preg_replace_callback", &_11, 227, &_35$$36, &_33$$36, &_34$$36);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVS(&exprCode, "\"", &_36$$36, "\"");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_15: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZVAL_STRING(&exprCode, "null");
			goto zephir_switch_0_end;
		zephir_switch_0_clause_16: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZVAL_STRING(&exprCode, "false");
			goto zephir_switch_0_end;
		zephir_switch_0_clause_17: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZVAL_STRING(&exprCode, "true");
			goto zephir_switch_0_end;
		zephir_switch_0_clause_18: ;
			ZEPHIR_OBS_NVAR(&_37$$40);
			zephir_array_fetch_string(&_37$$40, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1621);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SV(&exprCode, "$", &_37$$40);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_19: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " && ", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_20: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " || ", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_21: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " <= ", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_22: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " >= ", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_23: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " == ", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_24: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " != ", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_25: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " === ", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_26: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSV(&exprCode, &leftCode, " !== ", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_27: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVSVS(&exprCode, "range(", &leftCode, ", ", &rightCode, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_28: ;
			if (doubleQuotes) {
				ZVAL_BOOL(&_38$$50, 1);
			} else {
				ZVAL_BOOL(&_38$$50, 0);
			}
			ZEPHIR_CALL_METHOD_CACHED(&exprCode, this_ptr, "functionCall", &_zephir_call_cache[12], &expr, &_38$$50);
			zephir_check_call_status();
			goto zephir_switch_0_end;
		zephir_switch_0_clause_29: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVS(&exprCode, "(", &leftCode, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_30: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_VSVS(&exprCode, &leftCode, "[", &rightCode, "]");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_31: ;
			ZEPHIR_OBS_NVAR(&start);
			_39$$53 = zephir_array_isset_string_fetch(&start, &expr, SL("start"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_39$$53) {
				if (doubleQuotes) {
					ZVAL_BOOL(&_40$$54, 1);
				} else {
					ZVAL_BOOL(&_40$$54, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&startCode, this_ptr, "expression", &_zephir_call_cache[13], &start, &_40$$54);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&startCode);
				ZVAL_STRING(&startCode, "null");
			}
			ZEPHIR_OBS_NVAR(&end);
			_41$$53 = zephir_array_isset_string_fetch(&end, &expr, SL("end"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_41$$53) {
				if (doubleQuotes) {
					ZVAL_BOOL(&_42$$56, 1);
				} else {
					ZVAL_BOOL(&_42$$56, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&endCode, this_ptr, "expression", &_zephir_call_cache[14], &end, &_42$$56);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&endCode);
				ZVAL_STRING(&endCode, "null");
			}
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVSVSVS(&exprCode, "$this->slice(", &leftCode, ", ", &startCode, ", ", &endCode, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_32: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVS(&exprCode, "!isset(", &leftCode, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_33: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVS(&exprCode, "isset(", &leftCode, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_34: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVS(&exprCode, "!empty(", &leftCode, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_35: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVS(&exprCode, "empty(", &leftCode, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_36: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVS(&exprCode, "!(((", &leftCode, ") % 2) == 0)");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_37: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVS(&exprCode, "(((", &leftCode, ") % 2) == 0)");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_38: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVS(&exprCode, "!(((", &leftCode, ") % 2) != 0)");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_39: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVS(&exprCode, "(((", &leftCode, ") % 2) != 0)");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_40: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVS(&exprCode, "!is_numeric(", &leftCode, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_41: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVS(&exprCode, "is_numeric(", &leftCode, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_42: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVS(&exprCode, "!is_scalar(", &leftCode, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_43: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVS(&exprCode, "is_scalar(", &leftCode, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_44: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVSVS(&exprCode, "!(is_array(", &leftCode, ") || (", &leftCode, ") instanceof Traversable)");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_45: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVSVS(&exprCode, "(is_array(", &leftCode, ") || (", &leftCode, ") instanceof Traversable)");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_46: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVSVS(&exprCode, "$this->isIncluded(", &leftCode, ", ", &rightCode, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_47: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVSVS(&exprCode, "!$this->isIncluded(", &leftCode, ", ", &rightCode, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_48: ;
			ZEPHIR_OBS_NVAR(&_44$$74);
			zephir_array_fetch_string(&_44$$74, &expr, SL("ternary"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1760);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (doubleQuotes) {
				ZVAL_BOOL(&_45$$74, 1);
			} else {
				ZVAL_BOOL(&_45$$74, 0);
			}
			ZEPHIR_CALL_METHOD_CACHED(&_43$$74, this_ptr, "expression", &_zephir_call_cache[15], &_44$$74, &_45$$74);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SVSVSVS(&exprCode, "(", &_43$$74, " ? ", &leftCode, " : ", &rightCode, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_49: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SV(&exprCode, "-", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_50: ;
			ZEPHIR_INIT_NVAR(&exprCode);
			ZEPHIR_CONCAT_SV(&exprCode, "+", &rightCode);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_51: ;
			ZEPHIR_OBS_NVAR(&exprCode);
			zephir_array_fetch_string(&exprCode, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1772);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_52: ;
			ZEPHIR_INIT_NVAR(&_46$$78);
			object_init_ex(&_46$$78, phalcon_mvc_view_engine_volt_exceptions_unknownvoltexpression_ce);
			ZEPHIR_OBS_NVAR(&_47$$78);
			zephir_array_fetch_string(&_47$$78, &expr, SL("file"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1776);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_cast_to_string(&_48$$78, &_47$$78);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&_49$$78);
			zephir_array_fetch_string(&_49$$78, &expr, SL("line"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1776);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_LONG(&_50$$78, zephir_get_intval(&type));
			ZVAL_LONG(&_51$$78, zephir_get_intval(&_49$$78));
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_46$$78, "__construct", &_zephir_call_cache[16], &_50$$78, &_48$$78, &_51$$78);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_46$$78, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1776);
			ZEPHIR_MM_RESTORE();
			return;
		zephir_switch_0_end: ;

		break;
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("exprLevel")));
	RETURN_CCTOR(&exprCode);
}

/**
 * Fires an event to registered extensions
 *
 * @phpstan-param array<array-key, mixed> $arguments
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, fireExtensionEvent)
{
	zend_bool _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments, _4$$5, _5$$6, _8$$10, _9$$11;
	zval name_zv, *arguments_param = NULL, extensions, extension, status, _0, *_1, _2, *_3, _6;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$11);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("extensions", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(arguments, arguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		arguments_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
		zephir_get_arrval(&arguments, arguments_param);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1225, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&extensions, &_0);
	if (Z_TYPE_P(&extensions) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &extensions);
		_1 = &_2;
	} else {
		_1 = &extensions;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1823);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&extension);
			ZVAL_COPY(&extension, _3);
			if ((zephir_method_exists(&extension, &name_zv)  == SUCCESS)) {
				if (!(ZEPHIR_IS_EMPTY(&arguments))) {
					ZEPHIR_INIT_NVAR(&_4$$5);
					zephir_create_array(&_4$$5, 2, 0);
					zephir_array_fast_append(&_4$$5, &extension);
					zephir_array_fast_append(&_4$$5, &name_zv);
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &_4$$5, &arguments);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_5$$6);
					zephir_create_array(&_5$$6, 2, 0);
					zephir_array_fast_append(&_5$$6, &extension);
					zephir_array_fast_append(&_5$$6, &name_zv);
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC(&status, &_5$$6);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&status) == IS_STRING) {
					RETURN_CCTOR(&status);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[0]);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[1]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_6, _1, "valid", &_zephir_call_cache[2]);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&extension, _1, "current", &_zephir_call_cache[3]);
			zephir_check_call_status();
				if ((zephir_method_exists(&extension, &name_zv)  == SUCCESS)) {
					if (!(ZEPHIR_IS_EMPTY(&arguments))) {
						ZEPHIR_INIT_NVAR(&_8$$10);
						zephir_create_array(&_8$$10, 2, 0);
						zephir_array_fast_append(&_8$$10, &extension);
						zephir_array_fast_append(&_8$$10, &name_zv);
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &_8$$10, &arguments);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&_9$$11);
						zephir_create_array(&_9$$11, 2, 0);
						zephir_array_fast_append(&_9$$11, &extension);
						zephir_array_fast_append(&_9$$11, &name_zv);
						ZEPHIR_INIT_NVAR(&status);
						ZEPHIR_CALL_USER_FUNC(&status, &_9$$11);
						zephir_check_call_status();
					}
					if (Z_TYPE_P(&status) == IS_STRING) {
						RETURN_CCTOR(&status);
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&extension);
	ZEPHIR_MM_RESTORE();
}

/**
 * Resolves function intermediate code into PHP function calls
 *
 * @phpstan-param mvc_volt_node $expr
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, functionCall)
{
	zval _8$$9, _10$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool doubleQuotes, _0, _13$$5, _22$$5, _5$$8, _16$$16, _17$$16, _21$$26, _29$$29;
	zval *expr_param = NULL, *doubleQuotes_param = NULL, __$true, arguments, arrayHelpers, block, currentBlock, definition, escapedCode, exprLevel, extendedBlocks, extensions, functions, method, name, nameExpr, nameType, tagService, code, funcArguments, _31, _32, _1$$3, _2$$5, _19$$5, _20$$5, _23$$5, _24$$5, _25$$5, _4$$6, _7$$9, _9$$9, _11$$9, _12$$9, _14$$15, _15$$16, _18$$17, _26$$28, _27$$28, _28$$28, _30$$30;
	zval expr, _3$$6, _6$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_6$$12);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&arrayHelpers);
	ZVAL_UNDEF(&block);
	ZVAL_UNDEF(&currentBlock);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&escapedCode);
	ZVAL_UNDEF(&exprLevel);
	ZVAL_UNDEF(&extendedBlocks);
	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&functions);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&nameExpr);
	ZVAL_UNDEF(&nameType);
	ZVAL_UNDEF(&tagService);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&funcArguments);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_26$$28);
	ZVAL_UNDEF(&_27$$28);
	ZVAL_UNDEF(&_28$$28);
	ZVAL_UNDEF(&_30$$30);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_10$$9);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("extensions", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("functions", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("extendedBlocks", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("currentBlock", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("exprLevel", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(expr, expr_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(doubleQuotes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &expr_param, &doubleQuotes_param);
	zephir_get_arrval(&expr, expr_param);
	if (!doubleQuotes_param) {
		doubleQuotes = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&code);
	ZVAL_NULL(&code);
	ZEPHIR_INIT_VAR(&funcArguments);
	ZVAL_NULL(&funcArguments);
	zephir_memory_observe(&nameExpr);
	zephir_array_fetch_string(&nameExpr, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1839);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&nameType);
	zephir_array_fetch_string(&nameType, &nameExpr, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1840);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_NVAR(&funcArguments);
	_0 = zephir_array_isset_string_fetch(&funcArguments, &expr, SL("arguments"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		if (doubleQuotes) {
			ZVAL_BOOL(&_1$$3, 1);
		} else {
			ZVAL_BOOL(&_1$$3, 0);
		}
		ZEPHIR_CALL_METHOD_CACHED(&arguments, this_ptr, "expression", &_zephir_call_cache[0], &funcArguments, &_1$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&arguments);
		ZVAL_STRING(&arguments, "");
	}
	if (ZEPHIR_IS_LONG(&nameType, 265)) {
		zephir_memory_observe(&name);
		zephir_array_fetch_string(&name, &nameExpr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1857);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_2$$5, this_ptr, _zephir_prop_0, 1225, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&extensions, &_2$$5);
		if (!(ZEPHIR_IS_EMPTY(&extensions))) {
			ZEPHIR_INIT_VAR(&_3$$6);
			zephir_create_array(&_3$$6, 3, 0);
			zephir_array_fast_append(&_3$$6, &name);
			zephir_array_fast_append(&_3$$6, &arguments);
			zephir_array_fast_append(&_3$$6, &funcArguments);
			ZEPHIR_INIT_VAR(&_4$$6);
			ZVAL_STRING(&_4$$6, "compileFunction");
			ZEPHIR_CALL_METHOD_CACHED(&code, this_ptr, "fireExtensionEvent", &_zephir_call_cache[1], &_4$$6, &_3$$6);
			zephir_check_call_status();
			if (Z_TYPE_P(&code) == IS_STRING) {
				RETURN_CCTOR(&code);
			}
		}
		zephir_read_property_cached(&_2$$5, this_ptr, _zephir_prop_1, 1226, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&functions, &_2$$5);
		if (Z_TYPE_P(&functions) == IS_ARRAY) {
			zephir_memory_observe(&definition);
			_5$$8 = zephir_array_isset_fetch(&definition, &functions, &name, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_5$$8) {
				if (Z_TYPE_P(&definition) == IS_STRING) {
					ZEPHIR_CONCAT_VSVS(return_value, &definition, "(", &arguments, ")");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					RETURN_MM();
				}
				if (Z_TYPE_P(&definition) == IS_OBJECT) {
					if (zephir_is_instance_of(&definition, SL("Closure"))) {
						ZEPHIR_INIT_VAR(&_6$$12);
						zephir_create_array(&_6$$12, 2, 0);
						zephir_array_fast_append(&_6$$12, &arguments);
						zephir_array_fast_append(&_6$$12, &funcArguments);
						ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &definition, &_6$$12);
						zephir_check_call_status();
						RETURN_MM();
					}
				}
				ZEPHIR_INIT_VAR(&_7$$9);
				object_init_ex(&_7$$9, phalcon_mvc_view_engine_volt_exceptions_invaliduserfunctiondefinition_ce);
				zephir_cast_to_string(&_8$$9, &name);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_memory_observe(&_9$$9);
				zephir_array_fetch_string(&_9$$9, &expr, SL("file"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1906);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_cast_to_string(&_10$$9, &_9$$9);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_memory_observe(&_11$$9);
				zephir_array_fetch_string(&_11$$9, &expr, SL("line"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1906);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZVAL_LONG(&_12$$9, zephir_get_intval(&_11$$9));
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_7$$9, "__construct", &_zephir_call_cache[2], &_8$$9, &_10$$9, &_12$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$9, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1906);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		_13$$5 = ZEPHIR_IS_STRING(&name, "get_content");
		if (!(_13$$5)) {
			_13$$5 = ZEPHIR_IS_STRING(&name, "content");
		}
		if (_13$$5) {
			RETURN_MM_STRING("$this->getContent()");
		}
		if (ZEPHIR_IS_STRING(&name, "partial")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->partial(", &arguments, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "super")) {
			zephir_read_property_cached(&_14$$15, this_ptr, _zephir_prop_2, 1227, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&extendedBlocks, &_14$$15);
			if (Z_TYPE_P(&extendedBlocks) == IS_ARRAY) {
				zephir_read_property_cached(&_15$$16, this_ptr, _zephir_prop_3, 1228, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(&currentBlock, &_15$$16);
				_16$$16 = Z_TYPE_P(&currentBlock) != IS_NULL;
				if (_16$$16) {
					zephir_memory_observe(&block);
					_17$$16 = zephir_array_isset_fetch(&block, &extendedBlocks, &currentBlock, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_16$$16 = _17$$16;
				}
				if (_16$$16) {
					zephir_read_property_cached(&_18$$17, this_ptr, _zephir_prop_4, 1229, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&exprLevel, &_18$$17);
					if (Z_TYPE_P(&block) == IS_ARRAY) {
						ZEPHIR_CALL_METHOD_CACHED(&code, this_ptr, "statementListOrExtends", &_zephir_call_cache[3], &block);
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
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					RETURN_MM();
				}
			}
			RETURN_MM_STRING("''");
		}
		if (ZEPHIR_IS_STRING_IDENTICAL(&name, "preload")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->preload(", &arguments, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_19$$5);
		zephir_camelize(&_19$$5, &name, NULL );
		ZEPHIR_CALL_FUNCTION(&method, "lcfirst", NULL, 57, &_19$$5);
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
		ZEPHIR_INIT_VAR(&_20$$5);
		ZVAL_STRING(&_20$$5, "Phalcon\\Tag");
		if ((zephir_method_exists(&_20$$5, &method)  == SUCCESS)) {
			_21$$26 = zephir_array_isset_value(&arrayHelpers, &name);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_21$$26) {
				ZEPHIR_CONCAT_SVSVS(return_value, "\\Phalcon\\Tag::", &method, "([", &arguments, "])");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				RETURN_MM();
			}
			ZEPHIR_CONCAT_SVSVS(return_value, "\\Phalcon\\Tag::", &method, "(", &arguments, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		}
		zephir_read_property_cached(&_2$$5, this_ptr, _zephir_prop_5, 1216, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_22$$5 = Z_TYPE_P(&_2$$5) != IS_NULL;
		if (_22$$5) {
			zephir_read_property_cached(&_23$$5, this_ptr, _zephir_prop_5, 1216, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_25$$5);
			ZVAL_STRING(&_25$$5, "tag");
			ZEPHIR_CALL_METHOD_CACHED(&_24$$5, &_23$$5, "has", &_zephir_call_cache[4], &_25$$5);
			zephir_check_call_status();
			_22$$5 = ZEPHIR_IS_TRUE_IDENTICAL(&_24$$5);
		}
		if (_22$$5) {
			zephir_read_property_cached(&_26$$28, this_ptr, _zephir_prop_5, 1216, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_27$$28);
			ZVAL_STRING(&_27$$28, "tag");
			ZEPHIR_CALL_METHOD_CACHED(&tagService, &_26$$28, "get", &_zephir_call_cache[5], &_27$$28);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&_28$$28, &tagService, "has", &_zephir_call_cache[6], &name);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_28$$28)) {
				ZEPHIR_INIT_NVAR(&funcArguments);
				ZVAL_NULL(&funcArguments);
				ZEPHIR_OBS_NVAR(&funcArguments);
				_29$$29 = zephir_array_isset_string_fetch(&funcArguments, &expr, SL("arguments"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_29$$29) {
					ZVAL_BOOL(&_30$$30, 1);
					ZEPHIR_CALL_METHOD_CACHED(&arguments, this_ptr, "expression", &_zephir_call_cache[7], &funcArguments, &_30$$30);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&arguments);
					ZVAL_STRING(&arguments, "");
				}
				ZEPHIR_CONCAT_SVSVS(return_value, "$this->tag->", &name, "(", &arguments, ")");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				RETURN_MM();
			}
		}
		if (ZEPHIR_IS_STRING(&name, "url")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->url->get(", &arguments, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "static_url")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->url->getStatic(", &arguments, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "date")) {
			ZEPHIR_CONCAT_SVS(return_value, "date(", &arguments, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "time")) {
			RETURN_MM_STRING("time()");
		}
		if (ZEPHIR_IS_STRING(&name, "dump")) {
			ZEPHIR_CONCAT_SVS(return_value, "var_dump(", &arguments, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "version")) {
			RETURN_MM_STRING("(new Phalcon\\Support\\Version)->get()");
		}
		if (ZEPHIR_IS_STRING(&name, "version_id")) {
			RETURN_MM_STRING("(new Phalcon\\Support\\Version)->getId()");
		}
		if (ZEPHIR_IS_STRING(&name, "constant")) {
			ZEPHIR_CONCAT_SVS(return_value, "constant(", &arguments, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		}
		ZEPHIR_CONCAT_SVSVS(return_value, "$this->callMacro('", &name, "', [", &arguments, "])");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	if (doubleQuotes) {
		ZVAL_BOOL(&_32, 1);
	} else {
		ZVAL_BOOL(&_32, 0);
	}
	ZEPHIR_CALL_METHOD_CACHED(&_31, this_ptr, "expression", &_zephir_call_cache[8], &nameExpr, &_32);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVS(return_value, &_31, "(", &arguments, ")");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Returns the path to the last compiled template
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath)
{

	RETURN_MEMBER_TYPED(getThis(), "compiledTemplatePath", IS_STRING);
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
 * @phpstan-return list<object>
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getExtensions)
{

	RETURN_MEMBER_TYPED(getThis(), "extensions", IS_ARRAY);
}

/**
 * Register the user registered filters
 *
 * @phpstan-return array<string, mixed>
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFilters)
{

	RETURN_MEMBER_TYPED(getThis(), "filters", IS_ARRAY);
}

/**
 * Register the user registered functions
 *
 * @phpstan-return array<string, mixed>
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFunctions)
{

	RETURN_MEMBER_TYPED(getThis(), "functions", IS_ARRAY);
}

/**
 * Returns a compiler's option
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOption)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval option_zv, value, _0;
	zend_string *option = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(option)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&option_zv);
	ZVAL_STR_COPY(&option_zv, option);
	zephir_memory_observe(&value);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1217, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_fetch(&value, &_0, &option_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&value);
}

/**
 * Returns the compiler options
 *
 * @phpstan-return array<string, mixed>
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOptions)
{

	RETURN_MEMBER_TYPED(getThis(), "options", IS_ARRAY);
}

/**
 * Returns the path that is currently being compiled
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getTemplatePath)
{

	RETURN_MEMBER_TYPED(getThis(), "currentPath", IS_STRING);
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
	zval _0, _3, _8, _1$$3, _2$$3, _4$$4, _5$$5, _6$$5, _9$$6;
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
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_7$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("prefix", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("currentPath", 11, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1230, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_1, 1221, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_unique_path_key(&_1$$3, &_2$$3);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1230, &_1$$3);
	}
	zephir_memory_observe(&_3);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 1230, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_3) == IS_OBJECT) {
		zephir_memory_observe(&_4$$4);
		zephir_read_property_cached(&_4$$4, this_ptr, _zephir_prop_0, 1230, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (zephir_is_instance_of(&_4$$4, SL("Closure"))) {
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_read_property_cached(&_6$$5, this_ptr, _zephir_prop_0, 1230, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_7$$5);
			zephir_create_array(&_7$$5, 1, 0);
			zephir_array_fast_append(&_7$$5, this_ptr);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_5$$5, &_6$$5, &_7$$5);
			zephir_check_call_status();
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1230, &_5$$5);
		}
	}
	zephir_memory_observe(&_8);
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_0, 1230, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(Z_TYPE_P(&_8) != IS_STRING)) {
		ZEPHIR_INIT_VAR(&_9$$6);
		object_init_ex(&_9$$6, phalcon_mvc_view_engine_volt_exceptions_invalidcompilationprefix_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_9$$6, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_9$$6, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2189);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_MEMBER_TYPED(getThis(), "prefix", IS_STRING);
}

/**
 * Parses a Volt template returning its intermediate representation
 *
 *```php
 * print_r(
 *     $compiler->parse("{{ 3 + 2 }}")
 * );
 *```
 *
 * @phpstan-return mvc_volt_node
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, parse)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval viewCode_zv, currentPath;
	zend_string *viewCode = NULL;

	ZVAL_UNDEF(&viewCode_zv);
	ZVAL_UNDEF(&currentPath);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(viewCode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&viewCode_zv);
	ZVAL_STR_COPY(&viewCode_zv, viewCode);
	ZEPHIR_INIT_VAR(&currentPath);
	ZVAL_STRING(&currentPath, "eval code");
	ZEPHIR_LAST_CALL_STATUS = phvolt_parse_view(return_value, &viewCode_zv, &currentPath);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolves filter intermediate code into a valid PHP expression
 *
 * @phpstan-param mvc_volt_node $test
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveTest)
{
	zend_bool _0$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *left = NULL;
	zval *test_param = NULL, left_zv, type, name, testName, _7, _1$$12, _2$$12, _3$$13, _4$$13, _5$$14, _6$$14;
	zval test;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&test);
	ZVAL_UNDEF(&left_zv);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&testName);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$12);
	ZVAL_UNDEF(&_2$$12);
	ZVAL_UNDEF(&_3$$13);
	ZVAL_UNDEF(&_4$$13);
	ZVAL_UNDEF(&_5$$14);
	ZVAL_UNDEF(&_6$$14);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(test, test_param)
		Z_PARAM_STR(left)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	test_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&test, test_param);
	zephir_memory_observe(&left_zv);
	ZVAL_STR_COPY(&left_zv, left);
	zephir_memory_observe(&type);
	zephir_array_fetch_string(&type, &test, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2224);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG(&type, 265)) {
		zephir_memory_observe(&name);
		zephir_array_fetch_string(&name, &test, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2230);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_STRING(&name, "empty")) { goto zephir_switch_0_clause_0; }
		if (ZEPHIR_IS_STRING(&name, "even")) { goto zephir_switch_0_clause_1; }
		if (ZEPHIR_IS_STRING(&name, "odd")) { goto zephir_switch_0_clause_2; }
		if (ZEPHIR_IS_STRING(&name, "numeric")) { goto zephir_switch_0_clause_3; }
		if (ZEPHIR_IS_STRING(&name, "scalar")) { goto zephir_switch_0_clause_4; }
		if (ZEPHIR_IS_STRING(&name, "iterable")) { goto zephir_switch_0_clause_5; }
		goto zephir_switch_0_end;
		zephir_switch_0_clause_0: ;
			ZEPHIR_CONCAT_SVS(return_value, "empty(", &left_zv, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		zephir_switch_0_clause_1: ;
			ZEPHIR_CONCAT_SVS(return_value, "(((", &left_zv, ") % 2) == 0)");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		zephir_switch_0_clause_2: ;
			ZEPHIR_CONCAT_SVS(return_value, "(((", &left_zv, ") % 2) != 0)");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		zephir_switch_0_clause_3: ;
			ZEPHIR_CONCAT_SVS(return_value, "is_numeric(", &left_zv, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		zephir_switch_0_clause_4: ;
			ZEPHIR_CONCAT_SVS(return_value, "is_scalar(", &left_zv, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		zephir_switch_0_clause_5: ;
			ZEPHIR_CONCAT_SVSVS(return_value, "(is_array(", &left_zv, ") || (", &left_zv, ") instanceof Traversable)");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		zephir_switch_0_end: ;

	}
	if (ZEPHIR_IS_LONG(&type, 350)) {
		zephir_memory_observe(&testName);
		zephir_array_fetch_string(&testName, &test, SL("name"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2253);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&name);
		_0$$10 = zephir_array_isset_string_fetch(&name, &testName, SL("value"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_0$$10) {
			if (ZEPHIR_IS_STRING(&name, "divisibleby")) { goto zephir_switch_1_clause_0; }
			if (ZEPHIR_IS_STRING(&name, "sameas")) { goto zephir_switch_1_clause_1; }
			if (ZEPHIR_IS_STRING(&name, "type")) { goto zephir_switch_1_clause_2; }
			goto zephir_switch_1_end;
			zephir_switch_1_clause_0: ;
				zephir_memory_observe(&_2$$12);
				zephir_array_fetch_string(&_2$$12, &test, SL("arguments"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2258);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_1$$12, this_ptr, "expression", &_zephir_call_cache[0], &_2$$12);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVSVS(return_value, "(((", &left_zv, ") % (", &_1$$12, ")) == 0)");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				RETURN_MM();
			zephir_switch_1_clause_1: ;
				zephir_memory_observe(&_4$$13);
				zephir_array_fetch_string(&_4$$13, &test, SL("arguments"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2260);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_3$$13, this_ptr, "expression", &_zephir_call_cache[1], &_4$$13);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVSVS(return_value, "(", &left_zv, ") === (", &_3$$13, ")");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				RETURN_MM();
			zephir_switch_1_clause_2: ;
				zephir_memory_observe(&_6$$14);
				zephir_array_fetch_string(&_6$$14, &test, SL("arguments"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2262);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_5$$14, this_ptr, "expression", &_zephir_call_cache[2], &_6$$14);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVSVS(return_value, "gettype(", &left_zv, ") === (", &_5$$14, ")");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				RETURN_MM();
			zephir_switch_1_end: ;

		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_7, this_ptr, "expression", &_zephir_call_cache[3], &test);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &left_zv, " == ", &_7);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &container);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1216, container);
}

/**
 * Sets a single compiler option
 *
 * @param mixed value
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOption)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval option_zv, *value, value_sub, _0;
	zend_string *option = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("virtualPaths", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(option)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&option_zv);
	ZVAL_STR_COPY(&option_zv, option);
	zephir_update_property_array(this_ptr, SL("options"), &option_zv, value);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1218, &_0);
	RETURN_THIS();
}

/**
 * Sets the compiler options
 *
 * @phpstan-param array<string, mixed> $options
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL, _0;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("virtualPaths", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1217, &options);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1218, &_0);
	RETURN_THIS();
}

/**
 * Set a unique prefix to be used as prefix for compiled variables
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setUniquePrefix)
{
	zval prefix_zv;
	zend_string *prefix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("prefix", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&prefix_zv, prefix);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1230, &prefix_zv);
	RETURN_THISW();
}

/**
 * Compiles a Volt source code returning a PHP plain version
 *
 * @phpstan-return array<array-key, mixed>|string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSource)
{
	zend_ulong _11$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode, _1$$3, _15$$7, _13$$12, _16$$24;
	zval viewCode_zv, *extendsMode_param = NULL, __$true, __$false, __$null, currentPath, intermediate, extended, finalCompilation, blocks, extendedBlocks, name, block, blockCompilation, localBlock, compilation, options, autoescape, _0, _6, _2$$5, _3$$5, _4$$5, _5$$6, _7$$7, *_8$$7, _9$$7, *_10$$7, _14$$7, _17$$35;
	zend_string *viewCode = NULL, *_12$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewCode_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_17$$35);
	ZEND_TLS zephir_method_cache _zephir_call_cache[12];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	static zend_string *_zephir_prop_9 = NULL;
	static zend_string *_zephir_prop_10 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("extended", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("extendedBlocks", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("blocks", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("level", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("foreachLevel", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("blockLevel", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("exprLevel", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("currentPath", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("options", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("autoescape", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("currentBlock", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(viewCode)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		extendsMode_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&viewCode_zv);
	ZVAL_STR_COPY(&viewCode_zv, viewCode);
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		}
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1231, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1231, &__$false);
	}
	if (0) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1227, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1227, &__$false);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1232, &__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1233, &_0);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1215, &_0);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1234, &_0);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 1229, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_7, 1221, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&currentPath, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_8, 1217, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&options, &_0);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		zephir_memory_observe(&autoescape);
		_1$$3 = zephir_array_isset_string_fetch(&autoescape, &options, SL("autoescape"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_1$$3) {
			if (UNEXPECTED(((Z_TYPE_P(&autoescape) == IS_TRUE || Z_TYPE_P(&autoescape) == IS_FALSE) != 1))) {
				ZEPHIR_INIT_VAR(&_2$$5);
				object_init_ex(&_2$$5, phalcon_mvc_view_engine_volt_exceptions_invalidoptiontype_ce);
				ZEPHIR_INIT_VAR(&_3$$5);
				ZVAL_STRING(&_3$$5, "autoescape");
				ZEPHIR_INIT_VAR(&_4$$5);
				ZVAL_STRING(&_4$$5, "bool");
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$5, "__construct", &_zephir_call_cache[0], &_3$$5, &_4$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2361);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 1220, &autoescape);
		}
	}
	ZEPHIR_INIT_VAR(&intermediate);
	ZEPHIR_LAST_CALL_STATUS = phvolt_parse_view(&intermediate, &viewCode_zv, &currentPath);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&intermediate) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_5$$6);
		object_init_ex(&_5$$6, phalcon_mvc_view_engine_volt_exceptions_invalidintermediaterepresentation_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_5$$6, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$6, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2374);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (extendsMode) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_CALL_METHOD_CACHED(&compilation, this_ptr, "statementList", &_zephir_call_cache[2], &intermediate, &_0);
	zephir_check_call_status();
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_0, 1231, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&extended, &_6);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&extended)) {
		ZEPHIR_INIT_VAR(&finalCompilation);
		if (extendsMode == 1) {
			array_init(&finalCompilation);
		} else {
			ZVAL_NULL(&finalCompilation);
		}
		zephir_read_property_cached(&_7$$7, this_ptr, _zephir_prop_2, 1232, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&blocks, &_7$$7);
		zephir_read_property_cached(&_7$$7, this_ptr, _zephir_prop_1, 1227, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&extendedBlocks, &_7$$7);
		if (Z_TYPE_P(&blocks) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&blocks);
			array_init(&blocks);
		}
		if (Z_TYPE_P(&extendedBlocks) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_9$$7);
			zephir_string_to_char_array(&_9$$7, &extendedBlocks);
			_8$$7 = &_9$$7;
		} else {
			_8$$7 = &extendedBlocks;
		}
		zephir_is_iterable(_8$$7, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2455);
		if (Z_TYPE_P(_8$$7) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_8$$7), _11$$7, _12$$7, _10$$7)
			{
				ZEPHIR_INIT_NVAR(&name);
				if (_12$$7 != NULL) { 
					ZVAL_STR_COPY(&name, _12$$7);
				} else {
					ZVAL_LONG(&name, _11$$7);
				}
				ZEPHIR_INIT_NVAR(&block);
				ZVAL_COPY(&block, _10$$7);
				if (Z_TYPE_P(&name) == IS_STRING) {
					_13$$12 = zephir_array_key_exists(&blocks, &name);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_13$$12) {
						ZEPHIR_OBS_NVAR(&localBlock);
						zephir_array_fetch(&localBlock, &blocks, &name, PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2415);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 1228, &name);
						if (Z_TYPE_P(&localBlock) == IS_NULL) {
							ZEPHIR_INIT_NVAR(&localBlock);
							array_init(&localBlock);
						}
						ZEPHIR_CALL_METHOD_CACHED(&blockCompilation, this_ptr, "statementList", &_zephir_call_cache[3], &localBlock);
						zephir_check_call_status();
					} else {
						if (Z_TYPE_P(&block) == IS_ARRAY) {
							ZEPHIR_CALL_METHOD_CACHED(&blockCompilation, this_ptr, "statementList", &_zephir_call_cache[4], &block);
							zephir_check_call_status();
						} else {
							ZEPHIR_CPY_WRT(&blockCompilation, &block);
						}
					}
					if (extendsMode) {
						zephir_array_update_zval(&finalCompilation, &name, &blockCompilation, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						zephir_concat_self(&finalCompilation, &blockCompilation);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					if (extendsMode) {
						zephir_array_append(&finalCompilation, &block, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2448);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						zephir_concat_self(&finalCompilation, &block);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _8$$7, "rewind", &_zephir_call_cache[5]);
			zephir_check_call_status();
			_15$$7 = 1;
			while (1) {
				if (_15$$7) {
					_15$$7 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _8$$7, "next", &_zephir_call_cache[6]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_14$$7, _8$$7, "valid", &_zephir_call_cache[7]);
				zephir_check_call_status();
				if (!zend_is_true(&_14$$7)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&name, _8$$7, "key", &_zephir_call_cache[8]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&block, _8$$7, "current", &_zephir_call_cache[9]);
				zephir_check_call_status();
					if (Z_TYPE_P(&name) == IS_STRING) {
						_16$$24 = zephir_array_key_exists(&blocks, &name);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_16$$24) {
							ZEPHIR_OBS_NVAR(&localBlock);
							zephir_array_fetch(&localBlock, &blocks, &name, PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2415);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_update_property_zval_cached(this_ptr, _zephir_prop_10, 1228, &name);
							if (Z_TYPE_P(&localBlock) == IS_NULL) {
								ZEPHIR_INIT_NVAR(&localBlock);
								array_init(&localBlock);
							}
							ZEPHIR_CALL_METHOD_CACHED(&blockCompilation, this_ptr, "statementList", &_zephir_call_cache[10], &localBlock);
							zephir_check_call_status();
						} else {
							if (Z_TYPE_P(&block) == IS_ARRAY) {
								ZEPHIR_CALL_METHOD_CACHED(&blockCompilation, this_ptr, "statementList", &_zephir_call_cache[11], &block);
								zephir_check_call_status();
							} else {
								ZEPHIR_CPY_WRT(&blockCompilation, &block);
							}
						}
						if (extendsMode) {
							zephir_array_update_zval(&finalCompilation, &name, &blockCompilation, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							zephir_concat_self(&finalCompilation, &blockCompilation);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						if (extendsMode) {
							zephir_array_append(&finalCompilation, &block, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2448);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							zephir_concat_self(&finalCompilation, &block);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&block);
		ZEPHIR_INIT_NVAR(&name);
		RETURN_CCTOR(&finalCompilation);
	}
	if (extendsMode) {
		zephir_read_property_cached(&_17$$35, this_ptr, _zephir_prop_2, 1232, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&blocks, &_17$$35);
		if (Z_TYPE_P(&blocks) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&blocks);
			array_init(&blocks);
		}
		RETURN_CCTOR(&blocks);
	}
	RETURN_CCTOR(&compilation);
}

/**
 * Gets the final path with VIEW
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFinalPath)
{
	zend_bool _1, _11$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval path_zv, view, viewsDirs, viewsDir, _0, _4, _2$$4, _3$$4, *_5$$6, _6$$6, *_7$$6, _10$$6, _8$$7, _9$$7, _12$$9, _13$$9;
	zend_string *path = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&view);
	ZVAL_UNDEF(&viewsDirs);
	ZVAL_UNDEF(&viewsDir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("currentPath", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("view", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	ZEPHIR_INIT_VAR(&viewsDir);
	ZVAL_STRING(&viewsDir, "");
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "isAbsolutePath", &_zephir_call_cache[0], &path_zv);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_STR(zend_string_copy(path));
	}
	_1 = zephir_start_with_str(&path_zv, SL("./"));
	if (!(_1)) {
		_1 = zephir_start_with_str(&path_zv, SL("../"));
	}
	if (_1) {
		zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_0, 1221, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_3$$4, "dirname", NULL, 238, &_2$$4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VSV(return_value, &_3$$4, "/", &path_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 1214, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&view, &_4);
	if (Z_TYPE_P(&view) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD_CACHED(&viewsDirs, &view, "getViewsDir", &_zephir_call_cache[1]);
		zephir_check_call_status();
		if (Z_TYPE_P(&viewsDirs) == IS_ARRAY) {
			if (Z_TYPE_P(&viewsDirs) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_6$$6);
				zephir_string_to_char_array(&_6$$6, &viewsDirs);
				_5$$6 = &_6$$6;
			} else {
				_5$$6 = &viewsDirs;
			}
			zephir_is_iterable(_5$$6, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2514);
			if (Z_TYPE_P(_5$$6) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_5$$6), _7$$6)
				{
					ZEPHIR_INIT_NVAR(&viewsDir);
					ZVAL_COPY(&viewsDir, _7$$6);
					ZEPHIR_INIT_NVAR(&_9$$7);
					ZEPHIR_CONCAT_VV(&_9$$7, &viewsDir, &path_zv);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&_8$$7, this_ptr, "phpFileExists", &_zephir_call_cache[2], &_9$$7);
					zephir_check_call_status();
					if (zephir_is_true(&_8$$7)) {
						ZEPHIR_CONCAT_VV(return_value, &viewsDir, &path_zv);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						RETURN_MM();
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _5$$6, "rewind", &_zephir_call_cache[3]);
				zephir_check_call_status();
				_11$$6 = 1;
				while (1) {
					if (_11$$6) {
						_11$$6 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _5$$6, "next", &_zephir_call_cache[4]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_10$$6, _5$$6, "valid", &_zephir_call_cache[5]);
					zephir_check_call_status();
					if (!zend_is_true(&_10$$6)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&viewsDir, _5$$6, "current", &_zephir_call_cache[6]);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_13$$9);
						ZEPHIR_CONCAT_VV(&_13$$9, &viewsDir, &path_zv);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(&_12$$9, this_ptr, "phpFileExists", &_zephir_call_cache[7], &_13$$9);
						zephir_check_call_status();
						if (zephir_is_true(&_12$$9)) {
							ZEPHIR_CONCAT_VV(return_value, &viewsDir, &path_zv);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							RETURN_MM();
						}
				}
			}
			ZEPHIR_INIT_NVAR(&viewsDir);
			ZEPHIR_CONCAT_VV(return_value, &viewsDir, &path_zv);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		} else {
			ZEPHIR_CONCAT_VV(return_value, &viewsDirs, &path_zv);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		}
	}
	RETURN_MM_STR(zend_string_copy(path));
}

/**
 * Resolves filter intermediate code into PHP function calls
 *
 * @phpstan-param mvc_volt_node $filter
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveFilter)
{
	zval _36, _38, _2$$5, _14$$11, _16$$11;
	zend_bool _5, _11, _26$$30, _31$$41;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *left = NULL;
	zval *filter_param = NULL, left_zv, code, type, functionName, name, file, line, extensions, filters, funcArguments, arguments, definition, _8, _35, _37, _39, _0$$5, _1$$5, _3$$5, _4$$5, _10$$9, _13$$11, _15$$11, _17$$11, _18$$11, _19$$24, _20$$24, _21$$24, _22$$24, _23$$24, _24$$24, _25$$30, _27$$30, _28$$30, _29$$30, _30$$41, _32$$41, _33$$41, _34$$41;
	zval filter, _6$$7, _7$$7, _9$$9, _12$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&left_zv);
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
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$24);
	ZVAL_UNDEF(&_20$$24);
	ZVAL_UNDEF(&_21$$24);
	ZVAL_UNDEF(&_22$$24);
	ZVAL_UNDEF(&_23$$24);
	ZVAL_UNDEF(&_24$$24);
	ZVAL_UNDEF(&_25$$30);
	ZVAL_UNDEF(&_27$$30);
	ZVAL_UNDEF(&_28$$30);
	ZVAL_UNDEF(&_29$$30);
	ZVAL_UNDEF(&_30$$41);
	ZVAL_UNDEF(&_32$$41);
	ZVAL_UNDEF(&_33$$41);
	ZVAL_UNDEF(&_34$$41);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_16$$11);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("extensions", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("filters", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(filter, filter_param)
		Z_PARAM_STR(left)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	filter_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&filter, filter_param);
	zephir_memory_observe(&left_zv);
	ZVAL_STR_COPY(&left_zv, left);
	ZEPHIR_INIT_VAR(&code);
	ZVAL_NULL(&code);
	zephir_memory_observe(&type);
	zephir_array_fetch_string(&type, &filter, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2536);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG(&type, 265)) {
		zephir_memory_observe(&name);
		zephir_array_fetch_string(&name, &filter, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2542);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		if (UNEXPECTED(!ZEPHIR_IS_LONG(&type, 350))) {
			ZEPHIR_INIT_VAR(&_0$$5);
			object_init_ex(&_0$$5, phalcon_mvc_view_engine_volt_exceptions_unknownvoltfiltertype_ce);
			zephir_memory_observe(&_1$$5);
			zephir_array_fetch_string(&_1$$5, &filter, SL("file"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2548);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_cast_to_string(&_2$$5, &_1$$5);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&_3$$5);
			zephir_array_fetch_string(&_3$$5, &filter, SL("line"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2548);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_LONG(&_4$$5, zephir_get_intval(&_3$$5));
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$5, "__construct", &_zephir_call_cache[0], &_2$$5, &_4$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_0$$5, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2548);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&functionName);
		zephir_array_fetch_string(&functionName, &filter, SL("name"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2551);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&name);
		zephir_array_fetch_string(&name, &functionName, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2552);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&funcArguments);
	ZVAL_NULL(&funcArguments);
	ZEPHIR_INIT_VAR(&arguments);
	ZVAL_NULL(&arguments);
	ZEPHIR_OBS_NVAR(&funcArguments);
	_5 = zephir_array_isset_string_fetch(&funcArguments, &filter, SL("arguments"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_5) {
		if (!ZEPHIR_IS_STRING(&name, "default")) {
			zephir_memory_observe(&file);
			zephir_array_fetch_string(&file, &filter, SL("file"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2566);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&line);
			zephir_array_fetch_string(&line, &filter, SL("line"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2567);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_6$$7);
			zephir_create_array(&_6$$7, 3, 0);
			ZEPHIR_INIT_VAR(&_7$$7);
			zephir_create_array(&_7$$7, 4, 0);
			add_assoc_long_ex(&_7$$7, SL("type"), 364);
			zephir_array_update_string(&_7$$7, SL("value"), &left_zv, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_7$$7, SL("file"), &file, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_7$$7, SL("line"), &line, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_6$$7, SL("expr"), &_7$$7, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_6$$7, SL("file"), &file, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_6$$7, SL("line"), &line, PH_COPY | PH_SEPARATE);
			ZEPHIR_MAKE_REF(&funcArguments);
			ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 146, &funcArguments, &_6$$7);
			ZEPHIR_UNREF(&funcArguments);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD_CACHED(&arguments, this_ptr, "expression", &_zephir_call_cache[1], &funcArguments);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&arguments, &left_zv);
	}
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_0, 1225, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&extensions, &_8);
	if (!(ZEPHIR_IS_EMPTY(&extensions))) {
		ZEPHIR_INIT_VAR(&_9$$9);
		zephir_create_array(&_9$$9, 3, 0);
		zephir_array_fast_append(&_9$$9, &name);
		zephir_array_fast_append(&_9$$9, &arguments);
		zephir_array_fast_append(&_9$$9, &funcArguments);
		ZEPHIR_INIT_VAR(&_10$$9);
		ZVAL_STRING(&_10$$9, "compileFilter");
		ZEPHIR_CALL_METHOD_CACHED(&code, this_ptr, "fireExtensionEvent", &_zephir_call_cache[2], &_10$$9, &_9$$9);
		zephir_check_call_status();
		if (Z_TYPE_P(&code) == IS_STRING) {
			RETURN_CCTOR(&code);
		}
	}
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_1, 1235, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&filters, &_8);
	zephir_memory_observe(&definition);
	_11 = zephir_array_isset_fetch(&definition, &filters, &name, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_11) {
		if (Z_TYPE_P(&definition) == IS_STRING) {
			ZEPHIR_CONCAT_VSVS(return_value, &definition, "(", &arguments, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		}
		if (Z_TYPE_P(&definition) == IS_OBJECT) {
			if (zephir_is_instance_of(&definition, SL("Closure"))) {
				ZEPHIR_INIT_VAR(&_12$$14);
				zephir_create_array(&_12$$14, 2, 0);
				zephir_array_fast_append(&_12$$14, &arguments);
				zephir_array_fast_append(&_12$$14, &funcArguments);
				ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &definition, &_12$$14);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
		ZEPHIR_INIT_VAR(&_13$$11);
		object_init_ex(&_13$$11, phalcon_mvc_view_engine_volt_exceptions_invaliduserfilterdefinition_ce);
		zephir_cast_to_string(&_14$$11, &name);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_15$$11);
		zephir_array_fetch_string(&_15$$11, &filter, SL("file"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2640);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_cast_to_string(&_16$$11, &_15$$11);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_17$$11);
		zephir_array_fetch_string(&_17$$11, &filter, SL("line"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2640);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_18$$11, zephir_get_intval(&_17$$11));
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_13$$11, "__construct", &_zephir_call_cache[3], &_14$$11, &_16$$11, &_18$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_13$$11, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2640);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_STRING(&name, "abs")) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_STRING(&name, "capitalize")) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_STRING(&name, "convert_encoding")) { goto zephir_switch_0_clause_2; }
	if (ZEPHIR_IS_STRING(&name, "default")) { goto zephir_switch_0_clause_3; }
	if (ZEPHIR_IS_STRING(&name, "e")) { goto zephir_switch_0_clause_4; }
	if (ZEPHIR_IS_STRING(&name, "escape")) { goto zephir_switch_0_clause_5; }
	if (ZEPHIR_IS_STRING(&name, "escape_attr")) { goto zephir_switch_0_clause_6; }
	if (ZEPHIR_IS_STRING(&name, "escape_css")) { goto zephir_switch_0_clause_7; }
	if (ZEPHIR_IS_STRING(&name, "escape_js")) { goto zephir_switch_0_clause_8; }
	if (ZEPHIR_IS_STRING(&name, "format")) { goto zephir_switch_0_clause_9; }
	if (ZEPHIR_IS_STRING(&name, "join")) { goto zephir_switch_0_clause_10; }
	if (ZEPHIR_IS_STRING(&name, "json_encode")) { goto zephir_switch_0_clause_11; }
	if (ZEPHIR_IS_STRING(&name, "json_decode")) { goto zephir_switch_0_clause_12; }
	if (ZEPHIR_IS_STRING(&name, "keys")) { goto zephir_switch_0_clause_13; }
	if (ZEPHIR_IS_STRING(&name, "left_trim")) { goto zephir_switch_0_clause_14; }
	if (ZEPHIR_IS_STRING(&name, "length")) { goto zephir_switch_0_clause_15; }
	if (ZEPHIR_IS_STRING(&name, "lower")) { goto zephir_switch_0_clause_16; }
	if (ZEPHIR_IS_STRING(&name, "lowercase")) { goto zephir_switch_0_clause_17; }
	if (ZEPHIR_IS_STRING(&name, "right_trim")) { goto zephir_switch_0_clause_18; }
	if (ZEPHIR_IS_STRING(&name, "nl2br")) { goto zephir_switch_0_clause_19; }
	if (ZEPHIR_IS_STRING(&name, "slashes")) { goto zephir_switch_0_clause_20; }
	if (ZEPHIR_IS_STRING(&name, "slice")) { goto zephir_switch_0_clause_21; }
	if (ZEPHIR_IS_STRING(&name, "sort")) { goto zephir_switch_0_clause_22; }
	if (ZEPHIR_IS_STRING(&name, "stripslashes")) { goto zephir_switch_0_clause_23; }
	if (ZEPHIR_IS_STRING(&name, "striptags")) { goto zephir_switch_0_clause_24; }
	if (ZEPHIR_IS_STRING(&name, "trim")) { goto zephir_switch_0_clause_25; }
	if (ZEPHIR_IS_STRING(&name, "upper")) { goto zephir_switch_0_clause_26; }
	if (ZEPHIR_IS_STRING(&name, "uppercase")) { goto zephir_switch_0_clause_27; }
	if (ZEPHIR_IS_STRING(&name, "url_encode")) { goto zephir_switch_0_clause_28; }
	goto zephir_switch_0_end;
	zephir_switch_0_clause_0: ;
		ZEPHIR_CONCAT_SVS(return_value, "abs(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_1: ;
		ZEPHIR_CONCAT_SVS(return_value, "ucwords(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_2: ;
		ZEPHIR_CONCAT_SVS(return_value, "$this->convertEncoding(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_3: ;
		ZEPHIR_CONCAT_SVSVSVS(return_value, "(empty(", &left_zv, ") ? (", &arguments, ") : (", &left_zv, "))");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_4: ;
	zephir_switch_0_clause_5: ;
		ZEPHIR_CONCAT_SVS(return_value, "$this->escaper->html(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_6: ;
		ZEPHIR_CONCAT_SVS(return_value, "$this->escaper->attributes(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_7: ;
		ZEPHIR_CONCAT_SVS(return_value, "$this->escaper->css(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_8: ;
		ZEPHIR_CONCAT_SVS(return_value, "$this->escaper->js(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_9: ;
		ZEPHIR_CONCAT_SVS(return_value, "sprintf(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_10: ;
		zephir_memory_observe(&_20$$24);
		zephir_array_fetch_long(&_20$$24, &funcArguments, 1, PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2666);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_21$$24);
		zephir_array_fetch_string(&_21$$24, &_20$$24, SL("expr"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2666);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_19$$24, this_ptr, "expression", &_zephir_call_cache[4], &_21$$24);
		zephir_check_call_status();
		zephir_memory_observe(&_23$$24);
		zephir_array_fetch_long(&_23$$24, &funcArguments, 0, PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2667);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_24$$24);
		zephir_array_fetch_string(&_24$$24, &_23$$24, SL("expr"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2667);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_22$$24, this_ptr, "expression", &_zephir_call_cache[5], &_24$$24);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVSVS(return_value, "join(", &_19$$24, ", ", &_22$$24, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_11: ;
		ZEPHIR_CONCAT_SVS(return_value, "json_encode(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_12: ;
		ZEPHIR_CONCAT_SVS(return_value, "json_decode(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_13: ;
		ZEPHIR_CONCAT_SVS(return_value, "array_keys(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_14: ;
		ZEPHIR_CONCAT_SVS(return_value, "ltrim(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_15: ;
		ZEPHIR_CONCAT_SVS(return_value, "$this->length(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_16: ;
	zephir_switch_0_clause_17: ;
		zephir_read_property_cached(&_25$$30, this_ptr, _zephir_prop_2, 1216, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_26$$30 = Z_TYPE_P(&_25$$30) != IS_NULL;
		if (_26$$30) {
			zephir_read_property_cached(&_27$$30, this_ptr, _zephir_prop_2, 1216, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_29$$30);
			ZVAL_STRING(&_29$$30, "helper");
			ZEPHIR_CALL_METHOD_CACHED(&_28$$30, &_27$$30, "has", &_zephir_call_cache[6], &_29$$30);
			zephir_check_call_status();
			_26$$30 = ZEPHIR_IS_TRUE_IDENTICAL(&_28$$30);
		}
		if (_26$$30) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->helper->lower(", &arguments, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		} else {
			ZEPHIR_CONCAT_SVS(return_value, "strtolower(", &arguments, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		}
	zephir_switch_0_clause_18: ;
		ZEPHIR_CONCAT_SVS(return_value, "rtrim(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_19: ;
		ZEPHIR_CONCAT_SVS(return_value, "nl2br(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_20: ;
		ZEPHIR_CONCAT_SVS(return_value, "addslashes(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_21: ;
		ZEPHIR_CONCAT_SVS(return_value, "$this->slice(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_22: ;
		ZEPHIR_CONCAT_SVS(return_value, "$this->sort(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_23: ;
		ZEPHIR_CONCAT_SVS(return_value, "stripslashes(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_24: ;
		ZEPHIR_CONCAT_SVS(return_value, "strip_tags(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_25: ;
		ZEPHIR_CONCAT_SVS(return_value, "trim(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_clause_26: ;
	zephir_switch_0_clause_27: ;
		zephir_read_property_cached(&_30$$41, this_ptr, _zephir_prop_2, 1216, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_31$$41 = Z_TYPE_P(&_30$$41) != IS_NULL;
		if (_31$$41) {
			zephir_read_property_cached(&_32$$41, this_ptr, _zephir_prop_2, 1216, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_34$$41);
			ZVAL_STRING(&_34$$41, "helper");
			ZEPHIR_CALL_METHOD_CACHED(&_33$$41, &_32$$41, "has", &_zephir_call_cache[7], &_34$$41);
			zephir_check_call_status();
			_31$$41 = ZEPHIR_IS_TRUE_IDENTICAL(&_33$$41);
		}
		if (_31$$41) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->helper->upper(", &arguments, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		} else {
			ZEPHIR_CONCAT_SVS(return_value, "strtoupper(", &arguments, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		}
	zephir_switch_0_clause_28: ;
		ZEPHIR_CONCAT_SVS(return_value, "urlencode(", &arguments, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	zephir_switch_0_end: ;

	ZEPHIR_INIT_VAR(&_35);
	object_init_ex(&_35, phalcon_mvc_view_engine_volt_exceptions_unknownvoltfilter_ce);
	zephir_cast_to_string(&_36, &name);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_37);
	zephir_array_fetch_string(&_37, &filter, SL("file"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2712);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_cast_to_string(&_38, &_37);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_39);
	zephir_array_fetch_string(&_39, &filter, SL("line"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2712);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_LONG(&_8, zephir_get_intval(&_39));
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_35, "__construct", &_zephir_call_cache[8], &_36, &_38, &_8);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_35, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2712);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Traverses a statement list compiling each of its nodes
 *
 * @phpstan-param mvc_volt_node $statements
 * @phpstan-return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, statementList)
{
	zval _97, _7$$7, _45$$39, _55$$42, _93$$74;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode, _1, _50, _4$$5, _13$$10, _27$$20, _31$$26, _52$$40, _61$$45, _75$$55, _79$$61;
	zval *statements_param = NULL, *extendsMode_param = NULL, __$true, __$false, extended, blockMode, compilation, extensions, statement, tempCompilation, type, blockName, blockStatements, blocks, path, pathValue, finalPath, subCompiler, level, _0, *_2, _49, _3$$6, _10$$5, _5$$7, _6$$7, _8$$7, _9$$7, _12$$8, _14$$11, _15$$12, _16$$12, _17$$13, _18$$14, _19$$14, _20$$15, _21$$16, _22$$16, _23$$17, _24$$17, _25$$18, _26$$19, _28$$20, _29$$25, _30$$25, _32$$28, _33$$29, _34$$30, _35$$31, _36$$32, _37$$32, _38$$35, _39$$36, _40$$36, _41$$37, _42$$37, _43$$39, _44$$39, _46$$39, _47$$39, _48$$39, _51$$41, _58$$40, _53$$42, _54$$42, _56$$42, _57$$42, _60$$43, _62$$46, _63$$47, _64$$47, _65$$48, _66$$49, _67$$49, _68$$50, _69$$51, _70$$51, _71$$52, _72$$52, _73$$53, _74$$54, _76$$55, _77$$60, _78$$60, _80$$63, _81$$64, _82$$65, _83$$66, _84$$67, _85$$67, _86$$70, _87$$71, _88$$71, _89$$72, _90$$72, _91$$74, _92$$74, _94$$74, _95$$74, _96$$74;
	zval statements, _11$$8, _59$$43;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statements);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_59$$43);
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
	ZVAL_UNDEF(&pathValue);
	ZVAL_UNDEF(&finalPath);
	ZVAL_UNDEF(&subCompiler);
	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_49);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_29$$25);
	ZVAL_UNDEF(&_30$$25);
	ZVAL_UNDEF(&_32$$28);
	ZVAL_UNDEF(&_33$$29);
	ZVAL_UNDEF(&_34$$30);
	ZVAL_UNDEF(&_35$$31);
	ZVAL_UNDEF(&_36$$32);
	ZVAL_UNDEF(&_37$$32);
	ZVAL_UNDEF(&_38$$35);
	ZVAL_UNDEF(&_39$$36);
	ZVAL_UNDEF(&_40$$36);
	ZVAL_UNDEF(&_41$$37);
	ZVAL_UNDEF(&_42$$37);
	ZVAL_UNDEF(&_43$$39);
	ZVAL_UNDEF(&_44$$39);
	ZVAL_UNDEF(&_46$$39);
	ZVAL_UNDEF(&_47$$39);
	ZVAL_UNDEF(&_48$$39);
	ZVAL_UNDEF(&_51$$41);
	ZVAL_UNDEF(&_58$$40);
	ZVAL_UNDEF(&_53$$42);
	ZVAL_UNDEF(&_54$$42);
	ZVAL_UNDEF(&_56$$42);
	ZVAL_UNDEF(&_57$$42);
	ZVAL_UNDEF(&_60$$43);
	ZVAL_UNDEF(&_62$$46);
	ZVAL_UNDEF(&_63$$47);
	ZVAL_UNDEF(&_64$$47);
	ZVAL_UNDEF(&_65$$48);
	ZVAL_UNDEF(&_66$$49);
	ZVAL_UNDEF(&_67$$49);
	ZVAL_UNDEF(&_68$$50);
	ZVAL_UNDEF(&_69$$51);
	ZVAL_UNDEF(&_70$$51);
	ZVAL_UNDEF(&_71$$52);
	ZVAL_UNDEF(&_72$$52);
	ZVAL_UNDEF(&_73$$53);
	ZVAL_UNDEF(&_74$$54);
	ZVAL_UNDEF(&_76$$55);
	ZVAL_UNDEF(&_77$$60);
	ZVAL_UNDEF(&_78$$60);
	ZVAL_UNDEF(&_80$$63);
	ZVAL_UNDEF(&_81$$64);
	ZVAL_UNDEF(&_82$$65);
	ZVAL_UNDEF(&_83$$66);
	ZVAL_UNDEF(&_84$$67);
	ZVAL_UNDEF(&_85$$67);
	ZVAL_UNDEF(&_86$$70);
	ZVAL_UNDEF(&_87$$71);
	ZVAL_UNDEF(&_88$$71);
	ZVAL_UNDEF(&_89$$72);
	ZVAL_UNDEF(&_90$$72);
	ZVAL_UNDEF(&_91$$74);
	ZVAL_UNDEF(&_92$$74);
	ZVAL_UNDEF(&_94$$74);
	ZVAL_UNDEF(&_95$$74);
	ZVAL_UNDEF(&_96$$74);
	ZVAL_UNDEF(&_97);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_45$$39);
	ZVAL_UNDEF(&_55$$42);
	ZVAL_UNDEF(&_93$$74);
	ZEND_TLS zephir_method_cache _zephir_call_cache[52];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("extended", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("extensions", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("blocks", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("extendedBlocks", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("blockLevel", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(statements, statements_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(extendsMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &statements_param, &extendsMode_param);
	zephir_get_arrval(&statements, statements_param);
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		}
	if (ZEPHIR_IS_EMPTY(&statements)) {
		RETURN_MM_STRING("");
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1231, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	zephir_is_iterable(&statements, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 3005);
	if (Z_TYPE_P(&statements) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&statements), _2)
		{
			ZEPHIR_INIT_NVAR(&statement);
			ZVAL_COPY(&statement, _2);
			if (UNEXPECTED(Z_TYPE_P(&statement) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(&_3$$6);
				object_init_ex(&_3$$6, phalcon_mvc_view_engine_volt_exceptions_corruptedstatement_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_3$$6, "__construct", &_zephir_call_cache[0]);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$6, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2753);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_4$$5 = zephir_array_isset_value_string(&statement, SL("type"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(!(_4$$5))) {
				ZEPHIR_INIT_NVAR(&_5$$7);
				object_init_ex(&_5$$7, phalcon_mvc_view_engine_volt_exceptions_invalidstatement_ce);
				ZEPHIR_OBS_NVAR(&_6$$7);
				zephir_array_fetch_string(&_6$$7, &statement, SL("file"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2760);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_cast_to_string(&_7$$7, &_6$$7);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_8$$7);
				zephir_array_fetch_string(&_8$$7, &statement, SL("line"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2760);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZVAL_LONG(&_9$$7, zephir_get_intval(&_8$$7));
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_5$$7, "__construct", &_zephir_call_cache[1], &_7$$7, &_9$$7, &statement);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$7, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2760);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_read_property_cached(&_10$$5, this_ptr, _zephir_prop_1, 1225, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&extensions, &_10$$5);
			if (!(ZEPHIR_IS_EMPTY(&extensions))) {
				ZEPHIR_INIT_NVAR(&_11$$8);
				zephir_create_array(&_11$$8, 1, 0);
				zephir_array_fast_append(&_11$$8, &statement);
				ZEPHIR_INIT_NVAR(&_12$$8);
				ZVAL_STRING(&_12$$8, "compileStatement");
				ZEPHIR_CALL_METHOD_CACHED(&tempCompilation, this_ptr, "fireExtensionEvent", &_zephir_call_cache[2], &_12$$8, &_11$$8);
				zephir_check_call_status();
				if (Z_TYPE_P(&tempCompilation) == IS_STRING) {
					zephir_concat_self(&compilation, &tempCompilation);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
			}
			ZEPHIR_OBS_NVAR(&type);
			zephir_array_fetch_string(&type, &statement, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2789);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_LONG(&type, 357)) { goto zephir_switch_0_clause_0; }
			if (ZEPHIR_IS_LONG(&type, 300)) { goto zephir_switch_0_clause_1; }
			if (ZEPHIR_IS_LONG(&type, 302)) { goto zephir_switch_0_clause_2; }
			if (ZEPHIR_IS_LONG(&type, 411)) { goto zephir_switch_0_clause_3; }
			if (ZEPHIR_IS_LONG(&type, 412)) { goto zephir_switch_0_clause_4; }
			if (ZEPHIR_IS_LONG(&type, 413)) { goto zephir_switch_0_clause_5; }
			if (ZEPHIR_IS_LONG(&type, 304)) { goto zephir_switch_0_clause_6; }
			if (ZEPHIR_IS_LONG(&type, 306)) { goto zephir_switch_0_clause_7; }
			if (ZEPHIR_IS_LONG(&type, 359)) { goto zephir_switch_0_clause_8; }
			if (ZEPHIR_IS_LONG(&type, 307)) { goto zephir_switch_0_clause_9; }
			if (ZEPHIR_IS_LONG(&type, 310)) { goto zephir_switch_0_clause_10; }
			if (ZEPHIR_IS_LONG(&type, 313)) { goto zephir_switch_0_clause_11; }
			if (ZEPHIR_IS_LONG(&type, 316)) { goto zephir_switch_0_clause_12; }
			if (ZEPHIR_IS_LONG(&type, 327)) { goto zephir_switch_0_clause_13; }
			if (ZEPHIR_IS_LONG(&type, 317)) { goto zephir_switch_0_clause_14; }
			if (ZEPHIR_IS_LONG(&type, 319)) { goto zephir_switch_0_clause_15; }
			if (ZEPHIR_IS_LONG(&type, 320)) { goto zephir_switch_0_clause_16; }
			if (ZEPHIR_IS_LONG(&type, 321)) { goto zephir_switch_0_clause_17; }
			if (ZEPHIR_IS_LONG(&type, 322)) { goto zephir_switch_0_clause_18; }
			if (ZEPHIR_IS_LONG(&type, 325)) { goto zephir_switch_0_clause_19; }
			if (ZEPHIR_IS_LONG(&type, 358)) { goto zephir_switch_0_clause_20; }
			goto zephir_switch_0_clause_21;
			zephir_switch_0_clause_0: ;
				_13$$10 = zephir_array_isset_value_string(&statement, SL("value"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_13$$10) {
					ZEPHIR_OBS_NVAR(&_14$$11);
					zephir_array_fetch_string(&_14$$11, &statement, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2798);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&compilation, &_14$$11);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_1: ;
				if (extendsMode) {
					ZVAL_BOOL(&_16$$12, 1);
				} else {
					ZVAL_BOOL(&_16$$12, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&_15$$12, this_ptr, "compileIf", &_zephir_call_cache[3], &statement, &_16$$12);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_15$$12);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_2: ;
				ZEPHIR_CALL_METHOD_CACHED(&_17$$13, this_ptr, "compileElseIf", &_zephir_call_cache[4], &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_17$$13);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_3: ;
				if (extendsMode) {
					ZVAL_BOOL(&_19$$14, 1);
				} else {
					ZVAL_BOOL(&_19$$14, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&_18$$14, this_ptr, "compileSwitch", &_zephir_call_cache[5], &statement, &_19$$14);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_18$$14);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_4: ;
				ZEPHIR_CALL_METHOD_CACHED(&_20$$15, this_ptr, "compileCase", &_zephir_call_cache[6], &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_20$$15);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_5: ;
				ZVAL_BOOL(&_22$$16, 0);
				ZEPHIR_CALL_METHOD_CACHED(&_21$$16, this_ptr, "compileCase", &_zephir_call_cache[7], &statement, &_22$$16);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_21$$16);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_6: ;
				if (extendsMode) {
					ZVAL_BOOL(&_24$$17, 1);
				} else {
					ZVAL_BOOL(&_24$$17, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&_23$$17, this_ptr, "compileForeach", &_zephir_call_cache[8], &statement, &_24$$17);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_23$$17);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_7: ;
				ZEPHIR_CALL_METHOD_CACHED(&_25$$18, this_ptr, "compileSet", &_zephir_call_cache[9], &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_25$$18);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_8: ;
				ZEPHIR_CALL_METHOD_CACHED(&_26$$19, this_ptr, "compileEcho", &_zephir_call_cache[10], &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_26$$19);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_9: ;
				ZEPHIR_OBS_NVAR(&blockName);
				zephir_array_fetch_string(&blockName, &statement, SL("name"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2847);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&blockStatements);
				_27$$20 = zephir_array_isset_string_fetch(&blockStatements, &statement, SL("block_statements"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_27$$20;
				zephir_read_property_cached(&_28$$20, this_ptr, _zephir_prop_2, 1232, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(&blocks, &_28$$20);
				if (zephir_is_true(&blockMode)) {
					if (Z_TYPE_P(&blocks) != IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&blocks);
						array_init(&blocks);
					}
					if (Z_TYPE_P(&compilation) != IS_NULL) {
						zephir_array_append(&blocks, &compilation, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2862);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&compilation);
						ZVAL_NULL(&compilation);
					}
					zephir_array_update_zval(&blocks, &blockName, &blockStatements, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1232, &blocks);
				} else {
					if (Z_TYPE_P(&blockStatements) == IS_ARRAY) {
						if (extendsMode) {
							ZVAL_BOOL(&_30$$25, 1);
						} else {
							ZVAL_BOOL(&_30$$25, 0);
						}
						ZEPHIR_CALL_METHOD_CACHED(&_29$$25, this_ptr, "statementList", &_zephir_call_cache[11], &blockStatements, &_30$$25);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_29$$25);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_10: ;
				ZEPHIR_OBS_NVAR(&path);
				zephir_array_fetch_string(&path, &statement, SL("path"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2887);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&pathValue);
				_31$$26 = zephir_array_isset_string_fetch(&pathValue, &path, SL("value"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_31$$26)) {
					ZEPHIR_INIT_NVAR(&pathValue);
					ZVAL_STRING(&pathValue, "");
				}
				ZEPHIR_CALL_METHOD_CACHED(&finalPath, this_ptr, "getFinalPath", &_zephir_call_cache[12], &pathValue);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&extended);
				ZVAL_BOOL(&extended, 1);
				ZEPHIR_INIT_NVAR(&subCompiler);
				if (zephir_clone(&subCompiler, this_ptr) == FAILURE) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&tempCompilation, &subCompiler, "compile", &_zephir_call_cache[13], &finalPath, &extended);
				zephir_check_call_status();
				if (Z_TYPE_P(&tempCompilation) == IS_NULL) {
					ZEPHIR_CALL_METHOD_CACHED(&_32$$28, &subCompiler, "getCompiledTemplatePath", &_zephir_call_cache[14]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&tempCompilation, this_ptr, "phpFileGetContents", &_zephir_call_cache[15], &_32$$28);
					zephir_check_call_status();
				}
				if (1) {
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1231, &__$true);
				} else {
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1231, &__$false);
				}
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1227, &tempCompilation);
				ZEPHIR_CPY_WRT(&blockMode, &extended);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_11: ;
				ZEPHIR_CALL_METHOD_CACHED(&_33$$29, this_ptr, "compileInclude", &_zephir_call_cache[16], &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_33$$29);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_12: ;
				ZEPHIR_CALL_METHOD_CACHED(&_34$$30, this_ptr, "compileDo", &_zephir_call_cache[17], &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_34$$30);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_13: ;
				ZEPHIR_CALL_METHOD_CACHED(&_35$$31, this_ptr, "compileReturn", &_zephir_call_cache[18], &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_35$$31);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_14: ;
				if (extendsMode) {
					ZVAL_BOOL(&_37$$32, 1);
				} else {
					ZVAL_BOOL(&_37$$32, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&_36$$32, this_ptr, "compileAutoEscape", &_zephir_call_cache[19], &statement, &_37$$32);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_36$$32);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_15: ;
				zephir_concat_self_str(&compilation, SL("<?php continue; ?>"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_16: ;
				zephir_concat_self_str(&compilation, SL("<?php break; ?>"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_17: ;
				ZEPHIR_CALL_METHOD_CACHED(&_38$$35, this_ptr, "compileForElse", &_zephir_call_cache[20]);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_38$$35);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_18: ;
				if (extendsMode) {
					ZVAL_BOOL(&_40$$36, 1);
				} else {
					ZVAL_BOOL(&_40$$36, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&_39$$36, this_ptr, "compileMacro", &_zephir_call_cache[21], &statement, &_40$$36);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_39$$36);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_19: ;
				if (extendsMode) {
					ZVAL_BOOL(&_42$$37, 1);
				} else {
					ZVAL_BOOL(&_42$$37, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&_41$$37, this_ptr, "compileCall", &_zephir_call_cache[22], &statement, &_42$$37);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_41$$37);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_20: ;
				goto zephir_switch_0_end;
			zephir_switch_0_clause_21: ;
				ZEPHIR_INIT_NVAR(&_43$$39);
				object_init_ex(&_43$$39, phalcon_mvc_view_engine_volt_exceptions_unknownvoltstatement_ce);
				ZEPHIR_OBS_NVAR(&_44$$39);
				zephir_array_fetch_string(&_44$$39, &statement, SL("file"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2997);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_cast_to_string(&_45$$39, &_44$$39);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_46$$39);
				zephir_array_fetch_string(&_46$$39, &statement, SL("line"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2997);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZVAL_LONG(&_47$$39, zephir_get_intval(&type));
				ZVAL_LONG(&_48$$39, zephir_get_intval(&_46$$39));
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_43$$39, "__construct", &_zephir_call_cache[23], &_47$$39, &_45$$39, &_48$$39);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_43$$39, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2997);
				ZEPHIR_MM_RESTORE();
				return;
			zephir_switch_0_end: ;

		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &statements, "rewind", &_zephir_call_cache[24]);
		zephir_check_call_status();
		_50 = 1;
		while (1) {
			if (_50) {
				_50 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &statements, "next", &_zephir_call_cache[25]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_49, &statements, "valid", &_zephir_call_cache[26]);
			zephir_check_call_status();
			if (!zend_is_true(&_49)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&statement, &statements, "current", &_zephir_call_cache[27]);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&statement) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_51$$41);
					object_init_ex(&_51$$41, phalcon_mvc_view_engine_volt_exceptions_corruptedstatement_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_51$$41, "__construct", &_zephir_call_cache[28]);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_51$$41, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2753);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_52$$40 = zephir_array_isset_value_string(&statement, SL("type"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_52$$40))) {
					ZEPHIR_INIT_NVAR(&_53$$42);
					object_init_ex(&_53$$42, phalcon_mvc_view_engine_volt_exceptions_invalidstatement_ce);
					ZEPHIR_OBS_NVAR(&_54$$42);
					zephir_array_fetch_string(&_54$$42, &statement, SL("file"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2760);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_cast_to_string(&_55$$42, &_54$$42);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_56$$42);
					zephir_array_fetch_string(&_56$$42, &statement, SL("line"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2760);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZVAL_LONG(&_57$$42, zephir_get_intval(&_56$$42));
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_53$$42, "__construct", &_zephir_call_cache[29], &_55$$42, &_57$$42, &statement);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_53$$42, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2760);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property_cached(&_58$$40, this_ptr, _zephir_prop_1, 1225, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(&extensions, &_58$$40);
				if (!(ZEPHIR_IS_EMPTY(&extensions))) {
					ZEPHIR_INIT_NVAR(&_59$$43);
					zephir_create_array(&_59$$43, 1, 0);
					zephir_array_fast_append(&_59$$43, &statement);
					ZEPHIR_INIT_NVAR(&_60$$43);
					ZVAL_STRING(&_60$$43, "compileStatement");
					ZEPHIR_CALL_METHOD_CACHED(&tempCompilation, this_ptr, "fireExtensionEvent", &_zephir_call_cache[30], &_60$$43, &_59$$43);
					zephir_check_call_status();
					if (Z_TYPE_P(&tempCompilation) == IS_STRING) {
						zephir_concat_self(&compilation, &tempCompilation);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
				}
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch_string(&type, &statement, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2789);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_LONG(&type, 357)) { goto zephir_switch_1_clause_0; }
				if (ZEPHIR_IS_LONG(&type, 300)) { goto zephir_switch_1_clause_1; }
				if (ZEPHIR_IS_LONG(&type, 302)) { goto zephir_switch_1_clause_2; }
				if (ZEPHIR_IS_LONG(&type, 411)) { goto zephir_switch_1_clause_3; }
				if (ZEPHIR_IS_LONG(&type, 412)) { goto zephir_switch_1_clause_4; }
				if (ZEPHIR_IS_LONG(&type, 413)) { goto zephir_switch_1_clause_5; }
				if (ZEPHIR_IS_LONG(&type, 304)) { goto zephir_switch_1_clause_6; }
				if (ZEPHIR_IS_LONG(&type, 306)) { goto zephir_switch_1_clause_7; }
				if (ZEPHIR_IS_LONG(&type, 359)) { goto zephir_switch_1_clause_8; }
				if (ZEPHIR_IS_LONG(&type, 307)) { goto zephir_switch_1_clause_9; }
				if (ZEPHIR_IS_LONG(&type, 310)) { goto zephir_switch_1_clause_10; }
				if (ZEPHIR_IS_LONG(&type, 313)) { goto zephir_switch_1_clause_11; }
				if (ZEPHIR_IS_LONG(&type, 316)) { goto zephir_switch_1_clause_12; }
				if (ZEPHIR_IS_LONG(&type, 327)) { goto zephir_switch_1_clause_13; }
				if (ZEPHIR_IS_LONG(&type, 317)) { goto zephir_switch_1_clause_14; }
				if (ZEPHIR_IS_LONG(&type, 319)) { goto zephir_switch_1_clause_15; }
				if (ZEPHIR_IS_LONG(&type, 320)) { goto zephir_switch_1_clause_16; }
				if (ZEPHIR_IS_LONG(&type, 321)) { goto zephir_switch_1_clause_17; }
				if (ZEPHIR_IS_LONG(&type, 322)) { goto zephir_switch_1_clause_18; }
				if (ZEPHIR_IS_LONG(&type, 325)) { goto zephir_switch_1_clause_19; }
				if (ZEPHIR_IS_LONG(&type, 358)) { goto zephir_switch_1_clause_20; }
				goto zephir_switch_1_clause_21;
				zephir_switch_1_clause_0: ;
					_61$$45 = zephir_array_isset_value_string(&statement, SL("value"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_61$$45) {
						ZEPHIR_OBS_NVAR(&_62$$46);
						zephir_array_fetch_string(&_62$$46, &statement, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2798);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&compilation, &_62$$46);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_1: ;
					if (extendsMode) {
						ZVAL_BOOL(&_64$$47, 1);
					} else {
						ZVAL_BOOL(&_64$$47, 0);
					}
					ZEPHIR_CALL_METHOD_CACHED(&_63$$47, this_ptr, "compileIf", &_zephir_call_cache[31], &statement, &_64$$47);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_63$$47);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_2: ;
					ZEPHIR_CALL_METHOD_CACHED(&_65$$48, this_ptr, "compileElseIf", &_zephir_call_cache[32], &statement);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_65$$48);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_3: ;
					if (extendsMode) {
						ZVAL_BOOL(&_67$$49, 1);
					} else {
						ZVAL_BOOL(&_67$$49, 0);
					}
					ZEPHIR_CALL_METHOD_CACHED(&_66$$49, this_ptr, "compileSwitch", &_zephir_call_cache[33], &statement, &_67$$49);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_66$$49);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_4: ;
					ZEPHIR_CALL_METHOD_CACHED(&_68$$50, this_ptr, "compileCase", &_zephir_call_cache[34], &statement);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_68$$50);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_5: ;
					ZVAL_BOOL(&_70$$51, 0);
					ZEPHIR_CALL_METHOD_CACHED(&_69$$51, this_ptr, "compileCase", &_zephir_call_cache[35], &statement, &_70$$51);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_69$$51);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_6: ;
					if (extendsMode) {
						ZVAL_BOOL(&_72$$52, 1);
					} else {
						ZVAL_BOOL(&_72$$52, 0);
					}
					ZEPHIR_CALL_METHOD_CACHED(&_71$$52, this_ptr, "compileForeach", &_zephir_call_cache[36], &statement, &_72$$52);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_71$$52);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_7: ;
					ZEPHIR_CALL_METHOD_CACHED(&_73$$53, this_ptr, "compileSet", &_zephir_call_cache[37], &statement);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_73$$53);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_8: ;
					ZEPHIR_CALL_METHOD_CACHED(&_74$$54, this_ptr, "compileEcho", &_zephir_call_cache[38], &statement);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_74$$54);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_9: ;
					ZEPHIR_OBS_NVAR(&blockName);
					zephir_array_fetch_string(&blockName, &statement, SL("name"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2847);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&blockStatements);
					_75$$55 = zephir_array_isset_string_fetch(&blockStatements, &statement, SL("block_statements"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_75$$55;
					zephir_read_property_cached(&_76$$55, this_ptr, _zephir_prop_2, 1232, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&blocks, &_76$$55);
					if (zephir_is_true(&blockMode)) {
						if (Z_TYPE_P(&blocks) != IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&blocks);
							array_init(&blocks);
						}
						if (Z_TYPE_P(&compilation) != IS_NULL) {
							zephir_array_append(&blocks, &compilation, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2862);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&compilation);
							ZVAL_NULL(&compilation);
						}
						zephir_array_update_zval(&blocks, &blockName, &blockStatements, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1232, &blocks);
					} else {
						if (Z_TYPE_P(&blockStatements) == IS_ARRAY) {
							if (extendsMode) {
								ZVAL_BOOL(&_78$$60, 1);
							} else {
								ZVAL_BOOL(&_78$$60, 0);
							}
							ZEPHIR_CALL_METHOD_CACHED(&_77$$60, this_ptr, "statementList", &_zephir_call_cache[39], &blockStatements, &_78$$60);
							zephir_check_call_status();
							zephir_concat_self(&compilation, &_77$$60);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_10: ;
					ZEPHIR_OBS_NVAR(&path);
					zephir_array_fetch_string(&path, &statement, SL("path"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2887);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&pathValue);
					_79$$61 = zephir_array_isset_string_fetch(&pathValue, &path, SL("value"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_79$$61)) {
						ZEPHIR_INIT_NVAR(&pathValue);
						ZVAL_STRING(&pathValue, "");
					}
					ZEPHIR_CALL_METHOD_CACHED(&finalPath, this_ptr, "getFinalPath", &_zephir_call_cache[40], &pathValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&extended);
					ZVAL_BOOL(&extended, 1);
					ZEPHIR_INIT_NVAR(&subCompiler);
					if (zephir_clone(&subCompiler, this_ptr) == FAILURE) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&tempCompilation, &subCompiler, "compile", &_zephir_call_cache[41], &finalPath, &extended);
					zephir_check_call_status();
					if (Z_TYPE_P(&tempCompilation) == IS_NULL) {
						ZEPHIR_CALL_METHOD_CACHED(&_80$$63, &subCompiler, "getCompiledTemplatePath", &_zephir_call_cache[42]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&tempCompilation, this_ptr, "phpFileGetContents", &_zephir_call_cache[43], &_80$$63);
						zephir_check_call_status();
					}
					if (1) {
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1231, &__$true);
					} else {
						zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1231, &__$false);
					}
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1227, &tempCompilation);
					ZEPHIR_CPY_WRT(&blockMode, &extended);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_11: ;
					ZEPHIR_CALL_METHOD_CACHED(&_81$$64, this_ptr, "compileInclude", &_zephir_call_cache[44], &statement);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_81$$64);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_12: ;
					ZEPHIR_CALL_METHOD_CACHED(&_82$$65, this_ptr, "compileDo", &_zephir_call_cache[45], &statement);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_82$$65);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_13: ;
					ZEPHIR_CALL_METHOD_CACHED(&_83$$66, this_ptr, "compileReturn", &_zephir_call_cache[46], &statement);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_83$$66);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_14: ;
					if (extendsMode) {
						ZVAL_BOOL(&_85$$67, 1);
					} else {
						ZVAL_BOOL(&_85$$67, 0);
					}
					ZEPHIR_CALL_METHOD_CACHED(&_84$$67, this_ptr, "compileAutoEscape", &_zephir_call_cache[47], &statement, &_85$$67);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_84$$67);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_15: ;
					zephir_concat_self_str(&compilation, SL("<?php continue; ?>"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_16: ;
					zephir_concat_self_str(&compilation, SL("<?php break; ?>"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_17: ;
					ZEPHIR_CALL_METHOD_CACHED(&_86$$70, this_ptr, "compileForElse", &_zephir_call_cache[48]);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_86$$70);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_18: ;
					if (extendsMode) {
						ZVAL_BOOL(&_88$$71, 1);
					} else {
						ZVAL_BOOL(&_88$$71, 0);
					}
					ZEPHIR_CALL_METHOD_CACHED(&_87$$71, this_ptr, "compileMacro", &_zephir_call_cache[49], &statement, &_88$$71);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_87$$71);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_19: ;
					if (extendsMode) {
						ZVAL_BOOL(&_90$$72, 1);
					} else {
						ZVAL_BOOL(&_90$$72, 0);
					}
					ZEPHIR_CALL_METHOD_CACHED(&_89$$72, this_ptr, "compileCall", &_zephir_call_cache[50], &statement, &_90$$72);
					zephir_check_call_status();
					zephir_concat_self(&compilation, &_89$$72);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_20: ;
					goto zephir_switch_1_end;
				zephir_switch_1_clause_21: ;
					ZEPHIR_INIT_NVAR(&_91$$74);
					object_init_ex(&_91$$74, phalcon_mvc_view_engine_volt_exceptions_unknownvoltstatement_ce);
					ZEPHIR_OBS_NVAR(&_92$$74);
					zephir_array_fetch_string(&_92$$74, &statement, SL("file"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2997);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_cast_to_string(&_93$$74, &_92$$74);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_94$$74);
					zephir_array_fetch_string(&_94$$74, &statement, SL("line"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2997);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZVAL_LONG(&_95$$74, zephir_get_intval(&type));
					ZVAL_LONG(&_96$$74, zephir_get_intval(&_94$$74));
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_91$$74, "__construct", &_zephir_call_cache[51], &_95$$74, &_93$$74, &_96$$74);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_91$$74, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2997);
					ZEPHIR_MM_RESTORE();
					return;
				zephir_switch_1_end: ;

		}
	}
	ZEPHIR_INIT_NVAR(&statement);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&blockMode)) {
		zephir_read_property_cached(&level, this_ptr, _zephir_prop_4, 1234, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(&level, 1)) {
			if (Z_TYPE_P(&compilation) != IS_NULL) {
				zephir_update_property_array_append(this_ptr, SL("blocks"), &compilation);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("blockLevel")));
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("level")));
	zephir_cast_to_string(&_97, &compilation);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&_97);
}

/**
 * Compiles a block of statements
 *
 * @param array statements
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, statementListOrExtends)
{
	zend_bool isStatementList = 0, _0, _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statements, statements_sub, statement, *_1$$4, _2$$4, *_3$$4, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statements_sub);
	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
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
	_0 = zephir_array_isset_value_string(statements, SL("type"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_0)) {
		if (Z_TYPE_P(statements) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_string_to_char_array(&_2$$4, statements);
			_1$$4 = &_2$$4;
		} else {
			_1$$4 = statements;
		}
		zephir_is_iterable(_1$$4, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 3054);
		if (Z_TYPE_P(_1$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1$$4), _3$$4)
			{
				ZEPHIR_INIT_NVAR(&statement);
				ZVAL_COPY(&statement, _3$$4);
				if (Z_TYPE_P(&statement) != IS_ARRAY) {
					isStatementList = 0;
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _1$$4, "rewind", &_zephir_call_cache[0]);
			zephir_check_call_status();
			_5$$4 = 1;
			while (1) {
				if (_5$$4) {
					_5$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _1$$4, "next", &_zephir_call_cache[1]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_4$$4, _1$$4, "valid", &_zephir_call_cache[2]);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&statement, _1$$4, "current", &_zephir_call_cache[3]);
				zephir_check_call_status();
					if (Z_TYPE_P(&statement) != IS_ARRAY) {
						isStatementList = 0;
						break;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&statement);
	}
	if (isStatementList) {
		ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "statementList", &_zephir_call_cache[4], statements);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(statements, 1, 0);
	RETURN_MM();
}

/**
 * Checks whether a path is absolute (Unix root, Windows UNC or drive)
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, isAbsolutePath)
{
	zend_bool _0, _1, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval path_zv, _2, _3, _4, _5, _7, _8, _9;
	zend_string *path = NULL;

	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	_0 = zephir_start_with_str(&path_zv, SL("/"));
	if (!(_0)) {
		_0 = zephir_start_with_str(&path_zv, SL("\\"));
	}
	if (_0) {
		RETURN_MM_BOOL(1);
	}
	_1 = zephir_fast_strlen_ev(&path_zv) >= 2;
	if (_1) {
		ZVAL_LONG(&_2, 0);
		ZVAL_LONG(&_3, 1);
		ZEPHIR_INIT_VAR(&_4);
		zephir_substr(&_4, &path_zv, 0 , 1 , 0);
		ZEPHIR_CALL_FUNCTION(&_5, "ctype_alpha", NULL, 239, &_4);
		zephir_check_call_status();
		_1 = zephir_is_true(&_5);
	}
	_6 = _1;
	if (_6) {
		ZVAL_LONG(&_7, 1);
		ZVAL_LONG(&_8, 1);
		ZEPHIR_INIT_VAR(&_9);
		zephir_substr(&_9, &path_zv, 1 , 1 , 0);
		_6 = ZEPHIR_IS_STRING_IDENTICAL(&_9, ":");
	}
	if (_6) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

/**
 * @phpstan-param mvc_volt_node $expression
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, isTagFactory)
{
	zend_bool _0, _1$$3, _2$$4, _3$$6, _4$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expression_param = NULL, left, leftValue, name, _5$$6;
	zval expression;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&leftValue);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_5$$6);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(expression, expression_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expression_param);
	zephir_get_arrval(&expression, expression_param);
	zephir_memory_observe(&name);
	_0 = zephir_array_isset_string_fetch(&name, &expression, SL("name"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		zephir_memory_observe(&left);
		_1$$3 = zephir_array_isset_string_fetch(&left, &name, SL("left"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_1$$3) {
			zephir_memory_observe(&leftValue);
			_2$$4 = zephir_array_isset_string_fetch(&leftValue, &left, SL("value"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_2$$4) {
				RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&leftValue, "tag"));
			} else {
				_3$$6 = zephir_array_isset_value_string(&left, SL("name"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_4$$6 = _3$$6;
				if (_4$$6) {
					zephir_memory_observe(&_5$$6);
					zephir_array_fetch_string(&_5$$6, &left, SL("name"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 3116);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_4$$6 = Z_TYPE_P(&_5$$6) == IS_ARRAY;
				}
				if (_4$$6) {
					ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "isTagFactory", &_zephir_call_cache[0], &left);
					zephir_check_call_status();
					RETURN_MM();
				}
			}
		}
	}
	RETURN_MM_BOOL(0);
}

/**
 * Closes an open file pointer
 *
 * @link https://php.net/manual/en/function.fclose.php
 *
 * @param resource $handle
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, phpFclose)
{
	zval *handle, handle_sub;

	ZVAL_UNDEF(&handle_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle);
	RETURN_BOOL(zephir_fclose(handle));
}

/**
 * Gets line from file pointer and parse for CSV fields
 *
 * @param resource $stream
 * @param int      $length
 * @param string   $separator
 * @param string   $enclosure
 * @param string   $escape
 *
 * @return array<array-key, mixed>|false
 *
 * @link https://php.net/manual/en/function.fgetcsv.php
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, phpFgetCsv)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *separator = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *length_param = NULL, separator_zv, *enclosure = NULL, enclosure_sub, *escape = NULL, escape_sub, __$null, _0;

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&separator_zv);
	ZVAL_UNDEF(&enclosure_sub);
	ZVAL_UNDEF(&escape_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_ZVAL(stream)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(length)
		Z_PARAM_STR(separator)
		Z_PARAM_ZVAL_OR_NULL(enclosure)
		Z_PARAM_ZVAL_OR_NULL(escape)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	stream = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 1) {
		length_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 3) {
		enclosure = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		escape = ZEND_CALL_ARG(execute_data, 5);
	}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (!separator) {
		separator = zend_string_init(ZEND_STRL(","), 0);
		zephir_memory_observe(&separator_zv);
		ZVAL_STR(&separator_zv, separator);
	} else {
		zephir_memory_observe(&separator_zv);
	ZVAL_STR_COPY(&separator_zv, separator);
	}
	if (!enclosure) {
		enclosure = &enclosure_sub;
		ZEPHIR_CPY_WRT(enclosure, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(enclosure);
	}
	if (!escape) {
		escape = &escape_sub;
		ZEPHIR_CPY_WRT(escape, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(escape);
	}
	if (Z_TYPE_P(enclosure) == IS_NULL) {
		ZEPHIR_INIT_NVAR(enclosure);
		ZVAL_STRING(enclosure, "\"");
	}
	if (Z_TYPE_P(escape) == IS_NULL) {
		ZEPHIR_INIT_NVAR(escape);
		ZVAL_STRING(escape, "\\");
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 44, stream, &_0, &separator_zv, enclosure, escape);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.file-exists.php
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, phpFileExists)
{
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&filename_zv, filename);
	RETURN_BOOL((zephir_file_exists(&filename_zv) == SUCCESS));
}

/**
 * @param string        $filename
 * @param bool          $useIncludePath
 * @param resource|null $context
 * @param int           $offset
 * @param int|null      $length
 *
 * @return false|string
 *
 * @link https://php.net/manual/en/function.file-get-contents.php
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, phpFileGetContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long offset, length, ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, *offset_param = NULL, *length_param = NULL, __$null, _0$$3, _1$$3, _3, _4, _5;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		context = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		offset_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		length_param = ZEND_CALL_ARG(execute_data, 5);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	if (!offset_param) {
		offset = 0;
	} else {
		}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == (length != 0)) {
		ZVAL_BOOL(&_0$$3, (useIncludePath ? 1 : 0));
		ZVAL_LONG(&_1$$3, offset);
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", &_2, 45, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_3, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_4, offset);
	ZVAL_LONG(&_5, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", &_2, 45, &filename_zv, &_3, context, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string   $filename
 * @param mixed    $data
 * @param int      $flags
 * @param resource $context
 *
 * @return false|int
 *
 * @link https://php.net/manual/en/function.file-put-contents.php
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, phpFilePutContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long flags, ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *data, data_sub, *flags_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		flags_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!flags_param) {
		flags = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, flags);
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 46, &filename_zv, data, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param string        $mode
 * @param bool          $useIncludePath
 * @param resource|null $context
 *
 * @return resource|false
 *
 * @link https://php.net/manual/en/function.fopen.php
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, phpFopen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, mode_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL, *mode = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&mode_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_STR(mode)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	zephir_memory_observe(&mode_zv);
	ZVAL_STR_COPY(&mode_zv, mode);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_BOOL(&_0, (useIncludePath ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 47, &filename_zv, &mode_zv, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Binary-safe file write
 *
 * @link https://php.net/manual/en/function.fwrite.php
 *
 * @param resource $handle
 * @param string   $data
 * @param int|null $length
 *
 * @return false|int
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, phpFwrite)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zend_string *data = NULL;
	zval *handle, handle_sub, data_zv, *length_param = NULL, _0;

	ZVAL_UNDEF(&handle_sub);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(handle)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handle = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		length_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == (length != 0)) {
		zephir_fwrite(return_value, handle, &data_zv);
		RETURN_MM();
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", &_1, 48, handle, &data_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is a directory
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-dir.php
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, phpIsDir)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	ZEPHIR_RETURN_CALL_FUNCTION("is_dir", NULL, 49, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is writable
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-writable.php
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, phpIsWritable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 50, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Makes a directory
 *
 * @param string        $directory
 * @param int           $permissions
 * @param bool          $recursive
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.mkdir.php
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, phpMkdir)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool recursive;
	zend_long permissions, ZEPHIR_LAST_CALL_STATUS;
	zval directory_zv, *permissions_param = NULL, *recursive_param = NULL, *context = NULL, context_sub, __$null, _0, _1;
	zend_string *directory = NULL;

	ZVAL_UNDEF(&directory_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(directory)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(permissions)
		Z_PARAM_BOOL(recursive)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		permissions_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		recursive_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&directory_zv);
	ZVAL_STR_COPY(&directory_zv, directory);
	if (!permissions_param) {
		permissions = 0777;
	} else {
		}
	if (!recursive_param) {
		recursive = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, permissions);
	ZVAL_BOOL(&_1, (recursive ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("mkdir", NULL, 51, &directory_zv, &_0, &_1, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.unlink.php
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, phpUnlink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *context = NULL, context_sub, __$null;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 52, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

