
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

PHP_METHOD(Phalcon_Db_Mysql, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL, NULL };

	phalcon_step_over("Phalcon_Db_Mysql::__construct (Method) File=/Db/Mysql Line=31");
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_BOOL(v1, 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Mysql", "__construct", 0);
	phalcon_step_over("Phalcon_Db_Mysql::__construct (If) File=/Db/Mysql Line=32");
	if (PHALCON_COMPARE_STRING(v0, "")) {
		phalcon_step_over("Phalcon_Db_Mysql::__construct (Block) File=/Db/Mysql Line=32");
		phalcon_step_over("Phalcon_Db_Mysql::__construct (Assignment) File=/Db/Mysql Line=33");
		PHALCON_ALLOC_ZVAL(t0);
		phalcon_read_property(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT_PARAM(v0, t0);
		phalcon_debug_assign("$descriptor", t0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Db_Mysql::__construct (MethodCall) File=/Db/Mysql Line=35");
	phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "connect" TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "connect", 2, p0, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db_Mysql::__construct (Method) File=/Db/Mysql Line=46");
}

PHP_METHOD(Phalcon_Db_Mysql, connect){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL, *t17 = NULL, *t18 = NULL, *t19 = NULL, *t20 = NULL;
	zval *t21 = NULL, *t22 = NULL, *t23 = NULL, *t24 = NULL, *t25 = NULL, *t26 = NULL, *t27 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL, NULL }, *p2[] = { NULL, NULL }, *p3[] = { NULL, NULL, NULL }, *p6[] = { NULL }, *p7[] = { NULL }, *p8[] = { NULL }, *p9[] = { NULL }, *p10[] = { NULL, NULL, NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_BOOL(v1, 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Mysql", "connect", 0);
	phalcon_step_over("Phalcon_Db_Mysql::connect (If) File=/Db/Mysql Line=47");
	if (PHALCON_COMPARE_STRING(v0, "")) {
		phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=47");
		phalcon_step_over("Phalcon_Db_Mysql::connect (Assignment) File=/Db/Mysql Line=48");
		PHALCON_ALLOC_ZVAL(t0);
		phalcon_read_property(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT_PARAM(v0, t0);
		phalcon_debug_assign("$descriptor", t0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Db_Mysql::connect (Assignment) File=/Db/Mysql Line=50");
	eval_int = phalcon_isset_property(v0, "host", strlen("host") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, v0, "host", sizeof("host")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		r0 = t1;
	} else {
		PHALCON_ALLOC_ZVAL(t2);
		ZVAL_STRING(t2, "", 1);
		r0 = t2;
	}
	PHALCON_CPY_WRT(v2, r0);
	phalcon_debug_assign("$host", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_Mysql::connect (Assignment) File=/Db/Mysql Line=51");
	eval_int = phalcon_isset_property(v0, "username", strlen("username") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, v0, "username", sizeof("username")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		r1 = t3;
	} else {
		PHALCON_ALLOC_ZVAL(t4);
		ZVAL_STRING(t4, "", 1);
		r1 = t4;
	}
	PHALCON_CPY_WRT(v3, r1);
	phalcon_debug_assign("$username", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_Mysql::connect (Assignment) File=/Db/Mysql Line=52");
	eval_int = phalcon_isset_property(v0, "password", strlen("password") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(t5);
		phalcon_read_property(t5, v0, "password", sizeof("password")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		r2 = t5;
	} else {
		PHALCON_ALLOC_ZVAL(t6);
		ZVAL_STRING(t6, "", 1);
		r2 = t6;
	}
	PHALCON_CPY_WRT(v4, r2);
	phalcon_debug_assign("$password", r2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_Mysql::connect (If) File=/Db/Mysql Line=53");
	eval_int = phalcon_isset_property(v0, "port", strlen("port") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=53");
		phalcon_step_over("Phalcon_Db_Mysql::connect (Assignment) File=/Db/Mysql Line=54");
		PHALCON_ALLOC_ZVAL(t7);
		phalcon_read_property(t7, v0, "port", sizeof("port")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_concat_vboth(r3, v2, ":", t7 TSRMLS_CC);
		PHALCON_CPY_WRT(v5, r3);
		phalcon_debug_assign("$dbstring", r3 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=55");
		phalcon_step_over("Phalcon_Db_Mysql::connect (Assignment) File=/Db/Mysql Line=56");
		PHALCON_CPY_WRT(v5, v2);
		phalcon_debug_assign("$dbstring", v2 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Db_Mysql::connect (Assignment) File=/Db/Mysql Line=58");
	PHALCON_ALLOC_ZVAL(v6);
	ZVAL_NULL(v6);
	phalcon_step_over("Phalcon_Db_Mysql::connect (If) File=/Db/Mysql Line=59");
	eval_int = phalcon_isset_property(v0, "compression", strlen("compression") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=59");
		phalcon_step_over("Phalcon_Db_Mysql::connect (If) File=/Db/Mysql Line=60");
		PHALCON_ALLOC_ZVAL(t8);
		phalcon_read_property(t8, v0, "compression", sizeof("compression")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(t8)) {
			phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=60");
			phalcon_step_over("Phalcon_Db_Mysql::connect (If) File=/Db/Mysql Line=61");
			if (!zend_is_true(v6)) {
				phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=61");
				phalcon_step_over("Phalcon_Db_Mysql::connect (Assignment) File=/Db/Mysql Line=62");
				PHALCON_ALLOC_ZVAL(t9);
				ZVAL_LONG(t9, 32);
				PHALCON_CPY_WRT(v6, t9);
				phalcon_debug_assign("$clientFlags", t9 TSRMLS_CC);
			} else {
				phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=63");
				phalcon_step_over("Phalcon_Db_Mysql::connect (AssignOp) File=/Db/Mysql Line=64");
				PHALCON_ALLOC_ZVAL(t10);
				ZVAL_LONG(t10, 32);
				PHALCON_ALLOC_ZVAL(r4);
				bitwise_or_function(r4, v6, t10 TSRMLS_CC);
				PHALCON_CPY_WRT(v6, r4);
				phalcon_debug_assign("$clientFlags", r4 TSRMLS_CC);
			}
		}
	}
	phalcon_step_over("Phalcon_Db_Mysql::connect (If) File=/Db/Mysql Line=68");
	eval_int = phalcon_isset_property(v0, "ssl", strlen("ssl") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=68");
		phalcon_step_over("Phalcon_Db_Mysql::connect (If) File=/Db/Mysql Line=69");
		PHALCON_ALLOC_ZVAL(t11);
		phalcon_read_property(t11, v0, "ssl", sizeof("ssl")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(t11)) {
			phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=69");
			phalcon_step_over("Phalcon_Db_Mysql::connect (If) File=/Db/Mysql Line=70");
			if (!zend_is_true(v6)) {
				phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=70");
				phalcon_step_over("Phalcon_Db_Mysql::connect (Assignment) File=/Db/Mysql Line=71");
				PHALCON_ALLOC_ZVAL(t12);
				ZVAL_LONG(t12, 2048);
				PHALCON_CPY_WRT(v6, t12);
				phalcon_debug_assign("$clientFlags", t12 TSRMLS_CC);
			} else {
				phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=72");
				phalcon_step_over("Phalcon_Db_Mysql::connect (AssignOp) File=/Db/Mysql Line=73");
				PHALCON_ALLOC_ZVAL(t13);
				ZVAL_LONG(t13, 2048);
				PHALCON_ALLOC_ZVAL(r5);
				bitwise_or_function(r5, v6, t13 TSRMLS_CC);
				PHALCON_CPY_WRT(v6, r5);
				phalcon_debug_assign("$clientFlags", r5 TSRMLS_CC);
			}
		}
	}
	phalcon_step_over("Phalcon_Db_Mysql::connect (If) File=/Db/Mysql Line=77");
	eval_int = phalcon_isset_property(v0, "interactive", strlen("interactive") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=77");
		phalcon_step_over("Phalcon_Db_Mysql::connect (If) File=/Db/Mysql Line=78");
		PHALCON_ALLOC_ZVAL(t14);
		phalcon_read_property(t14, v0, "interactive", sizeof("interactive")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(t14)) {
			phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=78");
			phalcon_step_over("Phalcon_Db_Mysql::connect (If) File=/Db/Mysql Line=79");
			if (!zend_is_true(v6)) {
				phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=79");
				phalcon_step_over("Phalcon_Db_Mysql::connect (Assignment) File=/Db/Mysql Line=80");
				PHALCON_ALLOC_ZVAL(t15);
				ZVAL_LONG(t15, 1024);
				PHALCON_CPY_WRT(v6, t15);
				phalcon_debug_assign("$clientFlags", t15 TSRMLS_CC);
			} else {
				phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=81");
				phalcon_step_over("Phalcon_Db_Mysql::connect (AssignOp) File=/Db/Mysql Line=82");
				PHALCON_ALLOC_ZVAL(t16);
				ZVAL_LONG(t16, 1024);
				PHALCON_ALLOC_ZVAL(r6);
				bitwise_or_function(r6, v6, t16 TSRMLS_CC);
				PHALCON_CPY_WRT(v6, r6);
				phalcon_debug_assign("$clientFlags", r6 TSRMLS_CC);
			}
		}
	}
	phalcon_step_over("Phalcon_Db_Mysql::connect (If) File=/Db/Mysql Line=86");
	if (!zend_is_true(v1)) {
		phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=86");
		phalcon_step_over("Phalcon_Db_Mysql::connect (Assignment) File=/Db/Mysql Line=87");
		PHALCON_ALLOC_ZVAL(r7);
		p0[0] = v5;
		phalcon_debug_param(v5 TSRMLS_CC);
		p0[1] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		p0[2] = v4;
		phalcon_debug_param(v4 TSRMLS_CC);
		PHALCON_PARAM_BOOL(p0[3], 1);
		p0[4] = v6;
		phalcon_debug_param(v6 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r7, "mysql_connect", 5, p0);
		phalcon_debug_vdump("mysql_connect > ", r7 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r7, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_idConnection", strlen("_idConnection"), copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=88");
		phalcon_step_over("Phalcon_Db_Mysql::connect (Assignment) File=/Db/Mysql Line=89");
		PHALCON_ALLOC_ZVAL(r8);
		p1[0] = v5;
		phalcon_debug_param(v5 TSRMLS_CC);
		p1[1] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		p1[2] = v4;
		phalcon_debug_param(v4 TSRMLS_CC);
		p1[3] = v6;
		phalcon_debug_param(v6 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r8, "mysql_pconnect", 4, p1);
		phalcon_debug_vdump("mysql_pconnect > ", r8 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r8, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_idConnection", strlen("_idConnection"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Db_Mysql::connect (If) File=/Db/Mysql Line=91");
	PHALCON_ALLOC_ZVAL(t17);
	phalcon_read_property(t17, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t17)) {
		phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=91");
		phalcon_step_over("Phalcon_Db_Mysql::connect (Assignment) File=/Db/Mysql Line=92");
		eval_int = phalcon_isset_property(v0, "name", strlen("name") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(t18);
			phalcon_read_property(t18, v0, "name", sizeof("name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			r9 = t18;
		} else {
			PHALCON_ALLOC_ZVAL(t19);
			ZVAL_STRING(t19, "", 1);
			r9 = t19;
		}
		PHALCON_CPY_WRT(v7, r9);
		phalcon_debug_assign("$dbname", r9 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_Mysql::connect (If) File=/Db/Mysql Line=93");
		PHALCON_ALLOC_ZVAL(t20);
		ZVAL_STRING(t20, "", 1);
		PHALCON_ALLOC_ZVAL(r10);
		is_not_identical_function(r10, t20, v7 TSRMLS_CC);
		if (zend_is_true(r10)) {
			phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=93");
			phalcon_step_over("Phalcon_Db_Mysql::connect (If) File=/Db/Mysql Line=94");
			PHALCON_ALLOC_ZVAL(r11);
			p2[0] = v7;
			phalcon_debug_param(v7 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(t21);
			phalcon_read_property(t21, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			p2[1] = t21;
			phalcon_debug_param(t21 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r11, "mysql_select_db", 2, p2);
			phalcon_debug_vdump("mysql_select_db > ", r11 TSRMLS_CC);
			if (!zend_is_true(r11)) {
				phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=94");
				phalcon_step_over("Phalcon_Db_Mysql::connect (Throw) File=/Db/Mysql Line=95");
				PHALCON_ALLOC_ZVAL(i0);
				object_init_ex(i0, phalcon_db_exception_class_entry);
				phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
				phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r12);
				phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
				phalcon_debug_method_call(this_ptr, "error" TSRMLS_CC);
				PHALCON_CALL_METHOD(r12, this_ptr, "error", PHALCON_CALL_DEFAULT);
				phalcon_debug_vdump("MethodReturn > ", r12 TSRMLS_CC);
				phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
				Z_ADDREF_P(r12);
				p3[0] = r12;
				phalcon_debug_param(r12 TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r13);
				phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
				phalcon_debug_method_call(this_ptr, "noerror" TSRMLS_CC);
				PHALCON_CALL_METHOD(r13, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
				phalcon_debug_vdump("MethodReturn > ", r13 TSRMLS_CC);
				phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
				Z_ADDREF_P(r13);
				p3[1] = r13;
				phalcon_debug_param(r13 TSRMLS_CC);
				PHALCON_PARAM_BOOL(p3[2], 0);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 3, p3, PHALCON_CALL_CHECK);
				phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				return;
			}
		}
		phalcon_step_over("Phalcon_Db_Mysql::connect (Assignment) File=/Db/Mysql Line=98");
		eval_int = phalcon_isset_property(v0, "autocommit", strlen("autocommit") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(t22);
			phalcon_read_property(t22, v0, "autocommit", sizeof("autocommit")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			r14 = t22;
		} else {
			PHALCON_ALLOC_ZVAL(t23);
			ZVAL_BOOL(t23, 0);
			r14 = t23;
		}
		PHALCON_CPY_WRT(v8, r14);
		phalcon_debug_assign("$autocommit", r14 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_Mysql::connect (Assignment) File=/Db/Mysql Line=99");
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v8, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_autoCommit", strlen("_autoCommit"), copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Db_Mysql::connect (Assignment) File=/Db/Mysql Line=100");
		PHALCON_ALLOC_ZVAL(t24);
		ZVAL_LONG(t24, 3);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t24, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Db_Mysql::connect (StaticMethodCall) File=/Db/Mysql Line=101");
		Z_ADDREF_P(v0);
		p6[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Db_Mysql", "__construct", 1, p6);
		phalcon_step_over("Phalcon_Db_Mysql::connect (If) File=/Db/Mysql Line=103");
		eval_int = phalcon_isset_property(v0, "charset", strlen("charset") TSRMLS_CC);
		if (eval_int) {
			phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=103");
			phalcon_step_over("Phalcon_Db_Mysql::connect (MethodCall) File=/Db/Mysql Line=104");
			phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "query" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(t25);
			phalcon_read_property(t25, v0, "charset", sizeof("charset")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r15);
			PHALCON_CONCAT_LEFT(r15, "SET NAMES ", t25);
			Z_ADDREF_P(r15);
			p7[0] = r15;
			phalcon_debug_param(r15 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "query", 1, p7, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Db_Mysql::connect (If) File=/Db/Mysql Line=106");
		eval_int = phalcon_isset_property(v0, "collation", strlen("collation") TSRMLS_CC);
		if (eval_int) {
			phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=106");
			phalcon_step_over("Phalcon_Db_Mysql::connect (MethodCall) File=/Db/Mysql Line=107");
			phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "query" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(t26);
			phalcon_read_property(t26, v0, "collation", sizeof("collation")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r16);
			PHALCON_CONCAT_LEFT(r16, "SET collation_connection=", t26);
			Z_ADDREF_P(r16);
			p8[0] = r16;
			phalcon_debug_param(r16 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "query", 1, p8, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
			phalcon_step_over("Phalcon_Db_Mysql::connect (MethodCall) File=/Db/Mysql Line=108");
			phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "query" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(t27);
			phalcon_read_property(t27, v0, "collation", sizeof("collation")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r17);
			PHALCON_CONCAT_LEFT(r17, "SET collation_database=", t27);
			Z_ADDREF_P(r17);
			p9[0] = r17;
			phalcon_debug_param(r17 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "query", 1, p9, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		}
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Db_Mysql::connect (Block) File=/Db/Mysql Line=111");
		phalcon_step_over("Phalcon_Db_Mysql::connect (Throw) File=/Db/Mysql Line=112");
		PHALCON_ALLOC_ZVAL(i1);
		object_init_ex(i1, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r18);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "error" TSRMLS_CC);
		PHALCON_CALL_METHOD(r18, this_ptr, "error", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r18 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		Z_ADDREF_P(r18);
		p10[0] = r18;
		phalcon_debug_param(r18 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r19);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "noerror" TSRMLS_CC);
		PHALCON_CALL_METHOD(r19, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r19 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		Z_ADDREF_P(r19);
		p10[1] = r19;
		phalcon_debug_param(r19 TSRMLS_CC);
		PHALCON_PARAM_BOOL(p10[2], 0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 3, p10, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db_Mysql::connect (Method) File=/Db/Mysql Line=129");
}

PHP_METHOD(Phalcon_Db_Mysql, query){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL, NULL }, *p4[] = { NULL }, *p3[] = { NULL }, *p6[] = { NULL, NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Mysql", "query", 0);
	phalcon_step_over("Phalcon_Db_Mysql::query (Assignment) File=/Db/Mysql Line=130");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v1, t0);
	phalcon_debug_assign("$idConnection", t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_Mysql::query (If) File=/Db/Mysql Line=131");
	if (!zend_is_true(v1)) {
		phalcon_step_over("Phalcon_Db_Mysql::query (Block) File=/Db/Mysql Line=131");
		phalcon_step_over("Phalcon_Db_Mysql::query (MethodCall) File=/Db/Mysql Line=132");
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "connect" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "connect", PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_Mysql::query (If) File=/Db/Mysql Line=133");
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!zend_is_true(t1)) {
			phalcon_step_over("Phalcon_Db_Mysql::query (Block) File=/Db/Mysql Line=133");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	}
	phalcon_step_over("Phalcon_Db_Mysql::query (Assignment) File=/Db/Mysql Line=137");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_lastQuery", strlen("_lastQuery"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Db_Mysql::query (MethodCall) File=/Db/Mysql Line=138");
	phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_beforequery" TSRMLS_CC);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_beforequery", 1, p1, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_Mysql::query (If) File=/Db/Mysql Line=139");
	PHALCON_ALLOC_ZVAL(r0);
	p2[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	p2[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_query", 2, p2);
	phalcon_debug_vdump("mysql_query > ", r0 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r0);
	phalcon_debug_assign("$resultQuery", r0 TSRMLS_CC);
	if (zend_is_true(v2)) {
		phalcon_step_over("Phalcon_Db_Mysql::query (Block) File=/Db/Mysql Line=139");
		phalcon_step_over("Phalcon_Db_Mysql::query (Assignment) File=/Db/Mysql Line=140");
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_lastResultQuery", strlen("_lastResultQuery"), copy TSRMLS_CC);
		}
		phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(v2);
	} else {
		phalcon_step_over("Phalcon_Db_Mysql::query (Block) File=/Db/Mysql Line=142");
		phalcon_step_over("Phalcon_Db_Mysql::query (Assignment) File=/Db/Mysql Line=143");
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_lastResultQuery", strlen("_lastResultQuery"), 0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_Mysql::query (Assignment) File=/Db/Mysql Line=144");
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "error" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r3);
		PHALCON_CONCAT_LEFT(r3, " when executing \"", v0);
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "getconnectionid" TSRMLS_CC);
		PHALCON_PARAM_BOOL(p4[0], 1);
		PHALCON_CALL_METHOD_PARAMS(r4, this_ptr, "getconnectionid", 1, p4, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r4 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_vboth(r2, r3, "\" on connection \"", r4 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r5);
		PHALCON_CONCAT_RIGHT(r5, r2, "\"");
		Z_ADDREF_P(r5);
		p3[0] = r5;
		phalcon_debug_param(r5 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "error", 1, p3, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r1);
		phalcon_debug_assign("$errorMessage", r1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_Mysql::query (Assignment) File=/Db/Mysql Line=145");
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "noerror" TSRMLS_CC);
		PHALCON_CALL_METHOD(r6, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r6 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		PHALCON_CPY_WRT(v4, r6);
		phalcon_debug_assign("$numberError", r6 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_Mysql::query (Throw) File=/Db/Mysql Line=161");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		Z_ADDREF_P(v3);
		p6[0] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r7);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "noerror" TSRMLS_CC);
		PHALCON_CALL_METHOD(r7, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r7 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		Z_ADDREF_P(r7);
		p6[1] = r7;
		phalcon_debug_param(r7 TSRMLS_CC);
		PHALCON_PARAM_BOOL(p6[2], 1);
		Z_ADDREF_P(this_ptr);
		p6[3] = this_ptr;
		phalcon_debug_param(this_ptr TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p6, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db_Mysql::query (Method) File=/Db/Mysql Line=170");
}

PHP_METHOD(Phalcon_Db_Mysql, close){

	zval *t0 = NULL, *t1 = NULL;
	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p1[] = { NULL };
	zend_bool silence;

	phalcon_step_into_entry("Phalcon_Db_Mysql", "close", 0);
	phalcon_step_over("Phalcon_Db_Mysql::close (If) File=/Db/Mysql Line=171");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Db_Mysql::close (Block) File=/Db/Mysql Line=171");
		phalcon_step_over("Phalcon_Db_Mysql::close (StaticMethodCall) File=/Db/Mysql Line=172");
		PHALCON_CALL_PARENT_NORETURN(this_ptr, "Phalcon_Db_Mysql", "close");
		phalcon_step_over("Phalcon_Db_Mysql::close (Assignment) File=/Db/Mysql Line=173");
		silence = PG(display_errors);
		PG(display_errors) = 0;
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t1);
		p1[0] = t1;
		phalcon_debug_param(t1 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r0, "mysql_close", 1, p1);
		phalcon_debug_vdump("mysql_close > ", r0 TSRMLS_CC);
		PG(display_errors) = silence;
		PHALCON_CPY_WRT_PARAM(v0, r0);
		phalcon_debug_assign("$success", r0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_Mysql::close (Assignment) File=/Db/Mysql Line=174");
		zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_idConnection", strlen("_idConnection") TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(v0);
	} else {
		phalcon_step_over("Phalcon_Db_Mysql::close (Block) File=/Db/Mysql Line=176");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db_Mysql::close (Method) File=/Db/Mysql Line=195");
}

PHP_METHOD(Phalcon_Db_Mysql, fetchArray){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Mysql", "fetchArray", 0);
	phalcon_step_over("Phalcon_Db_Mysql::fetchArray (If) File=/Db/Mysql Line=196");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Db_Mysql::fetchArray (Block) File=/Db/Mysql Line=196");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_over("Phalcon_Db_Mysql::fetchArray (If) File=/Db/Mysql Line=199");
	if (!zend_is_true(v0)) {
		phalcon_step_over("Phalcon_Db_Mysql::fetchArray (Block) File=/Db/Mysql Line=199");
		phalcon_step_over("Phalcon_Db_Mysql::fetchArray (Assignment) File=/Db/Mysql Line=200");
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT_PARAM(v0, t1);
		phalcon_debug_assign("$resultQuery", t1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_Mysql::fetchArray (If) File=/Db/Mysql Line=201");
		if (!zend_is_true(v0)) {
			phalcon_step_over("Phalcon_Db_Mysql::fetchArray (Block) File=/Db/Mysql Line=201");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	}
	PHALCON_ALLOC_ZVAL(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_fetchMode", sizeof("_fetchMode")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t2);
	p0[1] = t2;
	phalcon_debug_param(t2 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_fetch_array", 2, p0);
	phalcon_debug_vdump("mysql_fetch_array > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_Mysql::fetchArray (Method) File=/Db/Mysql Line=219");
}

PHP_METHOD(Phalcon_Db_Mysql, numRows){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL;
	zval **pv0;
	zval *p0[] = { NULL }, *p2[] = { NULL }, *p1[] = { NULL, NULL, NULL, NULL };
	zend_bool silence;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Mysql", "numRows", 0);
	phalcon_step_over("Phalcon_Db_Mysql::numRows (If) File=/Db/Mysql Line=220");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Db_Mysql::numRows (Block) File=/Db/Mysql Line=220");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_over("Phalcon_Db_Mysql::numRows (If) File=/Db/Mysql Line=223");
	if (!zend_is_true(v0)) {
		phalcon_step_over("Phalcon_Db_Mysql::numRows (Block) File=/Db/Mysql Line=223");
		phalcon_step_over("Phalcon_Db_Mysql::numRows (Assignment) File=/Db/Mysql Line=224");
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT_PARAM(v0, t1);
		phalcon_debug_assign("$resultQuery", t1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_Mysql::numRows (If) File=/Db/Mysql Line=225");
		if (!zend_is_true(v0)) {
			phalcon_step_over("Phalcon_Db_Mysql::numRows (Block) File=/Db/Mysql Line=225");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	}
	phalcon_step_over("Phalcon_Db_Mysql::numRows (If) File=/Db/Mysql Line=229");
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL(r0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_num_rows", 1, p0);
	phalcon_debug_vdump("mysql_num_rows > ", r0 TSRMLS_CC);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(v1, r0);
	phalcon_debug_assign("$numberRows", r0 TSRMLS_CC);
	if (Z_TYPE_P(v1) != IS_BOOL || (Z_TYPE_P(v1) == IS_BOOL && Z_BVAL_P(v1))) {
		phalcon_step_over("Phalcon_Db_Mysql::numRows (Block) File=/Db/Mysql Line=229");
		phalcon_debug_vdump("Returning > ", v1 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(v1);
	} else {
		phalcon_step_over("Phalcon_Db_Mysql::numRows (Block) File=/Db/Mysql Line=231");
		phalcon_step_over("Phalcon_Db_Mysql::numRows (Throw) File=/Db/Mysql Line=232");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "error" TSRMLS_CC);
		PHALCON_READ_SYMBOL(v2, pv0, "php_errormsg");
		Z_ADDREF_P(v2);
		p2[0] = v2;
		phalcon_debug_param(v2 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "error", 1, p2, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		Z_ADDREF_P(r1);
		p1[0] = r1;
		phalcon_debug_param(r1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "noerror" TSRMLS_CC);
		PHALCON_CALL_METHOD(r2, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		Z_ADDREF_P(r2);
		p1[1] = r2;
		phalcon_debug_param(r2 TSRMLS_CC);
		PHALCON_PARAM_BOOL(p1[2], 1);
		Z_ADDREF_P(this_ptr);
		p1[3] = this_ptr;
		phalcon_debug_param(this_ptr TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_FALSE;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_Mysql::numRows (Method) File=/Db/Mysql Line=249");
}

PHP_METHOD(Phalcon_Db_Mysql, dataSeek){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL;
	zval **pv0;
	zval *p0[] = { NULL, NULL }, *p2[] = { NULL }, *p1[] = { NULL, NULL };
	zend_bool silence;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_NULL(v1);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Mysql", "dataSeek", 0);
	phalcon_step_over("Phalcon_Db_Mysql::dataSeek (If) File=/Db/Mysql Line=250");
	if (!zend_is_true(v1)) {
		phalcon_step_over("Phalcon_Db_Mysql::dataSeek (Block) File=/Db/Mysql Line=250");
		phalcon_step_over("Phalcon_Db_Mysql::dataSeek (Assignment) File=/Db/Mysql Line=251");
		PHALCON_ALLOC_ZVAL(t0);
		phalcon_read_property(t0, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT_PARAM(v1, t0);
		phalcon_debug_assign("$resultQuery", t0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_Mysql::dataSeek (If) File=/Db/Mysql Line=252");
		if (!zend_is_true(v1)) {
			phalcon_step_over("Phalcon_Db_Mysql::dataSeek (Block) File=/Db/Mysql Line=252");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	}
	phalcon_step_over("Phalcon_Db_Mysql::dataSeek (If) File=/Db/Mysql Line=256");
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL(r0);
	p0[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	p0[1] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_data_seek", 2, p0);
	phalcon_debug_vdump("mysql_data_seek > ", r0 TSRMLS_CC);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(v2, r0);
	phalcon_debug_assign("$success", r0 TSRMLS_CC);
	if (Z_TYPE_P(v2) != IS_BOOL || (Z_TYPE_P(v2) == IS_BOOL && Z_BVAL_P(v2))) {
		phalcon_step_over("Phalcon_Db_Mysql::dataSeek (Block) File=/Db/Mysql Line=256");
		phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(v2);
	} else {
		phalcon_step_over("Phalcon_Db_Mysql::dataSeek (Block) File=/Db/Mysql Line=258");
		phalcon_step_over("Phalcon_Db_Mysql::dataSeek (Throw) File=/Db/Mysql Line=259");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "error" TSRMLS_CC);
		PHALCON_READ_SYMBOL(v3, pv0, "php_errormsg");
		Z_ADDREF_P(v3);
		p2[0] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "error", 1, p2, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		Z_ADDREF_P(r1);
		p1[0] = r1;
		phalcon_debug_param(r1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "noerror" TSRMLS_CC);
		PHALCON_CALL_METHOD(r2, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		Z_ADDREF_P(r2);
		p1[1] = r2;
		phalcon_debug_param(r2 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p1, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_FALSE;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_Mysql::dataSeek (Method) File=/Db/Mysql Line=275");
}

PHP_METHOD(Phalcon_Db_Mysql, affectedRows){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL;
	zval **pv0;
	zval *p0[] = { NULL }, *p2[] = { NULL }, *p1[] = { NULL, NULL };
	zend_bool silence;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Mysql", "affectedRows", 0);
	phalcon_step_over("Phalcon_Db_Mysql::affectedRows (If) File=/Db/Mysql Line=276");
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	p0[0] = t0;
	phalcon_debug_param(t0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_affected_rows", 1, p0);
	phalcon_debug_vdump("mysql_affected_rows > ", r0 TSRMLS_CC);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(v1, r0);
	phalcon_debug_assign("$numberRows", r0 TSRMLS_CC);
	if (Z_TYPE_P(v1) != IS_BOOL || (Z_TYPE_P(v1) == IS_BOOL && Z_BVAL_P(v1))) {
		phalcon_step_over("Phalcon_Db_Mysql::affectedRows (Block) File=/Db/Mysql Line=276");
		phalcon_debug_vdump("Returning > ", v1 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(v1);
	} else {
		phalcon_step_over("Phalcon_Db_Mysql::affectedRows (Block) File=/Db/Mysql Line=278");
		phalcon_step_over("Phalcon_Db_Mysql::affectedRows (Throw) File=/Db/Mysql Line=279");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "error" TSRMLS_CC);
		PHALCON_READ_SYMBOL(v2, pv0, "php_errormsg");
		Z_ADDREF_P(v2);
		p2[0] = v2;
		phalcon_debug_param(v2 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "error", 1, p2, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		Z_ADDREF_P(r1);
		p1[0] = r1;
		phalcon_debug_param(r1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "noerror" TSRMLS_CC);
		PHALCON_CALL_METHOD(r2, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		Z_ADDREF_P(r2);
		p1[1] = r2;
		phalcon_debug_param(r2 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p1, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_FALSE;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_Mysql::affectedRows (Method) File=/Db/Mysql Line=300");
}

PHP_METHOD(Phalcon_Db_Mysql, setFetchMode){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Mysql", "setFetchMode", 0);
	phalcon_step_over("Phalcon_Db_Mysql::setFetchMode (If) File=/Db/Mysql Line=301");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_get_class_constant(t0, phalcon_db_mysql_class_entry, "DB_ASSOC", strlen("DB_ASSOC") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	is_equal_function(r0, v0, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Db_Mysql::setFetchMode (Block) File=/Db/Mysql Line=301");
		phalcon_step_over("Phalcon_Db_Mysql::setFetchMode (Assignment) File=/Db/Mysql Line=302");
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_LONG(t1, 1);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Db_Mysql::setFetchMode (If) File=/Db/Mysql Line=305");
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_get_class_constant(t2, phalcon_db_mysql_class_entry, "DB_BOTH", strlen("DB_BOTH") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	is_equal_function(r1, v0, t2 TSRMLS_CC);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Db_Mysql::setFetchMode (Block) File=/Db/Mysql Line=305");
		phalcon_step_over("Phalcon_Db_Mysql::setFetchMode (Assignment) File=/Db/Mysql Line=306");
		PHALCON_ALLOC_ZVAL(t3);
		ZVAL_LONG(t3, 3);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t3, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Db_Mysql::setFetchMode (If) File=/Db/Mysql Line=309");
	PHALCON_ALLOC_ZVAL(t4);
	phalcon_get_class_constant(t4, phalcon_db_mysql_class_entry, "DB_NUM", strlen("DB_NUM") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r2);
	is_equal_function(r2, v0, t4 TSRMLS_CC);
	if (zend_is_true(r2)) {
		phalcon_step_over("Phalcon_Db_Mysql::setFetchMode (Block) File=/Db/Mysql Line=309");
		phalcon_step_over("Phalcon_Db_Mysql::setFetchMode (Assignment) File=/Db/Mysql Line=310");
		PHALCON_ALLOC_ZVAL(t5);
		ZVAL_LONG(t5, 2);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t5, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), copy TSRMLS_CC);
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db_Mysql::setFetchMode (Method) File=/Db/Mysql Line=322");
}

PHP_METHOD(Phalcon_Db_Mysql, error){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *p1[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_NULL(v1);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Mysql", "error", 0);
	phalcon_step_over("Phalcon_Db_Mysql::error (If) File=/Db/Mysql Line=323");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Db_Mysql::error (Block) File=/Db/Mysql Line=323");
		phalcon_step_over("Phalcon_Db_Mysql::error (Assignment) File=/Db/Mysql Line=324");
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CALL_FUNC(r0, "mysql_error");
		phalcon_debug_vdump("mysql_error > ", r0 TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r0);
		phalcon_debug_assign("$errorMessage", r0 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Db_Mysql::error (Block) File=/Db/Mysql Line=325");
		phalcon_step_over("Phalcon_Db_Mysql::error (Assignment) File=/Db/Mysql Line=326");
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		p1[0] = t1;
		phalcon_debug_param(t1 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r1, "mysql_error", 1, p1);
		phalcon_debug_vdump("mysql_error > ", r1 TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r1);
		phalcon_debug_assign("$errorMessage", r1 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Db_Mysql::error (If) File=/Db/Mysql Line=328");
	if (zend_is_true(v2)) {
		phalcon_step_over("Phalcon_Db_Mysql::error (Block) File=/Db/Mysql Line=328");
		phalcon_step_over("Phalcon_Db_Mysql::error (Assignment) File=/Db/Mysql Line=329");
		PHALCON_ALLOC_ZVAL(r3);
		PHALCON_CONCAT_LEFT(r3, "\"", v2);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_vboth(r2, r3, "\" ", v0 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_lastError", strlen("_lastError"), copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Db_Mysql::error (Block) File=/Db/Mysql Line=330");
		phalcon_step_over("Phalcon_Db_Mysql::error (Assignment) File=/Db/Mysql Line=331");
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_concat_both(r4,  "[Unknown MySQL error: ", v0, "]" TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r4, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_lastError", strlen("_lastError"), copy TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_lastError", sizeof("_lastError")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t2);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_Mysql::error (Method) File=/Db/Mysql Line=343");
}

PHP_METHOD(Phalcon_Db_Mysql, noError){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_NULL(v0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Mysql", "noError", 0);
	phalcon_step_over("Phalcon_Db_Mysql::noError (If) File=/Db/Mysql Line=344");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Db_Mysql::noError (Block) File=/Db/Mysql Line=344");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t1);
	p0[0] = t1;
	phalcon_debug_param(t1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_errno", 1, p0);
	phalcon_debug_vdump("mysql_errno > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_Mysql::noError (Method) File=/Db/Mysql Line=358");
}

PHP_METHOD(Phalcon_Db_Mysql, lastInsertId){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzz", &v0, &v1, &v2) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "", 0);
	}
	if (!v2) {
		PHALCON_ALLOC_ZVAL(v2);
		ZVAL_STRING(v2, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Mysql", "lastInsertId", 0);
	phalcon_step_over("Phalcon_Db_Mysql::lastInsertId (If) File=/Db/Mysql Line=359");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Db_Mysql::lastInsertId (Block) File=/Db/Mysql Line=359");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	p0[0] = t1;
	phalcon_debug_param(t1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_insert_id", 1, p0);
	phalcon_debug_vdump("mysql_insert_id > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_Mysql::lastInsertId (Method) File=/Db/Mysql Line=374");
}

PHP_METHOD(Phalcon_Db_Mysql, limit){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Mysql", "limit", 0);
	phalcon_step_over("Phalcon_Db_Mysql::limit (If) File=/Db/Mysql Line=375");
	PHALCON_ALLOC_ZVAL(r0);
	Z_ADDREF_P(v1);
	p0[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "is_numeric", 1, p0);
	phalcon_debug_vdump("is_numeric > ", r0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Db_Mysql::limit (Block) File=/Db/Mysql Line=375");
		phalcon_step_over("Phalcon_Db_Mysql::limit (Assignment) File=/Db/Mysql Line=376");
		convert_to_long(v1);
		phalcon_debug_assign("$number", v1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_concat_vboth(r1, v0, " LIMIT ", v1 TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r1 TSRMLS_CC);
		phalcon_step_out_entry();
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(r1);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
			Z_SET_REFCOUNT_P(return_value, refcount);
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Db_Mysql::limit (Block) File=/Db/Mysql Line=378");
		phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
		phalcon_step_out_entry();
		PHALCON_RETURN_CTOR(v0);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db_Mysql::limit (Method) File=/Db/Mysql Line=392");
}

PHP_METHOD(Phalcon_Db_Mysql, tableExists){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL }, *p2[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Mysql", "tableExists", 0);
	phalcon_step_over("Phalcon_Db_Mysql::tableExists (Assignment) File=/Db/Mysql Line=393");
	PHALCON_ALLOC_ZVAL(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "addslashes", 1, p0);
	phalcon_debug_vdump("addslashes > ", r0 TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v0, r0);
	phalcon_debug_assign("$tableName", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_Mysql::tableExists (Assignment) File=/Db/Mysql Line=394");
	PHALCON_ALLOC_ZVAL(r1);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	Z_ADDREF_P(v1);
	p1[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_db_dialect_mysql", "tableexists", 2, p1);
	phalcon_debug_vdump("StaticReturn > ", r1 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r1);
	phalcon_debug_assign("$sql", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_Mysql::tableExists (Assignment) File=/Db/Mysql Line=395");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_fetchMode", sizeof("_fetchMode")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v3, t0);
	phalcon_debug_assign("$fetchMode", t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_Mysql::tableExists (Assignment) File=/Db/Mysql Line=396");
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 2);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Db_Mysql::tableExists (Assignment) File=/Db/Mysql Line=397");
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "fetchone" TSRMLS_CC);
	Z_ADDREF_P(v2);
	p2[0] = v2;
	phalcon_debug_param(v2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "fetchone", 1, p2, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r2);
	phalcon_debug_assign("$num", r2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_Mysql::tableExists (Assignment) File=/Db/Mysql Line=398");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v3, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), copy TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(r3);
	phalcon_array_fetch_long(r3, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(r3);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_Mysql::tableExists (Method) File=/Db/Mysql Line=412");
}

PHP_METHOD(Phalcon_Db_Mysql, viewExists){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Mysql", "viewExists", 0);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "tableexists" TSRMLS_CC);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "tableexists", 2, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_Mysql::viewExists (Method) File=/Db/Mysql Line=425");
}

PHP_METHOD(Phalcon_Db_Mysql, describeTable){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Mysql", "describeTable", 0);
	phalcon_step_over("Phalcon_Db_Mysql::describeTable (Assignment) File=/Db/Mysql Line=426");
	PHALCON_ALLOC_ZVAL(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "describetable", 2, p0);
	phalcon_debug_vdump("StaticReturn > ", r0 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r0);
	phalcon_debug_assign("$sql", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_Mysql::describeTable (Assignment) File=/Db/Mysql Line=427");
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Db_Mysql::describeTable (Assignment) File=/Db/Mysql Line=428");
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "fetchall" TSRMLS_CC);
	Z_ADDREF_P(v2);
	p1[0] = v2;
	phalcon_debug_param(v2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetchall", 1, p1, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r1);
	phalcon_debug_assign("$describe", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_Mysql::describeTable (Assignment) File=/Db/Mysql Line=429");
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 3);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), copy TSRMLS_CC);
	}
	phalcon_debug_vdump("Returning > ", v3 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(v3);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_Mysql::describeTable (Method) File=/Db/Mysql Line=441");
}

PHP_METHOD(Phalcon_Db_Mysql, listTables){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *a0 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Mysql", "listTables", 0);
	phalcon_step_over("Phalcon_Db_Mysql::listTables (Assignment) File=/Db/Mysql Line=442");
	PHALCON_ALLOC_ZVAL(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "listtables", 1, p0);
	phalcon_debug_vdump("StaticReturn > ", r0 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r0);
	phalcon_debug_assign("$sql", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_Mysql::listTables (Assignment) File=/Db/Mysql Line=443");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_fetchMode", sizeof("_fetchMode")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v2, t0);
	phalcon_debug_assign("$fetchMode", t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_Mysql::listTables (Assignment) File=/Db/Mysql Line=444");
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 2);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Db_Mysql::listTables (Assignment) File=/Db/Mysql Line=445");
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "fetchall" TSRMLS_CC);
	Z_ADDREF_P(v1);
	p1[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetchall", 1, p1, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Db_Mysql" TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r1);
	phalcon_debug_assign("$tables", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_Mysql::listTables (Assignment) File=/Db/Mysql Line=446");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v4, a0);
	phalcon_debug_assign("$allTables", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_Mysql::listTables (Foreach) File=/Db/Mysql Line=447");
	FOREACH_V(v3, ac0, fes50, fee50, ah0, hp0, v5)
		phalcon_step_over("Phalcon_Db_Mysql::listTables (Block) File=/Db/Mysql Line=447");
		phalcon_step_over("Phalcon_Db_Mysql::listTables (Assignment) File=/Db/Mysql Line=448");
		if (!r2) {
			PHALCON_ALLOC_ZVAL(r2);
		} else {
			if (Z_REFCOUNT_P(r2) > 1) {
				PHALCON_SEPARATE(r2);
			} else {
				FREE_ZVAL(r2);
				PHALCON_ALLOC_ZVAL(r2);
			}
		}
		phalcon_array_fetch_long(r2, v5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			PHALCON_SEPARATE(v4);
			phalcon_array_append(v4, copy TSRMLS_CC);
		}
	END_FOREACH(ac0, fes50, fee50, ah0, hp0);
	phalcon_step_over("Phalcon_Db_Mysql::listTables (Assignment) File=/Db/Mysql Line=450");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v2, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), copy TSRMLS_CC);
	}
	phalcon_debug_vdump("Returning > ", v4 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v4);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_Mysql::listTables (Method) File=/Db/Mysql Line=461");
}

PHP_METHOD(Phalcon_Db_Mysql, getDateUsingFormat){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "YYYY-MM-DD", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_Mysql", "getDateUsingFormat", 0);
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_concat_both(r0,  "'", v0, "'" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
}

