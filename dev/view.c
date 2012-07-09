
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
#include "kernel/concat.h"
#include "kernel/operators.h"
/**
 * Phalcon_View
 *
 * Phalcon_View is a class for working with the "view" portion of the model-view-controller pattern.
 * That is, it exists to help keep the view script separate from the model and controller scripts.
 * It provides a system of helpers, output filters, and variable escaping.
 *
 * 
 */

/**
 * Phalcon_View constructor
 *
 * @param Phalcon_Config|stClass $options
 */
PHP_METHOD(Phalcon_View, __construct){

	zval *options = NULL, *view_options = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_view_ce, this_ptr, SL("_viewParams"), a0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_view_ce, this_ptr, SL("_templatesBefore"), a1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	zend_update_property(phalcon_view_ce, this_ptr, SL("_templatesAfter"), a2 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	zend_update_property(phalcon_view_ce, this_ptr, SL("_registeredEngines"), a3 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	zend_update_property(phalcon_view_ce, this_ptr, SL("_params"), a4 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
		ZVAL_NULL(options);
	}
	
	if (zend_is_true(options)) {
		if (Z_TYPE_P(options) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Options parameter must be an object");
			return;
		}
		PHALCON_CPY_WRT(view_options, options);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init(i0);
		PHALCON_CPY_WRT(view_options, i0);
	}
	phalcon_update_property_zval(this_ptr, SL("_options"), view_options TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets views directory. Depending of your platform, always add a trailing slash or backslash
 *
 * @param string $viewsDir
 */
PHP_METHOD(Phalcon_View, setViewsDir){

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
PHP_METHOD(Phalcon_View, getViewsDir){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_viewsDir"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

/**
 * Sets base path. Depending of your platform, always add a trailing slash or backslash
 *
 * 
 *
 * @param string $basePath
 */
PHP_METHOD(Phalcon_View, setBasePath){

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
 * 
 *
 * @param string $level
 */
PHP_METHOD(Phalcon_View, setRenderLevel){

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
 * 
 *
 * @param string $name
 */
PHP_METHOD(Phalcon_View, setMainView){

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
PHP_METHOD(Phalcon_View, setTemplateBefore){

	zval *template_before = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &template_before) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(template_before) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_append(&a0, template_before, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_templatesBefore"), a0 TSRMLS_CC);
	} else {
		phalcon_update_property_zval(this_ptr, SL("_templatesBefore"), template_before TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Resets any template before layouts
 *
 */
PHP_METHOD(Phalcon_View, cleanTemplateBefore){


	PHALCON_MM_GROW();
	phalcon_update_property_null(this_ptr, SL("_templatesBefore") TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Appends template after controller layout
 *
 * @param string|array $templateAfter
 */
PHP_METHOD(Phalcon_View, setTemplateAfter){

	zval *template_after = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &template_after) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(template_after) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_append(&a0, template_after, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_templatesAfter"), a0 TSRMLS_CC);
	} else {
		phalcon_update_property_zval(this_ptr, SL("_templatesAfter"), template_after TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Resets any template before layouts
 *
 */
PHP_METHOD(Phalcon_View, cleanTemplateAfter){


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
PHP_METHOD(Phalcon_View, setParamToView){

	zval *key = NULL, *value = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &key, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_viewParams"), PHALCON_NOISY TSRMLS_CC);
	phalcon_array_update(&t0, key, &value, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_viewParams"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Adds parameters to views
 *
 * @param string $key
 * @param mixed $value
 */
PHP_METHOD(Phalcon_View, setVar){

	zval *key = NULL, *value = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &key, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_viewParams"), PHALCON_NOISY TSRMLS_CC);
	phalcon_array_update(&t0, key, &value, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_viewParams"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns parameters to views
 *
 * @return array
 */
PHP_METHOD(Phalcon_View, getParamsToView){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_viewParams"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

/**
 * Gets the name of the controller rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_View, getControllerName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_controllerName"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

/**
 * Gets the name of the action rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_View, getActionName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_actionName"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

/**
 * Gets extra parameters of the action rendered
 */
PHP_METHOD(Phalcon_View, getParams){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_params"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

/**
 * Starts rendering process enabling the output buffering
 */
PHP_METHOD(Phalcon_View, start){


	PHALCON_MM_GROW();
	phalcon_update_property_null(this_ptr, SL("_content") TSRMLS_CC);
	PHALCON_CALL_FUNC_NORETURN("ob_start");
	
	PHALCON_MM_RESTORE();
}

/**
 * Loads registered template engines, if none is registered use Phalcon_View_Engine_Php
 *
 * @return array
 */
PHP_METHOD(Phalcon_View, _loadTemplateEngines){

	zval *engines = NULL, *registered_engines = NULL, *engine = NULL;
	zval *extension = NULL, *options = NULL, *name = NULL, *class_name = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_engines"), PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(engines, a0);
		
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_registeredEngines"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(registered_engines, t1);
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_fast_count(r0, registered_engines TSRMLS_CC);
		if (!zend_is_true(r0)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_view_engine_php_ce);
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", this_ptr, a1, PHALCON_CHECK);
			phalcon_array_update_string(&engines, SL(".phtml"), &i0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		} else {
			if (phalcon_valid_foreach(registered_engines TSRMLS_CC)) {
				ah0 = Z_ARRVAL_P(registered_engines);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				fes_b0d8_0:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_b0d8_0;
				} else {
					PHALCON_INIT_VAR(extension);
					PHALCON_GET_FOREACH_KEY(extension, ah0, hp0);
				}
				PHALCON_INIT_VAR(engine);
				ZVAL_ZVAL(engine, *hd, 1, 0);
				PHALCON_INIT_VAR(a2);
				array_init(a2);
				PHALCON_CPY_WRT(options, a2);
				if (Z_TYPE_P(engine) == IS_ARRAY) { 
					eval_int = phalcon_array_isset_long(engine, 0);
					if (eval_int) {
						PHALCON_INIT_VAR(r1);
						phalcon_array_fetch_long(&r1, engine, 0, PHALCON_NOISY TSRMLS_CC);
						PHALCON_CPY_WRT(name, r1);
					} else {
						PHALCON_THROW_EXCEPTION_STR(phalcon_view_exception_ce, "The template engine name is required");
						return;
					}
					eval_int = phalcon_array_isset_long(engine, 1);
					if (eval_int) {
						PHALCON_INIT_VAR(r2);
						phalcon_array_fetch_long(&r2, engine, 1, PHALCON_NOISY TSRMLS_CC);
						PHALCON_CPY_WRT(options, r2);
					}
				} else {
					if (Z_TYPE_P(engine) == IS_STRING) {
						PHALCON_CPY_WRT(name, engine);
					} else {
						if (Z_TYPE_P(engine) == IS_OBJECT) {
							PHALCON_CALL_METHOD_PARAMS_2_NORETURN(engine, "initialize", this_ptr, options, PHALCON_NO_CHECK);
							phalcon_array_update(&engines, extension, &engine, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
							goto fes_b0d8_0;
						} else {
							PHALCON_THROW_EXCEPTION_STR(phalcon_view_exception_ce, "The template engine is invalid");
							return;
						}
					}
				}
				
				PHALCON_INIT_VAR(r3);
				PHALCON_CONCAT_SV(r3, "Phalcon_View_Engine_", name);
				PHALCON_CPY_WRT(class_name, r3);
				
				PHALCON_INIT_VAR(r4);
				PHALCON_CALL_FUNC_PARAMS_1(r4, "class_exists", class_name);
				if (zend_is_true(r4)) {
					ce0 = phalcon_fetch_class(class_name TSRMLS_CC);
					PHALCON_INIT_VAR(i1);
					object_init_ex(i1, ce0);
					PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i1, "__construct", this_ptr, options, PHALCON_CHECK);
					phalcon_array_update(&engines, extension, &i1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(i2);
					object_init_ex(i2, phalcon_view_exception_ce);
					PHALCON_INIT_VAR(r5);
					PHALCON_CONCAT_SVS(r5, "Template engine '", class_name, "' cannot be loaded");
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i2, "__construct", r5, PHALCON_CHECK);
					phalcon_throw_exception(i2 TSRMLS_CC);
					return;
				}
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_b0d8_0;
				fee_b0d8_0:
				if(0){}
			} else {
				return;
			}
		}
		
		phalcon_update_property_zval(this_ptr, SL("_engines"), engines TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, SL("_engines"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(engines, t2);
	}
	
	RETURN_CHECK_CTOR(engines);
}

/**
 * Checks whether view exists on registered extensions and render it
 *
 * @param array $engines
 * @param string $viewPath
 * @param boolean $silence
 * @param Phalcon_Cache $cache
 */
PHP_METHOD(Phalcon_View, _engineRender){

	zval *engines = NULL, *view_path = NULL, *silence = NULL, *cache = NULL, *not_exists = NULL;
	zval *view_params = NULL, *views_dir_path = NULL, *render_level = NULL;
	zval *cache_level = NULL, *key = NULL, *view_options = NULL, *cache_options = NULL;
	zval *cached_view = NULL, *engine = NULL, *extension = NULL, *view_engine_path = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *i0 = NULL;
	zval *rendered = NULL;
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

	PHALCON_INIT_VAR(rendered);
	ZVAL_NULL(rendered);
	PHALCON_INIT_VAR(not_exists);
	ZVAL_BOOL(not_exists, 1);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_viewParams"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(view_params, t0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_basePath"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_viewsDir"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CONCAT_VVV(r0, t1, t2, view_path);
	PHALCON_CPY_WRT(views_dir_path, r0);
	if (zend_is_true(cache)) {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, SL("_renderLevel"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(render_level, t3);
		
		PHALCON_ALLOC_ZVAL_MM(t4);
		phalcon_read_property(&t4, this_ptr, SL("_cacheLevel"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(cache_level, t4);
		
		PHALCON_INIT_VAR(r1);
		is_smaller_or_equal_function(r1, cache_level, render_level TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CALL_METHOD(r2, cache, "isstarted", PHALCON_NO_CHECK);
			if (!zend_is_true(r2)) {
				PHALCON_INIT_VAR(key);
				ZVAL_NULL(key);
				
				PHALCON_ALLOC_ZVAL_MM(t5);
				phalcon_read_property(&t5, this_ptr, SL("_options"), PHALCON_NOISY TSRMLS_CC);
				PHALCON_CPY_WRT(view_options, t5);
				eval_int = phalcon_isset_property(view_options, SL("cache") TSRMLS_CC);
				if (eval_int) {
					PHALCON_ALLOC_ZVAL_MM(t6);
					phalcon_read_property(&t6, view_options, SL("cache"), PHALCON_NOISY TSRMLS_CC);
					PHALCON_CPY_WRT(cache_options, t6);
					if (Z_TYPE_P(cache_options) == IS_OBJECT) {
						eval_int = phalcon_isset_property(cache_options, SL("key") TSRMLS_CC);
						if (eval_int) {
							PHALCON_ALLOC_ZVAL_MM(t7);
							phalcon_read_property(&t7, cache_options, SL("key"), PHALCON_NOISY TSRMLS_CC);
							PHALCON_CPY_WRT(key, t7);
						}
					}
				}
				
				if (!zend_is_true(key)) {
					PHALCON_INIT_VAR(key);
					PHALCON_CALL_FUNC_PARAMS_1(key, "md5", view_path);
				}
				
				PHALCON_ALLOC_ZVAL_MM(r3);
				PHALCON_CALL_METHOD_PARAMS_1(r3, cache, "start", key, PHALCON_NO_CHECK);
				PHALCON_CPY_WRT(cached_view, r3);
				if (Z_TYPE_P(cached_view) != IS_NULL) {
					phalcon_update_property_zval(this_ptr, SL("_content"), cached_view TSRMLS_CC);
					PHALCON_MM_RESTORE();
					RETURN_NULL();
				}
			}
			
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_METHOD(r4, cache, "isfresh", PHALCON_NO_CHECK);
			if (!zend_is_true(r4)) {
				PHALCON_MM_RESTORE();
				RETURN_NULL();
			}
		}
	}
	
	if (phalcon_valid_foreach(engines TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(engines);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_b0d8_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_b0d8_1;
		} else {
			PHALCON_INIT_VAR(extension);
			PHALCON_GET_FOREACH_KEY(extension, ah0, hp0);
		}
		PHALCON_INIT_VAR(engine);
		ZVAL_ZVAL(engine, *hd, 1, 0);
		PHALCON_INIT_VAR(r5);
		PHALCON_CONCAT_VV(r5, views_dir_path, extension);
		PHALCON_CPY_WRT(view_engine_path, r5);
		if (phalcon_file_exists(view_engine_path TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_PARAMS_2(rendered, engine, "render", view_engine_path, view_params, PHALCON_NO_CHECK);
			
			PHALCON_INIT_VAR(not_exists);
			ZVAL_BOOL(not_exists, 0);
			goto fee_b0d8_1;
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_b0d8_1;
		fee_b0d8_1:
		if(0){}
	} else {
		return;
	}
	if (zend_is_true(not_exists)) {
		if (!zend_is_true(silence)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_view_exception_ce);
			PHALCON_ALLOC_ZVAL_MM(r6);
			PHALCON_CONCAT_SVS(r6, "View '", views_dir_path, "' was not found in the views directory");
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r6, PHALCON_CHECK);
			phalcon_throw_exception(i0 TSRMLS_CC);
			return;
		}
	}
	
	RETURN_DZVAL(rendered);
}

/**
 * Register templating engines
 *
 *
 *
 * @param array $engines
 */
PHP_METHOD(Phalcon_View, registerEngines){

	zval *engines = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &engines) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(engines) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_view_exception_ce, "Engines to register must be an array");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_registeredEngines"), engines TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Executes render process from request data
 *
 *
 *
 * @param string $controllerName
 * @param string $actionName
 * @param array $params
 */
PHP_METHOD(Phalcon_View, render){

	zval *controller_name = NULL, *action_name = NULL, *params = NULL;
	zval *layouts_dir = NULL, *engines = NULL, *pick_view = NULL, *render_view = NULL;
	zval *render_controller = NULL, *cache = NULL, *cache_level = NULL;
	zval *silence = NULL, *render_level = NULL, *templates_before = NULL;
	zval *template_before = NULL, *templates_after = NULL, *template_after = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL;
	zval *render_buffer = NULL;
	zval *z_null = NULL;
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
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(params, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_layoutsDir"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(layouts_dir, t0);
	if (!zend_is_true(layouts_dir)) {
		PHALCON_INIT_VAR(layouts_dir);
		ZVAL_STRING(layouts_dir, "layouts/", 1);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_controllerName"), controller_name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_actionName"), action_name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_params"), params TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_initEngines"), 0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "_loadtemplateengines", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(engines, r0);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_pickView"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(pick_view, t1);
	if (!zend_is_true(pick_view)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_VSV(r1, controller_name, "/", action_name);
		PHALCON_CPY_WRT(render_view, r1);
		PHALCON_CPY_WRT(render_controller, controller_name);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_long(&r2, pick_view, 0, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(render_view, r2);
		eval_int = phalcon_array_isset_long(pick_view, 1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch_long(&r3, pick_view, 1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(render_controller, r3);
		} else {
			PHALCON_CPY_WRT(render_controller, controller_name);
		}
	}
	
	PHALCON_INIT_VAR(cache);
	ZVAL_NULL(cache);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_cacheLevel"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(cache_level, t2);
	if (zend_is_true(cache_level)) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CALL_METHOD(r4, this_ptr, "getcache", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(cache, r4);
	}
	
	PHALCON_INIT_VAR(silence);
	ZVAL_BOOL(silence, 1);
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, SL("_renderLevel"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(render_level, t3);
	if (zend_is_true(render_level)) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CALL_FUNC(r5, "ob_get_contents");
		phalcon_update_property_zval(this_ptr, SL("_content"), r5 TSRMLS_CC);
		
		PHALCON_INIT_VAR(t4);
		ZVAL_LONG(t4, 1);
		
		PHALCON_INIT_VAR(r6);
		is_smaller_or_equal_function(r6, t4, render_level TSRMLS_CC);
		if (zend_is_true(r6)) {
			PHALCON_INIT_VAR(render_buffer);
			PHALCON_CALL_METHOD_PARAMS_4(render_buffer, this_ptr, "_enginerender", engines, render_view, silence, cache, PHALCON_NO_CHECK);
			if (zend_is_true(render_buffer)) {
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "setcontent", render_buffer, PHALCON_NO_CHECK);
			}
		}
		
		PHALCON_INIT_VAR(t5);
		ZVAL_LONG(t5, 2);
		
		PHALCON_INIT_VAR(r7);
		is_smaller_or_equal_function(r7, t5, render_level TSRMLS_CC);
		if (zend_is_true(r7)) {
			PHALCON_ALLOC_ZVAL_MM(t6);
			phalcon_read_property(&t6, this_ptr, SL("_templatesBefore"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(templates_before, t6);
			if (zend_is_true(templates_before)) {
				PHALCON_INIT_VAR(silence);
				ZVAL_BOOL(silence, 0);
				if (Z_TYPE_P(templates_before) == IS_ARRAY) { 
					if (phalcon_valid_foreach(templates_before TSRMLS_CC)) {
						ah0 = Z_ARRVAL_P(templates_before);
						zend_hash_internal_pointer_reset_ex(ah0, &hp0);
						fes_b0d8_2:
						if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
							goto fee_b0d8_2;
						}
						PHALCON_INIT_VAR(template_before);
						ZVAL_ZVAL(template_before, *hd, 1, 0);
						PHALCON_INIT_VAR(r8);
						PHALCON_CONCAT_VV(r8, layouts_dir, template_before);
						PHALCON_INIT_VAR(render_buffer);
						PHALCON_CALL_METHOD_PARAMS_4(render_buffer, this_ptr, "_enginerender", engines, r8, silence, cache, PHALCON_NO_CHECK);
						if (zend_is_true(render_buffer)) {
							PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "setcontent", render_buffer, PHALCON_NO_CHECK);
						}
						zend_hash_move_forward_ex(ah0, &hp0);
						goto fes_b0d8_2;
						fee_b0d8_2:
						if(0){}
					} else {
						return;
					}
				} else {
					PHALCON_ALLOC_ZVAL_MM(r9);
					PHALCON_CONCAT_VV(r9, layouts_dir, template_before);
					PHALCON_INIT_VAR(render_buffer);
					PHALCON_CALL_METHOD_PARAMS_4(render_buffer, this_ptr, "_enginerender", engines, r9, silence, cache, PHALCON_NO_CHECK);
					if (zend_is_true(render_buffer)) {
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "setcontent", render_buffer, PHALCON_NO_CHECK);
					}
				}
				
				PHALCON_INIT_VAR(silence);
				ZVAL_BOOL(silence, 1);
			}
		}
		
		PHALCON_INIT_VAR(t7);
		ZVAL_LONG(t7, 3);
		
		PHALCON_INIT_VAR(r10);
		is_smaller_or_equal_function(r10, t7, render_level TSRMLS_CC);
		if (zend_is_true(r10)) {
			PHALCON_ALLOC_ZVAL_MM(r11);
			PHALCON_CONCAT_VV(r11, layouts_dir, render_controller);
			PHALCON_INIT_VAR(render_buffer);
			PHALCON_CALL_METHOD_PARAMS_4(render_buffer, this_ptr, "_enginerender", engines, r11, silence, cache, PHALCON_NO_CHECK);
			if (zend_is_true(render_buffer)) {
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "setcontent", render_buffer, PHALCON_NO_CHECK);
			}

		}
		
		PHALCON_INIT_VAR(t8);
		ZVAL_LONG(t8, 4);
		
		PHALCON_INIT_VAR(r12);
		is_smaller_or_equal_function(r12, t8, render_level TSRMLS_CC);
		if (zend_is_true(r12)) {
			PHALCON_ALLOC_ZVAL_MM(t9);
			phalcon_read_property(&t9, this_ptr, SL("_templatesAfter"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(templates_after, t9);
			if (zend_is_true(templates_after)) {
				PHALCON_INIT_VAR(silence);
				ZVAL_BOOL(silence, 0);
				if (Z_TYPE_P(templates_after) == IS_ARRAY) { 
					if (phalcon_valid_foreach(templates_after TSRMLS_CC)) {
						ah1 = Z_ARRVAL_P(templates_after);
						zend_hash_internal_pointer_reset_ex(ah1, &hp1);
						fes_b0d8_3:
						if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
							goto fee_b0d8_3;
						}
						PHALCON_INIT_VAR(template_after);
						ZVAL_ZVAL(template_after, *hd, 1, 0);
						PHALCON_INIT_VAR(r13);
						PHALCON_CONCAT_VV(r13, layouts_dir, template_after);
						PHALCON_INIT_VAR(render_buffer);
						PHALCON_CALL_METHOD_PARAMS_4(render_buffer, this_ptr, "_enginerender", engines, r13, silence, cache, PHALCON_NO_CHECK);
						if (zend_is_true(render_buffer)) {
							PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "setcontent", render_buffer, PHALCON_NO_CHECK);
						}
						zend_hash_move_forward_ex(ah1, &hp1);
						goto fes_b0d8_3;
						fee_b0d8_3:
						if(0){}
					} else {
						return;
					}
				} else {
					PHALCON_ALLOC_ZVAL_MM(r14);
					PHALCON_CONCAT_VV(r14, layouts_dir, templates_after);
					PHALCON_INIT_VAR(render_buffer);
					PHALCON_CALL_METHOD_PARAMS_4(render_buffer, this_ptr, "_enginerender", engines, r14, silence, cache, PHALCON_NO_CHECK);
					if (zend_is_true(render_buffer)) {
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "setcontent", render_buffer, PHALCON_NO_CHECK);
					}
				}
				
				PHALCON_INIT_VAR(silence);
				ZVAL_BOOL(silence, 1);
			}
		}
		
		PHALCON_INIT_VAR(t10);
		ZVAL_LONG(t10, 5);
		
		PHALCON_INIT_VAR(r15);
		is_smaller_or_equal_function(r15, t10, render_level TSRMLS_CC);
		if (zend_is_true(r15)) {
			PHALCON_ALLOC_ZVAL_MM(t11);
			phalcon_read_property(&t11, this_ptr, SL("_mainView"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_INIT_VAR(render_buffer);
			PHALCON_CALL_METHOD_PARAMS_4(render_buffer, this_ptr, "_enginerender", engines, t11, silence, cache, PHALCON_NO_CHECK);
			if (zend_is_true(render_buffer)) {
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "setcontent", render_buffer, PHALCON_NO_CHECK);
			}
		}
		
		if (zend_is_true(cache)) {
			PHALCON_ALLOC_ZVAL_MM(r16);
			PHALCON_CALL_METHOD(r16, cache, "isstarted", PHALCON_NO_CHECK);
			if (zend_is_true(r16)) {
				PHALCON_ALLOC_ZVAL_MM(r17);
				PHALCON_CALL_METHOD(r17, cache, "isfresh", PHALCON_NO_CHECK);
				if (zend_is_true(r17)) {
					PHALCON_INIT_VAR(render_buffer);
					PHALCON_CALL_METHOD(render_buffer, this_ptr, "getcontent", PHALCON_NO_CHECK);
					PHALCON_INIT_VAR(z_null);
					ZVAL_NULL(z_null);
					PHALCON_CALL_METHOD_PARAMS_2_NORETURN(cache, "save", z_null, render_buffer, PHALCON_NO_CHECK);
				}
			}
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Choose a view different to render than last-controller/last-action
 *
 * 
 *
 * @param string $renderView
 */
PHP_METHOD(Phalcon_View, pick){

	zval *render_view = NULL, *separator = NULL, *pick_view = NULL, *layout = NULL;
	zval *parts = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *a0 = NULL;

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
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_fast_strpos(r0, render_view, separator TSRMLS_CC);
		if (zend_is_true(r0)) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_fast_explode(r1, separator, render_view TSRMLS_CC);
			PHALCON_CPY_WRT(parts, r1);
			
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_array_fetch_long(&r2, parts, 0, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(layout, r2);
		}
		
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_append(&a0, render_view, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		PHALCON_CPY_WRT(pick_view, a0);
		if (Z_TYPE_P(layout) != IS_NULL) {
			phalcon_array_append(&pick_view, layout, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		}
	}
	
	phalcon_update_property_zval(this_ptr, SL("_pickView"), pick_view TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Renders a partial view
 *
 * 
 *
 * @param string $partialPath
 */
PHP_METHOD(Phalcon_View, partial){

	zval *partial_path = NULL, *vfalse = NULL;
	zval *render_buffer = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &partial_path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(vfalse);
	ZVAL_BOOL(vfalse, 0);
	
	PHALCON_INIT_VAR(render_buffer);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "_loadtemplateengines", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_4(render_buffer, this_ptr, "_enginerender", r0, partial_path, vfalse, vfalse, PHALCON_NO_CHECK);
	
	RETURN_DZVAL(render_buffer);
}

/**
 * Finishes the render process by stopping the output buffering
 */
PHP_METHOD(Phalcon_View, finish){


	PHALCON_MM_GROW();
	PHALCON_CALL_FUNC_NORETURN("ob_end_clean");
	
	PHALCON_MM_RESTORE();
}

/**
 * Set the cache object or cache parameters to do the resultset caching
 *
 * @param Phalcon_Cache_Backend|object $cache
 */
PHP_METHOD(Phalcon_View, setCache){

	zval *cache = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &cache) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(cache) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Cache must be an object instance");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_cache"), cache TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Create a Phalcon_Cache based on the internal cache options
 *
 * @return Phalcon_Cache
 */
PHP_METHOD(Phalcon_View, _createCache){

	zval *options = NULL, *cache_options = NULL, *array_options = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_options"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(options, t0);
	eval_int = phalcon_isset_property(options, SL("cache") TSRMLS_CC);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_view_exception_ce, "Cache options aren't defined");
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, options, SL("cache"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(cache_options, t1);
	eval_int = phalcon_isset_property(cache_options, SL("adapter") TSRMLS_CC);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Cache adapter isn't defined");
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_cast(r0, cache_options, IS_ARRAY);
	PHALCON_CPY_WRT(array_options, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "Output", 1);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, cache_options, SL("adapter"), PHALCON_NOISY TSRMLS_CC);
	p0[1] = t2;
	p0[2] = array_options;
	p0[3] = array_options;
	PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_cache", "factory", 4, p0);
	RETURN_DZVAL(r1);
}

/**
 * Returns the cache instance used to cache
 *
 * @return Phalcon_Cache
 */
PHP_METHOD(Phalcon_View, getCache){

	zval *cache = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_cache"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(cache, t0);
	if (zend_is_true(cache)) {
		if (Z_TYPE_P(cache) != IS_OBJECT) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_CALL_METHOD(r0, this_ptr, "_createcache", PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(cache, r0);
			phalcon_update_property_zval(this_ptr, SL("_cache"), cache TSRMLS_CC);
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "_createcache", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(cache, r1);
		phalcon_update_property_zval(this_ptr, SL("_cache"), cache TSRMLS_CC);
	}
	
	
	RETURN_CHECK_CTOR(cache);
}

/**
 * Cache the actual view render to certain level
 *
 * @param boolean|array $options
 */
PHP_METHOD(Phalcon_View, cache){

	zval *options = NULL, *view_options = NULL, *cache_options = NULL;
	zval *value = NULL, *key = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *i0 = NULL;
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
		PHALCON_INIT_VAR(options);
		ZVAL_BOOL(options, 1);
	}
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("_options"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(view_options, t0);
		eval_int = phalcon_isset_property(view_options, SL("cache") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, view_options, SL("cache"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(cache_options, t1);
		} else {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init(i0);
			PHALCON_CPY_WRT(cache_options, i0);
		}
		
		if (phalcon_valid_foreach(options TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(options);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_b0d8_4:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_b0d8_4;
			} else {
				PHALCON_INIT_VAR(key);
				PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			}
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			phalcon_update_property_zval_zval(cache_options, key, value TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_b0d8_4;
			fee_b0d8_4:
			if(0){}
		} else {
			return;
		}
		eval_int = phalcon_isset_property(cache_options, SL("level") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t2);
			phalcon_read_property(&t2, cache_options, SL("level"), PHALCON_NOISY TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_cacheLevel"), t2 TSRMLS_CC);
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
 *
 *
 * @param string $content
 */
PHP_METHOD(Phalcon_View, setContent){

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
PHP_METHOD(Phalcon_View, getContent){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_content"), PHALCON_NOISY TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t0);
}

/**
 * Disable view. No show any view or template
 *
 */
PHP_METHOD(Phalcon_View, disable){


	PHALCON_MM_GROW();
	phalcon_update_property_long(this_ptr, SL("_renderLevel"), 0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

