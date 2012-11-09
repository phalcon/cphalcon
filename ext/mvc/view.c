
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/string.h"

/**
 * Phalcon\Mvc\View
 *
 * Phalcon\Mvc\View is a class for working with the "view" portion of the model-view-controller pattern.
 * That is, it exists to help keep the view script separate from the model and controller scripts.
 * It provides a system of helpers, output filters, and variable escaping.
 *
 * <code>
 * //Setting views directory
 * $view = new Phalcon\Mvc\View();
 * $view->setViewsDir('app/views/');
 *
 * $view->start();
 * //Shows recent posts view (app/views/posts/recent.phtml)
 * $view->render('posts', 'recent');
 * $view->finish();
 *
 * //Printing views output
 * echo $view->getContent();
 * </code>
 */


/**
 * Phalcon\Mvc\View constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_View, __construct){

	zval *options = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_mvc_view_ce, this_ptr, SL("_viewParams"), a0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_mvc_view_ce, this_ptr, SL("_registeredEngines"), a1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	zend_update_property(phalcon_mvc_view_ce, this_ptr, SL("_params"), a2 TSRMLS_CC);
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_options"), options TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets views directory. Depending of your platform, always add a trailing slash or backslash
 *
 * @param string $viewsDir
 */
PHP_METHOD(Phalcon_Mvc_View, setViewsDir){

	zval *views_dir;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &views_dir) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_viewsDir"), views_dir TSRMLS_CC);
	
}

/**
 * Gets views directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getViewsDir){

	zval *views_dir;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(views_dir);
	phalcon_read_property(&views_dir, this_ptr, SL("_viewsDir"), PH_NOISY_CC);
	
	RETURN_CCTOR(views_dir);
}

/**
 * Sets base path. Depending of your platform, always add a trailing slash or backslash
 *
 * <code>
 * $view->setBasePath(__DIR__.'/');
 * </code>
 *
 * @param string $basePath
 */
PHP_METHOD(Phalcon_Mvc_View, setBasePath){

	zval *base_path;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &base_path) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_basePath"), base_path TSRMLS_CC);
	
}

/**
 * Sets the render level for the view
 *
 * <code>
 * //Render the view related to the controller only
 * $this->view->setRenderLevel(Phalcon\Mvc\View::LEVEL_VIEW);
 * </code>
 *
 * @param string $level
 */
PHP_METHOD(Phalcon_Mvc_View, setRenderLevel){

	zval *level;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &level) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_renderLevel"), level TSRMLS_CC);
	
}

/**
 * Sets default view name. Must be a file without extension in the views directory
 *
 * <code>
 * //Renders as main view views-dir/inicio.phtml
 * $this->view->setMainView('inicio');
 * </code>
 *
 * @param string $name
 */
PHP_METHOD(Phalcon_Mvc_View, setMainView){

	zval *view_path;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &view_path) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_mainView"), view_path TSRMLS_CC);
	
}

/**
 * Appends template before controller layout
 *
 * @param string|array $templateBefore
 */
