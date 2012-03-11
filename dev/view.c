
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
	phalcon_step_over("Phalcon_View::setViewsDir (Assignment) File=/View Line=83");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_viewsDir", strlen("_viewsDir"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::setViewsDir (Method) File=/View Line=91");
}

/**
 * Gets views directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_View, getViewsDir){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_View", "getViewsDir", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_viewsDir", sizeof("_viewsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_View::getViewsDir (Method) File=/View Line=98");
}

/**
 * Sets the render level for the view
 */
PHP_METHOD(Phalcon_View, setRenderLevel){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_View", "setRenderLevel", 0);
	phalcon_step_over("Phalcon_View::setRenderLevel (Assignment) File=/View Line=99");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_renderLevel", strlen("_renderLevel"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::setRenderLevel (Method) File=/View Line=107");
}

/**
 * Appends template before controller layout
 *
 * @param string|array $templateBefore
 */
PHP_METHOD(Phalcon_View, setTemplateBefore){

	zval *v0 = NULL;
	zval *a0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_View", "setTemplateBefore", 0);
	phalcon_step_over("Phalcon_View::setTemplateBefore (If) File=/View Line=108");
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		phalcon_step_over("Phalcon_View::setTemplateBefore (Block) File=/View Line=108");
		phalcon_step_over("Phalcon_View::setTemplateBefore (Assignment) File=/View Line=109");
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, a0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_templatesBefore", strlen("_templatesBefore"), copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_View::setTemplateBefore (Block) File=/View Line=110");
		phalcon_step_over("Phalcon_View::setTemplateBefore (Assignment) File=/View Line=111");
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_templatesBefore", strlen("_templatesBefore"), copy TSRMLS_CC);
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::setTemplateBefore (Method) File=/View Line=119");
}

/**
 * Resets any template before layouts
 *
 */
PHP_METHOD(Phalcon_View, cleanTemplateBefore){


	phalcon_step_into_entry("Phalcon_View", "cleanTemplateBefore", 0);
	phalcon_step_over("Phalcon_View::cleanTemplateBefore (Assignment) File=/View Line=120");
	zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_templatesBefore", strlen("_templatesBefore") TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::cleanTemplateBefore (Method) File=/View Line=128");
}

/**
 * Appends template after controller layout
 *
 * @param string|array $templateAfter
 */
PHP_METHOD(Phalcon_View, setTemplateAfter){

	zval *v0 = NULL;
	zval *a0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_View", "setTemplateAfter", 0);
	phalcon_step_over("Phalcon_View::setTemplateAfter (If) File=/View Line=129");
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		phalcon_step_over("Phalcon_View::setTemplateAfter (Block) File=/View Line=129");
		phalcon_step_over("Phalcon_View::setTemplateAfter (Assignment) File=/View Line=130");
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, a0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_templatesAfter", strlen("_templatesAfter"), copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_View::setTemplateAfter (Block) File=/View Line=131");
		phalcon_step_over("Phalcon_View::setTemplateAfter (Assignment) File=/View Line=132");
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_templatesAfter", strlen("_templatesAfter"), copy TSRMLS_CC);
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::setTemplateAfter (Method) File=/View Line=140");
}

/**
 * Resets any template before layouts
 *
 */
PHP_METHOD(Phalcon_View, cleanTemplateAfter){


	phalcon_step_into_entry("Phalcon_View", "cleanTemplateAfter", 0);
	phalcon_step_over("Phalcon_View::cleanTemplateAfter (Assignment) File=/View Line=141");
	zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_templatesAfter", strlen("_templatesAfter") TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::cleanTemplateAfter (Method) File=/View Line=150");
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
	phalcon_step_over("Phalcon_View::setParamToView (Assignment) File=/View Line=151");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE(t0);
	phalcon_array_update(t0, v0, v1 TSRMLS_CC);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::setParamToView (Method) File=/View Line=159");
}

/**
 * Returns parameters to views
 *
 * @return array
 */
