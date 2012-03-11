
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
 * Phalcon_Tag
 *
 * Phalcon_Tag is designed to simplify building of HTML tags.
 * It provides a set of helpers to generate HTML in a dynamic way.
 * This component is an abstract class that you can extend to add more helpers.
 */

/**
 * Sets the request dispatcher. A valid dispatcher is required to generated absolute paths
 *
 * @param Phalcon_Dispatcher $dipatcher
 */
PHP_METHOD(Phalcon_Tag, setDispatcher){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Tag", "setDispatcher", 0);
	phalcon_step_over("Phalcon_Tag::setDispatcher (Assignment) File=/Tag Line=30");
	zend_update_static_property(phalcon_tag_class_entry, "_dispatcher", sizeof("_dispatcher")-1, v0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Tag::setDispatcher (Method) File=/Tag Line=38");
}

/**
 * Internally gets the request dispatcher
 *
 * @return Phalcon_Dispatcher
 */
PHP_METHOD(Phalcon_Tag, _getDispatcher){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	phalcon_step_into_entry("Phalcon_Tag", "_getDispatcher", 0);
	phalcon_step_over("Phalcon_Tag::_getDispatcher (If) File=/Tag Line=39");
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_dispatcher", sizeof("_dispatcher")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Tag::_getDispatcher (Block) File=/Tag Line=39");
		phalcon_step_over("Phalcon_Tag::_getDispatcher (Assignment) File=/Tag Line=40");
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
		phalcon_debug_vdump("StaticReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
		phalcon_debug_method_call(r1, "getdispatcher" TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, r1, "getdispatcher", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
		zend_update_static_property(phalcon_tag_class_entry, "_dispatcher", sizeof("_dispatcher")-1, r0 TSRMLS_CC);
	}
	t1 = zend_read_static_property(phalcon_tag_class_entry, "_dispatcher", sizeof("_dispatcher")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Tag::_getDispatcher (Method) File=/Tag Line=59");
}

/**
 * Assigns values to tags
 *
 * 
 *
 * @param string $id
 * @param string $value
 */
PHP_METHOD(Phalcon_Tag, displayTo){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Tag", "displayTo", 0);
	phalcon_step_over("Phalcon_Tag::displayTo (If) File=/Tag Line=60");
	PHALCON_ALLOC_ZVAL(r0);
	Z_ADDREF_P(v1);
	p0[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "is_scalar", 1, p0);
	phalcon_debug_vdump("is_scalar > ", r0 TSRMLS_CC);
	if (!zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Tag::displayTo (Block) File=/Tag Line=60");
		phalcon_step_over("Phalcon_Tag::displayTo (Throw) File=/Tag Line=61");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_tag_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], "Only scalar values can be assigned to UI components", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_over("Phalcon_Tag::displayTo (Assignment) File=/Tag Line=63");
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		convert_to_array(t0);
	}
	phalcon_array_update(t0, v0, v1 TSRMLS_CC);
	zend_update_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, t0 TSRMLS_CC);
	
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Tag::displayTo (Method) File=/Tag Line=73");
}

