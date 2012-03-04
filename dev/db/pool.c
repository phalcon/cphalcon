
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
 * Phalcon_Db_Pool
 *
 * Manages caching of database connections. With the help of Phalcon_Db_Pool, developers can be sure that no new database
 * connections will made when calling multiple of times Phalcon_Db_Pool::getConnection.
 */

/**
 * Check if a default descriptor has already defined
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Pool, hasDefaultDescriptor){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Db_Pool", "hasDefaultDescriptor", 0);
	t0 = zend_read_static_property(phalcon_db_pool_class_entry, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_INIT_NULL(t1);
	PHALCON_NOT_IDENTICAL_FUNCTION(r0, t0, t1);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r0);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_Pool::hasDefaultDescriptor (Method) File=/Db/Pool Line=40");
}

/**
 * Sets the default descriptor for database connections.
 *
 *
 *
 * @param array $options
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Pool, setDefaultDescriptor){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };
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
	phalcon_step_into_entry("Phalcon_Db_Pool", "setDefaultDescriptor", 0);
	phalcon_step_over("Phalcon_Db_Pool::setDefaultDescriptor (If) File=/Db/Pool Line=41");
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		phalcon_step_over("Phalcon_Db_Pool::setDefaultDescriptor (Block) File=/Db/Pool Line=41");
		phalcon_step_over("Phalcon_Db_Pool::setDefaultDescriptor (If) File=/Db/Pool Line=42");
		if (Z_TYPE_P(v0) != IS_OBJECT) {
			phalcon_step_over("Phalcon_Db_Pool::setDefaultDescriptor (Block) File=/Db/Pool Line=42");
			phalcon_step_over("Phalcon_Db_Pool::setDefaultDescriptor (Throw) File=/Db/Pool Line=43");
			PHALCON_ALLOC_ZVAL(i0);
			object_init_ex(i0, phalcon_db_exception_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Db_Pool" TSRMLS_CC);
			phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p0[0]);
			ZVAL_STRING(p0[0], "The parameter 'options' must be an Array or Object", 1);
			PHALCON_PARAM_LONG(p0[1], 0);
			PHALCON_PARAM_BOOL(p0[2], 1);
			PHALCON_PARAM_NULL(p0[3]);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p0, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Db_Pool" TSRMLS_CC);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			return;
		}
	}
	phalcon_step_over("Phalcon_Db_Pool::setDefaultDescriptor (If) File=/Db/Pool Line=46");
	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		phalcon_step_over("Phalcon_Db_Pool::setDefaultDescriptor (Block) File=/Db/Pool Line=46");
		phalcon_step_over("Phalcon_Db_Pool::setDefaultDescriptor (Assignment) File=/Db/Pool Line=47");
		PHALCON_ALLOC_ZVAL(i1);
		object_init(i1);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(i1);
		v1 = i1;
		phalcon_debug_assign("$descriptor", i1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_Pool::setDefaultDescriptor (Foreach) File=/Db/Pool Line=48");
		FOREACH_KV(v0, ac0, fes51, fee51, ah0, hp0, v3, v2)
			phalcon_step_over("Phalcon_Db_Pool::setDefaultDescriptor (Block) File=/Db/Pool Line=48");
			phalcon_step_over("Phalcon_Db_Pool::setDefaultDescriptor (Assignment) File=/Db/Pool Line=49");
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(v1, Z_STRVAL_P(v3), Z_STRLEN_P(v3), copy TSRMLS_CC);
			}
		END_FOREACH(ac0, fes51, fee51, ah0, hp0);
	} else {
		phalcon_step_over("Phalcon_Db_Pool::setDefaultDescriptor (Block) File=/Db/Pool Line=51");
		phalcon_step_over("Phalcon_Db_Pool::setDefaultDescriptor (Assignment) File=/Db/Pool Line=52");
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(v0);
		v1 = v0;
		phalcon_debug_assign("$descriptor", v0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Db_Pool::setDefaultDescriptor (Assignment) File=/Db/Pool Line=54");
	zend_update_static_property(phalcon_db_pool_class_entry, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, v1 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db_Pool::setDefaultDescriptor (Method) File=/Db/Pool Line=66");
}

/**
 * Returns a connection builded with the default descriptor parameters
 *
 * 
 *
 * @param boolean $newConnection
     * @param boolean $renovate
 * @return Phalcon_Db
 */
