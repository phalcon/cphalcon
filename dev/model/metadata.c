
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
 *
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
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_MetaData", "__construct", 0);
	phalcon_step_over("Phalcon_Model_MetaData::__construct (Assignment) File=Library/Phalcon/Model/MetaData.php Line=29");
	//$adapterClass
	//$adapter
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
	phalcon_debug_assign("$adapterClass", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_MetaData::__construct (If) File=Library/Phalcon/Model/MetaData.php Line=30");
	PHALCON_ALLOC_ZVAL(r1);
	//$adapterClass
	Z_ADDREF_P(v1);
	p0[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r1, "class_exists", 1, p0);
	phalcon_debug_vdump("class_exists > ", r1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Model_MetaData::__construct (Block) File=Library/Phalcon/Model/MetaData.php Line=30");
		phalcon_step_over("Phalcon_Model_MetaData::__construct (Assignment) File=Library/Phalcon/Model/MetaData.php Line=31");
		//$adapterClass
		ce0 = zend_fetch_class(Z_STRVAL_P(v1), Z_STRLEN_P(v1), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, ce0);
		phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, i0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_adapter", strlen("_adapter"), copy TSRMLS_CC);
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_MetaData::__construct (Method) File=Library/Phalcon/Model/MetaData.php Line=35");
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

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_MetaData", "_initializeMetaData", 0);
	phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (If) File=Library/Phalcon/Model/MetaData.php Line=36");
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	//$schema
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_array_fetch(t2, t0, v2, PHALCON_SILENT_FETCH TSRMLS_CC);
	//$table
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t2, v1, PHALCON_SILENT_FETCH TSRMLS_CC);
	if (!zend_is_true(t1)) {
		phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Block) File=Library/Phalcon/Model/MetaData.php Line=36");
		phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=37");
		//$connection
		PHALCON_ALLOC_ZVAL(r0);
		//$model
		phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
		phalcon_debug_method_call(v0, "getconnection" TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, v0, "getconnection", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r0);
		v3 = r0;
		phalcon_debug_assign("$connection", r0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=38");
		//$isView
		PHALCON_ALLOC_ZVAL(r1);
		//$model
		phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
		phalcon_debug_method_call(v0, "isview" TSRMLS_CC);
		PHALCON_CALL_METHOD(r1, v0, "isview", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r1);
		v4 = r1;
		phalcon_debug_assign("$isView", r1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (If) File=Library/Phalcon/Model/MetaData.php Line=39");
		//$isView
		if (!zend_is_true(v4)) {
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Block) File=Library/Phalcon/Model/MetaData.php Line=39");
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=40");
			//$exists
			PHALCON_ALLOC_ZVAL(r2);
			//$connection
			phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
			phalcon_debug_method_call(v3, "tableexists" TSRMLS_CC);
			//$table
			Z_ADDREF_P(v1);
			p2[0] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			//$schema
			Z_ADDREF_P(v2);
			p2[1] = v2;
			phalcon_debug_param(v2 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS(r2, v3, "tableexists", 2, p2, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
			if (v5) {
				Z_DELREF_P(v5);
				if (!Z_REFCOUNT_P(v5)) {
					FREE_ZVAL(v5);
				}
			}
			Z_ADDREF_P(r2);
			v5 = r2;
			phalcon_debug_assign("$exists", r2 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Block) File=Library/Phalcon/Model/MetaData.php Line=41");
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=42");
			//$exists
			PHALCON_ALLOC_ZVAL(r3);
			//$connection
			phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
			phalcon_debug_method_call(v3, "viewexists" TSRMLS_CC);
			//$table
			Z_ADDREF_P(v1);
			p3[0] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			//$schema
			Z_ADDREF_P(v2);
			p3[1] = v2;
			phalcon_debug_param(v2 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS(r3, v3, "viewexists", 2, p3, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
			if (v5) {
				Z_DELREF_P(v5);
				if (!Z_REFCOUNT_P(v5)) {
					FREE_ZVAL(v5);
				}
			}
			Z_ADDREF_P(r3);
			v5 = r3;
			phalcon_debug_assign("$exists", r3 TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (If) File=Library/Phalcon/Model/MetaData.php Line=44");
		//$exists
		if (!zend_is_true(v5)) {
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Block) File=Library/Phalcon/Model/MetaData.php Line=44");
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Throw) File=Library/Phalcon/Model/MetaData.php Line=45");
			PHALCON_ALLOC_ZVAL(i0);
			object_init_ex(i0, phalcon_model_exception_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
			phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
			//$schema
			PHALCON_ALLOC_ZVAL(r6);
			phalcon_concat_left(r6, "Table \"", v2 TSRMLS_CC);
			//$table
			PHALCON_ALLOC_ZVAL(r5);
			phalcon_concat_vboth(r5, r6, "\".\"", v1 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r7);
			//$model
			p5[0] = v0;
			phalcon_debug_param(v0 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r7, "get_class", 1, p5);
			phalcon_debug_vdump("get_class > ", r7 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r4);
			phalcon_concat_vboth(r4, r5, "\" doesn't exists on database when dumping information for ", r7 TSRMLS_CC);
			Z_ADDREF_P(r4);
			p4[0] = r4;
			phalcon_debug_param(r4 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			return;
		} else {
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Block) File=Library/Phalcon/Model/MetaData.php Line=46");
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (If) File=Library/Phalcon/Model/MetaData.php Line=47");
			//$isView
			if (zend_is_true(v4)) {
				phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Block) File=Library/Phalcon/Model/MetaData.php Line=47");
				phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=48");
				//$metaDatas
				PHALCON_ALLOC_ZVAL(r8);
				//$connection
				phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
				phalcon_debug_method_call(v3, "describeview" TSRMLS_CC);
				//$table
				Z_ADDREF_P(v1);
				p6[0] = v1;
				phalcon_debug_param(v1 TSRMLS_CC);
				//$schema
				Z_ADDREF_P(v2);
				p6[1] = v2;
				phalcon_debug_param(v2 TSRMLS_CC);
				PHALCON_CALL_METHOD_PARAMS(r8, v3, "describeview", 2, p6, PHALCON_CALL_DEFAULT);
				phalcon_debug_vdump("MethodReturn > ", r8 TSRMLS_CC);
				phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
				if (v6) {
					Z_DELREF_P(v6);
					if (!Z_REFCOUNT_P(v6)) {
						FREE_ZVAL(v6);
					}
				}
				Z_ADDREF_P(r8);
				v6 = r8;
				phalcon_debug_assign("$metaDatas", r8 TSRMLS_CC);
			} else {
				phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Block) File=Library/Phalcon/Model/MetaData.php Line=49");
				phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=50");
				//$metaDatas
				PHALCON_ALLOC_ZVAL(r9);
				//$connection
				phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
				phalcon_debug_method_call(v3, "describetable" TSRMLS_CC);
				//$table
				Z_ADDREF_P(v1);
				p7[0] = v1;
				phalcon_debug_param(v1 TSRMLS_CC);
				//$schema
				Z_ADDREF_P(v2);
				p7[1] = v2;
				phalcon_debug_param(v2 TSRMLS_CC);
				PHALCON_CALL_METHOD_PARAMS(r9, v3, "describetable", 2, p7, PHALCON_CALL_DEFAULT);
				phalcon_debug_vdump("MethodReturn > ", r9 TSRMLS_CC);
				phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
				if (v6) {
					Z_DELREF_P(v6);
					if (!Z_REFCOUNT_P(v6)) {
						FREE_ZVAL(v6);
					}
				}
				Z_ADDREF_P(r9);
				v6 = r9;
				phalcon_debug_assign("$metaDatas", r9 TSRMLS_CC);
			}
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=52");
			//$attributes
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
			phalcon_debug_assign("$attributes", a0 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=53");
			//$primaryKeys
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
			phalcon_debug_assign("$primaryKeys", a1 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=54");
			//$nonPrimaryKeys
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
			phalcon_debug_assign("$nonPrimaryKeys", a2 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=55");
			//$numericTyped
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
			phalcon_debug_assign("$numericTyped", a3 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=56");
			//$notNull
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
			phalcon_debug_assign("$notNull", a4 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=57");
			//$fieldTypes
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
			phalcon_debug_assign("$fieldTypes", a5 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Foreach) File=Library/Phalcon/Model/MetaData.php Line=58");
			//$metaDatas
			//$metaData
			FOREACH_V(v6, ac0, fes62, fee62, ah0, hp0, v13)
				phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Block) File=Library/Phalcon/Model/MetaData.php Line=58");
				phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=59");
				//$fieldName
				//$metaData
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
				phalcon_debug_assign("$fieldName", r10 TSRMLS_CC);
				phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=60");
				//$fieldName
				//$attributes
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
				phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (If) File=Library/Phalcon/Model/MetaData.php Line=61");
				//$metaData
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
					phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Block) File=Library/Phalcon/Model/MetaData.php Line=61");
					phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=62");
					//$fieldName
					//$primaryKeys
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
					phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Block) File=Library/Phalcon/Model/MetaData.php Line=63");
					phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=64");
					//$fieldName
					//$nonPrimaryKeys
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
				phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=66");
				//$type
				//$metaData
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
				phalcon_debug_assign("$type", r12 TSRMLS_CC);
				phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=67");
				//$type
				//$fieldTypes
				//$fieldName
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
				phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (If) File=Library/Phalcon/Model/MetaData.php Line=68");
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
				//$type
				p8[0] = v15;
				phalcon_debug_param(v15 TSRMLS_CC);
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
				phalcon_debug_vdump("strpos > ", r13 TSRMLS_CC);
				PHALCON_INIT_FALSE(t3);
				PHALCON_NOT_IDENTICAL_FUNCTION(r14, r13, t3);
				if (zend_is_true(r14)) {
					phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Block) File=Library/Phalcon/Model/MetaData.php Line=68");
					phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=69");
					PHALCON_INIT_TRUE(t4);
					//$numericTyped
					//$fieldName
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
					phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Block) File=Library/Phalcon/Model/MetaData.php Line=70");
					phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (If) File=Library/Phalcon/Model/MetaData.php Line=71");
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
					//$type
					p9[0] = v15;
					phalcon_debug_param(v15 TSRMLS_CC);
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
					phalcon_debug_vdump("strpos > ", r15 TSRMLS_CC);
					PHALCON_INIT_FALSE(t5);
					PHALCON_NOT_IDENTICAL_FUNCTION(r16, r15, t5);
					if (zend_is_true(r16)) {
						phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Block) File=Library/Phalcon/Model/MetaData.php Line=71");
						phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=72");
						PHALCON_INIT_TRUE(t6);
						//$numericTyped
						//$fieldName
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
				phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (If) File=Library/Phalcon/Model/MetaData.php Line=75");
				//$metaData
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
					phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Block) File=Library/Phalcon/Model/MetaData.php Line=75");
					phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=76");
					//$fieldName
					//$notNull
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
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=79");
			//$tableMetadata
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
			phalcon_debug_assign("$tableMetadata", a6 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=80");
			//$attributes
			//$tableMetadata
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
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=81");
			//$primaryKeys
			//$tableMetadata
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
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=82");
			//$nonPrimaryKeys
			//$tableMetadata
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
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=83");
			//$notNull
			//$tableMetadata
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
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=84");
			//$fieldTypes
			//$tableMetadata
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
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=85");
			//$numericTyped
			//$tableMetadata
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
			phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Assignment) File=Library/Phalcon/Model/MetaData.php Line=86");
			//$tableMetadata
			t13 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
			if (Z_TYPE_P(t13) != IS_ARRAY) {
				convert_to_array(t13);
			}
			//$schema
			if (Z_TYPE_P(t13) == IS_ARRAY) {
				PHALCON_ALLOC_ZVAL(t14);
				phalcon_array_fetch(t14, t13, v2, PHALCON_SILENT_FETCH TSRMLS_CC);
			}
			if (Z_TYPE_P(t14) != IS_ARRAY) {
				convert_to_array(t14);
				phalcon_array_update(t13, v2, t14 TSRMLS_CC);
				Z_ADDREF_P(t14);
			}
			//$table
			phalcon_array_update(t14, v1, v16 TSRMLS_CC);
			zend_update_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, t13 TSRMLS_CC);
			
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_MetaData::_initializeMetaData (Method) File=Library/Phalcon/Model/MetaData.php Line=91");
}

PHP_METHOD(Phalcon_Model_MetaData, getAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_MetaData", "getAttributes", 0);
	phalcon_step_over("Phalcon_Model_MetaData::getAttributes (Assignment) File=Library/Phalcon/Model/MetaData.php Line=92");
	//$table
	PHALCON_ALLOC_ZVAL(r0);
	//$model
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(v0, "getsource" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_debug_assign("$table", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_MetaData::getAttributes (Assignment) File=Library/Phalcon/Model/MetaData.php Line=93");
	//$schema
	PHALCON_ALLOC_ZVAL(r1);
	//$model
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(v0, "getschema" TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	phalcon_debug_assign("$schema", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_MetaData::getAttributes (MethodCall) File=Library/Phalcon/Model/MetaData.php Line=94");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_initializemetadata" TSRMLS_CC);
	//$model
	Z_ADDREF_P(v0);
	p2[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$table
	Z_ADDREF_P(v1);
	p2[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	//$schema
	Z_ADDREF_P(v2);
	p2[2] = v2;
	phalcon_debug_param(v2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	//$schema
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_array_fetch(t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	//$table
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_array_fetch(t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_ATTRIBUTES");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_MetaData::getAttributes (Method) File=Library/Phalcon/Model/MetaData.php Line=98");
}

PHP_METHOD(Phalcon_Model_MetaData, getPrimaryKeyAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_MetaData", "getPrimaryKeyAttributes", 0);
	phalcon_step_over("Phalcon_Model_MetaData::getPrimaryKeyAttributes (Assignment) File=Library/Phalcon/Model/MetaData.php Line=99");
	//$table
	PHALCON_ALLOC_ZVAL(r0);
	//$model
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(v0, "getsource" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_debug_assign("$table", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_MetaData::getPrimaryKeyAttributes (Assignment) File=Library/Phalcon/Model/MetaData.php Line=100");
	//$schema
	PHALCON_ALLOC_ZVAL(r1);
	//$model
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(v0, "getschema" TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	phalcon_debug_assign("$schema", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_MetaData::getPrimaryKeyAttributes (MethodCall) File=Library/Phalcon/Model/MetaData.php Line=101");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_initializemetadata" TSRMLS_CC);
	//$model
	Z_ADDREF_P(v0);
	p2[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$table
	Z_ADDREF_P(v1);
	p2[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	//$schema
	Z_ADDREF_P(v2);
	p2[2] = v2;
	phalcon_debug_param(v2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	//$schema
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_array_fetch(t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	//$table
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_array_fetch(t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_PRIMARY_KEY");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_MetaData::getPrimaryKeyAttributes (Method) File=Library/Phalcon/Model/MetaData.php Line=105");
}

PHP_METHOD(Phalcon_Model_MetaData, getNonPrimaryKeyAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_MetaData", "getNonPrimaryKeyAttributes", 0);
	phalcon_step_over("Phalcon_Model_MetaData::getNonPrimaryKeyAttributes (Assignment) File=Library/Phalcon/Model/MetaData.php Line=106");
	//$table
	PHALCON_ALLOC_ZVAL(r0);
	//$model
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(v0, "getsource" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_debug_assign("$table", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_MetaData::getNonPrimaryKeyAttributes (Assignment) File=Library/Phalcon/Model/MetaData.php Line=107");
	//$schema
	PHALCON_ALLOC_ZVAL(r1);
	//$model
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(v0, "getschema" TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	phalcon_debug_assign("$schema", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_MetaData::getNonPrimaryKeyAttributes (MethodCall) File=Library/Phalcon/Model/MetaData.php Line=108");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_initializemetadata" TSRMLS_CC);
	//$model
	Z_ADDREF_P(v0);
	p2[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$table
	Z_ADDREF_P(v1);
	p2[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	//$schema
	Z_ADDREF_P(v2);
	p2[2] = v2;
	phalcon_debug_param(v2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	//$schema
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_array_fetch(t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	//$table
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_array_fetch(t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_NON_PRIMARY_KEY");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_MetaData::getNonPrimaryKeyAttributes (Method) File=Library/Phalcon/Model/MetaData.php Line=112");
}

PHP_METHOD(Phalcon_Model_MetaData, getNotNullAttributes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_MetaData", "getNotNullAttributes", 0);
	phalcon_step_over("Phalcon_Model_MetaData::getNotNullAttributes (Assignment) File=Library/Phalcon/Model/MetaData.php Line=113");
	//$table
	PHALCON_ALLOC_ZVAL(r0);
	//$model
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(v0, "getsource" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_debug_assign("$table", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_MetaData::getNotNullAttributes (Assignment) File=Library/Phalcon/Model/MetaData.php Line=114");
	//$schema
	PHALCON_ALLOC_ZVAL(r1);
	//$model
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(v0, "getschema" TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	phalcon_debug_assign("$schema", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_MetaData::getNotNullAttributes (MethodCall) File=Library/Phalcon/Model/MetaData.php Line=115");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_initializemetadata" TSRMLS_CC);
	//$model
	Z_ADDREF_P(v0);
	p2[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$table
	Z_ADDREF_P(v1);
	p2[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	//$schema
	Z_ADDREF_P(v2);
	p2[2] = v2;
	phalcon_debug_param(v2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	//$schema
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_array_fetch(t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	//$table
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_array_fetch(t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_NOT_NULL");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_MetaData::getNotNullAttributes (Method) File=Library/Phalcon/Model/MetaData.php Line=119");
}

PHP_METHOD(Phalcon_Model_MetaData, getDataTypes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_MetaData", "getDataTypes", 0);
	phalcon_step_over("Phalcon_Model_MetaData::getDataTypes (Assignment) File=Library/Phalcon/Model/MetaData.php Line=120");
	//$table
	PHALCON_ALLOC_ZVAL(r0);
	//$model
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(v0, "getsource" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_debug_assign("$table", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_MetaData::getDataTypes (Assignment) File=Library/Phalcon/Model/MetaData.php Line=121");
	//$schema
	PHALCON_ALLOC_ZVAL(r1);
	//$model
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(v0, "getschema" TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	phalcon_debug_assign("$schema", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_MetaData::getDataTypes (MethodCall) File=Library/Phalcon/Model/MetaData.php Line=122");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_initializemetadata" TSRMLS_CC);
	//$model
	Z_ADDREF_P(v0);
	p2[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$table
	Z_ADDREF_P(v1);
	p2[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	//$schema
	Z_ADDREF_P(v2);
	p2[2] = v2;
	phalcon_debug_param(v2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	//$schema
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_array_fetch(t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	//$table
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_array_fetch(t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_DATA_TYPE");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_MetaData::getDataTypes (Method) File=Library/Phalcon/Model/MetaData.php Line=126");
}

PHP_METHOD(Phalcon_Model_MetaData, getDataTypesNumeric){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p2[] = { NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_MetaData", "getDataTypesNumeric", 0);
	phalcon_step_over("Phalcon_Model_MetaData::getDataTypesNumeric (Assignment) File=Library/Phalcon/Model/MetaData.php Line=127");
	//$table
	PHALCON_ALLOC_ZVAL(r0);
	//$model
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(v0, "getsource" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, v0, "getsource", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_debug_assign("$table", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_MetaData::getDataTypesNumeric (Assignment) File=Library/Phalcon/Model/MetaData.php Line=128");
	//$schema
	PHALCON_ALLOC_ZVAL(r1);
	//$model
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(v0, "getschema" TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, v0, "getschema", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	phalcon_debug_assign("$schema", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_MetaData::getDataTypesNumeric (MethodCall) File=Library/Phalcon/Model/MetaData.php Line=129");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_initializemetadata" TSRMLS_CC);
	//$model
	Z_ADDREF_P(v0);
	p2[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$table
	Z_ADDREF_P(v1);
	p2[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	//$schema
	Z_ADDREF_P(v2);
	p2[2] = v2;
	phalcon_debug_param(v2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_initializemetadata", 3, p2, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_MetaData" TSRMLS_CC);
	t0 = zend_read_static_property(phalcon_model_metadata_class_entry, "_metaData", sizeof("_metaData")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	//$schema
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_array_fetch(t3, t0, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
	//$table
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_array_fetch(t2, t3, v1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_metadata_class_entry, "MODELS_DATA_TYPE_NUMERIC");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t2, t4, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t1 TSRMLS_CC);
	phalcon_step_out_entry();
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
	phalcon_step_out_entry();
}