/**
 * Every helper call this function to check whether a component has a predefined
 * value using Phalcon_Tag::displayTo or value from $_POST
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_Tag, _getValueFromAction){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval **gv0;
	zval *p1[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Tag", "_getValueFromAction", 0);
	phalcon_step_over("Phalcon_Tag::_getValueFromAction (If) File=/Tag Line=74");
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t0, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
	if (zend_is_true(t1)) {
		phalcon_step_over("Phalcon_Tag::_getValueFromAction (Block) File=/Tag Line=74");
		t2 = zend_read_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_array_fetch(t3, t2, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", t3 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(t3);
	} else {
		phalcon_step_over("Phalcon_Tag::_getValueFromAction (Block) File=/Tag Line=76");
		phalcon_step_over("Phalcon_Tag::_getValueFromAction (If) File=/Tag Line=77");
		phalcon_init_global("_POST" TSRMLS_CC);
		if (&EG(symbol_table)) {
			if( zend_hash_find(&EG(symbol_table), "_POST", sizeof("_POST"), (void **) &gv0) == SUCCESS) {
				if(Z_TYPE_PP(gv0)==IS_ARRAY){
					a0 = *gv0;
				} else {
					PHALCON_ALLOC_ZVAL(a0);
					array_init(a0);
				}
			}
		}
		if (!a0) {
			PHALCON_ALLOC_ZVAL(a0);
			array_init(a0);
		}
		eval_int = phalcon_array_isset(a0, v0);
		if (eval_int) {
			phalcon_step_over("Phalcon_Tag::_getValueFromAction (Block) File=/Tag Line=77");
			phalcon_step_over("Phalcon_Tag::_getValueFromAction (If) File=/Tag Line=78");
			PHALCON_ALLOC_ZVAL(r0);
			PHALCON_CALL_FUNC(r0, "get_magic_quotes_gpc");
			phalcon_debug_vdump("get_magic_quotes_gpc > ", r0 TSRMLS_CC);
			if (!zend_is_true(r0)) {
				phalcon_step_over("Phalcon_Tag::_getValueFromAction (Block) File=/Tag Line=78");
				PHALCON_ALLOC_ZVAL(r1);
				phalcon_array_fetch(r1, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
				phalcon_debug_vdump("Returning > ", r1 TSRMLS_CC);
				phalcon_step_out_entry();
				PHALCON_RETURN_CTOR(r1);
			} else {
				phalcon_step_over("Phalcon_Tag::_getValueFromAction (Block) File=/Tag Line=80");
				PHALCON_ALLOC_ZVAL(r2);
				PHALCON_ALLOC_ZVAL(r3);
				phalcon_array_fetch(r3, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r3);
				p1[0] = r3;
				phalcon_debug_param(r3 TSRMLS_CC);
				PHALCON_CALL_FUNC_PARAMS(r2, "stripslashes", 1, p1);
				phalcon_debug_vdump("stripslashes > ", r2 TSRMLS_CC);
				phalcon_debug_vdump("Returning > ", r2 TSRMLS_CC);
				phalcon_step_out_entry();
				RETURN_ZVAL(r2, 1, 0);
			}
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Tag::_getValueFromAction (Method) File=/Tag Line=95");
}

/**
 * Builds a HTML A tag using framework conventions
 *
 * 
 *
 * @paramarray $params
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, linkTo){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL;
	zval *t0 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_NULL(v1);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Tag", "linkTo", 0);
	phalcon_step_over("Phalcon_Tag::linkTo (If) File=/Tag Line=96");
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		phalcon_step_over("Phalcon_Tag::linkTo (Block) File=/Tag Line=96");
		phalcon_step_over("Phalcon_Tag::linkTo (Assignment) File=/Tag Line=97");
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
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		PHALCON_CPY_WRT_PARAM(v0, a0);
		phalcon_debug_assign("$params", a0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::linkTo (Assignment) File=/Tag Line=99");
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_STRING(v2, "", 0);
	phalcon_step_over("Phalcon_Tag::linkTo (If) File=/Tag Line=100");
	eval_int = phalcon_array_isset_long(v0, 0);
	if (eval_int) {
		phalcon_step_over("Phalcon_Tag::linkTo (Block) File=/Tag Line=100");
		phalcon_step_over("Phalcon_Tag::linkTo (Assignment) File=/Tag Line=101");
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_long(r0, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r0);
		phalcon_debug_assign("$action", r0 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Tag::linkTo (Block) File=/Tag Line=102");
		phalcon_step_over("Phalcon_Tag::linkTo (If) File=/Tag Line=103");
		eval_int = phalcon_array_isset_string(v0, "action", strlen("action")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Tag::linkTo (Block) File=/Tag Line=103");
			phalcon_step_over("Phalcon_Tag::linkTo (Assignment) File=/Tag Line=104");
			PHALCON_ALLOC_ZVAL(r1);
			phalcon_array_fetch_string(r1, v0, "action", strlen("action"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r1);
			phalcon_debug_assign("$action", r1 TSRMLS_CC);
			phalcon_step_over("Phalcon_Tag::linkTo (Unset) File=/Tag Line=105");
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_unset_string(v0, "action", strlen("action")+1);
		}
	}
	phalcon_step_over("Phalcon_Tag::linkTo (Assignment) File=/Tag Line=108");
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "", 0);
	phalcon_step_over("Phalcon_Tag::linkTo (If) File=/Tag Line=109");
	eval_int = phalcon_array_isset_long(v0, 1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Tag::linkTo (Block) File=/Tag Line=109");
		phalcon_step_over("Phalcon_Tag::linkTo (Assignment) File=/Tag Line=110");
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_long(r2, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT_PARAM(v1, r2);
		phalcon_debug_assign("$text", r2 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Tag::linkTo (Block) File=/Tag Line=111");
		phalcon_step_over("Phalcon_Tag::linkTo (If) File=/Tag Line=112");
		eval_int = phalcon_array_isset_string(v0, "text", strlen("text")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Tag::linkTo (Block) File=/Tag Line=112");
			phalcon_step_over("Phalcon_Tag::linkTo (Assignment) File=/Tag Line=113");
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch_string(r3, v0, "text", strlen("text"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT_PARAM(v1, r3);
			phalcon_debug_assign("$text", r3 TSRMLS_CC);
			phalcon_step_over("Phalcon_Tag::linkTo (Unset) File=/Tag Line=114");
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_unset_string(v0, "text", strlen("text")+1);
		}
	}
	phalcon_step_over("Phalcon_Tag::linkTo (Assignment) File=/Tag Line=117");
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_STRING(v3, "", 0);
	phalcon_step_over("Phalcon_Tag::linkTo (If) File=/Tag Line=118");
	if (!PHALCON_COMPARE_STRING(v2, "")) {
		phalcon_step_over("Phalcon_Tag::linkTo (Block) File=/Tag Line=118");
		phalcon_step_over("Phalcon_Tag::linkTo (If) File=/Tag Line=119");
		eval_int = phalcon_array_isset_string(v0, "confirm", strlen("confirm")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Tag::linkTo (Block) File=/Tag Line=119");
			phalcon_step_over("Phalcon_Tag::linkTo (If) File=/Tag Line=120");
			eval_int = phalcon_array_isset_string(v0, "onclick", strlen("onclick")+1);
			if (!eval_int) {
				phalcon_step_over("Phalcon_Tag::linkTo (Block) File=/Tag Line=120");
				phalcon_step_over("Phalcon_Tag::linkTo (Assignment) File=/Tag Line=121");
				PHALCON_ALLOC_ZVAL(t0);
				ZVAL_STRING(t0, "", 1);
				PHALCON_SEPARATE_PARAM(v0);
				phalcon_array_update_string(v0, "onclick", strlen("onclick"), t0 TSRMLS_CC);
			}
			phalcon_step_over("Phalcon_Tag::linkTo (Assignment) File=/Tag Line=123");
			PHALCON_ALLOC_ZVAL(r5);
			phalcon_array_fetch_string(r5, v0, "confirm", strlen("confirm"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r6);
			PHALCON_CONCAT_LEFT(r6, "if(!confirm('", r5);
			PHALCON_ALLOC_ZVAL(r7);
			phalcon_array_fetch_string(r7, v0, "onclick", strlen("onclick"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r4);
			phalcon_concat_vboth(r4, r6, "')) { return false; }; ", r7 TSRMLS_CC);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update_string(v0, "onclick", strlen("onclick"), r4 TSRMLS_CC);
			phalcon_step_over("Phalcon_Tag::linkTo (Unset) File=/Tag Line=124");
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_unset_string(v0, "confirm", strlen("confirm")+1);
		}
		phalcon_step_over("Phalcon_Tag::linkTo (Assignment) File=/Tag Line=126");
		PHALCON_ALLOC_ZVAL(r8);
		Z_ADDREF_P(v2);
		p0[0] = v2;
		phalcon_debug_param(v2 TSRMLS_CC);
		PHALCON_CALL_STATIC_PARAMS(r8, "phalcon_utils", "geturl", 1, p0);
		phalcon_debug_vdump("StaticReturn > ", r8 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r9);
		phalcon_concat_both(r9,  "<a href=\"", r8, "\" " TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r9);
		phalcon_debug_assign("$code", r9 TSRMLS_CC);
		phalcon_step_over("Phalcon_Tag::linkTo (Foreach) File=/Tag Line=127");
		FOREACH_KV(v0, ac0, fes76, fee76, ah0, hp0, v5, v4)
			phalcon_step_over("Phalcon_Tag::linkTo (Block) File=/Tag Line=127");
			phalcon_step_over("Phalcon_Tag::linkTo (If) File=/Tag Line=128");
			if (Z_TYPE_P(v5) != IS_LONG) {
				phalcon_step_over("Phalcon_Tag::linkTo (Block) File=/Tag Line=128");
				phalcon_step_over("Phalcon_Tag::linkTo (AssignOp) File=/Tag Line=129");
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
				PHALCON_CONCAT_LEFT(r11, " ", v5);
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
				phalcon_concat_vboth(r10, r11, "=\"", v4 TSRMLS_CC);
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
				PHALCON_CONCAT_RIGHT(r12, r10, "\" ");
				if (!r13) {
					PHALCON_ALLOC_ZVAL(r13);
				} else {
					if (Z_REFCOUNT_P(r13) > 1) {
						PHALCON_SEPARATE(r13);
					} else {
						FREE_ZVAL(r13);
						PHALCON_ALLOC_ZVAL(r13);
					}
				}
				concat_function(r13, v3, r12 TSRMLS_CC);
				PHALCON_CPY_WRT(v3, r13);
				phalcon_debug_assign("$code", r13 TSRMLS_CC);
			}
		END_FOREACH(ac0, fes76, fee76, ah0, hp0);
		phalcon_step_over("Phalcon_Tag::linkTo (AssignOp) File=/Tag Line=132");
		PHALCON_ALLOC_ZVAL(r14);
		phalcon_concat_both(r14,  ">", v1, "</a>" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r15);
		concat_function(r15, v3, r14 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r15);
		phalcon_debug_assign("$code", r15 TSRMLS_CC);
	}
	phalcon_debug_vdump("Returning > ", v3 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v3);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Tag::linkTo (Method) File=/Tag Line=145");
}

/**
 * Builds a HTML input[type="text"] tag
 *
 * 
 *
 * @paramarray $params
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, textField){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL;
	zval *ac0 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Tag", "textField", 0);
	phalcon_step_over("Phalcon_Tag::textField (If) File=/Tag Line=146");
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		phalcon_step_over("Phalcon_Tag::textField (Block) File=/Tag Line=146");
		phalcon_step_over("Phalcon_Tag::textField (Assignment) File=/Tag Line=147");
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
		PHALCON_CPY_WRT_PARAM(v0, a0);
		phalcon_debug_assign("$params", a0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::textField (If) File=/Tag Line=149");
	eval_int = phalcon_array_isset_long(v0, 0);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Tag::textField (Block) File=/Tag Line=149");
		phalcon_step_over("Phalcon_Tag::textField (Assignment) File=/Tag Line=150");
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, v0, "id", strlen("id"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_update_long(v0, 0, r0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::textField (If) File=/Tag Line=152");
	eval_int = phalcon_array_isset_string(v0, "name", strlen("name")+1);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Tag::textField (Block) File=/Tag Line=152");
		phalcon_step_over("Phalcon_Tag::textField (Assignment) File=/Tag Line=153");
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_update_string(v0, "name", strlen("name"), r1 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Tag::textField (Block) File=/Tag Line=154");
		phalcon_step_over("Phalcon_Tag::textField (If) File=/Tag Line=155");
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_string(r2, v0, "name", strlen("name"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!zend_is_true(r2)) {
			phalcon_step_over("Phalcon_Tag::textField (Block) File=/Tag Line=155");
			phalcon_step_over("Phalcon_Tag::textField (Assignment) File=/Tag Line=156");
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch_long(r3, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update_string(v0, "name", strlen("name"), r3 TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Tag::textField (If) File=/Tag Line=159");
	eval_int = phalcon_array_isset_string(v0, "value", strlen("value")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Tag::textField (Block) File=/Tag Line=159");
		phalcon_step_over("Phalcon_Tag::textField (Assignment) File=/Tag Line=160");
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_array_fetch_string(r4, v0, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r4);
		phalcon_debug_assign("$value", r4 TSRMLS_CC);
		phalcon_step_over("Phalcon_Tag::textField (Unset) File=/Tag Line=161");
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "value", strlen("value")+1);
	} else {
		phalcon_step_over("Phalcon_Tag::textField (Block) File=/Tag Line=162");
		phalcon_step_over("Phalcon_Tag::textField (Assignment) File=/Tag Line=163");
		PHALCON_ALLOC_ZVAL(r5);
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_array_fetch_long(r6, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r6);
		p0[0] = r6;
		phalcon_debug_param(r6 TSRMLS_CC);
		PHALCON_CALL_SELF_PARAMS(r5, this_ptr, "_getvaluefromaction", 1, p0);
		phalcon_debug_vdump("SelfStaticReturn > ", r5 TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r5);
		phalcon_debug_assign("$value", r5 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::textField (Assignment) File=/Tag Line=165");
	PHALCON_ALLOC_ZVAL(r8);
	phalcon_array_fetch_long(r8, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r9);
	PHALCON_CONCAT_LEFT(r9, "<input type=\"text\" id=\"", r8);
	PHALCON_ALLOC_ZVAL(r7);
	phalcon_concat_vboth(r7, r9, "\" value=\"", v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r10);
	PHALCON_CONCAT_RIGHT(r10, r7, "\" ");
	PHALCON_CPY_WRT(v2, r10);
	phalcon_debug_assign("$code", r10 TSRMLS_CC);
	phalcon_step_over("Phalcon_Tag::textField (Foreach) File=/Tag Line=166");
	FOREACH_KV(v0, ac0, fes77, fee77, ah0, hp0, v3, v1)
		phalcon_step_over("Phalcon_Tag::textField (Block) File=/Tag Line=166");
		phalcon_step_over("Phalcon_Tag::textField (If) File=/Tag Line=167");
		if (Z_TYPE_P(v3) != IS_LONG) {
			phalcon_step_over("Phalcon_Tag::textField (Block) File=/Tag Line=167");
			phalcon_step_over("Phalcon_Tag::textField (AssignOp) File=/Tag Line=168");
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
			phalcon_concat_vboth(r11, v3, "=\"", v1 TSRMLS_CC);
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
			PHALCON_CONCAT_RIGHT(r12, r11, "\" ");
			if (!r13) {
				PHALCON_ALLOC_ZVAL(r13);
			} else {
				if (Z_REFCOUNT_P(r13) > 1) {
					PHALCON_SEPARATE(r13);
				} else {
					FREE_ZVAL(r13);
					PHALCON_ALLOC_ZVAL(r13);
				}
			}
			concat_function(r13, v2, r12 TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r13);
			phalcon_debug_assign("$code", r13 TSRMLS_CC);
		}
	END_FOREACH(ac0, fes77, fee77, ah0, hp0);
	phalcon_step_over("Phalcon_Tag::textField (AssignOp) File=/Tag Line=171");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, " />", 1);
	PHALCON_ALLOC_ZVAL(r14);
	concat_function(r14, v2, t0 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r14);
	phalcon_debug_assign("$code", r14 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Tag::textField (Method) File=/Tag Line=183");
}

/**
 * Builds a HTML input[type="submit"] tag
 *
 * 
 *
 * @paramarray $params
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, submitButton){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *ac0 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Tag", "submitButton", 0);
	phalcon_step_over("Phalcon_Tag::submitButton (If) File=/Tag Line=184");
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		phalcon_step_over("Phalcon_Tag::submitButton (Block) File=/Tag Line=184");
		phalcon_step_over("Phalcon_Tag::submitButton (Assignment) File=/Tag Line=185");
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
		PHALCON_CPY_WRT_PARAM(v0, a0);
		phalcon_debug_assign("$params", a0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::submitButton (If) File=/Tag Line=188");
	eval_int = phalcon_array_isset_string(v0, "value", strlen("value")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Tag::submitButton (Block) File=/Tag Line=188");
		phalcon_step_over("Phalcon_Tag::submitButton (Assignment) File=/Tag Line=189");
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, v0, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r0);
		phalcon_debug_assign("$value", r0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Tag::submitButton (Unset) File=/Tag Line=190");
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "value", strlen("value")+1);
	} else {
		phalcon_step_over("Phalcon_Tag::submitButton (Block) File=/Tag Line=191");
		phalcon_step_over("Phalcon_Tag::submitButton (If) File=/Tag Line=192");
		eval_int = phalcon_array_isset_long(v0, 0);
		if (eval_int) {
			phalcon_step_over("Phalcon_Tag::submitButton (Block) File=/Tag Line=192");
			phalcon_step_over("Phalcon_Tag::submitButton (Assignment) File=/Tag Line=193");
			PHALCON_ALLOC_ZVAL(r1);
			phalcon_array_fetch_long(r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v1, r1);
			phalcon_debug_assign("$value", r1 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Tag::submitButton (Block) File=/Tag Line=194");
			phalcon_step_over("Phalcon_Tag::submitButton (Assignment) File=/Tag Line=195");
			PHALCON_ALLOC_ZVAL(v1);
			ZVAL_STRING(v1, "", 0);
		}
	}
	phalcon_step_over("Phalcon_Tag::submitButton (Assignment) File=/Tag Line=198");
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_concat_both(r2,  "<input type=\"submit\" value=\"", v1, "\" " TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r2);
	phalcon_debug_assign("$code", r2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Tag::submitButton (Foreach) File=/Tag Line=199");
	FOREACH_KV(v0, ac0, fes78, fee78, ah0, hp0, v3, v1)
		phalcon_step_over("Phalcon_Tag::submitButton (Block) File=/Tag Line=199");
		phalcon_step_over("Phalcon_Tag::submitButton (If) File=/Tag Line=200");
		if (Z_TYPE_P(v3) != IS_LONG) {
			phalcon_step_over("Phalcon_Tag::submitButton (Block) File=/Tag Line=200");
			phalcon_step_over("Phalcon_Tag::submitButton (AssignOp) File=/Tag Line=201");
			if (!r3) {
				PHALCON_ALLOC_ZVAL(r3);
			} else {
				if (Z_REFCOUNT_P(r3) > 1) {
					PHALCON_SEPARATE(r3);
				} else {
					FREE_ZVAL(r3);
					PHALCON_ALLOC_ZVAL(r3);
				}
			}
			phalcon_concat_vboth(r3, v3, "=\"", v1 TSRMLS_CC);
			if (!r4) {
				PHALCON_ALLOC_ZVAL(r4);
			} else {
				if (Z_REFCOUNT_P(r4) > 1) {
					PHALCON_SEPARATE(r4);
				} else {
					FREE_ZVAL(r4);
					PHALCON_ALLOC_ZVAL(r4);
				}
			}
			PHALCON_CONCAT_RIGHT(r4, r3, "\" ");
			if (!r5) {
				PHALCON_ALLOC_ZVAL(r5);
			} else {
				if (Z_REFCOUNT_P(r5) > 1) {
					PHALCON_SEPARATE(r5);
				} else {
					FREE_ZVAL(r5);
					PHALCON_ALLOC_ZVAL(r5);
				}
			}
			concat_function(r5, v2, r4 TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r5);
			phalcon_debug_assign("$code", r5 TSRMLS_CC);
		}
	END_FOREACH(ac0, fes78, fee78, ah0, hp0);
	phalcon_step_over("Phalcon_Tag::submitButton (AssignOp) File=/Tag Line=204");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, " />", 1);
	PHALCON_ALLOC_ZVAL(r6);
	concat_function(r6, v2, t0 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r6);
	phalcon_debug_assign("$code", r6 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Tag::submitButton (Method) File=/Tag Line=216");
}

/**
 * Builds a HTML SELECT tag using an array for options
 *
 * 
 *
 * @paramarray $params
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, selectStatic){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Tag", "selectStatic", 0);
	phalcon_step_over("Phalcon_Tag::selectStatic (If) File=/Tag Line=218");
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		phalcon_step_over("Phalcon_Tag::selectStatic (Block) File=/Tag Line=218");
		phalcon_step_over("Phalcon_Tag::selectStatic (Assignment) File=/Tag Line=219");
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
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		PHALCON_CPY_WRT_PARAM(v0, a0);
		phalcon_debug_assign("$params", a0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::selectStatic (Assignment) File=/Tag Line=222");
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_STRING(v2, "", 0);
	phalcon_step_over("Phalcon_Tag::selectStatic (If) File=/Tag Line=223");
	eval_int = phalcon_array_isset_string(v0, "value", strlen("value")+1);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Tag::selectStatic (Block) File=/Tag Line=223");
		phalcon_step_over("Phalcon_Tag::selectStatic (Assignment) File=/Tag Line=224");
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r1);
		p0[0] = r1;
		phalcon_debug_param(r1 TSRMLS_CC);
		PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_getvaluefromaction", 1, p0);
		phalcon_debug_vdump("SelfStaticReturn > ", r0 TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r0);
		phalcon_debug_assign("$value", r0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Tag::selectStatic (Unset) File=/Tag Line=225");
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "value", strlen("value")+1);
	} else {
		phalcon_step_over("Phalcon_Tag::selectStatic (Block) File=/Tag Line=226");
		phalcon_step_over("Phalcon_Tag::selectStatic (Assignment) File=/Tag Line=227");
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_string(r2, v0, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r2);
		phalcon_debug_assign("$value", r2 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::selectStatic (Assignment) File=/Tag Line=230");
	PHALCON_ALLOC_ZVAL(r4);
	phalcon_array_fetch_long(r4, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r5);
	PHALCON_CONCAT_LEFT(r5, "<select id=\"", r4);
	PHALCON_ALLOC_ZVAL(r6);
	phalcon_array_fetch_long(r6, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r3);
	phalcon_concat_vboth(r3, r5, "\" name=\"", r6 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r7);
	PHALCON_CONCAT_RIGHT(r7, r3, "\" ");
	PHALCON_CPY_WRT(v3, r7);
	phalcon_debug_assign("$code", r7 TSRMLS_CC);
	phalcon_step_over("Phalcon_Tag::selectStatic (If) File=/Tag Line=231");
	eval_int = phalcon_array_isset_string(v0, "dummyValue", strlen("dummyValue")+1);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Tag::selectStatic (Block) File=/Tag Line=231");
		phalcon_step_over("Phalcon_Tag::selectStatic (Assignment) File=/Tag Line=232");
		PHALCON_ALLOC_ZVAL(v4);
		ZVAL_STRING(v4, "@", 0);
	} else {
		phalcon_step_over("Phalcon_Tag::selectStatic (Block) File=/Tag Line=233");
		phalcon_step_over("Phalcon_Tag::selectStatic (Assignment) File=/Tag Line=234");
		PHALCON_ALLOC_ZVAL(r8);
		phalcon_array_fetch_string(r8, v0, "dummyValue", strlen("dummyValue"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v4, r8);
		phalcon_debug_assign("$dummyValue", r8 TSRMLS_CC);
		phalcon_step_over("Phalcon_Tag::selectStatic (Unset) File=/Tag Line=235");
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "dummyValue", strlen("dummyValue")+1);
	}
	phalcon_step_over("Phalcon_Tag::selectStatic (If) File=/Tag Line=238");
	eval_int = phalcon_array_isset_string(v0, "dummyText", strlen("dummyText")+1);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Tag::selectStatic (Block) File=/Tag Line=238");
		phalcon_step_over("Phalcon_Tag::selectStatic (Assignment) File=/Tag Line=239");
		PHALCON_ALLOC_ZVAL(v5);
		ZVAL_STRING(v5, "Choose...", 0);
	} else {
		phalcon_step_over("Phalcon_Tag::selectStatic (Block) File=/Tag Line=240");
		phalcon_step_over("Phalcon_Tag::selectStatic (Assignment) File=/Tag Line=241");
		PHALCON_ALLOC_ZVAL(r9);
		phalcon_array_fetch_string(r9, v0, "dummyText", strlen("dummyText"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v5, r9);
		phalcon_debug_assign("$dummyText", r9 TSRMLS_CC);
		phalcon_step_over("Phalcon_Tag::selectStatic (Unset) File=/Tag Line=242");
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "dummyText", strlen("dummyText")+1);
	}
	phalcon_step_over("Phalcon_Tag::selectStatic (Foreach) File=/Tag Line=245");
	FOREACH_KV(v0, ac0, fes79, fee79, ah0, hp0, v7, v6)
		phalcon_step_over("Phalcon_Tag::selectStatic (Block) File=/Tag Line=245");
		phalcon_step_over("Phalcon_Tag::selectStatic (If) File=/Tag Line=246");
		if (Z_TYPE_P(v7) != IS_LONG) {
			phalcon_step_over("Phalcon_Tag::selectStatic (Block) File=/Tag Line=246");
			phalcon_step_over("Phalcon_Tag::selectStatic (If) File=/Tag Line=247");
			if (Z_TYPE_P(v6) != IS_ARRAY) { 
				phalcon_step_over("Phalcon_Tag::selectStatic (Block) File=/Tag Line=247");
				phalcon_step_over("Phalcon_Tag::selectStatic (AssignOp) File=/Tag Line=248");
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
				phalcon_concat_vboth(r10, v7, "=\"", v6 TSRMLS_CC);
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
				PHALCON_CONCAT_RIGHT(r11, r10, "\" ");
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
				concat_function(r12, v3, r11 TSRMLS_CC);
				PHALCON_CPY_WRT(v3, r12);
				phalcon_debug_assign("$code", r12 TSRMLS_CC);
			}
		}
	END_FOREACH(ac0, fes79, fee79, ah0, hp0);
	phalcon_step_over("Phalcon_Tag::selectStatic (AssignOp) File=/Tag Line=252");
	PHALCON_ALLOC_ZVAL(t0);
	zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r13);
	PHALCON_CONCAT_LEFT(r13, ">", t0);
	PHALCON_ALLOC_ZVAL(r14);
	concat_function(r14, v3, r13 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r14);
	phalcon_debug_assign("$code", r14 TSRMLS_CC);
	phalcon_step_over("Phalcon_Tag::selectStatic (If) File=/Tag Line=254");
	eval_int = phalcon_array_isset_string(v0, "useDummy", strlen("useDummy")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Tag::selectStatic (Block) File=/Tag Line=254");
		phalcon_step_over("Phalcon_Tag::selectStatic (AssignOp) File=/Tag Line=255");
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_STRING(t1, "\t", 1);
		PHALCON_ALLOC_ZVAL(r17);
		phalcon_concat_vboth(r17, t1, "<option value=\"", v4 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r16);
		phalcon_concat_vboth(r16, r17, "\">", v5 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t2);
		zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t2 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r15);
		phalcon_concat_vboth(r15, r16, "</option>", t2 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r18);
		concat_function(r18, v3, r15 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r18);
		phalcon_debug_assign("$code", r18 TSRMLS_CC);
		phalcon_step_over("Phalcon_Tag::selectStatic (Unset) File=/Tag Line=256");
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "useDummy", strlen("useDummy")+1);
	}
	phalcon_step_over("Phalcon_Tag::selectStatic (If) File=/Tag Line=259");
	eval_int = phalcon_array_isset_long(v0, 1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Tag::selectStatic (Block) File=/Tag Line=259");
		phalcon_step_over("Phalcon_Tag::selectStatic (If) File=/Tag Line=260");
		PHALCON_ALLOC_ZVAL(r19);
		phalcon_array_fetch_long(r19, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(r19) == IS_ARRAY) { 
			phalcon_step_over("Phalcon_Tag::selectStatic (Block) File=/Tag Line=260");
			phalcon_step_over("Phalcon_Tag::selectStatic (Foreach) File=/Tag Line=261");
			PHALCON_ALLOC_ZVAL(r20);
			phalcon_array_fetch_long(r20, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
			FOREACH_KV(r20, ac1, fes80, fee80, ah1, hp1, v9, v8)
				phalcon_step_over("Phalcon_Tag::selectStatic (Block) File=/Tag Line=261");
				phalcon_step_over("Phalcon_Tag::selectStatic (If) File=/Tag Line=262");
				if (!r21) {
					PHALCON_ALLOC_ZVAL(r21);
				} else {
					if (Z_REFCOUNT_P(r21) > 1){ 
						PHALCON_SEPARATE(r21);
					}
				}
				is_equal_function(r21, v9, v2 TSRMLS_CC);
				if (!t3) {
					PHALCON_ALLOC_ZVAL(t3);
				} else {
					if (Z_REFCOUNT_P(t3) > 1) {
						SEPARATE_ZVAL(&t3);
					} else {
						if (Z_TYPE_P(t3) != IS_STRING) {
							FREE_ZVAL(t3);
							PHALCON_ALLOC_ZVAL(t3);
						}
					}
				}
				ZVAL_STRING(t3, "", 1);
				if (!r22) {
					PHALCON_ALLOC_ZVAL(r22);
				} else {
					if (Z_REFCOUNT_P(r22) > 1) {
						SEPARATE_ZVAL(&r22);
					} else {
						if (Z_TYPE_P(r22) != IS_BOOL) {
							FREE_ZVAL(r22);
							PHALCON_ALLOC_ZVAL(r22);
						}
					}
				}
				is_not_identical_function(r22, t3, v2 TSRMLS_CC);
				if (!r23) {
					PHALCON_ALLOC_ZVAL(r23);
				} else {
					if (Z_REFCOUNT_P(r23) > 1) {
						SEPARATE_ZVAL(&r23);
					} else {
						if (Z_TYPE_P(r23) != IS_BOOL) {
							FREE_ZVAL(r23);
							PHALCON_ALLOC_ZVAL(r23);
						}
					}
				}
				phalcon_and_function(r23, r21, r22 TSRMLS_CC);
				if (zend_is_true(r23)) {
					phalcon_step_over("Phalcon_Tag::selectStatic (Block) File=/Tag Line=262");
					phalcon_step_over("Phalcon_Tag::selectStatic (AssignOp) File=/Tag Line=263");
					if (!t4) {
						PHALCON_ALLOC_ZVAL(t4);
					} else {
						if (Z_REFCOUNT_P(t4) > 1) {
							SEPARATE_ZVAL(&t4);
						} else {
							if (Z_TYPE_P(t4) != IS_STRING) {
								FREE_ZVAL(t4);
								PHALCON_ALLOC_ZVAL(t4);
							}
						}
					}
					ZVAL_STRING(t4, "\t", 1);
					if (!r26) {
						PHALCON_ALLOC_ZVAL(r26);
					} else {
						if (Z_REFCOUNT_P(r26) > 1) {
							PHALCON_SEPARATE(r26);
						} else {
							FREE_ZVAL(r26);
							PHALCON_ALLOC_ZVAL(r26);
						}
					}
					phalcon_concat_vboth(r26, t4, "<option value=\"", v9 TSRMLS_CC);
					if (!r25) {
						PHALCON_ALLOC_ZVAL(r25);
					} else {
						if (Z_REFCOUNT_P(r25) > 1) {
							PHALCON_SEPARATE(r25);
						} else {
							FREE_ZVAL(r25);
							PHALCON_ALLOC_ZVAL(r25);
						}
					}
					phalcon_concat_vboth(r25, r26, "\" selected=\"selected\">", v8 TSRMLS_CC);
					if (!t5) {
						PHALCON_ALLOC_ZVAL(t5);
					} else {
						if (Z_REFCOUNT_P(t5) > 1) {
							PHALCON_SEPARATE(t5);
						} else {
							FREE_ZVAL(t5);
							PHALCON_ALLOC_ZVAL(t5);
						}
					}
					zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t5 TSRMLS_CC);
					if (!r24) {
						PHALCON_ALLOC_ZVAL(r24);
					} else {
						if (Z_REFCOUNT_P(r24) > 1) {
							PHALCON_SEPARATE(r24);
						} else {
							FREE_ZVAL(r24);
							PHALCON_ALLOC_ZVAL(r24);
						}
					}
					phalcon_concat_vboth(r24, r25, "</option>", t5 TSRMLS_CC);
					if (!r27) {
						PHALCON_ALLOC_ZVAL(r27);
					} else {
						if (Z_REFCOUNT_P(r27) > 1) {
							PHALCON_SEPARATE(r27);
						} else {
							FREE_ZVAL(r27);
							PHALCON_ALLOC_ZVAL(r27);
						}
					}
					concat_function(r27, v3, r24 TSRMLS_CC);
					PHALCON_CPY_WRT(v3, r27);
					phalcon_debug_assign("$code", r27 TSRMLS_CC);
				} else {
					phalcon_step_over("Phalcon_Tag::selectStatic (Block) File=/Tag Line=264");
					phalcon_step_over("Phalcon_Tag::selectStatic (AssignOp) File=/Tag Line=265");
					if (!t6) {
						PHALCON_ALLOC_ZVAL(t6);
					} else {
						if (Z_REFCOUNT_P(t6) > 1) {
							SEPARATE_ZVAL(&t6);
						} else {
							if (Z_TYPE_P(t6) != IS_STRING) {
								FREE_ZVAL(t6);
								PHALCON_ALLOC_ZVAL(t6);
							}
						}
					}
					ZVAL_STRING(t6, "\t", 1);
					if (!r30) {
						PHALCON_ALLOC_ZVAL(r30);
					} else {
						if (Z_REFCOUNT_P(r30) > 1) {
							PHALCON_SEPARATE(r30);
						} else {
							FREE_ZVAL(r30);
							PHALCON_ALLOC_ZVAL(r30);
						}
					}
					phalcon_concat_vboth(r30, t6, "<option value=\"", v9 TSRMLS_CC);
					if (!r29) {
						PHALCON_ALLOC_ZVAL(r29);
					} else {
						if (Z_REFCOUNT_P(r29) > 1) {
							PHALCON_SEPARATE(r29);
						} else {
							FREE_ZVAL(r29);
							PHALCON_ALLOC_ZVAL(r29);
						}
					}
					phalcon_concat_vboth(r29, r30, "\">", v8 TSRMLS_CC);
					if (!t7) {
						PHALCON_ALLOC_ZVAL(t7);
					} else {
						if (Z_REFCOUNT_P(t7) > 1) {
							PHALCON_SEPARATE(t7);
						} else {
							FREE_ZVAL(t7);
							PHALCON_ALLOC_ZVAL(t7);
						}
					}
					zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t7 TSRMLS_CC);
					if (!r28) {
						PHALCON_ALLOC_ZVAL(r28);
					} else {
						if (Z_REFCOUNT_P(r28) > 1) {
							PHALCON_SEPARATE(r28);
						} else {
							FREE_ZVAL(r28);
							PHALCON_ALLOC_ZVAL(r28);
						}
					}
					phalcon_concat_vboth(r28, r29, "</option>", t7 TSRMLS_CC);
					if (!r31) {
						PHALCON_ALLOC_ZVAL(r31);
					} else {
						if (Z_REFCOUNT_P(r31) > 1) {
							PHALCON_SEPARATE(r31);
						} else {
							FREE_ZVAL(r31);
							PHALCON_ALLOC_ZVAL(r31);
						}
					}
					concat_function(r31, v3, r28 TSRMLS_CC);
					PHALCON_CPY_WRT(v3, r31);
					phalcon_debug_assign("$code", r31 TSRMLS_CC);
				}
			END_FOREACH(ac1, fes80, fee80, ah1, hp1);
		} else {
			phalcon_step_over("Phalcon_Tag::selectStatic (Block) File=/Tag Line=268");
			phalcon_step_over("Phalcon_Tag::selectStatic (Throw) File=/Tag Line=269");
			PHALCON_ALLOC_ZVAL(i0);
			object_init_ex(i0, phalcon_tag_exception_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
			phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p1[0]);
			ZVAL_STRING(p1[0], "Data supplied for Phalcon_Tag::selectStatic is not valid", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			return;
		}
	}
	phalcon_step_over("Phalcon_Tag::selectStatic (AssignOp) File=/Tag Line=272");
	PHALCON_ALLOC_ZVAL(t8);
	ZVAL_STRING(t8, "</select>", 1);
	PHALCON_ALLOC_ZVAL(r32);
	concat_function(r32, v3, t8 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r32);
	phalcon_debug_assign("$code", r32 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", v3 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v3);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Tag::selectStatic (Method) File=/Tag Line=289");
}

/**
 * Builds a HTML SELECT tag using a resultset as options
 *
 * 
 *
 * @paramarray $params
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, select){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL, *r41 = NULL;
	zval *r42 = NULL, *r43 = NULL, *r44 = NULL, *r45 = NULL, *r46 = NULL, *r47 = NULL, *r48 = NULL;
	zval *r49 = NULL, *r50 = NULL, *r51 = NULL, *r52 = NULL, *r53 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p6[] = { NULL }, *p7[] = { NULL }, *p8[] = { NULL }, *p9[] = { NULL }, *p10[] = { NULL }, *p12[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Tag", "select", 0);
	phalcon_step_over("Phalcon_Tag::select (If) File=/Tag Line=291");
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=291");
		phalcon_step_over("Phalcon_Tag::select (Assignment) File=/Tag Line=292");
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
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		PHALCON_CPY_WRT_PARAM(v0, a0);
		phalcon_debug_assign("$params", a0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::select (If) File=/Tag Line=295");
	eval_int = phalcon_array_isset_string(v0, "value", strlen("value")+1);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=295");
		phalcon_step_over("Phalcon_Tag::select (Assignment) File=/Tag Line=296");
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r1);
		p0[0] = r1;
		phalcon_debug_param(r1 TSRMLS_CC);
		PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_getvaluefromaction", 1, p0);
		phalcon_debug_vdump("SelfStaticReturn > ", r0 TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r0);
		phalcon_debug_assign("$value", r0 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=297");
		phalcon_step_over("Phalcon_Tag::select (Assignment) File=/Tag Line=298");
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_string(r2, v0, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r2);
		phalcon_debug_assign("$value", r2 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::select (Assignment) File=/Tag Line=301");
	PHALCON_ALLOC_ZVAL(r4);
	phalcon_array_fetch_long(r4, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r5);
	PHALCON_CONCAT_LEFT(r5, "<select id='", r4);
	PHALCON_ALLOC_ZVAL(r6);
	phalcon_array_fetch_long(r6, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r3);
	phalcon_concat_vboth(r3, r5, "' name='", r6 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r7);
	PHALCON_CONCAT_RIGHT(r7, r3, "' ");
	PHALCON_CPY_WRT(v3, r7);
	phalcon_debug_assign("$code", r7 TSRMLS_CC);
	phalcon_step_over("Phalcon_Tag::select (If) File=/Tag Line=302");
	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=302");
		phalcon_step_over("Phalcon_Tag::select (Foreach) File=/Tag Line=303");
		FOREACH_KV(v0, ac0, fes81, fee81, ah0, hp0, v4, v2)
			phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=303");
			phalcon_step_over("Phalcon_Tag::select (If) File=/Tag Line=304");
			if (Z_TYPE_P(v4) != IS_LONG) {
				phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=304");
				phalcon_step_over("Phalcon_Tag::select (If) File=/Tag Line=305");
				if (Z_TYPE_P(v2) != IS_ARRAY) { 
					phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=305");
					phalcon_step_over("Phalcon_Tag::select (AssignOp) File=/Tag Line=306");
					if (!r8) {
						PHALCON_ALLOC_ZVAL(r8);
					} else {
						if (Z_REFCOUNT_P(r8) > 1) {
							PHALCON_SEPARATE(r8);
						} else {
							FREE_ZVAL(r8);
							PHALCON_ALLOC_ZVAL(r8);
						}
					}
					phalcon_concat_vboth(r8, v4, "='", v2 TSRMLS_CC);
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
					PHALCON_CONCAT_RIGHT(r9, r8, "' ");
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
					concat_function(r10, v3, r9 TSRMLS_CC);
					PHALCON_CPY_WRT(v3, r10);
					phalcon_debug_assign("$code", r10 TSRMLS_CC);
				}
			}
		END_FOREACH(ac0, fes81, fee81, ah0, hp0);
	}
	phalcon_step_over("Phalcon_Tag::select (AssignOp) File=/Tag Line=311");
	PHALCON_ALLOC_ZVAL(t0);
	zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r11);
	PHALCON_CONCAT_LEFT(r11, ">", t0);
	PHALCON_ALLOC_ZVAL(r12);
	concat_function(r12, v3, r11 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r12);
	phalcon_debug_assign("$code", r12 TSRMLS_CC);
	phalcon_step_over("Phalcon_Tag::select (If) File=/Tag Line=313");
	eval_int = phalcon_array_isset_string(v0, "dummyValue", strlen("dummyValue")+1);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=313");
		phalcon_step_over("Phalcon_Tag::select (Assignment) File=/Tag Line=314");
		PHALCON_ALLOC_ZVAL(v5);
		ZVAL_STRING(v5, "", 0);
	} else {
		phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=315");
		phalcon_step_over("Phalcon_Tag::select (Assignment) File=/Tag Line=316");
		PHALCON_ALLOC_ZVAL(r13);
		phalcon_array_fetch_string(r13, v0, "dummyValue", strlen("dummyValue"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v5, r13);
		phalcon_debug_assign("$dummyValue", r13 TSRMLS_CC);
		phalcon_step_over("Phalcon_Tag::select (Unset) File=/Tag Line=317");
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "dummyValue", strlen("dummyValue")+1);
	}
	phalcon_step_over("Phalcon_Tag::select (If) File=/Tag Line=319");
	eval_int = phalcon_array_isset_string(v0, "dummyText", strlen("dummyText")+1);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=319");
		phalcon_step_over("Phalcon_Tag::select (Assignment) File=/Tag Line=320");
		PHALCON_ALLOC_ZVAL(v6);
		ZVAL_STRING(v6, "Choose...", 0);
	} else {
		phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=321");
		phalcon_step_over("Phalcon_Tag::select (Assignment) File=/Tag Line=322");
		PHALCON_ALLOC_ZVAL(r14);
		phalcon_array_fetch_string(r14, v0, "dummyText", strlen("dummyText"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v6, r14);
		phalcon_debug_assign("$dummyText", r14 TSRMLS_CC);
		phalcon_step_over("Phalcon_Tag::select (Unset) File=/Tag Line=323");
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "dummyText", strlen("dummyText")+1);
	}
	phalcon_step_over("Phalcon_Tag::select (If) File=/Tag Line=326");
	eval_int = phalcon_array_isset_string(v0, "useDummy", strlen("useDummy")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=326");
		phalcon_step_over("Phalcon_Tag::select (AssignOp) File=/Tag Line=327");
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_STRING(t1, "\t", 1);
		PHALCON_ALLOC_ZVAL(r17);
		phalcon_concat_vboth(r17, t1, "<option value=\"", v5 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r16);
		phalcon_concat_vboth(r16, r17, "\">", v6 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t2);
		zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t2 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r15);
		phalcon_concat_vboth(r15, r16, "</option>", t2 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r18);
		concat_function(r18, v3, r15 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r18);
		phalcon_debug_assign("$code", r18 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::select (If) File=/Tag Line=330");
	eval_int = phalcon_array_isset_long(v0, 1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=330");
		phalcon_step_over("Phalcon_Tag::select (If) File=/Tag Line=331");
		PHALCON_ALLOC_ZVAL(r19);
		phalcon_array_fetch_long(r19, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r19)) {
			phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=331");
			phalcon_step_over("Phalcon_Tag::select (If) File=/Tag Line=332");
			PHALCON_ALLOC_ZVAL(r20);
			phalcon_array_fetch_long(r20, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (Z_TYPE_P(r20) == IS_OBJECT) {
				phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=332");
				phalcon_step_over("Phalcon_Tag::select (If) File=/Tag Line=333");
				eval_int = phalcon_array_isset_string(v0, "using", strlen("using")+1);
				if (!eval_int) {
					phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=333");
					phalcon_step_over("Phalcon_Tag::select (Throw) File=/Tag Line=334");
					PHALCON_ALLOC_ZVAL(i0);
					object_init_ex(i0, phalcon_tag_exception_class_entry);
					phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
					phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
					PHALCON_ALLOC_ZVAL(p1[0]);
					ZVAL_STRING(p1[0], "The 'using' parameter is required", 1);
					PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
					phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
					zend_throw_exception_object(i0 TSRMLS_CC);
					Z_ADDREF_P(i0);
					return;
				} else {
					phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=335");
					phalcon_step_over("Phalcon_Tag::select (If) File=/Tag Line=336");
					PHALCON_ALLOC_ZVAL(r21);
					phalcon_array_fetch_string(r21, v0, "using", strlen("using"), PHALCON_NOISY_FETCH TSRMLS_CC);
					if (Z_TYPE_P(r21) != IS_ARRAY) { 
						phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=336");
						phalcon_step_over("Phalcon_Tag::select (Throw) File=/Tag Line=337");
						PHALCON_ALLOC_ZVAL(i1);
						object_init_ex(i1, phalcon_tag_exception_class_entry);
						phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
						phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
						PHALCON_ALLOC_ZVAL(p2[0]);
						ZVAL_STRING(p2[0], "The 'using' parameter should be an Array", 1);
						PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
						phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
						zend_throw_exception_object(i1 TSRMLS_CC);
						Z_ADDREF_P(i1);
						return;
					}
				}
				phalcon_step_over("Phalcon_Tag::select (Assignment) File=/Tag Line=340");
				PHALCON_ALLOC_ZVAL(r22);
				phalcon_array_fetch_string(r22, v0, "using", strlen("using"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v7, r22);
				phalcon_debug_assign("$using", r22 TSRMLS_CC);
				phalcon_step_over("Phalcon_Tag::select (Assignment) File=/Tag Line=341");
				PHALCON_ALLOC_ZVAL(r23);
				phalcon_array_fetch_long(r23, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v8, r23);
				phalcon_debug_assign("$resultset", r23 TSRMLS_CC);
				phalcon_step_over("Phalcon_Tag::select (MethodCall) File=/Tag Line=342");
				phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
				phalcon_debug_method_call(v8, "rewind" TSRMLS_CC);
				PHALCON_CALL_METHOD_NORETURN(v8, "rewind", PHALCON_CALL_DEFAULT);
				phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
				phalcon_step_over("Phalcon_Tag::select (While) File=/Tag Line=343");
				ws82:
				PHALCON_ALLOC_ZVAL(r24);
				phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
				phalcon_debug_method_call(v8, "valid" TSRMLS_CC);
				PHALCON_CALL_METHOD(r24, v8, "valid", PHALCON_CALL_DEFAULT);
				phalcon_debug_vdump("MethodReturn > ", r24 TSRMLS_CC);
				phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
				if (!zend_is_true(r24)) {
					goto we82;
				}
				phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=343");
				phalcon_step_over("Phalcon_Tag::select (Assignment) File=/Tag Line=344");
				if (!r25) {
					PHALCON_ALLOC_ZVAL(r25);
				} else {
					if (Z_REFCOUNT_P(r25) > 1) {
						PHALCON_SEPARATE(r25);
					} else {
						FREE_ZVAL(r25);
						PHALCON_ALLOC_ZVAL(r25);
					}
				}
				phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
				phalcon_debug_method_call(v8, "current" TSRMLS_CC);
				PHALCON_CALL_METHOD(r25, v8, "current", PHALCON_CALL_DEFAULT);
				phalcon_debug_vdump("MethodReturn > ", r25 TSRMLS_CC);
				phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
				PHALCON_CPY_WRT(v9, r25);
				phalcon_debug_assign("$option", r25 TSRMLS_CC);
				phalcon_step_over("Phalcon_Tag::select (If) File=/Tag Line=345");
				if (!r26) {
					PHALCON_ALLOC_ZVAL(r26);
				} else {
					if (Z_REFCOUNT_P(r26) > 1) {
						PHALCON_SEPARATE(r26);
					} else {
						FREE_ZVAL(r26);
						PHALCON_ALLOC_ZVAL(r26);
					}
				}
				phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
				phalcon_debug_method_call(v9, "readattribute" TSRMLS_CC);
				if (!r27) {
					PHALCON_ALLOC_ZVAL(r27);
				} else {
					if (Z_REFCOUNT_P(r27) > 1) {
						PHALCON_SEPARATE(r27);
					} else {
						FREE_ZVAL(r27);
						PHALCON_ALLOC_ZVAL(r27);
					}
				}
				phalcon_array_fetch_long(r27, v7, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r27);
				p6[0] = r27;
				phalcon_debug_param(r27 TSRMLS_CC);
				PHALCON_CALL_METHOD_PARAMS(r26, v9, "readattribute", 1, p6, PHALCON_CALL_DEFAULT);
				phalcon_debug_vdump("MethodReturn > ", r26 TSRMLS_CC);
				phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
				if (!r28) {
					PHALCON_ALLOC_ZVAL(r28);
				} else {
					if (Z_REFCOUNT_P(r28) > 1){ 
						PHALCON_SEPARATE(r28);
					}
				}
				is_equal_function(r28, v2, r26 TSRMLS_CC);
				if (zend_is_true(r28)) {
					phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=345");
					phalcon_step_over("Phalcon_Tag::select (AssignOp) File=/Tag Line=346");
					if (!t3) {
						PHALCON_ALLOC_ZVAL(t3);
					} else {
						if (Z_REFCOUNT_P(t3) > 1) {
							SEPARATE_ZVAL(&t3);
						} else {
							if (Z_TYPE_P(t3) != IS_STRING) {
								FREE_ZVAL(t3);
								PHALCON_ALLOC_ZVAL(t3);
							}
						}
					}
					ZVAL_STRING(t3, "\t", 1);
					if (!r32) {
						PHALCON_ALLOC_ZVAL(r32);
					} else {
						if (Z_REFCOUNT_P(r32) > 1) {
							PHALCON_SEPARATE(r32);
						} else {
							FREE_ZVAL(r32);
							PHALCON_ALLOC_ZVAL(r32);
						}
					}
					phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
					phalcon_debug_method_call(v9, "readattribute" TSRMLS_CC);
					if (!r33) {
						PHALCON_ALLOC_ZVAL(r33);
					} else {
						if (Z_REFCOUNT_P(r33) > 1) {
							PHALCON_SEPARATE(r33);
						} else {
							FREE_ZVAL(r33);
							PHALCON_ALLOC_ZVAL(r33);
						}
					}
					phalcon_array_fetch_long(r33, v7, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r33);
					p7[0] = r33;
					phalcon_debug_param(r33 TSRMLS_CC);
					PHALCON_CALL_METHOD_PARAMS(r32, v9, "readattribute", 1, p7, PHALCON_CALL_DEFAULT);
					phalcon_debug_vdump("MethodReturn > ", r32 TSRMLS_CC);
					phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
					if (!r31) {
						PHALCON_ALLOC_ZVAL(r31);
					} else {
						if (Z_REFCOUNT_P(r31) > 1) {
							PHALCON_SEPARATE(r31);
						} else {
							FREE_ZVAL(r31);
							PHALCON_ALLOC_ZVAL(r31);
						}
					}
					phalcon_concat_vboth(r31, t3, "<option selected=\"selected\" value=\"", r32 TSRMLS_CC);
					if (!r34) {
						PHALCON_ALLOC_ZVAL(r34);
					} else {
						if (Z_REFCOUNT_P(r34) > 1) {
							PHALCON_SEPARATE(r34);
						} else {
							FREE_ZVAL(r34);
							PHALCON_ALLOC_ZVAL(r34);
						}
					}
					phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
					phalcon_debug_method_call(v9, "readattribute" TSRMLS_CC);
					if (!r35) {
						PHALCON_ALLOC_ZVAL(r35);
					} else {
						if (Z_REFCOUNT_P(r35) > 1) {
							PHALCON_SEPARATE(r35);
						} else {
							FREE_ZVAL(r35);
							PHALCON_ALLOC_ZVAL(r35);
						}
					}
					phalcon_array_fetch_long(r35, v7, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r35);
					p8[0] = r35;
					phalcon_debug_param(r35 TSRMLS_CC);
					PHALCON_CALL_METHOD_PARAMS(r34, v9, "readattribute", 1, p8, PHALCON_CALL_DEFAULT);
					phalcon_debug_vdump("MethodReturn > ", r34 TSRMLS_CC);
					phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
					if (!r30) {
						PHALCON_ALLOC_ZVAL(r30);
					} else {
						if (Z_REFCOUNT_P(r30) > 1) {
							PHALCON_SEPARATE(r30);
						} else {
							FREE_ZVAL(r30);
							PHALCON_ALLOC_ZVAL(r30);
						}
					}
					phalcon_concat_vboth(r30, r31, "'>", r34 TSRMLS_CC);
					if (!t4) {
						PHALCON_ALLOC_ZVAL(t4);
					} else {
						if (Z_REFCOUNT_P(t4) > 1) {
							PHALCON_SEPARATE(t4);
						} else {
							FREE_ZVAL(t4);
							PHALCON_ALLOC_ZVAL(t4);
						}
					}
					zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t4 TSRMLS_CC);
					if (!r29) {
						PHALCON_ALLOC_ZVAL(r29);
					} else {
						if (Z_REFCOUNT_P(r29) > 1) {
							PHALCON_SEPARATE(r29);
						} else {
							FREE_ZVAL(r29);
							PHALCON_ALLOC_ZVAL(r29);
						}
					}
					phalcon_concat_vboth(r29, r30, "</option>", t4 TSRMLS_CC);
					if (!r36) {
						PHALCON_ALLOC_ZVAL(r36);
					} else {
						if (Z_REFCOUNT_P(r36) > 1) {
							PHALCON_SEPARATE(r36);
						} else {
							FREE_ZVAL(r36);
							PHALCON_ALLOC_ZVAL(r36);
						}
					}
					concat_function(r36, v3, r29 TSRMLS_CC);
					PHALCON_CPY_WRT(v3, r36);
					phalcon_debug_assign("$code", r36 TSRMLS_CC);
				} else {
					phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=347");
					phalcon_step_over("Phalcon_Tag::select (AssignOp) File=/Tag Line=348");
					if (!t5) {
						PHALCON_ALLOC_ZVAL(t5);
					} else {
						if (Z_REFCOUNT_P(t5) > 1) {
							SEPARATE_ZVAL(&t5);
						} else {
							if (Z_TYPE_P(t5) != IS_STRING) {
								FREE_ZVAL(t5);
								PHALCON_ALLOC_ZVAL(t5);
							}
						}
					}
					ZVAL_STRING(t5, "\t", 1);
					if (!r40) {
						PHALCON_ALLOC_ZVAL(r40);
					} else {
						if (Z_REFCOUNT_P(r40) > 1) {
							PHALCON_SEPARATE(r40);
						} else {
							FREE_ZVAL(r40);
							PHALCON_ALLOC_ZVAL(r40);
						}
					}
					phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
					phalcon_debug_method_call(v9, "readattribute" TSRMLS_CC);
					if (!r41) {
						PHALCON_ALLOC_ZVAL(r41);
					} else {
						if (Z_REFCOUNT_P(r41) > 1) {
							PHALCON_SEPARATE(r41);
						} else {
							FREE_ZVAL(r41);
							PHALCON_ALLOC_ZVAL(r41);
						}
					}
					phalcon_array_fetch_long(r41, v7, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r41);
					p9[0] = r41;
					phalcon_debug_param(r41 TSRMLS_CC);
					PHALCON_CALL_METHOD_PARAMS(r40, v9, "readattribute", 1, p9, PHALCON_CALL_DEFAULT);
					phalcon_debug_vdump("MethodReturn > ", r40 TSRMLS_CC);
					phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
					if (!r39) {
						PHALCON_ALLOC_ZVAL(r39);
					} else {
						if (Z_REFCOUNT_P(r39) > 1) {
							PHALCON_SEPARATE(r39);
						} else {
							FREE_ZVAL(r39);
							PHALCON_ALLOC_ZVAL(r39);
						}
					}
					phalcon_concat_vboth(r39, t5, "<option value=\"", r40 TSRMLS_CC);
					if (!r42) {
						PHALCON_ALLOC_ZVAL(r42);
					} else {
						if (Z_REFCOUNT_P(r42) > 1) {
							PHALCON_SEPARATE(r42);
						} else {
							FREE_ZVAL(r42);
							PHALCON_ALLOC_ZVAL(r42);
						}
					}
					phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
					phalcon_debug_method_call(v9, "readattribute" TSRMLS_CC);
					if (!r43) {
						PHALCON_ALLOC_ZVAL(r43);
					} else {
						if (Z_REFCOUNT_P(r43) > 1) {
							PHALCON_SEPARATE(r43);
						} else {
							FREE_ZVAL(r43);
							PHALCON_ALLOC_ZVAL(r43);
						}
					}
					phalcon_array_fetch_long(r43, v7, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r43);
					p10[0] = r43;
					phalcon_debug_param(r43 TSRMLS_CC);
					PHALCON_CALL_METHOD_PARAMS(r42, v9, "readattribute", 1, p10, PHALCON_CALL_DEFAULT);
					phalcon_debug_vdump("MethodReturn > ", r42 TSRMLS_CC);
					phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
					if (!r38) {
						PHALCON_ALLOC_ZVAL(r38);
					} else {
						if (Z_REFCOUNT_P(r38) > 1) {
							PHALCON_SEPARATE(r38);
						} else {
							FREE_ZVAL(r38);
							PHALCON_ALLOC_ZVAL(r38);
						}
					}
					phalcon_concat_vboth(r38, r39, "\">", r42 TSRMLS_CC);
					if (!t6) {
						PHALCON_ALLOC_ZVAL(t6);
					} else {
						if (Z_REFCOUNT_P(t6) > 1) {
							PHALCON_SEPARATE(t6);
						} else {
							FREE_ZVAL(t6);
							PHALCON_ALLOC_ZVAL(t6);
						}
					}
					zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t6 TSRMLS_CC);
					if (!r37) {
						PHALCON_ALLOC_ZVAL(r37);
					} else {
						if (Z_REFCOUNT_P(r37) > 1) {
							PHALCON_SEPARATE(r37);
						} else {
							FREE_ZVAL(r37);
							PHALCON_ALLOC_ZVAL(r37);
						}
					}
					phalcon_concat_vboth(r37, r38, "</option>", t6 TSRMLS_CC);
					if (!r44) {
						PHALCON_ALLOC_ZVAL(r44);
					} else {
						if (Z_REFCOUNT_P(r44) > 1) {
							PHALCON_SEPARATE(r44);
						} else {
							FREE_ZVAL(r44);
							PHALCON_ALLOC_ZVAL(r44);
						}
					}
					concat_function(r44, v3, r37 TSRMLS_CC);
					PHALCON_CPY_WRT(v3, r44);
					phalcon_debug_assign("$code", r44 TSRMLS_CC);
				}
				phalcon_step_over("Phalcon_Tag::select (MethodCall) File=/Tag Line=350");
				phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
				phalcon_debug_method_call(v8, "next" TSRMLS_CC);
				PHALCON_CALL_METHOD_NORETURN(v8, "next", PHALCON_CALL_DEFAULT);
				phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
				goto ws82;
				we82:
				r24 = NULL;
			} else {
				phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=352");
				phalcon_step_over("Phalcon_Tag::select (If) File=/Tag Line=353");
				PHALCON_ALLOC_ZVAL(r45);
				phalcon_array_fetch_long(r45, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
				if (Z_TYPE_P(r45) == IS_ARRAY) { 
					phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=353");
					phalcon_step_over("Phalcon_Tag::select (Foreach) File=/Tag Line=354");
					PHALCON_ALLOC_ZVAL(r46);
					phalcon_array_fetch_long(r46, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
					FOREACH_V(r46, ac1, fes83, fee83, ah1, hp1, v9)
						phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=354");
						phalcon_step_over("Phalcon_Tag::select (AssignOp) File=/Tag Line=355");
						if (!t7) {
							PHALCON_ALLOC_ZVAL(t7);
						} else {
							if (Z_REFCOUNT_P(t7) > 1) {
								SEPARATE_ZVAL(&t7);
							} else {
								if (Z_TYPE_P(t7) != IS_STRING) {
									FREE_ZVAL(t7);
									PHALCON_ALLOC_ZVAL(t7);
								}
							}
						}
						ZVAL_STRING(t7, "\t", 1);
						if (!r50) {
							PHALCON_ALLOC_ZVAL(r50);
						} else {
							if (Z_REFCOUNT_P(r50) > 1) {
								PHALCON_SEPARATE(r50);
							} else {
								FREE_ZVAL(r50);
								PHALCON_ALLOC_ZVAL(r50);
							}
						}
						phalcon_array_fetch_long(r50, v9, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
						if (!r49) {
							PHALCON_ALLOC_ZVAL(r49);
						} else {
							if (Z_REFCOUNT_P(r49) > 1) {
								PHALCON_SEPARATE(r49);
							} else {
								FREE_ZVAL(r49);
								PHALCON_ALLOC_ZVAL(r49);
							}
						}
						phalcon_concat_vboth(r49, t7, "<option value=\"", r50 TSRMLS_CC);
						if (!r51) {
							PHALCON_ALLOC_ZVAL(r51);
						} else {
							if (Z_REFCOUNT_P(r51) > 1) {
								PHALCON_SEPARATE(r51);
							} else {
								FREE_ZVAL(r51);
								PHALCON_ALLOC_ZVAL(r51);
							}
						}
						phalcon_array_fetch_long(r51, v9, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
						if (!r48) {
							PHALCON_ALLOC_ZVAL(r48);
						} else {
							if (Z_REFCOUNT_P(r48) > 1) {
								PHALCON_SEPARATE(r48);
							} else {
								FREE_ZVAL(r48);
								PHALCON_ALLOC_ZVAL(r48);
							}
						}
						phalcon_concat_vboth(r48, r49, "\">", r51 TSRMLS_CC);
						if (!t8) {
							PHALCON_ALLOC_ZVAL(t8);
						} else {
							if (Z_REFCOUNT_P(t8) > 1) {
								PHALCON_SEPARATE(t8);
							} else {
								FREE_ZVAL(t8);
								PHALCON_ALLOC_ZVAL(t8);
							}
						}
						zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t8 TSRMLS_CC);
						if (!r47) {
							PHALCON_ALLOC_ZVAL(r47);
						} else {
							if (Z_REFCOUNT_P(r47) > 1) {
								PHALCON_SEPARATE(r47);
							} else {
								FREE_ZVAL(r47);
								PHALCON_ALLOC_ZVAL(r47);
							}
						}
						phalcon_concat_vboth(r47, r48, "</option>", t8 TSRMLS_CC);
						if (!r52) {
							PHALCON_ALLOC_ZVAL(r52);
						} else {
							if (Z_REFCOUNT_P(r52) > 1) {
								PHALCON_SEPARATE(r52);
							} else {
								FREE_ZVAL(r52);
								PHALCON_ALLOC_ZVAL(r52);
							}
						}
						concat_function(r52, v3, r47 TSRMLS_CC);
						PHALCON_CPY_WRT(v3, r52);
						phalcon_debug_assign("$code", r52 TSRMLS_CC);
					END_FOREACH(ac1, fes83, fee83, ah1, hp1);
				} else {
					phalcon_step_over("Phalcon_Tag::select (Block) File=/Tag Line=357");
					phalcon_step_over("Phalcon_Tag::select (Throw) File=/Tag Line=358");
					PHALCON_ALLOC_ZVAL(i2);
					object_init_ex(i2, phalcon_tag_exception_class_entry);
					phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
					phalcon_debug_method_call(i2, "__construct" TSRMLS_CC);
					PHALCON_ALLOC_ZVAL(p12[0]);
					ZVAL_STRING(p12[0], "Options value should be an Array or Object", 1);
					PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p12, PHALCON_CALL_CHECK);
					phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
					zend_throw_exception_object(i2 TSRMLS_CC);
					Z_ADDREF_P(i2);
					return;
				}
			}
		}
	}
	phalcon_step_over("Phalcon_Tag::select (AssignOp) File=/Tag Line=363");
	PHALCON_ALLOC_ZVAL(t9);
	ZVAL_STRING(t9, "</select>", 1);
	PHALCON_ALLOC_ZVAL(r53);
	concat_function(r53, v3, t9 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r53);
	phalcon_debug_assign("$code", r53 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", v3 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v3);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Tag::select (Method) File=/Tag Line=375");
}

/**
 * Builds a HTML TEXTAREA tag
 *
 * 
 *
 * @paramarray $params
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, textArea){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Tag", "textArea", 0);
	phalcon_step_over("Phalcon_Tag::textArea (If) File=/Tag Line=376");
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		phalcon_step_over("Phalcon_Tag::textArea (Block) File=/Tag Line=376");
		phalcon_step_over("Phalcon_Tag::textArea (Assignment) File=/Tag Line=377");
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
		PHALCON_CPY_WRT_PARAM(v0, a0);
		phalcon_debug_assign("$params", a0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::textArea (If) File=/Tag Line=379");
	eval_int = phalcon_array_isset_long(v0, 0);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Tag::textArea (Block) File=/Tag Line=379");
		phalcon_step_over("Phalcon_Tag::textArea (Assignment) File=/Tag Line=380");
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, v0, "id", strlen("id"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_update_long(v0, 0, r0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::textArea (If) File=/Tag Line=382");
	eval_int = phalcon_array_isset_string(v0, "name", strlen("name")+1);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Tag::textArea (Block) File=/Tag Line=382");
		phalcon_step_over("Phalcon_Tag::textArea (Assignment) File=/Tag Line=383");
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_update_string(v0, "name", strlen("name"), r1 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Tag::textArea (Block) File=/Tag Line=384");
		phalcon_step_over("Phalcon_Tag::textArea (If) File=/Tag Line=385");
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_string(r2, v0, "name", strlen("name"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!zend_is_true(r2)) {
			phalcon_step_over("Phalcon_Tag::textArea (Block) File=/Tag Line=385");
			phalcon_step_over("Phalcon_Tag::textArea (Assignment) File=/Tag Line=386");
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch_long(r3, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update_string(v0, "name", strlen("name"), r3 TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Tag::textArea (If) File=/Tag Line=389");
	eval_int = phalcon_array_isset_string(v0, "value", strlen("value")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Tag::textArea (Block) File=/Tag Line=389");
		phalcon_step_over("Phalcon_Tag::textArea (Assignment) File=/Tag Line=390");
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_array_fetch_string(r4, v0, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r4);
		phalcon_debug_assign("$content", r4 TSRMLS_CC);
		phalcon_step_over("Phalcon_Tag::textArea (Unset) File=/Tag Line=391");
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "value", strlen("value")+1);
	} else {
		phalcon_step_over("Phalcon_Tag::textArea (Block) File=/Tag Line=392");
		phalcon_step_over("Phalcon_Tag::textArea (Assignment) File=/Tag Line=393");
		PHALCON_ALLOC_ZVAL(r5);
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_array_fetch_long(r6, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r6);
		p0[0] = r6;
		phalcon_debug_param(r6 TSRMLS_CC);
		PHALCON_CALL_SELF_PARAMS(r5, this_ptr, "_getvaluefromaction", 1, p0);
		phalcon_debug_vdump("SelfStaticReturn > ", r5 TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r5);
		phalcon_debug_assign("$content", r5 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::textArea (Assignment) File=/Tag Line=395");
	PHALCON_ALLOC_ZVAL(r7);
	phalcon_array_fetch_long(r7, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r8);
	phalcon_concat_both(r8,  "<textarea id=\"", r7, "\" " TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r8);
	phalcon_debug_assign("$code", r8 TSRMLS_CC);
	phalcon_step_over("Phalcon_Tag::textArea (Foreach) File=/Tag Line=396");
	FOREACH_KV(v0, ac0, fes84, fee84, ah0, hp0, v4, v3)
		phalcon_step_over("Phalcon_Tag::textArea (Block) File=/Tag Line=396");
		phalcon_step_over("Phalcon_Tag::textArea (If) File=/Tag Line=397");
		if (Z_TYPE_P(v4) != IS_LONG) {
			phalcon_step_over("Phalcon_Tag::textArea (Block) File=/Tag Line=397");
			phalcon_step_over("Phalcon_Tag::textArea (AssignOp) File=/Tag Line=398");
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
			phalcon_concat_vboth(r9, v4, "=\"", v3 TSRMLS_CC);
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
			PHALCON_CONCAT_RIGHT(r10, r9, "\" ");
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
			concat_function(r11, v2, r10 TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r11);
			phalcon_debug_assign("$code", r11 TSRMLS_CC);
		}
	END_FOREACH(ac0, fes84, fee84, ah0, hp0);
	phalcon_step_over("Phalcon_Tag::textArea (AssignOp) File=/Tag Line=401");
	PHALCON_ALLOC_ZVAL(r12);
	phalcon_concat_both(r12,  ">", v1, "</textarea>" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r13);
	concat_function(r13, v2, r12 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r13);
	phalcon_debug_assign("$code", r13 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Tag::textArea (Method) File=/Tag Line=416");
}

/**
 * Builds a HTML FORM tag
 *
 * 
 *
 * @paramarray $params
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, form){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL;
	zval *t0 = NULL;
	zval *ac0 = NULL;
	zval *p1[] = { NULL, NULL }, *p5[] = { NULL }, *p6[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Tag", "form", 0);
	phalcon_step_over("Phalcon_Tag::form (If) File=/Tag Line=417");
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		phalcon_step_over("Phalcon_Tag::form (Block) File=/Tag Line=417");
		phalcon_step_over("Phalcon_Tag::form (Assignment) File=/Tag Line=418");
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
		PHALCON_CPY_WRT_PARAM(v0, a0);
		phalcon_debug_assign("$params", a0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::form (Assignment) File=/Tag Line=421");
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_SELF(r0, this_ptr, "_getdispatcher");
	phalcon_debug_vdump("SelfStaticReturn > ", r0 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r0);
	phalcon_debug_assign("$dispatcher", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Tag::form (Assignment) File=/Tag Line=423");
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(p1[0]);
	ZVAL_STRING(p1[0], "/", 1);
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
	phalcon_debug_method_call(v1, "getparams" TSRMLS_CC);
	PHALCON_CALL_METHOD(r2, v1, "getparams", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
	p1[1] = r2;
	phalcon_debug_param(r2 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r1, "join", 2, p1);
	phalcon_debug_vdump("join > ", r1 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r1);
	phalcon_debug_assign("$parameters", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Tag::form (If) File=/Tag Line=424");
	eval_int = phalcon_array_isset_long(v0, 0);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Tag::form (Block) File=/Tag Line=424");
		phalcon_step_over("Phalcon_Tag::form (If) File=/Tag Line=425");
		eval_int = phalcon_array_isset_string(v0, "action", strlen("action")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Tag::form (Block) File=/Tag Line=425");
			phalcon_step_over("Phalcon_Tag::form (Assignment) File=/Tag Line=426");
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch_string(r3, v0, "action", strlen("action"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r3);
			phalcon_debug_assign("$action", r3 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Tag::form (Block) File=/Tag Line=427");
			phalcon_step_over("Phalcon_Tag::form (Assignment) File=/Tag Line=428");
			PHALCON_ALLOC_ZVAL(r5);
			phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
			phalcon_debug_method_call(v1, "getcontrollername" TSRMLS_CC);
			PHALCON_CALL_METHOD(r5, v1, "getcontrollername", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r5 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r6);
			phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
			phalcon_debug_method_call(v1, "getactionname" TSRMLS_CC);
			PHALCON_CALL_METHOD(r6, v1, "getactionname", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r6 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Tag" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r4);
			phalcon_concat_vboth(r4, r5, "/", r6 TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r4);
			phalcon_debug_assign("$action", r4 TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Tag::form (Block) File=/Tag Line=430");
		phalcon_step_over("Phalcon_Tag::form (Assignment) File=/Tag Line=431");
		PHALCON_ALLOC_ZVAL(r7);
		phalcon_array_fetch_long(r7, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r7);
		phalcon_debug_assign("$action", r7 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::form (If) File=/Tag Line=433");
	eval_int = phalcon_array_isset_string(v0, "method", strlen("method")+1);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Tag::form (Block) File=/Tag Line=433");
		phalcon_step_over("Phalcon_Tag::form (Assignment) File=/Tag Line=434");
		PHALCON_ALLOC_ZVAL(t0);
		ZVAL_STRING(t0, "post", 1);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_update_string(v0, "method", strlen("method"), t0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::form (If) File=/Tag Line=436");
	eval_int = phalcon_array_isset_string(v0, "confirm", strlen("confirm")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Tag::form (Block) File=/Tag Line=436");
		phalcon_step_over("Phalcon_Tag::form (AssignOp) File=/Tag Line=437");
		PHALCON_ALLOC_ZVAL(r8);
		phalcon_array_fetch_string(r8, v0, "onsubmit", strlen("onsubmit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r10);
		phalcon_array_fetch_string(r10, v0, "onsubmit", strlen("onsubmit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r11);
		phalcon_array_fetch_string(r11, v0, "confirm", strlen("confirm"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r9);
		phalcon_concat_vboth(r9, r10, ";if(!confirm(\"", r11 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r12);
		PHALCON_CONCAT_RIGHT(r12, r9, "\")) { return false; }");
		PHALCON_ALLOC_ZVAL(r13);
		concat_function(r13, r8, r12 TSRMLS_CC);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_update_string(v0, "onsubmit", strlen("onsubmit"), r13 TSRMLS_CC);
		phalcon_step_over("Phalcon_Tag::form (Unset) File=/Tag Line=438");
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "confirm", strlen("confirm")+1);
	}
	phalcon_step_over("Phalcon_Tag::form (If) File=/Tag Line=440");
	if (zend_is_true(v2)) {
		phalcon_step_over("Phalcon_Tag::form (Block) File=/Tag Line=440");
		phalcon_step_over("Phalcon_Tag::form (Assignment) File=/Tag Line=441");
		PHALCON_ALLOC_ZVAL(r14);
		Z_ADDREF_P(v3);
		p5[0] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		PHALCON_CALL_STATIC_PARAMS(r14, "phalcon_utils", "geturl", 1, p5);
		phalcon_debug_vdump("StaticReturn > ", r14 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r14);
		phalcon_debug_assign("$action", r14 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Tag::form (Block) File=/Tag Line=442");
		phalcon_step_over("Phalcon_Tag::form (Assignment) File=/Tag Line=443");
		PHALCON_ALLOC_ZVAL(r15);
		PHALCON_ALLOC_ZVAL(r16);
		phalcon_concat_vboth(r16, v3, "/", v2 TSRMLS_CC);
		Z_ADDREF_P(r16);
		p6[0] = r16;
		phalcon_debug_param(r16 TSRMLS_CC);
		PHALCON_CALL_STATIC_PARAMS(r15, "phalcon_utils", "geturl", 1, p6);
		phalcon_debug_vdump("StaticReturn > ", r15 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r15);
		phalcon_debug_assign("$action", r15 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::form (If) File=/Tag Line=445");
	eval_int = phalcon_array_isset_string(v0, "parameters", strlen("parameters")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Tag::form (Block) File=/Tag Line=445");
		phalcon_step_over("Phalcon_Tag::form (AssignOp) File=/Tag Line=446");
		PHALCON_ALLOC_ZVAL(r17);
		phalcon_array_fetch_string(r17, v0, "parameters", strlen("parameters"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r18);
		PHALCON_CONCAT_LEFT(r18, "?", r17);
		PHALCON_ALLOC_ZVAL(r19);
		concat_function(r19, v3, r18 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r19);
		phalcon_debug_assign("$action", r19 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::form (Assignment) File=/Tag Line=448");
	PHALCON_ALLOC_ZVAL(r20);
	phalcon_concat_both(r20,  "<form action=\"", v3, "\" " TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r20);
	phalcon_debug_assign("$code", r20 TSRMLS_CC);
	phalcon_step_over("Phalcon_Tag::form (Foreach) File=/Tag Line=449");
	FOREACH_KV(v0, ac0, fes85, fee85, ah0, hp0, v6, v5)
		phalcon_step_over("Phalcon_Tag::form (Block) File=/Tag Line=449");
		phalcon_step_over("Phalcon_Tag::form (If) File=/Tag Line=450");
		if (Z_TYPE_P(v6) != IS_LONG) {
			phalcon_step_over("Phalcon_Tag::form (Block) File=/Tag Line=450");
			phalcon_step_over("Phalcon_Tag::form (AssignOp) File=/Tag Line=451");
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
			phalcon_concat_vboth(r21, v6, "= \"", v5 TSRMLS_CC);
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
			PHALCON_CONCAT_RIGHT(r22, r21, "\" ");
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
			concat_function(r23, v4, r22 TSRMLS_CC);
			PHALCON_CPY_WRT(v4, r23);
			phalcon_debug_assign("$code", r23 TSRMLS_CC);
		}
	END_FOREACH(ac0, fes85, fee85, ah0, hp0);
	PHALCON_ALLOC_ZVAL(r24);
	PHALCON_CONCAT_RIGHT(r24, v4, ">");
	phalcon_debug_vdump("Returning > ", r24 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r24);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Tag::form (Method) File=/Tag Line=462");
}

/**
 * Builds a HTML close FORM tag
 *
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, endForm){


	phalcon_step_into_entry("Phalcon_Tag", "endForm", 0);
	phalcon_step_out_entry();
	RETURN_STRING("</form>", 1);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Tag::endForm (Method) File=/Tag Line=466");
}

PHP_METHOD(Phalcon_Tag, setTitle){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Tag", "setTitle", 0);
	phalcon_step_over("Phalcon_Tag::setTitle (Assignment) File=/Tag Line=467");
	zend_update_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, v0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Tag::setTitle (Method) File=/Tag Line=470");
}

PHP_METHOD(Phalcon_Tag, appendTitle){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Tag", "appendTitle", 0);
	phalcon_step_over("Phalcon_Tag::appendTitle (AssignOp) File=/Tag Line=471");
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	concat_function(r0, t0, v0 TSRMLS_CC);
	zend_update_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Tag::appendTitle (Method) File=/Tag Line=474");
}

PHP_METHOD(Phalcon_Tag, prependTitle){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Tag", "prependTitle", 0);
	phalcon_step_over("Phalcon_Tag::prependTitle (Assignment) File=/Tag Line=475");
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	concat_function(r0, v0, t0 TSRMLS_CC);
	zend_update_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Tag::prependTitle (Method) File=/Tag Line=478");
}

PHP_METHOD(Phalcon_Tag, getTitle){

	zval *t0 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Tag", "getTitle", 0);
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_concat_both(r0,  "<title>", t0, "</title>" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Tag::getTitle (Method) File=/Tag Line=494");
}

/**
 * Builds a LINK[rel="stylesheet"] tag
 *
 * 
 *
 * @paramarray $params
 * @param   boolean $local
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, stylesheetLink){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_BOOL(v1, 1);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Tag", "stylesheetLink", 0);
	phalcon_step_over("Phalcon_Tag::stylesheetLink (If) File=/Tag Line=496");
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		phalcon_step_over("Phalcon_Tag::stylesheetLink (Block) File=/Tag Line=496");
		phalcon_step_over("Phalcon_Tag::stylesheetLink (Assignment) File=/Tag Line=497");
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
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		PHALCON_CPY_WRT_PARAM(v0, a0);
		phalcon_debug_assign("$params", a0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::stylesheetLink (If) File=/Tag Line=500");
	eval_int = phalcon_array_isset_string(v0, "href", strlen("href")+1);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Tag::stylesheetLink (Block) File=/Tag Line=500");
		phalcon_step_over("Phalcon_Tag::stylesheetLink (If) File=/Tag Line=501");
		eval_int = phalcon_array_isset_long(v0, 0);
		if (eval_int) {
			phalcon_step_over("Phalcon_Tag::stylesheetLink (Block) File=/Tag Line=501");
			phalcon_step_over("Phalcon_Tag::stylesheetLink (Assignment) File=/Tag Line=502");
			PHALCON_ALLOC_ZVAL(r0);
			phalcon_array_fetch_long(r0, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update_string(v0, "href", strlen("href"), r0 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Tag::stylesheetLink (Block) File=/Tag Line=503");
			phalcon_step_over("Phalcon_Tag::stylesheetLink (Assignment) File=/Tag Line=504");
			PHALCON_ALLOC_ZVAL(t0);
			ZVAL_STRING(t0, "", 1);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update_string(v0, "href", strlen("href"), t0 TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Tag::stylesheetLink (Assignment) File=/Tag Line=508");
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "", 0);
	phalcon_step_over("Phalcon_Tag::stylesheetLink (If) File=/Tag Line=509");
	eval_int = phalcon_array_isset_long(v0, 1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Tag::stylesheetLink (Block) File=/Tag Line=509");
		phalcon_step_over("Phalcon_Tag::stylesheetLink (Assignment) File=/Tag Line=510");
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT_PARAM(v1, r1);
		phalcon_debug_assign("$local", r1 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Tag::stylesheetLink (Block) File=/Tag Line=511");
		phalcon_step_over("Phalcon_Tag::stylesheetLink (If) File=/Tag Line=512");
		eval_int = phalcon_array_isset_string(v0, "local", strlen("local")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Tag::stylesheetLink (Block) File=/Tag Line=512");
			phalcon_step_over("Phalcon_Tag::stylesheetLink (Assignment) File=/Tag Line=513");
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_array_fetch_string(r2, v0, "local", strlen("local"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT_PARAM(v1, r2);
			phalcon_debug_assign("$local", r2 TSRMLS_CC);
			phalcon_step_over("Phalcon_Tag::stylesheetLink (Unset) File=/Tag Line=514");
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_unset_string(v0, "local", strlen("local")+1);
		}
	}
	phalcon_step_over("Phalcon_Tag::stylesheetLink (If) File=/Tag Line=518");
	eval_int = phalcon_array_isset_string(v0, "type", strlen("type")+1);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Tag::stylesheetLink (Block) File=/Tag Line=518");
		phalcon_step_over("Phalcon_Tag::stylesheetLink (Assignment) File=/Tag Line=519");
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_STRING(t1, "text/css", 1);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_update_string(v0, "type", strlen("type"), t1 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::stylesheetLink (If) File=/Tag Line=522");
	if (zend_is_true(v1)) {
		phalcon_step_over("Phalcon_Tag::stylesheetLink (Block) File=/Tag Line=522");
		phalcon_step_over("Phalcon_Tag::stylesheetLink (Assignment) File=/Tag Line=523");
		PHALCON_ALLOC_ZVAL(r3);
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_array_fetch_string(r4, v0, "href", strlen("href"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r4);
		p0[0] = r4;
		phalcon_debug_param(r4 TSRMLS_CC);
		PHALCON_CALL_STATIC_PARAMS(r3, "phalcon_utils", "geturl", 1, p0);
		phalcon_debug_vdump("StaticReturn > ", r3 TSRMLS_CC);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_update_string(v0, "href", strlen("href"), r3 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::stylesheetLink (Assignment) File=/Tag Line=526");
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_STRING(v2, "<link rel=\"stylesheet\" ", 0);
	phalcon_step_over("Phalcon_Tag::stylesheetLink (Foreach) File=/Tag Line=527");
	FOREACH_KV(v0, ac0, fes86, fee86, ah0, hp0, v4, v3)
		phalcon_step_over("Phalcon_Tag::stylesheetLink (Block) File=/Tag Line=527");
		phalcon_step_over("Phalcon_Tag::stylesheetLink (If) File=/Tag Line=528");
		if (Z_TYPE_P(v4) != IS_LONG) {
			phalcon_step_over("Phalcon_Tag::stylesheetLink (Block) File=/Tag Line=528");
			phalcon_step_over("Phalcon_Tag::stylesheetLink (AssignOp) File=/Tag Line=529");
			if (!r6) {
				PHALCON_ALLOC_ZVAL(r6);
			} else {
				if (Z_REFCOUNT_P(r6) > 1) {
					PHALCON_SEPARATE(r6);
				} else {
					FREE_ZVAL(r6);
					PHALCON_ALLOC_ZVAL(r6);
				}
			}
			PHALCON_CONCAT_LEFT(r6, " ", v4);
			if (!r5) {
				PHALCON_ALLOC_ZVAL(r5);
			} else {
				if (Z_REFCOUNT_P(r5) > 1) {
					PHALCON_SEPARATE(r5);
				} else {
					FREE_ZVAL(r5);
					PHALCON_ALLOC_ZVAL(r5);
				}
			}
			phalcon_concat_vboth(r5, r6, "=\"", v3 TSRMLS_CC);
			if (!r7) {
				PHALCON_ALLOC_ZVAL(r7);
			} else {
				if (Z_REFCOUNT_P(r7) > 1) {
					PHALCON_SEPARATE(r7);
				} else {
					FREE_ZVAL(r7);
					PHALCON_ALLOC_ZVAL(r7);
				}
			}
			PHALCON_CONCAT_RIGHT(r7, r5, "\" ");
			if (!r8) {
				PHALCON_ALLOC_ZVAL(r8);
			} else {
				if (Z_REFCOUNT_P(r8) > 1) {
					PHALCON_SEPARATE(r8);
				} else {
					FREE_ZVAL(r8);
					PHALCON_ALLOC_ZVAL(r8);
				}
			}
			concat_function(r8, v2, r7 TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r8);
			phalcon_debug_assign("$code", r8 TSRMLS_CC);
		}
	END_FOREACH(ac0, fes86, fee86, ah0, hp0);
	phalcon_step_over("Phalcon_Tag::stylesheetLink (AssignOp) File=/Tag Line=532");
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_STRING(t2, ">", 1);
	PHALCON_ALLOC_ZVAL(r9);
	concat_function(r9, v2, t2 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r9);
	phalcon_debug_assign("$code", r9 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Tag::stylesheetLink (Method) File=/Tag Line=542");
}

/**
 * Builds HTML IMG tags
 *
 * @param  array $params
 * @return string
 */
