
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
	t0 = zend_read_static_property(phalcon_db_pool_ce, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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

	zval *options = NULL, *descriptor = NULL, *value = NULL, *key = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		if (Z_TYPE_P(options) != IS_OBJECT) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_db_exception_ce);
			PHALCON_INIT_VAR(p0[0]);
			ZVAL_STRING(p0[0], "The parameter 'options' must be an Array or Object", 1);
			PHALCON_INIT_VAR(p0[1]);
			ZVAL_LONG(p0[1], 0);
			PHALCON_INIT_VAR(p0[2]);
			ZVAL_BOOL(p0[2], 1);
			PHALCON_INIT_VAR(p0[3]);
			ZVAL_NULL(p0[3]);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p0, PHALCON_CHECK);
			phalcon_throw_exception(i0 TSRMLS_CC);
			return;
		}
	}
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init(i1);
		PHALCON_CPY_WRT(descriptor, i1);
		if (phalcon_valid_foreach(options TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(options);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_162f_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_162f_0;
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
			phalcon_update_property_zval(descriptor, Z_STRVAL_P(key), Z_STRLEN_P(key), value TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_162f_0;
			fee_162f_0:
			if(0){ };
		}
	} else {
		PHALCON_CPY_WRT(descriptor, options);
	}
	zend_update_static_property(phalcon_db_pool_ce, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, descriptor TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
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

	zval *new_connection = NULL, *renovate = NULL, *database = NULL, *connection = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &new_connection, &renovate) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!new_connection) {
		PHALCON_INIT_VAR(new_connection);
		ZVAL_BOOL(new_connection, 0);
	}
	
	if (!renovate) {
		PHALCON_INIT_VAR(renovate);
		ZVAL_BOOL(renovate, 0);
	}
	
	t0 = zend_read_static_property(phalcon_db_pool_ce, "_defaultDescriptor", sizeof("_defaultDescriptor")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CPY_WRT(database, t0);
	if (!zend_is_true(database)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Default database connection parameters was not defined", 1);
		PHALCON_INIT_VAR(p0[1]);
		ZVAL_LONG(p0[1], 0);
		PHALCON_INIT_VAR(p0[2]);
		ZVAL_BOOL(p0[2], 1);
		PHALCON_INIT_VAR(p0[3]);
		ZVAL_NULL(p0[3]);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	eval_int = phalcon_isset_property(database, "adapter", strlen("adapter") TSRMLS_CC);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "A valid adapter name is required", 1);
		PHALCON_INIT_VAR(p1[1]);
		ZVAL_LONG(p1[1], 0);
		PHALCON_INIT_VAR(p1[2]);
		ZVAL_BOOL(p1[2], 1);
		PHALCON_INIT_VAR(p1[3]);
		ZVAL_NULL(p1[3]);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 4, p1, PHALCON_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	
	if (zend_is_true(new_connection)) {
		if (zend_is_true(renovate)) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, database, "adapter", sizeof("adapter")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_INIT_VAR(c0);
			ZVAL_BOOL(c0, 1);
			PHALCON_CALL_STATIC_PARAMS_3(r0, "phalcon_db", "factory", t1, database, c0);
			zend_update_static_property(phalcon_db_pool_ce, "_persistentConnection", sizeof("_persistentConnection")-1, r0 TSRMLS_CC);
			t2 = zend_read_static_property(phalcon_db_pool_ce, "_persistentConnection", sizeof("_persistentConnection")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			PHALCON_CPY_WRT(connection, t2);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_ALLOC_ZVAL_MM(t3);
			phalcon_read_property(&t3, database, "adapter", sizeof("adapter")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_INIT_VAR(c1);
			ZVAL_BOOL(c1, 0);
			PHALCON_CALL_STATIC_PARAMS_3(r1, "phalcon_db", "factory", t3, database, c1);
			PHALCON_CPY_WRT(connection, r1);
		}
	} else {
		t4 = zend_read_static_property(phalcon_db_pool_ce, "_persistentConnection", sizeof("_persistentConnection")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (!zend_is_true(t4)) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_ALLOC_ZVAL_MM(t5);
			phalcon_read_property(&t5, database, "adapter", sizeof("adapter")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_INIT_VAR(c2);
			ZVAL_BOOL(c2, 1);
			PHALCON_CALL_STATIC_PARAMS_3(r2, "phalcon_db", "factory", t5, database, c2);
			zend_update_static_property(phalcon_db_pool_ce, "_persistentConnection", sizeof("_persistentConnection")-1, r2 TSRMLS_CC);
		}
		t6 = zend_read_static_property(phalcon_db_pool_ce, "_persistentConnection", sizeof("_persistentConnection")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_CPY_WRT(connection, t6);
	}
	PHALCON_RETURN_CHECK_CTOR(connection);
}

