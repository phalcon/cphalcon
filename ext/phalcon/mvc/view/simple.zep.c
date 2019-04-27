
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "Zend/zend_closures.h"
#include "kernel/concat.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\View\Simple
 *
 * This component allows to render views without hierarchical levels
 *
 *<code>
 * use Phalcon\Mvc\View\Simple as View;
 *
 * $view = new View();
 *
 * // Render a view
 * echo $view->render(
 *     "templates/my-view",
 *     [
 *         "some" => $param,
 *     ]
 * );
 *
 * // Or with filename with extension
 * echo $view->render(
 *     "templates/my-view.volt",
 *     [
 *         "parameter" => $here,
 *     ]
 * );
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Simple) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View, Simple, phalcon, mvc_view_simple, phalcon_di_injectable_ce, phalcon_mvc_view_simple_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("activeRenderPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_view_simple_ce, SL("cache"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("cacheOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("content"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Phalcon\Mvc\View\EngineInterface[]|false
	 */
	zend_declare_property_bool(phalcon_mvc_view_simple_ce, SL("engines"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("partialsDir"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array|null
	 */
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("registeredEngines"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("viewsDir"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("viewParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_mvc_view_simple_ce->create_object = zephir_init_properties_Phalcon_Mvc_View_Simple;

	zend_class_implements(phalcon_mvc_view_simple_ce TSRMLS_CC, 1, phalcon_mvc_viewbaseinterface_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getRegisteredEngines) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "registeredEngines");

}

/**
 * Phalcon\Mvc\View\Simple constructor
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __construct) {

	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	zephir_update_property_zval(this_ptr, SL("options"), &options);
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic method to retrieve a variable passed to the view
 *
 *<code>
 * echo $this->view->products;
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __get) {

	zval *key_param = NULL, value, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_read_property(&_0, this_ptr, SL("viewParams"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&value, &_0, &key, 1 TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	RETURN_CTOR(&value);

}

/**
 * Magic method to pass variables to the views
 *
 *<code>
 * $this->view->products = $products;
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __set) {

	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_update_property_array(this_ptr, SL("viewParams"), &key, value);
	ZEPHIR_MM_RESTORE();

}

/**
 * Cache the actual view render to certain level
 *
 *<code>
 * $this->view->cache(
 *     [
 *         "key"      => "my-key",
 *         "lifetime" => 86400,
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, cache) {

	zval *options = NULL, options_sub, __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 0, 1, &options);

	if (!options) {
		options = &options_sub;
		options = &__$true;
	}


	if (Z_TYPE_P(options) == IS_ARRAY) {
		if (1) {
			zephir_update_property_zval(this_ptr, SL("cache"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("cache"), &__$false);
		}
		zephir_update_property_zval(this_ptr, SL("cacheOptions"), options);
	} else {
		if (zephir_is_true(options)) {
			if (1) {
				zephir_update_property_zval(this_ptr, SL("cache"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("cache"), &__$false);
			}
		} else {
			if (0) {
				zephir_update_property_zval(this_ptr, SL("cache"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("cache"), &__$false);
			}
		}
	}
	RETURN_THISW();

}

/**
 * Returns the path of the view that is currently rendered
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getActiveRenderPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeRenderPath");

}

/**
 * Returns the cache instance used to cache
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getCache) {

	zend_bool _1;
	zval _0, _2, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_is_true(&_0);
	if (_1) {
		ZEPHIR_OBS_VAR(&_2);
		zephir_read_property(&_2, this_ptr, SL("cache"), PH_NOISY_CC);
		_1 = Z_TYPE_P(&_2) != IS_OBJECT;
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "createcache", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("cache"), &_3$$3);
	}
	RETURN_MM_MEMBER(getThis(), "cache");

}

/**
 * Returns the cache options
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getCacheOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cacheOptions");

}

/**
 * Returns cached output from another view stage
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getContent) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "content");

}

/**
 * Returns parameters to views
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getParamsToView) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "viewParams");

}

/**
 * Returns a parameter previously set in the view
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getVar) {

	zval *key_param = NULL, value, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_read_property(&_0, this_ptr, SL("viewParams"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&value, &_0, &key, 1 TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	RETURN_CTOR(&value);

}

/**
 * Gets views directory
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getViewsDir) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "viewsDir");

}

/**
 * Renders a partial view
 *
 * <code>
 * // Show a partial inside another view
 * $this->partial("shared/footer");
 * </code>
 *
 * <code>
 * // Show a partial inside another view with parameters
 * $this->partial(
 *     "shared/footer",
 *     [
 *         "content" => $html,
 *     ]
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, partial) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *partialPath_param = NULL, *params = NULL, params_sub, __$null, viewParams, mergedParams, _2, _0$$3, _1$$3;
	zval partialPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&partialPath);
	ZVAL_UNDEF(&params_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&viewParams);
	ZVAL_UNDEF(&mergedParams);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &partialPath_param, &params);

	if (UNEXPECTED(Z_TYPE_P(partialPath_param) != IS_STRING && Z_TYPE_P(partialPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'partialPath' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(partialPath_param) == IS_STRING)) {
		zephir_get_strval(&partialPath, partialPath_param);
	} else {
		ZEPHIR_INIT_VAR(&partialPath);
		ZVAL_EMPTY_STRING(&partialPath);
	}
	if (!params) {
		params = &params_sub;
		params = &__$null;
	}


	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 354);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_read_property(&_0$$3, this_ptr, SL("viewParams"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&viewParams, &_0$$3);
		ZEPHIR_INIT_VAR(&mergedParams);
		zephir_fast_array_merge(&mergedParams, &viewParams, params TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_symbol_table(TSRMLS_C);
		
	} else {
		ZEPHIR_CPY_WRT(&mergedParams, params);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "internalrender", NULL, 483, &partialPath, &mergedParams);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_update_property_zval(this_ptr, SL("viewParams"), &viewParams);
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 153);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("content"), PH_NOISY_CC | PH_READONLY);
	zend_print_zval(&_2, 0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Register templating engines
 *
 *<code>
 * $this->view->registerEngines(
 *     [
 *         ".phtml" => "Phalcon\\Mvc\\View\\Engine\\Php",
 *         ".volt"  => "Phalcon\\Mvc\\View\\Engine\\Volt",
 *         ".mhtml" => "MyCustomEngine",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, registerEngines) {

	zval *engines_param = NULL;
	zval engines;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&engines);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &engines_param);

	ZEPHIR_OBS_COPY_OR_DUP(&engines, engines_param);


	zephir_update_property_zval(this_ptr, SL("registeredEngines"), &engines);
	ZEPHIR_MM_RESTORE();

}

/**
 * Renders a view
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, render) {

	zend_bool _5$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *path_param = NULL, *params_param = NULL, cache, key, lifetime, cacheOptions, content, viewParams, mergedParams, _2, _3, _0$$3, _1$$4, _4$$8, _6$$8;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&lifetime);
	ZVAL_UNDEF(&cacheOptions);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&viewParams);
	ZVAL_UNDEF(&mergedParams);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &params_param);

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
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}


	ZEPHIR_CALL_METHOD(&cache, this_ptr, "getcache", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&cache) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_0$$3, &cache, "isstarted", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0$$3))) {
			ZEPHIR_INIT_VAR(&key);
			ZVAL_NULL(&key);
			ZEPHIR_INIT_VAR(&lifetime);
			ZVAL_NULL(&lifetime);
			zephir_read_property(&_1$$4, this_ptr, SL("cacheOptions"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&cacheOptions, &_1$$4);
			if (Z_TYPE_P(&cacheOptions) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&key);
				zephir_array_isset_string_fetch(&key, &cacheOptions, SL("key"), 0);
				ZEPHIR_OBS_NVAR(&lifetime);
				zephir_array_isset_string_fetch(&lifetime, &cacheOptions, SL("lifetime"), 0);
			}
			if (Z_TYPE_P(&key) == IS_NULL) {
				ZEPHIR_INIT_NVAR(&key);
				zephir_md5(&key, &path);
			}
			ZEPHIR_CALL_METHOD(&content, &cache, "start", NULL, 0, &key, &lifetime);
			zephir_check_call_status();
			if (Z_TYPE_P(&content) != IS_NULL) {
				zephir_update_property_zval(this_ptr, SL("content"), &content);
				RETURN_CCTOR(&content);
			}
		}
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_symbol_table(TSRMLS_C);
	
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 354);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("viewParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&viewParams, &_3);
	ZEPHIR_INIT_VAR(&mergedParams);
	zephir_fast_array_merge(&mergedParams, &viewParams, &params TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "internalrender", NULL, 483, &path, &mergedParams);
	zephir_check_call_status();
	if (Z_TYPE_P(&cache) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_4$$8, &cache, "isstarted", NULL, 0);
		zephir_check_call_status();
		_5$$8 = zephir_is_true(&_4$$8);
		if (_5$$8) {
			ZEPHIR_CALL_METHOD(&_6$$8, &cache, "isfresh", NULL, 0);
			zephir_check_call_status();
			_5$$8 = zephir_is_true(&_6$$8);
		}
		if (_5$$8) {
			ZEPHIR_CALL_METHOD(NULL, &cache, "save", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &cache, "stop", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 153);
	zephir_check_call_status();
	RETURN_MM_MEMBER(getThis(), "content");

}

/**
 * Sets the cache options
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setCacheOptions) {

	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	zephir_update_property_zval(this_ptr, SL("cacheOptions"), &options);
	RETURN_THIS();

}

/**
 * Externally sets the view content
 *
 *<code>
 * $this->view->setContent("<h1>hello</h1>");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setContent) {

	zval *content_param = NULL;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	if (UNEXPECTED(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(&content, content_param);
	} else {
		ZEPHIR_INIT_VAR(&content);
		ZVAL_EMPTY_STRING(&content);
	}


	zephir_update_property_zval(this_ptr, SL("content"), &content);
	RETURN_THIS();

}

/**
 * Adds parameters to views (alias of setVar)
 *
 *<code>
 * $this->view->setParamToView("products", $products);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setParamToView) {

	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_update_property_array(this_ptr, SL("viewParams"), &key, value);
	RETURN_THIS();

}

/**
 * Set a single view parameter
 *
 *<code>
 * $this->view->setVar("products", $products);
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setVar) {

	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_update_property_array(this_ptr, SL("viewParams"), &key, value);
	RETURN_THIS();

}

/**
 * Set all the render params
 *
 *<code>
 * $this->view->setVars(
 *     [
 *         "products" => $products,
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setVars) {

	zend_bool merge;
	zval *params_param = NULL, *merge_param = NULL, _0$$3, _1$$3;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &params_param, &merge_param);

	ZEPHIR_OBS_COPY_OR_DUP(&params, params_param);
	if (!merge_param) {
		merge = 1;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, SL("viewParams"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$3, &_1$$3, &params TSRMLS_CC);
		ZEPHIR_CPY_WRT(&params, &_0$$3);
	}
	zephir_update_property_zval(this_ptr, SL("viewParams"), &params);
	RETURN_THIS();

}

/**
 * Sets views directory
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setViewsDir) {

	zval *viewsDir_param = NULL, _0, _1;
	zval viewsDir;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewsDir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &viewsDir_param);

	if (UNEXPECTED(Z_TYPE_P(viewsDir_param) != IS_STRING && Z_TYPE_P(viewsDir_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewsDir' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewsDir_param) == IS_STRING)) {
		zephir_get_strval(&viewsDir, viewsDir_param);
	} else {
		ZEPHIR_INIT_VAR(&viewsDir);
		ZVAL_EMPTY_STRING(&viewsDir);
	}


	ZVAL_LONG(&_0, -1);
	ZEPHIR_INIT_VAR(&_1);
	zephir_substr(&_1, &viewsDir, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	if (!ZEPHIR_IS_STRING(&_1, "/")) {
		zephir_concat_self_str(&viewsDir, "/", sizeof("/")-1 TSRMLS_CC);
	}
	zephir_update_property_zval(this_ptr, SL("viewsDir"), &viewsDir);
	ZEPHIR_MM_RESTORE();

}

/**
 * Create a Phalcon\Cache based on the internal cache options
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, createCache) {

	zval container, cacheService, cacheOptions, viewCache, _0, _5, _1$$3, _2$$3, _4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&cacheService);
	ZVAL_UNDEF(&cacheOptions);
	ZVAL_UNDEF(&viewCache);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (Z_TYPE_P(&container) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_view_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "the view cache services");
		ZEPHIR_CALL_CE_STATIC(&_2$$3, phalcon_mvc_view_exception_ce, "containerservicenotfound", &_3, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 1, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/View/Simple.zep", 478 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&cacheService);
	ZVAL_STRING(&cacheService, "viewCache");
	zephir_read_property(&_0, this_ptr, SL("cacheOptions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cacheOptions, &_0);
	if (Z_TYPE_P(&cacheOptions) == IS_ARRAY) {
		if (zephir_array_isset_string(&cacheOptions, SL("service"))) {
			ZEPHIR_OBS_NVAR(&cacheService);
			zephir_array_isset_string_fetch(&cacheService, &cacheOptions, SL("service"), 0);
		}
	}
	ZEPHIR_CALL_METHOD(&_5, &container, "getshared", NULL, 0, &cacheService);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&viewCache, &_5);
	if (Z_TYPE_P(&viewCache) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "The injected caching service is invalid", "phalcon/Mvc/View/Simple.zep", 497);
		return;
	}
	RETURN_CCTOR(&viewCache);

}

/**
 * Loads registered template engines, if none is registered it will use Phalcon\Mvc\View\Engine\Php
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, loadTemplateEngines) {

	zval _15$$11, _20$$17;
	zend_class_entry *_12$$9, *_19$$15;
	zend_string *_10$$5;
	zend_ulong _9$$5;
	zval engines, di, registeredEngines, extension, engineService, engineObject, _0, _1$$3, _2$$4, _3$$6, _4$$6, _6$$6, *_7$$5, _8$$5, _11$$9, _16$$12, _17$$12, _18$$15, _21$$18, _22$$18, _23$$19;
	zephir_fcall_cache_entry *_5 = NULL, *_13 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&registeredEngines);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&engineService);
	ZVAL_UNDEF(&engineObject);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_22$$18);
	ZVAL_UNDEF(&_23$$19);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_20$$17);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("engines"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&engines, &_0);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&engines)) {
		ZEPHIR_OBS_VAR(&di);
		zephir_read_property(&di, this_ptr, SL("container"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&engines);
		array_init(&engines);
		zephir_read_property(&_1$$3, this_ptr, SL("registeredEngines"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&registeredEngines, &_1$$3);
		if (Z_TYPE_P(&registeredEngines) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, phalcon_mvc_view_engine_php_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 469, this_ptr, &di);
			zephir_check_call_status();
			zephir_array_update_string(&engines, SL(".phtml"), &_2$$4, PH_COPY | PH_SEPARATE);
		} else {
			if (Z_TYPE_P(&di) != IS_OBJECT) {
				ZEPHIR_INIT_VAR(&_3$$6);
				object_init_ex(&_3$$6, phalcon_mvc_view_exception_ce);
				ZEPHIR_INIT_VAR(&_6$$6);
				ZVAL_STRING(&_6$$6, "the application services");
				ZEPHIR_CALL_CE_STATIC(&_4$$6, phalcon_mvc_view_exception_ce, "containerservicenotfound", &_5, 0, &_6$$6);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_3$$6, "__construct", NULL, 1, &_4$$6);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$6, "phalcon/Mvc/View/Simple.zep", 535 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_is_iterable(&registeredEngines, 0, "phalcon/Mvc/View/Simple.zep", 568);
			if (Z_TYPE_P(&registeredEngines) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&registeredEngines), _9$$5, _10$$5, _7$$5)
				{
					ZEPHIR_INIT_NVAR(&extension);
					if (_10$$5 != NULL) { 
						ZVAL_STR_COPY(&extension, _10$$5);
					} else {
						ZVAL_LONG(&extension, _9$$5);
					}
					ZEPHIR_INIT_NVAR(&engineService);
					ZVAL_COPY(&engineService, _7$$5);
					if (Z_TYPE_P(&engineService) == IS_OBJECT) {
						if (zephir_instance_of_ev(&engineService, zend_ce_closure TSRMLS_CC)) {
							_12$$9 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
							ZEPHIR_CALL_CE_STATIC(&_11$$9, _12$$9, "bind", &_13, 0, &engineService, &di);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&engineService, &_11$$9);
							ZEPHIR_CALL_FUNCTION(&engineObject, "call_user_func", &_14, 203, &engineService, this_ptr);
							zephir_check_call_status();
						} else {
							ZEPHIR_CPY_WRT(&engineObject, &engineService);
						}
					} else if (Z_TYPE_P(&engineService) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_15$$11);
						zephir_create_array(&_15$$11, 1, 0 TSRMLS_CC);
						zephir_array_fast_append(&_15$$11, this_ptr);
						ZEPHIR_CALL_METHOD(&engineObject, &di, "getshared", NULL, 0, &engineService, &_15$$11);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&_16$$12);
						object_init_ex(&_16$$12, phalcon_mvc_view_exception_ce);
						ZEPHIR_INIT_LNVAR(_17$$12);
						ZEPHIR_CONCAT_SV(&_17$$12, "Invalid template engine registration for extension: ", &extension);
						ZEPHIR_CALL_METHOD(NULL, &_16$$12, "__construct", NULL, 1, &_17$$12);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_16$$12, "phalcon/Mvc/View/Simple.zep", 563 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&engines, &extension, &engineObject, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &registeredEngines, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_8$$5, &registeredEngines, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_8$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&extension, &registeredEngines, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&engineService, &registeredEngines, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&engineService) == IS_OBJECT) {
							if (zephir_instance_of_ev(&engineService, zend_ce_closure TSRMLS_CC)) {
								_19$$15 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
								ZEPHIR_CALL_CE_STATIC(&_18$$15, _19$$15, "bind", &_13, 0, &engineService, &di);
								zephir_check_call_status();
								ZEPHIR_CPY_WRT(&engineService, &_18$$15);
								ZEPHIR_CALL_FUNCTION(&engineObject, "call_user_func", &_14, 203, &engineService, this_ptr);
								zephir_check_call_status();
							} else {
								ZEPHIR_CPY_WRT(&engineObject, &engineService);
							}
						} else if (Z_TYPE_P(&engineService) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_20$$17);
							zephir_create_array(&_20$$17, 1, 0 TSRMLS_CC);
							zephir_array_fast_append(&_20$$17, this_ptr);
							ZEPHIR_CALL_METHOD(&engineObject, &di, "getshared", NULL, 0, &engineService, &_20$$17);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(&_21$$18);
							object_init_ex(&_21$$18, phalcon_mvc_view_exception_ce);
							ZEPHIR_INIT_LNVAR(_22$$18);
							ZEPHIR_CONCAT_SV(&_22$$18, "Invalid template engine registration for extension: ", &extension);
							ZEPHIR_CALL_METHOD(NULL, &_21$$18, "__construct", NULL, 1, &_22$$18);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_21$$18, "phalcon/Mvc/View/Simple.zep", 563 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&engines, &extension, &engineObject, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &registeredEngines, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&engineService);
			ZEPHIR_INIT_NVAR(&extension);
		}
		zephir_update_property_zval(this_ptr, SL("engines"), &engines);
	} else {
		zephir_read_property(&_23$$19, this_ptr, SL("engines"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&engines, &_23$$19);
	}
	RETURN_CCTOR(&engines);

}

/**
 * Tries to render the view with every engine registered in the component
 *
 * @param array  params
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, internalRender) {

	zend_string *_7;
	zend_ulong _6;
	zend_bool notExists = 0, mustClean = 0, _11$$6, _22$$13;
	zephir_fcall_cache_entry *_15 = NULL, *_18 = NULL, *_26 = NULL, *_29 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *params, params_sub, eventsManager, engines, extension, engine, _0, _3, *_4, _5, _1$$4, _2$$4, _8$$6, _9$$6, _10$$6, _16$$6, _12$$7, _13$$10, _14$$10, _17$$12, _19$$13, _20$$13, _21$$13, _27$$13, _23$$14, _24$$17, _25$$17, _28$$19, _30$$20, _32$$21;
	zval path, viewEnginePath, viewsDirPath, _31$$20;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&viewEnginePath);
	ZVAL_UNDEF(&viewsDirPath);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&engines);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&engine);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_32$$21);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path_param, &params);

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


	zephir_read_property(&_0, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_0);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		zephir_update_property_zval(this_ptr, SL("activeRenderPath"), &path);
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "view:beforeRender");
		ZEPHIR_CALL_METHOD(&_1$$4, &eventsManager, "fire", NULL, 0, &_2$$4, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_1$$4)) {
			RETURN_MM_NULL();
		}
	}
	notExists = 1;
	mustClean = 1;
	zephir_read_property(&_0, this_ptr, SL("viewsDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &_0, &path);
	zephir_get_strval(&viewsDirPath, &_3);
	ZEPHIR_CALL_METHOD(&engines, this_ptr, "loadtemplateengines", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&engines, 0, "phalcon/Mvc/View/Simple.zep", 656);
	if (Z_TYPE_P(&engines) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&engines), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&extension);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&extension, _7);
			} else {
				ZVAL_LONG(&extension, _6);
			}
			ZEPHIR_INIT_NVAR(&engine);
			ZVAL_COPY(&engine, _4);
			ZEPHIR_INIT_LNVAR(_8$$6);
			ZEPHIR_CONCAT_VV(&_8$$6, &viewsDirPath, &extension);
			ZVAL_LONG(&_9$$6, -zephir_fast_strlen_ev(&extension));
			ZEPHIR_INIT_NVAR(&_10$$6);
			zephir_substr(&_10$$6, &viewsDirPath, zephir_get_intval(&_9$$6), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			_11$$6 = ZEPHIR_IS_EQUAL(&_10$$6, &extension);
			if (_11$$6) {
				_11$$6 = (zephir_file_exists(&viewsDirPath TSRMLS_CC) == SUCCESS);
			}
			if ((zephir_file_exists(&_8$$6 TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_INIT_LNVAR(_12$$7);
				ZEPHIR_CONCAT_VV(&_12$$7, &viewsDirPath, &extension);
				zephir_get_strval(&viewEnginePath, &_12$$7);
			} else if (_11$$6) {
				ZEPHIR_CPY_WRT(&viewEnginePath, &viewsDirPath);
			} else {
				continue;
			}
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&_14$$10);
				ZVAL_STRING(&_14$$10, "view:beforeRenderView");
				ZEPHIR_CALL_METHOD(&_13$$10, &eventsManager, "fire", &_15, 0, &_14$$10, this_ptr, &viewEnginePath);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(&_13$$10)) {
					continue;
				}
			}
			if (mustClean) {
				ZVAL_BOOL(&_16$$6, 1);
			} else {
				ZVAL_BOOL(&_16$$6, 0);
			}
			ZEPHIR_CALL_METHOD(NULL, &engine, "render", NULL, 0, &viewEnginePath, params, &_16$$6);
			zephir_check_call_status();
			notExists = 0;
			if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&_17$$12);
				ZVAL_STRING(&_17$$12, "view:afterRenderView");
				ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_18, 0, &_17$$12, this_ptr);
				zephir_check_call_status();
			}
			break;
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &engines, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &engines, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&extension, &engines, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&engine, &engines, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_19$$13);
				ZEPHIR_CONCAT_VV(&_19$$13, &viewsDirPath, &extension);
				ZVAL_LONG(&_20$$13, -zephir_fast_strlen_ev(&extension));
				ZEPHIR_INIT_NVAR(&_21$$13);
				zephir_substr(&_21$$13, &viewsDirPath, zephir_get_intval(&_20$$13), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				_22$$13 = ZEPHIR_IS_EQUAL(&_21$$13, &extension);
				if (_22$$13) {
					_22$$13 = (zephir_file_exists(&viewsDirPath TSRMLS_CC) == SUCCESS);
				}
				if ((zephir_file_exists(&_19$$13 TSRMLS_CC) == SUCCESS)) {
					ZEPHIR_INIT_LNVAR(_23$$14);
					ZEPHIR_CONCAT_VV(&_23$$14, &viewsDirPath, &extension);
					zephir_get_strval(&viewEnginePath, &_23$$14);
				} else if (_22$$13) {
					ZEPHIR_CPY_WRT(&viewEnginePath, &viewsDirPath);
				} else {
					continue;
				}
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_25$$17);
					ZVAL_STRING(&_25$$17, "view:beforeRenderView");
					ZEPHIR_CALL_METHOD(&_24$$17, &eventsManager, "fire", &_26, 0, &_25$$17, this_ptr, &viewEnginePath);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_24$$17)) {
						continue;
					}
				}
				if (mustClean) {
					ZVAL_BOOL(&_27$$13, 1);
				} else {
					ZVAL_BOOL(&_27$$13, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, &engine, "render", NULL, 0, &viewEnginePath, params, &_27$$13);
				zephir_check_call_status();
				notExists = 0;
				if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_28$$19);
					ZVAL_STRING(&_28$$19, "view:afterRenderView");
					ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", &_29, 0, &_28$$19, this_ptr);
					zephir_check_call_status();
				}
				break;
			ZEPHIR_CALL_METHOD(NULL, &engines, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&engine);
	ZEPHIR_INIT_NVAR(&extension);
	if (notExists) {
		ZEPHIR_INIT_VAR(&_30$$20);
		object_init_ex(&_30$$20, phalcon_mvc_view_exception_ce);
		ZEPHIR_INIT_VAR(&_31$$20);
		ZEPHIR_CONCAT_SVS(&_31$$20, "View '", &viewsDirPath, "' was not found in the views directory");
		ZEPHIR_CALL_METHOD(NULL, &_30$$20, "__construct", NULL, 1, &_31$$20);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_30$$20, "phalcon/Mvc/View/Simple.zep", 659 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_32$$21);
		ZVAL_STRING(&_32$$21, "view:afterRender");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_32$$21, this_ptr);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Phalcon_Mvc_View_Simple(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("viewParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("viewParams"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

