
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

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Phalcon_View
 *
 * Phalcon_View is a class for working with the "view" portion of the model-view-controller pattern.
 * That is, it exists to help keep the view script separate from the model and controller scripts.
 * It provides a system of helpers, output filters, and variable escaping.
 *
 * 
 */

PHP_METHOD(Phalcon_View, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_view_ce, this_ptr, "_viewParams", strlen("_viewParams"), a0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_view_ce, this_ptr, "_templatesBefore", strlen("_templatesBefore"), a1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	zend_update_property(phalcon_view_ce, this_ptr, "_templatesAfter", strlen("_templatesAfter"), a2 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	zend_update_property(phalcon_view_ce, this_ptr, "_registeredEngines", strlen("_registeredEngines"), a3 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	zend_update_property(phalcon_view_ce, this_ptr, "_params", strlen("_params"), a4 TSRMLS_CC);

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

	phalcon_update_property_zval(this_ptr, "_viewsDir", strlen("_viewsDir"), views_dir TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, "_viewsDir", sizeof("_viewsDir")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets base path. Depending of your platform, always add a trailing slash or backslash
 */
PHP_METHOD(Phalcon_View, setBasePath){

	zval *base_path = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &base_path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_basePath", strlen("_basePath"), base_path TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the render level for the view
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

	phalcon_update_property_zval(this_ptr, "_renderLevel", strlen("_renderLevel"), level TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets default view name. Must be a file without extension in the views directory
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

	phalcon_update_property_zval(this_ptr, "_mainView", strlen("_mainView"), view_path TSRMLS_CC);
	
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
		phalcon_update_property_zval(this_ptr, "_templatesBefore", strlen("_templatesBefore"), a0 TSRMLS_CC);
	} else {
		phalcon_update_property_zval(this_ptr, "_templatesBefore", strlen("_templatesBefore"), template_before TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Resets any template before layouts
 *
 */
PHP_METHOD(Phalcon_View, cleanTemplateBefore){


	PHALCON_MM_GROW();
	phalcon_update_property_null(this_ptr, "_templatesBefore", strlen("_templatesBefore") TSRMLS_CC);
	
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
		phalcon_update_property_zval(this_ptr, "_templatesAfter", strlen("_templatesAfter"), a0 TSRMLS_CC);
	} else {
		phalcon_update_property_zval(this_ptr, "_templatesAfter", strlen("_templatesAfter"), template_after TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Resets any template before layouts
 *
 */
PHP_METHOD(Phalcon_View, cleanTemplateAfter){


	PHALCON_MM_GROW();
	phalcon_update_property_null(this_ptr, "_templatesAfter", strlen("_templatesAfter") TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, "_viewParams", sizeof("_viewParams")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_array_update(&t0, key, &value, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_viewParams", strlen("_viewParams"), t0 TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, "_viewParams", sizeof("_viewParams")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_array_update(&t0, key, &value, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_viewParams", strlen("_viewParams"), t0 TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, "_viewParams", sizeof("_viewParams")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, "_controllerName", sizeof("_controllerName")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, "_actionName", sizeof("_actionName")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Gets extra parameters of the action rendered
 */
PHP_METHOD(Phalcon_View, getParams){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Starts rendering process
 */
PHP_METHOD(Phalcon_View, start){


	PHALCON_MM_GROW();
	phalcon_update_property_null(this_ptr, "_content", strlen("_content") TSRMLS_CC);
	PHALCON_CALL_FUNC_NORETURN("ob_start", 0x014);
	
	PHALCON_MM_RESTORE();
}

/**
 * Loads registered template engines, if none is registered use Phalcon_View_Engine_Php
 *
 * @return array
 */
PHP_METHOD(Phalcon_View, _loadTemplateEngines){

	zval *engines = NULL, *params = NULL, *registered_engines = NULL;
	zval *engine = NULL, *extension = NULL, *options = NULL, *name = NULL, *class_name = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL, *i4 = NULL;
	zval *c0 = NULL, *c1 = NULL;
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
	phalcon_read_property(&t0, this_ptr, "_engines", sizeof("_engines")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(engines, a0);
		
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_viewParams", sizeof("_viewParams")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(params, t1);
		
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_registeredEngines", sizeof("_registeredEngines")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(registered_engines, t2);
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_fast_count(r0, registered_engines TSRMLS_CC);
		if (!zend_is_true(r0)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_view_engine_php_ce);
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(i0, "__construct", this_ptr, a1, params, PHALCON_CHECK);
			phalcon_array_update_string(&engines, ".phtml", strlen(".phtml"), &i0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
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
						PHALCON_INIT_VAR(i1);
						object_init_ex(i1, phalcon_view_exception_ce);
						PHALCON_INIT_VAR(c0);
						ZVAL_STRING(c0, "The template engine name is required", 1);
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c0, PHALCON_CHECK);
						phalcon_throw_exception(i1 TSRMLS_CC);
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
							PHALCON_CALL_METHOD_PARAMS_3_NORETURN(engine, "initialize", this_ptr, options, params, PHALCON_NO_CHECK);
							phalcon_array_update(&engines, extension, &engine, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
							goto fes_b0d8_0;
						} else {
							PHALCON_INIT_VAR(i2);
							object_init_ex(i2, phalcon_view_exception_ce);
							PHALCON_INIT_VAR(c1);
							ZVAL_STRING(c1, "The template engine is invalid", 1);
							PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i2, "__construct", c1, PHALCON_CHECK);
							phalcon_throw_exception(i2 TSRMLS_CC);
							return;
						}
					}
				}
				
				
				PHALCON_INIT_VAR(r3);
				PHALCON_CONCAT_LEFT(r3, "Phalcon_View_Engine_", name);
				PHALCON_CPY_WRT(class_name, r3);
				
				PHALCON_INIT_VAR(r4);
				PHALCON_CALL_FUNC_PARAMS_1(r4, "class_exists", class_name, 0x012);
				if (zend_is_true(r4)) {
					ce0 = phalcon_fetch_class(class_name TSRMLS_CC);
					PHALCON_INIT_VAR(i3);
					object_init_ex(i3, ce0);
					PHALCON_CALL_METHOD_PARAMS_3_NORETURN(i3, "__construct", this_ptr, options, params, PHALCON_CHECK);
					phalcon_array_update(&engines, extension, &i3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(i4);
					object_init_ex(i4, phalcon_view_exception_ce);
					PHALCON_INIT_VAR(r5);
					PHALCON_CONCAT_BOTH(r5,  "Template engine '", class_name, "' cannot be loaded");
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i4, "__construct", r5, PHALCON_CHECK);
					phalcon_throw_exception(i4 TSRMLS_CC);
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
		
		phalcon_update_property_zval(this_ptr, "_engines", strlen("_engines"), engines TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_engines", sizeof("_engines")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(engines, t3);
	}
	
	PHALCON_RETURN_CHECK_CTOR(engines);
}

/**
 * Checks whether view exists on registered extensions and render it
 */
PHP_METHOD(Phalcon_View, _engineRender){

	zval *engines = NULL, *view_path = NULL, *silence = NULL, *not_exists = NULL;
	zval *views_dir_path = NULL, *engine = NULL, *extension = NULL, *view_engine_path = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &engines, &view_path, &silence) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(not_exists);
	ZVAL_BOOL(not_exists, 1);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_basePath", sizeof("_basePath")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_viewsDir", sizeof("_viewsDir")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, t1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	concat_function(r1, r0, view_path TSRMLS_CC);
	PHALCON_CPY_WRT(views_dir_path, r1);
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
		PHALCON_INIT_VAR(r2);
		concat_function(r2, views_dir_path, extension TSRMLS_CC);
		PHALCON_CPY_WRT(view_engine_path, r2);
		if (phalcon_file_exists(view_engine_path TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(engine, "render", view_engine_path, PHALCON_NO_CHECK);
			
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
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CONCAT_BOTH(r3,  "View '", views_dir_path, "' was not found in the views directory");
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r3, PHALCON_CHECK);
			phalcon_throw_exception(i0 TSRMLS_CC);
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
PHP_METHOD(Phalcon_View, registerEngines){

	zval *engines = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &engines) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(engines) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_view_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Engines to register must be an array", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	phalcon_update_property_zval(this_ptr, "_registeredEngines", strlen("_registeredEngines"), engines TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Executes render process from request data
 *
 * @param string $controllerName
 * @param string $actionName
 * @param array $params
 */
PHP_METHOD(Phalcon_View, render){

	zval *controller_name = NULL, *action_name = NULL, *params = NULL;
	zval *layouts_dir = NULL, *engines = NULL, *silence = NULL, *render_level = NULL;
	zval *templates_before = NULL, *template_before = NULL;
	zval *templates_after = NULL, *template_after = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

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
	phalcon_read_property(&t0, this_ptr, "_layoutsDir", sizeof("_layoutsDir")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(layouts_dir, t0);
	if (!zend_is_true(layouts_dir)) {
		PHALCON_INIT_VAR(layouts_dir);
		ZVAL_STRING(layouts_dir, "layouts/", 1);
	}
	
	phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), controller_name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), action_name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), params TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, "_initEngines", strlen("_initEngines"), 0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "_loadtemplateengines", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(engines, r0);
	
	PHALCON_INIT_VAR(silence);
	ZVAL_BOOL(silence, 1);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_renderLevel", sizeof("_renderLevel")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(render_level, t1);
	if (zend_is_true(render_level)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC(r1, "ob_get_contents", 0x015);
		phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r1 TSRMLS_CC);
		
		PHALCON_INIT_VAR(t2);
		ZVAL_LONG(t2, 1);
		
		PHALCON_INIT_VAR(r2);
		is_smaller_or_equal_function(r2, t2, render_level TSRMLS_CC);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CONCAT_VBOTH(r3, controller_name, "/", action_name);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_enginerender", engines, r3, silence, PHALCON_NO_CHECK);
		}
		
		
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 2);
		
		PHALCON_INIT_VAR(r4);
		is_smaller_or_equal_function(r4, t3, render_level TSRMLS_CC);
		if (zend_is_true(r4)) {
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_read_property(&t4, this_ptr, "_templatesBefore", sizeof("_templatesBefore")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(templates_before, t4);
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
						PHALCON_INIT_VAR(r5);
						concat_function(r5, layouts_dir, template_before TSRMLS_CC);
						PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_enginerender", engines, r5, silence, PHALCON_NO_CHECK);
						zend_hash_move_forward_ex(ah0, &hp0);
						goto fes_b0d8_2;
						fee_b0d8_2:
						if(0){}
					} else {
						return;
					}
				} else {
					PHALCON_ALLOC_ZVAL_MM(r6);
					concat_function(r6, layouts_dir, template_before TSRMLS_CC);
					PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_enginerender", engines, r6, silence, PHALCON_NO_CHECK);
				}
				
				
				PHALCON_INIT_VAR(silence);
				ZVAL_BOOL(silence, 1);
			}
		}
		
		
		PHALCON_INIT_VAR(t5);
		ZVAL_LONG(t5, 3);
		
		PHALCON_INIT_VAR(r7);
		is_smaller_or_equal_function(r7, t5, render_level TSRMLS_CC);
		if (zend_is_true(r7)) {
			PHALCON_ALLOC_ZVAL_MM(r8);
			concat_function(r8, layouts_dir, controller_name TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_enginerender", engines, r8, silence, PHALCON_NO_CHECK);
		}
		
		
		PHALCON_INIT_VAR(t6);
		ZVAL_LONG(t6, 4);
		
		PHALCON_INIT_VAR(r9);
		is_smaller_or_equal_function(r9, t6, render_level TSRMLS_CC);
		if (zend_is_true(r9)) {
			PHALCON_ALLOC_ZVAL_MM(t7);
			phalcon_read_property(&t7, this_ptr, "_templatesAfter", sizeof("_templatesAfter")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(templates_after, t7);
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
						PHALCON_INIT_VAR(r10);
						concat_function(r10, layouts_dir, template_after TSRMLS_CC);
						PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_enginerender", engines, r10, silence, PHALCON_NO_CHECK);
						zend_hash_move_forward_ex(ah1, &hp1);
						goto fes_b0d8_3;
						fee_b0d8_3:
						if(0){}
					} else {
						return;
					}
				} else {
					PHALCON_ALLOC_ZVAL_MM(r11);
					concat_function(r11, layouts_dir, templates_after TSRMLS_CC);
					PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_enginerender", engines, r11, silence, PHALCON_NO_CHECK);
				}
				
				
				PHALCON_INIT_VAR(silence);
				ZVAL_BOOL(silence, 1);
			}
		}
		
		
		PHALCON_INIT_VAR(t8);
		ZVAL_LONG(t8, 5);
		
		PHALCON_INIT_VAR(r12);
		is_smaller_or_equal_function(r12, t8, render_level TSRMLS_CC);
		if (zend_is_true(r12)) {
			PHALCON_ALLOC_ZVAL_MM(t9);
			phalcon_read_property(&t9, this_ptr, "_mainView", sizeof("_mainView")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_enginerender", engines, t9, silence, PHALCON_NO_CHECK);
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Renders a partial view
 *
 * @param string $partialPath
 */
PHP_METHOD(Phalcon_View, partial){

	zval *partial_path = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &partial_path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "_loadtemplateengines", PHALCON_NO_CHECK);
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 0);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_enginerender", r0, partial_path, c0, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Finishes the render process
 */
PHP_METHOD(Phalcon_View, finish){


	PHALCON_MM_GROW();
	PHALCON_CALL_FUNC_NORETURN("ob_end_clean", 0x016);
	
	PHALCON_MM_RESTORE();
}

/**
 * Set externally the view content
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

	phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), content TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns cached ouput on another view stage
 *
 * @return string
 */
PHP_METHOD(Phalcon_View, getContent){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_content", sizeof("_content")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

