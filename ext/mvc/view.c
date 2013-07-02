
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/output.h"

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
 * Phalcon\Mvc\View initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_View){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc, View, mvc_view, "phalcon\\di\\injectable", phalcon_mvc_view_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_view_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_view_ce, SL("_basePath"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_view_ce, SL("_content"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_view_ce, SL("_renderLevel"), 5, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_disabledLevels"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_viewParams"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_layout"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_view_ce, SL("_layoutsDir"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_view_ce, SL("_partialsDir"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_viewsDir"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_templatesBefore"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_templatesAfter"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_view_ce, SL("_engines"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_registeredEngines"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_view_ce, SL("_mainView"), "index", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_controllerName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_actionName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_pickView"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_cache"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_view_ce, SL("_cacheLevel"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_ce, SL("_activeRenderPath"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_view_ce, SL("_disabled"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_MAIN_LAYOUT"), 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_AFTER_TEMPLATE"), 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_LAYOUT"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_BEFORE_TEMPLATE"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_ACTION_VIEW"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_view_ce, SL("LEVEL_NO_RENDER"), 0 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_view_ce TSRMLS_CC, 1, phalcon_mvc_viewinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\View constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_View, __construct){

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
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, setViewsDir){

	zval *views_dir;

	phalcon_fetch_params(0, 1, 0, &views_dir);
	
	if (Z_TYPE_P(views_dir) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, "The views directory must be a string");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_viewsDir"), views_dir TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Gets views directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getViewsDir){


	RETURN_MEMBER(this_ptr, "_viewsDir");
}

/**
 * Sets the layouts sub-directory. Must be a directory under the views directory. Depending of your platform, always add a trailing slash or backslash
 *
 *<code>
 * $view->setLayoutsDir('../common/layouts/');
 *</code>
 *
 * @param string $layoutsDir
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, setLayoutsDir){

	zval *layouts_dir;

	phalcon_fetch_params(0, 1, 0, &layouts_dir);
	
	phalcon_update_property_this(this_ptr, SL("_layoutsDir"), layouts_dir TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Gets the current layouts sub-directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getLayoutsDir){


	RETURN_MEMBER(this_ptr, "_layoutsDir");
}

/**
 * Sets a partials sub-directory. Must be a directory under the views directory. Depending of your platform, always add a trailing slash or backslash
 *
 *<code>
 * $view->setPartialsDir('../common/partials/');
 *</code>
 *
 * @param string $partialsDir
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, setPartialsDir){

	zval *partials_dir;

	phalcon_fetch_params(0, 1, 0, &partials_dir);
	
	phalcon_update_property_this(this_ptr, SL("_partialsDir"), partials_dir TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Gets the current partials sub-directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getPartialsDir){


	RETURN_MEMBER(this_ptr, "_partialsDir");
}

/**
 * Sets base path. Depending of your platform, always add a trailing slash or backslash
 *
 * <code>
 * 	$view->setBasePath(__DIR__ . '/');
 * </code>
 *
 * @param string $basePath
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, setBasePath){

	zval *base_path;

	phalcon_fetch_params(0, 1, 0, &base_path);
	
	phalcon_update_property_this(this_ptr, SL("_basePath"), base_path TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Sets the render level for the view
 *
 * <code>
 * 	//Render the view related to the controller only
 * 	$this->view->setRenderLevel(View::LEVEL_VIEW);
 * </code>
 *
 * @param string $level
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, setRenderLevel){

	zval *level;

	phalcon_fetch_params(0, 1, 0, &level);
	
	phalcon_update_property_this(this_ptr, SL("_renderLevel"), level TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Disables a specific level of rendering
 *
 *<code>
 * //Render all levels except ACTION level
 * $this->view->disableLevel(View::LEVEL_ACTION_VIEW);
 *</code>
 *
 * @param int|array $level
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, disableLevel){

	zval *level, *disabled;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &level);
	
	if (Z_TYPE_P(level) == IS_ARRAY) { 
		phalcon_update_property_this(this_ptr, SL("_disabledLevels"), level TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(disabled);
		ZVAL_BOOL(disabled, 1);
		phalcon_update_property_array(this_ptr, SL("_disabledLevels"), level, disabled TSRMLS_CC);
	}
	
	RETURN_THIS();
}

/**
 * Sets default view name. Must be a file without extension in the views directory
 *
 * <code>
 * 	//Renders as main view views-dir/base.phtml
 * 	$this->view->setMainView('base');
 * </code>
 *
 * @param string $viewPath
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, setMainView){

	zval *view_path;

	phalcon_fetch_params(0, 1, 0, &view_path);
	
	phalcon_update_property_this(this_ptr, SL("_mainView"), view_path TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the name of the main view
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getMainView){


	RETURN_MEMBER(this_ptr, "_mainView");
}

/**
 * Change the layout to be used instead of using the name of the latest controller name
 *
 * <code>
 * 	$this->view->setLayout('main');
 * </code>
 *
 * @param string $layout
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, setLayout){

	zval *layout;

	phalcon_fetch_params(0, 1, 0, &layout);
	
	phalcon_update_property_this(this_ptr, SL("_layout"), layout TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the name of the main view
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getLayout){


	RETURN_MEMBER(this_ptr, "_layout");
}

/**
 * Appends template before controller layout
 *
 * @param string|array $templateBefore
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, setTemplateBefore){

	zval *template_before, *array_template;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &template_before);
	
	if (Z_TYPE_P(template_before) != IS_ARRAY) { 
		PHALCON_INIT_VAR(array_template);
		array_init_size(array_template, 1);
		phalcon_array_append(&array_template, template_before, PH_SEPARATE TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_templatesBefore"), array_template TSRMLS_CC);
	} else {
		phalcon_update_property_this(this_ptr, SL("_templatesBefore"), template_before TSRMLS_CC);
	}
	
	RETURN_THIS();
}

/**
 * Resets any template before layouts
 *
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, cleanTemplateBefore){


	phalcon_update_property_null(this_ptr, SL("_templatesBefore") TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Appends template after controller layout
 *
 * @param string|array $templateAfter
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, setTemplateAfter){

	zval *template_after, *array_template;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &template_after);
	
	if (Z_TYPE_P(template_after) != IS_ARRAY) { 
		PHALCON_INIT_VAR(array_template);
		array_init_size(array_template, 1);
		phalcon_array_append(&array_template, template_after, PH_SEPARATE TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_templatesAfter"), array_template TSRMLS_CC);
	} else {
		phalcon_update_property_this(this_ptr, SL("_templatesAfter"), template_after TSRMLS_CC);
	}
	
	RETURN_THIS();
}

/**
 * Resets any template before layouts
 *
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, cleanTemplateAfter){


	phalcon_update_property_null(this_ptr, SL("_templatesAfter") TSRMLS_CC);
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
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, setParamToView){

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
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, setVars){

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
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, setVar){

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
 */
PHP_METHOD(Phalcon_Mvc_View, getVar){

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
PHP_METHOD(Phalcon_Mvc_View, getParamsToView){


	RETURN_MEMBER(this_ptr, "_viewParams");
}

/**
 * Gets the name of the controller rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getControllerName){


	RETURN_MEMBER(this_ptr, "_controllerName");
}

/**
 * Gets the name of the action rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getActionName){


	RETURN_MEMBER(this_ptr, "_actionName");
}

/**
 * Gets extra parameters of the action rendered
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View, getParams){


	RETURN_MEMBER(this_ptr, "_params");
}

/**
 * Starts rendering process enabling the output buffering
 *
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, start){


	phalcon_update_property_null(this_ptr, SL("_content") TSRMLS_CC);
	phalcon_ob_start(TSRMLS_C);
	RETURN_THISW();
}

/**
 * Loads registered template engines, if none is registered it will use Phalcon\Mvc\View\Engine\Php
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View, _loadTemplateEngines){

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
	
			phalcon_is_iterable(registered_engines, &ah0, &hp0, 0, 0);
	
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
 * Checks whether view exists on registered extensions and render it
 *
 * @param array $engines
 * @param string $viewPath
 * @param boolean $silence
 * @param boolean $mustClean
 * @param Phalcon\Cache\BackendInterface $cache
 */
PHP_METHOD(Phalcon_Mvc_View, _engineRender){

	zval *engines, *view_path, *silence, *must_clean;
	zval *cache, *not_exists = NULL, *views_dir, *base_path;
	zval *views_dir_path, *render_level, *cache_level;
	zval *is_started, *key = NULL, *lifetime = NULL, *view_options;
	zval *cache_options, *cached_view, *is_fresh;
	zval *view_params, *events_manager, *engine = NULL;
	zval *extension = NULL, *view_engine_path = NULL, *event_name = NULL;
	zval *status = NULL, *exception_message;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 5, 0, &engines, &view_path, &silence, &must_clean, &cache);
	
	PHALCON_INIT_VAR(not_exists);
	ZVAL_BOOL(not_exists, 1);
	
	PHALCON_OBS_VAR(views_dir);
	phalcon_read_property_this(&views_dir, this_ptr, SL("_viewsDir"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(base_path);
	phalcon_read_property_this(&base_path, this_ptr, SL("_basePath"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(views_dir_path);
	PHALCON_CONCAT_VVV(views_dir_path, base_path, views_dir, view_path);
	
	if (Z_TYPE_P(cache) == IS_OBJECT) {
	
		PHALCON_OBS_VAR(render_level);
		phalcon_read_property_this(&render_level, this_ptr, SL("_renderLevel"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(cache_level);
		phalcon_read_property_this(&cache_level, this_ptr, SL("_cacheLevel"), PH_NOISY_CC);
		if (PHALCON_GE(render_level, cache_level)) {
	
			/** 
			 * Check if the cache is started, the first time a cache is started we start the
			 * cache
			 */
			PHALCON_INIT_VAR(is_started);
			phalcon_call_method(is_started, cache, "isstarted");
			if (PHALCON_IS_FALSE(is_started)) {
	
				PHALCON_INIT_VAR(key);
	
				PHALCON_INIT_VAR(lifetime);
	
				PHALCON_OBS_VAR(view_options);
				phalcon_read_property_this(&view_options, this_ptr, SL("_options"), PH_NOISY_CC);
	
				/** 
				 * Check if the user has defined a different options to the default
				 */
				if (Z_TYPE_P(view_options) == IS_ARRAY) { 
					if (phalcon_array_isset_string(view_options, SS("cache"))) {
	
						PHALCON_OBS_VAR(cache_options);
						phalcon_array_fetch_string(&cache_options, view_options, SL("cache"), PH_NOISY_CC);
						if (Z_TYPE_P(cache_options) == IS_ARRAY) { 
							if (phalcon_array_isset_string(cache_options, SS("key"))) {
								PHALCON_OBS_NVAR(key);
								phalcon_array_fetch_string(&key, cache_options, SL("key"), PH_NOISY_CC);
							}
							if (phalcon_array_isset_string(cache_options, SS("lifetime"))) {
								PHALCON_OBS_NVAR(lifetime);
								phalcon_array_fetch_string(&lifetime, cache_options, SL("lifetime"), PH_NOISY_CC);
							}
						}
					}
				}
	
				/** 
				 * If a cache key is not set we create one using a md5
				 */
				if (Z_TYPE_P(key) == IS_NULL) {
					PHALCON_INIT_NVAR(key);
					phalcon_md5(key, view_path);
				}
	
				/** 
				 * We start the cache using the key set
				 */
				PHALCON_INIT_VAR(cached_view);
				phalcon_call_method_p2(cached_view, cache, "start", key, lifetime);
				if (Z_TYPE_P(cached_view) != IS_NULL) {
					phalcon_update_property_this(this_ptr, SL("_content"), cached_view TSRMLS_CC);
					RETURN_MM_NULL();
				}
			}
	
			/** 
			 * This method only returns true if the cache has not expired
			 */
			PHALCON_INIT_VAR(is_fresh);
			phalcon_call_method(is_fresh, cache, "isfresh");
			if (!zend_is_true(is_fresh)) {
				RETURN_MM_NULL();
			}
		}
	}
	
	PHALCON_OBS_VAR(view_params);
	phalcon_read_property_this(&view_params, this_ptr, SL("_viewParams"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
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
				phalcon_update_property_this(this_ptr, SL("_activeRenderPath"), view_engine_path TSRMLS_CC);
	
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "view:beforeRenderView", 1);
	
				PHALCON_INIT_NVAR(status);
				phalcon_call_method_p3(status, events_manager, "fire", event_name, this_ptr, view_engine_path);
				if (PHALCON_IS_FALSE(status)) {
					zend_hash_move_forward_ex(ah0, &hp0);
					continue;
				}
			}
			phalcon_call_method_p3_noret(engine, "render", view_engine_path, view_params, must_clean);
	
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
	
	if (PHALCON_IS_TRUE(not_exists)) {
	
		/** 
		 * Notify about not found views
		 */
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			phalcon_update_property_this(this_ptr, SL("_activeRenderPath"), view_engine_path TSRMLS_CC);
	
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "view:notFoundView", 1);
			phalcon_call_method_p2_noret(events_manager, "fire", event_name, this_ptr);
		}
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
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, registerEngines){

	zval *engines;

	phalcon_fetch_params(0, 1, 0, &engines);
	
	if (Z_TYPE_P(engines) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, "Engines to register must be an array");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_registeredEngines"), engines TSRMLS_CC);
	
	RETURN_THISW();
}

/**
 * Executes render process from dispatching data
 *
 *<code>
 * //Shows recent posts view (app/views/posts/recent.phtml)
 * $view->start()->render('posts', 'recent')->finish();
 *</code>
 *
 * @param string $controllerName
 * @param string $actionName
 * @param array $params
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, render){

	zval *controller_name, *action_name, *params = NULL;
	zval *disabled, *contents = NULL, *layouts_dir = NULL, *layout;
	zval *layout_name = NULL, *engines, *pick_view, *render_view = NULL;
	zval *pick_view_action, *cache = NULL, *cache_level;
	zval *events_manager, *event_name = NULL, *status, *must_clean;
	zval *silence = NULL, *disabled_levels, *render_level;
	zval *templates_before, *template_before = NULL;
	zval *view_temp_path = NULL, *templates_after, *template_after = NULL;
	zval *main_view, *is_started, *is_fresh;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &controller_name, &action_name, &params);
	
	if (!params) {
		PHALCON_INIT_VAR(params);
	}
	
	/** 
	 * If the view is disabled we simply update the buffer from any output produced in
	 * the controller
	 */
	PHALCON_OBS_VAR(disabled);
	phalcon_read_property_this(&disabled, this_ptr, SL("_disabled"), PH_NOISY_CC);
	if (PHALCON_IS_NOT_FALSE(disabled)) {
		PHALCON_INIT_VAR(contents);
		phalcon_ob_get_contents(contents TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_content"), contents TSRMLS_CC);
		RETURN_MM_FALSE;
	}
	
	phalcon_update_property_this(this_ptr, SL("_controllerName"), controller_name TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_params"), params TSRMLS_CC);
	
	/** 
	 * Check if there is a layouts directory set
	 */
	PHALCON_OBS_VAR(layouts_dir);
	phalcon_read_property_this(&layouts_dir, this_ptr, SL("_layoutsDir"), PH_NOISY_CC);
	if (!zend_is_true(layouts_dir)) {
		PHALCON_INIT_NVAR(layouts_dir);
		ZVAL_STRING(layouts_dir, "layouts/", 1);
	}
	
	/** 
	 * Check if the user has defined a custom layout
	 */
	PHALCON_OBS_VAR(layout);
	phalcon_read_property_this(&layout, this_ptr, SL("_layout"), PH_NOISY_CC);
	if (zend_is_true(layout)) {
		PHALCON_CPY_WRT(layout_name, layout);
	} else {
		PHALCON_CPY_WRT(layout_name, controller_name);
	}
	
	/** 
	 * Load the template engines
	 */
	PHALCON_INIT_VAR(engines);
	phalcon_call_method(engines, this_ptr, "_loadtemplateengines");
	
	/** 
	 * Check if the user has picked a view diferent than the automatic
	 */
	PHALCON_OBS_VAR(pick_view);
	phalcon_read_property_this(&pick_view, this_ptr, SL("_pickView"), PH_NOISY_CC);
	if (Z_TYPE_P(pick_view) == IS_NULL) {
		PHALCON_INIT_VAR(render_view);
		PHALCON_CONCAT_VSV(render_view, controller_name, "/", action_name);
	} else {
		/** 
		 * The 'picked' view is an array, where the first element is controller and the
		 * second the action
		 */
		PHALCON_OBS_NVAR(render_view);
		phalcon_array_fetch_long(&render_view, pick_view, 0, PH_NOISY_CC);
		if (phalcon_array_isset_long(pick_view, 1)) {
			PHALCON_OBS_VAR(pick_view_action);
			phalcon_array_fetch_long(&pick_view_action, pick_view, 1, PH_NOISY_CC);
			PHALCON_CPY_WRT(layout_name, pick_view_action);
		}
	}
	
	PHALCON_INIT_VAR(cache);
	
	/** 
	 * Start the cache if there is a cache level enabled
	 */
	PHALCON_OBS_VAR(cache_level);
	phalcon_read_property_this(&cache_level, this_ptr, SL("_cacheLevel"), PH_NOISY_CC);
	if (zend_is_true(cache_level)) {
		phalcon_call_method(cache, this_ptr, "getcache");
	}
	
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
	/** 
	 * Create a virtual symbol table
	 */
	phalcon_create_symbol_table(TSRMLS_C);
	
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
	 * Get the current content in the buffer maybe some output from the controller
	 */
	PHALCON_INIT_NVAR(contents);
	phalcon_ob_get_contents(contents TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_content"), contents TSRMLS_CC);
	
	PHALCON_INIT_VAR(must_clean);
	ZVAL_BOOL(must_clean, 1);
	
	PHALCON_INIT_VAR(silence);
	ZVAL_BOOL(silence, 1);
	
	/** 
	 * Disabled levels allow to avoid an specific level of rendering
	 */
	PHALCON_OBS_VAR(disabled_levels);
	phalcon_read_property_this(&disabled_levels, this_ptr, SL("_disabledLevels"), PH_NOISY_CC);
	
	/** 
	 * Render level will tell use when to stop
	 */
	PHALCON_OBS_VAR(render_level);
	phalcon_read_property_this(&render_level, this_ptr, SL("_renderLevel"), PH_NOISY_CC);
	if (zend_is_true(render_level)) {
	
		/** 
		 * Inserts view related to action
		 */
		if (PHALCON_GE_LONG(render_level, 1)) {
			if (!phalcon_array_isset_long(disabled_levels, 1)) {
				phalcon_call_method_p5_noret(this_ptr, "_enginerender", engines, render_view, silence, must_clean, cache);
			}
		}
	
		/** 
		 * Inserts templates before layout
		 */
		if (PHALCON_GE_LONG(render_level, 2)) {
			if (!phalcon_array_isset_long(disabled_levels, 2)) {
	
				PHALCON_OBS_VAR(templates_before);
				phalcon_read_property_this(&templates_before, this_ptr, SL("_templatesBefore"), PH_NOISY_CC);
	
				/** 
				 * Templates before must be an array
				 */
				if (Z_TYPE_P(templates_before) == IS_ARRAY) { 
	
					ZVAL_BOOL(silence, 0);
	
					phalcon_is_iterable(templates_before, &ah0, &hp0, 0, 0);
	
					while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
						PHALCON_GET_HVALUE(template_before);
	
						PHALCON_INIT_NVAR(view_temp_path);
						PHALCON_CONCAT_VV(view_temp_path, layouts_dir, template_before);
						phalcon_call_method_p5_noret(this_ptr, "_enginerender", engines, view_temp_path, silence, must_clean, cache);
	
						zend_hash_move_forward_ex(ah0, &hp0);
					}
	
					PHALCON_INIT_NVAR(silence);
					ZVAL_BOOL(silence, 1);
				}
			}
		}
	
		/** 
		 * Inserts controller layout
		 */
		if (PHALCON_GE_LONG(render_level, 3)) {
			if (!phalcon_array_isset_long(disabled_levels, 3)) {
				PHALCON_INIT_NVAR(view_temp_path);
				PHALCON_CONCAT_VV(view_temp_path, layouts_dir, layout_name);
				phalcon_call_method_p5_noret(this_ptr, "_enginerender", engines, view_temp_path, silence, must_clean, cache);
			}
		}
	
		/** 
		 * Inserts templates after layout
		 */
		if (PHALCON_GE_LONG(render_level, 4)) {
			if (!phalcon_array_isset_long(disabled_levels, 4)) {
	
				/** 
				 * Templates after must be an array
				 */
				PHALCON_OBS_VAR(templates_after);
				phalcon_read_property_this(&templates_after, this_ptr, SL("_templatesAfter"), PH_NOISY_CC);
				if (Z_TYPE_P(templates_after) == IS_ARRAY) { 
	
					PHALCON_INIT_NVAR(silence);
					ZVAL_BOOL(silence, 0);
	
					phalcon_is_iterable(templates_after, &ah1, &hp1, 0, 0);
	
					while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
						PHALCON_GET_HVALUE(template_after);
	
						PHALCON_INIT_NVAR(view_temp_path);
						PHALCON_CONCAT_VV(view_temp_path, layouts_dir, template_after);
						phalcon_call_method_p5_noret(this_ptr, "_enginerender", engines, view_temp_path, silence, must_clean, cache);
	
						zend_hash_move_forward_ex(ah1, &hp1);
					}
	
					PHALCON_INIT_NVAR(silence);
					ZVAL_BOOL(silence, 1);
				}
			}
		}
	
		/** 
		 * Inserts main view
		 */
		if (PHALCON_GE_LONG(render_level, 5)) {
			if (!phalcon_array_isset_long(disabled_levels, 5)) {
				PHALCON_OBS_VAR(main_view);
				phalcon_read_property_this(&main_view, this_ptr, SL("_mainView"), PH_NOISY_CC);
				phalcon_call_method_p5_noret(this_ptr, "_enginerender", engines, main_view, silence, must_clean, cache);
			}
		}
	
		/** 
		 * Store the data in the cache
		 */
		if (Z_TYPE_P(cache) == IS_OBJECT) {
	
			PHALCON_INIT_VAR(is_started);
			phalcon_call_method(is_started, cache, "isstarted");
			if (PHALCON_IS_TRUE(is_started)) {
	
				PHALCON_INIT_VAR(is_fresh);
				phalcon_call_method(is_fresh, cache, "isfresh");
				if (PHALCON_IS_TRUE(is_fresh)) {
					phalcon_call_method_noret(cache, "save");
				} else {
					phalcon_call_method_noret(cache, "stop");
				}
			} else {
				phalcon_call_method_noret(cache, "stop");
			}
		}
	}
	
	/** 
	 * Call afterRender event
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "view:afterRender", 1);
		phalcon_call_method_p2_noret(events_manager, "fire", event_name, this_ptr);
	}
	
	RETURN_MM_NULL();
}

/**
 * Choose a different view to render instead of last-controller/last-action
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
 * @param string|array $renderView
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, pick){

	zval *render_view, *pick_view = NULL, *layout = NULL, *parts;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &render_view);
	
	if (Z_TYPE_P(render_view) == IS_ARRAY) { 
		PHALCON_CPY_WRT(pick_view, render_view);
	} else {
		PHALCON_INIT_VAR(layout);
		if (phalcon_memnstr_str(render_view, SL("/") TSRMLS_CC)) {
			PHALCON_INIT_VAR(parts);
			phalcon_fast_explode_str(parts, SL("/"), render_view TSRMLS_CC);
	
			PHALCON_OBS_NVAR(layout);
			phalcon_array_fetch_long(&layout, parts, 0, PH_NOISY_CC);
		}
	
		PHALCON_INIT_NVAR(pick_view);
		array_init_size(pick_view, 1);
		phalcon_array_append(&pick_view, render_view, PH_SEPARATE TSRMLS_CC);
		if (Z_TYPE_P(layout) != IS_NULL) {
			phalcon_array_append(&pick_view, layout, PH_SEPARATE TSRMLS_CC);
		}
	}
	phalcon_update_property_this(this_ptr, SL("_pickView"), pick_view TSRMLS_CC);
	
	RETURN_THIS();
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
PHP_METHOD(Phalcon_Mvc_View, partial){

	zval *partial_path, *params = NULL, *view_params, *new_params = NULL;
	zval *zfalse, *partials_dir, *real_path, *engines;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &partial_path, &params);
	
	if (!params) {
		PHALCON_INIT_VAR(params);
	}
	
	/** 
	 * If the developer pass an array of variables we create a new virtual symbol table
	 */
	if (Z_TYPE_P(params) == IS_ARRAY) { 
	
		PHALCON_OBS_VAR(view_params);
		phalcon_read_property_this(&view_params, this_ptr, SL("_viewParams"), PH_NOISY_CC);
	
		/** 
		 * Merge or assign the new params as parameters
		 */
		if (Z_TYPE_P(view_params) == IS_ARRAY) { 
			PHALCON_INIT_VAR(new_params);
			phalcon_fast_array_merge(new_params, &view_params, &params TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(new_params, params);
		}
	
		/** 
		 * Update the parameters with the new ones
		 */
		phalcon_update_property_this(this_ptr, SL("_viewParams"), new_params TSRMLS_CC);
	
		/** 
		 * Create a virtual symbol table
		 */
		phalcon_create_symbol_table(TSRMLS_C);
	
	}
	
	PHALCON_INIT_VAR(zfalse);
	ZVAL_BOOL(zfalse, 0);
	
	PHALCON_OBS_VAR(partials_dir);
	phalcon_read_property_this(&partials_dir, this_ptr, SL("_partialsDir"), PH_NOISY_CC);
	
	/** 
	 * Partials are looked up under the partials directory
	 */
	PHALCON_INIT_VAR(real_path);
	PHALCON_CONCAT_VV(real_path, partials_dir, partial_path);
	
	/** 
	 * We need to check if the engines are loaded first, this method could be called
	 * outside of 'render'
	 */
	PHALCON_INIT_VAR(engines);
	phalcon_call_method(engines, this_ptr, "_loadtemplateengines");
	
	/** 
	 * Call engine render, this checks in every registered engine for the partial
	 */
	phalcon_call_method_p5_noret(this_ptr, "_enginerender", engines, real_path, zfalse, zfalse, zfalse);
	
	/** 
	 * Now we need to restore the original view parameters
	 */
	if (Z_TYPE_P(params) == IS_ARRAY) { 
		/** 
		 * Restore the original view params
		 */
		phalcon_update_property_this(this_ptr, SL("_viewParams"), view_params TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Perform the automatic rendering returning the output as a string
 *
 * <code>
 * 	$template = $this->view->getRender('products', 'show', array('products' => $products));
 * </code>
 *
 * @param string $controllerName
 * @param string $actionName
 * @param array $params
 * @param mixed $configCallback
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getRender){

	zval *controller_name, *action_name, *params = NULL;
	zval *config_callback = NULL, *view, *status, *content;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 2, &controller_name, &action_name, &params, &config_callback);
	
	if (!params) {
		PHALCON_INIT_VAR(params);
	} else {
		PHALCON_SEPARATE_PARAM(params);
	}
	
	if (!config_callback) {
		PHALCON_INIT_VAR(config_callback);
	}
	
	/** 
	 * We must to clone the current view to keep the old state
	 */
	PHALCON_INIT_VAR(view);
	if (phalcon_clone(view, this_ptr TSRMLS_CC) == FAILURE) {
		return;
	}
	
	/** 
	 * The component must be reset to its defaults
	 */
	phalcon_call_method_noret(view, "reset");
	
	/** 
	 * Set the render variables
	 */
	if (Z_TYPE_P(params) == IS_ARRAY) { 
		phalcon_call_method_p1_noret(view, "setvars", params);
	}
	
	/** 
	 * Perform extra configurations over the cloned object
	 */
	if (Z_TYPE_P(config_callback) == IS_OBJECT) {
		PHALCON_INIT_NVAR(params);
		array_init_size(params, 1);
		phalcon_array_append(&params, view, PH_SEPARATE TSRMLS_CC);
	
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_USER_FUNC_ARRAY(status, config_callback, params);
	}
	
	/** 
	 * Start the output buffering
	 */
	phalcon_call_method_noret(view, "start");
	
	/** 
	 * Perform the render passing only the controller and action
	 */
	phalcon_call_method_p2_noret(view, "render", controller_name, action_name);
	
	/** 
	 * Stop the output buffering
	 */
	phalcon_ob_end_clean(TSRMLS_C);
	
	/** 
	 * Get the processed content
	 */
	PHALCON_INIT_VAR(content);
	phalcon_call_method(content, view, "getcontent");
	
	RETURN_CCTOR(content);
}

/**
 * Finishes the render process by stopping the output buffering
 *
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, finish){


	phalcon_ob_end_clean(TSRMLS_C);
	RETURN_THISW();
}

/**
 * Create a Phalcon\Cache based on the internal cache options
 *
 * @return Phalcon\Cache\BackendInterface
 */
PHP_METHOD(Phalcon_Mvc_View, _createCache){

	zval *dependency_injector, *cache_service = NULL;
	zval *view_options, *cache_options, *view_cache;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "A dependency injector container is required to obtain the view cache services");
		return;
	}
	
	PHALCON_INIT_VAR(cache_service);
	ZVAL_STRING(cache_service, "viewCache", 1);
	
	PHALCON_OBS_VAR(view_options);
	phalcon_read_property_this(&view_options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(view_options) == IS_ARRAY) { 
		if (phalcon_array_isset_string(view_options, SS("cache"))) {
	
			PHALCON_OBS_VAR(cache_options);
			phalcon_array_fetch_string(&cache_options, view_options, SL("cache"), PH_NOISY_CC);
			if (Z_TYPE_P(cache_options) == IS_ARRAY) { 
				if (phalcon_array_isset_string(cache_options, SS("service"))) {
					PHALCON_OBS_NVAR(cache_service);
					phalcon_array_fetch_string(&cache_service, cache_options, SL("service"), PH_NOISY_CC);
				}
			}
		}
	}
	
	/** 
	 * The injected service must be an object
	 */
	PHALCON_INIT_VAR(view_cache);
	phalcon_call_method_p1(view_cache, dependency_injector, "getshared", cache_service);
	if (Z_TYPE_P(view_cache) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "The injected caching service is invalid");
		return;
	}
	
	RETURN_CCTOR(view_cache);
}

/**
 * Check if the component is currently caching the output content
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_View, isCaching){

	zval *zero, *cache_level, *is_caching;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(zero);
	ZVAL_LONG(zero, 0);
	
	PHALCON_OBS_VAR(cache_level);
	phalcon_read_property_this(&cache_level, this_ptr, SL("_cacheLevel"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(is_caching);
	is_smaller_function(is_caching, zero, cache_level TSRMLS_CC);
	RETURN_NCTOR(is_caching);
}

/**
 * Returns the cache instance used to cache
 *
 * @return Phalcon\Cache\BackendInterface
 */
PHP_METHOD(Phalcon_Mvc_View, getCache){

	zval *cache = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(cache);
	phalcon_read_property_this(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	if (zend_is_true(cache)) {
		if (Z_TYPE_P(cache) != IS_OBJECT) {
			PHALCON_INIT_NVAR(cache);
			phalcon_call_method(cache, this_ptr, "_createcache");
			phalcon_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
		}
	} else {
		PHALCON_INIT_NVAR(cache);
		phalcon_call_method(cache, this_ptr, "_createcache");
		phalcon_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
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
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, cache){

	zval *options = NULL, *view_options = NULL, *cache_options = NULL;
	zval *value = NULL, *key = NULL, *cache_level;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &options);
	
	if (!options) {
		PHALCON_INIT_VAR(options);
		ZVAL_BOOL(options, 1);
	}
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
	
		PHALCON_OBS_VAR(view_options);
		phalcon_read_property_this(&view_options, this_ptr, SL("_options"), PH_NOISY_CC);
		if (Z_TYPE_P(view_options) != IS_ARRAY) { 
			PHALCON_INIT_NVAR(view_options);
			array_init(view_options);
		}
	
		/** 
		 * Get the default cache options
		 */
		if (phalcon_array_isset_string(view_options, SS("cache"))) {
			PHALCON_OBS_VAR(cache_options);
			phalcon_array_fetch_string(&cache_options, view_options, SL("cache"), PH_NOISY_CC);
		} else {
			PHALCON_INIT_NVAR(cache_options);
			array_init(cache_options);
		}
	
		phalcon_is_iterable(options, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(value);
	
			phalcon_array_update_zval(&cache_options, key, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		/** 
		 * Check if the user has defined a default cache level or use 5 as default
		 */
		if (phalcon_array_isset_string(cache_options, SS("level"))) {
			PHALCON_OBS_VAR(cache_level);
			phalcon_array_fetch_string(&cache_level, cache_options, SL("level"), PH_NOISY_CC);
			phalcon_update_property_this(this_ptr, SL("_cacheLevel"), cache_level TSRMLS_CC);
		} else {
			phalcon_update_property_long(this_ptr, SL("_cacheLevel"), 5 TSRMLS_CC);
		}
	
		phalcon_array_update_string(&view_options, SL("cache"), &cache_options, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_options"), view_options TSRMLS_CC);
	} else {
		/** 
		 * If 'options' isn't an array we enable the cache with the default options
		 */
		if (zend_is_true(options)) {
			phalcon_update_property_long(this_ptr, SL("_cacheLevel"), 5 TSRMLS_CC);
		} else {
			phalcon_update_property_long(this_ptr, SL("_cacheLevel"), 0 TSRMLS_CC);
		}
	}
	
	RETURN_THIS();
}

/**
 * Externally sets the view content
 *
 *<code>
 *	$this->view->setContent("<h1>hello</h1>");
 *</code>
 *
 * @param string $content
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, setContent){

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
 * Returns cached output from another view stage
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getContent){


	RETURN_MEMBER(this_ptr, "_content");
}

/**
 * Returns the path of the view that is currently rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View, getActiveRenderPath){


	RETURN_MEMBER(this_ptr, "_activeRenderPath");
}

/**
 * Disables the auto-rendering process
 *
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, disable){


	phalcon_update_property_bool(this_ptr, SL("_disabled"), 1 TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Enables the auto-rendering process
 *
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, enable){


	phalcon_update_property_bool(this_ptr, SL("_disabled"), 0 TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Resets the view component to its factory default values
 *
 * @return Phalcon\Mvc\View
 */
PHP_METHOD(Phalcon_Mvc_View, reset){

	zval *znull;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(znull);
	phalcon_update_property_bool(this_ptr, SL("_disabled"), 0 TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_engines"), 0 TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_cache"), znull TSRMLS_CC);
	phalcon_update_property_long(this_ptr, SL("_renderLevel"), 5 TSRMLS_CC);
	phalcon_update_property_long(this_ptr, SL("_cacheLevel"), 0 TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_content"), znull TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_templatesBefore"), znull TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_templatesAfter"), znull TSRMLS_CC);
	RETURN_THIS();
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
PHP_METHOD(Phalcon_Mvc_View, __set){

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
PHP_METHOD(Phalcon_Mvc_View, __get){

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

