
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "phalcon/mvc/view/engine/markdown/markdown.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "Zend/zend_closures.h"

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Markdown_Compiler) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\View\\Engine\\Markdown, Compiler, phalcon, mvc_view_engine_markdown_compiler, phalcon_mvc_view_engine_markdown_compiler_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_view_engine_markdown_compiler_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_markdown_compiler_ce, SL("_view"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_markdown_compiler_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_markdown_compiler_ce, SL("_currentPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_markdown_compiler_ce, SL("_compiledTemplatePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_mvc_view_engine_markdown_compiler_ce, SL("_compilation"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_mvc_view_engine_markdown_compiler_ce, SL("_toc"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_mvc_view_engine_markdown_compiler_ce, SL("_meta"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_engine_markdown_compiler_ce, SL("_defaultCompileOption"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_view_engine_markdown_compiler_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\View\Engine\Markdown\Compiler
 *
 * @param Phalcon\Mvc\ViewInterface view
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, __construct) {

	zval *_0, *_2;
	zval *view = NULL, *_1 = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &view);

	if (!view) {
		view = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 7, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "tables", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "fenced-code", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "autolink", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "strikethrough", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "no-intra-emphasis", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "task", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "script-tags", 1);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_this(this_ptr, SL("_defaultCompileOption"), _0 TSRMLS_CC);
	if (Z_TYPE_P(view) == IS_OBJECT) {
		zephir_update_property_this(this_ptr, SL("_view"), view TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_this(&_3, this_ptr, SL("_defaultCompileOption"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("compileOption"), &_3, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("_options"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_mvc_view_exception_ce, "Dependency Injector is invalid", "phalcon/mvc/view/engine/markdown/compiler.zep", 86);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets the compiler options
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, setOptions) {

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
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, setOption) {

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
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, getOption) {

	zval *option_param = NULL, *value, *_0;
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
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, getOptions) {


	RETURN_MEMBER(this_ptr, "_options");

}

/**
 * Compiles a Markdown source code returning a PHP plain version
 *
 * @param string  viewCode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, _compileSource) {

	zval *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0, _2, _4;
	zval *viewCode_param = NULL, *intermediate, *options, *code = NULL, *compileOption = NULL, *compileRender = NULL, *afterCompile = NULL, *_1, *_3, *_5, *_6;
	zval *viewCode = NULL, *_8 = NULL;

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


	ZEPHIR_OBS_VAR(compileOption);
	zephir_read_property_this(&compileOption, this_ptr, SL("_defaultCompileOption"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(compileRender);
	array_init(compileRender);
	ZEPHIR_INIT_VAR(afterCompile);
	ZVAL_NULL(afterCompile);
	ZEPHIR_OBS_VAR(options);
	zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(options) == IS_ARRAY) {
		_0 = zephir_array_isset_string(options, SS("compileOption"));
		if (_0) {
			ZEPHIR_OBS_VAR(_1);
			zephir_array_fetch_string(&_1, options, SL("compileOption"), PH_NOISY, "phalcon/mvc/view/engine/markdown/compiler.zep", 164 TSRMLS_CC);
			_0 = Z_TYPE_P(_1) == IS_ARRAY;
		}
		if (_0) {
			ZEPHIR_OBS_NVAR(compileOption);
			zephir_array_fetch_string(&compileOption, options, SL("compileOption"), PH_NOISY, "phalcon/mvc/view/engine/markdown/compiler.zep", 165 TSRMLS_CC);
		}
		_2 = zephir_array_isset_string(options, SS("compileRender"));
		if (_2) {
			ZEPHIR_OBS_VAR(_3);
			zephir_array_fetch_string(&_3, options, SL("compileRender"), PH_NOISY, "phalcon/mvc/view/engine/markdown/compiler.zep", 168 TSRMLS_CC);
			_2 = Z_TYPE_P(_3) == IS_ARRAY;
		}
		if (_2) {
			ZEPHIR_OBS_NVAR(compileRender);
			zephir_array_fetch_string(&compileRender, options, SL("compileRender"), PH_NOISY, "phalcon/mvc/view/engine/markdown/compiler.zep", 169 TSRMLS_CC);
		}
		_4 = zephir_array_isset_string(options, SS("beforeCompile"));
		if (_4) {
			zephir_array_fetch_string(&_5, options, SL("beforeCompile"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/markdown/compiler.zep", 172 TSRMLS_CC);
			_4 = zephir_is_callable(_5 TSRMLS_CC);
		}
		if (_4) {
			ZEPHIR_INIT_VAR(code);
			zephir_array_fetch_string(&_6, options, SL("beforeCompile"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/markdown/compiler.zep", 174 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_7);
			zephir_create_array(_7, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_7, viewCode);
			ZEPHIR_CALL_USER_FUNC_ARRAY(code, _6, _7);
			zephir_check_call_status();
			zephir_get_strval(_8, code);
			ZEPHIR_CPY_WRT(viewCode, _8);
		}
		if (zephir_array_isset_string(options, SS("afterCompile"))) {
			ZEPHIR_OBS_NVAR(afterCompile);
			zephir_array_fetch_string(&afterCompile, options, SL("afterCompile"), PH_NOISY, "phalcon/mvc/view/engine/markdown/compiler.zep", 180 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_VAR(intermediate);
	if (phmarkdown_parse_view(intermediate, viewCode, compileOption, compileRender TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	if (Z_TYPE_P(intermediate) == IS_ARRAY) {
		if (zephir_array_isset_string(intermediate, SS("result"))) {
			zephir_array_fetch_string(&_5, intermediate, SL("result"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/markdown/compiler.zep", 189 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_compilation"), _5 TSRMLS_CC);
		}
		if (zephir_array_isset_string(intermediate, SS("toc"))) {
			zephir_array_fetch_string(&_6, intermediate, SL("toc"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/markdown/compiler.zep", 193 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_toc"), _6 TSRMLS_CC);
		}
		if (zephir_array_isset_string(intermediate, SS("meta"))) {
			zephir_array_fetch_string(&_6, intermediate, SL("meta"), PH_NOISY | PH_READONLY, "phalcon/mvc/view/engine/markdown/compiler.zep", 197 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("_meta"), _6 TSRMLS_CC);
		}
		if (zephir_is_callable(afterCompile TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(code);
			ZEPHIR_INIT_NVAR(_7);
			zephir_create_array(_7, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_7, this_ptr);
			ZEPHIR_CALL_USER_FUNC_ARRAY(code, afterCompile, _7);
			zephir_check_call_status();
			if (Z_TYPE_P(code) != IS_NULL) {
				zephir_update_property_this(this_ptr, SL("_compilation"), code TSRMLS_CC);
			}
		}
		RETURN_MM_MEMBER(this_ptr, "_compilation");
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "Invalid intermediate representation", "phalcon/mvc/view/engine/markdown/compiler.zep", 210);
	return;

}

/**
 * Compiles a template into a string
 *
 *<code>
 *  echo $compiler->compileString('hello world');
 *</code>
 *
 * @param  string  viewCode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, compileString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *viewCode_param = NULL, *_0;
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


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "eval code", 1);
	zephir_update_property_this(this_ptr, SL("_currentPath"), _0 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_compilesource", NULL, viewCode);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Compiles a template into a file forcing the destination path
 *
 *<code>
 *  $compiler->compile('views/layouts/main.md', 'views/layouts/main.markdown.php');
 *</code>
 *
 * @param string path
 * @param string compiledPath
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, compileFile) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *compiledPath_param = NULL, *viewCode, *compilation = NULL, *_0 = NULL;
	zval *path = NULL, *compiledPath = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path_param, &compiledPath_param);

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


	if (ZEPHIR_IS_EQUAL(path, compiledPath)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "Template path and compilation template path cannot be the same", "phalcon/mvc/view/engine/markdown/compiler.zep", 245);
		return;
	}
	if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_mvc_view_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "Template file ", path, " does not exist");
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_2, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalcon/mvc/view/engine/markdown/compiler.zep", 252 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(viewCode);
	zephir_file_get_contents(viewCode, path TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(viewCode)) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_mvc_view_exception_ce);
		ZEPHIR_INIT_LNVAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "Template file ", path, " could not be opened");
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_2, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalcon/mvc/view/engine/markdown/compiler.zep", 260 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("_currentPath"), path TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&compilation, this_ptr, "_compilesource", NULL, viewCode);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	zephir_file_put_contents(_0, compiledPath, compilation TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "Markdown directory can't be written", "phalcon/mvc/view/engine/markdown/compiler.zep", 270);
		return;
	}
	RETURN_CCTOR(compilation);

}

/**
 * Compiles a template into a file applying the compiler options
 * This method does not return the compiled path if the template was not compiled
 *
 *<code>
 *  $compiler->compile('views/layouts/main.md');
 *  require $compiler->getCompiledTemplatePath();
 *</code>
 *
 * @param string templatePath
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, compile) {

	zephir_fcall_cache_entry *_3 = NULL;
	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_6 = NULL;
	zval *templatePath_param = NULL, *stat = NULL, *compileAlways = NULL, *prefix = NULL, *compiledPath = NULL, *compiledSeparator = NULL, *compiledExtension = NULL, *compilation = NULL, *options, *realCompiledPath = NULL, *compiledTemplatePath = NULL, *templateSepPath = NULL, *_0 = NULL, *_4 = NULL, *_5;
	zval *templatePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &templatePath_param);

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
			zephir_array_fetch_string(&compileAlways, options, SL("compileAlways"), PH_NOISY, "phalcon/mvc/view/engine/markdown/compiler.zep", 312 TSRMLS_CC);
			if (Z_TYPE_P(compileAlways) != IS_BOOL) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "compileAlways must be a bool value", "phalcon/mvc/view/engine/markdown/compiler.zep", 314);
				return;
			}
		}
		if (zephir_array_isset_string(options, SS("prefix"))) {
			ZEPHIR_OBS_NVAR(prefix);
			zephir_array_fetch_string(&prefix, options, SL("prefix"), PH_NOISY, "phalcon/mvc/view/engine/markdown/compiler.zep", 322 TSRMLS_CC);
			if (Z_TYPE_P(prefix) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "prefix must be a string", "phalcon/mvc/view/engine/markdown/compiler.zep", 324);
				return;
			}
		}
		if (zephir_array_isset_string(options, SS("compiledPath"))) {
			ZEPHIR_OBS_NVAR(compiledPath);
			zephir_array_fetch_string(&compiledPath, options, SL("compiledPath"), PH_NOISY, "phalcon/mvc/view/engine/markdown/compiler.zep", 332 TSRMLS_CC);
			if (Z_TYPE_P(compiledPath) != IS_STRING) {
				if (Z_TYPE_P(compiledPath) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "compiledPath must be a string or a closure", "phalcon/mvc/view/engine/markdown/compiler.zep", 335);
					return;
				}
			}
		}
		if (zephir_array_isset_string(options, SS("compiledSeparator"))) {
			ZEPHIR_OBS_NVAR(compiledSeparator);
			zephir_array_fetch_string(&compiledSeparator, options, SL("compiledSeparator"), PH_NOISY, "phalcon/mvc/view/engine/markdown/compiler.zep", 344 TSRMLS_CC);
			if (Z_TYPE_P(compiledSeparator) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "compiledSeparator must be a string", "phalcon/mvc/view/engine/markdown/compiler.zep", 346);
				return;
			}
		}
		if (zephir_array_isset_string(options, SS("compiledExtension"))) {
			ZEPHIR_OBS_NVAR(compiledExtension);
			zephir_array_fetch_string(&compiledExtension, options, SL("compiledExtension"), PH_NOISY, "phalcon/mvc/view/engine/markdown/compiler.zep", 354 TSRMLS_CC);
			if (Z_TYPE_P(compiledExtension) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "compiledExtension must be a string", "phalcon/mvc/view/engine/markdown/compiler.zep", 356);
				return;
			}
		}
		if (zephir_array_isset_string(options, SS("stat"))) {
			ZEPHIR_OBS_NVAR(stat);
			zephir_array_fetch_string(&stat, options, SL("stat"), PH_NOISY, "phalcon/mvc/view/engine/markdown/compiler.zep", 364 TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(compiledPath) == IS_STRING) {
		if (!(ZEPHIR_IS_EMPTY(compiledPath))) {
			ZEPHIR_INIT_VAR(templateSepPath);
			ZEPHIR_CALL_FUNCTION(&_0, "realpath", &_1, templatePath);
			zephir_check_call_status();
			zephir_prepare_virtual_path(templateSepPath, _0, compiledSeparator TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(templateSepPath, templatePath);
		}
		ZEPHIR_INIT_VAR(compiledTemplatePath);
		ZEPHIR_CONCAT_VVVV(compiledTemplatePath, compiledPath, prefix, templateSepPath, compiledExtension);
	} else {
		if (Z_TYPE_P(compiledPath) == IS_OBJECT) {
			if (zephir_instance_of_ev(compiledPath, zend_ce_closure TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(compiledTemplatePath);
				ZEPHIR_INIT_VAR(_2);
				zephir_create_array(_2, 2, 0 TSRMLS_CC);
				zephir_array_fast_append(_2, templatePath);
				zephir_array_fast_append(_2, options);
				ZEPHIR_CALL_USER_FUNC_ARRAY(compiledTemplatePath, compiledPath, _2);
				zephir_check_call_status();
				if (Z_TYPE_P(compiledTemplatePath) != IS_STRING) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "compiledPath closure didn't return a valid string", "phalcon/mvc/view/engine/markdown/compiler.zep", 405);
					return;
				}
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "compiledPath must be a string or a closure", "phalcon/mvc/view/engine/markdown/compiler.zep", 408);
				return;
			}
		}
	}
	ZEPHIR_CPY_WRT(realCompiledPath, compiledTemplatePath);
	if (zephir_is_true(compileAlways)) {
		ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilefile", &_3, templatePath, realCompiledPath);
		zephir_check_call_status();
	} else {
		if (ZEPHIR_IS_TRUE_IDENTICAL(stat)) {
			if ((zephir_file_exists(compiledTemplatePath TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_INIT_VAR(_4);
				if (zephir_compare_mtime(templatePath, realCompiledPath TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilefile", &_3, templatePath, realCompiledPath);
					zephir_check_call_status();
				}
			} else {
				ZEPHIR_CALL_METHOD(&compilation, this_ptr, "compilefile", &_3, templatePath, realCompiledPath);
				zephir_check_call_status();
			}
		} else {
			if (!((zephir_file_exists(realCompiledPath TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_INIT_NVAR(_4);
				object_init_ex(_4, phalcon_mvc_view_exception_ce);
				ZEPHIR_INIT_VAR(_5);
				ZEPHIR_CONCAT_SVS(_5, "Compiled template file ", realCompiledPath, " does not exist");
				ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_6, _5);
				zephir_check_call_status();
				zephir_throw_exception_debug(_4, "phalcon/mvc/view/engine/markdown/compiler.zep", 447 TSRMLS_CC);
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
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, getTemplatePath) {


	RETURN_MEMBER(this_ptr, "_currentPath");

}

/**
 * Returns the path to the last compiled template
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, getCompiledTemplatePath) {


	RETURN_MEMBER(this_ptr, "_compiledTemplatePath");

}

/**
 * Parses a Markdown template returning its intermediate representation
 *
 *<code>
 *  print_r($compiler->parse('# example'));
 *</code>
 *
 * @param string viewCode
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, parse) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *viewCode_param = NULL;
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


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "compilestring", NULL, viewCode);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the compiled content to the last compiled template
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, getCompiled) {


	RETURN_MEMBER(this_ptr, "_compilation");

}

/**
 * Returns the toc content to the last compiled template
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, getToc) {


	RETURN_MEMBER(this_ptr, "_toc");

}

/**
 * Returns the meta content to the last compiled template
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Markdown_Compiler, getMeta) {


	RETURN_MEMBER(this_ptr, "_meta");

}

