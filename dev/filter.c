
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
 * Php_Filter
 *
 * The Php_Filter component provides a set of commonly needed data filters. It provides
 * object oriented wrappers to the php filter extension
 */

/**
 * Sanizites a value with a specified single or set of filters
 *
 * @param mixed $value
 * @param mixed $filters
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, sanitize){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Filter", "sanitize", 0);
	phalcon_step_over("Phalcon_Filter::sanitize (If) File=Library/Phalcon/Filter.php Line=19");
	//$filters
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		phalcon_step_over("Phalcon_Filter::sanitize (Block) File=Library/Phalcon/Filter.php Line=19");
		phalcon_step_over("Phalcon_Filter::sanitize (If) File=Library/Phalcon/Filter.php Line=20");
		//$value
		if (zend_is_true(v0)) {
			phalcon_step_over("Phalcon_Filter::sanitize (Block) File=Library/Phalcon/Filter.php Line=20");
			phalcon_step_over("Phalcon_Filter::sanitize (Foreach) File=Library/Phalcon/Filter.php Line=21");
			//$filters
			//$filter
			FOREACH_V(v1, ac0, fes52, fee52, ah0, hp0, v2)
				phalcon_step_over("Phalcon_Filter::sanitize (Block) File=Library/Phalcon/Filter.php Line=21");
				phalcon_step_over("Phalcon_Filter::sanitize (Assignment) File=Library/Phalcon/Filter.php Line=22");
				//$value
				if (!r0) {
					PHALCON_ALLOC_ZVAL(r0);
				} else {
					if (Z_REFCOUNT_P(r0) > 1) {
						{
							zval *orig_ptr = r0;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r0);
								*r0 = *orig_ptr;
								zval_copy_ctor(r0);
								Z_SET_REFCOUNT_P(r0, 1);
								Z_UNSET_ISREF_P(r0);
							}
						}
					} else {
						FREE_ZVAL(r0);
						PHALCON_ALLOC_ZVAL(r0);
					}
				}
				//$this
				phalcon_assert_class(this_ptr, "Phalcon_Filter" TSRMLS_CC);
				phalcon_debug_method_call(this_ptr, "_sanitize" TSRMLS_CC);
				//$value
				Z_ADDREF_P(v0);
				p0[0] = v0;
				phalcon_debug_param(v0 TSRMLS_CC);
				//$filter
				Z_ADDREF_P(v2);
				p0[1] = v2;
				phalcon_debug_param(v2 TSRMLS_CC);
				PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_sanitize", 2, p0, PHALCON_CALL_DEFAULT);
				phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
				phalcon_assert_class(this_ptr, "Phalcon_Filter" TSRMLS_CC);
				if (v0) {
					if (!Z_REFCOUNT_P(v0)) {
						FREE_ZVAL(v0);
					}
				}
				Z_ADDREF_P(r0);
				v0 = r0;
				phalcon_debug_assign("$value", r0 TSRMLS_CC);
			END_FOREACH(ac0, fes52, fee52, ah0, hp0);
		}
		//$value
		phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(v0) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v0);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v0);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Filter::sanitize (Block) File=Library/Phalcon/Filter.php Line=26");
		PHALCON_ALLOC_ZVAL(r1);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Filter" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "_sanitize" TSRMLS_CC);
		//$value
		Z_ADDREF_P(v0);
		p1[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		//$filters
		Z_ADDREF_P(v1);
		p1[1] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "_sanitize", 2, p1, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Filter" TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r1 TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_ZVAL(r1, 1, 0);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Filter::sanitize (Method) File=Library/Phalcon/Filter.php Line=38");
}

/**
 * Internal sanizite wrapper to filter_var
 *
 * @param mixed $value
 * @param mixed $filters
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, _sanitize){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL, NULL }, *p2[] = { NULL, NULL }, *p3[] = { NULL, NULL, NULL }, *p4[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Filter", "_sanitize", 0);
	phalcon_step_over("Phalcon_Filter::_sanitize (Switch) File=Library/Phalcon/Filter.php Line=39");
	//$filter
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "email", 1);
	PHALCON_EQUAL_FUNCTION(r0, v1, t0);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL(r1);
		//$value
		p0[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		//UnresolvedConstantParam=FILTER_SANITIZE_EMAIL
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_LONG(t1, 517);
		p0[1] = t1;
		phalcon_debug_param(t1 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r1, "filter_var", 2, p0);
		phalcon_debug_vdump("filter_var > ", r1 TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r1 TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_ZVAL(r1, 1, 0);
	}
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_STRING(t2, "int", 1);
	PHALCON_EQUAL_FUNCTION(r2, v1, t2);
	if (zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL(r3);
		//$value
		p1[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		//UnresolvedConstantParam=FILTER_SANITIZE_NUMBER_INT
		PHALCON_ALLOC_ZVAL(t3);
		ZVAL_LONG(t3, 519);
		p1[1] = t3;
		phalcon_debug_param(t3 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r3, "filter_var", 2, p1);
		phalcon_debug_vdump("filter_var > ", r3 TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_ZVAL(r3, 1, 0);
	}
	PHALCON_ALLOC_ZVAL(t4);
	ZVAL_STRING(t4, "string", 1);
	PHALCON_EQUAL_FUNCTION(r4, v1, t4);
	if (zend_is_true(r4)) {
		PHALCON_ALLOC_ZVAL(r5);
		//$value
		p2[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		//UnresolvedConstantParam=FILTER_SANITIZE_STRING
		PHALCON_ALLOC_ZVAL(t5);
		ZVAL_LONG(t5, 513);
		p2[1] = t5;
		phalcon_debug_param(t5 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r5, "filter_var", 2, p2);
		phalcon_debug_vdump("filter_var > ", r5 TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r5 TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_ZVAL(r5, 1, 0);
	}
	PHALCON_ALLOC_ZVAL(t6);
	ZVAL_STRING(t6, "float", 1);
	PHALCON_EQUAL_FUNCTION(r6, v1, t6);
	if (zend_is_true(r6)) {
		PHALCON_ALLOC_ZVAL(r7);
		//$value
		p3[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		//UnresolvedConstantParam=FILTER_SANITIZE_NUMBER_FLOAT
		PHALCON_ALLOC_ZVAL(t7);
		ZVAL_LONG(t7, 520);
		p3[1] = t7;
		phalcon_debug_param(t7 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL(t8);
		ZVAL_LONG(t8, 4096);
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
		add_assoc_zval(a0, "flags", t8);
		p3[2] = a0;
		phalcon_debug_param(a0 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r7, "filter_var", 3, p3);
		phalcon_debug_vdump("filter_var > ", r7 TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r7 TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_ZVAL(r7, 1, 0);
	}
	phalcon_step_over("Phalcon_Filter::_sanitize (Throw) File=Library/Phalcon/Filter.php Line=51");
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_exception_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Filter" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	//$filter
	PHALCON_ALLOC_ZVAL(r8);
	phalcon_concat_both(r8,  "Filter ", v1, " is not supported" TSRMLS_CC);
	Z_ADDREF_P(r8);
	p4[0] = r8;
	phalcon_debug_param(r8 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Filter" TSRMLS_CC);
	zend_throw_exception_object(i0 TSRMLS_CC);
	Z_ADDREF_P(i0);
	return;
	se53:
	php_printf("");
	phalcon_step_out_entry();
	RETURN_NULL();
}

