
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"

/**
 * Phalcon\Mvc\View
 *
 * Phalcon\Mvc\View is a class for working with the "view" portion of the model-view-controller pattern.
 * That is, it exists to help keep the view script separate from the model and controller scripts.
 * It provides a system of helpers, output filters, and variable escaping.
 *
 * 
 */

/**
 * Phalcon\Mvc\View constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_View, __construct){

	zval *options = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL;

	PHALCON_MM_GROW();
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_mvc_view_ce, this_ptr, SL("_viewParams"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a1);
	array_init(a1);
	zend_update_property(phalcon_mvc_view_ce, this_ptr, SL("_templatesBefore"), a1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a2);
	array_init(a2);
	zend_update_property(phalcon_mvc_view_ce, this_ptr, SL("_templatesAfter"), a2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a3);
	array_init(a3);
	zend_update_property(phalcon_mvc_view_ce, this_ptr, SL("_registeredEngines"), a3 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a4);
	array_init(a4);
	zend_update_property(phalcon_mvc_view_ce, this_ptr, SL("_params"), a4 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
		array_init(options);
	}
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Options parameter must be an array");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_options"), options TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injection container
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_View, setDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the dependency injection container
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Mvc_View, getDI){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Sets the event manager
 *
 * @param Phalcon\Events\Manager $eventsManager
 */
PHP_METHOD(Phalcon_Mvc_View, setEventsManager){

	zval *events_manager = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &events_manager) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets views directory. Depending of your platform, always add a trailing slash or backslash
 *
 * @param string $viewsDir
 */
PHP_METHOD(Phalcon_Mvc_View, setViewsDir){

	zval *views_dir = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &views_dir) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_viewsDir"), views_dir TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets views directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getViewsDir){

	zval *views_dir = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(views_dir);
	phalcon_read_property(&views_dir, this_ptr, SL("_viewsDir"), PH_NOISY_CC);
	
	RETURN_CCTOR(views_dir);
}

/**
 * Sets base path. Depending of your platform, always add a trailing slash or backslash
 *
 * @param string $basePath
 */
