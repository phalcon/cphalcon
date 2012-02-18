
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

PHP_METHOD(Phalcon_Model_Row, __construct){

	zval *a0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Row", "::__construct", 0);
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_property(phalcon_model_row_class_entry, this_ptr, "_columns", strlen("_columns"), a0 TSRMLS_CC);
}

PHP_METHOD(Phalcon_Model_Row, setConnection){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Row", "setConnection", 0);
	phalcon_step_over("Phalcon_Model_Row::setConnection (Assignment) File=Library/Phalcon/Model/Row.php Line=10");
	//$connection
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Row::setConnection (Method) File=Library/Phalcon/Model/Row.php Line=13");
}

PHP_METHOD(Phalcon_Model_Row, getConnection){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Row", "getConnection", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t0) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Row::getConnection (Method) File=Library/Phalcon/Model/Row.php Line=17");
}

PHP_METHOD(Phalcon_Model_Row, dumpResult){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *s0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *a0 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Row", "dumpResult", 0);
	phalcon_step_over("Phalcon_Model_Row::dumpResult (Assignment) File=Library/Phalcon/Model/Row.php Line=18");
	//$objectRow
	//$this
	phalcon_clone(&s0, this_ptr TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(s0);
	v1 = s0;
	phalcon_debug_assign("$objectRow", s0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Row::dumpResult (If) File=Library/Phalcon/Model/Row.php Line=19");
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_columns", sizeof("_columns")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	p0[0] = t0;
	phalcon_debug_param(t0 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "count", 1, p0);
	phalcon_debug_vdump("count > ", r0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_EQUAL_FUNCTION(r1, r0, t1);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Model_Row::dumpResult (Block) File=Library/Phalcon/Model/Row.php Line=19");
		phalcon_step_over("Phalcon_Model_Row::dumpResult (Assignment) File=Library/Phalcon/Model/Row.php Line=20");
		//$columns
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(a0);
		v2 = a0;
		phalcon_debug_assign("$columns", a0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Row::dumpResult (Foreach) File=Library/Phalcon/Model/Row.php Line=21");
		//$result
		//$value
		//$field
		FOREACH_KV(v0, ac0, fes63, fee63, ah0, hp0, v4, v3)
			phalcon_step_over("Phalcon_Model_Row::dumpResult (Block) File=Library/Phalcon/Model/Row.php Line=21");
			phalcon_step_over("Phalcon_Model_Row::dumpResult (Assignment) File=Library/Phalcon/Model/Row.php Line=22");
			PHALCON_INIT_TRUE(t2);
			//$columns
			//$field
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, t2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				{
					zval *orig_ptr = v2;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(v2);
						*v2 = *orig_ptr;
						zval_copy_ctor(v2);
						Z_SET_REFCOUNT_P(v2, 1);
						Z_UNSET_ISREF_P(v2);
					}
				}
				phalcon_array_update(v2, v4, copy TSRMLS_CC);
			}
			phalcon_step_over("Phalcon_Model_Row::dumpResult (Assignment) File=Library/Phalcon/Model/Row.php Line=23");
			//$field
			//$value
			//$objectRow
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v3, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(v1, Z_STRVAL_P(v4), Z_STRLEN_P(v4), copy TSRMLS_CC);
			}
		END_FOREACH(ac0, fes63, fee63, ah0, hp0);
		phalcon_step_over("Phalcon_Model_Row::dumpResult (Assignment) File=Library/Phalcon/Model/Row.php Line=25");
		//$columns
		//$objectRow
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(v1, "_columns", strlen("_columns"), copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Model_Row::dumpResult (Assignment) File=Library/Phalcon/Model/Row.php Line=26");
		//$columns
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v2, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_columns", strlen("_columns"), copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Model_Row::dumpResult (Block) File=Library/Phalcon/Model/Row.php Line=27");
		phalcon_step_over("Phalcon_Model_Row::dumpResult (Foreach) File=Library/Phalcon/Model/Row.php Line=28");
		//$result
		//$value
		//$field
		FOREACH_KV(v0, ac1, fes64, fee64, ah1, hp1, v4, v3)
			phalcon_step_over("Phalcon_Model_Row::dumpResult (Block) File=Library/Phalcon/Model/Row.php Line=28");
			phalcon_step_over("Phalcon_Model_Row::dumpResult (Assignment) File=Library/Phalcon/Model/Row.php Line=29");
			//$field
			//$value
			//$objectRow
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v3, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(v1, Z_STRVAL_P(v4), Z_STRLEN_P(v4), copy TSRMLS_CC);
			}
		END_FOREACH(ac1, fes64, fee64, ah1, hp1);
		phalcon_step_over("Phalcon_Model_Row::dumpResult (Assignment) File=Library/Phalcon/Model/Row.php Line=31");
		//$this
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_columns", sizeof("_columns")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t3);
		//$objectRow
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t3, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(v1, "_columns", strlen("_columns"), copy TSRMLS_CC);
		}
	}
	//$objectRow
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Row::dumpResult (Method) File=Library/Phalcon/Model/Row.php Line=36");
}

PHP_METHOD(Phalcon_Model_Row, readAttribute){

	zval *v0 = NULL;
	zval *t0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Row", "readAttribute", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	//$property
	phalcon_read_property_zval(t0, this_ptr, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t0) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Row::readAttribute (Method) File=Library/Phalcon/Model/Row.php Line=40");
}

PHP_METHOD(Phalcon_Model_Row, sleep){

	zval *a0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Row", "sleep", 0);
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_next_index_string(a0, "_columns", 1);
	phalcon_debug_vdump("Returning > ", a0 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(a0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
}

