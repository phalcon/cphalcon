
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
#include "Zend/zend_closures.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/string.h"


/**
 * Phalcon\Mvc\View\Simple
 *
 * This component allows to render views without hierarchical levels
 *
 *<code>
 * $view = new \Phalcon\Mvc\View\Simple();
 * echo $view->render('templates/my-view', array('content' => $html));
 * //or with filename with extension
 * echo $view->render('templates/my-view.volt', array('content' => $html));
 *</code>
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

	zend_class_implements(phalcon_mvc_view_simple_ce TSRMLS_CC, 1, phalcon_mvc_viewbaseinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Mvc_View_Simple, getRegisteredEngines) {


	RETURN_MEMBER(this_ptr, "_registeredEngines");

}

/**
 * Phalcon\Mvc\View\Simple constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __construct) {

	zval *options = NULL;

	zephir_fetch_params(0, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(options) == IS_ARRAY) {
		zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	}

}

/**
 * Sets views directory. Depending of your platform, always add a trailing slash or backslash
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setViewsDir) {

	zval *viewsDir_param = NULL;
	zval *viewsDir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &viewsDir_param);

	if (unlikely(Z_TYPE_P(viewsDir_param) != IS_STRING && Z_TYPE_P(viewsDir_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewsDir' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(viewsDir_param) == IS_STRING)) {
		zephir_get_strval(viewsDir, viewsDir_param);
	} else {
		ZEPHIR_INIT_VAR(viewsDir);
		ZVAL_EMPTY_STRING(viewsDir);
	}


	zephir_update_property_this(this_ptr, SL("_viewsDir"), viewsDir TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets views directory
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
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, registerEngines) {

	zval *engines_param = NULL;
	zval *engines = NULL;

	zephir_fetch_params(0, 1, 0, &engines_param);

	engines = engines_param;



	zephir_update_property_this(this_ptr, SL("_registeredEngines"), engines TSRMLS_CC);

}

/**
 * Loads registered template engines, if none is registered it will use Phalcon\Mvc\View\Engine\Php
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, _loadTemplateEngines) {

	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *engines = NULL, *dependencyInjector, *registeredEngines, *arguments, *extension = NULL, *engineService = NULL, *engineObject = NULL, *_0 = NULL, **_3, *_5 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(engines);
	zephir_read_property_this(&engines, this_ptr, SL("_engines"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(engines)) {
		ZEPHIR_OBS_VAR(dependencyInjector);
		zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(engines);
		array_init(engines);
		ZEPHIR_OBS_VAR(registeredEngines);
		zephir_read_property_this(&registeredEngines, this_ptr, SL("_registeredEngines"), PH_NOISY_CC);
		if (Z_TYPE_P(registeredEngines) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(_0);
			object_init_ex(_0, phalcon_mvc_view_engine_php_ce);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 359, this_ptr, dependencyInjector);
			zephir_check_call_status();
			zephir_array_update_string(&engines, SL(".phtml"), &_0, PH_COPY | PH_SEPARATE);
		} else {
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the application services", "phalcon/mvc/view/simple.zep", 139);
				return;
			}
			ZEPHIR_INIT_VAR(arguments);
			zephir_create_array(arguments, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(arguments, this_ptr);
			zephir_array_fast_append(arguments, dependencyInjector);
			zephir_is_iterable(registeredEngines, &_2, &_1, 0, 0, "phalcon/mvc/view/simple.zep", 171);
			for (
			  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			  ; zephir_hash_move_forward_ex(_2, &_1)
			) {
				ZEPHIR_GET_HMKEY(extension, _2, _1);
				ZEPHIR_GET_HVALUE(engineService, _3);
				if (Z_TYPE_P(engineService) == IS_OBJECT) {
					if (zephir_instance_of_ev(engineService, zend_ce_closure TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(engineObject);
						ZEPHIR_CALL_USER_FUNC_ARRAY(engineObject, engineService, arguments);
						zephir_check_call_status();
					} else {
						ZEPHIR_CPY_WRT(engineObject, engineService);
					}
				} else {
					if (Z_TYPE_P(engineService) == IS_STRING) {
						ZEPHIR_CALL_METHOD(&engineObject, dependencyInjector, "getshared", &_4, 0, engineService, arguments);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(_0);
						object_init_ex(_0, phalcon_mvc_view_exception_ce);
						ZEPHIR_INIT_LNVAR(_5);
						ZEPHIR_CONCAT_SV(_5, "Invalid template engine registration for extension: ", extension);
						ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_6, 2, _5);
						zephir_check_call_status();
						zephir_throw_exception_debug(_0, "phalcon/mvc/view/simple.zep", 165 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_array_update_zval(&engines, extension, &engineObject, PH_COPY | PH_SEPARATE);
			}
		}
		zephir_update_property_this(this_ptr, SL("_engines"), engines TSRMLS_CC);
	} else {
		ZEPHIR_OBS_NVAR(engines);
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

	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL;
	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool notExists, mustClean, _7, _9;
	zval *path_param = NULL, *params, *eventsManager, *engines = NULL, *extension = NULL, *engine = NULL, *viewEnginePath = NULL, *viewsDirPath, *_0 = NULL, *_1 = NULL, *_2, **_5, *_6 = NULL, _8 = zval_used_for_init, *_10 = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path_param, &params);

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


	ZEPHIR_OBS_VAR(eventsManager);
	zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		zephir_update_property_this(this_ptr, SL("_activeRenderPath"), path TSRMLS_CC);
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "view:beforeRender", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_0, eventsManager, "fire", NULL, 0, _1, this_ptr);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
			RETURN_MM_NULL();
		}
	}
	notExists = 1;
	mustClean = 1;
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_viewsDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(viewsDirPath);
	ZEPHIR_CONCAT_VV(viewsDirPath, _2, path);
	ZEPHIR_CALL_METHOD(&engines, this_ptr, "_loadtemplateengines", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(engines, &_4, &_3, 0, 0, "phalcon/mvc/view/simple.zep", 261);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(extension, _4, _3);
		ZEPHIR_GET_HVALUE(engine, _5);
		ZEPHIR_INIT_LNVAR(_6);
		ZEPHIR_CONCAT_VV(_6, viewsDirPath, extension);
		if ((zephir_file_exists(_6 TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_INIT_NVAR(viewEnginePath);
			ZEPHIR_CONCAT_VV(viewEnginePath, viewsDirPath, extension);
		} else {
			_7 = zephir_is_true(extension);
			if (_7) {
				ZEPHIR_SINIT_NVAR(_8);
				ZVAL_LONG(&_8, -zephir_fast_strlen_ev(extension));
				ZEPHIR_INIT_NVAR(_1);
				zephir_substr(_1, viewsDirPath, zephir_get_intval(&_8), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				_7 = ZEPHIR_IS_EQUAL(_1, extension);
			}
			_9 = _7;
			if (_9) {
				_9 = (zephir_file_exists(viewsDirPath TSRMLS_CC) == SUCCESS);
			}
			if (_9) {
				ZEPHIR_CPY_WRT(viewEnginePath, viewsDirPath);
			} else {
				ZEPHIR_INIT_NVAR(viewEnginePath);
				ZVAL_STRING(viewEnginePath, "", 1);
			}
		}
		if (zephir_is_true(viewEnginePath)) {
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(_10);
				ZVAL_STRING(_10, "view:beforeRenderView", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_0, eventsManager, "fire", &_11, 0, _10, this_ptr, viewEnginePath);
				zephir_check_temp_parameter(_10);
				zephir_check_call_status();
				if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
					continue;
				}
			}
			ZEPHIR_CALL_METHOD(NULL, engine, "render", NULL, 0, viewEnginePath, params, (mustClean ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
			zephir_check_call_status();
			notExists = 0;
			if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(_10);
				ZVAL_STRING(_10, "view:afterRenderView", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", &_12, 0, _10, this_ptr);
				zephir_check_temp_parameter(_10);
				zephir_check_call_status();
			}
			break;
		}
	}
	if (notExists == 1) {
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, phalcon_mvc_view_exception_ce);
		ZEPHIR_INIT_LNVAR(_6);
		ZEPHIR_CONCAT_SVS(_6, "View '", viewsDirPath, "' was not found in the views directory");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/mvc/view/simple.zep", 262 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "view:afterRender", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _1, this_ptr);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *params = NULL, *cache = NULL, *key = NULL, *lifetime = NULL, *cacheOptions, *content = NULL, *viewParams, *mergedParams = NULL, *_0 = NULL, *_1, *_2 = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &params);

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
	if (!params) {
		params = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&cache, this_ptr, "getcache", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(cache) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_0, cache, "isstarted", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
			ZEPHIR_INIT_VAR(key);
			ZVAL_NULL(key);
			ZEPHIR_INIT_VAR(lifetime);
			ZVAL_NULL(lifetime);
			ZEPHIR_OBS_VAR(cacheOptions);
			zephir_read_property_this(&cacheOptions, this_ptr, SL("_cacheOptions"), PH_NOISY_CC);
			if (Z_TYPE_P(cacheOptions) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(key);
				zephir_array_isset_string_fetch(&key, cacheOptions, SS("key"), 0 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(lifetime);
				zephir_array_isset_string_fetch(&lifetime, cacheOptions, SS("lifetime"), 0 TSRMLS_CC);
			}
			if (Z_TYPE_P(key) == IS_NULL) {
				ZEPHIR_INIT_NVAR(key);
				zephir_md5(key, path);
			}
			ZEPHIR_CALL_METHOD(&content, cache, "start", NULL, 0, key, lifetime);
			zephir_check_call_status();
			if (Z_TYPE_P(content) != IS_NULL) {
				zephir_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);
				RETURN_CCTOR(content);
			}
		}
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_create_symbol_table(TSRMLS_C);
	
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 49);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(viewParams);
	zephir_read_property_this(&viewParams, this_ptr, SL("_viewParams"), PH_NOISY_CC);
	if (Z_TYPE_P(params) == IS_ARRAY) {
		if (Z_TYPE_P(viewParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_fast_array_merge(mergedParams, &(viewParams), &(params) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, params);
		}
	} else {
		ZEPHIR_CPY_WRT(mergedParams, viewParams);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_internalrender", NULL, 377, path, mergedParams);
	zephir_check_call_status();
	if (Z_TYPE_P(cache) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_0, cache, "isstarted", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(_0)) {
			ZEPHIR_CALL_METHOD(&_2, cache, "isfresh", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(_2)) {
				ZEPHIR_CALL_METHOD(NULL, cache, "save", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(NULL, cache, "stop", NULL, 0);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CALL_METHOD(NULL, cache, "stop", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 51);
	zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *partialPath_param = NULL, *params = NULL, *viewParams, *mergedParams = NULL, *_0, *_1;
	zval *partialPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &partialPath_param, &params);

	if (unlikely(Z_TYPE_P(partialPath_param) != IS_STRING && Z_TYPE_P(partialPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'partialPath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(partialPath_param) == IS_STRING)) {
		zephir_get_strval(partialPath, partialPath_param);
	} else {
		ZEPHIR_INIT_VAR(partialPath);
		ZVAL_EMPTY_STRING(partialPath);
	}
	if (!params) {
		params = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 49);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(viewParams);
		zephir_read_property_this(&viewParams, this_ptr, SL("_viewParams"), PH_NOISY_CC);
		if (Z_TYPE_P(viewParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(mergedParams);
			zephir_fast_array_merge(mergedParams, &(viewParams), &(params) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(mergedParams, params);
		}
		ZEPHIR_INIT_VAR(_0);
		zephir_create_symbol_table(TSRMLS_C);
		
	} else {
		ZEPHIR_CPY_WRT(mergedParams, params);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_internalrender", NULL, 377, partialPath, mergedParams);
	zephir_check_call_status();
	if (Z_TYPE_P(params) == IS_ARRAY) {
		zephir_update_property_this(this_ptr, SL("_viewParams"), viewParams TSRMLS_CC);
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 51);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_content"), PH_NOISY_CC);
	zend_print_zval(_1, 0);
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
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, _createCache) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dependencyInjector, *cacheService = NULL, *cacheOptions, *viewCache = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the view cache services", "phalcon/mvc/view/simple.zep", 478);
		return;
	}
	ZEPHIR_INIT_VAR(cacheService);
	ZVAL_STRING(cacheService, "viewCache", 1);
	ZEPHIR_OBS_VAR(cacheOptions);
	zephir_read_property_this(&cacheOptions, this_ptr, SL("_cacheOptions"), PH_NOISY_CC);
	if (Z_TYPE_P(cacheOptions) == IS_ARRAY) {
		if (zephir_array_isset_string(cacheOptions, SS("service"))) {
			ZEPHIR_OBS_NVAR(cacheService);
			zephir_array_isset_string_fetch(&cacheService, cacheOptions, SS("service"), 0 TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(&_0, dependencyInjector, "getshared", NULL, 0, cacheService);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(viewCache, _0);
	if (Z_TYPE_P(viewCache) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_view_exception_ce, "The injected caching service is invalid", "phalcon/mvc/view/simple.zep", 495);
		return;
	}
	RETURN_CCTOR(viewCache);

}

/**
 * Returns the cache instance used to cache
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getCache) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cache = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(cache);
	zephir_read_property_this(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	if (zephir_is_true(cache)) {
		if (Z_TYPE_P(cache) != IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&cache, this_ptr, "_createcache", NULL, 0);
			zephir_check_call_status();
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
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, cache) {

	zval *options = NULL;

	zephir_fetch_params(0, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_true);
	}


	if (Z_TYPE_P(options) == IS_ARRAY) {
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
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setParamToView) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	zephir_update_property_array(this_ptr, SL("_viewParams"), key, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Set all the render params
 *
 *<code>
 *	$this->view->setVars(array('products' => $products));
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setVars) {

	zend_bool merge;
	zval *params_param = NULL, *merge_param = NULL, *viewParams, *mergedParams = NULL;
	zval *params = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &params_param, &merge_param);

	params = params_param;

	if (!merge_param) {
		merge = 1;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_OBS_VAR(viewParams);
		zephir_read_property_this(&viewParams, this_ptr, SL("_viewParams"), PH_NOISY_CC);
		if (Z_TYPE_P(viewParams) == IS_ARRAY) {
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
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setVar) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


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

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


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
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setContent) {

	zval *content_param = NULL;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	if (unlikely(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(content, content_param);
	} else {
		ZEPHIR_INIT_VAR(content);
		ZVAL_EMPTY_STRING(content);
	}


	zephir_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns cached output from another view stage
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
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __set) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


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

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_viewParams"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETURN_MM_NULL();

}

