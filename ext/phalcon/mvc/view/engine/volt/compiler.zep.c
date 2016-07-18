
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
#include "kernel/hash.h"
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
 *	$compiler = new \Phalcon\Mvc\View\Engine\Volt\Compiler();
 *
 *	$compiler->compile('views/partials/header.volt');
 *
 *	require $compiler->getCompiledTemplatePath();
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
		zephir_update_property_this(this_ptr, SL("_view"), view TSRMLS_CC);
	}

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI) {

	

	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets the compiler options
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions) {

	zval *options_param = NULL;
	zval *options = NULL;

	zephir_fetch_params(0, 1, 0, &options_param);

	options = options_param;


	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);

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

	if (unlikely(Z_TYPE_P(option_param) != IS_STRING && Z_TYPE_P(option_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'option' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(option_param) == IS_STRING)) {
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

	if (unlikely(Z_TYPE_P(option_param) != IS_STRING && Z_TYPE_P(option_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'option' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(option_param) == IS_STRING)) {
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

	

	RETURN_MEMBER(this_ptr, "_options");

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
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *arguments = NULL, *extensions = NULL, *extension = NULL, *status = NULL, **_2$$3;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &arguments);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
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
		  ; zephir_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$3, &_0$$3)
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

	int ZEPHIR_LAST_CALL_STATUS;
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

	

	RETURN_MEMBER(this_ptr, "_extensions");

}

/**
 * Register a new function in the compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFunction) {

	zval *name_param = NULL, *definition;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
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

	

	RETURN_MEMBER(this_ptr, "_functions");

}

/**
 * Register a new filter in the compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFilter) {

	zval *name_param = NULL, *definition;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
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

	

	RETURN_MEMBER(this_ptr, "_filters");

}

/**
 * Set a unique prefix to be used as prefix for compiled variables
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setUniquePrefix) {

	zval *prefix_param = NULL;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	if (unlikely(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	}


	zephir_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Return a unique prefix to be used as prefix for compiled variables and contexts
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getUniquePrefix) {

	zval *_7$$5;
	zval *_0, *_3, *_8, *_1$$3, *_2$$3, *_4$$4, *_5$$5, *_6$$5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_currentPath"), PH_NOISY_CC);
		zephir_unique_path_key(_1$$3, _2$$3 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_prefix"), _1$$3 TSRMLS_CC);
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
			zephir_update_property_this(this_ptr, SL("_prefix"), _5$$5 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(_8);
	zephir_read_property_this(&_8, this_ptr, SL("_prefix"), PH_NOISY_CC);
	if (Z_TYPE_P(_8) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "The unique compilation prefix is invalid", "phalcon/mvc/view/engine/volt/compiler.zep", 285);
		return;
	}
	RETURN_MM_MEMBER(this_ptr, "_prefix");

}

/**
 * Resolves attribute reading
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, attributeReader) {

	zend_bool _3$$5, _8$$8;
	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *exprCode = NULL, *left = NULL, *leftType = NULL, *variable = NULL, *level = NULL, *dependencyInjector = NULL, *leftCode = NULL, *right = NULL, *_0, *_9, *_1$$4 = NULL, *_2$$4, *_4$$5 = NULL, *_5$$6, *_6$$7, *_10$$11, *_11$$12 = NULL;
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
		ZEPHIR_CALL_METHOD(&leftCode, this_ptr, "expression", &_7, 396, left);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(leftType);
		zephir_array_fetch_string(&leftType, left, SL("type"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 328 TSRMLS_CC);
		_8$$8 = !ZEPHIR_IS_LONG(leftType, '.');
		if (_8$$8) {
			_8$$8 = !ZEPHIR_IS_LONG(leftType, 350);
		}
		if (_8$$8) {
			zephir_concat_self(&exprCode, leftCode TSRMLS_CC);
		} else {
			zephir_concat_self(&exprCode, leftCode TSRMLS_CC);
		}
	}
	zephir_concat_self_str(&exprCode, SL("->") TSRMLS_CC);
	ZEPHIR_OBS_VAR(right);
	zephir_array_fetch_string(&right, expr, SL("right"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 338 TSRMLS_CC);
	zephir_array_fetch_string(&_9, right, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 340 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(_9, 265)) {
		zephir_array_fetch_string(&_10$$11, right, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 341 TSRMLS_CC);
		zephir_concat_self(&exprCode, _10$$11 TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&_11$$12, this_ptr, "expression", &_7, 396, right);
		zephir_check_call_status();
		zephir_concat_self(&exprCode, _11$$12 TSRMLS_CC);
	}
	RETURN_CCTOR(exprCode);

}

/**
 * Resolves function intermediate code into PHP function calls
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, functionCall) {

	zend_bool _8$$5;
	zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, *code = NULL, *funcArguments = NULL, *arguments = NULL, *nameExpr = NULL, *nameType = NULL, *name = NULL, *extensions = NULL, *functions = NULL, *definition = NULL, *extendedBlocks = NULL, *block = NULL, *currentBlock = NULL, *exprLevel = NULL, *escapedCode = NULL, *method = NULL, *arrayHelpers = NULL, *className = NULL, *_10 = NULL, *_2$$6, *_4$$9, *_5$$9, *_6$$9, *_7$$9, *_9$$5;
	zval *expr = NULL, *_1$$6, *_3$$12;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	expr = expr_param;


	ZEPHIR_INIT_VAR(code);
	ZVAL_NULL(code);
	ZEPHIR_INIT_VAR(funcArguments);
	ZVAL_NULL(funcArguments);
	ZEPHIR_OBS_NVAR(funcArguments);
	if (zephir_array_isset_string_fetch(&funcArguments, expr, SS("arguments"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&arguments, this_ptr, "expression", &_0, 396, funcArguments);
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
			ZEPHIR_INIT_VAR(_1$$6);
			zephir_create_array(_1$$6, 3, 0 TSRMLS_CC);
			zephir_array_fast_append(_1$$6, name);
			zephir_array_fast_append(_1$$6, arguments);
			zephir_array_fast_append(_1$$6, funcArguments);
			ZEPHIR_INIT_VAR(_2$$6);
			ZVAL_STRING(_2$$6, "compileFunction", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&code, this_ptr, "fireextensionevent", NULL, 397, _2$$6, _1$$6);
			zephir_check_temp_parameter(_2$$6);
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
						ZEPHIR_INIT_VAR(_3$$12);
						zephir_create_array(_3$$12, 2, 0 TSRMLS_CC);
						zephir_array_fast_append(_3$$12, arguments);
						zephir_array_fast_append(_3$$12, funcArguments);
						ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, definition, _3$$12);
						zephir_check_call_status();
						RETURN_MM();
					}
				}
				ZEPHIR_INIT_VAR(_4$$9);
				object_init_ex(_4$$9, phalcon_mvc_view_engine_volt_exception_ce);
				zephir_array_fetch_string(&_5$$9, expr, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 416 TSRMLS_CC);
				zephir_array_fetch_string(&_6$$9, expr, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 416 TSRMLS_CC);
				ZEPHIR_INIT_VAR(_7$$9);
				ZEPHIR_CONCAT_SVSVSV(_7$$9, "Invalid definition for user function '", name, "' in ", _5$$9, " on line ", _6$$9);
				ZEPHIR_CALL_METHOD(NULL, _4$$9, "__construct", NULL, 9, _7$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(_4$$9, "phalcon/mvc/view/engine/volt/compiler.zep", 416 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		_8$$5 = ZEPHIR_IS_STRING(name, "get_content");
		if (!(_8$$5)) {
			_8$$5 = ZEPHIR_IS_STRING(name, "content");
		}
		if (_8$$5) {
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
						ZEPHIR_CALL_METHOD(&code, this_ptr, "_statementlistorextends", NULL, 398, block);
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
		ZEPHIR_INIT_VAR(_9$$5);
		zephir_camelize(_9$$5, name, NULL  );
		ZEPHIR_CALL_FUNCTION(&method, "lcfirst", NULL, 68, _9$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(className);
		ZVAL_STRING(className, "Phalcon\\Tag", 1);
		if ((zephir_method_exists(className, method TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_OBS_VAR(arrayHelpers);
			zephir_read_property_this(&arrayHelpers, this_ptr, SL("_arrayHelpers"), PH_NOISY_CC);
			if (Z_TYPE_P(arrayHelpers) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(arrayHelpers);
				zephir_create_array(arrayHelpers, 18, 0 TSRMLS_CC);
				zephir_array_update_string(&arrayHelpers, SL("link_to"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("image"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("form"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("select"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("select_static"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("submit_button"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("radio_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("check_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("file_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("hidden_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("password_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("text_area"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("text_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("email_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("date_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("tel_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("numeric_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("image_input"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_update_property_this(this_ptr, SL("_arrayHelpers"), arrayHelpers TSRMLS_CC);
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
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "expression", &_0, 396, nameExpr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVS(return_value, _10, "(", arguments, ")");
	RETURN_MM();

}

/**
 * Resolves filter intermediate code into a valid PHP expression
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveTest) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *left = NULL;
	zval *test_param = NULL, *left_param = NULL, *type = NULL, *name = NULL, *testName = NULL, *_7 = NULL, *_0$$12 = NULL, *_1$$12, *_3$$13 = NULL, *_4$$13, *_5$$14 = NULL, *_6$$14;
	zval *test = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &test_param, &left_param);

	test = test_param;
	zephir_get_strval(left, left_param);


	ZEPHIR_OBS_VAR(type);
	zephir_array_fetch_string(&type, test, SL("type"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 568 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(type, 265)) {
		ZEPHIR_OBS_VAR(name);
		zephir_array_fetch_string(&name, test, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 575 TSRMLS_CC);
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
		zephir_array_fetch_string(&testName, test, SL("name"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 626 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(name);
		if (zephir_array_isset_string_fetch(&name, testName, SS("value"), 0 TSRMLS_CC)) {
			if (ZEPHIR_IS_STRING(name, "divisibleby")) {
				zephir_array_fetch_string(&_1$$12, test, SL("arguments"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 630 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_0$$12, this_ptr, "expression", &_2, 396, _1$$12);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVSVS(return_value, "(((", left, ") % (", _0$$12, ")) == 0)");
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(name, "sameas")) {
				zephir_array_fetch_string(&_4$$13, test, SL("arguments"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 637 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_3$$13, this_ptr, "expression", &_2, 396, _4$$13);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVSVS(return_value, "(", left, ") === (", _3$$13, ")");
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(name, "type")) {
				zephir_array_fetch_string(&_6$$14, test, SL("arguments"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 644 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_5$$14, this_ptr, "expression", &_2, 396, _6$$14);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVSVS(return_value, "gettype(", left, ") === (", _5$$14, ")");
				RETURN_MM();
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "expression", &_2, 396, test);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, left, " == ", _7);
	RETURN_MM();

}

/**
 * Resolves filter intermediate code into PHP function calls
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveFilter) {

	zend_bool _13, _14, _15;
	int ZEPHIR_LAST_CALL_STATUS;
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
	zephir_array_fetch_string(&type, filter, SL("type"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 663 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(type, 265)) {
		ZEPHIR_OBS_VAR(name);
		zephir_array_fetch_string(&name, filter, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 669 TSRMLS_CC);
	} else {
		if (!ZEPHIR_IS_LONG(type, 350)) {
			ZEPHIR_INIT_VAR(_0$$5);
			object_init_ex(_0$$5, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_1$$5, filter, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 677 TSRMLS_CC);
			zephir_array_fetch_string(&_2$$5, filter, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 677 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_3$$5);
			ZEPHIR_CONCAT_SVSV(_3$$5, "Unknown filter type in ", _1$$5, " on line ", _2$$5);
			ZEPHIR_CALL_METHOD(NULL, _0$$5, "__construct", NULL, 9, _3$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_0$$5, "phalcon/mvc/view/engine/volt/compiler.zep", 677 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(functionName);
		zephir_array_fetch_string(&functionName, filter, SL("name"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 680 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(name);
		zephir_array_fetch_string(&name, functionName, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 681 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(funcArguments);
	ZVAL_NULL(funcArguments);
	ZEPHIR_INIT_VAR(arguments);
	ZVAL_NULL(arguments);
	ZEPHIR_OBS_NVAR(funcArguments);
	if (zephir_array_isset_string_fetch(&funcArguments, filter, SS("arguments"), 0 TSRMLS_CC)) {
		if (!ZEPHIR_IS_STRING(name, "default")) {
			ZEPHIR_OBS_VAR(file);
			zephir_array_fetch_string(&file, filter, SL("file"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 696 TSRMLS_CC);
			ZEPHIR_OBS_VAR(line);
			zephir_array_fetch_string(&line, filter, SL("line"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 696 TSRMLS_CC);
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
			ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 399, funcArguments, _4$$7);
			ZEPHIR_UNREF(funcArguments);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&arguments, this_ptr, "expression", NULL, 396, funcArguments);
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
		ZEPHIR_CALL_METHOD(&code, this_ptr, "fireextensionevent", NULL, 397, _7$$9, _6$$9);
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
			zephir_array_fetch_string(&_10$$12, filter, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 759 TSRMLS_CC);
			zephir_array_fetch_string(&_11$$12, filter, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 759 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_12$$12);
			ZEPHIR_CONCAT_SVSVSV(_12$$12, "Invalid definition for user filter '", name, "' in ", _10$$12, " on line ", _11$$12);
			ZEPHIR_CALL_METHOD(NULL, _9$$12, "__construct", NULL, 9, _12$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9$$12, "phalcon/mvc/view/engine/volt/compiler.zep", 759 TSRMLS_CC);
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
	zephir_array_fetch_string(&_17, filter, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 948 TSRMLS_CC);
	zephir_array_fetch_string(&_18, filter, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 948 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_19);
	ZEPHIR_CONCAT_SVSVSV(_19, "Unknown filter \"", name, "\" in ", _17, " on line ", _18);
	ZEPHIR_CALL_METHOD(NULL, _16, "__construct", NULL, 9, _19);
	zephir_check_call_status();
	zephir_throw_exception_debug(_16, "phalcon/mvc/view/engine/volt/compiler.zep", 948 TSRMLS_CC);
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
	int ZEPHIR_LAST_CALL_STATUS;
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
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "fireextensionevent", &_2, 397, _1$$4, _0$$4);
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
			zephir_is_iterable(expr, &_4$$6, &_3$$6, 0, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 989);
			for (
			  ; zephir_hash_get_current_data_ex(_4$$6, (void**) &_5$$6, &_3$$6) == SUCCESS
			  ; zephir_hash_move_forward_ex(_4$$6, &_3$$6)
			) {
				ZEPHIR_GET_HVALUE(singleExpr, _5$$6);
				zephir_array_fetch_string(&_6$$7, singleExpr, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 982 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&singleExprCode, this_ptr, "expression", &_7, 396, _6$$7);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(name);
				if (zephir_array_isset_string_fetch(&name, singleExpr, SS("name"), 0 TSRMLS_CC)) {
					ZEPHIR_INIT_LNVAR(_8$$8);
					ZEPHIR_CONCAT_SVSV(_8$$8, "'", name, "' => ", singleExprCode);
					zephir_array_append(&items, _8$$8, PH_SEPARATE, "phalcon/mvc/view/engine/volt/compiler.zep", 984);
				} else {
					zephir_array_append(&items, singleExprCode, PH_SEPARATE, "phalcon/mvc/view/engine/volt/compiler.zep", 986);
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
			ZEPHIR_CALL_METHOD(&leftCode, this_ptr, "expression", &_7, 396, left);
			zephir_check_call_status();
		}
		if (ZEPHIR_IS_LONG(type, 311)) {
			zephir_array_fetch_string(&_10$$12, expr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1012 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "resolvetest", &_11, 0, _10$$12, leftCode);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(type, 124)) {
			zephir_array_fetch_string(&_12$$13, expr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1020 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "resolvefilter", &_13, 400, _12$$13, leftCode);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_OBS_NVAR(right);
		if (zephir_array_isset_string_fetch(&right, expr, SS("right"), 0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&rightCode, this_ptr, "expression", &_7, 396, right);
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
				zephir_array_fetch_string(&exprCode, expr, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1087 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 259)) {
				ZEPHIR_OBS_NVAR(exprCode);
				zephir_array_fetch_string(&exprCode, expr, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1091 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 260)) {
				ZEPHIR_INIT_NVAR(_14$$31);
				zephir_array_fetch_string(&_15$$31, expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1095 TSRMLS_CC);
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
				zephir_array_fetch_string(&_18$$35, expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1111 TSRMLS_CC);
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
					ZEPHIR_CALL_METHOD(&startCode, this_ptr, "expression", &_7, 396, start);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(startCode);
					ZVAL_STRING(startCode, "null", 1);
				}
				ZEPHIR_OBS_NVAR(end);
				if (zephir_array_isset_string_fetch(&end, expr, SS("end"), 0 TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&endCode, this_ptr, "expression", &_7, 396, end);
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
				zephir_array_fetch_string(&_21$$69, expr, SL("ternary"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1250 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_20$$69, this_ptr, "expression", &_7, 396, _21$$69);
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
				zephir_array_fetch_string(&exprCode, expr, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1262 TSRMLS_CC);
				break;
			}
			ZEPHIR_INIT_NVAR(_22$$73);
			object_init_ex(_22$$73, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_23$$73, expr, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1266 TSRMLS_CC);
			zephir_array_fetch_string(&_24$$73, expr, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1266 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_25$$73);
			ZEPHIR_CONCAT_SVSVSV(_25$$73, "Unknown expression ", type, " in ", _23$$73, " on line ", _24$$73);
			ZEPHIR_CALL_METHOD(NULL, _22$$73, "__construct", &_26, 9, _25$$73);
			zephir_check_call_status();
			zephir_throw_exception_debug(_22$$73, "phalcon/mvc/view/engine/volt/compiler.zep", 1266 TSRMLS_CC);
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
	int ZEPHIR_LAST_CALL_STATUS;
	zval *statements, *statement = NULL, **_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statements);



	if (Z_TYPE_P(statements) != IS_ARRAY) {
		RETVAL_ZVAL(statements, 1, 0);
		RETURN_MM();
	}
	isStatementList = 1;
	if (!(zephir_array_isset_string(statements, SS("type")))) {
		zephir_is_iterable(statements, &_1$$4, &_0$$4, 0, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 1306);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$4, (void**) &_2$$4, &_0$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$4, &_0$$4)
		) {
			ZEPHIR_GET_HVALUE(statement, _2$$4);
			if (Z_TYPE_P(statement) != IS_ARRAY) {
				isStatementList = 0;
				break;
			}
		}
	}
	if (isStatementList == 1) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_statementlist", NULL, 401, statements);
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

	HashTable *_2$$4;
	HashPosition _1$$4;
	zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, *compilation = NULL, *prefix = NULL, *level = NULL, *prefixLevel = NULL, *expr = NULL, *exprCode = NULL, *bstatement = NULL, *type = NULL, *blockStatements = NULL, *forElse = NULL, *code = NULL, *loopContext = NULL, *iterator = NULL, *key = NULL, *ifExpr = NULL, *variable = NULL, *_5, **_3$$4, *_4$$8 = NULL, *_6$$9, *_7$$9, *_8$$9, *_9$$9, *_10$$9, *_11$$9, *_12$$9, *_13$$9, *_14$$9, *_15$$11, *_16$$12, *_17$$13 = NULL, *_18$$13, *_19$$15, *_20$$15, *_21$$15, *_22$$15, *_23$$15, *_24$$15, *_25$$16, *_26$$20;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1334);
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
	zephir_array_fetch_string(&expr, statement, SL("expr"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1352 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", &_0, 396, expr);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(blockStatements);
	zephir_array_fetch_string(&blockStatements, statement, SL("block_statements"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1358 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(forElse);
	ZVAL_BOOL(forElse, 0);
	if (Z_TYPE_P(blockStatements) == IS_ARRAY) {
		zephir_is_iterable(blockStatements, &_2$$4, &_1$$4, 0, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 1384);
		for (
		  ; zephir_hash_get_current_data_ex(_2$$4, (void**) &_3$$4, &_1$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2$$4, &_1$$4)
		) {
			ZEPHIR_GET_HVALUE(bstatement, _3$$4);
			if (Z_TYPE_P(bstatement) != IS_ARRAY) {
				break;
			}
			ZEPHIR_OBS_NVAR(type);
			if (!(zephir_array_isset_string_fetch(&type, bstatement, SS("type"), 0 TSRMLS_CC))) {
				break;
			}
			if (ZEPHIR_IS_LONG(type, 321)) {
				ZEPHIR_INIT_LNVAR(_4$$8);
				ZEPHIR_CONCAT_SVS(_4$$8, "<?php $", prefixLevel, "iterated = false; ?>");
				zephir_concat_self(&compilation, _4$$8 TSRMLS_CC);
				ZEPHIR_CPY_WRT(forElse, prefixLevel);
				zephir_update_property_array(this_ptr, SL("_forElsePointers"), level, forElse TSRMLS_CC);
				break;
			}
		}
	}
	ZEPHIR_INIT_VAR(_5);
	if (extendsMode) {
		ZVAL_BOOL(_5, 1);
	} else {
		ZVAL_BOOL(_5, 0);
	}
	ZEPHIR_CALL_METHOD(&code, this_ptr, "_statementlist", NULL, 401, blockStatements, _5);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(loopContext);
	zephir_read_property_this(&loopContext, this_ptr, SL("_loopPointers"), PH_NOISY_CC);
	if (zephir_array_isset(loopContext, level)) {
		ZEPHIR_INIT_VAR(_6$$9);
		ZEPHIR_CONCAT_SVSVS(_6$$9, "<?php $", prefixLevel, "iterator = ", exprCode, "; ");
		zephir_concat_self(&compilation, _6$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7$$9);
		ZEPHIR_CONCAT_SVS(_7$$9, "$", prefixLevel, "incr = 0; ");
		zephir_concat_self(&compilation, _7$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_8$$9);
		ZEPHIR_CONCAT_SVS(_8$$9, "$", prefixLevel, "loop = new stdClass(); ");
		zephir_concat_self(&compilation, _8$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_9$$9);
		ZEPHIR_CONCAT_SVSVS(_9$$9, "$", prefixLevel, "loop->self = &$", prefixLevel, "loop; ");
		zephir_concat_self(&compilation, _9$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_10$$9);
		ZEPHIR_CONCAT_SVSVS(_10$$9, "$", prefixLevel, "loop->length = count($", prefixLevel, "iterator); ");
		zephir_concat_self(&compilation, _10$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_11$$9);
		ZEPHIR_CONCAT_SVS(_11$$9, "$", prefixLevel, "loop->index = 1; ");
		zephir_concat_self(&compilation, _11$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_12$$9);
		ZEPHIR_CONCAT_SVS(_12$$9, "$", prefixLevel, "loop->index0 = 1; ");
		zephir_concat_self(&compilation, _12$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_13$$9);
		ZEPHIR_CONCAT_SVSVS(_13$$9, "$", prefixLevel, "loop->revindex = $", prefixLevel, "loop->length; ");
		zephir_concat_self(&compilation, _13$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_14$$9);
		ZEPHIR_CONCAT_SVSVS(_14$$9, "$", prefixLevel, "loop->revindex0 = $", prefixLevel, "loop->length - 1; ?>");
		zephir_concat_self(&compilation, _14$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(iterator);
		ZEPHIR_CONCAT_SVS(iterator, "$", prefixLevel, "iterator");
	} else {
		ZEPHIR_CPY_WRT(iterator, exprCode);
	}
	ZEPHIR_OBS_VAR(variable);
	zephir_array_fetch_string(&variable, statement, SL("variable"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1414 TSRMLS_CC);
	ZEPHIR_OBS_VAR(key);
	if (zephir_array_isset_string_fetch(&key, statement, SS("key"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_15$$11);
		ZEPHIR_CONCAT_SVSVSVS(_15$$11, "<?php foreach (", iterator, " as $", key, " => $", variable, ") { ");
		zephir_concat_self(&compilation, _15$$11 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_16$$12);
		ZEPHIR_CONCAT_SVSVS(_16$$12, "<?php foreach (", iterator, " as $", variable, ") { ");
		zephir_concat_self(&compilation, _16$$12 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(ifExpr);
	if (zephir_array_isset_string_fetch(&ifExpr, statement, SS("if_expr"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_17$$13, this_ptr, "expression", &_0, 396, ifExpr);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_18$$13);
		ZEPHIR_CONCAT_SVS(_18$$13, "if (", _17$$13, ") { ?>");
		zephir_concat_self(&compilation, _18$$13 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&compilation, SL("?>") TSRMLS_CC);
	}
	if (zephir_array_isset(loopContext, level)) {
		ZEPHIR_INIT_VAR(_19$$15);
		ZEPHIR_CONCAT_SVSVS(_19$$15, "<?php $", prefixLevel, "loop->first = ($", prefixLevel, "incr == 0); ");
		zephir_concat_self(&compilation, _19$$15 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_20$$15);
		ZEPHIR_CONCAT_SVSVS(_20$$15, "$", prefixLevel, "loop->index = $", prefixLevel, "incr + 1; ");
		zephir_concat_self(&compilation, _20$$15 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_21$$15);
		ZEPHIR_CONCAT_SVSVS(_21$$15, "$", prefixLevel, "loop->index0 = $", prefixLevel, "incr; ");
		zephir_concat_self(&compilation, _21$$15 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_22$$15);
		ZEPHIR_CONCAT_SVSVSVS(_22$$15, "$", prefixLevel, "loop->revindex = $", prefixLevel, "loop->length - $", prefixLevel, "incr; ");
		zephir_concat_self(&compilation, _22$$15 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_23$$15);
		ZEPHIR_CONCAT_SVSVSVS(_23$$15, "$", prefixLevel, "loop->revindex0 = $", prefixLevel, "loop->length - ($", prefixLevel, "incr + 1); ");
		zephir_concat_self(&compilation, _23$$15 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_24$$15);
		ZEPHIR_CONCAT_SVSVSVS(_24$$15, "$", prefixLevel, "loop->last = ($", prefixLevel, "incr == ($", prefixLevel, "loop->length - 1)); ?>");
		zephir_concat_self(&compilation, _24$$15 TSRMLS_CC);
	}
	if (Z_TYPE_P(forElse) == IS_STRING) {
		ZEPHIR_INIT_VAR(_25$$16);
		ZEPHIR_CONCAT_SVS(_25$$16, "<?php $", forElse, "iterated = true; ?>");
		zephir_concat_self(&compilation, _25$$16 TSRMLS_CC);
	}
	zephir_concat_self(&compilation, code TSRMLS_CC);
	if (zephir_array_isset_string(statement, SS("if_expr"))) {
		zephir_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
	}
	if (Z_TYPE_P(forElse) == IS_STRING) {
		zephir_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
	} else {
		if (zephir_array_isset(loopContext, level)) {
			ZEPHIR_INIT_VAR(_26$$20);
			ZEPHIR_CONCAT_SVS(_26$$20, "<?php $", prefixLevel, "incr++; } ?>");
			zephir_concat_self(&compilation, _26$$20 TSRMLS_CC);
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

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, *compilation = NULL, *blockStatements = NULL, *expr = NULL, *_0 = NULL, *_1 = NULL, *_2, *_3, *_5$$4 = NULL, *_6$$4, *_7$$4;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupt statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1505);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "expression", NULL, 396, expr);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, statement, SL("true_statements"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1511 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	if (extendsMode) {
		ZVAL_BOOL(_3, 1);
	} else {
		ZVAL_BOOL(_3, 0);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_statementlist", &_4, 401, _2, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(compilation);
	ZEPHIR_CONCAT_SVSV(compilation, "<?php if (", _0, ") { ?>", _1);
	ZEPHIR_OBS_VAR(blockStatements);
	if (zephir_array_isset_string_fetch(&blockStatements, statement, SS("false_statements"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_6$$4);
		if (extendsMode) {
			ZVAL_BOOL(_6$$4, 1);
		} else {
			ZVAL_BOOL(_6$$4, 0);
		}
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "_statementlist", &_4, 401, blockStatements, _6$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_7$$4);
		ZEPHIR_CONCAT_SV(_7$$4, "<?php } else { ?>", _5$$4);
		zephir_concat_self(&compilation, _7$$4 TSRMLS_CC);
	}
	zephir_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
	RETURN_CCTOR(compilation);

}

/**
 * Compiles a "elseif" statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileElseIf) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *expr = NULL, *_0 = NULL;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	statement = statement_param;


	ZEPHIR_OBS_VAR(expr);
	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupt statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1540);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "expression", NULL, 396, expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php } elseif (", _0, ") { ?>");
	RETURN_MM();

}

/**
 * Compiles a "cache" statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCache) {

	zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, *compilation = NULL, *expr = NULL, *exprCode = NULL, *lifetime = NULL, *_1 = NULL, *_9, *_10 = NULL, *_11, *_12, *_2$$4, *_3$$4, *_4$$5, *_5$$5, *_6$$6, *_7$$6, *_8$$7, *_13$$8, *_18$$8, *_14$$9, *_15$$9, *_16$$10, *_17$$10, *_19$$11;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupt statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1560);
		return;
	}
	ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", &_0, 396, expr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "expression", &_0, 396, expr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(compilation);
	ZEPHIR_CONCAT_SVS(compilation, "<?php $_cache[", _1, "] = $this->di->get('viewCache'); ");
	ZEPHIR_OBS_VAR(lifetime);
	if (zephir_array_isset_string_fetch(&lifetime, statement, SS("lifetime"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZEPHIR_CONCAT_SVS(_2$$4, "$_cacheKey[", exprCode, "]");
		zephir_concat_self(&compilation, _2$$4 TSRMLS_CC);
		zephir_array_fetch_string(&_3$$4, lifetime, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1570 TSRMLS_CC);
		if (ZEPHIR_IS_LONG(_3$$4, 265)) {
			zephir_array_fetch_string(&_4$$5, lifetime, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1571 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_5$$5);
			ZEPHIR_CONCAT_SVSVSVS(_5$$5, " = $_cache[", exprCode, "]->start(", exprCode, ", $", _4$$5, "); ");
			zephir_concat_self(&compilation, _5$$5 TSRMLS_CC);
		} else {
			zephir_array_fetch_string(&_6$$6, lifetime, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1573 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_7$$6);
			ZEPHIR_CONCAT_SVSVSVS(_7$$6, " = $_cache[", exprCode, "]->start(", exprCode, ", ", _6$$6, "); ");
			zephir_concat_self(&compilation, _7$$6 TSRMLS_CC);
		}
	} else {
		ZEPHIR_INIT_VAR(_8$$7);
		ZEPHIR_CONCAT_SVSVSVS(_8$$7, "$_cacheKey[", exprCode, "] = $_cache[", exprCode, "]->start(", exprCode, "); ");
		zephir_concat_self(&compilation, _8$$7 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_CONCAT_SVS(_9, "if ($_cacheKey[", exprCode, "] === null) { ?>");
	zephir_concat_self(&compilation, _9 TSRMLS_CC);
	zephir_array_fetch_string(&_11, statement, SL("block_statements"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1583 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_12);
	if (extendsMode) {
		ZVAL_BOOL(_12, 1);
	} else {
		ZVAL_BOOL(_12, 0);
	}
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "_statementlist", NULL, 401, _11, _12);
	zephir_check_call_status();
	zephir_concat_self(&compilation, _10 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(lifetime);
	if (zephir_array_isset_string_fetch(&lifetime, statement, SS("lifetime"), 0 TSRMLS_CC)) {
		zephir_array_fetch_string(&_13$$8, lifetime, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1589 TSRMLS_CC);
		if (ZEPHIR_IS_LONG(_13$$8, 265)) {
			zephir_array_fetch_string(&_14$$9, lifetime, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1590 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_15$$9);
			ZEPHIR_CONCAT_SVSVSVS(_15$$9, "<?php $_cache[", exprCode, "]->save(", exprCode, ", null, $", _14$$9, "); ");
			zephir_concat_self(&compilation, _15$$9 TSRMLS_CC);
		} else {
			zephir_array_fetch_string(&_16$$10, lifetime, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1592 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_17$$10);
			ZEPHIR_CONCAT_SVSVSVS(_17$$10, "<?php $_cache[", exprCode, "]->save(", exprCode, ", null, ", _16$$10, "); ");
			zephir_concat_self(&compilation, _17$$10 TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(_18$$8);
		ZEPHIR_CONCAT_SVS(_18$$8, "} else { echo $_cacheKey[", exprCode, "]; } ?>");
		zephir_concat_self(&compilation, _18$$8 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_19$$11);
		ZEPHIR_CONCAT_SVSVSVS(_19$$11, "<?php $_cache[", exprCode, "]->save(", exprCode, "); } else { echo $_cacheKey[", exprCode, "]; } ?>");
		zephir_concat_self(&compilation, _19$$11 TSRMLS_CC);
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
	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *assignments = NULL, *assignment = NULL, *exprCode = NULL, *target = NULL, *compilation = NULL, **_2, *_3$$4, *_5$$4, *_6$$4, *_7$$5 = NULL, *_8$$6 = NULL, *_9$$7 = NULL, *_10$$8 = NULL, *_11$$9 = NULL;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	statement = statement_param;


	ZEPHIR_OBS_VAR(assignments);
	if (!(zephir_array_isset_string_fetch(&assignments, statement, SS("assignments"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1613);
		return;
	}
	ZEPHIR_INIT_VAR(compilation);
	ZVAL_STRING(compilation, "<?php", 1);
	zephir_is_iterable(assignments, &_1, &_0, 0, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 1659);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(assignment, _2);
		zephir_array_fetch_string(&_3$$4, assignment, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1623 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", &_4, 396, _3$$4);
		zephir_check_call_status();
		zephir_array_fetch_string(&_5$$4, assignment, SL("variable"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1628 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&target, this_ptr, "expression", &_4, 396, _5$$4);
		zephir_check_call_status();
		zephir_array_fetch_string(&_6$$4, assignment, SL("op"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1634 TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *expr = NULL, *_0 = NULL;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	statement = statement_param;


	ZEPHIR_OBS_VAR(expr);
	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1674);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "expression", NULL, 396, expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php ", _0, "; ?>");
	RETURN_MM();

}

/**
 * Compiles a "return" statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileReturn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *expr = NULL, *_0 = NULL;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	statement = statement_param;


	ZEPHIR_OBS_VAR(expr);
	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1694);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "expression", NULL, 396, expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php return ", _0, "; ?>");
	RETURN_MM();

}

/**
 * Compiles a "autoescape" statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileAutoEscape) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, *autoescape = NULL, *oldAutoescape = NULL, *compilation = NULL, *_0, *_1;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &statement_param, &extendsMode_param);

	statement = statement_param;
	extendsMode = zephir_get_boolval(extendsMode_param);


	ZEPHIR_OBS_VAR(autoescape);
	if (!(zephir_array_isset_string_fetch(&autoescape, statement, SS("enable"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1714);
		return;
	}
	ZEPHIR_OBS_VAR(oldAutoescape);
	zephir_read_property_this(&oldAutoescape, this_ptr, SL("_autoescape"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("_autoescape"), autoescape TSRMLS_CC);
	zephir_array_fetch_string(&_0, statement, SL("block_statements"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1723 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	if (extendsMode) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_CALL_METHOD(&compilation, this_ptr, "_statementlist", NULL, 401, _0, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_autoescape"), oldAutoescape TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *expr = NULL, *exprCode = NULL, *name = NULL, *_0, *_3, *_1$$4, *_2$$5;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	statement = statement_param;


	ZEPHIR_OBS_VAR(expr);
	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupt statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1744);
		return;
	}
	ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", NULL, 396, expr);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, expr, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1752 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(_0, 350)) {
		zephir_array_fetch_string(&name, expr, SL("name"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1754 TSRMLS_CC);
		zephir_array_fetch_string(&_1$$4, name, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1756 TSRMLS_CC);
		if (ZEPHIR_IS_LONG(_1$$4, 265)) {
			zephir_array_fetch_string(&_2$$5, name, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1761 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(_2$$5, "super")) {
				RETURN_CCTOR(exprCode);
			}
		}
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_autoescape"), PH_NOISY_CC);
	if (zephir_is_true(_3)) {
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

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *pathExpr = NULL, *path = NULL, *subCompiler = NULL, *finalPath = NULL, *compilation = NULL, *params = NULL, *_0, *_4 = NULL, *_1$$5, *_2$$6 = NULL;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	statement = statement_param;


	ZEPHIR_OBS_VAR(pathExpr);
	if (!(zephir_array_isset_string_fetch(&pathExpr, statement, SS("path"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1789);
		return;
	}
	zephir_array_fetch_string(&_0, pathExpr, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1796 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(_0, 260)) {
		if (!(zephir_array_isset_string(statement, SS("params")))) {
			ZEPHIR_OBS_VAR(path);
			zephir_array_fetch_string(&path, pathExpr, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1806 TSRMLS_CC);
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
	ZEPHIR_CALL_METHOD(&path, this_ptr, "expression", &_3, 396, pathExpr);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(params);
	if (!(zephir_array_isset_string_fetch(&params, statement, SS("params"), 0 TSRMLS_CC))) {
		ZEPHIR_CONCAT_SVS(return_value, "<?php $this->partial(", path, "); ?>");
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "expression", &_3, 396, params);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "<?php $this->partial(", path, ", ", _4, "); ?>");
	RETURN_MM();

}

/**
 * Compiles macros
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileMacro) {

	HashTable *_6$$6;
	HashPosition _5$$6;
	zephir_fcall_cache_entry *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, *code = NULL, *name = NULL, *defaultValue = NULL, *macroName = NULL, *parameters = NULL, *position = NULL, *parameter = NULL, *variableName = NULL, *blockStatements = NULL, *_0, *_19, *_1$$4, *_2$$4, *_3$$5, *_4$$6, **_7$$6, *_8$$7 = NULL, *_9$$7 = NULL, *_10$$7 = NULL, *_11$$7 = NULL, *_12$$8 = NULL, *_14$$8 = NULL, *_15$$9 = NULL, *_16$$10 = NULL, *_17$$10, *_18$$10;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &statement_param, &extendsMode_param);

	statement = statement_param;
	extendsMode = zephir_get_boolval(extendsMode_param);


	ZEPHIR_OBS_VAR(name);
	if (!(zephir_array_isset_string_fetch(&name, statement, SS("name"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1856);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_macros"), PH_NOISY_CC);
	if (zephir_array_isset(_0, name)) {
		ZEPHIR_INIT_VAR(_1$$4);
		object_init_ex(_1$$4, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(_2$$4);
		ZEPHIR_CONCAT_SVS(_2$$4, "Macro '", name, "' is already defined");
		ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 9, _2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$4, "phalcon/mvc/view/engine/volt/compiler.zep", 1863 TSRMLS_CC);
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
		zephir_is_iterable(parameters, &_6$$6, &_5$$6, 0, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 1901);
		for (
		  ; zephir_hash_get_current_data_ex(_6$$6, (void**) &_7$$6, &_5$$6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6$$6, &_5$$6)
		) {
			ZEPHIR_GET_HMKEY(position, _6$$6, _5$$6);
			ZEPHIR_GET_HVALUE(parameter, _7$$6);
			ZEPHIR_OBS_NVAR(variableName);
			zephir_array_fetch_string(&variableName, parameter, SL("variable"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1885 TSRMLS_CC);
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
				ZEPHIR_CALL_METHOD(&_12$$8, this_ptr, "expression", &_13, 396, defaultValue);
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
		ZEPHIR_CALL_METHOD(&_16$$10, this_ptr, "_statementlist", NULL, 401, blockStatements, _17$$10);
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
	zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL, *_15 = NULL, *_17 = NULL, *_20 = NULL, *_22 = NULL, *_24 = NULL, *_27 = NULL, *_29 = NULL, *_32 = NULL, *_35 = NULL, *_37 = NULL, *_39 = NULL, *_42 = NULL, *_44 = NULL, *_47 = NULL, *_50 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode, _0;
	zval *statements_param = NULL, *extendsMode_param = NULL, *extended = NULL, *blockMode = NULL, *compilation = NULL, *extensions = NULL, *statement = NULL, *tempCompilation = NULL, *type = NULL, *blockName = NULL, *blockStatements = NULL, *blocks = NULL, *path = NULL, *finalPath = NULL, *subCompiler = NULL, *level = NULL, **_3, *_4$$7 = NULL, *_5$$7, *_6$$7, *_7$$7 = NULL, *_10$$8 = NULL, *_12$$10, *_13$$11 = NULL, *_14$$11 = NULL, *_16$$12 = NULL, *_18$$13 = NULL, *_19$$13 = NULL, *_21$$14 = NULL, *_23$$15 = NULL, *_25$$21 = NULL, *_26$$21 = NULL, *_28$$22, *_30$$23 = NULL, *_31$$24 = NULL, *_33$$25 = NULL, *_34$$25 = NULL, *_36$$26 = NULL, *_38$$27 = NULL, *_40$$28 = NULL, *_41$$28 = NULL, *_43$$31 = NULL, *_45$$32 = NULL, *_46$$32 = NULL, *_48$$33 = NULL, *_49$$33 = NULL, *_51$$35 = NULL, *_52$$35, *_53$$35, *_54$$35 = NULL;
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
	zephir_is_iterable(statements, &_2, &_1, 0, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 2168);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(statement, _3);
		if (Z_TYPE_P(statement) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1973);
			return;
		}
		if (!(zephir_array_isset_string(statement, SS("type")))) {
			ZEPHIR_INIT_NVAR(_4$$7);
			object_init_ex(_4$$7, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_5$$7, statement, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1980 TSRMLS_CC);
			zephir_array_fetch_string(&_6$$7, statement, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1980 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_7$$7);
			ZEPHIR_CONCAT_SVSV(_7$$7, "Invalid statement in ", _5$$7, " on line ", _6$$7);
			ZEPHIR_CALL_METHOD(NULL, _4$$7, "__construct", &_8, 9, _7$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4$$7, "phalcon/mvc/view/engine/volt/compiler.zep", 1980 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(extensions) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_9$$8);
			zephir_create_array(_9$$8, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_9$$8, statement);
			ZEPHIR_INIT_NVAR(_10$$8);
			ZVAL_STRING(_10$$8, "compileStatement", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&tempCompilation, this_ptr, "fireextensionevent", &_11, 397, _10$$8, _9$$8);
			zephir_check_temp_parameter(_10$$8);
			zephir_check_call_status();
			if (Z_TYPE_P(tempCompilation) == IS_STRING) {
				zephir_concat_self(&compilation, tempCompilation TSRMLS_CC);
				continue;
			}
		}
		ZEPHIR_OBS_NVAR(type);
		zephir_array_fetch_string(&type, statement, SL("type"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2001 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(type, 357)) {
				zephir_array_fetch_string(&_12$$10, statement, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 2009 TSRMLS_CC);
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
			if (ZEPHIR_IS_LONG(type, 304)) {
				ZEPHIR_INIT_NVAR(_19$$13);
				if (extendsMode) {
					ZVAL_BOOL(_19$$13, 1);
				} else {
					ZVAL_BOOL(_19$$13, 0);
				}
				ZEPHIR_CALL_METHOD(&_18$$13, this_ptr, "compileforeach", &_20, 0, statement, _19$$13);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _18$$13 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 306)) {
				ZEPHIR_CALL_METHOD(&_21$$14, this_ptr, "compileset", &_22, 0, statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _21$$14 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 359)) {
				ZEPHIR_CALL_METHOD(&_23$$15, this_ptr, "compileecho", &_24, 0, statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _23$$15 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 307)) {
				ZEPHIR_OBS_NVAR(blockName);
				zephir_array_fetch_string(&blockName, statement, SL("name"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2037 TSRMLS_CC);
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
						zephir_array_append(&blocks, compilation, PH_SEPARATE, "phalcon/mvc/view/engine/volt/compiler.zep", 2052);
						ZEPHIR_INIT_NVAR(compilation);
						ZVAL_NULL(compilation);
					}
					zephir_array_update_zval(&blocks, blockName, &blockStatements, PH_COPY | PH_SEPARATE);
					zephir_update_property_this(this_ptr, SL("_blocks"), blocks TSRMLS_CC);
				} else {
					if (Z_TYPE_P(blockStatements) == IS_ARRAY) {
						ZEPHIR_INIT_NVAR(_26$$21);
						if (extendsMode) {
							ZVAL_BOOL(_26$$21, 1);
						} else {
							ZVAL_BOOL(_26$$21, 0);
						}
						ZEPHIR_CALL_METHOD(&_25$$21, this_ptr, "_statementlist", &_27, 401, blockStatements, _26$$21);
						zephir_check_call_status();
						zephir_concat_self(&compilation, _25$$21 TSRMLS_CC);
					}
				}
				break;
			}
			if (ZEPHIR_IS_LONG(type, 310)) {
				ZEPHIR_OBS_NVAR(path);
				zephir_array_fetch_string(&path, statement, SL("path"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2074 TSRMLS_CC);
				zephir_array_fetch_string(&_28$$22, path, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 2076 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&finalPath, this_ptr, "getfinalpath", &_29, 0, _28$$22);
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
					ZEPHIR_CALL_METHOD(&_30$$23, subCompiler, "getcompiledtemplatepath", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(tempCompilation);
					zephir_file_get_contents(tempCompilation, _30$$23 TSRMLS_CC);
				}
				if (1) {
					zephir_update_property_this(this_ptr, SL("_extended"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
				} else {
					zephir_update_property_this(this_ptr, SL("_extended"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				}
				zephir_update_property_this(this_ptr, SL("_extendedBlocks"), tempCompilation TSRMLS_CC);
				ZEPHIR_CPY_WRT(blockMode, extended);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 313)) {
				ZEPHIR_CALL_METHOD(&_31$$24, this_ptr, "compileinclude", &_32, 0, statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _31$$24 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 314)) {
				ZEPHIR_INIT_NVAR(_34$$25);
				if (extendsMode) {
					ZVAL_BOOL(_34$$25, 1);
				} else {
					ZVAL_BOOL(_34$$25, 0);
				}
				ZEPHIR_CALL_METHOD(&_33$$25, this_ptr, "compilecache", &_35, 0, statement, _34$$25);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _33$$25 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 316)) {
				ZEPHIR_CALL_METHOD(&_36$$26, this_ptr, "compiledo", &_37, 0, statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _36$$26 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 327)) {
				ZEPHIR_CALL_METHOD(&_38$$27, this_ptr, "compilereturn", &_39, 0, statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _38$$27 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 317)) {
				ZEPHIR_INIT_NVAR(_41$$28);
				if (extendsMode) {
					ZVAL_BOOL(_41$$28, 1);
				} else {
					ZVAL_BOOL(_41$$28, 0);
				}
				ZEPHIR_CALL_METHOD(&_40$$28, this_ptr, "compileautoescape", &_42, 0, statement, _41$$28);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _40$$28 TSRMLS_CC);
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
				ZEPHIR_CALL_METHOD(&_43$$31, this_ptr, "compileforelse", &_44, 0);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _43$$31 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 322)) {
				ZEPHIR_INIT_NVAR(_46$$32);
				if (extendsMode) {
					ZVAL_BOOL(_46$$32, 1);
				} else {
					ZVAL_BOOL(_46$$32, 0);
				}
				ZEPHIR_CALL_METHOD(&_45$$32, this_ptr, "compilemacro", &_47, 0, statement, _46$$32);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _45$$32 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 325)) {
				ZEPHIR_INIT_NVAR(_49$$33);
				if (extendsMode) {
					ZVAL_BOOL(_49$$33, 1);
				} else {
					ZVAL_BOOL(_49$$33, 0);
				}
				ZEPHIR_CALL_METHOD(&_48$$33, this_ptr, "compilecall", &_50, 0, statement, _49$$33);
				zephir_check_call_status();
				zephir_concat_self(&compilation, _48$$33 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 358)) {
				break;
			}
			ZEPHIR_INIT_NVAR(_51$$35);
			object_init_ex(_51$$35, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_52$$35, statement, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 2160 TSRMLS_CC);
			zephir_array_fetch_string(&_53$$35, statement, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 2160 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_54$$35);
			ZEPHIR_CONCAT_SVSVSV(_54$$35, "Unknown statement ", type, " in ", _52$$35, " on line ", _53$$35);
			ZEPHIR_CALL_METHOD(NULL, _51$$35, "__construct", &_8, 9, _54$$35);
			zephir_check_call_status();
			zephir_throw_exception_debug(_51$$35, "phalcon/mvc/view/engine/volt/compiler.zep", 2160 TSRMLS_CC);
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

	HashTable *_3$$7;
	HashPosition _2$$7;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *viewCode_param = NULL, *extendsMode_param = NULL, *currentPath = NULL, *intermediate = NULL, *extended = NULL, *finalCompilation = NULL, *blocks = NULL, *extendedBlocks = NULL, *name = NULL, *block = NULL, *blockCompilation = NULL, *localBlock = NULL, *compilation = NULL, *options = NULL, *autoescape = NULL, *_0, **_4$$7;
	zval *viewCode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewCode_param, &extendsMode_param);

	if (unlikely(Z_TYPE_P(viewCode_param) != IS_STRING && Z_TYPE_P(viewCode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewCode' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(viewCode_param) == IS_STRING)) {
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
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'autoescape' must be boolean", "phalcon/mvc/view/engine/volt/compiler.zep", 2205);
				return;
			}
			zephir_update_property_this(this_ptr, SL("_autoescape"), autoescape TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_VAR(intermediate);
	ZEPHIR_LAST_CALL_STATUS = phvolt_parse_view(intermediate, viewCode, currentPath TSRMLS_CC);
	zephir_check_call_status();
	if (Z_TYPE_P(intermediate) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Invalid intermediate representation", "phalcon/mvc/view/engine/volt/compiler.zep", 2217);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	if (extendsMode) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	ZEPHIR_CALL_METHOD(&compilation, this_ptr, "_statementlist", &_1, 401, intermediate, _0);
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
		zephir_is_iterable(extendedBlocks, &_3$$7, &_2$$7, 0, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 2283);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$7, (void**) &_4$$7, &_2$$7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$7, &_2$$7)
		) {
			ZEPHIR_GET_HMKEY(name, _3$$7, _2$$7);
			ZEPHIR_GET_HVALUE(block, _4$$7);
			if (Z_TYPE_P(name) == IS_STRING) {
				if (zephir_array_isset(blocks, name)) {
					ZEPHIR_OBS_NVAR(localBlock);
					zephir_array_fetch(&localBlock, blocks, name, PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2251 TSRMLS_CC);
					zephir_update_property_this(this_ptr, SL("_currentBlock"), name TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&blockCompilation, this_ptr, "_statementlist", &_1, 401, localBlock);
					zephir_check_call_status();
				} else {
					if (Z_TYPE_P(block) == IS_ARRAY) {
						ZEPHIR_CALL_METHOD(&blockCompilation, this_ptr, "_statementlist", &_1, 401, block);
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
					zephir_array_append(&finalCompilation, block, PH_SEPARATE, "phalcon/mvc/view/engine/volt/compiler.zep", 2276);
				} else {
					zephir_concat_self(&finalCompilation, block TSRMLS_CC);
				}
			}
		}
		RETURN_CCTOR(finalCompilation);
	}
	if (extendsMode == 1) {
		RETURN_MM_MEMBER(this_ptr, "_blocks");
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

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *viewCode_param = NULL, *extendsMode_param = NULL, *_0, *_1;
	zval *viewCode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewCode_param, &extendsMode_param);

	if (unlikely(Z_TYPE_P(viewCode_param) != IS_STRING && Z_TYPE_P(viewCode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewCode' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(viewCode_param) == IS_STRING)) {
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
	zephir_update_property_this(this_ptr, SL("_currentPath"), _0 TSRMLS_CC);
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
 *	$compiler->compile('views/layouts/main.volt', 'views/layouts/main.volt.php');
 *</code>
 *
 * @param string path
 * @param string compiledPath
 * @param boolean extendsMode
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileFile) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *path_param = NULL, *compiledPath_param = NULL, *extendsMode_param = NULL, *viewCode = NULL, *compilation = NULL, *finalCompilation = NULL, *_4, *_5, *_0$$4, *_2$$5;
	zval *path = NULL, *compiledPath = NULL, *_1$$4, *_3$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &path_param, &compiledPath_param, &extendsMode_param);

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}
	if (unlikely(Z_TYPE_P(compiledPath_param) != IS_STRING && Z_TYPE_P(compiledPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'compiledPath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(compiledPath_param) == IS_STRING)) {
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Template path and compilation template path cannot be the same", "phalcon/mvc/view/engine/volt/compiler.zep", 2325);
		return;
	}
	if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(_0$$4);
		object_init_ex(_0$$4, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(_1$$4);
		ZEPHIR_CONCAT_SVS(_1$$4, "Template file ", path, " does not exist");
		ZEPHIR_CALL_METHOD(NULL, _0$$4, "__construct", NULL, 9, _1$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$4, "phalcon/mvc/view/engine/volt/compiler.zep", 2332 TSRMLS_CC);
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
		ZEPHIR_CALL_METHOD(NULL, _2$$5, "__construct", NULL, 9, _3$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$5, "phalcon/mvc/view/engine/volt/compiler.zep", 2340 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("_currentPath"), path TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	if (extendsMode) {
		ZVAL_BOOL(_4, 1);
	} else {
		ZVAL_BOOL(_4, 0);
	}
	ZEPHIR_CALL_METHOD(&compilation, this_ptr, "_compilesource", NULL, 0, viewCode, _4);
	zephir_check_call_status();
	if (Z_TYPE_P(compilation) == IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&finalCompilation, "serialize", NULL, 65, compilation);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(finalCompilation, compilation);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_file_put_contents(_5, compiledPath, finalCompilation TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_5)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Volt directory can't be written", "phalcon/mvc/view/engine/volt/compiler.zep", 2359);
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
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compile) {

	zval *_2$$23;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *templatePath_param = NULL, *extendsMode_param = NULL, *stat = NULL, *compileAlways = NULL, *prefix = NULL, *compiledPath = NULL, *compiledSeparator = NULL, *blocksCode = NULL, *compiledExtension = NULL, *compilation = NULL, *options = NULL, *realCompiledPath = NULL, *compiledTemplatePath = NULL, *templateSepPath = NULL, *_0, *_1$$17 = NULL, *_3$$23, *_4$$26, *_6$$29, *_7$$30, *_8$$33, *_9$$33, *_10$$36, *_11$$38, *_12$$38;
	zval *templatePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &templatePath_param, &extendsMode_param);

	if (unlikely(Z_TYPE_P(templatePath_param) != IS_STRING && Z_TYPE_P(templatePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'templatePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(templatePath_param) == IS_STRING)) {
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
		zephir_update_property_this(this_ptr, SL("_extended"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_extended"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (0) {
		zephir_update_property_this(this_ptr, SL("_extendedBlocks"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_extendedBlocks"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("_blocks"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("_level"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("_foreachLevel"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("_blockLevel"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("_exprLevel"), _0 TSRMLS_CC);
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
			zephir_array_fetch_string(&compileAlways, options, SL("compileAlways"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2406 TSRMLS_CC);
			if (Z_TYPE_P(compileAlways) != IS_BOOL) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'compileAlways' must be a bool value", "phalcon/mvc/view/engine/volt/compiler.zep", 2408);
				return;
			}
		}
		if (zephir_array_isset_string(options, SS("prefix"))) {
			ZEPHIR_OBS_NVAR(prefix);
			zephir_array_fetch_string(&prefix, options, SL("prefix"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2416 TSRMLS_CC);
			if (Z_TYPE_P(prefix) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'prefix' must be a string", "phalcon/mvc/view/engine/volt/compiler.zep", 2418);
				return;
			}
		}
		if (zephir_array_isset_string(options, SS("compiledPath"))) {
			ZEPHIR_OBS_NVAR(compiledPath);
			zephir_array_fetch_string(&compiledPath, options, SL("compiledPath"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2426 TSRMLS_CC);
			if (Z_TYPE_P(compiledPath) != IS_STRING) {
				if (Z_TYPE_P(compiledPath) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'compiledPath' must be a string or a closure", "phalcon/mvc/view/engine/volt/compiler.zep", 2429);
					return;
				}
			}
		}
		if (zephir_array_isset_string(options, SS("compiledSeparator"))) {
			ZEPHIR_OBS_NVAR(compiledSeparator);
			zephir_array_fetch_string(&compiledSeparator, options, SL("compiledSeparator"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2438 TSRMLS_CC);
			if (Z_TYPE_P(compiledSeparator) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'compiledSeparator' must be a string", "phalcon/mvc/view/engine/volt/compiler.zep", 2440);
				return;
			}
		}
		if (zephir_array_isset_string(options, SS("compiledExtension"))) {
			ZEPHIR_OBS_NVAR(compiledExtension);
			zephir_array_fetch_string(&compiledExtension, options, SL("compiledExtension"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2448 TSRMLS_CC);
			if (Z_TYPE_P(compiledExtension) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'compiledExtension' must be a string", "phalcon/mvc/view/engine/volt/compiler.zep", 2450);
				return;
			}
		}
		if (zephir_array_isset_string(options, SS("stat"))) {
			ZEPHIR_OBS_NVAR(stat);
			zephir_array_fetch_string(&stat, options, SL("stat"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2458 TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(compiledPath) == IS_STRING) {
		if (!(ZEPHIR_IS_EMPTY(compiledPath))) {
			ZEPHIR_CALL_FUNCTION(&_1$$17, "realpath", NULL, 64, templatePath);
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
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "compiledPath closure didn't return a valid string", "phalcon/mvc/view/engine/volt/compiler.zep", 2503);
					return;
				}
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "compiledPath must be a string or a closure", "phalcon/mvc/view/engine/volt/compiler.zep", 2506);
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
		ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilefile", &_5, 0, templatePath, realCompiledPath, _4$$26);
		zephir_check_call_status();
	} else {
		if (ZEPHIR_IS_TRUE_IDENTICAL(stat)) {
			if ((zephir_file_exists(compiledTemplatePath TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_INIT_VAR(_6$$29);
				if (zephir_compare_mtime(templatePath, realCompiledPath TSRMLS_CC)) {
					ZEPHIR_INIT_VAR(_7$$30);
					if (extendsMode) {
						ZVAL_BOOL(_7$$30, 1);
					} else {
						ZVAL_BOOL(_7$$30, 0);
					}
					ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilefile", &_5, 0, templatePath, realCompiledPath, _7$$30);
					zephir_check_call_status();
				} else {
					if (extendsMode == 1) {
						ZEPHIR_INIT_VAR(blocksCode);
						zephir_file_get_contents(blocksCode, realCompiledPath TSRMLS_CC);
						if (ZEPHIR_IS_FALSE_IDENTICAL(blocksCode)) {
							ZEPHIR_INIT_VAR(_8$$33);
							object_init_ex(_8$$33, phalcon_mvc_view_engine_volt_exception_ce);
							ZEPHIR_INIT_VAR(_9$$33);
							ZEPHIR_CONCAT_SVS(_9$$33, "Extends compilation file ", realCompiledPath, " could not be opened");
							ZEPHIR_CALL_METHOD(NULL, _8$$33, "__construct", NULL, 9, _9$$33);
							zephir_check_call_status();
							zephir_throw_exception_debug(_8$$33, "phalcon/mvc/view/engine/volt/compiler.zep", 2540 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (zephir_is_true(blocksCode)) {
							ZEPHIR_CALL_FUNCTION(&compilation, "unserialize", NULL, 66, blocksCode);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(compilation);
							array_init(compilation);
						}
					}
				}
			} else {
				ZEPHIR_INIT_VAR(_10$$36);
				if (extendsMode) {
					ZVAL_BOOL(_10$$36, 1);
				} else {
					ZVAL_BOOL(_10$$36, 0);
				}
				ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilefile", &_5, 0, templatePath, realCompiledPath, _10$$36);
				zephir_check_call_status();
			}
		} else {
			if (!((zephir_file_exists(realCompiledPath TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_INIT_VAR(_11$$38);
				object_init_ex(_11$$38, phalcon_mvc_view_engine_volt_exception_ce);
				ZEPHIR_INIT_VAR(_12$$38);
				ZEPHIR_CONCAT_SVS(_12$$38, "Compiled template file ", realCompiledPath, " does not exist");
				ZEPHIR_CALL_METHOD(NULL, _11$$38, "__construct", NULL, 9, _12$$38);
				zephir_check_call_status();
				zephir_throw_exception_debug(_11$$38, "phalcon/mvc/view/engine/volt/compiler.zep", 2566 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_update_property_this(this_ptr, SL("_compiledTemplatePath"), realCompiledPath TSRMLS_CC);
	RETURN_CCTOR(compilation);

}

/**
 * Returns the path that is currently being compiled
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getTemplatePath) {

	

	RETURN_MEMBER(this_ptr, "_currentPath");

}

/**
 * Returns the path to the last compiled template
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath) {

	

	RETURN_MEMBER(this_ptr, "_compiledTemplatePath");

}

/**
 * Parses a Volt template returning its intermediate representation
 *
 *<code>
 *	print_r($compiler->parse('{{ 3 + 2 }}'));
 *</code>
 *
 * @param string viewCode
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, parse) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *viewCode_param = NULL, *currentPath = NULL;
	zval *viewCode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &viewCode_param);

	if (unlikely(Z_TYPE_P(viewCode_param) != IS_STRING && Z_TYPE_P(viewCode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewCode' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(viewCode_param) == IS_STRING)) {
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
	int ZEPHIR_LAST_CALL_STATUS;
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
			zephir_is_iterable(viewsDirs, &_1$$4, &_0$$4, 0, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 2628);
			for (
			  ; zephir_hash_get_current_data_ex(_1$$4, (void**) &_2$$4, &_0$$4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_1$$4, &_0$$4)
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

