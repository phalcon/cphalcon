
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/hash.h"
#include "phalcon/mvc/view/engine/volt/scanner.h"
#include "phalcon/mvc/view/engine/volt/volt.h"


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
 *
 * @param Phalcon\Mvc\ViewInterface view
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, __construct) {

	zval *view = NULL;

	zephir_fetch_params(0, 0, 1, &view);

	if (!view) {
		view = ZEPHIR_GLOBAL(global_null);
	}


	if ((Z_TYPE_P(view) == IS_OBJECT)) {
		zephir_update_property_this(this_ptr, SL("_view"), view TSRMLS_CC);
	}

}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, "Dependency Injector is invalid");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets the compiler options
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions) {

	zval *options;

	zephir_fetch_params(0, 1, 0, &options);



	if ((Z_TYPE_P(options) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, "Options must be an array");
		return;
	}
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

	if (Z_TYPE_P(option_param) != IS_STRING) {
		if (Z_TYPE_P(option_param) != IS_NULL) {
			zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'option' must be a string") TSRMLS_CC);
			RETURN_MM_NULL();
		}
	}

	if (Z_TYPE_P(option_param) == IS_STRING) {
		option = option_param;
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

	zval *option_param = NULL, *value, *_0;
	zval *option = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &option_param);

	if (Z_TYPE_P(option_param) != IS_STRING) {
		if (Z_TYPE_P(option_param) != IS_NULL) {
			zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'option' must be a string") TSRMLS_CC);
			RETURN_MM_NULL();
		}
	}

	if (Z_TYPE_P(option_param) == IS_STRING) {
		option = option_param;
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
 *
 * @return array
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

	HashTable *_1;
	HashPosition _0;
	zval *name_param = NULL, *arguments = NULL, *extensions, *extension = NULL, *status = NULL, **_2, *_3 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &arguments);

	if (Z_TYPE_P(name_param) != IS_STRING) {
		if (Z_TYPE_P(name_param) != IS_NULL) {
			zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
			RETURN_MM_NULL();
		}
	}

	if (Z_TYPE_P(name_param) == IS_STRING) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	extensions = zephir_fetch_nproperty_this(this_ptr, SL("_extensions"), PH_NOISY_CC);
	if ((Z_TYPE_P(extensions) == IS_ARRAY)) {
		zephir_is_iterable(extensions, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(extension, _2);
			if ((zephir_method_exists(extension, name TSRMLS_CC)  == SUCCESS)) {
				ZEPHIR_INIT_NVAR(status);
				if ((Z_TYPE_P(arguments) == IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(_3);
					array_init_size(_3, 3);
					zephir_array_fast_append(_3, extension);
					zephir_array_fast_append(_3, name);
					zephir_call_func_p2(status, "call_user_func_array", _3, arguments);
				} else {
					ZEPHIR_INIT_NVAR(_3);
					array_init_size(_3, 3);
					zephir_array_fast_append(_3, extension);
					zephir_array_fast_append(_3, name);
					zephir_call_func_p1(status, "call_user_func", _3);
				}
				if ((Z_TYPE_P(status) == IS_STRING)) {
					RETURN_CCTOR(status);
				}
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Registers a Volt's extension
 *
 * @param object extension
 * @return Phalcon\Mvc\View\Engine\Volt\Compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addExtension) {

	zval *extension;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &extension);



	if ((Z_TYPE_P(extension) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "The extension is not valid");
		return;
	}
	if ((zephir_method_exists_ex(extension, SS("initialize") TSRMLS_CC) == SUCCESS)) {
		zephir_call_method_p1_noret(extension, "initialize", this_ptr);
	}
	zephir_update_property_array_append(this_ptr, SL("_extensions"), extension TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the list of extensions registered in Volt
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getExtensions) {


	RETURN_MEMBER(this_ptr, "_extensions");

}

/**
 * Register a new function in the compiler
 *
 * @param string name
 * @param Closure|string definition
 * @return Phalcon\Mvc\View\Engine\Volt\Compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFunction) {

	zval *name_param = NULL, *definition;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition);

	if (Z_TYPE_P(name_param) != IS_STRING) {
		if (Z_TYPE_P(name_param) != IS_NULL) {
			zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
			RETURN_MM_NULL();
		}
	}

	if (Z_TYPE_P(name_param) == IS_STRING) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_array(this_ptr, SL("_functions"), name, definition TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Register the user registered functions
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFunctions) {


	RETURN_MEMBER(this_ptr, "_functions");

}

/**
 * Register a new filter in the compiler
 *
 * @param string name
 * @param Closure|string definition
 * @return Phalcon\Mvc\View\Engine\Volt\Compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFilter) {

	zval *name_param = NULL, *definition;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition);

	if (Z_TYPE_P(name_param) != IS_STRING) {
		if (Z_TYPE_P(name_param) != IS_NULL) {
			zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
			RETURN_MM_NULL();
		}
	}

	if (Z_TYPE_P(name_param) == IS_STRING) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_array(this_ptr, SL("_filters"), name, definition TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Register the user registered filters
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFilters) {


	RETURN_MEMBER(this_ptr, "_filters");

}

/**
 * Set a unique prefix to be used as prefix for compiled variables
 *
 * @param string prefix
 * @return Phalcon\Mvc\View\Engine\Volt\Compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setUniquePrefix) {

	zval *prefix_param = NULL;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	if (Z_TYPE_P(prefix_param) != IS_STRING) {
		if (Z_TYPE_P(prefix_param) != IS_NULL) {
			zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
			RETURN_MM_NULL();
		}
	}

	if (Z_TYPE_P(prefix_param) == IS_STRING) {
		prefix = prefix_param;
	} else {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	}


	zephir_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Return a unique prefix to be used as prefix for compiled variables and contexts
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getUniquePrefix) {

	zval *prefix = NULL, *calculatedPrefix, *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(prefix);
	zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	if (!(zephir_is_true(prefix))) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_currentPath"), PH_NOISY_CC);
		ZEPHIR_INIT_BNVAR(prefix);
		zephir_call_func_p1(prefix, "md5", _0);
		zephir_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
	}
	if ((Z_TYPE_P(prefix) == IS_OBJECT)) {
		if (zephir_is_instance_of(prefix, SL("Closure") TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_1);
			array_init_size(_1, 2);
			zephir_array_fast_append(_1, this_ptr);
			ZEPHIR_INIT_VAR(calculatedPrefix);
			zephir_call_func_p2(calculatedPrefix, "call_user_func_array", prefix, _1);
			zephir_update_property_this(this_ptr, SL("_prefix"), calculatedPrefix TSRMLS_CC);
			ZEPHIR_CPY_WRT(prefix, calculatedPrefix);
		}
	}
	if ((Z_TYPE_P(prefix) != IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "The unique compilation prefix is invalid");
		return;
	}
	RETURN_CCTOR(prefix);

}

/**
 * Resolves attribute reading
 *
 * @param array expr
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, attributeReader) {

	zval *expr, *exprCode, loopContext, *left, *leftType, *variable, *level, *dependencyInjector, *leftCode, *right, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr);



	ZEPHIR_INIT_VAR(exprCode);
	ZVAL_NULL(exprCode);
	ZEPHIR_SINIT_VAR(loopContext);
	ZVAL_NULL(&loopContext);
	zephir_array_fetch_string(&left, expr, SL("left"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_string(&_0, left, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_LONG(_0, 265)) {
		zephir_array_fetch_string(&variable, left, SL("value"), PH_NOISY | PH_READONLY TSRMLS_CC);
		if (ZEPHIR_IS_STRING(variable, "loop")) {
			level = zephir_fetch_nproperty_this(this_ptr, SL("_foreachLevel"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_1);
			zephir_call_method(_1, this_ptr, "getuniqueprefix");
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_CONCAT_SVVS(_2, "$", _1, level, "loop");
			zephir_concat_self(&exprCode, _2 TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("_loopPointers"), level, level TSRMLS_CC);
		} else {
			dependencyInjector = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
			if ((Z_TYPE_P(dependencyInjector) == IS_OBJECT)) {
				ZEPHIR_INIT_NVAR(_1);
				zephir_call_method_p1(_1, dependencyInjector, "has", variable);
				if (zephir_is_true(_1)) {
					ZEPHIR_INIT_LNVAR(_2);
					ZEPHIR_CONCAT_SV(_2, "$this->", variable);
					zephir_concat_self(&exprCode, _2 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_VAR(_3);
					ZEPHIR_CONCAT_SV(_3, "$", variable);
					zephir_concat_self(&exprCode, _3 TSRMLS_CC);
				}
			} else {
				ZEPHIR_INIT_LNVAR(_3);
				ZEPHIR_CONCAT_SV(_3, "$", variable);
				zephir_concat_self(&exprCode, _3 TSRMLS_CC);
			}
		}
	} else {
		ZEPHIR_INIT_VAR(leftCode);
		zephir_call_method_p1(leftCode, this_ptr, "expression", left);
		zephir_array_fetch_string(&leftType, left, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
		if (!ZEPHIR_IS_LONG(leftType, 46)) {
			if (!ZEPHIR_IS_LONG(leftType, 350)) {
				ZEPHIR_INIT_LNVAR(_2);
				ZEPHIR_CONCAT_SVS(_2, "(", leftCode, ")");
				zephir_concat_self(&exprCode, _2 TSRMLS_CC);
			} else {
				zephir_concat_self(&exprCode, leftCode TSRMLS_CC);
			}
		} else {
			zephir_concat_self(&exprCode, leftCode TSRMLS_CC);
		}
	}
	zephir_concat_self_str(&exprCode, SL("->") TSRMLS_CC);
	zephir_array_fetch_string(&right, expr, SL("right"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_string(&_4, right, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_LONG(_4, 265)) {
		zephir_array_fetch_string(&_5, right, SL("value"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_concat_self(&exprCode, _5 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		zephir_call_method_p1(_1, this_ptr, "expression", right);
		zephir_concat_self(&exprCode, _1 TSRMLS_CC);
	}
	RETURN_CCTOR(exprCode);

}

/**
 * Resolves function intermediate code into PHP function calls
 *
 * @param array expr
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, functionCall) {

	zval *expr, *code, *funcArguments = NULL, *arguments, *nameExpr, *nameType, *name, *extensions, *functions, *definition, *macros, *extendedBlocks, *block, *currentBlock, *exprLevel, *escapedCode = NULL, *method, *arrayHelpers = NULL, *className, *_0 = NULL, *_1 = NULL, *_2, *_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr);



	if ((Z_TYPE_P(expr) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted function call");
		return;
	}
	ZEPHIR_INIT_VAR(code);
	ZVAL_NULL(code);
	ZEPHIR_INIT_VAR(funcArguments);
	ZVAL_NULL(funcArguments);
	ZEPHIR_INIT_VAR(arguments);
	ZEPHIR_OBS_NVAR(funcArguments);
	if (zephir_array_isset_string_fetch(&funcArguments, expr, SS("arguments"), 0 TSRMLS_CC)) {
		zephir_call_method_p1(arguments, this_ptr, "expression", funcArguments);
	} else {
		ZVAL_STRING(arguments, "", 1);
	}
	zephir_array_fetch_string(&nameExpr, expr, SL("name"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_string(&nameType, nameExpr, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_LONG(nameType, 265)) {
		zephir_array_fetch_string(&name, nameExpr, SL("value"), PH_NOISY | PH_READONLY TSRMLS_CC);
		extensions = zephir_fetch_nproperty_this(this_ptr, SL("_extensions"), PH_NOISY_CC);
		if ((Z_TYPE_P(extensions) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(_0);
			array_init_size(_0, 5);
			zephir_array_fast_append(_0, name);
			zephir_array_fast_append(_0, arguments);
			zephir_array_fast_append(_0, funcArguments);
			ZEPHIR_INIT_VAR(_1);
			ZVAL_STRING(_1, "compileFunction", 1);
			ZEPHIR_INIT_BNVAR(code);
			zephir_call_method_p2(code, this_ptr, "fireextensionevent", _1, _0);
			if ((Z_TYPE_P(code) == IS_STRING)) {
				RETURN_CCTOR(code);
			}
		}
		functions = zephir_fetch_nproperty_this(this_ptr, SL("_functions"), PH_NOISY_CC);
		if ((Z_TYPE_P(functions) == IS_ARRAY)) {
			if (zephir_array_isset_fetch(&definition, functions, name, 1 TSRMLS_CC)) {
				if ((Z_TYPE_P(definition) == IS_STRING)) {
					ZEPHIR_CONCAT_VSVS(return_value, definition, "(", arguments, ")");
					RETURN_MM();
				}
				if ((Z_TYPE_P(definition) == IS_OBJECT)) {
					if (zephir_is_instance_of(definition, SL("Closure") TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(_0);
						array_init_size(_0, 3);
						zephir_array_fast_append(_0, arguments);
						zephir_array_fast_append(_0, funcArguments);
						zephir_call_func_p2(return_value, "call_user_func_array", definition, _0);
						RETURN_MM();
					}
				}
				ZEPHIR_INIT_NVAR(_1);
				object_init_ex(_1, phalcon_mvc_view_exception_ce);
				zephir_array_fetch_string(&_2, expr, SL("file"), PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_array_fetch_string(&_3, expr, SL("line"), PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_INIT_VAR(_4);
				ZEPHIR_CONCAT_SVSVSV(_4, "Invalid definition for user function '", name, "' in ", _2, " on line ", _3);
				zephir_call_method_p1_noret(_1, "__construct", _4);
				zephir_throw_exception(_1 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		macros = zephir_fetch_nproperty_this(this_ptr, SL("_macros"), PH_NOISY_CC);
		if (zephir_array_isset(macros, name)) {
			ZEPHIR_CONCAT_SVSVS(return_value, "vmacro_", name, "(array(", arguments, "))");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(name, "get_content")) {
			RETURN_MM_STRING("$this->getContent()", 1);
		}
		if (ZEPHIR_IS_STRING(name, "content")) {
			RETURN_MM_STRING("$this->getContent()", 1);
		}
		if (ZEPHIR_IS_STRING(name, "partial")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->partial(", arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(name, "super")) {
			extendedBlocks = zephir_fetch_nproperty_this(this_ptr, SL("_extendedBlocks"), PH_NOISY_CC);
			if ((Z_TYPE_P(extendedBlocks) == IS_ARRAY)) {
				currentBlock = zephir_fetch_nproperty_this(this_ptr, SL("_currentBlock"), PH_NOISY_CC);
				if (zephir_array_isset_fetch(&block, extendedBlocks, currentBlock, 1 TSRMLS_CC)) {
					exprLevel = zephir_fetch_nproperty_this(this_ptr, SL("_exprLevel"), PH_NOISY_CC);
					if ((Z_TYPE_P(block) == IS_ARRAY)) {
						ZEPHIR_INIT_BNVAR(code);
						zephir_call_method_p1(code, this_ptr, "_statementlistorextends", block);
						if (ZEPHIR_IS_LONG(exprLevel, 1)) {
							ZEPHIR_CPY_WRT(escapedCode, code);
						} else {
							ZEPHIR_INIT_VAR(escapedCode);
							zephir_call_func_p1(escapedCode, "addslashes", code);
						}
					} else {
						if (ZEPHIR_IS_LONG(exprLevel, 1)) {
							ZEPHIR_CPY_WRT(escapedCode, block);
						} else {
							ZEPHIR_INIT_NVAR(escapedCode);
							zephir_call_func_p1(escapedCode, "addslashes", block);
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
		ZEPHIR_INIT_NVAR(_0);
		zephir_camelize(_0, name);
		ZEPHIR_INIT_VAR(method);
		zephir_call_func_p1(method, "lcfirst", _0);
		ZEPHIR_INIT_VAR(className);
		ZVAL_STRING(className, "Phalcon\\Tag", 1);
		if ((zephir_method_exists(className, method TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_OBS_VAR(arrayHelpers);
			zephir_read_property_this(&arrayHelpers, this_ptr, SL("_arrayHelpers"), PH_NOISY_CC);
			if ((Z_TYPE_P(arrayHelpers) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(arrayHelpers);
				array_init_size(arrayHelpers, 17);
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
				zephir_array_update_string(&arrayHelpers, SL("date_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("numeric_field"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_update_property_this(this_ptr, SL("_arrayHelpers"), arrayHelpers TSRMLS_CC);
			}
			if (zephir_array_isset(arrayHelpers, name)) {
				ZEPHIR_CONCAT_SVSVS(return_value, "$this->tag->", method, "(array(", arguments, "))");
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
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_mvc_view_exception_ce);
		zephir_array_fetch_string(&_2, expr, SL("file"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch_string(&_3, expr, SL("line"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SVSVSV(_4, "Undefined function '", name, "' in ", _2, " on line ", _3);
		zephir_call_method_p1_noret(_0, "__construct", _4);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(_0);
	zephir_call_method_p1(_0, this_ptr, "expression", nameExpr);
	ZEPHIR_CONCAT_VSVS(return_value, _0, "(", arguments, ")");
	RETURN_MM();

}

/**
 * Resolves filter intermediate code into a valid PHP expression
 *
 * @param array test
 * @param string left
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveTest) {

	zval *test, *left, *type, *name = NULL, *testName, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &test, &left);



	if ((Z_TYPE_P(test) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted test");
		return;
	}
	zephir_array_fetch_string(&type, test, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_LONG(type, 265)) {
		ZEPHIR_OBS_VAR(name);
		zephir_array_fetch_string(&name, test, SL("value"), PH_NOISY TSRMLS_CC);
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
		zephir_array_fetch_string(&testName, test, SL("name"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(name);
		if (zephir_array_isset_string_fetch(&name, testName, SS("value"), 0 TSRMLS_CC)) {
			if (ZEPHIR_IS_STRING(name, "divisibleby")) {
				ZEPHIR_INIT_VAR(_0);
				zephir_array_fetch_string(&_1, test, SL("arguments"), PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_call_method_p1(_0, this_ptr, "expression", _1);
				ZEPHIR_CONCAT_SVSVS(return_value, "(((", left, ") % (", _0, ")) == 0)");
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(name, "sameas")) {
				ZEPHIR_INIT_NVAR(_0);
				zephir_array_fetch_string(&_1, test, SL("arguments"), PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_call_method_p1(_0, this_ptr, "expression", _1);
				ZEPHIR_CONCAT_SVSVS(return_value, "(", left, ") === (", _0, ")");
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(name, "type")) {
				ZEPHIR_INIT_NVAR(_0);
				zephir_array_fetch_string(&_1, test, SL("arguments"), PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_call_method_p1(_0, this_ptr, "expression", _1);
				ZEPHIR_CONCAT_SVSVS(return_value, "gettype(", left, ") === (", _0, ")");
				RETURN_MM();
			}
		}
	}
	ZEPHIR_INIT_NVAR(_0);
	zephir_call_method_p1(_0, this_ptr, "expression", test);
	ZEPHIR_CONCAT_VSV(return_value, left, " == ", _0);
	RETURN_MM();

}

/**
 * Resolves filter intermediate code into PHP function calls
 *
 * @param array filter
 * @param string left
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveFilter) {

	zval *filter, *left, *code, *type, *functionName, *name = NULL, *file, *line, *extensions, *filters, *funcArguments = NULL, *arguments = NULL, *definition, *_0 = NULL, *_1, *_2, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &filter, &left);



	if ((Z_TYPE_P(filter) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted filter");
		return;
	}
	ZEPHIR_INIT_VAR(code);
	ZVAL_NULL(code);
	zephir_array_fetch_string(&type, filter, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_LONG(type, 265)) {
		ZEPHIR_OBS_VAR(name);
		zephir_array_fetch_string(&name, filter, SL("value"), PH_NOISY TSRMLS_CC);
	} else {
		if (ZEPHIR_IS_LONG(type, 350)) {
			zephir_array_fetch_string(&functionName, filter, SL("name"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_OBS_NVAR(name);
			zephir_array_fetch_string(&name, functionName, SL("value"), PH_NOISY TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_0);
			object_init_ex(_0, phalcon_mvc_view_exception_ce);
			zephir_array_fetch_string(&_1, filter, SL("file"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_string(&_2, filter, SL("line"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_VAR(_3);
			ZEPHIR_CONCAT_SVSV(_3, "Unknown filter type in ", _1, " on line ", _2);
			zephir_call_method_p1_noret(_0, "__construct", _3);
			zephir_throw_exception(_0 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(funcArguments);
	ZVAL_NULL(funcArguments);
	ZEPHIR_INIT_VAR(arguments);
	ZVAL_NULL(arguments);
	ZEPHIR_OBS_NVAR(funcArguments);
	if (zephir_array_isset_string_fetch(&funcArguments, filter, SS("arguments"), 0 TSRMLS_CC)) {
		if (!ZEPHIR_IS_STRING(name, "default")) {
			zephir_array_fetch_string(&file, filter, SL("file"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_string(&line, filter, SL("line"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_0);
			array_init_size(_0, 5);
			ZEPHIR_INIT_VAR(_4);
			array_init_size(_4, 5);
			add_assoc_long_ex(_4, SS("type"), 364);
			zephir_array_update_string(&_4, SL("value"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4, SL("file"), &file, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4, SL("line"), &line, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_0, SL("expr"), &_4, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_0, SL("file"), &file, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_0, SL("line"), &line, PH_COPY | PH_SEPARATE);
			Z_SET_ISREF_P(funcArguments);
			zephir_call_func_p2_noret("array_unshift", funcArguments, _0);
		}
		ZEPHIR_INIT_BNVAR(arguments);
		zephir_call_method_p1(arguments, this_ptr, "expression", funcArguments);
	} else {
		ZEPHIR_CPY_WRT(arguments, left);
	}
	extensions = zephir_fetch_nproperty_this(this_ptr, SL("_extensions"), PH_NOISY_CC);
	if ((Z_TYPE_P(extensions) == IS_ARRAY)) {
		ZEPHIR_INIT_NVAR(_0);
		array_init_size(_0, 3);
		zephir_array_fast_append(_0, arguments);
		zephir_array_fast_append(_0, funcArguments);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "compileFilter", 1);
		ZEPHIR_INIT_BNVAR(code);
		zephir_call_method_p2(code, this_ptr, "fireextensionevent", _4, _0);
		if ((Z_TYPE_P(code) == IS_STRING)) {
			RETURN_CCTOR(code);
		}
	}
	filters = zephir_fetch_nproperty_this(this_ptr, SL("_filters"), PH_NOISY_CC);
	if ((Z_TYPE_P(filters) == IS_ARRAY)) {
		if (zephir_array_isset_fetch(&definition, filters, name, 1 TSRMLS_CC)) {
			if ((Z_TYPE_P(definition) == IS_STRING)) {
				ZEPHIR_CONCAT_VSVS(return_value, definition, "(", arguments, ")");
				RETURN_MM();
			}
			if ((Z_TYPE_P(definition) == IS_OBJECT)) {
				if (zephir_is_instance_of(definition, SL("Closure") TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_0);
					array_init_size(_0, 3);
					zephir_array_fast_append(_0, arguments);
					zephir_array_fast_append(_0, funcArguments);
					zephir_call_func_p2(return_value, "call_user_func_array", definition, _0);
					RETURN_MM();
				}
			}
			ZEPHIR_INIT_NVAR(_4);
			object_init_ex(_4, phalcon_mvc_view_exception_ce);
			zephir_array_fetch_string(&_1, filter, SL("file"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_string(&_2, filter, SL("line"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_3);
			ZEPHIR_CONCAT_SVSVSV(_3, "Invalid definition for user filter '", name, "' in ", _1, " on line ", _2);
			zephir_call_method_p1_noret(_4, "__construct", _3);
			zephir_throw_exception(_4 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (ZEPHIR_IS_STRING(name, "length")) {
		ZEPHIR_CONCAT_SVS(return_value, "this->length(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "e")) {
		ZEPHIR_CONCAT_SVS(return_value, "this->escaper->escapeHtml(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "escape")) {
		ZEPHIR_CONCAT_SVS(return_value, "this->escaper->escapeHtml(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "escape_css")) {
		ZEPHIR_CONCAT_SVS(return_value, "this->escaper->escapeCss(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "escape_js")) {
		ZEPHIR_CONCAT_SVS(return_value, "this->escaper->escapeJs(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "escape_attr")) {
		ZEPHIR_CONCAT_SVS(return_value, "this->escaper->escapeHtmlAttr(", arguments, ")");
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
	if (ZEPHIR_IS_STRING(name, "lowercase")) {
		ZEPHIR_CONCAT_SVS(return_value, "Phalcon\\Text::lower(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "lower")) {
		ZEPHIR_CONCAT_SVS(return_value, "Phalcon\\Text::lower(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "uppercase")) {
		ZEPHIR_CONCAT_SVS(return_value, "Phalcon\\Text::upper(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "upper")) {
		ZEPHIR_CONCAT_SVS(return_value, "Phalcon\\Text::upper(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "capitalize")) {
		ZEPHIR_CONCAT_SVS(return_value, "ucwords(", arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "sort")) {
		ZEPHIR_CONCAT_SVS(return_value, "this->sort(", arguments, ")");
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
	ZEPHIR_INIT_NVAR(_0);
	object_init_ex(_0, phalcon_mvc_view_exception_ce);
	zephir_array_fetch_string(&_1, filter, SL("file"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_string(&_2, filter, SL("line"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_3);
	ZEPHIR_CONCAT_SVSVSV(_3, "Unknown filter '", name, "' in ", _1, " on line ", _2);
	zephir_call_method_p1_noret(_0, "__construct", _3);
	zephir_throw_exception(_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Resolves an expression node in an AST volt tree
 *
 * @param array expr
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, expression) {

	HashTable *_4;
	HashPosition _3;
	zend_function *_2 = NULL, *_7 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_13 = NULL, *_14 = NULL, *_17 = NULL, *_18 = NULL, *_19 = NULL, *_20 = NULL, *_22 = NULL;
	zval *expr, *exprCode = NULL, *extensions, *items = NULL, *singleExpr = NULL, *singleExprCode = NULL, *name, *left, *leftCode = NULL, *right, *rightCode = NULL, *type, *startCode = NULL, *endCode = NULL, *start, *end, *_0 = NULL, *_1 = NULL, **_5, *_6, *_8 = NULL, *_12, _15 = zval_used_for_init, _16 = zval_used_for_init, *_21;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr);



	if ((Z_TYPE_P(expr) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted expression");
		return;
	}
	ZEPHIR_INIT_VAR(exprCode);
	ZVAL_NULL(exprCode);
	extensions = zephir_fetch_nproperty_this(this_ptr, SL("_extensions"), PH_NOISY_CC);
	while (1) {
		if ((Z_TYPE_P(extensions) == IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_0);
			array_init_size(_0, 2);
			zephir_array_fast_append(_0, expr);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "resolveExpression", 1);
			ZEPHIR_INIT_NVAR(exprCode);
			zephir_call_method_p2_cache(exprCode, this_ptr, "fireextensionevent", &_2, _1, _0);
			if ((Z_TYPE_P(exprCode) == IS_STRING)) {
				break;
			}
		}
		if (!(zephir_array_isset_string(expr, SS("type")))) {
			ZEPHIR_INIT_NVAR(items);
			array_init(items);
			zephir_is_iterable(expr, &_4, &_3, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
				; zend_hash_move_forward_ex(_4, &_3)
			) {
				ZEPHIR_GET_HVALUE(singleExpr, _5);
				zephir_array_fetch_string(&_6, singleExpr, SL("expr"), PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_INIT_NVAR(singleExprCode);
				zephir_call_method_p1_cache(singleExprCode, this_ptr, "expression", &_7, _6);
				if (zephir_array_isset_string_fetch(&name, singleExpr, SS("name"), 1 TSRMLS_CC)) {
					ZEPHIR_INIT_LNVAR(_8);
					ZEPHIR_CONCAT_SVSV(_8, "'", name, "' => ", singleExprCode);
					zephir_array_append(&items, _8, PH_SEPARATE);
				} else {
					zephir_array_append(&items, singleExprCode, PH_SEPARATE);
				}
			}
			ZEPHIR_INIT_NVAR(exprCode);
			zephir_fast_join_str(exprCode, SL(", "), items TSRMLS_CC);
			break;
		}
		zephir_array_fetch_string(&type, expr, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
		if (ZEPHIR_IS_LONG(type, 46)) {
			ZEPHIR_INIT_NVAR(exprCode);
			zephir_call_method_p1_cache(exprCode, this_ptr, "attributereader", &_9, expr);
			break;
		}
		if (zephir_array_isset_string_fetch(&left, expr, SS("left"), 1 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(leftCode);
			zephir_call_method_p1_cache(leftCode, this_ptr, "expression", &_10, left);
		}
		if (ZEPHIR_IS_LONG(type, 311)) {
			zephir_array_fetch_string(&_6, expr, SL("right"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_NVAR(exprCode);
			zephir_call_method_p2_cache(exprCode, this_ptr, "resolvetest", &_11, _6, leftCode);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 124)) {
			zephir_array_fetch_string(&_12, expr, SL("right"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_NVAR(exprCode);
			zephir_call_method_p2_cache(exprCode, this_ptr, "resolvefilter", &_13, _12, leftCode);
			break;
		}
		if (zephir_array_isset_string_fetch(&right, expr, SS("right"), 1 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(rightCode);
			zephir_call_method_p1_cache(rightCode, this_ptr, "expression", &_14, right);
		}
		ZEPHIR_INIT_NVAR(exprCode);
		ZVAL_NULL(exprCode);
		do {
			if (ZEPHIR_IS_LONG(type, 33)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SV(exprCode, "!", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 42)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " * ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 43)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " + ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 45)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " - ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 47)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " / ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 37)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_VSV(exprCode, leftCode, " % ", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 60)) {
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
					ZEPHIR_CONCAT_SVS(exprCode, "array(", leftCode, ")");
				} else {
					ZVAL_STRING(exprCode, "array()", 1);
				}
				break;
			}
			if (ZEPHIR_IS_LONG(type, 258)) {
				ZEPHIR_OBS_NVAR(exprCode);
				zephir_array_fetch_string(&exprCode, expr, SL("value"), PH_NOISY TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 259)) {
				ZEPHIR_OBS_NVAR(exprCode);
				zephir_array_fetch_string(&exprCode, expr, SL("value"), PH_NOISY TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 260)) {
				ZEPHIR_INIT_NVAR(_0);
				zephir_array_fetch_string(&_6, expr, SL("value"), PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_15);
				ZVAL_STRING(&_15, "'", 0);
				ZEPHIR_SINIT_NVAR(_16);
				ZVAL_STRING(&_16, "\\'", 0);
				zephir_fast_str_replace(_0, &_15, &_16, _6);
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVS(exprCode, "'", _0, "'");
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
				zephir_array_fetch_string(&_12, expr, SL("value"), PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SV(exprCode, "$", _12);
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
				ZEPHIR_INIT_NVAR(exprCode);
				zephir_call_method_p1_cache(exprCode, this_ptr, "functioncall", &_17, expr);
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
				ZEPHIR_INIT_NVAR(startCode);
				if (zephir_array_isset_string_fetch(&start, expr, SS("start"), 1 TSRMLS_CC)) {
					zephir_call_method_p1_cache(startCode, this_ptr, "expression", &_18, start);
				} else {
					ZVAL_STRING(startCode, "null", 1);
				}
				ZEPHIR_INIT_NVAR(endCode);
				if (zephir_array_isset_string_fetch(&end, expr, SS("end"), 1 TSRMLS_CC)) {
					zephir_call_method_p1_cache(endCode, this_ptr, "expression", &_19, end);
				} else {
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
			if (ZEPHIR_IS_LONG(type, 309)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVSVS(exprCode, "$this->isIncluded(", leftCode, ", ", rightCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 369)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVSVS(exprCode, "!$this->isIncluded(", leftCode, ", ", rightCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 366)) {
				ZEPHIR_INIT_NVAR(_0);
				zephir_array_fetch_string(&_6, expr, SL("ternary"), PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_call_method_p1_cache(_0, this_ptr, "expression", &_20, _6);
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SVSVSVS(exprCode, "(", _0, " ? ", leftCode, " : ", rightCode, ")");
				break;
			}
			if (ZEPHIR_IS_LONG(type, 367)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SV(exprCode, "-", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 368)) {
				ZEPHIR_INIT_NVAR(exprCode);
				ZEPHIR_CONCAT_SV(exprCode, "+", rightCode);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 364)) {
				ZEPHIR_OBS_NVAR(exprCode);
				zephir_array_fetch_string(&exprCode, expr, SL("value"), PH_NOISY TSRMLS_CC);
				break;
			}
			ZEPHIR_INIT_NVAR(_0);
			object_init_ex(_0, phalcon_mvc_view_exception_ce);
			zephir_array_fetch_string(&_12, expr, SL("file"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_string(&_21, expr, SL("line"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_8);
			ZEPHIR_CONCAT_SVSVSV(_8, "Unknown expression ", type, " in ", _12, " on line ", _21);
			zephir_call_method_p1_cache_noret(_0, "__construct", &_22, _8);
			zephir_throw_exception(_0 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

		break;
	}
	RETURN_CCTOR(exprCode);

}

/**
 * Compiles a block of statements
 *
 * @param array statements
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementListOrExtends) {

	HashTable *_1;
	HashPosition _0;
	zend_bool isStatementList;
	zval *statements, *statement = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statements);



	if ((Z_TYPE_P(statements) == IS_ARRAY)) {
		RETURN_CCTOR(statements);
	}
	isStatementList = 1;
	if (!(zephir_array_isset_string(statements, SS("type")))) {
		zephir_is_iterable(statements, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(statement, _2);
			if ((Z_TYPE_P(statement) != IS_ARRAY)) {
				isStatementList = 0;
				break;
			}
		}
	}
	if ((isStatementList == 1)) {
		zephir_call_method_p1(return_value, this_ptr, "_statementlist", statements);
		RETURN_MM();
	}
	RETURN_CCTOR(statements);

}

/**
 * Compiles a "foreach" intermediate code representation into plain PHP code
 *
 * @param array statement
 * @param boolean extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForeach) {

	HashTable *_1;
	HashPosition _0;
	zend_bool extendsMode;
	zval *statement, *extendsMode_param = NULL, *compilation, *prefix, *level, *prefixLevel, *expr, *exprCode, *bstatement = NULL, *type, *blockStatements, *forElse = NULL, *code, *loopContext, *iterator = NULL, *key, *ifExpr, *variable, **_2, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10, *_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement, &extendsMode_param);

	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	if (!(zephir_array_isset_string(statement, SS("expr")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	ZEPHIR_INIT_VAR(compilation);
	ZVAL_STRING(compilation, "", 1);
	ZEPHIR_INIT_VAR(forElse);
	ZVAL_NULL(forElse);
	ZEPHIR_INIT_VAR(prefix);
	zephir_call_method(prefix, this_ptr, "getuniqueprefix");
	level = zephir_fetch_nproperty_this(this_ptr, SL("_foreachLevel"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixLevel);
	ZEPHIR_CONCAT_VV(prefixLevel, prefix, level);
	zephir_array_fetch_string(&expr, statement, SL("expr"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_VAR(exprCode);
	zephir_call_method_p1(exprCode, this_ptr, "expression", expr);
	zephir_array_fetch_string(&blockStatements, statement, SL("block_statements"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(forElse);
	ZVAL_BOOL(forElse, 0);
	if ((Z_TYPE_P(blockStatements) == IS_ARRAY)) {
		zephir_is_iterable(blockStatements, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(bstatement, _2);
			if ((Z_TYPE_P(bstatement) != IS_ARRAY)) {
				break;
			}
			if (!(zephir_array_isset_string_fetch(&type, bstatement, SS("type"), 1 TSRMLS_CC))) {
				break;
			}
			if (ZEPHIR_IS_LONG(type, 321)) {
				ZEPHIR_INIT_LNVAR(_3);
				ZEPHIR_CONCAT_SVS(_3, "<?php $", prefixLevel, "iterated = false; ?>");
				zephir_concat_self(&compilation, _3 TSRMLS_CC);
				ZEPHIR_CPY_WRT(forElse, prefixLevel);
				zephir_update_property_array(this_ptr, SL("_forElsePointers"), level, forElse TSRMLS_CC);
				break;
			}
		}
	}
	ZEPHIR_INIT_VAR(code);
	zephir_call_method_p2(code, this_ptr, "_statementlist", blockStatements, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	loopContext = zephir_fetch_nproperty_this(this_ptr, SL("_loopPointers"), PH_NOISY_CC);
	if (zephir_array_isset(loopContext, level)) {
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SVSVS(_3, "<?php $", prefixLevel, "iterator = ", exprCode, "; ");
		zephir_concat_self(&compilation, _3 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SVS(_4, "$", prefixLevel, "incr = 0; ");
		zephir_concat_self(&compilation, _4 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_SVS(_5, "$", prefixLevel, "loop = new stdClass(); ");
		zephir_concat_self(&compilation, _5 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_CONCAT_SVSVS(_6, "$", prefixLevel, "loop->length = count(", prefixLevel, "iterator); ");
		zephir_concat_self(&compilation, _6 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_SVS(_7, "$", prefixLevel, "loop->index = 1; ");
		zephir_concat_self(&compilation, _7 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_CONCAT_SVS(_8, "$", prefixLevel, "loop->index0 = 1; ");
		zephir_concat_self(&compilation, _8 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_9);
		ZEPHIR_CONCAT_SVSVS(_9, "$", prefixLevel, "loop->revindex = ", prefixLevel, "loop->length; ");
		zephir_concat_self(&compilation, _9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_10);
		ZEPHIR_CONCAT_SVSVS(_10, "$", prefixLevel, "loop->revindex0 = ", prefixLevel, "loop->length - 1; ?>");
		zephir_concat_self(&compilation, _10 TSRMLS_CC);
		ZEPHIR_INIT_VAR(iterator);
		ZEPHIR_CONCAT_SVS(iterator, "$", prefixLevel, "iterator");
	} else {
		ZEPHIR_CPY_WRT(iterator, exprCode);
	}
	zephir_array_fetch_string(&variable, statement, SL("variable"), PH_NOISY | PH_READONLY TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&key, statement, SS("key"), 1 TSRMLS_CC)) {
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SVSVSVS(_4, "<?php foreach (", iterator, " as ", key, " => ", variable, ") { ");
		zephir_concat_self(&compilation, _4 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SVSVS(_4, "<?php foreach (", iterator, " as ", variable, ") { ");
		zephir_concat_self(&compilation, _4 TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&ifExpr, statement, SS("if_expr"), 1 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_11);
		zephir_call_method_p1(_11, this_ptr, "expression", ifExpr);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SVS(_4, "if (", _11, ") { ?>");
		zephir_concat_self(&compilation, _4 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&compilation, SL("?>") TSRMLS_CC);
	}
	if (zephir_array_isset(loopContext, level)) {
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SVSVS(_4, "<?php $", prefixLevel, "loop->first = (", prefixLevel, "incr == 0); ");
		zephir_concat_self(&compilation, _4 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_5);
		ZEPHIR_CONCAT_SVSVS(_5, "$", prefixLevel, "loop->index = ", prefixLevel, "incr + 1; ");
		zephir_concat_self(&compilation, _5 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_6);
		ZEPHIR_CONCAT_SVSVS(_6, "$", prefixLevel, "loop->index0 = ", prefixLevel, "incr; ");
		zephir_concat_self(&compilation, _6 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_7);
		ZEPHIR_CONCAT_SVSVSVS(_7, "$", prefixLevel, "loop->revindex = ", prefixLevel, "loop->length - ", prefixLevel, "incr; ");
		zephir_concat_self(&compilation, _7 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_8);
		ZEPHIR_CONCAT_SVSVSVS(_8, "$", prefixLevel, "loop->revindex0 = ", prefixLevel, "loop->length - (", prefixLevel, "incr + 1); ");
		zephir_concat_self(&compilation, _8 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_9);
		ZEPHIR_CONCAT_SVSVSVS(_9, "$", prefixLevel, "loop->last = (", prefixLevel, "incr == (", prefixLevel, "loop->length - 1)); ?>");
		zephir_concat_self(&compilation, _9 TSRMLS_CC);
	}
	if ((Z_TYPE_P(forElse) == IS_STRING)) {
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SVS(_4, "<?php $", forElse, "iterated = true; ?>");
		zephir_concat_self(&compilation, _4 TSRMLS_CC);
	}
	zephir_concat_self(&compilation, code TSRMLS_CC);
	if (zephir_array_isset_string(statement, SS("if_expr"))) {
		zephir_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
	}
	if ((Z_TYPE_P(forElse) == IS_STRING)) {
		zephir_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
	} else {
		if (zephir_array_isset(loopContext, level)) {
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SVS(_4, "<?php $", prefixLevel, "incr++; } ?>");
			zephir_concat_self(&compilation, _4 TSRMLS_CC);
		} else {
			zephir_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
		}
	}
	RETURN_CCTOR(compilation);

}

/**
 * Generates a 'forelse' PHP code
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForElse) {

	zval *level, *prefix, *_0, *_1;


	level = zephir_fetch_nproperty_this(this_ptr, SL("_foreachLevel"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_forElsePointers"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&prefix, _0, level, 1 TSRMLS_CC)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_loopPointers"), PH_NOISY_CC);
		if (zephir_array_isset(_1, level)) {
			ZEPHIR_CONCAT_SVSVS(return_value, "<?php $", prefix, "incr++; } if (!$", prefix, "iterated) { ?>");
			return;
		} else {
			ZEPHIR_CONCAT_SVS(return_value, "<?php } if (!$", prefix, "iterated) { ?>");
			return;
		}
	}
	RETURN_STRING("", 1);

}

/**
 * Compiles a 'if' statement returning PHP code
 *
 * @param array statement
 * @param boolean extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileIf) {

	zend_bool extendsMode;
	zval *statement, *extendsMode_param = NULL, *compilation, *blockStatements, *expr, *_0, *_1, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement, &extendsMode_param);

	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, this_ptr, "expression", expr);
	ZEPHIR_INIT_VAR(_1);
	zephir_array_fetch_string(&_2, statement, SL("true_statements"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_call_method_p2(_1, this_ptr, "_statementlist", _2, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	ZEPHIR_INIT_VAR(compilation);
	ZEPHIR_CONCAT_SVSV(compilation, "<?php if (", _0, ") { ?>", _1);
	if (zephir_array_isset_string_fetch(&blockStatements, statement, SS("false_statements"), 1 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_3);
		zephir_call_method_p2(_3, this_ptr, "_statementlist", blockStatements, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SV(_4, "<?php } else { ?>", _3);
		zephir_concat_self(&compilation, _4 TSRMLS_CC);
	}
	zephir_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
	RETURN_CCTOR(compilation);

}

/**
 * Compiles a "elseif" statement returning PHP code
 *
 * @param array statement
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileElseIf) {

	zval *statement, *expr, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement);



	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, this_ptr, "expression", expr);
	ZEPHIR_CONCAT_SVS(return_value, "<?php } elseif (", _0, ") { ?>");
	RETURN_MM();

}

/**
 * Compiles a "cache" statement returning PHP code
 *
 * @param array statement
 * @param boolean extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCache) {

	zval *statement, *extendsMode = NULL, *compilation, *expr, *exprCode, *lifetime = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement, &extendsMode);

	if (!extendsMode) {
		extendsMode = ZEPHIR_GLOBAL(global_false);
	}


	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	ZEPHIR_INIT_VAR(exprCode);
	zephir_call_method_p1(exprCode, this_ptr, "expression", expr);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, this_ptr, "expression", expr);
	ZEPHIR_INIT_VAR(compilation);
	ZEPHIR_CONCAT_SVS(compilation, "<?php $_cache[", _0, "] = $this->di->get(\"viewCache\"); ");
	ZEPHIR_OBS_VAR(lifetime);
	if (zephir_array_isset_string_fetch(&lifetime, statement, SS("lifetime"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "$_cacheKey[", exprCode, "]");
		zephir_concat_self(&compilation, _1 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVSVSVS(_2, " = $_cache[", exprCode, "]->start(", exprCode, ", ", lifetime, "); ");
		zephir_concat_self(&compilation, _2 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_LNVAR(_1);
		ZEPHIR_CONCAT_SVSVSVS(_1, "$_cacheKey[", exprCode, "] = $_cache[", exprCode, "]->start(", exprCode, "); ");
		zephir_concat_self(&compilation, _1 TSRMLS_CC);
	}
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "if ($_cacheKey[", exprCode, "] === null) { ?>");
	zephir_concat_self(&compilation, _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_array_fetch_string(&_4, statement, SL("block_statements"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_call_method_p2(_3, this_ptr, "_statementlist", _4, extendsMode);
	zephir_concat_self(&compilation, _3 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(lifetime);
	if (zephir_array_isset_string_fetch(&lifetime, statement, SS("lifetime"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_SVSVSVS(_2, "<?php $_cache[", exprCode, "]->save(", exprCode, ", null, ", lifetime, "); ");
		zephir_concat_self(&compilation, _2 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_SVS(_5, "} else { echo $_cacheKey[", exprCode, "]; } ?>");
		zephir_concat_self(&compilation, _5 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_LNVAR(_1);
		ZEPHIR_CONCAT_SVSVSVS(_1, "<?php $_cache[", exprCode, "]->save(", exprCode, "); } else { echo $_cacheKey[", exprCode, "]; } ?>");
		zephir_concat_self(&compilation, _1 TSRMLS_CC);
	}
	RETURN_CCTOR(compilation);

}

/**
 * Compiles a "set" statement returning PHP code
 *
 * @param array statement
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSet) {

	zend_function *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *statement, *assignments, *assignment = NULL, *exprCode = NULL, *variable, *compilation, **_2, *_3, *_5, *_6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement);



	if (!(zephir_array_isset_string_fetch(&assignments, statement, SS("assignments"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	ZEPHIR_INIT_VAR(compilation);
	ZVAL_STRING(compilation, "<?php", 1);
	zephir_is_iterable(assignments, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(assignment, _2);
		zephir_array_fetch_string(&_3, assignment, SL("expr"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(exprCode);
		zephir_call_method_p1_cache(exprCode, this_ptr, "expression", &_4, _3);
		zephir_array_fetch_string(&variable, assignment, SL("variable"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch_string(&_5, assignment, SL("op"), PH_NOISY | PH_READONLY TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(_5, 281)) {
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SVSVS(_6, " $", variable, " += ", exprCode, ";");
				zephir_concat_self(&compilation, _6 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_5, 282)) {
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SVSVS(_6, " $", variable, " -= ", exprCode, ";");
				zephir_concat_self(&compilation, _6 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_5, 283)) {
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SVSVS(_6, " $", variable, " *= ", exprCode, ";");
				zephir_concat_self(&compilation, _6 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_5, 284)) {
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SVSVS(_6, " $", variable, " /= ", exprCode, ";");
				zephir_concat_self(&compilation, _6 TSRMLS_CC);
				break;
			}
			ZEPHIR_INIT_LNVAR(_6);
			ZEPHIR_CONCAT_SVSVS(_6, " $", variable, " = ", exprCode, ";");
			zephir_concat_self(&compilation, _6 TSRMLS_CC);
			break;
		} while(0);

	}
	zephir_concat_self_str(&compilation, SL(" ?>") TSRMLS_CC);
	RETURN_CCTOR(compilation);

}

/**
 * Compiles a "do" statement returning PHP code
 *
 * @param array statement
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileDo) {

	zval *statement, *expr, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement);



	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, this_ptr, "expression", expr);
	ZEPHIR_CONCAT_SVS(return_value, "<?php ", _0, "; ?>");
	RETURN_MM();

}

/**
 * Compiles a "return" statement returning PHP code
 *
 * @param array statement
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileReturn) {

	zval *statement, *expr, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement);



	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, this_ptr, "expression", expr);
	ZEPHIR_CONCAT_SVS(return_value, "<?php return ", _0, "; ?>");
	RETURN_MM();

}

/**
 * Compiles a "autoescape" statement returning PHP code
 *
 * @param array   statement
 * @param boolean extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileAutoEscape) {

	zend_bool extendsMode;
	zval *statement, *extendsMode_param = NULL, *autoescape, *oldAutoescape, *compilation, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &statement, &extendsMode_param);

		extendsMode = zephir_get_boolval(extendsMode_param);


	if (!(zephir_array_isset_string_fetch(&autoescape, statement, SS("enable"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	oldAutoescape = zephir_fetch_nproperty_this(this_ptr, SL("_autoescape"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("_autoescape"), autoescape TSRMLS_CC);
	zephir_array_fetch_string(&_0, statement, SL("block_statements"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_VAR(compilation);
	zephir_call_method_p2(compilation, this_ptr, "_statementlist", _0, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
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

	zval *statement, *expr, *exprCode, *name, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement);



	if (!(zephir_array_isset_string_fetch(&expr, statement, SS("expr"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	ZEPHIR_INIT_VAR(exprCode);
	zephir_call_method_p1(exprCode, this_ptr, "expression", expr);
	zephir_array_fetch_string(&_0, expr, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_LONG(_0, 350)) {
		zephir_array_fetch_string(&name, expr, SL("name"), PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch_string(&_1, name, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
		if (ZEPHIR_IS_LONG(_1, 265)) {
			zephir_array_fetch_string(&_2, name, SL("value"), PH_NOISY | PH_READONLY TSRMLS_CC);
			if (ZEPHIR_IS_STRING(_2, "super")) {
				RETURN_CCTOR(exprCode);
			}
		}
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_autoescape"), PH_NOISY_CC);
	if (zephir_is_true(_1)) {
		ZEPHIR_CONCAT_SVS(return_value, "<?php echo $this->escaper->escapeHtml(", exprCode, "); ?>");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "<?php echo ", exprCode, "; ?>");
	RETURN_MM();

}

/**
 * Compiles a 'include' statement returning PHP code
 *
 * @param  array statement
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileInclude) {

	zval *statement, *pathExpr, *path = NULL, *view, *subCompiler, *finalPath = NULL, *compilation = NULL, *params, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement);



	if (!(zephir_array_isset_string_fetch(&pathExpr, statement, SS("path"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	zephir_array_fetch_string(&_0, pathExpr, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_LONG(_0, 260)) {
		if (!(zephir_array_isset_string(statement, SS("params")))) {
			ZEPHIR_OBS_VAR(path);
			zephir_array_fetch_string(&path, pathExpr, SL("value"), PH_NOISY TSRMLS_CC);
			view = zephir_fetch_nproperty_this(this_ptr, SL("_view"), PH_NOISY_CC);
			if ((Z_TYPE_P(view) == IS_OBJECT)) {
				ZEPHIR_INIT_VAR(_1);
				zephir_call_method(_1, view, "getviewsdir");
				ZEPHIR_INIT_VAR(finalPath);
				ZEPHIR_CONCAT_VV(finalPath, _1, path);
			} else {
				ZEPHIR_CPY_WRT(finalPath, path);
			}
			ZEPHIR_INIT_VAR(subCompiler);
			if (zephir_clone(subCompiler, this_ptr TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}
			ZEPHIR_INIT_VAR(compilation);
			zephir_call_method_p2(compilation, subCompiler, "compile", finalPath, ZEPHIR_GLOBAL(global_false));
			if ((Z_TYPE_P(compilation) == IS_NULL)) {
				ZEPHIR_INIT_NVAR(compilation);
				ZEPHIR_INIT_NVAR(_1);
				zephir_call_method(_1, subCompiler, "getcompiledtemplatepath");
				zephir_file_get_contents(compilation, _1 TSRMLS_CC);
			}
			RETURN_CCTOR(compilation);
		}
	}
	ZEPHIR_INIT_NVAR(path);
	zephir_call_method_p1(path, this_ptr, "expression", pathExpr);
	if (!(zephir_array_isset_string_fetch(&params, statement, SS("params"), 1 TSRMLS_CC))) {
		ZEPHIR_CONCAT_SVS(return_value, "<?php $this->partial(", path, "); ?>");
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_call_method_p1(_1, this_ptr, "expression", params);
	ZEPHIR_CONCAT_SVSVS(return_value, "<?php $this->partial(", path, ", ", _1, "); ?>");
	RETURN_MM();

}

/**
 * Compiles macros
 *
 * @param array   statement
 * @param boolean extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileMacro) {

	HashTable *_4;
	HashPosition _3;
	zend_bool extendsMode;
	zval *statement, *extendsMode_param = NULL, *code, *name, *parameters, *position = NULL, *parameter = NULL, *variableName, *blockStatements, *_0, *_1 = NULL, *_2 = NULL, **_5, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &statement, &extendsMode_param);

		extendsMode = zephir_get_boolval(extendsMode_param);


	if (!(zephir_array_isset_string_fetch(&name, statement, SS("name"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_macros"), PH_NOISY_CC);
	if (zephir_array_isset(_0, name)) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_mvc_view_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Macro '", name, "' is already defined");
		zephir_call_method_p1_noret(_1, "__construct", _2);
		zephir_throw_exception(_1 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else {
		zephir_update_property_array(this_ptr, SL("_macros"), name, name TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(code);
	ZVAL_STRING(code, "<?php function vmacro_", 1);
	if (!(zephir_array_isset_string_fetch(&parameters, statement, SS("parameters"), 1 TSRMLS_CC))) {
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_VS(_2, name, "() { ?>");
		zephir_concat_self(&code, _2 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_VS(_2, name, "($__p) { ");
		zephir_concat_self(&code, _2 TSRMLS_CC);
		zephir_is_iterable(parameters, &_4, &_3, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
			; zend_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HMKEY(position, _4, _3);
			ZEPHIR_GET_HVALUE(parameter, _5);
			zephir_array_fetch_string(&variableName, parameter, SL("variable"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_6);
			ZEPHIR_CONCAT_SVS(_6, "if (isset($__p[", position, "])) { ");
			zephir_concat_self(&code, _6 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_7);
			ZEPHIR_CONCAT_SVSVS(_7, "$", variableName, " = $__p[", position, "];");
			zephir_concat_self(&code, _7 TSRMLS_CC);
			zephir_concat_self_str(&code, SL(" } else { ") TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_8);
			ZEPHIR_CONCAT_SVS(_8, "if (isset($__p[\"", variableName, "\"])) { ");
			zephir_concat_self(&code, _8 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_9);
			ZEPHIR_CONCAT_SVSVS(_9, "$", variableName, " = $__p[\"", variableName, "\"];");
			zephir_concat_self(&code, _9 TSRMLS_CC);
			zephir_concat_self_str(&code, SL(" } else { ") TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_10);
			ZEPHIR_CONCAT_SVSVS(_10, " throw new \\Phalcon\\Mvc\\View\\Exception(\"Macro ", name, " was called without parameter: ", variableName, "\"); ");
			zephir_concat_self(&code, _10 TSRMLS_CC);
			zephir_concat_self_str(&code, SL(" } } ") TSRMLS_CC);
		}
		zephir_concat_self_str(&code, SL(" ?>") TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&blockStatements, statement, SS("block_statements"), 1 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(_1);
		zephir_call_method_p2(_1, this_ptr, "_statementlist", blockStatements, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_VS(_2, _1, "<?php } ?>");
		zephir_concat_self(&code, _2 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&code, SL("<?php } ?>") TSRMLS_CC);
	}
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

	zval *statement, *extendsMode;

	zephir_fetch_params(0, 2, 0, &statement, &extendsMode);




}

/**
 * Traverses a statement list compiling each of its nodes
 *
 * @param array statement
 * @param boolean extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementList) {

	zend_function *_7 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL, *_18 = NULL, *_19 = NULL, *_20 = NULL, *_21 = NULL, *_22 = NULL, *_23 = NULL, *_24 = NULL, *_25 = NULL, *_26 = NULL, *_27 = NULL;
	HashTable *_1;
	HashPosition _0;
	zend_bool extendsMode, blockMode;
	zval *statements, *extendsMode_param = NULL, *extended = NULL, *compilation = NULL, *extensions, *statement = NULL, *tempCompilation = NULL, *type, *blockName, *blockStatements, *blocks = NULL, *path, *view, *finalPath = NULL, *subCompiler = NULL, *level, **_2, *_3 = NULL, *_4, *_5, *_6 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statements, &extendsMode_param);

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
	blockMode = zephir_is_true(extended) || extendsMode;
	if ((blockMode == 1)) {
	}
	ZEPHIR_INIT_VAR(compilation);
	ZVAL_NULL(compilation);
	extensions = zephir_fetch_nproperty_this(this_ptr, SL("_extensions"), PH_NOISY_CC);
	zephir_is_iterable(statements, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(statement, _2);
		if ((Z_TYPE_P(statement) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
			return;
		}
		if (!(zephir_array_isset_string(statement, SS("type")))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, phalcon_mvc_view_exception_ce);
			zephir_array_fetch_string(&_4, statement, SL("file"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_string(&_5, statement, SL("line"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_6);
			ZEPHIR_CONCAT_SVSV(_6, "Invalid statement in ", _4, " on line ", _5);
			zephir_call_method_p1_cache_noret(_3, "__construct", &_7, _6);
			zephir_throw_exception(_3 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if ((Z_TYPE_P(extensions) == IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_3);
			array_init_size(_3, 2);
			zephir_array_fast_append(_3, statement);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_STRING(_8, "compileStatement", 1);
			ZEPHIR_INIT_NVAR(tempCompilation);
			zephir_call_method_p2_cache(tempCompilation, this_ptr, "fireextensionevent", &_9, _8, _3);
			if ((Z_TYPE_P(tempCompilation) == IS_STRING)) {
				zephir_concat_self(&compilation, tempCompilation TSRMLS_CC);
				continue;
			}
		}
		zephir_array_fetch_string(&type, statement, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(type, 357)) {
				zephir_array_fetch_string(&_4, statement, SL("value"), PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_concat_self(&compilation, _4 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 300)) {
				ZEPHIR_INIT_NVAR(_3);
				zephir_call_method_p2_cache(_3, this_ptr, "compileif", &_10, statement, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_concat_self(&compilation, _3 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 302)) {
				ZEPHIR_INIT_NVAR(_3);
				zephir_call_method_p1_cache(_3, this_ptr, "compileelseif", &_11, statement);
				zephir_concat_self(&compilation, _3 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 304)) {
				ZEPHIR_INIT_NVAR(_3);
				zephir_call_method_p2_cache(_3, this_ptr, "compileforeach", &_12, statement, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_concat_self(&compilation, _3 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 306)) {
				ZEPHIR_INIT_NVAR(_3);
				zephir_call_method_p1_cache(_3, this_ptr, "compileset", &_13, statement);
				zephir_concat_self(&compilation, _3 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 359)) {
				ZEPHIR_INIT_NVAR(_3);
				zephir_call_method_p1_cache(_3, this_ptr, "compileecho", &_14, statement);
				zephir_concat_self(&compilation, _3 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 307)) {
				zephir_array_fetch_string(&blockName, statement, SL("name"), PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_OBS_NVAR(blocks);
				zephir_read_property_this(&blocks, this_ptr, SL("_blocks"), PH_NOISY_CC);
				if (blockMode) {
					if ((Z_TYPE_P(blocks) != IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(blocks);
						array_init(blocks);
					}
					if ((Z_TYPE_P(compilation) != IS_NULL)) {
						zephir_array_append(&blocks, compilation, PH_SEPARATE);
						ZEPHIR_INIT_NVAR(compilation);
						ZVAL_NULL(compilation);
					}
					zephir_array_update_zval(&blocks, blockName, &blockStatements, PH_COPY | PH_SEPARATE);
					zephir_update_property_this(this_ptr, SL("_blocks"), blocks TSRMLS_CC);
				} else {
					if ((Z_TYPE_P(blockStatements) == IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(_3);
						zephir_call_method_p2_cache(_3, this_ptr, "_statementlist", &_15, blockStatements, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
						zephir_concat_self(&compilation, _3 TSRMLS_CC);
					}
				}
				break;
			}
			if (ZEPHIR_IS_LONG(type, 310)) {
				zephir_array_fetch_string(&path, statement, SL("path"), PH_NOISY | PH_READONLY TSRMLS_CC);
				view = zephir_fetch_nproperty_this(this_ptr, SL("_view"), PH_NOISY_CC);
				if ((Z_TYPE_P(view) == IS_OBJECT)) {
					ZEPHIR_INIT_NVAR(_3);
					zephir_call_method_cache(_3, view, "getviewsdir", &_16);
					ZEPHIR_INIT_NVAR(finalPath);
					ZEPHIR_CONCAT_VV(finalPath, _3, path);
				} else {
					ZEPHIR_CPY_WRT(finalPath, path);
				}
				ZEPHIR_INIT_NVAR(extended);
				ZVAL_BOOL(extended, 1);
				ZEPHIR_INIT_NVAR(subCompiler);
				if (zephir_clone(subCompiler, this_ptr TSRMLS_CC) == FAILURE) {
					RETURN_MM();
				}
				ZEPHIR_INIT_NVAR(tempCompilation);
				zephir_call_method_p2_cache(tempCompilation, subCompiler, "compile", &_17, finalPath, extended);
				if ((Z_TYPE_P(tempCompilation) == IS_NULL)) {
					ZEPHIR_INIT_NVAR(tempCompilation);
					ZEPHIR_INIT_NVAR(_8);
					zephir_call_method_cache(_8, subCompiler, "getcompiledtemplatepath", &_18);
					zephir_file_get_contents(tempCompilation, _8 TSRMLS_CC);
				}
				zephir_update_property_this(this_ptr, SL("_extended"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				zephir_update_property_this(this_ptr, SL("_extendedBlocks"), tempCompilation TSRMLS_CC);
				blockMode = zephir_get_boolval(extended);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 313)) {
				ZEPHIR_INIT_NVAR(_3);
				zephir_call_method_p1_cache(_3, this_ptr, "compileinclude", &_19, statement);
				zephir_concat_self(&compilation, _3 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 314)) {
				ZEPHIR_INIT_NVAR(_3);
				zephir_call_method_p2_cache(_3, this_ptr, "compilecache", &_20, statement, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_concat_self(&compilation, _3 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 316)) {
				ZEPHIR_INIT_NVAR(_3);
				zephir_call_method_p1_cache(_3, this_ptr, "compiledo", &_21, statement);
				zephir_concat_self(&compilation, _3 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 327)) {
				ZEPHIR_INIT_NVAR(_3);
				zephir_call_method_p1_cache(_3, this_ptr, "compilereturn", &_22, statement);
				zephir_concat_self(&compilation, _3 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 317)) {
				ZEPHIR_INIT_NVAR(_3);
				zephir_call_method_p2_cache(_3, this_ptr, "compileautoescape", &_23, statement, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_concat_self(&compilation, _3 TSRMLS_CC);
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
				ZEPHIR_INIT_NVAR(_3);
				zephir_call_method_cache(_3, this_ptr, "compileforelse", &_24);
				zephir_concat_self(&compilation, _3 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 322)) {
				ZEPHIR_INIT_NVAR(_3);
				zephir_call_method_p2_cache(_3, this_ptr, "compilemacro", &_25, statement, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_concat_self(&compilation, _3 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 325)) {
				ZEPHIR_INIT_NVAR(_3);
				zephir_call_method_p2_cache(_3, this_ptr, "compilecall", &_26, statement, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_concat_self(&compilation, _3 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(type, 358)) {
				break;
			}
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, phalcon_mvc_view_exception_ce);
			zephir_array_fetch_string(&_4, statement, SL("file"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_string(&_5, statement, SL("line"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_6);
			ZEPHIR_CONCAT_SVSVSV(_6, "Unknown statement ", type, " in ", _4, " on line ", _5);
			zephir_call_method_p1_cache_noret(_3, "__construct", &_27, _6);
			zephir_throw_exception(_3 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

	}
	if ((blockMode == 1)) {
		level = zephir_fetch_nproperty_this(this_ptr, SL("_blockLevel"), PH_NOISY_CC);
		if (ZEPHIR_IS_LONG(level, 1)) {
			if ((Z_TYPE_P(compilation) != IS_NULL)) {
				zephir_update_property_array_append(this_ptr, SL("_blocks"), compilation TSRMLS_CC);
			}
		}
	}
	RETURN_CCTOR(compilation);

}

/**
 * Compiles a Volt source code returning a PHP plain version
 *
 * @param string  viewCode
 * @param boolean extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _compileSource) {

	zend_function *_3 = NULL, *_4 = NULL, *_5 = NULL;
	HashTable *_1;
	HashPosition _0;
	zend_bool extendsMode;
	zval *viewCode_param = NULL, *extendsMode_param = NULL, *currentPath, *intermediate, *extended, *finalCompilation, *blocks, *extendedBlocks, *name = NULL, *block = NULL, *blockCompilation = NULL, *localBlock = NULL, *compilation, **_2;
	zval *viewCode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewCode_param, &extendsMode_param);

	if (Z_TYPE_P(viewCode_param) != IS_STRING) {
		if (Z_TYPE_P(viewCode_param) != IS_NULL) {
			zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewCode' must be a string") TSRMLS_CC);
			RETURN_MM_NULL();
		}
	}

	if (Z_TYPE_P(viewCode_param) == IS_STRING) {
		viewCode = viewCode_param;
	} else {
		ZEPHIR_INIT_VAR(viewCode);
		ZVAL_EMPTY_STRING(viewCode);
	}
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	currentPath = zephir_fetch_nproperty_this(this_ptr, SL("_currentPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(intermediate);
	if (phvolt_parse_view(intermediate, viewCode, currentPath TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	if ((Z_TYPE_P(intermediate) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(compilation);
		zephir_call_method_p2(compilation, this_ptr, "_statementlist", intermediate, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		extended = zephir_fetch_nproperty_this(this_ptr, SL("_extended"), PH_NOISY_CC);
		if (ZEPHIR_IS_TRUE(extended)) {
			ZEPHIR_INIT_VAR(finalCompilation);
			if ((extendsMode == 1)) {
				array_init(finalCompilation);
			} else {
				ZVAL_NULL(finalCompilation);
			}
			blocks = zephir_fetch_nproperty_this(this_ptr, SL("_blocks"), PH_NOISY_CC);
			extendedBlocks = zephir_fetch_nproperty_this(this_ptr, SL("_extendedBlocks"), PH_NOISY_CC);
			zephir_is_iterable(extendedBlocks, &_1, &_0, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
				; zend_hash_move_forward_ex(_1, &_0)
			) {
				ZEPHIR_GET_HMKEY(name, _1, _0);
				ZEPHIR_GET_HVALUE(block, _2);
				if ((Z_TYPE_P(name) == IS_STRING)) {
					if ((Z_TYPE_P(block) == IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(blockCompilation);
						if (zephir_array_isset(blocks, name)) {
							ZEPHIR_OBS_NVAR(localBlock);
							zephir_array_fetch(&localBlock, blocks, name, PH_NOISY TSRMLS_CC);
							zephir_update_property_this(this_ptr, SL("_currentBlock"), name TSRMLS_CC);
							zephir_call_method_p1_cache(blockCompilation, this_ptr, "_statementlist", &_3, localBlock);
						} else {
							zephir_call_method_p1_cache(blockCompilation, this_ptr, "_statementlist", &_4, block);
						}
					} else {
						if (zephir_array_isset(blocks, name)) {
							ZEPHIR_OBS_NVAR(localBlock);
							zephir_array_fetch(&localBlock, blocks, name, PH_NOISY TSRMLS_CC);
							zephir_update_property_this(this_ptr, SL("_currentBlock"), name TSRMLS_CC);
							ZEPHIR_INIT_NVAR(blockCompilation);
							zephir_call_method_p1_cache(blockCompilation, this_ptr, "_statementlist", &_5, localBlock);
						} else {
							ZEPHIR_CPY_WRT(blockCompilation, block);
						}
					}
					if ((extendsMode == 1)) {
						zephir_array_update_zval(&finalCompilation, name, &blockCompilation, PH_COPY | PH_SEPARATE);
					} else {
						zephir_concat_self(&finalCompilation, blockCompilation TSRMLS_CC);
					}
				} else {
					if ((extendsMode == 1)) {
						zephir_array_append(&finalCompilation, block, PH_SEPARATE);
					} else {
						zephir_concat_self(&finalCompilation, block TSRMLS_CC);
					}
				}
			}
			RETURN_CCTOR(finalCompilation);
		}
		if ((extendsMode == 1)) {
			RETURN_MM_MEMBER(this_ptr, "_blocks");
		}
		RETURN_CCTOR(compilation);
	}
	ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Invalid intermediate representation");
	return;

}

/**
 * Compiles a template into a string
 *
 *<code>
 * echo $compiler->compileString('{{ "hello world" }}');
 *</code>
 *
 * @param  string  viewCode
 * @param  boolean extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString) {

	zend_bool extendsMode;
	zval *viewCode_param = NULL, *extendsMode_param = NULL, *_0;
	zval *viewCode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewCode_param, &extendsMode_param);

	if (Z_TYPE_P(viewCode_param) != IS_STRING) {
		if (Z_TYPE_P(viewCode_param) != IS_NULL) {
			zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewCode' must be a string") TSRMLS_CC);
			RETURN_MM_NULL();
		}
	}

	if (Z_TYPE_P(viewCode_param) == IS_STRING) {
		viewCode = viewCode_param;
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
	zephir_call_method_p2(return_value, this_ptr, "_compilesource", viewCode, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
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

	zend_bool extendsMode;
	zval *path_param = NULL, *compiledPath_param = NULL, *extendsMode_param = NULL, *viewCode, *compilation, *finalCompilation = NULL, *_0, *_1 = NULL, *_2 = NULL;
	zval *path = NULL, *compiledPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &path_param, &compiledPath_param, &extendsMode_param);

	if (Z_TYPE_P(path_param) != IS_STRING) {
		if (Z_TYPE_P(path_param) != IS_NULL) {
			zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
			RETURN_MM_NULL();
		}
	}

	if (Z_TYPE_P(path_param) == IS_STRING) {
		path = path_param;
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}
	if (Z_TYPE_P(compiledPath_param) != IS_STRING) {
		if (Z_TYPE_P(compiledPath_param) != IS_NULL) {
			zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'compiledPath' must be a string") TSRMLS_CC);
			RETURN_MM_NULL();
		}
	}

	if (Z_TYPE_P(compiledPath_param) == IS_STRING) {
		compiledPath = compiledPath_param;
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
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Template path and compilation template path cannot be the same");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "file_exists", path);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_mvc_view_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Template file ", path, " does not exist");
		zephir_call_method_p1_noret(_1, "__construct", _2);
		zephir_throw_exception(_1 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(viewCode);
	zephir_file_get_contents(viewCode, path TSRMLS_CC);
	if (ZEPHIR_IS_FALSE(viewCode)) {
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, phalcon_mvc_view_exception_ce);
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Template file ", path, " could not be opened");
		zephir_call_method_p1_noret(_1, "__construct", _2);
		zephir_throw_exception(_1 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("_currentPath"), path TSRMLS_CC);
	ZEPHIR_INIT_VAR(compilation);
	zephir_call_method_p2(compilation, this_ptr, "_compilesource", viewCode, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	if ((Z_TYPE_P(compilation) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(finalCompilation);
		zephir_call_func_p1(finalCompilation, "serialize", compilation);
	} else {
		ZEPHIR_CPY_WRT(finalCompilation, compilation);
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_file_put_contents(_1, compiledPath, finalCompilation TSRMLS_CC);
	if (ZEPHIR_IS_FALSE(_1)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Volt directory can't be written");
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
 * @param string templatePath
 * @param boolean extendsMode
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compile) {

	zend_bool extendsMode;
	zval *templatePath_param = NULL, *extendsMode_param = NULL, *stat = NULL, *compileAlways = NULL, *prefix = NULL, *compiledPath = NULL, *compiledSeparator = NULL, *blocksCode, *compiledExtension = NULL, *compilation, *options, *realCompiledPath = NULL, *compiledTemplatePath = NULL, *realTemplatePath, *templateSepPath = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3, *_4 = NULL;
	zval *templatePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &templatePath_param, &extendsMode_param);

	if (Z_TYPE_P(templatePath_param) != IS_STRING) {
		if (Z_TYPE_P(templatePath_param) != IS_NULL) {
			zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'templatePath' must be a string") TSRMLS_CC);
			RETURN_MM_NULL();
		}
	}

	if (Z_TYPE_P(templatePath_param) == IS_STRING) {
		templatePath = templatePath_param;
	} else {
		ZEPHIR_INIT_VAR(templatePath);
		ZVAL_EMPTY_STRING(templatePath);
	}
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	zephir_update_property_this(this_ptr, SL("_extended"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_extendedBlocks"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
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
	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if ((Z_TYPE_P(options) == IS_ARRAY)) {
		ZEPHIR_OBS_NVAR(compileAlways);
		if (zephir_array_isset_string_fetch(&compileAlways, options, SS("compileAlways"), 0 TSRMLS_CC)) {
			if ((Z_TYPE_P(compileAlways) != IS_BOOL)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compileAlways must be a bool value");
				return;
			}
		}
		ZEPHIR_OBS_NVAR(prefix);
		if (zephir_array_isset_string_fetch(&prefix, options, SS("prefix"), 0 TSRMLS_CC)) {
			if ((Z_TYPE_P(prefix) != IS_STRING)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "prefix must be a string");
				return;
			}
		}
		ZEPHIR_OBS_NVAR(compiledPath);
		if (zephir_array_isset_string_fetch(&compiledPath, options, SS("compiledPath"), 0 TSRMLS_CC)) {
			if ((Z_TYPE_P(compiledPath) != IS_STRING)) {
				if ((Z_TYPE_P(compiledPath) != IS_OBJECT)) {
					ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compiledPath must be a string or a closure");
					return;
				}
			}
		}
		ZEPHIR_OBS_NVAR(compiledSeparator);
		if (zephir_array_isset_string_fetch(&compiledSeparator, options, SS("compiledSeparator"), 0 TSRMLS_CC)) {
			if ((Z_TYPE_P(compiledSeparator) != IS_STRING)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compiledSeparator must be a string");
				return;
			}
		}
		ZEPHIR_OBS_NVAR(compiledExtension);
		if (zephir_array_isset_string_fetch(&compiledExtension, options, SS("compiledExtension"), 0 TSRMLS_CC)) {
			if ((Z_TYPE_P(compiledExtension) != IS_STRING)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compiledExtension must be a string");
				return;
			}
		}
		if (zephir_array_isset_string(options, SS("stat"))) {
			ZEPHIR_OBS_NVAR(stat);
			zephir_array_fetch_string(&stat, options, SL("stat"), PH_NOISY TSRMLS_CC);
		}
	}
	if ((Z_TYPE_P(compiledPath) == IS_STRING)) {
		if (!(ZEPHIR_IS_EMPTY(compiledPath))) {
			ZEPHIR_INIT_VAR(realTemplatePath);
			zephir_call_func_p1(realTemplatePath, "realpath", templatePath);
			ZEPHIR_INIT_VAR(templateSepPath);
			zephir_call_func_p1(templateSepPath, "md5", realTemplatePath);
		} else {
			ZEPHIR_CPY_WRT(templateSepPath, templatePath);
		}
		ZEPHIR_INIT_VAR(compiledTemplatePath);
		if ((extendsMode == 1)) {
			ZEPHIR_CONCAT_VVVVSVV(compiledTemplatePath, compiledPath, prefix, templateSepPath, compiledSeparator, "e", compiledSeparator, compiledExtension);
		} else {
			ZEPHIR_CONCAT_VVVV(compiledTemplatePath, compiledPath, prefix, templateSepPath, compiledExtension);
		}
	} else {
		if ((Z_TYPE_P(compiledPath) == IS_OBJECT)) {
			if (zephir_is_instance_of(compiledPath, SL("Closure") TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(_1);
				array_init_size(_1, 5);
				zephir_array_fast_append(_1, templatePath);
				zephir_array_fast_append(_1, options);
				ZEPHIR_INIT_VAR(_2);
				ZVAL_BOOL(_2, extendsMode);
				zephir_array_fast_append(_1, _2);
				ZEPHIR_INIT_NVAR(compiledTemplatePath);
				zephir_call_func_p2(compiledTemplatePath, "call_user_func_array", compiledPath, _1);
				if ((Z_TYPE_P(compiledTemplatePath) == IS_STRING)) {
					ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compiledPath closure didn't return a valid string");
					return;
				}
			} else {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compiledPath must be a string or a closure");
				return;
			}
		}
	}
	ZEPHIR_CPY_WRT(realCompiledPath, compiledTemplatePath);
	if (zephir_is_true(compileAlways)) {
		ZEPHIR_INIT_BNVAR(compilation);
		zephir_call_method_p3(compilation, this_ptr, "compilefile", templatePath, realCompiledPath, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	} else {
		if (ZEPHIR_IS_TRUE(stat)) {
			ZEPHIR_INIT_NVAR(_1);
			zephir_call_func_p1(_1, "file_exists", compiledTemplatePath);
			if (zephir_is_true(_1)) {
				ZEPHIR_INIT_NVAR(_2);
				zephir_call_func_p2(_2, "compare_mtime", templatePath, realCompiledPath);
				if (zephir_is_true(_2)) {
					ZEPHIR_INIT_BNVAR(compilation);
					zephir_call_method_p3(compilation, this_ptr, "compilefile", templatePath, realCompiledPath, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				} else {
					if ((extendsMode == 1)) {
						ZEPHIR_INIT_VAR(blocksCode);
						zephir_file_get_contents(blocksCode, realCompiledPath TSRMLS_CC);
						if (ZEPHIR_IS_FALSE(blocksCode)) {
							ZEPHIR_INIT_VAR(_3);
							object_init_ex(_3, phalcon_mvc_view_exception_ce);
							ZEPHIR_INIT_VAR(_4);
							ZEPHIR_CONCAT_SVS(_4, "Extends compilation file ", realCompiledPath, " could not be opened");
							zephir_call_method_p1_noret(_3, "__construct", _4);
							zephir_throw_exception(_3 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_BNVAR(compilation);
						if (zephir_is_true(blocksCode)) {
							zephir_call_func_p1(compilation, "unserialize", blocksCode);
						} else {
							array_init(compilation);
						}
					}
				}
			} else {
				ZEPHIR_INIT_BNVAR(compilation);
				zephir_call_method_p3(compilation, this_ptr, "compilefile", templatePath, realCompiledPath, (extendsMode ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
			}
		} else {
			ZEPHIR_INIT_NVAR(_1);
			zephir_call_func_p1(_1, "file_exists", realCompiledPath);
			if (!(zephir_is_true(_1))) {
				ZEPHIR_INIT_NVAR(_2);
				object_init_ex(_2, phalcon_mvc_view_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SVS(_4, "Compiled template file ", realCompiledPath, " does not exist");
				zephir_call_method_p1_noret(_2, "__construct", _4);
				zephir_throw_exception(_2 TSRMLS_CC);
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
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getTemplatePath) {


	RETURN_MEMBER(this_ptr, "_currentPath");

}

/**
 * Returns the path to the last compiled template
 *
 * @return string
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

	zval *viewCode_param = NULL, _0;
	zval *viewCode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &viewCode_param);

	if (Z_TYPE_P(viewCode_param) != IS_STRING) {
		if (Z_TYPE_P(viewCode_param) != IS_NULL) {
			zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewCode' must be a string") TSRMLS_CC);
			RETURN_MM_NULL();
		}
	}

	if (Z_TYPE_P(viewCode_param) == IS_STRING) {
		viewCode = viewCode_param;
	} else {
		ZEPHIR_INIT_VAR(viewCode);
		ZVAL_EMPTY_STRING(viewCode);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "eval code", 0);
	if (phvolt_parse_view(return_value, viewCode, &_0 TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	RETURN_MM();

}

