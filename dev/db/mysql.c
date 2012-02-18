
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

PHP_METHOD(Phalcon_Db_MySQL, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL, NULL };

	phalcon_step_over("Phalcon_Db_MySQL::__construct (Method) File=Library/Phalcon/Db/Mysql.php Line=10");
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	if (!v1) {
		PHALCON_INIT_BOOL(v1, 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_MySQL", "__construct", 0);
	phalcon_step_over("Phalcon_Db_MySQL::__construct (If) File=Library/Phalcon/Db/Mysql.php Line=11");
	//$descriptor
	if (phalcon_compare_strict_string(v0, "")) {
		phalcon_step_over("Phalcon_Db_MySQL::__construct (Block) File=Library/Phalcon/Db/Mysql.php Line=11");
		phalcon_step_over("Phalcon_Db_MySQL::__construct (Assignment) File=Library/Phalcon/Db/Mysql.php Line=12");
		//$descriptor
		//$this
		PHALCON_ALLOC_ZVAL(t0);
		phalcon_read_property(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t0);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(t0);
		v0 = t0;
		phalcon_debug_assign("$descriptor", t0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Db_MySQL::__construct (MethodCall) File=Library/Phalcon/Db/Mysql.php Line=14");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "connect" TSRMLS_CC);
	//$descriptor
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$persistent
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "connect", 2, p0, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db_MySQL::__construct (Method) File=Library/Phalcon/Db/Mysql.php Line=17");
}

PHP_METHOD(Phalcon_Db_MySQL, connect){

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
		PHALCON_INIT_BOOL(v1, 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_MySQL", "connect", 0);
	phalcon_step_over("Phalcon_Db_MySQL::connect (If) File=Library/Phalcon/Db/Mysql.php Line=18");
	//$descriptor
	if (phalcon_compare_strict_string(v0, "")) {
		phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=18");
		phalcon_step_over("Phalcon_Db_MySQL::connect (Assignment) File=Library/Phalcon/Db/Mysql.php Line=19");
		//$descriptor
		//$this
		PHALCON_ALLOC_ZVAL(t0);
		phalcon_read_property(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t0);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(t0);
		v0 = t0;
		phalcon_debug_assign("$descriptor", t0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Db_MySQL::connect (Assignment) File=Library/Phalcon/Db/Mysql.php Line=21");
	//$host
	//$descriptor
	eval_int = phalcon_isset_property(v0, "host", strlen("host") TSRMLS_CC);
	if (eval_int) {
		//$descriptor
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, v0, "host", sizeof("host")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		r0 = t1;
	} else {
		PHALCON_ALLOC_ZVAL(t2);
		ZVAL_STRING(t2, "", 1);
		r0 = t2;
	}
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r0);
	v2 = r0;
	phalcon_debug_assign("$host", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_MySQL::connect (Assignment) File=Library/Phalcon/Db/Mysql.php Line=22");
	//$username
	//$descriptor
	eval_int = phalcon_isset_property(v0, "username", strlen("username") TSRMLS_CC);
	if (eval_int) {
		//$descriptor
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, v0, "username", sizeof("username")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t3);
		r1 = t3;
	} else {
		PHALCON_ALLOC_ZVAL(t4);
		ZVAL_STRING(t4, "", 1);
		r1 = t4;
	}
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(r1);
	v3 = r1;
	phalcon_debug_assign("$username", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_MySQL::connect (Assignment) File=Library/Phalcon/Db/Mysql.php Line=23");
	//$password
	//$descriptor
	eval_int = phalcon_isset_property(v0, "password", strlen("password") TSRMLS_CC);
	if (eval_int) {
		//$descriptor
		PHALCON_ALLOC_ZVAL(t5);
		phalcon_read_property(t5, v0, "password", sizeof("password")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t5);
		r2 = t5;
	} else {
		PHALCON_ALLOC_ZVAL(t6);
		ZVAL_STRING(t6, "", 1);
		r2 = t6;
	}
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(r2);
	v4 = r2;
	phalcon_debug_assign("$password", r2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_MySQL::connect (If) File=Library/Phalcon/Db/Mysql.php Line=24");
	//$descriptor
	eval_int = phalcon_isset_property(v0, "port", strlen("port") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=24");
		phalcon_step_over("Phalcon_Db_MySQL::connect (Assignment) File=Library/Phalcon/Db/Mysql.php Line=25");
		//$dbstring
		//$host
		//$descriptor
		PHALCON_ALLOC_ZVAL(t7);
		phalcon_read_property(t7, v0, "port", sizeof("port")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t7);
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_concat_vboth(r3, v2, ":", t7 TSRMLS_CC);
		if (v5) {
			Z_DELREF_P(v5);
			if (!Z_REFCOUNT_P(v5)) {
				FREE_ZVAL(v5);
			}
		}
		Z_ADDREF_P(r3);
		v5 = r3;
		phalcon_debug_assign("$dbstring", r3 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=26");
		phalcon_step_over("Phalcon_Db_MySQL::connect (Assignment) File=Library/Phalcon/Db/Mysql.php Line=27");
		//$dbstring
		//$host
		if (v5) {
			Z_DELREF_P(v5);
			if (!Z_REFCOUNT_P(v5)) {
				FREE_ZVAL(v5);
			}
		}
		Z_ADDREF_P(v2);
		v5 = v2;
		phalcon_debug_assign("$dbstring", v2 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Db_MySQL::connect (Assignment) File=Library/Phalcon/Db/Mysql.php Line=29");
	//$clientFlags
	PHALCON_INIT_NULL(v6);
	phalcon_step_over("Phalcon_Db_MySQL::connect (If) File=Library/Phalcon/Db/Mysql.php Line=30");
	//$descriptor
	eval_int = phalcon_isset_property(v0, "compression", strlen("compression") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=30");
		phalcon_step_over("Phalcon_Db_MySQL::connect (If) File=Library/Phalcon/Db/Mysql.php Line=31");
		//$descriptor
		PHALCON_ALLOC_ZVAL(t8);
		phalcon_read_property(t8, v0, "compression", sizeof("compression")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t8);
		if (zend_is_true(t8)) {
			phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=31");
			phalcon_step_over("Phalcon_Db_MySQL::connect (If) File=Library/Phalcon/Db/Mysql.php Line=32");
			//$clientFlags
			if (Z_TYPE_P(v6) == IS_NULL) {
				phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=32");
				phalcon_step_over("Phalcon_Db_MySQL::connect (Assignment) File=Library/Phalcon/Db/Mysql.php Line=33");
				//$clientFlags
				//Wasted infer Constant MYSQL_CLIENT_COMPRESS
				PHALCON_ALLOC_ZVAL(t9);
				ZVAL_LONG(t9, 32);
				if (v6) {
					Z_DELREF_P(v6);
					if (!Z_REFCOUNT_P(v6)) {
						FREE_ZVAL(v6);
					}
				}
				Z_ADDREF_P(t9);
				v6 = t9;
				phalcon_debug_assign("$clientFlags", t9 TSRMLS_CC);
			} else {
				phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=34");
				phalcon_step_over("Phalcon_Db_MySQL::connect (AssignOp) File=Library/Phalcon/Db/Mysql.php Line=35");
				//$clientFlags
				PHALCON_ALLOC_ZVAL(t10);
				ZVAL_LONG(t10, 32);
				PHALCON_BITWISE_OR_FUNCTION(r4, v6, t10);
				//$clientFlags
				if (v6) {
					Z_DELREF_P(v6);
					if (!Z_REFCOUNT_P(v6)) {
						FREE_ZVAL(v6);
					}
				}
				Z_ADDREF_P(r4);
				v6 = r4;
				phalcon_debug_assign("$clientFlags", r4 TSRMLS_CC);
			}
		}
	}
	phalcon_step_over("Phalcon_Db_MySQL::connect (If) File=Library/Phalcon/Db/Mysql.php Line=39");
	//$descriptor
	eval_int = phalcon_isset_property(v0, "ssl", strlen("ssl") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=39");
		phalcon_step_over("Phalcon_Db_MySQL::connect (If) File=Library/Phalcon/Db/Mysql.php Line=40");
		//$descriptor
		PHALCON_ALLOC_ZVAL(t11);
		phalcon_read_property(t11, v0, "ssl", sizeof("ssl")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t11);
		if (zend_is_true(t11)) {
			phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=40");
			phalcon_step_over("Phalcon_Db_MySQL::connect (If) File=Library/Phalcon/Db/Mysql.php Line=41");
			//$clientFlags
			if (Z_TYPE_P(v6) == IS_NULL) {
				phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=41");
				phalcon_step_over("Phalcon_Db_MySQL::connect (Assignment) File=Library/Phalcon/Db/Mysql.php Line=42");
				//$clientFlags
				//Wasted infer Constant MYSQL_CLIENT_SSL
				PHALCON_ALLOC_ZVAL(t12);
				ZVAL_LONG(t12, 2048);
				if (v6) {
					Z_DELREF_P(v6);
					if (!Z_REFCOUNT_P(v6)) {
						FREE_ZVAL(v6);
					}
				}
				Z_ADDREF_P(t12);
				v6 = t12;
				phalcon_debug_assign("$clientFlags", t12 TSRMLS_CC);
			} else {
				phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=43");
				phalcon_step_over("Phalcon_Db_MySQL::connect (AssignOp) File=Library/Phalcon/Db/Mysql.php Line=44");
				//$clientFlags
				PHALCON_ALLOC_ZVAL(t13);
				ZVAL_LONG(t13, 2048);
				PHALCON_BITWISE_OR_FUNCTION(r5, v6, t13);
				//$clientFlags
				if (v6) {
					Z_DELREF_P(v6);
					if (!Z_REFCOUNT_P(v6)) {
						FREE_ZVAL(v6);
					}
				}
				Z_ADDREF_P(r5);
				v6 = r5;
				phalcon_debug_assign("$clientFlags", r5 TSRMLS_CC);
			}
		}
	}
	phalcon_step_over("Phalcon_Db_MySQL::connect (If) File=Library/Phalcon/Db/Mysql.php Line=48");
	//$descriptor
	eval_int = phalcon_isset_property(v0, "interactive", strlen("interactive") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=48");
		phalcon_step_over("Phalcon_Db_MySQL::connect (If) File=Library/Phalcon/Db/Mysql.php Line=49");
		//$descriptor
		PHALCON_ALLOC_ZVAL(t14);
		phalcon_read_property(t14, v0, "interactive", sizeof("interactive")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t14);
		if (zend_is_true(t14)) {
			phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=49");
			phalcon_step_over("Phalcon_Db_MySQL::connect (If) File=Library/Phalcon/Db/Mysql.php Line=50");
			//$clientFlags
			if (Z_TYPE_P(v6) == IS_NULL) {
				phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=50");
				phalcon_step_over("Phalcon_Db_MySQL::connect (Assignment) File=Library/Phalcon/Db/Mysql.php Line=51");
				//$clientFlags
				//Wasted infer Constant MYSQL_CLIENT_INTERACTIVE
				PHALCON_ALLOC_ZVAL(t15);
				ZVAL_LONG(t15, 1024);
				if (v6) {
					Z_DELREF_P(v6);
					if (!Z_REFCOUNT_P(v6)) {
						FREE_ZVAL(v6);
					}
				}
				Z_ADDREF_P(t15);
				v6 = t15;
				phalcon_debug_assign("$clientFlags", t15 TSRMLS_CC);
			} else {
				phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=52");
				phalcon_step_over("Phalcon_Db_MySQL::connect (AssignOp) File=Library/Phalcon/Db/Mysql.php Line=53");
				//$clientFlags
				PHALCON_ALLOC_ZVAL(t16);
				ZVAL_LONG(t16, 1024);
				PHALCON_BITWISE_OR_FUNCTION(r6, v6, t16);
				//$clientFlags
				if (v6) {
					Z_DELREF_P(v6);
					if (!Z_REFCOUNT_P(v6)) {
						FREE_ZVAL(v6);
					}
				}
				Z_ADDREF_P(r6);
				v6 = r6;
				phalcon_debug_assign("$clientFlags", r6 TSRMLS_CC);
			}
		}
	}
	phalcon_step_over("Phalcon_Db_MySQL::connect (If) File=Library/Phalcon/Db/Mysql.php Line=57");
	//$persistent
	if (!zend_is_true(v1)) {
		phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=57");
		phalcon_step_over("Phalcon_Db_MySQL::connect (Assignment) File=Library/Phalcon/Db/Mysql.php Line=58");
		PHALCON_ALLOC_ZVAL(r7);
		//$dbstring
		p0[0] = v5;
		phalcon_debug_param(v5 TSRMLS_CC);
		//$username
		p0[1] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		//$password
		p0[2] = v4;
		phalcon_debug_param(v4 TSRMLS_CC);
		PHALCON_PARAM_BOOL(p0[3], 1);
		//$clientFlags
		p0[4] = v6;
		phalcon_debug_param(v6 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r7, "mysql_connect", 5, p0);
		phalcon_debug_vdump("mysql_connect > ", r7 TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r7, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_idConnection", strlen("_idConnection"), copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=59");
		phalcon_step_over("Phalcon_Db_MySQL::connect (Assignment) File=Library/Phalcon/Db/Mysql.php Line=60");
		PHALCON_ALLOC_ZVAL(r8);
		//$dbstring
		p1[0] = v5;
		phalcon_debug_param(v5 TSRMLS_CC);
		//$username
		p1[1] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		//$password
		p1[2] = v4;
		phalcon_debug_param(v4 TSRMLS_CC);
		//$clientFlags
		p1[3] = v6;
		phalcon_debug_param(v6 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r8, "mysql_pconnect", 4, p1);
		phalcon_debug_vdump("mysql_pconnect > ", r8 TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r8, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_idConnection", strlen("_idConnection"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Db_MySQL::connect (If) File=Library/Phalcon/Db/Mysql.php Line=62");
	//$this
	PHALCON_ALLOC_ZVAL(t17);
	phalcon_read_property(t17, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t17);
	if (zend_is_true(t17)) {
		phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=62");
		phalcon_step_over("Phalcon_Db_MySQL::connect (Assignment) File=Library/Phalcon/Db/Mysql.php Line=63");
		//$dbname
		//$descriptor
		eval_int = phalcon_isset_property(v0, "name", strlen("name") TSRMLS_CC);
		if (eval_int) {
			//$descriptor
			PHALCON_ALLOC_ZVAL(t18);
			phalcon_read_property(t18, v0, "name", sizeof("name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t18);
			r9 = t18;
		} else {
			PHALCON_ALLOC_ZVAL(t19);
			ZVAL_STRING(t19, "", 1);
			r9 = t19;
		}
		if (v7) {
			Z_DELREF_P(v7);
			if (!Z_REFCOUNT_P(v7)) {
				FREE_ZVAL(v7);
			}
		}
		Z_ADDREF_P(r9);
		v7 = r9;
		phalcon_debug_assign("$dbname", r9 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_MySQL::connect (If) File=Library/Phalcon/Db/Mysql.php Line=64");
		//$dbname
		PHALCON_ALLOC_ZVAL(t20);
		ZVAL_STRING(t20, "", 1);
		PHALCON_NOT_IDENTICAL_FUNCTION(r10, v7, t20);
		if (zend_is_true(r10)) {
			phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=64");
			phalcon_step_over("Phalcon_Db_MySQL::connect (If) File=Library/Phalcon/Db/Mysql.php Line=65");
			PHALCON_ALLOC_ZVAL(r11);
			//$dbname
			p2[0] = v7;
			phalcon_debug_param(v7 TSRMLS_CC);
			//$this
			PHALCON_ALLOC_ZVAL(t21);
			phalcon_read_property(t21, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t21);
			p2[1] = t21;
			phalcon_debug_param(t21 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r11, "mysql_select_db", 2, p2);
			phalcon_debug_vdump("mysql_select_db > ", r11 TSRMLS_CC);
			if (!zend_is_true(r11)) {
				phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=65");
				phalcon_step_over("Phalcon_Db_MySQL::connect (Throw) File=Library/Phalcon/Db/Mysql.php Line=66");
				PHALCON_ALLOC_ZVAL(i0);
				object_init_ex(i0, phalcon_db_exception_class_entry);
				phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
				phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r12);
				//$this
				phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
				phalcon_debug_method_call(this_ptr, "error" TSRMLS_CC);
				PHALCON_CALL_METHOD(r12, this_ptr, "error", PHALCON_CALL_DEFAULT);
				phalcon_debug_vdump("MethodReturn > ", r12 TSRMLS_CC);
				phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
				Z_ADDREF_P(r12);
				p3[0] = r12;
				phalcon_debug_param(r12 TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r13);
				//$this
				phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
				phalcon_debug_method_call(this_ptr, "noerror" TSRMLS_CC);
				PHALCON_CALL_METHOD(r13, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
				phalcon_debug_vdump("MethodReturn > ", r13 TSRMLS_CC);
				phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
				Z_ADDREF_P(r13);
				p3[1] = r13;
				phalcon_debug_param(r13 TSRMLS_CC);
				PHALCON_PARAM_BOOL(p3[2], 0);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 3, p3, PHALCON_CALL_CHECK);
				phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				return;
			}
		}
		phalcon_step_over("Phalcon_Db_MySQL::connect (Assignment) File=Library/Phalcon/Db/Mysql.php Line=69");
		//$autocommit
		//$descriptor
		eval_int = phalcon_isset_property(v0, "autocommit", strlen("autocommit") TSRMLS_CC);
		if (eval_int) {
			//$descriptor
			PHALCON_ALLOC_ZVAL(t22);
			phalcon_read_property(t22, v0, "autocommit", sizeof("autocommit")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t22);
			r14 = t22;
		} else {
			PHALCON_INIT_FALSE(t23);
			r14 = t23;
		}
		if (v8) {
			Z_DELREF_P(v8);
			if (!Z_REFCOUNT_P(v8)) {
				FREE_ZVAL(v8);
			}
		}
		Z_ADDREF_P(r14);
		v8 = r14;
		phalcon_debug_assign("$autocommit", r14 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_MySQL::connect (Assignment) File=Library/Phalcon/Db/Mysql.php Line=70");
		//$autocommit
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v8, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_autoCommit", strlen("_autoCommit"), copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Db_MySQL::connect (Assignment) File=Library/Phalcon/Db/Mysql.php Line=71");
		//Wasted infer Constant MYSQL_BOTH
		PHALCON_ALLOC_ZVAL(t24);
		ZVAL_LONG(t24, 3);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t24, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Db_MySQL::connect (StaticMethodCall) File=Library/Phalcon/Db/Mysql.php Line=72");
		//$descriptor
		Z_ADDREF_P(v0);
		p6[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Db_MySQL", "__construct", 1, p6);
		phalcon_step_over("Phalcon_Db_MySQL::connect (If) File=Library/Phalcon/Db/Mysql.php Line=74");
		//$descriptor
		eval_int = phalcon_isset_property(v0, "charset", strlen("charset") TSRMLS_CC);
		if (eval_int) {
			phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=74");
			phalcon_step_over("Phalcon_Db_MySQL::connect (MethodCall) File=Library/Phalcon/Db/Mysql.php Line=75");
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "query" TSRMLS_CC);
			//$descriptor
			PHALCON_ALLOC_ZVAL(t25);
			phalcon_read_property(t25, v0, "charset", sizeof("charset")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t25);
			PHALCON_ALLOC_ZVAL(r15);
			phalcon_concat_left(r15, "SET NAMES ", t25 TSRMLS_CC);
			Z_ADDREF_P(r15);
			p7[0] = r15;
			phalcon_debug_param(r15 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "query", 1, p7, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Db_MySQL::connect (If) File=Library/Phalcon/Db/Mysql.php Line=77");
		//$descriptor
		eval_int = phalcon_isset_property(v0, "collation", strlen("collation") TSRMLS_CC);
		if (eval_int) {
			phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=77");
			phalcon_step_over("Phalcon_Db_MySQL::connect (MethodCall) File=Library/Phalcon/Db/Mysql.php Line=78");
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "query" TSRMLS_CC);
			//$descriptor
			PHALCON_ALLOC_ZVAL(t26);
			phalcon_read_property(t26, v0, "collation", sizeof("collation")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t26);
			PHALCON_ALLOC_ZVAL(r16);
			phalcon_concat_left(r16, "SET collation_connection=", t26 TSRMLS_CC);
			Z_ADDREF_P(r16);
			p8[0] = r16;
			phalcon_debug_param(r16 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "query", 1, p8, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
			phalcon_step_over("Phalcon_Db_MySQL::connect (MethodCall) File=Library/Phalcon/Db/Mysql.php Line=79");
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "query" TSRMLS_CC);
			//$descriptor
			PHALCON_ALLOC_ZVAL(t27);
			phalcon_read_property(t27, v0, "collation", sizeof("collation")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t27);
			PHALCON_ALLOC_ZVAL(r17);
			phalcon_concat_left(r17, "SET collation_database=", t27 TSRMLS_CC);
			Z_ADDREF_P(r17);
			p9[0] = r17;
			phalcon_debug_param(r17 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "query", 1, p9, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		}
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Db_MySQL::connect (Block) File=Library/Phalcon/Db/Mysql.php Line=82");
		phalcon_step_over("Phalcon_Db_MySQL::connect (Throw) File=Library/Phalcon/Db/Mysql.php Line=83");
		PHALCON_ALLOC_ZVAL(i1);
		object_init_ex(i1, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r18);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "error" TSRMLS_CC);
		PHALCON_CALL_METHOD(r18, this_ptr, "error", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r18 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		Z_ADDREF_P(r18);
		p10[0] = r18;
		phalcon_debug_param(r18 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r19);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "noerror" TSRMLS_CC);
		PHALCON_CALL_METHOD(r19, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r19 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		Z_ADDREF_P(r19);
		p10[1] = r19;
		phalcon_debug_param(r19 TSRMLS_CC);
		PHALCON_PARAM_BOOL(p10[2], 0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 3, p10, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db_MySQL::connect (Method) File=Library/Phalcon/Db/Mysql.php Line=87");
}

PHP_METHOD(Phalcon_Db_MySQL, query){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL, NULL }, *p3[] = { NULL }, *p2[] = { NULL }, *p5[] = { NULL, NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_MySQL", "query", 0);
	phalcon_step_over("Phalcon_Db_MySQL::query (If) File=Library/Phalcon/Db/Mysql.php Line=88");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Db_MySQL::query (Block) File=Library/Phalcon/Db/Mysql.php Line=88");
		phalcon_step_over("Phalcon_Db_MySQL::query (MethodCall) File=Library/Phalcon/Db/Mysql.php Line=89");
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "connect" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "connect", PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_MySQL::query (If) File=Library/Phalcon/Db/Mysql.php Line=90");
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		if (!zend_is_true(t1)) {
			phalcon_step_over("Phalcon_Db_MySQL::query (Block) File=Library/Phalcon/Db/Mysql.php Line=90");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	}
	phalcon_step_over("Phalcon_Db_MySQL::query (Assignment) File=Library/Phalcon/Db/Mysql.php Line=94");
	//$sqlStatement
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_lastQuery", strlen("_lastQuery"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Db_MySQL::query (If) File=Library/Phalcon/Db/Mysql.php Line=95");
	//$resultQuery
	PHALCON_ALLOC_ZVAL(r0);
	//$sqlStatement
	p1[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$this
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
	p1[1] = t2;
	phalcon_debug_param(t2 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_query", 2, p1);
	phalcon_debug_vdump("mysql_query > ", r0 TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_debug_assign("$resultQuery", r0 TSRMLS_CC);
	if (zend_is_true(v1)) {
		phalcon_step_over("Phalcon_Db_MySQL::query (Block) File=Library/Phalcon/Db/Mysql.php Line=95");
		phalcon_step_over("Phalcon_Db_MySQL::query (Assignment) File=Library/Phalcon/Db/Mysql.php Line=96");
		//$resultQuery
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_lastResultQuery", strlen("_lastResultQuery"), copy TSRMLS_CC);
		}
		//$resultQuery
		phalcon_debug_vdump("Returning > ", v1 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(v1) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v1);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v1);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Db_MySQL::query (Block) File=Library/Phalcon/Db/Mysql.php Line=98");
		phalcon_step_over("Phalcon_Db_MySQL::query (Assignment) File=Library/Phalcon/Db/Mysql.php Line=99");
		//$this
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_lastResultQuery", strlen("_lastResultQuery"), 0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_MySQL::query (Assignment) File=Library/Phalcon/Db/Mysql.php Line=100");
		//$errorMessage
		PHALCON_ALLOC_ZVAL(r1);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "error" TSRMLS_CC);
		//$sqlStatement
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_concat_left(r3, " when executing \"", v0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r4);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "getconnectionid" TSRMLS_CC);
		PHALCON_PARAM_BOOL(p3[0], 1);
		PHALCON_CALL_METHOD_PARAMS(r4, this_ptr, "getconnectionid", 1, p3, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r4 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_vboth(r2, r3, "\" on connection \"", r4 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r5);
		phalcon_concat_right(r5, r2, "\"" TSRMLS_CC);
		Z_ADDREF_P(r5);
		p2[0] = r5;
		phalcon_debug_param(r5 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "error", 1, p2, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(r1);
		v2 = r1;
		phalcon_debug_assign("$errorMessage", r1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_MySQL::query (Assignment) File=Library/Phalcon/Db/Mysql.php Line=101");
		//$numberError
		PHALCON_ALLOC_ZVAL(r6);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "noerror" TSRMLS_CC);
		PHALCON_CALL_METHOD(r6, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r6 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r6);
		v3 = r6;
		phalcon_debug_assign("$numberError", r6 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_MySQL::query (Throw) File=Library/Phalcon/Db/Mysql.php Line=117");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		//$errorMessage
		Z_ADDREF_P(v2);
		p5[0] = v2;
		phalcon_debug_param(v2 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r7);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "noerror" TSRMLS_CC);
		PHALCON_CALL_METHOD(r7, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r7 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		Z_ADDREF_P(r7);
		p5[1] = r7;
		phalcon_debug_param(r7 TSRMLS_CC);
		PHALCON_PARAM_BOOL(p5[2], 1);
		//$this
		Z_ADDREF_P(this_ptr);
		p5[3] = this_ptr;
		phalcon_debug_param(this_ptr TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p5, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db_MySQL::query (Method) File=Library/Phalcon/Db/Mysql.php Line=121");
}

PHP_METHOD(Phalcon_Db_MySQL, close){

	zval *t0 = NULL, *t1 = NULL;
	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p1[] = { NULL };
	zend_bool silence;

	phalcon_step_into_entry("Phalcon_Db_MySQL", "close", 0);
	phalcon_step_over("Phalcon_Db_MySQL::close (If) File=Library/Phalcon/Db/Mysql.php Line=122");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Db_MySQL::close (Block) File=Library/Phalcon/Db/Mysql.php Line=122");
		phalcon_step_over("Phalcon_Db_MySQL::close (StaticMethodCall) File=Library/Phalcon/Db/Mysql.php Line=123");
		PHALCON_CALL_PARENT_NORETURN(this_ptr, "Phalcon_Db_MySQL", "close");
		phalcon_step_over("Phalcon_Db_MySQL::close (Assignment) File=Library/Phalcon/Db/Mysql.php Line=124");
		//$success
		silence = PG(display_errors);
		PG(display_errors) = 0;
		PHALCON_ALLOC_ZVAL(r0);
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		Z_ADDREF_P(t1);
		p1[0] = t1;
		phalcon_debug_param(t1 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r0, "mysql_close", 1, p1);
		phalcon_debug_vdump("mysql_close > ", r0 TSRMLS_CC);
		PG(display_errors) = silence;
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(r0);
		v0 = r0;
		phalcon_debug_assign("$success", r0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_MySQL::close (Assignment) File=Library/Phalcon/Db/Mysql.php Line=125");
		//$this
		zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_idConnection", strlen("_idConnection") TSRMLS_CC);
		//$success
		phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(v0) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v0);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v0);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Db_MySQL::close (Block) File=Library/Phalcon/Db/Mysql.php Line=127");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db_MySQL::close (Method) File=Library/Phalcon/Db/Mysql.php Line=132");
}

PHP_METHOD(Phalcon_Db_MySQL, fetchArray){

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
	phalcon_step_into_entry("Phalcon_Db_MySQL", "fetchArray", 0);
	phalcon_step_over("Phalcon_Db_MySQL::fetchArray (If) File=Library/Phalcon/Db/Mysql.php Line=133");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Db_MySQL::fetchArray (Block) File=Library/Phalcon/Db/Mysql.php Line=133");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_over("Phalcon_Db_MySQL::fetchArray (If) File=Library/Phalcon/Db/Mysql.php Line=136");
	//$resultQuery
	if (!zend_is_true(v0)) {
		phalcon_step_over("Phalcon_Db_MySQL::fetchArray (Block) File=Library/Phalcon/Db/Mysql.php Line=136");
		phalcon_step_over("Phalcon_Db_MySQL::fetchArray (Assignment) File=Library/Phalcon/Db/Mysql.php Line=137");
		//$resultQuery
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(t1);
		v0 = t1;
		phalcon_debug_assign("$resultQuery", t1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_MySQL::fetchArray (If) File=Library/Phalcon/Db/Mysql.php Line=138");
		//$resultQuery
		if (!zend_is_true(v0)) {
			phalcon_step_over("Phalcon_Db_MySQL::fetchArray (Block) File=Library/Phalcon/Db/Mysql.php Line=138");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	}
	PHALCON_ALLOC_ZVAL(r0);
	//$resultQuery
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$this
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_fetchMode", sizeof("_fetchMode")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
	Z_ADDREF_P(t2);
	p0[1] = t2;
	phalcon_debug_param(t2 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_fetch_array", 2, p0);
	phalcon_debug_vdump("mysql_fetch_array > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_MySQL::fetchArray (Method) File=Library/Phalcon/Db/Mysql.php Line=145");
}

PHP_METHOD(Phalcon_Db_MySQL, numRows){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
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
	phalcon_step_into_entry("Phalcon_Db_MySQL", "numRows", 0);
	phalcon_step_over("Phalcon_Db_MySQL::numRows (If) File=Library/Phalcon/Db/Mysql.php Line=146");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Db_MySQL::numRows (Block) File=Library/Phalcon/Db/Mysql.php Line=146");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_over("Phalcon_Db_MySQL::numRows (If) File=Library/Phalcon/Db/Mysql.php Line=149");
	//$resultQuery
	if (!zend_is_true(v0)) {
		phalcon_step_over("Phalcon_Db_MySQL::numRows (Block) File=Library/Phalcon/Db/Mysql.php Line=149");
		phalcon_step_over("Phalcon_Db_MySQL::numRows (Assignment) File=Library/Phalcon/Db/Mysql.php Line=150");
		//$resultQuery
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(t1);
		v0 = t1;
		phalcon_debug_assign("$resultQuery", t1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_MySQL::numRows (If) File=Library/Phalcon/Db/Mysql.php Line=151");
		//$resultQuery
		if (!zend_is_true(v0)) {
			phalcon_step_over("Phalcon_Db_MySQL::numRows (Block) File=Library/Phalcon/Db/Mysql.php Line=151");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	}
	phalcon_step_over("Phalcon_Db_MySQL::numRows (If) File=Library/Phalcon/Db/Mysql.php Line=155");
	//$numberRows
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL(r0);
	//$resultQuery
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_num_rows", 1, p0);
	phalcon_debug_vdump("mysql_num_rows > ", r0 TSRMLS_CC);
	PG(display_errors) = silence;
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_debug_assign("$numberRows", r0 TSRMLS_CC);
	PHALCON_INIT_FALSE(t2);
	PHALCON_NOT_IDENTICAL_FUNCTION(r1, v1, t2);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Db_MySQL::numRows (Block) File=Library/Phalcon/Db/Mysql.php Line=155");
		//$numberRows
		phalcon_debug_vdump("Returning > ", v1 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(v1) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v1);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v1);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Db_MySQL::numRows (Block) File=Library/Phalcon/Db/Mysql.php Line=157");
		phalcon_step_over("Phalcon_Db_MySQL::numRows (Throw) File=Library/Phalcon/Db/Mysql.php Line=158");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r2);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "error" TSRMLS_CC);
		//$php_errormsg
		PHALCON_READ_SYMBOL(v2, pv0, "php_errormsg");
		Z_ADDREF_P(v2);
		p2[0] = v2;
		phalcon_debug_param(v2 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "error", 1, p2, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		Z_ADDREF_P(r2);
		p1[0] = r2;
		phalcon_debug_param(r2 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r3);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "noerror" TSRMLS_CC);
		PHALCON_CALL_METHOD(r3, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		Z_ADDREF_P(r3);
		p1[1] = r3;
		phalcon_debug_param(r3 TSRMLS_CC);
		PHALCON_PARAM_BOOL(p1[2], 1);
		//$this
		Z_ADDREF_P(this_ptr);
		p1[3] = this_ptr;
		phalcon_debug_param(this_ptr TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_FALSE;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_MySQL::numRows (Method) File=Library/Phalcon/Db/Mysql.php Line=163");
}

PHP_METHOD(Phalcon_Db_MySQL, dataSeek){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL;
	zval **pv0;
	zval *p0[] = { NULL, NULL }, *p2[] = { NULL }, *p1[] = { NULL, NULL };
	zend_bool silence;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_INIT_NULL(v1);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_MySQL", "dataSeek", 0);
	phalcon_step_over("Phalcon_Db_MySQL::dataSeek (If) File=Library/Phalcon/Db/Mysql.php Line=164");
	//$resultQuery
	if (!zend_is_true(v1)) {
		phalcon_step_over("Phalcon_Db_MySQL::dataSeek (Block) File=Library/Phalcon/Db/Mysql.php Line=164");
		phalcon_step_over("Phalcon_Db_MySQL::dataSeek (Assignment) File=Library/Phalcon/Db/Mysql.php Line=165");
		//$resultQuery
		//$this
		PHALCON_ALLOC_ZVAL(t0);
		phalcon_read_property(t0, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t0);
		if (v1) {
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(t0);
		v1 = t0;
		phalcon_debug_assign("$resultQuery", t0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db_MySQL::dataSeek (If) File=Library/Phalcon/Db/Mysql.php Line=166");
		//$resultQuery
		if (!zend_is_true(v1)) {
			phalcon_step_over("Phalcon_Db_MySQL::dataSeek (Block) File=Library/Phalcon/Db/Mysql.php Line=166");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	}
	phalcon_step_over("Phalcon_Db_MySQL::dataSeek (If) File=Library/Phalcon/Db/Mysql.php Line=170");
	//$success
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL(r0);
	//$resultQuery
	p0[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	//$number
	p0[1] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_data_seek", 2, p0);
	phalcon_debug_vdump("mysql_data_seek > ", r0 TSRMLS_CC);
	PG(display_errors) = silence;
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r0);
	v2 = r0;
	phalcon_debug_assign("$success", r0 TSRMLS_CC);
	PHALCON_INIT_FALSE(t1);
	PHALCON_NOT_IDENTICAL_FUNCTION(r1, v2, t1);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Db_MySQL::dataSeek (Block) File=Library/Phalcon/Db/Mysql.php Line=170");
		//$success
		phalcon_debug_vdump("Returning > ", v2 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(v2) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v2);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v2);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Db_MySQL::dataSeek (Block) File=Library/Phalcon/Db/Mysql.php Line=172");
		phalcon_step_over("Phalcon_Db_MySQL::dataSeek (Throw) File=Library/Phalcon/Db/Mysql.php Line=173");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r2);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "error" TSRMLS_CC);
		//$php_errormsg
		PHALCON_READ_SYMBOL(v3, pv0, "php_errormsg");
		Z_ADDREF_P(v3);
		p2[0] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "error", 1, p2, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		Z_ADDREF_P(r2);
		p1[0] = r2;
		phalcon_debug_param(r2 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r3);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "noerror" TSRMLS_CC);
		PHALCON_CALL_METHOD(r3, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		Z_ADDREF_P(r3);
		p1[1] = r3;
		phalcon_debug_param(r3 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p1, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_FALSE;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_MySQL::dataSeek (Method) File=Library/Phalcon/Db/Mysql.php Line=178");
}

PHP_METHOD(Phalcon_Db_MySQL, affectedRows){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
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
	phalcon_step_into_entry("Phalcon_Db_MySQL", "affectedRows", 0);
	phalcon_step_over("Phalcon_Db_MySQL::affectedRows (If) File=Library/Phalcon/Db/Mysql.php Line=179");
	//$numberRows
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	p0[0] = t0;
	phalcon_debug_param(t0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_affected_rows", 1, p0);
	phalcon_debug_vdump("mysql_affected_rows > ", r0 TSRMLS_CC);
	PG(display_errors) = silence;
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_debug_assign("$numberRows", r0 TSRMLS_CC);
	PHALCON_INIT_FALSE(t1);
	PHALCON_NOT_IDENTICAL_FUNCTION(r1, v1, t1);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Db_MySQL::affectedRows (Block) File=Library/Phalcon/Db/Mysql.php Line=179");
		//$numberRows
		phalcon_debug_vdump("Returning > ", v1 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(v1) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v1);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v1);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Db_MySQL::affectedRows (Block) File=Library/Phalcon/Db/Mysql.php Line=181");
		phalcon_step_over("Phalcon_Db_MySQL::affectedRows (Throw) File=Library/Phalcon/Db/Mysql.php Line=182");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r2);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "error" TSRMLS_CC);
		//$php_errormsg
		PHALCON_READ_SYMBOL(v2, pv0, "php_errormsg");
		Z_ADDREF_P(v2);
		p2[0] = v2;
		phalcon_debug_param(v2 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "error", 1, p2, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		Z_ADDREF_P(r2);
		p1[0] = r2;
		phalcon_debug_param(r2 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r3);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "noerror" TSRMLS_CC);
		PHALCON_CALL_METHOD(r3, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		Z_ADDREF_P(r3);
		p1[1] = r3;
		phalcon_debug_param(r3 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p1, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_FALSE;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_MySQL::affectedRows (Method) File=Library/Phalcon/Db/Mysql.php Line=187");
}

PHP_METHOD(Phalcon_Db_MySQL, setFetchMode){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_MySQL", "setFetchMode", 0);
	phalcon_step_over("Phalcon_Db_MySQL::setFetchMode (If) File=Library/Phalcon/Db/Mysql.php Line=188");
	//$fetchMode
	PHALCON_GET_CLASS_CONSTANT(t0, phalcon_db_mysql_class_entry, "DB_ASSOC");
	PHALCON_EQUAL_FUNCTION(r0, v0, t0);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Db_MySQL::setFetchMode (Block) File=Library/Phalcon/Db/Mysql.php Line=188");
		phalcon_step_over("Phalcon_Db_MySQL::setFetchMode (Assignment) File=Library/Phalcon/Db/Mysql.php Line=189");
		//Wasted infer Constant MYSQL_ASSOC
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_LONG(t1, 1);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Db_MySQL::setFetchMode (If) File=Library/Phalcon/Db/Mysql.php Line=192");
	//$fetchMode
	PHALCON_GET_CLASS_CONSTANT(t2, phalcon_db_mysql_class_entry, "DB_BOTH");
	PHALCON_EQUAL_FUNCTION(r1, v0, t2);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Db_MySQL::setFetchMode (Block) File=Library/Phalcon/Db/Mysql.php Line=192");
		phalcon_step_over("Phalcon_Db_MySQL::setFetchMode (Assignment) File=Library/Phalcon/Db/Mysql.php Line=193");
		//Wasted infer Constant MYSQL_BOTH
		PHALCON_ALLOC_ZVAL(t3);
		ZVAL_LONG(t3, 3);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t3, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Db_MySQL::setFetchMode (If) File=Library/Phalcon/Db/Mysql.php Line=196");
	//$fetchMode
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_db_mysql_class_entry, "DB_NUM");
	PHALCON_EQUAL_FUNCTION(r2, v0, t4);
	if (zend_is_true(r2)) {
		phalcon_step_over("Phalcon_Db_MySQL::setFetchMode (Block) File=Library/Phalcon/Db/Mysql.php Line=196");
		phalcon_step_over("Phalcon_Db_MySQL::setFetchMode (Assignment) File=Library/Phalcon/Db/Mysql.php Line=197");
		//Wasted infer Constant MYSQL_NUM
		PHALCON_ALLOC_ZVAL(t5);
		ZVAL_LONG(t5, 2);
		//$this
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
	phalcon_step_over("Phalcon_Db_MySQL::setFetchMode (Method) File=Library/Phalcon/Db/Mysql.php Line=202");
}

PHP_METHOD(Phalcon_Db_MySQL, error){

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
		PHALCON_INIT_NULL(v1);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_MySQL", "error", 0);
	phalcon_step_over("Phalcon_Db_MySQL::error (If) File=Library/Phalcon/Db/Mysql.php Line=203");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Db_MySQL::error (Block) File=Library/Phalcon/Db/Mysql.php Line=203");
		phalcon_step_over("Phalcon_Db_MySQL::error (Assignment) File=Library/Phalcon/Db/Mysql.php Line=204");
		//$errorMessage
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CALL_FUNC(r0, "mysql_error");
		phalcon_debug_vdump("mysql_error > ", r0 TSRMLS_CC);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(r0);
		v2 = r0;
		phalcon_debug_assign("$errorMessage", r0 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Db_MySQL::error (Block) File=Library/Phalcon/Db/Mysql.php Line=205");
		phalcon_step_over("Phalcon_Db_MySQL::error (Assignment) File=Library/Phalcon/Db/Mysql.php Line=206");
		//$errorMessage
		PHALCON_ALLOC_ZVAL(r1);
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		p1[0] = t1;
		phalcon_debug_param(t1 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r1, "mysql_error", 1, p1);
		phalcon_debug_vdump("mysql_error > ", r1 TSRMLS_CC);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(r1);
		v2 = r1;
		phalcon_debug_assign("$errorMessage", r1 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Db_MySQL::error (If) File=Library/Phalcon/Db/Mysql.php Line=208");
	//$errorMessage
	if (zend_is_true(v2)) {
		phalcon_step_over("Phalcon_Db_MySQL::error (Block) File=Library/Phalcon/Db/Mysql.php Line=208");
		phalcon_step_over("Phalcon_Db_MySQL::error (Assignment) File=Library/Phalcon/Db/Mysql.php Line=209");
		//$errorMessage
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_concat_left(r3, "\"", v2 TSRMLS_CC);
		//$errorString
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_vboth(r2, r3, "\" ", v0 TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_lastError", strlen("_lastError"), copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Db_MySQL::error (Block) File=Library/Phalcon/Db/Mysql.php Line=210");
		phalcon_step_over("Phalcon_Db_MySQL::error (Assignment) File=Library/Phalcon/Db/Mysql.php Line=211");
		//$errorString
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_concat_both(r4,  "[Unknown MySQL error: ", v0, "]" TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r4, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_lastError", strlen("_lastError"), copy TSRMLS_CC);
		}
	}
	//$this
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_lastError", sizeof("_lastError")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
	phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t2) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t2);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t2);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_MySQL::error (Method) File=Library/Phalcon/Db/Mysql.php Line=216");
}

PHP_METHOD(Phalcon_Db_MySQL, noError){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_NULL(v0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_MySQL", "noError", 0);
	phalcon_step_over("Phalcon_Db_MySQL::noError (If) File=Library/Phalcon/Db/Mysql.php Line=217");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Db_MySQL::noError (Block) File=Library/Phalcon/Db/Mysql.php Line=217");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	Z_ADDREF_P(t1);
	p0[0] = t1;
	phalcon_debug_param(t1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_errno", 1, p0);
	phalcon_debug_vdump("mysql_errno > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_MySQL::noError (Method) File=Library/Phalcon/Db/Mysql.php Line=223");
}

PHP_METHOD(Phalcon_Db_MySQL, lastInsertId){

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
	phalcon_step_into_entry("Phalcon_Db_MySQL", "lastInsertId", 0);
	phalcon_step_over("Phalcon_Db_MySQL::lastInsertId (If) File=Library/Phalcon/Db/Mysql.php Line=224");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Db_MySQL::lastInsertId (Block) File=Library/Phalcon/Db/Mysql.php Line=224");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	p0[0] = t1;
	phalcon_debug_param(t1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "mysql_insert_id", 1, p0);
	phalcon_debug_vdump("mysql_insert_id > ", r0 TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_MySQL::lastInsertId (Method) File=Library/Phalcon/Db/Mysql.php Line=230");
}

PHP_METHOD(Phalcon_Db_MySQL, limit){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db_MySQL", "limit", 0);
	phalcon_step_over("Phalcon_Db_MySQL::limit (If) File=Library/Phalcon/Db/Mysql.php Line=231");
	PHALCON_ALLOC_ZVAL(r0);
	//$number
	Z_ADDREF_P(v1);
	p0[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "is_numeric", 1, p0);
	phalcon_debug_vdump("is_numeric > ", r0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Db_MySQL::limit (Block) File=Library/Phalcon/Db/Mysql.php Line=231");
		phalcon_step_over("Phalcon_Db_MySQL::limit (Assignment) File=Library/Phalcon/Db/Mysql.php Line=232");
		//$number
		//$number
		convert_to_long(v1);
		phalcon_debug_assign("$number", v1 TSRMLS_CC);
		//$sqlQuery
		//$number
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
		phalcon_step_over("Phalcon_Db_MySQL::limit (Block) File=Library/Phalcon/Db/Mysql.php Line=234");
		//$sqlQuery
		phalcon_debug_vdump("Returning > ", v0 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(v0) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v0);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v0);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db_MySQL::limit (Method) File=Library/Phalcon/Db/Mysql.php Line=239");
}

PHP_METHOD(Phalcon_Db_MySQL, tableExists){

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
	phalcon_step_into_entry("Phalcon_Db_MySQL", "tableExists", 0);
	phalcon_step_over("Phalcon_Db_MySQL::tableExists (Assignment) File=Library/Phalcon/Db/Mysql.php Line=240");
	//$tableName
	PHALCON_ALLOC_ZVAL(r0);
	//$tableName
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "addslashes", 1, p0);
	phalcon_debug_vdump("addslashes > ", r0 TSRMLS_CC);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r0);
	v0 = r0;
	phalcon_debug_assign("$tableName", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_MySQL::tableExists (Assignment) File=Library/Phalcon/Db/Mysql.php Line=241");
	//$sql
	PHALCON_ALLOC_ZVAL(r1);
	//$tableName
	Z_ADDREF_P(v0);
	p1[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$schemaName
	Z_ADDREF_P(v1);
	p1[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_db_dialect_mysql", "tableexists", 2, p1);
	phalcon_debug_vdump("StaticReturn > ", r1 TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	phalcon_debug_assign("$sql", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_MySQL::tableExists (Assignment) File=Library/Phalcon/Db/Mysql.php Line=242");
	//$fetchMode
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_fetchMode", sizeof("_fetchMode")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(t0);
	v3 = t0;
	phalcon_debug_assign("$fetchMode", t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_MySQL::tableExists (Assignment) File=Library/Phalcon/Db/Mysql.php Line=243");
	//Wasted infer Constant MYSQL_NUM
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 2);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Db_MySQL::tableExists (Assignment) File=Library/Phalcon/Db/Mysql.php Line=244");
	//$num
	PHALCON_ALLOC_ZVAL(r2);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "fetchone" TSRMLS_CC);
	//$sql
	Z_ADDREF_P(v2);
	p2[0] = v2;
	phalcon_debug_param(v2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "fetchone", 1, p2, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(r2);
	v4 = r2;
	phalcon_debug_assign("$num", r2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_MySQL::tableExists (Assignment) File=Library/Phalcon/Db/Mysql.php Line=245");
	//$fetchMode
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v3, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), copy TSRMLS_CC);
	}
	//$num
	PHALCON_ALLOC_ZVAL(r3);
	phalcon_array_fetch_long(r3, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(r3) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(r3);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(r3);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_MySQL::tableExists (Method) File=Library/Phalcon/Db/Mysql.php Line=250");
}

PHP_METHOD(Phalcon_Db_MySQL, viewExists){

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
	phalcon_step_into_entry("Phalcon_Db_MySQL", "viewExists", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "tableexists" TSRMLS_CC);
	//$viewName
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$schemaName
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "tableexists", 2, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_MySQL::viewExists (Method) File=Library/Phalcon/Db/Mysql.php Line=254");
}

PHP_METHOD(Phalcon_Db_MySQL, describeTable){

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
	phalcon_step_into_entry("Phalcon_Db_MySQL", "describeTable", 0);
	phalcon_step_over("Phalcon_Db_MySQL::describeTable (Assignment) File=Library/Phalcon/Db/Mysql.php Line=255");
	//$sql
	PHALCON_ALLOC_ZVAL(r0);
	//$table
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$schema
	Z_ADDREF_P(v1);
	p0[1] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "describetable", 2, p0);
	phalcon_debug_vdump("StaticReturn > ", r0 TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r0);
	v2 = r0;
	phalcon_debug_assign("$sql", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_MySQL::describeTable (Assignment) File=Library/Phalcon/Db/Mysql.php Line=256");
	//Wasted infer Constant MYSQL_ASSOC
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_LONG(t0, 1);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Db_MySQL::describeTable (Assignment) File=Library/Phalcon/Db/Mysql.php Line=257");
	//$describe
	PHALCON_ALLOC_ZVAL(r1);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "fetchall" TSRMLS_CC);
	//$sql
	Z_ADDREF_P(v2);
	p1[0] = v2;
	phalcon_debug_param(v2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetchall", 1, p1, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Db_MySQL" TSRMLS_CC);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(r1);
	v3 = r1;
	phalcon_debug_assign("$describe", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db_MySQL::describeTable (Assignment) File=Library/Phalcon/Db/Mysql.php Line=258");
	//Wasted infer Constant MYSQL_BOTH
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 3);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), copy TSRMLS_CC);
	}
	//$describe
	phalcon_debug_vdump("Returning > ", v3 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(v3) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v3);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v3);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db_MySQL::describeTable (Method) File=Library/Phalcon/Db/Mysql.php Line=262");
}

PHP_METHOD(Phalcon_Db_MySQL, getDateUsingFormat){

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
	phalcon_step_into_entry("Phalcon_Db_MySQL", "getDateUsingFormat", 0);
	//$date
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

