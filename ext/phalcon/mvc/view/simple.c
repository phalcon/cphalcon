
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 * Phalcon\Mvc\View\Simple
 *
 * This component allows to render views without hicherquical levels
 *
 *<code>
 * $view = new Phalcon\Mvc\View\Simple();
 * echo $view->render('templates/my-view', array('content' => $html));
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Simple) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\View, Simple, phalcon, mvc_view_simple, phalcon_di_injectable_ce, phalcon_mvc_view_simple_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_viewsDir"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_partialsDir"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_viewParams"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_view_simple_ce, SL("_engines"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_registeredEngines"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_activeRenderPath"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_content"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_view_simple_ce, SL("_cache"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_cacheOptions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\View constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __construct) {

	zval *options = NULL;

	zephir_fetch_params(0, 0, 1, &options);

	if (!options || Z_TYPE_P(options) == IS_NULL) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if ((Z_TYPE_P(options) == IS_ARRAY)) {
		zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	}

}

/**
 * Sets views directory. Depending of your platform, always add a trailing slash or backslash
 *
 * @param string viewsDir
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setViewsDir) {

	zval *viewsDir_param = NULL;
	zval *viewsDir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &viewsDir_param);

		if (Z_TYPE_P(viewsDir_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewsDir' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		viewsDir = viewsDir_param;



	zephir_update_property_this(this_ptr, SL("_viewsDir"), viewsDir TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets views directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getViewsDir) {


	RETURN_MEMBER(this_ptr, "_viewsDir");

}

/**
 * Register templating engines
 *
 *<code>
 *$this->view->registerEngines(array(
 *  ".phtml" => "Phalcon\Mvc\View\Engine\Php",
 *  ".volt" => "Phalcon\Mvc\View\Engine\Volt",
 *  ".mhtml" => "MyCustomEngine"
 *));
 *</code>
 *
 * @param array engines
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, registerEngines) {

	zval *engines;

	zephir_fetch_params(0, 1, 0, &engines);



	if ((Z_TYPE_P(engines) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, "Engines to register must be an array");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_registeredEngines"), engines TSRMLS_CC);

}

/**
 * Loads registered template engines, if none is registered it will use Phalcon\Mvc\View\Engine\Php
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, _loadTemplateEngines) {

	zend_function *_5 = NULL, *_7 = NULL;
	HashTable *_3;
	HashPosition _2;
	zend_class_entry *_1;
	zval *engines, *dependencyInjector, *registeredEngines, *arguments, *extension = NULL, *engineService = NULL, *engineObject = NULL, *_0 = NULL, **_4, *_6 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(engines);
	zephir_read_property_this(&engines, this_ptr, SL("_engines"), PH_NOISY_CC);
	ZEPHIR_INIT_BNVAR(engines);
	if (ZEPHIR_IS_FALSE(engines)) {
		dependencyInjector = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		array_init(engines);
		registeredEngines = zephir_fetch_nproperty_this(this_ptr, SL("_registeredEngines"), PH_NOISY_CC);
		if ((Z_TYPE_P(registeredEngines) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(_0);
			object_init_ex(_0, phalcon_mvc_view_engine_php_ce);
			zephir_call_method_p2_noret(_0, "__construct", this_ptr, dependencyInjector);
			zephir_array_update_string(&engines, SL(".phtml"), &_0, PH_COPY | PH_SEPARATE);
		} else {
			if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
				ZEPHIR_INIT_NVAR(_0);
				_1 = zend_fetch_class(SL("Phalcon\\_Mvc\\View\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				object_init_ex(_0, _1);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(arguments);
			array_init(arguments);
			zephir_array_fast_append(arguments, this_ptr);
			zephir_array_fast_append(arguments, dependencyInjector);
			zephir_is_iterable(registeredEngines, &_3, &_2, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
				; zend_hash_move_forward_ex(_3, &_2)
			) {
				ZEPHIR_GET_HMKEY(extension, _3, _2);
				ZEPHIR_GET_HVALUE(engineService, _4);
				if ((Z_TYPE_P(engineService) == IS_OBJECT)) {
					if (zephir_is_instance_of(engineService, SL("Closure") TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(engineObject);
						zephir_call_func_p2(engineObject, "call_user_func_array", engineService, arguments);
					} else {
						ZEPHIR_CPY_WRT(engineObject, engineService);
					}
				} else {
					if ((Z_TYPE_P(engineService) == IS_STRING)) {
						ZEPHIR_INIT_NVAR(engineObject);
						zephir_call_method_p2_cache(engineObject, dependencyInjector, "getshared", &_5, engineService, arguments);
					} else {
						ZEPHIR_INIT_NVAR(_0);
						object_init_ex(_0, phalcon_mvc_view_exception_ce);
						ZEPHIR_INIT_LNVAR(_6);
						ZEPHIR_CONCAT_SV(_6, "Invalid template engine registration for extension: ", extension);
						zephir_call_method_p1_cache_noret(_0, "__construct", &_7, _6);
						zephir_throw_exception(_0 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_array_update_zval(&engines, extension, &engineObject, PH_COPY | PH_SEPARATE);
			}
		}
		zephir_update_property_this(this_ptr, SL("_engines"), engines TSRMLS_CC);
	} else {
		zephir_read_property_this(&engines, this_ptr, SL("_engines"), PH_NOISY_CC);
	}
	RETURN_CCTOR(engines);

}

/**
 * Tries to render the view with every engine registered in the component
 *
 * @param string path
 * @param array  params
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, _internalRender) {

	zend_function *_7 = NULL, *_8 = NULL, *_9 = NULL;
	HashTable *_4;
	HashPosition _3;
	zend_bool notExists, mustClean;
	zval *path_param = NULL, *params, *eventsManager, *engines, *extension = NULL, *engine = NULL, *viewEnginePath = NULL, *viewsDirPath, *_0 = NULL, *_1 = NULL, *_2, **_5, *_6 = NULL, *_10;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path_param, &params);

		if (Z_TYPE_P(path_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		path = path_param;



	eventsManager = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		zephir_update_property_this(this_ptr, SL("_activeRenderPath"), path TSRMLS_CC);
	}
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "view:beforeRender", 1);
		zephir_call_method_p2(_0, eventsManager, "fire", _1, this_ptr);
		if (ZEPHIR_IS_FALSE(_0)) {
			RETURN_MM_NULL();
		}
	}
	notExists = 1;
	mustClean = 1;
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_viewsDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(viewsDirPath);
	ZEPHIR_CONCAT_VV(viewsDirPath, _2, path);
	ZEPHIR_INIT_VAR(engines);
	zephir_call_method(engines, this_ptr, "_loadtemplateengines");
	zephir_is_iterable(engines, &_4, &_3, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(extension, _4, _3);
		ZEPHIR_GET_HVALUE(engine, _5);
		ZEPHIR_INIT_NVAR(viewEnginePath);
		ZEPHIR_CONCAT_VV(viewEnginePath, viewsDirPath, extension);
		ZEPHIR_INIT_NVAR(_0);
		zephir_call_func_p1(_0, "file_exists", viewEnginePath);
		if (zephir_is_true(_0)) {
			if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
				ZEPHIR_INIT_NVAR(_1);
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_STRING(_6, "view:beforeRenderView", 1);
				zephir_call_method_p3_cache(_1, eventsManager, "fire", &_7, _6, this_ptr, viewEnginePath);
				if (ZEPHIR_IS_FALSE(_1)) {
					continue;
				}
			}
			zephir_call_method_p3_cache_noret(engine, "render", &_8, viewEnginePath, params, (mustClean ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
			notExists = 0;
			if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_STRING(_6, "view:afterRenderView", 1);
				zephir_call_method_p2_cache_noret(eventsManager, "fire", &_9, _6, this_ptr);
			}
			break;
		}
	}
	if ((notExists == 1)) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_mvc_view_exception_ce);
		ZEPHIR_INIT_VAR(_10);
		ZEPHIR_CONCAT_SVS(_10, "View '", viewsDirPath, "' was not found in the views directory");
		zephir_call_method_p1_noret(_0, "__construct", _10);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "view:afterRender", 1);
		zephir_call_method_p2_noret(eventsManager, "fire", _0, this_ptr);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Renders a view
 *
 * @param  string path
 * @param  array  params
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, render) {

	zval *path_param = NULL, *params = NULL, *cache, *key = NULL, *lifetime = NULL, *cacheOptions, *content, *viewParams, *mergedParams = NULL, *_0 = NULL, *_1;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &params);

		if (Z_TYPE_P(path_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		path = path_param;

	if (!params || Z_TYPE_P(params) == IS_NULL) {
		params = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(cache);
	zephir_call_method(cache, this_ptr, "getcache");
	if ((Z_TYPE_P(cache) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_method(_0, cache, "isstarted");
		if (ZEPHIR_IS_FALSE(_0)) {
			ZEPHIR_INIT_VAR(key);
			ZVAL_NULL(key);
			ZEPHIR_INIT_VAR(lifetime);
			ZVAL_NULL(lifetime);
			cacheOptions = zephir_fetch_nproperty_this(this_ptr, SL("_cacheOptions"), PH_NOISY_CC);
			if ((Z_TYPE_P(cacheOptions) == IS_ARRAY)) {
				ZEPHIR_OBS_NVAR(key);
				ZEPHIR_OBS_NVAR(lifetime);
			}
			if ((Z_TYPE_P(key) == IS_NULL)) {
				ZEPHIR_INIT_NVAR(key);
				zephir_call_func_p1(key, "md5", path);
			}
			ZEPHIR_INIT_VAR(content);
			zephir_call_method_p2(content, cache, "start", key, lifetime);
			if ((Z_TYPE_P(content) != IS_NULL)) {
				zephir_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);
				RETURN_CCTOR(content);
			}
		}
	}
	zephir_create_symbol_table(TSRMLS_C);
	
	zephir_call_func_noret("ob_start");
	viewParams = zephir_fetch_nproperty_this(this_ptr, SL("_viewParams"), PH_NOISY_CC);
	if ((Z_TYPE_P(params) == IS_ARRAY)) {
		if ((Z_TYPE_P(viewParams) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_fast_array_merge(mergedParams, &(viewParams), &(params) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, params);
		}
	} else {
		ZEPHIR_CPY_WRT(mergedParams, viewParams);
	}
	zephir_call_method_p2_noret(this_ptr, "_internalrender", path, mergedParams);
	if ((Z_TYPE_P(cache) == IS_OBJECT)) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_call_method(_0, cache, "isstarted");
		if (ZEPHIR_IS_TRUE(_0)) {
			ZEPHIR_INIT_VAR(_1);
			zephir_call_method(_1, cache, "isfresh");
			if (ZEPHIR_IS_TRUE(_1)) {
				zephir_call_method_noret(cache, "save");
			} else {
				zephir_call_method_noret(cache, "stop");
			}
		} else {
			zephir_call_method_noret(cache, "stop");
		}
	}
	zephir_call_func_noret("ob_end_clean");
	RETURN_MM_MEMBER(this_ptr, "_content");

}

/**
 * Renders a partial view
 *
 * <code>
 * 	//Show a partial inside another view
 * 	$this->partial('shared/footer');
 * </code>
 *
 * <code>
 * 	//Show a partial inside another view with parameters
 * 	$this->partial('shared/footer', array('content' => $html));
 * </code>
 *
 * @param string partialPath
 * @param array  params
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, partial) {

	zval *partialPath_param = NULL, *params = NULL, *viewParams, *mergedParams = NULL, *_0;
	zval *partialPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &partialPath_param, &params);

		if (Z_TYPE_P(partialPath_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'partialPath' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		partialPath = partialPath_param;

	if (!params || Z_TYPE_P(params) == IS_NULL) {
		params = ZEPHIR_GLOBAL(global_null);
	}


	zephir_call_func_noret("ob_start");
	if ((Z_TYPE_P(params) == IS_ARRAY)) {
		viewParams = zephir_fetch_nproperty_this(this_ptr, SL("_viewParams"), PH_NOISY_CC);
		if ((Z_TYPE_P(viewParams) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_fast_array_merge(mergedParams, &(viewParams), &(params) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, params);
		}
		zephir_create_symbol_table(TSRMLS_C);
		
	} else {
		ZEPHIR_CPY_WRT(mergedParams, params);
	}
	zephir_call_method_p2_noret(this_ptr, "_internalrender", partialPath, mergedParams);
	if ((Z_TYPE_P(params) == IS_ARRAY)) {
		zephir_update_property_this(this_ptr, SL("_viewParams"), viewParams TSRMLS_CC);
	}
	zephir_call_func_noret("ob_end_clean");
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_content"), PH_NOISY_CC);
	zend_print_zval(_0, 0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the cache options
 *
 * @param  array options
 * @return Phalcon\Mvc\View\Simple
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setCacheOptions) {

	zval *options;

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_this(this_ptr, SL("_cacheOptions"), options TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the cache options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getCacheOptions) {


	RETURN_MEMBER(this_ptr, "_cacheOptions");

}

/**
 * Create a Phalcon\Cache based on the internal cache options
 *
 * @return Phalcon\Cache\BackendInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, _createCache) {

	zval *dependencyInjector, *cacheService = NULL, *cacheOptions, *viewCache;

	ZEPHIR_MM_GROW();

	dependencyInjector = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if ((Z_TYPE_P(dependencyInjector) == IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the view cache services");
		return;
	}
	ZEPHIR_INIT_VAR(cacheService);
	ZVAL_STRING(cacheService, "viewCache", 1);
	cacheOptions = zephir_fetch_nproperty_this(this_ptr, SL("_cacheOptions"), PH_NOISY_CC);
	if ((Z_TYPE_P(cacheOptions) == IS_ARRAY)) {
		ZEPHIR_OBS_NVAR(cacheService);
	}
	ZEPHIR_INIT_VAR(viewCache);
	zephir_call_method_p1(viewCache, dependencyInjector, "getshared", cacheService);
	if ((Z_TYPE_P(viewCache) == IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "The injected caching service is invalid");
		return;
	}
	RETURN_CCTOR(viewCache);

}

/**
 * Returns the cache instance used to cache
 *
 * @return Phalcon\Cache\BackendInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getCache) {

	zval *cache;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(cache);
	zephir_read_property_this(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	if (zephir_is_true(cache)) {
		if ((Z_TYPE_P(cache) != IS_OBJECT)) {
			ZEPHIR_INIT_BNVAR(cache);
			zephir_call_method(cache, this_ptr, "_createcache");
			zephir_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
		}
	}
	RETURN_CCTOR(cache);

}

/**
 * Cache the actual view render to certain level
 *
 *<code>
 *  $this->view->cache(array('key' => 'my-key', 'lifetime' => 86400));
 *</code>
 *
 * @param boolean|array options
 * @return Phalcon\Mvc\View\Simple
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, cache) {

	zval *options = NULL;

	zephir_fetch_params(0, 0, 1, &options);

	if (!options || Z_TYPE_P(options) == IS_NULL) {
		options = ZEPHIR_GLOBAL(global_true);
	}


	if ((Z_TYPE_P(options) == IS_ARRAY)) {
		zephir_update_property_this(this_ptr, SL("_cache"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_cacheOptions"), options TSRMLS_CC);
	} else {
		if (zephir_is_true(options)) {
			zephir_update_property_this(this_ptr, SL("_cache"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_cache"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	RETURN_THISW();

}

/**
 * Adds parameters to views (alias of setVar)
 *
 *<code>
 *	$this->view->setParamToView('products', $products);
 *</code>
 *
 * @param string $key
 * @param mixed $value
 * @return Phalcon\Mvc\View\Simple
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setParamToView) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

		if (Z_TYPE_P(key_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		key = key_param;



	zephir_update_property_array(this_ptr, SL("_viewParams"), key, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Set all the render params
 *
 *<code>
 *	$this->view->setVars(array('products' => $products));
 *</code>
 *
 * @param  array params
 * @param  boolean merge
 * @return Phalcon\Mvc\View\Simple
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setVars) {

	zend_bool merge;
	zval *params, *merge_param = NULL, *viewParams, *mergedParams = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &params, &merge_param);

	if (!merge_param || Z_TYPE_P(merge_param) == IS_NULL) {
		merge = 1;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if ((Z_TYPE_P(params) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "The render parameters must be an array");
		return;
	}
	if (merge) {
		viewParams = zephir_fetch_nproperty_this(this_ptr, SL("_viewParams"), PH_NOISY_CC);
		if ((Z_TYPE_P(viewParams) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_fast_array_merge(mergedParams, &(viewParams), &(params) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, params);
		}
		zephir_update_property_this(this_ptr, SL("_viewParams"), mergedParams TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_viewParams"), params TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Set a single view parameter
 *
 *<code>
 *	$this->view->setVar('products', $products);
 *</code>
 *
 * @param string key
 * @param mixed  value
 * @return Phalcon\Mvc\View\Simple
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setVar) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

		if (Z_TYPE_P(key_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		key = key_param;



	zephir_update_property_array(this_ptr, SL("_viewParams"), key, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns a parameter previously set in the view
 *
 * @param string key
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getVar) {

	zval *key_param = NULL, *value, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

		if (Z_TYPE_P(key_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		key = key_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_viewParams"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETURN_MM_NULL();

}

/**
 * Returns parameters to views
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getParamsToView) {


	RETURN_MEMBER(this_ptr, "_viewParams");

}

/**
 * Externally sets the view content
 *
 *<code>
 *	$this->view->setContent("<h1>hello</h1>");
 *</code>
 *
 * @param  string content
 * @return Phalcon\Mvc\View\Simple
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setContent) {

	zval *content_param = NULL;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

		if (Z_TYPE_P(content_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		content = content_param;



	zephir_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns cached ouput from another view stage
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getContent) {


	RETURN_MEMBER(this_ptr, "_content");

}

/**
 * Returns the path of the view that is currently rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getActiveRenderPath) {


	RETURN_MEMBER(this_ptr, "_activeRenderPath");

}

/**
 * Magic method to pass variables to the views
 *
 *<code>
 *	$this->view->products = $products;
 *</code>
 *
 * @param string key
 * @param mixed  value
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __set) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

		if (Z_TYPE_P(key_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		key = key_param;



	zephir_update_property_array(this_ptr, SL("_viewParams"), key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic method to retrieve a variable passed to the view
 *
 *<code>
 *	echo $this->view->products;
 *</code>
 *
 * @param string key
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __get) {

	zval *key_param = NULL, *value, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

		if (Z_TYPE_P(key_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		key = key_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_viewParams"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETURN_MM_NULL();

}