PHP_METHOD(Phalcon_Mvc_View, setTemplateBefore){

	zval *template_before, *array_template;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &template_before) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(template_before) != IS_ARRAY) { 
		PHALCON_INIT_VAR(array_template);
		array_init(array_template);
		phalcon_array_append(&array_template, template_before, PH_SEPARATE TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_templatesBefore"), array_template TSRMLS_CC);
	} else {
		phalcon_update_property_zval(this_ptr, SL("_templatesBefore"), template_before TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Resets any template before layouts
 *
 */
PHP_METHOD(Phalcon_Mvc_View, cleanTemplateBefore){


	phalcon_update_property_null(this_ptr, SL("_templatesBefore") TSRMLS_CC);
	
}

/**
 * Appends template after controller layout
 *
 * @param string|array $templateAfter
 */
PHP_METHOD(Phalcon_Mvc_View, setTemplateAfter){

	zval *template_after, *array_template;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &template_after) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(template_after) != IS_ARRAY) { 
		PHALCON_INIT_VAR(array_template);
		array_init(array_template);
		phalcon_array_append(&array_template, template_after, PH_SEPARATE TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_templatesAfter"), array_template TSRMLS_CC);
	} else {
		phalcon_update_property_zval(this_ptr, SL("_templatesAfter"), template_after TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Resets any template before layouts
 *
 */
PHP_METHOD(Phalcon_Mvc_View, cleanTemplateAfter){


	phalcon_update_property_null(this_ptr, SL("_templatesAfter") TSRMLS_CC);
	
}

/**
 * Adds parameters to views (alias of setVar)
 *
 * @param string $key
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Mvc_View, setParamToView){

	zval *key, *value;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &key, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(t0);
	phalcon_read_property(&t0, this_ptr, SL("_viewParams"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, key, &value, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_viewParams"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Adds parameters to views
 *
 * @param string $key
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Mvc_View, setVar){

	zval *key, *value;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &key, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(t0);
	phalcon_read_property(&t0, this_ptr, SL("_viewParams"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, key, &value, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_viewParams"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns parameters to views
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View, getParamsToView){

	zval *view_params;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(view_params);
	phalcon_read_property(&view_params, this_ptr, SL("_viewParams"), PH_NOISY_CC);
	
	RETURN_CCTOR(view_params);
}

/**
 * Gets the name of the controller rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getControllerName){

	zval *controller_name;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(controller_name);
	phalcon_read_property(&controller_name, this_ptr, SL("_controllerName"), PH_NOISY_CC);
	
	RETURN_CCTOR(controller_name);
}

/**
 * Gets the name of the action rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getActionName){

	zval *action_name;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(action_name);
	phalcon_read_property(&action_name, this_ptr, SL("_actionName"), PH_NOISY_CC);
	
	RETURN_CCTOR(action_name);
}

/**
 * Gets extra parameters of the action rendered
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View, getParams){

	zval *params;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(params);
	phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	
	RETURN_CCTOR(params);
}

/**
 * Starts rendering process enabling the output buffering
 */
PHP_METHOD(Phalcon_Mvc_View, start){


	PHALCON_MM_GROW();

	phalcon_update_property_null(this_ptr, SL("_content") TSRMLS_CC);
	PHALCON_CALL_FUNC_NORETURN("ob_start");
	
	PHALCON_MM_RESTORE();
}

/**
 * Loads registered template engines, if none is registered it will use Phalcon\Mvc\View\Engine\Php
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View, _loadTemplateEngines){

	zval *engines = NULL, *dependency_injector, *registered_engines;
	zval *number_engines, *php_engine, *arguments;
	zval *engine_service = NULL, *extension = NULL, *engine_object = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(engines);
	phalcon_read_property(&engines, this_ptr, SL("_engines"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(engines)) {
		PHALCON_INIT_VAR(dependency_injector);
		phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		
		PHALCON_INIT_NVAR(engines);
		array_init(engines);
		
		PHALCON_INIT_VAR(registered_engines);
		phalcon_read_property(&registered_engines, this_ptr, SL("_registeredEngines"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(number_engines);
		phalcon_fast_count(number_engines, registered_engines TSRMLS_CC);
		if (phalcon_compare_strict_long(number_engines, 0 TSRMLS_CC)) {
			PHALCON_INIT_VAR(php_engine);
			object_init_ex(php_engine, phalcon_mvc_view_engine_php_ce);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(php_engine, "__construct", this_ptr, dependency_injector, PH_CHECK);
			phalcon_array_update_string(&engines, SL(".phtml"), &php_engine, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the application services");
				return;
			}
			
			PHALCON_INIT_VAR(arguments);
			array_init(arguments);
			phalcon_array_append(&arguments, this_ptr, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&arguments, dependency_injector, PH_SEPARATE TSRMLS_CC);
			
			if (!phalcon_valid_foreach(registered_engines TSRMLS_CC)) {
				return;
			}
			
			ah0 = Z_ARRVAL_P(registered_engines);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			
			ph_cycle_start_0:
			
				if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
					goto ph_cycle_end_0;
				}
				
				PHALCON_GET_FOREACH_KEY(extension, ah0, hp0);
				PHALCON_GET_FOREACH_VALUE(engine_service);
				
				PHALCON_INIT_NVAR(engine_object);
				PHALCON_CALL_METHOD_PARAMS_2(engine_object, dependency_injector, "getshared", engine_service, arguments, PH_NO_CHECK);
				phalcon_array_update_zval(&engines, extension, &engine_object, PH_COPY | PH_SEPARATE TSRMLS_CC);
				
				zend_hash_move_forward_ex(ah0, &hp0);
				goto ph_cycle_start_0;
				
			ph_cycle_end_0:
			if(0){}
			
		}
		
		phalcon_update_property_zval(this_ptr, SL("_engines"), engines TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(engines);
		phalcon_read_property(&engines, this_ptr, SL("_engines"), PH_NOISY_CC);
	}
	
	
	RETURN_CCTOR(engines);
}

/**
 * Checks whether view exists on registered extensions and render it
 *
 * @param array $engines
 * @param string $viewPath
 * @param boolean $silence
 * @param boolean $mustClean
 * @param Phalcon\Cache\Backend $cache
 */
PHP_METHOD(Phalcon_Mvc_View, _engineRender){

	zval *engines, *view_path, *silence, *must_clean;
	zval *cache, *not_exists = NULL, *view_params, *views_dir;
	zval *base_path, *views_dir_path, *events_manager;
	zval *render_level, *cache_level, *enter_cache;
	zval *is_started, *key = NULL, *view_options, *cache_options;
	zval *cached_view, *is_fresh, *engine = NULL, *extension = NULL;
	zval *view_engine_path = NULL, *event_name = NULL, *status = NULL;
	zval *exception_message;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzzz", &engines, &view_path, &silence, &must_clean, &cache) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(not_exists);
	ZVAL_BOOL(not_exists, 1);
	
	PHALCON_INIT_VAR(view_params);
	phalcon_read_property(&view_params, this_ptr, SL("_viewParams"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(views_dir);
	phalcon_read_property(&views_dir, this_ptr, SL("_viewsDir"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(base_path);
	phalcon_read_property(&base_path, this_ptr, SL("_basePath"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(views_dir_path);
	PHALCON_CONCAT_VVV(views_dir_path, base_path, views_dir, view_path);
	
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(cache) == IS_OBJECT) {
		PHALCON_INIT_VAR(render_level);
		phalcon_read_property(&render_level, this_ptr, SL("_renderLevel"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(cache_level);
		phalcon_read_property(&cache_level, this_ptr, SL("_cacheLevel"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(enter_cache);
		is_smaller_or_equal_function(enter_cache, cache_level, render_level TSRMLS_CC);
		if (zend_is_true(enter_cache)) {
			PHALCON_INIT_VAR(is_started);
			PHALCON_CALL_METHOD(is_started, cache, "isstarted", PH_NO_CHECK);
			if (PHALCON_IS_FALSE(is_started)) {
				PHALCON_INIT_VAR(key);
				
				PHALCON_INIT_VAR(view_options);
				phalcon_read_property(&view_options, this_ptr, SL("_options"), PH_NOISY_CC);
				if (Z_TYPE_P(view_options) == IS_ARRAY) { 
					eval_int = phalcon_array_isset_string(view_options, SS("cache"));
					if (eval_int) {
						PHALCON_INIT_VAR(cache_options);
						phalcon_array_fetch_string(&cache_options, view_options, SL("cache"), PH_NOISY_CC);
						if (Z_TYPE_P(cache_options) == IS_ARRAY) { 
							eval_int = phalcon_array_isset_string(cache_options, SS("key"));
							if (eval_int) {
								phalcon_array_fetch_string(&key, cache_options, SL("key"), PH_NOISY_CC);
							}
						}
					}
				}
				
				if (Z_TYPE_P(key) == IS_NULL) {
					PHALCON_INIT_NVAR(key);
					PHALCON_CALL_FUNC_PARAMS_1(key, "md5", view_path);
				}
				
				PHALCON_INIT_VAR(cached_view);
				PHALCON_CALL_METHOD_PARAMS_1(cached_view, cache, "start", key, PH_NO_CHECK);
				if (Z_TYPE_P(cached_view) != IS_NULL) {
					phalcon_update_property_zval(this_ptr, SL("_content"), cached_view TSRMLS_CC);
					PHALCON_MM_RESTORE();
					RETURN_NULL();
				}
			}
			
			PHALCON_INIT_VAR(is_fresh);
			PHALCON_CALL_METHOD(is_fresh, cache, "isfresh", PH_NO_CHECK);
			if (!zend_is_true(is_fresh)) {
				PHALCON_MM_RESTORE();
				RETURN_NULL();
			}
		}
	}
	
	
	if (!phalcon_valid_foreach(engines TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(engines);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_KEY(extension, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(engine);
		
		PHALCON_INIT_NVAR(view_engine_path);
		PHALCON_CONCAT_VV(view_engine_path, views_dir_path, extension);
		if (phalcon_file_exists(view_engine_path TSRMLS_CC) == SUCCESS) {
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
				phalcon_update_property_zval(this_ptr, SL("_activeRenderPath"), view_engine_path TSRMLS_CC);
				
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "view:beforeRenderView", 1);
				
				PHALCON_INIT_NVAR(status);
				PHALCON_CALL_METHOD_PARAMS_3(status, events_manager, "fire", event_name, this_ptr, view_engine_path, PH_NO_CHECK);
				if (PHALCON_IS_FALSE(status)) {
					zend_hash_move_forward_ex(ah0, &hp0);
					goto ph_cycle_start_0;
				}
			}
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(engine, "render", view_engine_path, view_params, must_clean, PH_NO_CHECK);
			
			PHALCON_INIT_NVAR(not_exists);
			ZVAL_BOOL(not_exists, 0);
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
				phalcon_update_property_zval(this_ptr, SL("_activeRenderPath"), view_engine_path TSRMLS_CC);
				
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "view:afterRenderView", 1);
				
				PHALCON_INIT_NVAR(status);
				PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
				if (PHALCON_IS_FALSE(status)) {
					zend_hash_move_forward_ex(ah0, &hp0);
					goto ph_cycle_start_0;
				}
			}
			
			goto ph_cycle_end_0;
		}
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
		
	ph_cycle_end_0:
	
	if (PHALCON_IS_TRUE(not_exists)) {
		if (!zend_is_true(silence)) {
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "View '", views_dir_path, "' was not found in the views directory");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
			return;
		}
	}
	
	PHALCON_MM_RESTORE();
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
PHP_METHOD(Phalcon_Mvc_View, registerEngines){

	zval *engines;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &engines) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(engines) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Engines to register must be an array");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_registeredEngines"), engines TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Executes render process from dispatching data
 *
 *<code>
 * $view->start();
 * //Shows recent posts view (app/views/posts/recent.phtml)
 * $view->render('posts', 'recent');
 * $view->finish();
 *</code>
 *
 * @param string $controllerName
 * @param string $actionName
 * @param array $params
 */
PHP_METHOD(Phalcon_Mvc_View, render){

	zval *controller_name, *action_name, *params = NULL;
	zval *disabled, *layouts_dir = NULL, *engines, *pick_view;
	zval *render_view = NULL, *render_controller = NULL, *pick_view_action;
	zval *cache = NULL, *cache_level, *events_manager, *event_name = NULL;
	zval *status, *contents, *must_clean, *silence = NULL;
	zval *render_level, *enter_level = NULL, *templates_before;
	zval *template_before = NULL, *view_temp_path = NULL, *templates_after;
	zval *template_after = NULL, *main_view, *is_started;
	zval *is_fresh;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &controller_name, &action_name, &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!params) {
		PHALCON_INIT_NVAR(params);
		array_init(params);
	}
	
	PHALCON_INIT_VAR(disabled);
	phalcon_read_property(&disabled, this_ptr, SL("_disabled"), PH_NOISY_CC);
	if (PHALCON_IS_NOT_FALSE(disabled)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_INIT_VAR(layouts_dir);
	phalcon_read_property(&layouts_dir, this_ptr, SL("_layoutsDir"), PH_NOISY_CC);
	if (!zend_is_true(layouts_dir)) {
		PHALCON_INIT_NVAR(layouts_dir);
		ZVAL_STRING(layouts_dir, "layouts/", 1);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_controllerName"), controller_name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_params"), params TSRMLS_CC);
	
	PHALCON_INIT_VAR(engines);
	PHALCON_CALL_METHOD(engines, this_ptr, "_loadtemplateengines", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(pick_view);
	phalcon_read_property(&pick_view, this_ptr, SL("_pickView"), PH_NOISY_CC);
	if (Z_TYPE_P(pick_view) == IS_NULL) {
		PHALCON_INIT_VAR(render_view);
		PHALCON_CONCAT_VSV(render_view, controller_name, "/", action_name);
		PHALCON_CPY_WRT(render_controller, controller_name);
	} else {
		PHALCON_INIT_NVAR(render_view);
		phalcon_array_fetch_long(&render_view, pick_view, 0, PH_NOISY_CC);
		eval_int = phalcon_array_isset_long(pick_view, 1);
		if (eval_int) {
			PHALCON_INIT_VAR(pick_view_action);
			phalcon_array_fetch_long(&pick_view_action, pick_view, 1, PH_NOISY_CC);
			PHALCON_CPY_WRT(render_controller, pick_view_action);
		} else {
			PHALCON_CPY_WRT(render_controller, controller_name);
		}
	}
	
	PHALCON_INIT_VAR(cache);
	
	PHALCON_INIT_VAR(cache_level);
	phalcon_read_property(&cache_level, this_ptr, SL("_cacheLevel"), PH_NOISY_CC);
	if (zend_is_true(cache_level)) {
		PHALCON_CALL_METHOD(cache, this_ptr, "getcache", PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "view:beforeRender", 1);
		
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
		if (PHALCON_IS_FALSE(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(contents);
	PHALCON_CALL_FUNC(contents, "ob_get_contents");
	phalcon_update_property_zval(this_ptr, SL("_content"), contents TSRMLS_CC);
	
	PHALCON_INIT_VAR(must_clean);
	ZVAL_BOOL(must_clean, 1);
	
	PHALCON_INIT_VAR(silence);
	ZVAL_BOOL(silence, 1);
	
	PHALCON_INIT_VAR(render_level);
	phalcon_read_property(&render_level, this_ptr, SL("_renderLevel"), PH_NOISY_CC);
	if (zend_is_true(render_level)) {
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 1);
		PHALCON_INIT_VAR(enter_level);
		is_smaller_or_equal_function(enter_level, t0, render_level TSRMLS_CC);
		if (PHALCON_IS_TRUE(enter_level)) {
			PHALCON_CALL_METHOD_PARAMS_5_NORETURN(this_ptr, "_enginerender", engines, render_view, silence, must_clean, cache, PH_NO_CHECK);
		}
		
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 2);
		
		PHALCON_INIT_NVAR(enter_level);
		is_smaller_or_equal_function(enter_level, t1, render_level TSRMLS_CC);
		if (PHALCON_IS_TRUE(enter_level)) {
			PHALCON_INIT_VAR(templates_before);
			phalcon_read_property(&templates_before, this_ptr, SL("_templatesBefore"), PH_NOISY_CC);
			if (Z_TYPE_P(templates_before) == IS_ARRAY) { 
				ZVAL_BOOL(silence, 0);
				
				if (!phalcon_valid_foreach(templates_before TSRMLS_CC)) {
					return;
				}
				
				ah0 = Z_ARRVAL_P(templates_before);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				
				ph_cycle_start_0:
				
					if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
						goto ph_cycle_end_0;
					}
					
					PHALCON_GET_FOREACH_VALUE(template_before);
					
					PHALCON_INIT_NVAR(view_temp_path);
					PHALCON_CONCAT_VV(view_temp_path, layouts_dir, template_before);
					PHALCON_CALL_METHOD_PARAMS_5_NORETURN(this_ptr, "_enginerender", engines, view_temp_path, silence, must_clean, cache, PH_NO_CHECK);
					
					zend_hash_move_forward_ex(ah0, &hp0);
					goto ph_cycle_start_0;
					
				ph_cycle_end_0:
				
				ZVAL_BOOL(silence, 1);
			}
		}
		
		PHALCON_INIT_VAR(t2);
		ZVAL_LONG(t2, 3);
		
		PHALCON_INIT_NVAR(enter_level);
		is_smaller_or_equal_function(enter_level, t2, render_level TSRMLS_CC);
		if (PHALCON_IS_TRUE(enter_level)) {
			PHALCON_INIT_NVAR(view_temp_path);
			PHALCON_CONCAT_VV(view_temp_path, layouts_dir, render_controller);
			PHALCON_CALL_METHOD_PARAMS_5_NORETURN(this_ptr, "_enginerender", engines, view_temp_path, silence, must_clean, cache, PH_NO_CHECK);
		}
		
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 4);
		
		PHALCON_INIT_NVAR(enter_level);
		is_smaller_or_equal_function(enter_level, t3, render_level TSRMLS_CC);
		if (PHALCON_IS_TRUE(enter_level)) {
			PHALCON_INIT_VAR(templates_after);
			phalcon_read_property(&templates_after, this_ptr, SL("_templatesAfter"), PH_NOISY_CC);
			if (Z_TYPE_P(templates_after) == IS_ARRAY) { 
				ZVAL_BOOL(silence, 0);
				
				if (!phalcon_valid_foreach(templates_after TSRMLS_CC)) {
					return;
				}
				
				ah1 = Z_ARRVAL_P(templates_after);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				
				ph_cycle_start_1:
				
					if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
						goto ph_cycle_end_1;
					}
					
					PHALCON_GET_FOREACH_VALUE(template_after);
					
					PHALCON_INIT_NVAR(view_temp_path);
					PHALCON_CONCAT_VV(view_temp_path, layouts_dir, template_after);
					PHALCON_CALL_METHOD_PARAMS_5_NORETURN(this_ptr, "_enginerender", engines, view_temp_path, silence, must_clean, cache, PH_NO_CHECK);
					
					zend_hash_move_forward_ex(ah1, &hp1);
					goto ph_cycle_start_1;
					
				ph_cycle_end_1:
				
				ZVAL_BOOL(silence, 1);
			}
		}
		
		PHALCON_INIT_VAR(t4);
		ZVAL_LONG(t4, 5);
		
		PHALCON_INIT_NVAR(enter_level);
		is_smaller_or_equal_function(enter_level, t4, render_level TSRMLS_CC);
		if (PHALCON_IS_TRUE(enter_level)) {
			PHALCON_INIT_VAR(main_view);
			phalcon_read_property(&main_view, this_ptr, SL("_mainView"), PH_NOISY_CC);
			PHALCON_CALL_METHOD_PARAMS_5_NORETURN(this_ptr, "_enginerender", engines, main_view, silence, must_clean, cache, PH_NO_CHECK);
		}
		
		if (Z_TYPE_P(cache) == IS_OBJECT) {
			PHALCON_INIT_VAR(is_started);
			PHALCON_CALL_METHOD(is_started, cache, "isstarted", PH_NO_CHECK);
			if (PHALCON_IS_TRUE(is_started)) {
				PHALCON_INIT_VAR(is_fresh);
				PHALCON_CALL_METHOD(is_fresh, cache, "isfresh", PH_NO_CHECK);
				if (PHALCON_IS_TRUE(is_fresh)) {
					PHALCON_CALL_METHOD_NORETURN(cache, "save", PH_NO_CHECK);
				} else {
					PHALCON_CALL_METHOD_NORETURN(cache, "stop", PH_NO_CHECK);
				}
			} else {
				PHALCON_CALL_METHOD_NORETURN(cache, "stop", PH_NO_CHECK);
			}
		}
	}
	
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "view:afterRender", 1);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Choose a view different to render than last-controller/last-action
 *
 * <code>
 * class ProductsController extends Phalcon\Mvc\Controller
 * {
 *
 *    public function saveAction()
 *    {
 *
 *         //Do some save stuff...
 *
 *         //Then show the list view
 *         $this->view->pick("products/list");
 *    }
 * }
 * </code>
 *
 * @param string $renderView
 */
PHP_METHOD(Phalcon_Mvc_View, pick){

	zval *render_view, *separator, *pick_view = NULL, *layout = NULL;
	zval *parts;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &render_view) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(separator);
	ZVAL_STRING(separator, "/", 1);
	if (Z_TYPE_P(render_view) == IS_ARRAY) { 
		PHALCON_CPY_WRT(pick_view, render_view);
	} else {
		PHALCON_INIT_VAR(layout);
		if (phalcon_memnstr(render_view, separator TSRMLS_CC)) {
			PHALCON_INIT_VAR(parts);
			phalcon_fast_explode(parts, separator, render_view TSRMLS_CC);
			
			phalcon_array_fetch_long(&layout, parts, 0, PH_NOISY_CC);
		}
		
		PHALCON_INIT_VAR(pick_view);
		array_init(pick_view);
		phalcon_array_append(&pick_view, render_view, PH_SEPARATE TSRMLS_CC);
		if (Z_TYPE_P(layout) != IS_NULL) {
			phalcon_array_append(&pick_view, layout, PH_SEPARATE TSRMLS_CC);
		}
	}
	
	phalcon_update_property_zval(this_ptr, SL("_pickView"), pick_view TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Renders a partial view
 *
 * <code>
 * //Show a partial inside another view
 * $this->partial('shared/footer');
 * </code>
 *
 * @param string $partialPath
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, partial){

	zval *partial_path, *zfalse, *engines, *content;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &partial_path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(zfalse);
	ZVAL_BOOL(zfalse, 0);
	
	PHALCON_INIT_VAR(engines);
	PHALCON_CALL_METHOD(engines, this_ptr, "_loadtemplateengines", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(content);
	PHALCON_CALL_METHOD_PARAMS_5(content, this_ptr, "_enginerender", engines, partial_path, zfalse, zfalse, zfalse, PH_NO_CHECK);
	
	RETURN_CCTOR(content);
}

/**
 * Finishes the render process by stopping the output buffering
 */
PHP_METHOD(Phalcon_Mvc_View, finish){


	PHALCON_MM_GROW();

	PHALCON_CALL_FUNC_NORETURN("ob_end_clean");
	
	PHALCON_MM_RESTORE();
}

/**
 * Create a Phalcon\Cache based on the internal cache options
 *
 * @return Phalcon\Cache\Backend
 */
PHP_METHOD(Phalcon_Mvc_View, _createCache){

	zval *dependency_injector, *cache_service = NULL;
	zval *view_options, *cache_options, *view_cache;
	int eval_int;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the view cache services");
		return;
	}
	
	PHALCON_INIT_VAR(cache_service);
	ZVAL_STRING(cache_service, "viewCache", 1);
	
	PHALCON_INIT_VAR(view_options);
	phalcon_read_property(&view_options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(view_options) == IS_ARRAY) { 
		eval_int = phalcon_array_isset_string(view_options, SS("cache"));
		if (eval_int) {
			PHALCON_INIT_VAR(cache_options);
			phalcon_array_fetch_string(&cache_options, view_options, SL("cache"), PH_NOISY_CC);
			if (Z_TYPE_P(cache_options) == IS_ARRAY) { 
				eval_int = phalcon_array_isset_string(cache_options, SS("service"));
				if (eval_int) {
					PHALCON_INIT_NVAR(cache_service);
					phalcon_array_fetch_string(&cache_service, cache_options, SL("service"), PH_NOISY_CC);
				}
			}
		}
	}
	
	PHALCON_INIT_VAR(view_cache);
	PHALCON_CALL_METHOD_PARAMS_1(view_cache, dependency_injector, "getshared", cache_service, PH_NO_CHECK);
	
	RETURN_CCTOR(view_cache);
}

/**
 * Returns the cache instance used to cache
 *
 * @return Phalcon\Cache\Backend
 */
PHP_METHOD(Phalcon_Mvc_View, getCache){

	zval *cache = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(cache);
	phalcon_read_property(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	if (zend_is_true(cache)) {
		if (Z_TYPE_P(cache) != IS_OBJECT) {
			PHALCON_INIT_NVAR(cache);
			PHALCON_CALL_METHOD(cache, this_ptr, "_createcache", PH_NO_CHECK);
			phalcon_update_property_zval(this_ptr, SL("_cache"), cache TSRMLS_CC);
		}
	} else {
		PHALCON_INIT_NVAR(cache);
		PHALCON_CALL_METHOD(cache, this_ptr, "_createcache", PH_NO_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_cache"), cache TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(cache);
}

/**
 * Cache the actual view render to certain level
 *
 * @param boolean|array $options
 */
PHP_METHOD(Phalcon_Mvc_View, cache){

	zval *options = NULL, *view_options = NULL, *cache_options = NULL;
	zval *value = NULL, *key = NULL, *cache_level;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
		ZVAL_BOOL(options, 1);
	}
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		PHALCON_INIT_VAR(view_options);
		phalcon_read_property(&view_options, this_ptr, SL("_options"), PH_NOISY_CC);
		if (Z_TYPE_P(view_options) != IS_ARRAY) { 
			PHALCON_INIT_NVAR(view_options);
			array_init(view_options);
		}
		
		eval_int = phalcon_array_isset_string(view_options, SS("cache"));
		if (eval_int) {
			PHALCON_INIT_VAR(cache_options);
			phalcon_array_fetch_string(&cache_options, view_options, SL("cache"), PH_NOISY_CC);
		} else {
			PHALCON_INIT_NVAR(cache_options);
			array_init(cache_options);
		}
		
		
		if (!phalcon_valid_foreach(options TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(options);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
			
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(value);
			
			phalcon_array_update_zval(&cache_options, key, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
			
		ph_cycle_end_0:
		
		eval_int = phalcon_array_isset_string(cache_options, SS("level"));
		if (eval_int) {
			PHALCON_INIT_VAR(cache_level);
			phalcon_array_fetch_string(&cache_level, cache_options, SL("level"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_cacheLevel"), cache_level TSRMLS_CC);
		} else {
			phalcon_update_property_long(this_ptr, SL("_cacheLevel"), 5 TSRMLS_CC);
		}
		
		phalcon_array_update_string(&view_options, SL("cache"), &cache_options, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_options"), view_options TSRMLS_CC);
	} else {
		if (zend_is_true(options)) {
			phalcon_update_property_long(this_ptr, SL("_cacheLevel"), 5 TSRMLS_CC);
		} else {
			phalcon_update_property_long(this_ptr, SL("_cacheLevel"), 0 TSRMLS_CC);
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Externally sets the view content
 *
 *<code>
 *$this->view->setContent("<h1>hello</h1>");
 *</code>
 *
 * @param string $content
 */
PHP_METHOD(Phalcon_Mvc_View, setContent){

	zval *content;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &content) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(content) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Content must be a string");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_content"), content TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns cached ouput from another view stage
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getContent){

	zval *content;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(content);
	phalcon_read_property(&content, this_ptr, SL("_content"), PH_NOISY_CC);
	
	RETURN_CCTOR(content);
}

/**
 * Returns the path of the view that is currently rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getActiveRenderPath){

	zval *active_render_path;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(active_render_path);
	phalcon_read_property(&active_render_path, this_ptr, SL("_activeRenderPath"), PH_NOISY_CC);
	
	RETURN_CCTOR(active_render_path);
}

/**
 * Disables the auto-rendering process
 *
 */
PHP_METHOD(Phalcon_Mvc_View, disable){


	phalcon_update_property_bool(this_ptr, SL("_disabled"), 1 TSRMLS_CC);
	
}

/**
 * Enables the auto-rendering process
 *
 */
PHP_METHOD(Phalcon_Mvc_View, enable){


	phalcon_update_property_bool(this_ptr, SL("_disabled"), 0 TSRMLS_CC);
	
}

/**
 * Resets the view component to its factory default values
 *
 */
PHP_METHOD(Phalcon_Mvc_View, reset){


	phalcon_update_property_bool(this_ptr, SL("_disabled"), 0 TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_engines"), 0 TSRMLS_CC);
	phalcon_update_property_null(this_ptr, SL("_cache") TSRMLS_CC);
	phalcon_update_property_long(this_ptr, SL("_renderLevel"), 5 TSRMLS_CC);
	phalcon_update_property_long(this_ptr, SL("_cacheLevel"), 0 TSRMLS_CC);
	phalcon_update_property_null(this_ptr, SL("_content") TSRMLS_CC);
	
}

