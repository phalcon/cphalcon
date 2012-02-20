
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
 * Php_Model_MetaData
 *
 * <p>Because Php_Model requires meta-data as field names, data types, primary keys, etc.
 * Php_Model_MetaData recopiles them and store for further querying by Php_Model_Base.
 * This component can also be used to store metadata adapters temporarily or permanently.</p>
 *
 * <p>A standard Php_Model_MetaData can be used to query model attributes:</p>
 *
 * 
 *
 */

/**
 * Php_Model_MetaData constructor
 *
 * @param string $adapter
 */
PHP_METHOD(Phalcon_Model_MetaData, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };
	zend_class_entry *ce0;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "Memory", 0);
	}
	
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_concat_left(r0, "Phalcon_Model_MetaData_", v0 TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	PHALCON_ALLOC_ZVAL(r1);
	Z_ADDREF_P(v1);
	p0[0] = v1;
	PHALCON_CALL_FUNC_PARAMS(r1, "class_exists", 1, p0);
	if (zend_is_true(r1)) {
		ce0 = zend_fetch_class(Z_STRVAL_P(v1), Z_STRLEN_P(v1), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, ce0);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, i0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_adapter", strlen("_adapter"), copy TSRMLS_CC);
		}
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_MetaData, _initializeMetaData){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL, *v13 = NULL;
	zval *v14 = NULL, *v15 = NULL, *v16 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *ac0 = NULL;
	zval *p2[] = { NULL, NULL }, *p3[] = { NULL, NULL }, *p5[] = { NULL }, *p4[] = { NULL }, *p6[] = { NULL, NULL }, *p7[] = { NULL, NULL }, *p8[] = { NULL, NULL }, *p9[] = { NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_array_fetch(t2, t0, v2, PHALCON_SILENT_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t2, v1, PHALCON_SILENT_FETCH TSRMLS_CC);
	if (!zend_is_true(t1)) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CALL_METHOD(r0, v0, "getconnection", PHALCON_CALL_DEFAULT);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r0);
		v3 = r0;
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_CALL_METHOD(r1, v0, "isview", PHALCON_CALL_DEFAULT);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r1);
		v4 = r1;
		if (!zend_is_true(v4)) {
			PHALCON_ALLOC_ZVAL(r2);
			Z_ADDREF_P(v1);
			p2[0] = v1;
			Z_ADDREF_P(v2);
			p2[1] = v2;
			PHALCON_CALL_METHOD_PARAMS(r2, v3, "tableexists", 2, p2, PHALCON_CALL_DEFAULT);
			if (v5) {
				Z_DELREF_P(v5);
				if (!Z_REFCOUNT_P(v5)) {
					FREE_ZVAL(v5);
				}
			}
			Z_ADDREF_P(r2);
			v5 = r2;
		} else {
			PHALCON_ALLOC_ZVAL(r3);
			Z_ADDREF_P(v1);
			p3[0] = v1;
			Z_ADDREF_P(v2);
			p3[1] = v2;
			PHALCON_CALL_METHOD_PARAMS(r3, v3, "viewexists", 2, p3, PHALCON_CALL_DEFAULT);
			if (v5) {
				Z_DELREF_P(v5);
				if (!Z_REFCOUNT_P(v5)) {
					FREE_ZVAL(v5);
				}
			}
			Z_ADDREF_P(r3);
			v5 = r3;
		}
		if (!zend_is_true(v5)) {
			PHALCON_ALLOC_ZVAL(i0);
			object_init_ex(i0, phalcon_model_exception_class_entry);
			PHALCON_ALLOC_ZVAL(r6);
			phalcon_concat_left(r6, "Table \"", v2 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r5);
			phalcon_concat_vboth(r5, r6, "\".\"", v1 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r7);
			p5[0] = v0;
			PHALCON_CALL_FUNC_PARAMS(r7, "get_class", 1, p5);
			PHALCON_ALLOC_ZVAL(r4);
			phalcon_concat_vboth(r4, r5, "\" doesn't exists on database when dumping information for ", r7 TSRMLS_CC);
			Z_ADDREF_P(r4);
			p4[0] = r4;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			return;
		} else {
			if (zend_is_true(v4)) {
				PHALCON_ALLOC_ZVAL(r8);
				Z_ADDREF_P(v1);
				p6[0] = v1;
				Z_ADDREF_P(v2);
				p6[1] = v2;
				PHALCON_CALL_METHOD_PARAMS(r8, v3, "describeview", 2, p6, PHALCON_CALL_DEFAULT);
				if (v6) {
					Z_DELREF_P(v6);
					if (!Z_REFCOUNT_P(v6)) {
						FREE_ZVAL(v6);
					}
				}
				Z_ADDREF_P(r8);
				v6 = r8;
			} else {
				PHALCON_ALLOC_ZVAL(r9);
				Z_ADDREF_P(v1);
				p7[0] = v1;
				Z_ADDREF_P(v2);
				p7[1] = v2;
				PHALCON_CALL_METHOD_PARAMS(r9, v3, "describetable", 2, p7, PHALCON_CALL_DEFAULT);
				if (v6) {
					Z_DELREF_P(v6);
					if (!Z_REFCOUNT_P(v6)) {
						FREE_ZVAL(v6);
					}
				}
				Z_ADDREF_P(r9);
				v6 = r9;
			}
			PHALCON_ALLOC_ZVAL(a0);
			array_init(a0);
			if (v7) {
				Z_DELREF_P(v7);
				if (!Z_REFCOUNT_P(v7)) {
					FREE_ZVAL(v7);
				}
			}
			Z_ADDREF_P(a0);
			v7 = a0;
			PHALCON_ALLOC_ZVAL(a1);
			array_init(a1);
			if (v8) {
				Z_DELREF_P(v8);
				if (!Z_REFCOUNT_P(v8)) {
					FREE_ZVAL(v8);
				}
			}
			Z_ADDREF_P(a1);
			v8 = a1;
			PHALCON_ALLOC_ZVAL(a2);
			array_init(a2);
			if (v9) {
				Z_DELREF_P(v9);
				if (!Z_REFCOUNT_P(v9)) {
					FREE_ZVAL(v9);
				}
			}
			Z_ADDREF_P(a2);
			v9 = a2;
			PHALCON_ALLOC_ZVAL(a3);
			array_init(a3);
			if (v10) {
				Z_DELREF_P(v10);
				if (!Z_REFCOUNT_P(v10)) {
					FREE_ZVAL(v10);
				}
			}
			Z_ADDREF_P(a3);
			v10 = a3;
			PHALCON_ALLOC_ZVAL(a4);
			array_init(a4);
			if (v11) {
				Z_DELREF_P(v11);
				if (!Z_REFCOUNT_P(v11)) {
					FREE_ZVAL(v11);
				}
			}
			Z_ADDREF_P(a4);
			v11 = a4;
			PHALCON_ALLOC_ZVAL(a5);
			array_init(a5);
			if (v12) {
				Z_DELREF_P(v12);
				if (!Z_REFCOUNT_P(v12)) {
					FREE_ZVAL(v12);
				}
			}
			Z_ADDREF_P(a5);
			v12 = a5;
			FOREACH_V(v6, ac0, fes62, fee62, ah0, hp0, v13)
				if (!r10) {
					PHALCON_ALLOC_ZVAL(r10);
				} else {
					if (Z_REFCOUNT_P(r10) > 1) {
						{
							zval *orig_ptr = r10;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r10);
								*r10 = *orig_ptr;
								zval_copy_ctor(r10);
								Z_SET_REFCOUNT_P(r10, 1);
								Z_UNSET_ISREF_P(r10);
							}
						}
					} else {
						FREE_ZVAL(r10);
						PHALCON_ALLOC_ZVAL(r10);
					}
				}
				phalcon_array_fetch_string(r10, v13, "Field", strlen("Field"), PHALCON_NOISY_FETCH TSRMLS_CC);
				if (v14) {
					Z_DELREF_P(v14);
					if (!Z_REFCOUNT_P(v14)) {
						FREE_ZVAL(v14);
					}
				}
				Z_ADDREF_P(r10);
				v14 = r10;
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v14, 1, 0);
					Z_SET_REFCOUNT_P(copy, 1);
					{
						zval *orig_ptr = v7;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(v7);
							*v7 = *orig_ptr;
							zval_copy_ctor(v7);
							Z_SET_REFCOUNT_P(v7, 1);
							Z_UNSET_ISREF_P(v7);
						}
					}
					phalcon_array_append(v7, copy TSRMLS_CC);
				}
				if (!r11) {
					PHALCON_ALLOC_ZVAL(r11);
				} else {
					if (Z_REFCOUNT_P(r11) > 1) {
						{
							zval *orig_ptr = r11;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r11);
								*r11 = *orig_ptr;
								zval_copy_ctor(r11);
								Z_SET_REFCOUNT_P(r11, 1);
								Z_UNSET_ISREF_P(r11);
							}
						}
					} else {
						FREE_ZVAL(r11);
						PHALCON_ALLOC_ZVAL(r11);
					}
				}
				phalcon_array_fetch_string(r11, v13, "Key", strlen("Key"), PHALCON_NOISY_FETCH TSRMLS_CC);
				if (phalcon_compare_strict_string(r11, "PRI")) {
					{
						zval *copy;
						ALLOC_ZVAL(copy);
						ZVAL_ZVAL(copy, v14, 1, 0);
						Z_SET_REFCOUNT_P(copy, 1);
						{
							zval *orig_ptr = v8;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(v8);
								*v8 = *orig_ptr;
								zval_copy_ctor(v8);
								Z_SET_REFCOUNT_P(v8, 1);
								Z_UNSET_ISREF_P(v8);
							}
						}
						phalcon_array_append(v8, copy TSRMLS_CC);
					}
				} else {
					{
						zval *copy;
						ALLOC_ZVAL(copy);
						ZVAL_ZVAL(copy, v14, 1, 0);
						Z_SET_REFCOUNT_P(copy, 1);
						{
							zval *orig_ptr = v9;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(v9);
								*v9 = *orig_ptr;
								zval_copy_ctor(v9);
								Z_SET_REFCOUNT_P(v9, 1);
								Z_UNSET_ISREF_P(v9);
							}
						}
						phalcon_array_append(v9, copy TSRMLS_CC);
					}
				}
				if (!r12) {
					PHALCON_ALLOC_ZVAL(r12);
				} else {
					if (Z_REFCOUNT_P(r12) > 1) {
						{
							zval *orig_ptr = r12;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r12);
								*r12 = *orig_ptr;
								zval_copy_ctor(r12);
								Z_SET_REFCOUNT_P(r12, 1);
								Z_UNSET_ISREF_P(r12);
							}
						}
					} else {
						FREE_ZVAL(r12);
						PHALCON_ALLOC_ZVAL(r12);
					}
				}
				phalcon_array_fetch_string(r12, v13, "Type", strlen("Type"), PHALCON_NOISY_FETCH TSRMLS_CC);
				if (v15) {
					Z_DELREF_P(v15);
					if (!Z_REFCOUNT_P(v15)) {
						FREE_ZVAL(v15);
					}
				}
				Z_ADDREF_P(r12);
				v15 = r12;
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v15, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					{
						zval *orig_ptr = v12;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(v12);
							*v12 = *orig_ptr;
							zval_copy_ctor(v12);
							Z_SET_REFCOUNT_P(v12, 1);
							Z_UNSET_ISREF_P(v12);
						}
					}
					phalcon_array_update(v12, v14, copy TSRMLS_CC);
				}
				if (!r13) {
					PHALCON_ALLOC_ZVAL(r13);
				} else {
					if (Z_REFCOUNT_P(r13) > 1) {
						{
							zval *orig_ptr = r13;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r13);
								*r13 = *orig_ptr;
								zval_copy_ctor(r13);
								Z_SET_REFCOUNT_P(r13, 1);
								Z_UNSET_ISREF_P(r13);
							}
						}
					} else {
						FREE_ZVAL(r13);
						PHALCON_ALLOC_ZVAL(r13);
					}
				}
				p8[0] = v15;
				if (!p8[1]) {
					PHALCON_ALLOC_ZVAL(p8[1]);
				} else {
					if (Z_REFCOUNT_P(p8[1]) > 1) {
						SEPARATE_ZVAL(&p8[1]);
					} else {
						if (Z_TYPE_P(p8[1]) != IS_STRING) {
							FREE_ZVAL(p8[1]);
							PHALCON_ALLOC_ZVAL(p8[1]);
						}
					}
				}
				ZVAL_STRING(p8[1], "int", 1);
				PHALCON_CALL_FUNC_PARAMS(r13, "strpos", 2, p8);
				PHALCON_INIT_FALSE(t3);
				PHALCON_NOT_IDENTICAL_FUNCTION(r14, r13, t3);
				if (zend_is_true(r14)) {
					PHALCON_INIT_TRUE(t4);
					{
						zval *copy;
						ALLOC_ZVAL(copy);
						ZVAL_ZVAL(copy, t4, 1, 0);
						Z_SET_REFCOUNT_P(copy, 0);
						{
							zval *orig_ptr = v10;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(v10);
								*v10 = *orig_ptr;
								zval_copy_ctor(v10);
								Z_SET_REFCOUNT_P(v10, 1);
								Z_UNSET_ISREF_P(v10);
							}
						}
						phalcon_array_update(v10, v14, copy TSRMLS_CC);
					}
				} else {
					if (!r15) {
						PHALCON_ALLOC_ZVAL(r15);
					} else {
						if (Z_REFCOUNT_P(r15) > 1) {
							{
								zval *orig_ptr = r15;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r15);
									*r15 = *orig_ptr;
									zval_copy_ctor(r15);
									Z_SET_REFCOUNT_P(r15, 1);
									Z_UNSET_ISREF_P(r15);
								}
							}
						} else {
							FREE_ZVAL(r15);
							PHALCON_ALLOC_ZVAL(r15);
						}
					}
					p9[0] = v15;
					if (!p9[1]) {
						PHALCON_ALLOC_ZVAL(p9[1]);
					} else {
						if (Z_REFCOUNT_P(p9[1]) > 1) {
							SEPARATE_ZVAL(&p9[1]);
						} else {
							if (Z_TYPE_P(p9[1]) != IS_STRING) {
								FREE_ZVAL(p9[1]);
								PHALCON_ALLOC_ZVAL(p9[1]);
							}
						}
					}
					ZVAL_STRING(p9[1], "decimal", 1);
					PHALCON_CALL_FUNC_PARAMS(r15, "strpos", 2, p9);
					PHALCON_INIT_FALSE(t5);
					PHALCON_NOT_IDENTICAL_FUNCTION(r16, r15, t5);
					if (zend_is_true(r16)) {
						PHALCON_INIT_TRUE(t6);
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, t6, 1, 0);
							Z_SET_REFCOUNT_P(copy, 0);
							{
								zval *orig_ptr = v10;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(v10);
									*v10 = *orig_ptr;
									zval_copy_ctor(v10);
									Z_SET_REFCOUNT_P(v10, 1);
									Z_UNSET_ISREF_P(v10);
								}
							}
							phalcon_array_update(v10, v14, copy TSRMLS_CC);
						}
					}
				}
				if (!r17) {
					PHALCON_ALLOC_ZVAL(r17);
				} else {
					if (Z_REFCOUNT_P(r17) > 1) {
						{
							zval *orig_ptr = r17;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r17);
								*r17 = *orig_ptr;
								zval_copy_ctor(r17);
								Z_SET_REFCOUNT_P(r17, 1);
								Z_UNSET_ISREF_P(r17);
							}
						}
					} else {
						FREE_ZVAL(r17);
						PHALCON_ALLOC_ZVAL(r17);
					}
				}
				phalcon_array_fetch_string(r17, v13, "Null", strlen("Null"), PHALCON_NOISY_FETCH TSRMLS_CC);
				if (phalcon_compare_strict_string(r17, "NO")) {
					{
						zval *copy;
						ALLOC_ZVAL(copy);
						ZVAL_ZVAL(copy, v14, 1, 0);
						Z_SET_REFCOUNT_P(copy, 1);
						{
							zval *orig_ptr = v11;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(v11);
								*v11 = *orig_ptr;
								zval_copy_ctor(v11);
								Z_SET_REFCOUNT_P(v11, 1);
								Z_UNSET_ISREF_P(v11);
							}
						}
						phalcon_array_append(v11, copy TSRMLS_CC);
					}
				}
			END_FOREACH(ac0, fes62, fee62, ah0, hp0);
			PHALCON_ALLOC_ZVAL(a6);
			array_init(a6);
			if (v16) {
				Z_DELREF_P(v16);
				if (!Z_REFCOUNT_P(v16)) {
					FREE_ZVAL(v16);
				}
			}
			Z_ADDREF_P(a6);
			v16 = a6;
			PHALCON_GET_CLASS_CONSTANT(t7, phalcon_model_metadata_class_entry, "MODELS_ATTRIBUTES");
			{
				zval *orig_ptr = v16;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v16);
					*v16 = *orig_ptr;
					zval_copy_ctor(v16);
					Z_SET_REFCOUNT_P(v16, 1);
					Z_UNSET_ISREF_P(v16);
				}
			}
			phalcon_array_update(v16, t7, v7 TSRMLS_CC);
			PHALCON_GET_CLASS_CONSTANT(t8, phalcon_model_metadata_class_entry, "MODELS_PRIMARY_KEY");
			{
				zval *orig_ptr = v16;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v16);
					*v16 = *orig_ptr;
					zval_copy_ctor(v16);
					Z_SET_REFCOUNT_P(v16, 1);
					Z_UNSET_ISREF_P(v16);
				}
			}
			phalcon_array_update(v16, t8, v8 TSRMLS_CC);
			PHALCON_GET_CLASS_CONSTANT(t9, phalcon_model_metadata_class_entry, "MODELS_NON_PRIMARY_KEY");
			{
				zval *orig_ptr = v16;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v16);
					*v16 = *orig_ptr;
					zval_copy_ctor(v16);
					Z_SET_REFCOUNT_P(v16, 1);
					Z_UNSET_ISREF_P(v16);
				}
			}
			phalcon_array_update(v16, t9, v9 TSRMLS_CC);
			PHALCON_GET_CLASS_CONSTANT(t10, phalcon_model_metadata_class_entry, "MODELS_NOT_NULL");
			{
				zval *orig_ptr = v16;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v16);
					*v16 = *orig_ptr;
					zval_copy_ctor(v16);
					Z_SET_REFCOUNT_P(v16, 1);
					Z_UNSET_ISREF_P(v16);
				}
			}
			phalcon_array_update(v16, t10, v11 TSRMLS_CC);
			PHALCON_GET_CLASS_CONSTANT(t11, phalcon_model_metadata_class_entry, "MODELS_DATA_TYPE");
			{
				zval *orig_ptr = v16;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v16);
					*v16 = *orig_ptr;
					zval_copy_ctor(v16);
					Z_SET_REFCOUNT_P(v16, 1);
					Z_UNSET_ISREF_P(v16);
				}
			}
			phalcon_array_update(v16, t11, v12 TSRMLS_CC);
			PHALCON_GET_CLASS_CONSTANT(t12, phalcon_model_metadata_class_entry, "MODELS_DATA_TYPE_NUMERIC");
			{
				zval *orig_ptr = v16;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v16);
					*v16 = *orig_ptr;
					zval_copy_ctor(v16);
					Z_SET_REFCOUNT_P(v16, 1);
					Z_UNSET_ISREF_P(v16);
				}
			}
			phalcon_array_update(v16, t12, v10 TSRMLS_CC);
			t13 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			if (Z_TYPE_P(t13) != IS_ARRAY) {
				convert_to_array(t13);
			}
			if (Z_TYPE_P(t13) == IS_ARRAY) {
				PHALCON_ALLOC_ZVAL(t14);
				phalcon_array_fetch(t14, t13, v2, PHALCON_SILENT_FETCH TSRMLS_CC);
			}
			if (Z_TYPE_P(t14) != IS_ARRAY) {
				convert_to_array(t14);
				phalcon_array_update(t13, v2, t14 TSRMLS_CC);
				Z_ADDREF_P(t14);
			}
			phalcon_array_update(t14, v1, v16 TSRMLS_CC);
			zend_update_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, t13 TSRMLS_CC);
			
		}
	}
	RETURN_NULL();
}