PHP_METHOD(Phalcon_View, getParamsToView){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_View", "getParamsToView", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_View::getParamsToView (Method) File=/View Line=168");
}

/**
 * Gets the name of the controller rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_View, getControllerName){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_View", "getControllerName", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_controllerName", sizeof("_controllerName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_View::getControllerName (Method) File=/View Line=177");
}

/**
 * Gets the name of the action rendered
 *
 * @return string
 */
PHP_METHOD(Phalcon_View, getActionName){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_View", "getActionName", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_actionName", sizeof("_actionName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_View::getActionName (Method) File=/View Line=184");
}

/**
 * Starts rendering process
 */
PHP_METHOD(Phalcon_View, start){


	phalcon_step_into_entry("Phalcon_View", "start", 0);
	phalcon_step_over("Phalcon_View::start (Assignment) File=/View Line=185");
	zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_content", strlen("_content") TSRMLS_CC);
	phalcon_step_over("Phalcon_View::start (FunctionCall) File=/View Line=186");
	PHALCON_CALL_FUNC_NORETURN("ob_start");
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::start (Method) File=/View Line=195");
}

/**
 * Executes render process from controller data
 *
 * @param string $controllerName
 * @param string $actionName
 */
PHP_METHOD(Phalcon_View, render){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL;
	zval *ac0 = NULL, *ac1 = NULL, *ac2 = NULL;
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
	phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=197");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_viewsDir", sizeof("_viewsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v2, t0);
	phalcon_debug_assign("$viewsDir", t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=198");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_layoutsDir", sizeof("_layoutsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v3, t1);
	phalcon_debug_assign("$layoutsDir", t1 TSRMLS_CC);
	phalcon_step_over("Phalcon_View::render (If) File=/View Line=199");
	if (PHALCON_COMPARE_STRING(v3, "")) {
		phalcon_step_over("Phalcon_View::render (Block) File=/View Line=199");
		phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=200");
		PHALCON_ALLOC_ZVAL(v3);
		ZVAL_STRING(v3, "layouts/", 0);
	}
	phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=203");
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_renderLevel", sizeof("_renderLevel")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v4, t2);
	phalcon_debug_assign("$renderLevel", t2 TSRMLS_CC);
	phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=204");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_controllerName", strlen("_controllerName"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=205");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_actionName", strlen("_actionName"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_View::render (If) File=/View Line=209");
	PHALCON_ALLOC_ZVAL(t3);
	ZVAL_LONG(t3, 6);
	PHALCON_ALLOC_ZVAL(r0);
	is_smaller_function(r0, v4, t3 TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_View::render (Block) File=/View Line=209");
		phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=211");
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_CALL_FUNC(r1, "ob_get_contents");
		phalcon_debug_vdump("ob_get_contents > ", r1 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_View::render (Foreach) File=/View Line=213");
		PHALCON_ALLOC_ZVAL(t4);
		phalcon_read_property(t4, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		FOREACH_KV(t4, ac0, fes7, fee7, ah0, hp0, v6, v5)
			phalcon_step_over("Phalcon_View::render (Block) File=/View Line=213");
			phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=214");
			Z_ADDREF_P(v5);
			ZEND_SET_SYMBOL(EG(active_symbol_table), Z_STRVAL_P(v6), v5);
		END_FOREACH(ac0, fes7, fee7, ah0, hp0);
		phalcon_step_over("Phalcon_View::render (If) File=/View Line=218");
		PHALCON_ALLOC_ZVAL(t5);
		ZVAL_LONG(t5, 1);
		PHALCON_ALLOC_ZVAL(r2);
		is_smaller_or_equal_function(r2, v4, t5 TSRMLS_CC);
		if (zend_is_true(r2)) {
			phalcon_step_over("Phalcon_View::render (Block) File=/View Line=218");
			phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=219");
			PHALCON_ALLOC_ZVAL(r4);
			concat_function(r4, v2, v0 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_concat_vboth(r3, r4, "/", v1 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r5);
			PHALCON_CONCAT_RIGHT(r5, r3, ".phtml");
			PHALCON_CPY_WRT(v7, r5);
			phalcon_debug_assign("$viewPath", r5 TSRMLS_CC);
			phalcon_step_over("Phalcon_View::render (If) File=/View Line=221");
			phalcon_debug_vdump("FileExists? > ", v7 TSRMLS_CC);
			if (phalcon_file_exists(v7 TSRMLS_CC) == SUCCESS) {
				phalcon_step_over("Phalcon_View::render (Block) File=/View Line=221");
				phalcon_step_over("Phalcon_View::render (FunctionCall) File=/View Line=222");
				PHALCON_CALL_FUNC_NORETURN("ob_clean");
				phalcon_step_over("Phalcon_View::render (Require) File=/View Line=223");
				phalcon_debug_vdump("Requiring File > ", v7 TSRMLS_CC);
				phalcon_require(v7 TSRMLS_CC);
				if (EG(exception) || EG(exit_status) == 255) {
					return;
				}
				phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=224");
				PHALCON_ALLOC_ZVAL(r6);
				PHALCON_CALL_FUNC(r6, "ob_get_contents");
				phalcon_debug_vdump("ob_get_contents > ", r6 TSRMLS_CC);
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, r6, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
				}
			}
		}
		phalcon_step_over("Phalcon_View::render (If) File=/View Line=230");
		PHALCON_ALLOC_ZVAL(t6);
		ZVAL_LONG(t6, 2);
		PHALCON_ALLOC_ZVAL(r7);
		is_smaller_or_equal_function(r7, v4, t6 TSRMLS_CC);
		if (zend_is_true(r7)) {
			phalcon_step_over("Phalcon_View::render (Block) File=/View Line=230");
			phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=231");
			PHALCON_ALLOC_ZVAL(t7);
			phalcon_read_property(t7, this_ptr, "_templatesBefore", sizeof("_templatesBefore")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v8, t7);
			phalcon_debug_assign("$templatesBefore", t7 TSRMLS_CC);
			phalcon_step_over("Phalcon_View::render (If) File=/View Line=232");
			if (Z_TYPE_P(v8) == IS_ARRAY) { 
				phalcon_step_over("Phalcon_View::render (Block) File=/View Line=232");
				phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=233");
				PHALCON_ALLOC_ZVAL(r8);
				concat_function(r8, v2, v3 TSRMLS_CC);
				PHALCON_CPY_WRT(v7, r8);
				phalcon_debug_assign("$viewPath", r8 TSRMLS_CC);
				phalcon_step_over("Phalcon_View::render (Foreach) File=/View Line=234");
				FOREACH_V(v8, ac1, fes8, fee8, ah1, hp1, v9)
					phalcon_step_over("Phalcon_View::render (Block) File=/View Line=234");
					phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=235");
					if (!r9) {
						PHALCON_ALLOC_ZVAL(r9);
					} else {
						if (Z_REFCOUNT_P(r9) > 1) {
							PHALCON_SEPARATE(r9);
						} else {
							FREE_ZVAL(r9);
							PHALCON_ALLOC_ZVAL(r9);
						}
					}
					concat_function(r9, v7, v9 TSRMLS_CC);
					if (!r10) {
						PHALCON_ALLOC_ZVAL(r10);
					} else {
						if (Z_REFCOUNT_P(r10) > 1) {
							PHALCON_SEPARATE(r10);
						} else {
							FREE_ZVAL(r10);
							PHALCON_ALLOC_ZVAL(r10);
						}
					}
					PHALCON_CONCAT_RIGHT(r10, r9, ".phtml");
					PHALCON_CPY_WRT(v10, r10);
					phalcon_debug_assign("$templateView", r10 TSRMLS_CC);
					phalcon_step_over("Phalcon_View::render (If) File=/View Line=236");
					phalcon_debug_vdump("FileExists? > ", v10 TSRMLS_CC);
					if (phalcon_file_exists(v10 TSRMLS_CC) == SUCCESS) {
						phalcon_step_over("Phalcon_View::render (Block) File=/View Line=236");
						phalcon_step_over("Phalcon_View::render (FunctionCall) File=/View Line=237");
						PHALCON_CALL_FUNC_NORETURN("ob_clean");
						phalcon_step_over("Phalcon_View::render (Require) File=/View Line=238");
						phalcon_debug_vdump("Requiring File > ", v10 TSRMLS_CC);
						phalcon_require(v10 TSRMLS_CC);
						if (EG(exception) || EG(exit_status) == 255) {
							return;
						}
						phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=239");
						if (!r11) {
							PHALCON_ALLOC_ZVAL(r11);
						} else {
							if (Z_REFCOUNT_P(r11) > 1) {
								PHALCON_SEPARATE(r11);
							} else {
								FREE_ZVAL(r11);
								PHALCON_ALLOC_ZVAL(r11);
							}
						}
						PHALCON_CALL_FUNC(r11, "ob_get_contents");
						phalcon_debug_vdump("ob_get_contents > ", r11 TSRMLS_CC);
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, r11, 1, 0);
							Z_SET_REFCOUNT_P(copy, 0);
							phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
						}
					} else {
						phalcon_step_over("Phalcon_View::render (Block) File=/View Line=240");
						phalcon_step_over("Phalcon_View::render (Throw) File=/View Line=241");
						if (!i0) {
							PHALCON_ALLOC_ZVAL(i0);
						} else {
							if (Z_REFCOUNT_P(i0) > 1) {
								PHALCON_SEPARATE(i0);
							} else {
								FREE_ZVAL(i0);
								PHALCON_ALLOC_ZVAL(i0);
							}
						}
						object_init_ex(i0, phalcon_view_exception_class_entry);
						phalcon_assert_class(this_ptr, "Phalcon_View" TSRMLS_CC);
						phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
						if (!r12) {
							PHALCON_ALLOC_ZVAL(r12);
						} else {
							if (Z_REFCOUNT_P(r12) > 1) {
								PHALCON_SEPARATE(r12);
							} else {
								FREE_ZVAL(r12);
								PHALCON_ALLOC_ZVAL(r12);
							}
						}
						phalcon_concat_both(r12,  "Template '", v9, "' was not found in layouts directory" TSRMLS_CC);
						Z_ADDREF_P(r12);
						p5[0] = r12;
						phalcon_debug_param(r12 TSRMLS_CC);
						PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p5, PHALCON_CALL_CHECK);
						phalcon_assert_class(this_ptr, "Phalcon_View" TSRMLS_CC);
						zend_throw_exception_object(i0 TSRMLS_CC);
						Z_ADDREF_P(i0);
						return;
					}
				END_FOREACH(ac1, fes8, fee8, ah1, hp1);
			}
		}
		phalcon_step_over("Phalcon_View::render (If) File=/View Line=248");
		PHALCON_ALLOC_ZVAL(t8);
		ZVAL_LONG(t8, 3);
		PHALCON_ALLOC_ZVAL(r13);
		is_smaller_or_equal_function(r13, v4, t8 TSRMLS_CC);
		if (zend_is_true(r13)) {
			phalcon_step_over("Phalcon_View::render (Block) File=/View Line=248");
			phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=249");
			PHALCON_ALLOC_ZVAL(r14);
			concat_function(r14, v2, v3 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r15);
			concat_function(r15, r14, v0 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r16);
			PHALCON_CONCAT_RIGHT(r16, r15, ".phtml");
			PHALCON_CPY_WRT(v7, r16);
			phalcon_debug_assign("$viewPath", r16 TSRMLS_CC);
			phalcon_step_over("Phalcon_View::render (If) File=/View Line=251");
			phalcon_debug_vdump("FileExists? > ", v7 TSRMLS_CC);
			if (phalcon_file_exists(v7 TSRMLS_CC) == SUCCESS) {
				phalcon_step_over("Phalcon_View::render (Block) File=/View Line=251");
				phalcon_step_over("Phalcon_View::render (FunctionCall) File=/View Line=252");
				PHALCON_CALL_FUNC_NORETURN("ob_clean");
				phalcon_step_over("Phalcon_View::render (Require) File=/View Line=253");
				phalcon_debug_vdump("Requiring File > ", v7 TSRMLS_CC);
				phalcon_require(v7 TSRMLS_CC);
				if (EG(exception) || EG(exit_status) == 255) {
					return;
				}
				phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=254");
				PHALCON_ALLOC_ZVAL(r17);
				PHALCON_CALL_FUNC(r17, "ob_get_contents");
				phalcon_debug_vdump("ob_get_contents > ", r17 TSRMLS_CC);
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, r17, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
				}
			}
		}
		phalcon_step_over("Phalcon_View::render (If) File=/View Line=260");
		PHALCON_ALLOC_ZVAL(t9);
		ZVAL_LONG(t9, 4);
		PHALCON_ALLOC_ZVAL(r18);
		is_smaller_or_equal_function(r18, v4, t9 TSRMLS_CC);
		if (zend_is_true(r18)) {
			phalcon_step_over("Phalcon_View::render (Block) File=/View Line=260");
			phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=261");
			PHALCON_ALLOC_ZVAL(t10);
			phalcon_read_property(t10, this_ptr, "_templatesAfter", sizeof("_templatesAfter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v11, t10);
			phalcon_debug_assign("$templatesAfter", t10 TSRMLS_CC);
			phalcon_step_over("Phalcon_View::render (If) File=/View Line=262");
			if (Z_TYPE_P(v11) == IS_ARRAY) { 
				phalcon_step_over("Phalcon_View::render (Block) File=/View Line=262");
				phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=263");
				PHALCON_ALLOC_ZVAL(r19);
				concat_function(r19, v2, v3 TSRMLS_CC);
				PHALCON_CPY_WRT(v7, r19);
				phalcon_debug_assign("$viewPath", r19 TSRMLS_CC);
				phalcon_step_over("Phalcon_View::render (Foreach) File=/View Line=264");
				FOREACH_V(v11, ac2, fes9, fee9, ah2, hp2, v12)
					phalcon_step_over("Phalcon_View::render (Block) File=/View Line=264");
					phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=265");
					if (!r20) {
						PHALCON_ALLOC_ZVAL(r20);
					} else {
						if (Z_REFCOUNT_P(r20) > 1) {
							PHALCON_SEPARATE(r20);
						} else {
							FREE_ZVAL(r20);
							PHALCON_ALLOC_ZVAL(r20);
						}
					}
					concat_function(r20, v7, v12 TSRMLS_CC);
					if (!r21) {
						PHALCON_ALLOC_ZVAL(r21);
					} else {
						if (Z_REFCOUNT_P(r21) > 1) {
							PHALCON_SEPARATE(r21);
						} else {
							FREE_ZVAL(r21);
							PHALCON_ALLOC_ZVAL(r21);
						}
					}
					PHALCON_CONCAT_RIGHT(r21, r20, ".phtml");
					PHALCON_CPY_WRT(v10, r21);
					phalcon_debug_assign("$templateView", r21 TSRMLS_CC);
					phalcon_step_over("Phalcon_View::render (If) File=/View Line=266");
					phalcon_debug_vdump("FileExists? > ", v10 TSRMLS_CC);
					if (phalcon_file_exists(v10 TSRMLS_CC) == SUCCESS) {
						phalcon_step_over("Phalcon_View::render (Block) File=/View Line=266");
						phalcon_step_over("Phalcon_View::render (FunctionCall) File=/View Line=267");
						PHALCON_CALL_FUNC_NORETURN("ob_clean");
						phalcon_step_over("Phalcon_View::render (Require) File=/View Line=268");
						phalcon_debug_vdump("Requiring File > ", v10 TSRMLS_CC);
						phalcon_require(v10 TSRMLS_CC);
						if (EG(exception) || EG(exit_status) == 255) {
							return;
						}
						phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=269");
						if (!r22) {
							PHALCON_ALLOC_ZVAL(r22);
						} else {
							if (Z_REFCOUNT_P(r22) > 1) {
								PHALCON_SEPARATE(r22);
							} else {
								FREE_ZVAL(r22);
								PHALCON_ALLOC_ZVAL(r22);
							}
						}
						PHALCON_CALL_FUNC(r22, "ob_get_contents");
						phalcon_debug_vdump("ob_get_contents > ", r22 TSRMLS_CC);
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, r22, 1, 0);
							Z_SET_REFCOUNT_P(copy, 0);
							phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
						}
					} else {
						phalcon_step_over("Phalcon_View::render (Block) File=/View Line=270");
						phalcon_step_over("Phalcon_View::render (Throw) File=/View Line=271");
						if (!i1) {
							PHALCON_ALLOC_ZVAL(i1);
						} else {
							if (Z_REFCOUNT_P(i1) > 1) {
								PHALCON_SEPARATE(i1);
							} else {
								FREE_ZVAL(i1);
								PHALCON_ALLOC_ZVAL(i1);
							}
						}
						object_init_ex(i1, phalcon_view_exception_class_entry);
						phalcon_assert_class(this_ptr, "Phalcon_View" TSRMLS_CC);
						phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
						if (!r23) {
							PHALCON_ALLOC_ZVAL(r23);
						} else {
							if (Z_REFCOUNT_P(r23) > 1) {
								PHALCON_SEPARATE(r23);
							} else {
								FREE_ZVAL(r23);
								PHALCON_ALLOC_ZVAL(r23);
							}
						}
						phalcon_concat_both(r23,  "Template '", v9, "' was not found in layouts directory" TSRMLS_CC);
						Z_ADDREF_P(r23);
						p10[0] = r23;
						phalcon_debug_param(r23 TSRMLS_CC);
						PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p10, PHALCON_CALL_CHECK);
						phalcon_assert_class(this_ptr, "Phalcon_View" TSRMLS_CC);
						zend_throw_exception_object(i1 TSRMLS_CC);
						Z_ADDREF_P(i1);
						return;
					}
				END_FOREACH(ac2, fes9, fee9, ah2, hp2);
			}
		}
		phalcon_step_over("Phalcon_View::render (If) File=/View Line=278");
		PHALCON_ALLOC_ZVAL(t11);
		ZVAL_LONG(t11, 5);
		PHALCON_ALLOC_ZVAL(r24);
		is_smaller_or_equal_function(r24, v4, t11 TSRMLS_CC);
		if (zend_is_true(r24)) {
			phalcon_step_over("Phalcon_View::render (Block) File=/View Line=278");
			phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=279");
			PHALCON_ALLOC_ZVAL(r25);
			PHALCON_CONCAT_RIGHT(r25, v2, "index.phtml");
			PHALCON_CPY_WRT(v7, r25);
			phalcon_debug_assign("$viewPath", r25 TSRMLS_CC);
			phalcon_step_over("Phalcon_View::render (If) File=/View Line=281");
			phalcon_debug_vdump("FileExists? > ", v7 TSRMLS_CC);
			if (phalcon_file_exists(v7 TSRMLS_CC) == SUCCESS) {
				phalcon_step_over("Phalcon_View::render (Block) File=/View Line=281");
				phalcon_step_over("Phalcon_View::render (FunctionCall) File=/View Line=282");
				PHALCON_CALL_FUNC_NORETURN("ob_clean");
				phalcon_step_over("Phalcon_View::render (Require) File=/View Line=283");
				phalcon_debug_vdump("Requiring File > ", v7 TSRMLS_CC);
				phalcon_require(v7 TSRMLS_CC);
				if (EG(exception) || EG(exit_status) == 255) {
					return;
				}
				phalcon_step_over("Phalcon_View::render (Assignment) File=/View Line=284");
				PHALCON_ALLOC_ZVAL(r26);
				PHALCON_CALL_FUNC(r26, "ob_get_contents");
				phalcon_debug_vdump("ob_get_contents > ", r26 TSRMLS_CC);
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, r26, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
				}
			}
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::render (Method) File=/View Line=297");
}

/**
 * Rendes a partial view
 *
 */
PHP_METHOD(Phalcon_View, partial){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_View", "partial", 0);
	phalcon_step_over("Phalcon_View::partial (Foreach) File=/View Line=299");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	FOREACH_KV(t0, ac0, fes10, fee10, ah0, hp0, v2, v1)
		phalcon_step_over("Phalcon_View::partial (Block) File=/View Line=299");
		phalcon_step_over("Phalcon_View::partial (Assignment) File=/View Line=300");
		Z_ADDREF_P(v1);
		ZEND_SET_SYMBOL(EG(active_symbol_table), Z_STRVAL_P(v2), v1);
	END_FOREACH(ac0, fes10, fee10, ah0, hp0);
	phalcon_step_over("Phalcon_View::partial (Assignment) File=/View Line=303");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_viewsDir", sizeof("_viewsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v3, t1);
	phalcon_debug_assign("$viewsDir", t1 TSRMLS_CC);
	phalcon_step_over("Phalcon_View::partial (Assignment) File=/View Line=304");
	PHALCON_ALLOC_ZVAL(r0);
	concat_function(r0, v3, v0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CONCAT_RIGHT(r1, r0, ".phtml");
	PHALCON_CPY_WRT(v4, r1);
	phalcon_debug_assign("$partialView", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_View::partial (If) File=/View Line=305");
	phalcon_debug_vdump("FileExists? > ", v4 TSRMLS_CC);
	if (phalcon_file_exists(v4 TSRMLS_CC) == SUCCESS) {
		phalcon_step_over("Phalcon_View::partial (Block) File=/View Line=305");
		phalcon_step_over("Phalcon_View::partial (Require) File=/View Line=306");
		phalcon_debug_vdump("Requiring File > ", v4 TSRMLS_CC);
		phalcon_require(v4 TSRMLS_CC);
		if (EG(exception) || EG(exit_status) == 255) {
			return;
		}
	} else {
		phalcon_step_over("Phalcon_View::partial (Block) File=/View Line=307");
		phalcon_step_over("Phalcon_View::partial (Throw) File=/View Line=308");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_view_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_View" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_both(r2,  "Partial view '", v4, "' was not found in views directory" TSRMLS_CC);
		Z_ADDREF_P(r2);
		p0[0] = r2;
		phalcon_debug_param(r2 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_View" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::partial (Method) File=/View Line=316");
}

/**
 * Finish render process
 */
PHP_METHOD(Phalcon_View, finish){


	phalcon_step_into_entry("Phalcon_View", "finish", 0);
	phalcon_step_over("Phalcon_View::finish (FunctionCall) File=/View Line=317");
	PHALCON_CALL_FUNC_NORETURN("ob_end_clean");
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_View::finish (Method) File=/View Line=325");
}

/**
 * Returns cached ouput on another view stage
 *
 * @return string
 */
PHP_METHOD(Phalcon_View, getContent){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_View", "getContent", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_content", sizeof("_content")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_View::getContent (Method) File=/View Line=335");
}

/**
 * Generates a external absolute path to an application uri
 *
 * @param array|string $params
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
	phalcon_step_over("Phalcon_View::url (If) File=/View Line=336");
	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		phalcon_step_over("Phalcon_View::url (Block) File=/View Line=336");
		phalcon_step_over("Phalcon_View::url (FunctionCall) File=/View Line=337");
		p0[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_NORETURN("print_r", 1, p0);
	} else {
		phalcon_step_over("Phalcon_View::url (Block) File=/View Line=338");
		PHALCON_ALLOC_ZVAL(r0);
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
	phalcon_step_over("Phalcon_View::url (Method) File=/View Line=349");
}

/**
 * Returns local path
 *
 * @param array|string $params
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