PHP_METHOD(Phalcon_Mvc_View, setBasePath){

	zval *base_path = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &base_path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_basePath"), base_path TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the render level for the view
 *
 * @param string $level
 */
PHP_METHOD(Phalcon_Mvc_View, setRenderLevel){

	zval *level = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &level) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_renderLevel"), level TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets default view name. Must be a file without extension in the views directory
 *
 * @param string $name
 */
PHP_METHOD(Phalcon_Mvc_View, setMainView){

	zval *view_path = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &view_path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_mainView"), view_path TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Appends template before controller layout
 *
 * @param string|array $templateBefore
 */
PHP_METHOD(Phalcon_Mvc_View, setTemplateBefore){

	zval *template_before = NULL, *array_template = NULL;

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


	PHALCON_MM_GROW();
	phalcon_update_property_null(this_ptr, SL("_templatesBefore") TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Appends template after controller layout
 *
 * @param string|array $templateAfter
 */
PHP_METHOD(Phalcon_Mvc_View, setTemplateAfter){

	zval *template_after = NULL, *array_template = NULL;

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


	PHALCON_MM_GROW();
	phalcon_update_property_null(this_ptr, SL("_templatesAfter") TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Adds parameters to views (alias of setVar)
 *
 * @param string $key
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Mvc_View, setParamToView){

	zval *key = NULL, *value = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &key, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
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

	zval *key = NULL, *value = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &key, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
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

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_viewParams"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Gets the name of the controller rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getControllerName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_controllerName"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Gets the name of the action rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getActionName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_actionName"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Gets extra parameters of the action rendered
 */
PHP_METHOD(Phalcon_Mvc_View, getParams){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_params"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
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

	zval *engines = NULL, *registered_engines = NULL, *number_engines = NULL;
	zval *php_engine = NULL, *dependency_injector = NULL, *arguments = NULL;
	zval *engine_service = NULL, *extension = NULL, *engine_object = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_engines"), PH_NOISY_CC);
	if (!zend_is_true(t0)) {
		PHALCON_INIT_VAR(engines);
		array_init(engines);
		
		PHALCON_INIT_VAR(registered_engines);
		phalcon_read_property(&registered_engines, this_ptr, SL("_registeredEngines"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(number_engines);
		phalcon_fast_count(number_engines, registered_engines TSRMLS_CC);
		if (!zend_is_true(number_engines)) {
			PHALCON_INIT_VAR(php_engine);
			object_init_ex(php_engine, phalcon_mvc_view_engine_php_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(php_engine, "__construct", this_ptr, PH_CHECK);
			phalcon_array_update_string(&engines, SL(".phtml"), &php_engine, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(dependency_injector);
			phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
			if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the view engine services");
				return;
			}
			
			PHALCON_INIT_VAR(arguments);
			array_init(arguments);
			phalcon_array_append(&arguments, this_ptr, PH_SEPARATE TSRMLS_CC);
			if (!phalcon_valid_foreach(registered_engines TSRMLS_CC)) {
				return;
			}
			
			ah0 = Z_ARRVAL_P(registered_engines);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_ecde_0:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_ecde_0;
				}
				
				PHALCON_INIT_VAR(extension);
				PHALCON_GET_FOREACH_KEY(extension, ah0, hp0);
				PHALCON_INIT_VAR(engine_service);
				ZVAL_ZVAL(engine_service, *hd, 1, 0);
				PHALCON_INIT_VAR(engine_object);
				PHALCON_CALL_METHOD_PARAMS_2(engine_object, dependency_injector, "getshared", engine_service, arguments, PH_NO_CHECK);
				phalcon_array_update_zval(&engines, extension, &engine_object, PH_COPY | PH_SEPARATE TSRMLS_CC);
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_ecde_0;
			fee_ecde_0:
			if(0){}
			
		}
		
		phalcon_update_property_zval(this_ptr, SL("_engines"), engines TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(engines);
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
 * @param Phalcon\Cache\Backend $cache
 */
PHP_METHOD(Phalcon_Mvc_View, _engineRender){

	zval *engines = NULL, *view_path = NULL, *silence = NULL, *cache = NULL, *not_exists = NULL;
	zval *view_params = NULL, *views_dir = NULL, *views_dir_path = NULL;
	zval *events_manager = NULL, *render_level = NULL, *cache_level = NULL;
	zval *key = NULL, *view_options = NULL, *cache_options = NULL, *cached_view = NULL;
	zval *is_fresh = NULL, *engine = NULL, *extension = NULL, *view_engine_path = NULL;
	zval *status = NULL, *exception_msg = NULL, *exception = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &engines, &view_path, &silence, &cache) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(not_exists);
	ZVAL_BOOL(not_exists, 1);
	
	PHALCON_INIT_VAR(view_params);
	phalcon_read_property(&view_params, this_ptr, SL("_viewParams"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(views_dir);
	phalcon_read_property(&views_dir, this_ptr, SL("_viewsDir"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_basePath"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(views_dir_path);
	PHALCON_CONCAT_VVV(views_dir_path, t0, views_dir, view_path);
	
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (zend_is_true(cache)) {
		PHALCON_INIT_VAR(render_level);
		phalcon_read_property(&render_level, this_ptr, SL("_renderLevel"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(cache_level);
		phalcon_read_property(&cache_level, this_ptr, SL("_cacheLevel"), PH_NOISY_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		is_smaller_or_equal_function(r0, cache_level, render_level TSRMLS_CC);
		if (zend_is_true(r0)) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_METHOD(r1, cache, "isstarted", PH_NO_CHECK);
			if (!zend_is_true(r1)) {
				PHALCON_INIT_VAR(key);
				ZVAL_NULL(key);
				
				PHALCON_INIT_VAR(view_options);
				phalcon_read_property(&view_options, this_ptr, SL("_options"), PH_NOISY_CC);
				eval_int = phalcon_array_isset_string(view_options, SL("cache")+1);
				if (eval_int) {
					PHALCON_INIT_VAR(cache_options);
					phalcon_array_fetch_string(&cache_options, view_options, SL("cache"), PH_NOISY_CC);
					if (Z_TYPE_P(cache_options) == IS_ARRAY) { 
						eval_int = phalcon_array_isset_string(cache_options, SL("key")+1);
						if (eval_int) {
							PHALCON_INIT_VAR(key);
							phalcon_array_fetch_string(&key, cache_options, SL("key"), PH_NOISY_CC);
						}
					}
				}
				
				if (!zend_is_true(key)) {
					PHALCON_INIT_VAR(key);
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
	fes_ecde_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_ecde_1;
		}
		
		PHALCON_INIT_VAR(extension);
		PHALCON_GET_FOREACH_KEY(extension, ah0, hp0);
		PHALCON_INIT_VAR(engine);
		ZVAL_ZVAL(engine, *hd, 1, 0);
		PHALCON_INIT_VAR(view_engine_path);
		PHALCON_CONCAT_VV(view_engine_path, views_dir_path, extension);
		if (phalcon_file_exists(view_engine_path TSRMLS_CC) == SUCCESS) {
			if (zend_is_true(events_manager)) {
				phalcon_update_property_zval(this_ptr, SL("_activeRenderPath"), view_engine_path TSRMLS_CC);
				
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, "view:beforeRender", 1);
				
				PHALCON_INIT_VAR(status);
				PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", c0, this_ptr, PH_NO_CHECK);
				if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
					zend_hash_move_forward_ex(ah0, &hp0);
					goto fes_ecde_1;
				}
			}
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(engine, "render", view_engine_path, view_params, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(not_exists);
			ZVAL_BOOL(not_exists, 0);
			goto fee_ecde_1;
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_ecde_1;
	fee_ecde_1:
	
	if (zend_is_true(not_exists)) {
		if (!zend_is_true(silence)) {
			PHALCON_INIT_VAR(exception_msg);
			PHALCON_CONCAT_SVS(exception_msg, "View '", views_dir_path, "' was not found in the views directory");
			
			PHALCON_INIT_VAR(exception);
			object_init_ex(exception, phalcon_mvc_view_exception_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_msg, PH_CHECK);
			phalcon_throw_exception(exception TSRMLS_CC);
			return;
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Register templating engines
 *
 * @param array $engines
 */
PHP_METHOD(Phalcon_Mvc_View, registerEngines){

	zval *engines = NULL;

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
 * @param string $controllerName
 * @param string $actionName
 * @param array $params
 */
PHP_METHOD(Phalcon_Mvc_View, render){

	zval *controller_name = NULL, *action_name = NULL, *params = NULL;
	zval *layouts_dir = NULL, *engines = NULL, *pick_view = NULL, *render_view = NULL;
	zval *render_controller = NULL, *pick_view_action = NULL;
	zval *cache = NULL, *cache_level = NULL, *silence = NULL, *render_level = NULL;
	zval *templates_before = NULL, *template_before = NULL;
	zval *view_temp_path = NULL, *templates_after = NULL, *template_after = NULL;
	zval *main_view = NULL, *is_started = NULL, *is_fresh = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
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
		PHALCON_INIT_VAR(params);
		array_init(params);
	}
	
	PHALCON_INIT_VAR(layouts_dir);
	phalcon_read_property(&layouts_dir, this_ptr, SL("_layoutsDir"), PH_NOISY_CC);
	if (!zend_is_true(layouts_dir)) {
		PHALCON_INIT_VAR(layouts_dir);
		ZVAL_STRING(layouts_dir, "layouts/", 1);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_controllerName"), controller_name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_params"), params TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_initEngines"), 0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(engines);
	PHALCON_CALL_METHOD(engines, this_ptr, "_loadtemplateengines", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(pick_view);
	phalcon_read_property(&pick_view, this_ptr, SL("_pickView"), PH_NOISY_CC);
	if (!zend_is_true(pick_view)) {
		PHALCON_INIT_VAR(render_view);
		PHALCON_CONCAT_VSV(render_view, controller_name, "/", action_name);
		PHALCON_CPY_WRT(render_controller, controller_name);
	} else {
		PHALCON_INIT_VAR(render_view);
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
	ZVAL_NULL(cache);
	
	PHALCON_INIT_VAR(cache_level);
	phalcon_read_property(&cache_level, this_ptr, SL("_cacheLevel"), PH_NOISY_CC);
	if (zend_is_true(cache_level)) {
		PHALCON_INIT_VAR(cache);
		PHALCON_CALL_METHOD(cache, this_ptr, "getcache", PH_NO_CHECK);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "ob_get_contents");
	phalcon_update_property_zval(this_ptr, SL("_content"), r0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(silence);
	ZVAL_BOOL(silence, 1);
	
	PHALCON_INIT_VAR(render_level);
	phalcon_read_property(&render_level, this_ptr, SL("_renderLevel"), PH_NOISY_CC);
	if (zend_is_true(render_level)) {
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 1);
		PHALCON_ALLOC_ZVAL_MM(r1);
		is_smaller_or_equal_function(r1, t0, render_level TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_CALL_METHOD_PARAMS_4_NORETURN(this_ptr, "_enginerender", engines, render_view, silence, cache, PH_NO_CHECK);
		}
		
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 2);
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		is_smaller_or_equal_function(r2, t1, render_level TSRMLS_CC);
		if (zend_is_true(r2)) {
			PHALCON_INIT_VAR(templates_before);
			phalcon_read_property(&templates_before, this_ptr, SL("_templatesBefore"), PH_NOISY_CC);
			if (zend_is_true(templates_before)) {
				PHALCON_INIT_VAR(silence);
				ZVAL_BOOL(silence, 0);
				if (Z_TYPE_P(templates_before) == IS_ARRAY) { 
					if (!phalcon_valid_foreach(templates_before TSRMLS_CC)) {
						return;
					}
					
					ah0 = Z_ARRVAL_P(templates_before);
					zend_hash_internal_pointer_reset_ex(ah0, &hp0);
					fes_ecde_2:
						if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
							goto fee_ecde_2;
						}
						
						PHALCON_INIT_VAR(template_before);
						ZVAL_ZVAL(template_before, *hd, 1, 0);
						PHALCON_INIT_VAR(view_temp_path);
						PHALCON_CONCAT_VV(view_temp_path, layouts_dir, template_before);
						PHALCON_CALL_METHOD_PARAMS_4_NORETURN(this_ptr, "_enginerender", engines, view_temp_path, silence, cache, PH_NO_CHECK);
						zend_hash_move_forward_ex(ah0, &hp0);
						goto fes_ecde_2;
					fee_ecde_2:
					if(0){}
					
				} else {
					PHALCON_INIT_VAR(view_temp_path);
					PHALCON_CONCAT_VV(view_temp_path, layouts_dir, template_before);
					PHALCON_CALL_METHOD_PARAMS_4_NORETURN(this_ptr, "_enginerender", engines, view_temp_path, silence, cache, PH_NO_CHECK);
				}
				
				PHALCON_INIT_VAR(silence);
				ZVAL_BOOL(silence, 1);
			}
		}
		
		PHALCON_INIT_VAR(t2);
		ZVAL_LONG(t2, 3);
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		is_smaller_or_equal_function(r3, t2, render_level TSRMLS_CC);
		if (zend_is_true(r3)) {
			PHALCON_INIT_VAR(view_temp_path);
			PHALCON_CONCAT_VV(view_temp_path, layouts_dir, render_controller);
			PHALCON_CALL_METHOD_PARAMS_4_NORETURN(this_ptr, "_enginerender", engines, view_temp_path, silence, cache, PH_NO_CHECK);
		}
		
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 4);
		
		PHALCON_ALLOC_ZVAL_MM(r4);
		is_smaller_or_equal_function(r4, t3, render_level TSRMLS_CC);
		if (zend_is_true(r4)) {
			PHALCON_INIT_VAR(templates_after);
			phalcon_read_property(&templates_after, this_ptr, SL("_templatesAfter"), PH_NOISY_CC);
			if (zend_is_true(templates_after)) {
				PHALCON_INIT_VAR(silence);
				ZVAL_BOOL(silence, 0);
				if (Z_TYPE_P(templates_after) == IS_ARRAY) { 
					if (!phalcon_valid_foreach(templates_after TSRMLS_CC)) {
						return;
					}
					
					ah1 = Z_ARRVAL_P(templates_after);
					zend_hash_internal_pointer_reset_ex(ah1, &hp1);
					fes_ecde_3:
						if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
							goto fee_ecde_3;
						}
						
						PHALCON_INIT_VAR(template_after);
						ZVAL_ZVAL(template_after, *hd, 1, 0);
						PHALCON_INIT_VAR(view_temp_path);
						PHALCON_CONCAT_VV(view_temp_path, layouts_dir, template_after);
						PHALCON_CALL_METHOD_PARAMS_4_NORETURN(this_ptr, "_enginerender", engines, view_temp_path, silence, cache, PH_NO_CHECK);
						zend_hash_move_forward_ex(ah1, &hp1);
						goto fes_ecde_3;
					fee_ecde_3:
					if(0){}
					
				} else {
					PHALCON_INIT_VAR(view_temp_path);
					PHALCON_CONCAT_VV(view_temp_path, layouts_dir, templates_after);
					PHALCON_CALL_METHOD_PARAMS_4_NORETURN(this_ptr, "_enginerender", engines, view_temp_path, silence, cache, PH_NO_CHECK);
				}
				
				PHALCON_INIT_VAR(silence);
				ZVAL_BOOL(silence, 1);
			}
		}
		
		PHALCON_INIT_VAR(t4);
		ZVAL_LONG(t4, 5);
		
		PHALCON_ALLOC_ZVAL_MM(r5);
		is_smaller_or_equal_function(r5, t4, render_level TSRMLS_CC);
		if (zend_is_true(r5)) {
			PHALCON_INIT_VAR(main_view);
			phalcon_read_property(&main_view, this_ptr, SL("_mainView"), PH_NOISY_CC);
			PHALCON_CALL_METHOD_PARAMS_4_NORETURN(this_ptr, "_enginerender", engines, main_view, silence, cache, PH_NO_CHECK);
		}
		
		if (zend_is_true(cache)) {
			PHALCON_INIT_VAR(is_started);
			PHALCON_CALL_METHOD(is_started, cache, "isstarted", PH_NO_CHECK);
			if (zend_is_true(is_started)) {
				PHALCON_INIT_VAR(is_fresh);
				PHALCON_CALL_METHOD(is_fresh, cache, "isfresh", PH_NO_CHECK);
				if (zend_is_true(is_fresh)) {
					PHALCON_CALL_METHOD_NORETURN(cache, "save", PH_NO_CHECK);
				}
			}
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Choose a view different to render than last-controller/last-action
 *
 * @param string $renderView
 */
PHP_METHOD(Phalcon_Mvc_View, pick){

	zval *render_view = NULL, *separator = NULL, *pick_view = NULL, *layout = NULL;
	zval *have_separator = NULL, *parts = NULL;

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
		ZVAL_NULL(layout);
		
		PHALCON_INIT_VAR(have_separator);
		phalcon_fast_strpos(have_separator, render_view, separator TSRMLS_CC);
		if (zend_is_true(have_separator)) {
			PHALCON_INIT_VAR(parts);
			phalcon_fast_explode(parts, separator, render_view TSRMLS_CC);
			
			PHALCON_INIT_VAR(layout);
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
 * @param string $partialPath
 */
PHP_METHOD(Phalcon_Mvc_View, partial){

	zval *partial_path = NULL, *vfalse = NULL, *previous_content = NULL;
	zval *engines = NULL, *new_content = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &partial_path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(vfalse);
	ZVAL_BOOL(vfalse, 0);
	
	PHALCON_INIT_VAR(previous_content);
	phalcon_read_property(&previous_content, this_ptr, SL("_content"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(engines);
	PHALCON_CALL_METHOD(engines, this_ptr, "_loadtemplateengines", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_4_NORETURN(this_ptr, "_enginerender", engines, partial_path, vfalse, vfalse, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(new_content);
	phalcon_read_property(&new_content, this_ptr, SL("_content"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_VV(r0, previous_content, new_content);
	phalcon_update_property_zval(this_ptr, SL("_content"), r0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
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

	zval *dependency_injector = NULL, *cache_service = NULL;
	zval *view_options = NULL, *cache_options = NULL, *view_cache = NULL;
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
	eval_int = phalcon_array_isset_string(view_options, SL("cache")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(cache_options);
		phalcon_array_fetch_string(&cache_options, view_options, SL("cache"), PH_NOISY_CC);
		if (Z_TYPE_P(cache_options) == IS_ARRAY) { 
			eval_int = phalcon_array_isset_string(cache_options, SL("key")+1);
			if (eval_int) {
				PHALCON_INIT_VAR(cache_service);
				phalcon_array_fetch_string(&cache_service, cache_options, SL("key"), PH_NOISY_CC);
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
			PHALCON_INIT_VAR(cache);
			PHALCON_CALL_METHOD(cache, this_ptr, "_createcache", PH_NO_CHECK);
			phalcon_update_property_zval(this_ptr, SL("_cache"), cache TSRMLS_CC);
		}
	} else {
		PHALCON_INIT_VAR(cache);
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
	zval *value = NULL, *key = NULL, *cache_level = NULL;
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
		PHALCON_ALLOC_ZVAL_MM(options);
		ZVAL_BOOL(options, 1);
	}
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		PHALCON_INIT_VAR(view_options);
		phalcon_read_property(&view_options, this_ptr, SL("_options"), PH_NOISY_CC);
		eval_int = phalcon_array_isset_string(view_options, SL("cache")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(cache_options);
			phalcon_array_fetch_string(&cache_options, view_options, SL("cache"), PH_NOISY_CC);
		} else {
			PHALCON_INIT_VAR(cache_options);
			array_init(cache_options);
		}
		
		if (!phalcon_valid_foreach(options TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(options);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_ecde_4:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_ecde_4;
			}
			
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			phalcon_array_update_zval(&cache_options, key, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_ecde_4;
		fee_ecde_4:
		
		eval_int = phalcon_array_isset_string(cache_options, SL("level")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(cache_level);
			phalcon_array_fetch_string(&cache_level, cache_options, SL("level"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_cacheLevel"), cache_level TSRMLS_CC);
		} else {
			phalcon_update_property_long(this_ptr, SL("_cacheLevel"), 5 TSRMLS_CC);
		}
		
		phalcon_update_property_zval(view_options, SL("cache"), cache_options TSRMLS_CC);
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
 * @param string $content
 */
PHP_METHOD(Phalcon_Mvc_View, setContent){

	zval *content = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &content) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
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

	zval *content = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(content);
	phalcon_read_property(&content, this_ptr, SL("_content"), PH_NOISY_CC);
	
	RETURN_CCTOR(content);
}

PHP_METHOD(Phalcon_Mvc_View, getActiveRenderPath){

	zval *active_render_path = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(active_render_path);
	phalcon_read_property(&active_render_path, this_ptr, SL("_activeRenderPath"), PH_NOISY_CC);
	
	RETURN_CCTOR(active_render_path);
}

/**
 * Disable view. No show any view or template
 *
 */
PHP_METHOD(Phalcon_Mvc_View, disable){


	PHALCON_MM_GROW();
	phalcon_update_property_long(this_ptr, SL("_renderLevel"), 0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