/**
 * Returns table attributes name (fields)
 *
     * @paramPhp_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_array_fetch(t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_array_fetch(t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_ATTRIBUTES");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t1) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

/**
 * Returns table attributes which are part of primary key
 *
 * @paramPhp_Model_Base $model
 * @returnarray
 */
PHP_METHOD(Phalcon_Model_MetaData, getPrimaryKeyAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_array_fetch(t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_array_fetch(t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_PRIMARY_KEY");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t1) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

/**
 * Returns table attributes which are non part of primary key
 *
     * @paramPhp_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getNonPrimaryKeyAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_array_fetch(t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_array_fetch(t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_NON_PRIMARY_KEY");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t1) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

/**
 * Returns not null attributes
 *
     * @paramPhp_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getNotNullAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_array_fetch(t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_array_fetch(t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_NOT_NULL");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t1) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

/**
 * Returns attributes and their data types
 *
     * @paramPhp_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getDataTypes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_array_fetch(t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_array_fetch(t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_DATA_TYPE");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t1) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

/**
 * Returns attributes which types are numerical
 *
     * @param  Php_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getDataTypesNumeric){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	Z_ADDREF_P(v0);
	p2[0] = v0;
	Z_ADDREF_P(v1);
	p2[1] = v1;
	Z_ADDREF_P(v2);
	p2[2] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_array_fetch(t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_array_fetch(t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_DATA_TYPE_NUMERIC");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t1) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

