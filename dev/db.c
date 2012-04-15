
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
 * Phalcon_Db
 *
 * Phalcon_Db and its related classes provide a simple SQL database interface for Phalcon Framework.
 * The Phalcon_Db is the basic class you use to connect your PHP application to a RDBMS.
 * There is a different adapter class for each brand of RDBMS.
 *
 * This component is intended to low level database operations. If you want to interact with databases using
 * high level abstraction use Phalcon_Model.
 *
 * Phalcon_Db is an abstract class. You only can use it with a database adapter like Phalcon_Db_Mysql
 *
 * 
 */

/**
 * Phalcon_Db contructor, This method does not should to be called directly. Use Phalcon_Db::factory instead
 *
 * @param stdClass $descriptor
 */
PHP_METHOD(Phalcon_Db, __construct){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_descriptor", strlen("_descriptor"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets a logger class to log all SQL operations sended to database server
 *
 * @param Phalcon_Logger $logger
 */
PHP_METHOD(Phalcon_Db, setLogger){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_logger", strlen("_logger"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the active logger
 *
 * @return Phalcon_Logger
 */
PHP_METHOD(Phalcon_Db, getLogger){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sends an aribtrary text to the related logger in the instance
 *
 * @param string $sqlStatement
 * @param int $type
 */
PHP_METHOD(Phalcon_Db, log){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v0);
		p0[0] = v0;
		Z_ADDREF_P(v1);
		p0[1] = v1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "log", 2, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
		Z_DELREF_P(p0[1]);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets a database profiler in the connection
 *
 * @param Phalcon_Db_Profiler $profiler
 */
PHP_METHOD(Phalcon_Db, setProfiler){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) == IS_OBJECT) {
		phalcon_update_property_zval(this_ptr, "_profiler", strlen("_profiler"), v0 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Profiler must be an object", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the first row in a SQL query result
 *
 * 
 *
 * @param string $sqlQuery
 * @return array
 */
PHP_METHOD(Phalcon_Db, fetchOne){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_CPY_WRT(v1, r0);
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(v1);
		p1[0] = v1;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetcharray", 1, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
		PHALCON_RETURN_DZVAL(r1);
	} else {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_RETURN_CTOR(a0);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Dumps the complete result of a query into an array
 *
 * 
 *
 * @param string $sqlQuery
 * @return array
 */
PHP_METHOD(Phalcon_Db, fetchAll){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v1, a0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_INIT_VAR(t0);
	ZVAL_BOOL(t0, 0);
	PHALCON_INIT_VAR(r1);
	is_not_equal_function(r1, v2, t0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		ws_e7f0_0:
		PHALCON_INIT_VAR(r2);
		Z_ADDREF_P(v2);
		p1[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "fetcharray", 1, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
		PHALCON_CPY_WRT(v3, r2);
		if (!zend_is_true(v3)) {
			goto we_e7f0_0;
		}
		Z_ADDREF_P(v3);
		PHALCON_SEPARATE_ARRAY(v1);
		phalcon_array_append(v1, v3 TSRMLS_CC);
		goto ws_e7f0_0;
		we_e7f0_0:
		if(0) { };
	}
	PHALCON_RETURN_CTOR(v1);
}

/**
 * Inserts data into a database table using custom RBDM SQL syntax
 *
 * 
 *
 * @param string $tables
 * @param array $values
 * @param array $fields
 * @param boolean $automaticQuotes
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, insert){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *p1[] = { NULL, NULL, NULL, NULL }, *p9[] = { NULL }, *p10[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v1);
	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_NULL(v2);
	}
	if (!v3) {
		PHALCON_INIT_VAR(v3);
		ZVAL_BOOL(v3, 0);
	}
	
	PHALCON_INIT_VAR(v4);
	ZVAL_STRING(v4, "", 1);
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "count", v1, 0x008);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		is_equal_function(r1, r0, t0 TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_db_exception_class_entry);
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CONCAT_BOTH(r2,  "Unable to insert into ", v0, " without data");
			Z_ADDREF_P(r2);
			p1[0] = r2;
			PHALCON_INIT_VAR(p1[1]);
			ZVAL_LONG(p1[1], 0);
			PHALCON_INIT_VAR(p1[2]);
			ZVAL_BOOL(p1[2], 1);
			Z_ADDREF_P(this_ptr);
			p1[3] = this_ptr;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
			Z_DELREF_P(p1[0]);
			Z_DELREF_P(p1[3]);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			PHALCON_MM_RESTORE();
			return;
		} else {
			if (zend_is_true(v3)) {
				if (Z_TYPE_P(v1) != IS_ARRAY) {
					php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
				} else {
					ALLOC_HASHTABLE(ah0);
					zend_hash_init(ah0, 0, NULL, NULL, 0);
					zend_hash_copy(ah0, Z_ARRVAL_P(v1), NULL, NULL, sizeof(zval*));
					zend_hash_internal_pointer_reset_ex(ah0, &hp0);
					fes_e7f0_1:
					if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
						goto fee_e7f0_1;
					} else {
						PHALCON_INIT_VAR(v6);
						htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
						if (htype == HASH_KEY_IS_STRING) {
							ZVAL_STRINGL(v6, index, index_len-1, 1);
						} else {
							if (htype == HASH_KEY_IS_LONG) {
								ZVAL_LONG(v6, num);
							}
						}
					}
					PHALCON_INIT_VAR(v5);
					ZVAL_ZVAL(v5, *hd, 1, 0);
					PHALCON_INIT_VAR(r3);
					phalcon_array_fetch(&r3, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
					if (Z_TYPE_P(r3) == IS_OBJECT) {
						PHALCON_INIT_VAR(r4);
						phalcon_array_fetch(&r4, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_INIT_VAR(r5);
						phalcon_instance_of(r5, r4, phalcon_db_rawvalue_class_entry TSRMLS_CC);
						if (zend_is_true(r5)) {
							PHALCON_INIT_VAR(r6);
							PHALCON_INIT_VAR(r7);
							PHALCON_INIT_VAR(r8);
							phalcon_array_fetch(&r8, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
							PHALCON_CALL_METHOD(r7, r8, "getvalue", PHALCON_CALL_DEFAULT);
							Z_ADDREF_P(r7);
							PHALCON_CALL_FUNC_PARAMS_1(r6, "addslashes", r7, 0x01F);
							Z_DELREF_P(r7);
							Z_ADDREF_P(r6);
							if (Z_REFCOUNT_P(v1) > 1) {
								zval *new_zv;
								Z_DELREF_P(v1);
								ALLOC_ZVAL(new_zv);
								INIT_PZVAL_COPY(new_zv, v1);
								v1 = new_zv;
								zval_copy_ctor(new_zv);
							}
							phalcon_array_update(v1, v6, r6 TSRMLS_CC);
							goto fes_e7f0_1;
						} else {
							PHALCON_INIT_VAR(r9);
							PHALCON_INIT_VAR(r10);
							phalcon_array_fetch(&r10, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
							Z_ADDREF_P(r10);
							PHALCON_CALL_FUNC_PARAMS_1(r9, "addslashes", r10, 0x01F);
							Z_DELREF_P(r10);
							PHALCON_INIT_VAR(r11);
							PHALCON_CONCAT_BOTH(r11,  "'", r9, "'");
							Z_ADDREF_P(r11);
							if (Z_REFCOUNT_P(v1) > 1) {
								zval *new_zv;
								Z_DELREF_P(v1);
								ALLOC_ZVAL(new_zv);
								INIT_PZVAL_COPY(new_zv, v1);
								v1 = new_zv;
								zval_copy_ctor(new_zv);
							}
							phalcon_array_update(v1, v6, r11 TSRMLS_CC);
						}
					} else {
						PHALCON_INIT_VAR(r12);
						PHALCON_INIT_VAR(r13);
						phalcon_array_fetch(&r13, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
						Z_ADDREF_P(r13);
						PHALCON_CALL_FUNC_PARAMS_1(r12, "addslashes", r13, 0x01F);
						Z_DELREF_P(r13);
						PHALCON_INIT_VAR(r14);
						PHALCON_CONCAT_BOTH(r14,  "'", r12, "'");
						Z_ADDREF_P(r14);
						if (Z_REFCOUNT_P(v1) > 1) {
							zval *new_zv;
							Z_DELREF_P(v1);
							ALLOC_ZVAL(new_zv);
							INIT_PZVAL_COPY(new_zv, v1);
							v1 = new_zv;
							zval_copy_ctor(new_zv);
						}
						phalcon_array_update(v1, v6, r14 TSRMLS_CC);
					}
					zend_hash_move_forward_ex(ah0, &hp0);
					goto fes_e7f0_1;
					fee_e7f0_1:
					zend_hash_destroy(ah0);
					efree(ah0);
				}
			}
		}
		if (Z_TYPE_P(v2) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL_MM(r17);
			PHALCON_CONCAT_LEFT(r17, "INSERT INTO ", v0);
			PHALCON_ALLOC_ZVAL_MM(r18);
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, ", ", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r18, "join", c0, v2, 0x00F);
			PHALCON_ALLOC_ZVAL_MM(r16);
			PHALCON_CONCAT_VBOTH(r16, r17, " (", r18);
			PHALCON_ALLOC_ZVAL_MM(r19);
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, ", ", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r19, "join", c1, v1, 0x00F);
			PHALCON_ALLOC_ZVAL_MM(r15);
			PHALCON_CONCAT_VBOTH(r15, r16, ") VALUES (", r19);
			PHALCON_ALLOC_ZVAL_MM(r20);
			PHALCON_CONCAT_RIGHT(r20, r15, ")");
			PHALCON_CPY_WRT(v4, r20);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r22);
			PHALCON_CONCAT_LEFT(r22, "INSERT INTO ", v0);
			PHALCON_ALLOC_ZVAL_MM(r23);
			PHALCON_INIT_VAR(c2);
			ZVAL_STRING(c2, ", ", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r23, "join", c2, v1, 0x00F);
			PHALCON_ALLOC_ZVAL_MM(r21);
			PHALCON_CONCAT_VBOTH(r21, r22, " VALUES (", r23);
			PHALCON_ALLOC_ZVAL_MM(r24);
			PHALCON_CONCAT_RIGHT(r24, r21, ")");
			PHALCON_CPY_WRT(v4, r24);
		}
		PHALCON_ALLOC_ZVAL_MM(r25);
		Z_ADDREF_P(v4);
		p9[0] = v4;
		PHALCON_CALL_METHOD_PARAMS(r25, this_ptr, "query", 1, p9, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p9[0]);
		PHALCON_RETURN_DZVAL(r25);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p10[0]);
		ZVAL_STRING(p10[0], "The second parameter for insert isn't an Array", 1);
		PHALCON_INIT_VAR(p10[1]);
		ZVAL_LONG(p10[1], 0);
		PHALCON_INIT_VAR(p10[2]);
		ZVAL_BOOL(p10[2], 1);
		Z_ADDREF_P(this_ptr);
		p10[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 4, p10, PHALCON_CALL_CHECK);
		Z_DELREF_P(p10[3]);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Updates data on a table using custom RBDM SQL syntax
 *
 * 
 *
 * @param string $tables
 * @param array $fields
 * @param array $values
 * @param string $whereCondition
 * @param boolean $automaticQuotes
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, update){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL;
	zval *p2[] = { NULL, NULL, NULL, NULL }, *p8[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|zz", &v0, &v1, &v2, &v3, &v4) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v2);
	
	if (!v3) {
		PHALCON_INIT_VAR(v3);
		ZVAL_NULL(v3);
	}
	if (!v4) {
		PHALCON_INIT_VAR(v4);
		ZVAL_BOOL(v4, 0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_BOTH(r0,  "UPDATE ", v0, " SET ");
	PHALCON_CPY_WRT(v5, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "count", v1, 0x008);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "count", v2, 0x008);
	PHALCON_INIT_VAR(r3);
	is_not_equal_function(r3, r1, r2 TSRMLS_CC);
	if (zend_is_true(r3)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p2[0]);
		ZVAL_STRING(p2[0], "The number of values to update is not the same as fields", 1);
		PHALCON_INIT_VAR(p2[1]);
		ZVAL_LONG(p2[1], 0);
		PHALCON_INIT_VAR(p2[2]);
		ZVAL_BOOL(p2[2], 1);
		Z_ADDREF_P(this_ptr);
		p2[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p2, PHALCON_CALL_CHECK);
		Z_DELREF_P(p2[3]);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_INIT_VAR(v6);
	ZVAL_LONG(v6, 0);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v7, a0);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_e7f0_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_e7f0_2;
		}
		PHALCON_INIT_VAR(v8);
		ZVAL_ZVAL(v8, *hd, 1, 0);
		if (zend_is_true(v4)) {
			PHALCON_INIT_VAR(r4);
			phalcon_array_fetch(&r4, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (Z_TYPE_P(r4) == IS_OBJECT) {
				PHALCON_INIT_VAR(r5);
				phalcon_array_fetch(&r5, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_INIT_VAR(r6);
				phalcon_instance_of(r6, r5, phalcon_db_rawvalue_class_entry TSRMLS_CC);
				if (zend_is_true(r6)) {
					PHALCON_INIT_VAR(r7);
					PHALCON_INIT_VAR(r8);
					PHALCON_INIT_VAR(r9);
					phalcon_array_fetch(&r9, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_CALL_METHOD(r8, r9, "getvalue", PHALCON_CALL_DEFAULT);
					Z_ADDREF_P(r8);
					PHALCON_CALL_FUNC_PARAMS_1(r7, "addslashes", r8, 0x01F);
					Z_DELREF_P(r8);
					Z_ADDREF_P(r7);
					if (Z_REFCOUNT_P(v2) > 1) {
						zval *new_zv;
						Z_DELREF_P(v2);
						ALLOC_ZVAL(new_zv);
						INIT_PZVAL_COPY(new_zv, v2);
						v2 = new_zv;
						zval_copy_ctor(new_zv);
					}
					phalcon_array_update(v2, v6, r7 TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(r10);
					PHALCON_INIT_VAR(r11);
					phalcon_array_fetch(&r11, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r11);
					PHALCON_CALL_FUNC_PARAMS_1(r10, "addslashes", r11, 0x01F);
					Z_DELREF_P(r11);
					PHALCON_INIT_VAR(r12);
					PHALCON_CONCAT_BOTH(r12,  "'", r10, "'");
					Z_ADDREF_P(r12);
					if (Z_REFCOUNT_P(v2) > 1) {
						zval *new_zv;
						Z_DELREF_P(v2);
						ALLOC_ZVAL(new_zv);
						INIT_PZVAL_COPY(new_zv, v2);
						v2 = new_zv;
						zval_copy_ctor(new_zv);
					}
					phalcon_array_update(v2, v6, r12 TSRMLS_CC);
				}
			} else {
				PHALCON_INIT_VAR(r13);
				PHALCON_INIT_VAR(r14);
				phalcon_array_fetch(&r14, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r14);
				PHALCON_CALL_FUNC_PARAMS_1(r13, "addslashes", r14, 0x01F);
				Z_DELREF_P(r14);
				PHALCON_INIT_VAR(r15);
				PHALCON_CONCAT_BOTH(r15,  "'", r13, "'");
				Z_ADDREF_P(r15);
				if (Z_REFCOUNT_P(v2) > 1) {
					zval *new_zv;
					Z_DELREF_P(v2);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, v2);
					v2 = new_zv;
					zval_copy_ctor(new_zv);
				}
				phalcon_array_update(v2, v6, r15 TSRMLS_CC);
			}
		}
		PHALCON_INIT_VAR(r17);
		phalcon_array_fetch(&r17, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_INIT_VAR(r16);
		PHALCON_CONCAT_VBOTH(r16, v8, " = ", r17);
		Z_ADDREF_P(r16);
		PHALCON_SEPARATE_ARRAY(v7);
		phalcon_array_append(v7, r16 TSRMLS_CC);
		PHALCON_SEPARATE(v6);
		increment_function(v6);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_e7f0_2;
		fee_e7f0_2:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(r18);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, ", ", 1);
	PHALCON_CALL_FUNC_PARAMS_2(r18, "join", c0, v7, 0x00F);
	PHALCON_ALLOC_ZVAL_MM(r19);
	concat_function(r19, v5, r18 TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r19);
	PHALCON_INIT_VAR(t0);
	ZVAL_NULL(t0);
	PHALCON_INIT_VAR(r20);
	is_not_equal_function(r20, v3, t0 TSRMLS_CC);
	if (zend_is_true(r20)) {
		PHALCON_ALLOC_ZVAL_MM(r21);
		PHALCON_CONCAT_LEFT(r21, " WHERE ", v3);
		PHALCON_ALLOC_ZVAL_MM(r22);
		concat_function(r22, v5, r21 TSRMLS_CC);
		PHALCON_CPY_WRT(v5, r22);
	}
	PHALCON_ALLOC_ZVAL_MM(r23);
	Z_ADDREF_P(v5);
	p8[0] = v5;
	PHALCON_CALL_METHOD_PARAMS(r23, this_ptr, "query", 1, p8, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p8[0]);
	PHALCON_RETURN_DZVAL(r23);
}

/**
 * Deletes data from a table using custom RBDM SQL syntax
 *
 * 
 *
 * @param string $tables
 * @param string $whereCondition
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, delete){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "trim", v1, 0x020);
	Z_DELREF_P(v1);
	if (!PHALCON_COMPARE_STRING(r0, "")) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_LEFT(r3, "DELETE FROM ", v0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_VBOTH(r2, r3, " WHERE ", v1);
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
		PHALCON_RETURN_DZVAL(r1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_LEFT(r5, "DELETE FROM ", v0);
		Z_ADDREF_P(r5);
		p2[0] = r5;
		PHALCON_CALL_METHOD_PARAMS(r4, this_ptr, "query", 1, p2, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p2[0]);
		PHALCON_RETURN_DZVAL(r4);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
     * Starts a transaction in the connection
     *
     * @return boolean
     */
PHP_METHOD(Phalcon_Db, begin){

	zval *r0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 0 TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], "BEGIN", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
	PHALCON_RETURN_DZVAL(r0);
}

/**
     * Rollbacks the active transaction in the connection
     *
     * @return boolean
     */
PHP_METHOD(Phalcon_Db, rollback){

	zval *t0 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 0 TSRMLS_CC);
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "ROLLBACK", 1);
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
		PHALCON_RETURN_DZVAL(r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "There is not an active transaction on relational manager", 1);
		PHALCON_INIT_VAR(p1[1]);
		ZVAL_LONG(p1[1], 0);
		PHALCON_INIT_VAR(p1[2]);
		ZVAL_BOOL(p1[2], 1);
		Z_ADDREF_P(this_ptr);
		p1[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[3]);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
     * Commits the active transaction in the connection
     *
     * @return boolean
     */
PHP_METHOD(Phalcon_Db, commit){

	zval *t0 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 0 TSRMLS_CC);
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "COMMIT", 1);
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
		PHALCON_RETURN_DZVAL(r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "There is not an active transaction on relational manager", 1);
		PHALCON_INIT_VAR(p1[1]);
		ZVAL_LONG(p1[1], 0);
		PHALCON_INIT_VAR(p1[2]);
		ZVAL_BOOL(p1[2], 1);
		Z_ADDREF_P(this_ptr);
		p1[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[3]);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Manually sets a "under transaction" state for the connection
 *
 * @param boolean $underTransaction
 */
PHP_METHOD(Phalcon_Db, setUnderTransaction){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_underTransaction", strlen("_underTransaction"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Checks whether connection is under database transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, isUnderTransaction){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Checks whether connection have auto commit
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db, getHaveAutoCommit){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_autoCommit", sizeof("_autoCommit")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns database name in the internal connection
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db, getDatabaseName){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_isset_property(t0, "name", strlen("name") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, t1, "name", sizeof("name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t2);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_STRING("", 1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns active schema name in the internal connection
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db, getDefaultSchema){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_isset_property(t0, "schema", strlen("schema") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, t1, "schema", sizeof("schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_isset_property(t3, "name", strlen("name") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_read_property(&t4, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(t5);
			phalcon_read_property(&t5, t4, "name", sizeof("name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_RETURN_CHECK_CTOR(t5);
		} else {
			PHALCON_MM_RESTORE();
			RETURN_STRING("", 1);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the username which has connected to the database
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db, getUsername){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_isset_property(t0, "username", strlen("username") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, t1, "username", sizeof("username")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t2);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_STRING("", 1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the username which has connected to the database
     *
 * @return string
 */
PHP_METHOD(Phalcon_Db, getHostName){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_isset_property(t0, "host", strlen("host") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, t1, "host", sizeof("host")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t2);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_STRING("", 1);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets an active connection unique identifier
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db, getConnectionId){

	zval *v0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_BOOL(v0, 0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * This method is executed before every SQL statement sended to the database system
 *
 * @param string $sqlStatement
 */
PHP_METHOD(Phalcon_Db, _beforeQuery){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_LEFT(r1, "[", t2);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, r1, "] ", v0);
		Z_ADDREF_P(r0);
		p0[0] = r0;
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_get_class_constant(t3, phalcon_logger_class_entry, "DEBUG", strlen("DEBUG") TSRMLS_CC);
		Z_ADDREF_P(t3);
		p0[1] = t3;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "log", 2, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
		Z_DELREF_P(p0[1]);
	}
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, "_profiler", sizeof("_profiler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t4)) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property(&t5, this_ptr, "_profiler", sizeof("_profiler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v0);
		p1[0] = v0;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t5, "startprofile", 1, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * This method is executed after every SQL statement sended to the database system
 *
 * @param string $sqlStatement
 */
PHP_METHOD(Phalcon_Db, _afterQuery){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_profiler", sizeof("_profiler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_profiler", sizeof("_profiler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v0);
		p0[0] = v0;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "stopprofile", 1, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Instantiates Phalcon_Db adapter using given parameters
 *
 * @param string $adapterName
 * @param stdClass $options
 * @param boolean $persistent
 * @return Phalcon_Db
 */
PHP_METHOD(Phalcon_Db, factory){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL, *i4 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL, NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_BOOL(v2, 0);
	}
	
	if (PHALCON_COMPARE_STRING(v0, "")) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "A valid adapter name is required", 1);
		PHALCON_INIT_VAR(p0[1]);
		ZVAL_LONG(p0[1], 0);
		PHALCON_INIT_VAR(p0[2]);
		ZVAL_BOOL(p0[2], 1);
		PHALCON_INIT_VAR(p0[3]);
		ZVAL_NULL(p0[3]);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p0, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(v1) != IS_ARRAY) { 
		if (Z_TYPE_P(v1) != IS_OBJECT) {
			PHALCON_ALLOC_ZVAL_MM(i1);
			object_init_ex(i1, phalcon_db_exception_class_entry);
			PHALCON_INIT_VAR(p1[0]);
			ZVAL_STRING(p1[0], "The parameter 'options' must be an Array or Object", 1);
			PHALCON_INIT_VAR(p1[1]);
			ZVAL_LONG(p1[1], 0);
			PHALCON_INIT_VAR(p1[2]);
			ZVAL_BOOL(p1[2], 1);
			PHALCON_INIT_VAR(p1[3]);
			ZVAL_NULL(p1[3]);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 4, p1, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i1 TSRMLS_CC);
			Z_ADDREF_P(i1);
			PHALCON_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(i2);
		object_init(i2);
		PHALCON_CPY_WRT(v3, i2);
		if (Z_TYPE_P(v1) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v1);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_e7f0_3:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_e7f0_3;
			} else {
				PHALCON_INIT_VAR(v5);
				htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
				if (htype == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(v5, index, index_len-1, 1);
				} else {
					if (htype == HASH_KEY_IS_LONG) {
						ZVAL_LONG(v5, num);
					}
				}
			}
			PHALCON_INIT_VAR(v4);
			ZVAL_ZVAL(v4, *hd, 1, 0);
			phalcon_update_property_zval(v3, Z_STRVAL_P(v5), Z_STRLEN_P(v5), v4 TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_e7f0_3;
			fee_e7f0_3:
			if(0){ };
		}
	} else {
		PHALCON_CPY_WRT(v3, v1);
	}
	eval_int = phalcon_isset_property(v3, "layer", strlen("layer") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, v3, "layer", sizeof("layer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v6, t0);
	} else {
		PHALCON_INIT_VAR(v6);
		ZVAL_STRING(v6, "native", 1);
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Db_Adapter_", v0);
	PHALCON_CPY_WRT(v7, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v7);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", v7, 0x000);
	Z_DELREF_P(v7);
	if (zend_is_true(r1)) {
		ce0 = zend_fetch_class(Z_STRVAL_P(v7), Z_STRLEN_P(v7), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i3);
		object_init_ex(i3, ce0);
		Z_ADDREF_P(v3);
		p3[0] = v3;
		Z_ADDREF_P(v2);
		p3[1] = v2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 2, p3, PHALCON_CALL_CHECK);
		Z_DELREF_P(p3[0]);
		Z_DELREF_P(p3[1]);
		PHALCON_RETURN_CTOR(i3);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i4);
		object_init_ex(i4, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Database adapter class ", v7, " was not found");
		Z_ADDREF_P(r2);
		p4[0] = r2;
		PHALCON_INIT_VAR(p4[1]);
		ZVAL_LONG(p4[1], 0);
		PHALCON_INIT_VAR(p4[2]);
		ZVAL_BOOL(p4[2], 1);
		PHALCON_INIT_VAR(p4[3]);
		ZVAL_NULL(p4[3]);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i4, "__construct", 4, p4, PHALCON_CALL_CHECK);
		Z_DELREF_P(p4[0]);
		zend_throw_exception_object(i4 TSRMLS_CC);
		Z_ADDREF_P(i4);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

