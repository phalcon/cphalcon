
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
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"

/**
 * Phalcon\Mvc\View\Simple
 *
 * This component provides a simpler view component
 */


/**
 * Phalcon\Mvc\View\Simple initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_View_Simple){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\View, Simple, mvc_view_simple, "phalcon\\di\\injectable", phalcon_mvc_view_simple_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_viewsDir"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_viewParams"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_view_simple_ce, SL("_engines"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_registeredEngines"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_activeRenderPath"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_simple_ce, SL("_content"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\View constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, __construct){

	zval *options = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &options);
	
	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		phalcon_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
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
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Engines to register must be an array");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_registeredEngines"), engines TSRMLS_CC);
	
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
	phalcon_read_property_this(&engines, this_ptr, SL("_engines"), PH_NOISY_CC);
	
	/** 
	 * If the engines aren't initialized 'engines' is false
	 */
	if (PHALCON_IS_FALSE(engines)) {
	
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(engines);
		array_init(engines);
	
		PHALCON_OBS_VAR(registered_engines);
		phalcon_read_property_this(&registered_engines, this_ptr, SL("_registeredEngines"), PH_NOISY_CC);
		if (Z_TYPE_P(registered_engines) != IS_ARRAY) { 
			/** 
			 * We use Phalcon\Mvc\View\Engine\Php as default
			 */
			PHALCON_INIT_VAR(php_engine);
			object_init_ex(php_engine, phalcon_mvc_view_engine_php_ce);
			phalcon_call_method_p2_noret(php_engine, "__construct", this_ptr, dependency_injector);
	
			phalcon_array_update_string(&engines, SL(".phtml"), &php_engine, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the application services");
				return;
			}
	
			PHALCON_INIT_VAR(arguments);
			array_init_size(arguments, 2);
			phalcon_array_append(&arguments, this_ptr, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&arguments, dependency_injector, PH_SEPARATE TSRMLS_CC);
	
			if (!phalcon_is_iterable(registered_engines, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HKEY(extension, ah0, hp0);
				PHALCON_GET_HVALUE(engine_service);
	
				if (Z_TYPE_P(engine_service) == IS_OBJECT) {
	
					/** 
					 * Engine can be a closure
					 */
					if (phalcon_is_instance_of(engine_service, SL("Closure") TSRMLS_CC)) {
						PHALCON_INIT_NVAR(engine_object);
						PHALCON_CALL_USER_FUNC_ARRAY(engine_object, engine_service, arguments);
					} else {
						PHALCON_CPY_WRT(engine_object, engine_service);
					}
				} else {
					/** 
					 * Engine can be a string representing a service in the DI
					 */
					if (Z_TYPE_P(engine_service) == IS_STRING) {
						PHALCON_INIT_NVAR(engine_object);
						phalcon_call_method_p2(engine_object, dependency_injector, "getshared", engine_service, arguments);
					} else {
						PHALCON_INIT_NVAR(exception_message);
						PHALCON_CONCAT_SV(exception_message, "Invalid template engine registration for extension: ", extension);
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
						return;
					}
				}
				phalcon_array_update_zval(&engines, extension, &engine_object, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
	
		phalcon_update_property_this(this_ptr, SL("_engines"), engines TSRMLS_CC);
	} else {
		PHALCON_OBS_NVAR(engines);
		phalcon_read_property_this(&engines, this_ptr, SL("_engines"), PH_NOISY_CC);
	}
	
	RETURN_CCTOR(engines);
}

/**
 * Renders a view
 *
 * @param string $path
 * @param array $params
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, render){

	zval *path, *params = NULL, *events_manager, *event_name = NULL;
	zval *status = NULL, *not_exists = NULL, *must_clean, *view_params;
	zval *views_dir, *views_dir_path, *merged_params = NULL;
	zval *engines, *engine = NULL, *extension = NULL, *view_engine_path = NULL;
	zval *exception_message, *content;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &path, &params);
	
	if (!params) {
		PHALCON_INIT_VAR(params);
	}
	
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		phalcon_update_property_this(this_ptr, SL("_activeRenderPath"), path TSRMLS_CC);
	}
	
	/** 
	 * Call beforeRender if there is an events manager
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "view:beforeRender", 1);
	
		PHALCON_INIT_VAR(status);
		phalcon_call_method_p2(status, events_manager, "fire", event_name, this_ptr);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * Create a virtual symbol table
	 */
	phalcon_create_symbol_table(TSRMLS_C);
	
	phalcon_call_func_noret("ob_start");
	
	PHALCON_INIT_VAR(not_exists);
	ZVAL_BOOL(not_exists, 1);
	
	PHALCON_INIT_VAR(must_clean);
	ZVAL_BOOL(must_clean, 1);
	
	PHALCON_OBS_VAR(view_params);
	phalcon_read_property_this(&view_params, this_ptr, SL("_viewParams"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(views_dir);
	phalcon_read_property_this(&views_dir, this_ptr, SL("_viewsDir"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(views_dir_path);
	PHALCON_CONCAT_VV(views_dir_path, views_dir, path);
	
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
	 * Load the template engines
	 */
	PHALCON_INIT_VAR(engines);
	phalcon_call_method(engines, this_ptr, "_loadtemplateengines");
	
	/** 
	 * Views are rendered in each engine
	 */
	
	if (!phalcon_is_iterable(engines, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
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
	
				PHALCON_INIT_NVAR(status);
				phalcon_call_method_p3(status, events_manager, "fire", event_name, this_ptr, view_engine_path);
				if (PHALCON_IS_FALSE(status)) {
					zend_hash_move_forward_ex(ah0, &hp0);
					continue;
				}
			}
			phalcon_call_method_p3_noret(engine, "render", view_engine_path, merged_params, must_clean);
	
			/** 
			 * Call afterRenderView if there is a events manager available
			 */
			PHALCON_INIT_NVAR(not_exists);
			ZVAL_BOOL(not_exists, 0);
			if (Z_TYPE_P(events_manager) == IS_OBJECT) {
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "view:afterRenderView", 1);
				phalcon_call_method_p2_noret(events_manager, "fire", event_name, this_ptr);
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
		phalcon_call_method_p2_noret(events_manager, "fire", event_name, this_ptr);
	}
	
	phalcon_call_func_noret("ob_end_clean");
	
	PHALCON_OBS_VAR(content);
	phalcon_read_property_this(&content, this_ptr, SL("_content"), PH_NOISY_CC);
	
	RETURN_CCTOR(content);
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
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setParamToView){

	zval *key, *value;

	phalcon_fetch_params(0, 2, 0, &key, &value);
	
	phalcon_update_property_array(this_ptr, SL("_viewParams"), key, value TSRMLS_CC);
	
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
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setVars){

	zval *params, *merge = NULL, *view_params, *merged_params = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &params, &merge);
	
	if (!merge) {
		PHALCON_INIT_VAR(merge);
		ZVAL_BOOL(merge, 1);
	}
	
	if (Z_TYPE_P(params) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "The render parameters must be an array");
		return;
	}
	if (zend_is_true(merge)) {
	
		PHALCON_OBS_VAR(view_params);
		phalcon_read_property_this(&view_params, this_ptr, SL("_viewParams"), PH_NOISY_CC);
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
	
	PHALCON_MM_RESTORE();
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
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setVar){

	zval *key, *value;

	phalcon_fetch_params(0, 2, 0, &key, &value);
	
	phalcon_update_property_array(this_ptr, SL("_viewParams"), key, value TSRMLS_CC);
	
}

/**
 * Returns a parameter previously set in the view
 *
 * @param string $key
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, getVar){

	zval *key, *params, *value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key);
	
	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_viewParams"), PH_NOISY_CC);
	if (phalcon_array_isset(params, key)) {
		PHALCON_OBS_VAR(value);
		phalcon_array_fetch(&value, params, key, PH_NOISY_CC);
		RETURN_CCTOR(value);
	}
	
	RETURN_MM_NULL();
}

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
 */
PHP_METHOD(Phalcon_Mvc_View_Simple, setContent){

	zval *content;

	phalcon_fetch_params(0, 1, 0, &content);
	
	if (Z_TYPE_P(content) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Content must be a string");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);
	
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

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key);
	
	PHALCON_OBS_VAR(params);
	phalcon_read_property_this(&params, this_ptr, SL("_viewParams"), PH_NOISY_CC);
	if (phalcon_array_isset(params, key)) {
		PHALCON_OBS_VAR(value);
		phalcon_array_fetch(&value, params, key, PH_NOISY_CC);
		RETURN_CCTOR(value);
	}
	
	RETURN_MM_NULL();
}

