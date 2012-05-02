
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

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_db_pool_class_entry, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_NULL(t1);
	PHALCON_INIT_VAR(r0);
	is_not_identical_function(r0, t1, t0 TSRMLS_CC);
	PHALCON_RETURN_NCTOR(r0);
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
	zval *p0[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		if (Z_TYPE_P(v0) != IS_OBJECT) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_db_exception_class_entry);
			PHALCON_INIT_VAR(p0[0]);
			ZVAL_STRING(p0[0], "The parameter 'options' must be an Array or Object", 1);
			PHALCON_INIT_VAR(p0[1]);
			ZVAL_LONG(p0[1], 0);
			PHALCON_INIT_VAR(p0[2]);
			ZVAL_BOOL(p0[2], 1);
			PHALCON_INIT_VAR(p0[3]);
			ZVAL_NULL(p0[3]);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p0, PHALCON_CALL_CHECK);
			return phalcon_throw_exception(i0 TSRMLS_CC);
		}
	}
	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init(i1);
		PHALCON_CPY_WRT(v1, i1);
		if (Z_TYPE_P(v0) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v0);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_162f_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_162f_0;
			} else {
				PHALCON_INIT_VAR(v3);
				htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
				if (htype == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(v3, index, index_len-1, 1);
				} else {
					if (htype == HASH_KEY_IS_LONG) {
						ZVAL_LONG(v3, num);
					}
				}
			}
			PHALCON_INIT_VAR(v2);
			ZVAL_ZVAL(v2, *hd, 1, 0);
			phalcon_update_property_zval(v1, Z_STRVAL_P(v3), Z_STRLEN_P(v3), v2 TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_162f_0;
			fee_162f_0:
			if(0){ };
		}
	} else {
		PHALCON_CPY_WRT(v1, v0);
	}
	zend_update_static_property(phalcon_db_pool_class_entry, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, v1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
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
	zval *t7 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL, NULL }, *p2[] = { NULL, NULL, NULL }, *p3[] = { NULL, NULL, NULL }, *p4[] = { NULL, NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_BOOL(v0, 0);
	}
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_BOOL(v1, 0);
	}
	
	t0 = zend_read_static_property(phalcon_db_pool_class_entry, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CPY_WRT(v2, t0);
	if (!zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Default database connection parameters was not defined", 1);
		PHALCON_INIT_VAR(p0[1]);
		ZVAL_LONG(p0[1], 0);
		PHALCON_INIT_VAR(p0[2]);
		ZVAL_BOOL(p0[2], 1);
		PHALCON_INIT_VAR(p0[3]);
		ZVAL_NULL(p0[3]);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	eval_int = phalcon_isset_property(v2, "adapter", strlen("adapter") TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_BOOL(t1, eval_int);
	if (!zend_is_true(t1)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "A valid adapter name is required", 1);
		PHALCON_INIT_VAR(p1[1]);
		ZVAL_LONG(p1[1], 0);
		PHALCON_INIT_VAR(p1[2]);
		ZVAL_BOOL(p1[2], 1);
		PHALCON_INIT_VAR(p1[3]);
		ZVAL_NULL(p1[3]);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 4, p1, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	if (zend_is_true(v0)) {
		if (zend_is_true(v1)) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_ALLOC_ZVAL_MM(t2);
			phalcon_read_property(&t2, v2, "adapter", sizeof("adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(t2);
			p2[0] = t2;
			Z_ADDREF_P(v2);
			p2[1] = v2;
			PHALCON_INIT_VAR(p2[2]);
			ZVAL_BOOL(p2[2], 1);
			PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db", "factory", 3, p2);
			Z_DELREF_P(p2[0]);
			Z_DELREF_P(p2[1]);
			zend_update_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, r0 TSRMLS_CC);
			t3 = zend_read_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			PHALCON_CPY_WRT(v3, t3);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_read_property(&t4, v2, "adapter", sizeof("adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(t4);
			p3[0] = t4;
			Z_ADDREF_P(v2);
			p3[1] = v2;
			PHALCON_INIT_VAR(p3[2]);
			ZVAL_BOOL(p3[2], 0);
			PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_db", "factory", 3, p3);
			Z_DELREF_P(p3[0]);
			Z_DELREF_P(p3[1]);
			PHALCON_CPY_WRT(v3, r1);
		}
	} else {
		t5 = zend_read_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (!zend_is_true(t5)) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_ALLOC_ZVAL_MM(t6);
			phalcon_read_property(&t6, v2, "adapter", sizeof("adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(t6);
			p4[0] = t6;
			Z_ADDREF_P(v2);
			p4[1] = v2;
			PHALCON_INIT_VAR(p4[2]);
			ZVAL_BOOL(p4[2], 1);
			PHALCON_CALL_STATIC_PARAMS(r2, "phalcon_db", "factory", 3, p4);
			Z_DELREF_P(p4[0]);
			Z_DELREF_P(p4[1]);
			zend_update_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, r2 TSRMLS_CC);
		}
		t7 = zend_read_static_property(phalcon_db_pool_class_entry, "_persistentConnection", sizeof("_persistentConnection")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_CPY_WRT(v3, t7);
	}
	PHALCON_RETURN_CHECK_CTOR(v3);
}