PHP_METHOD(Phalcon_Db_Pool, getConnection){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL, NULL }, *p2[] = { NULL, NULL, NULL }, *p3[] = { NULL, NULL, NULL }, *p4[] = { NULL, NULL, NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_BOOL(v0, 0);
	}
	if (!v1) {
		PHALCON_INIT_BOOL(v1, 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Pool", "getConnection", 0);
	phalcon_step_over("Phalcon_Db_Pool::getConnection (Assignment) File=/Db/Pool Line=67");
	t0 = zend_read_static_property(phalcon_db_pool_class_entry, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(t0);
	v2 = t0;
	phalcon_debug_assign("$database", t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_Pool::getConnection (If) File=/Db/Pool Line=68");
	if (!zend_is_true(v2)) {
		phalcon_step_over("Phalcon_Db_Pool::getConnection (Block) File=/Db/Pool Line=68");
		phalcon_step_over("Phalcon_Db_Pool::getConnection (Throw) File=/Db/Pool Line=69");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Pool" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p0[0]);
		ZVAL_STRING(p0[0], "Default database connection parameters was not defined", 1);
		PHALCON_PARAM_LONG(p0[1], 0);
		PHALCON_PARAM_BOOL(p0[2], 1);
		PHALCON_PARAM_NULL(p0[3]);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p0, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Pool" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_over("Phalcon_Db_Pool::getConnection (If) File=/Db/Pool Line=71");
	eval_int = phalcon_isset_property(v2, "adapter", strlen("adapter") TSRMLS_CC);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Db_Pool::getConnection (Block) File=/Db/Pool Line=71");
		phalcon_step_over("Phalcon_Db_Pool::getConnection (Throw) File=/Db/Pool Line=72");
		PHALCON_ALLOC_ZVAL(i1);
		object_init_ex(i1, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Pool" TSRMLS_CC);
		phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], "A valid adapter name is required", 1);
		PHALCON_PARAM_LONG(p1[1], 0);
		PHALCON_PARAM_BOOL(p1[2], 1);
		PHALCON_PARAM_NULL(p1[3]);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 4, p1, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Pool" TSRMLS_CC);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		return;
	}
	phalcon_step_over("Phalcon_Db_Pool::getConnection (If) File=/Db/Pool Line=74");
	if (zend_is_true(v0)) {
		phalcon_step_over("Phalcon_Db_Pool::getConnection (Block) File=/Db/Pool Line=74");
		phalcon_step_over("Phalcon_Db_Pool::getConnection (If) File=/Db/Pool Line=75");
		if (zend_is_true(v1)) {
			phalcon_step_over("Phalcon_Db_Pool::getConnection (Block) File=/Db/Pool Line=75");
			phalcon_step_over("Phalcon_Db_Pool::getConnection (Assignment) File=/Db/Pool Line=76");
			PHALCON_ALLOC_ZVAL(r0);
			PHALCON_ALLOC_ZVAL(t1);
			phalcon_read_property(t1, v2, "adapter", sizeof("adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(t1);
			p2[0] = t1;
			phalcon_debug_param(t1 TSRMLS_CC);
			Z_ADDREF_P(v2);
			p2[1] = v2;
			phalcon_debug_param(v2 TSRMLS_CC);
			PHALCON_PARAM_BOOL(p2[2], 1);
			PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db", "factory", 3, p2);
			phalcon_debug_vdump("StaticReturn > ", r0 TSRMLS_CC);
			zend_update_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, r0 TSRMLS_CC);
			phalcon_step_over("Phalcon_Db_Pool::getConnection (Assignment) File=/Db/Pool Line=77");
			t2 = zend_read_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			if (v3) {
				Z_DELREF_P(v3);
				if (!Z_REFCOUNT_P(v3)) {
					FREE_ZVAL(v3);
				}
			}
			Z_ADDREF_P(t2);
			v3 = t2;
			phalcon_debug_assign("$connection", t2 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Db_Pool::getConnection (Block) File=/Db/Pool Line=78");
			phalcon_step_over("Phalcon_Db_Pool::getConnection (Assignment) File=/Db/Pool Line=79");
			PHALCON_ALLOC_ZVAL(r1);
			PHALCON_ALLOC_ZVAL(t3);
			phalcon_read_property(t3, v2, "adapter", sizeof("adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(t3);
			p3[0] = t3;
			phalcon_debug_param(t3 TSRMLS_CC);
			Z_ADDREF_P(v2);
			p3[1] = v2;
			phalcon_debug_param(v2 TSRMLS_CC);
			PHALCON_PARAM_BOOL(p3[2], 0);
			PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_db", "factory", 3, p3);
			phalcon_debug_vdump("StaticReturn > ", r1 TSRMLS_CC);
			if (v3) {
				Z_DELREF_P(v3);
				if (!Z_REFCOUNT_P(v3)) {
					FREE_ZVAL(v3);
				}
			}
			Z_ADDREF_P(r1);
			v3 = r1;
			phalcon_debug_assign("$connection", r1 TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Db_Pool::getConnection (Block) File=/Db/Pool Line=81");
		phalcon_step_over("Phalcon_Db_Pool::getConnection (If) File=/Db/Pool Line=82");
		t4 = zend_read_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (!zend_is_true(t4)) {
			phalcon_step_over("Phalcon_Db_Pool::getConnection (Block) File=/Db/Pool Line=82");
			phalcon_step_over("Phalcon_Db_Pool::getConnection (Assignment) File=/Db/Pool Line=83");
			PHALCON_ALLOC_ZVAL(r2);
			PHALCON_ALLOC_ZVAL(t5);
			phalcon_read_property(t5, v2, "adapter", sizeof("adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(t5);
			p4[0] = t5;
			phalcon_debug_param(t5 TSRMLS_CC);
			Z_ADDREF_P(v2);
			p4[1] = v2;
			phalcon_debug_param(v2 TSRMLS_CC);
			PHALCON_PARAM_BOOL(p4[2], 1);
			PHALCON_CALL_STATIC_PARAMS(r2, "phalcon_db", "factory", 3, p4);
			phalcon_debug_vdump("StaticReturn > ", r2 TSRMLS_CC);
			zend_update_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, r2 TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Db_Pool::getConnection (Assignment) File=/Db/Pool Line=85");
		t6 = zend_read_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(t6);
		v3 = t6;
		phalcon_debug_assign("$connection", t6 TSRMLS_CC);
	}
	phalcon_debug_vdump("Returning > ", v3 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(v3) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v3);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v3);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
}

