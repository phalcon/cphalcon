
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
 * Because Phalcon_Model requires meta-data as field names, data types, primary keys, etc.
 * Phalcon_Model_MetaData recopiles them and store for further querying by Phalcon_Model_Base.
 * This component can also be used to store metadata adapters temporarily or permanently.
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
 */
PHP_METHOD(Phalcon_Model_MetaData, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *i0 = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "Memory", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Model_MetaData_", v0);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", v1, 0x000);
	Z_DELREF_P(v1);
	if (zend_is_true(r1)) {
		ce0 = zend_fetch_class(Z_STRVAL_P(v1), Z_STRLEN_P(v1), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, ce0);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_update_property_zval(this_ptr, "_adapter", strlen("_adapter"), i0 TSRMLS_CC);
	} else {
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_MetaData, _initializeMetaData){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL, *v13 = NULL;
	zval *v14 = NULL, *v15 = NULL, *v16 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *p2[] = { NULL, NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL }, *p6[] = { NULL, NULL }, *p7[] = { NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_array_fetch(&t2, t0, v2, PHALCON_SILENT_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_array_fetch(&t1, t2, v1, PHALCON_SILENT_FETCH TSRMLS_CC);
	if (!zend_is_true(t1)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, v0, "getconnection", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v3, r0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, v0, "isview", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v4, r1);
		if (!zend_is_true(v4)) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			Z_ADDREF_P(v1);
			p2[0] = v1;
			Z_ADDREF_P(v2);
			p2[1] = v2;
			PHALCON_CALL_METHOD_PARAMS(r2, v3, "tableexists", 2, p2, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p2[0]);
			Z_DELREF_P(p2[1]);
			PHALCON_CPY_WRT(v5, r2);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r3);
			Z_ADDREF_P(v1);
			p3[0] = v1;
			Z_ADDREF_P(v2);
			p3[1] = v2;
			PHALCON_CALL_METHOD_PARAMS(r3, v3, "viewexists", 2, p3, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p3[0]);
			Z_DELREF_P(p3[1]);
			PHALCON_CPY_WRT(v5, r3);
		}
		if (!zend_is_true(v5)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_model_exception_class_entry);
			PHALCON_ALLOC_ZVAL_MM(r6);
			PHALCON_CONCAT_LEFT(r6, "Table \"", v2);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CONCAT_VBOTH(r5, r6, "\".\"", v1);
			PHALCON_ALLOC_ZVAL_MM(r7);
			PHALCON_CALL_FUNC_PARAMS_1(r7, "get_class", v0, 0x049);
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CONCAT_VBOTH(r4, r5, "\" doesn't exist on database when dumping information for ", r7);
			Z_ADDREF_P(r4);
			p4[0] = r4;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
			Z_DELREF_P(p4[0]);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			PHALCON_MM_RESTORE();
			return;
		} else {
			if (zend_is_true(v4)) {
				PHALCON_ALLOC_ZVAL_MM(r8);
				Z_ADDREF_P(v1);
				p6[0] = v1;
				Z_ADDREF_P(v2);
				p6[1] = v2;
				PHALCON_CALL_METHOD_PARAMS(r8, v3, "describeview", 2, p6, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p6[0]);
				Z_DELREF_P(p6[1]);
				PHALCON_CPY_WRT(v6, r8);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r9);
				Z_ADDREF_P(v1);
				p7[0] = v1;
				Z_ADDREF_P(v2);
				p7[1] = v2;
				PHALCON_CALL_METHOD_PARAMS(r9, v3, "describetable", 2, p7, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p7[0]);
				Z_DELREF_P(p7[1]);
				PHALCON_CPY_WRT(v6, r9);
			}
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			PHALCON_CPY_WRT(v7, a0);
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_CPY_WRT(v8, a1);
			PHALCON_INIT_VAR(a2);
			array_init(a2);
			PHALCON_CPY_WRT(v9, a2);
			PHALCON_INIT_VAR(a3);
			array_init(a3);
			PHALCON_CPY_WRT(v10, a3);
			PHALCON_INIT_VAR(a4);
			array_init(a4);
			PHALCON_CPY_WRT(v11, a4);
			PHALCON_INIT_VAR(a5);
			array_init(a5);
			PHALCON_CPY_WRT(v12, a5);
			if (Z_TYPE_P(v6) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah0 = Z_ARRVAL_P(v6);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				fes_f5c6_0:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_f5c6_0;
				}
				PHALCON_INIT_VAR(v13);
				ZVAL_ZVAL(v13, *hd, 1, 0);
				PHALCON_INIT_VAR(r10);
				phalcon_array_fetch_string(&r10, v13, "Field", strlen("Field"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v14, r10);
				Z_ADDREF_P(v14);
				PHALCON_SEPARATE_ARRAY(v7);
				phalcon_array_append(v7, v14 TSRMLS_CC);
				PHALCON_INIT_VAR(r11);
				phalcon_array_fetch_string(&r11, v13, "Key", strlen("Key"), PHALCON_NOISY_FETCH TSRMLS_CC);
				if (PHALCON_COMPARE_STRING(r11, "PRI")) {
					Z_ADDREF_P(v14);
					PHALCON_SEPARATE_ARRAY(v8);
					phalcon_array_append(v8, v14 TSRMLS_CC);
				} else {
					Z_ADDREF_P(v14);
					PHALCON_SEPARATE_ARRAY(v9);
					phalcon_array_append(v9, v14 TSRMLS_CC);
				}
				PHALCON_INIT_VAR(r12);
				phalcon_array_fetch_string(&r12, v13, "Type", strlen("Type"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v15, r12);
				Z_ADDREF_P(v15);
				if (Z_REFCOUNT_P(v12) > 1) {
					zval *new_zv;
					Z_DELREF_P(v12);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, v12);
					v12 = new_zv;
					zval_copy_ctor(new_zv);
				}
				phalcon_array_update(v12, v14, v15 TSRMLS_CC);
				PHALCON_INIT_VAR(r13);
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, "int", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r13, "strpos", v15, c0, 0x005);
				if (Z_TYPE_P(r13) != IS_BOOL || (Z_TYPE_P(r13) == IS_BOOL && Z_BVAL_P(r13))) {
					PHALCON_INIT_VAR(t3);
					ZVAL_BOOL(t3, 1);
					Z_ADDREF_P(t3);
					if (Z_REFCOUNT_P(v10) > 1) {
						zval *new_zv;
						Z_DELREF_P(v10);
						ALLOC_ZVAL(new_zv);
						INIT_PZVAL_COPY(new_zv, v10);
						v10 = new_zv;
						zval_copy_ctor(new_zv);
					}
					phalcon_array_update(v10, v14, t3 TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(r14);
					PHALCON_INIT_VAR(c1);
					ZVAL_STRING(c1, "decimal", 1);
					PHALCON_CALL_FUNC_PARAMS_2(r14, "strpos", v15, c1, 0x005);
					if (Z_TYPE_P(r14) != IS_BOOL || (Z_TYPE_P(r14) == IS_BOOL && Z_BVAL_P(r14))) {
						PHALCON_INIT_VAR(t4);
						ZVAL_BOOL(t4, 1);
						Z_ADDREF_P(t4);
						if (Z_REFCOUNT_P(v10) > 1) {
							zval *new_zv;
							Z_DELREF_P(v10);
							ALLOC_ZVAL(new_zv);
							INIT_PZVAL_COPY(new_zv, v10);
							v10 = new_zv;
							zval_copy_ctor(new_zv);
						}
						phalcon_array_update(v10, v14, t4 TSRMLS_CC);
					}
				}
				PHALCON_INIT_VAR(r15);
				phalcon_array_fetch_string(&r15, v13, "Null", strlen("Null"), PHALCON_NOISY_FETCH TSRMLS_CC);
				if (PHALCON_COMPARE_STRING(r15, "NO")) {
					Z_ADDREF_P(v14);
					PHALCON_SEPARATE_ARRAY(v11);
					phalcon_array_append(v11, v14 TSRMLS_CC);
				}
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_f5c6_0;
				fee_f5c6_0:
				if(0){ };
			}
			PHALCON_INIT_VAR(a6);
			array_init(a6);
			PHALCON_CPY_WRT(v16, a6);
			Z_ADDREF_P(v7);
			if (Z_REFCOUNT_P(v16) > 1) {
				zval *new_zv;
				Z_DELREF_P(v16);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v16);
				v16 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v16, 0, v7 TSRMLS_CC);
			Z_ADDREF_P(v8);
			if (Z_REFCOUNT_P(v16) > 1) {
				zval *new_zv;
				Z_DELREF_P(v16);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v16);
				v16 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v16, 1, v8 TSRMLS_CC);
			Z_ADDREF_P(v9);
			if (Z_REFCOUNT_P(v16) > 1) {
				zval *new_zv;
				Z_DELREF_P(v16);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v16);
				v16 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v16, 2, v9 TSRMLS_CC);
			Z_ADDREF_P(v11);
			if (Z_REFCOUNT_P(v16) > 1) {
				zval *new_zv;
				Z_DELREF_P(v16);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v16);
				v16 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v16, 3, v11 TSRMLS_CC);
			Z_ADDREF_P(v12);
			if (Z_REFCOUNT_P(v16) > 1) {
				zval *new_zv;
				Z_DELREF_P(v16);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v16);
				v16 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v16, 4, v12 TSRMLS_CC);
			Z_ADDREF_P(v10);
			if (Z_REFCOUNT_P(v16) > 1) {
				zval *new_zv;
				Z_DELREF_P(v16);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v16);
				v16 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_long(v16, 5, v10 TSRMLS_CC);
			t5 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			if (Z_TYPE_P(t5) != IS_ARRAY) {
				convert_to_array(t5);
			}
			if (Z_TYPE_P(t5) == IS_ARRAY) {
				PHALCON_ALLOC_ZVAL_MM(t6);
				phalcon_array_fetch(&t6, t5, v2, PHALCON_SILENT_FETCH TSRMLS_CC);
			}
			if (Z_REFCOUNT_P(t6) > 1) {
				zval *new_zv;
				Z_DELREF_P(t6);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, t6);
				t6 = new_zv;
				zval_copy_ctor(new_zv);
				phalcon_array_update(t5, v2, t6 TSRMLS_CC);
			}
			Z_ADDREF_P(t6);
			if (Z_TYPE_P(t6) != IS_ARRAY) {
				convert_to_array(t6);
				phalcon_array_update(t5, v2, t6 TSRMLS_CC);
			}
			Z_ADDREF_P(v16);
			phalcon_array_update(t6, v1, v16 TSRMLS_CC);
			zend_update_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, t5 TSRMLS_CC);
			
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns table attributes name (fields)
 *
     * @paramPhalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
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
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_array_fetch(&t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_array_fetch(&t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_array_fetch(&t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Returns table attributes which are part of primary key
 *
 * @paramPhalcon_Model_Base $model
 * @returnarray
 */
PHP_METHOD(Phalcon_Model_MetaData, getPrimaryKeyAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
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
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_array_fetch(&t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_array_fetch(&t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 1);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_array_fetch(&t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Returns table attributes which are non part of primary key
 *
     * @paramPhalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getNonPrimaryKeyAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
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
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_array_fetch(&t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_array_fetch(&t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 2);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_array_fetch(&t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Returns not null attributes
 *
     * @paramPhalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getNotNullAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
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
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_array_fetch(&t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_array_fetch(&t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 3);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_array_fetch(&t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Returns attributes and their data types
 *
     * @paramPhalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getDataTypes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
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
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_array_fetch(&t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_array_fetch(&t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 4);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_array_fetch(&t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Returns attributes which types are numerical
 *
     * @param  Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getDataTypesNumeric){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
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
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_array_fetch(&t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_array_fetch(&t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 5);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_array_fetch(&t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

