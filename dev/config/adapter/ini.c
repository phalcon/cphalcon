
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
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *i0 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *p1[] = { NULL }, *p5[] = { NULL };
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
	PHALCON_ALLOC_ZVAL(c0);
	ZVAL_BOOL(c0, 1);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "parse_ini_file", v0, c0, 0x03B);
	FREE_ZVAL(c0);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(v2, r0);
	if (Z_TYPE_P(v2) == IS_BOOL && !Z_BVAL_P(v2)) {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_config_exception_class_entry);
		PHALCON_ALLOC_ZVAL(r1);
		Z_ADDREF_P(v0);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "basename", v0, 0x03C);
		PHALCON_ALLOC_ZVAL(r2);
		PHALCON_CONCAT_BOTH(r2,  "Configuration file ", r1, " can't be loaded");
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	FOREACH_KV(v2, ac0, fes62, fee62, ah0, hp0, v4, v3)
		FOREACH_KV(v3, ac1, fes63, fee63, ah1, hp1, v6, v5)
			PHALCON_INIT_RESULT(r3);
			PHALCON_INIT_VARTYPE(c1, IS_STRING);
			ZVAL_STRING(c1, ".", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r3, "strpos", v6, c1, 0x005);
			if (Z_TYPE_P(r3) != IS_BOOL || (Z_TYPE_P(r3) == IS_BOOL && Z_BVAL_P(r3))) {
				PHALCON_INIT_RESULT(r4);
				PHALCON_INIT_VARTYPE(c2, IS_STRING);
				ZVAL_STRING(c2, ".", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r4, "explode", c2, v6, 0x002);
				PHALCON_CPY_WRT(v7, r4);
				if (Z_TYPE_P(v1) == IS_ARRAY) {
					PHALCON_INIT_RESULT(t0);
					phalcon_array_fetch(t0, v1, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_TYPE_P(t0) != IS_ARRAY) {
					convert_to_array(t0);
					phalcon_array_update(v1, v4, t0 TSRMLS_CC);
					Z_ADDREF_P(t0);
				}
				PHALCON_INIT_RESULT(r5);
				phalcon_array_fetch_long(r5, v7, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				if (Z_TYPE_P(t0) == IS_ARRAY) {
					PHALCON_INIT_RESULT(t1);
					phalcon_array_fetch(t1, t0, r5, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_TYPE_P(t1) != IS_ARRAY) {
					convert_to_array(t1);
					phalcon_array_update(t0, r5, t1 TSRMLS_CC);
					Z_ADDREF_P(t1);
				}
				PHALCON_INIT_RESULT(r6);
				phalcon_array_fetch_long(r6, v7, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ARRAY_UPDATE(t1, r6, v5);
			} else {
				if (Z_TYPE_P(v1) == IS_ARRAY) {
					PHALCON_INIT_RESULT(t2);
					phalcon_array_fetch(t2, v1, v4, PHALCON_SILENT_FETCH TSRMLS_CC);
				}
				if (Z_TYPE_P(t2) != IS_ARRAY) {
					convert_to_array(t2);
					phalcon_array_update(v1, v4, t2 TSRMLS_CC);
					Z_ADDREF_P(t2);
				}
				PHALCON_ARRAY_UPDATE(t2, v6, v5);
			}
		END_FOREACH(ac1, fes63, fee63, ah1, hp1);
	END_FOREACH(ac0, fes62, fee62, ah0, hp0);
	Z_ADDREF_P(v1);
	p5[0] = v1;
	PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Config_Adapter_Ini", "__construct", 1, p5);
	RETURN_NULL();
}

