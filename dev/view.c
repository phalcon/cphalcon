
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

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Php_View
 *
 * Php_View is a class for working with the "view" portion of the model-view-controller pattern.
 * That is, it exists to help keep the view script separate from the model and controller scripts.
 * It provides a system of helpers, output filters, and variable escaping.
 */

PHP_METHOD(Phalcon_View, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;

	phalcon_step_into_entry("Phalcon_View", "::__construct", 0);
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_property(phalcon_view_class_entry, this_ptr, "_params", strlen("_params"), a0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	zend_update_property(phalcon_view_class_entry, this_ptr, "_templatesBefore", strlen("_templatesBefore"), a1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	zend_update_property(phalcon_view_class_entry, this_ptr, "_templatesAfter", strlen("_templatesAfter"), a2 TSRMLS_CC);
}

/**
 * Sets views directory
 *
 * @param string $viewsDir
 */
PHP_METHOD(Phalcon_View, setViewsDir){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_View", "setViewsDir", 0);
	phalcon_step_over("Phalcon_View::setViewsDir (Assignment) File=Library/Phalcon/View.php Line=28");
	//$viewsDir
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_viewsDir", strlen("_viewsDir"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::setViewsDir (Method) File=Library/Phalcon/View.php Line=36");
}

/**
 * Gets views directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_View, getViewsDir){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_View", "getViewsDir", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_viewsDir", sizeof("_viewsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t0) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_View::getViewsDir (Method) File=Library/Phalcon/View.php Line=45");
}

/**
 * Appends template before controller layout
 *
 * @param string $templateAfter
 */
PHP_METHOD(Phalcon_View, setTemplateBefore){

	zval *v0 = NULL;
	zval *a0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_View", "setTemplateBefore", 0);
	phalcon_step_over("Phalcon_View::setTemplateBefore (Assignment) File=Library/Phalcon/View.php Line=46");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	//$templateBefore
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		{
			zval *orig_ptr = a0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(a0);
				*a0 = *orig_ptr;
				zval_copy_ctor(a0);
				Z_SET_REFCOUNT_P(a0, 1);
				Z_UNSET_ISREF_P(a0);
			}
		}
		add_next_index_zval(a0, copy);
	}
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, a0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_templatesBefore", strlen("_templatesBefore"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::setTemplateBefore (Method) File=Library/Phalcon/View.php Line=54");
}

/**
 * Appends template after controller layout
 *
 * @param string $templateAfter
 */
PHP_METHOD(Phalcon_View, setTemplateAfter){

	zval *v0 = NULL;
	zval *a0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_View", "setTemplateAfter", 0);
	phalcon_step_over("Phalcon_View::setTemplateAfter (Assignment) File=Library/Phalcon/View.php Line=55");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	//$templateAfter
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		{
			zval *orig_ptr = a0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(a0);
				*a0 = *orig_ptr;
				zval_copy_ctor(a0);
				Z_SET_REFCOUNT_P(a0, 1);
				Z_UNSET_ISREF_P(a0);
			}
		}
		add_next_index_zval(a0, copy);
	}
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, a0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_templatesAfter", strlen("_templatesAfter"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::setTemplateAfter (Method) File=Library/Phalcon/View.php Line=64");
}

/**
 * Adds parameter to views
 *
 * @param string $key
 * @param mixed $value
 */
PHP_METHOD(Phalcon_View, setParamToView){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_View", "setParamToView", 0);
	phalcon_step_over("Phalcon_View::setParamToView (Assignment) File=Library/Phalcon/View.php Line=65");
	//$value
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	//$key
	{
		zval *orig_ptr = t0;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(t0);
			*t0 = *orig_ptr;
			zval_copy_ctor(t0);
			Z_SET_REFCOUNT_P(t0, 1);
			Z_UNSET_ISREF_P(t0);
		}
	}
	phalcon_array_update(t0, v0, v1 TSRMLS_CC);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::setParamToView (Method) File=Library/Phalcon/View.php Line=73");
}

/**
 * Returns parameters to views
 *
 * @return array 
 */
