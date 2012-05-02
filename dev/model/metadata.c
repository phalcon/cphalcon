
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
 * Phalcon_Model_MetaData
 *
 * Because Phalcon_Model requires meta-data like field names, data types, primary keys, etc.
 * Phalcon_Model_MetaData recopiles them and store for further querying by Phalcon_Model_Base.
 * This component can also use adapters to store temporarily or permanently the meta-data.
 *
 * A standard Phalcon_Model_MetaData can be used to query model attributes:
 *
 * 
 *
 */

/**
 * Phalcon_Model_MetaData constructor
 *
 * @param string $adapter
 * @param array $options
 */
PHP_METHOD(Phalcon_Model_MetaData, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p4[] = { NULL };
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v1, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Model_MetaData_", v0);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", v2, 0x00F);
	Z_DELREF_P(v2);
	if (zend_is_true(r1)) {
		ce0 = zend_fetch_class(Z_STRVAL_P(v2), Z_STRLEN_P(v2), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, ce0);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		PHALCON_CPY_WRT(v3, i0);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, v3, "read", PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "_metaData", strlen("_metaData"), r2 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_adapter", strlen("_adapter"), v3 TSRMLS_CC);
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		Z_ADDREF_P(this_ptr);
		PHALCON_SEPARATE_ARRAY(a1);
		add_next_index_zval(a1, this_ptr);
		add_next_index_stringl(a1, "storeMetaData", strlen("storeMetaData"), 1);
		PHALCON_CALL_FUNC_PARAMS_1_NORETURN("register_shutdown_function", a1, 0x043);
	} else {
		ce1 = zend_fetch_class("phacon_model_exception", strlen("phacon_model_exception"), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, ce1);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "Meta-data adapter '", v0, "' could not found");
		Z_ADDREF_P(r3);
		p4[0] = r3;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p4, PHALCON_CALL_CHECK);
		Z_DELREF_P(p4[0]);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_MetaData, _initializeMetaData){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL, *v13 = NULL;
	zval *v14 = NULL, *v15 = NULL, *v16 = NULL, *v17 = NULL, *v18 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *p2[] = { NULL, NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL }, *p6[] = { NULL, NULL }, *p7[] = { NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, v2, v1 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, v3);
	PHALCON_INIT_VAR(r1);
	ZVAL_BOOL(r1, eval_int);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, v0, "getconnection", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v4, r2);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_METHOD(r3, v0, "isview", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v5, r3);
		if (!zend_is_true(v5)) {
			PHALCON_ALLOC_ZVAL_MM(r4);
			Z_ADDREF_P(v1);
			p2[0] = v1;
			Z_ADDREF_P(v2);
			p2[1] = v2;
			PHALCON_CALL_METHOD_PARAMS(r4, v4, "tableexists", 2, p2, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p2[0]);
			Z_DELREF_P(p2[1]);
			PHALCON_CPY_WRT(v6, r4);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r5);
			Z_ADDREF_P(v1);
			p3[0] = v1;
			Z_ADDREF_P(v2);
			p3[1] = v2;
			PHALCON_CALL_METHOD_PARAMS(r5, v4, "viewexists", 2, p3, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p3[0]);
			Z_DELREF_P(p3[1]);
			PHALCON_CPY_WRT(v6, r5);
		}
		if (!zend_is_true(v6)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_model_exception_class_entry);
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_CONCAT_LEFT(r8, "Table \"", v2);
			PHALCON_ALLOC_ZVAL_MM(r7);
			PHALCON_CONCAT_VBOTH(r7, r8, "\".\"", v1);
			PHALCON_ALLOC_ZVAL_MM(r9);
			PHALCON_CALL_FUNC_PARAMS_1(r9, "get_class", v0, 0x02F);
			PHALCON_ALLOC_ZVAL_MM(r6);
			PHALCON_CONCAT_VBOTH(r6, r7, "\" doesn't exist on database when dumping information for ", r9);
			Z_ADDREF_P(r6);
			p4[0] = r6;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
			Z_DELREF_P(p4[0]);
			return phalcon_throw_exception(i0 TSRMLS_CC);
		} else {
			if (zend_is_true(v5)) {
				PHALCON_ALLOC_ZVAL_MM(r10);
				Z_ADDREF_P(v1);
				p6[0] = v1;
				Z_ADDREF_P(v2);
				p6[1] = v2;
				PHALCON_CALL_METHOD_PARAMS(r10, v4, "describeview", 2, p6, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p6[0]);
				Z_DELREF_P(p6[1]);
				PHALCON_CPY_WRT(v7, r10);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r11);
				Z_ADDREF_P(v1);
				p7[0] = v1;
				Z_ADDREF_P(v2);
				p7[1] = v2;
				PHALCON_CALL_METHOD_PARAMS(r11, v4, "describetable", 2, p7, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p7[0]);
				Z_DELREF_P(p7[1]);
				PHALCON_CPY_WRT(v7, r11);
			}
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			PHALCON_CPY_WRT(v8, a0);
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_CPY_WRT(v9, a1);
			PHALCON_INIT_VAR(a2);
			array_init(a2);
			PHALCON_CPY_WRT(v10, a2);
			PHALCON_INIT_VAR(a3);
			array_init(a3);
			PHALCON_CPY_WRT(v11, a3);
			PHALCON_INIT_VAR(a4);
			array_init(a4);
			PHALCON_CPY_WRT(v12, a4);
			PHALCON_INIT_VAR(a5);
			array_init(a5);
			PHALCON_CPY_WRT(v13, a5);
			PHALCON_INIT_VAR(v14);
			ZVAL_BOOL(v14, 0);
			if (Z_TYPE_P(v7) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah0 = Z_ARRVAL_P(v7);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				fes_f5c6_0:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_f5c6_0;
				}
				PHALCON_INIT_VAR(v15);
				ZVAL_ZVAL(v15, *hd, 1, 0);
				PHALCON_INIT_VAR(r12);
				phalcon_array_fetch_string(&r12, v15, "Field", strlen("Field"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v16, r12);
				Z_ADDREF_P(v16);
				PHALCON_SEPARATE_ARRAY(v8);
				phalcon_array_append(v8, v16 TSRMLS_CC);
				PHALCON_INIT_VAR(r13);
				phalcon_array_fetch_string(&r13, v15, "Key", strlen("Key"), PHALCON_NOISY_FETCH TSRMLS_CC);
				if (PHALCON_COMPARE_STRING(r13, "PRI")) {
					Z_ADDREF_P(v16);
					PHALCON_SEPARATE_ARRAY(v9);
					phalcon_array_append(v9, v16 TSRMLS_CC);
				} else {
					Z_ADDREF_P(v16);
					PHALCON_SEPARATE_ARRAY(v10);
					phalcon_array_append(v10, v16 TSRMLS_CC);
				}
				PHALCON_INIT_VAR(r14);
				phalcon_array_fetch_string(&r14, v15, "Type", strlen("Type"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v17, r14);
				Z_ADDREF_P(v17);
				if (Z_REFCOUNT_P(v13) > 1) {
					zval *new_zv;
					Z_DELREF_P(v13);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, v13);
					v13 = new_zv;
					zval_copy_ctor(new_zv);
				}
				phalcon_array_update(v13, v16, v17 TSRMLS_CC);
				PHALCON_INIT_VAR(r15);
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, "int", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r15, "strpos", v17, c0, 0x00A);
				if (Z_TYPE_P(r15) != IS_BOOL || (Z_TYPE_P(r15) == IS_BOOL && Z_BVAL_P(r15))) {
					PHALCON_INIT_VAR(t1);
					ZVAL_BOOL(t1, 1);
					Z_ADDREF_P(t1);
					if (Z_REFCOUNT_P(v11) > 1) {
						zval *new_zv;
						Z_DELREF_P(v11);
						ALLOC_ZVAL(new_zv);
						INIT_PZVAL_COPY(new_zv, v11);
						v11 = new_zv;
						zval_copy_ctor(new_zv);
					}
					phalcon_array_update(v11, v16, t1 TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(r16);
					PHALCON_INIT_VAR(c1);
					ZVAL_STRING(c1, "decimal", 1);
					PHALCON_CALL_FUNC_PARAMS_2(r16, "strpos", v17, c1, 0x00A);
					if (Z_TYPE_P(r16) != IS_BOOL || (Z_TYPE_P(r16) == IS_BOOL && Z_BVAL_P(r16))) {
						PHALCON_INIT_VAR(t2);
						ZVAL_BOOL(t2, 1);
						Z_ADDREF_P(t2);
						if (Z_REFCOUNT_P(v11) > 1) {
							zval *new_zv;
							Z_DELREF_P(v11);
							ALLOC_ZVAL(new_zv);
							INIT_PZVAL_COPY(new_zv, v11);
							v11 = new_zv;
							zval_copy_ctor(new_zv);
						}
						phalcon_array_update(v11, v16, t2 TSRMLS_CC);
					}
				}
				PHALCON_INIT_VAR(r17);
				phalcon_array_fetch_string(&r17, v15, "Null", strlen("Null"), PHALCON_NOISY_FETCH TSRMLS_CC);
				if (PHALCON_COMPARE_STRING(r17, "NO")) {
					Z_ADDREF_P(v16);
					PHALCON_SEPARATE_ARRAY(v12);
					phalcon_array_append(v12, v16 TSRMLS_CC);
				}
				PHALCON_INIT_VAR(r18);
				phalcon_array_fetch_string(&r18, v15, "Extra", strlen("Extra"), PHALCON_NOISY_FETCH TSRMLS_CC);
				if (PHALCON_COMPARE_STRING(r18, "auto_increment")) {
					PHALCON_CPY_WRT(v14, v16);
				}
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_f5c6_0;
				fee_f5c6_0:
				if(0){ };
			}
			PHALCON_INIT_VAR(a6);
			array_init(a6);
			PHALCON_CPY_WRT(v18, a6);
			Z_ADDREF_P(v8);
			if (Z_REFCOUNT_P(v18) > 1) {
				zval *new_zv;
				Z_DELREF_P(v18);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v18);
				v18 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v18, 0, v8 TSRMLS_CC);
			Z_ADDREF_P(v9);
			if (Z_REFCOUNT_P(v18) > 1) {
				zval *new_zv;
				Z_DELREF_P(v18);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v18);
				v18 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v18, 1, v9 TSRMLS_CC);
			Z_ADDREF_P(v10);
			if (Z_REFCOUNT_P(v18) > 1) {
				zval *new_zv;
				Z_DELREF_P(v18);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v18);
				v18 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v18, 2, v10 TSRMLS_CC);
			Z_ADDREF_P(v12);
			if (Z_REFCOUNT_P(v18) > 1) {
				zval *new_zv;
				Z_DELREF_P(v18);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v18);
				v18 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v18, 3, v12 TSRMLS_CC);
			Z_ADDREF_P(v13);
			if (Z_REFCOUNT_P(v18) > 1) {
				zval *new_zv;
				Z_DELREF_P(v18);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v18);
				v18 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v18, 4, v13 TSRMLS_CC);
			Z_ADDREF_P(v11);
			if (Z_REFCOUNT_P(v18) > 1) {
				zval *new_zv;
				Z_DELREF_P(v18);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v18);
				v18 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v18, 5, v11 TSRMLS_CC);
			Z_ADDREF_P(v14);
			if (Z_REFCOUNT_P(v18) > 1) {
				zval *new_zv;
				Z_DELREF_P(v18);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v18);
				v18 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v18, 8, v14 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(t3);
			phalcon_read_property(&t3, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(v18);
			phalcon_array_update(t3, v3, v18 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_metaData", strlen("_metaData"), t3 TSRMLS_CC);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns table attributes names (fields)
 *
     * @paramPhalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r1);
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_DELREF_P(p2[2]);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, v2, v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns table attributes which are part of primary key
 *
 * @paramPhalcon_Model_Base $model
 * @returnarray
 */
PHP_METHOD(Phalcon_Model_MetaData, getPrimaryKeyAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r1);
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_DELREF_P(p2[2]);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, v2, v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns table attributes which are not part of primary key
 *
     * @paramPhalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getNonPrimaryKeyAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r1);
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_DELREF_P(p2[2]);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, v2, v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns not null attributes
 *
     * @paramPhalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getNotNullAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r1);
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_DELREF_P(p2[2]);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, v2, v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 3, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns attributes and their data types
 *
     * @paramPhalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getDataTypes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r1);
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_DELREF_P(p2[2]);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, v2, v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 4, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns attributes which types are numerical
 *
     * @param  Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getDataTypesNumeric){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r1);
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_DELREF_P(p2[2]);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, v2, v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 5, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns the name of identity field (if one is present)
 *
 * @param  Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getIdentityField){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r1);
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	Z_DELREF_P(p2[2]);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, v2, v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 8, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/** 
 * Stores meta-data using an adapter
 */
PHP_METHOD(Phalcon_Model_MetaData, storeMetaData){

	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t1);
	p0[0] = t1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(t0, "write", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

