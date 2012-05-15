
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
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

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

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_view_ce, this_ptr, "_params", strlen("_params"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_view_ce, this_ptr, "_templatesBefore", strlen("_templatesBefore"), a1 TSRMLS_CC);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	zend_update_property(phalcon_view_ce, this_ptr, "_templatesAfter", strlen("_templatesAfter"), a2 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets views directory
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
	zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_templatesBefore", strlen("_templatesBefore") TSRMLS_CC);
	
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
	zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_templatesAfter", strlen("_templatesAfter") TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_array_update(&t0, key, value, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), t0 TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_array_update(&t0, key, value, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), t0 TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY TSRMLS_CC);
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
 * Starts rendering process
 */
PHP_METHOD(Phalcon_View, start){


	PHALCON_MM_GROW();
	zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_content", strlen("_content") TSRMLS_CC);
	PHALCON_CALL_FUNC_NORETURN("ob_start", 0x010);
	
	PHALCON_MM_RESTORE();
}

/**
 * Executes render process from controller data
 *
 * @param string $controllerName
 * @param string $actionName
 */
PHP_METHOD(Phalcon_View, render){

	zval *controller_name = NULL, *action_name = NULL, *views_dir = NULL;
	zval *layouts_dir = NULL, *render_level = NULL, *value = NULL, *key = NULL;
	zval *view_path = NULL, *templates_before = NULL, *template_before = NULL;
	zval *template_view = NULL, *templates_after = NULL, *template_after = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &controller_name, &action_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_viewsDir", sizeof("_viewsDir")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(views_dir, t0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_layoutsDir", sizeof("_layoutsDir")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(layouts_dir, t1);
	if (PHALCON_COMPARE_STRING(layouts_dir, "")) {
		PHALCON_INIT_VAR(layouts_dir);
		ZVAL_STRING(layouts_dir, "layouts/", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_renderLevel", sizeof("_renderLevel")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(render_level, t2);
	phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), controller_name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), action_name TSRMLS_CC);
	if (zend_is_true(render_level)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC(r0, "ob_get_contents", 0x011);
		phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY TSRMLS_CC);
		if (phalcon_valid_foreach(t3 TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(t3);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_b0d8_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_b0d8_0;
			} else {
				PHALCON_INIT_VAR(key);
				hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
				if (hash_type == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(key, hash_index, hash_index_len-1, 1);
				} else {
					if (hash_type == HASH_KEY_IS_LONG) {
						ZVAL_LONG(key, hash_num);
					}
				}
			}
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, value, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				Z_UNSET_ISREF_P(copy);
				ZEND_SET_SYMBOL(EG(active_symbol_table), Z_STRVAL_P(key), copy);
				if (EG(exception)) {
					return;
				}
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_b0d8_0;
			fee_b0d8_0:
			if(0){ };
		}
		PHALCON_INIT_VAR(t4);
		ZVAL_LONG(t4, 1);
		PHALCON_INIT_VAR(r1);
		is_smaller_or_equal_function(r1, t4, render_level TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			concat_function(r3, views_dir, controller_name TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CONCAT_VBOTH(r2, r3, "/", action_name);
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CONCAT_RIGHT(r4, r2, ".phtml");
			PHALCON_CPY_WRT(view_path, r4);
			if (phalcon_file_exists(view_path TSRMLS_CC) == SUCCESS) {
				PHALCON_CALL_FUNC_NORETURN("ob_clean", 0x019);
				if (phalcon_require(view_path TSRMLS_CC) == FAILURE) {
					return;
				}
				PHALCON_ALLOC_ZVAL_MM(r5);
				PHALCON_CALL_FUNC(r5, "ob_get_contents", 0x011);
				phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r5 TSRMLS_CC);
			}
			
		}
		
		PHALCON_INIT_VAR(t5);
		ZVAL_LONG(t5, 2);
		PHALCON_INIT_VAR(r6);
		is_smaller_or_equal_function(r6, t5, render_level TSRMLS_CC);
		if (zend_is_true(r6)) {
			PHALCON_ALLOC_ZVAL_MM(t6);
			phalcon_read_property(&t6, this_ptr, "_templatesBefore", sizeof("_templatesBefore")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(templates_before, t6);
			if (Z_TYPE_P(templates_before) == IS_ARRAY) { 
				PHALCON_ALLOC_ZVAL_MM(r7);
				concat_function(r7, views_dir, layouts_dir TSRMLS_CC);
				PHALCON_CPY_WRT(view_path, r7);
				if (phalcon_valid_foreach(templates_before TSRMLS_CC)) {
					ah1 = Z_ARRVAL_P(templates_before);
					zend_hash_internal_pointer_reset_ex(ah1, &hp1);
					fes_b0d8_1:
					if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
						goto fee_b0d8_1;
					}
					PHALCON_INIT_VAR(template_before);
					ZVAL_ZVAL(template_before, *hd, 1, 0);
					PHALCON_INIT_VAR(r8);
					concat_function(r8, view_path, template_before TSRMLS_CC);
					PHALCON_INIT_VAR(r9);
					PHALCON_CONCAT_RIGHT(r9, r8, ".phtml");
					PHALCON_CPY_WRT(template_view, r9);
					if (phalcon_file_exists(template_view TSRMLS_CC) == SUCCESS) {
						PHALCON_CALL_FUNC_NORETURN("ob_clean", 0x019);
						if (phalcon_require(template_view TSRMLS_CC) == FAILURE) {
							return;
						}
						PHALCON_INIT_VAR(r10);
						PHALCON_CALL_FUNC(r10, "ob_get_contents", 0x011);
						phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r10 TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(i0);
						object_init_ex(i0, phalcon_view_exception_ce);
						PHALCON_INIT_VAR(r11);
						PHALCON_CONCAT_BOTH(r11,  "Template '", template_before, "' was not found in layouts directory");
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r11, PHALCON_CHECK);
						phalcon_throw_exception(i0 TSRMLS_CC);
						return;
					}
					
					zend_hash_move_forward_ex(ah1, &hp1);
					goto fes_b0d8_1;
					fee_b0d8_1:
					if(0){ };
				}
			}
			
		}
		
		PHALCON_INIT_VAR(t7);
		ZVAL_LONG(t7, 3);
		PHALCON_INIT_VAR(r12);
		is_smaller_or_equal_function(r12, t7, render_level TSRMLS_CC);
		if (zend_is_true(r12)) {
			PHALCON_ALLOC_ZVAL_MM(r13);
			concat_function(r13, views_dir, layouts_dir TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r14);
			concat_function(r14, r13, controller_name TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r15);
			PHALCON_CONCAT_RIGHT(r15, r14, ".phtml");
			PHALCON_CPY_WRT(view_path, r15);
			if (phalcon_file_exists(view_path TSRMLS_CC) == SUCCESS) {
				PHALCON_CALL_FUNC_NORETURN("ob_clean", 0x019);
				if (phalcon_require(view_path TSRMLS_CC) == FAILURE) {
					return;
				}
				PHALCON_ALLOC_ZVAL_MM(r16);
				PHALCON_CALL_FUNC(r16, "ob_get_contents", 0x011);
				phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r16 TSRMLS_CC);
			}
			
		}
		
		PHALCON_INIT_VAR(t8);
		ZVAL_LONG(t8, 4);
		PHALCON_INIT_VAR(r17);
		is_smaller_or_equal_function(r17, t8, render_level TSRMLS_CC);
		if (zend_is_true(r17)) {
			PHALCON_ALLOC_ZVAL_MM(t9);
			phalcon_read_property(&t9, this_ptr, "_templatesAfter", sizeof("_templatesAfter")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(templates_after, t9);
			if (Z_TYPE_P(templates_after) == IS_ARRAY) { 
				PHALCON_ALLOC_ZVAL_MM(r18);
				concat_function(r18, views_dir, layouts_dir TSRMLS_CC);
				PHALCON_CPY_WRT(view_path, r18);
				if (phalcon_valid_foreach(templates_after TSRMLS_CC)) {
					ah2 = Z_ARRVAL_P(templates_after);
					zend_hash_internal_pointer_reset_ex(ah2, &hp2);
					fes_b0d8_2:
					if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
						goto fee_b0d8_2;
					}
					PHALCON_INIT_VAR(template_after);
					ZVAL_ZVAL(template_after, *hd, 1, 0);
					PHALCON_INIT_VAR(r19);
					concat_function(r19, view_path, template_after TSRMLS_CC);
					PHALCON_INIT_VAR(r20);
					PHALCON_CONCAT_RIGHT(r20, r19, ".phtml");
					PHALCON_CPY_WRT(template_view, r20);
					if (phalcon_file_exists(template_view TSRMLS_CC) == SUCCESS) {
						PHALCON_CALL_FUNC_NORETURN("ob_clean", 0x019);
						if (phalcon_require(template_view TSRMLS_CC) == FAILURE) {
							return;
						}
						PHALCON_INIT_VAR(r21);
						PHALCON_CALL_FUNC(r21, "ob_get_contents", 0x011);
						phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r21 TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(i1);
						object_init_ex(i1, phalcon_view_exception_ce);
						PHALCON_INIT_VAR(r22);
						PHALCON_CONCAT_BOTH(r22,  "Template '", template_before, "' was not found in layouts directory");
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", r22, PHALCON_CHECK);
						phalcon_throw_exception(i1 TSRMLS_CC);
						return;
					}
					
					zend_hash_move_forward_ex(ah2, &hp2);
					goto fes_b0d8_2;
					fee_b0d8_2:
					if(0){ };
				}
			}
			
		}
		
		PHALCON_INIT_VAR(t10);
		ZVAL_LONG(t10, 5);
		PHALCON_INIT_VAR(r23);
		is_smaller_or_equal_function(r23, t10, render_level TSRMLS_CC);
		if (zend_is_true(r23)) {
			PHALCON_ALLOC_ZVAL_MM(r24);
			PHALCON_CONCAT_RIGHT(r24, views_dir, "index.phtml");
			PHALCON_CPY_WRT(view_path, r24);
			if (phalcon_file_exists(view_path TSRMLS_CC) == SUCCESS) {
				PHALCON_CALL_FUNC_NORETURN("ob_clean", 0x019);
				if (phalcon_require(view_path TSRMLS_CC) == FAILURE) {
					return;
				}
				PHALCON_ALLOC_ZVAL_MM(r25);
				PHALCON_CALL_FUNC(r25, "ob_get_contents", 0x011);
				phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), r25 TSRMLS_CC);
			}
			
		}
		
	}
	
	
	PHALCON_MM_RESTORE();
}

