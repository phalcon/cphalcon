
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
 * Phalcon_Model_Resultset
 *
 * This component allows to Phalcon_Model_Base returns large resulsets with the minimum memory comsuption
 *
 * Resulsets can be traversed using a standard foreach or a while statement.
 *
 * 
 *
 */

/**
 * Phalcon_Model_Resultset constructor
 *
 * @param Phalcon_Model_Base $model
 * @param resource $resultResource
 */
PHP_METHOD(Phalcon_Model_Resultset, __construct){

	zval *v0 = NULL, *v1 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Resultset", "__construct", 0);
	phalcon_step_over("Phalcon_Model_Resultset::__construct (Assignment) File=/Model/Resultset Line=47");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_model", strlen("_model"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Resultset::__construct (Assignment) File=/Model/Resultset Line=48");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_resultResource", strlen("_resultResource"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::__construct (Method) File=/Model/Resultset Line=56");
}

/**
 * Check whether internal resource has rows to fetch
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Resultset, valid){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Resultset", "valid", 0);
	phalcon_step_over("Phalcon_Model_Resultset::valid (If) File=/Model/Resultset Line=57");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) == IS_BOOL && !Z_BVAL_P(t0)) {
		phalcon_step_over("Phalcon_Model_Resultset::valid (Block) File=/Model/Resultset Line=57");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_over("Phalcon_Model_Resultset::valid (Assignment) File=/Model/Resultset Line=60");
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v0, t1);
	phalcon_debug_assign("$model", t1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Resultset::valid (Assignment) File=/Model/Resultset Line=61");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(v0, "getconnection" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, v0, "getconnection", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v1, r0);
	phalcon_debug_assign("$dbResource", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Resultset::valid (MethodCall) File=/Model/Resultset Line=62");
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(v1, "setfetchmode" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_get_class_constant(t2, phalcon_db_class_entry, "DB_ASSOC", strlen("DB_ASSOC") TSRMLS_CC);
	Z_ADDREF_P(t2);
	p1[0] = t2;
	phalcon_debug_param(t2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "setfetchmode", 1, p1, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Resultset::valid (Assignment) File=/Model/Resultset Line=63");
	PHALCON_ALLOC_ZVAL(r1);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(v1, "fetcharray" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t3);
	p2[0] = t3;
	phalcon_debug_param(t3 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r1, v1, "fetcharray", 1, p2, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r1);
	phalcon_debug_assign("$row", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Resultset::valid (If) File=/Model/Resultset Line=64");
	if (zend_is_true(v2)) {
		phalcon_step_over("Phalcon_Model_Resultset::valid (Block) File=/Model/Resultset Line=64");
		phalcon_step_over("Phalcon_Model_Resultset::valid (Assignment) File=/Model/Resultset Line=68");
		PHALCON_ALLOC_ZVAL(r2);
		Z_ADDREF_P(v0);
		p3[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		Z_ADDREF_P(v2);
		p3[1] = v2;
		phalcon_debug_param(v2 TSRMLS_CC);
		PHALCON_CALL_STATIC_PARAMS(r2, "phalcon_model_base", "dumpresult", 2, p3);
		phalcon_debug_vdump("StaticReturn > ", r2 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_activeRow", strlen("_activeRow"), copy TSRMLS_CC);
		}
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	} else {
		phalcon_step_over("Phalcon_Model_Resultset::valid (Block) File=/Model/Resultset Line=70");
		phalcon_step_over("Phalcon_Model_Resultset::valid (MethodCall) File=/Model/Resultset Line=71");
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(v1, "setfetchmode" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t4);
		phalcon_get_class_constant(t4, phalcon_db_class_entry, "DB_BOTH", strlen("DB_BOTH") TSRMLS_CC);
		Z_ADDREF_P(t4);
		p4[0] = t4;
		phalcon_debug_param(t4 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "setfetchmode", 1, p4, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::valid (Method) File=/Model/Resultset Line=81");
}

/**
 * Returns current row in the resultset
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Resultset, current){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Resultset", "current", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_activeRow", sizeof("_activeRow")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Resultset::current (Method) File=/Model/Resultset Line=89");
}

/**
 * Moves cursor to next row in the resultset
 *
 */
