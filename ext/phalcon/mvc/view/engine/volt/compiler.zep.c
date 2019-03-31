
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
#include "kernel/file.h"
#include "Zend/zend_closures.h"
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

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("arrayHelpers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_view_engine_volt_compiler_ce, SL("autoescape"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_view_engine_volt_compiler_ce, SL("blockLevel"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("blocks"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("compiledTemplatePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("currentBlock"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("currentPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_view_engine_volt_compiler_ce, SL("exprLevel"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_view_engine_volt_compiler_ce, SL("extended"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("extensions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("extendedBlocks"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_view_engine_volt_compiler_ce, SL("foreachLevel"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("forElsePointers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("functions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_view_engine_volt_compiler_ce, SL("level"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("loopPointers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("macros"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("view"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
		zephir_update_property_zval(this_ptr, SL("view"), view);
	}

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "The extension is not valid", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 73);
		return;
	}
	if ((zephir_method_exists_ex(extension, SL("initialize") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, extension, "initialize", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	zephir_update_property_array_append(this_ptr, SL("extensions"), extension TSRMLS_CC);
	RETURN_THIS();

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


	zephir_update_property_array(this_ptr, SL("filters"), &name, definition TSRMLS_CC);
	RETURN_THIS();

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


	zephir_update_property_array(this_ptr, SL("functions"), &name, definition TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Resolves attribute reading
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, attributeReader) {

	zend_bool _4$$5, _8$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, exprCode, left, leftType, variable, level, container, leftCode, right, _0, _9, _1$$4, _2$$4, _3$$5, _5$$5, _6$$6, _7$$7, _10$$11, _11$$12;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&exprCode);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&leftType);
	ZVAL_UNDEF(&variable);
	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&leftCode);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);


	ZEPHIR_INIT_VAR(&exprCode);
	ZVAL_NULL(&exprCode);
	ZEPHIR_OBS_VAR(&left);
	zephir_array_fetch_string(&left, &expr, SL("left"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 115 TSRMLS_CC);
	zephir_array_fetch_string(&_0, &left, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 117 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(&_0, 265)) {
		ZEPHIR_OBS_VAR(&variable);
		zephir_array_fetch_string(&variable, &left, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 119 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&variable, "loop")) {
			ZEPHIR_OBS_VAR(&level);
			zephir_read_property(&level, this_ptr, SL("foreachLevel"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "getuniqueprefix", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_CONCAT_SVVS(&_2$$4, "$", &_1$$4, &level, "loop");
			zephir_concat_self(&exprCode, &_2$$4 TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("loopPointers"), &level, &level TSRMLS_CC);
		} else {
			zephir_read_property(&_3$$5, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&container, &_3$$5);
			_4$$5 = Z_TYPE_P(&container) == IS_OBJECT;
			if (_4$$5) {
				ZEPHIR_CALL_METHOD(&_5$$5, &container, "has", NULL, 0, &variable);
				zephir_check_call_status();
				_4$$5 = zephir_is_true(&_5$$5);
			}
			if (_4$$5) {
				ZEPHIR_INIT_VAR(&_6$$6);
				ZEPHIR_CONCAT_SV(&_6$$6, "$this->", &variable);
				zephir_concat_self(&exprCode, &_6$$6 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(&_7$$7);
				ZEPHIR_CONCAT_SV(&_7$$7, "$", &variable);
				zephir_concat_self(&exprCode, &_7$$7 TSRMLS_CC);
			}
		}
	} else {
		ZEPHIR_CALL_METHOD(&leftCode, this_ptr, "expression", NULL, 449, &left);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&leftType);
		zephir_array_fetch_string(&leftType, &left, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 142 TSRMLS_CC);
		_8$$8 = !ZEPHIR_IS_LONG(&leftType, '.');
		if (_8$$8) {
			_8$$8 = !ZEPHIR_IS_LONG(&leftType, 350);
		}
		if (_8$$8) {
			zephir_concat_self(&exprCode, &leftCode TSRMLS_CC);
		} else {
			zephir_concat_self(&exprCode, &leftCode TSRMLS_CC);
		}
	}
	zephir_concat_self_str(&exprCode, SL("->") TSRMLS_CC);
	ZEPHIR_OBS_VAR(&right);
	zephir_array_fetch_string(&right, &expr, SL("right"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 152 TSRMLS_CC);
	zephir_array_fetch_string(&_9, &right, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 154 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(&_9, 265)) {
		zephir_array_fetch_string(&_10$$11, &right, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 155 TSRMLS_CC);
		zephir_concat_self(&exprCode, &_10$$11 TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&_11$$12, this_ptr, "expression", NULL, 449, &right);
		zephir_check_call_status();
		zephir_concat_self(&exprCode, &_11$$12 TSRMLS_CC);
	}
	RETURN_CCTOR(&exprCode);

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
		zephir_update_property_zval(this_ptr, SL("extended"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("extended"), &__$false);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("extendedBlocks"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("extendedBlocks"), &__$false);
	}
	zephir_update_property_zval(this_ptr, SL("blocks"), &__$null);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("level"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("foreachLevel"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("blockLevel"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("exprLevel"), &_0);
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
	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
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
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 2, &_2$$6, &_3$$6);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(&compileAlways);
			zephir_array_fetch(&compileAlways, &options, &optionKey, PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 211 TSRMLS_CC);
			if (((Z_TYPE_P(&compileAlways) == IS_TRUE || Z_TYPE_P(&compileAlways) == IS_FALSE) != 1)) {
				ZEPHIR_INIT_VAR(&_4$$7);
				object_init_ex(&_4$$7, phalcon_mvc_view_engine_volt_exception_ce);
				ZEPHIR_INIT_VAR(&_5$$7);
				ZEPHIR_CONCAT_SVS(&_5$$7, "'", &optionKey, "' must be a bool value");
				ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", NULL, 450, &_5$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_4$$7, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 213 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (zephir_array_isset_string(&options, SL("prefix"))) {
			ZEPHIR_OBS_NVAR(&prefix);
			zephir_array_fetch_string(&prefix, &options, SL("prefix"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 221 TSRMLS_CC);
			if (Z_TYPE_P(&prefix) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'prefix' must be a string", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 223);
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
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 2, &_7$$12, &_8$$12);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(&compiledPath);
			zephir_array_fetch(&compiledPath, &options, &optionKey, PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 237 TSRMLS_CC);
			if (Z_TYPE_P(&compiledPath) != IS_STRING) {
				if (Z_TYPE_P(&compiledPath) != IS_OBJECT) {
					ZEPHIR_INIT_VAR(&_9$$14);
					object_init_ex(&_9$$14, phalcon_mvc_view_engine_volt_exception_ce);
					ZEPHIR_INIT_VAR(&_10$$14);
					ZEPHIR_CONCAT_SVS(&_10$$14, "'", &optionKey, "' must be a string or a closure");
					ZEPHIR_CALL_METHOD(NULL, &_9$$14, "__construct", NULL, 450, &_10$$14);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_9$$14, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 240 TSRMLS_CC);
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
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 2, &_12$$17, &_13$$17);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(&compiledPath);
			zephir_array_fetch(&compiledPath, &options, &optionKey, PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 255 TSRMLS_CC);
			if (Z_TYPE_P(&compiledSeparator) != IS_STRING) {
				ZEPHIR_INIT_VAR(&_14$$18);
				object_init_ex(&_14$$18, phalcon_mvc_view_engine_volt_exception_ce);
				ZEPHIR_INIT_VAR(&_15$$18);
				ZEPHIR_CONCAT_SVS(&_15$$18, "'", &optionKey, "' must be a string");
				ZEPHIR_CALL_METHOD(NULL, &_14$$18, "__construct", NULL, 450, &_15$$18);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_14$$18, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 257 TSRMLS_CC);
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
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 2, &_17$$21, &_18$$21);
				zephir_check_call_status();
			}
			ZEPHIR_OBS_NVAR(&compiledPath);
			zephir_array_fetch(&compiledPath, &options, &optionKey, PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 271 TSRMLS_CC);
			if (Z_TYPE_P(&compiledExtension) != IS_STRING) {
				ZEPHIR_INIT_VAR(&_19$$22);
				object_init_ex(&_19$$22, phalcon_mvc_view_engine_volt_exception_ce);
				ZEPHIR_INIT_VAR(&_20$$22);
				ZEPHIR_CONCAT_SVS(&_20$$22, "'", &optionKey, "' must be a string");
				ZEPHIR_CALL_METHOD(NULL, &_19$$22, "__construct", NULL, 450, &_20$$22);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_19$$22, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 273 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (zephir_array_isset_string(&options, SL("stat"))) {
			ZEPHIR_OBS_NVAR(&stat);
			zephir_array_fetch_string(&stat, &options, SL("stat"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 281 TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(&compiledPath) == IS_STRING) {
		if (!(ZEPHIR_IS_EMPTY(&compiledPath))) {
			ZEPHIR_CALL_FUNCTION(&_21$$25, "realpath", NULL, 64, &templatePath);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&templateSepPath);
			zephir_prepare_virtual_path(&templateSepPath, &_21$$25, &compiledSeparator TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(&templateSepPath, &templatePath);
		}
		ZEPHIR_INIT_VAR(&compiledTemplatePath);
		if (extendsMode) {
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
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "compiledPath closure didn't return a valid string", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 326);
					return;
				}
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "compiledPath must be a string or a closure", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 329);
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
					if (extendsMode) {
						ZEPHIR_INIT_VAR(&blocksCode);
						zephir_file_get_contents(&blocksCode, &realCompiledPath TSRMLS_CC);
						if (ZEPHIR_IS_FALSE_IDENTICAL(&blocksCode)) {
							ZEPHIR_INIT_VAR(&_27$$41);
							object_init_ex(&_27$$41, phalcon_mvc_view_engine_volt_exception_ce);
							ZEPHIR_INIT_VAR(&_28$$41);
							ZEPHIR_CONCAT_SVS(&_28$$41, "Extends compilation file ", &realCompiledPath, " could not be opened");
							ZEPHIR_CALL_METHOD(NULL, &_27$$41, "__construct", NULL, 450, &_28$$41);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_27$$41, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 363 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (zephir_is_true(&blocksCode)) {
							ZEPHIR_CALL_FUNCTION(&compilation, "unserialize", NULL, 67, &blocksCode);
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
	zephir_update_property_zval(this_ptr, SL("compiledTemplatePath"), &realCompiledPath);
	RETURN_CCTOR(&compilation);

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 414);
		return;
	}
	ZEPHIR_OBS_VAR(&oldAutoescape);
	zephir_read_property(&oldAutoescape, this_ptr, SL("autoescape"), PH_NOISY_CC);
	zephir_update_property_zval(this_ptr, SL("autoescape"), &autoescape);
	zephir_array_fetch_string(&_0, &statement, SL("block_statements"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 423 TSRMLS_CC);
	if (extendsMode) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(&compilation, this_ptr, "statementlist", NULL, 451, &_0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("autoescape"), &oldAutoescape);
	RETURN_CCTOR(&compilation);

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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 450, &_1$$3, &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 440 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", NULL, 449, &expr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 449, &expr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&compilation);
	ZEPHIR_CONCAT_SVS(&compilation, "<?php $_cache[", &_2, "] = $this->di->get('viewCache'); ");
	ZEPHIR_OBS_VAR(&lifetime);
	if (zephir_array_isset_string_fetch(&lifetime, &statement, SL("lifetime"), 0)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_SVS(&_3$$4, "$_cacheKey[", &exprCode, "]");
		zephir_concat_self(&compilation, &_3$$4 TSRMLS_CC);
		zephir_array_fetch_string(&_4$$4, &lifetime, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 450 TSRMLS_CC);
		if (ZEPHIR_IS_LONG(&_4$$4, 265)) {
			zephir_array_fetch_string(&_5$$5, &lifetime, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 451 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_6$$5);
			ZEPHIR_CONCAT_SVSVSVS(&_6$$5, " = $_cache[", &exprCode, "]->start(", &exprCode, ", $", &_5$$5, "); ");
			zephir_concat_self(&compilation, &_6$$5 TSRMLS_CC);
		} else {
			zephir_array_fetch_string(&_7$$6, &lifetime, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 453 TSRMLS_CC);
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
	zephir_array_fetch_string(&_12, &statement, SL("block_statements"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 463 TSRMLS_CC);
	if (extendsMode) {
		ZVAL_BOOL(&_13, 1);
	} else {
		ZVAL_BOOL(&_13, 0);
	}
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "statementlist", NULL, 451, &_12, &_13);
	zephir_check_call_status();
	zephir_concat_self(&compilation, &_11 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(&lifetime);
	if (zephir_array_isset_string_fetch(&lifetime, &statement, SL("lifetime"), 0)) {
		zephir_array_fetch_string(&_14$$8, &lifetime, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 469 TSRMLS_CC);
		if (ZEPHIR_IS_LONG(&_14$$8, 265)) {
			zephir_array_fetch_string(&_15$$9, &lifetime, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 470 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_16$$9);
			ZEPHIR_CONCAT_SVSVSVS(&_16$$9, "<?php $_cache[", &exprCode, "]->save(", &exprCode, ", null, $", &_15$$9, "); ");
			zephir_concat_self(&compilation, &_16$$9 TSRMLS_CC);
		} else {
			zephir_array_fetch_string(&_17$$10, &lifetime, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 472 TSRMLS_CC);
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
		ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 450, &_1$$4, &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$4, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 508 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 449, &expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php case ", &_2, ": ?>");
	RETURN_MM();

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 528);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "expression", NULL, 449, &expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php ", &_0, "; ?>");
	RETURN_MM();

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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 450, &_1$$3, &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 548 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", NULL, 449, &expr);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, &expr, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 556 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(&_2, 350)) {
		zephir_array_fetch_string(&name, &expr, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 558 TSRMLS_CC);
		zephir_array_fetch_string(&_3$$4, &name, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 560 TSRMLS_CC);
		if (ZEPHIR_IS_LONG(&_3$$4, 265)) {
			zephir_array_fetch_string(&_4$$5, &name, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 565 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(&_4$$5, "super")) {
				RETURN_CCTOR(&exprCode);
			}
		}
	}
	zephir_read_property(&_5, this_ptr, SL("autoescape"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_5)) {
		ZEPHIR_CONCAT_SVS(return_value, "<?= $this->escaper->escapeHtml(", &exprCode, ") ?>");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "<?= ", &exprCode, " ?>");
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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 450, &_1$$3, &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 592 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 449, &expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php } elseif (", &_2, ") { ?>");
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Template path and compilation template path cannot be the same", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 615);
		return;
	}
	if (!((zephir_file_exists(&path TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(&_0$$4);
		object_init_ex(&_0$$4, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_SVS(&_1$$4, "Template file ", &path, " does not exist");
		ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 450, &_1$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$4, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 622 TSRMLS_CC);
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
		ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 450, &_3$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 630 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("currentPath"), &path);
	if (extendsMode) {
		ZVAL_BOOL(&_4, 1);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilesource", NULL, 0, &viewCode, &_4);
	zephir_check_call_status();
	if (Z_TYPE_P(&compilation) == IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&finalCompilation, "serialize", NULL, 66, &compilation);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&finalCompilation, &compilation);
	}
	ZEPHIR_INIT_VAR(&_5);
	zephir_file_put_contents(&_5, &compiledPath, &finalCompilation TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_5)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Volt directory can't be written", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 650);
		return;
	}
	RETURN_CCTOR(&compilation);

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 669);
		return;
	}
	ZEPHIR_INIT_VAR(&compilation);
	ZVAL_STRING(&compilation, "");
	ZEPHIR_INIT_VAR(&forElse);
	ZVAL_NULL(&forElse);
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("foreachLevel") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(&prefix, this_ptr, "getuniqueprefix", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&level);
	zephir_read_property(&level, this_ptr, SL("foreachLevel"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&prefixLevel);
	ZEPHIR_CONCAT_VV(&prefixLevel, &prefix, &level);
	ZEPHIR_OBS_VAR(&expr);
	zephir_array_fetch_string(&expr, &statement, SL("expr"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 687 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", NULL, 449, &expr);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&blockStatements);
	zephir_array_fetch_string(&blockStatements, &statement, SL("block_statements"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 693 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&forElse);
	ZVAL_BOOL(&forElse, 0);
	if (Z_TYPE_P(&blockStatements) == IS_ARRAY) {
		zephir_is_iterable(&blockStatements, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 719);
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
				zephir_update_property_array(this_ptr, SL("forElsePointers"), &level, &forElse TSRMLS_CC);
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
	ZEPHIR_CALL_METHOD(&code, this_ptr, "statementlist", NULL, 451, &blockStatements, &_2);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&loopContext);
	zephir_read_property(&loopContext, this_ptr, SL("loopPointers"), PH_NOISY_CC);
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
	zephir_array_fetch_string(&variable, &statement, SL("variable"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 749 TSRMLS_CC);
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
		ZEPHIR_CALL_METHOD(&_14$$13, this_ptr, "expression", NULL, 449, &ifExpr);
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
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("foreachLevel") TSRMLS_CC));
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


	zephir_read_property(&level, this_ptr, SL("foreachLevel"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_0, this_ptr, SL("forElsePointers"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&prefix, &_0, &level, 1 TSRMLS_CC)) {
		zephir_read_property(&_1$$3, this_ptr, SL("loopPointers"), PH_NOISY_CC | PH_READONLY);
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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 450, &_1$$3, &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 840 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 449, &expr);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, &statement, SL("true_statements"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 846 TSRMLS_CC);
	if (extendsMode) {
		ZVAL_BOOL(&_5, 1);
	} else {
		ZVAL_BOOL(&_5, 0);
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "statementlist", NULL, 451, &_4, &_5);
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
		ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "statementlist", NULL, 451, &blockStatements, &_7$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$4);
		ZEPHIR_CONCAT_SV(&_8$$4, "<?php } else { ?>", &_6$$4);
		zephir_concat_self(&compilation, &_8$$4 TSRMLS_CC);
	}
	zephir_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
	RETURN_CCTOR(&compilation);

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 876);
		return;
	}
	zephir_array_fetch_string(&_0, &pathExpr, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 883 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(&_0, 260)) {
		if (!(zephir_array_isset_string(&statement, SL("params")))) {
			ZEPHIR_OBS_VAR(&path);
			zephir_array_fetch_string(&path, &pathExpr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 893 TSRMLS_CC);
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
	ZEPHIR_CALL_METHOD(&path, this_ptr, "expression", NULL, 449, &pathExpr);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&params);
	if (!(zephir_array_isset_string_fetch(&params, &statement, SL("params"), 0))) {
		ZEPHIR_CONCAT_SVS(return_value, "<?php $this->partial(", &path, "); ?>");
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "expression", NULL, 449, &params);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 943);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("macros"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &name)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_mvc_view_engine_volt_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SVS(&_2$$4, "Macro '", &name, "' is already defined");
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 450, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 950 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("macros"), &name, &name TSRMLS_CC);
	ZEPHIR_INIT_VAR(&macroName);
	ZEPHIR_CONCAT_SVS(&macroName, "$this->macros['", &name, "']");
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
		zephir_is_iterable(&parameters, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 987);
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
			zephir_array_fetch_string(&variableName, &parameter, SL("variable"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 971 TSRMLS_CC);
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
				ZEPHIR_CALL_METHOD(&_12$$8, this_ptr, "expression", &_13, 449, &defaultValue);
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
		ZEPHIR_CALL_METHOD(&_16$$10, this_ptr, "statementlist", NULL, 451, &blockStatements, &_17$$10);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1022);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "expression", NULL, 449, &expr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<?php return ", &_0, "; ?>");
	RETURN_MM();

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1042);
		return;
	}
	ZEPHIR_INIT_VAR(&compilation);
	ZVAL_STRING(&compilation, "<?php");
	zephir_is_iterable(&assignments, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1088);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&assignments), _0)
	{
		ZEPHIR_INIT_NVAR(&assignment);
		ZVAL_COPY(&assignment, _0);
		zephir_array_fetch_string(&_1$$4, &assignment, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1052 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "expression", &_2, 449, &_1$$4);
		zephir_check_call_status();
		zephir_array_fetch_string(&_3$$4, &assignment, SL("variable"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1057 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&target, this_ptr, "expression", &_2, 449, &_3$$4);
		zephir_check_call_status();
		zephir_array_fetch_string(&_4$$4, &assignment, SL("op"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1063 TSRMLS_CC);
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
	zephir_update_property_zval(this_ptr, SL("currentPath"), &_0);
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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 450, &_1$$3, &statement);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1116 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "expression", NULL, 449, &expr);
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
		ZEPHIR_CALL_METHOD(&lines, this_ptr, "statementlist", NULL, 451, &caseClauses, &_3$$4);
		zephir_check_call_status();
		if (zephir_fast_strlen_ev(&lines) != 0) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "/(*ANYCRLF)^\\h+|\\h+$|(\\h){2,}/mu");
			ZEPHIR_INIT_VAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "");
			ZEPHIR_CALL_FUNCTION(&_6$$5, "preg_replace", NULL, 21, &_4$$5, &_5$$5, &lines);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&lines, &_6$$5);
		}
		zephir_concat_self(&compilation, &lines TSRMLS_CC);
	}
	zephir_concat_self_str(&compilation, SL("<?php endswitch ?>") TSRMLS_CC);
	RETURN_CCTOR(&compilation);

}

/**
 * Resolves an expression node in an AST volt tree
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, expression) {

	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_8 = NULL, *_10 = NULL, *_12 = NULL, *_18 = NULL, *_25 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, exprCode, extensions, items, singleExpr, singleExprCode, name, left, leftCode, right, rightCode, type, startCode, endCode, start, end, _0, _2$$4, *_4$$6, _5$$7, _7$$8, _9$$12, _11$$13, _13$$31, _14$$31, _15$$31, _16$$31, _17$$35, _19$$69, _20$$69, _21$$73, _22$$73, _23$$73, _24$$73;
	zval expr, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_1$$4);
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
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_13$$31);
	ZVAL_UNDEF(&_14$$31);
	ZVAL_UNDEF(&_15$$31);
	ZVAL_UNDEF(&_16$$31);
	ZVAL_UNDEF(&_17$$35);
	ZVAL_UNDEF(&_19$$69);
	ZVAL_UNDEF(&_20$$69);
	ZVAL_UNDEF(&_21$$73);
	ZVAL_UNDEF(&_22$$73);
	ZVAL_UNDEF(&_23$$73);
	ZVAL_UNDEF(&_24$$73);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);


	ZEPHIR_INIT_VAR(&exprCode);
	ZVAL_NULL(&exprCode);
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("exprLevel") TSRMLS_CC));
	zephir_read_property(&_0, this_ptr, SL("extensions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&extensions, &_0);
	while (1) {
		if (Z_TYPE_P(&extensions) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&_1$$4);
			zephir_create_array(&_1$$4, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_1$$4, &expr);
			ZEPHIR_INIT_NVAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "resolveExpression");
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "fireextensionevent", &_3, 452, &_2$$4, &_1$$4);
			zephir_check_call_status();
			if (Z_TYPE_P(&exprCode) == IS_STRING) {
				break;
			}
		}
		ZEPHIR_OBS_NVAR(&type);
		if (!(zephir_array_isset_string_fetch(&type, &expr, SL("type"), 0))) {
			ZEPHIR_INIT_NVAR(&items);
			array_init(&items);
			zephir_is_iterable(&expr, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1196);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&expr), _4$$6)
			{
				ZEPHIR_INIT_NVAR(&singleExpr);
				ZVAL_COPY(&singleExpr, _4$$6);
				zephir_array_fetch_string(&_5$$7, &singleExpr, SL("expr"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1189 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&singleExprCode, this_ptr, "expression", &_6, 449, &_5$$7);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&name);
				if (zephir_array_isset_string_fetch(&name, &singleExpr, SL("name"), 0)) {
					ZEPHIR_INIT_LNVAR(_7$$8);
					ZEPHIR_CONCAT_SVSV(&_7$$8, "'", &name, "' => ", &singleExprCode);
					zephir_array_append(&items, &_7$$8, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1191);
				} else {
					zephir_array_append(&items, &singleExprCode, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1193);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&singleExpr);
			ZEPHIR_INIT_NVAR(&exprCode);
			zephir_fast_join_str(&exprCode, SL(", "), &items TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&type, '.')) {
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "attributereader", &_8, 0, &expr);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_OBS_NVAR(&left);
		if (zephir_array_isset_string_fetch(&left, &expr, SL("left"), 0)) {
			ZEPHIR_CALL_METHOD(&leftCode, this_ptr, "expression", &_6, 449, &left);
			zephir_check_call_status();
		}
		if (ZEPHIR_IS_LONG(&type, 311)) {
			zephir_array_fetch_string(&_9$$12, &expr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1219 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "resolvetest", &_10, 0, &_9$$12, &leftCode);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 124)) {
			zephir_array_fetch_string(&_11$$13, &expr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1227 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "resolvefilter", &_12, 453, &_11$$13, &leftCode);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_OBS_NVAR(&right);
		if (zephir_array_isset_string_fetch(&right, &expr, SL("right"), 0)) {
			ZEPHIR_CALL_METHOD(&rightCode, this_ptr, "expression", &_6, 449, &right);
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
				zephir_array_fetch_string(&exprCode, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1294 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 259)) {
				ZEPHIR_OBS_NVAR(&exprCode);
				zephir_array_fetch_string(&exprCode, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1298 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 260)) {
				ZEPHIR_INIT_NVAR(&_13$$31);
				zephir_array_fetch_string(&_14$$31, &expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1302 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_15$$31);
				ZVAL_STRING(&_15$$31, "'");
				ZEPHIR_INIT_NVAR(&_16$$31);
				ZVAL_STRING(&_16$$31, "\\'");
				zephir_fast_str_replace(&_13$$31, &_15$$31, &_16$$31, &_14$$31 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVS(&exprCode, "'", &_13$$31, "'");
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
				zephir_array_fetch_string(&_17$$35, &expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1318 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SV(&exprCode, "$", &_17$$35);
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
				ZEPHIR_CALL_METHOD(&exprCode, this_ptr, "functioncall", &_18, 0, &expr);
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
					ZEPHIR_CALL_METHOD(&startCode, this_ptr, "expression", &_6, 449, &start);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&startCode);
					ZVAL_STRING(&startCode, "null");
				}
				ZEPHIR_OBS_NVAR(&end);
				if (zephir_array_isset_string_fetch(&end, &expr, SL("end"), 0)) {
					ZEPHIR_CALL_METHOD(&endCode, this_ptr, "expression", &_6, 449, &end);
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
				zephir_array_fetch_string(&_20$$69, &expr, SL("ternary"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1457 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_19$$69, this_ptr, "expression", &_6, 449, &_20$$69);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&exprCode);
				ZEPHIR_CONCAT_SVSVSVS(&exprCode, "(", &_19$$69, " ? ", &leftCode, " : ", &rightCode, ")");
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
				zephir_array_fetch_string(&exprCode, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1469 TSRMLS_CC);
				break;
			}
			ZEPHIR_INIT_NVAR(&_21$$73);
			object_init_ex(&_21$$73, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_22$$73, &expr, SL("file"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1473 TSRMLS_CC);
			zephir_array_fetch_string(&_23$$73, &expr, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1473 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_24$$73);
			ZEPHIR_CONCAT_SVSVSV(&_24$$73, "Unknown expression ", &type, " in ", &_22$$73, " on line ", &_23$$73);
			ZEPHIR_CALL_METHOD(NULL, &_21$$73, "__construct", &_25, 450, &_24$$73);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_21$$73, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1473 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

		break;
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("exprLevel") TSRMLS_CC));
	RETURN_CCTOR(&exprCode);

}

/**
 * Fires an event to registered extensions
 *
 * @param array arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, fireExtensionEvent) {

	zval _2$$6, _3$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *arguments = NULL, arguments_sub, __$null, extensions, extension, status, _0, *_1$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&extensions);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$7);

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


	zephir_read_property(&_0, this_ptr, SL("extensions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&extensions, &_0);
	if (Z_TYPE_P(&extensions) == IS_ARRAY) {
		zephir_is_iterable(&extensions, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1517);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extensions), _1$$3)
		{
			ZEPHIR_INIT_NVAR(&extension);
			ZVAL_COPY(&extension, _1$$3);
			if ((zephir_method_exists(&extension, &name TSRMLS_CC)  == SUCCESS)) {
				if (Z_TYPE_P(arguments) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_2$$6);
					zephir_create_array(&_2$$6, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_2$$6, &extension);
					zephir_array_fast_append(&_2$$6, &name);
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&status, &_2$$6, arguments);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_3$$7);
					zephir_create_array(&_3$$7, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_3$$7, &extension);
					zephir_array_fast_append(&_3$$7, &name);
					ZEPHIR_INIT_NVAR(&status);
					ZEPHIR_CALL_USER_FUNC(&status, &_3$$7);
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
 * Resolves function intermediate code into PHP function calls
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, functionCall) {

	zend_bool _8$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, __$true, code, funcArguments, arguments, nameExpr, nameType, name, extensions, functions, definition, extendedBlocks, block, currentBlock, exprLevel, escapedCode, method, arrayHelpers, className, _14, _0$$5, _12$$5, _2$$6, _4$$9, _5$$9, _6$$9, _7$$9, _9$$15, _10$$16, _11$$17, _13$$25;
	zval expr, _1$$6, _3$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_3$$12);
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
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_9$$15);
	ZVAL_UNDEF(&_10$$16);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_13$$25);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expr_param);

	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);


	ZEPHIR_INIT_VAR(&code);
	ZVAL_NULL(&code);
	ZEPHIR_INIT_VAR(&funcArguments);
	ZVAL_NULL(&funcArguments);
	ZEPHIR_OBS_NVAR(&funcArguments);
	if (zephir_array_isset_string_fetch(&funcArguments, &expr, SL("arguments"), 0)) {
		ZEPHIR_CALL_METHOD(&arguments, this_ptr, "expression", NULL, 449, &funcArguments);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&arguments);
		ZVAL_STRING(&arguments, "");
	}
	ZEPHIR_OBS_VAR(&nameExpr);
	zephir_array_fetch_string(&nameExpr, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1539 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&nameType);
	zephir_array_fetch_string(&nameType, &nameExpr, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1539 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(&nameType, 265)) {
		ZEPHIR_OBS_VAR(&name);
		zephir_array_fetch_string(&name, &nameExpr, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1546 TSRMLS_CC);
		zephir_read_property(&_0$$5, this_ptr, SL("extensions"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&extensions, &_0$$5);
		if (Z_TYPE_P(&extensions) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_1$$6);
			zephir_create_array(&_1$$6, 3, 0 TSRMLS_CC);
			zephir_array_fast_append(&_1$$6, &name);
			zephir_array_fast_append(&_1$$6, &arguments);
			zephir_array_fast_append(&_1$$6, &funcArguments);
			ZEPHIR_INIT_VAR(&_2$$6);
			ZVAL_STRING(&_2$$6, "compileFunction");
			ZEPHIR_CALL_METHOD(&code, this_ptr, "fireextensionevent", NULL, 452, &_2$$6, &_1$$6);
			zephir_check_call_status();
			if (Z_TYPE_P(&code) == IS_STRING) {
				RETURN_CCTOR(&code);
			}
		}
		zephir_read_property(&_0$$5, this_ptr, SL("functions"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&functions, &_0$$5);
		if (Z_TYPE_P(&functions) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(&definition);
			if (zephir_array_isset_fetch(&definition, &functions, &name, 0 TSRMLS_CC)) {
				if (Z_TYPE_P(&definition) == IS_STRING) {
					ZEPHIR_CONCAT_VSVS(return_value, &definition, "(", &arguments, ")");
					RETURN_MM();
				}
				if (Z_TYPE_P(&definition) == IS_OBJECT) {
					if (zephir_instance_of_ev(&definition, zend_ce_closure TSRMLS_CC)) {
						ZEPHIR_INIT_VAR(&_3$$12);
						zephir_create_array(&_3$$12, 2, 0 TSRMLS_CC);
						zephir_array_fast_append(&_3$$12, &arguments);
						zephir_array_fast_append(&_3$$12, &funcArguments);
						ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &definition, &_3$$12);
						zephir_check_call_status();
						RETURN_MM();
					}
				}
				ZEPHIR_INIT_VAR(&_4$$9);
				object_init_ex(&_4$$9, phalcon_mvc_view_engine_volt_exception_ce);
				zephir_array_fetch_string(&_5$$9, &expr, SL("file"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1588 TSRMLS_CC);
				zephir_array_fetch_string(&_6$$9, &expr, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1589 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_7$$9);
				ZEPHIR_CONCAT_SVSVSV(&_7$$9, "Invalid definition for user function '", &name, "' in ", &_5$$9, " on line ", &_6$$9);
				ZEPHIR_CALL_METHOD(NULL, &_4$$9, "__construct", NULL, 450, &_7$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_4$$9, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1589 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		_8$$5 = ZEPHIR_IS_STRING(&name, "get_content");
		if (!(_8$$5)) {
			_8$$5 = ZEPHIR_IS_STRING(&name, "content");
		}
		if (_8$$5) {
			RETURN_MM_STRING("$this->getContent()");
		}
		if (ZEPHIR_IS_STRING(&name, "partial")) {
			ZEPHIR_CONCAT_SVS(return_value, "$this->partial(", &arguments, ")");
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&name, "super")) {
			zephir_read_property(&_9$$15, this_ptr, SL("extendedBlocks"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&extendedBlocks, &_9$$15);
			if (Z_TYPE_P(&extendedBlocks) == IS_ARRAY) {
				zephir_read_property(&_10$$16, this_ptr, SL("currentBlock"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CPY_WRT(&currentBlock, &_10$$16);
				ZEPHIR_OBS_VAR(&block);
				if (zephir_array_isset_fetch(&block, &extendedBlocks, &currentBlock, 0 TSRMLS_CC)) {
					zephir_read_property(&_11$$17, this_ptr, SL("exprLevel"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CPY_WRT(&exprLevel, &_11$$17);
					if (Z_TYPE_P(&block) == IS_ARRAY) {
						ZEPHIR_CALL_METHOD(&code, this_ptr, "statementlistorextends", NULL, 454, &block);
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
		ZEPHIR_INIT_VAR(&_12$$5);
		zephir_camelize(&_12$$5, &name, NULL  );
		ZEPHIR_CALL_FUNCTION(&method, "lcfirst", NULL, 68, &_12$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&className);
		ZVAL_STRING(&className, "Phalcon\\Tag");
		if ((zephir_method_exists(&className, &method TSRMLS_CC)  == SUCCESS)) {
			zephir_read_property(&_13$$25, this_ptr, SL("arrayHelpers"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&arrayHelpers, &_13$$25);
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
				zephir_update_property_zval(this_ptr, SL("arrayHelpers"), &arrayHelpers);
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
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "expression", NULL, 449, &nameExpr);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVS(return_value, &_14, "(", &arguments, ")");
	RETURN_MM();

}

/**
 * Returns the path to the last compiled template
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "compiledTemplatePath");

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * Returns the list of extensions registered in Volt
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getExtensions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "extensions");

}

/**
 * Register the user registered filters
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFilters) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "filters");

}

/**
 * Register the user registered functions
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFunctions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "functions");

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


	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
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


	RETURN_MEMBER(getThis(), "options");

}

/**
 * Returns the path that is currently being compiled
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getTemplatePath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "currentPath");

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

	zephir_read_property(&_0, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("currentPath"), PH_NOISY_CC | PH_READONLY);
		zephir_unique_path_key(&_1$$3, &_2$$3 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("prefix"), &_1$$3);
	}
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, this_ptr, SL("prefix"), PH_NOISY_CC);
	if (Z_TYPE_P(&_3) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(&_4$$4);
		zephir_read_property(&_4$$4, this_ptr, SL("prefix"), PH_NOISY_CC);
		if (zephir_instance_of_ev(&_4$$4, zend_ce_closure TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_read_property(&_6$$5, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_7$$5);
			zephir_create_array(&_7$$5, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_7$$5, this_ptr);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_5$$5, &_6$$5, &_7$$5);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("prefix"), &_5$$5);
		}
	}
	ZEPHIR_OBS_VAR(&_8);
	zephir_read_property(&_8, this_ptr, SL("prefix"), PH_NOISY_CC);
	if (Z_TYPE_P(&_8) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "The unique compilation prefix is invalid", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1883);
		return;
	}
	RETURN_MM_MEMBER(getThis(), "prefix");

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
	zephir_array_fetch_string(&type, &test, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1914 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(&type, 265)) {
		ZEPHIR_OBS_VAR(&name);
		zephir_array_fetch_string(&name, &test, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1921 TSRMLS_CC);
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
		zephir_array_fetch_string(&testName, &test, SL("name"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1972 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&name);
		if (zephir_array_isset_string_fetch(&name, &testName, SL("value"), 0)) {
			if (ZEPHIR_IS_STRING(&name, "divisibleby")) {
				zephir_array_fetch_string(&_1$$12, &test, SL("arguments"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1976 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_0$$12, this_ptr, "expression", NULL, 449, &_1$$12);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVSVS(return_value, "(((", &left, ") % (", &_0$$12, ")) == 0)");
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(&name, "sameas")) {
				zephir_array_fetch_string(&_3$$13, &test, SL("arguments"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1983 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_2$$13, this_ptr, "expression", NULL, 449, &_3$$13);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVSVS(return_value, "(", &left, ") === (", &_2$$13, ")");
				RETURN_MM();
			}
			if (ZEPHIR_IS_STRING(&name, "type")) {
				zephir_array_fetch_string(&_5$$14, &test, SL("arguments"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 1990 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_4$$14, this_ptr, "expression", NULL, 449, &_5$$14);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVSVS(return_value, "gettype(", &left, ") === (", &_4$$14, ")");
				RETURN_MM();
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "expression", NULL, 449, &test);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &left, " == ", &_6);
	RETURN_MM();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params(0, 1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);

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


	zephir_update_property_array(this_ptr, SL("options"), &option, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

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


	zephir_update_property_zval(this_ptr, SL("options"), &options);
	ZEPHIR_MM_RESTORE();

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


	zephir_update_property_zval(this_ptr, SL("prefix"), &prefix);
	RETURN_THIS();

}

/**
 * Compiles a Volt source code returning a PHP plain version
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSource) {

	zend_string *_5$$7;
	zend_ulong _4$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode;
	zval *viewCode_param = NULL, *extendsMode_param = NULL, currentPath, intermediate, extended, finalCompilation, blocks, extendedBlocks, name, block, blockCompilation, localBlock, compilation, options, autoescape, _0, _1, _2$$7, *_3$$7;
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


	zephir_read_property(&_0, this_ptr, SL("currentPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&currentPath, &_0);
	zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&autoescape);
		if (zephir_array_isset_string_fetch(&autoescape, &options, SL("autoescape"), 0)) {
			if (((Z_TYPE_P(&autoescape) == IS_TRUE || Z_TYPE_P(&autoescape) == IS_FALSE) != 1)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "'autoescape' must be bool", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2059);
				return;
			}
			zephir_update_property_zval(this_ptr, SL("autoescape"), &autoescape);
		}
	}
	ZEPHIR_INIT_VAR(&intermediate);
	ZEPHIR_LAST_CALL_STATUS = phvolt_parse_view(&intermediate, &viewCode, &currentPath TSRMLS_CC);
	zephir_check_call_status();
	if (Z_TYPE_P(&intermediate) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Invalid intermediate representation", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2071);
		return;
	}
	if (extendsMode) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_CALL_METHOD(&compilation, this_ptr, "statementlist", NULL, 451, &intermediate, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("extended"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&extended, &_1);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&extended)) {
		ZEPHIR_INIT_VAR(&finalCompilation);
		if (extendsMode == 1) {
			array_init(&finalCompilation);
		} else {
			ZVAL_NULL(&finalCompilation);
		}
		zephir_read_property(&_2$$7, this_ptr, SL("blocks"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&blocks, &_2$$7);
		zephir_read_property(&_2$$7, this_ptr, SL("extendedBlocks"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&extendedBlocks, &_2$$7);
		zephir_is_iterable(&extendedBlocks, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2137);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&extendedBlocks), _4$$7, _5$$7, _3$$7)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_5$$7 != NULL) { 
				ZVAL_STR_COPY(&name, _5$$7);
			} else {
				ZVAL_LONG(&name, _4$$7);
			}
			ZEPHIR_INIT_NVAR(&block);
			ZVAL_COPY(&block, _3$$7);
			if (Z_TYPE_P(&name) == IS_STRING) {
				if (zephir_array_isset(&blocks, &name)) {
					ZEPHIR_OBS_NVAR(&localBlock);
					zephir_array_fetch(&localBlock, &blocks, &name, PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2105 TSRMLS_CC);
					zephir_update_property_zval(this_ptr, SL("currentBlock"), &name);
					ZEPHIR_CALL_METHOD(&blockCompilation, this_ptr, "statementlist", NULL, 451, &localBlock);
					zephir_check_call_status();
				} else {
					if (Z_TYPE_P(&block) == IS_ARRAY) {
						ZEPHIR_CALL_METHOD(&blockCompilation, this_ptr, "statementlist", NULL, 451, &block);
						zephir_check_call_status();
					} else {
						ZEPHIR_CPY_WRT(&blockCompilation, &block);
					}
				}
				if (extendsMode) {
					zephir_array_update_zval(&finalCompilation, &name, &blockCompilation, PH_COPY | PH_SEPARATE);
				} else {
					zephir_concat_self(&finalCompilation, &blockCompilation TSRMLS_CC);
				}
			} else {
				if (extendsMode) {
					zephir_array_append(&finalCompilation, &block, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2130);
				} else {
					zephir_concat_self(&finalCompilation, &block TSRMLS_CC);
				}
			}
		} ZEND_HASH_FOREACH_END();
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
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFinalPath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, view, viewsDirs, viewsDir, _0, *_1$$4, _2$$5;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&view);
	ZVAL_UNDEF(&viewsDirs);
	ZVAL_UNDEF(&viewsDir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&view, &_0);
	if (Z_TYPE_P(&view) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&viewsDirs, &view, "getviewsdir", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&viewsDirs) == IS_ARRAY) {
			zephir_is_iterable(&viewsDirs, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2168);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&viewsDirs), _1$$4)
			{
				ZEPHIR_INIT_NVAR(&viewsDir);
				ZVAL_COPY(&viewsDir, _1$$4);
				ZEPHIR_INIT_LNVAR(_2$$5);
				ZEPHIR_CONCAT_VV(&_2$$5, &viewsDir, &path);
				if ((zephir_file_exists(&_2$$5 TSRMLS_CC) == SUCCESS)) {
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

/**
 * Resolves filter intermediate code into PHP function calls
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveFilter) {

	zend_bool _14, _15, _16;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval left;
	zval *filter_param = NULL, *left_param = NULL, code, type, functionName, name, file, line, extensions, filters, funcArguments, arguments, definition, _6, _17, _18, _19, _20, _0$$5, _1$$5, _2$$5, _3$$5, _8$$9, _10$$12, _11$$12, _12$$12, _13$$12;
	zval filter, _4$$7, _5$$7, _7$$9, _9$$15;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_9$$15);
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
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&left);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &filter_param, &left_param);

	ZEPHIR_OBS_COPY_OR_DUP(&filter, filter_param);
	zephir_get_strval(&left, left_param);


	ZEPHIR_INIT_VAR(&code);
	ZVAL_NULL(&code);
	ZEPHIR_OBS_VAR(&type);
	zephir_array_fetch_string(&type, &filter, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2186 TSRMLS_CC);
	if (ZEPHIR_IS_LONG(&type, 265)) {
		ZEPHIR_OBS_VAR(&name);
		zephir_array_fetch_string(&name, &filter, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2192 TSRMLS_CC);
	} else {
		if (!ZEPHIR_IS_LONG(&type, 350)) {
			ZEPHIR_INIT_VAR(&_0$$5);
			object_init_ex(&_0$$5, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_1$$5, &filter, SL("file"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2200 TSRMLS_CC);
			zephir_array_fetch_string(&_2$$5, &filter, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2200 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_3$$5);
			ZEPHIR_CONCAT_SVSV(&_3$$5, "Unknown filter type in ", &_1$$5, " on line ", &_2$$5);
			ZEPHIR_CALL_METHOD(NULL, &_0$$5, "__construct", NULL, 450, &_3$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_0$$5, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2200 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(&functionName);
		zephir_array_fetch_string(&functionName, &filter, SL("name"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2203 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&name);
		zephir_array_fetch_string(&name, &functionName, SL("value"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2204 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(&funcArguments);
	ZVAL_NULL(&funcArguments);
	ZEPHIR_INIT_VAR(&arguments);
	ZVAL_NULL(&arguments);
	ZEPHIR_OBS_NVAR(&funcArguments);
	if (zephir_array_isset_string_fetch(&funcArguments, &filter, SL("arguments"), 0)) {
		if (!ZEPHIR_IS_STRING(&name, "default")) {
			ZEPHIR_OBS_VAR(&file);
			zephir_array_fetch_string(&file, &filter, SL("file"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2219 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&line);
			zephir_array_fetch_string(&line, &filter, SL("line"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2219 TSRMLS_CC);
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
			ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 455, &funcArguments, &_4$$7);
			ZEPHIR_UNREF(&funcArguments);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&arguments, this_ptr, "expression", NULL, 449, &funcArguments);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&arguments, &left);
	}
	zephir_read_property(&_6, this_ptr, SL("extensions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&extensions, &_6);
	if (Z_TYPE_P(&extensions) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_7$$9);
		zephir_create_array(&_7$$9, 3, 0 TSRMLS_CC);
		zephir_array_fast_append(&_7$$9, &name);
		zephir_array_fast_append(&_7$$9, &arguments);
		zephir_array_fast_append(&_7$$9, &funcArguments);
		ZEPHIR_INIT_VAR(&_8$$9);
		ZVAL_STRING(&_8$$9, "compileFilter");
		ZEPHIR_CALL_METHOD(&code, this_ptr, "fireextensionevent", NULL, 452, &_8$$9, &_7$$9);
		zephir_check_call_status();
		if (Z_TYPE_P(&code) == IS_STRING) {
			RETURN_CCTOR(&code);
		}
	}
	zephir_read_property(&_6, this_ptr, SL("filters"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&filters, &_6);
	if (Z_TYPE_P(&filters) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&definition);
		if (zephir_array_isset_fetch(&definition, &filters, &name, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(&definition) == IS_STRING) {
				ZEPHIR_CONCAT_VSVS(return_value, &definition, "(", &arguments, ")");
				RETURN_MM();
			}
			if (Z_TYPE_P(&definition) == IS_OBJECT) {
				if (zephir_instance_of_ev(&definition, zend_ce_closure TSRMLS_CC)) {
					ZEPHIR_INIT_VAR(&_9$$15);
					zephir_create_array(&_9$$15, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(&_9$$15, &arguments);
					zephir_array_fast_append(&_9$$15, &funcArguments);
					ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &definition, &_9$$15);
					zephir_check_call_status();
					RETURN_MM();
				}
			}
			ZEPHIR_INIT_VAR(&_10$$12);
			object_init_ex(&_10$$12, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_11$$12, &filter, SL("file"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2283 TSRMLS_CC);
			zephir_array_fetch_string(&_12$$12, &filter, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2284 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_13$$12);
			ZEPHIR_CONCAT_SVSVSV(&_13$$12, "Invalid definition for user filter '", &name, "' in ", &_11$$12, " on line ", &_12$$12);
			ZEPHIR_CALL_METHOD(NULL, &_10$$12, "__construct", NULL, 450, &_13$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_10$$12, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2284 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (ZEPHIR_IS_STRING(&name, "length")) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->length(", &arguments, ")");
		RETURN_MM();
	}
	_14 = ZEPHIR_IS_STRING(&name, "e");
	if (!(_14)) {
		_14 = ZEPHIR_IS_STRING(&name, "escape");
	}
	if (_14) {
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
	_15 = ZEPHIR_IS_STRING(&name, "lower");
	if (!(_15)) {
		_15 = ZEPHIR_IS_STRING(&name, "lowercase");
	}
	if (_15) {
		ZEPHIR_CONCAT_SVS(return_value, "Phalcon\\Text::lower(", &arguments, ")");
		RETURN_MM();
	}
	_16 = ZEPHIR_IS_STRING(&name, "upper");
	if (!(_16)) {
		_16 = ZEPHIR_IS_STRING(&name, "uppercase");
	}
	if (_16) {
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
	ZEPHIR_INIT_VAR(&_17);
	object_init_ex(&_17, phalcon_mvc_view_engine_volt_exception_ce);
	zephir_array_fetch_string(&_18, &filter, SL("file"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2473 TSRMLS_CC);
	zephir_array_fetch_string(&_19, &filter, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2473 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_20);
	ZEPHIR_CONCAT_SVSVSV(&_20, "Unknown filter \"", &name, "\" in ", &_18, " on line ", &_19);
	ZEPHIR_CALL_METHOD(NULL, &_17, "__construct", NULL, 450, &_20);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_17, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2473 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Traverses a statement list compiling each of its nodes
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, statementList) {

	zephir_fcall_cache_entry *_7 = NULL, *_10 = NULL, *_14 = NULL, *_16 = NULL, *_19 = NULL, *_21 = NULL, *_26 = NULL, *_28 = NULL, *_30 = NULL, *_34 = NULL, *_36 = NULL, *_39 = NULL, *_42 = NULL, *_44 = NULL, *_46 = NULL, *_49 = NULL, *_51 = NULL, *_54 = NULL, *_57 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool extendsMode, _1;
	zval *statements_param = NULL, *extendsMode_param = NULL, __$true, __$false, extended, blockMode, compilation, extensions, statement, tempCompilation, type, blockName, blockStatements, blocks, path, finalPath, subCompiler, level, _0, *_2, _3$$7, _4$$7, _5$$7, _6$$7, _9$$8, _11$$10, _12$$11, _13$$11, _15$$12, _17$$13, _18$$13, _20$$14, _22$$15, _23$$15, _24$$16, _25$$16, _27$$17, _29$$18, _31$$19, _32$$24, _33$$24, _35$$25, _37$$26, _38$$27, _40$$28, _41$$28, _43$$29, _45$$30, _47$$31, _48$$31, _50$$34, _52$$35, _53$$35, _55$$36, _56$$36, _58$$38, _59$$38, _60$$38, _61$$38;
	zval statements, _8$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statements);
	ZVAL_UNDEF(&_8$$8);
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
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&_32$$24);
	ZVAL_UNDEF(&_33$$24);
	ZVAL_UNDEF(&_35$$25);
	ZVAL_UNDEF(&_37$$26);
	ZVAL_UNDEF(&_38$$27);
	ZVAL_UNDEF(&_40$$28);
	ZVAL_UNDEF(&_41$$28);
	ZVAL_UNDEF(&_43$$29);
	ZVAL_UNDEF(&_45$$30);
	ZVAL_UNDEF(&_47$$31);
	ZVAL_UNDEF(&_48$$31);
	ZVAL_UNDEF(&_50$$34);
	ZVAL_UNDEF(&_52$$35);
	ZVAL_UNDEF(&_53$$35);
	ZVAL_UNDEF(&_55$$36);
	ZVAL_UNDEF(&_56$$36);
	ZVAL_UNDEF(&_58$$38);
	ZVAL_UNDEF(&_59$$38);
	ZVAL_UNDEF(&_60$$38);
	ZVAL_UNDEF(&_61$$38);

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
	zephir_read_property(&_0, this_ptr, SL("extended"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&extended, &_0);
	_1 = zephir_is_true(&extended);
	if (!(_1)) {
		_1 = extendsMode;
	}
	ZEPHIR_INIT_VAR(&blockMode);
	ZVAL_BOOL(&blockMode, _1);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&blockMode)) {
		RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("blockLevel") TSRMLS_CC));
	}
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("level") TSRMLS_CC));
	ZEPHIR_INIT_VAR(&compilation);
	ZVAL_NULL(&compilation);
	zephir_read_property(&_0, this_ptr, SL("extensions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&extensions, &_0);
	zephir_is_iterable(&statements, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2719);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&statements), _2)
	{
		ZEPHIR_INIT_NVAR(&statement);
		ZVAL_COPY(&statement, _2);
		if (Z_TYPE_P(&statement) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_engine_volt_exception_ce, "Corrupted statement", "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2512);
			return;
		}
		if (!(zephir_array_isset_string(&statement, SL("type")))) {
			ZEPHIR_INIT_NVAR(&_3$$7);
			object_init_ex(&_3$$7, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_4$$7, &statement, SL("file"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2519 TSRMLS_CC);
			zephir_array_fetch_string(&_5$$7, &statement, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2519 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_6$$7);
			ZEPHIR_CONCAT_SVSV(&_6$$7, "Invalid statement in ", &_4$$7, " on line ", &_5$$7);
			ZEPHIR_CALL_METHOD(NULL, &_3$$7, "__construct", &_7, 450, &_6$$7, &statement);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$7, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2519 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&extensions) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&_8$$8);
			zephir_create_array(&_8$$8, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_8$$8, &statement);
			ZEPHIR_INIT_NVAR(&_9$$8);
			ZVAL_STRING(&_9$$8, "compileStatement");
			ZEPHIR_CALL_METHOD(&tempCompilation, this_ptr, "fireextensionevent", &_10, 452, &_9$$8, &_8$$8);
			zephir_check_call_status();
			if (Z_TYPE_P(&tempCompilation) == IS_STRING) {
				zephir_concat_self(&compilation, &tempCompilation TSRMLS_CC);
				continue;
			}
		}
		ZEPHIR_OBS_NVAR(&type);
		zephir_array_fetch_string(&type, &statement, SL("type"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2540 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(&type, 357)) {
				zephir_array_fetch_string(&_11$$10, &statement, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2548 TSRMLS_CC);
				zephir_concat_self(&compilation, &_11$$10 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 300)) {
				if (extendsMode) {
					ZVAL_BOOL(&_13$$11, 1);
				} else {
					ZVAL_BOOL(&_13$$11, 0);
				}
				ZEPHIR_CALL_METHOD(&_12$$11, this_ptr, "compileif", &_14, 0, &statement, &_13$$11);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_12$$11 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 302)) {
				ZEPHIR_CALL_METHOD(&_15$$12, this_ptr, "compileelseif", &_16, 0, &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_15$$12 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 411)) {
				if (extendsMode) {
					ZVAL_BOOL(&_18$$13, 1);
				} else {
					ZVAL_BOOL(&_18$$13, 0);
				}
				ZEPHIR_CALL_METHOD(&_17$$13, this_ptr, "compileswitch", &_19, 0, &statement, &_18$$13);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_17$$13 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 412)) {
				ZEPHIR_CALL_METHOD(&_20$$14, this_ptr, "compilecase", &_21, 0, &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_20$$14 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 413)) {
				ZVAL_BOOL(&_23$$15, 0);
				ZEPHIR_CALL_METHOD(&_22$$15, this_ptr, "compilecase", &_21, 0, &statement, &_23$$15);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_22$$15 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 304)) {
				if (extendsMode) {
					ZVAL_BOOL(&_25$$16, 1);
				} else {
					ZVAL_BOOL(&_25$$16, 0);
				}
				ZEPHIR_CALL_METHOD(&_24$$16, this_ptr, "compileforeach", &_26, 0, &statement, &_25$$16);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_24$$16 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 306)) {
				ZEPHIR_CALL_METHOD(&_27$$17, this_ptr, "compileset", &_28, 0, &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_27$$17 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 359)) {
				ZEPHIR_CALL_METHOD(&_29$$18, this_ptr, "compileecho", &_30, 0, &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_29$$18 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 307)) {
				ZEPHIR_OBS_NVAR(&blockName);
				zephir_array_fetch_string(&blockName, &statement, SL("name"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2588 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&blockStatements);
				zephir_array_isset_string_fetch(&blockStatements, &statement, SL("block_statements"), 0);
				zephir_read_property(&_31$$19, this_ptr, SL("blocks"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CPY_WRT(&blocks, &_31$$19);
				if (zephir_is_true(&blockMode)) {
					if (Z_TYPE_P(&blocks) != IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&blocks);
						array_init(&blocks);
					}
					if (Z_TYPE_P(&compilation) != IS_NULL) {
						zephir_array_append(&blocks, &compilation, PH_SEPARATE, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2603);
						ZEPHIR_INIT_NVAR(&compilation);
						ZVAL_NULL(&compilation);
					}
					zephir_array_update_zval(&blocks, &blockName, &blockStatements, PH_COPY | PH_SEPARATE);
					zephir_update_property_zval(this_ptr, SL("blocks"), &blocks);
				} else {
					if (Z_TYPE_P(&blockStatements) == IS_ARRAY) {
						if (extendsMode) {
							ZVAL_BOOL(&_33$$24, 1);
						} else {
							ZVAL_BOOL(&_33$$24, 0);
						}
						ZEPHIR_CALL_METHOD(&_32$$24, this_ptr, "statementlist", &_34, 451, &blockStatements, &_33$$24);
						zephir_check_call_status();
						zephir_concat_self(&compilation, &_32$$24 TSRMLS_CC);
					}
				}
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 310)) {
				ZEPHIR_OBS_NVAR(&path);
				zephir_array_fetch_string(&path, &statement, SL("path"), PH_NOISY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2625 TSRMLS_CC);
				zephir_array_fetch_string(&_35$$25, &path, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2627 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&finalPath, this_ptr, "getfinalpath", &_36, 0, &_35$$25);
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
					ZEPHIR_CALL_METHOD(&_37$$26, &subCompiler, "getcompiledtemplatepath", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&tempCompilation);
					zephir_file_get_contents(&tempCompilation, &_37$$26 TSRMLS_CC);
				}
				if (1) {
					zephir_update_property_zval(this_ptr, SL("extended"), &__$true);
				} else {
					zephir_update_property_zval(this_ptr, SL("extended"), &__$false);
				}
				zephir_update_property_zval(this_ptr, SL("extendedBlocks"), &tempCompilation);
				ZEPHIR_CPY_WRT(&blockMode, &extended);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 313)) {
				ZEPHIR_CALL_METHOD(&_38$$27, this_ptr, "compileinclude", &_39, 0, &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_38$$27 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 314)) {
				if (extendsMode) {
					ZVAL_BOOL(&_41$$28, 1);
				} else {
					ZVAL_BOOL(&_41$$28, 0);
				}
				ZEPHIR_CALL_METHOD(&_40$$28, this_ptr, "compilecache", &_42, 0, &statement, &_41$$28);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_40$$28 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 316)) {
				ZEPHIR_CALL_METHOD(&_43$$29, this_ptr, "compiledo", &_44, 0, &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_43$$29 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 327)) {
				ZEPHIR_CALL_METHOD(&_45$$30, this_ptr, "compilereturn", &_46, 0, &statement);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_45$$30 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 317)) {
				if (extendsMode) {
					ZVAL_BOOL(&_48$$31, 1);
				} else {
					ZVAL_BOOL(&_48$$31, 0);
				}
				ZEPHIR_CALL_METHOD(&_47$$31, this_ptr, "compileautoescape", &_49, 0, &statement, &_48$$31);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_47$$31 TSRMLS_CC);
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
				ZEPHIR_CALL_METHOD(&_50$$34, this_ptr, "compileforelse", &_51, 0);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_50$$34 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 322)) {
				if (extendsMode) {
					ZVAL_BOOL(&_53$$35, 1);
				} else {
					ZVAL_BOOL(&_53$$35, 0);
				}
				ZEPHIR_CALL_METHOD(&_52$$35, this_ptr, "compilemacro", &_54, 0, &statement, &_53$$35);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_52$$35 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 325)) {
				if (extendsMode) {
					ZVAL_BOOL(&_56$$36, 1);
				} else {
					ZVAL_BOOL(&_56$$36, 0);
				}
				ZEPHIR_CALL_METHOD(&_55$$36, this_ptr, "compilecall", &_57, 0, &statement, &_56$$36);
				zephir_check_call_status();
				zephir_concat_self(&compilation, &_55$$36 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(&type, 358)) {
				break;
			}
			ZEPHIR_INIT_NVAR(&_58$$38);
			object_init_ex(&_58$$38, phalcon_mvc_view_engine_volt_exception_ce);
			zephir_array_fetch_string(&_59$$38, &statement, SL("file"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2711 TSRMLS_CC);
			zephir_array_fetch_string(&_60$$38, &statement, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2711 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_61$$38);
			ZEPHIR_CONCAT_SVSVSV(&_61$$38, "Unknown statement ", &type, " in ", &_59$$38, " on line ", &_60$$38);
			ZEPHIR_CALL_METHOD(NULL, &_58$$38, "__construct", &_7, 450, &_61$$38);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_58$$38, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2711 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&statement);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&blockMode)) {
		zephir_read_property(&level, this_ptr, SL("blockLevel"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_LONG(&level, 1)) {
			if (Z_TYPE_P(&compilation) != IS_NULL) {
				zephir_update_property_array_append(this_ptr, SL("blocks"), &compilation TSRMLS_CC);
			}
		}
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("blockLevel") TSRMLS_CC));
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("level") TSRMLS_CC));
	RETURN_CCTOR(&compilation);

}

/**
 * Compiles a block of statements
 *
 * @param array statements
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, statementListOrExtends) {

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
		zephir_is_iterable(statements, 0, "phalcon/Mvc/View/Engine/Volt/Compiler.zep", 2763);
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
	if (isStatementList) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "statementlist", NULL, 451, statements);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(statements, 1, 0);
	RETURN_MM();

}