/**
 * Renders a partial view
 *
 * @param string $partialName
 */
PHP_METHOD(Phalcon_View, partial){

	zval *partial_name = NULL, *value = NULL, *key = NULL, *views_dir = NULL, *partial_view = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &partial_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY TSRMLS_CC);
	if (phalcon_valid_foreach(t0 TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(t0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_b0d8_3:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_b0d8_3;
		} else {
			PHALCON_INIT_VAR(key);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(key, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(key, hash_num);
				}
			}
		}
		PHALCON_INIT_VAR(value);
		ZVAL_ZVAL(value, *hd, 1, 0);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, value, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			Z_UNSET_ISREF_P(copy);
			ZEND_SET_SYMBOL(EG(active_symbol_table), Z_STRVAL_P(key), copy);
			if (EG(exception)) {
				return;
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_b0d8_3;
		fee_b0d8_3:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_viewsDir", sizeof("_viewsDir")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(views_dir, t1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, views_dir, partial_name TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CONCAT_RIGHT(r1, r0, ".phtml");
	PHALCON_CPY_WRT(partial_view, r1);
	if (phalcon_file_exists(partial_view TSRMLS_CC) == SUCCESS) {
		if (phalcon_require(partial_view TSRMLS_CC) == FAILURE) {
			return;
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_view_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Partial view '", partial_view, "' was not found in views directory");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r2, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	
	PHALCON_MM_RESTORE();
}

/**
 * Finishes render process
 */
PHP_METHOD(Phalcon_View, finish){


	PHALCON_MM_GROW();
	PHALCON_CALL_FUNC_NORETURN("ob_end_clean", 0x012);
	
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

/**
 * Generates a external absolute path to an application uri
 *
 * @param array|string $params
 * @return string
 */
PHP_METHOD(Phalcon_View, url){

	zval *params = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!params) {
		PHALCON_INIT_VAR(params);
		ZVAL_STRING(params, "", 1);
	}
	
	if (Z_TYPE_P(params) == IS_ARRAY) { 
		PHALCON_CALL_FUNC_PARAMS_1_NORETURN("print_r", params, 0x004);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_STATIC_PARAMS_1(r0, "phalcon_utils", "geturl", params);
		PHALCON_RETURN_DZVAL(r0);
	}
	
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns a local path
 *
 * @param array|string $params
 * @return string
 */
PHP_METHOD(Phalcon_View, path){

	zval *params = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!params) {
		PHALCON_INIT_VAR(params);
		ZVAL_STRING(params, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_1(r0, "phalcon_utils", "getlocalpath", params);
	PHALCON_RETURN_DZVAL(r0);
}

