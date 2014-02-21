
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

#include "mvc/view/simple.h"
#include "mvc/view/exception.h"
#include "mvc/view/engineinterface.h"
#include "mvc/view/engine/php.h"
#include "cache/backendinterface.h"
#include "di/injectable.h"

#include <Zend/zend_closures.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/string.h"
#include "kernel/output.h"

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
zend_class_entry *phalcon_mvc_view_simple_ce;

PHP_METHOD(Phalcon_Mvc_View_Simple, __construct);
PHP_METHOD(Phalcon_Mvc_View_Simple, setViewsDir);
PHP_METHOD(Phalcon_Mvc_View_Simple, getViewsDir);
PHP_METHOD(Phalcon_Mvc_View_Simple, registerEngines);
PHP_METHOD(Phalcon_Mvc_View_Simple, getRegisteredEngines);
PHP_METHOD(Phalcon_Mvc_View_Simple, _loadTemplateEngines);
PHP_METHOD(Phalcon_Mvc_View_Simple, _internalRender);
PHP_METHOD(Phalcon_Mvc_View_Simple, render);
PHP_METHOD(Phalcon_Mvc_View_Simple, partial);
PHP_METHOD(Phalcon_Mvc_View_Simple, setCacheOptions);
PHP_METHOD(Phalcon_Mvc_View_Simple, getCacheOptions);
PHP_METHOD(Phalcon_Mvc_View_Simple, _createCache);
PHP_METHOD(Phalcon_Mvc_View_Simple, getCache);
PHP_METHOD(Phalcon_Mvc_View_Simple, cache);
PHP_METHOD(Phalcon_Mvc_View_Simple, setParamToView);
PHP_METHOD(Phalcon_Mvc_View_Simple, setVars);
PHP_METHOD(Phalcon_Mvc_View_Simple, setVar);
PHP_METHOD(Phalcon_Mvc_View_Simple, getParamsToView);
PHP_METHOD(Phalcon_Mvc_View_Simple, setContent);
PHP_METHOD(Phalcon_Mvc_View_Simple, getContent);
PHP_METHOD(Phalcon_Mvc_View_Simple, getActiveRenderPath);
PHP_METHOD(Phalcon_Mvc_View_Simple, __set);
PHP_METHOD(Phalcon_Mvc_View_Simple, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_setviewsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, viewsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_registerengines, 0, 0, 1)
	ZEND_ARG_INFO(0, engines)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_render, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, partialPath)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_setcacheoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_cache, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_setparamtoview, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_setvars, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_setvar, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_view_simple_method_entry[] = {
	PHP_ME(Phalcon_Mvc_View_Simple, __construct, arginfo_phalcon_mvc_view_simple___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_View_Simple, setViewsDir, arginfo_phalcon_mvc_view_simple_setviewsdir, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getViewsDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, registerEngines, arginfo_phalcon_mvc_view_simple_registerengines, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getRegisteredEngines, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, _loadTemplateEngines, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Simple, _internalRender, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Simple, render, arginfo_phalcon_mvc_view_simple_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, partial, arginfo_phalcon_mvc_view_simple_partial, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, setCacheOptions, arginfo_phalcon_mvc_view_simple_setcacheoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getCacheOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, _createCache, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Simple, getCache, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, cache, arginfo_phalcon_mvc_view_simple_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, setParamToView, arginfo_phalcon_mvc_view_simple_setparamtoview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, setVars, arginfo_phalcon_mvc_view_simple_setvars, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, setVar, arginfo_phalcon_mvc_view_simple_setvar, ZEND_ACC_PUBLIC)
	PHP_MALIAS(Phalcon_Mvc_View_Simple, getVar, __get, arginfo_phalcon_mvc_view_simple___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getParamsToView, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, setContent, arginfo_phalcon_mvc_view_simple_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getActiveRenderPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, __set, arginfo_phalcon_mvc_view_simple___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, __get, arginfo_phalcon_mvc_view_simple___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\View\Simple initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_View_Simple){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\View, Simple, mvc_view_simple, phalcon_di_injectable_ce, phalcon_mvc_view_simple_method_entry, 0);

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
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __construct){

	zval *options = NULL;

	phalcon_fetch_params(0, 0, 1, &options);
	
	if (options && Z_TYPE_P(options) == IS_ARRAY) {
		phalcon_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	}
}

