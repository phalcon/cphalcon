
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
 * Phalcon_Utils
 *
 * Implements functionality used widely by the framework
 */

/**
 * Converts strings to camelize style
 *
 * 
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Utils, camelize){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p3[] = { NULL }, *p2[] = { NULL, NULL, NULL }, *p1[] = { NULL }, *p0[] = { NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Utils", "camelize", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], " ", 1);
	PHALCON_ALLOC_ZVAL(p0[1]);
	ZVAL_STRING(p0[1], "", 1);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(r2);
	PHALCON_ALLOC_ZVAL(p2[0]);
	ZVAL_STRING(p2[0], "_", 1);
	PHALCON_ALLOC_ZVAL(p2[1]);
	ZVAL_STRING(p2[1], " ", 1);
	PHALCON_ALLOC_ZVAL(r3);
	p3[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r3, "strtolower", strlen("strtolower"), 1, p3);
	phalcon_debug_vdump("strtolower > ", r3 TSRMLS_CC);
	p2[2] = r3;
	phalcon_debug_param(r3 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r2, "str_replace", strlen("str_replace"), 3, p2);
	phalcon_debug_vdump("str_replace > ", r2 TSRMLS_CC);
	p1[0] = r2;
	phalcon_debug_param(r2 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r1, "ucwords", strlen("ucwords"), 1, p1);
	phalcon_debug_vdump("ucwords > ", r1 TSRMLS_CC);
	p0[2] = r1;
	phalcon_debug_param(r1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "str_replace", strlen("str_replace"), 3, p0);
	phalcon_debug_vdump("str_replace > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Utils::camelize (Method) File=/Utils Line=30");
}

/**
 * Uncamelize strings which are camelized
 *
 * 
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Utils, uncamelize){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p0[] = { NULL, NULL }, *p2[] = { NULL, NULL, NULL }, *p1[] = { NULL }, *p3[] = { NULL };
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
	phalcon_step_into_entry("Phalcon_Utils", "uncamelize", 0);
	phalcon_step_over("Phalcon_Utils::uncamelize (Assignment) File=/Utils Line=31");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_assoc_string(a0, "/(?<=(?:[A-Z]))([A-Z]+)([A-Z][A-z])/", "\\1_\\2", 1);
	add_assoc_string(a0, "/(?<=(?:[a-z]))([A-Z])/", "_\\1", 1);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a0);
	v1 = a0;
	phalcon_debug_assign("$patterns", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Utils::uncamelize (Foreach) File=/Utils Line=35");
	FOREACH_KV(v1, ac0, fes12, fee12, ah0, hp0, v3, v2)
		phalcon_step_over("Phalcon_Utils::uncamelize (Block) File=/Utils Line=35");
		phalcon_step_over("Phalcon_Utils::uncamelize (If) File=/Utils Line=36");
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
		Z_ADDREF_P(v3);
		p0[0] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		Z_ADDREF_P(v0);
		p0[1] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r0, "preg_match", strlen("preg_match"), 2, p0);
		phalcon_debug_vdump("preg_match > ", r0 TSRMLS_CC);
		if (zend_is_true(r0)) {
			phalcon_step_over("Phalcon_Utils::uncamelize (Block) File=/Utils Line=36");
			if (!r1) {
				PHALCON_ALLOC_ZVAL(r1);
			} else {
				if (Z_REFCOUNT_P(r1) > 1) {
					{
						zval *orig_ptr = r1;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r1);
							*r1 = *orig_ptr;
							zval_copy_ctor(r1);
							Z_SET_REFCOUNT_P(r1, 1);
							Z_UNSET_ISREF_P(r1);
						}
					}
				} else {
					FREE_ZVAL(r1);
					PHALCON_ALLOC_ZVAL(r1);
				}
			}
			if (!r2) {
				PHALCON_ALLOC_ZVAL(r2);
			} else {
				if (Z_REFCOUNT_P(r2) > 1) {
					{
						zval *orig_ptr = r2;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r2);
							*r2 = *orig_ptr;
							zval_copy_ctor(r2);
							Z_SET_REFCOUNT_P(r2, 1);
							Z_UNSET_ISREF_P(r2);
						}
					}
				} else {
					FREE_ZVAL(r2);
					PHALCON_ALLOC_ZVAL(r2);
				}
			}
			Z_ADDREF_P(v3);
			p2[0] = v3;
			phalcon_debug_param(v3 TSRMLS_CC);
			Z_ADDREF_P(v2);
			p2[1] = v2;
			phalcon_debug_param(v2 TSRMLS_CC);
			Z_ADDREF_P(v0);
			p2[2] = v0;
			phalcon_debug_param(v0 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r2, "preg_replace", strlen("preg_replace"), 3, p2);
			phalcon_debug_vdump("preg_replace > ", r2 TSRMLS_CC);
			p1[0] = r2;
			phalcon_debug_param(r2 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r1, "strtolower", strlen("strtolower"), 1, p1);
			phalcon_debug_vdump("strtolower > ", r1 TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r1 TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_ZVAL(r1, 1, 0);
		}
	END_FOREACH(ac0, fes12, fee12, ah0, hp0);
	PHALCON_ALLOC_ZVAL(r3);
	p3[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r3, "strtolower", strlen("strtolower"), 1, p3);
	phalcon_debug_vdump("strtolower > ", r3 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r3, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Utils::uncamelize (Method) File=/Utils Line=49");
}

/**
 * Gets public URL to phalcon instance
 *
 * @param string $params
 * @return string
 */
PHP_METHOD(Phalcon_Utils, getUrl){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Utils", "getUrl", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
	phalcon_debug_vdump("StaticReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Utils" TSRMLS_CC);
	phalcon_debug_method_call(r1, "getbaseuri" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, r1, "getbaseuri", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Utils" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r2);
	concat_function(r2, r0, v0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Utils::getUrl (Method) File=/Utils Line=59");
}

/**
 * Gets path to local file
 *
 * @param string $params
 * @return string
 */
PHP_METHOD(Phalcon_Utils, getLocalPath){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Utils", "getLocalPath", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
	phalcon_debug_vdump("StaticReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Utils" TSRMLS_CC);
	phalcon_debug_method_call(r1, "getbasepath" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, r1, "getbasepath", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Utils" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r2);
	concat_function(r2, r0, v0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
}