PHP_METHOD(Phalcon_Model_Resultset, next){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Resultset", "next", 0);
	phalcon_step_over("Phalcon_Model_Resultset::next (PreIncDecOp) File=/Model/Resultset Line=90");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_SEPARATE(t0);
	increment_function(t0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::next (Method) File=/Model/Resultset Line=97");
}

/**
 * Gets pointer number to active row in the resultset
 *
 */
PHP_METHOD(Phalcon_Model_Resultset, key){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Resultset", "key", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Resultset::key (Method) File=/Model/Resultset Line=105");
}

/**
 * Rewinds resultset to its beginning
 *
 */
PHP_METHOD(Phalcon_Model_Resultset, rewind){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p1[] = { NULL, NULL };

	phalcon_step_into_entry("Phalcon_Model_Resultset", "rewind", 0);
	phalcon_step_over("Phalcon_Model_Resultset::rewind (If) File=/Model/Resultset Line=106");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) == IS_BOOL && !Z_BVAL_P(t0)) {
		phalcon_step_over("Phalcon_Model_Resultset::rewind (Block) File=/Model/Resultset Line=106");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_over("Phalcon_Model_Resultset::rewind (Assignment) File=/Model/Resultset Line=109");
	phalcon_update_property_long(this_ptr, "pointer", strlen("pointer"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Resultset::rewind (Assignment) File=/Model/Resultset Line=110");
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(t1, "getconnection" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t1, "getconnection", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	PHALCON_CPY_WRT_PARAM(v0, r0);
	phalcon_debug_assign("$dbResource", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Resultset::rewind (MethodCall) File=/Model/Resultset Line=111");
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(v0, "dataseek" TSRMLS_CC);
	PHALCON_PARAM_LONG(p1[0], 0);
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t2);
	p1[1] = t2;
	phalcon_debug_param(t2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "dataseek", 2, p1, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::rewind (Method) File=/Model/Resultset Line=117");
}

/**
 * Changes interal pointer to a specifically position in the resultset
 */
PHP_METHOD(Phalcon_Model_Resultset, seek){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p1[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Resultset", "seek", 0);
	phalcon_step_over("Phalcon_Model_Resultset::seek (Assignment) File=/Model/Resultset Line=118");
	convert_to_long(v0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_pointer", strlen("_pointer"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Resultset::seek (Assignment) File=/Model/Resultset Line=119");
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(t0, "getconnection" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "getconnection", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r0);
	phalcon_debug_assign("$dbResource", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Resultset::seek (MethodCall) File=/Model/Resultset Line=120");
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(v1, "dataseek" TSRMLS_CC);
	convert_to_long(v0);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t1);
	p1[1] = t1;
	phalcon_debug_param(t1 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "dataseek", 2, p1, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::seek (Method) File=/Model/Resultset Line=128");
}

/**
 * Counts how many rows are in the resultset
 *
 * @return int
 */
PHP_METHOD(Phalcon_Model_Resultset, count){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *v0 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Resultset", "count", 0);
	phalcon_step_over("Phalcon_Model_Resultset::count (If) File=/Model/Resultset Line=129");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) == IS_BOOL && !Z_BVAL_P(t0)) {
		phalcon_step_over("Phalcon_Model_Resultset::count (Block) File=/Model/Resultset Line=129");
		phalcon_step_out_entry();
		RETURN_LONG(0);
	}
	phalcon_step_over("Phalcon_Model_Resultset::count (If) File=/Model/Resultset Line=132");
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_count", sizeof("_count")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t1);
	p0[0] = t1;
	phalcon_debug_param(t1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "is_null", 1, p0);
	phalcon_debug_vdump("is_null > ", r0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Model_Resultset::count (Block) File=/Model/Resultset Line=132");
		phalcon_step_over("Phalcon_Model_Resultset::count (Assignment) File=/Model/Resultset Line=133");
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(t2, "getconnection" TSRMLS_CC);
		PHALCON_CALL_METHOD(r1, t2, "getconnection", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		PHALCON_CPY_WRT_PARAM(v0, r1);
		phalcon_debug_assign("$dbResource", r1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Resultset::count (Assignment) File=/Model/Resultset Line=134");
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(v0, "numrows" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t3);
		p2[0] = t3;
		phalcon_debug_param(t3 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r2, v0, "numrows", 1, p2, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_count", strlen("_count"), copy TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(t4);
	phalcon_read_property(t4, this_ptr, "_count", sizeof("_count")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t4 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t4);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Resultset::count (Method) File=/Model/Resultset Line=144");
}

/**
 * Checks whether offset exists in the resultset
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, offsetExists){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Resultset", "offsetExists", 0);
	phalcon_step_over("Phalcon_Model_Resultset::offsetExists (If) File=/Model/Resultset Line=145");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "count" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "count", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	is_smaller_function(r1, v0, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Model_Resultset::offsetExists (Block) File=/Model/Resultset Line=145");
		phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_TRUE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::offsetExists (Method) File=/Model/Resultset Line=155");
}

/**
 * Gets row in a specifically position of the resultset
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, offsetGet){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL }, *p4[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Resultset", "offsetGet", 0);
	phalcon_step_over("Phalcon_Model_Resultset::offsetGet (If) File=/Model/Resultset Line=156");
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "count" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "count", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r1);
	is_smaller_function(r1, v0, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Model_Resultset::offsetGet (Block) File=/Model/Resultset Line=156");
		phalcon_step_over("Phalcon_Model_Resultset::offsetGet (MethodCall) File=/Model/Resultset Line=157");
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "seek" TSRMLS_CC);
		Z_ADDREF_P(v0);
		p1[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "seek", 1, p1, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Resultset::offsetGet (If) File=/Model/Resultset Line=158");
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "valid" TSRMLS_CC);
		PHALCON_CALL_METHOD(r2, this_ptr, "valid", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		if (zend_is_true(r2)) {
			phalcon_step_over("Phalcon_Model_Resultset::offsetGet (Block) File=/Model/Resultset Line=158");
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "current" TSRMLS_CC);
			PHALCON_CALL_METHOD(r3, this_ptr, "current", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_ZVAL(r3, 1, 0);
		} else {
			phalcon_step_over("Phalcon_Model_Resultset::offsetGet (Block) File=/Model/Resultset Line=160");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	} else {
		phalcon_step_over("Phalcon_Model_Resultset::offsetGet (Block) File=/Model/Resultset Line=163");
		phalcon_step_over("Phalcon_Model_Resultset::offsetGet (Throw) File=/Model/Resultset Line=164");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p4[0]);
		ZVAL_STRING(p4[0], "The index does not exist in the cursor", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p4, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::offsetGet (Method) File=/Model/Resultset Line=173");
}

/**
 * Resulsets cannot be changed. It has only been implemented to meet the definition of the interface
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, offsetSet){

	zval *v0 = NULL, *v1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Resultset", "offsetSet", 0);
	phalcon_step_over("Phalcon_Model_Resultset::offsetSet (Throw) File=/Model/Resultset Line=174");
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_model_exception_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "Cursor is read only", 1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	zend_throw_exception_object(i0 TSRMLS_CC);
	Z_ADDREF_P(i0);
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Resultset::offsetSet (Method) File=/Model/Resultset Line=182");
}

/**
 * Resulsets cannot be changed. It has only been implemented to meet the definition of the interface
 *
 * @param int $index
 */
PHP_METHOD(Phalcon_Model_Resultset, offsetUnset){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Resultset", "offsetUnset", 0);
	phalcon_step_over("Phalcon_Model_Resultset::offsetUnset (Throw) File=/Model/Resultset Line=183");
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_model_exception_class_entry);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "Cursor is read only", 1);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	zend_throw_exception_object(i0 TSRMLS_CC);
	Z_ADDREF_P(i0);
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Resultset::offsetUnset (Method) File=/Model/Resultset Line=191");
}

/**
 * Get first row in the resultset
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Resultset, getFirst){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Resultset", "getFirst", 0);
	phalcon_step_over("Phalcon_Model_Resultset::getFirst (If) File=/Model/Resultset Line=192");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_pointer", sizeof("_pointer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 1);
	PHALCON_ALLOC_ZVAL(r0);
	is_not_equal_function(r0, t0, t1 TSRMLS_CC);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Model_Resultset::getFirst (Block) File=/Model/Resultset Line=192");
		phalcon_step_over("Phalcon_Model_Resultset::getFirst (MethodCall) File=/Model/Resultset Line=193");
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "rewind" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "rewind", PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Resultset::getFirst (If) File=/Model/Resultset Line=195");
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t2) != IS_BOOL || (Z_TYPE_P(t2) == IS_BOOL && Z_BVAL_P(t2))) {
		phalcon_step_over("Phalcon_Model_Resultset::getFirst (Block) File=/Model/Resultset Line=195");
		phalcon_step_over("Phalcon_Model_Resultset::getFirst (If) File=/Model/Resultset Line=196");
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "valid" TSRMLS_CC);
		PHALCON_CALL_METHOD(r1, this_ptr, "valid", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		if (zend_is_true(r1)) {
			phalcon_step_over("Phalcon_Model_Resultset::getFirst (Block) File=/Model/Resultset Line=196");
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "current" TSRMLS_CC);
			PHALCON_CALL_METHOD(r2, this_ptr, "current", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r2 TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_ZVAL(r2, 1, 0);
		} else {
			phalcon_step_over("Phalcon_Model_Resultset::getFirst (Block) File=/Model/Resultset Line=198");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	} else {
		phalcon_step_over("Phalcon_Model_Resultset::getFirst (Block) File=/Model/Resultset Line=201");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::getFirst (Method) File=/Model/Resultset Line=211");
}

/**
 * Get last row in the resultset
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Resultset, getLast){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Resultset", "getLast", 0);
	phalcon_step_over("Phalcon_Model_Resultset::getLast (If) File=/Model/Resultset Line=212");
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_resultResource", sizeof("_resultResource")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_BOOL || (Z_TYPE_P(t0) == IS_BOOL && Z_BVAL_P(t0))) {
		phalcon_step_over("Phalcon_Model_Resultset::getLast (Block) File=/Model/Resultset Line=212");
		phalcon_step_over("Phalcon_Model_Resultset::getLast (MethodCall) File=/Model/Resultset Line=213");
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "seek" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "count" TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, this_ptr, "count", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_LONG(t1, 1);
		PHALCON_ALLOC_ZVAL(r1);
		sub_function(r1, r0, t1 TSRMLS_CC);
		Z_ADDREF_P(r1);
		p0[0] = r1;
		phalcon_debug_param(r1 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "seek", 1, p0, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Resultset::getLast (If) File=/Model/Resultset Line=214");
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "valid" TSRMLS_CC);
		PHALCON_CALL_METHOD(r2, this_ptr, "valid", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
		if (zend_is_true(r2)) {
			phalcon_step_over("Phalcon_Model_Resultset::getLast (Block) File=/Model/Resultset Line=214");
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "current" TSRMLS_CC);
			PHALCON_CALL_METHOD(r3, this_ptr, "current", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Resultset" TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_ZVAL(r3, 1, 0);
		} else {
			phalcon_step_over("Phalcon_Model_Resultset::getLast (Block) File=/Model/Resultset Line=216");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	} else {
		phalcon_step_over("Phalcon_Model_Resultset::getLast (Block) File=/Model/Resultset Line=219");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Resultset::getLast (Method) File=/Model/Resultset Line=229");
}

/**
 * Get model which originates the resultset
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Resultset, getModel){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Resultset", "getModel", 0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_model", sizeof("_model")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	PHALCON_RETURN_CTOR(t0);
	phalcon_step_out_entry();
}

