
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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

	zval *view = NULL, view_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&view_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 0, 1, &view);

	if (!view) {
		view = &view_sub;
		view = &__$null;
	}


	if (Z_TYPE_P(view) == IS_OBJECT) {
		zephir_update_property_zval(this_ptr, SL("_view"), view);
	}

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI) {

	zval *dependencyInjector, dependencyInjector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets the compiler options
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions) {

	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);


	zephir_update_property_zval(this_ptr, SL("_options"), &options);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a single compiler option
 *
 * @param mixed value
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOption) {

	zval *option_param = NULL, *value, value_sub;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &option_param, &value);

	if (UNEXPECTED(Z_TYPE_P(option_param) != IS_STRING && Z_TYPE_P(option_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'option' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(option_param) == IS_STRING)) {
		zephir_get_strval(&option, option_param);
	} else {
		ZEPHIR_INIT_VAR(&option);
		ZVAL_EMPTY_STRING(&option);
	}


	zephir_update_property_array(this_ptr, SL("_options"), &option, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a compiler's option
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOption) {

	zval *option_param = NULL, value, _0;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &option_param);

	if (UNEXPECTED(Z_TYPE_P(option_param) != IS_STRING && Z_TYPE_P(option_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'option' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(option_param) == IS_STRING)) {
		zephir_get_strval(&option, option_param);
	} else {
		ZEPHIR_INIT_VAR(&option);
		ZVAL_EMPTY_STRING(&option);
	}


	zephir_read_property(&_0, this_ptr, SL("_options"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&value, &_0, &option, 1 TSRMLS_CC)) {
		RETURN_CTOR(&value);
	}
	RETURN_MM_NULL();

}

/**
 * Returns the compiler options
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_options");

}

/**
 * Fires an event to registered extensions
 *
 * @param array arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, fireExtensionEvent) {

	zval _1$$6, _2$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *arguments = NULL, arguments_sub, __$null, extensions, extension, status, *_0$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &arguments);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}


	ZEPHIR_OBS_VAR(&extensions);
	zephir_read_property(&extensions, this_ptr, SL("_extensions"), PH_NOISY_CC);
	if (Z_TYPE_P(&extensions) == IS_ARRAY) {
		zephir_is_iterable(&extensions, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 177);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _0$$3)
		{
			ZEPHIR_INIT_NVAR(&extension);
			ZVAL_COPY(&extension, _0$$3);
			if ((zephir_method_exists(&extension, &name TSRMLS_CC)  == SUCCESS)) {
				if (Z_TYPE_P(arguments) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_1$$6);
					zephir_create_array(&_1$$6, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_1$$6, &extension);
					zephir_array_fast_append(&_1$$6, &name);
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &_1$$6, arguments);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_2$$7);
					zephir_create_array(&_2$$7, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_2$$7, &extension);
					zephir_array_fast_append(&_2$$7, &name);
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC(&status, &_2$$7);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&status) == IS_STRING) {
					RETURN_CCTOR(&status);
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&extension);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Registers a Volt's extension
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addExtension) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *extension, extension_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&extension_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &extension);



	if (Z_TYPE_P(extension) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "The extension is not valid", "phalcon/mvc/view/engine/volt/compiler.zep", 186);
		return;
	}
	if ((zephir_method_exists_ex(extension, SL("initialize") TSRMLS_CC) == SUCCESS)) {
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

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_extensions");

}

/**
 * Register a new function in the compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFunction) {

	zval *name_param = NULL, *definition, definition_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_update_property_array(this_ptr, SL("_functions"), &name, definition TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Register the user registered functions
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFunctions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_functions");

}

/**
 * Register a new filter in the compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFilter) {

	zval *name_param = NULL, *definition, definition_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_update_property_array(this_ptr, SL("_filters"), &name, definition TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Register the user registered filters
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFilters) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_filters");

}

/**
 * Set a unique prefix to be used as prefix for compiled variables
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setUniquePrefix) {

	zval *prefix_param = NULL;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(&prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_EMPTY_STRING(&prefix);
	}


	zephir_update_property_zval(this_ptr, SL("_prefix"), &prefix);
	RETURN_THIS();

}

/**
 * Return a unique prefix to be used as prefix for compiled variables and contexts
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getUniquePrefix) {

	zval _7$$5;
	zval _0, _3, _8, _1$$3, _2$$3, _4$$4, _5$$5, _6$$5;
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

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("_currentPath"), PH_NOISY_CC | PH_READONLY);
		zephir_unique_path_key(&_1$$3, &_2$$3 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_prefix"), &_1$$3);
	}
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, this_ptr, SL("_prefix"), PH_NOISY_CC);
	if (Z_TYPE_P(&_3) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(&_4$$4);
		zephir_read_property(&_4$$4, this_ptr, SL("_prefix"), PH_NOISY_CC);
		if (zephir_instance_of_ev(&_4$$4, zend_ce_closure TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_read_property(&_6$$5, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_7$$5);
			zephir_create_array(&_7$$5, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_7$$5, this_ptr);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_5$$5, &_6$$5, &_7$$5);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_prefix"), &_5$$5);
		}
	}
	ZEPHIR_OBS_VAR(&_8);
	zephir_read_property(&_8, this_ptr, SL("_prefix"), PH_NOISY_CC);
	if (Z_TYPE_P(&_8) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "The unique compilation prefix is invalid", "phalcon/mvc/view/engine/volt/compiler.zep", 273);
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
	zval *expr_param = NULL, exprCode, left, leftType, variable, level, dependencyInjector, leftCode, right, _0, _8, _1$$4, _2$$4, _4$$5, _5$$6, _6$$7, _9$$11, _10$$12;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&exprCode);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&leftType);
	ZVAL_UNDEF(&variable);
	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&leftCode);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);


	ZEPHIR_INIT_VAR(&exprCode);
	ZVAL_NULL(&exprCode);
	ZEPHIR_OBS_VAR(&left);
	zephir_array_fetch_string(&left, &expr, SL("left"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 289 TSRMLS_CC);
	zephir_array_fetch_string(&_0, &left, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 291 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(&_0, 265)) {
		ZEPHIR_OBS_VAR(&variable);
		zephir_array_fetch_string(&variable, &left, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 293 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&variable, "loop")) {
			ZEPHIR_OBS_VAR(&level);
			zephir_read_property(&level, this_ptr, SL("_foreachLevel"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "getuniqueprefix", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_CONCAT_SVVS(&_2$$4, "$", &_1$$4, &level, "loop");
			zephir_concat_self(&exprCode, &_2$$4 TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("_loopPointers"), &level, &level TSRMLS_CC);
		} else {
			ZEPHIR_OBS_VAR(&dependencyInjector);
			zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
			_3$$5 = Z_TYPE_P(&dependencyInjector) == IS_OBJECT;
			if (_3$$5) {
				ZEPHIR_CALL_METHOD(&_4$$5, &dependencyInjector, "has", NULL, 0, &variable);
				zephir_check_call_status();
				_3$$5 = zephir_is_true(&_4$$5);
			}
			if (_3$$5) {
				ZEPHIR_INIT_VAR(&_5$$6);
				ZEPHIR_CONCAT_SV(&_5$$6, "$this->", &variable);
				zephir_concat_self(&exprCode, &_5$$6 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(&_6$$7);
				ZEPHIR_CONCAT_SV(&_6$$7, "$", &variable);
				zephir_concat_self(&exprCode, &_6$$7 TSRMLS_CC);
			}
		}
	} else {
		ZEPHIR_CALL_METHOD(&leftCode, this_ptr, "expression", NULL, 389, &left);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&leftType);
		zephir_array_fetch_string(&leftType, &left, SL("type"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 316 TSRMLS_CC);
		_7$$8 = !ZEPHIR_IS_LONG(&leftType, '.');
		if (_7$$8) {
			_7$$8 = !ZEPHIR_IS_LONG(&leftType, 350);
		}
		if (_7$$8) {
			zephir_concat_self(&exprCode, &leftCode TSRMLS_CC);
		} else {
			zephir_concat_self(&exprCode, &leftCode TSRMLS_CC);
		}
	}
	zephir_concat_self_str(&exprCode, SL("->") TSRMLS_CC);
	ZEPHIR_OBS_VAR(&right);
	zephir_array_fetch_string(&right, &expr, SL("right"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 326 TSRMLS_CC);
	zephir_array_fetch_string(&_8, &right, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 328 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(&_8, 265)) {
		zephir_array_fetch_string(&_9$$11, &right, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 329 TSRMLS_CC);
		zephir_concat_self(&exprCode, &_9$$11 TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&_10$$12, this_ptr, "expression", NULL, 389, &right);
		zephir_check_call_status();
		zephir_concat_self(&exprCode, &_10$$12 TSRMLS_CC);
	}
	RETURN_CCTOR(&exprCode);

}

/**
 * Resolves function intermediate code into PHP function calls
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, functionCall) {

	zend_bool _7$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, __$true, code, funcArguments, arguments, nameExpr, nameType, name, extensions, functions, definition, extendedBlocks, block, currentBlock, exprLevel, escapedCode, method, arrayHelpers, className, _9, _1$$6, _3$$9, _4$$9, _5$$9, _6$$9, _8$$5;
	zval expr, _0$$6, _2$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_2$$12);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&funcArguments);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&nameExpr);
	ZVAL_UNDEF(&nameType);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&functions);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&extendedBlocks);
	ZVAL_UNDEF(&block);
	ZVAL_UNDEF(&currentBlock);
	ZVAL_UNDEF(&exprLevel);
	ZVAL_UNDEF(&escapedCode);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&arrayHelpers);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);


	ZEPHIR_INIT_VAR(&code);
	ZVAL_NULL(&code);
	ZEPHIR_INIT_VAR(&funcArguments);
	ZVAL_NULL(&funcArguments);
	ZEPHIR_OBS_NVAR(&funcArguments);
	if (zephir_array_isset_string_fetch(&funcArguments, &expr, SL("arguments"), 0)) {
		ZEPHIR_CALL_METHOD(&arguments, this_ptr, "expression", NULL, 389, &funcArguments);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&arguments);
		ZVAL_STRING(&arguments, "");
	}
	ZEPHIR_OBS_VAR(&nameExpr);
	zephir_array_fetch_string(&nameExpr, &expr, SL("name"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 356 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&nameType);
	zephir_array_fetch_string(&nameType, &nameExpr, SL("type"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 356 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(&nameType, 265)) {
		ZEPHIR_OBS_VAR(&name);
		zephir_array_fetch_string(&name, &nameExpr, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 363 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&extensions);
		zephir_read_property(&extensions, this_ptr, SL("_extensions"), PH_NOISY_CC);
		if (Z_TYPE_P(&extensions) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$6);
			zephir_create_array(&_0$$6, 3, 0 TSRMLS_CC);
			zephir_array_fast_append(&_0$$6, &name);
			zephir_array_fast_append(&_0$$6, &arguments);
			zephir_array_fast_append(&_0$$6, &funcArguments);
			ZEPHIR_INIT_VAR(&_1$$6);
			ZVAL_STRING(&_1$$6, "compileFunction");
			ZEPHIR_CALL_METHOD(&code, this_ptr, "fireextensionevent", NULL, 390, &_1$$6, &_0$$6);
			zephir_check_call_status();
			if (Z_TYPE_P(&code) == IS_STRING) {
				RETURN_CCTOR(&code);
			}
		}
		ZEPHIR_OBS_VAR(&functions);
		zephir_read_property(&functions, this_ptr, SL("_functions"), PH_NOISY_CC);
		if (Z_TYPE_P(&functions) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(&definition);
			if (zephir_array_isset_fetch(&definition, &functions, &name, 0 TSRMLS_CC)) {
				if (Z_TYPE_P(&definition) == IS_STRING) {
					ZEPHIR_CONCAT_VSVS(return_value, &definition, "(", &arguments, ")");
					RETURN_MM();
				}
				if (Z_TYPE_P(&definition) == IS_OBJECT) {
					if (zephir_instance_of_ev(&definition, zend_ce_closure TSRMLS_CC)) {
						ZEPHIR_INIT_VAR(&_2$$12);
						zephir_create_array(&_2$$12, 2, 0 TSRMLS_CC);
						zephir_array_fast_append(&_2$$12, &arguments);
						zephir_array_fast_append(&_2$$12, &funcArguments);
						ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &definition, &_2$$12);
						zephir_check_call_status();
						RETURN_MM();
					}
				}
				ZEPHIR_INIT_VAR(&_3$$9);
				object_init_ex(&_3$$9, phalcon_mvc_view_engine_volt_exception_ce);
				zephir_array_fetch_string(&_4$$9, &expr, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 405 TSRMLS_CC);
				zephir_array_fetch_string(&_5$$9, &expr, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 406 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_6$$9);
				ZEPHIR_CONCAT_SVSVSV(&_6$$9, "Invalid definition for user function '", &name, "' in ", &_4$$9, " on line ", &_5$$9);
				ZEPHIR_CALL_METHOD(NULL, &_3$$9, "__construct", NULL, 391, &_6$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$9, "phalcon/mvc/view/engine/volt/compiler.zep", 406 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		_7$$5 = ZEPHIR_IS_STRING(&name, "get_content");
		if (!(_7$$5)) {
			_7$$5 = ZEPHIR_IS_STRING(&name, "content");
		}
		if (_7$$5) {
			RETURN_MM_STRING("$this->getContent()");
		}
		if (ZEPHIR_IS_STRING(&name, "partial")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->partial(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "super")) {
			ZEPHIR_OBS_VAR(&extendedBlocks);
			zephir_read_property(&extendedBlocks, this_ptr, SL("_extendedBlocks"), PH_NOISY_CC);
			if (Z_TYPE_P(&extendedBlocks) == IS_ARRAY) {
				ZEPHIR_OBS_VAR(&currentBlock);
				zephir_read_property(&currentBlock, this_ptr, SL("_currentBlock"), PH_NOISY_CC);
				ZEPHIR_OBS_VAR(&block);
				if (zephir_array_isset_fetch(&block, &extendedBlocks, &currentBlock, 0 TSRMLS_CC)) {
					ZEPHIR_OBS_VAR(&exprLevel);
					zephir_read_property(&exprLevel, this_ptr, SL("_exprLevel"), PH_NOISY_CC);
					if (Z_TYPE_P(&block) == IS_ARRAY) {
						ZEPHIR_CALL_METHOD(&code, this_ptr, "_statementlistorextends", NULL, 392, &block);
						zephir_check_call_status();
						if (ZEPHIR_IS_LONG(&exprLevel, 1)) {
							ZEPHIR_CPY_WRT(&escapedCode, &code);
						} else {
							ZEPHIR_INIT_NVAR(&escapedCode);
							zephir_addslashes(&escapedCode, &code TSRMLS_CC);
						}
					} else {
						if (ZEPHIR_IS_LONG(&exprLevel, 1)) {
							ZEPHIR_CPY_WRT(&escapedCode, &block);
						} else {
							ZEPHIR_INIT_NVAR(&escapedCode);
							zephir_addslashes(&escapedCode, &block TSRMLS_CC);
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
		ZEPHIR_INIT_VAR(&_8$$5);
		zephir_camelize(&_8$$5, &name, NULL  );
		ZEPHIR_CALL_FUNCTION(&method, "lcfirst", NULL, 55, &_8$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&className);
		ZVAL_STRING(&className, "Phalcon\\Tag");
		if ((zephir_method_exists(&className, &method TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_OBS_VAR(&arrayHelpers);
			zephir_read_property(&arrayHelpers, this_ptr, SL("_arrayHelpers"), PH_NOISY_CC);
			if (Z_TYPE_P(&arrayHelpers) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&arrayHelpers);
				zephir_create_array(&arrayHelpers, 16, 0 TSRMLS_CC);
				zephir_array_update_string(&arrayHelpers, SL("link_to"), &__$true, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("image"), &__$true, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&arrayHelpers, SL("form"), &__$true, PH_COPY | PH_SEPARATE);
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
				zephir_update_property_zval(this_ptr, SL("_arrayHelpers"), &arrayHelpers);
			}
			if (zephir_array_isset(&arrayHelpers, &name)) {
				ZEPHIR_CONCAT_SVSVS(return_value, "$this->tag->", &method, "([", &arguments, "])");
				RETURN_MM();
			}
			ZEPHIR_CONCAT_SVSVS(return_value, "$this->tag->", &method, "(", &arguments, ")");
			RETURN_MM();
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
			RETURN_MM_STRING("Phalcon\\Version::get()");
		}
		if (ZEPHIR_IS_STRING(&name, "version_id")) {
			RETURN_MM_STRING("Phalcon\\Version::getId()");
		}
		if (ZEPHIR_IS_STRING(&name, "constant")) {
			ZEPHIR_CONCAT_SVS(return_value, "constant(", &arguments, ")");
			RETURN_MM();
		}
		ZEPHIR_CONCAT_SVSVS(return_value, "$this->callMacro('", &name, "', [", &arguments, "])");
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "expression", NULL, 389, &nameExpr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVS(return_value, &_9, "(", &arguments, ")");
	RETURN_MM();

}

/**
 * Resolves filter intermediate code into a valid PHP expression
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveTest) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &test_param, &left_param);

	ZEPHIR_OBS_COPY_OR_DUP(&test, test_param);
	zephir_get_strval(&left, left_param);


	ZEPHIR_OBS_VAR(&type);
	zephir_array_fetch_string(&type, &test, SL("type"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 615 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(&type, 265)) {
		ZEPHIR_OBS_VAR(&name);
		zephir_array_fetch_string(&name, &test, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 622 TSRMLS_CC);
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
	}
	if (ZEPHIR_IS_LONG(&type, 350)) {
		ZEPHIR_OBS_VAR(&testName);
		zephir_array_fetch_string(&testName, &test, SL("name"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 673 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&name);
		if (zephir_array_isset_string_fetch(&name, &testName, SL("value"), 0)) {
			if (ZEPHIR_IS_STRING(&name, "divisibleby")) {
				zephir_array_fetch_string(&_1$$12, &test, SL("arguments"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 677 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_0$$12, this_ptr, "expression", NULL, 389, &_1$$12);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVSVS(return_value, "(((", &left, ") % (", &_0$$12, ")) == 0)");
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(&name, "sameas")) {
				zephir_array_fetch_string(&_3$$13, &test, SL("arguments"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 684 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_2$$13, this_ptr, "expression", NULL, 389, &_3$$13);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVSVS(return_value, "(", &left, ") === (", &_2$$13, ")");
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(&name, "type")) {
				zephir_array_fetch_string(&_5$$14, &test, SL("arguments"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 691 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_4$$14, this_ptr, "expression", NULL, 389, &_5$$14);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVSVS(return_value, "gettype(", &left, ") === (", &_4$$14, ")");
				RETURN_MM();
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "expression", NULL, 389, &test);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &left, " == ", &_6);
	RETURN_MM();

}

/**
 * Resolves filter intermediate code into PHP function calls
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveFilter) {

	zend_bool _13, _14, _15;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval left;
	zval *filter_param = NULL, *left_param = NULL, code, type, functionName, name, file, line, extensions, filters, funcArguments, arguments, definition, _16, _17, _18, _19, _0$$5, _1$$5, _2$$5, _3$$5, _7$$9, _9$$12, _10$$12, _11$$12, _12$$12;
	zval filter, _4$$7, _5$$7, _6$$9, _8$$15;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_8$$15);
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
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&left);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &filter_param, &left_param);

	ZEPHIR_OBS_COPY_OR_DUP(&filter, filter_param);
	zephir_get_strval(&left, left_param);


	ZEPHIR_INIT_VAR(&code);
	ZVAL_NULL(&code);
	ZEPHIR_OBS_VAR(&type);
	zephir_array_fetch_string(&type, &filter, SL("type"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 710 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(&type, 265)) {
		ZEPHIR_OBS_VAR(&name);
		zephir_array_fetch_string(&name, &filter, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 716 TSRMLS_CC);
	} else {
		if (!ZEPHIR_IS_LONG(&type, 350)) {
			ZEPHIR_INIT_VAR(&_0$$5);
			object_init_ex(&_0$$5, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_1$$5, &filter, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 724 TSRMLS_CC);
			zephir_array_fetch_string(&_2$$5, &filter, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 724 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_3$$5);
			ZEPHIR_CONCAT_SVSV(&_3$$5, "Unknown filter type in ", &_1$$5, " on line ", &_2$$5);
			ZEPHIR_CALL_METHOD(NULL, &_0$$5, "__construct", NULL, 391, &_3$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_0$$5, "phalcon/mvc/view/engine/volt/compiler.zep", 724 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(&functionName);
		zephir_array_fetch_string(&functionName, &filter, SL("name"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 727 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&name);
		zephir_array_fetch_string(&name, &functionName, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 728 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(&funcArguments);
	ZVAL_NULL(&funcArguments);
	ZEPHIR_INIT_VAR(&arguments);
	ZVAL_NULL(&arguments);
	ZEPHIR_OBS_NVAR(&funcArguments);
	if (zephir_array_isset_string_fetch(&funcArguments, &filter, SL("arguments"), 0)) {
		if (!ZEPHIR_IS_STRING(&name, "default")) {
			ZEPHIR_OBS_VAR(&file);
			zephir_array_fetch_string(&file, &filter, SL("file"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 743 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&line);
			zephir_array_fetch_string(&line, &filter, SL("line"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 743 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_4$$7);
			zephir_create_array(&_4$$7, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_5$$7);
			zephir_create_array(&_5$$7, 4, 0 TSRMLS_CC);
			add_assoc_long_ex(&_5$$7, SL("type"), 364);
			zephir_array_update_string(&_5$$7, SL("value"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_5$$7, SL("file"), &file, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_5$$7, SL("line"), &line, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4$$7, SL("expr"), &_5$$7, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4$$7, SL("file"), &file, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4$$7, SL("line"), &line, PH_COPY | PH_SEPARATE);
			ZEPHIR_MAKE_REF(&funcArguments);
			ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 393, &funcArguments, &_4$$7);
			ZEPHIR_UNREF(&funcArguments);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&arguments, this_ptr, "expression", NULL, 389, &funcArguments);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&arguments, &left);
	}
	ZEPHIR_OBS_VAR(&extensions);
	zephir_read_property(&extensions, this_ptr, SL("_extensions"), PH_NOISY_CC);
	if (Z_TYPE_P(&extensions) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_6$$9);
		zephir_create_array(&_6$$9, 3, 0 TSRMLS_CC);
		zephir_array_fast_append(&_6$$9, &name);
		zephir_array_fast_append(&_6$$9, &arguments);
		zephir_array_fast_append(&_6$$9, &funcArguments);
		ZEPHIR_INIT_VAR(&_7$$9);
		ZVAL_STRING(&_7$$9, "compileFilter");
		ZEPHIR_CALL_METHOD(&code, this_ptr, "fireextensionevent", NULL, 390, &_7$$9, &_6$$9);
		zephir_check_call_status();
		if (Z_TYPE_P(&code) == IS_STRING) {
			RETURN_CCTOR(&code);
		}
	}
	ZEPHIR_OBS_VAR(&filters);
	zephir_read_property(&filters, this_ptr, SL("_filters"), PH_NOISY_CC);
	if (Z_TYPE_P(&filters) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&definition);
		if (zephir_array_isset_fetch(&definition, &filters, &name, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(&definition) == IS_STRING) {
				ZEPHIR_CONCAT_VSVS(return_value, &definition, "(", &arguments, ")");
				RETURN_MM();
			}
			if (Z_TYPE_P(&definition) == IS_OBJECT) {
				if (zephir_instance_of_ev(&definition, zend_ce_closure TSRMLS_CC)) {
					ZEPHIR_INIT_VAR(&_8$$15);
					zephir_create_array(&_8$$15, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_8$$15, &arguments);
					zephir_array_fast_append(&_8$$15, &funcArguments);
					ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &definition, &_8$$15);
					zephir_check_call_status();
					RETURN_MM();
				}
			}
			ZEPHIR_INIT_VAR(&_9$$12);
			object_init_ex(&_9$$12, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_10$$12, &filter, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 807 TSRMLS_CC);
			zephir_array_fetch_string(&_11$$12, &filter, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 808 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_12$$12);
			ZEPHIR_CONCAT_SVSVSV(&_12$$12, "Invalid definition for user filter '", &name, "' in ", &_10$$12, " on line ", &_11$$12);
			ZEPHIR_CALL_METHOD(NULL, &_9$$12, "__construct", NULL, 391, &_12$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$12, "phalcon/mvc/view/engine/volt/compiler.zep", 808 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (ZEPHIR_IS_STRING(&name, "length")) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->length(", &arguments, ")");
		RETURN_MM();
	}
	_13 = ZEPHIR_IS_STRING(&name, "e");
	if (!(_13)) {
		_13 = ZEPHIR_IS_STRING(&name, "escape");
	}
	if (_13) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->escaper->escapeHtml(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "escape_css")) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->escaper->escapeCss(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "escape_js")) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->escaper->escapeJs(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "escape_attr")) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->escaper->escapeHtmlAttr(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "trim")) {
		ZEPHIR_CONCAT_SVS(return_value, "trim(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "left_trim")) {
		ZEPHIR_CONCAT_SVS(return_value, "ltrim(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "right_trim")) {
		ZEPHIR_CONCAT_SVS(return_value, "rtrim(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "striptags")) {
		ZEPHIR_CONCAT_SVS(return_value, "strip_tags(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "url_encode")) {
		ZEPHIR_CONCAT_SVS(return_value, "urlencode(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "slashes")) {
		ZEPHIR_CONCAT_SVS(return_value, "addslashes(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "stripslashes")) {
		ZEPHIR_CONCAT_SVS(return_value, "stripslashes(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "nl2br")) {
		ZEPHIR_CONCAT_SVS(return_value, "nl2br(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "keys")) {
		ZEPHIR_CONCAT_SVS(return_value, "array_keys(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "join")) {
		ZEPHIR_CONCAT_SVS(return_value, "join(", &arguments, ")");
		RETURN_MM();
	}
	_14 = ZEPHIR_IS_STRING(&name, "lower");
	if (!(_14)) {
		_14 = ZEPHIR_IS_STRING(&name, "lowercase");
	}
	if (_14) {
		ZEPHIR_CONCAT_SVS(return_value, "Phalcon\\Text::lower(", &arguments, ")");
		RETURN_MM();
	}
	_15 = ZEPHIR_IS_STRING(&name, "upper");
	if (!(_15)) {
		_15 = ZEPHIR_IS_STRING(&name, "uppercase");
	}
	if (_15) {
		ZEPHIR_CONCAT_SVS(return_value, "Phalcon\\Text::upper(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "capitalize")) {
		ZEPHIR_CONCAT_SVS(return_value, "ucwords(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "sort")) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->sort(", &arguments, ")");
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
	if (ZEPHIR_IS_STRING(&name, "format")) {
		ZEPHIR_CONCAT_SVS(return_value, "sprintf(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "abs")) {
		ZEPHIR_CONCAT_SVS(return_value, "abs(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "slice")) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->slice(", &arguments, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "default")) {
		ZEPHIR_CONCAT_SVSVSVS(return_value, "(empty(", &left, ") ? (", &arguments, ") : (", &left, "))");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(&name, "convert_encoding")) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->convertEncoding(", &arguments, ")");
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_16);
	object_init_ex(&_16, phalcon_mvc_view_engine_volt_exception_ce);
	zephir_array_fetch_string(&_17, &filter, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 997 TSRMLS_CC);
	zephir_array_fetch_string(&_18, &filter, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 997 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_19);
	ZEPHIR_CONCAT_SVSVSV(&_19, "Unknown filter \"", &name, "\" in ", &_17, " on line ", &_18);
	ZEPHIR_CALL_METHOD(NULL, &_16, "__construct", NULL, 391, &_19);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_16, "phalcon/mvc/view/engine/volt/compiler.zep", 997 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Resolves an expression node in an AST volt tree
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, expression) {

	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL, *_7 = NULL, *_9 = NULL, *_11 = NULL, *_17 = NULL, *_24 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, exprCode, extensions, items, singleExpr, singleExprCode, name, left, leftCode, right, rightCode, type, startCode, endCode, start, end, _1$$4, *_3$$6, _4$$7, _6$$8, _8$$12, _10$$13, _12$$31, _13$$31, _14$$31, _15$$31, _16$$35, _18$$69, _19$$69, _20$$73, _21$$73, _22$$73, _23$$73;
	zval expr, _0$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&exprCode);
	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&singleExpr);
	ZVAL_UNDEF(&singleExprCode);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&leftCode);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&rightCode);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&startCode);
	ZVAL_UNDEF(&endCode);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&end);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_12$$31);
	ZVAL_UNDEF(&_13$$31);
	ZVAL_UNDEF(&_14$$31);
	ZVAL_UNDEF(&_15$$31);
	ZVAL_UNDEF(&_16$$35);
	ZVAL_UNDEF(&_18$$69);
	ZVAL_UNDEF(&_19$$69);
	ZVAL_UNDEF(&_20$$73);
	ZVAL_UNDEF(&_21$$73);
	ZVAL_UNDEF(&_22$$73);
	ZVAL_UNDEF(&_23$$73);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);


	ZEPHIR_INIT_VAR(&exprCode);
	ZVAL_NULL(&exprCode);
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_exprLevel") TSRMLS_CC));
	ZEPHIR_OBS_VAR(&extensions);
	zephir_read_property(&extensions, this_ptr, SL("_extensions"), PH_NOISY_CC);
	while (1) {
		if (Z_TYPE_P(&extensions) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&_0$$4);
			zephir_create_array(&_0$$4, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_0$$4, &expr);
			ZEPHIR_INIT_NVAR(&_1$$4);
			ZVAL_STRING(&_1$$4, "resolveExpression");
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "fireextensionevent", &_2, 390, &_1$$4, &_0$$4);
			zephir_check_call_status();
			if (Z_TYPE_P(&exprCode) == IS_STRING) {
				break;
			}
		}
		ZEPHIR_OBS_NVAR(&type);
		if (!(zephir_array_isset_string_fetch(&type, &expr, SL("type"), 0))) {
			ZEPHIR_INIT_NVAR(&items);
			array_init(&items);
			zephir_is_iterable(&expr, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 1038);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&expr), _3$$6)
			{
				ZEPHIR_INIT_NVAR(&singleExpr);
				ZVAL_COPY(&singleExpr, _3$$6);
				zephir_array_fetch_string(&_4$$7, &singleExpr, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1031 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&singleExprCode, this_ptr, "expression", &_5, 389, &_4$$7);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&name);
				if (zephir_array_isset_string_fetch(&name, &singleExpr, SL("name"), 0)) {
					ZEPHIR_INIT_LNVAR(_6$$8);
					ZEPHIR_CONCAT_SVSV(&_6$$8, "'", &name, "' => ", &singleExprCode);
					zephir_array_append(&items, &_6$$8, PH_SEPARATE, "phalcon/mvc/view/engine/volt/compiler.zep", 1033);
				} else {
					zephir_array_append(&items, &singleExprCode, PH_SEPARATE, "phalcon/mvc/view/engine/volt/compiler.zep", 1035);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&singleExpr);
			ZEPHIR_INIT_NVAR(&exprCode);
			zephir_fast_join_str(&exprCode, SL(", "), &items TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&type, '.')) {
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "attributereader", &_7, 0, &expr);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_OBS_NVAR(&left);
		if (zephir_array_isset_string_fetch(&left, &expr, SL("left"), 0)) {
			ZEPHIR_CALL_METHOD(&leftCode, this_ptr, "expression", &_5, 389, &left);
			zephir_check_call_status();
		}
		if (ZEPHIR_IS_LONG(&type, 311)) {
			zephir_array_fetch_string(&_8$$12, &expr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1061 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "resolvetest", &_9, 0, &_8$$12, &leftCode);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 124)) {
			zephir_array_fetch_string(&_10$$13, &expr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1069 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "resolvefilter", &_11, 394, &_10$$13, &leftCode);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_OBS_NVAR(&right);
		if (zephir_array_isset_string_fetch(&right, &expr, SL("right"), 0)) {
			ZEPHIR_CALL_METHOD(&rightCode, this_ptr, "expression", &_5, 389, &right);
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
				zephir_array_fetch_string(&exprCode, &expr, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1136 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 259)) {
				ZEPHIR_OBS_NVAR(&exprCode);
				zephir_array_fetch_string(&exprCode, &expr, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1140 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 260)) {
				ZEPHIR_INIT_NVAR(&_12$$31);
				zephir_array_fetch_string(&_13$$31, &expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1144 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_14$$31);
				ZVAL_STRING(&_14$$31, "'");
				ZEPHIR_INIT_NVAR(&_15$$31);
				ZVAL_STRING(&_15$$31, "\\'");
				zephir_fast_str_replace(&_12$$31, &_14$$31, &_15$$31, &_13$$31 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVS(&exprCode, "'", &_12$$31, "'");
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
				zephir_array_fetch_string(&_16$$35, &expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1160 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SV(&exprCode, "$", &_16$$35);
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
				ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "functioncall", &_17, 0, &expr);
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
					ZEPHIR_CALL_METHOD(&startCode, this_ptr, "expression", &_5, 389, &start);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&startCode);
					ZVAL_STRING(&startCode, "null");
				}
				ZEPHIR_OBS_NVAR(&end);
				if (zephir_array_isset_string_fetch(&end, &expr, SL("end"), 0)) {
					ZEPHIR_CALL_METHOD(&endCode, this_ptr, "expression", &_5, 389, &end);
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
				zephir_array_fetch_string(&_19$$69, &expr, SL("ternary"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1299 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_18$$69, this_ptr, "expression", &_5, 389, &_19$$69);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVSVSVS(&exprCode, "(", &_18$$69, " ? ", &leftCode, " : ", &rightCode, ")");
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
				zephir_array_fetch_string(&exprCode, &expr, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1311 TSRMLS_CC);
				break;
			}
			ZEPHIR_INIT_NVAR(&_20$$73);
			object_init_ex(&_20$$73, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_21$$73, &expr, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1315 TSRMLS_CC);
			zephir_array_fetch_string(&_22$$73, &expr, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1315 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_23$$73);
			ZEPHIR_CONCAT_SVSVSV(&_23$$73, "Unknown expression ", &type, " in ", &_21$$73, " on line ", &_22$$73);
			ZEPHIR_CALL_METHOD(NULL, &_20$$73, "__construct", &_24, 391, &_23$$73);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_20$$73, "phalcon/mvc/view/engine/volt/compiler.zep", 1315 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

		break;
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_exprLevel") TSRMLS_CC));
	RETURN_CCTOR(&exprCode);

}

/**
 * Compiles a block of statements
 *
 * @param array statements
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementListOrExtends) {

	zend_bool isStatementList = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statements, statements_sub, statement, *_0$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statements_sub);
	ZVAL_UNDEF(&statement);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statements);



	if (Z_TYPE_P(statements) != IS_ARRAY) {
		RETVAL_ZVAL(statements, 1, 0);
		RETURN_MM();
	}
	isStatementList = 1;
	if (!(zephir_array_isset_string(statements, SL("type")))) {
		zephir_is_iterable(statements, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 1355);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(statements), _0$$4)
		{
			ZEPHIR_INIT_NVAR(&statement);
			ZVAL_COPY(&statement, _0$$4);
			if (Z_TYPE_P(&statement) != IS_ARRAY) {
				isStatementList = 0;
				break;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&statement);
	}
	if (isStatementList == 1) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_statementlist", NULL, 395, statements);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, compilation, prefix, level, prefixLevel, expr, exprCode, bstatement, type, blockStatements, forElse, code, loopContext, iterator, key, ifExpr, variable, _2, *_0$$4, _1$$8, _3$$9, _4$$9, _5$$9, _6$$9, _7$$9, _8$$9, _9$$9, _10$$9, _11$$9, _12$$11, _13$$12, _14$$13, _15$$13, _16$$15, _17$$15, _18$$15, _19$$15, _20$$15, _21$$15, _22$$16, _23$$20;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&compilation);
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$8);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$20);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &extendsMode_param);

	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	if (!(zephir_array_isset_string(&statement, SL("expr")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1383);
		return;
	}
	ZEPHIR_INIT_VAR(&compilation);
	ZVAL_STRING(&compilation, "");
	ZEPHIR_INIT_VAR(&forElse);
	ZVAL_NULL(&forElse);
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_foreachLevel") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(&prefix, this_ptr, "getuniqueprefix", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&level);
	zephir_read_property(&level, this_ptr, SL("_foreachLevel"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&prefixLevel);
	ZEPHIR_CONCAT_VV(&prefixLevel, &prefix, &level);
	ZEPHIR_OBS_VAR(&expr);
	zephir_array_fetch_string(&expr, &statement, SL("expr"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1401 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", NULL, 389, &expr);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&blockStatements);
	zephir_array_fetch_string(&blockStatements, &statement, SL("block_statements"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1407 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&forElse);
	ZVAL_BOOL(&forElse, 0);
	if (Z_TYPE_P(&blockStatements) == IS_ARRAY) {
		zephir_is_iterable(&blockStatements, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 1433);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&blockStatements), _0$$4)
		{
			ZEPHIR_INIT_NVAR(&bstatement);
			ZVAL_COPY(&bstatement, _0$$4);
			if (Z_TYPE_P(&bstatement) != IS_ARRAY) {
				break;
			}
			ZEPHIR_OBS_NVAR(&type);
			if (!(zephir_array_isset_string_fetch(&type, &bstatement, SL("type"), 0))) {
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 321)) {
				ZEPHIR_INIT_LNVAR(_1$$8);
				ZEPHIR_CONCAT_SVS(&_1$$8, "<?php $", &prefixLevel, "iterated = false; ?>");
				zephir_concat_self(&compilation, &_1$$8 TSRMLS_CC);
				ZEPHIR_CPY_WRT(&forElse, &prefixLevel);
				zephir_update_property_array(this_ptr, SL("_forElsePointers"), &level, &forElse TSRMLS_CC);
				break;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&bstatement);
	}
	if (extendsMode) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(&code, this_ptr, "_statementlist", NULL, 395, &blockStatements, &_2);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&loopContext);
	zephir_read_property(&loopContext, this_ptr, SL("_loopPointers"), PH_NOISY_CC);
	if (zephir_array_isset(&loopContext, &level)) {
		ZEPHIR_INIT_VAR(&_3$$9);
		ZEPHIR_CONCAT_SVSVS(&_3$$9, "<?php $", &prefixLevel, "iterator = ", &exprCode, "; ");
		zephir_concat_self(&compilation, &_3$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_4$$9);
		ZEPHIR_CONCAT_SVS(&_4$$9, "$", &prefixLevel, "incr = 0; ");
		zephir_concat_self(&compilation, &_4$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_5$$9);
		ZEPHIR_CONCAT_SVS(&_5$$9, "$", &prefixLevel, "loop = new stdClass(); ");
		zephir_concat_self(&compilation, &_5$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_6$$9);
		ZEPHIR_CONCAT_SVSVS(&_6$$9, "$", &prefixLevel, "loop->self = &$", &prefixLevel, "loop; ");
		zephir_concat_self(&compilation, &_6$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_7$$9);
		ZEPHIR_CONCAT_SVSVS(&_7$$9, "$", &prefixLevel, "loop->length = count($", &prefixLevel, "iterator); ");
		zephir_concat_self(&compilation, &_7$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_8$$9);
		ZEPHIR_CONCAT_SVS(&_8$$9, "$", &prefixLevel, "loop->index = 1; ");
		zephir_concat_self(&compilation, &_8$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_9$$9);
		ZEPHIR_CONCAT_SVS(&_9$$9, "$", &prefixLevel, "loop->index0 = 1; ");
		zephir_concat_self(&compilation, &_9$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_10$$9);
		ZEPHIR_CONCAT_SVSVS(&_10$$9, "$", &prefixLevel, "loop->revindex = $", &prefixLevel, "loop->length; ");
		zephir_concat_self(&compilation, &_10$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_11$$9);
		ZEPHIR_CONCAT_SVSVS(&_11$$9, "$", &prefixLevel, "loop->revindex0 = $", &prefixLevel, "loop->length - 1; ?>");
		zephir_concat_self(&compilation, &_11$$9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&iterator);
		ZEPHIR_CONCAT_SVS(&iterator, "$", &prefixLevel, "iterator");
	} else {
		ZEPHIR_CPY_WRT(&iterator, &exprCode);
	}
	ZEPHIR_OBS_VAR(&variable);
	zephir_array_fetch_string(&variable, &statement, SL("variable"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1463 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&key);
	if (zephir_array_isset_string_fetch(&key, &statement, SL("key"), 0)) {
		ZEPHIR_INIT_VAR(&_12$$11);
		ZEPHIR_CONCAT_SVSVSVS(&_12$$11, "<?php foreach (", &iterator, " as $", &key, " => $", &variable, ") { ");
		zephir_concat_self(&compilation, &_12$$11 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(&_13$$12);
		ZEPHIR_CONCAT_SVSVS(&_13$$12, "<?php foreach (", &iterator, " as $", &variable, ") { ");
		zephir_concat_self(&compilation, &_13$$12 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(&ifExpr);
	if (zephir_array_isset_string_fetch(&ifExpr, &statement, SL("if_expr"), 0)) {
		ZEPHIR_CALL_METHOD(&_14$$13, this_ptr, "expression", NULL, 389, &ifExpr);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_15$$13);
		ZEPHIR_CONCAT_SVS(&_15$$13, "if (", &_14$$13, ") { ?>");
		zephir_concat_self(&compilation, &_15$$13 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&compilation, SL("?>") TSRMLS_CC);
	}
	if (zephir_array_isset(&loopContext, &level)) {
		ZEPHIR_INIT_VAR(&_16$$15);
		ZEPHIR_CONCAT_SVSVS(&_16$$15, "<?php $", &prefixLevel, "loop->first = ($", &prefixLevel, "incr == 0); ");
		zephir_concat_self(&compilation, &_16$$15 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_17$$15);
		ZEPHIR_CONCAT_SVSVS(&_17$$15, "$", &prefixLevel, "loop->index = $", &prefixLevel, "incr + 1; ");
		zephir_concat_self(&compilation, &_17$$15 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_18$$15);
		ZEPHIR_CONCAT_SVSVS(&_18$$15, "$", &prefixLevel, "loop->index0 = $", &prefixLevel, "incr; ");
		zephir_concat_self(&compilation, &_18$$15 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_19$$15);
		ZEPHIR_CONCAT_SVSVSVS(&_19$$15, "$", &prefixLevel, "loop->revindex = $", &prefixLevel, "loop->length - $", &prefixLevel, "incr; ");
		zephir_concat_self(&compilation, &_19$$15 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_20$$15);
		ZEPHIR_CONCAT_SVSVSVS(&_20$$15, "$", &prefixLevel, "loop->revindex0 = $", &prefixLevel, "loop->length - ($", &prefixLevel, "incr + 1); ");
		zephir_concat_self(&compilation, &_20$$15 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_21$$15);
		ZEPHIR_CONCAT_SVSVSVS(&_21$$15, "$", &prefixLevel, "loop->last = ($", &prefixLevel, "incr == ($", &prefixLevel, "loop->length - 1)); ?>");
		zephir_concat_self(&compilation, &_21$$15 TSRMLS_CC);
	}
	if (Z_TYPE_P(&forElse) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_22$$16);
		ZEPHIR_CONCAT_SVS(&_22$$16, "<?php $", &forElse, "iterated = true; ?>");
		zephir_concat_self(&compilation, &_22$$16 TSRMLS_CC);
	}
	zephir_concat_self(&compilation, &code TSRMLS_CC);
	if (zephir_array_isset_string(&statement, SL("if_expr"))) {
		zephir_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
	}
	if (Z_TYPE_P(&forElse) == IS_STRING) {
		zephir_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
	} else {
		if (zephir_array_isset(&loopContext, &level)) {
			ZEPHIR_INIT_VAR(&_23$$20);
			ZEPHIR_CONCAT_SVS(&_23$$20, "<?php $", &prefixLevel, "incr++; } ?>");
			zephir_concat_self(&compilation, &_23$$20 TSRMLS_CC);
		} else {
			zephir_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
		}
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_foreachLevel") TSRMLS_CC));
	RETURN_CCTOR(&compilation);

}

/**
 * Generates a 'forelse' PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForElse) {

	zval level, prefix, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);


	zephir_read_property(&level, this_ptr, SL("_foreachLevel"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_0, this_ptr, SL("_forElsePointers"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&prefix, &_0, &level, 1 TSRMLS_CC)) {
		zephir_read_property(&_1$$3, this_ptr, SL("_loopPointers"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_1$$3, &level)) {
			ZEPHIR_CONCAT_SVSVS(return_value, "<?php $", &prefix, "incr++; } if (!$", &prefix, "iterated) { ?>");
			return;
		}
		ZEPHIR_CONCAT_SVS(return_value, "<?php } if (!$", &prefix, "iterated) { ?>");
		return;
	}
	RETURN_STRING("");

}

/**
 * Compiles a 'if' statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileIf) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, compilation, blockStatements, expr, _2, _3, _4, _5, _0$$3, _1$$3, _6$$4, _7$$4, _8$$4;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&compilation);
	ZVAL_UNDEF(&blockStatements);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &extendsMode_param);

	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	ZEPHIR_OBS_VAR(&expr);
	if (!(zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Corrupt statement");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 391, &_1$$3, &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/mvc/view/engine/volt/compiler.zep", 1554 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 389, &expr);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, &statement, SL("true_statements"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1560 TSRMLS_CC);
	if (extendsMode) {
		ZVAL_BOOL(&_5, 1);
	} else {
		ZVAL_BOOL(&_5, 0);
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "_statementlist", NULL, 395, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&compilation);
	ZEPHIR_CONCAT_SVSV(&compilation, "<?php if (", &_2, ") { ?>", &_3);
	ZEPHIR_OBS_VAR(&blockStatements);
	if (zephir_array_isset_string_fetch(&blockStatements, &statement, SL("false_statements"), 0)) {
		if (extendsMode) {
			ZVAL_BOOL(&_7$$4, 1);
		} else {
			ZVAL_BOOL(&_7$$4, 0);
		}
		ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "_statementlist", NULL, 395, &blockStatements, &_7$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$4);
		ZEPHIR_CONCAT_SV(&_8$$4, "<?php } else { ?>", &_6$$4);
		zephir_concat_self(&compilation, &_8$$4 TSRMLS_CC);
	}
	zephir_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
	RETURN_CCTOR(&compilation);

}

/**
 * Compiles a 'switch' statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSwitch) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &extendsMode_param);

	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	ZEPHIR_OBS_VAR(&expr);
	if (!(zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Corrupt statement");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 391, &_1$$3, &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/mvc/view/engine/volt/compiler.zep", 1589 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 389, &expr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&compilation);
	ZEPHIR_CONCAT_SVS(&compilation, "<?php switch (", &_2, "): ?>");
	ZEPHIR_OBS_VAR(&caseClauses);
	if (zephir_array_isset_string_fetch(&caseClauses, &statement, SL("case_clauses"), 0)) {
		if (extendsMode) {
			ZVAL_BOOL(&_3$$4, 1);
		} else {
			ZVAL_BOOL(&_3$$4, 0);
		}
		ZEPHIR_CALL_METHOD(&lines, this_ptr, "_statementlist", NULL, 395, &caseClauses, &_3$$4);
		zephir_check_call_status();
		if (zephir_fast_strlen_ev(&lines) != 0) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "/(*ANYCRLF)^\\h+|\\h+$|(\\h){2,}/mu");
			ZEPHIR_INIT_VAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "");
			ZEPHIR_CALL_FUNCTION(&_6$$5, "preg_replace", NULL, 23, &_4$$5, &_5$$5, &lines);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&lines, &_6$$5);
		}
		zephir_concat_self(&compilation, &lines TSRMLS_CC);
	}
	zephir_concat_self_str(&compilation, SL("<?php endswitch ?>") TSRMLS_CC);
	RETURN_CCTOR(&compilation);

}

/**
 * Compiles a "case"/"default" clause returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCase) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &caseClause_param);

	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	if (!caseClause_param) {
		caseClause = 1;
	} else {
		caseClause = zephir_get_boolval(caseClause_param);
	}


	if (UNEXPECTED(caseClause == 0)) {
		RETURN_MM_STRING("<?php default: ?>");
	}
	ZEPHIR_OBS_VAR(&expr);
	if (!(zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0))) {
		ZEPHIR_INIT_VAR(&_0$$4);
		object_init_ex(&_0$$4, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "Corrupt statement");
		ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 391, &_1$$4, &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$4, "phalcon/mvc/view/engine/volt/compiler.zep", 1649 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 389, &expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php case ", &_2, ": ?>");
	RETURN_MM();

}

/**
 * Compiles a "elseif" statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileElseIf) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, expr, _2, _0$$3, _1$$3;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);


	ZEPHIR_OBS_VAR(&expr);
	if (!(zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Corrupt statement");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 391, &_1$$3, &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/mvc/view/engine/volt/compiler.zep", 1669 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 389, &expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php } elseif (", &_2, ") { ?>");
	RETURN_MM();

}

/**
 * Compiles a "cache" statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCache) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, compilation, expr, exprCode, lifetime, _2, _10, _11, _12, _13, _0$$3, _1$$3, _3$$4, _4$$4, _5$$5, _6$$5, _7$$6, _8$$6, _9$$7, _14$$8, _19$$8, _15$$9, _16$$9, _17$$10, _18$$10, _20$$11;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&compilation);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&exprCode);
	ZVAL_UNDEF(&lifetime);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_20$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &extendsMode_param);

	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	ZEPHIR_OBS_VAR(&expr);
	if (!(zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Corrupt statement");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 391, &_1$$3, &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/mvc/view/engine/volt/compiler.zep", 1689 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", NULL, 389, &expr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 389, &expr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&compilation);
	ZEPHIR_CONCAT_SVS(&compilation, "<?php $_cache[", &_2, "] = $this->di->get('viewCache'); ");
	ZEPHIR_OBS_VAR(&lifetime);
	if (zephir_array_isset_string_fetch(&lifetime, &statement, SL("lifetime"), 0)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_SVS(&_3$$4, "$_cacheKey[", &exprCode, "]");
		zephir_concat_self(&compilation, &_3$$4 TSRMLS_CC);
		zephir_array_fetch_string(&_4$$4, &lifetime, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1699 TSRMLS_CC);
		if (ZEPHIR_IS_LONG(&_4$$4, 265)) {
			zephir_array_fetch_string(&_5$$5, &lifetime, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1700 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_6$$5);
			ZEPHIR_CONCAT_SVSVSVS(&_6$$5, " = $_cache[", &exprCode, "]->start(", &exprCode, ", $", &_5$$5, "); ");
			zephir_concat_self(&compilation, &_6$$5 TSRMLS_CC);
		} else {
			zephir_array_fetch_string(&_7$$6, &lifetime, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1702 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_8$$6);
			ZEPHIR_CONCAT_SVSVSVS(&_8$$6, " = $_cache[", &exprCode, "]->start(", &exprCode, ", ", &_7$$6, "); ");
			zephir_concat_self(&compilation, &_8$$6 TSRMLS_CC);
		}
	} else {
		ZEPHIR_INIT_VAR(&_9$$7);
		ZEPHIR_CONCAT_SVSVSVS(&_9$$7, "$_cacheKey[", &exprCode, "] = $_cache[", &exprCode, "]->start(", &exprCode, "); ");
		zephir_concat_self(&compilation, &_9$$7 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_SVS(&_10, "if ($_cacheKey[", &exprCode, "] === null) { ?>");
	zephir_concat_self(&compilation, &_10 TSRMLS_CC);
	zephir_array_fetch_string(&_12, &statement, SL("block_statements"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1712 TSRMLS_CC);
	if (extendsMode) {
		ZVAL_BOOL(&_13, 1);
	} else {
		ZVAL_BOOL(&_13, 0);
	}
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "_statementlist", NULL, 395, &_12, &_13);
	zephir_check_call_status();
	zephir_concat_self(&compilation, &_11 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(&lifetime);
	if (zephir_array_isset_string_fetch(&lifetime, &statement, SL("lifetime"), 0)) {
		zephir_array_fetch_string(&_14$$8, &lifetime, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1718 TSRMLS_CC);
		if (ZEPHIR_IS_LONG(&_14$$8, 265)) {
			zephir_array_fetch_string(&_15$$9, &lifetime, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1719 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_16$$9);
			ZEPHIR_CONCAT_SVSVSVS(&_16$$9, "<?php $_cache[", &exprCode, "]->save(", &exprCode, ", null, $", &_15$$9, "); ");
			zephir_concat_self(&compilation, &_16$$9 TSRMLS_CC);
		} else {
			zephir_array_fetch_string(&_17$$10, &lifetime, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1721 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_18$$10);
			ZEPHIR_CONCAT_SVSVSVS(&_18$$10, "<?php $_cache[", &exprCode, "]->save(", &exprCode, ", null, ", &_17$$10, "); ");
			zephir_concat_self(&compilation, &_18$$10 TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(&_19$$8);
		ZEPHIR_CONCAT_SVS(&_19$$8, "} else { echo $_cacheKey[", &exprCode, "]; } ?>");
		zephir_concat_self(&compilation, &_19$$8 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(&_20$$11);
		ZEPHIR_CONCAT_SVSVSVS(&_20$$11, "<?php $_cache[", &exprCode, "]->save(", &exprCode, "); } else { echo $_cacheKey[", &exprCode, "]; } ?>");
		zephir_concat_self(&compilation, &_20$$11 TSRMLS_CC);
	}
	RETURN_CCTOR(&compilation);

}

/**
 * Compiles a "set" statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSet) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, assignments, assignment, exprCode, target, compilation, *_0, _1$$4, _3$$4, _4$$4, _5$$5, _6$$6, _7$$7, _8$$8, _9$$9;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&assignments);
	ZVAL_UNDEF(&assignment);
	ZVAL_UNDEF(&exprCode);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&compilation);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);


	ZEPHIR_OBS_VAR(&assignments);
	if (!(zephir_array_isset_string_fetch(&assignments, &statement, SL("assignments"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1742);
		return;
	}
	ZEPHIR_INIT_VAR(&compilation);
	ZVAL_STRING(&compilation, "<?php");
	zephir_is_iterable(&assignments, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 1788);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&assignments), _0)
	{
		ZEPHIR_INIT_NVAR(&assignment);
		ZVAL_COPY(&assignment, _0);
		zephir_array_fetch_string(&_1$$4, &assignment, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1752 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", &_2, 389, &_1$$4);
		zephir_check_call_status();
		zephir_array_fetch_string(&_3$$4, &assignment, SL("variable"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1757 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&target, this_ptr, "expression", &_2, 389, &_3$$4);
		zephir_check_call_status();
		zephir_array_fetch_string(&_4$$4, &assignment, SL("op"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1763 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(&_4$$4, 281)) {
				ZEPHIR_INIT_LNVAR(_5$$5);
				ZEPHIR_CONCAT_SVSVS(&_5$$5, " ", &target, " += ", &exprCode, ";");
				zephir_concat_self(&compilation, &_5$$5 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&_4$$4, 282)) {
				ZEPHIR_INIT_LNVAR(_6$$6);
				ZEPHIR_CONCAT_SVSVS(&_6$$6, " ", &target, " -= ", &exprCode, ";");
				zephir_concat_self(&compilation, &_6$$6 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&_4$$4, 283)) {
				ZEPHIR_INIT_LNVAR(_7$$7);
				ZEPHIR_CONCAT_SVSVS(&_7$$7, " ", &target, " *= ", &exprCode, ";");
				zephir_concat_self(&compilation, &_7$$7 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&_4$$4, 284)) {
				ZEPHIR_INIT_LNVAR(_8$$8);
				ZEPHIR_CONCAT_SVSVS(&_8$$8, " ", &target, " /= ", &exprCode, ";");
				zephir_concat_self(&compilation, &_8$$8 TSRMLS_CC);
				break;
			}
			ZEPHIR_INIT_LNVAR(_9$$9);
			ZEPHIR_CONCAT_SVSVS(&_9$$9, " ", &target, " = ", &exprCode, ";");
			zephir_concat_self(&compilation, &_9$$9 TSRMLS_CC);
			break;
		} while(0);

	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&assignment);
	zephir_concat_self_str(&compilation, SL(" ?>") TSRMLS_CC);
	RETURN_CCTOR(&compilation);

}

/**
 * Compiles a "do" statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileDo) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, expr, _0;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);


	ZEPHIR_OBS_VAR(&expr);
	if (!(zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1803);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "expression", NULL, 389, &expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php ", &_0, "; ?>");
	RETURN_MM();

}

/**
 * Compiles a "return" statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileReturn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, expr, _0;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);


	ZEPHIR_OBS_VAR(&expr);
	if (!(zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1823);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "expression", NULL, 389, &expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php return ", &_0, "; ?>");
	RETURN_MM();

}

/**
 * Compiles a "autoescape" statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileAutoEscape) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &statement_param, &extendsMode_param);

	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	extendsMode = zephir_get_boolval(extendsMode_param);


	ZEPHIR_OBS_VAR(&autoescape);
	if (!(zephir_array_isset_string_fetch(&autoescape, &statement, SL("enable"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1843);
		return;
	}
	ZEPHIR_OBS_VAR(&oldAutoescape);
	zephir_read_property(&oldAutoescape, this_ptr, SL("_autoescape"), PH_NOISY_CC);
	zephir_update_property_zval(this_ptr, SL("_autoescape"), &autoescape);
	zephir_array_fetch_string(&_0, &statement, SL("block_statements"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1852 TSRMLS_CC);
	if (extendsMode) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(&compilation, this_ptr, "_statementlist", NULL, 395, &_0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_autoescape"), &oldAutoescape);
	RETURN_CCTOR(&compilation);

}

/**
 * Compiles a '{{' '}}' statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileEcho) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, expr, exprCode, name, _2, _5, _0$$3, _1$$3, _3$$4, _4$$5;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&exprCode);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);


	ZEPHIR_OBS_VAR(&expr);
	if (!(zephir_array_isset_string_fetch(&expr, &statement, SL("expr"), 0))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Corrupt statement");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 391, &_1$$3, &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/mvc/view/engine/volt/compiler.zep", 1869 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", NULL, 389, &expr);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, &expr, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1877 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(&_2, 350)) {
		zephir_array_fetch_string(&name, &expr, SL("name"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1879 TSRMLS_CC);
		zephir_array_fetch_string(&_3$$4, &name, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1881 TSRMLS_CC);
		if (ZEPHIR_IS_LONG(&_3$$4, 265)) {
			zephir_array_fetch_string(&_4$$5, &name, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1886 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(&_4$$5, "super")) {
				RETURN_CCTOR(&exprCode);
			}
		}
	}
	zephir_read_property(&_5, this_ptr, SL("_autoescape"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_5)) {
		ZEPHIR_CONCAT_SVS(return_value, "<?= $this->escaper->escapeHtml(", &exprCode, ") ?>");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "<?= ", &exprCode, " ?>");
	RETURN_MM();

}

/**
 * Compiles a 'include' statement returning PHP code
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileInclude) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);


	ZEPHIR_OBS_VAR(&pathExpr);
	if (!(zephir_array_isset_string_fetch(&pathExpr, &statement, SL("path"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1914);
		return;
	}
	zephir_array_fetch_string(&_0, &pathExpr, SL("type"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 1921 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(&_0, 260)) {
		if (!(zephir_array_isset_string(&statement, SL("params")))) {
			ZEPHIR_OBS_VAR(&path);
			zephir_array_fetch_string(&path, &pathExpr, SL("value"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 1931 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&finalPath, this_ptr, "getfinalpath", NULL, 0, &path);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&subCompiler);
			if (zephir_clone(&subCompiler, this_ptr TSRMLS_CC) == FAILURE) {
				RETURN_MM();
			}
			ZVAL_BOOL(&_1$$5, 0);
			ZEPHIR_CALL_METHOD(&compilation, &subCompiler, "compile", NULL, 0, &finalPath, &_1$$5);
			zephir_check_call_status();
			if (Z_TYPE_P(&compilation) == IS_NULL) {
				ZEPHIR_CALL_METHOD(&_2$$6, &subCompiler, "getcompiledtemplatepath", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&compilation);
				zephir_file_get_contents(&compilation, &_2$$6 TSRMLS_CC);
			}
			RETURN_CCTOR(&compilation);
		}
	}
	ZEPHIR_CALL_METHOD(&path, this_ptr, "expression", NULL, 389, &pathExpr);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&params);
	if (!(zephir_array_isset_string_fetch(&params, &statement, SL("params"), 0))) {
		ZEPHIR_CONCAT_SVS(return_value, "<?php $this->partial(", &path, "); ?>");
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "expression", NULL, 389, &params);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "<?php $this->partial(", &path, ", ", &_3, "); ?>");
	RETURN_MM();

}

/**
 * Compiles macros
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileMacro) {

	zend_string *_7$$6;
	zend_ulong _6$$6;
	zephir_fcall_cache_entry *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL, code, name, defaultValue, macroName, parameters, position, parameter, variableName, blockStatements, _0, _19, _1$$4, _2$$4, _3$$5, _4$$6, *_5$$6, _8$$7, _9$$7, _10$$7, _11$$7, _12$$8, _14$$8, _15$$9, _16$$10, _17$$10, _18$$10;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&macroName);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&parameter);
	ZVAL_UNDEF(&variableName);
	ZVAL_UNDEF(&blockStatements);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &statement_param, &extendsMode_param);

	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	extendsMode = zephir_get_boolval(extendsMode_param);


	ZEPHIR_OBS_VAR(&name);
	if (!(zephir_array_isset_string_fetch(&name, &statement, SL("name"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 1981);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("_macros"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &name)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SVS(&_2$$4, "Macro '", &name, "' is already defined");
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 391, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/mvc/view/engine/volt/compiler.zep", 1988 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("_macros"), &name, &name TSRMLS_CC);
	ZEPHIR_INIT_VAR(&macroName);
	ZEPHIR_CONCAT_SVS(&macroName, "$this->_macros['", &name, "']");
	ZEPHIR_INIT_VAR(&code);
	ZVAL_STRING(&code, "<?php ");
	ZEPHIR_OBS_VAR(&parameters);
	if (!(zephir_array_isset_string_fetch(&parameters, &statement, SL("parameters"), 0))) {
		ZEPHIR_INIT_VAR(&_3$$5);
		ZEPHIR_CONCAT_VS(&_3$$5, &macroName, " = function() { ?>");
		zephir_concat_self(&code, &_3$$5 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(&_4$$6);
		ZEPHIR_CONCAT_VS(&_4$$6, &macroName, " = function($__p = null) { ");
		zephir_concat_self(&code, &_4$$6 TSRMLS_CC);
		zephir_is_iterable(&parameters, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 2025);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parameters), _6$$6, _7$$6, _5$$6)
		{
			ZEPHIR_INIT_NVAR(&position);
			if (_7$$6 != NULL) { 
				ZVAL_STR_COPY(&position, _7$$6);
			} else {
				ZVAL_LONG(&position, _6$$6);
			}
			ZEPHIR_INIT_NVAR(&parameter);
			ZVAL_COPY(&parameter, _5$$6);
			ZEPHIR_OBS_NVAR(&variableName);
			zephir_array_fetch_string(&variableName, &parameter, SL("variable"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2009 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_8$$7);
			ZEPHIR_CONCAT_SVS(&_8$$7, "if (isset($__p[", &position, "])) { ");
			zephir_concat_self(&code, &_8$$7 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_9$$7);
			ZEPHIR_CONCAT_SVSVS(&_9$$7, "$", &variableName, " = $__p[", &position, "];");
			zephir_concat_self(&code, &_9$$7 TSRMLS_CC);
			zephir_concat_self_str(&code, SL(" } else { ") TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_10$$7);
			ZEPHIR_CONCAT_SVS(&_10$$7, "if (array_key_exists(\"", &variableName, "\", $__p)) { ");
			zephir_concat_self(&code, &_10$$7 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_11$$7);
			ZEPHIR_CONCAT_SVSVS(&_11$$7, "$", &variableName, " = $__p[\"", &variableName, "\"];");
			zephir_concat_self(&code, &_11$$7 TSRMLS_CC);
			zephir_concat_self_str(&code, SL(" } else { ") TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&defaultValue);
			if (zephir_array_isset_string_fetch(&defaultValue, &parameter, SL("default"), 0)) {
				ZEPHIR_CALL_METHOD(&_12$$8, this_ptr, "expression", &_13, 389, &defaultValue);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_14$$8);
				ZEPHIR_CONCAT_SVSVS(&_14$$8, "$", &variableName, " = ", &_12$$8, ";");
				zephir_concat_self(&code, &_14$$8 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_15$$9);
				ZEPHIR_CONCAT_SVSVS(&_15$$9, " throw new \\Phalcon\\Mvc\\View\\Exception(\"Macro '", &name, "' was called without parameter: ", &variableName, "\"); ");
				zephir_concat_self(&code, &_15$$9 TSRMLS_CC);
			}
			zephir_concat_self_str(&code, SL(" } } ") TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&parameter);
		ZEPHIR_INIT_NVAR(&position);
		zephir_concat_self_str(&code, SL(" ?>") TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(&blockStatements);
	if (zephir_array_isset_string_fetch(&blockStatements, &statement, SL("block_statements"), 0)) {
		if (extendsMode) {
			ZVAL_BOOL(&_17$$10, 1);
		} else {
			ZVAL_BOOL(&_17$$10, 0);
		}
		ZEPHIR_CALL_METHOD(&_16$$10, this_ptr, "_statementlist", NULL, 395, &blockStatements, &_17$$10);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_18$$10);
		ZEPHIR_CONCAT_VS(&_18$$10, &_16$$10, "<?php }; ");
		zephir_concat_self(&code, &_18$$10 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&code, SL("<?php }; ") TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(&_19);
	ZEPHIR_CONCAT_VSVS(&_19, &macroName, " = \\Closure::bind(", &macroName, ", $this); ?>");
	zephir_concat_self(&code, &_19 TSRMLS_CC);
	RETURN_CCTOR(&code);

}

/**
 * Compiles calls to macros
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCall) {

	zend_bool extendsMode;
	zval *statement_param = NULL, *extendsMode_param = NULL;
	zval statement;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statement);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &statement_param, &extendsMode_param);

	ZEPHIR_OBS_COPY_OR_DUP(&statement, statement_param);
	extendsMode = zephir_get_boolval(extendsMode_param);



}

/**
 * Traverses a statement list compiling each of its nodes
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementList) {

	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL, *_13 = NULL, *_15 = NULL, *_18 = NULL, *_20 = NULL, *_25 = NULL, *_27 = NULL, *_29 = NULL, *_32 = NULL, *_34 = NULL, *_37 = NULL, *_40 = NULL, *_42 = NULL, *_44 = NULL, *_47 = NULL, *_49 = NULL, *_52 = NULL, *_55 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode, _0;
	zval *statements_param = NULL, *extendsMode_param = NULL, __$true, __$false, extended, blockMode, compilation, extensions, statement, tempCompilation, type, blockName, blockStatements, blocks, path, finalPath, subCompiler, level, *_1, _2$$7, _3$$7, _4$$7, _5$$7, _8$$8, _10$$10, _11$$11, _12$$11, _14$$12, _16$$13, _17$$13, _19$$14, _21$$15, _22$$15, _23$$16, _24$$16, _26$$17, _28$$18, _30$$24, _31$$24, _33$$25, _35$$26, _36$$27, _38$$28, _39$$28, _41$$29, _43$$30, _45$$31, _46$$31, _48$$34, _50$$35, _51$$35, _53$$36, _54$$36, _56$$38, _57$$38, _58$$38, _59$$38;
	zval statements, _7$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statements);
	ZVAL_UNDEF(&_7$$8);
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
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_30$$24);
	ZVAL_UNDEF(&_31$$24);
	ZVAL_UNDEF(&_33$$25);
	ZVAL_UNDEF(&_35$$26);
	ZVAL_UNDEF(&_36$$27);
	ZVAL_UNDEF(&_38$$28);
	ZVAL_UNDEF(&_39$$28);
	ZVAL_UNDEF(&_41$$29);
	ZVAL_UNDEF(&_43$$30);
	ZVAL_UNDEF(&_45$$31);
	ZVAL_UNDEF(&_46$$31);
	ZVAL_UNDEF(&_48$$34);
	ZVAL_UNDEF(&_50$$35);
	ZVAL_UNDEF(&_51$$35);
	ZVAL_UNDEF(&_53$$36);
	ZVAL_UNDEF(&_54$$36);
	ZVAL_UNDEF(&_56$$38);
	ZVAL_UNDEF(&_57$$38);
	ZVAL_UNDEF(&_58$$38);
	ZVAL_UNDEF(&_59$$38);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statements_param, &extendsMode_param);

	ZEPHIR_OBS_COPY_OR_DUP(&statements, statements_param);
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	if (!(zephir_fast_count_int(&statements TSRMLS_CC))) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_OBS_VAR(&extended);
	zephir_read_property(&extended, this_ptr, SL("_extended"), PH_NOISY_CC);
	_0 = zephir_is_true(&extended);
	if (!(_0)) {
		_0 = extendsMode;
	}
	ZEPHIR_INIT_VAR(&blockMode);
	ZVAL_BOOL(&blockMode, _0);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&blockMode)) {
		RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_blockLevel") TSRMLS_CC));
	}
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_level") TSRMLS_CC));
	ZEPHIR_INIT_VAR(&compilation);
	ZVAL_NULL(&compilation);
	ZEPHIR_OBS_VAR(&extensions);
	zephir_read_property(&extensions, this_ptr, SL("_extensions"), PH_NOISY_CC);
	zephir_is_iterable(&statements, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 2300);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&statements), _1)
	{
		ZEPHIR_INIT_NVAR(&statement);
		ZVAL_COPY(&statement, _1);
		if (Z_TYPE_P(&statement) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/mvc/view/engine/volt/compiler.zep", 2093);
			return;
		}
		if (!(zephir_array_isset_string(&statement, SL("type")))) {
			ZEPHIR_INIT_NVAR(&_2$$7);
			object_init_ex(&_2$$7, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_3$$7, &statement, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 2100 TSRMLS_CC);
			zephir_array_fetch_string(&_4$$7, &statement, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 2100 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_5$$7);
			ZEPHIR_CONCAT_SVSV(&_5$$7, "Invalid statement in ", &_3$$7, " on line ", &_4$$7);
			ZEPHIR_CALL_METHOD(NULL, &_2$$7, "__construct", &_6, 391, &_5$$7, &statement);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$7, "phalcon/mvc/view/engine/volt/compiler.zep", 2100 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&extensions) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&_7$$8);
			zephir_create_array(&_7$$8, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_7$$8, &statement);
			ZEPHIR_INIT_NVAR(&_8$$8);
			ZVAL_STRING(&_8$$8, "compileStatement");
			ZEPHIR_CALL_METHOD(&tempCompilation, this_ptr, "fireextensionevent", &_9, 390, &_8$$8, &_7$$8);
			zephir_check_call_status();
			if (Z_TYPE_P(&tempCompilation) == IS_STRING) {
				zephir_concat_self(&compilation, &tempCompilation TSRMLS_CC);
				continue;
			}
		}
		ZEPHIR_OBS_NVAR(&type);
		zephir_array_fetch_string(&type, &statement, SL("type"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2121 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(&type, 357)) {
				zephir_array_fetch_string(&_10$$10, &statement, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 2129 TSRMLS_CC);
				zephir_concat_self(&compilation, &_10$$10 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 300)) {
				if (extendsMode) {
					ZVAL_BOOL(&_12$$11, 1);
				} else {
					ZVAL_BOOL(&_12$$11, 0);
				}
				ZEPHIR_CALL_METHOD(&_11$$11, this_ptr, "compileif", &_13, 0, &statement, &_12$$11);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_11$$11 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 302)) {
				ZEPHIR_CALL_METHOD(&_14$$12, this_ptr, "compileelseif", &_15, 0, &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_14$$12 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 411)) {
				if (extendsMode) {
					ZVAL_BOOL(&_17$$13, 1);
				} else {
					ZVAL_BOOL(&_17$$13, 0);
				}
				ZEPHIR_CALL_METHOD(&_16$$13, this_ptr, "compileswitch", &_18, 0, &statement, &_17$$13);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_16$$13 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 412)) {
				ZEPHIR_CALL_METHOD(&_19$$14, this_ptr, "compilecase", &_20, 0, &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_19$$14 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 413)) {
				ZVAL_BOOL(&_22$$15, 0);
				ZEPHIR_CALL_METHOD(&_21$$15, this_ptr, "compilecase", &_20, 0, &statement, &_22$$15);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_21$$15 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 304)) {
				if (extendsMode) {
					ZVAL_BOOL(&_24$$16, 1);
				} else {
					ZVAL_BOOL(&_24$$16, 0);
				}
				ZEPHIR_CALL_METHOD(&_23$$16, this_ptr, "compileforeach", &_25, 0, &statement, &_24$$16);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_23$$16 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 306)) {
				ZEPHIR_CALL_METHOD(&_26$$17, this_ptr, "compileset", &_27, 0, &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_26$$17 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 359)) {
				ZEPHIR_CALL_METHOD(&_28$$18, this_ptr, "compileecho", &_29, 0, &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_28$$18 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 307)) {
				ZEPHIR_OBS_NVAR(&blockName);
				zephir_array_fetch_string(&blockName, &statement, SL("name"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2169 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&blockStatements);
				zephir_array_isset_string_fetch(&blockStatements, &statement, SL("block_statements"), 0);
				ZEPHIR_OBS_NVAR(&blocks);
				zephir_read_property(&blocks, this_ptr, SL("_blocks"), PH_NOISY_CC);
				if (zephir_is_true(&blockMode)) {
					if (Z_TYPE_P(&blocks) != IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&blocks);
						array_init(&blocks);
					}
					if (Z_TYPE_P(&compilation) != IS_NULL) {
						zephir_array_append(&blocks, &compilation, PH_SEPARATE, "phalcon/mvc/view/engine/volt/compiler.zep", 2184);
						ZEPHIR_INIT_NVAR(&compilation);
						ZVAL_NULL(&compilation);
					}
					zephir_array_update_zval(&blocks, &blockName, &blockStatements, PH_COPY | PH_SEPARATE);
					zephir_update_property_zval(this_ptr, SL("_blocks"), &blocks);
				} else {
					if (Z_TYPE_P(&blockStatements) == IS_ARRAY) {
						if (extendsMode) {
							ZVAL_BOOL(&_31$$24, 1);
						} else {
							ZVAL_BOOL(&_31$$24, 0);
						}
						ZEPHIR_CALL_METHOD(&_30$$24, this_ptr, "_statementlist", &_32, 395, &blockStatements, &_31$$24);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_30$$24 TSRMLS_CC);
					}
				}
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 310)) {
				ZEPHIR_OBS_NVAR(&path);
				zephir_array_fetch_string(&path, &statement, SL("path"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2206 TSRMLS_CC);
				zephir_array_fetch_string(&_33$$25, &path, SL("value"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 2208 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&finalPath, this_ptr, "getfinalpath", &_34, 0, &_33$$25);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&extended);
				ZVAL_BOOL(&extended, 1);
				ZEPHIR_INIT_NVAR(&subCompiler);
				if (zephir_clone(&subCompiler, this_ptr TSRMLS_CC) == FAILURE) {
					RETURN_MM();
				}
				ZEPHIR_CALL_METHOD(&tempCompilation, &subCompiler, "compile", NULL, 0, &finalPath, &extended);
				zephir_check_call_status();
				if (Z_TYPE_P(&tempCompilation) == IS_NULL) {
					ZEPHIR_CALL_METHOD(&_35$$26, &subCompiler, "getcompiledtemplatepath", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&tempCompilation);
					zephir_file_get_contents(&tempCompilation, &_35$$26 TSRMLS_CC);
				}
				if (1) {
					zephir_update_property_zval(this_ptr, SL("_extended"), &__$true);
				} else {
					zephir_update_property_zval(this_ptr, SL("_extended"), &__$false);
				}
				zephir_update_property_zval(this_ptr, SL("_extendedBlocks"), &tempCompilation);
				ZEPHIR_CPY_WRT(&blockMode, &extended);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 313)) {
				ZEPHIR_CALL_METHOD(&_36$$27, this_ptr, "compileinclude", &_37, 0, &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_36$$27 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 314)) {
				if (extendsMode) {
					ZVAL_BOOL(&_39$$28, 1);
				} else {
					ZVAL_BOOL(&_39$$28, 0);
				}
				ZEPHIR_CALL_METHOD(&_38$$28, this_ptr, "compilecache", &_40, 0, &statement, &_39$$28);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_38$$28 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 316)) {
				ZEPHIR_CALL_METHOD(&_41$$29, this_ptr, "compiledo", &_42, 0, &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_41$$29 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 327)) {
				ZEPHIR_CALL_METHOD(&_43$$30, this_ptr, "compilereturn", &_44, 0, &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_43$$30 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 317)) {
				if (extendsMode) {
					ZVAL_BOOL(&_46$$31, 1);
				} else {
					ZVAL_BOOL(&_46$$31, 0);
				}
				ZEPHIR_CALL_METHOD(&_45$$31, this_ptr, "compileautoescape", &_47, 0, &statement, &_46$$31);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_45$$31 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 319)) {
				zephir_concat_self_str(&compilation, SL("<?php continue; ?>") TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 320)) {
				zephir_concat_self_str(&compilation, SL("<?php break; ?>") TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 321)) {
				ZEPHIR_CALL_METHOD(&_48$$34, this_ptr, "compileforelse", &_49, 0);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_48$$34 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 322)) {
				if (extendsMode) {
					ZVAL_BOOL(&_51$$35, 1);
				} else {
					ZVAL_BOOL(&_51$$35, 0);
				}
				ZEPHIR_CALL_METHOD(&_50$$35, this_ptr, "compilemacro", &_52, 0, &statement, &_51$$35);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_50$$35 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 325)) {
				if (extendsMode) {
					ZVAL_BOOL(&_54$$36, 1);
				} else {
					ZVAL_BOOL(&_54$$36, 0);
				}
				ZEPHIR_CALL_METHOD(&_53$$36, this_ptr, "compilecall", &_55, 0, &statement, &_54$$36);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_53$$36 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 358)) {
				break;
			}
			ZEPHIR_INIT_NVAR(&_56$$38);
			object_init_ex(&_56$$38, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_57$$38, &statement, SL("file"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 2292 TSRMLS_CC);
			zephir_array_fetch_string(&_58$$38, &statement, SL("line"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/volt/compiler.zep", 2292 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_59$$38);
			ZEPHIR_CONCAT_SVSVSV(&_59$$38, "Unknown statement ", &type, " in ", &_57$$38, " on line ", &_58$$38);
			ZEPHIR_CALL_METHOD(NULL, &_56$$38, "__construct", &_6, 391, &_59$$38);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_56$$38, "phalcon/mvc/view/engine/volt/compiler.zep", 2292 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&statement);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&blockMode)) {
		zephir_read_property(&level, this_ptr, SL("_blockLevel"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_LONG(&level, 1)) {
			if (Z_TYPE_P(&compilation) != IS_NULL) {
				zephir_update_property_array_append(this_ptr, SL("_blocks"), &compilation TSRMLS_CC);
			}
		}
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_blockLevel") TSRMLS_CC));
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_level") TSRMLS_CC));
	RETURN_CCTOR(&compilation);

}

/**
 * Compiles a Volt source code returning a PHP plain version
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _compileSource) {

	zend_string *_3$$7;
	zend_ulong _2$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *viewCode_param = NULL, *extendsMode_param = NULL, currentPath, intermediate, extended, finalCompilation, blocks, extendedBlocks, name, block, blockCompilation, localBlock, compilation, options, autoescape, _0, *_1$$7;
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewCode_param, &extendsMode_param);

	if (UNEXPECTED(Z_TYPE_P(viewCode_param) != IS_STRING && Z_TYPE_P(viewCode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewCode' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewCode_param) == IS_STRING)) {
		zephir_get_strval(&viewCode, viewCode_param);
	} else {
		ZEPHIR_INIT_VAR(&viewCode);
		ZVAL_EMPTY_STRING(&viewCode);
	}
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	ZEPHIR_OBS_VAR(&currentPath);
	zephir_read_property(&currentPath, this_ptr, SL("_currentPath"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&autoescape);
		if (zephir_array_isset_string_fetch(&autoescape, &options, SL("autoescape"), 0)) {
			if (((Z_TYPE_P(&autoescape) == IS_TRUE || Z_TYPE_P(&autoescape) == IS_FALSE) != 1)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'autoescape' must be bool", "phalcon/mvc/view/engine/volt/compiler.zep", 2337);
				return;
			}
			zephir_update_property_zval(this_ptr, SL("_autoescape"), &autoescape);
		}
	}
	ZEPHIR_INIT_VAR(&intermediate);
	ZEPHIR_LAST_CALL_STATUS = phvolt_parse_view(&intermediate, &viewCode, &currentPath TSRMLS_CC);
	zephir_check_call_status();
	if (Z_TYPE_P(&intermediate) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Invalid intermediate representation", "phalcon/mvc/view/engine/volt/compiler.zep", 2349);
		return;
	}
	if (extendsMode) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_CALL_METHOD(&compilation, this_ptr, "_statementlist", NULL, 395, &intermediate, &_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&extended);
	zephir_read_property(&extended, this_ptr, SL("_extended"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&extended)) {
		ZEPHIR_INIT_VAR(&finalCompilation);
		if (extendsMode == 1) {
			array_init(&finalCompilation);
		} else {
			ZVAL_NULL(&finalCompilation);
		}
		ZEPHIR_OBS_VAR(&blocks);
		zephir_read_property(&blocks, this_ptr, SL("_blocks"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&extendedBlocks);
		zephir_read_property(&extendedBlocks, this_ptr, SL("_extendedBlocks"), PH_NOISY_CC);
		zephir_is_iterable(&extendedBlocks, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 2415);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&extendedBlocks), _2$$7, _3$$7, _1$$7)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3$$7 != NULL) { 
				ZVAL_STR_COPY(&name, _3$$7);
			} else {
				ZVAL_LONG(&name, _2$$7);
			}
			ZEPHIR_INIT_NVAR(&block);
			ZVAL_COPY(&block, _1$$7);
			if (Z_TYPE_P(&name) == IS_STRING) {
				if (zephir_array_isset(&blocks, &name)) {
					ZEPHIR_OBS_NVAR(&localBlock);
					zephir_array_fetch(&localBlock, &blocks, &name, PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2383 TSRMLS_CC);
					zephir_update_property_zval(this_ptr, SL("_currentBlock"), &name);
					ZEPHIR_CALL_METHOD(&blockCompilation, this_ptr, "_statementlist", NULL, 395, &localBlock);
					zephir_check_call_status();
				} else {
					if (Z_TYPE_P(&block) == IS_ARRAY) {
						ZEPHIR_CALL_METHOD(&blockCompilation, this_ptr, "_statementlist", NULL, 395, &block);
						zephir_check_call_status();
					} else {
						ZEPHIR_CPY_WRT(&blockCompilation, &block);
					}
				}
				if (extendsMode == 1) {
					zephir_array_update_zval(&finalCompilation, &name, &blockCompilation, PH_COPY | PH_SEPARATE);
				} else {
					zephir_concat_self(&finalCompilation, &blockCompilation TSRMLS_CC);
				}
			} else {
				if (extendsMode == 1) {
					zephir_array_append(&finalCompilation, &block, PH_SEPARATE, "phalcon/mvc/view/engine/volt/compiler.zep", 2408);
				} else {
					zephir_concat_self(&finalCompilation, &block TSRMLS_CC);
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&block);
		ZEPHIR_INIT_NVAR(&name);
		RETURN_CCTOR(&finalCompilation);
	}
	if (extendsMode == 1) {
		RETURN_MM_MEMBER(getThis(), "_blocks");
	}
	RETURN_CCTOR(&compilation);

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
	zval *viewCode_param = NULL, *extendsMode_param = NULL, _0, _1;
	zval viewCode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewCode);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewCode_param, &extendsMode_param);

	if (UNEXPECTED(Z_TYPE_P(viewCode_param) != IS_STRING && Z_TYPE_P(viewCode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewCode' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewCode_param) == IS_STRING)) {
		zephir_get_strval(&viewCode, viewCode_param);
	} else {
		ZEPHIR_INIT_VAR(&viewCode);
		ZVAL_EMPTY_STRING(&viewCode);
	}
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "eval code");
	zephir_update_property_zval(this_ptr, SL("_currentPath"), &_0);
	if (extendsMode) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_compilesource", NULL, 0, &viewCode, &_1);
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
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileFile) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &path_param, &compiledPath_param, &extendsMode_param);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}
	if (UNEXPECTED(Z_TYPE_P(compiledPath_param) != IS_STRING && Z_TYPE_P(compiledPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'compiledPath' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(compiledPath_param) == IS_STRING)) {
		zephir_get_strval(&compiledPath, compiledPath_param);
	} else {
		ZEPHIR_INIT_VAR(&compiledPath);
		ZVAL_EMPTY_STRING(&compiledPath);
	}
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	if (ZEPHIR_IS_EQUAL(&path, &compiledPath)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Template path and compilation template path cannot be the same", "phalcon/mvc/view/engine/volt/compiler.zep", 2454);
		return;
	}
	if (!((zephir_file_exists(&path TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(&_0$$4);
		object_init_ex(&_0$$4, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_SVS(&_1$$4, "Template file ", &path, " does not exist");
		ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 391, &_1$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$4, "phalcon/mvc/view/engine/volt/compiler.zep", 2461 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&viewCode);
	zephir_file_get_contents(&viewCode, &path TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&viewCode)) {
		ZEPHIR_INIT_VAR(&_2$$5);
		object_init_ex(&_2$$5, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$5);
		ZEPHIR_CONCAT_SVS(&_3$$5, "Template file ", &path, " could not be opened");
		ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 391, &_3$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$5, "phalcon/mvc/view/engine/volt/compiler.zep", 2469 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_currentPath"), &path);
	if (extendsMode) {
		ZVAL_BOOL(&_4, 1);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	ZEPHIR_CALL_METHOD(&compilation, this_ptr, "_compilesource", NULL, 0, &viewCode, &_4);
	zephir_check_call_status();
	if (Z_TYPE_P(&compilation) == IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&finalCompilation, "serialize", NULL, 52, &compilation);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&finalCompilation, &compilation);
	}
	ZEPHIR_INIT_VAR(&_5);
	zephir_file_put_contents(&_5, &compiledPath, &finalCompilation TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_5)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Volt directory can't be written", "phalcon/mvc/view/engine/volt/compiler.zep", 2489);
		return;
	}
	RETURN_CCTOR(&compilation);

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

	zval _22$$31;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode, _1$$3, _6$$3, _11$$3, _16$$3;
	zval *templatePath_param = NULL, *extendsMode_param = NULL, __$true, __$false, __$null, blocksCode, compilation, compileAlways, compiledExtension, compiledPath, compiledSeparator, compiledTemplatePath, optionKey, options, prefix, realCompiledPath, stat, templateSepPath, _0, _2$$6, _3$$6, _4$$7, _5$$7, _7$$12, _8$$12, _9$$14, _10$$14, _12$$17, _13$$17, _14$$18, _15$$18, _17$$21, _18$$21, _19$$22, _20$$22, _21$$25, _23$$31, _24$$34, _25$$37, _26$$38, _27$$41, _28$$41, _29$$44, _30$$46;
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
	ZVAL_UNDEF(&optionKey);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&realCompiledPath);
	ZVAL_UNDEF(&stat);
	ZVAL_UNDEF(&templateSepPath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&_12$$17);
	ZVAL_UNDEF(&_13$$17);
	ZVAL_UNDEF(&_14$$18);
	ZVAL_UNDEF(&_15$$18);
	ZVAL_UNDEF(&_17$$21);
	ZVAL_UNDEF(&_18$$21);
	ZVAL_UNDEF(&_19$$22);
	ZVAL_UNDEF(&_20$$22);
	ZVAL_UNDEF(&_21$$25);
	ZVAL_UNDEF(&_23$$31);
	ZVAL_UNDEF(&_24$$34);
	ZVAL_UNDEF(&_25$$37);
	ZVAL_UNDEF(&_26$$38);
	ZVAL_UNDEF(&_27$$41);
	ZVAL_UNDEF(&_28$$41);
	ZVAL_UNDEF(&_29$$44);
	ZVAL_UNDEF(&_30$$46);
	ZVAL_UNDEF(&_22$$31);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &templatePath_param, &extendsMode_param);

	if (UNEXPECTED(Z_TYPE_P(templatePath_param) != IS_STRING && Z_TYPE_P(templatePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'templatePath' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(templatePath_param) == IS_STRING)) {
		zephir_get_strval(&templatePath, templatePath_param);
	} else {
		ZEPHIR_INIT_VAR(&templatePath);
		ZVAL_EMPTY_STRING(&templatePath);
	}
	if (!extendsMode_param) {
		extendsMode = 0;
	} else {
		extendsMode = zephir_get_boolval(extendsMode_param);
	}


	if (0) {
		zephir_update_property_zval(this_ptr, SL("_extended"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_extended"), &__$false);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("_extendedBlocks"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_extendedBlocks"), &__$false);
	}
	zephir_update_property_zval(this_ptr, SL("_blocks"), &__$null);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("_level"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("_foreachLevel"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("_blockLevel"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("_exprLevel"), &_0);
	ZEPHIR_INIT_VAR(&stat);
	ZVAL_BOOL(&stat, 1);
	ZEPHIR_INIT_VAR(&compileAlways);
	ZVAL_BOOL(&compileAlways, 0);
	ZEPHIR_INIT_VAR(&compiledPath);
	ZVAL_STRING(&compiledPath, "");
	ZEPHIR_INIT_VAR(&prefix);
	ZVAL_NULL(&prefix);
	ZEPHIR_INIT_VAR(&compiledSeparator);
	ZVAL_STRING(&compiledSeparator, "%%");
	ZEPHIR_INIT_VAR(&compiledExtension);
	ZVAL_STRING(&compiledExtension, ".php");
	ZEPHIR_INIT_VAR(&compilation);
	ZVAL_NULL(&compilation);
	ZEPHIR_OBS_VAR(&options);
	zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		_1$$3 = zephir_array_isset_string(&options, SL("always"));
		if (!(_1$$3)) {
			_1$$3 = zephir_array_isset_string(&options, SL("compileAlways"));
		}
		if (_1$$3) {
			ZEPHIR_INIT_VAR(&optionKey);
			if (zephir_array_isset_string(&options, SL("always"))) {
				ZVAL_STRING(&optionKey, "always");
			} else {
				ZVAL_STRING(&optionKey, "compileAlways");
				ZEPHIR_INIT_VAR(&_2$$6);
				ZVAL_STRING(&_2$$6, "The 'compileAlways' option is deprecated. Use 'always' instead.");
				ZVAL_LONG(&_3$$6, 16384);
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 1, &_2$$6, &_3$$6);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(&compileAlways);
			zephir_array_fetch(&compileAlways, &options, &optionKey, PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2543 TSRMLS_CC);
			if (((Z_TYPE_P(&compileAlways) == IS_TRUE || Z_TYPE_P(&compileAlways) == IS_FALSE) != 1)) {
				ZEPHIR_INIT_VAR(&_4$$7);
				object_init_ex(&_4$$7, phalcon_mvc_view_engine_volt_exception_ce);
				ZEPHIR_INIT_VAR(&_5$$7);
				ZEPHIR_CONCAT_SVS(&_5$$7, "'", &optionKey, "' must be a bool value");
				ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", NULL, 391, &_5$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_4$$7, "phalcon/mvc/view/engine/volt/compiler.zep", 2545 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (zephir_array_isset_string(&options, SL("prefix"))) {
			ZEPHIR_OBS_NVAR(&prefix);
			zephir_array_fetch_string(&prefix, &options, SL("prefix"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2553 TSRMLS_CC);
			if (Z_TYPE_P(&prefix) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'prefix' must be a string", "phalcon/mvc/view/engine/volt/compiler.zep", 2555);
				return;
			}
		}
		_6$$3 = zephir_array_isset_string(&options, SL("path"));
		if (!(_6$$3)) {
			_6$$3 = zephir_array_isset_string(&options, SL("compiledPath"));
		}
		if (_6$$3) {
			ZEPHIR_INIT_NVAR(&optionKey);
			if (zephir_array_isset_string(&options, SL("path"))) {
				ZVAL_STRING(&optionKey, "path");
			} else {
				ZVAL_STRING(&optionKey, "compiledPath");
				ZEPHIR_INIT_VAR(&_7$$12);
				ZVAL_STRING(&_7$$12, "The 'compiledPath' option is deprecated. Use 'path' instead.");
				ZVAL_LONG(&_8$$12, 16384);
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 1, &_7$$12, &_8$$12);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(&compiledPath);
			zephir_array_fetch(&compiledPath, &options, &optionKey, PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2569 TSRMLS_CC);
			if (Z_TYPE_P(&compiledPath) != IS_STRING) {
				if (Z_TYPE_P(&compiledPath) != IS_OBJECT) {
					ZEPHIR_INIT_VAR(&_9$$14);
					object_init_ex(&_9$$14, phalcon_mvc_view_engine_volt_exception_ce);
					ZEPHIR_INIT_VAR(&_10$$14);
					ZEPHIR_CONCAT_SVS(&_10$$14, "'", &optionKey, "' must be a string or a closure");
					ZEPHIR_CALL_METHOD(NULL, &_9$$14, "__construct", NULL, 391, &_10$$14);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_9$$14, "phalcon/mvc/view/engine/volt/compiler.zep", 2572 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		_11$$3 = zephir_array_isset_string(&options, SL("separator"));
		if (!(_11$$3)) {
			_11$$3 = zephir_array_isset_string(&options, SL("compiledSeparator"));
		}
		if (_11$$3) {
			ZEPHIR_INIT_NVAR(&optionKey);
			if (zephir_array_isset_string(&options, SL("separator"))) {
				ZVAL_STRING(&optionKey, "separator");
			} else {
				ZVAL_STRING(&optionKey, "compiledSeparator");
				ZEPHIR_INIT_VAR(&_12$$17);
				ZVAL_STRING(&_12$$17, "The 'compiledSeparator' option is deprecated. Use 'separator' instead.");
				ZVAL_LONG(&_13$$17, 16384);
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 1, &_12$$17, &_13$$17);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(&compiledPath);
			zephir_array_fetch(&compiledPath, &options, &optionKey, PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2587 TSRMLS_CC);
			if (Z_TYPE_P(&compiledSeparator) != IS_STRING) {
				ZEPHIR_INIT_VAR(&_14$$18);
				object_init_ex(&_14$$18, phalcon_mvc_view_engine_volt_exception_ce);
				ZEPHIR_INIT_VAR(&_15$$18);
				ZEPHIR_CONCAT_SVS(&_15$$18, "'", &optionKey, "' must be a string");
				ZEPHIR_CALL_METHOD(NULL, &_14$$18, "__construct", NULL, 391, &_15$$18);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_14$$18, "phalcon/mvc/view/engine/volt/compiler.zep", 2589 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		_16$$3 = zephir_array_isset_string(&options, SL("extension"));
		if (!(_16$$3)) {
			_16$$3 = zephir_array_isset_string(&options, SL("compiledExtension"));
		}
		if (_16$$3) {
			ZEPHIR_INIT_NVAR(&optionKey);
			if (zephir_array_isset_string(&options, SL("extension"))) {
				ZVAL_STRING(&optionKey, "extension");
			} else {
				ZVAL_STRING(&optionKey, "compiledExtension");
				ZEPHIR_INIT_VAR(&_17$$21);
				ZVAL_STRING(&_17$$21, "The 'compiledExtension' option is deprecated. Use 'extension' instead.");
				ZVAL_LONG(&_18$$21, 16384);
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 1, &_17$$21, &_18$$21);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(&compiledPath);
			zephir_array_fetch(&compiledPath, &options, &optionKey, PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2603 TSRMLS_CC);
			if (Z_TYPE_P(&compiledExtension) != IS_STRING) {
				ZEPHIR_INIT_VAR(&_19$$22);
				object_init_ex(&_19$$22, phalcon_mvc_view_engine_volt_exception_ce);
				ZEPHIR_INIT_VAR(&_20$$22);
				ZEPHIR_CONCAT_SVS(&_20$$22, "'", &optionKey, "' must be a string");
				ZEPHIR_CALL_METHOD(NULL, &_19$$22, "__construct", NULL, 391, &_20$$22);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_19$$22, "phalcon/mvc/view/engine/volt/compiler.zep", 2605 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (zephir_array_isset_string(&options, SL("stat"))) {
			ZEPHIR_OBS_NVAR(&stat);
			zephir_array_fetch_string(&stat, &options, SL("stat"), PH_NOISY, "phalcon/mvc/view/engine/volt/compiler.zep", 2613 TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(&compiledPath) == IS_STRING) {
		if (!(ZEPHIR_IS_EMPTY(&compiledPath))) {
			ZEPHIR_CALL_FUNCTION(&_21$$25, "realpath", NULL, 51, &templatePath);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&templateSepPath);
			zephir_prepare_virtual_path(&templateSepPath, &_21$$25, &compiledSeparator TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(&templateSepPath, &templatePath);
		}
		ZEPHIR_INIT_VAR(&compiledTemplatePath);
		if (extendsMode == 1) {
			ZEPHIR_CONCAT_VVVVSVV(&compiledTemplatePath, &compiledPath, &prefix, &templateSepPath, &compiledSeparator, "e", &compiledSeparator, &compiledExtension);
		} else {
			ZEPHIR_CONCAT_VVVV(&compiledTemplatePath, &compiledPath, &prefix, &templateSepPath, &compiledExtension);
		}
	} else {
		if (Z_TYPE_P(&compiledPath) == IS_OBJECT) {
			if (zephir_instance_of_ev(&compiledPath, zend_ce_closure TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(&_22$$31);
				zephir_create_array(&_22$$31, 3, 0 TSRMLS_CC);
				zephir_array_fast_append(&_22$$31, &templatePath);
				zephir_array_fast_append(&_22$$31, &options);
				ZEPHIR_INIT_VAR(&_23$$31);
				ZVAL_BOOL(&_23$$31, extendsMode);
				zephir_array_fast_append(&_22$$31, &_23$$31);
				ZEPHIR_INIT_NVAR(&compiledTemplatePath);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&compiledTemplatePath, &compiledPath, &_22$$31);
				zephir_check_call_status();
				if (Z_TYPE_P(&compiledTemplatePath) != IS_STRING) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "compiledPath closure didn't return a valid string", "phalcon/mvc/view/engine/volt/compiler.zep", 2658);
					return;
				}
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "compiledPath must be a string or a closure", "phalcon/mvc/view/engine/volt/compiler.zep", 2661);
				return;
			}
		}
	}
	ZEPHIR_CPY_WRT(&realCompiledPath, &compiledTemplatePath);
	if (zephir_is_true(&compileAlways)) {
		if (extendsMode) {
			ZVAL_BOOL(&_24$$34, 1);
		} else {
			ZVAL_BOOL(&_24$$34, 0);
		}
		ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilefile", NULL, 0, &templatePath, &realCompiledPath, &_24$$34);
		zephir_check_call_status();
	} else {
		if (ZEPHIR_IS_TRUE_IDENTICAL(&stat)) {
			if ((zephir_file_exists(&compiledTemplatePath TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_INIT_VAR(&_25$$37);
				if (zephir_compare_mtime(&templatePath, &realCompiledPath TSRMLS_CC)) {
					if (extendsMode) {
						ZVAL_BOOL(&_26$$38, 1);
					} else {
						ZVAL_BOOL(&_26$$38, 0);
					}
					ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilefile", NULL, 0, &templatePath, &realCompiledPath, &_26$$38);
					zephir_check_call_status();
				} else {
					if (extendsMode == 1) {
						ZEPHIR_INIT_VAR(&blocksCode);
						zephir_file_get_contents(&blocksCode, &realCompiledPath TSRMLS_CC);
						if (ZEPHIR_IS_FALSE_IDENTICAL(&blocksCode)) {
							ZEPHIR_INIT_VAR(&_27$$41);
							object_init_ex(&_27$$41, phalcon_mvc_view_engine_volt_exception_ce);
							ZEPHIR_INIT_VAR(&_28$$41);
							ZEPHIR_CONCAT_SVS(&_28$$41, "Extends compilation file ", &realCompiledPath, " could not be opened");
							ZEPHIR_CALL_METHOD(NULL, &_27$$41, "__construct", NULL, 391, &_28$$41);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_27$$41, "phalcon/mvc/view/engine/volt/compiler.zep", 2695 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (zephir_is_true(&blocksCode)) {
							ZEPHIR_CALL_FUNCTION(&compilation, "unserialize", NULL, 53, &blocksCode);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(&compilation);
							array_init(&compilation);
						}
					}
				}
			} else {
				if (extendsMode) {
					ZVAL_BOOL(&_29$$44, 1);
				} else {
					ZVAL_BOOL(&_29$$44, 0);
				}
				ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilefile", NULL, 0, &templatePath, &realCompiledPath, &_29$$44);
				zephir_check_call_status();
			}
		} else {
			if (!((zephir_file_exists(&realCompiledPath TSRMLS_CC) == SUCCESS))) {
				if (extendsMode) {
					ZVAL_BOOL(&_30$$46, 1);
				} else {
					ZVAL_BOOL(&_30$$46, 0);
				}
				ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilefile", NULL, 0, &templatePath, &realCompiledPath, &_30$$46);
				zephir_check_call_status();
			}
		}
	}
	zephir_update_property_zval(this_ptr, SL("_compiledTemplatePath"), &realCompiledPath);
	RETURN_CCTOR(&compilation);

}

/**
 * Returns the path that is currently being compiled
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getTemplatePath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_currentPath");

}

/**
 * Returns the path to the last compiled template
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath) {

	zval *this_ptr = getThis();


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
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, parse) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *viewCode_param = NULL, currentPath;
	zval viewCode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewCode);
	ZVAL_UNDEF(&currentPath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &viewCode_param);

	if (UNEXPECTED(Z_TYPE_P(viewCode_param) != IS_STRING && Z_TYPE_P(viewCode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewCode' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewCode_param) == IS_STRING)) {
		zephir_get_strval(&viewCode, viewCode_param);
	} else {
		ZEPHIR_INIT_VAR(&viewCode);
		ZVAL_EMPTY_STRING(&viewCode);
	}


	ZEPHIR_INIT_VAR(&currentPath);
	ZVAL_STRING(&currentPath, "eval code");
	ZEPHIR_LAST_CALL_STATUS = phvolt_parse_view(return_value, &viewCode, &currentPath TSRMLS_CC);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets the final path with VIEW
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFinalPath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, view, viewsDirs, viewsDir, *_0$$4, _1$$5;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&view);
	ZVAL_UNDEF(&viewsDirs);
	ZVAL_UNDEF(&viewsDir);
	ZVAL_UNDEF(&_1$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	ZEPHIR_OBS_VAR(&view);
	zephir_read_property(&view, this_ptr, SL("_view"), PH_NOISY_CC);
	if (Z_TYPE_P(&view) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&viewsDirs, &view, "getviewsdir", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&viewsDirs) == IS_ARRAY) {
			zephir_is_iterable(&viewsDirs, 0, "phalcon/mvc/view/engine/volt/compiler.zep", 2787);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&viewsDirs), _0$$4)
			{
				ZEPHIR_INIT_NVAR(&viewsDir);
				ZVAL_COPY(&viewsDir, _0$$4);
				ZEPHIR_INIT_LNVAR(_1$$5);
				ZEPHIR_CONCAT_VV(&_1$$5, &viewsDir, &path);
				if ((zephir_file_exists(&_1$$5 TSRMLS_CC) == SUCCESS)) {
					ZEPHIR_CONCAT_VV(return_value, &viewsDir, &path);
					RETURN_MM();
				}
			} ZEND_HASH_FOREACH_END();
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