PHP_METHOD(Phalcon_Tag, image){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Tag", "image", 0);
	phalcon_step_over("Phalcon_Tag::image (If) File=/Tag Line=544");
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		phalcon_step_over("Phalcon_Tag::image (Block) File=/Tag Line=544");
		phalcon_step_over("Phalcon_Tag::image (Assignment) File=/Tag Line=545");
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
		PHALCON_CPY_WRT_PARAM(v0, a0);
		phalcon_debug_assign("$params", a0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Tag::image (If) File=/Tag Line=548");
	eval_int = phalcon_array_isset_string(v0, "src", strlen("src")+1);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Tag::image (Block) File=/Tag Line=548");
		phalcon_step_over("Phalcon_Tag::image (If) File=/Tag Line=549");
		eval_int = phalcon_array_isset_long(v0, 0);
		if (eval_int) {
			phalcon_step_over("Phalcon_Tag::image (Block) File=/Tag Line=549");
			phalcon_step_over("Phalcon_Tag::image (Assignment) File=/Tag Line=550");
			PHALCON_ALLOC_ZVAL(r0);
			phalcon_array_fetch_long(r0, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update_string(v0, "src", strlen("src"), r0 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Tag::image (Block) File=/Tag Line=551");
			phalcon_step_over("Phalcon_Tag::image (Assignment) File=/Tag Line=552");
			PHALCON_ALLOC_ZVAL(t0);
			ZVAL_STRING(t0, "", 1);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update_string(v0, "src", strlen("src"), t0 TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Tag::image (Assignment) File=/Tag Line=556");
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_array_fetch_string(r2, v0, "src", strlen("src"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[0] = r2;
	phalcon_debug_param(r2 TSRMLS_CC);
	PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_utils", "geturl", 1, p0);
	phalcon_debug_vdump("StaticReturn > ", r1 TSRMLS_CC);
	PHALCON_SEPARATE_PARAM(v0);
	phalcon_array_update_string(v0, "src", strlen("src"), r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Tag::image (Assignment) File=/Tag Line=558");
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "<img ", 0);
	phalcon_step_over("Phalcon_Tag::image (Foreach) File=/Tag Line=559");
	FOREACH_KV(v0, ac0, fes87, fee87, ah0, hp0, v3, v2)
		phalcon_step_over("Phalcon_Tag::image (Block) File=/Tag Line=559");
		phalcon_step_over("Phalcon_Tag::image (If) File=/Tag Line=560");
		if (Z_TYPE_P(v3) != IS_LONG) {
			phalcon_step_over("Phalcon_Tag::image (Block) File=/Tag Line=560");
			phalcon_step_over("Phalcon_Tag::image (AssignOp) File=/Tag Line=561");
			if (!r4) {
				PHALCON_ALLOC_ZVAL(r4);
			} else {
				if (Z_REFCOUNT_P(r4) > 1) {
					PHALCON_SEPARATE(r4);
				} else {
					FREE_ZVAL(r4);
					PHALCON_ALLOC_ZVAL(r4);
				}
			}
			PHALCON_CONCAT_LEFT(r4, " ", v3);
			if (!r3) {
				PHALCON_ALLOC_ZVAL(r3);
			} else {
				if (Z_REFCOUNT_P(r3) > 1) {
					PHALCON_SEPARATE(r3);
				} else {
					FREE_ZVAL(r3);
					PHALCON_ALLOC_ZVAL(r3);
				}
			}
			phalcon_concat_vboth(r3, r4, "=\"", v2 TSRMLS_CC);
			if (!r5) {
				PHALCON_ALLOC_ZVAL(r5);
			} else {
				if (Z_REFCOUNT_P(r5) > 1) {
					PHALCON_SEPARATE(r5);
				} else {
					FREE_ZVAL(r5);
					PHALCON_ALLOC_ZVAL(r5);
				}
			}
			PHALCON_CONCAT_RIGHT(r5, r3, "\" ");
			if (!r6) {
				PHALCON_ALLOC_ZVAL(r6);
			} else {
				if (Z_REFCOUNT_P(r6) > 1) {
					PHALCON_SEPARATE(r6);
				} else {
					FREE_ZVAL(r6);
					PHALCON_ALLOC_ZVAL(r6);
				}
			}
			concat_function(r6, v1, r5 TSRMLS_CC);
			PHALCON_CPY_WRT(v1, r6);
			phalcon_debug_assign("$code", r6 TSRMLS_CC);
		}
	END_FOREACH(ac0, fes87, fee87, ah0, hp0);
	phalcon_step_over("Phalcon_Tag::image (AssignOp) File=/Tag Line=564");
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_STRING(t1, ">", 1);
	PHALCON_ALLOC_ZVAL(r7);
	concat_function(r7, v1, t1 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r7);
	phalcon_debug_assign("$code", r7 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", v1 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v1);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
}

