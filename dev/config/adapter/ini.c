
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

PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *i0 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *p0[] = { NULL, NULL }, *p2[] = { NULL }, *p1[] = { NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL, NULL }, *p5[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	zend_bool silence;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Config_Adapter_Ini", "__construct", 0);
	phalcon_step_over("Phalcon_Config_Adapter_Ini::__construct (Assignment) File=/Config/Adapter/Ini Line=38");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a0);
	v1 = a0;
	phalcon_debug_assign("$config", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Config_Adapter_Ini::__construct (Assignment) File=/Config/Adapter/Ini Line=39");
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL(r0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_PARAM_BOOL(p0[1], 1);
	PHALCON_CALL_FUNC_PARAMS(r0, "parse_ini_file", strlen("parse_ini_file"), 2, p0);
	phalcon_debug_vdump("parse_ini_file > ", r0 TSRMLS_CC);
	PG(display_errors) = silence;
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r0);
	v2 = r0;
	phalcon_debug_assign("$iniConfig", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Config_Adapter_Ini::__construct (If) File=/Config/Adapter/Ini Line=40");
	if (Z_TYPE_P(v2) == IS_BOOL && !Z_BVAL_P(v2)) {
		phalcon_step_over("Phalcon_Config_Adapter_Ini::__construct (Block) File=/Config/Adapter/Ini Line=40");
		phalcon_step_over("Phalcon_Config_Adapter_Ini::__construct (Throw) File=/Config/Adapter/Ini Line=41");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_config_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Config_Adapter_Ini" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r1);
		Z_ADDREF_P(v0);
		p2[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r1, "basename", strlen("basename"), 1, p2);
		phalcon_debug_vdump("basename > ", r1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_both(r2,  "Configuration file ", r1, " can't be loaded" TSRMLS_CC);
		Z_ADDREF_P(r2);
		p1[0] = r2;
		phalcon_debug_param(r2 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Config_Adapter_Ini" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_over("Phalcon_Config_Adapter_Ini::__construct (Foreach) File=/Config/Adapter/Ini Line=43");
	FOREACH_KV(v2, ac0, fes62, fee62, ah0, hp0, v4, v3)
		phalcon_step_over("Phalcon_Config_Adapter_Ini::__construct (Block) File=/Config/Adapter/Ini Line=43");
		phalcon_step_over("Phalcon_Config_Adapter_Ini::__construct (Foreach) File=/Config/Adapter/Ini Line=44");
		FOREACH_KV(v3, ac1, fes63, fee63, ah1, hp1, v6, v5)
			phalcon_step_over("Phalcon_Config_Adapter_Ini::__construct (Block) File=/Config/Adapter/Ini Line=44");
			phalcon_step_over("Phalcon_Config_Adapter_Ini::__construct (If) File=/Config/Adapter/Ini Line=45");
			if (!r3) {
				PHALCON_ALLOC_ZVAL(r3);
			} else {
				if (Z_REFCOUNT_P(r3) > 1) {
					{
						zval *orig_ptr = r3;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r3);
							*r3 = *orig_ptr;
							zval_copy_ctor(r3);
							Z_SET_REFCOUNT_P(r3, 1);
							Z_UNSET_ISREF_P(r3);
						}
					}
				} else {
					FREE_ZVAL(r3);
					PHALCON_ALLOC_ZVAL(r3);
				}
			}
			p3[0] = v6;
			phalcon_debug_param(v6 TSRMLS_CC);
			if (!p3[1]) {
				PHALCON_ALLOC_ZVAL(p3[1]);
			} else {
				if (Z_REFCOUNT_P(p3[1]) > 1) {
					SEPARATE_ZVAL(&p3[1]);
				} else {
					if (Z_TYPE_P(p3[1]) != IS_STRING) {
						FREE_ZVAL(p3[1]);
						PHALCON_ALLOC_ZVAL(p3[1]);
					}
				}
			}
			ZVAL_STRING(p3[1], ".", 1);
			PHALCON_CALL_FUNC_PARAMS(r3, "strpos", strlen("strpos"), 2, p3);
			phalcon_debug_vdump("strpos > ", r3 TSRMLS_CC);
			PHALCON_INIT_FALSE(t0);
			PHALCON_NOT_IDENTICAL_FUNCTION(r4, r3, t0);
			if (zend_is_true(r4)) {
				phalcon_step_over("Phalcon_Config_Adapter_Ini::__construct (Block) File=/Config/Adapter/Ini Line=45");
				phalcon_step_over("Phalcon_Config_Adapter_Ini::__construct (Assignment) File=/Config/Adapter/Ini Line=46");
				if (!r5) {
					PHALCON_ALLOC_ZVAL(r5);
				} else {
					if (Z_REFCOUNT_P(r5) > 1) {
						{
							zval *orig_ptr = r5;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r5);
								*r5 = *orig_ptr;
								zval_copy_ctor(r5);
								Z_SET_REFCOUNT_P(r5, 1);
								Z_UNSET_ISREF_P(r5);
							}
						}
					} else {
						FREE_ZVAL(r5);
						PHALCON_ALLOC_ZVAL(r5);
					}
				}
				if (!p4[0]) {
					PHALCON_ALLOC_ZVAL(p4[0]);
				} else {
					if (Z_REFCOUNT_P(p4[0]) > 1) {
						SEPARATE_ZVAL(&p4[0]);
					} else {
						if (Z_TYPE_P(p4[0]) != IS_STRING) {
							FREE_ZVAL(p4[0]);
							PHALCON_ALLOC_ZVAL(p4[0]);
						}
					}
				}
				ZVAL_STRING(p4[0], ".", 1);
				p4[1] = v6;
				phalcon_debug_param(v6 TSRMLS_CC);
				PHALCON_CALL_FUNC_PARAMS(r5, "explode", strlen("explode"), 2, p4);
				phalcon_debug_vdump("explode > ", r5 TSRMLS_CC);
				if (v7) {
					Z_DELREF_P(v7);
					if (!Z_REFCOUNT_P(v7)) {
						FREE_ZVAL(v7);
					}
				}
				Z_ADDREF_P(r5);
				v7 = r5;
				phalcon_debug_assign("$directiveParts", r5 TSRMLS_CC);
				phalcon_step_over("Phalcon_Config_Adapter_Ini::__construct (Assignment) File=/Config/Adapter/Ini Line=47");
				if (Z_TYPE_P(v1) == IS_ARRAY) {
					if (!t1) {
						PHALCON_ALLOC_ZVAL(t1);
					} else {
						if (Z_REFCOUNT_P(t1) > 1) {
							{
								zval *orig_ptr = t1;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(t1);
									*t1 = *orig_ptr;
									zval_copy_ctor(t1);
									Z_SET_REFCOUNT_P(t1, 1);
									Z_UNSET_ISREF_P(t1);
								}
							}
						} else {
							FREE_ZVAL(t1);
							PHALCON_ALLOC_ZVAL(t1);
						}
					}
					phalcon_array_fetch(t1, v1, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_TYPE_P(t1) != IS_ARRAY) {
					convert_to_array(t1);
					phalcon_array_update(v1, v4, t1 TSRMLS_CC);
					Z_ADDREF_P(t1);
				}
				if (!r6) {
					PHALCON_ALLOC_ZVAL(r6);
				} else {
					if (Z_REFCOUNT_P(r6) > 1) {
						{
							zval *orig_ptr = r6;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r6);
								*r6 = *orig_ptr;
								zval_copy_ctor(r6);
								Z_SET_REFCOUNT_P(r6, 1);
								Z_UNSET_ISREF_P(r6);
							}
						}
					} else {
						FREE_ZVAL(r6);
						PHALCON_ALLOC_ZVAL(r6);
					}
				}
				phalcon_array_fetch_long(r6, v7, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				if (Z_TYPE_P(t1) == IS_ARRAY) {
					if (!t2) {
						PHALCON_ALLOC_ZVAL(t2);
					} else {
						if (Z_REFCOUNT_P(t2) > 1) {
							{
								zval *orig_ptr = t2;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(t2);
									*t2 = *orig_ptr;
									zval_copy_ctor(t2);
									Z_SET_REFCOUNT_P(t2, 1);
									Z_UNSET_ISREF_P(t2);
								}
							}
						} else {
							FREE_ZVAL(t2);
							PHALCON_ALLOC_ZVAL(t2);
						}
					}
					phalcon_array_fetch(t2, t1, r6, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_TYPE_P(t2) != IS_ARRAY) {
					convert_to_array(t2);
					phalcon_array_update(t1, r6, t2 TSRMLS_CC);
					Z_ADDREF_P(t2);
				}
				if (!r7) {
					PHALCON_ALLOC_ZVAL(r7);
				} else {
					if (Z_REFCOUNT_P(r7) > 1) {
						{
							zval *orig_ptr = r7;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r7);
								*r7 = *orig_ptr;
								zval_copy_ctor(r7);
								Z_SET_REFCOUNT_P(r7, 1);
								Z_UNSET_ISREF_P(r7);
							}
						}
					} else {
						FREE_ZVAL(r7);
						PHALCON_ALLOC_ZVAL(r7);
					}
				}
				phalcon_array_fetch_long(r7, v7, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v5, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_array_update(t2, r7, copy TSRMLS_CC);
				}
			} else {
				phalcon_step_over("Phalcon_Config_Adapter_Ini::__construct (Block) File=/Config/Adapter/Ini Line=48");
				phalcon_step_over("Phalcon_Config_Adapter_Ini::__construct (Assignment) File=/Config/Adapter/Ini Line=49");
				if (Z_TYPE_P(v1) == IS_ARRAY) {
					if (!t3) {
						PHALCON_ALLOC_ZVAL(t3);
					} else {
						if (Z_REFCOUNT_P(t3) > 1) {
							{
								zval *orig_ptr = t3;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(t3);
									*t3 = *orig_ptr;
									zval_copy_ctor(t3);
									Z_SET_REFCOUNT_P(t3, 1);
									Z_UNSET_ISREF_P(t3);
								}
							}
						} else {
							FREE_ZVAL(t3);
							PHALCON_ALLOC_ZVAL(t3);
						}
					}
					phalcon_array_fetch(t3, v1, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_TYPE_P(t3) != IS_ARRAY) {
					convert_to_array(t3);
					phalcon_array_update(v1, v4, t3 TSRMLS_CC);
					Z_ADDREF_P(t3);
				}
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v5, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_array_update(t3, v6, copy TSRMLS_CC);
				}
			}
		END_FOREACH(ac1, fes63, fee63, ah1, hp1);
	END_FOREACH(ac0, fes62, fee62, ah0, hp0);
	phalcon_step_over("Phalcon_Config_Adapter_Ini::__construct (StaticMethodCall) File=/Config/Adapter/Ini Line=53");
	Z_ADDREF_P(v1);
	p5[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Config_Adapter_Ini", "__construct", 1, p5);
	phalcon_step_out_entry();
	RETURN_NULL();
}