/**
 * Sets views directory. Depending of your platform, always add a trailing slash or backslash
 *
 * @param string $viewsDir
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setViewsDir){

	zval *views_dir;

	phalcon_fetch_params(0, 1, 0, &views_dir);
	
	phalcon_update_property_this(this_ptr, SL("_viewsDir"), views_dir TSRMLS_CC);
	
}

/**
 * Gets views directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getViewsDir){


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
 * @param array $engines
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, registerEngines){

	zval *engines;

	phalcon_fetch_params(0, 1, 0, &engines);
	
	if (Z_TYPE_P(engines) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, "Engines to register must be an array");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_registeredEngines"), engines TSRMLS_CC);
	
}

/**
 * Returns the registered templating engines
 *
 * @brief array Phalcon\Mvc\View\Simple::getRegisteredEngines()
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getRegisteredEngines) {

	RETURN_MEMBER(getThis(), "_registeredEngines")
}

/**
 * Loads registered template engines, if none is registered it will use Phalcon\Mvc\View\Engine\Php
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, _loadTemplateEngines){

	zval *engines = NULL, *dependency_injector, *registered_engines;
	zval *php_engine, *arguments, *engine_service = NULL;
	zval *extension = NULL, *engine_object = NULL, *exception_message = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(engines);
	phalcon_read_property_this(&engines, this_ptr, SL("_engines"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * If the engines aren't initialized 'engines' is false
	 */
	if (PHALCON_IS_FALSE(engines)) {
	
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	
		PHALCON_INIT_NVAR(engines);
		array_init(engines);
	
		PHALCON_OBS_VAR(registered_engines);
		phalcon_read_property_this(&registered_engines, this_ptr, SL("_registeredEngines"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(registered_engines) != IS_ARRAY) { 
			/** 
			 * We use Phalcon\Mvc\View\Engine\Php as default
			 */
			PHALCON_INIT_VAR(php_engine);
			object_init_ex(php_engine, phalcon_mvc_view_engine_php_ce);
			PHALCON_CALL_METHOD(NULL, php_engine, "__construct", this_ptr, dependency_injector);
	
			/** 
			 * Use .phtml as extension for the PHP engine
			 */
			phalcon_array_update_string(&engines, SL(".phtml"), php_engine, PH_COPY | PH_SEPARATE);
		} else {
			if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the application services");
				return;
			}
	
			/** 
			 * Arguments for instantiated engines
			 */
			PHALCON_INIT_VAR(arguments);
			array_init_size(arguments, 2);
			phalcon_array_append(&arguments, this_ptr, PH_SEPARATE);
			phalcon_array_append(&arguments, dependency_injector, PH_SEPARATE);
	
			phalcon_is_iterable(registered_engines, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HKEY(extension, ah0, hp0);
				PHALCON_GET_HVALUE(engine_service);
	
				if (Z_TYPE_P(engine_service) == IS_OBJECT) {
	
					/** 
					 * Engine can be a closure
					 */
					if (instanceof_function(Z_OBJCE_P(engine_service), zend_ce_closure TSRMLS_CC)) {
						PHALCON_INIT_NVAR(engine_object);/**/
						PHALCON_CALL_USER_FUNC_ARRAY(engine_object, engine_service, arguments);
					} else {
						PHALCON_CPY_WRT(engine_object, engine_service);
					}
				} else {
					/** 
					 * Engine can be a string representing a service in the DI
					 */
					if (Z_TYPE_P(engine_service) == IS_STRING) {
						PHALCON_CALL_METHOD(&engine_object, dependency_injector, "getshared", engine_service, arguments);
						PHALCON_VERIFY_INTERFACE(engine_object, phalcon_mvc_view_engineinterface_ce);
					} else {
						PHALCON_INIT_NVAR(exception_message);
						PHALCON_CONCAT_SV(exception_message, "Invalid template engine registration for extension: ", extension);
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
						return;
					}
				}
				phalcon_array_update_zval(&engines, extension, engine_object, PH_COPY | PH_SEPARATE);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
	
		phalcon_update_property_this(this_ptr, SL("_engines"), engines TSRMLS_CC);
	} else {
		PHALCON_OBS_NVAR(engines);
		phalcon_read_property_this(&engines, this_ptr, SL("_engines"), PH_NOISY TSRMLS_CC);
	}
	
	RETURN_CCTOR(engines);
}

/**
 * Tries to render the view with every engine registered in the component
 *
 * @param string $path
 * @param array $params
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, _internalRender){

	zval *path, *params, *events_manager, *event_name = NULL;
	zval *status = NULL, *not_exists = NULL, *views_dir;
	zval *views_dir_path, *engines = NULL, *engine = NULL, *extension = NULL;
	zval *view_engine_path = NULL, *exception_message;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &path, &params);
	
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		phalcon_update_property_this(this_ptr, SL("_activeRenderPath"), path TSRMLS_CC);
	}
	
	/** 
	 * Call beforeRender if there is an events manager
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "view:beforeRender", 1);
	
		PHALCON_CALL_METHOD(&status, events_manager, "fire", event_name, this_ptr);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_NULL();
		}
	}
	
	PHALCON_INIT_VAR(not_exists);
	ZVAL_TRUE(not_exists);
	
	PHALCON_OBS_VAR(views_dir);
	phalcon_read_property_this(&views_dir, this_ptr, SL("_viewsDir"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(views_dir_path);
	PHALCON_CONCAT_VV(views_dir_path, views_dir, path);
	
	/** 
	 * Load the template engines
	 */
	PHALCON_CALL_METHOD(&engines, this_ptr, "_loadtemplateengines");
	
	/** 
	 * Views are rendered in each engine
	 */
	phalcon_is_iterable(engines, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(extension, ah0, hp0);
		PHALCON_GET_HVALUE(engine);
	
		PHALCON_INIT_NVAR(view_engine_path);
		PHALCON_CONCAT_VV(view_engine_path, views_dir_path, extension);
	
		if (phalcon_file_exists(view_engine_path TSRMLS_CC) == SUCCESS) {
	
			/** 
			 * Call beforeRenderView if there is a events manager available
			 */
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "view:beforeRenderView", 1);
	
				PHALCON_CALL_METHOD(&status, events_manager, "fire", event_name, this_ptr, view_engine_path);
				if (PHALCON_IS_FALSE(status)) {
					zend_hash_move_forward_ex(ah0, &hp0);
					continue;
				}
			}
			
			PHALCON_CALL_METHOD(NULL, engine, "render", view_engine_path, params, PHALCON_GLOBAL(z_true));
	
			/** 
			 * Call afterRenderView if there is a events manager available
			 */
			PHALCON_INIT_NVAR(not_exists);
			ZVAL_FALSE(not_exists);
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "view:afterRenderView", 1);
				PHALCON_CALL_METHOD(NULL, events_manager, "fire", event_name, this_ptr);
			}
	
			break;
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Always throw an exception if the view does not exist
	 */
	if (PHALCON_IS_TRUE(not_exists)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "View '", views_dir_path, "' was not found in the views directory");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
		return;
	}
	
	/** 
	 * Call afterRender event
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "view:afterRender", 1);
		PHALCON_CALL_METHOD(NULL, events_manager, "fire", event_name, this_ptr);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Renders a view
 *
 * @param string $path
 * @param array $params
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, render){

	zval *path, *params = NULL, *cache = NULL, *is_started = NULL, *key = NULL, *lifetime = NULL;
	zval *cache_options, *content = NULL, *view_params;
	zval *merged_params = NULL, *is_fresh = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &path, &params);
	
	if (!params) {
		params = PHALCON_GLOBAL(z_null);
	}
	
	/** 
	 * Create/Get a cache
	 */
	PHALCON_CALL_METHOD(&cache, this_ptr, "getcache");
	if (Z_TYPE_P(cache) == IS_OBJECT) {
	
		/** 
		 * Check if the cache is started, the first time a cache is started we start the
		 * cache
		 */
		PHALCON_CALL_METHOD(&is_started, cache, "isstarted");
		if (PHALCON_IS_FALSE(is_started)) {
	
			PHALCON_INIT_VAR(key);
	
			PHALCON_INIT_VAR(lifetime);
	
			PHALCON_OBS_VAR(cache_options);
			phalcon_read_property_this(&cache_options, this_ptr, SL("_cacheOptions"), PH_NOISY TSRMLS_CC);
	
			/** 
			 * Check if the user has defined a different options to the default
			 */
			if (Z_TYPE_P(cache_options) == IS_ARRAY) { 
				if (phalcon_array_isset_string(cache_options, SS("key"))) {
					PHALCON_OBS_NVAR(key);
					phalcon_array_fetch_string(&key, cache_options, SL("key"), PH_NOISY);
				}
				if (phalcon_array_isset_string(cache_options, SS("lifetime"))) {
					PHALCON_OBS_NVAR(lifetime);
					phalcon_array_fetch_string(&lifetime, cache_options, SL("lifetime"), PH_NOISY);
				}
			}
	
			/** 
			 * If a cache key is not set we create one using a md5
			 */
			if (Z_TYPE_P(key) == IS_NULL) {
				PHALCON_INIT_NVAR(key);
				phalcon_md5(key, path);
			}
	
			/** 
			 * We start the cache using the key set
			 */
			PHALCON_CALL_METHOD(&content, cache, "start", key, lifetime);
			if (Z_TYPE_P(content) != IS_NULL) {
				phalcon_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);
				RETURN_CTOR(content);
			}
		}
	}
	
	/** 
	 * Create a virtual symbol table
	 */
	phalcon_create_symbol_table(TSRMLS_C);
	
	phalcon_ob_start(TSRMLS_C);
	
	PHALCON_OBS_VAR(view_params);
	phalcon_read_property_this(&view_params, this_ptr, SL("_viewParams"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Merge parameters
	 */
	if (Z_TYPE_P(params) == IS_ARRAY) { 
		if (Z_TYPE_P(view_params) == IS_ARRAY) { 
			PHALCON_INIT_VAR(merged_params);
			phalcon_fast_array_merge(merged_params, &view_params, &params TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_params, params);
		}
	} else {
		PHALCON_CPY_WRT(merged_params, view_params);
	}
	
	/** 
	 * internalRender is also reused by partials
	 */
	PHALCON_CALL_METHOD(NULL, this_ptr, "_internalrender", path, merged_params);
	
	/** 
	 * Store the data in output into the cache
	 */
	if (Z_TYPE_P(cache) == IS_OBJECT) {
		PHALCON_CALL_METHOD(&is_started, cache, "isstarted");
		if (PHALCON_IS_TRUE(is_started)) {
			PHALCON_CALL_METHOD(&is_fresh, cache, "isfresh");
			if (PHALCON_IS_TRUE(is_fresh)) {
				PHALCON_CALL_METHOD(NULL, cache, "save");
			} else {
				PHALCON_CALL_METHOD(NULL, cache, "stop");
			}
		} else {
			PHALCON_CALL_METHOD(NULL, cache, "stop");
		}
	}
	
	phalcon_ob_end_clean(TSRMLS_C);
	
	PHALCON_OBS_NVAR(content);
	phalcon_read_property_this(&content, this_ptr, SL("_content"), PH_NOISY TSRMLS_CC);
	RETURN_CTOR(content);
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
 * @param string $partialPath
 * @param array $params
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, partial){

	zval *partial_path, *params = NULL, *view_params = NULL, *merged_params = NULL;
	zval *content;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &partial_path, &params);
	
	if (!params) {
		params = PHALCON_GLOBAL(z_null);
	}
	
	/** 
	 * Start ouput buffering
	 */
	phalcon_ob_start(TSRMLS_C);
	
	/** 
	 * If the developer pass an array of variables we create a new virtual symbol table
	 */
	if (Z_TYPE_P(params) == IS_ARRAY) { 
	
		PHALCON_OBS_VAR(view_params);
		phalcon_read_property_this(&view_params, this_ptr, SL("_viewParams"), PH_NOISY TSRMLS_CC);
	
		/** 
		 * Merge or assign the new params as parameters
		 */
		if (Z_TYPE_P(view_params) == IS_ARRAY) { 
			PHALCON_INIT_VAR(merged_params);
			phalcon_fast_array_merge(merged_params, &view_params, &params TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_params, params);
		}
	
		/** 
		 * Create a virtual symbol table
		 */
		phalcon_create_symbol_table(TSRMLS_C);
	
	} else {
		PHALCON_CPY_WRT(merged_params, params);
	}
	
	/** 
	 * Call engine render, this checks in every registered engine for the partial
	 */
	PHALCON_CALL_METHOD(NULL, this_ptr, "_internalrender", partial_path, merged_params);
	
	/** 
	 * Now we need to restore the original view parameters
	 */
	if (view_params != NULL) {
		/** 
		 * Restore the original view params
		 */
		phalcon_update_property_this(this_ptr, SL("_viewParams"), view_params TSRMLS_CC);
	}
	
	phalcon_ob_end_clean(TSRMLS_C);
	
	content = phalcon_fetch_nproperty_this(this_ptr, SL("_content"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Content is output to the parent view
	 */
	zend_print_zval(content, 0);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the cache options
 *
 * @param array $options
 * @return Phalcon\Mvc\View\Simple
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setCacheOptions){

	zval *options;

	phalcon_fetch_params(0, 1, 0, &options);
	
	phalcon_update_property_this(this_ptr, SL("_cacheOptions"), options TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the cache options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getCacheOptions){


	RETURN_MEMBER(this_ptr, "_cacheOptions");
}

/**
 * Create a Phalcon\Cache based on the internal cache options
 *
 * @return Phalcon\Cache\BackendInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, _createCache){

	zval *dependency_injector, *cache_service = NULL;
	zval *cache_options;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the view cache services");
		return;
	}
	
	PHALCON_INIT_VAR(cache_service);
	ZVAL_STRING(cache_service, "viewCache", 1);
	
	PHALCON_OBS_VAR(cache_options);
	phalcon_read_property_this(&cache_options, this_ptr, SL("_cacheOptions"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(cache_options) == IS_ARRAY) { 
		if (phalcon_array_isset_string(cache_options, SS("service"))) {
			PHALCON_OBS_NVAR(cache_service);
			phalcon_array_fetch_string(&cache_service, cache_options, SL("service"), PH_NOISY);
		}
	}
	
	/** 
	 * The injected service must be an object
	 */
	PHALCON_RETURN_CALL_METHOD(dependency_injector, "getshared", cache_service);
	if (return_value_ptr) {
		return_value = *return_value_ptr;
	}

	if (Z_TYPE_P(return_value) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "The injected caching service is invalid");
		return;
	}
	
	PHALCON_VERIFY_INTERFACE(return_value, phalcon_cache_backendinterface_ce);
	PHALCON_MM_RESTORE();
}

/**
 * Returns the cache instance used to cache
 *
 * @return Phalcon\Cache\BackendInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getCache){

	zval *cache = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(cache);
	phalcon_read_property_this(&cache, this_ptr, SL("_cache"), PH_NOISY TSRMLS_CC);
	if (zend_is_true(cache)) {
		if (Z_TYPE_P(cache) != IS_OBJECT) {
			PHALCON_CALL_METHOD(&cache, this_ptr, "_createcache");
			phalcon_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
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
 * @param boolean|array $options
 * @return Phalcon\Mvc\View\Simple
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, cache){

	zval *options = NULL;

	phalcon_fetch_params(0, 0, 1, &options);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_true);
	}
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		phalcon_update_property_this(this_ptr, SL("_cache"), PHALCON_GLOBAL(z_true) TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_cacheOptions"), options TSRMLS_CC);
	} else {
		if (zend_is_true(options)) {
			phalcon_update_property_this(this_ptr, SL("_cache"), PHALCON_GLOBAL(z_true) TSRMLS_CC);
		} else {
			phalcon_update_property_this(this_ptr, SL("_cache"), PHALCON_GLOBAL(z_false) TSRMLS_CC);
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
PHP_METHOD(Phalcon_Mvc_View_Simple, setParamToView){

	zval *key, *value;

	phalcon_fetch_params(0, 2, 0, &key, &value);
	
	phalcon_update_property_array(this_ptr, SL("_viewParams"), key, value TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Set all the render params
 *
 *<code>
 *	$this->view->setVars(array('products' => $products));
 *</code>
 *
 * @param array $params
 * @param boolean $merge
 * @return Phalcon\Mvc\View\Simple
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setVars){

	zval *params, *merge = NULL, *view_params, *merged_params = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &params, &merge);
	
	if (!merge) {
		merge = PHALCON_GLOBAL(z_true);
	}
	
	if (Z_TYPE_P(params) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "The render parameters must be an array");
		return;
	}

	if (zend_is_true(merge)) {
		PHALCON_OBS_VAR(view_params);
		phalcon_read_property_this(&view_params, this_ptr, SL("_viewParams"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(view_params) == IS_ARRAY) { 
			PHALCON_INIT_VAR(merged_params);
			phalcon_fast_array_merge(merged_params, &view_params, &params TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_params, params);
		}
	
		phalcon_update_property_this(this_ptr, SL("_viewParams"), merged_params TSRMLS_CC);
	} else {
		phalcon_update_property_this(this_ptr, SL("_viewParams"), params TSRMLS_CC);
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
 * @param string $key
 * @param mixed $value
 * @return Phalcon\Mvc\View\Simple
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setVar){

	zval *key, *value;

	phalcon_fetch_params(0, 2, 0, &key, &value);
	
	phalcon_update_property_array(this_ptr, SL("_viewParams"), key, value TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns a parameter previously set in the view
 *
 * @param string $key
 * @return mixed
 * @see __get()
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_View_Simple, getVar);

/**
 * Returns parameters to views
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getParamsToView){


	RETURN_MEMBER(this_ptr, "_viewParams");
}

/**
 * Externally sets the view content
 *
 *<code>
 *	$this->view->setContent("<h1>hello</h1>");
 *</code>
 *
 * @param string $content
 * @return Phalcon\Mvc\View\Simple
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setContent){

	zval *content;

	phalcon_fetch_params(0, 1, 0, &content);
	
	if (Z_TYPE_P(content) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, "Content must be a string");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Returns cached ouput from another view stage
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getContent){


	RETURN_MEMBER(this_ptr, "_content");
}

/**
 * Returns the path of the view that is currently rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getActiveRenderPath){


	RETURN_MEMBER(this_ptr, "_activeRenderPath");
}

/**
 * Magic method to pass variables to the views
 *
 *<code>
 *	$this->view->products = $products;
 *</code>
 *
 * @param string $key
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __set){

	zval *key, *value;

	phalcon_fetch_params(0, 2, 0, &key, &value);
	
	phalcon_update_property_array(this_ptr, SL("_viewParams"), key, value TSRMLS_CC);
	
}

/**
 * Magic method to retrieve a variable passed to the view
 *
 *<code>
 *	echo $this->view->products;
 *</code>
 *
 * @param string $key
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __get){

	zval *key, *params, *value;

	phalcon_fetch_params(0, 1, 0, &key);
	
	params = phalcon_fetch_nproperty_this(this_ptr, SL("_viewParams"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_fetch(&value, params, key)) {
		RETURN_ZVAL(value, 1, 0);
	}
	
	RETURN_NULL();
}
