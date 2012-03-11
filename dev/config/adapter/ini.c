
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
	zval *i0 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
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

	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v1, a0);
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL(r0);
	p0[0] = v0;
	PHALCON_PARAM_BOOL(p0[1], 1);
	PHALCON_CALL_FUNC_PARAMS(r0, "parse_ini_file", 2, p0);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(v2, r0);
	if (Z_TYPE_P(v2) == IS_BOOL && !Z_BVAL_P(v2)) {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_config_exception_class_entry);
		PHALCON_ALLOC_ZVAL(r1);
		Z_ADDREF_P(v0);
		p2[0] = v0;
		PHALCON_CALL_FUNC_PARAMS(r1, "basename", 1, p2);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_both(r2,  "Configuration file ", r1, " can't be loaded" TSRMLS_CC);
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	FOREACH_KV(v2, ac0, fes62, fee62, ah0, hp0, v4, v3)
		FOREACH_KV(v3, ac1, fes63, fee63, ah1, hp1, v6, v5)
			if (!r3) {
				PHALCON_ALLOC_ZVAL(r3);
			} else {
				if (Z_REFCOUNT_P(r3) > 1) {
					PHALCON_SEPARATE(r3);
				} else {
					FREE_ZVAL(r3);
					PHALCON_ALLOC_ZVAL(r3);
				}
			}
			p3[0] = v6;
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
			PHALCON_CALL_FUNC_PARAMS(r3, "strpos", 2, p3);
			if (Z_TYPE_P(r3) != IS_BOOL || (Z_TYPE_P(r3) == IS_BOOL && Z_BVAL_P(r3))) {
				if (!r4) {
					PHALCON_ALLOC_ZVAL(r4);
				} else {
					if (Z_REFCOUNT_P(r4) > 1) {
						PHALCON_SEPARATE(r4);
					} else {
						FREE_ZVAL(r4);
						PHALCON_ALLOC_ZVAL(r4);
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
				PHALCON_CALL_FUNC_PARAMS(r4, "explode", 2, p4);
				PHALCON_CPY_WRT(v7, r4);
				if (Z_TYPE_P(v1) == IS_ARRAY) {
					if (!t0) {
						PHALCON_ALLOC_ZVAL(t0);
					} else {
						if (Z_REFCOUNT_P(t0) > 1) {
							PHALCON_SEPARATE(t0);
						} else {
							FREE_ZVAL(t0);
							PHALCON_ALLOC_ZVAL(t0);
						}
					}
					phalcon_array_fetch(t0, v1, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_TYPE_P(t0) != IS_ARRAY) {
					convert_to_array(t0);
					phalcon_array_update(v1, v4, t0 TSRMLS_CC);
					Z_ADDREF_P(t0);
				}
				if (!r5) {
					PHALCON_ALLOC_ZVAL(r5);
				} else {
					if (Z_REFCOUNT_P(r5) > 1) {
						PHALCON_SEPARATE(r5);
					} else {
						FREE_ZVAL(r5);
						PHALCON_ALLOC_ZVAL(r5);
					}
				}
				phalcon_array_fetch_long(r5, v7, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				if (Z_TYPE_P(t0) == IS_ARRAY) {
					if (!t1) {
						PHALCON_ALLOC_ZVAL(t1);
					} else {
						if (Z_REFCOUNT_P(t1) > 1) {
							PHALCON_SEPARATE(t1);
						} else {
							FREE_ZVAL(t1);
							PHALCON_ALLOC_ZVAL(t1);
						}
					}
					phalcon_array_fetch(t1, t0, r5, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_TYPE_P(t1) != IS_ARRAY) {
					convert_to_array(t1);
					phalcon_array_update(t0, r5, t1 TSRMLS_CC);
					Z_ADDREF_P(t1);
				}
				if (!r6) {
					PHALCON_ALLOC_ZVAL(r6);
				} else {
					if (Z_REFCOUNT_P(r6) > 1) {
						PHALCON_SEPARATE(r6);
					} else {
						FREE_ZVAL(r6);
						PHALCON_ALLOC_ZVAL(r6);
					}
				}
				phalcon_array_fetch_long(r6, v7, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v5, 1, 0);
					Z_SET_REFCOUNT_P(copy, 1);
					phalcon_array_update(t1, r6, copy TSRMLS_CC);
				}
			} else {
				if (Z_TYPE_P(v1) == IS_ARRAY) {
					if (!t2) {
						PHALCON_ALLOC_ZVAL(t2);
					} else {
						if (Z_REFCOUNT_P(t2) > 1) {
							PHALCON_SEPARATE(t2);
						} else {
							FREE_ZVAL(t2);
							PHALCON_ALLOC_ZVAL(t2);
						}
					}
					phalcon_array_fetch(t2, v1, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_TYPE_P(t2) != IS_ARRAY) {
					convert_to_array(t2);
					phalcon_array_update(v1, v4, t2 TSRMLS_CC);
					Z_ADDREF_P(t2);
				}
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v5, 1, 0);
					Z_SET_REFCOUNT_P(copy, 1);
					phalcon_array_update(t2, v6, copy TSRMLS_CC);
				}
			}
		END_FOREACH(ac1, fes63, fee63, ah1, hp1);
	END_FOREACH(ac0, fes62, fee62, ah0, hp0);
	Z_ADDREF_P(v1);
	p5[0] = v1;
	PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Config_Adapter_Ini", "__construct", 1, p5);
	RETURN_NULL();
}

