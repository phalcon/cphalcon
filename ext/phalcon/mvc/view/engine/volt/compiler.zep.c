
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "Zend/zend_closures.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "phalcon/mvc/view/engine/volt/scanner.h"
#include "phalcon/mvc/view/engine/volt/volt.h"


/**
 * Phalcon\Mvc\View\Engine\Volt\Compiler
 *
 * This class reads and compiles Volt templates into PHP plain code
 *
 *<code>
 * $compiler = new \Phalcon\Mvc\View\Engine\Volt\Compiler();
 *
 * $compiler->compile("views/partials/header.volt");
 *
 * require $compiler->getCompiledTemplatePath();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Compiler) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\View\\Engine\\Volt, Compiler, phalcon, mvc_view_engine_volt_compiler, phalcon_mvc_view_engine_volt_compiler_method_entry, 0);

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
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, __construct) {

	zval *view = NULL;

	zephir_fetch_params(0, 0, 1, &view);

	if (!view) {
		view = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(view) == IS_OBJECT) {
		zephir_update_property_this(getThis(), SL("_view"), view TSRMLS_CC);
	}

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI) {

	

	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets the compiler options
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions) {

	zval *options_param = NULL;
	zval *options = NULL;

	zephir_fetch_params(0, 1, 0, &options_param);

	options = options_param;


	zephir_update_property_this(getThis(), SL("_options"), options TSRMLS_CC);

}

/**
 * Sets a single compiler option
 *
 * @param string option
 * @param mixed value
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOption) {

	zval *option_param = NULL, *value;
	zval *option = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &option_param, &value);

	if (UNEXPECTED(Z_TYPE_P(option_param) != IS_STRING && Z_TYPE_P(option_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'option' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(option_param) == IS_STRING)) {
		zephir_get_strval(option, option_param);
	} else {
		ZEPHIR_INIT_VAR(option);
		ZVAL_EMPTY_STRING(option);
	}


	zephir_update_property_array(this_ptr, SL("_options"), option, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a compiler's option
 *
 * @param string option
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOption) {

	zval *option_param = NULL, *value = NULL, *_0;
	zval *option = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &option_param);

	if (UNEXPECTED(Z_TYPE_P(option_param) != IS_STRING && Z_TYPE_P(option_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'option' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(option_param) == IS_STRING)) {
		zephir_get_strval(option, option_param);
	} else {
		ZEPHIR_INIT_VAR(option);
		ZVAL_EMPTY_STRING(option);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, option, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETURN_MM_NULL();

}

/**
 * Returns the compiler options
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOptions) {

	

	RETURN_MEMBER(getThis(), "_options");

}

/**
 * Fires an event to registered extensions
 *
 * @param string name
 * @param array arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, fireExtensionEvent) {

	zval *_3$$6 = NULL, *_4$$7 = NULL;
	HashTable *_1$$3;
	HashPosition _0$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *arguments = NULL, *extensions = NULL, *extension = NULL, *status = NULL, **_2$$3;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &arguments);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(extensions);
	zephir_read_property_this(&extensions, this_ptr, SL("_extensions"), PH_NOISY_CC);
	if (Z_TYPE_P(extensions) == IS_ARRAY) {
		zephir_is_iterable(extensions, &_1$$3, &_0$$3, 0, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 189);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(extension, _2$$3);
			if ((zephir_method_exists(extension, name TSRMLS_CC)  == SUCCESS)) {
				if (Z_TYPE_P(arguments) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(_3$$6);
					zephir_create_array(_3$$6, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(_3$$6, extension);
					zephir_array_fast_append(_3$$6, name);
					ZEPHIR_INIT_NVAR(status);
					ZEPHIR_CALL_USER_FUNC_ARRAY(status, _3$$6, arguments);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(_4$$7);
					zephir_create_array(_4$$7, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(_4$$7, extension);
					zephir_array_fast_append(_4$$7, name);
					ZEPHIR_INIT_NVAR(status);
					ZEPHIR_CALL_USER_FUNC(status, _4$$7);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(status) == IS_STRING) {
					RETURN_CCTOR(status);
				}
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Registers a Volt's extension
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addExtension) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *extension;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &extension);



	if (Z_TYPE_P(extension) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "The extension is not valid", "phalcon/mvc/view/engine/volt/compiler.zep", 198);
		return;
	}
	if ((zephir_method_exists_ex(extension, SS("initialize") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, extension, "initialize", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	zephir_update_property_array_append(this_ptr, SL("_extensions"), extension TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the list of extensions registered in Volt
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getExtensions) {

	

	RETURN_MEMBER(getThis(), "_extensions");

}

/**
 * Register a new function in the compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFunction) {

	zval *name_param = NULL, *definition;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_array(this_ptr, SL("_functions"), name, definition TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Register the user registered functions
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFunctions) {

	

	RETURN_MEMBER(getThis(), "_functions");

}

/**
 * Register a new filter in the compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFilter) {

	zval *name_param = NULL, *definition;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_array(this_ptr, SL("_filters"), name, definition TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Register the user registered filters
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFilters) {

	

	RETURN_MEMBER(getThis(), "_filters");

}

/**
 * Set a unique prefix to be used as prefix for compiled variables
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setUniquePrefix) {

	zval *prefix_param = NULL;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	}


	zephir_update_property_this(getThis(), SL("_prefix"), prefix TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Return a unique prefix to be used as prefix for compiled variables and contexts
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getUniquePrefix) {

	zval *_7$$5;
	zval *_0, *_3, *_8, *_1$$3, *_2$$3, *_4$$4, *_5$$5, *_6$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_currentPath"), PH_NOISY_CC);
		zephir_unique_path_key(_1$$3, _2$$3 TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_prefix"), _1$$3 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_this(&_3, this_ptr, SL("_prefix"), PH_NOISY_CC);
	if (Z_TYPE_P(_3) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(_4$$4);
		zephir_read_property_this(&_4$$4, this_ptr, SL("_prefix"), PH_NOISY_CC);
		if (zephir_instance_of_ev(_4$$4, zend_ce_closure TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_5$$5);
			_6$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_7$$5);
			zephir_create_array(_7$$5, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_7$$5, this_ptr);
			ZEPHIR_CALL_USER_FUNC_ARRAY(_5$$5, _6$$5, _7$$5);
			zephir_check_call_status();
			zephir_update_property_this(getThis(), SL("_prefix"), _5$$5 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(_8);
	zephir_read_property_this(&_8, this_ptr, SL("_prefix"), PH_NOISY_CC);
	if (Z_TYPE_P(_8) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "The unique compilation prefix is invalid", "phalcon/mvc/view/engine/volt/compiler.zep", 285);
		return;
	}
	RETURN_MM_MEMBER(getThis(), "_prefix");

}

/**
 * Resolves attribute reading
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, attributeReader) {

	zend_bool _3$$5, _7$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *exprCode = NULL, *left = NULL, *leftType = NULL, *variable = NULL, *level = NULL, *dependencyInjector = NULL, *leftCode = NULL, *right = NULL, *_0, *_8, *_1$$4 = NULL, *_2$$4, *_4$$5 = NULL, *_5$$6, *_6$$7, *_9$$11, *_10$$12 = NULL;
	zval *expr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	expr = expr_param;


	ZEPHIR_INIT_VAR(exprCode);
	ZVAL_NULL(exprCode);
	ZEPHIR_OBS_VAR(left);
	zephir_array_fetch_string(&left, expr, SL("left"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 301 TSRMLS_CC);
	zephir_array_fetch_string(&_0, left, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 303 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(_0, 265)) {
		ZEPHIR_OBS_VAR(variable);
		zephir_array_fetch_string(&variable, left, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 305 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(variable, "loop")) {
			ZEPHIR_OBS_VAR(level);
			zephir_read_property_this(&level, this_ptr, SL("_foreachLevel"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "getuniqueprefix", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_2$$4);
			ZEPHIR_CONCAT_SVVS(_2$$4, "$", _1$$4, level, "loop");
			zephir_concat_self(&exprCode, _2$$4 TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("_loopPointers"), level, level TSRMLS_CC);
		} else {
			ZEPHIR_OBS_VAR(dependencyInjector);
			zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
			_3$$5 = Z_TYPE_P(dependencyInjector) == IS_OBJECT;
			if (_3$$5) {
				ZEPHIR_CALL_METHOD(&_4$$5, dependencyInjector, "has", NULL, 0, variable);
				zephir_check_call_status();
				_3$$5 = zephir_is_true(_4$$5);
			}
			if (_3$$5) {
				ZEPHIR_INIT_VAR(_5$$6);
				ZEPHIR_CONCAT_SV(_5$$6, "$this->", variable);
				zephir_concat_self(&exprCode, _5$$6 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(_6$$7);
				ZEPHIR_CONCAT_SV(_6$$7, "$", variable);
				zephir_concat_self(&exprCode, _6$$7 TSRMLS_CC);
			}
		}
	} else {
		ZEPHIR_CALL_METHOD(&leftCode, this_ptr, "expression", NULL, 413, left);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(leftType);
		zephir_array_fetch_string(&leftType, left, SL("type"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 328 TSRMLS_CC);
		_7$$8 = !ZEPHIR_IS_LONG(leftType, '.');
		if (_7$$8) {
			_7$$8 = !ZEPHIR_IS_LONG(leftType, 350);
		}
		if (_7$$8) {
			zephir_concat_self(&exprCode, leftCode TSRMLS_CC);
		} else {
			zephir_concat_self(&exprCode, leftCode TSRMLS_CC);
		}
	}
	zephir_concat_self_str(&exprCode, SL("->") TSRMLS_CC);
	ZEPHIR_OBS_VAR(right);
	zephir_array_fetch_string(&right, expr, SL("right"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 338 TSRMLS_CC);
	zephir_array_fetch_string(&_8, right, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 340 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(_8, 265)) {
		zephir_array_fetch_string(&_9$$11, right, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 341 TSRMLS_CC);
		zephir_concat_self(&exprCode, _9$$11 TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&_10$$12, this_ptr, "expression", NULL, 413, right);
		zephir_check_call_status();
		zephir_concat_self(&exprCode, _10$$12 TSRMLS_CC);
	}
	RETURN_CCTOR(exprCode);

}

/**
 * Resolves function intermediate code into PHP function calls
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, functionCall) {

	zend_bool _7$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *code = NULL, *funcArguments = NULL, *arguments = NULL, *nameExpr = NULL, *nameType = NULL, *name = NULL, *extensions = NULL, *functions = NULL, *definition = NULL, *extendedBlocks = NULL, *block = NULL, *currentBlock = NULL, *exprLevel = NULL, *escapedCode = NULL, *method = NULL, *arrayHelpers = NULL, *className = NULL, *_9 = NULL, *_1$$6, *_3$$9, *_4$$9, *_5$$9, *_6$$9, *_8$$5;
	zval *expr = NULL, *_0$$6, *_2$$12;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	expr = expr_param;


	ZEPHIR_INIT_VAR(code);
	ZVAL_NULL(code);
	ZEPHIR_INIT_VAR(funcArguments);
	ZVAL_NULL(funcArguments);
	ZEPHIR_OBS_NVAR(funcArguments);
	if (zephir_array_isset_string_fetch(&funcArguments, expr, SS("arguments"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&arguments, this_ptr, "expression", NULL, 413, funcArguments);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(arguments);
		ZVAL_STRING(arguments, "", 1);
	}
	ZEPHIR_OBS_VAR(nameExpr);
	zephir_array_fetch_string(&nameExpr, expr, SL("name"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 368 TSRMLS_CC);
	ZEPHIR_OBS_VAR(nameType);
	zephir_array_fetch_string(&nameType, nameExpr, SL("type"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 368 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(nameType, 265)) {
		ZEPHIR_OBS_VAR(name);
		zephir_array_fetch_string(&name, nameExpr, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 375 TSRMLS_CC);
		ZEPHIR_OBS_VAR(extensions);
		zephir_read_property_this(&extensions, this_ptr, SL("_extensions"), PH_NOISY_CC);
		if (Z_TYPE_P(extensions) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_0$$6);
			zephir_create_array(_0$$6, 3, 0 TSRMLS_CC);
			zephir_array_fast_append(_0$$6, name);
			zephir_array_fast_append(_0$$6, arguments);
			zephir_array_fast_append(_0$$6, funcArguments);
			ZEPHIR_INIT_VAR(_1$$6);
			ZVAL_STRING(_1$$6, "compileFunction", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&code, this_ptr, "fireextensionevent", NULL, 414, _1$$6, _0$$6);
			zephir_check_temp_parameter(_1$$6);
			zephir_check_call_status();
			if (Z_TYPE_P(code) == IS_STRING) {
				RETURN_CCTOR(code);
			}
		}
		ZEPHIR_OBS_VAR(functions);
		zephir_read_property_this(&functions, this_ptr, SL("_functions"), PH_NOISY_CC);
		if (Z_TYPE_P(functions) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(definition);
			if (zephir_array_isset_fetch(&definition, functions, name, 0 TSRMLS_CC)) {
				if (Z_TYPE_P(definition) == IS_STRING) {
					ZEPHIR_CONCAT_VSVS(return_value, definition, "(", arguments, ")");
					RETURN_MM();
				}
				if (Z_TYPE_P(definition) == IS_OBJECT) {
					if (zephir_instance_of_ev(definition, zend_ce_closure TSRMLS_CC)) {
						ZEPHIR_INIT_VAR(_2$$12);
						zephir_create_array(_2$$12, 2, 0 TSRMLS_CC);
						zephir_array_fast_append(_2$$12, arguments);
						zephir_array_fast_append(_2$$12, funcArguments);
						ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, definition, _2$$12);
						zephir_check_call_status();
						RETURN_MM();
					}
				}
				ZEPHIR_INIT_VAR(_3$$9);
				object_init_ex(_3$$9, phalcon_mvc_view_engine_volt_exception_ce);
				zephir_array_fetch_string(&_4$$9, expr, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 417 TSRMLS_CC);
				zephir_array_fetch_string(&_5$$9, expr, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 418 TSRMLS_CC);
				ZEPHIR_INIT_VAR(_6$$9);
				ZEPHIR_CONCAT_SVSVSV(_6$$9, "Invalid definition for user function '", name, "' in ", _4$$9, " on line ", _5$$9);
				ZEPHIR_CALL_METHOD(NULL, _3$$9, "__construct", NULL, 415, _6$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(_3$$9, "phalcon/mvc/view/engine/volt/compiler.zep", 418 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		_7$$5 = ZEPHIR_IS_STRING(name, "get_content");
		if (!(_7$$5)) {
			_7$$5 = ZEPHIR_IS_STRING(name, "content");
		}
		if (_7$$5) {
			RETURN_MM_STRING("$this->getContent()", 1);
		}
		if (ZEPHIR_IS_STRING(name, "partial")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->partial(", arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(name, "super")) {
			ZEPHIR_OBS_VAR(extendedBlocks);
			zephir_read_property_this(&extendedBlocks, this_ptr, SL("_extendedBlocks"), PH_NOISY_CC);
			if (Z_TYPE_P(extendedBlocks) == IS_ARRAY) {
				ZEPHIR_OBS_VAR(currentBlock);
				zephir_read_property_this(&currentBlock, this_ptr, SL("_currentBlock"), PH_NOISY_CC);
				ZEPHIR_OBS_VAR(block);
				if (zephir_array_isset_fetch(&block, extendedBlocks, currentBlock, 0 TSRMLS_CC)) {
					ZEPHIR_OBS_VAR(exprLevel);
					zephir_read_property_this(&exprLevel, this_ptr, SL("_exprLevel"), PH_NOISY_CC);
					if (Z_TYPE_P(block) == IS_ARRAY) {
						ZEPHIR_CALL_METHOD(&code, this_ptr, "_statementlistorextends", NULL, 416, block);
						zephir_check_call_status();
						if (ZEPHIR_IS_LONG(exprLevel, 1)) {
							ZEPHIR_CPY_WRT(escapedCode, code);
						} else {
							ZEPHIR_INIT_NVAR(escapedCode);
							zephir_addslashes(escapedCode, code TSRMLS_CC);
						}
					} else {
						if (ZEPHIR_IS_LONG(exprLevel, 1)) {
							ZEPHIR_CPY_WRT(escapedCode, block);
						} else {
							ZEPHIR_INIT_NVAR(escapedCode);
							zephir_addslashes(escapedCode, block TSRMLS_CC);
						}
					}
					if (ZEPHIR_IS_LONG(exprLevel, 1)) {
						RETURN_CCTOR(escapedCode);
					}
					ZEPHIR_CONCAT_SVS(return_value, "'", escapedCode, "'");
					RETURN_MM();
				}
			}
			RETURN_MM_STRING("''", 1);
		}
		ZEPHIR_INIT_VAR(_8$$5);
		zephir_camelize(_8$$5, name, NULL  );
		ZEPHIR_CALL_FUNCTION(&method, "lcfirst", NULL, 71, _8$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(className);
		ZVAL_STRING(className, "Phalcon\\Tag", 1);
		if ((zephir_method_exists(className, method TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_OBS_VAR(arrayHelpers);
			zephir_read_property_this(&arrayHelpers, this_ptr, SL("_arrayHelpers"), PH_NOISY_CC);
			if (Z_TYPE_P(arrayHelpers) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(arrayHelpers);
				zephir_create_array(arrayHelpers, 27, 0 TSRMLS_CC);
				zephir_array_update_string(&arrayHelpers, SL("check_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("color_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("date_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("date_time_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("date_time_local_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("email_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("file_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("form"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("hidden_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("image"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("image_input"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("link_to"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("month_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("numeric_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("password_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("radio_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("range_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("search_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("select"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("select_static"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("submit_button"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("tel_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("text_area"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("text_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("time_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("url_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("week_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_update_property_this(getThis(), SL("_arrayHelpers"), arrayHelpers TSRMLS_CC);
			}
			if (zephir_array_isset(arrayHelpers, name)) {
				ZEPHIR_CONCAT_SVSVS(return_value, "$this->tag->", method, "([", arguments, "])");
				RETURN_MM();
			}
			ZEPHIR_CONCAT_SVSVS(return_value, "$this->tag->", method, "(", arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(name, "url")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->url->get(", arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(name, "static_url")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->url->getStatic(", arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(name, "date")) {
			ZEPHIR_CONCAT_SVS(return_value, "date(", arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(name, "time")) {
			RETURN_MM_STRING("time()", 1);
		}
		if (ZEPHIR_IS_STRING(name, "dump")) {
			ZEPHIR_CONCAT_SVS(return_value, "var_dump(", arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(name, "version")) {
			RETURN_MM_STRING("Phalcon\\Version::get()", 1);
		}
		if (ZEPHIR_IS_STRING(name, "version_id")) {
			RETURN_MM_STRING("Phalcon\\Version::getId()", 1);
		}
		if (ZEPHIR_IS_STRING(name, "constant")) {
			ZEPHIR_CONCAT_SVS(return_value, "constant(", arguments, ")");
			RETURN_MM();
		}
		ZEPHIR_CONCAT_SVSVS(return_value, "$this->callMacro('", name, "', [", arguments, "])");
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "expression", NULL, 413, nameExpr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVS(return_value, _9, "(", arguments, ")");
	RETURN_MM();

}

/**
 * Resolves filter intermediate code into a valid PHP expression
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveTest) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *left = NULL;
	zval *test_param = NULL, *left_param = NULL, *type = NULL, *name = NULL, *testName = NULL, *_6 = NULL, *_0$$12 = NULL, *_1$$12, *_2$$13 = NULL, *_3$$13, *_4$$14 = NULL, *_5$$14;
	zval *test = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &test_param, &left_param);

	test = test_param;
	zephir_get_strval(left, left_param);


	ZEPHIR_OBS_VAR(type);
	zephir_array_fetch_string(&type, test, SL("type"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 579 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(type, 265)) {
		ZEPHIR_OBS_VAR(name);
		zephir_array_fetch_string(&name, test, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 586 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(name, "empty")) {
			ZEPHIR_CONCAT_SVS(return_value, "empty(", left, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(name, "even")) {
			ZEPHIR_CONCAT_SVS(return_value, "(((", left, ") % 2) == 0)");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(name, "odd")) {
			ZEPHIR_CONCAT_SVS(return_value, "(((", left, ") % 2) != 0)");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(name, "numeric")) {
			ZEPHIR_CONCAT_SVS(return_value, "is_numeric(", left, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(name, "scalar")) {
			ZEPHIR_CONCAT_SVS(return_value, "is_scalar(", left, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(name, "iterable")) {
			ZEPHIR_CONCAT_SVSVS(return_value, "(is_array(", left, ") || (", left, ") instanceof Traversable)");
			RETURN_MM();
		}
	}
	if (ZEPHIR_IS_LONG(type, 350)) {
		ZEPHIR_OBS_VAR(testName);
		zephir_array_fetch_string(&testName, test, SL("name"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 637 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(name);
		if (zephir_array_isset_string_fetch(&name, testName, SS("value"), 0 TSRMLS_CC)) {
			if (ZEPHIR_IS_STRING(name, "divisibleby")) {
				zephir_array_fetch_string(&_1$$12, test, SL("arguments"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 641 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_0$$12, this_ptr, "expression", NULL, 413, _1$$12);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVSVS(return_value, "(((", left, ") % (", _0$$12, ")) == 0)");
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(name, "sameas")) {
				zephir_array_fetch_string(&_3$$13, test, SL("arguments"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 648 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_2$$13, this_ptr, "expression", NULL, 413, _3$$13);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVSVS(return_value, "(", left, ") === (", _2$$13, ")");
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(name, "type")) {
				zephir_array_fetch_string(&_5$$14, test, SL("arguments"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 655 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_4$$14, this_ptr, "expression", NULL, 413, _5$$14);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVSVS(return_value, "gettype(", left, ") === (", _4$$14, ")");
				RETURN_MM();
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "expression", NULL, 413, test);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, left, " == ", _6);
	RETURN_MM();

}

/**
 * Resolves filter intermediate code into PHP function calls
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveFilter) {

	zend_bool _13, _14, _15;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *left = NULL;
	zval *filter_param = NULL, *left_param = NULL, *code = NULL, *type = NULL, *functionName = NULL, *name = NULL, *file = NULL, *line = NULL, *extensions = NULL, *filters = NULL, *funcArguments = NULL, *arguments = NULL, *definition = NULL, *_16, *_17, *_18, *_19, *_0$$5, *_1$$5, *_2$$5, *_3$$5, *_7$$9, *_9$$12, *_10$$12, *_11$$12, *_12$$12;
	zval *filter = NULL, *_4$$7, *_5$$7, *_6$$9, *_8$$15;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &filter_param, &left_param);

	filter = filter_param;
	zephir_get_strval(left, left_param);


	ZEPHIR_INIT_VAR(code);
	ZVAL_NULL(code);
	ZEPHIR_OBS_VAR(type);
	zephir_array_fetch_string(&type, filter, SL("type"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 674 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(type, 265)) {
		ZEPHIR_OBS_VAR(name);
		zephir_array_fetch_string(&name, filter, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 680 TSRMLS_CC);
	} else {
		if (!ZEPHIR_IS_LONG(type, 350)) {
			ZEPHIR_INIT_VAR(_0$$5);
			object_init_ex(_0$$5, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_1$$5, filter, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 688 TSRMLS_CC);
			zephir_array_fetch_string(&_2$$5, filter, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 688 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_3$$5);
			ZEPHIR_CONCAT_SVSV(_3$$5, "Unknown filter type in ", _1$$5, " on line ", _2$$5);
			ZEPHIR_CALL_METHOD(NULL, _0$$5, "__construct", NULL, 415, _3$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_0$$5, "phalcon/mvc/view/engine/volt/compiler.zep", 688 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(functionName);
		zephir_array_fetch_string(&functionName, filter, SL("name"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 691 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(name);
		zephir_array_fetch_string(&name, functionName, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 692 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(funcArguments);
	ZVAL_NULL(funcArguments);
	ZEPHIR_INIT_VAR(arguments);
	ZVAL_NULL(arguments);
	ZEPHIR_OBS_NVAR(funcArguments);
	if (zephir_array_isset_string_fetch(&funcArguments, filter, SS("arguments"), 0 TSRMLS_CC)) {
		if (!ZEPHIR_IS_STRING(name, "default")) {
			ZEPHIR_OBS_VAR(file);
			zephir_array_fetch_string(&file, filter, SL("file"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 707 TSRMLS_CC);
			ZEPHIR_OBS_VAR(line);
			zephir_array_fetch_string(&line, filter, SL("line"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 707 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_4$$7);
			zephir_create_array(_4$$7, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_5$$7);
			zephir_create_array(_5$$7, 4, 0 TSRMLS_CC);
			add_assoc_long_ex(_5$$7, SS("type"), 364);
			zephir_array_update_string(&_5$$7, SL("value"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_5$$7, SL("file"), &file, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_5$$7, SL("line"), &line, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4$$7, SL("expr"), &_5$$7, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4$$7, SL("file"), &file, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4$$7, SL("line"), &line, PH_COPY | PH_SEPARATE);
			ZEPHIR_MAKE_REF(funcArguments);
			ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 417, funcArguments, _4$$7);
			ZEPHIR_UNREF(funcArguments);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&arguments, this_ptr, "expression", NULL, 413, funcArguments);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(arguments, left);
	}
	ZEPHIR_OBS_VAR(extensions);
	zephir_read_property_this(&extensions, this_ptr, SL("_extensions"), PH_NOISY_CC);
	if (Z_TYPE_P(extensions) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_6$$9);
		zephir_create_array(_6$$9, 3, 0 TSRMLS_CC);
		zephir_array_fast_append(_6$$9, name);
		zephir_array_fast_append(_6$$9, arguments);
		zephir_array_fast_append(_6$$9, funcArguments);
		ZEPHIR_INIT_VAR(_7$$9);
		ZVAL_STRING(_7$$9, "compileFilter", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&code, this_ptr, "fireextensionevent", NULL, 414, _7$$9, _6$$9);
		zephir_check_temp_parameter(_7$$9);
		zephir_check_call_status();
		if (Z_TYPE_P(code) == IS_STRING) {
			RETURN_CCTOR(code);
		}
	}
	ZEPHIR_OBS_VAR(filters);
	zephir_read_property_this(&filters, this_ptr, SL("_filters"), PH_NOISY_CC);
	if (Z_TYPE_P(filters) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(definition);
		if (zephir_array_isset_fetch(&definition, filters, name, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(definition) == IS_STRING) {
				ZEPHIR_CONCAT_VSVS(return_value, definition, "(", arguments, ")");
				RETURN_MM();
			}
			if (Z_TYPE_P(definition) == IS_OBJECT) {
				if (zephir_instance_of_ev(definition, zend_ce_closure TSRMLS_CC)) {
					ZEPHIR_INIT_VAR(_8$$15);
					zephir_create_array(_8$$15, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(_8$$15, arguments);
					zephir_array_fast_append(_8$$15, funcArguments);
					ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, definition, _8$$15);
					zephir_check_call_status();
					RETURN_MM();
				}
			}
			ZEPHIR_INIT_VAR(_9$$12);
			object_init_ex(_9$$12, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_10$$12, filter, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 771 TSRMLS_CC);
			zephir_array_fetch_string(&_11$$12, filter, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 772 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_12$$12);
			ZEPHIR_CONCAT_SVSVSV(_12$$12, "Invalid definition for user filter '", name, "' in ", _10$$12, " on line ", _11$$12);
			ZEPHIR_CALL_METHOD(NULL, _9$$12, "__construct", NULL, 415, _12$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9$$12, "phalcon/mvc/view/engine/volt/compiler.zep", 772 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (ZEPHIR_IS_STRING(name, "length")) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->length(", arguments, ")");
		RETURN_MM();
	}
	_13 = ZEPHIR_IS_STRING(name, "e");
	if (!(_13)) {
		_13 = ZEPHIR_IS_STRING(name, "escape");
	}
	if (_13) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->escaper->escapeHtml(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "escape_css")) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->escaper->escapeCss(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "escape_js")) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->escaper->escapeJs(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "escape_attr")) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->escaper->escapeHtmlAttr(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "trim")) {
		ZEPHIR_CONCAT_SVS(return_value, "trim(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "left_trim")) {
		ZEPHIR_CONCAT_SVS(return_value, "ltrim(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "right_trim")) {
		ZEPHIR_CONCAT_SVS(return_value, "rtrim(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "striptags")) {
		ZEPHIR_CONCAT_SVS(return_value, "strip_tags(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "url_encode")) {
		ZEPHIR_CONCAT_SVS(return_value, "urlencode(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "slashes")) {
		ZEPHIR_CONCAT_SVS(return_value, "addslashes(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "stripslashes")) {
		ZEPHIR_CONCAT_SVS(return_value, "stripslashes(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "nl2br")) {
		ZEPHIR_CONCAT_SVS(return_value, "nl2br(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "keys")) {
		ZEPHIR_CONCAT_SVS(return_value, "array_keys(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "join")) {
		ZEPHIR_CONCAT_SVS(return_value, "join(", arguments, ")");
		RETURN_MM();
	}
	_14 = ZEPHIR_IS_STRING(name, "lower");
	if (!(_14)) {
		_14 = ZEPHIR_IS_STRING(name, "lowercase");
	}
	if (_14) {
		ZEPHIR_CONCAT_SVS(return_value, "Phalcon\\Text::lower(", arguments, ")");
		RETURN_MM();
	}
	_15 = ZEPHIR_IS_STRING(name, "upper");
	if (!(_15)) {
		_15 = ZEPHIR_IS_STRING(name, "uppercase");
	}
	if (_15) {
		ZEPHIR_CONCAT_SVS(return_value, "Phalcon\\Text::upper(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "capitalize")) {
		ZEPHIR_CONCAT_SVS(return_value, "ucwords(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "sort")) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->sort(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "json_encode")) {
		ZEPHIR_CONCAT_SVS(return_value, "json_encode(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "json_decode")) {
		ZEPHIR_CONCAT_SVS(return_value, "json_decode(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "format")) {
		ZEPHIR_CONCAT_SVS(return_value, "sprintf(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "abs")) {
		ZEPHIR_CONCAT_SVS(return_value, "abs(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "slice")) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->slice(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "default")) {
		ZEPHIR_CONCAT_SVSVSVS(return_value, "(empty(", left, ") ? (", arguments, ") : (", left, "))");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "convert_encoding")) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->convertEncoding(", arguments, ")");
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_16);
	object_init_ex(_16, phalcon_mvc_view_engine_volt_exception_ce);
	zephir_array_fetch_string(&_17, filter, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 961 TSRMLS_CC);
	zephir_array_fetch_string(&_18, filter, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 961 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_19);
	ZEPHIR_CONCAT_SVSVSV(_19, "Unknown filter \"", name, "\" in ", _17, " on line ", _18);
	ZEPHIR_CALL_METHOD(NULL, _16, "__construct", NULL, 415, _19);
	zephir_check_call_status();
	zephir_throw_exception_debug(_16, "phalcon/mvc/view/engine/volt/compiler.zep", 961 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Resolves an expression node in an AST volt tree
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, expression) {

	HashTable *_4$$6;
	HashPosition _3$$6;
	zephir_fcall_cache_entry *_2 = NULL, *_7 = NULL, *_9 = NULL, *_11 = NULL, *_13 = NULL, *_19 = NULL, *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *exprCode = NULL, *extensions = NULL, *items = NULL, *singleExpr = NULL, *singleExprCode = NULL, *name = NULL, *left = NULL, *leftCode = NULL, *right = NULL, *rightCode = NULL, *type = NULL, *startCode = NULL, *endCode = NULL, *start = NULL, *end = NULL, *_1$$4 = NULL, **_5$$6, *_6$$7, *_8$$8 = NULL, *_10$$12, *_12$$13, *_14$$31 = NULL, *_15$$31, _16$$31 = zval_used_for_init, _17$$31 = zval_used_for_init, *_18$$35, *_20$$69 = NULL, *_21$$69, *_22$$73 = NULL, *_23$$73, *_24$$73, *_25$$73 = NULL;
	zval *expr = NULL, *_0$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	expr = expr_param;


	ZEPHIR_INIT_VAR(exprCode);
	ZVAL_NULL(exprCode);
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_exprLevel") TSRMLS_CC));
	ZEPHIR_OBS_VAR(extensions);
	zephir_read_property_this(&extensions, this_ptr, SL("_extensions"), PH_NOISY_CC);
	while (1) {
		if (Z_TYPE_P(extensions) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_0$$4);
			zephir_create_array(_0$$4, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_0$$4, expr);
			ZEPHIR_INIT_NVAR(_1$$4);
			ZVAL_STRING(_1$$4, "resolveExpression", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "fireextensionevent", &_2, 414, _1$$4, _0$$4);
			zephir_check_temp_parameter(_1$$4);
			zephir_check_call_status();
			if (Z_TYPE_P(exprCode) == IS_STRING) {
				break;
			}
		}
		ZEPHIR_OBS_NVAR(type);
		if (!(zephir_array_isset_string_fetch(&type, expr, SS("type"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(items);
			array_init(items);
			zephir_is_iterable(expr, &_4$$6, &_3$$6, 0, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 1002);
			for (
			  ; zend_hash_get_current_data_ex(_4$$6, (void**) &_5$$6, &_3$$6) == SUCCESS
			  ; zend_hash_move_forward_ex(_4$$6, &_3$$6)
			) {
				ZEPHIR_GET_HVALUE(singleExpr, _5$$6);
				zephir_array_fetch_string(&_6$$7, singleExpr, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 995 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&singleExprCode, this_ptr, "expression", &_7, 413, _6$$7);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(name);
				if (zephir_array_isset_string_fetch(&name, singleExpr, SS("name"), 0 TSRMLS_CC)) {
					ZEPHIR_INIT_LNVAR(_8$$8);
					ZEPHIR_CONCAT_SVSV(_8$$8, "'", name, "' => ", singleExprCode);
					zephir_array_append(&items, _8$$8, PH_SEPARATE, "phalcon/mvc/view/engine/volt/compiler.zep", 997);
				} else {
					zephir_array_append(&items, singleExprCode, PH_SEPARATE, "phalcon/mvc/view/engine/volt/compiler.zep", 999);
				}
			}
			ZEPHIR_INIT_NVAR(exprCode);
			zephir_fast_join_str(exprCode, SL(", "), items TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(type, '.')) {
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "attributereader", &_9, 0, expr);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_OBS_NVAR(left);
		if (zephir_array_isset_string_fetch(&left, expr, SS("left"), 0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&leftCode, this_ptr, "expression", &_7, 413, left);
			zephir_check_call_status();
		}
		if (ZEPHIR_IS_LONG(type, 311)) {
			zephir_array_fetch_string(&_10$$12, expr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1025 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "resolvetest", &_11, 0, _10$$12, leftCode);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(type, 124)) {
			zephir_array_fetch_string(&_12$$13, expr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1033 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "resolvefilter", &_13, 418, _12$$13, leftCode);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_OBS_NVAR(right);
		if (zephir_array_isset_string_fetch(&right, expr, SS("right"), 0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&rightCode, this_ptr, "expression", &_7, 413, right);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(exprCode);
		ZVAL_NULL(exprCode);
		do {
			if (ZEPHIR_IS_LONG(type, '!')) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SV(exprCode, "!", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, '*')) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " * ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, '+')) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " + ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, '-')) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " - ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, '/')) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " / ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 37)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " % ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, '<')) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " < ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 61)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " > ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 62)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " > ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 126)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " . ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 278)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVSVS(exprCode, "pow(", leftCode, ", ", rightCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 360)) {
				ZEPHIR_INIT_NVAR(exprCode);
				if (zephir_array_isset_string(expr, SS("left"))) {
					ZEPHIR_CONCAT_SVS(exprCode, "[", leftCode, "]");
				} else {
					ZVAL_STRING(exprCode, "[]", 1);
				}
				break;
			}
			if (ZEPHIR_IS_LONG(type, 258)) {
				ZEPHIR_OBS_NVAR(exprCode);
				zephir_array_fetch_string(&exprCode, expr, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1100 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 259)) {
				ZEPHIR_OBS_NVAR(exprCode);
				zephir_array_fetch_string(&exprCode, expr, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1104 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 260)) {
				ZEPHIR_INIT_NVAR(_14$$31);
				zephir_array_fetch_string(&_15$$31, expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1108 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_16$$31);
				ZVAL_STRING(&_16$$31, "'", 0);
				ZEPHIR_SINIT_NVAR(_17$$31);
				ZVAL_STRING(&_17$$31, "\\'", 0);
				zephir_fast_str_replace(&_14$$31, &_16$$31, &_17$$31, _15$$31 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVS(exprCode, "'", _14$$31, "'");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 261)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZVAL_STRING(exprCode, "null", 1);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 262)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZVAL_STRING(exprCode, "false", 1);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 263)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZVAL_STRING(exprCode, "true", 1);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 265)) {
				zephir_array_fetch_string(&_18$$35, expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1124 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SV(exprCode, "$", _18$$35);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 266)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " && ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 267)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " || ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 270)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " <= ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 271)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " >= ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 272)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " == ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 273)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " != ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 274)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " === ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 275)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " !== ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 276)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVSVS(exprCode, "range(", leftCode, ", ", rightCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 350)) {
				ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "functioncall", &_19, 0, expr);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(type, 356)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVS(exprCode, "(", leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 361)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSVS(exprCode, leftCode, "[", rightCode, "]");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 365)) {
				ZEPHIR_OBS_NVAR(start);
				if (zephir_array_isset_string_fetch(&start, expr, SS("start"), 0 TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&startCode, this_ptr, "expression", &_7, 413, start);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(startCode);
					ZVAL_STRING(startCode, "null", 1);
				}
				ZEPHIR_OBS_NVAR(end);
				if (zephir_array_isset_string_fetch(&end, expr, SS("end"), 0 TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&endCode, this_ptr, "expression", &_7, 413, end);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(endCode);
					ZVAL_STRING(endCode, "null", 1);
				}
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVSVSVS(exprCode, "$this->slice(", leftCode, ", ", startCode, ", ", endCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 362)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVS(exprCode, "!isset(", leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 363)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVS(exprCode, "isset(", leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 392)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVS(exprCode, "!empty(", leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 386)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVS(exprCode, "empty(", leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 393)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVS(exprCode, "!(((", leftCode, ") % 2) == 0)");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 387)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVS(exprCode, "(((", leftCode, ") % 2) == 0)");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 394)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVS(exprCode, "!(((", leftCode, ") % 2) != 0)");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 388)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVS(exprCode, "(((", leftCode, ") % 2) != 0)");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 395)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVS(exprCode, "!is_numeric(", leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 389)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVS(exprCode, "is_numeric(", leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 396)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVS(exprCode, "!is_scalar(", leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 390)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVS(exprCode, "is_scalar(", leftCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 397)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVSVS(exprCode, "!(is_array(", leftCode, ") || (", leftCode, ") instanceof Traversable)");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 391)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVSVS(exprCode, "(is_array(", leftCode, ") || (", leftCode, ") instanceof Traversable)");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 309)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVSVS(exprCode, "$this->isIncluded(", leftCode, ", ", rightCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 367)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVSVS(exprCode, "!$this->isIncluded(", leftCode, ", ", rightCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 366)) {
				zephir_array_fetch_string(&_21$$69, expr, SL("ternary"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1263 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_20$$69, this_ptr, "expression", &_7, 413, _21$$69);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVSVSVS(exprCode, "(", _20$$69, " ? ", leftCode, " : ", rightCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 368)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SV(exprCode, "-", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 369)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SV(exprCode, "+", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 364)) {
				ZEPHIR_OBS_NVAR(exprCode);
				zephir_array_fetch_string(&exprCode, expr, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1275 TSRMLS_CC);
				break;
			}
			ZEPHIR_INIT_NVAR(_22$$73);
			object_init_ex(_22$$73, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_23$$73, expr, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1279 TSRMLS_CC);
			zephir_array_fetch_string(&_24$$73, expr, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1279 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_25$$73);
			ZEPHIR_CONCAT_SVSVSV(_25$$73, "Unknown expression ", type, " in ", _23$$73, " on line ", _24$$73);
			ZEPHIR_CALL_METHOD(NULL, _22$$73, "__construct", &_26, 415, _25$$73);
			zephir_check_call_status();
			zephir_throw_exception_debug(_22$$73, "phalcon/mvc/view/engine/volt/compiler.zep", 1279 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

		break;
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_exprLevel") TSRMLS_CC));
	RETURN_CCTOR(exprCode);

}

/**
 * Compiles a block of statements
 *
 * @param array statements
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementListOrExtends) {

	HashTable *_1$$4;
	HashPosition _0$$4;
	zend_bool isStatementList = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statements, *statement = NULL, **_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statements);



	if (Z_TYPE_P(statements) != IS_ARRAY) {
		RETVAL_ZVAL(statements, 1, 0);
		RETURN_MM();
	}
	isStatementList = 1;
	if (!(zephir_array_isset_string(statements, SS("type")))) {
		zephir_is_iterable(statements, &_1$$4, &_0$$4, 0, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 1319);
		for (
		  ; zend_hash_get_current_data_ex(_1$$4, (void**) &_2$$4, &_0$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$4, &_0$$4)
		) {
			ZEPHIR_GET_HVALUE(statement, _2$$4);
			if (Z_TYPE_P(statement) != IS_ARRAY) {
				isStatementList = 0;
				break;
			}
		}
	}
	if (isStatementList == 1) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_statementlist", NULL, 419, statements);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(statements, 1, 0);
	RETURN_MM();

}

/**
 * Compiles a "foreach" intermediate code representation into plain PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForeach) {

	HashTable *_1$$4;
	HashPosition _0$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, *compilation = NULL, *prefix = NULL, *level = NULL, *prefixLevel = NULL, *expr = NULL, *exprCode = NULL, *bstatement = NULL, *type = NULL, *blockStatements = NULL, *forElse = NULL, *code = NULL, *loopContext = NULL, *iterator = NULL, *key = NULL, *ifExpr = NULL, *variable = NULL, *_4, **_2$$4, *_3$$8 = NULL, *_5$$9, *_6$$9, *_7$$9, *_8$$9, *_9$$9, *_10$$9, *_11$$9, *_12$$9, *_13$$9, *_14$$11, *_15$$12, *_16$$13 = NULL, *_17$$13, *_18$$15, *_19$$15, *_20$$15, *_21$$15, *_22$$15, *_23$$15, *_24$$16, *_25$$20;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &extendsMode_param);

	statement = statement_param;
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	if (!(zephir_array_isset_string(statement, SS("expr")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1347);
		return;
	}
	ZEPHIR_INIT_VAR(compilation);
	ZVAL_STRING(compilation, "", 1);
	ZEPHIR_INIT_VAR(forElse);
	ZVAL_NULL(forElse);
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_foreachLevel") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(&prefix, this_ptr, "getuniqueprefix", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(level);
	zephir_read_property_this(&level, this_ptr, SL("_foreachLevel"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixLevel);
	ZEPHIR_CONCAT_VV(prefixLevel, prefix, level);
	ZEPHIR_OBS_VAR(expr);
	zephir_array_fetch_string(&expr, statement, SL("expr"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1365 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", NULL, 413, expr);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(blockStatements);
	zephir_array_fetch_string(&blockStatements, statement, SL("block_statements"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1371 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(forElse);
	ZVAL_BOOL(forElse, 0);
	if (Z_TYPE_P(blockStatements) == IS_ARRAY) {
		zephir_is_iterable(blockStatements, &_1$$4, &_0$$4, 0, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 1397);
		for (
		  ; zend_hash_get_current_data_ex(_1$$4, (void**) &_2$$4, &_0$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$4, &_0$$4)
		) {
			ZEPHIR_GET_HVALUE(bstatement, _2$$4);
			if (Z_TYPE_P(bstatement) != IS_ARRAY) {
				break;
			}
			ZEPHIR_OBS_NVAR(type);
			if (!(zephir_array_isset_string_fetch(&type, bstatement, SS("type"), 0 TSRMLS_CC))) {
				break;
			}
			if (ZEPHIR_IS_LONG(type, 321)) {
				ZEPHIR_INIT_LNVAR(_3$$8);
				ZEPHIR_CONCAT_SVS(_3$$8, "<?php $", prefixLevel, "iterated = false; ?>");
				zephir_concat_self(&compilation, _3$$8 TSRMLS_CC);
				ZEPHIR_CPY_WRT(forElse, prefixLevel);
				zephir_update_property_array(this_ptr, SL("_forElsePointers"), level, forElse TSRMLS_CC);
				break;
			}
		}
	}
	ZEPHIR_INIT_VAR(_4);
	if (extendsMode) {
		ZVAL_BOOL(_4, 1);
	} else {
		ZVAL_BOOL(_4, 0);
	}
	ZEPHIR_CALL_METHOD(&code, this_ptr, "_statementlist", NULL, 419, blockStatements, _4);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(loopContext);
	zephir_read_property_this(&loopContext, this_ptr, SL("_loopPointers"), PH_NOISY_CC);
	if (zephir_array_isset(loopContext, level)) {
		ZEPHIR_INIT_VAR(_5$$9);
		ZEPHIR_CONCAT_SVSVS(_5$$9, "<?php $", prefixLevel, "iterator = ", exprCode, "; ");
		zephir_concat_self(&compilation, _5$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6$$9);
		ZEPHIR_CONCAT_SVS(_6$$9, "$", prefixLevel, "incr = 0; ");
		zephir_concat_self(&compilation, _6$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7$$9);
		ZEPHIR_CONCAT_SVS(_7$$9, "$", prefixLevel, "loop = new stdClass(); ");
		zephir_concat_self(&compilation, _7$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_8$$9);
		ZEPHIR_CONCAT_SVSVS(_8$$9, "$", prefixLevel, "loop->self = &$", prefixLevel, "loop; ");
		zephir_concat_self(&compilation, _8$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_9$$9);
		ZEPHIR_CONCAT_SVSVS(_9$$9, "$", prefixLevel, "loop->length = count($", prefixLevel, "iterator); ");
		zephir_concat_self(&compilation, _9$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_10$$9);
		ZEPHIR_CONCAT_SVS(_10$$9, "$", prefixLevel, "loop->index = 1; ");
		zephir_concat_self(&compilation, _10$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_11$$9);
		ZEPHIR_CONCAT_SVS(_11$$9, "$", prefixLevel, "loop->index0 = 1; ");
		zephir_concat_self(&compilation, _11$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_12$$9);
		ZEPHIR_CONCAT_SVSVS(_12$$9, "$", prefixLevel, "loop->revindex = $", prefixLevel, "loop->length; ");
		zephir_concat_self(&compilation, _12$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_13$$9);
		ZEPHIR_CONCAT_SVSVS(_13$$9, "$", prefixLevel, "loop->revindex0 = $", prefixLevel, "loop->length - 1; ?>");
		zephir_concat_self(&compilation, _13$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(iterator);
		ZEPHIR_CONCAT_SVS(iterator, "$", prefixLevel, "iterator");
	} else {
		ZEPHIR_CPY_WRT(iterator, exprCode);
	}
	ZEPHIR_OBS_VAR(variable);
	zephir_array_fetch_string(&variable, statement, SL("variable"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1427 TSRMLS_CC);
	ZEPHIR_OBS_VAR(key);
	if (zephir_array_isset_string_fetch(&key, statement, SS("key"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_14$$11);
		ZEPHIR_CONCAT_SVSVSVS(_14$$11, "<?php foreach (", iterator, " as $", key, " => $", variable, ") { ");
		zephir_concat_self(&compilation, _14$$11 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_15$$12);
		ZEPHIR_CONCAT_SVSVS(_15$$12, "<?php foreach (", iterator, " as $", variable, ") { ");
		zephir_concat_self(&compilation, _15$$12 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(ifExpr);
	if (zephir_array_isset_string_fetch(&ifExpr, statement, SS("if_expr"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_16$$13, this_ptr, "expression", NULL, 413, ifExpr);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_17$$13);
		ZEPHIR_CONCAT_SVS(_17$$13, "if (", _16$$13, ") { ?>");
		zephir_concat_self(&compilation, _17$$13 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&compilation, SL("?>") TSRMLS_CC);
	}
	if (zephir_array_isset(loopContext, level)) {
		ZEPHIR_INIT_VAR(_18$$15);
		ZEPHIR_CONCAT_SVSVS(_18$$15, "<?php $", prefixLevel, "loop->first = ($", prefixLevel, "incr == 0); ");
		zephir_concat_self(&compilation, _18$$15 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_19$$15);
		ZEPHIR_CONCAT_SVSVS(_19$$15, "$", prefixLevel, "loop->index = $", prefixLevel, "incr + 1; ");
		zephir_concat_self(&compilation, _19$$15 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_20$$15);
		ZEPHIR_CONCAT_SVSVS(_20$$15, "$", prefixLevel, "loop->index0 = $", prefixLevel, "incr; ");
		zephir_concat_self(&compilation, _20$$15 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_21$$15);
		ZEPHIR_CONCAT_SVSVSVS(_21$$15, "$", prefixLevel, "loop->revindex = $", prefixLevel, "loop->length - $", prefixLevel, "incr; ");
		zephir_concat_self(&compilation, _21$$15 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_22$$15);
		ZEPHIR_CONCAT_SVSVSVS(_22$$15, "$", prefixLevel, "loop->revindex0 = $", prefixLevel, "loop->length - ($", prefixLevel, "incr + 1); ");
		zephir_concat_self(&compilation, _22$$15 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_23$$15);
		ZEPHIR_CONCAT_SVSVSVS(_23$$15, "$", prefixLevel, "loop->last = ($", prefixLevel, "incr == ($", prefixLevel, "loop->length - 1)); ?>");
		zephir_concat_self(&compilation, _23$$15 TSRMLS_CC);
	}
	if (Z_TYPE_P(forElse) == IS_STRING) {
		ZEPHIR_INIT_VAR(_24$$16);
		ZEPHIR_CONCAT_SVS(_24$$16, "<?php $", forElse, "iterated = true; ?>");
		zephir_concat_self(&compilation, _24$$16 TSRMLS_CC);
	}
	zephir_concat_self(&compilation, code TSRMLS_CC);
	if (zephir_array_isset_string(statement, SS("if_expr"))) {
		zephir_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
	}
	if (Z_TYPE_P(forElse) == IS_STRING) {
		zephir_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
	} else {
		if (zephir_array_isset(loopContext, level)) {
			ZEPHIR_INIT_VAR(_25$$20);
			ZEPHIR_CONCAT_SVS(_25$$20, "<?php $", prefixLevel, "incr++; } ?>");
			zephir_concat_self(&compilation, _25$$20 TSRMLS_CC);
		} else {
			zephir_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
		}
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_foreachLevel") TSRMLS_CC));
	RETURN_CCTOR(compilation);

}

/**
 * Generates a 'forelse' PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForElse) {

	zval *level = NULL, *prefix = NULL, *_0, *_1$$3;


	level = zephir_fetch_nproperty_this(this_ptr, SL("_foreachLevel"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_forElsePointers"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&prefix, _0, level, 1 TSRMLS_CC)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_loopPointers"), PH_NOISY_CC);
		if (zephir_array_isset(_1$$3, level)) {
			ZEPHIR_CONCAT_SVSVS(return_value, "<?php $", prefix, "incr++; } if (!$", prefix, "iterated) { ?>");
			return;
		}
		ZEPHIR_CONCAT_SVS(return_value, "<?php } if (!$", prefix, "iterated) { ?>");
		return;
	}
	RETURN_STRING("", 1);

}

/**
 * Compiles a 'if' statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileIf) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, *compilation = NULL, *blockStatements = NULL, *expr = NULL, *_2 = NULL, *_3 = NULL, *_4, *_5, *_0$$3, *_1$$3, *_6$$4 = NULL, *_7$$4, *_8$$4;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &extendsMode_param);

	statement = statement_param;
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	ZEPHIR_OBS_VAR(expr);
	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "Corrupt statement", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 415, _1$$3, statement);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "phalcon/mvc/view/engine/volt/compiler.zep", 1518 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 413, expr);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, statement, SL("true_statements"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1524 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	if (extendsMode) {
		ZVAL_BOOL(_5, 1);
	} else {
		ZVAL_BOOL(_5, 0);
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "_statementlist", NULL, 419, _4, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(compilation);
	ZEPHIR_CONCAT_SVSV(compilation, "<?php if (", _2, ") { ?>", _3);
	ZEPHIR_OBS_VAR(blockStatements);
	if (zephir_array_isset_string_fetch(&blockStatements, statement, SS("false_statements"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_7$$4);
		if (extendsMode) {
			ZVAL_BOOL(_7$$4, 1);
		} else {
			ZVAL_BOOL(_7$$4, 0);
		}
		ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "_statementlist", NULL, 419, blockStatements, _7$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_8$$4);
		ZEPHIR_CONCAT_SV(_8$$4, "<?php } else { ?>", _6$$4);
		zephir_concat_self(&compilation, _8$$4 TSRMLS_CC);
	}
	zephir_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
	RETURN_CCTOR(compilation);

}

/**
 * Compiles a 'switch' statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSwitch) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, *compilation = NULL, *caseClauses = NULL, *expr = NULL, *lines = NULL, *_2 = NULL, *_0$$3, *_1$$3, *_3$$4, *_4$$5, *_5$$5, *_6$$5 = NULL;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &extendsMode_param);

	statement = statement_param;
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	ZEPHIR_OBS_VAR(expr);
	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "Corrupt statement", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 415, _1$$3, statement);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "phalcon/mvc/view/engine/volt/compiler.zep", 1553 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 413, expr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(compilation);
	ZEPHIR_CONCAT_SVS(compilation, "<?php switch (", _2, "): ?>");
	ZEPHIR_OBS_VAR(caseClauses);
	if (zephir_array_isset_string_fetch(&caseClauses, statement, SS("case_clauses"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_3$$4);
		if (extendsMode) {
			ZVAL_BOOL(_3$$4, 1);
		} else {
			ZVAL_BOOL(_3$$4, 0);
		}
		ZEPHIR_CALL_METHOD(&lines, this_ptr, "_statementlist", NULL, 419, caseClauses, _3$$4);
		zephir_check_call_status();
		if (zephir_fast_strlen_ev(lines) != 0) {
			ZEPHIR_INIT_VAR(_4$$5);
			ZVAL_STRING(_4$$5, "/(*ANYCRLF)^\\h+|\\h+$|(\\h){2,}/mu", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_5$$5);
			ZVAL_STRING(_5$$5, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&_6$$5, "preg_replace", NULL, 42, _4$$5, _5$$5, lines);
			zephir_check_temp_parameter(_4$$5);
			zephir_check_temp_parameter(_5$$5);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(lines, _6$$5);
		}
		zephir_concat_self(&compilation, lines TSRMLS_CC);
	}
	zephir_concat_self_str(&compilation, SL("<?php endswitch ?>") TSRMLS_CC);
	RETURN_CCTOR(compilation);

}

/**
 * Compiles a "case"/"default" clause returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCase) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool caseClause;
	zval *statement_param = NULL, *caseClause_param = NULL, *expr = NULL, *_2 = NULL, *_0$$4, *_1$$4;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &caseClause_param);

	statement = statement_param;
	if (!caseClause_param) {
		caseClause = 1;
	} else {
		caseClause = zephir_get_boolval(caseClause_param);
	}


	if (UNEXPECTED(caseClause == 0)) {
		RETURN_MM_STRING("<?php default: ?>", 1);
	}
	ZEPHIR_OBS_VAR(expr);
	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0$$4);
		object_init_ex(_0$$4, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(_1$$4);
		ZVAL_STRING(_1$$4, "Corrupt statement", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0$$4, "__construct", NULL, 415, _1$$4, statement);
		zephir_check_temp_parameter(_1$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$4, "phalcon/mvc/view/engine/volt/compiler.zep", 1613 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 413, expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php case ", _2, ": ?>");
	RETURN_MM();

}

/**
 * Compiles a "elseif" statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileElseIf) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *expr = NULL, *_2 = NULL, *_0$$3, *_1$$3;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	statement = statement_param;


	ZEPHIR_OBS_VAR(expr);
	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "Corrupt statement", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 415, _1$$3, statement);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "phalcon/mvc/view/engine/volt/compiler.zep", 1633 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 413, expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php } elseif (", _2, ") { ?>");
	RETURN_MM();

}

/**
 * Compiles a "cache" statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCache) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, *compilation = NULL, *expr = NULL, *exprCode = NULL, *lifetime = NULL, *_2 = NULL, *_10, *_11 = NULL, *_12, *_13, *_0$$3, *_1$$3, *_3$$4, *_4$$4, *_5$$5, *_6$$5, *_7$$6, *_8$$6, *_9$$7, *_14$$8, *_19$$8, *_15$$9, *_16$$9, *_17$$10, *_18$$10, *_20$$11;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &extendsMode_param);

	statement = statement_param;
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	ZEPHIR_OBS_VAR(expr);
	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "Corrupt statement", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 415, _1$$3, statement);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "phalcon/mvc/view/engine/volt/compiler.zep", 1653 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", NULL, 413, expr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 413, expr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(compilation);
	ZEPHIR_CONCAT_SVS(compilation, "<?php $_cache[", _2, "] = $this->di->get('viewCache'); ");
	ZEPHIR_OBS_VAR(lifetime);
	if (zephir_array_isset_string_fetch(&lifetime, statement, SS("lifetime"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SVS(_3$$4, "$_cacheKey[", exprCode, "]");
		zephir_concat_self(&compilation, _3$$4 TSRMLS_CC);
		zephir_array_fetch_string(&_4$$4, lifetime, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1663 TSRMLS_CC);
		if (ZEPHIR_IS_LONG(_4$$4, 265)) {
			zephir_array_fetch_string(&_5$$5, lifetime, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1664 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_6$$5);
			ZEPHIR_CONCAT_SVSVSVS(_6$$5, " = $_cache[", exprCode, "]->start(", exprCode, ", $", _5$$5, "); ");
			zephir_concat_self(&compilation, _6$$5 TSRMLS_CC);
		} else {
			zephir_array_fetch_string(&_7$$6, lifetime, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1666 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_8$$6);
			ZEPHIR_CONCAT_SVSVSVS(_8$$6, " = $_cache[", exprCode, "]->start(", exprCode, ", ", _7$$6, "); ");
			zephir_concat_self(&compilation, _8$$6 TSRMLS_CC);
		}
	} else {
		ZEPHIR_INIT_VAR(_9$$7);
		ZEPHIR_CONCAT_SVSVSVS(_9$$7, "$_cacheKey[", exprCode, "] = $_cache[", exprCode, "]->start(", exprCode, "); ");
		zephir_concat_self(&compilation, _9$$7 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_SVS(_10, "if ($_cacheKey[", exprCode, "] === null) { ?>");
	zephir_concat_self(&compilation, _10 TSRMLS_CC);
	zephir_array_fetch_string(&_12, statement, SL("block_statements"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1676 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_13);
	if (extendsMode) {
		ZVAL_BOOL(_13, 1);
	} else {
		ZVAL_BOOL(_13, 0);
	}
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "_statementlist", NULL, 419, _12, _13);
	zephir_check_call_status();
	zephir_concat_self(&compilation, _11 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(lifetime);
	if (zephir_array_isset_string_fetch(&lifetime, statement, SS("lifetime"), 0 TSRMLS_CC)) {
		zephir_array_fetch_string(&_14$$8, lifetime, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1682 TSRMLS_CC);
		if (ZEPHIR_IS_LONG(_14$$8, 265)) {
			zephir_array_fetch_string(&_15$$9, lifetime, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1683 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_16$$9);
			ZEPHIR_CONCAT_SVSVSVS(_16$$9, "<?php $_cache[", exprCode, "]->save(", exprCode, ", null, $", _15$$9, "); ");
			zephir_concat_self(&compilation, _16$$9 TSRMLS_CC);
		} else {
			zephir_array_fetch_string(&_17$$10, lifetime, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1685 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_18$$10);
			ZEPHIR_CONCAT_SVSVSVS(_18$$10, "<?php $_cache[", exprCode, "]->save(", exprCode, ", null, ", _17$$10, "); ");
			zephir_concat_self(&compilation, _18$$10 TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(_19$$8);
		ZEPHIR_CONCAT_SVS(_19$$8, "} else { echo $_cacheKey[", exprCode, "]; } ?>");
		zephir_concat_self(&compilation, _19$$8 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_20$$11);
		ZEPHIR_CONCAT_SVSVSVS(_20$$11, "<?php $_cache[", exprCode, "]->save(", exprCode, "); } else { echo $_cacheKey[", exprCode, "]; } ?>");
		zephir_concat_self(&compilation, _20$$11 TSRMLS_CC);
	}
	RETURN_CCTOR(compilation);

}

/**
 * Compiles a "set" statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSet) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *assignments = NULL, *assignment = NULL, *exprCode = NULL, *target = NULL, *compilation = NULL, **_2, *_3$$4, *_5$$4, *_6$$4, *_7$$5 = NULL, *_8$$6 = NULL, *_9$$7 = NULL, *_10$$8 = NULL, *_11$$9 = NULL;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	statement = statement_param;


	ZEPHIR_OBS_VAR(assignments);
	if (!(zephir_array_isset_string_fetch(&assignments, statement, SS("assignments"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1706);
		return;
	}
	ZEPHIR_INIT_VAR(compilation);
	ZVAL_STRING(compilation, "<?php", 1);
	zephir_is_iterable(assignments, &_1, &_0, 0, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 1752);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(assignment, _2);
		zephir_array_fetch_string(&_3$$4, assignment, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1716 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", &_4, 413, _3$$4);
		zephir_check_call_status();
		zephir_array_fetch_string(&_5$$4, assignment, SL("variable"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1721 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&target, this_ptr, "expression", &_4, 413, _5$$4);
		zephir_check_call_status();
		zephir_array_fetch_string(&_6$$4, assignment, SL("op"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1727 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(_6$$4, 281)) {
				ZEPHIR_INIT_LNVAR(_7$$5);
				ZEPHIR_CONCAT_SVSVS(_7$$5, " ", target, " += ", exprCode, ";");
				zephir_concat_self(&compilation, _7$$5 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_6$$4, 282)) {
				ZEPHIR_INIT_LNVAR(_8$$6);
				ZEPHIR_CONCAT_SVSVS(_8$$6, " ", target, " -= ", exprCode, ";");
				zephir_concat_self(&compilation, _8$$6 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_6$$4, 283)) {
				ZEPHIR_INIT_LNVAR(_9$$7);
				ZEPHIR_CONCAT_SVSVS(_9$$7, " ", target, " *= ", exprCode, ";");
				zephir_concat_self(&compilation, _9$$7 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_6$$4, 284)) {
				ZEPHIR_INIT_LNVAR(_10$$8);
				ZEPHIR_CONCAT_SVSVS(_10$$8, " ", target, " /= ", exprCode, ";");
				zephir_concat_self(&compilation, _10$$8 TSRMLS_CC);
				break;
			}
			ZEPHIR_INIT_LNVAR(_11$$9);
			ZEPHIR_CONCAT_SVSVS(_11$$9, " ", target, " = ", exprCode, ";");
			zephir_concat_self(&compilation, _11$$9 TSRMLS_CC);
			break;
		} while(0);

	}
	zephir_concat_self_str(&compilation, SL(" ?>") TSRMLS_CC);
	RETURN_CCTOR(compilation);

}

/**
 * Compiles a "do" statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileDo) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *expr = NULL, *_0 = NULL;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	statement = statement_param;


	ZEPHIR_OBS_VAR(expr);
	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1767);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "expression", NULL, 413, expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php ", _0, "; ?>");
	RETURN_MM();

}

/**
 * Compiles a "return" statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileReturn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *expr = NULL, *_0 = NULL;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	statement = statement_param;


	ZEPHIR_OBS_VAR(expr);
	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1787);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "expression", NULL, 413, expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php return ", _0, "; ?>");
	RETURN_MM();

}

/**
 * Compiles a "autoescape" statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileAutoEscape) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, *autoescape = NULL, *oldAutoescape = NULL, *compilation = NULL, *_0, *_1;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &statement_param, &extendsMode_param);

	statement = statement_param;
	extendsMode = zephir_get_boolval(extendsMode_param);


	ZEPHIR_OBS_VAR(autoescape);
	if (!(zephir_array_isset_string_fetch(&autoescape, statement, SS("enable"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1807);
		return;
	}
	ZEPHIR_OBS_VAR(oldAutoescape);
	zephir_read_property_this(&oldAutoescape, this_ptr, SL("_autoescape"), PH_NOISY_CC);
	zephir_update_property_this(getThis(), SL("_autoescape"), autoescape TSRMLS_CC);
	zephir_array_fetch_string(&_0, statement, SL("block_statements"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1816 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	if (extendsMode) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_CALL_METHOD(&compilation, this_ptr, "_statementlist", NULL, 419, _0, _1);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_autoescape"), oldAutoescape TSRMLS_CC);
	RETURN_CCTOR(compilation);

}

/**
 * Compiles a '{{' '}}' statement returning PHP code
 *
 * @param array   statement
 * @param boolean extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileEcho) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *expr = NULL, *exprCode = NULL, *name = NULL, *_2, *_5, *_0$$3, *_1$$3, *_3$$4, *_4$$5;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	statement = statement_param;


	ZEPHIR_OBS_VAR(expr);
	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "Corrupt statement", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 415, _1$$3, statement);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "phalcon/mvc/view/engine/volt/compiler.zep", 1837 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", NULL, 413, expr);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, expr, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1845 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(_2, 350)) {
		zephir_array_fetch_string(&name, expr, SL("name"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1847 TSRMLS_CC);
		zephir_array_fetch_string(&_3$$4, name, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1849 TSRMLS_CC);
		if (ZEPHIR_IS_LONG(_3$$4, 265)) {
			zephir_array_fetch_string(&_4$$5, name, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1854 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(_4$$5, "super")) {
				RETURN_CCTOR(exprCode);
			}
		}
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_autoescape"), PH_NOISY_CC);
	if (zephir_is_true(_5)) {
		ZEPHIR_CONCAT_SVS(return_value, "<?= $this->escaper->escapeHtml(", exprCode, ") ?>");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "<?= ", exprCode, " ?>");
	RETURN_MM();

}

/**
 * Compiles a 'include' statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileInclude) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *pathExpr = NULL, *path = NULL, *subCompiler = NULL, *finalPath = NULL, *compilation = NULL, *params = NULL, *_0, *_3 = NULL, *_1$$5, *_2$$6 = NULL;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	statement = statement_param;


	ZEPHIR_OBS_VAR(pathExpr);
	if (!(zephir_array_isset_string_fetch(&pathExpr, statement, SS("path"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1882);
		return;
	}
	zephir_array_fetch_string(&_0, pathExpr, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1889 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(_0, 260)) {
		if (!(zephir_array_isset_string(statement, SS("params")))) {
			ZEPHIR_OBS_VAR(path);
			zephir_array_fetch_string(&path, pathExpr, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1899 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&finalPath, this_ptr, "getfinalpath", NULL, 0, path);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(subCompiler);
			if (zephir_clone(subCompiler, this_ptr TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}
			ZEPHIR_INIT_VAR(_1$$5);
			ZVAL_BOOL(_1$$5, 0);
			ZEPHIR_CALL_METHOD(&compilation, subCompiler, "compile", NULL, 0, finalPath, _1$$5);
			zephir_check_call_status();
			if (Z_TYPE_P(compilation) == IS_NULL) {
				ZEPHIR_CALL_METHOD(&_2$$6, subCompiler, "getcompiledtemplatepath", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(compilation);
				zephir_file_get_contents(compilation, _2$$6 TSRMLS_CC);
			}
			RETURN_CCTOR(compilation);
		}
	}
	ZEPHIR_CALL_METHOD(&path, this_ptr, "expression", NULL, 413, pathExpr);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(params);
	if (!(zephir_array_isset_string_fetch(&params, statement, SS("params"), 0 TSRMLS_CC))) {
		ZEPHIR_CONCAT_SVS(return_value, "<?php $this->partial(", path, "); ?>");
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "expression", NULL, 413, params);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "<?php $this->partial(", path, ", ", _3, "); ?>");
	RETURN_MM();

}

/**
 * Compiles macros
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileMacro) {

	HashTable *_6$$6;
	HashPosition _5$$6;
	zephir_fcall_cache_entry *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, *code = NULL, *name = NULL, *defaultValue = NULL, *macroName = NULL, *parameters = NULL, *position = NULL, *parameter = NULL, *variableName = NULL, *blockStatements = NULL, *_0, *_19, *_1$$4, *_2$$4, *_3$$5, *_4$$6, **_7$$6, *_8$$7 = NULL, *_9$$7 = NULL, *_10$$7 = NULL, *_11$$7 = NULL, *_12$$8 = NULL, *_14$$8 = NULL, *_15$$9 = NULL, *_16$$10 = NULL, *_17$$10, *_18$$10;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &statement_param, &extendsMode_param);

	statement = statement_param;
	extendsMode = zephir_get_boolval(extendsMode_param);


	ZEPHIR_OBS_VAR(name);
	if (!(zephir_array_isset_string_fetch(&name, statement, SS("name"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1949);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_macros"), PH_NOISY_CC);
	if (zephir_array_isset(_0, name)) {
		ZEPHIR_INIT_VAR(_1$$4);
		object_init_ex(_1$$4, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(_2$$4);
		ZEPHIR_CONCAT_SVS(_2$$4, "Macro '", name, "' is already defined");
		ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 415, _2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$4, "phalcon/mvc/view/engine/volt/compiler.zep", 1956 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("_macros"), name, name TSRMLS_CC);
	ZEPHIR_INIT_VAR(macroName);
	ZEPHIR_CONCAT_SVS(macroName, "$this->_macros['", name, "']");
	ZEPHIR_INIT_VAR(code);
	ZVAL_STRING(code, "<?php ", 1);
	ZEPHIR_OBS_VAR(parameters);
	if (!(zephir_array_isset_string_fetch(&parameters, statement, SS("parameters"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_3$$5);
		ZEPHIR_CONCAT_VS(_3$$5, macroName, " = function() { ?>");
		zephir_concat_self(&code, _3$$5 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_4$$6);
		ZEPHIR_CONCAT_VS(_4$$6, macroName, " = function($__p = null) { ");
		zephir_concat_self(&code, _4$$6 TSRMLS_CC);
		zephir_is_iterable(parameters, &_6$$6, &_5$$6, 0, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 1994);
		for (
		  ; zend_hash_get_current_data_ex(_6$$6, (void**) &_7$$6, &_5$$6) == SUCCESS
		  ; zend_hash_move_forward_ex(_6$$6, &_5$$6)
		) {
			ZEPHIR_GET_HMKEY(position, _6$$6, _5$$6);
			ZEPHIR_GET_HVALUE(parameter, _7$$6);
			ZEPHIR_OBS_NVAR(variableName);
			zephir_array_fetch_string(&variableName, parameter, SL("variable"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1978 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_8$$7);
			ZEPHIR_CONCAT_SVS(_8$$7, "if (isset($__p[", position, "])) { ");
			zephir_concat_self(&code, _8$$7 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_9$$7);
			ZEPHIR_CONCAT_SVSVS(_9$$7, "$", variableName, " = $__p[", position, "];");
			zephir_concat_self(&code, _9$$7 TSRMLS_CC);
			zephir_concat_self_str(&code, SL(" } else { ") TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_10$$7);
			ZEPHIR_CONCAT_SVS(_10$$7, "if (isset($__p[\"", variableName, "\"])) { ");
			zephir_concat_self(&code, _10$$7 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_11$$7);
			ZEPHIR_CONCAT_SVSVS(_11$$7, "$", variableName, " = $__p[\"", variableName, "\"];");
			zephir_concat_self(&code, _11$$7 TSRMLS_CC);
			zephir_concat_self_str(&code, SL(" } else { ") TSRMLS_CC);
			ZEPHIR_OBS_NVAR(defaultValue);
			if (zephir_array_isset_string_fetch(&defaultValue, parameter, SS("default"), 0 TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(&_12$$8, this_ptr, "expression", &_13, 413, defaultValue);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_14$$8);
				ZEPHIR_CONCAT_SVSVS(_14$$8, "$", variableName, " = ", _12$$8, ";");
				zephir_concat_self(&code, _14$$8 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_15$$9);
				ZEPHIR_CONCAT_SVSVS(_15$$9, " throw new \\Phalcon\\Mvc\\View\\Exception(\"Macro '", name, "' was called without parameter: ", variableName, "\"); ");
				zephir_concat_self(&code, _15$$9 TSRMLS_CC);
			}
			zephir_concat_self_str(&code, SL(" } } ") TSRMLS_CC);
		}
		zephir_concat_self_str(&code, SL(" ?>") TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(blockStatements);
	if (zephir_array_isset_string_fetch(&blockStatements, statement, SS("block_statements"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_17$$10);
		if (extendsMode) {
			ZVAL_BOOL(_17$$10, 1);
		} else {
			ZVAL_BOOL(_17$$10, 0);
		}
		ZEPHIR_CALL_METHOD(&_16$$10, this_ptr, "_statementlist", NULL, 419, blockStatements, _17$$10);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_18$$10);
		ZEPHIR_CONCAT_VS(_18$$10, _16$$10, "<?php }; ");
		zephir_concat_self(&code, _18$$10 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&code, SL("<?php }; ") TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_19);
	ZEPHIR_CONCAT_VSVS(_19, macroName, " = \\Closure::bind(", macroName, ", $this); ?>");
	zephir_concat_self(&code, _19 TSRMLS_CC);
	RETURN_CCTOR(code);

}

/**
 * Compiles calls to macros
 *
 * @param array    statement
 * @param boolean  extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCall) {

	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL;
	zval *statement = NULL;

	zephir_fetch_params(0, 2, 0, &statement_param, &extendsMode_param);

	statement = statement_param;
	extendsMode = zephir_get_boolval(extendsMode_param);



}

/**
 * Traverses a statement list compiling each of its nodes
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementList) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL, *_15 = NULL, *_17 = NULL, *_20 = NULL, *_22 = NULL, *_27 = NULL, *_29 = NULL, *_31 = NULL, *_34 = NULL, *_36 = NULL, *_39 = NULL, *_42 = NULL, *_44 = NULL, *_46 = NULL, *_49 = NULL, *_51 = NULL, *_54 = NULL, *_57 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode, _0;
	zval *statements_param = NULL, *extendsMode_param = NULL, *extended = NULL, *blockMode = NULL, *compilation = NULL, *extensions = NULL, *statement = NULL, *tempCompilation = NULL, *type = NULL, *blockName = NULL, *blockStatements = NULL, *blocks = NULL, *path = NULL, *finalPath = NULL, *subCompiler = NULL, *level = NULL, **_3, *_4$$7 = NULL, *_5$$7, *_6$$7, *_7$$7 = NULL, *_10$$8 = NULL, *_12$$10, *_13$$11 = NULL, *_14$$11 = NULL, *_16$$12 = NULL, *_18$$13 = NULL, *_19$$13 = NULL, *_21$$14 = NULL, *_23$$15 = NULL, *_24$$15 = NULL, *_25$$16 = NULL, *_26$$16 = NULL, *_28$$17 = NULL, *_30$$18 = NULL, *_32$$24 = NULL, *_33$$24 = NULL, *_35$$25, *_37$$26 = NULL, *_38$$27 = NULL, *_40$$28 = NULL, *_41$$28 = NULL, *_43$$29 = NULL, *_45$$30 = NULL, *_47$$31 = NULL, *_48$$31 = NULL, *_50$$34 = NULL, *_52$$35 = NULL, *_53$$35 = NULL, *_55$$36 = NULL, *_56$$36 = NULL, *_58$$38 = NULL, *_59$$38, *_60$$38, *_61$$38 = NULL;
	zval *statements = NULL, *_9$$8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statements_param, &extendsMode_param);

	statements = statements_param;
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	if (!(zephir_fast_count_int(statements TSRMLS_CC))) {
		RETURN_MM_STRING("", 1);
	}
	ZEPHIR_OBS_VAR(extended);
	zephir_read_property_this(&extended, this_ptr, SL("_extended"), PH_NOISY_CC);
	_0 = zephir_is_true(extended);
	if (!(_0)) {
		_0 = extendsMode;
	}
	ZEPHIR_INIT_VAR(blockMode);
	ZVAL_BOOL(blockMode, _0);
	if (ZEPHIR_IS_TRUE_IDENTICAL(blockMode)) {
		RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_blockLevel") TSRMLS_CC));
	}
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_level") TSRMLS_CC));
	ZEPHIR_INIT_VAR(compilation);
	ZVAL_NULL(compilation);
	ZEPHIR_OBS_VAR(extensions);
	zephir_read_property_this(&extensions, this_ptr, SL("_extensions"), PH_NOISY_CC);
	zephir_is_iterable(statements, &_2, &_1, 0, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 2273);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(statement, _3);
		if (Z_TYPE_P(statement) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 2066);
			return;
		}
		if (!(zephir_array_isset_string(statement, SS("type")))) {
			ZEPHIR_INIT_NVAR(_4$$7);
			object_init_ex(_4$$7, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_5$$7, statement, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 2073 TSRMLS_CC);
			zephir_array_fetch_string(&_6$$7, statement, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 2073 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_7$$7);
			ZEPHIR_CONCAT_SVSV(_7$$7, "Invalid statement in ", _5$$7, " on line ", _6$$7);
			ZEPHIR_CALL_METHOD(NULL, _4$$7, "__construct", &_8, 415, _7$$7, statement);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4$$7, "phalcon/mvc/view/engine/volt/compiler.zep", 2073 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(extensions) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_9$$8);
			zephir_create_array(_9$$8, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_9$$8, statement);
			ZEPHIR_INIT_NVAR(_10$$8);
			ZVAL_STRING(_10$$8, "compileStatement", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&tempCompilation, this_ptr, "fireextensionevent", &_11, 414, _10$$8, _9$$8);
			zephir_check_temp_parameter(_10$$8);
			zephir_check_call_status();
			if (Z_TYPE_P(tempCompilation) == IS_STRING) {
				zephir_concat_self(&compilation, tempCompilation TSRMLS_CC);
				continue;
			}
		}
		ZEPHIR_OBS_NVAR(type);
		zephir_array_fetch_string(&type, statement, SL("type"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2094 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(type, 357)) {
				zephir_array_fetch_string(&_12$$10, statement, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 2102 TSRMLS_CC);
				zephir_concat_self(&compilation, _12$$10 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 300)) {
				ZEPHIR_INIT_NVAR(_14$$11);
				if (extendsMode) {
					ZVAL_BOOL(_14$$11, 1);
				} else {
					ZVAL_BOOL(_14$$11, 0);
				}
				ZEPHIR_CALL_METHOD(&_13$$11, this_ptr, "compileif", &_15, 0, statement, _14$$11);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _13$$11 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 302)) {
				ZEPHIR_CALL_METHOD(&_16$$12, this_ptr, "compileelseif", &_17, 0, statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _16$$12 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 411)) {
				ZEPHIR_INIT_NVAR(_19$$13);
				if (extendsMode) {
					ZVAL_BOOL(_19$$13, 1);
				} else {
					ZVAL_BOOL(_19$$13, 0);
				}
				ZEPHIR_CALL_METHOD(&_18$$13, this_ptr, "compileswitch", &_20, 0, statement, _19$$13);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _18$$13 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 412)) {
				ZEPHIR_CALL_METHOD(&_21$$14, this_ptr, "compilecase", &_22, 0, statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _21$$14 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 413)) {
				ZEPHIR_INIT_NVAR(_24$$15);
				ZVAL_BOOL(_24$$15, 0);
				ZEPHIR_CALL_METHOD(&_23$$15, this_ptr, "compilecase", &_22, 0, statement, _24$$15);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _23$$15 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 304)) {
				ZEPHIR_INIT_NVAR(_26$$16);
				if (extendsMode) {
					ZVAL_BOOL(_26$$16, 1);
				} else {
					ZVAL_BOOL(_26$$16, 0);
				}
				ZEPHIR_CALL_METHOD(&_25$$16, this_ptr, "compileforeach", &_27, 0, statement, _26$$16);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _25$$16 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 306)) {
				ZEPHIR_CALL_METHOD(&_28$$17, this_ptr, "compileset", &_29, 0, statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _28$$17 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 359)) {
				ZEPHIR_CALL_METHOD(&_30$$18, this_ptr, "compileecho", &_31, 0, statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _30$$18 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 307)) {
				ZEPHIR_OBS_NVAR(blockName);
				zephir_array_fetch_string(&blockName, statement, SL("name"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2142 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(blockStatements);
				zephir_array_isset_string_fetch(&blockStatements, statement, SS("block_statements"), 0 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(blocks);
				zephir_read_property_this(&blocks, this_ptr, SL("_blocks"), PH_NOISY_CC);
				if (zephir_is_true(blockMode)) {
					if (Z_TYPE_P(blocks) != IS_ARRAY) {
						ZEPHIR_INIT_NVAR(blocks);
						array_init(blocks);
					}
					if (Z_TYPE_P(compilation) != IS_NULL) {
						zephir_array_append(&blocks, compilation, PH_SEPARATE, "phalcon/mvc/view/engine/volt/compiler.zep", 2157);
						ZEPHIR_INIT_NVAR(compilation);
						ZVAL_NULL(compilation);
					}
					zephir_array_update_zval(&blocks, blockName, &blockStatements, PH_COPY | PH_SEPARATE);
					zephir_update_property_this(getThis(), SL("_blocks"), blocks TSRMLS_CC);
				} else {
					if (Z_TYPE_P(blockStatements) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(_33$$24);
						if (extendsMode) {
							ZVAL_BOOL(_33$$24, 1);
						} else {
							ZVAL_BOOL(_33$$24, 0);
						}
						ZEPHIR_CALL_METHOD(&_32$$24, this_ptr, "_statementlist", &_34, 419, blockStatements, _33$$24);
						zephir_check_call_status();
						zephir_concat_self(&compilation, _32$$24 TSRMLS_CC);
					}
				}
				break;
			}
			if (ZEPHIR_IS_LONG(type, 310)) {
				ZEPHIR_OBS_NVAR(path);
				zephir_array_fetch_string(&path, statement, SL("path"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2179 TSRMLS_CC);
				zephir_array_fetch_string(&_35$$25, path, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 2181 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&finalPath, this_ptr, "getfinalpath", &_36, 0, _35$$25);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(extended);
				ZVAL_BOOL(extended, 1);
				ZEPHIR_INIT_NVAR(subCompiler);
				if (zephir_clone(subCompiler, this_ptr TSRMLS_CC) == FAILURE) {
					RETURN_MM();
				}
				ZEPHIR_CALL_METHOD(&tempCompilation, subCompiler, "compile", NULL, 0, finalPath, extended);
				zephir_check_call_status();
				if (Z_TYPE_P(tempCompilation) == IS_NULL) {
					ZEPHIR_CALL_METHOD(&_37$$26, subCompiler, "getcompiledtemplatepath", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(tempCompilation);
					zephir_file_get_contents(tempCompilation, _37$$26 TSRMLS_CC);
				}
				if (1) {
					zephir_update_property_this(getThis(), SL("_extended"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
				} else {
					zephir_update_property_this(getThis(), SL("_extended"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				}
				zephir_update_property_this(getThis(), SL("_extendedBlocks"), tempCompilation TSRMLS_CC);
				ZEPHIR_CPY_WRT(blockMode, extended);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 313)) {
				ZEPHIR_CALL_METHOD(&_38$$27, this_ptr, "compileinclude", &_39, 0, statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _38$$27 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 314)) {
				ZEPHIR_INIT_NVAR(_41$$28);
				if (extendsMode) {
					ZVAL_BOOL(_41$$28, 1);
				} else {
					ZVAL_BOOL(_41$$28, 0);
				}
				ZEPHIR_CALL_METHOD(&_40$$28, this_ptr, "compilecache", &_42, 0, statement, _41$$28);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _40$$28 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 316)) {
				ZEPHIR_CALL_METHOD(&_43$$29, this_ptr, "compiledo", &_44, 0, statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _43$$29 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 327)) {
				ZEPHIR_CALL_METHOD(&_45$$30, this_ptr, "compilereturn", &_46, 0, statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _45$$30 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 317)) {
				ZEPHIR_INIT_NVAR(_48$$31);
				if (extendsMode) {
					ZVAL_BOOL(_48$$31, 1);
				} else {
					ZVAL_BOOL(_48$$31, 0);
				}
				ZEPHIR_CALL_METHOD(&_47$$31, this_ptr, "compileautoescape", &_49, 0, statement, _48$$31);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _47$$31 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 319)) {
				zephir_concat_self_str(&compilation, SL("<?php continue; ?>") TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 320)) {
				zephir_concat_self_str(&compilation, SL("<?php break; ?>") TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 321)) {
				ZEPHIR_CALL_METHOD(&_50$$34, this_ptr, "compileforelse", &_51, 0);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _50$$34 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 322)) {
				ZEPHIR_INIT_NVAR(_53$$35);
				if (extendsMode) {
					ZVAL_BOOL(_53$$35, 1);
				} else {
					ZVAL_BOOL(_53$$35, 0);
				}
				ZEPHIR_CALL_METHOD(&_52$$35, this_ptr, "compilemacro", &_54, 0, statement, _53$$35);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _52$$35 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 325)) {
				ZEPHIR_INIT_NVAR(_56$$36);
				if (extendsMode) {
					ZVAL_BOOL(_56$$36, 1);
				} else {
					ZVAL_BOOL(_56$$36, 0);
				}
				ZEPHIR_CALL_METHOD(&_55$$36, this_ptr, "compilecall", &_57, 0, statement, _56$$36);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _55$$36 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 358)) {
				break;
			}
			ZEPHIR_INIT_NVAR(_58$$38);
			object_init_ex(_58$$38, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_59$$38, statement, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 2265 TSRMLS_CC);
			zephir_array_fetch_string(&_60$$38, statement, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 2265 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_61$$38);
			ZEPHIR_CONCAT_SVSVSV(_61$$38, "Unknown statement ", type, " in ", _59$$38, " on line ", _60$$38);
			ZEPHIR_CALL_METHOD(NULL, _58$$38, "__construct", &_8, 415, _61$$38);
			zephir_check_call_status();
			zephir_throw_exception_debug(_58$$38, "phalcon/mvc/view/engine/volt/compiler.zep", 2265 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(blockMode)) {
		level = zephir_fetch_nproperty_this(this_ptr, SL("_blockLevel"), PH_NOISY_CC);
		if (ZEPHIR_IS_LONG(level, 1)) {
			if (Z_TYPE_P(compilation) != IS_NULL) {
				zephir_update_property_array_append(this_ptr, SL("_blocks"), compilation TSRMLS_CC);
			}
		}
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_blockLevel") TSRMLS_CC));
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_level") TSRMLS_CC));
	RETURN_CCTOR(compilation);

}

/**
 * Compiles a Volt source code returning a PHP plain version
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _compileSource) {

	HashTable *_2$$7;
	HashPosition _1$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *viewCode_param = NULL, *extendsMode_param = NULL, *currentPath = NULL, *intermediate = NULL, *extended = NULL, *finalCompilation = NULL, *blocks = NULL, *extendedBlocks = NULL, *name = NULL, *block = NULL, *blockCompilation = NULL, *localBlock = NULL, *compilation = NULL, *options = NULL, *autoescape = NULL, *_0, **_3$$7;
	zval *viewCode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewCode_param, &extendsMode_param);

	if (UNEXPECTED(Z_TYPE_P(viewCode_param) != IS_STRING && Z_TYPE_P(viewCode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewCode' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewCode_param) == IS_STRING)) {
		zephir_get_strval(viewCode, viewCode_param);
	} else {
		ZEPHIR_INIT_VAR(viewCode);
		ZVAL_EMPTY_STRING(viewCode);
	}
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	ZEPHIR_OBS_VAR(currentPath);
	zephir_read_property_this(&currentPath, this_ptr, SL("_currentPath"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(options) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(autoescape);
		if (zephir_array_isset_string_fetch(&autoescape, options, SS("autoescape"), 0 TSRMLS_CC)) {
			if (Z_TYPE_P(autoescape) != IS_BOOL) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'autoescape' must be boolean", "phalcon/mvc/view/engine/volt/compiler.zep", 2310);
				return;
			}
			zephir_update_property_this(getThis(), SL("_autoescape"), autoescape TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_VAR(intermediate);
	ZEPHIR_LAST_CALL_STATUS = phvolt_parse_view(intermediate, viewCode, currentPath TSRMLS_CC);
	zephir_check_call_status();
	if (Z_TYPE_P(intermediate) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Invalid intermediate representation", "phalcon/mvc/view/engine/volt/compiler.zep", 2322);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	if (extendsMode) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	ZEPHIR_CALL_METHOD(&compilation, this_ptr, "_statementlist", NULL, 419, intermediate, _0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(extended);
	zephir_read_property_this(&extended, this_ptr, SL("_extended"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(extended)) {
		ZEPHIR_INIT_VAR(finalCompilation);
		if (extendsMode == 1) {
			array_init(finalCompilation);
		} else {
			ZVAL_NULL(finalCompilation);
		}
		ZEPHIR_OBS_VAR(blocks);
		zephir_read_property_this(&blocks, this_ptr, SL("_blocks"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(extendedBlocks);
		zephir_read_property_this(&extendedBlocks, this_ptr, SL("_extendedBlocks"), PH_NOISY_CC);
		zephir_is_iterable(extendedBlocks, &_2$$7, &_1$$7, 0, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 2388);
		for (
		  ; zend_hash_get_current_data_ex(_2$$7, (void**) &_3$$7, &_1$$7) == SUCCESS
		  ; zend_hash_move_forward_ex(_2$$7, &_1$$7)
		) {
			ZEPHIR_GET_HMKEY(name, _2$$7, _1$$7);
			ZEPHIR_GET_HVALUE(block, _3$$7);
			if (Z_TYPE_P(name) == IS_STRING) {
				if (zephir_array_isset(blocks, name)) {
					ZEPHIR_OBS_NVAR(localBlock);
					zephir_array_fetch(&localBlock, blocks, name, PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2356 TSRMLS_CC);
					zephir_update_property_this(getThis(), SL("_currentBlock"), name TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&blockCompilation, this_ptr, "_statementlist", NULL, 419, localBlock);
					zephir_check_call_status();
				} else {
					if (Z_TYPE_P(block) == IS_ARRAY) {
						ZEPHIR_CALL_METHOD(&blockCompilation, this_ptr, "_statementlist", NULL, 419, block);
						zephir_check_call_status();
					} else {
						ZEPHIR_CPY_WRT(blockCompilation, block);
					}
				}
				if (extendsMode == 1) {
					zephir_array_update_zval(&finalCompilation, name, &blockCompilation, PH_COPY | PH_SEPARATE);
				} else {
					zephir_concat_self(&finalCompilation, blockCompilation TSRMLS_CC);
				}
			} else {
				if (extendsMode == 1) {
					zephir_array_append(&finalCompilation, block, PH_SEPARATE, "phalcon/mvc/view/engine/volt/compiler.zep", 2381);
				} else {
					zephir_concat_self(&finalCompilation, block TSRMLS_CC);
				}
			}
		}
		RETURN_CCTOR(finalCompilation);
	}
	if (extendsMode == 1) {
		RETURN_MM_MEMBER(getThis(), "_blocks");
	}
	RETURN_CCTOR(compilation);

}

/**
 * Compiles a template into a string
 *
 *<code>
 * echo $compiler->compileString('{{ "hello world" }}');
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *viewCode_param = NULL, *extendsMode_param = NULL, *_0, *_1;
	zval *viewCode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewCode_param, &extendsMode_param);

	if (UNEXPECTED(Z_TYPE_P(viewCode_param) != IS_STRING && Z_TYPE_P(viewCode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewCode' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewCode_param) == IS_STRING)) {
		zephir_get_strval(viewCode, viewCode_param);
	} else {
		ZEPHIR_INIT_VAR(viewCode);
		ZVAL_EMPTY_STRING(viewCode);
	}
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "eval code", 1);
	zephir_update_property_this(getThis(), SL("_currentPath"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	if (extendsMode) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_compilesource", NULL, 0, viewCode, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Compiles a template into a file forcing the destination path
 *
 *<code>
 * $compiler->compileFile("views/layouts/main.volt", "views/layouts/main.volt.php");
 *</code>
 *
 * @param string path
 * @param string compiledPath
 * @param boolean extendsMode
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *path_param = NULL, *compiledPath_param = NULL, *extendsMode_param = NULL, *viewCode = NULL, *compilation = NULL, *finalCompilation = NULL, *_4, *_5, *_0$$4, *_2$$5;
	zval *path = NULL, *compiledPath = NULL, *_1$$4, *_3$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &path_param, &compiledPath_param, &extendsMode_param);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}
	if (UNEXPECTED(Z_TYPE_P(compiledPath_param) != IS_STRING && Z_TYPE_P(compiledPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'compiledPath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(compiledPath_param) == IS_STRING)) {
		zephir_get_strval(compiledPath, compiledPath_param);
	} else {
		ZEPHIR_INIT_VAR(compiledPath);
		ZVAL_EMPTY_STRING(compiledPath);
	}
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	if (ZEPHIR_IS_EQUAL(path, compiledPath)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Template path and compilation template path cannot be the same", "phalcon/mvc/view/engine/volt/compiler.zep", 2430);
		return;
	}
	if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(_0$$4);
		object_init_ex(_0$$4, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(_1$$4);
		ZEPHIR_CONCAT_SVS(_1$$4, "Template file ", path, " does not exist");
		ZEPHIR_CALL_METHOD(NULL, _0$$4, "__construct", NULL, 415, _1$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$4, "phalcon/mvc/view/engine/volt/compiler.zep", 2437 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(viewCode);
	zephir_file_get_contents(viewCode, path TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(viewCode)) {
		ZEPHIR_INIT_VAR(_2$$5);
		object_init_ex(_2$$5, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(_3$$5);
		ZEPHIR_CONCAT_SVS(_3$$5, "Template file ", path, " could not be opened");
		ZEPHIR_CALL_METHOD(NULL, _2$$5, "__construct", NULL, 415, _3$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$5, "phalcon/mvc/view/engine/volt/compiler.zep", 2445 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(getThis(), SL("_currentPath"), path TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	if (extendsMode) {
		ZVAL_BOOL(_4, 1);
	} else {
		ZVAL_BOOL(_4, 0);
	}
	ZEPHIR_CALL_METHOD(&compilation, this_ptr, "_compilesource", NULL, 0, viewCode, _4);
	zephir_check_call_status();
	if (Z_TYPE_P(compilation) == IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&finalCompilation, "serialize", NULL, 68, compilation);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(finalCompilation, compilation);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_file_put_contents(_5, compiledPath, finalCompilation TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_5)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Volt directory can't be written", "phalcon/mvc/view/engine/volt/compiler.zep", 2465);
		return;
	}
	RETURN_CCTOR(compilation);

}

/**
 * Compiles a template into a file applying the compiler options
 * This method does not return the compiled path if the template was not compiled
 *
 *<code>
 * $compiler->compile("views/layouts/main.volt");
 *
 * require $compiler->getCompiledTemplatePath();
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compile) {

	zval *_2$$23;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *templatePath_param = NULL, *extendsMode_param = NULL, *stat = NULL, *compileAlways = NULL, *prefix = NULL, *compiledPath = NULL, *compiledSeparator = NULL, *blocksCode = NULL, *compiledExtension = NULL, *compilation = NULL, *options = NULL, *realCompiledPath = NULL, *compiledTemplatePath = NULL, *templateSepPath = NULL, *_0, *_1$$17 = NULL, *_3$$23, *_4$$26, *_5$$29, *_6$$30, *_7$$33, *_8$$33, *_9$$36, *_10$$38;
	zval *templatePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &templatePath_param, &extendsMode_param);

	if (UNEXPECTED(Z_TYPE_P(templatePath_param) != IS_STRING && Z_TYPE_P(templatePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'templatePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(templatePath_param) == IS_STRING)) {
		zephir_get_strval(templatePath, templatePath_param);
	} else {
		ZEPHIR_INIT_VAR(templatePath);
		ZVAL_EMPTY_STRING(templatePath);
	}
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	if (0) {
		zephir_update_property_this(getThis(), SL("_extended"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_extended"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (0) {
		zephir_update_property_this(getThis(), SL("_extendedBlocks"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_extendedBlocks"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	zephir_update_property_this(getThis(), SL("_blocks"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(getThis(), SL("_level"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(getThis(), SL("_foreachLevel"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(getThis(), SL("_blockLevel"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(getThis(), SL("_exprLevel"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(stat);
	ZVAL_BOOL(stat, 1);
	ZEPHIR_INIT_VAR(compileAlways);
	ZVAL_BOOL(compileAlways, 0);
	ZEPHIR_INIT_VAR(compiledPath);
	ZVAL_STRING(compiledPath, "", 1);
	ZEPHIR_INIT_VAR(prefix);
	ZVAL_NULL(prefix);
	ZEPHIR_INIT_VAR(compiledSeparator);
	ZVAL_STRING(compiledSeparator, "%%", 1);
	ZEPHIR_INIT_VAR(compiledExtension);
	ZVAL_STRING(compiledExtension, ".php", 1);
	ZEPHIR_INIT_VAR(compilation);
	ZVAL_NULL(compilation);
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(options) == IS_ARRAY) {
		if (zephir_array_isset_string(options, SS("compileAlways"))) {
			ZEPHIR_OBS_NVAR(compileAlways);
			zephir_array_fetch_string(&compileAlways, options, SL("compileAlways"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2513 TSRMLS_CC);
			if (Z_TYPE_P(compileAlways) != IS_BOOL) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'compileAlways' must be a bool value", "phalcon/mvc/view/engine/volt/compiler.zep", 2515);
				return;
			}
		}
		if (zephir_array_isset_string(options, SS("prefix"))) {
			ZEPHIR_OBS_NVAR(prefix);
			zephir_array_fetch_string(&prefix, options, SL("prefix"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2523 TSRMLS_CC);
			if (Z_TYPE_P(prefix) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'prefix' must be a string", "phalcon/mvc/view/engine/volt/compiler.zep", 2525);
				return;
			}
		}
		if (zephir_array_isset_string(options, SS("compiledPath"))) {
			ZEPHIR_OBS_NVAR(compiledPath);
			zephir_array_fetch_string(&compiledPath, options, SL("compiledPath"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2533 TSRMLS_CC);
			if (Z_TYPE_P(compiledPath) != IS_STRING) {
				if (Z_TYPE_P(compiledPath) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'compiledPath' must be a string or a closure", "phalcon/mvc/view/engine/volt/compiler.zep", 2536);
					return;
				}
			}
		}
		if (zephir_array_isset_string(options, SS("compiledSeparator"))) {
			ZEPHIR_OBS_NVAR(compiledSeparator);
			zephir_array_fetch_string(&compiledSeparator, options, SL("compiledSeparator"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2545 TSRMLS_CC);
			if (Z_TYPE_P(compiledSeparator) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'compiledSeparator' must be a string", "phalcon/mvc/view/engine/volt/compiler.zep", 2547);
				return;
			}
		}
		if (zephir_array_isset_string(options, SS("compiledExtension"))) {
			ZEPHIR_OBS_NVAR(compiledExtension);
			zephir_array_fetch_string(&compiledExtension, options, SL("compiledExtension"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2555 TSRMLS_CC);
			if (Z_TYPE_P(compiledExtension) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'compiledExtension' must be a string", "phalcon/mvc/view/engine/volt/compiler.zep", 2557);
				return;
			}
		}
		if (zephir_array_isset_string(options, SS("stat"))) {
			ZEPHIR_OBS_NVAR(stat);
			zephir_array_fetch_string(&stat, options, SL("stat"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2565 TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(compiledPath) == IS_STRING) {
		if (!(ZEPHIR_IS_EMPTY(compiledPath))) {
			ZEPHIR_CALL_FUNCTION(&_1$$17, "realpath", NULL, 67, templatePath);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(templateSepPath);
			zephir_prepare_virtual_path(templateSepPath, _1$$17, compiledSeparator TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(templateSepPath, templatePath);
		}
		ZEPHIR_INIT_VAR(compiledTemplatePath);
		if (extendsMode == 1) {
			ZEPHIR_CONCAT_VVVVSVV(compiledTemplatePath, compiledPath, prefix, templateSepPath, compiledSeparator, "e", compiledSeparator, compiledExtension);
		} else {
			ZEPHIR_CONCAT_VVVV(compiledTemplatePath, compiledPath, prefix, templateSepPath, compiledExtension);
		}
	} else {
		if (Z_TYPE_P(compiledPath) == IS_OBJECT) {
			if (zephir_instance_of_ev(compiledPath, zend_ce_closure TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(_2$$23);
				zephir_create_array(_2$$23, 3, 0 TSRMLS_CC);
				zephir_array_fast_append(_2$$23, templatePath);
				zephir_array_fast_append(_2$$23, options);
				ZEPHIR_INIT_VAR(_3$$23);
				ZVAL_BOOL(_3$$23, extendsMode);
				zephir_array_fast_append(_2$$23, _3$$23);
				ZEPHIR_INIT_NVAR(compiledTemplatePath);
				ZEPHIR_CALL_USER_FUNC_ARRAY(compiledTemplatePath, compiledPath, _2$$23);
				zephir_check_call_status();
				if (Z_TYPE_P(compiledTemplatePath) != IS_STRING) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "compiledPath closure didn't return a valid string", "phalcon/mvc/view/engine/volt/compiler.zep", 2610);
					return;
				}
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "compiledPath must be a string or a closure", "phalcon/mvc/view/engine/volt/compiler.zep", 2613);
				return;
			}
		}
	}
	ZEPHIR_CPY_WRT(realCompiledPath, compiledTemplatePath);
	if (zephir_is_true(compileAlways)) {
		ZEPHIR_INIT_VAR(_4$$26);
		if (extendsMode) {
			ZVAL_BOOL(_4$$26, 1);
		} else {
			ZVAL_BOOL(_4$$26, 0);
		}
		ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilefile", NULL, 0, templatePath, realCompiledPath, _4$$26);
		zephir_check_call_status();
	} else {
		if (ZEPHIR_IS_TRUE_IDENTICAL(stat)) {
			if ((zephir_file_exists(compiledTemplatePath TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_INIT_VAR(_5$$29);
				if (zephir_compare_mtime(templatePath, realCompiledPath TSRMLS_CC)) {
					ZEPHIR_INIT_VAR(_6$$30);
					if (extendsMode) {
						ZVAL_BOOL(_6$$30, 1);
					} else {
						ZVAL_BOOL(_6$$30, 0);
					}
					ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilefile", NULL, 0, templatePath, realCompiledPath, _6$$30);
					zephir_check_call_status();
				} else {
					if (extendsMode == 1) {
						ZEPHIR_INIT_VAR(blocksCode);
						zephir_file_get_contents(blocksCode, realCompiledPath TSRMLS_CC);
						if (ZEPHIR_IS_FALSE_IDENTICAL(blocksCode)) {
							ZEPHIR_INIT_VAR(_7$$33);
							object_init_ex(_7$$33, phalcon_mvc_view_engine_volt_exception_ce);
							ZEPHIR_INIT_VAR(_8$$33);
							ZEPHIR_CONCAT_SVS(_8$$33, "Extends compilation file ", realCompiledPath, " could not be opened");
							ZEPHIR_CALL_METHOD(NULL, _7$$33, "__construct", NULL, 415, _8$$33);
							zephir_check_call_status();
							zephir_throw_exception_debug(_7$$33, "phalcon/mvc/view/engine/volt/compiler.zep", 2647 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (zephir_is_true(blocksCode)) {
							ZEPHIR_CALL_FUNCTION(&compilation, "unserialize", NULL, 69, blocksCode);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(compilation);
							array_init(compilation);
						}
					}
				}
			} else {
				ZEPHIR_INIT_VAR(_9$$36);
				if (extendsMode) {
					ZVAL_BOOL(_9$$36, 1);
				} else {
					ZVAL_BOOL(_9$$36, 0);
				}
				ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilefile", NULL, 0, templatePath, realCompiledPath, _9$$36);
				zephir_check_call_status();
			}
		} else {
			if (!((zephir_file_exists(realCompiledPath TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_INIT_VAR(_10$$38);
				if (extendsMode) {
					ZVAL_BOOL(_10$$38, 1);
				} else {
					ZVAL_BOOL(_10$$38, 0);
				}
				ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilefile", NULL, 0, templatePath, realCompiledPath, _10$$38);
				zephir_check_call_status();
			}
		}
	}
	zephir_update_property_this(getThis(), SL("_compiledTemplatePath"), realCompiledPath TSRMLS_CC);
	RETURN_CCTOR(compilation);

}

/**
 * Returns the path that is currently being compiled
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getTemplatePath) {

	

	RETURN_MEMBER(getThis(), "_currentPath");

}

/**
 * Returns the path to the last compiled template
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath) {

	

	RETURN_MEMBER(getThis(), "_compiledTemplatePath");

}

/**
 * Parses a Volt template returning its intermediate representation
 *
 *<code>
 * print_r(
 *     $compiler->parse("{{ 3 + 2 }}")
 * );
 *</code>
 *
 * @param string viewCode
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, parse) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *viewCode_param = NULL, *currentPath = NULL;
	zval *viewCode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &viewCode_param);

	if (UNEXPECTED(Z_TYPE_P(viewCode_param) != IS_STRING && Z_TYPE_P(viewCode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewCode' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewCode_param) == IS_STRING)) {
		zephir_get_strval(viewCode, viewCode_param);
	} else {
		ZEPHIR_INIT_VAR(viewCode);
		ZVAL_EMPTY_STRING(viewCode);
	}


	ZEPHIR_INIT_VAR(currentPath);
	ZVAL_STRING(currentPath, "eval code", 1);
	ZEPHIR_LAST_CALL_STATUS = phvolt_parse_view(return_value, viewCode, currentPath TSRMLS_CC);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets the final path with VIEW
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFinalPath) {

	HashTable *_1$$4;
	HashPosition _0$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *view = NULL, *viewsDirs = NULL, *viewsDir = NULL, **_2$$4, *_3$$5 = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	ZEPHIR_OBS_VAR(view);
	zephir_read_property_this(&view, this_ptr, SL("_view"), PH_NOISY_CC);
	if (Z_TYPE_P(view) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&viewsDirs, view, "getviewsdir", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(viewsDirs) == IS_ARRAY) {
			zephir_is_iterable(viewsDirs, &_1$$4, &_0$$4, 0, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 2740);
			for (
			  ; zend_hash_get_current_data_ex(_1$$4, (void**) &_2$$4, &_0$$4) == SUCCESS
			  ; zend_hash_move_forward_ex(_1$$4, &_0$$4)
			) {
				ZEPHIR_GET_HVALUE(viewsDir, _2$$4);
				ZEPHIR_INIT_LNVAR(_3$$5);
				ZEPHIR_CONCAT_VV(_3$$5, viewsDir, path);
				if ((zephir_file_exists(_3$$5 TSRMLS_CC) == SUCCESS)) {
					ZEPHIR_CONCAT_VV(return_value, viewsDir, path);
					RETURN_MM();
				}
			}
			ZEPHIR_CONCAT_VV(return_value, viewsDir, path);
			RETURN_MM();
		} else {
			ZEPHIR_CONCAT_VV(return_value, viewsDirs, path);
			RETURN_MM();
		}
	}
	RETURN_CTOR(path);

}

