
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
 * Phalcon_Model_Query
 *
 * Phalcon_Model_Query is designed to simplify building of search on models.
 * It provides a set of helpers to generate searchs in a dynamic way to support differents databases.
 *
 * 
 * 
 *
 */

/**
 * Phalcon_Model_Criteria constructor
 */
PHP_METHOD(Phalcon_Model_Query, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_model_query_class_entry, this_ptr, "_models", strlen("_models"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_model_query_class_entry, this_ptr, "_parameters", strlen("_parameters"), a1 TSRMLS_CC);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	zend_update_property(phalcon_model_query_class_entry, this_ptr, "_conditions", strlen("_conditions"), a2 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Set the data to use to make the conditions in query
 *
 * @param array $data
 */
PHP_METHOD(Phalcon_Model_Query, setInputData){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_data", strlen("_data"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Set the Phalcon_Model_Manager instance to use in query
 *
 * 
 *
 * @param Phalcon_Model_Manager $manager
 */
PHP_METHOD(Phalcon_Model_Query, setManager){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Add models to use in query
 *
 * @param Phalcon_Model_Base $model
 */
PHP_METHOD(Phalcon_Model_Query, from){

	zval *v0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	phalcon_array_append(t0, v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_models", strlen("_models"), t0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Add conditions to use in query
 *
 * @param string $condition
 */
PHP_METHOD(Phalcon_Model_Query, where){

	zval *v0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_conditions", sizeof("_conditions")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	phalcon_array_append(t0, v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_conditions", strlen("_conditions"), t0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Set parameter in query to different database adapters.
 *
 * @param string $parameter
 */
PHP_METHOD(Phalcon_Model_Query, setParameters){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_parameters", strlen("_parameters"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Set the limit of rows to show
 *
 * @param int $limit
 */
PHP_METHOD(Phalcon_Model_Query, setLimit){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_limit", strlen("_limit"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Query, getResultset){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Get the conditions of query
 *
 * @return string $query
 */
PHP_METHOD(Phalcon_Model_Query, getConditions){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL, *v13 = NULL;
	zval *v14 = NULL, *v15 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p6[] = { NULL }, *p7[] = { NULL }, *p9[] = { NULL }, *p10[] = { NULL };
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_STATIC(r0, "phalcon_controller_front", "getinstance");
		PHALCON_CPY_WRT(v0, r0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, v0, "getmodelcomponent", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v1, r1);
		Z_ADDREF_P(v1);
		p2[0] = v1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "setmanager", 1, p2, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p2[0]);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, t1);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t2) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(t2);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes97:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee97;
		}
		PHALCON_INIT_VAR(v2);
		ZVAL_ZVAL(v2, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		Z_ADDREF_P(v2);
		p3[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r2, v1, "getmodel", 1, p3, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p3[0]);
		PHALCON_CPY_WRT(v3, r2);
		PHALCON_INIT_VAR(t3);
		ZVAL_BOOL(t3, 0);
		PHALCON_INIT_VAR(r3);
		is_equal_function(r3, v3, t3 TSRMLS_CC);
		if (zend_is_true(r3)) {
			PHALCON_INIT_VAR(i0);
			object_init_ex(i0, phalcon_exception_class_entry);
			PHALCON_INIT_VAR(r4);
			PHALCON_CONCAT_BOTH(r4,  "The model ", v2, " not exist");
			Z_ADDREF_P(r4);
			p4[0] = r4;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
			Z_DELREF_P(p4[0]);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			PHALCON_MM_RESTORE();
			return;
		}
		PHALCON_INIT_VAR(r5);
		PHALCON_CALL_METHOD(r5, v1, "getmetadata", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v4, r5);
		PHALCON_INIT_VAR(r6);
		Z_ADDREF_P(v3);
		p6[0] = v3;
		PHALCON_CALL_METHOD_PARAMS(r6, v4, "getattributes", 1, p6, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p6[0]);
		PHALCON_CPY_WRT(v5, r6);
		PHALCON_INIT_VAR(r7);
		Z_ADDREF_P(v3);
		p7[0] = v3;
		PHALCON_CALL_METHOD_PARAMS(r7, v4, "getdatatypesnumeric", 1, p7, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p7[0]);
		PHALCON_CPY_WRT(v6, r7);
		PHALCON_INIT_VAR(v7);
		ZVAL_LONG(v7, 0);
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v8, a0);
		PHALCON_INIT_VAR(t4);
		phalcon_read_property(&t4, this_ptr, "_data", sizeof("_data")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(t4) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah1 = Z_ARRVAL_P(t4);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes98:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee98;
			} else {
				PHALCON_INIT_VAR(v10);
				htype = zend_hash_get_current_key_ex(ah1, &index, &index_len, &num, 0, &hp1);
				if (htype == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(v10, index, index_len-1, 1);
				} else {
					if (htype == HASH_KEY_IS_LONG) {
						ZVAL_LONG(v10, num);
					}
				}
			}
			PHALCON_INIT_VAR(v9);
			ZVAL_ZVAL(v9, *hd, 1, 0);
			PHALCON_INIT_VAR(r8);
			Z_ADDREF_P(v10);
			Z_ADDREF_P(v5);
			PHALCON_CALL_FUNC_PARAMS_2(r8, "in_array", v10, v5, 0x031);
			Z_DELREF_P(v10);
			Z_DELREF_P(v5);
			if (zend_is_true(r8)) {
				PHALCON_INIT_VAR(t5);
				ZVAL_STRING(t5, "@", 1);
				PHALCON_INIT_VAR(r9);
				is_not_equal_function(r9, v9, t5 TSRMLS_CC);
				PHALCON_INIT_VAR(r10);
				phalcon_and_function(r10, v9, r9);
				if (zend_is_true(r10)) {
					eval_int = phalcon_array_isset(v6, v10);
					if (eval_int) {
						PHALCON_INIT_VAR(r11);
						PHALCON_CONCAT_VBOTH(r11, v10, " = ?", v7);
						PHALCON_CPY_WRT(v11, r11);
						Z_ADDREF_P(v9);
						if (Z_REFCOUNT_P(v8) > 1) {
							zval *new_zv;
							Z_DELREF_P(v8);
							ALLOC_ZVAL(new_zv);
							INIT_PZVAL_COPY(new_zv, v8);
							v8 = new_zv;
							zval_copy_ctor(new_zv);
						}
						phalcon_array_update(v8, v7, v9 TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r12);
						PHALCON_CONCAT_VBOTH(r12, v10, " LIKE ?", v7);
						PHALCON_CPY_WRT(v11, r12);
						PHALCON_INIT_VAR(r13);
						PHALCON_CONCAT_BOTH(r13,  "%", v9, "%");
						Z_ADDREF_P(r13);
						if (Z_REFCOUNT_P(v8) > 1) {
							zval *new_zv;
							Z_DELREF_P(v8);
							ALLOC_ZVAL(new_zv);
							INIT_PZVAL_COPY(new_zv, v8);
							v8 = new_zv;
							zval_copy_ctor(new_zv);
						}
						phalcon_array_update(v8, v7, r13 TSRMLS_CC);
					}
					Z_ADDREF_P(v11);
					p9[0] = v11;
					PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "where", 1, p9, PHALCON_CALL_DEFAULT);
					Z_DELREF_P(p9[0]);
				}
			}
			PHALCON_SEPARATE(v7);
			increment_function(v7);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes98;
			fee98:
			if(0){ };
		}
		Z_ADDREF_P(v8);
		p10[0] = v8;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "setparameters", 1, p10, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p10[0]);
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_CPY_WRT(v12, a1);
		PHALCON_INIT_VAR(t6);
		phalcon_read_property(&t6, this_ptr, "_parameters", sizeof("_parameters")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v8, t6);
		PHALCON_INIT_VAR(t7);
		phalcon_read_property(&t7, this_ptr, "_conditions", sizeof("_conditions")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(t7) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah2 = Z_ARRVAL_P(t7);
			zend_hash_internal_pointer_reset_ex(ah2, &hp2);
			fes99:
			if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
				goto fee99;
			}
			PHALCON_INIT_VAR(v11);
			ZVAL_ZVAL(v11, *hd, 1, 0);
			PHALCON_INIT_VAR(r14);
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "?", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r14, "explode", c0, v11, 0x002);
			PHALCON_CPY_WRT(v13, r14);
			PHALCON_INIT_VAR(r15);
			phalcon_array_fetch_long(&r15, v13, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v14, r15);
			PHALCON_INIT_VAR(r16);
			phalcon_array_fetch(&r16, v8, v14, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v9, r16);
			if (zend_is_true(v9)) {
				PHALCON_INIT_VAR(r18);
				phalcon_array_fetch_long(&r18, v13, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_INIT_VAR(r17);
				PHALCON_CONCAT_VBOTH(r17, r18, " '", v9);
				PHALCON_INIT_VAR(r19);
				PHALCON_CONCAT_RIGHT(r19, r17, "'");
				Z_ADDREF_P(r19);
				PHALCON_SEPARATE_ARRAY(v12);
				phalcon_array_append(v12, r19 TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah2, &hp2);
			goto fes99;
			fee99:
			if(0){ };
		}
		PHALCON_INIT_VAR(r20);
		PHALCON_CALL_FUNC_PARAMS_1(r20, "count", v12, 0x008);
		if (!zend_is_true(r20)) {
			PHALCON_INIT_VAR(v15);
			ZVAL_STRING(v15, "1=1", 1);
		} else {
			PHALCON_INIT_VAR(r21);
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, " AND ", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r21, "join", c1, v12, 0x00D);
			PHALCON_CPY_WRT(v15, r21);
		}
		PHALCON_RETURN_CTOR(v15);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes97;
		fee97:
		if(0){ };
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Get instace of model query
 *
 * @param string $modelName
 * @param array $data
 * @return Phalcon_Model_Query $query
 */
PHP_METHOD(Phalcon_Model_Query, fromInput){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_model_query_class_entry);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	PHALCON_CPY_WRT(v2, i0);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "from", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	Z_ADDREF_P(v1);
	p2[0] = v1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setinputdata", 1, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	PHALCON_RETURN_CTOR(v2);
}