PHP_METHOD(Phalcon_View, getParamsToView){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_View", "getParamsToView", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t0) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_View::getParamsToView (Method) File=Library/Phalcon/View.php Line=80");
}

/**
 * Starts rendering process
 */
PHP_METHOD(Phalcon_View, start){


	phalcon_step_into_entry("Phalcon_View", "start", 0);
	phalcon_step_over("Phalcon_View::start (FunctionCall) File=Library/Phalcon/View.php Line=81");
	PHALCON_CALL_FUNC_NORETURN("ob_start");
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::start (Method) File=Library/Phalcon/View.php Line=90");
}

/**
 * Executes render process from controller data
 *
 * @param string $controllerName
 * @param string $actionName
 */
PHP_METHOD(Phalcon_View, render){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *ac0 = NULL, *ac1 = NULL, *ac2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p5[] = { NULL }, *p10[] = { NULL };
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_View", "render", 0);
	phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=92");
	//$viewsDir
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_viewsDir", sizeof("_viewsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(t0);
	v2 = t0;
	phalcon_debug_assign("$viewsDir", t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=93");
	//$layoutsDir
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_layoutsDir", sizeof("_layoutsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(t1);
	v3 = t1;
	phalcon_debug_assign("$layoutsDir", t1 TSRMLS_CC);
	phalcon_step_over("Phalcon_View::render (If) File=Library/Phalcon/View.php Line=94");
	//$layoutsDir
	if (phalcon_compare_strict_string(v3, "")) {
		phalcon_step_over("Phalcon_View::render (Block) File=Library/Phalcon/View.php Line=94");
		phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=95");
		//$layoutsDir
		PHALCON_ALLOC_ZVAL(v3);
		ZVAL_STRING(v3, "layouts/", 0);
	}
	phalcon_step_over("Phalcon_View::render (Foreach) File=Library/Phalcon/View.php Line=98");
	//$this
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
	//$value
	//$key
	FOREACH_KV(t2, ac0, fes7, fee7, ah0, hp0, v5, v4)
		phalcon_step_over("Phalcon_View::render (Block) File=Library/Phalcon/View.php Line=98");
		phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=99");
		//$key
		//$value
		ZEND_SET_SYMBOL(EG(active_symbol_table), Z_STRVAL_P(v5), v4);
	END_FOREACH(ac0, fes7, fee7, ah0, hp0);
	phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=102");
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_FUNC(r0, "ob_get_contents");
	phalcon_debug_vdump("ob_get_contents > ", r0 TSRMLS_CC);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, r0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=105");
	//$viewPath
	//$viewsDir
	//$controllerName
	PHALCON_ALLOC_ZVAL(r2);
	concat_function(r2, v2, v0 TSRMLS_CC);
	//$actionName
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_concat_vboth(r1, r2, "/", v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r3);
	phalcon_concat_right(r3, r1, ".phtml" TSRMLS_CC);
	if (v6) {
		Z_DELREF_P(v6);
		if (!Z_REFCOUNT_P(v6)) {
			FREE_ZVAL(v6);
		}
	}
	Z_ADDREF_P(r3);
	v6 = r3;
	phalcon_debug_assign("$viewPath", r3 TSRMLS_CC);
	phalcon_step_over("Phalcon_View::render (If) File=Library/Phalcon/View.php Line=107");
	//$viewPath
	phalcon_debug_vdump("FileExists? > ", v6 TSRMLS_CC);
	if (phalcon_file_exists(v6 TSRMLS_CC) == SUCCESS) {
		phalcon_step_over("Phalcon_View::render (Block) File=Library/Phalcon/View.php Line=107");
		phalcon_step_over("Phalcon_View::render (FunctionCall) File=Library/Phalcon/View.php Line=108");
		PHALCON_CALL_FUNC_NORETURN("ob_clean");
		phalcon_step_over("Phalcon_View::render (Require) File=Library/Phalcon/View.php Line=109");
		//$viewPath
		phalcon_debug_vdump("Requiring File > ", v6 TSRMLS_CC);
		phalcon_require(v6 TSRMLS_CC);
		if (EG(exception) || EG(exit_status) == 255) {
			return;
		}
		phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=110");
		PHALCON_ALLOC_ZVAL(r4);
		PHALCON_CALL_FUNC(r4, "ob_get_contents");
		phalcon_debug_vdump("ob_get_contents > ", r4 TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r4, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=114");
	//$templatesBefore
	//$this
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, this_ptr, "_templatesBefore", sizeof("_templatesBefore")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t3);
	if (v7) {
		Z_DELREF_P(v7);
		if (!Z_REFCOUNT_P(v7)) {
			FREE_ZVAL(v7);
		}
	}
	Z_ADDREF_P(t3);
	v7 = t3;
	phalcon_debug_assign("$templatesBefore", t3 TSRMLS_CC);
	phalcon_step_over("Phalcon_View::render (If) File=Library/Phalcon/View.php Line=115");
	//$templatesBefore
	if (Z_TYPE_P(v7) == IS_ARRAY) { 
		phalcon_step_over("Phalcon_View::render (Block) File=Library/Phalcon/View.php Line=115");
		phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=116");
		//$viewPath
		//$viewsDir
		//$layoutsDir
		PHALCON_ALLOC_ZVAL(r5);
		concat_function(r5, v2, v3 TSRMLS_CC);
		if (v6) {
			Z_DELREF_P(v6);
			if (!Z_REFCOUNT_P(v6)) {
				FREE_ZVAL(v6);
			}
		}
		Z_ADDREF_P(r5);
		v6 = r5;
		phalcon_debug_assign("$viewPath", r5 TSRMLS_CC);
		phalcon_step_over("Phalcon_View::render (Foreach) File=Library/Phalcon/View.php Line=117");
		//$templatesBefore
		//$templateBefore
		FOREACH_V(v7, ac1, fes8, fee8, ah1, hp1, v8)
			phalcon_step_over("Phalcon_View::render (Block) File=Library/Phalcon/View.php Line=117");
			phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=118");
			//$templateView
			//$viewPath
			//$templateBefore
			if (!r6) {
				PHALCON_ALLOC_ZVAL(r6);
			} else {
				if (Z_REFCOUNT_P(r6) > 1) {
					{
						zval *orig_ptr = r6;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r6);
							*r6 = *orig_ptr;
							zval_copy_ctor(r6);
							Z_SET_REFCOUNT_P(r6, 1);
							Z_UNSET_ISREF_P(r6);
						}
					}
				} else {
					FREE_ZVAL(r6);
					PHALCON_ALLOC_ZVAL(r6);
				}
			}
			concat_function(r6, v6, v8 TSRMLS_CC);
			if (!r7) {
				PHALCON_ALLOC_ZVAL(r7);
			} else {
				if (Z_REFCOUNT_P(r7) > 1) {
					{
						zval *orig_ptr = r7;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r7);
							*r7 = *orig_ptr;
							zval_copy_ctor(r7);
							Z_SET_REFCOUNT_P(r7, 1);
							Z_UNSET_ISREF_P(r7);
						}
					}
				} else {
					FREE_ZVAL(r7);
					PHALCON_ALLOC_ZVAL(r7);
				}
			}
			phalcon_concat_right(r7, r6, ".phtml" TSRMLS_CC);
			if (v9) {
				Z_DELREF_P(v9);
				if (!Z_REFCOUNT_P(v9)) {
					FREE_ZVAL(v9);
				}
			}
			Z_ADDREF_P(r7);
			v9 = r7;
			phalcon_debug_assign("$templateView", r7 TSRMLS_CC);
			phalcon_step_over("Phalcon_View::render (If) File=Library/Phalcon/View.php Line=120");
			//$templateView
			phalcon_debug_vdump("FileExists? > ", v9 TSRMLS_CC);
			if (phalcon_file_exists(v9 TSRMLS_CC) == SUCCESS) {
				phalcon_step_over("Phalcon_View::render (Block) File=Library/Phalcon/View.php Line=120");
				phalcon_step_over("Phalcon_View::render (FunctionCall) File=Library/Phalcon/View.php Line=121");
				PHALCON_CALL_FUNC_NORETURN("ob_clean");
				phalcon_step_over("Phalcon_View::render (Require) File=Library/Phalcon/View.php Line=122");
				//$templateView
				phalcon_debug_vdump("Requiring File > ", v9 TSRMLS_CC);
				phalcon_require(v9 TSRMLS_CC);
				if (EG(exception) || EG(exit_status) == 255) {
					return;
				}
				phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=123");
				if (!r8) {
					PHALCON_ALLOC_ZVAL(r8);
				} else {
					if (Z_REFCOUNT_P(r8) > 1) {
						{
							zval *orig_ptr = r8;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r8);
								*r8 = *orig_ptr;
								zval_copy_ctor(r8);
								Z_SET_REFCOUNT_P(r8, 1);
								Z_UNSET_ISREF_P(r8);
							}
						}
					} else {
						FREE_ZVAL(r8);
						PHALCON_ALLOC_ZVAL(r8);
					}
				}
				PHALCON_CALL_FUNC(r8, "ob_get_contents");
				phalcon_debug_vdump("ob_get_contents > ", r8 TSRMLS_CC);
				//$this
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, r8, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
				}
			} else {
				phalcon_step_over("Phalcon_View::render (Block) File=Library/Phalcon/View.php Line=124");
				phalcon_step_over("Phalcon_View::render (Throw) File=Library/Phalcon/View.php Line=125");
				if (!i0) {
					PHALCON_ALLOC_ZVAL(i0);
				} else {
					if (Z_REFCOUNT_P(i0) > 1) {
						{
							zval *orig_ptr = i0;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(i0);
								*i0 = *orig_ptr;
								zval_copy_ctor(i0);
								Z_SET_REFCOUNT_P(i0, 1);
								Z_UNSET_ISREF_P(i0);
							}
						}
					} else {
						FREE_ZVAL(i0);
						PHALCON_ALLOC_ZVAL(i0);
					}
				}
				object_init_ex(i0, phalcon_view_exception_class_entry);
				phalcon_assert_class(this_ptr, "Phalcon_View" TSRMLS_CC);
				phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
				//$templateBefore
				if (!r9) {
					PHALCON_ALLOC_ZVAL(r9);
				} else {
					if (Z_REFCOUNT_P(r9) > 1) {
						{
							zval *orig_ptr = r9;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r9);
								*r9 = *orig_ptr;
								zval_copy_ctor(r9);
								Z_SET_REFCOUNT_P(r9, 1);
								Z_UNSET_ISREF_P(r9);
							}
						}
					} else {
						FREE_ZVAL(r9);
						PHALCON_ALLOC_ZVAL(r9);
					}
				}
				phalcon_concat_both(r9,  "Template '", v8, "' was not found on templates directory" TSRMLS_CC);
				Z_ADDREF_P(r9);
				p5[0] = r9;
				phalcon_debug_param(r9 TSRMLS_CC);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p5, PHALCON_CALL_CHECK);
				phalcon_assert_class(this_ptr, "Phalcon_View" TSRMLS_CC);
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				return;
			}
		END_FOREACH(ac1, fes8, fee8, ah1, hp1);
	}
	phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=131");
	//$viewPath
	//$viewsDir
	//$layoutsDir
	PHALCON_ALLOC_ZVAL(r10);
	concat_function(r10, v2, v3 TSRMLS_CC);
	//$controllerName
	PHALCON_ALLOC_ZVAL(r11);
	concat_function(r11, r10, v0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r12);
	phalcon_concat_right(r12, r11, ".phtml" TSRMLS_CC);
	if (v6) {
		Z_DELREF_P(v6);
		if (!Z_REFCOUNT_P(v6)) {
			FREE_ZVAL(v6);
		}
	}
	Z_ADDREF_P(r12);
	v6 = r12;
	phalcon_debug_assign("$viewPath", r12 TSRMLS_CC);
	phalcon_step_over("Phalcon_View::render (If) File=Library/Phalcon/View.php Line=133");
	//$viewPath
	phalcon_debug_vdump("FileExists? > ", v6 TSRMLS_CC);
	if (phalcon_file_exists(v6 TSRMLS_CC) == SUCCESS) {
		phalcon_step_over("Phalcon_View::render (Block) File=Library/Phalcon/View.php Line=133");
		phalcon_step_over("Phalcon_View::render (FunctionCall) File=Library/Phalcon/View.php Line=134");
		PHALCON_CALL_FUNC_NORETURN("ob_clean");
		phalcon_step_over("Phalcon_View::render (Require) File=Library/Phalcon/View.php Line=135");
		//$viewPath
		phalcon_debug_vdump("Requiring File > ", v6 TSRMLS_CC);
		phalcon_require(v6 TSRMLS_CC);
		if (EG(exception) || EG(exit_status) == 255) {
			return;
		}
		phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=136");
		PHALCON_ALLOC_ZVAL(r13);
		PHALCON_CALL_FUNC(r13, "ob_get_contents");
		phalcon_debug_vdump("ob_get_contents > ", r13 TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r13, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=140");
	//$templatesAfter
	//$this
	PHALCON_ALLOC_ZVAL(t4);
	phalcon_read_property(t4, this_ptr, "_templatesAfter", sizeof("_templatesAfter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t4);
	if (v10) {
		Z_DELREF_P(v10);
		if (!Z_REFCOUNT_P(v10)) {
			FREE_ZVAL(v10);
		}
	}
	Z_ADDREF_P(t4);
	v10 = t4;
	phalcon_debug_assign("$templatesAfter", t4 TSRMLS_CC);
	phalcon_step_over("Phalcon_View::render (If) File=Library/Phalcon/View.php Line=141");
	//$templatesAfter
	if (Z_TYPE_P(v10) == IS_ARRAY) { 
		phalcon_step_over("Phalcon_View::render (Block) File=Library/Phalcon/View.php Line=141");
		phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=142");
		//$viewPath
		//$viewsDir
		//$layoutsDir
		PHALCON_ALLOC_ZVAL(r14);
		concat_function(r14, v2, v3 TSRMLS_CC);
		if (v6) {
			Z_DELREF_P(v6);
			if (!Z_REFCOUNT_P(v6)) {
				FREE_ZVAL(v6);
			}
		}
		Z_ADDREF_P(r14);
		v6 = r14;
		phalcon_debug_assign("$viewPath", r14 TSRMLS_CC);
		phalcon_step_over("Phalcon_View::render (Foreach) File=Library/Phalcon/View.php Line=143");
		//$templatesAfter
		//$templateAfter
		FOREACH_V(v10, ac2, fes9, fee9, ah2, hp2, v11)
			phalcon_step_over("Phalcon_View::render (Block) File=Library/Phalcon/View.php Line=143");
			phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=144");
			//$templateView
			//$viewPath
			//$templateAfter
			if (!r15) {
				PHALCON_ALLOC_ZVAL(r15);
			} else {
				if (Z_REFCOUNT_P(r15) > 1) {
					{
						zval *orig_ptr = r15;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r15);
							*r15 = *orig_ptr;
							zval_copy_ctor(r15);
							Z_SET_REFCOUNT_P(r15, 1);
							Z_UNSET_ISREF_P(r15);
						}
					}
				} else {
					FREE_ZVAL(r15);
					PHALCON_ALLOC_ZVAL(r15);
				}
			}
			concat_function(r15, v6, v11 TSRMLS_CC);
			if (!r16) {
				PHALCON_ALLOC_ZVAL(r16);
			} else {
				if (Z_REFCOUNT_P(r16) > 1) {
					{
						zval *orig_ptr = r16;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r16);
							*r16 = *orig_ptr;
							zval_copy_ctor(r16);
							Z_SET_REFCOUNT_P(r16, 1);
							Z_UNSET_ISREF_P(r16);
						}
					}
				} else {
					FREE_ZVAL(r16);
					PHALCON_ALLOC_ZVAL(r16);
				}
			}
			phalcon_concat_right(r16, r15, ".phtml" TSRMLS_CC);
			if (v9) {
				Z_DELREF_P(v9);
				if (!Z_REFCOUNT_P(v9)) {
					FREE_ZVAL(v9);
				}
			}
			Z_ADDREF_P(r16);
			v9 = r16;
			phalcon_debug_assign("$templateView", r16 TSRMLS_CC);
			phalcon_step_over("Phalcon_View::render (If) File=Library/Phalcon/View.php Line=146");
			//$templateView
			phalcon_debug_vdump("FileExists? > ", v9 TSRMLS_CC);
			if (phalcon_file_exists(v9 TSRMLS_CC) == SUCCESS) {
				phalcon_step_over("Phalcon_View::render (Block) File=Library/Phalcon/View.php Line=146");
				phalcon_step_over("Phalcon_View::render (FunctionCall) File=Library/Phalcon/View.php Line=147");
				PHALCON_CALL_FUNC_NORETURN("ob_clean");
				phalcon_step_over("Phalcon_View::render (Require) File=Library/Phalcon/View.php Line=148");
				//$templateView
				phalcon_debug_vdump("Requiring File > ", v9 TSRMLS_CC);
				phalcon_require(v9 TSRMLS_CC);
				if (EG(exception) || EG(exit_status) == 255) {
					return;
				}
				phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=149");
				if (!r17) {
					PHALCON_ALLOC_ZVAL(r17);
				} else {
					if (Z_REFCOUNT_P(r17) > 1) {
						{
							zval *orig_ptr = r17;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r17);
								*r17 = *orig_ptr;
								zval_copy_ctor(r17);
								Z_SET_REFCOUNT_P(r17, 1);
								Z_UNSET_ISREF_P(r17);
							}
						}
					} else {
						FREE_ZVAL(r17);
						PHALCON_ALLOC_ZVAL(r17);
					}
				}
				PHALCON_CALL_FUNC(r17, "ob_get_contents");
				phalcon_debug_vdump("ob_get_contents > ", r17 TSRMLS_CC);
				//$this
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, r17, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
				}
			} else {
				phalcon_step_over("Phalcon_View::render (Block) File=Library/Phalcon/View.php Line=150");
				phalcon_step_over("Phalcon_View::render (Throw) File=Library/Phalcon/View.php Line=151");
				if (!i1) {
					PHALCON_ALLOC_ZVAL(i1);
				} else {
					if (Z_REFCOUNT_P(i1) > 1) {
						{
							zval *orig_ptr = i1;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(i1);
								*i1 = *orig_ptr;
								zval_copy_ctor(i1);
								Z_SET_REFCOUNT_P(i1, 1);
								Z_UNSET_ISREF_P(i1);
							}
						}
					} else {
						FREE_ZVAL(i1);
						PHALCON_ALLOC_ZVAL(i1);
					}
				}
				object_init_ex(i1, phalcon_view_exception_class_entry);
				phalcon_assert_class(this_ptr, "Phalcon_View" TSRMLS_CC);
				phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
				//$templateBefore
				if (!r18) {
					PHALCON_ALLOC_ZVAL(r18);
				} else {
					if (Z_REFCOUNT_P(r18) > 1) {
						{
							zval *orig_ptr = r18;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r18);
								*r18 = *orig_ptr;
								zval_copy_ctor(r18);
								Z_SET_REFCOUNT_P(r18, 1);
								Z_UNSET_ISREF_P(r18);
							}
						}
					} else {
						FREE_ZVAL(r18);
						PHALCON_ALLOC_ZVAL(r18);
					}
				}
				phalcon_concat_both(r18,  "Template '", v8, "' was not found on templates directory" TSRMLS_CC);
				Z_ADDREF_P(r18);
				p10[0] = r18;
				phalcon_debug_param(r18 TSRMLS_CC);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p10, PHALCON_CALL_CHECK);
				phalcon_assert_class(this_ptr, "Phalcon_View" TSRMLS_CC);
				zend_throw_exception_object(i1 TSRMLS_CC);
				Z_ADDREF_P(i1);
				return;
			}
		END_FOREACH(ac2, fes9, fee9, ah2, hp2);
	}
	phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=157");
	//$viewPath
	//$viewsDir
	PHALCON_ALLOC_ZVAL(r19);
	phalcon_concat_right(r19, v2, "index.phtml" TSRMLS_CC);
	if (v6) {
		Z_DELREF_P(v6);
		if (!Z_REFCOUNT_P(v6)) {
			FREE_ZVAL(v6);
		}
	}
	Z_ADDREF_P(r19);
	v6 = r19;
	phalcon_debug_assign("$viewPath", r19 TSRMLS_CC);
	phalcon_step_over("Phalcon_View::render (If) File=Library/Phalcon/View.php Line=159");
	//$viewPath
	phalcon_debug_vdump("FileExists? > ", v6 TSRMLS_CC);
	if (phalcon_file_exists(v6 TSRMLS_CC) == SUCCESS) {
		phalcon_step_over("Phalcon_View::render (Block) File=Library/Phalcon/View.php Line=159");
		phalcon_step_over("Phalcon_View::render (FunctionCall) File=Library/Phalcon/View.php Line=160");
		PHALCON_CALL_FUNC_NORETURN("ob_clean");
		phalcon_step_over("Phalcon_View::render (Require) File=Library/Phalcon/View.php Line=161");
		//$viewPath
		phalcon_debug_vdump("Requiring File > ", v6 TSRMLS_CC);
		phalcon_require(v6 TSRMLS_CC);
		if (EG(exception) || EG(exit_status) == 255) {
			return;
		}
		phalcon_step_over("Phalcon_View::render (Assignment) File=Library/Phalcon/View.php Line=162");
		PHALCON_ALLOC_ZVAL(r20);
		PHALCON_CALL_FUNC(r20, "ob_get_contents");
		phalcon_debug_vdump("ob_get_contents > ", r20 TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r20, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::render (Method) File=Library/Phalcon/View.php Line=170");
}

/**
 * Finish render process
 */
PHP_METHOD(Phalcon_View, finish){


	phalcon_step_into_entry("Phalcon_View", "finish", 0);
	phalcon_step_over("Phalcon_View::finish (FunctionCall) File=Library/Phalcon/View.php Line=171");
	PHALCON_CALL_FUNC_NORETURN("ob_end_clean");
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::finish (Method) File=Library/Phalcon/View.php Line=179");
}

/**
 * Returns cached ouput on another view stage
 *
 * @return string
 */
PHP_METHOD(Phalcon_View, getContent){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_View", "getContent", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_content", sizeof("_content")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t0) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_View::getContent (Method) File=Library/Phalcon/View.php Line=188");
}

/**
 * Generates a external absolute path to an application uri
 *
 * @return string
 */
PHP_METHOD(Phalcon_View, url){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_View", "url", 0);
	phalcon_step_over("Phalcon_View::url (If) File=Library/Phalcon/View.php Line=189");
	//$params
	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		phalcon_step_over("Phalcon_View::url (Block) File=Library/Phalcon/View.php Line=189");
		phalcon_step_over("Phalcon_View::url (FunctionCall) File=Library/Phalcon/View.php Line=190");
		//$params
		p0[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_NORETURN("print_r", 1, p0);
	} else {
		phalcon_step_over("Phalcon_View::url (Block) File=Library/Phalcon/View.php Line=191");
		PHALCON_ALLOC_ZVAL(r0);
		//$params
		Z_ADDREF_P(v0);
		p1[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_utils", "geturl", 1, p1);
		phalcon_debug_vdump("StaticReturn > ", r0 TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_ZVAL(r0, 1, 0);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::url (Method) File=Library/Phalcon/View.php Line=201");
}

/**
 * Returns local path
 *
 * @return string
 */
PHP_METHOD(Phalcon_View, path){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_View", "path", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$params
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_utils", "getlocalpath", 1, p0);
	phalcon_debug_vdump("StaticReturn > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
}

