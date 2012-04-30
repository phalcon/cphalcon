
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
 * Phalcon_Db_Mysql
 *
 * Phalcon_Db_Mysql is the Phalcon_Db adapter for MySQL database.
 * 
 */

/**
 * Constructor for Phalcon_Db_Adapter_Mysql. This method does not should to be called directly. Use Phalcon_Db::factory instead
 *
 * @param stdClass $descriptor
 * @param boolean $persistent
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v0);
	}
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_BOOL(v1, 0);
	}
	
	if (PHALCON_COMPARE_STRING(v0, "")) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v0, t0);
	}
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "connect", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * This method is automatically called in Phalcon_Db_Mysql constructor.
 * Call it when you need to restore a database connection
 *
 * @param stdClass $descriptor
 * @param boolean $persistent
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, connect){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL, *t17 = NULL, *t18 = NULL, *t19 = NULL, *t20 = NULL;
	zval *t21 = NULL, *t22 = NULL, *t23 = NULL, *t24 = NULL, *t25 = NULL, *t26 = NULL, *t27 = NULL;
	zval *t28 = NULL, *t29 = NULL, *t30 = NULL, *t31 = NULL, *t32 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL, NULL }, *p3[] = { NULL, NULL, NULL }, *p6[] = { NULL }, *p7[] = { NULL }, *p8[] = { NULL }, *p9[] = { NULL }, *p10[] = { NULL, NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v0);
	}
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_BOOL(v1, 0);
	}
	
	if (!zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v0, t0);
	}
	eval_int = phalcon_isset_property(v0, "host", strlen("host") TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_BOOL(t1, eval_int);
	if (zend_is_true(t1)) {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, v0, "host", sizeof("host")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		r0 = t2;
	} else {
		PHALCON_INIT_VAR(t3);
		ZVAL_STRING(t3, "", 1);
		r0 = t3;
	}
	PHALCON_CPY_WRT(v2, r0);
	eval_int = phalcon_isset_property(v0, "username", strlen("username") TSRMLS_CC);
	PHALCON_INIT_VAR(t4);
	ZVAL_BOOL(t4, eval_int);
	if (zend_is_true(t4)) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property(&t5, v0, "username", sizeof("username")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		r1 = t5;
	} else {
		PHALCON_INIT_VAR(t6);
		ZVAL_STRING(t6, "", 1);
		r1 = t6;
	}
	PHALCON_CPY_WRT(v3, r1);
	eval_int = phalcon_isset_property(v0, "password", strlen("password") TSRMLS_CC);
	PHALCON_INIT_VAR(t7);
	ZVAL_BOOL(t7, eval_int);
	if (zend_is_true(t7)) {
		PHALCON_ALLOC_ZVAL_MM(t8);
		phalcon_read_property(&t8, v0, "password", sizeof("password")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		r2 = t8;
	} else {
		PHALCON_INIT_VAR(t9);
		ZVAL_STRING(t9, "", 1);
		r2 = t9;
	}
	PHALCON_CPY_WRT(v4, r2);
	eval_int = phalcon_isset_property(v0, "port", strlen("port") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t10);
		phalcon_read_property(&t10, v0, "port", sizeof("port")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_VBOTH(r3, v2, ":", t10);
		PHALCON_CPY_WRT(v5, r3);
	} else {
		PHALCON_CPY_WRT(v5, v2);
	}
	PHALCON_INIT_VAR(v6);
	ZVAL_NULL(v6);
	eval_int = phalcon_isset_property(v0, "compression", strlen("compression") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t11);
		phalcon_read_property(&t11, v0, "compression", sizeof("compression")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(t11)) {
			if (!zend_is_true(v6)) {
				PHALCON_INIT_VAR(t12);
				ZVAL_LONG(t12, 32);
				PHALCON_CPY_WRT(v6, t12);
			} else {
				PHALCON_INIT_VAR(t13);
				ZVAL_LONG(t13, 32);
				PHALCON_ALLOC_ZVAL_MM(r4);
				bitwise_or_function(r4, v6, t13 TSRMLS_CC);
				PHALCON_CPY_WRT(v6, r4);
			}
		}
	}
	eval_int = phalcon_isset_property(v0, "ssl", strlen("ssl") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t14);
		phalcon_read_property(&t14, v0, "ssl", sizeof("ssl")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(t14)) {
			if (!zend_is_true(v6)) {
				PHALCON_INIT_VAR(t15);
				ZVAL_LONG(t15, 2048);
				PHALCON_CPY_WRT(v6, t15);
			} else {
				PHALCON_INIT_VAR(t16);
				ZVAL_LONG(t16, 2048);
				PHALCON_ALLOC_ZVAL_MM(r5);
				bitwise_or_function(r5, v6, t16 TSRMLS_CC);
				PHALCON_CPY_WRT(v6, r5);
			}
		}
	}
	eval_int = phalcon_isset_property(v0, "interactive", strlen("interactive") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t17);
		phalcon_read_property(&t17, v0, "interactive", sizeof("interactive")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(t17)) {
			if (!zend_is_true(v6)) {
				PHALCON_INIT_VAR(t18);
				ZVAL_LONG(t18, 1024);
				PHALCON_CPY_WRT(v6, t18);
			} else {
				PHALCON_INIT_VAR(t19);
				ZVAL_LONG(t19, 1024);
				PHALCON_ALLOC_ZVAL_MM(r6);
				bitwise_or_function(r6, v6, t19 TSRMLS_CC);
				PHALCON_CPY_WRT(v6, r6);
			}
		}
	}
	if (!zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		p0[0] = v5;
		p0[1] = v3;
		p0[2] = v4;
		PHALCON_INIT_VAR(p0[3]);
		ZVAL_BOOL(p0[3], 1);
		p0[4] = v6;
		PHALCON_CALL_FUNC_PARAMS(r7, "mysql_connect", 5, p0, 0x02B);
		phalcon_update_property_zval(this_ptr, "_idConnection", strlen("_idConnection"), r7 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r8);
		p1[0] = v5;
		p1[1] = v3;
		p1[2] = v4;
		p1[3] = v6;
		PHALCON_CALL_FUNC_PARAMS(r8, "mysql_pconnect", 4, p1, 0x035);
		phalcon_update_property_zval(this_ptr, "_idConnection", strlen("_idConnection"), r8 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t20);
	phalcon_read_property(&t20, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t20)) {
		eval_int = phalcon_isset_property(v0, "name", strlen("name") TSRMLS_CC);
		PHALCON_INIT_VAR(t21);
		ZVAL_BOOL(t21, eval_int);
		if (zend_is_true(t21)) {
			PHALCON_ALLOC_ZVAL_MM(t22);
			phalcon_read_property(&t22, v0, "name", sizeof("name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			r9 = t22;
		} else {
			PHALCON_INIT_VAR(t23);
			ZVAL_STRING(t23, "", 1);
			r9 = t23;
		}
		PHALCON_CPY_WRT(v7, r9);
		PHALCON_INIT_VAR(t24);
		ZVAL_STRING(t24, "", 1);
		PHALCON_INIT_VAR(r10);
		is_not_identical_function(r10, t24, v7 TSRMLS_CC);
		if (zend_is_true(r10)) {
			PHALCON_ALLOC_ZVAL_MM(r11);
			PHALCON_ALLOC_ZVAL_MM(t25);
			phalcon_read_property(&t25, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS_2(r11, "mysql_select_db", v7, t25, 0x02C);
			if (!zend_is_true(r11)) {
				PHALCON_ALLOC_ZVAL_MM(i0);
				object_init_ex(i0, phalcon_db_exception_class_entry);
				PHALCON_ALLOC_ZVAL_MM(r12);
				PHALCON_CALL_METHOD(r12, this_ptr, "error", PHALCON_CALL_DEFAULT);
				Z_ADDREF_P(r12);
				p3[0] = r12;
				PHALCON_ALLOC_ZVAL_MM(r13);
				PHALCON_CALL_METHOD(r13, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
				Z_ADDREF_P(r13);
				p3[1] = r13;
				PHALCON_INIT_VAR(p3[2]);
				ZVAL_BOOL(p3[2], 0);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 3, p3, PHALCON_CALL_CHECK);
				Z_DELREF_P(p3[0]);
				Z_DELREF_P(p3[1]);
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				PHALCON_MM_RESTORE();
				return;
			}
		}
		eval_int = phalcon_isset_property(v0, "autocommit", strlen("autocommit") TSRMLS_CC);
		PHALCON_INIT_VAR(t26);
		ZVAL_BOOL(t26, eval_int);
		if (zend_is_true(t26)) {
			PHALCON_ALLOC_ZVAL_MM(t27);
			phalcon_read_property(&t27, v0, "autocommit", sizeof("autocommit")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			r14 = t27;
		} else {
			PHALCON_INIT_VAR(t28);
			ZVAL_BOOL(t28, 0);
			r14 = t28;
		}
		PHALCON_CPY_WRT(v8, r14);
		phalcon_update_property_zval(this_ptr, "_autoCommit", strlen("_autoCommit"), v8 TSRMLS_CC);
		PHALCON_INIT_VAR(t29);
		ZVAL_LONG(t29, 3);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t29 TSRMLS_CC);
		Z_ADDREF_P(v0);
		p6[0] = v0;
		PHALCON_CALL_PARENT_PARAMS_NORETURN(this_ptr, "Phalcon_Db_Adapter_Mysql", "__construct", 1, p6);
		Z_DELREF_P(p6[0]);
		eval_int = phalcon_isset_property(v0, "charset", strlen("charset") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t30);
			phalcon_read_property(&t30, v0, "charset", sizeof("charset")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r15);
			PHALCON_CONCAT_LEFT(r15, "SET NAMES ", t30);
			Z_ADDREF_P(r15);
			p7[0] = r15;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "query", 1, p7, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p7[0]);
		}
		eval_int = phalcon_isset_property(v0, "collation", strlen("collation") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(t31);
			phalcon_read_property(&t31, v0, "collation", sizeof("collation")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r16);
			PHALCON_CONCAT_LEFT(r16, "SET collation_connection=", t31);
			Z_ADDREF_P(r16);
			p8[0] = r16;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "query", 1, p8, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p8[0]);
			PHALCON_ALLOC_ZVAL_MM(t32);
			phalcon_read_property(&t32, v0, "collation", sizeof("collation")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r17);
			PHALCON_CONCAT_LEFT(r17, "SET collation_database=", t32);
			Z_ADDREF_P(r17);
			p9[0] = r17;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "query", 1, p9, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p9[0]);
		}
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r18);
		PHALCON_CALL_METHOD(r18, this_ptr, "error", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r18);
		p10[0] = r18;
		PHALCON_ALLOC_ZVAL_MM(r19);
		PHALCON_CALL_METHOD(r19, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r19);
		p10[1] = r19;
		PHALCON_INIT_VAR(p10[2]);
		ZVAL_BOOL(p10[2], 0);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 3, p10, PHALCON_CALL_CHECK);
		Z_DELREF_P(p10[0]);
		Z_DELREF_P(p10[1]);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sends SQL statements to the MySQL database server returning success state.
 * When the SQL sent have returned any row, the result is a PHP resource.
 *
 * 
 *
 * @param  string $sqlStatement
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, query){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL }, *p3[] = { NULL }, *p5[] = { NULL }, *p4[] = { NULL }, *p7[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v1, t0);
	if (!zend_is_true(v1)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "connect", PHALCON_CALL_DEFAULT);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!zend_is_true(t1)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	phalcon_update_property_zval(this_ptr, "_lastQuery", strlen("_lastQuery"), v0 TSRMLS_CC);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_beforequery", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "mysql_query", v0, v1, 0x02D);
	PHALCON_CPY_WRT(v2, r0);
	if (zend_is_true(v2)) {
		phalcon_update_property_zval(this_ptr, "_lastResultQuery", strlen("_lastResultQuery"), v2 TSRMLS_CC);
		Z_ADDREF_P(v0);
		p3[0] = v0;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_afterquery", 1, p3, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p3[0]);
		PHALCON_RETURN_CHECK_CTOR(v2);
	} else {
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_lastResultQuery", strlen("_lastResultQuery"), 0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_LEFT(r3, " when executing \"", v0);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_INIT_VAR(p5[0]);
		ZVAL_BOOL(p5[0], 1);
		PHALCON_CALL_METHOD_PARAMS(r4, this_ptr, "getconnectionid", 1, p5, PHALCON_CALL_DEFAULT);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_VBOTH(r2, r3, "\" on connection \"", r4);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_RIGHT(r5, r2, "\"");
		Z_ADDREF_P(r5);
		p4[0] = r5;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "error", 1, p4, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p4[0]);
		PHALCON_CPY_WRT(v3, r1);
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CALL_METHOD(r6, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v4, r6);
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		Z_ADDREF_P(v3);
		p7[0] = v3;
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CALL_METHOD(r7, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r7);
		p7[1] = r7;
		PHALCON_INIT_VAR(p7[2]);
		ZVAL_BOOL(p7[2], 1);
		Z_ADDREF_P(this_ptr);
		p7[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p7, PHALCON_CALL_CHECK);
		Z_DELREF_P(p7[0]);
		Z_DELREF_P(p7[1]);
		Z_DELREF_P(p7[3]);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Closes active connection returning success. Phalcon automatically closes and destroys active connections within Phalcon_Db_Pool
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, close){

	zval *t0 = NULL, *t1 = NULL;
	zval *v0 = NULL;
	zval *r0 = NULL;
	zend_bool silence;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_CALL_PARENT_NORETURN(this_ptr, "Phalcon_Db_Adapter_Mysql", "close");
		silence = PG(display_errors);
		PG(display_errors) = 0;
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t1);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "mysql_close", t1, 0x036);
		Z_DELREF_P(t1);
		PG(display_errors) = silence;
		PHALCON_CPY_WRT(v0, r0);
		zend_update_property_null(Z_OBJCE_P(this_ptr), this_ptr, "_idConnection", strlen("_idConnection") TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(v0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns an array of strings that corresponds to the fetched row, or FALSE if there are no more rows.
 * This method is affected by the active fetch flag set using Phalcon_Db_Mysql::setFetchMode
 *
 * 
 *
 * @param resource $resultQuery
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, fetchArray){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	if (!zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v0, t1);
		if (!zend_is_true(v0)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_fetchMode", sizeof("_fetchMode")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t2);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "mysql_fetch_array", v0, t2, 0x02E);
	Z_DELREF_P(v0);
	Z_DELREF_P(t2);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Gets number of rows returned by a resulset
 *
 * 
 *
 * @param resource $resultQuery
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, numRows){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL;
	zval **pv0;
	zval *p2[] = { NULL }, *p1[] = { NULL, NULL, NULL, NULL };
	zend_bool silence;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	if (!zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v0, t1);
		if (!zend_is_true(v0)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysql_num_rows", v0, 0x037);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(v1, r0);
	if (Z_TYPE_P(v1) != IS_BOOL || (Z_TYPE_P(v1) == IS_BOOL && Z_BVAL_P(v1))) {
		PHALCON_RETURN_CHECK_CTOR(v1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_READ_SYMBOL(v2, pv0, "php_errormsg");
		Z_ADDREF_P(v2);
		p2[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "error", 1, p2, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p2[0]);
		Z_ADDREF_P(r1);
		p1[0] = r1;
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r2);
		p1[1] = r2;
		PHALCON_INIT_VAR(p1[2]);
		ZVAL_BOOL(p1[2], 1);
		Z_ADDREF_P(this_ptr);
		p1[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		Z_DELREF_P(p1[1]);
		Z_DELREF_P(p1[3]);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Moves internal resulset cursor to another position letting us to fetch a certain row
 *
 * 
 *
 * @param resource $resultQuery
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dataSeek){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL;
	zval **pv0;
	zval *p2[] = { NULL }, *p1[] = { NULL, NULL };
	zend_bool silence;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_NULL(v1);
	} else {
		PHALCON_SEPARATE_PARAM(v1);
	}
	
	if (!zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "_lastResultQuery", sizeof("_lastResultQuery")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, t0);
		if (!zend_is_true(v1)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "mysql_data_seek", v1, v0, 0x038);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(v2, r0);
	if (Z_TYPE_P(v2) != IS_BOOL || (Z_TYPE_P(v2) == IS_BOOL && Z_BVAL_P(v2))) {
		PHALCON_RETURN_CHECK_CTOR(v2);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_READ_SYMBOL(v3, pv0, "php_errormsg");
		Z_ADDREF_P(v3);
		p2[0] = v3;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "error", 1, p2, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p2[0]);
		Z_ADDREF_P(r1);
		p1[0] = r1;
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r2);
		p1[1] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		Z_DELREF_P(p1[1]);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Returns number of affected rows by the last INSERT/UPDATE/DELETE repoted by MySQL
 *
 * 
 *
 * @param resource $resultQuery
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, affectedRows){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL;
	zval **pv0;
	zval *p2[] = { NULL }, *p1[] = { NULL, NULL };
	zend_bool silence;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysql_affected_rows", t0, 0x039);
	PG(display_errors) = silence;
	PHALCON_CPY_WRT(v1, r0);
	if (Z_TYPE_P(v1) != IS_BOOL || (Z_TYPE_P(v1) == IS_BOOL && Z_BVAL_P(v1))) {
		PHALCON_RETURN_CHECK_CTOR(v1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_READ_SYMBOL(v2, pv0, "php_errormsg");
		Z_ADDREF_P(v2);
		p2[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "error", 1, p2, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p2[0]);
		Z_ADDREF_P(r1);
		p1[0] = r1;
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "noerror", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r2);
		p1[1] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		Z_DELREF_P(p1[1]);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Changes the fetching mode affecting Phalcon_Db_Mysql::fetchArray
 *
 * 
 *
 * @param int $fetchMode
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, setFetchMode){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, v0, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 1);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t1 TSRMLS_CC);
	}
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 2);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, v0, t2 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 3);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t3 TSRMLS_CC);
	}
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 3);
	PHALCON_ALLOC_ZVAL_MM(r2);
	is_equal_function(r2, v0, t4 TSRMLS_CC);
	if (zend_is_true(r2)) {
		PHALCON_INIT_VAR(t5);
		ZVAL_LONG(t5, 2);
		phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t5 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns last error message from MySQL
 *
 * @param string $errorString
 * @param resurce $resultQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, error){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_NULL(v1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC(r0, "mysql_error", 0x03A);
		PHALCON_CPY_WRT(v2, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "mysql_error", t1, 0x03A);
		PHALCON_CPY_WRT(v2, r1);
	}
	if (zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_LEFT(r3, "\"", v2);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_VBOTH(r2, r3, "\" ", v0);
		phalcon_update_property_zval(this_ptr, "_lastError", strlen("_lastError"), r2 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_BOTH(r4,  "[Unknown MySQL error: ", v0, "]");
		phalcon_update_property_zval(this_ptr, "_lastError", strlen("_lastError"), r4 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_lastError", sizeof("_lastError")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
}

/**
 * Returns last error code from MySQL
 *
 * @param string $errorString
 * @param resurce $resultQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, noError){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_NULL(v0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysql_errno", t1, 0x03B);
	Z_DELREF_P(t1);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Returns insert id for the auto_increment column inserted in the last SQL statement
 *
 * @param string $table
 * @param string $primaryKey
 * @param string $sequenceName
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, lastInsertId){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_STRING(v2, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "mysql_insert_id", t1, 0x03C);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Appends a LIMIT clause to $sqlQuery argument
 *
 * 
 *
 * @param string $errorString
 * @param int $number
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, limit){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_numeric", v1, 0x00B);
	if (zend_is_true(r0)) {
		convert_to_long(v1);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_VBOTH(r1, v0, " LIMIT ", v1);
		PHALCON_RETURN_CTOR(r1);
	} else {
		PHALCON_RETURN_CHECK_CTOR(v0);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * 
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, tableExists){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "tableexists", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_fetchMode", sizeof("_fetchMode")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v3, t0);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 2);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	p1[0] = v2;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetchone", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_CPY_WRT(v4, r1);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), v3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r2);
}

/**
 * Generates SQL checking for the existence of a schema.view
 *
 * 
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, viewExists){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "tableexists", 2, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Devuelve un FOR UPDATE valido para un SELECT del RBDM
 *
 * @paramstring $sqlQuery
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, forUpdate){

	zval *v0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_RIGHT(r0, v0, " FOR UPDATE");
	PHALCON_RETURN_CTOR(r0);
}

/**
 * Devuelve un SHARED LOCK valido para un SELECT del RBDM
 *
 * @paramstring $sqlQuery
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, sharedLock){

	zval *v0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_RIGHT(r0, v0, " LOCK IN SHARE MODE");
	PHALCON_RETURN_CTOR(r0);
}

/**
 * Creates a table using MySQL SQL
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramarray $definition
 * @returnboolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, createTable){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL, NULL, NULL }, *p5[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v2) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_BOTH(r0,  "Invalid definition to create the table '", v0, "'");
		Z_ADDREF_P(r0);
		p0[0] = r0;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		Z_DELREF_P(p0[0]);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	eval_int = phalcon_array_isset_string(v2, "columns", strlen("columns")+1);
	PHALCON_INIT_VAR(r1);
	ZVAL_BOOL(r1, eval_int);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "The table must contain at least one column", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch_string(&r3, v2, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "count", r3, 0x007);
	if (!zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(i2);
		object_init_ex(i2, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p3[0]);
		ZVAL_STRING(p3[0], "The table must contain at least one column", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p3, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i2 TSRMLS_CC);
		Z_ADDREF_P(i2);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_ALLOC_ZVAL_MM(r4);
	Z_ADDREF_P(v0);
	p4[0] = v0;
	Z_ADDREF_P(v1);
	p4[1] = v1;
	Z_ADDREF_P(v2);
	p4[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r4, "phalcon_db_dialect_mysql", "createtable", 3, p4);
	Z_DELREF_P(p4[0]);
	Z_DELREF_P(p4[1]);
	Z_DELREF_P(p4[2]);
	PHALCON_CPY_WRT(v3, r4);
	PHALCON_ALLOC_ZVAL_MM(r5);
	Z_ADDREF_P(v3);
	p5[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r5, this_ptr, "query", 1, p5, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p5[0]);
	PHALCON_RETURN_DZVAL(r5);
}

/**
 * Drops a table from a schema/database
 *
 * @paramstring $tableName
 * @param   string $schemaName
 * @paramboolean $ifExists
 * @returnboolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dropTable){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_BOOL(v2, 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "droptable", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Adds a column to a table
 *
 * @paramstring $tableName
 * @param string $schemaName
 * @paramPhalcon_Db_Column $column
 * @returnboolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, addColumn){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "addcolumn", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Modifies a table column based on a definition
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramPhalcon_Db_Column $column
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, modifyColumn){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "modifycolumn", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Drops a column from a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramstring $columnName
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dropColumn){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "dropcolumn", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Adds an index to a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramDbIndex $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, addIndex){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "addindex", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Drop an index from a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramstring $indexName
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dropIndex){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "dropindex", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Adds a primary key to a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramPhalcon_Db_Index $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, addPrimaryKey){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "addprimarykey", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Drops primary key from a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dropPrimaryKey){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "dropprimarykey", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	p1[0] = v2;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Adds a foreign key to a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramPhalcon_Db_Reference $reference
 * @returnboolean true
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, addForeignKey){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "addforeignkey", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Drops a foreign key from a table
 *
 * @paramstring $tableName
 * @paramstring $schemaName
 * @paramstring $referenceName
 * @returnboolean true
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, dropForeignKey){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	Z_ADDREF_P(v2);
	p0[2] = v2;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "dropforeignkey", 3, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	Z_DELREF_P(p0[2]);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	p1[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_RETURN_DZVAL(r1);
}

/**
 * Returns the SQL column definition from a column
 *
 * @paramPhalcon_Db_Column $column
 * @returnstring
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, getColumnDefinition){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "getcolumndefinition", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Generates SQL describing a table
 *
 * 
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, describeTable){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "describetable", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	p1[0] = v2;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetchall", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_CPY_WRT(v3, r1);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 3);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t1 TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(v3);
}

/**
 * List all tables on a database
 *
 * 
 *
 * @param string $schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, listTables){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "listtables", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_fetchMode", sizeof("_fetchMode")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v2, t0);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 2);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v1);
	p1[0] = v1;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetchall", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_CPY_WRT(v3, r1);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v4, a0);
	if (Z_TYPE_P(v3) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v3);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_321f_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_321f_0;
		}
		PHALCON_INIT_VAR(v5);
		ZVAL_ZVAL(v5, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch_long(&r2, v5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r2);
		PHALCON_SEPARATE_ARRAY(v4);
		phalcon_array_append(v4, r2 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_321f_0;
		fee_321f_0:
		if(0){ };
	}
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), v2 TSRMLS_CC);
	PHALCON_RETURN_CTOR(v4);
}

/**
 * Returns a database date formatted
 *
 * 
 *
 * @param string $date
 * @param string $format
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, getDateUsingFormat){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "YYYY-MM-DD", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_BOTH(r0,  "'", v0, "'");
	PHALCON_RETURN_CTOR(r0);
}

/**
 * Lists table indexes
 *
 * @paramstring $table
 * @paramstring $schema
 * @returnarray
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, describeIndexes){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL }, *p2[] = { NULL, NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "describeindexes", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	p1[0] = v2;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetchall", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_CPY_WRT(v3, r1);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v4, a0);
	if (Z_TYPE_P(v3) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v3);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_321f_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_321f_1;
		}
		PHALCON_INIT_VAR(v5);
		ZVAL_ZVAL(v5, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch_string(&r2, v5, "Key_name", strlen("Key_name"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v6, r2);
		eval_int = phalcon_array_isset(v4, v6);
		PHALCON_INIT_VAR(r3);
		ZVAL_BOOL(r3, eval_int);
		if (!zend_is_true(r3)) {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			Z_ADDREF_P(a1);
			if (Z_REFCOUNT_P(v4) > 1) {
				zval *new_zv;
				Z_DELREF_P(v4);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v4);
				v4 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update(v4, v6, a1 TSRMLS_CC);
		}
		PHALCON_INIT_VAR(r4);
		phalcon_array_fetch_string(&r4, v5, "Column_name", strlen("Column_name"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(v4) == IS_ARRAY) {
			PHALCON_INIT_VAR(t1);
			phalcon_array_fetch(&t1, v4, v6, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t1) > 1) {
			zval *new_zv;
			Z_DELREF_P(t1);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t1);
			t1 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update(v4, v6, t1 TSRMLS_CC);
		}
		Z_ADDREF_P(t1);
		if (Z_TYPE_P(t1) != IS_ARRAY) {
			convert_to_array(t1);
			phalcon_array_update(v4, v6, t1 TSRMLS_CC);
		}
		Z_ADDREF_P(r4);
		phalcon_array_append(t1, r4 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_321f_1;
		fee_321f_1:
		if(0){ };
	}
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	PHALCON_CPY_WRT(v7, a2);
	if (Z_TYPE_P(v4) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah1 = Z_ARRVAL_P(v4);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_321f_2:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_321f_2;
		} else {
			PHALCON_INIT_VAR(v9);
			htype = zend_hash_get_current_key_ex(ah1, &index, &index_len, &num, 0, &hp1);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v9, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v9, num);
				}
			}
		}
		PHALCON_INIT_VAR(v8);
		ZVAL_ZVAL(v8, *hd, 1, 0);
		PHALCON_INIT_VAR(i0);
		object_init_ex(i0, phalcon_db_index_class_entry);
		Z_ADDREF_P(v9);
		p2[0] = v9;
		Z_ADDREF_P(v8);
		p2[1] = v8;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p2, PHALCON_CALL_CHECK);
		Z_DELREF_P(p2[0]);
		Z_DELREF_P(p2[1]);
		Z_ADDREF_P(i0);
		if (Z_REFCOUNT_P(v7) > 1) {
			zval *new_zv;
			Z_DELREF_P(v7);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v7);
			v7 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update(v7, v9, i0 TSRMLS_CC);
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_321f_2;
		fee_321f_2:
		if(0){ };
	}
	PHALCON_INIT_VAR(t2);
	ZVAL_LONG(t2, 3);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t2 TSRMLS_CC);
	PHALCON_RETURN_CTOR(v7);
}

/**
 * Lists table references
 *
 * @paramstring $table
 * @paramstring $schema
 * @returnarray
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, describeReferences){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL }, *p2[] = { NULL, NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "describereferences", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t0 TSRMLS_CC);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v3, a0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	p1[0] = v2;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetchall", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_CPY_WRT(v4, r1);
	if (Z_TYPE_P(v4) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v4);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_321f_3:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_321f_3;
		}
		PHALCON_INIT_VAR(v5);
		ZVAL_ZVAL(v5, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch_string(&r2, v5, "CONSTRAINT_NAME", strlen("CONSTRAINT_NAME"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v6, r2);
		eval_int = phalcon_array_isset(v3, v6);
		PHALCON_INIT_VAR(r3);
		ZVAL_BOOL(r3, eval_int);
		if (!zend_is_true(r3)) {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_INIT_VAR(r4);
			phalcon_array_fetch_string(&r4, v5, "REFERENCED_TABLE_SCHEMA", strlen("REFERENCED_TABLE_SCHEMA"), PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r4);
			PHALCON_SEPARATE_ARRAY(a1);
			add_assoc_zval(a1, "referencedSchema", r4);
			PHALCON_INIT_VAR(r5);
			phalcon_array_fetch_string(&r5, v5, "REFERENCED_TABLE_NAME", strlen("REFERENCED_TABLE_NAME"), PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r5);
			PHALCON_SEPARATE_ARRAY(a1);
			add_assoc_zval(a1, "referencedTable", r5);
			PHALCON_INIT_VAR(a2);
			array_init(a2);
			Z_ADDREF_P(a2);
			PHALCON_SEPARATE_ARRAY(a1);
			add_assoc_zval(a1, "columns", a2);
			PHALCON_INIT_VAR(a3);
			array_init(a3);
			Z_ADDREF_P(a3);
			PHALCON_SEPARATE_ARRAY(a1);
			add_assoc_zval(a1, "referencedColumns", a3);
			Z_ADDREF_P(a1);
			if (Z_REFCOUNT_P(v3) > 1) {
				zval *new_zv;
				Z_DELREF_P(v3);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v3);
				v3 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update(v3, v6, a1 TSRMLS_CC);
		}
		PHALCON_INIT_VAR(r6);
		phalcon_array_fetch_string(&r6, v5, "COLUMN_NAME", strlen("COLUMN_NAME"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(v3) == IS_ARRAY) {
			PHALCON_INIT_VAR(t1);
			phalcon_array_fetch(&t1, v3, v6, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t1) > 1) {
			zval *new_zv;
			Z_DELREF_P(t1);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t1);
			t1 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update(v3, v6, t1 TSRMLS_CC);
		}
		Z_ADDREF_P(t1);
		if (Z_TYPE_P(t1) != IS_ARRAY) {
			convert_to_array(t1);
			phalcon_array_update(v3, v6, t1 TSRMLS_CC);
		}
		if (Z_TYPE_P(t1) == IS_ARRAY) {
			PHALCON_INIT_VAR(t2);
			phalcon_array_fetch_string(&t2, t1, "columns", strlen("columns"), PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t2) > 1) {
			zval *new_zv;
			Z_DELREF_P(t2);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t2);
			t2 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update_string(t1, "columns", strlen("columns"), t2 TSRMLS_CC);
		}
		Z_ADDREF_P(t2);
		if (Z_TYPE_P(t2) != IS_ARRAY) {
			convert_to_array(t2);
			phalcon_array_update_string(t1, "columns", strlen("columns"), t2 TSRMLS_CC);
		}
		Z_ADDREF_P(r6);
		phalcon_array_append(t2, r6 TSRMLS_CC);
		PHALCON_INIT_VAR(r7);
		phalcon_array_fetch_string(&r7, v5, "REFERENCED_COLUMN_NAME", strlen("REFERENCED_COLUMN_NAME"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(v3) == IS_ARRAY) {
			PHALCON_INIT_VAR(t3);
			phalcon_array_fetch(&t3, v3, v6, PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t3) > 1) {
			zval *new_zv;
			Z_DELREF_P(t3);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t3);
			t3 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update(v3, v6, t3 TSRMLS_CC);
		}
		Z_ADDREF_P(t3);
		if (Z_TYPE_P(t3) != IS_ARRAY) {
			convert_to_array(t3);
			phalcon_array_update(v3, v6, t3 TSRMLS_CC);
		}
		if (Z_TYPE_P(t3) == IS_ARRAY) {
			PHALCON_INIT_VAR(t4);
			phalcon_array_fetch_string(&t4, t3, "referencedColumns", strlen("referencedColumns"), PHALCON_SILENT_FETCH TSRMLS_CC);
		}
		if (Z_REFCOUNT_P(t4) > 1) {
			zval *new_zv;
			Z_DELREF_P(t4);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, t4);
			t4 = new_zv;
			zval_copy_ctor(new_zv);
			phalcon_array_update_string(t3, "referencedColumns", strlen("referencedColumns"), t4 TSRMLS_CC);
		}
		Z_ADDREF_P(t4);
		if (Z_TYPE_P(t4) != IS_ARRAY) {
			convert_to_array(t4);
			phalcon_array_update_string(t3, "referencedColumns", strlen("referencedColumns"), t4 TSRMLS_CC);
		}
		Z_ADDREF_P(r7);
		phalcon_array_append(t4, r7 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_321f_3;
		fee_321f_3:
		if(0){ };
	}
	PHALCON_INIT_VAR(a4);
	array_init(a4);
	PHALCON_CPY_WRT(v7, a4);
	if (Z_TYPE_P(v3) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah1 = Z_ARRVAL_P(v3);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_321f_4:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_321f_4;
		} else {
			PHALCON_INIT_VAR(v9);
			htype = zend_hash_get_current_key_ex(ah1, &index, &index_len, &num, 0, &hp1);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v9, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v9, num);
				}
			}
		}
		PHALCON_INIT_VAR(v8);
		ZVAL_ZVAL(v8, *hd, 1, 0);
		PHALCON_INIT_VAR(i0);
		object_init_ex(i0, phalcon_db_reference_class_entry);
		Z_ADDREF_P(v9);
		p2[0] = v9;
		PHALCON_INIT_VAR(a5);
		array_init(a5);
		PHALCON_INIT_VAR(r8);
		phalcon_array_fetch_string(&r8, v8, "referencedSchema", strlen("referencedSchema"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r8);
		PHALCON_SEPARATE_ARRAY(a5);
		add_assoc_zval(a5, "referencedSchema", r8);
		PHALCON_INIT_VAR(r9);
		phalcon_array_fetch_string(&r9, v8, "referencedTable", strlen("referencedTable"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r9);
		PHALCON_SEPARATE_ARRAY(a5);
		add_assoc_zval(a5, "referencedTable", r9);
		PHALCON_INIT_VAR(r10);
		phalcon_array_fetch_string(&r10, v8, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r10);
		PHALCON_SEPARATE_ARRAY(a5);
		add_assoc_zval(a5, "columns", r10);
		PHALCON_INIT_VAR(r11);
		phalcon_array_fetch_string(&r11, v8, "referencedColumns", strlen("referencedColumns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r11);
		PHALCON_SEPARATE_ARRAY(a5);
		add_assoc_zval(a5, "referencedColumns", r11);
		Z_ADDREF_P(a5);
		p2[1] = a5;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p2, PHALCON_CALL_CHECK);
		Z_DELREF_P(p2[0]);
		Z_DELREF_P(p2[1]);
		Z_ADDREF_P(i0);
		if (Z_REFCOUNT_P(v7) > 1) {
			zval *new_zv;
			Z_DELREF_P(v7);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v7);
			v7 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update(v7, v9, i0 TSRMLS_CC);
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_321f_4;
		fee_321f_4:
		if(0){ };
	}
	PHALCON_INIT_VAR(t5);
	ZVAL_LONG(t5, 3);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t5 TSRMLS_CC);
	PHALCON_RETURN_CTOR(v7);
}

/**
 * Get the creation options from a table
 *
 * @paramstring $table
 * @paramstring $schema
 * @returnarray
 */
PHP_METHOD(Phalcon_Db_Adapter_Mysql, tableOptions){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL, NULL }, *p1[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_db_dialect_mysql", "tableoptions", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 1);
	phalcon_update_property_zval(this_ptr, "_fetchMode", strlen("_fetchMode"), t0 TSRMLS_CC);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v3, a0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	p1[0] = v2;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetchall", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_CPY_WRT(v4, r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(r2);
}

