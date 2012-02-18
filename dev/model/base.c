
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
 * Php_Model_Base
 *
 * Php_Model connects business objects and database tables to create 
 * a persistable domain model where logic and data are presented in one wrapping. 
 * It‘s an implementation of the object- relational mapping (ORM)
 *
 */

PHP_METHOD(Phalcon_Model_Base, __construct){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_NULL(v0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "__construct", 0);
	phalcon_step_over("Phalcon_Model_Base::__construct (If) File=Library/Phalcon/Model/Base.php Line=52");
	//$manager
	if (!zend_is_true(v0)) {
		phalcon_step_over("Phalcon_Model_Base::__construct (Block) File=Library/Phalcon/Model/Base.php Line=52");
		phalcon_step_over("Phalcon_Model_Base::__construct (Assignment) File=Library/Phalcon/Model/Base.php Line=53");
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
		phalcon_debug_vdump("StaticReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(r1, "getmodelcomponent" TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, r1, "getmodelcomponent", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Model_Base::__construct (Block) File=Library/Phalcon/Model/Base.php Line=54");
		phalcon_step_over("Phalcon_Model_Base::__construct (Assignment) File=Library/Phalcon/Model/Base.php Line=55");
		//$manager
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Model_Base::__construct (If) File=Library/Phalcon/Model/Base.php Line=57");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "initialize", 1);
	if (phalcon_method_exists(this_ptr, t0 TSRMLS_CC) == SUCCESS) {
		phalcon_step_over("Phalcon_Model_Base::__construct (Block) File=Library/Phalcon/Model/Base.php Line=57");
		phalcon_step_over("Phalcon_Model_Base::__construct (MethodCall) File=Library/Phalcon/Model/Base.php Line=58");
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "initialize" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "initialize", PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Base::__construct (Method) File=Library/Phalcon/Model/Base.php Line=65");
}

/**
 * Internal method for doing connection
 */
PHP_METHOD(Phalcon_Model_Base, _connect){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Base", "_connect", 0);
	phalcon_step_over("Phalcon_Model_Base::_connect (If) File=Library/Phalcon/Model/Base.php Line=66");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Model_Base::_connect (Block) File=Library/Phalcon/Model/Base.php Line=66");
		phalcon_step_over("Phalcon_Model_Base::_connect (Assignment) File=Library/Phalcon/Model/Base.php Line=67");
		PHALCON_ALLOC_ZVAL(r0);
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(t1, "getconnection" TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, t1, "getconnection", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Model_Base::_connect (MethodCall) File=Library/Phalcon/Model/Base.php Line=69");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "dump" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "dump", PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Base::_connect (Method) File=Library/Phalcon/Model/Base.php Line=75");
}

/**
 * Internal method for get field attributes
 */
PHP_METHOD(Phalcon_Model_Base, _getAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Base", "_getAttributes", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(t0, "getmetadata" TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(r1, "getattributes" TSRMLS_CC);
	//$this
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	phalcon_debug_param(this_ptr TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getattributes", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Base::_getAttributes (Method) File=Library/Phalcon/Model/Base.php Line=79");
}

PHP_METHOD(Phalcon_Model_Base, _getPrimaryKeyAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Base", "_getPrimaryKeyAttributes", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(t0, "getmetadata" TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(r1, "getprimarykeyattributes" TSRMLS_CC);
	//$this
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	phalcon_debug_param(this_ptr TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getprimarykeyattributes", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Base::_getPrimaryKeyAttributes (Method) File=Library/Phalcon/Model/Base.php Line=83");
}

PHP_METHOD(Phalcon_Model_Base, _getNonPrimaryKeyAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Base", "_getNonPrimaryKeyAttributes", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(t0, "getmetadata" TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(r1, "getnonprimarykeyattributes" TSRMLS_CC);
	//$this
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	phalcon_debug_param(this_ptr TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getnonprimarykeyattributes", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Base::_getNonPrimaryKeyAttributes (Method) File=Library/Phalcon/Model/Base.php Line=87");
}

PHP_METHOD(Phalcon_Model_Base, _getNotNullAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Base", "_getNotNullAttributes", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(t0, "getmetadata" TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(r1, "getnotnullattributes" TSRMLS_CC);
	//$this
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	phalcon_debug_param(this_ptr TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getnotnullattributes", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Base::_getNotNullAttributes (Method) File=Library/Phalcon/Model/Base.php Line=91");
}

PHP_METHOD(Phalcon_Model_Base, _getDataTypesNumeric){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Base", "_getDataTypesNumeric", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(t0, "getmetadata" TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(r1, "getdatatypesnumeric" TSRMLS_CC);
	//$this
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	phalcon_debug_param(this_ptr TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getdatatypesnumeric", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Base::_getDataTypesNumeric (Method) File=Library/Phalcon/Model/Base.php Line=95");
}

PHP_METHOD(Phalcon_Model_Base, _getDataTypes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Base", "_getDataTypes", 0);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(t0, "getmetadata" TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(r1, "getdatatypes" TSRMLS_CC);
	//$this
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	phalcon_debug_param(this_ptr TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getdatatypes", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Base::_getDataTypes (Method) File=Library/Phalcon/Model/Base.php Line=99");
}

PHP_METHOD(Phalcon_Model_Base, dump){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Model_Base", "dump", 0);
	phalcon_step_over("Phalcon_Model_Base::dump (If) File=Library/Phalcon/Model/Base.php Line=100");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_dumped", sizeof("_dumped")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Model_Base::dump (Block) File=Library/Phalcon/Model/Base.php Line=100");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_over("Phalcon_Model_Base::dump (Assignment) File=Library/Phalcon/Model/Base.php Line=103");
	//$this
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumped", strlen("_dumped"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::dump (Assignment) File=Library/Phalcon/Model/Base.php Line=104");
	//$this
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::dump (Assignment) File=Library/Phalcon/Model/Base.php Line=105");
	//$attributes
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(t1, "getmetadata" TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t1, "getmetadata", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(r1, "getattributes" TSRMLS_CC);
	//$this
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	phalcon_debug_param(this_ptr TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getattributes", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r0);
	v0 = r0;
	phalcon_debug_assign("$attributes", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::dump (Foreach) File=Library/Phalcon/Model/Base.php Line=106");
	//$attributes
	//$field
	FOREACH_V(v0, ac0, fes65, fee65, ah0, hp0, v1)
		phalcon_step_over("Phalcon_Model_Base::dump (Block) File=Library/Phalcon/Model/Base.php Line=106");
		phalcon_step_over("Phalcon_Model_Base::dump (If) File=Library/Phalcon/Model/Base.php Line=107");
		//$this
		//$field
		eval_int = phalcon_isset_property_zval(this_ptr, v1 TSRMLS_CC);
		if (!eval_int) {
			phalcon_step_over("Phalcon_Model_Base::dump (Block) File=Library/Phalcon/Model/Base.php Line=107");
			phalcon_step_over("Phalcon_Model_Base::dump (Assignment) File=Library/Phalcon/Model/Base.php Line=108");
			//$field
			if (!t2) {
				PHALCON_ALLOC_ZVAL(t2);
			} else {
				if (Z_REFCOUNT_P(t2) > 1) {
					SEPARATE_ZVAL(&t2);
				} else {
					if (Z_TYPE_P(t2) != IS_STRING) {
						FREE_ZVAL(t2);
						PHALCON_ALLOC_ZVAL(t2);
					}
				}
			}
			ZVAL_STRING(t2, "", 1);
			//$this
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, t2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v1), Z_STRLEN_P(v1), copy TSRMLS_CC);
			}
		}
	END_FOREACH(ac0, fes65, fee65, ah0, hp0);
	phalcon_step_over("Phalcon_Model_Base::dump (Assignment) File=Library/Phalcon/Model/Base.php Line=111");
	//$this
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 0 TSRMLS_CC);
	//$this
	phalcon_debug_vdump("Returning > ", this_ptr TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(this_ptr) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(this_ptr);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(this_ptr);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Base::dump (Method) File=Library/Phalcon/Model/Base.php Line=115");
}

PHP_METHOD(Phalcon_Model_Base, _createSQLSelectMulti){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL, *r41 = NULL;
	zval *r42 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL;
	zval *p1[] = { NULL, NULL }, *p4[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL }, *p7[] = { NULL }, *p8[] = { NULL, NULL }, *p9[] = { NULL }, *p10[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "_createSQLSelectMulti", 0);
	phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Assignment) File=Library/Phalcon/Model/Base.php Line=116");
	//$select
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "SELECT ", 0);
	phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=117");
	//$params
	eval_int = phalcon_array_isset_string(v0, "columns", strlen("columns")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=117");
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (MethodCall) File=Library/Phalcon/Model/Base.php Line=118");
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "clear" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "clear", PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (AssignOp) File=Library/Phalcon/Model/Base.php Line=119");
		//$select
		//$params
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, v0, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r1, v1, r0);
		//$select
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r1);
		v1 = r1;
		phalcon_debug_assign("$select", r1 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=120");
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (AssignOp) File=Library/Phalcon/Model/Base.php Line=121");
		//$select
		PHALCON_ALLOC_ZVAL(r2);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], ", ", 1);
		PHALCON_ALLOC_ZVAL(r3);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "_getattributes" TSRMLS_CC);
		PHALCON_CALL_METHOD(r3, this_ptr, "_getattributes", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		p1[1] = r3;
		phalcon_debug_param(r3 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r2, "join", 2, p1);
		phalcon_debug_vdump("join > ", r2 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r4, v1, r2);
		//$select
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r4);
		v1 = r4;
		phalcon_debug_assign("$select", r4 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=123");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=123");
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (AssignOp) File=Library/Phalcon/Model/Base.php Line=124");
		//$select
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_concat_left(r6, " FROM ", t1 TSRMLS_CC);
		//$this
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		PHALCON_ALLOC_ZVAL(r5);
		phalcon_concat_vboth(r5, r6, ".", t2 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r7, v1, r5);
		//$select
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r7);
		v1 = r7;
		phalcon_debug_assign("$select", r7 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=125");
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (AssignOp) File=Library/Phalcon/Model/Base.php Line=126");
		//$select
		//$this
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t3);
		PHALCON_ALLOC_ZVAL(r8);
		phalcon_concat_left(r8, " FROM ", t3 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r9, v1, r8);
		//$select
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r9);
		v1 = r9;
		phalcon_debug_assign("$select", r9 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Assignment) File=Library/Phalcon/Model/Base.php Line=128");
	//$return
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_STRING(v2, "n", 0);
	phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=129");
	//$params
	eval_int = phalcon_array_isset_string(v0, "conditions", strlen("conditions")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=129");
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (AssignOp) File=Library/Phalcon/Model/Base.php Line=130");
		//$select
		//$params
		PHALCON_ALLOC_ZVAL(r10);
		phalcon_array_fetch_string(r10, v0, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r11);
		phalcon_concat_both(r11,  " WHERE ", r10, " " TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r12, v1, r11);
		//$select
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r12);
		v1 = r12;
		phalcon_debug_assign("$select", r12 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=131");
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Assignment) File=Library/Phalcon/Model/Base.php Line=132");
		//$primaryKeys
		PHALCON_ALLOC_ZVAL(r13);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "_getprimarykeyattributes" TSRMLS_CC);
		PHALCON_CALL_METHOD(r13, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r13 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r13);
		v3 = r13;
		phalcon_debug_assign("$primaryKeys", r13 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=133");
		//$primaryKeys
		eval_int = phalcon_array_isset_long(v3, 0);
		if (!eval_int) {
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=133");
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=134");
			//$this
			PHALCON_ALLOC_ZVAL(t4);
			phalcon_read_property(t4, this_ptr, "_isView", sizeof("_isView")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t4);
			if (zend_is_true(t4)) {
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=134");
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Assignment) File=Library/Phalcon/Model/Base.php Line=135");
				PHALCON_ALLOC_ZVAL(t5);
				ZVAL_STRING(t5, "id", 1);
				//$primaryKeys
				{
					zval *orig_ptr = v3;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(v3);
						*v3 = *orig_ptr;
						zval_copy_ctor(v3);
						Z_SET_REFCOUNT_P(v3, 1);
						Z_UNSET_ISREF_P(v3);
					}
				}
				phalcon_array_update_long(v3, 0, t5 TSRMLS_CC);
			}
		}
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=138");
		//$params
		eval_int = phalcon_array_isset_long(v0, 0);
		if (eval_int) {
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=138");
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=139");
			PHALCON_ALLOC_ZVAL(r14);
			//$params
			PHALCON_ALLOC_ZVAL(r15);
			phalcon_array_fetch_long(r15, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r15);
			p4[0] = r15;
			phalcon_debug_param(r15 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r14, "is_numeric", 1, p4);
			phalcon_debug_vdump("is_numeric > ", r14 TSRMLS_CC);
			if (zend_is_true(r14)) {
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=139");
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=140");
				//$primaryKeys
				eval_int = phalcon_array_isset_long(v3, 0);
				if (eval_int) {
					phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=140");
					phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Assignment) File=Library/Phalcon/Model/Base.php Line=141");
					//$primaryKeys
					PHALCON_ALLOC_ZVAL(r17);
					phalcon_array_fetch_long(r17, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_ALLOC_ZVAL(r18);
					//$this
					PHALCON_ALLOC_ZVAL(t6);
					phalcon_read_property(t6, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
					zval_copy_ctor(t6);
					phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
					phalcon_debug_method_call(t6, "addquotes" TSRMLS_CC);
					//$params
					PHALCON_ALLOC_ZVAL(r19);
					phalcon_array_fetch_long(r19, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r19);
					p5[0] = r19;
					phalcon_debug_param(r19 TSRMLS_CC);
					PHALCON_CALL_METHOD_PARAMS(r18, t6, "addquotes", 1, p5, PHALCON_CALL_DEFAULT);
					phalcon_debug_vdump("MethodReturn > ", r18 TSRMLS_CC);
					phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
					PHALCON_ALLOC_ZVAL(r16);
					phalcon_concat_vboth(r16, r17, " = ", r18 TSRMLS_CC);
					//$params
					{
						zval *orig_ptr = v0;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							ALLOC_ZVAL(v0);
							*v0 = *orig_ptr;
							zval_copy_ctor(v0);
							Z_SET_REFCOUNT_P(v0, 1);
							Z_UNSET_ISREF_P(v0);
						}
					}
					phalcon_array_update_string(v0, "conditions", strlen("conditions"), r16 TSRMLS_CC);
					phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Assignment) File=Library/Phalcon/Model/Base.php Line=142");
					//$return
					PHALCON_ALLOC_ZVAL(v2);
					ZVAL_STRING(v2, "1", 0);
				} else {
					phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=143");
					phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Throw) File=Library/Phalcon/Model/Base.php Line=144");
					PHALCON_ALLOC_ZVAL(i0);
					object_init_ex(i0, phalcon_model_exception_class_entry);
					phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
					phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
					PHALCON_ALLOC_ZVAL(p6[0]);
					ZVAL_STRING(p6[0], "Has not been defined a primary key for source related to this model", 1);
					PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p6, PHALCON_CALL_CHECK);
					phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
					zend_throw_exception_object(i0 TSRMLS_CC);
					Z_ADDREF_P(i0);
					return;
				}
			} else {
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=146");
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=147");
				//$params
				PHALCON_ALLOC_ZVAL(r20);
				phalcon_array_fetch_long(r20, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(t7);
				ZVAL_STRING(t7, "", 1);
				PHALCON_IDENTICAL_FUNCTION(r21, r20, t7);
				if (zend_is_true(r21)) {
					phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=147");
					phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=148");
					//$primaryKeys
					eval_int = phalcon_array_isset_long(v3, 0);
					if (eval_int) {
						phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=148");
						phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Assignment) File=Library/Phalcon/Model/Base.php Line=149");
						//$primaryKeys
						PHALCON_ALLOC_ZVAL(r22);
						phalcon_array_fetch_long(r22, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_ALLOC_ZVAL(r23);
						phalcon_concat_right(r23, r22, " = ''" TSRMLS_CC);
						//$params
						{
							zval *orig_ptr = v0;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								ALLOC_ZVAL(v0);
								*v0 = *orig_ptr;
								zval_copy_ctor(v0);
								Z_SET_REFCOUNT_P(v0, 1);
								Z_UNSET_ISREF_P(v0);
							}
						}
						phalcon_array_update_string(v0, "conditions", strlen("conditions"), r23 TSRMLS_CC);
					} else {
						phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=150");
						phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Throw) File=Library/Phalcon/Model/Base.php Line=151");
						PHALCON_ALLOC_ZVAL(i1);
						object_init_ex(i1, phalcon_model_exception_class_entry);
						phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
						phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
						PHALCON_ALLOC_ZVAL(p7[0]);
						ZVAL_STRING(p7[0], "Has not been defined a primary key for source related to this model", 1);
						PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p7, PHALCON_CALL_CHECK);
						phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
						zend_throw_exception_object(i1 TSRMLS_CC);
						Z_ADDREF_P(i1);
						return;
					}
				} else {
					phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=153");
					phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Assignment) File=Library/Phalcon/Model/Base.php Line=154");
					//$params
					PHALCON_ALLOC_ZVAL(r24);
					phalcon_array_fetch_long(r24, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					//$params
					{
						zval *orig_ptr = v0;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							ALLOC_ZVAL(v0);
							*v0 = *orig_ptr;
							zval_copy_ctor(v0);
							Z_SET_REFCOUNT_P(v0, 1);
							Z_UNSET_ISREF_P(v0);
						}
					}
					phalcon_array_update_string(v0, "conditions", strlen("conditions"), r24 TSRMLS_CC);
				}
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Assignment) File=Library/Phalcon/Model/Base.php Line=156");
				//$return
				PHALCON_ALLOC_ZVAL(v2);
				ZVAL_STRING(v2, "n", 0);
			}
		}
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=159");
		//$params
		eval_int = phalcon_array_isset_string(v0, "conditions", strlen("conditions")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=159");
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (AssignOp) File=Library/Phalcon/Model/Base.php Line=160");
			//$select
			//$params
			PHALCON_ALLOC_ZVAL(r25);
			phalcon_array_fetch_string(r25, v0, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r26);
			phalcon_concat_left(r26, " WHERE ", r25 TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r27, v1, r26);
			//$select
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r27);
			v1 = r27;
			phalcon_debug_assign("$select", r27 TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=163");
	//$params
	eval_int = phalcon_array_isset_string(v0, "group", strlen("group")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=163");
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=164");
		//$params
		PHALCON_ALLOC_ZVAL(r28);
		phalcon_array_fetch_string(r28, v0, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r28)) {
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=164");
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (AssignOp) File=Library/Phalcon/Model/Base.php Line=165");
			//$select
			//$params
			PHALCON_ALLOC_ZVAL(r29);
			phalcon_array_fetch_string(r29, v0, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r30);
			phalcon_concat_left(r30, " GROUP BY ", r29 TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r31, v1, r30);
			//$select
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r31);
			v1 = r31;
			phalcon_debug_assign("$select", r31 TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=168");
	//$params
	eval_int = phalcon_array_isset_string(v0, "order", strlen("order")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=168");
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=169");
		//$params
		PHALCON_ALLOC_ZVAL(r32);
		phalcon_array_fetch_string(r32, v0, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r32)) {
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=169");
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (AssignOp) File=Library/Phalcon/Model/Base.php Line=170");
			//$select
			//$params
			PHALCON_ALLOC_ZVAL(r33);
			phalcon_array_fetch_string(r33, v0, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r34);
			phalcon_concat_left(r34, " ORDER BY ", r33 TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r35, v1, r34);
			//$select
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r35);
			v1 = r35;
			phalcon_debug_assign("$select", r35 TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=173");
	//$params
	eval_int = phalcon_array_isset_string(v0, "limit", strlen("limit")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=173");
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=174");
		//$params
		PHALCON_ALLOC_ZVAL(r36);
		phalcon_array_fetch_string(r36, v0, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r36)) {
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=174");
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Assignment) File=Library/Phalcon/Model/Base.php Line=175");
			//$select
			PHALCON_ALLOC_ZVAL(r37);
			//$this
			PHALCON_ALLOC_ZVAL(t8);
			phalcon_read_property(t8, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t8);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(t8, "limit" TSRMLS_CC);
			//$select
			Z_ADDREF_P(v1);
			p8[0] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			//$params
			PHALCON_ALLOC_ZVAL(r38);
			phalcon_array_fetch_string(r38, v0, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r38);
			p8[1] = r38;
			phalcon_debug_param(r38 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS(r37, t8, "limit", 2, p8, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r37 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r37);
			v1 = r37;
			phalcon_debug_assign("$select", r37 TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=178");
	//$params
	eval_int = phalcon_array_isset_string(v0, "for_update", strlen("for_update")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=178");
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=179");
		//$params
		PHALCON_ALLOC_ZVAL(r39);
		phalcon_array_fetch_string(r39, v0, "for_update", strlen("for_update"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r39)) {
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=179");
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Assignment) File=Library/Phalcon/Model/Base.php Line=180");
			//$select
			PHALCON_ALLOC_ZVAL(r40);
			//$this
			PHALCON_ALLOC_ZVAL(t9);
			phalcon_read_property(t9, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t9);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(t9, "forupdate" TSRMLS_CC);
			//$select
			Z_ADDREF_P(v1);
			p9[0] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS(r40, t9, "forupdate", 1, p9, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r40 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r40);
			v1 = r40;
			phalcon_debug_assign("$select", r40 TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=183");
	//$params
	eval_int = phalcon_array_isset_string(v0, "shared_lock", strlen("shared_lock")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=183");
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (If) File=Library/Phalcon/Model/Base.php Line=184");
		//$params
		PHALCON_ALLOC_ZVAL(r41);
		phalcon_array_fetch_string(r41, v0, "shared_lock", strlen("shared_lock"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r41)) {
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Block) File=Library/Phalcon/Model/Base.php Line=184");
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Assignment) File=Library/Phalcon/Model/Base.php Line=185");
			//$select
			PHALCON_ALLOC_ZVAL(r42);
			//$this
			PHALCON_ALLOC_ZVAL(t10);
			phalcon_read_property(t10, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t10);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(t10, "sharedlock" TSRMLS_CC);
			//$select
			Z_ADDREF_P(v1);
			p10[0] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS(r42, t10, "sharedlock", 1, p10, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r42 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r42);
			v1 = r42;
			phalcon_debug_assign("$select", r42 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	//$return
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v2, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		{
			zval *orig_ptr = a0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(a0);
				*a0 = *orig_ptr;
				zval_copy_ctor(a0);
				Z_SET_REFCOUNT_P(a0, 1);
				Z_UNSET_ISREF_P(a0);
			}
		}
		add_assoc_zval(a0, "return", copy);
	}
	//$select
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		{
			zval *orig_ptr = a0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(a0);
				*a0 = *orig_ptr;
				zval_copy_ctor(a0);
				Z_SET_REFCOUNT_P(a0, 1);
				Z_UNSET_ISREF_P(a0);
			}
		}
		add_assoc_zval(a0, "sql", copy);
	}
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
	phalcon_step_over("Phalcon_Model_Base::_createSQLSelectMulti (Method) File=Library/Phalcon/Model/Base.php Line=191");
}

PHP_METHOD(Phalcon_Model_Base, _createSQLSelectOne){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL, NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "_createSQLSelectOne", 0);
	phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (If) File=Library/Phalcon/Model/Base.php Line=192");
	//$params
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=192");
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (If) File=Library/Phalcon/Model/Base.php Line=193");
		//$params
		eval_int = phalcon_array_isset_string(v1, "conditions", strlen("conditions")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=193");
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (If) File=Library/Phalcon/Model/Base.php Line=194");
			//$params
			PHALCON_ALLOC_ZVAL(r0);
			phalcon_array_fetch_string(r0, v1, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r0)) {
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=194");
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (AssignOp) File=Library/Phalcon/Model/Base.php Line=195");
				//$select
				//$params
				PHALCON_ALLOC_ZVAL(r1);
				phalcon_array_fetch_string(r1, v1, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r2);
				phalcon_concat_both(r2,  " WHERE ", r1, " " TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r3, v0, r2);
				//$select
				if (v0) {
					if (!Z_REFCOUNT_P(v0)) {
						FREE_ZVAL(v0);
					}
				}
				Z_ADDREF_P(r3);
				v0 = r3;
				phalcon_debug_assign("$select", r3 TSRMLS_CC);
			}
		} else {
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=197");
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Assignment) File=Library/Phalcon/Model/Base.php Line=198");
			//$primaryKeys
			PHALCON_ALLOC_ZVAL(r4);
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_getprimarykeyattributes" TSRMLS_CC);
			PHALCON_CALL_METHOD(r4, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r4 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			if (v2) {
				Z_DELREF_P(v2);
				if (!Z_REFCOUNT_P(v2)) {
					FREE_ZVAL(v2);
				}
			}
			Z_ADDREF_P(r4);
			v2 = r4;
			phalcon_debug_assign("$primaryKeys", r4 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (If) File=Library/Phalcon/Model/Base.php Line=199");
			//$params
			eval_int = phalcon_array_isset_long(v1, 0);
			if (eval_int) {
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=199");
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (If) File=Library/Phalcon/Model/Base.php Line=200");
				PHALCON_ALLOC_ZVAL(r5);
				//$params
				PHALCON_ALLOC_ZVAL(r6);
				phalcon_array_fetch_long(r6, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r6);
				p1[0] = r6;
				phalcon_debug_param(r6 TSRMLS_CC);
				PHALCON_CALL_FUNC_PARAMS(r5, "is_numeric", 1, p1);
				phalcon_debug_vdump("is_numeric > ", r5 TSRMLS_CC);
				if (zend_is_true(r5)) {
					phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=200");
					phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Assignment) File=Library/Phalcon/Model/Base.php Line=201");
					//$primaryKeys
					PHALCON_ALLOC_ZVAL(r8);
					phalcon_array_fetch_long(r8, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					//$params
					PHALCON_ALLOC_ZVAL(r9);
					phalcon_array_fetch_long(r9, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_ALLOC_ZVAL(r7);
					phalcon_concat_vboth(r7, r8, " = '", r9 TSRMLS_CC);
					PHALCON_ALLOC_ZVAL(r10);
					phalcon_concat_right(r10, r7, "'" TSRMLS_CC);
					//$params
					{
						zval *orig_ptr = v1;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							ALLOC_ZVAL(v1);
							*v1 = *orig_ptr;
							zval_copy_ctor(v1);
							Z_SET_REFCOUNT_P(v1, 1);
							Z_UNSET_ISREF_P(v1);
						}
					}
					phalcon_array_update_string(v1, "conditions", strlen("conditions"), r10 TSRMLS_CC);
				} else {
					phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=202");
					phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (If) File=Library/Phalcon/Model/Base.php Line=203");
					//$params
					PHALCON_ALLOC_ZVAL(r11);
					phalcon_array_fetch_long(r11, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					if (phalcon_compare_strict_string(r11, "")) {
						phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=203");
						phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Assignment) File=Library/Phalcon/Model/Base.php Line=204");
						//$primaryKeys
						PHALCON_ALLOC_ZVAL(r12);
						phalcon_array_fetch_long(r12, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_ALLOC_ZVAL(r13);
						phalcon_concat_right(r13, r12, " = ''" TSRMLS_CC);
						//$params
						{
							zval *orig_ptr = v1;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								ALLOC_ZVAL(v1);
								*v1 = *orig_ptr;
								zval_copy_ctor(v1);
								Z_SET_REFCOUNT_P(v1, 1);
								Z_UNSET_ISREF_P(v1);
							}
						}
						phalcon_array_update_string(v1, "conditions", strlen("conditions"), r13 TSRMLS_CC);
					} else {
						phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=205");
						phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Assignment) File=Library/Phalcon/Model/Base.php Line=206");
						//$params
						PHALCON_ALLOC_ZVAL(r14);
						phalcon_array_fetch_long(r14, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
						//$params
						{
							zval *orig_ptr = v1;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								ALLOC_ZVAL(v1);
								*v1 = *orig_ptr;
								zval_copy_ctor(v1);
								Z_SET_REFCOUNT_P(v1, 1);
								Z_UNSET_ISREF_P(v1);
							}
						}
						phalcon_array_update_string(v1, "conditions", strlen("conditions"), r14 TSRMLS_CC);
					}
				}
			}
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (If) File=Library/Phalcon/Model/Base.php Line=210");
			//$params
			eval_int = phalcon_array_isset_string(v1, "conditions", strlen("conditions")+1);
			if (eval_int) {
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=210");
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (AssignOp) File=Library/Phalcon/Model/Base.php Line=211");
				//$select
				//$params
				PHALCON_ALLOC_ZVAL(r15);
				phalcon_array_fetch_string(r15, v1, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r16);
				phalcon_concat_left(r16, " WHERE ", r15 TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r17, v0, r16);
				//$select
				if (v0) {
					if (!Z_REFCOUNT_P(v0)) {
						FREE_ZVAL(v0);
					}
				}
				Z_ADDREF_P(r17);
				v0 = r17;
				phalcon_debug_assign("$select", r17 TSRMLS_CC);
			}
		}
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (If) File=Library/Phalcon/Model/Base.php Line=214");
		//$params
		eval_int = phalcon_array_isset_string(v1, "order", strlen("order")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=214");
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (If) File=Library/Phalcon/Model/Base.php Line=215");
			//$params
			PHALCON_ALLOC_ZVAL(r18);
			phalcon_array_fetch_string(r18, v1, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r18)) {
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=215");
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (AssignOp) File=Library/Phalcon/Model/Base.php Line=216");
				//$select
				//$params
				PHALCON_ALLOC_ZVAL(r19);
				phalcon_array_fetch_string(r19, v1, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r20);
				phalcon_concat_left(r20, " ORDER BY ", r19 TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r21, v0, r20);
				//$select
				if (v0) {
					if (!Z_REFCOUNT_P(v0)) {
						FREE_ZVAL(v0);
					}
				}
				Z_ADDREF_P(r21);
				v0 = r21;
				phalcon_debug_assign("$select", r21 TSRMLS_CC);
			}
		} else {
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=218");
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (AssignOp) File=Library/Phalcon/Model/Base.php Line=219");
			//$select
			PHALCON_ALLOC_ZVAL(t0);
			ZVAL_STRING(t0, " ORDER BY 1", 1);
			PHALCON_CONCAT_FUNCTION(r22, v0, t0);
			//$select
			if (v0) {
				if (!Z_REFCOUNT_P(v0)) {
					FREE_ZVAL(v0);
				}
			}
			Z_ADDREF_P(r22);
			v0 = r22;
			phalcon_debug_assign("$select", r22 TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (If) File=Library/Phalcon/Model/Base.php Line=221");
		//$params
		eval_int = phalcon_array_isset_string(v1, "limit", strlen("limit")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=221");
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (If) File=Library/Phalcon/Model/Base.php Line=222");
			//$params
			PHALCON_ALLOC_ZVAL(r23);
			phalcon_array_fetch_string(r23, v1, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r23)) {
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=222");
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Assignment) File=Library/Phalcon/Model/Base.php Line=223");
				//$select
				PHALCON_ALLOC_ZVAL(r24);
				//$this
				PHALCON_ALLOC_ZVAL(t1);
				phalcon_read_property(t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t1);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_method_call(t1, "limit" TSRMLS_CC);
				//$select
				Z_ADDREF_P(v0);
				p2[0] = v0;
				phalcon_debug_param(v0 TSRMLS_CC);
				//$params
				PHALCON_ALLOC_ZVAL(r25);
				phalcon_array_fetch_string(r25, v1, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r25);
				p2[1] = r25;
				phalcon_debug_param(r25 TSRMLS_CC);
				PHALCON_CALL_METHOD_PARAMS(r24, t1, "limit", 2, p2, PHALCON_CALL_DEFAULT);
				phalcon_debug_vdump("MethodReturn > ", r24 TSRMLS_CC);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				if (v0) {
					if (!Z_REFCOUNT_P(v0)) {
						FREE_ZVAL(v0);
					}
				}
				Z_ADDREF_P(r24);
				v0 = r24;
				phalcon_debug_assign("$select", r24 TSRMLS_CC);
			}
		}
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (If) File=Library/Phalcon/Model/Base.php Line=226");
		//$params
		eval_int = phalcon_array_isset_string(v1, "for_update", strlen("for_update")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=226");
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (If) File=Library/Phalcon/Model/Base.php Line=227");
			//$params
			PHALCON_ALLOC_ZVAL(r26);
			phalcon_array_fetch_string(r26, v1, "for_update", strlen("for_update"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r26)) {
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=227");
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Assignment) File=Library/Phalcon/Model/Base.php Line=228");
				//$select
				PHALCON_ALLOC_ZVAL(r27);
				//$this
				PHALCON_ALLOC_ZVAL(t2);
				phalcon_read_property(t2, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t2);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_method_call(t2, "forupdate" TSRMLS_CC);
				//$select
				Z_ADDREF_P(v0);
				p3[0] = v0;
				phalcon_debug_param(v0 TSRMLS_CC);
				PHALCON_CALL_METHOD_PARAMS(r27, t2, "forupdate", 1, p3, PHALCON_CALL_DEFAULT);
				phalcon_debug_vdump("MethodReturn > ", r27 TSRMLS_CC);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				if (v0) {
					if (!Z_REFCOUNT_P(v0)) {
						FREE_ZVAL(v0);
					}
				}
				Z_ADDREF_P(r27);
				v0 = r27;
				phalcon_debug_assign("$select", r27 TSRMLS_CC);
			}
		}
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (If) File=Library/Phalcon/Model/Base.php Line=231");
		//$params
		eval_int = phalcon_array_isset_string(v1, "shared_lock", strlen("shared_lock")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=231");
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (If) File=Library/Phalcon/Model/Base.php Line=232");
			//$params
			PHALCON_ALLOC_ZVAL(r28);
			phalcon_array_fetch_string(r28, v1, "shared_lock", strlen("shared_lock"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r28)) {
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=232");
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Assignment) File=Library/Phalcon/Model/Base.php Line=233");
				//$select
				PHALCON_ALLOC_ZVAL(r29);
				//$this
				PHALCON_ALLOC_ZVAL(t3);
				phalcon_read_property(t3, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t3);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_method_call(t3, "sharedlock" TSRMLS_CC);
				//$select
				Z_ADDREF_P(v0);
				p4[0] = v0;
				phalcon_debug_param(v0 TSRMLS_CC);
				PHALCON_CALL_METHOD_PARAMS(r29, t3, "sharedlock", 1, p4, PHALCON_CALL_DEFAULT);
				phalcon_debug_vdump("MethodReturn > ", r29 TSRMLS_CC);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				if (v0) {
					if (!Z_REFCOUNT_P(v0)) {
						FREE_ZVAL(v0);
					}
				}
				Z_ADDREF_P(r29);
				v0 = r29;
				phalcon_debug_assign("$select", r29 TSRMLS_CC);
			}
		}
	} else {
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=236");
		phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (If) File=Library/Phalcon/Model/Base.php Line=237");
		PHALCON_ALLOC_ZVAL(r30);
		//$params
		p5[0] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r30, "strlen", 1, p5);
		phalcon_debug_vdump("strlen > ", r30 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t4);
		ZVAL_LONG(t4, 0);
		PHALCON_SMALLER_FUNCTION(r31, t4, r30);
		if (zend_is_true(r31)) {
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=237");
			phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (If) File=Library/Phalcon/Model/Base.php Line=238");
			PHALCON_ALLOC_ZVAL(r32);
			//$params
			Z_ADDREF_P(v1);
			p6[0] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r32, "is_numeric", 1, p6);
			phalcon_debug_vdump("is_numeric > ", r32 TSRMLS_CC);
			if (zend_is_true(r32)) {
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=238");
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (AssignOp) File=Library/Phalcon/Model/Base.php Line=239");
				//$select
				//$primaryKeys
				PHALCON_ALLOC_ZVAL(r34);
				phalcon_array_fetch_long(r34, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r35);
				phalcon_concat_left(r35, "WHERE ", r34 TSRMLS_CC);
				//$params
				PHALCON_ALLOC_ZVAL(r33);
				phalcon_concat_vboth(r33, r35, " = '", v1 TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r36);
				phalcon_concat_right(r36, r33, "'" TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r37, v0, r36);
				//$select
				if (v0) {
					if (!Z_REFCOUNT_P(v0)) {
						FREE_ZVAL(v0);
					}
				}
				Z_ADDREF_P(r37);
				v0 = r37;
				phalcon_debug_assign("$select", r37 TSRMLS_CC);
			} else {
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Block) File=Library/Phalcon/Model/Base.php Line=240");
				phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (AssignOp) File=Library/Phalcon/Model/Base.php Line=241");
				//$select
				//$params
				PHALCON_ALLOC_ZVAL(r38);
				phalcon_concat_left(r38, "WHERE ", v1 TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r39, v0, r38);
				//$select
				if (v0) {
					if (!Z_REFCOUNT_P(v0)) {
						FREE_ZVAL(v0);
					}
				}
				Z_ADDREF_P(r39);
				v0 = r39;
				phalcon_debug_assign("$select", r39 TSRMLS_CC);
			}
		}
	}
	//$select
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Base::_createSQLSelectOne (Method) File=Library/Phalcon/Model/Base.php Line=248");
}

PHP_METHOD(Phalcon_Model_Base, _createResultset){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL }, *p7[] = { NULL, NULL }, *p8[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "_createResultset", 0);
	phalcon_step_over("Phalcon_Model_Base::_createResultset (Assignment) File=Library/Phalcon/Model/Base.php Line=249");
	//$connection
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(t0);
	v2 = t0;
	phalcon_debug_assign("$connection", t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::_createResultset (If) File=Library/Phalcon/Model/Base.php Line=250");
	//$select
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_string(r0, v0, "return", strlen("return"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_STRING(t1, "1", 1);
	PHALCON_EQUAL_FUNCTION(r1, r0, t1);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Model_Base::_createResultset (Block) File=Library/Phalcon/Model/Base.php Line=250");
		phalcon_step_over("Phalcon_Model_Base::_createResultset (If) File=Library/Phalcon/Model/Base.php Line=251");
		PHALCON_ALLOC_ZVAL(r2);
		//$connection
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(v2, "numrows" TSRMLS_CC);
		//$resultResource
		Z_ADDREF_P(v1);
		p0[0] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r2, v2, "numrows", 1, p0, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t2);
		ZVAL_LONG(t2, 0);
		PHALCON_EQUAL_FUNCTION(r3, r2, t2);
		if (zend_is_true(r3)) {
			phalcon_step_over("Phalcon_Model_Base::_createResultset (Block) File=Library/Phalcon/Model/Base.php Line=251");
			phalcon_step_over("Phalcon_Model_Base::_createResultset (Assignment) File=Library/Phalcon/Model/Base.php Line=252");
			//$this
			phalcon_update_property_long(this_ptr, "_count", strlen("_count"), 0 TSRMLS_CC);
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		} else {
			phalcon_step_over("Phalcon_Model_Base::_createResultset (Block) File=Library/Phalcon/Model/Base.php Line=254");
			phalcon_step_over("Phalcon_Model_Base::_createResultset (MethodCall) File=Library/Phalcon/Model/Base.php Line=255");
			//$connection
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(v2, "setfetchmode" TSRMLS_CC);
			PHALCON_GET_CLASS_CONSTANT(t3, phalcon_db_class_entry, "DB_ASSOC");
			Z_ADDREF_P(t3);
			p1[0] = t3;
			phalcon_debug_param(t3 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setfetchmode", 1, p1, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Base::_createResultset (Assignment) File=Library/Phalcon/Model/Base.php Line=256");
			//$uniqueRow
			PHALCON_ALLOC_ZVAL(r4);
			//$connection
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(v2, "fetcharray" TSRMLS_CC);
			//$resultResource
			Z_ADDREF_P(v1);
			p2[0] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS(r4, v2, "fetcharray", 1, p2, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r4 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			if (v3) {
				Z_DELREF_P(v3);
				if (!Z_REFCOUNT_P(v3)) {
					FREE_ZVAL(v3);
				}
			}
			Z_ADDREF_P(r4);
			v3 = r4;
			phalcon_debug_assign("$uniqueRow", r4 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Base::_createResultset (MethodCall) File=Library/Phalcon/Model/Base.php Line=257");
			//$connection
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(v2, "setfetchmode" TSRMLS_CC);
			PHALCON_GET_CLASS_CONSTANT(t4, phalcon_db_class_entry, "DB_BOTH");
			Z_ADDREF_P(t4);
			p3[0] = t4;
			phalcon_debug_param(t4 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setfetchmode", 1, p3, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Base::_createResultset (MethodCall) File=Library/Phalcon/Model/Base.php Line=258");
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "dumpresultself" TSRMLS_CC);
			//$uniqueRow
			Z_ADDREF_P(v3);
			p4[0] = v3;
			phalcon_debug_param(v3 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "dumpresultself", 1, p4, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Base::_createResultset (Assignment) File=Library/Phalcon/Model/Base.php Line=259");
			//$this
			phalcon_update_property_long(this_ptr, "_count", strlen("_count"), 1 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r5);
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "dumpresult" TSRMLS_CC);
			//$uniqueRow
			Z_ADDREF_P(v3);
			p5[0] = v3;
			phalcon_debug_param(v3 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS(r5, this_ptr, "dumpresult", 1, p5, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r5 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", r5 TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_ZVAL(r5, 1, 0);
		}
	} else {
		phalcon_step_over("Phalcon_Model_Base::_createResultset (Block) File=Library/Phalcon/Model/Base.php Line=262");
		phalcon_step_over("Phalcon_Model_Base::_createResultset (Assignment) File=Library/Phalcon/Model/Base.php Line=263");
		PHALCON_ALLOC_ZVAL(r6);
		//$connection
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(v2, "numrows" TSRMLS_CC);
		//$resultResource
		Z_ADDREF_P(v1);
		p6[0] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r6, v2, "numrows", 1, p6, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r6 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r6, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_count", strlen("_count"), copy TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Model_Base::_createResultset (If) File=Library/Phalcon/Model/Base.php Line=264");
		//$this
		PHALCON_ALLOC_ZVAL(t5);
		phalcon_read_property(t5, this_ptr, "_count", sizeof("_count")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t5);
		PHALCON_ALLOC_ZVAL(t6);
		ZVAL_LONG(t6, 0);
		PHALCON_SMALLER_FUNCTION(r7, t6, t5);
		if (zend_is_true(r7)) {
			phalcon_step_over("Phalcon_Model_Base::_createResultset (Block) File=Library/Phalcon/Model/Base.php Line=264");
			PHALCON_ALLOC_ZVAL(i0);
			object_init_ex(i0, phalcon_model_resultset_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
			//$this
			Z_ADDREF_P(this_ptr);
			p7[0] = this_ptr;
			phalcon_debug_param(this_ptr TSRMLS_CC);
			//$resultResource
			Z_ADDREF_P(v1);
			p7[1] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p7, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", i0 TSRMLS_CC);
			phalcon_step_out_entry();
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(i0);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
				Z_SET_REFCOUNT_P(return_value, refcount);
			}
			return;
		} else {
			phalcon_step_over("Phalcon_Model_Base::_createResultset (Block) File=Library/Phalcon/Model/Base.php Line=266");
			PHALCON_ALLOC_ZVAL(i1);
			object_init_ex(i1, phalcon_model_resultset_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
			//$this
			Z_ADDREF_P(this_ptr);
			p8[0] = this_ptr;
			phalcon_debug_param(this_ptr TSRMLS_CC);
			PHALCON_PARAM_BOOL(p8[1], 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p8, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", i1 TSRMLS_CC);
			phalcon_step_out_entry();
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(i1);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
				Z_SET_REFCOUNT_P(return_value, refcount);
			}
			return;
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Base::_createResultset (Method) File=Library/Phalcon/Model/Base.php Line=272");
}

PHP_METHOD(Phalcon_Model_Base, setManager){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "setManager", 0);
	phalcon_step_over("Phalcon_Model_Base::setManager (Assignment) File=Library/Phalcon/Model/Base.php Line=273");
	//$manager
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Base::setManager (Method) File=Library/Phalcon/Model/Base.php Line=276");
}

PHP_METHOD(Phalcon_Model_Base, setTransaction){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "setTransaction", 0);
	phalcon_step_over("Phalcon_Model_Base::setTransaction (If) File=Library/Phalcon/Model/Base.php Line=277");
	//$transaction
	if (Z_TYPE_P(v0) == IS_OBJECT) {
		phalcon_step_over("Phalcon_Model_Base::setTransaction (Block) File=Library/Phalcon/Model/Base.php Line=277");
		phalcon_step_over("Phalcon_Model_Base::setTransaction (Assignment) File=Library/Phalcon/Model/Base.php Line=278");
		PHALCON_ALLOC_ZVAL(r0);
		//$transaction
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(v0, "getconnection" TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, v0, "getconnection", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Model_Base::setTransaction (Block) File=Library/Phalcon/Model/Base.php Line=279");
		phalcon_step_over("Phalcon_Model_Base::setTransaction (Throw) File=Library/Phalcon/Model/Base.php Line=280");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], "Transaction should be an object", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	//$this
	phalcon_debug_vdump("Returning > ", this_ptr TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(this_ptr) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(this_ptr);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(this_ptr);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Base::setTransaction (Method) File=Library/Phalcon/Model/Base.php Line=285");
}

PHP_METHOD(Phalcon_Model_Base, isView){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Base", "isView", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_isView", sizeof("_isView")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Model_Base::isView (Method) File=Library/Phalcon/Model/Base.php Line=289");
}

PHP_METHOD(Phalcon_Model_Base, setSource){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "setSource", 0);
	phalcon_step_over("Phalcon_Model_Base::setSource (Assignment) File=Library/Phalcon/Model/Base.php Line=290");
	//$source
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_source", strlen("_source"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Base::setSource (Method) File=Library/Phalcon/Model/Base.php Line=293");
}

PHP_METHOD(Phalcon_Model_Base, getSource){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p1[] = { NULL }, *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Base", "getSource", 0);
	phalcon_step_over("Phalcon_Model_Base::getSource (If) File=Library/Phalcon/Model/Base.php Line=294");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (phalcon_compare_strict_string(t0, "")) {
		phalcon_step_over("Phalcon_Model_Base::getSource (Block) File=Library/Phalcon/Model/Base.php Line=294");
		phalcon_step_over("Phalcon_Model_Base::getSource (Assignment) File=Library/Phalcon/Model/Base.php Line=295");
		PHALCON_ALLOC_ZVAL(r0);
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(t1, "getsource" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r1);
		//$this
		p1[0] = this_ptr;
		phalcon_debug_param(this_ptr TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r1, "get_class", 1, p1);
		phalcon_debug_vdump("get_class > ", r1 TSRMLS_CC);
		Z_ADDREF_P(r1);
		p0[0] = r1;
		phalcon_debug_param(r1 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r0, t1, "getsource", 1, p0, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_source", strlen("_source"), copy TSRMLS_CC);
		}
	}
	//$this
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Model_Base::getSource (Method) File=Library/Phalcon/Model/Base.php Line=300");
}

PHP_METHOD(Phalcon_Model_Base, setSchema){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "setSchema", 0);
	phalcon_step_over("Phalcon_Model_Base::setSchema (Assignment) File=Library/Phalcon/Model/Base.php Line=301");
	//$schema
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_schema", strlen("_schema"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Base::setSchema (Method) File=Library/Phalcon/Model/Base.php Line=304");
}

PHP_METHOD(Phalcon_Model_Base, getSchema){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Base", "getSchema", 0);
	phalcon_step_over("Phalcon_Model_Base::getSchema (If) File=Library/Phalcon/Model/Base.php Line=305");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (phalcon_compare_strict_string(t0, "")) {
		phalcon_step_over("Phalcon_Model_Base::getSchema (Block) File=Library/Phalcon/Model/Base.php Line=305");
		phalcon_step_over("Phalcon_Model_Base::getSchema (Assignment) File=Library/Phalcon/Model/Base.php Line=306");
		PHALCON_ALLOC_ZVAL(r0);
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(t1, "getdatabasename" TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, t1, "getdatabasename", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_schema", strlen("_schema"), copy TSRMLS_CC);
		}
	}
	//$this
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Model_Base::getSchema (Method) File=Library/Phalcon/Model/Base.php Line=311");
}

PHP_METHOD(Phalcon_Model_Base, getConnection){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Base", "getConnection", 0);
	phalcon_step_over("Phalcon_Model_Base::getConnection (MethodCall) File=Library/Phalcon/Model/Base.php Line=312");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_connect" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Model_Base::getConnection (Method) File=Library/Phalcon/Model/Base.php Line=316");
}

PHP_METHOD(Phalcon_Model_Base, dumpResult){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *s0 = NULL;
	zval *ac0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "dumpResult", 0);
	phalcon_step_over("Phalcon_Model_Base::dumpResult (Assignment) File=Library/Phalcon/Model/Base.php Line=317");
	//$object
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
	phalcon_debug_assign("$object", s0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::dumpResult (Assignment) File=Library/Phalcon/Model/Base.php Line=318");
	//$object
	zend_update_property_bool(Z_OBJCE_P(v1), v1, "_forceExists", strlen("_forceExists"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::dumpResult (Assignment) File=Library/Phalcon/Model/Base.php Line=319");
	//$this
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::dumpResult (If) File=Library/Phalcon/Model/Base.php Line=320");
	//$result
	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		phalcon_step_over("Phalcon_Model_Base::dumpResult (Block) File=Library/Phalcon/Model/Base.php Line=320");
		phalcon_step_over("Phalcon_Model_Base::dumpResult (Foreach) File=Library/Phalcon/Model/Base.php Line=321");
		//$result
		//$value
		//$key
		FOREACH_KV(v0, ac0, fes66, fee66, ah0, hp0, v3, v2)
			phalcon_step_over("Phalcon_Model_Base::dumpResult (Block) File=Library/Phalcon/Model/Base.php Line=321");
			phalcon_step_over("Phalcon_Model_Base::dumpResult (Assignment) File=Library/Phalcon/Model/Base.php Line=322");
			//$key
			//$value
			//$object
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(v1, Z_STRVAL_P(v3), Z_STRLEN_P(v3), copy TSRMLS_CC);
			}
		END_FOREACH(ac0, fes66, fee66, ah0, hp0);
	}
	phalcon_step_over("Phalcon_Model_Base::dumpResult (Assignment) File=Library/Phalcon/Model/Base.php Line=325");
	//$this
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 0 TSRMLS_CC);
	//$object
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
	phalcon_step_over("Phalcon_Model_Base::dumpResult (Method) File=Library/Phalcon/Model/Base.php Line=329");
}

PHP_METHOD(Phalcon_Model_Base, dumpResultSelf){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *ac0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "dumpResultSelf", 0);
	phalcon_step_over("Phalcon_Model_Base::dumpResultSelf (MethodCall) File=Library/Phalcon/Model/Base.php Line=330");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_connect" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::dumpResultSelf (Assignment) File=Library/Phalcon/Model/Base.php Line=331");
	//$this
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::dumpResultSelf (If) File=Library/Phalcon/Model/Base.php Line=332");
	//$result
	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		phalcon_step_over("Phalcon_Model_Base::dumpResultSelf (Block) File=Library/Phalcon/Model/Base.php Line=332");
		phalcon_step_over("Phalcon_Model_Base::dumpResultSelf (Foreach) File=Library/Phalcon/Model/Base.php Line=333");
		//$result
		//$value
		//$key
		FOREACH_KV(v0, ac0, fes67, fee67, ah0, hp0, v2, v1)
			phalcon_step_over("Phalcon_Model_Base::dumpResultSelf (Block) File=Library/Phalcon/Model/Base.php Line=333");
			phalcon_step_over("Phalcon_Model_Base::dumpResultSelf (Assignment) File=Library/Phalcon/Model/Base.php Line=334");
			//$key
			//$value
			//$this
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v1, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v2), Z_STRLEN_P(v2), copy TSRMLS_CC);
			}
		END_FOREACH(ac0, fes67, fee67, ah0, hp0);
	}
	phalcon_step_over("Phalcon_Model_Base::dumpResultSelf (Assignment) File=Library/Phalcon/Model/Base.php Line=337");
	//$this
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Base::dumpResultSelf (Method) File=Library/Phalcon/Model/Base.php Line=340");
}

PHP_METHOD(Phalcon_Model_Base, find){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *t0 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_NULL(v0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "find", 0);
	phalcon_step_over("Phalcon_Model_Base::find (MethodCall) File=Library/Phalcon/Model/Base.php Line=341");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_connect" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::find (If) File=Library/Phalcon/Model/Base.php Line=342");
	//$params
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		phalcon_step_over("Phalcon_Model_Base::find (Block) File=Library/Phalcon/Model/Base.php Line=342");
		phalcon_step_over("Phalcon_Model_Base::find (If) File=Library/Phalcon/Model/Base.php Line=343");
		//$params
		if (Z_TYPE_P(v0) != IS_NULL) {
			phalcon_step_over("Phalcon_Model_Base::find (Block) File=Library/Phalcon/Model/Base.php Line=343");
			phalcon_step_over("Phalcon_Model_Base::find (Assignment) File=Library/Phalcon/Model/Base.php Line=344");
			//$params
			PHALCON_ALLOC_ZVAL(a0);
			array_init(a0);
			//$params
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v0, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				{
					zval *orig_ptr = a0;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(a0);
						*a0 = *orig_ptr;
						zval_copy_ctor(a0);
						Z_SET_REFCOUNT_P(a0, 1);
						Z_UNSET_ISREF_P(a0);
					}
				}
				add_next_index_zval(a0, copy);
			}
			if (v0) {
				if (!Z_REFCOUNT_P(v0)) {
					FREE_ZVAL(v0);
				}
			}
			Z_ADDREF_P(a0);
			v0 = a0;
			phalcon_debug_assign("$params", a0 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Model_Base::find (Block) File=Library/Phalcon/Model/Base.php Line=345");
			phalcon_step_over("Phalcon_Model_Base::find (Assignment) File=Library/Phalcon/Model/Base.php Line=346");
			//$params
			PHALCON_ALLOC_ZVAL(a1);
			array_init(a1);
			if (v0) {
				if (!Z_REFCOUNT_P(v0)) {
					FREE_ZVAL(v0);
				}
			}
			Z_ADDREF_P(a1);
			v0 = a1;
			phalcon_debug_assign("$params", a1 TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Model_Base::find (Assignment) File=Library/Phalcon/Model/Base.php Line=349");
	//$select
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_createsqlselectmulti" TSRMLS_CC);
	//$params
	Z_ADDREF_P(v0);
	p1[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_createsqlselectmulti", 1, p1, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_debug_assign("$select", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::find (Assignment) File=Library/Phalcon/Model/Base.php Line=350");
	//$resultResource
	PHALCON_ALLOC_ZVAL(r1);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(t0, "query" TSRMLS_CC);
	//$select
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_array_fetch_string(r2, v1, "sql", strlen("sql"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r2);
	p2[0] = r2;
	phalcon_debug_param(r2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r1, t0, "query", 1, p2, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	phalcon_debug_assign("$resultResource", r1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r3);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_createresultset" TSRMLS_CC);
	//$select
	Z_ADDREF_P(v1);
	p3[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	//$resultResource
	Z_ADDREF_P(v2);
	p3[1] = v2;
	phalcon_debug_param(v2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "_createresultset", 2, p3, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r3 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r3, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Base::find (Method) File=Library/Phalcon/Model/Base.php Line=354");
}

PHP_METHOD(Phalcon_Model_Base, findFirst){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *p4[] = { NULL, NULL }, *p6[] = { NULL, NULL }, *p7[] = { NULL }, *p8[] = { NULL }, *p9[] = { NULL }, *p10[] = { NULL }, *p11[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_NULL(v0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "findFirst", 0);
	phalcon_step_over("Phalcon_Model_Base::findFirst (MethodCall) File=Library/Phalcon/Model/Base.php Line=355");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_connect" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::findFirst (If) File=Library/Phalcon/Model/Base.php Line=357");
	//$params
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		phalcon_step_over("Phalcon_Model_Base::findFirst (Block) File=Library/Phalcon/Model/Base.php Line=357");
		phalcon_step_over("Phalcon_Model_Base::findFirst (If) File=Library/Phalcon/Model/Base.php Line=358");
		//$params
		if (Z_TYPE_P(v0) != IS_NULL) {
			phalcon_step_over("Phalcon_Model_Base::findFirst (Block) File=Library/Phalcon/Model/Base.php Line=358");
			phalcon_step_over("Phalcon_Model_Base::findFirst (Assignment) File=Library/Phalcon/Model/Base.php Line=359");
			//$params
			PHALCON_ALLOC_ZVAL(a0);
			array_init(a0);
			//$params
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v0, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				{
					zval *orig_ptr = a0;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(a0);
						*a0 = *orig_ptr;
						zval_copy_ctor(a0);
						Z_SET_REFCOUNT_P(a0, 1);
						Z_UNSET_ISREF_P(a0);
					}
				}
				add_next_index_zval(a0, copy);
			}
			if (v0) {
				if (!Z_REFCOUNT_P(v0)) {
					FREE_ZVAL(v0);
				}
			}
			Z_ADDREF_P(a0);
			v0 = a0;
			phalcon_debug_assign("$params", a0 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Model_Base::findFirst (Block) File=Library/Phalcon/Model/Base.php Line=360");
			phalcon_step_over("Phalcon_Model_Base::findFirst (Assignment) File=Library/Phalcon/Model/Base.php Line=361");
			//$params
			PHALCON_ALLOC_ZVAL(a1);
			array_init(a1);
			if (v0) {
				if (!Z_REFCOUNT_P(v0)) {
					FREE_ZVAL(v0);
				}
			}
			Z_ADDREF_P(a1);
			v0 = a1;
			phalcon_debug_assign("$params", a1 TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Model_Base::findFirst (Assignment) File=Library/Phalcon/Model/Base.php Line=365");
	//$schema
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getschema" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getschema", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_debug_assign("$schema", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::findFirst (Assignment) File=Library/Phalcon/Model/Base.php Line=366");
	//$source
	PHALCON_ALLOC_ZVAL(r1);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getsource" TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	phalcon_debug_assign("$source", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::findFirst (Assignment) File=Library/Phalcon/Model/Base.php Line=368");
	//$select
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_STRING(v3, "SELECT ", 0);
	phalcon_step_over("Phalcon_Model_Base::findFirst (If) File=Library/Phalcon/Model/Base.php Line=369");
	//$params
	eval_int = phalcon_array_isset_string(v0, "columns", strlen("columns")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Base::findFirst (Block) File=Library/Phalcon/Model/Base.php Line=369");
		phalcon_step_over("Phalcon_Model_Base::findFirst (MethodCall) File=Library/Phalcon/Model/Base.php Line=370");
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "clear" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "clear", PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::findFirst (AssignOp) File=Library/Phalcon/Model/Base.php Line=371");
		//$select
		//$params
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_string(r2, v0, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r3, v3, r2);
		//$select
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r3);
		v3 = r3;
		phalcon_debug_assign("$select", r3 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Model_Base::findFirst (Block) File=Library/Phalcon/Model/Base.php Line=372");
		phalcon_step_over("Phalcon_Model_Base::findFirst (AssignOp) File=Library/Phalcon/Model/Base.php Line=373");
		//$select
		PHALCON_ALLOC_ZVAL(r4);
		PHALCON_ALLOC_ZVAL(p4[0]);
		ZVAL_STRING(p4[0], ", ", 1);
		PHALCON_ALLOC_ZVAL(r5);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "_getattributes" TSRMLS_CC);
		PHALCON_CALL_METHOD(r5, this_ptr, "_getattributes", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r5 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		p4[1] = r5;
		phalcon_debug_param(r5 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r4, "join", 2, p4);
		phalcon_debug_vdump("join > ", r4 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r6, v3, r4);
		//$select
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r6);
		v3 = r6;
		phalcon_debug_assign("$select", r6 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Base::findFirst (If) File=Library/Phalcon/Model/Base.php Line=375");
	//$schema
	if (!phalcon_compare_strict_string(v1, "")) {
		phalcon_step_over("Phalcon_Model_Base::findFirst (Block) File=Library/Phalcon/Model/Base.php Line=375");
		phalcon_step_over("Phalcon_Model_Base::findFirst (AssignOp) File=Library/Phalcon/Model/Base.php Line=376");
		//$select
		//$schema
		PHALCON_ALLOC_ZVAL(r8);
		phalcon_concat_left(r8, " FROM ", v1 TSRMLS_CC);
		//$source
		PHALCON_ALLOC_ZVAL(r7);
		phalcon_concat_vboth(r7, r8, ".", v2 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r9, v3, r7);
		//$select
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r9);
		v3 = r9;
		phalcon_debug_assign("$select", r9 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Model_Base::findFirst (Block) File=Library/Phalcon/Model/Base.php Line=377");
		phalcon_step_over("Phalcon_Model_Base::findFirst (AssignOp) File=Library/Phalcon/Model/Base.php Line=378");
		//$select
		//$source
		PHALCON_ALLOC_ZVAL(r10);
		phalcon_concat_left(r10, " FROM ", v2 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r11, v3, r10);
		//$select
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r11);
		v3 = r11;
		phalcon_debug_assign("$select", r11 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Base::findFirst (If) File=Library/Phalcon/Model/Base.php Line=380");
	//$params
	eval_int = phalcon_array_isset_string(v0, "limit", strlen("limit")+1);
	if (!eval_int) {
		phalcon_step_over("Phalcon_Model_Base::findFirst (Block) File=Library/Phalcon/Model/Base.php Line=380");
		phalcon_step_over("Phalcon_Model_Base::findFirst (Assignment) File=Library/Phalcon/Model/Base.php Line=381");
		PHALCON_ALLOC_ZVAL(t0);
		ZVAL_LONG(t0, 1);
		//$params
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		phalcon_array_update_string(v0, "limit", strlen("limit"), t0 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Base::findFirst (Assignment) File=Library/Phalcon/Model/Base.php Line=383");
	//$record
	PHALCON_ALLOC_ZVAL(v4);
	ZVAL_BOOL(v4, 0);
	phalcon_step_over("Phalcon_Model_Base::findFirst (Assignment) File=Library/Phalcon/Model/Base.php Line=384");
	//$connection
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	if (v5) {
		Z_DELREF_P(v5);
		if (!Z_REFCOUNT_P(v5)) {
			FREE_ZVAL(v5);
		}
	}
	Z_ADDREF_P(t1);
	v5 = t1;
	phalcon_debug_assign("$connection", t1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::findFirst (Assignment) File=Library/Phalcon/Model/Base.php Line=385");
	//$select
	PHALCON_ALLOC_ZVAL(r12);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_createsqlselectone" TSRMLS_CC);
	//$select
	Z_ADDREF_P(v3);
	p6[0] = v3;
	phalcon_debug_param(v3 TSRMLS_CC);
	//$params
	Z_ADDREF_P(v0);
	p6[1] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r12, this_ptr, "_createsqlselectone", 2, p6, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r12 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(r12);
	v3 = r12;
	phalcon_debug_assign("$select", r12 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::findFirst (MethodCall) File=Library/Phalcon/Model/Base.php Line=386");
	//$connection
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(v5, "setfetchmode" TSRMLS_CC);
	PHALCON_GET_CLASS_CONSTANT(t2, phalcon_db_class_entry, "DB_ASSOC");
	Z_ADDREF_P(t2);
	p7[0] = t2;
	phalcon_debug_param(t2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v5, "setfetchmode", 1, p7, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::findFirst (Assignment) File=Library/Phalcon/Model/Base.php Line=387");
	//$result
	PHALCON_ALLOC_ZVAL(r13);
	//$connection
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(v5, "fetchone" TSRMLS_CC);
	//$select
	Z_ADDREF_P(v3);
	p8[0] = v3;
	phalcon_debug_param(v3 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r13, v5, "fetchone", 1, p8, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r13 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v6) {
		Z_DELREF_P(v6);
		if (!Z_REFCOUNT_P(v6)) {
			FREE_ZVAL(v6);
		}
	}
	Z_ADDREF_P(r13);
	v6 = r13;
	phalcon_debug_assign("$result", r13 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::findFirst (If) File=Library/Phalcon/Model/Base.php Line=388");
	//$result
	if (zend_is_true(v6)) {
		phalcon_step_over("Phalcon_Model_Base::findFirst (Block) File=Library/Phalcon/Model/Base.php Line=388");
		phalcon_step_over("Phalcon_Model_Base::findFirst (MethodCall) File=Library/Phalcon/Model/Base.php Line=389");
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "dumpresultself" TSRMLS_CC);
		//$result
		Z_ADDREF_P(v6);
		p9[0] = v6;
		phalcon_debug_param(v6 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "dumpresultself", 1, p9, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::findFirst (Assignment) File=Library/Phalcon/Model/Base.php Line=390");
		//$record
		PHALCON_ALLOC_ZVAL(r14);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "dumpresult" TSRMLS_CC);
		//$result
		Z_ADDREF_P(v6);
		p10[0] = v6;
		phalcon_debug_param(v6 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r14, this_ptr, "dumpresult", 1, p10, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r14 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r14);
		v4 = r14;
		phalcon_debug_assign("$record", r14 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Base::findFirst (MethodCall) File=Library/Phalcon/Model/Base.php Line=392");
	//$connection
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(v5, "setfetchmode" TSRMLS_CC);
	PHALCON_GET_CLASS_CONSTANT(t3, phalcon_db_class_entry, "DB_BOTH");
	Z_ADDREF_P(t3);
	p11[0] = t3;
	phalcon_debug_param(t3 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v5, "setfetchmode", 1, p11, PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	//$record
	phalcon_debug_vdump("Returning > ", v4 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(v4) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v4);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v4);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Base::findFirst (Method) File=Library/Phalcon/Model/Base.php Line=396");
}

PHP_METHOD(Phalcon_Model_Base, exists){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p1[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "exists", 0);
	phalcon_step_over("Phalcon_Model_Base::exists (MethodCall) File=Library/Phalcon/Model/Base.php Line=397");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_connect" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_exists" TSRMLS_CC);
	//$wherePk
	Z_ADDREF_P(v0);
	p1[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_exists", 1, p1, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Base::exists (Method) File=Library/Phalcon/Model/Base.php Line=401");
}

PHP_METHOD(Phalcon_Model_Base, _exists){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *p4[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL, NULL }, *p7[] = { NULL }, *p8[] = { NULL }, *p11[] = { NULL }, *p12[] = { NULL }, *p13[] = { NULL, NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "_exists", 0);
	phalcon_step_over("Phalcon_Model_Base::_exists (If) File=Library/Phalcon/Model/Base.php Line=402");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_forceExists", sizeof("_forceExists")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=402");
		phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=403");
		//$schema
		PHALCON_ALLOC_ZVAL(r0);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "getschema" TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, this_ptr, "getschema", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r0);
		v1 = r0;
		phalcon_debug_assign("$schema", r0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=404");
		//$source
		PHALCON_ALLOC_ZVAL(r1);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "getsource" TSRMLS_CC);
		PHALCON_CALL_METHOD(r1, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(r1);
		v2 = r1;
		phalcon_debug_assign("$source", r1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::_exists (If) File=Library/Phalcon/Model/Base.php Line=405");
		//$schema
		if (zend_is_true(v1)) {
			phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=405");
			phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=406");
			//$table
			//$schema
			//$source
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_concat_vboth(r2, v1, ".", v2 TSRMLS_CC);
			if (v3) {
				Z_DELREF_P(v3);
				if (!Z_REFCOUNT_P(v3)) {
					FREE_ZVAL(v3);
				}
			}
			Z_ADDREF_P(r2);
			v3 = r2;
			phalcon_debug_assign("$table", r2 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=407");
			phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=408");
			//$table
			//$source
			if (v3) {
				Z_DELREF_P(v3);
				if (!Z_REFCOUNT_P(v3)) {
					FREE_ZVAL(v3);
				}
			}
			Z_ADDREF_P(v2);
			v3 = v2;
			phalcon_debug_assign("$table", v2 TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=410");
		//$query
		//$table
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_concat_both(r3,  "SELECT COUNT(*) AS rowcount FROM ", v3, " WHERE " TSRMLS_CC);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r3);
		v4 = r3;
		phalcon_debug_assign("$query", r3 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::_exists (If) File=Library/Phalcon/Model/Base.php Line=411");
		//$wherePk
		if (phalcon_compare_strict_string(v0, "")) {
			phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=411");
			phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=412");
			//$wherePk
			PHALCON_ALLOC_ZVAL(a0);
			array_init(a0);
			if (v0) {
				if (!Z_REFCOUNT_P(v0)) {
					FREE_ZVAL(v0);
				}
			}
			Z_ADDREF_P(a0);
			v0 = a0;
			phalcon_debug_assign("$wherePk", a0 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=413");
			//$primaryKeys
			PHALCON_ALLOC_ZVAL(r4);
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_getprimarykeyattributes" TSRMLS_CC);
			PHALCON_CALL_METHOD(r4, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r4 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			if (v5) {
				Z_DELREF_P(v5);
				if (!Z_REFCOUNT_P(v5)) {
					FREE_ZVAL(v5);
				}
			}
			Z_ADDREF_P(r4);
			v5 = r4;
			phalcon_debug_assign("$primaryKeys", r4 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=414");
			//$numericTyped
			PHALCON_ALLOC_ZVAL(r5);
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_getdatatypesnumeric" TSRMLS_CC);
			PHALCON_CALL_METHOD(r5, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r5 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			if (v6) {
				Z_DELREF_P(v6);
				if (!Z_REFCOUNT_P(v6)) {
					FREE_ZVAL(v6);
				}
			}
			Z_ADDREF_P(r5);
			v6 = r5;
			phalcon_debug_assign("$numericTyped", r5 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Base::_exists (If) File=Library/Phalcon/Model/Base.php Line=415");
			PHALCON_ALLOC_ZVAL(r6);
			//$primaryKeys
			p4[0] = v5;
			phalcon_debug_param(v5 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r6, "count", 1, p4);
			phalcon_debug_vdump("count > ", r6 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(t1);
			ZVAL_LONG(t1, 0);
			PHALCON_SMALLER_FUNCTION(r7, t1, r6);
			if (zend_is_true(r7)) {
				phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=415");
				phalcon_step_over("Phalcon_Model_Base::_exists (Foreach) File=Library/Phalcon/Model/Base.php Line=416");
				//$primaryKeys
				//$key
				FOREACH_V(v5, ac0, fes68, fee68, ah0, hp0, v7)
					phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=416");
					phalcon_step_over("Phalcon_Model_Base::_exists (If) File=Library/Phalcon/Model/Base.php Line=417");
					//$this
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
					//$key
					phalcon_read_property_zval(t2, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
					zval_copy_ctor(t2);
					PHALCON_INIT_NULL(t3);
					PHALCON_NOT_IDENTICAL_FUNCTION(r8, t2, t3);
					//$this
					if (!t4) {
						PHALCON_ALLOC_ZVAL(t4);
					} else {
						if (Z_REFCOUNT_P(t4) > 1) {
							{
								zval *orig_ptr = t4;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(t4);
									*t4 = *orig_ptr;
									zval_copy_ctor(t4);
									Z_SET_REFCOUNT_P(t4, 1);
									Z_UNSET_ISREF_P(t4);
								}
							}
						} else {
							FREE_ZVAL(t4);
							PHALCON_ALLOC_ZVAL(t4);
						}
					}
					//$key
					phalcon_read_property_zval(t4, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
					zval_copy_ctor(t4);
					if (!t5) {
						PHALCON_ALLOC_ZVAL(t5);
					} else {
						if (Z_REFCOUNT_P(t5) > 1) {
							SEPARATE_ZVAL(&t5);
						} else {
							if (Z_TYPE_P(t5) != IS_STRING) {
								FREE_ZVAL(t5);
								PHALCON_ALLOC_ZVAL(t5);
							}
						}
					}
					ZVAL_STRING(t5, "", 1);
					PHALCON_NOT_IDENTICAL_FUNCTION(r9, t4, t5);
					PHALCON_AND_FUNCTION(r10, r8, r9);
					if (zend_is_true(r10)) {
						phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=417");
						phalcon_step_over("Phalcon_Model_Base::_exists (If) File=Library/Phalcon/Model/Base.php Line=418");
						//$key
						//$numericTyped
						eval_int = phalcon_array_isset(v6, v7);
						if (eval_int) {
							phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=418");
							phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=419");
							//$key
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
							phalcon_concat_left(r12, " ", v7 TSRMLS_CC);
							//$this
							if (!t6) {
								PHALCON_ALLOC_ZVAL(t6);
							} else {
								if (Z_REFCOUNT_P(t6) > 1) {
									{
										zval *orig_ptr = t6;
										if (Z_REFCOUNT_P(orig_ptr) > 1) {
											Z_DELREF_P(orig_ptr);
											ALLOC_ZVAL(t6);
											*t6 = *orig_ptr;
											zval_copy_ctor(t6);
											Z_SET_REFCOUNT_P(t6, 1);
											Z_UNSET_ISREF_P(t6);
										}
									}
								} else {
									FREE_ZVAL(t6);
									PHALCON_ALLOC_ZVAL(t6);
								}
							}
							//$key
							phalcon_read_property_zval(t6, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
							zval_copy_ctor(t6);
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
							phalcon_concat_vboth(r11, r12, " = ", t6 TSRMLS_CC);
							//$wherePk
							{
								zval *copy;
								ALLOC_ZVAL(copy);
								ZVAL_ZVAL(copy, r11, 1, 0);
								Z_SET_REFCOUNT_P(copy, 1);
								{
									zval *orig_ptr = v0;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										ALLOC_ZVAL(v0);
										*v0 = *orig_ptr;
										zval_copy_ctor(v0);
										Z_SET_REFCOUNT_P(v0, 1);
										Z_UNSET_ISREF_P(v0);
									}
								}
								phalcon_array_append(v0, copy TSRMLS_CC);
							}
						} else {
							phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=420");
							phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=421");
							//$key
							if (!r14) {
								PHALCON_ALLOC_ZVAL(r14);
							} else {
								if (Z_REFCOUNT_P(r14) > 1) {
									{
										zval *orig_ptr = r14;
										if (Z_REFCOUNT_P(orig_ptr) > 1) {
											Z_DELREF_P(orig_ptr);
											ALLOC_ZVAL(r14);
											*r14 = *orig_ptr;
											zval_copy_ctor(r14);
											Z_SET_REFCOUNT_P(r14, 1);
											Z_UNSET_ISREF_P(r14);
										}
									}
								} else {
									FREE_ZVAL(r14);
									PHALCON_ALLOC_ZVAL(r14);
								}
							}
							phalcon_concat_left(r14, " ", v7 TSRMLS_CC);
							//$this
							if (!t7) {
								PHALCON_ALLOC_ZVAL(t7);
							} else {
								if (Z_REFCOUNT_P(t7) > 1) {
									{
										zval *orig_ptr = t7;
										if (Z_REFCOUNT_P(orig_ptr) > 1) {
											Z_DELREF_P(orig_ptr);
											ALLOC_ZVAL(t7);
											*t7 = *orig_ptr;
											zval_copy_ctor(t7);
											Z_SET_REFCOUNT_P(t7, 1);
											Z_UNSET_ISREF_P(t7);
										}
									}
								} else {
									FREE_ZVAL(t7);
									PHALCON_ALLOC_ZVAL(t7);
								}
							}
							//$key
							phalcon_read_property_zval(t7, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
							zval_copy_ctor(t7);
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
							phalcon_concat_vboth(r13, r14, " = '", t7 TSRMLS_CC);
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
							phalcon_concat_right(r15, r13, "'" TSRMLS_CC);
							//$wherePk
							{
								zval *copy;
								ALLOC_ZVAL(copy);
								ZVAL_ZVAL(copy, r15, 1, 0);
								Z_SET_REFCOUNT_P(copy, 1);
								{
									zval *orig_ptr = v0;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										ALLOC_ZVAL(v0);
										*v0 = *orig_ptr;
										zval_copy_ctor(v0);
										Z_SET_REFCOUNT_P(v0, 1);
										Z_UNSET_ISREF_P(v0);
									}
								}
								phalcon_array_append(v0, copy TSRMLS_CC);
							}
						}
					}
				END_FOREACH(ac0, fes68, fee68, ah0, hp0);
				phalcon_step_over("Phalcon_Model_Base::_exists (If) File=Library/Phalcon/Model/Base.php Line=425");
				PHALCON_ALLOC_ZVAL(r16);
				//$wherePk
				p5[0] = v0;
				phalcon_debug_param(v0 TSRMLS_CC);
				PHALCON_CALL_FUNC_PARAMS(r16, "count", 1, p5);
				phalcon_debug_vdump("count > ", r16 TSRMLS_CC);
				if (zend_is_true(r16)) {
					phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=425");
					phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=426");
					PHALCON_ALLOC_ZVAL(r17);
					PHALCON_ALLOC_ZVAL(p6[0]);
					ZVAL_STRING(p6[0], " AND ", 1);
					//$wherePk
					p6[1] = v0;
					phalcon_debug_param(v0 TSRMLS_CC);
					PHALCON_CALL_FUNC_PARAMS(r17, "join", 2, p6);
					phalcon_debug_vdump("join > ", r17 TSRMLS_CC);
					//$this
					{
						zval *copy;
						ALLOC_ZVAL(copy);
						ZVAL_ZVAL(copy, r17, 1, 0);
						Z_SET_REFCOUNT_P(copy, 0);
						phalcon_update_property_zval(this_ptr, "_uniqueKey", strlen("_uniqueKey"), copy TSRMLS_CC);
					}
				} else {
					phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=427");
					phalcon_step_out_entry();
					RETURN_LONG(0);
				}
				phalcon_step_over("Phalcon_Model_Base::_exists (AssignOp) File=Library/Phalcon/Model/Base.php Line=430");
				//$query
				//$this
				PHALCON_ALLOC_ZVAL(t8);
				phalcon_read_property(t8, this_ptr, "_uniqueKey", sizeof("_uniqueKey")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t8);
				PHALCON_CONCAT_FUNCTION(r18, v4, t8);
				//$query
				if (v4) {
					Z_DELREF_P(v4);
					if (!Z_REFCOUNT_P(v4)) {
						FREE_ZVAL(v4);
					}
				}
				Z_ADDREF_P(r18);
				v4 = r18;
				phalcon_debug_assign("$query", r18 TSRMLS_CC);
			} else {
				phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=431");
				phalcon_step_out_entry();
				RETURN_LONG(0);
			}
		} else {
			phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=434");
			phalcon_step_over("Phalcon_Model_Base::_exists (If) File=Library/Phalcon/Model/Base.php Line=435");
			PHALCON_ALLOC_ZVAL(r19);
			//$wherePk
			Z_ADDREF_P(v0);
			p7[0] = v0;
			phalcon_debug_param(v0 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r19, "is_numeric", 1, p7);
			phalcon_debug_vdump("is_numeric > ", r19 TSRMLS_CC);
			if (zend_is_true(r19)) {
				phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=435");
				phalcon_step_over("Phalcon_Model_Base::_exists (AssignOp) File=Library/Phalcon/Model/Base.php Line=436");
				//$query
				//$wherePk
				PHALCON_ALLOC_ZVAL(r20);
				phalcon_concat_left(r20, "id = ", v0 TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r21, v4, r20);
				//$query
				if (v4) {
					Z_DELREF_P(v4);
					if (!Z_REFCOUNT_P(v4)) {
						FREE_ZVAL(v4);
					}
				}
				Z_ADDREF_P(r21);
				v4 = r21;
				phalcon_debug_assign("$query", r21 TSRMLS_CC);
			} else {
				phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=437");
				phalcon_step_over("Phalcon_Model_Base::_exists (AssignOp) File=Library/Phalcon/Model/Base.php Line=438");
				//$query
				//$wherePk
				PHALCON_CONCAT_FUNCTION(r22, v4, v0);
				//$query
				if (v4) {
					Z_DELREF_P(v4);
					if (!Z_REFCOUNT_P(v4)) {
						FREE_ZVAL(v4);
					}
				}
				Z_ADDREF_P(r22);
				v4 = r22;
				phalcon_debug_assign("$query", r22 TSRMLS_CC);
			}
		}
		phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=441");
		//$num
		PHALCON_ALLOC_ZVAL(r23);
		//$this
		PHALCON_ALLOC_ZVAL(t9);
		phalcon_read_property(t9, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t9);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(t9, "fetchone" TSRMLS_CC);
		//$query
		Z_ADDREF_P(v4);
		p8[0] = v4;
		phalcon_debug_param(v4 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r23, t9, "fetchone", 1, p8, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r23 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (v8) {
			Z_DELREF_P(v8);
			if (!Z_REFCOUNT_P(v8)) {
				FREE_ZVAL(v8);
			}
		}
		Z_ADDREF_P(r23);
		v8 = r23;
		phalcon_debug_assign("$num", r23 TSRMLS_CC);
		//$num
		PHALCON_ALLOC_ZVAL(r24);
		phalcon_array_fetch_string(r24, v8, "rowcount", strlen("rowcount"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r24 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(r24) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r24);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r24);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=443");
		phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=444");
		//$wherePk
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(a1);
		v0 = a1;
		phalcon_debug_assign("$wherePk", a1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=445");
		//$primaryKeys
		PHALCON_ALLOC_ZVAL(r25);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "_getprimarykeyattributes" TSRMLS_CC);
		PHALCON_CALL_METHOD(r25, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r25 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (v5) {
			Z_DELREF_P(v5);
			if (!Z_REFCOUNT_P(v5)) {
				FREE_ZVAL(v5);
			}
		}
		Z_ADDREF_P(r25);
		v5 = r25;
		phalcon_debug_assign("$primaryKeys", r25 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=446");
		//$dataTypeNumeric
		PHALCON_ALLOC_ZVAL(r26);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "_getdatatypesnumeric" TSRMLS_CC);
		PHALCON_CALL_METHOD(r26, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r26 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (v9) {
			Z_DELREF_P(v9);
			if (!Z_REFCOUNT_P(v9)) {
				FREE_ZVAL(v9);
			}
		}
		Z_ADDREF_P(r26);
		v9 = r26;
		phalcon_debug_assign("$dataTypeNumeric", r26 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::_exists (If) File=Library/Phalcon/Model/Base.php Line=447");
		PHALCON_ALLOC_ZVAL(r27);
		//$primaryKeys
		p11[0] = v5;
		phalcon_debug_param(v5 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r27, "count", 1, p11);
		phalcon_debug_vdump("count > ", r27 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t10);
		ZVAL_LONG(t10, 0);
		PHALCON_SMALLER_FUNCTION(r28, t10, r27);
		if (zend_is_true(r28)) {
			phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=447");
			phalcon_step_over("Phalcon_Model_Base::_exists (Foreach) File=Library/Phalcon/Model/Base.php Line=448");
			//$primaryKeys
			//$key
			FOREACH_V(v5, ac1, fes69, fee69, ah1, hp1, v7)
				phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=448");
				phalcon_step_over("Phalcon_Model_Base::_exists (If) File=Library/Phalcon/Model/Base.php Line=449");
				//$this
				if (!t11) {
					PHALCON_ALLOC_ZVAL(t11);
				} else {
					if (Z_REFCOUNT_P(t11) > 1) {
						{
							zval *orig_ptr = t11;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(t11);
								*t11 = *orig_ptr;
								zval_copy_ctor(t11);
								Z_SET_REFCOUNT_P(t11, 1);
								Z_UNSET_ISREF_P(t11);
							}
						}
					} else {
						FREE_ZVAL(t11);
						PHALCON_ALLOC_ZVAL(t11);
					}
				}
				//$key
				phalcon_read_property_zval(t11, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t11);
				PHALCON_INIT_NULL(t12);
				PHALCON_NOT_IDENTICAL_FUNCTION(r29, t11, t12);
				//$this
				if (!t13) {
					PHALCON_ALLOC_ZVAL(t13);
				} else {
					if (Z_REFCOUNT_P(t13) > 1) {
						{
							zval *orig_ptr = t13;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(t13);
								*t13 = *orig_ptr;
								zval_copy_ctor(t13);
								Z_SET_REFCOUNT_P(t13, 1);
								Z_UNSET_ISREF_P(t13);
							}
						}
					} else {
						FREE_ZVAL(t13);
						PHALCON_ALLOC_ZVAL(t13);
					}
				}
				//$key
				phalcon_read_property_zval(t13, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t13);
				if (!t14) {
					PHALCON_ALLOC_ZVAL(t14);
				} else {
					if (Z_REFCOUNT_P(t14) > 1) {
						SEPARATE_ZVAL(&t14);
					} else {
						if (Z_TYPE_P(t14) != IS_STRING) {
							FREE_ZVAL(t14);
							PHALCON_ALLOC_ZVAL(t14);
						}
					}
				}
				ZVAL_STRING(t14, "", 1);
				PHALCON_NOT_IDENTICAL_FUNCTION(r30, t13, t14);
				PHALCON_AND_FUNCTION(r31, r29, r30);
				if (zend_is_true(r31)) {
					phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=449");
					phalcon_step_over("Phalcon_Model_Base::_exists (If) File=Library/Phalcon/Model/Base.php Line=450");
					//$key
					//$dataTypeNumeric
					eval_int = phalcon_array_isset(v9, v7);
					if (eval_int) {
						phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=450");
						phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=451");
						//$key
						if (!r33) {
							PHALCON_ALLOC_ZVAL(r33);
						} else {
							if (Z_REFCOUNT_P(r33) > 1) {
								{
									zval *orig_ptr = r33;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(r33);
										*r33 = *orig_ptr;
										zval_copy_ctor(r33);
										Z_SET_REFCOUNT_P(r33, 1);
										Z_UNSET_ISREF_P(r33);
									}
								}
							} else {
								FREE_ZVAL(r33);
								PHALCON_ALLOC_ZVAL(r33);
							}
						}
						phalcon_concat_left(r33, " ", v7 TSRMLS_CC);
						//$this
						if (!t15) {
							PHALCON_ALLOC_ZVAL(t15);
						} else {
							if (Z_REFCOUNT_P(t15) > 1) {
								{
									zval *orig_ptr = t15;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(t15);
										*t15 = *orig_ptr;
										zval_copy_ctor(t15);
										Z_SET_REFCOUNT_P(t15, 1);
										Z_UNSET_ISREF_P(t15);
									}
								}
							} else {
								FREE_ZVAL(t15);
								PHALCON_ALLOC_ZVAL(t15);
							}
						}
						//$key
						phalcon_read_property_zval(t15, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
						zval_copy_ctor(t15);
						if (!r32) {
							PHALCON_ALLOC_ZVAL(r32);
						} else {
							if (Z_REFCOUNT_P(r32) > 1) {
								{
									zval *orig_ptr = r32;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(r32);
										*r32 = *orig_ptr;
										zval_copy_ctor(r32);
										Z_SET_REFCOUNT_P(r32, 1);
										Z_UNSET_ISREF_P(r32);
									}
								}
							} else {
								FREE_ZVAL(r32);
								PHALCON_ALLOC_ZVAL(r32);
							}
						}
						phalcon_concat_vboth(r32, r33, " = ", t15 TSRMLS_CC);
						//$wherePk
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, r32, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
							{
								zval *orig_ptr = v0;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									ALLOC_ZVAL(v0);
									*v0 = *orig_ptr;
									zval_copy_ctor(v0);
									Z_SET_REFCOUNT_P(v0, 1);
									Z_UNSET_ISREF_P(v0);
								}
							}
							phalcon_array_append(v0, copy TSRMLS_CC);
						}
					} else {
						phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=452");
						phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=453");
						//$key
						if (!r35) {
							PHALCON_ALLOC_ZVAL(r35);
						} else {
							if (Z_REFCOUNT_P(r35) > 1) {
								{
									zval *orig_ptr = r35;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(r35);
										*r35 = *orig_ptr;
										zval_copy_ctor(r35);
										Z_SET_REFCOUNT_P(r35, 1);
										Z_UNSET_ISREF_P(r35);
									}
								}
							} else {
								FREE_ZVAL(r35);
								PHALCON_ALLOC_ZVAL(r35);
							}
						}
						phalcon_concat_left(r35, " ", v7 TSRMLS_CC);
						//$this
						if (!t16) {
							PHALCON_ALLOC_ZVAL(t16);
						} else {
							if (Z_REFCOUNT_P(t16) > 1) {
								{
									zval *orig_ptr = t16;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(t16);
										*t16 = *orig_ptr;
										zval_copy_ctor(t16);
										Z_SET_REFCOUNT_P(t16, 1);
										Z_UNSET_ISREF_P(t16);
									}
								}
							} else {
								FREE_ZVAL(t16);
								PHALCON_ALLOC_ZVAL(t16);
							}
						}
						//$key
						phalcon_read_property_zval(t16, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
						zval_copy_ctor(t16);
						if (!r34) {
							PHALCON_ALLOC_ZVAL(r34);
						} else {
							if (Z_REFCOUNT_P(r34) > 1) {
								{
									zval *orig_ptr = r34;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(r34);
										*r34 = *orig_ptr;
										zval_copy_ctor(r34);
										Z_SET_REFCOUNT_P(r34, 1);
										Z_UNSET_ISREF_P(r34);
									}
								}
							} else {
								FREE_ZVAL(r34);
								PHALCON_ALLOC_ZVAL(r34);
							}
						}
						phalcon_concat_vboth(r34, r35, " = '", t16 TSRMLS_CC);
						if (!r36) {
							PHALCON_ALLOC_ZVAL(r36);
						} else {
							if (Z_REFCOUNT_P(r36) > 1) {
								{
									zval *orig_ptr = r36;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(r36);
										*r36 = *orig_ptr;
										zval_copy_ctor(r36);
										Z_SET_REFCOUNT_P(r36, 1);
										Z_UNSET_ISREF_P(r36);
									}
								}
							} else {
								FREE_ZVAL(r36);
								PHALCON_ALLOC_ZVAL(r36);
							}
						}
						phalcon_concat_right(r36, r34, "'" TSRMLS_CC);
						//$wherePk
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, r36, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
							{
								zval *orig_ptr = v0;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									ALLOC_ZVAL(v0);
									*v0 = *orig_ptr;
									zval_copy_ctor(v0);
									Z_SET_REFCOUNT_P(v0, 1);
									Z_UNSET_ISREF_P(v0);
								}
							}
							phalcon_array_append(v0, copy TSRMLS_CC);
						}
					}
				}
			END_FOREACH(ac1, fes69, fee69, ah1, hp1);
			phalcon_step_over("Phalcon_Model_Base::_exists (If) File=Library/Phalcon/Model/Base.php Line=457");
			PHALCON_ALLOC_ZVAL(r37);
			//$wherePk
			p12[0] = v0;
			phalcon_debug_param(v0 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r37, "count", 1, p12);
			phalcon_debug_vdump("count > ", r37 TSRMLS_CC);
			if (zend_is_true(r37)) {
				phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=457");
				phalcon_step_over("Phalcon_Model_Base::_exists (Assignment) File=Library/Phalcon/Model/Base.php Line=458");
				PHALCON_ALLOC_ZVAL(r38);
				PHALCON_ALLOC_ZVAL(p13[0]);
				ZVAL_STRING(p13[0], " AND ", 1);
				//$wherePk
				p13[1] = v0;
				phalcon_debug_param(v0 TSRMLS_CC);
				PHALCON_CALL_FUNC_PARAMS(r38, "join", 2, p13);
				phalcon_debug_vdump("join > ", r38 TSRMLS_CC);
				//$this
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, r38, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_uniqueKey", strlen("_uniqueKey"), copy TSRMLS_CC);
				}
				phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
				phalcon_step_out_entry();
				RETURN_TRUE;
			} else {
				phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=460");
				phalcon_step_out_entry();
				RETURN_LONG(0);
			}
		} else {
			phalcon_step_over("Phalcon_Model_Base::_exists (Block) File=Library/Phalcon/Model/Base.php Line=463");
			phalcon_step_out_entry();
			RETURN_LONG(0);
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Base::_exists (Method) File=Library/Phalcon/Model/Base.php Line=469");
}

PHP_METHOD(Phalcon_Model_Base, _getGroupResult){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL, NULL }, *p5[] = { NULL, NULL }, *p6[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "_getGroupResult", 0);
	phalcon_step_over("Phalcon_Model_Base::_getGroupResult (Assignment) File=Library/Phalcon/Model/Base.php Line=470");
	//$connection
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(t0);
	v3 = t0;
	phalcon_debug_assign("$connection", t0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::_getGroupResult (If) File=Library/Phalcon/Model/Base.php Line=471");
	//$params
	eval_int = phalcon_array_isset_string(v0, "group", strlen("group")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Base::_getGroupResult (Block) File=Library/Phalcon/Model/Base.php Line=471");
		phalcon_step_over("Phalcon_Model_Base::_getGroupResult (Assignment) File=Library/Phalcon/Model/Base.php Line=472");
		//$resultResource
		PHALCON_ALLOC_ZVAL(r0);
		//$connection
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(v3, "query" TSRMLS_CC);
		//$selectStatement
		Z_ADDREF_P(v1);
		p0[0] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r0, v3, "query", 1, p0, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r0);
		v4 = r0;
		phalcon_debug_assign("$resultResource", r0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::_getGroupResult (Assignment) File=Library/Phalcon/Model/Base.php Line=473");
		//$count
		PHALCON_ALLOC_ZVAL(r1);
		//$connection
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(v3, "numrows" TSRMLS_CC);
		//$resultResource
		Z_ADDREF_P(v4);
		p1[0] = v4;
		phalcon_debug_param(v4 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r1, v3, "numrows", 1, p1, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (v5) {
			Z_DELREF_P(v5);
			if (!Z_REFCOUNT_P(v5)) {
				FREE_ZVAL(v5);
			}
		}
		Z_ADDREF_P(r1);
		v5 = r1;
		phalcon_debug_assign("$count", r1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::_getGroupResult (If) File=Library/Phalcon/Model/Base.php Line=474");
		//$count
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_LONG(t1, 0);
		PHALCON_SMALLER_FUNCTION(r2, t1, v5);
		if (zend_is_true(r2)) {
			phalcon_step_over("Phalcon_Model_Base::_getGroupResult (Block) File=Library/Phalcon/Model/Base.php Line=474");
			phalcon_step_over("Phalcon_Model_Base::_getGroupResult (Assignment) File=Library/Phalcon/Model/Base.php Line=475");
			//$rowObject
			PHALCON_ALLOC_ZVAL(i0);
			object_init_ex(i0, phalcon_model_row_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
			PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			if (v6) {
				Z_DELREF_P(v6);
				if (!Z_REFCOUNT_P(v6)) {
					FREE_ZVAL(v6);
				}
			}
			Z_ADDREF_P(i0);
			v6 = i0;
			phalcon_debug_assign("$rowObject", i0 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Base::_getGroupResult (MethodCall) File=Library/Phalcon/Model/Base.php Line=476");
			//$rowObject
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(v6, "setconnection" TSRMLS_CC);
			//$connection
			Z_ADDREF_P(v3);
			p3[0] = v3;
			phalcon_debug_param(v3 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v6, "setconnection", 1, p3, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(i1);
			object_init_ex(i1, phalcon_model_resultset_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
			//$rowObject
			Z_ADDREF_P(v6);
			p4[0] = v6;
			phalcon_debug_param(v6 TSRMLS_CC);
			//$resultResource
			Z_ADDREF_P(v4);
			p4[1] = v4;
			phalcon_debug_param(v4 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p4, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", i1 TSRMLS_CC);
			phalcon_step_out_entry();
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(i1);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
				Z_SET_REFCOUNT_P(return_value, refcount);
			}
			return;
		} else {
			phalcon_step_over("Phalcon_Model_Base::_getGroupResult (Block) File=Library/Phalcon/Model/Base.php Line=478");
			PHALCON_ALLOC_ZVAL(i2);
			object_init_ex(i2, phalcon_model_resultset_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(i2, "__construct" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(i3);
			object_init(i3);
			Z_ADDREF_P(i3);
			p5[0] = i3;
			phalcon_debug_param(i3 TSRMLS_CC);
			PHALCON_PARAM_BOOL(p5[1], 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 2, p5, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_vdump("Returning > ", i2 TSRMLS_CC);
			phalcon_step_out_entry();
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(i2);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
				Z_SET_REFCOUNT_P(return_value, refcount);
			}
			return;
		}
	} else {
		phalcon_step_over("Phalcon_Model_Base::_getGroupResult (Block) File=Library/Phalcon/Model/Base.php Line=481");
		phalcon_step_over("Phalcon_Model_Base::_getGroupResult (Assignment) File=Library/Phalcon/Model/Base.php Line=482");
		//$num
		PHALCON_ALLOC_ZVAL(r3);
		//$connection
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(v3, "fetchone" TSRMLS_CC);
		//$selectStatement
		Z_ADDREF_P(v1);
		p6[0] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r3, v3, "fetchone", 1, p6, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (v7) {
			Z_DELREF_P(v7);
			if (!Z_REFCOUNT_P(v7)) {
				FREE_ZVAL(v7);
			}
		}
		Z_ADDREF_P(r3);
		v7 = r3;
		phalcon_debug_assign("$num", r3 TSRMLS_CC);
		//$alias
		//$num
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_array_fetch(r4, v7, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r4 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(r4) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r4);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r4);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Base::_getGroupResult (Method) File=Library/Phalcon/Model/Base.php Line=487");
}

PHP_METHOD(Phalcon_Model_Base, count){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *p3[] = { NULL }, *p5[] = { NULL, NULL }, *p6[] = { NULL, NULL, NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "count", 0);
	phalcon_step_over("Phalcon_Model_Base::count (MethodCall) File=Library/Phalcon/Model/Base.php Line=489");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_connect" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::count (If) File=Library/Phalcon/Model/Base.php Line=490");
	//$params
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=490");
		phalcon_step_over("Phalcon_Model_Base::count (If) File=Library/Phalcon/Model/Base.php Line=491");
		//$params
		if (Z_TYPE_P(v0) != IS_NULL) {
			phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=491");
			phalcon_step_over("Phalcon_Model_Base::count (Assignment) File=Library/Phalcon/Model/Base.php Line=492");
			//$params
			PHALCON_ALLOC_ZVAL(a0);
			array_init(a0);
			//$params
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v0, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				{
					zval *orig_ptr = a0;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(a0);
						*a0 = *orig_ptr;
						zval_copy_ctor(a0);
						Z_SET_REFCOUNT_P(a0, 1);
						Z_UNSET_ISREF_P(a0);
					}
				}
				add_next_index_zval(a0, copy);
			}
			if (v0) {
				if (!Z_REFCOUNT_P(v0)) {
					FREE_ZVAL(v0);
				}
			}
			Z_ADDREF_P(a0);
			v0 = a0;
			phalcon_debug_assign("$params", a0 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=493");
			phalcon_step_over("Phalcon_Model_Base::count (Assignment) File=Library/Phalcon/Model/Base.php Line=494");
			//$params
			PHALCON_ALLOC_ZVAL(a1);
			array_init(a1);
			if (v0) {
				if (!Z_REFCOUNT_P(v0)) {
					FREE_ZVAL(v0);
				}
			}
			Z_ADDREF_P(a1);
			v0 = a1;
			phalcon_debug_assign("$params", a1 TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Model_Base::count (Assignment) File=Library/Phalcon/Model/Base.php Line=498");
	//$schema
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getschema" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "getschema", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_debug_assign("$schema", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::count (Assignment) File=Library/Phalcon/Model/Base.php Line=499");
	//$source
	PHALCON_ALLOC_ZVAL(r1);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getsource" TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	phalcon_debug_assign("$source", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::count (If) File=Library/Phalcon/Model/Base.php Line=500");
	//$schema
	if (zend_is_true(v1)) {
		phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=500");
		phalcon_step_over("Phalcon_Model_Base::count (Assignment) File=Library/Phalcon/Model/Base.php Line=501");
		//$table
		//$schema
		//$source
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_vboth(r2, v1, ".", v2 TSRMLS_CC);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r2);
		v3 = r2;
		phalcon_debug_assign("$table", r2 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=502");
		phalcon_step_over("Phalcon_Model_Base::count (Assignment) File=Library/Phalcon/Model/Base.php Line=503");
		//$table
		//$source
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(v2);
		v3 = v2;
		phalcon_debug_assign("$table", v2 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Base::count (If) File=Library/Phalcon/Model/Base.php Line=506");
	//$params
	eval_int = phalcon_array_isset_string(v0, "distinct", strlen("distinct")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=506");
		phalcon_step_over("Phalcon_Model_Base::count (Assignment) File=Library/Phalcon/Model/Base.php Line=507");
		//$select
		//$params
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_array_fetch_string(r4, v0, "distinct", strlen("distinct"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r5);
		phalcon_concat_left(r5, "SELECT COUNT(DISTINCT ", r4 TSRMLS_CC);
		//$table
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_concat_vboth(r3, r5, ") AS rowcount FROM ", v3 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_concat_right(r6, r3, " " TSRMLS_CC);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r6);
		v4 = r6;
		phalcon_debug_assign("$select", r6 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=508");
		phalcon_step_over("Phalcon_Model_Base::count (If) File=Library/Phalcon/Model/Base.php Line=509");
		//$params
		eval_int = phalcon_array_isset_string(v0, "group", strlen("group")+1);
		if (eval_int) {
			phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=509");
			phalcon_step_over("Phalcon_Model_Base::count (Assignment) File=Library/Phalcon/Model/Base.php Line=510");
			//$select
			//$params
			PHALCON_ALLOC_ZVAL(r8);
			phalcon_array_fetch_string(r8, v0, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r9);
			phalcon_concat_left(r9, "SELECT ", r8 TSRMLS_CC);
			//$table
			PHALCON_ALLOC_ZVAL(r7);
			phalcon_concat_vboth(r7, r9, ", COUNT(*) AS rowcount FROM ", v3 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r10);
			phalcon_concat_right(r10, r7, " " TSRMLS_CC);
			if (v4) {
				Z_DELREF_P(v4);
				if (!Z_REFCOUNT_P(v4)) {
					FREE_ZVAL(v4);
				}
			}
			Z_ADDREF_P(r10);
			v4 = r10;
			phalcon_debug_assign("$select", r10 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=511");
			phalcon_step_over("Phalcon_Model_Base::count (Assignment) File=Library/Phalcon/Model/Base.php Line=512");
			//$select
			//$table
			PHALCON_ALLOC_ZVAL(r11);
			phalcon_concat_both(r11,  "SELECT COUNT(*) AS rowcount FROM ", v3, " " TSRMLS_CC);
			if (v4) {
				Z_DELREF_P(v4);
				if (!Z_REFCOUNT_P(v4)) {
					FREE_ZVAL(v4);
				}
			}
			Z_ADDREF_P(r11);
			v4 = r11;
			phalcon_debug_assign("$select", r11 TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Model_Base::count (If) File=Library/Phalcon/Model/Base.php Line=516");
	//$params
	eval_int = phalcon_array_isset_string(v0, "conditions", strlen("conditions")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=516");
		phalcon_step_over("Phalcon_Model_Base::count (AssignOp) File=Library/Phalcon/Model/Base.php Line=517");
		//$select
		//$params
		PHALCON_ALLOC_ZVAL(r12);
		phalcon_array_fetch_string(r12, v0, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r13);
		phalcon_concat_both(r13,  " WHERE ", r12, " " TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r14, v4, r13);
		//$select
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r14);
		v4 = r14;
		phalcon_debug_assign("$select", r14 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=518");
		phalcon_step_over("Phalcon_Model_Base::count (If) File=Library/Phalcon/Model/Base.php Line=519");
		//$params
		eval_int = phalcon_array_isset_long(v0, 0);
		if (eval_int) {
			phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=519");
			phalcon_step_over("Phalcon_Model_Base::count (Assignment) File=Library/Phalcon/Model/Base.php Line=520");
			//$condition
			//$params
			PHALCON_ALLOC_ZVAL(r15);
			phalcon_array_fetch_long(r15, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (v5) {
				Z_DELREF_P(v5);
				if (!Z_REFCOUNT_P(v5)) {
					FREE_ZVAL(v5);
				}
			}
			Z_ADDREF_P(r15);
			v5 = r15;
			phalcon_debug_assign("$condition", r15 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Base::count (If) File=Library/Phalcon/Model/Base.php Line=521");
			PHALCON_ALLOC_ZVAL(r16);
			//$condition
			Z_ADDREF_P(v5);
			p3[0] = v5;
			phalcon_debug_param(v5 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r16, "is_numeric", 1, p3);
			phalcon_debug_vdump("is_numeric > ", r16 TSRMLS_CC);
			if (zend_is_true(r16)) {
				phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=521");
				phalcon_step_over("Phalcon_Model_Base::count (Assignment) File=Library/Phalcon/Model/Base.php Line=522");
				//$primaryKeys
				PHALCON_ALLOC_ZVAL(r17);
				//$this
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_method_call(this_ptr, "_getprimarykeyattributes" TSRMLS_CC);
				PHALCON_CALL_METHOD(r17, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
				phalcon_debug_vdump("MethodReturn > ", r17 TSRMLS_CC);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				if (v6) {
					Z_DELREF_P(v6);
					if (!Z_REFCOUNT_P(v6)) {
						FREE_ZVAL(v6);
					}
				}
				Z_ADDREF_P(r17);
				v6 = r17;
				phalcon_debug_assign("$primaryKeys", r17 TSRMLS_CC);
				phalcon_step_over("Phalcon_Model_Base::count (If) File=Library/Phalcon/Model/Base.php Line=523");
				//$this
				PHALCON_ALLOC_ZVAL(t0);
				phalcon_read_property(t0, this_ptr, "_isView", sizeof("_isView")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t0);
				if (zend_is_true(t0)) {
					phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=523");
					phalcon_step_over("Phalcon_Model_Base::count (Assignment) File=Library/Phalcon/Model/Base.php Line=524");
					PHALCON_ALLOC_ZVAL(t1);
					ZVAL_STRING(t1, "id", 1);
					//$primaryKeys
					{
						zval *orig_ptr = v6;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(v6);
							*v6 = *orig_ptr;
							zval_copy_ctor(v6);
							Z_SET_REFCOUNT_P(v6, 1);
							Z_UNSET_ISREF_P(v6);
						}
					}
					phalcon_array_update_long(v6, 0, t1 TSRMLS_CC);
				}
				phalcon_step_over("Phalcon_Model_Base::count (AssignOp) File=Library/Phalcon/Model/Base.php Line=526");
				//$select
				//$primaryKeys
				PHALCON_ALLOC_ZVAL(r19);
				phalcon_array_fetch_long(r19, v6, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r20);
				phalcon_concat_left(r20, " WHERE ", r19 TSRMLS_CC);
				//$condition
				PHALCON_ALLOC_ZVAL(r18);
				phalcon_concat_vboth(r18, r20, " = '", v5 TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r21);
				phalcon_concat_right(r21, r18, "'" TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r22, v4, r21);
				//$select
				if (v4) {
					Z_DELREF_P(v4);
					if (!Z_REFCOUNT_P(v4)) {
						FREE_ZVAL(v4);
					}
				}
				Z_ADDREF_P(r22);
				v4 = r22;
				phalcon_debug_assign("$select", r22 TSRMLS_CC);
			} else {
				phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=527");
				phalcon_step_over("Phalcon_Model_Base::count (If) File=Library/Phalcon/Model/Base.php Line=528");
				//$condition
				if (zend_is_true(v5)) {
					phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=528");
					phalcon_step_over("Phalcon_Model_Base::count (AssignOp) File=Library/Phalcon/Model/Base.php Line=529");
					//$select
					//$condition
					PHALCON_ALLOC_ZVAL(r23);
					phalcon_concat_left(r23, " WHERE ", v5 TSRMLS_CC);
					PHALCON_CONCAT_FUNCTION(r24, v4, r23);
					//$select
					if (v4) {
						Z_DELREF_P(v4);
						if (!Z_REFCOUNT_P(v4)) {
							FREE_ZVAL(v4);
						}
					}
					Z_ADDREF_P(r24);
					v4 = r24;
					phalcon_debug_assign("$select", r24 TSRMLS_CC);
				}
			}
		}
	}
	phalcon_step_over("Phalcon_Model_Base::count (If) File=Library/Phalcon/Model/Base.php Line=534");
	//$params
	eval_int = phalcon_array_isset_string(v0, "group", strlen("group")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=534");
		phalcon_step_over("Phalcon_Model_Base::count (AssignOp) File=Library/Phalcon/Model/Base.php Line=535");
		//$select
		//$params
		PHALCON_ALLOC_ZVAL(r25);
		phalcon_array_fetch_string(r25, v0, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r26);
		phalcon_concat_both(r26,  " GROUP BY ", r25, " " TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r27, v4, r26);
		//$select
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r27);
		v4 = r27;
		phalcon_debug_assign("$select", r27 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Base::count (If) File=Library/Phalcon/Model/Base.php Line=537");
	//$params
	eval_int = phalcon_array_isset_string(v0, "having", strlen("having")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=537");
		phalcon_step_over("Phalcon_Model_Base::count (AssignOp) File=Library/Phalcon/Model/Base.php Line=538");
		//$select
		//$params
		PHALCON_ALLOC_ZVAL(r28);
		phalcon_array_fetch_string(r28, v0, "having", strlen("having"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r29);
		phalcon_concat_both(r29,  " HAVING ", r28, " " TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r30, v4, r29);
		//$select
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r30);
		v4 = r30;
		phalcon_debug_assign("$select", r30 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Base::count (If) File=Library/Phalcon/Model/Base.php Line=540");
	//$params
	eval_int = phalcon_array_isset_string(v0, "order", strlen("order")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=540");
		phalcon_step_over("Phalcon_Model_Base::count (AssignOp) File=Library/Phalcon/Model/Base.php Line=541");
		//$select
		//$params
		PHALCON_ALLOC_ZVAL(r31);
		phalcon_array_fetch_string(r31, v0, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r32);
		phalcon_concat_both(r32,  " ORDER BY ", r31, " " TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r33, v4, r32);
		//$select
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r33);
		v4 = r33;
		phalcon_debug_assign("$select", r33 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Base::count (If) File=Library/Phalcon/Model/Base.php Line=543");
	//$params
	eval_int = phalcon_array_isset_string(v0, "limit", strlen("limit")+1);
	if (eval_int) {
		phalcon_step_over("Phalcon_Model_Base::count (Block) File=Library/Phalcon/Model/Base.php Line=543");
		phalcon_step_over("Phalcon_Model_Base::count (Assignment) File=Library/Phalcon/Model/Base.php Line=544");
		//$select
		PHALCON_ALLOC_ZVAL(r34);
		//$this
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "connection", sizeof("connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(t2, "_limit" TSRMLS_CC);
		//$select
		Z_ADDREF_P(v4);
		p5[0] = v4;
		phalcon_debug_param(v4 TSRMLS_CC);
		//$params
		PHALCON_ALLOC_ZVAL(r35);
		phalcon_array_fetch_string(r35, v0, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r35);
		p5[1] = r35;
		phalcon_debug_param(r35 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r34, t2, "_limit", 2, p5, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r34 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r34);
		v4 = r34;
		phalcon_debug_assign("$select", r34 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(r36);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_getgroupresult" TSRMLS_CC);
	//$params
	Z_ADDREF_P(v0);
	p6[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$select
	Z_ADDREF_P(v4);
	p6[1] = v4;
	phalcon_debug_param(v4 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p6[2]);
	ZVAL_STRING(p6[2], "rowcount", 1);
	PHALCON_CALL_METHOD_PARAMS(r36, this_ptr, "_getgroupresult", 3, p6, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r36 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r36 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r36, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Base::count (Method) File=Library/Phalcon/Model/Base.php Line=550");
}

PHP_METHOD(Phalcon_Model_Base, _callEvent){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "_callEvent", 0);
	phalcon_step_over("Phalcon_Model_Base::_callEvent (If) File=Library/Phalcon/Model/Base.php Line=551");
	//$this
	//$eventName
	if (phalcon_method_exists(this_ptr, v0 TSRMLS_CC) == SUCCESS) {
		phalcon_step_over("Phalcon_Model_Base::_callEvent (Block) File=Library/Phalcon/Model/Base.php Line=551");
		phalcon_step_over("Phalcon_Model_Base::_callEvent (If) File=Library/Phalcon/Model/Base.php Line=552");
		PHALCON_ALLOC_ZVAL(r0);
		//$eventName
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, Z_STRVAL_P(v0) TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, this_ptr, Z_STRVAL_P(v0), PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (Z_TYPE_P(r0) == IS_BOOL && !Z_BVAL_P(r0)) {
			phalcon_step_over("Phalcon_Model_Base::_callEvent (Block) File=Library/Phalcon/Model/Base.php Line=552");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	} else {
		phalcon_step_over("Phalcon_Model_Base::_callEvent (Block) File=Library/Phalcon/Model/Base.php Line=555");
		phalcon_step_over("Phalcon_Model_Base::_callEvent (If) File=Library/Phalcon/Model/Base.php Line=556");
		//$this
		//$eventName
		eval_int = phalcon_isset_property_zval(this_ptr, v0 TSRMLS_CC);
		if (eval_int) {
			phalcon_step_over("Phalcon_Model_Base::_callEvent (Block) File=Library/Phalcon/Model/Base.php Line=556");
			phalcon_step_over("Phalcon_Model_Base::_callEvent (Assignment) File=Library/Phalcon/Model/Base.php Line=557");
			//$method
			//$this
			PHALCON_ALLOC_ZVAL(t0);
			//$eventName
			phalcon_read_property_zval(t0, this_ptr, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t0);
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(t0);
			v1 = t0;
			phalcon_debug_assign("$method", t0 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Base::_callEvent (If) File=Library/Phalcon/Model/Base.php Line=558");
			PHALCON_ALLOC_ZVAL(r1);
			//$method
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, Z_STRVAL_P(v1) TSRMLS_CC);
			PHALCON_CALL_METHOD(r1, this_ptr, Z_STRVAL_P(v1), PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			if (Z_TYPE_P(r1) == IS_BOOL && !Z_BVAL_P(r1)) {
				phalcon_step_over("Phalcon_Model_Base::_callEvent (Block) File=Library/Phalcon/Model/Base.php Line=558");
				phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
				phalcon_step_out_entry();
				RETURN_FALSE;
			}
		}
	}
	phalcon_debug_vdump("Returning > TRUE", NULL TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_TRUE;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Base::_callEvent (Method) File=Library/Phalcon/Model/Base.php Line=566");
}

PHP_METHOD(Phalcon_Model_Base, _cancelOperation){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *v0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p4[] = { NULL };

	phalcon_step_into_entry("Phalcon_Model_Base", "_cancelOperation", 0);
	phalcon_step_over("Phalcon_Model_Base::_cancelOperation (If) File=Library/Phalcon/Model/Base.php Line=567");
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_INIT_FALSE(t1);
	PHALCON_EQUAL_FUNCTION(r0, t0, t1);
	if (zend_is_true(r0)) {
		phalcon_step_over("Phalcon_Model_Base::_cancelOperation (Block) File=Library/Phalcon/Model/Base.php Line=567");
		phalcon_step_over("Phalcon_Model_Base::_cancelOperation (If) File=Library/Phalcon/Model/Base.php Line=568");
		//$this
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_operationMade", sizeof("_operationMade")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		PHALCON_GET_CLASS_CONSTANT(t3, phalcon_model_base_class_entry, "OP_DELETE");
		PHALCON_EQUAL_FUNCTION(r1, t2, t3);
		if (zend_is_true(r1)) {
			phalcon_step_over("Phalcon_Model_Base::_cancelOperation (Block) File=Library/Phalcon/Model/Base.php Line=568");
			phalcon_step_over("Phalcon_Model_Base::_cancelOperation (MethodCall) File=Library/Phalcon/Model/Base.php Line=569");
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p0[0]);
			ZVAL_STRING(p0[0], "notDeleted", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p0, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Model_Base::_cancelOperation (Block) File=Library/Phalcon/Model/Base.php Line=570");
			phalcon_step_over("Phalcon_Model_Base::_cancelOperation (MethodCall) File=Library/Phalcon/Model/Base.php Line=571");
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p1[0]);
			ZVAL_STRING(p1[0], "notSaved", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p1, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Model_Base::_cancelOperation (If) File=Library/Phalcon/Model/Base.php Line=574");
	PHALCON_ALLOC_ZVAL(r2);
	PHALCON_CALL_STATIC(r2, "phalcon_transaction_manager", "isautomatic");
	phalcon_debug_vdump("StaticReturn > ", r2 TSRMLS_CC);
	if (zend_is_true(r2)) {
		phalcon_step_over("Phalcon_Model_Base::_cancelOperation (Block) File=Library/Phalcon/Model/Base.php Line=574");
		phalcon_step_over("Phalcon_Model_Base::_cancelOperation (Assignment) File=Library/Phalcon/Model/Base.php Line=575");
		//$transaction
		PHALCON_ALLOC_ZVAL(r3);
		PHALCON_CALL_STATIC(r3, "phalcon_transaction_manager", "getautomatic");
		phalcon_debug_vdump("StaticReturn > ", r3 TSRMLS_CC);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(r3);
		v0 = r3;
		phalcon_debug_assign("$transaction", r3 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::_cancelOperation (MethodCall) File=Library/Phalcon/Model/Base.php Line=576");
		//$transaction
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(v0, "setrollbackedrecord" TSRMLS_CC);
		//$this
		Z_ADDREF_P(this_ptr);
		p4[0] = this_ptr;
		phalcon_debug_param(this_ptr TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setrollbackedrecord", 1, p4, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::_cancelOperation (MethodCall) File=Library/Phalcon/Model/Base.php Line=577");
		//$transaction
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(v0, "rollback" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(v0, "rollback", PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Model_Base::_cancelOperation (Block) File=Library/Phalcon/Model/Base.php Line=578");
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Base::_cancelOperation (Method) File=Library/Phalcon/Model/Base.php Line=583");
}

PHP_METHOD(Phalcon_Model_Base, appendMessage){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL }, *p1[] = { NULL }, *p4[] = { NULL }, *p3[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "appendMessage", 0);
	phalcon_step_over("Phalcon_Model_Base::appendMessage (If) File=Library/Phalcon/Model/Base.php Line=584");
	//$message
	if (Z_TYPE_P(v0) == IS_OBJECT) {
		phalcon_step_over("Phalcon_Model_Base::appendMessage (Block) File=Library/Phalcon/Model/Base.php Line=584");
		phalcon_step_over("Phalcon_Model_Base::appendMessage (If) File=Library/Phalcon/Model/Base.php Line=585");
		PHALCON_ALLOC_ZVAL(r0);
		//$message
		p0[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r0, "get_class", 1, p0);
		phalcon_debug_vdump("get_class > ", r0 TSRMLS_CC);
		if (!phalcon_compare_strict_string(r0, "Phalcon_Model_Message")) {
			phalcon_step_over("Phalcon_Model_Base::appendMessage (Block) File=Library/Phalcon/Model/Base.php Line=585");
			phalcon_step_over("Phalcon_Model_Base::appendMessage (Throw) File=Library/Phalcon/Model/Base.php Line=586");
			PHALCON_ALLOC_ZVAL(i0);
			object_init_ex(i0, phalcon_model_exception_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r1);
			//$message
			p2[0] = v0;
			phalcon_debug_param(v0 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r1, "get_class", 1, p2);
			phalcon_debug_vdump("get_class > ", r1 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_concat_both(r2,  "Invalid message format '", r1, "'" TSRMLS_CC);
			Z_ADDREF_P(r2);
			p1[0] = r2;
			phalcon_debug_param(r2 TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			return;
		}
	} else {
		phalcon_step_over("Phalcon_Model_Base::appendMessage (Block) File=Library/Phalcon/Model/Base.php Line=588");
		phalcon_step_over("Phalcon_Model_Base::appendMessage (Throw) File=Library/Phalcon/Model/Base.php Line=589");
		PHALCON_ALLOC_ZVAL(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r3);
		//$message
		Z_ADDREF_P(v0);
		p4[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r3, "gettype", 1, p4);
		phalcon_debug_vdump("gettype > ", r3 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_concat_both(r4,  "Invalid message format '", r3, "'" TSRMLS_CC);
		Z_ADDREF_P(r4);
		p3[0] = r4;
		phalcon_debug_param(r4 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		return;
	}
	phalcon_step_over("Phalcon_Model_Base::appendMessage (Assignment) File=Library/Phalcon/Model/Base.php Line=591");
	//$message
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	{
		zval *orig_ptr = t0;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(t0);
			*t0 = *orig_ptr;
			zval_copy_ctor(t0);
			Z_SET_REFCOUNT_P(t0, 1);
			Z_UNSET_ISREF_P(t0);
		}
	}
	phalcon_array_append(t0, v0 TSRMLS_CC);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Base::appendMessage (Method) File=Library/Phalcon/Model/Base.php Line=594");
}

PHP_METHOD(Phalcon_Model_Base, getMessages){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Model_Base", "getMessages", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_step_over("Phalcon_Model_Base::getMessages (Method) File=Library/Phalcon/Model/Base.php Line=598");
}

PHP_METHOD(Phalcon_Model_Base, save){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL, *v13 = NULL;
	zval *v14 = NULL, *v15 = NULL, *v16 = NULL, *v17 = NULL, *v18 = NULL, *v19 = NULL, *v20 = NULL;
	zval *v21 = NULL, *v22 = NULL, *v23 = NULL, *v24 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL, *r41 = NULL;
	zval *r42 = NULL, *r43 = NULL, *r44 = NULL, *r45 = NULL, *r46 = NULL, *r47 = NULL, *r48 = NULL;
	zval *r49 = NULL, *r50 = NULL, *r51 = NULL, *r52 = NULL, *r53 = NULL, *r54 = NULL, *r55 = NULL;
	zval *r56 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL, *t17 = NULL, *t18 = NULL, *t19 = NULL, *t20 = NULL;
	zval *t21 = NULL, *t22 = NULL, *t23 = NULL, *t24 = NULL, *t25 = NULL, *t26 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL;
	zval *i0 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *p2[] = { NULL }, *p4[] = { NULL }, *p6[] = { NULL }, *p10[] = { NULL }, *p11[] = { NULL }, *p12[] = { NULL, NULL, NULL }, *p13[] = { NULL, NULL, NULL }, *p14[] = { NULL }, *p16[] = { NULL }, *p17[] = { NULL }, *p19[] = { NULL }, *p21[] = { NULL }, *p23[] = { NULL }, *p25[] = { NULL }, *p27[] = { NULL }, *p29[] = { NULL }, *p38[] = { NULL }, *p39[] = { NULL, NULL, NULL, NULL }, *p42[] = { NULL }, *p43[] = { NULL }, *p44[] = { NULL, NULL, NULL }, *p48[] = { NULL }, *p49[] = { NULL }, *p50[] = { NULL }, *p51[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Model_Base", "save", 0);
	phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=600");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_connect" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=601");
	//$exists
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_exists" TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, this_ptr, "_exists", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r0);
	v0 = r0;
	phalcon_debug_assign("$exists", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=603");
	//$exists
	if (!zend_is_true(v0)) {
		phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=603");
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=604");
		PHALCON_GET_CLASS_CONSTANT(t0, phalcon_model_base_class_entry, "OP_CREATE");
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_operationMade", strlen("_operationMade"), copy TSRMLS_CC);
		}
	} else {
		phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=605");
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=606");
		PHALCON_GET_CLASS_CONSTANT(t1, phalcon_model_base_class_entry, "OP_UPDATE");
		//$this
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_operationMade", strlen("_operationMade"), copy TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=610");
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, a0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=611");
	//$disableEvents
	t2 = zend_read_static_property(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(t2);
	v1 = t2;
	phalcon_debug_assign("$disableEvents", t2 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=612");
	//$disableEvents
	if (!zend_is_true(v1)) {
		phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=612");
		phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=613");
		PHALCON_ALLOC_ZVAL(r1);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p2[0]);
		ZVAL_STRING(p2[0], "beforeValidation", 1);
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "_callevent", 1, p2, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (Z_TYPE_P(r1) == IS_BOOL && !Z_BVAL_P(r1)) {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=613");
			phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=614");
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_canceloperation" TSRMLS_CC);
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
		phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=617");
		//$exists
		if (!zend_is_true(v0)) {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=617");
			phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=618");
			PHALCON_ALLOC_ZVAL(r2);
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p4[0]);
			ZVAL_STRING(p4[0], "beforeValidationOnCreate", 1);
			PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "_callevent", 1, p4, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			if (Z_TYPE_P(r2) == IS_BOOL && !Z_BVAL_P(r2)) {
				phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=618");
				phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=619");
				//$this
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_method_call(this_ptr, "_canceloperation" TSRMLS_CC);
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
				phalcon_step_out_entry();
				RETURN_FALSE;
			}
		} else {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=622");
			phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=623");
			PHALCON_ALLOC_ZVAL(r3);
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p6[0]);
			ZVAL_STRING(p6[0], "beforeValidationOnUpdate", 1);
			PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "_callevent", 1, p6, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r3 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			if (Z_TYPE_P(r3) == IS_BOOL && !Z_BVAL_P(r3)) {
				phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=623");
				phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=624");
				//$this
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_method_call(this_ptr, "_canceloperation" TSRMLS_CC);
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
				phalcon_step_out_entry();
				RETURN_FALSE;
			}
		}
	}
	phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=631");
	//$generator
	PHALCON_INIT_NULL(v2);
	phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=673");
	//$notNull
	PHALCON_ALLOC_ZVAL(r4);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_getnotnullattributes" TSRMLS_CC);
	PHALCON_CALL_METHOD(r4, this_ptr, "_getnotnullattributes", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r4 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(r4);
	v3 = r4;
	phalcon_debug_assign("$notNull", r4 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=674");
	//$dataTypeNumeric
	PHALCON_ALLOC_ZVAL(r5);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_getdatatypesnumeric" TSRMLS_CC);
	PHALCON_CALL_METHOD(r5, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r5 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(r5);
	v4 = r5;
	phalcon_debug_assign("$dataTypeNumeric", r5 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=675");
	//$notNull
	if (Z_TYPE_P(v3) == IS_ARRAY) { 
		phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=675");
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=676");
		//$error
		PHALCON_ALLOC_ZVAL(v5);
		ZVAL_BOOL(v5, 0);
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=677");
		//$numFields
		PHALCON_ALLOC_ZVAL(r6);
		//$notNull
		p10[0] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r6, "count", 1, p10);
		phalcon_debug_vdump("count > ", r6 TSRMLS_CC);
		if (v6) {
			Z_DELREF_P(v6);
			if (!Z_REFCOUNT_P(v6)) {
				FREE_ZVAL(v6);
			}
		}
		Z_ADDREF_P(r6);
		v6 = r6;
		phalcon_debug_assign("$numFields", r6 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::save (For) File=Library/Phalcon/Model/Base.php Line=678");
		//$i
		PHALCON_ALLOC_ZVAL(v7);
		ZVAL_LONG(v7, 0);
		fs70:
		//$i
		//$numFields
		PHALCON_SMALLER_FUNCTION(r7, v7, v6);
		if (!zend_is_true(r7)) {
			goto fe70;
		}
		phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=678");
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=679");
		//$isNull
		if (!v8) {
			PHALCON_ALLOC_ZVAL(v8);
		} else {
			if (Z_REFCOUNT_P(v8) > 1) {
				SEPARATE_ZVAL(&v8);
			} else {
				if (Z_TYPE_P(v8) != IS_BOOL) {
					FREE_ZVAL(v8);
					PHALCON_ALLOC_ZVAL(v8);
				}
			}
		}
		ZVAL_BOOL(v8, 0);
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=680");
		//$field
		//$i
		//$notNull
		if (!r8) {
			PHALCON_ALLOC_ZVAL(r8);
		} else {
			if (Z_REFCOUNT_P(r8) > 1) {
				{
					zval *orig_ptr = r8;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r8);
						*r8 = *orig_ptr;
						zval_copy_ctor(r8);
						Z_SET_REFCOUNT_P(r8, 1);
						Z_UNSET_ISREF_P(r8);
					}
				}
			} else {
				FREE_ZVAL(r8);
				PHALCON_ALLOC_ZVAL(r8);
			}
		}
		phalcon_array_fetch(r8, v3, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v9) {
			Z_DELREF_P(v9);
			if (!Z_REFCOUNT_P(v9)) {
				FREE_ZVAL(v9);
			}
		}
		Z_ADDREF_P(r8);
		v9 = r8;
		phalcon_debug_assign("$field", r8 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=681");
		//$value
		//$this
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
		//$field
		phalcon_read_property_zval(t3, this_ptr, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t3);
		if (v10) {
			Z_DELREF_P(v10);
			if (!Z_REFCOUNT_P(v10)) {
				FREE_ZVAL(v10);
			}
		}
		Z_ADDREF_P(t3);
		v10 = t3;
		phalcon_debug_assign("$value", t3 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=682");
		//$field
		//$dataTypeNumeric
		eval_int = phalcon_array_isset(v4, v9);
		if (!eval_int) {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=682");
			phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=683");
			//$value
			PHALCON_INIT_NULL(t4);
			PHALCON_IDENTICAL_FUNCTION(r9, v10, t4);
			//$value
			if (!t5) {
				PHALCON_ALLOC_ZVAL(t5);
			} else {
				if (Z_REFCOUNT_P(t5) > 1) {
					SEPARATE_ZVAL(&t5);
				} else {
					if (Z_TYPE_P(t5) != IS_STRING) {
						FREE_ZVAL(t5);
						PHALCON_ALLOC_ZVAL(t5);
					}
				}
			}
			ZVAL_STRING(t5, "", 1);
			PHALCON_IDENTICAL_FUNCTION(r10, v10, t5);
			PHALCON_OR_FUNCTION(r11, r9, r10);
			if (zend_is_true(r11)) {
				phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=683");
				phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=684");
				//$isNull
				if (!v8) {
					PHALCON_ALLOC_ZVAL(v8);
				} else {
					if (Z_REFCOUNT_P(v8) > 1) {
						SEPARATE_ZVAL(&v8);
					} else {
						if (Z_TYPE_P(v8) != IS_BOOL) {
							FREE_ZVAL(v8);
							PHALCON_ALLOC_ZVAL(v8);
						}
					}
				}
				ZVAL_BOOL(v8, 1);
			}
		} else {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=686");
			phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=687");
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
			//$value
			Z_ADDREF_P(v10);
			p11[0] = v10;
			phalcon_debug_param(v10 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r12, "is_numeric", 1, p11);
			phalcon_debug_vdump("is_numeric > ", r12 TSRMLS_CC);
			if (!zend_is_true(r12)) {
				phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=687");
				phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=688");
				//$isNull
				if (!v8) {
					PHALCON_ALLOC_ZVAL(v8);
				} else {
					if (Z_REFCOUNT_P(v8) > 1) {
						SEPARATE_ZVAL(&v8);
					} else {
						if (Z_TYPE_P(v8) != IS_BOOL) {
							FREE_ZVAL(v8);
							PHALCON_ALLOC_ZVAL(v8);
						}
					}
				}
				ZVAL_BOOL(v8, 1);
			}
		}
		phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=691");
		//$isNull
		PHALCON_INIT_TRUE(t6);
		PHALCON_EQUAL_FUNCTION(r13, v8, t6);
		if (zend_is_true(r13)) {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=691");
			phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=692");
			//$exists
			PHALCON_BOOLEAN_NOT_FUNCTION(r14, v0);
			//$field
			if (!t7) {
				PHALCON_ALLOC_ZVAL(t7);
			} else {
				if (Z_REFCOUNT_P(t7) > 1) {
					SEPARATE_ZVAL(&t7);
				} else {
					if (Z_TYPE_P(t7) != IS_STRING) {
						FREE_ZVAL(t7);
						PHALCON_ALLOC_ZVAL(t7);
					}
				}
			}
			ZVAL_STRING(t7, "id", 1);
			PHALCON_EQUAL_FUNCTION(r15, v9, t7);
			PHALCON_AND_FUNCTION(r16, r14, r15);
			if (zend_is_true(r16)) {
				phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=692");
				phalcon_step_over("Phalcon_Model_Base::save (Continue) File=Library/Phalcon/Model/Base.php Line=693");
				goto fi70;
			}
			phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=695");
			//$humanField
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
			if (!p12[0]) {
				PHALCON_ALLOC_ZVAL(p12[0]);
			} else {
				if (Z_REFCOUNT_P(p12[0]) > 1) {
					SEPARATE_ZVAL(&p12[0]);
				} else {
					if (Z_TYPE_P(p12[0]) != IS_STRING) {
						FREE_ZVAL(p12[0]);
						PHALCON_ALLOC_ZVAL(p12[0]);
					}
				}
			}
			ZVAL_STRING(p12[0], "_id", 1);
			if (!p12[1]) {
				PHALCON_ALLOC_ZVAL(p12[1]);
			} else {
				if (Z_REFCOUNT_P(p12[1]) > 1) {
					SEPARATE_ZVAL(&p12[1]);
				} else {
					if (Z_TYPE_P(p12[1]) != IS_STRING) {
						FREE_ZVAL(p12[1]);
						PHALCON_ALLOC_ZVAL(p12[1]);
					}
				}
			}
			ZVAL_STRING(p12[1], "", 1);
			//$field
			p12[2] = v9;
			phalcon_debug_param(v9 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r17, "str_replace", 3, p12);
			phalcon_debug_vdump("str_replace > ", r17 TSRMLS_CC);
			if (v11) {
				Z_DELREF_P(v11);
				if (!Z_REFCOUNT_P(v11)) {
					FREE_ZVAL(v11);
				}
			}
			Z_ADDREF_P(r17);
			v11 = r17;
			phalcon_debug_assign("$humanField", r17 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=696");
			//$message
			if (!i0) {
				PHALCON_ALLOC_ZVAL(i0);
			} else {
				if (Z_REFCOUNT_P(i0) > 1) {
					{
						zval *orig_ptr = i0;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(i0);
							*i0 = *orig_ptr;
							zval_copy_ctor(i0);
							Z_SET_REFCOUNT_P(i0, 1);
							Z_UNSET_ISREF_P(i0);
						}
					}
				} else {
					FREE_ZVAL(i0);
					PHALCON_ALLOC_ZVAL(i0);
				}
			}
			object_init_ex(i0, phalcon_model_message_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
			//$humanField
			if (!r18) {
				PHALCON_ALLOC_ZVAL(r18);
			} else {
				if (Z_REFCOUNT_P(r18) > 1) {
					{
						zval *orig_ptr = r18;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r18);
							*r18 = *orig_ptr;
							zval_copy_ctor(r18);
							Z_SET_REFCOUNT_P(r18, 1);
							Z_UNSET_ISREF_P(r18);
						}
					}
				} else {
					FREE_ZVAL(r18);
					PHALCON_ALLOC_ZVAL(r18);
				}
			}
			phalcon_concat_right(r18, v11, " is required" TSRMLS_CC);
			Z_ADDREF_P(r18);
			p13[0] = r18;
			phalcon_debug_param(r18 TSRMLS_CC);
			//$field
			Z_ADDREF_P(v9);
			p13[1] = v9;
			phalcon_debug_param(v9 TSRMLS_CC);
			if (!p13[2]) {
				PHALCON_ALLOC_ZVAL(p13[2]);
			} else {
				if (Z_REFCOUNT_P(p13[2]) > 1) {
					SEPARATE_ZVAL(&p13[2]);
				} else {
					if (Z_TYPE_P(p13[2]) != IS_STRING) {
						FREE_ZVAL(p13[2]);
						PHALCON_ALLOC_ZVAL(p13[2]);
					}
				}
			}
			ZVAL_STRING(p13[2], "PresenceOf", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 3, p13, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			if (v12) {
				Z_DELREF_P(v12);
				if (!Z_REFCOUNT_P(v12)) {
					FREE_ZVAL(v12);
				}
			}
			Z_ADDREF_P(i0);
			v12 = i0;
			phalcon_debug_assign("$message", i0 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=697");
			//$message
			//$this
			if (!t8) {
				PHALCON_ALLOC_ZVAL(t8);
			} else {
				if (Z_REFCOUNT_P(t8) > 1) {
					{
						zval *orig_ptr = t8;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(t8);
							*t8 = *orig_ptr;
							zval_copy_ctor(t8);
							Z_SET_REFCOUNT_P(t8, 1);
							Z_UNSET_ISREF_P(t8);
						}
					}
				} else {
					FREE_ZVAL(t8);
					PHALCON_ALLOC_ZVAL(t8);
				}
			}
			phalcon_read_property(t8, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t8);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v12, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				{
					zval *orig_ptr = t8;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(t8);
						*t8 = *orig_ptr;
						zval_copy_ctor(t8);
						Z_SET_REFCOUNT_P(t8, 1);
						Z_UNSET_ISREF_P(t8);
					}
				}
				phalcon_array_append(t8, copy TSRMLS_CC);
			}
			//$this
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, t8, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), copy TSRMLS_CC);
			}
			phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=698");
			//$error
			if (!v5) {
				PHALCON_ALLOC_ZVAL(v5);
			} else {
				if (Z_REFCOUNT_P(v5) > 1) {
					SEPARATE_ZVAL(&v5);
				} else {
					if (Z_TYPE_P(v5) != IS_BOOL) {
						FREE_ZVAL(v5);
						PHALCON_ALLOC_ZVAL(v5);
					}
				}
			}
			ZVAL_BOOL(v5, 1);
		}
		fi70:
		//$i
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
		increment_function(v7);
		phalcon_debug_vdump("PreIncrementing $i", v7);
		goto fs70;
		fe70:
		r7 = NULL;
		phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=701");
		//$error
		if (zend_is_true(v5)) {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=701");
			phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=702");
			//$disableEvents
			if (!zend_is_true(v1)) {
				phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=702");
				phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=703");
				//$this
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(p14[0]);
				ZVAL_STRING(p14[0], "onValidationFails", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p14, PHALCON_CALL_DEFAULT);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			}
			phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=705");
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_canceloperation" TSRMLS_CC);
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	}
	phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=711");
	PHALCON_ALLOC_ZVAL(r19);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p16[0]);
	ZVAL_STRING(p16[0], "validation", 1);
	PHALCON_CALL_METHOD_PARAMS(r19, this_ptr, "_callevent", 1, p16, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r19 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (Z_TYPE_P(r19) == IS_BOOL && !Z_BVAL_P(r19)) {
		phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=711");
		phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=712");
		//$disableEvents
		if (!zend_is_true(v1)) {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=712");
			phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=713");
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p17[0]);
			ZVAL_STRING(p17[0], "onValidationFails", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p17, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=715");
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "_canceloperation" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=719");
	//$disableEvents
	if (!zend_is_true(v1)) {
		phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=719");
		phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=722");
		//$exists
		if (!zend_is_true(v0)) {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=722");
			phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=723");
			PHALCON_ALLOC_ZVAL(r20);
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p19[0]);
			ZVAL_STRING(p19[0], "afterValidationOnCreate", 1);
			PHALCON_CALL_METHOD_PARAMS(r20, this_ptr, "_callevent", 1, p19, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r20 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			if (Z_TYPE_P(r20) == IS_BOOL && !Z_BVAL_P(r20)) {
				phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=723");
				phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=724");
				//$this
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_method_call(this_ptr, "_canceloperation" TSRMLS_CC);
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
				phalcon_step_out_entry();
				RETURN_FALSE;
			}
		} else {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=727");
			phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=728");
			PHALCON_ALLOC_ZVAL(r21);
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p21[0]);
			ZVAL_STRING(p21[0], "afterValidationOnUpdate", 1);
			PHALCON_CALL_METHOD_PARAMS(r21, this_ptr, "_callevent", 1, p21, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r21 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			if (Z_TYPE_P(r21) == IS_BOOL && !Z_BVAL_P(r21)) {
				phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=728");
				phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=729");
				//$this
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_method_call(this_ptr, "_canceloperation" TSRMLS_CC);
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
				phalcon_step_out_entry();
				RETURN_FALSE;
			}
		}
		phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=733");
		PHALCON_ALLOC_ZVAL(r22);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p23[0]);
		ZVAL_STRING(p23[0], "afterValidation", 1);
		PHALCON_CALL_METHOD_PARAMS(r22, this_ptr, "_callevent", 1, p23, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r22 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (Z_TYPE_P(r22) == IS_BOOL && !Z_BVAL_P(r22)) {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=733");
			phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=734");
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_canceloperation" TSRMLS_CC);
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
		phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=739");
		PHALCON_ALLOC_ZVAL(r23);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p25[0]);
		ZVAL_STRING(p25[0], "beforeSave", 1);
		PHALCON_CALL_METHOD_PARAMS(r23, this_ptr, "_callevent", 1, p25, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r23 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (Z_TYPE_P(r23) == IS_BOOL && !Z_BVAL_P(r23)) {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=739");
			phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=740");
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_canceloperation" TSRMLS_CC);
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
		phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=743");
		//$exists
		if (zend_is_true(v0)) {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=743");
			phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=744");
			PHALCON_ALLOC_ZVAL(r24);
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p27[0]);
			ZVAL_STRING(p27[0], "beforeUpdate", 1);
			PHALCON_CALL_METHOD_PARAMS(r24, this_ptr, "_callevent", 1, p27, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r24 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			if (Z_TYPE_P(r24) == IS_BOOL && !Z_BVAL_P(r24)) {
				phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=744");
				phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=745");
				//$this
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_method_call(this_ptr, "_canceloperation" TSRMLS_CC);
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
				phalcon_step_out_entry();
				RETURN_FALSE;
			}
		} else {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=748");
			phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=749");
			PHALCON_ALLOC_ZVAL(r25);
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p29[0]);
			ZVAL_STRING(p29[0], "beforeCreate", 1);
			PHALCON_CALL_METHOD_PARAMS(r25, this_ptr, "_callevent", 1, p29, PHALCON_CALL_DEFAULT);
			phalcon_debug_vdump("MethodReturn > ", r25 TSRMLS_CC);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			if (Z_TYPE_P(r25) == IS_BOOL && !Z_BVAL_P(r25)) {
				phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=749");
				phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=750");
				//$this
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_method_call(this_ptr, "_canceloperation" TSRMLS_CC);
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
				phalcon_step_out_entry();
				RETURN_FALSE;
			}
		}
	}
	phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=756");
	//$schema
	PHALCON_ALLOC_ZVAL(r26);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getschema" TSRMLS_CC);
	PHALCON_CALL_METHOD(r26, this_ptr, "getschema", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r26 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v13) {
		Z_DELREF_P(v13);
		if (!Z_REFCOUNT_P(v13)) {
			FREE_ZVAL(v13);
		}
	}
	Z_ADDREF_P(r26);
	v13 = r26;
	phalcon_debug_assign("$schema", r26 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=757");
	//$source
	PHALCON_ALLOC_ZVAL(r27);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "getsource" TSRMLS_CC);
	PHALCON_CALL_METHOD(r27, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r27 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v14) {
		Z_DELREF_P(v14);
		if (!Z_REFCOUNT_P(v14)) {
			FREE_ZVAL(v14);
		}
	}
	Z_ADDREF_P(r27);
	v14 = r27;
	phalcon_debug_assign("$source", r27 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=759");
	//$schema
	if (zend_is_true(v13)) {
		phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=759");
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=760");
		//$table
		//$schema
		//$source
		PHALCON_ALLOC_ZVAL(r28);
		phalcon_concat_vboth(r28, v13, ".", v14 TSRMLS_CC);
		if (v15) {
			Z_DELREF_P(v15);
			if (!Z_REFCOUNT_P(v15)) {
				FREE_ZVAL(v15);
			}
		}
		Z_ADDREF_P(r28);
		v15 = r28;
		phalcon_debug_assign("$table", r28 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=761");
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=762");
		//$table
		//$source
		if (v15) {
			Z_DELREF_P(v15);
			if (!Z_REFCOUNT_P(v15)) {
				FREE_ZVAL(v15);
			}
		}
		Z_ADDREF_P(v14);
		v15 = v14;
		phalcon_debug_assign("$table", v14 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=765");
	//$connection
	//$this
	PHALCON_ALLOC_ZVAL(t9);
	phalcon_read_property(t9, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t9);
	if (v16) {
		Z_DELREF_P(v16);
		if (!Z_REFCOUNT_P(v16)) {
			FREE_ZVAL(v16);
		}
	}
	Z_ADDREF_P(t9);
	v16 = t9;
	phalcon_debug_assign("$connection", t9 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=766");
	//$dataType
	PHALCON_ALLOC_ZVAL(r29);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_getdatatypes" TSRMLS_CC);
	PHALCON_CALL_METHOD(r29, this_ptr, "_getdatatypes", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r29 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v17) {
		Z_DELREF_P(v17);
		if (!Z_REFCOUNT_P(v17)) {
			FREE_ZVAL(v17);
		}
	}
	Z_ADDREF_P(r29);
	v17 = r29;
	phalcon_debug_assign("$dataType", r29 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=767");
	//$primaryKeys
	PHALCON_ALLOC_ZVAL(r30);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_getprimarykeyattributes" TSRMLS_CC);
	PHALCON_CALL_METHOD(r30, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r30 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v18) {
		Z_DELREF_P(v18);
		if (!Z_REFCOUNT_P(v18)) {
			FREE_ZVAL(v18);
		}
	}
	Z_ADDREF_P(r30);
	v18 = r30;
	phalcon_debug_assign("$primaryKeys", r30 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=768");
	//$dataTypeNumeric
	PHALCON_ALLOC_ZVAL(r31);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_getdatatypesnumeric" TSRMLS_CC);
	PHALCON_CALL_METHOD(r31, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r31 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(r31);
	v4 = r31;
	phalcon_debug_assign("$dataTypeNumeric", r31 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=770");
	//$exists
	if (zend_is_true(v0)) {
		phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=770");
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=771");
		//$fields
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		if (v19) {
			Z_DELREF_P(v19);
			if (!Z_REFCOUNT_P(v19)) {
				FREE_ZVAL(v19);
			}
		}
		Z_ADDREF_P(a1);
		v19 = a1;
		phalcon_debug_assign("$fields", a1 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=772");
		//$values
		PHALCON_ALLOC_ZVAL(a2);
		array_init(a2);
		if (v20) {
			Z_DELREF_P(v20);
			if (!Z_REFCOUNT_P(v20)) {
				FREE_ZVAL(v20);
			}
		}
		Z_ADDREF_P(a2);
		v20 = a2;
		phalcon_debug_assign("$values", a2 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=773");
		//$nonPrimary
		PHALCON_ALLOC_ZVAL(r32);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "_getnonprimarykeyattributes" TSRMLS_CC);
		PHALCON_CALL_METHOD(r32, this_ptr, "_getnonprimarykeyattributes", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r32 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (v21) {
			Z_DELREF_P(v21);
			if (!Z_REFCOUNT_P(v21)) {
				FREE_ZVAL(v21);
			}
		}
		Z_ADDREF_P(r32);
		v21 = r32;
		phalcon_debug_assign("$nonPrimary", r32 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::save (Foreach) File=Library/Phalcon/Model/Base.php Line=774");
		//$nonPrimary
		//$field
		FOREACH_V(v21, ac0, fes71, fee71, ah0, hp0, v9)
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=774");
			phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=775");
			//$field
			//$fields
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v9, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				{
					zval *orig_ptr = v19;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(v19);
						*v19 = *orig_ptr;
						zval_copy_ctor(v19);
						Z_SET_REFCOUNT_P(v19, 1);
						Z_UNSET_ISREF_P(v19);
					}
				}
				phalcon_array_append(v19, copy TSRMLS_CC);
			}
			phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=776");
			//$value
			//$this
			if (!t10) {
				PHALCON_ALLOC_ZVAL(t10);
			} else {
				if (Z_REFCOUNT_P(t10) > 1) {
					{
						zval *orig_ptr = t10;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(t10);
							*t10 = *orig_ptr;
							zval_copy_ctor(t10);
							Z_SET_REFCOUNT_P(t10, 1);
							Z_UNSET_ISREF_P(t10);
						}
					}
				} else {
					FREE_ZVAL(t10);
					PHALCON_ALLOC_ZVAL(t10);
				}
			}
			//$field
			phalcon_read_property_zval(t10, this_ptr, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t10);
			if (v10) {
				Z_DELREF_P(v10);
				if (!Z_REFCOUNT_P(v10)) {
					FREE_ZVAL(v10);
				}
			}
			Z_ADDREF_P(t10);
			v10 = t10;
			phalcon_debug_assign("$value", t10 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=777");
			//$value
			if (Z_TYPE_P(v10) == IS_OBJECT) {
				phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=777");
				phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=778");
				//$value
				if (!r33) {
					PHALCON_ALLOC_ZVAL(r33);
				} else {
					if (Z_REFCOUNT_P(r33) > 1){ 
						{
							zval *orig_ptr = r33;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r33);
								*r33 = *orig_ptr;
								zval_copy_ctor(r33);
								Z_SET_REFCOUNT_P(r33, 1);
								Z_UNSET_ISREF_P(r33);
							}
						}
					}
				}
				phalcon_instance_of(r33, v10, phalcon_db_rawvalue_class_entry TSRMLS_CC);
				if (zend_is_true(r33)) {
					phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=778");
					phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=779");
					if (!r34) {
						PHALCON_ALLOC_ZVAL(r34);
					} else {
						if (Z_REFCOUNT_P(r34) > 1) {
							{
								zval *orig_ptr = r34;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r34);
									*r34 = *orig_ptr;
									zval_copy_ctor(r34);
									Z_SET_REFCOUNT_P(r34, 1);
									Z_UNSET_ISREF_P(r34);
								}
							}
						} else {
							FREE_ZVAL(r34);
							PHALCON_ALLOC_ZVAL(r34);
						}
					}
					//$value
					phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
					phalcon_debug_method_call(v10, "getvalue" TSRMLS_CC);
					PHALCON_CALL_METHOD(r34, v10, "getvalue", PHALCON_CALL_DEFAULT);
					phalcon_debug_vdump("MethodReturn > ", r34 TSRMLS_CC);
					phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
					//$values
					{
						zval *copy;
						ALLOC_ZVAL(copy);
						ZVAL_ZVAL(copy, r34, 1, 0);
						Z_SET_REFCOUNT_P(copy, 1);
						{
							zval *orig_ptr = v20;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(v20);
								*v20 = *orig_ptr;
								zval_copy_ctor(v20);
								Z_SET_REFCOUNT_P(v20, 1);
								Z_UNSET_ISREF_P(v20);
							}
						}
						phalcon_array_append(v20, copy TSRMLS_CC);
					}
				} else {
					phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=780");
					phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=781");
					//$this
					if (!t11) {
						PHALCON_ALLOC_ZVAL(t11);
					} else {
						if (Z_REFCOUNT_P(t11) > 1) {
							{
								zval *orig_ptr = t11;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(t11);
									*t11 = *orig_ptr;
									zval_copy_ctor(t11);
									Z_SET_REFCOUNT_P(t11, 1);
									Z_UNSET_ISREF_P(t11);
								}
							}
						} else {
							FREE_ZVAL(t11);
							PHALCON_ALLOC_ZVAL(t11);
						}
					}
					//$field
					phalcon_read_property_zval(t11, this_ptr, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
					zval_copy_ctor(t11);
					convert_to_string(t11);
					//$values
					{
						zval *copy;
						ALLOC_ZVAL(copy);
						ZVAL_ZVAL(copy, t11, 1, 0);
						Z_SET_REFCOUNT_P(copy, 1);
						{
							zval *orig_ptr = v20;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(v20);
								*v20 = *orig_ptr;
								zval_copy_ctor(v20);
								Z_SET_REFCOUNT_P(v20, 1);
								Z_UNSET_ISREF_P(v20);
							}
						}
						phalcon_array_append(v20, copy TSRMLS_CC);
					}
				}
			} else {
				phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=783");
				phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=784");
				//$value
				if (!t12) {
					PHALCON_ALLOC_ZVAL(t12);
				} else {
					if (Z_REFCOUNT_P(t12) > 1) {
						SEPARATE_ZVAL(&t12);
					} else {
						if (Z_TYPE_P(t12) != IS_STRING) {
							FREE_ZVAL(t12);
							PHALCON_ALLOC_ZVAL(t12);
						}
					}
				}
				ZVAL_STRING(t12, "", 1);
				PHALCON_IDENTICAL_FUNCTION(r35, v10, t12);
				//$value
				PHALCON_INIT_NULL(t13);
				PHALCON_IDENTICAL_FUNCTION(r36, v10, t13);
				PHALCON_OR_FUNCTION(r37, r35, r36);
				if (zend_is_true(r37)) {
					phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=784");
					phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=785");
					if (!t14) {
						PHALCON_ALLOC_ZVAL(t14);
					} else {
						if (Z_REFCOUNT_P(t14) > 1) {
							SEPARATE_ZVAL(&t14);
						} else {
							if (Z_TYPE_P(t14) != IS_STRING) {
								FREE_ZVAL(t14);
								PHALCON_ALLOC_ZVAL(t14);
							}
						}
					}
					ZVAL_STRING(t14, "NULL", 1);
					//$values
					{
						zval *copy;
						ALLOC_ZVAL(copy);
						ZVAL_ZVAL(copy, t14, 1, 0);
						Z_SET_REFCOUNT_P(copy, 1);
						{
							zval *orig_ptr = v20;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(v20);
								*v20 = *orig_ptr;
								zval_copy_ctor(v20);
								Z_SET_REFCOUNT_P(v20, 1);
								Z_UNSET_ISREF_P(v20);
							}
						}
						phalcon_array_append(v20, copy TSRMLS_CC);
					}
				} else {
					phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=786");
					phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=787");
					//$field
					//$dataTypeNumeric
					eval_int = phalcon_array_isset(v4, v9);
					if (eval_int) {
						phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=787");
						phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=788");
						//$value
						//$values
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, v10, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
							{
								zval *orig_ptr = v20;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(v20);
									*v20 = *orig_ptr;
									zval_copy_ctor(v20);
									Z_SET_REFCOUNT_P(v20, 1);
									Z_UNSET_ISREF_P(v20);
								}
							}
							phalcon_array_append(v20, copy TSRMLS_CC);
						}
					} else {
						phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=789");
						phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=790");
						//$field
						//$dataType
						if (!r38) {
							PHALCON_ALLOC_ZVAL(r38);
						} else {
							if (Z_REFCOUNT_P(r38) > 1) {
								{
									zval *orig_ptr = r38;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(r38);
										*r38 = *orig_ptr;
										zval_copy_ctor(r38);
										Z_SET_REFCOUNT_P(r38, 1);
										Z_UNSET_ISREF_P(r38);
									}
								}
							} else {
								FREE_ZVAL(r38);
								PHALCON_ALLOC_ZVAL(r38);
							}
						}
						phalcon_array_fetch(r38, v17, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
						if (phalcon_compare_strict_string(r38, "date")) {
							phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=790");
							phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=791");
							if (!r39) {
								PHALCON_ALLOC_ZVAL(r39);
							} else {
								if (Z_REFCOUNT_P(r39) > 1) {
									{
										zval *orig_ptr = r39;
										if (Z_REFCOUNT_P(orig_ptr) > 1) {
											Z_DELREF_P(orig_ptr);
											ALLOC_ZVAL(r39);
											*r39 = *orig_ptr;
											zval_copy_ctor(r39);
											Z_SET_REFCOUNT_P(r39, 1);
											Z_UNSET_ISREF_P(r39);
										}
									}
								} else {
									FREE_ZVAL(r39);
									PHALCON_ALLOC_ZVAL(r39);
								}
							}
							//$connection
							phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
							phalcon_debug_method_call(v16, "getdateusingformat" TSRMLS_CC);
							//$value
							Z_ADDREF_P(v10);
							p38[0] = v10;
							phalcon_debug_param(v10 TSRMLS_CC);
							PHALCON_CALL_METHOD_PARAMS(r39, v16, "getdateusingformat", 1, p38, PHALCON_CALL_DEFAULT);
							phalcon_debug_vdump("MethodReturn > ", r39 TSRMLS_CC);
							phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
							//$values
							{
								zval *copy;
								ALLOC_ZVAL(copy);
								ZVAL_ZVAL(copy, r39, 1, 0);
								Z_SET_REFCOUNT_P(copy, 1);
								{
									zval *orig_ptr = v20;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(v20);
										*v20 = *orig_ptr;
										zval_copy_ctor(v20);
										Z_SET_REFCOUNT_P(v20, 1);
										Z_UNSET_ISREF_P(v20);
									}
								}
								phalcon_array_append(v20, copy TSRMLS_CC);
							}
						} else {
							phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=792");
							phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=793");
							//$value
							if (!r40) {
								PHALCON_ALLOC_ZVAL(r40);
							} else {
								if (Z_REFCOUNT_P(r40) > 1) {
									{
										zval *orig_ptr = r40;
										if (Z_REFCOUNT_P(orig_ptr) > 1) {
											Z_DELREF_P(orig_ptr);
											ALLOC_ZVAL(r40);
											*r40 = *orig_ptr;
											zval_copy_ctor(r40);
											Z_SET_REFCOUNT_P(r40, 1);
											Z_UNSET_ISREF_P(r40);
										}
									}
								} else {
									FREE_ZVAL(r40);
									PHALCON_ALLOC_ZVAL(r40);
								}
							}
							phalcon_concat_both(r40,  "'", v10, "'" TSRMLS_CC);
							//$values
							{
								zval *copy;
								ALLOC_ZVAL(copy);
								ZVAL_ZVAL(copy, r40, 1, 0);
								Z_SET_REFCOUNT_P(copy, 1);
								{
									zval *orig_ptr = v20;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(v20);
										*v20 = *orig_ptr;
										zval_copy_ctor(v20);
										Z_SET_REFCOUNT_P(v20, 1);
										Z_UNSET_ISREF_P(v20);
									}
								}
								phalcon_array_append(v20, copy TSRMLS_CC);
							}
						}
					}
				}
			}
		END_FOREACH(ac0, fes71, fee71, ah0, hp0);
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=799");
		//$success
		PHALCON_ALLOC_ZVAL(r41);
		//$connection
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(v16, "update" TSRMLS_CC);
		//$table
		Z_ADDREF_P(v15);
		p39[0] = v15;
		phalcon_debug_param(v15 TSRMLS_CC);
		//$fields
		Z_ADDREF_P(v19);
		p39[1] = v19;
		phalcon_debug_param(v19 TSRMLS_CC);
		//$values
		Z_ADDREF_P(v20);
		p39[2] = v20;
		phalcon_debug_param(v20 TSRMLS_CC);
		//$this
		PHALCON_ALLOC_ZVAL(t15);
		phalcon_read_property(t15, this_ptr, "_uniqueKey", sizeof("_uniqueKey")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t15);
		Z_ADDREF_P(t15);
		p39[3] = t15;
		phalcon_debug_param(t15 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r41, v16, "update", 4, p39, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r41 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (v22) {
			Z_DELREF_P(v22);
			if (!Z_REFCOUNT_P(v22)) {
				FREE_ZVAL(v22);
			}
		}
		Z_ADDREF_P(r41);
		v22 = r41;
		phalcon_debug_assign("$success", r41 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=800");
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=801");
		//$fields
		PHALCON_ALLOC_ZVAL(a3);
		array_init(a3);
		if (v19) {
			Z_DELREF_P(v19);
			if (!Z_REFCOUNT_P(v19)) {
				FREE_ZVAL(v19);
			}
		}
		Z_ADDREF_P(a3);
		v19 = a3;
		phalcon_debug_assign("$fields", a3 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=802");
		//$values
		PHALCON_ALLOC_ZVAL(a4);
		array_init(a4);
		if (v20) {
			Z_DELREF_P(v20);
			if (!Z_REFCOUNT_P(v20)) {
				FREE_ZVAL(v20);
			}
		}
		Z_ADDREF_P(a4);
		v20 = a4;
		phalcon_debug_assign("$values", a4 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=803");
		//$attributes
		PHALCON_ALLOC_ZVAL(r42);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "_getattributes" TSRMLS_CC);
		PHALCON_CALL_METHOD(r42, this_ptr, "_getattributes", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r42 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (v23) {
			Z_DELREF_P(v23);
			if (!Z_REFCOUNT_P(v23)) {
				FREE_ZVAL(v23);
			}
		}
		Z_ADDREF_P(r42);
		v23 = r42;
		phalcon_debug_assign("$attributes", r42 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::save (Foreach) File=Library/Phalcon/Model/Base.php Line=804");
		//$attributes
		//$field
		FOREACH_V(v23, ac1, fes72, fee72, ah1, hp1, v9)
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=804");
			phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=805");
			//$field
			if (!phalcon_compare_strict_string(v9, "id")) {
				phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=805");
				phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=806");
				//$field
				//$fields
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v9, 1, 0);
					Z_SET_REFCOUNT_P(copy, 1);
					{
						zval *orig_ptr = v19;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(v19);
							*v19 = *orig_ptr;
							zval_copy_ctor(v19);
							Z_SET_REFCOUNT_P(v19, 1);
							Z_UNSET_ISREF_P(v19);
						}
					}
					phalcon_array_append(v19, copy TSRMLS_CC);
				}
				phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=807");
				//$value
				//$this
				if (!t16) {
					PHALCON_ALLOC_ZVAL(t16);
				} else {
					if (Z_REFCOUNT_P(t16) > 1) {
						{
							zval *orig_ptr = t16;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(t16);
								*t16 = *orig_ptr;
								zval_copy_ctor(t16);
								Z_SET_REFCOUNT_P(t16, 1);
								Z_UNSET_ISREF_P(t16);
							}
						}
					} else {
						FREE_ZVAL(t16);
						PHALCON_ALLOC_ZVAL(t16);
					}
				}
				//$field
				phalcon_read_property_zval(t16, this_ptr, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t16);
				if (v10) {
					Z_DELREF_P(v10);
					if (!Z_REFCOUNT_P(v10)) {
						FREE_ZVAL(v10);
					}
				}
				Z_ADDREF_P(t16);
				v10 = t16;
				phalcon_debug_assign("$value", t16 TSRMLS_CC);
				phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=808");
				//$value
				if (Z_TYPE_P(v10) == IS_OBJECT) {
					phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=808");
					phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=809");
					//$value
					if (!r43) {
						PHALCON_ALLOC_ZVAL(r43);
					} else {
						if (Z_REFCOUNT_P(r43) > 1){ 
							{
								zval *orig_ptr = r43;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r43);
									*r43 = *orig_ptr;
									zval_copy_ctor(r43);
									Z_SET_REFCOUNT_P(r43, 1);
									Z_UNSET_ISREF_P(r43);
								}
							}
						}
					}
					phalcon_instance_of(r43, v10, phalcon_db_rawvalue_class_entry TSRMLS_CC);
					if (zend_is_true(r43)) {
						phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=809");
						phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=810");
						if (!r44) {
							PHALCON_ALLOC_ZVAL(r44);
						} else {
							if (Z_REFCOUNT_P(r44) > 1) {
								{
									zval *orig_ptr = r44;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(r44);
										*r44 = *orig_ptr;
										zval_copy_ctor(r44);
										Z_SET_REFCOUNT_P(r44, 1);
										Z_UNSET_ISREF_P(r44);
									}
								}
							} else {
								FREE_ZVAL(r44);
								PHALCON_ALLOC_ZVAL(r44);
							}
						}
						//$value
						phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
						phalcon_debug_method_call(v10, "getvalue" TSRMLS_CC);
						PHALCON_CALL_METHOD(r44, v10, "getvalue", PHALCON_CALL_DEFAULT);
						phalcon_debug_vdump("MethodReturn > ", r44 TSRMLS_CC);
						phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
						//$values
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, r44, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
							{
								zval *orig_ptr = v20;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(v20);
									*v20 = *orig_ptr;
									zval_copy_ctor(v20);
									Z_SET_REFCOUNT_P(v20, 1);
									Z_UNSET_ISREF_P(v20);
								}
							}
							phalcon_array_append(v20, copy TSRMLS_CC);
						}
					} else {
						phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=811");
						phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=812");
						//$value
						convert_to_string(v10);
						//$values
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, v10, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
							{
								zval *orig_ptr = v20;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(v20);
									*v20 = *orig_ptr;
									zval_copy_ctor(v20);
									Z_SET_REFCOUNT_P(v20, 1);
									Z_UNSET_ISREF_P(v20);
								}
							}
							phalcon_array_append(v20, copy TSRMLS_CC);
						}
					}
				} else {
					phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=814");
					phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=815");
					//$value
					if (!t17) {
						PHALCON_ALLOC_ZVAL(t17);
					} else {
						if (Z_REFCOUNT_P(t17) > 1) {
							SEPARATE_ZVAL(&t17);
						} else {
							if (Z_TYPE_P(t17) != IS_STRING) {
								FREE_ZVAL(t17);
								PHALCON_ALLOC_ZVAL(t17);
							}
						}
					}
					ZVAL_STRING(t17, "", 1);
					PHALCON_IDENTICAL_FUNCTION(r45, v10, t17);
					//$value
					PHALCON_INIT_NULL(t18);
					PHALCON_IDENTICAL_FUNCTION(r46, v10, t18);
					PHALCON_OR_FUNCTION(r47, r45, r46);
					if (zend_is_true(r47)) {
						phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=815");
						phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=816");
						if (!t19) {
							PHALCON_ALLOC_ZVAL(t19);
						} else {
							if (Z_REFCOUNT_P(t19) > 1) {
								SEPARATE_ZVAL(&t19);
							} else {
								if (Z_TYPE_P(t19) != IS_STRING) {
									FREE_ZVAL(t19);
									PHALCON_ALLOC_ZVAL(t19);
								}
							}
						}
						ZVAL_STRING(t19, "NULL", 1);
						//$values
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, t19, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
							{
								zval *orig_ptr = v20;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(v20);
									*v20 = *orig_ptr;
									zval_copy_ctor(v20);
									Z_SET_REFCOUNT_P(v20, 1);
									Z_UNSET_ISREF_P(v20);
								}
							}
							phalcon_array_append(v20, copy TSRMLS_CC);
						}
					} else {
						phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=817");
						phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=818");
						//$field
						//$dataTypeNumeric
						eval_int = phalcon_array_isset(v4, v9);
						if (eval_int) {
							phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=818");
							phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=819");
							//$value
							//$values
							{
								zval *copy;
								ALLOC_ZVAL(copy);
								ZVAL_ZVAL(copy, v10, 1, 0);
								Z_SET_REFCOUNT_P(copy, 1);
								{
									zval *orig_ptr = v20;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(v20);
										*v20 = *orig_ptr;
										zval_copy_ctor(v20);
										Z_SET_REFCOUNT_P(v20, 1);
										Z_UNSET_ISREF_P(v20);
									}
								}
								phalcon_array_append(v20, copy TSRMLS_CC);
							}
						} else {
							phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=820");
							phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=821");
							//$field
							//$dataType
							if (!r48) {
								PHALCON_ALLOC_ZVAL(r48);
							} else {
								if (Z_REFCOUNT_P(r48) > 1) {
									{
										zval *orig_ptr = r48;
										if (Z_REFCOUNT_P(orig_ptr) > 1) {
											Z_DELREF_P(orig_ptr);
											ALLOC_ZVAL(r48);
											*r48 = *orig_ptr;
											zval_copy_ctor(r48);
											Z_SET_REFCOUNT_P(r48, 1);
											Z_UNSET_ISREF_P(r48);
										}
									}
								} else {
									FREE_ZVAL(r48);
									PHALCON_ALLOC_ZVAL(r48);
								}
							}
							phalcon_array_fetch(r48, v17, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
							if (phalcon_compare_strict_string(r48, "date")) {
								phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=821");
								phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=822");
								if (!r49) {
									PHALCON_ALLOC_ZVAL(r49);
								} else {
									if (Z_REFCOUNT_P(r49) > 1) {
										{
											zval *orig_ptr = r49;
											if (Z_REFCOUNT_P(orig_ptr) > 1) {
												Z_DELREF_P(orig_ptr);
												ALLOC_ZVAL(r49);
												*r49 = *orig_ptr;
												zval_copy_ctor(r49);
												Z_SET_REFCOUNT_P(r49, 1);
												Z_UNSET_ISREF_P(r49);
											}
										}
									} else {
										FREE_ZVAL(r49);
										PHALCON_ALLOC_ZVAL(r49);
									}
								}
								//$this
								if (!t20) {
									PHALCON_ALLOC_ZVAL(t20);
								} else {
									if (Z_REFCOUNT_P(t20) > 1) {
										{
											zval *orig_ptr = t20;
											if (Z_REFCOUNT_P(orig_ptr) > 1) {
												Z_DELREF_P(orig_ptr);
												ALLOC_ZVAL(t20);
												*t20 = *orig_ptr;
												zval_copy_ctor(t20);
												Z_SET_REFCOUNT_P(t20, 1);
												Z_UNSET_ISREF_P(t20);
											}
										}
									} else {
										FREE_ZVAL(t20);
										PHALCON_ALLOC_ZVAL(t20);
									}
								}
								phalcon_read_property(t20, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
								zval_copy_ctor(t20);
								phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
								phalcon_debug_method_call(t20, "getdateusingformat" TSRMLS_CC);
								//$value
								Z_ADDREF_P(v10);
								p42[0] = v10;
								phalcon_debug_param(v10 TSRMLS_CC);
								PHALCON_CALL_METHOD_PARAMS(r49, t20, "getdateusingformat", 1, p42, PHALCON_CALL_DEFAULT);
								phalcon_debug_vdump("MethodReturn > ", r49 TSRMLS_CC);
								phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
								//$values
								{
									zval *copy;
									ALLOC_ZVAL(copy);
									ZVAL_ZVAL(copy, r49, 1, 0);
									Z_SET_REFCOUNT_P(copy, 1);
									{
										zval *orig_ptr = v20;
										if (Z_REFCOUNT_P(orig_ptr) > 1) {
											Z_DELREF_P(orig_ptr);
											ALLOC_ZVAL(v20);
											*v20 = *orig_ptr;
											zval_copy_ctor(v20);
											Z_SET_REFCOUNT_P(v20, 1);
											Z_UNSET_ISREF_P(v20);
										}
									}
									phalcon_array_append(v20, copy TSRMLS_CC);
								}
							} else {
								phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=823");
								phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=824");
								//$value
								if (!r50) {
									PHALCON_ALLOC_ZVAL(r50);
								} else {
									if (Z_REFCOUNT_P(r50) > 1) {
										{
											zval *orig_ptr = r50;
											if (Z_REFCOUNT_P(orig_ptr) > 1) {
												Z_DELREF_P(orig_ptr);
												ALLOC_ZVAL(r50);
												*r50 = *orig_ptr;
												zval_copy_ctor(r50);
												Z_SET_REFCOUNT_P(r50, 1);
												Z_UNSET_ISREF_P(r50);
											}
										}
									} else {
										FREE_ZVAL(r50);
										PHALCON_ALLOC_ZVAL(r50);
									}
								}
								phalcon_concat_both(r50,  "'", v10, "'" TSRMLS_CC);
								//$values
								{
									zval *copy;
									ALLOC_ZVAL(copy);
									ZVAL_ZVAL(copy, r50, 1, 0);
									Z_SET_REFCOUNT_P(copy, 1);
									{
										zval *orig_ptr = v20;
										if (Z_REFCOUNT_P(orig_ptr) > 1) {
											Z_DELREF_P(orig_ptr);
											ALLOC_ZVAL(v20);
											*v20 = *orig_ptr;
											zval_copy_ctor(v20);
											Z_SET_REFCOUNT_P(v20, 1);
											Z_UNSET_ISREF_P(v20);
										}
									}
									phalcon_array_append(v20, copy TSRMLS_CC);
								}
							}
						}
					}
				}
			}
		END_FOREACH(ac1, fes72, fee72, ah1, hp1);
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=831");
		//$sequenceName
		PHALCON_ALLOC_ZVAL(v24);
		ZVAL_STRING(v24, "", 0);
		phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=863");
		//$this
		eval_int = phalcon_isset_property(this_ptr, "id", strlen("id") TSRMLS_CC);
		if (eval_int) {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=863");
			phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=864");
			PHALCON_ALLOC_ZVAL(r51);
			//$this
			PHALCON_ALLOC_ZVAL(t21);
			phalcon_read_property(t21, this_ptr, "id", sizeof("id")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t21);
			Z_ADDREF_P(t21);
			p43[0] = t21;
			phalcon_debug_param(t21 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r51, "is_null", 1, p43);
			phalcon_debug_vdump("is_null > ", r51 TSRMLS_CC);
			//$this
			PHALCON_ALLOC_ZVAL(t22);
			phalcon_read_property(t22, this_ptr, "id", sizeof("id")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t22);
			PHALCON_ALLOC_ZVAL(t23);
			ZVAL_STRING(t23, "", 1);
			PHALCON_IDENTICAL_FUNCTION(r52, t22, t23);
			PHALCON_OR_FUNCTION(r53, r51, r52);
			if (zend_is_true(r53)) {
				phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=864");
				phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=865");
				//$this
				phalcon_update_property_string(this_ptr, "id", strlen("id"), "null" TSRMLS_CC);
			}
			phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=867");
			PHALCON_ALLOC_ZVAL(t24);
			ZVAL_STRING(t24, "id", 1);
			//$fields
			{
				zval *orig_ptr = v19;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v19);
					*v19 = *orig_ptr;
					zval_copy_ctor(v19);
					Z_SET_REFCOUNT_P(v19, 1);
					Z_UNSET_ISREF_P(v19);
				}
			}
			phalcon_array_append(v19, t24 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=868");
			//$this
			PHALCON_ALLOC_ZVAL(t25);
			phalcon_read_property(t25, this_ptr, "id", sizeof("id")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t25);
			//$values
			{
				zval *orig_ptr = v20;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v20);
					*v20 = *orig_ptr;
					zval_copy_ctor(v20);
					Z_SET_REFCOUNT_P(v20, 1);
					Z_UNSET_ISREF_P(v20);
				}
			}
			phalcon_array_append(v20, t25 TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Model_Base::save (Assignment) File=Library/Phalcon/Model/Base.php Line=870");
		//$success
		PHALCON_ALLOC_ZVAL(r54);
		//$this
		PHALCON_ALLOC_ZVAL(t26);
		phalcon_read_property(t26, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t26);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(t26, "insert" TSRMLS_CC);
		//$table
		Z_ADDREF_P(v15);
		p44[0] = v15;
		phalcon_debug_param(v15 TSRMLS_CC);
		//$values
		Z_ADDREF_P(v20);
		p44[1] = v20;
		phalcon_debug_param(v20 TSRMLS_CC);
		//$fields
		Z_ADDREF_P(v19);
		p44[2] = v19;
		phalcon_debug_param(v19 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r54, t26, "insert", 3, p44, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r54 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (v22) {
			Z_DELREF_P(v22);
			if (!Z_REFCOUNT_P(v22)) {
				FREE_ZVAL(v22);
			}
		}
		Z_ADDREF_P(r54);
		v22 = r54;
		phalcon_debug_assign("$success", r54 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=872");
	PHALCON_ALLOC_ZVAL(r55);
	//$connection
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(v16, "isundertransaction" TSRMLS_CC);
	PHALCON_CALL_METHOD(r55, v16, "isundertransaction", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r55 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (!zend_is_true(r55)) {
		phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=872");
		phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=873");
		PHALCON_ALLOC_ZVAL(r56);
		//$connection
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(v16, "gethaveautocommit" TSRMLS_CC);
		PHALCON_CALL_METHOD(r56, v16, "gethaveautocommit", PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r56 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (zend_is_true(r56)) {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=873");
			phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=874");
			//$connection
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(v16, "commit" TSRMLS_CC);
			PHALCON_CALL_METHOD_NORETURN(v16, "commit", PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		}
	}
	phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=877");
	//$success
	if (zend_is_true(v22)) {
		phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=877");
		phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=878");
		//$exists
		if (zend_is_true(v0)) {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=878");
			phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=879");
			//$disableEvents
			if (!zend_is_true(v1)) {
				phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=879");
				phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=880");
				//$this
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(p48[0]);
				ZVAL_STRING(p48[0], "afterUpdate", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p48, PHALCON_CALL_DEFAULT);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			}
		} else {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=882");
			phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=899");
			//$disableEvents
			if (!zend_is_true(v1)) {
				phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=899");
				phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=900");
				//$this
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
				phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(p49[0]);
				ZVAL_STRING(p49[0], "afterCreate", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p49, PHALCON_CALL_DEFAULT);
				phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			}
		}
		phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=903");
		//$disableEvents
		if (!zend_is_true(v1)) {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=903");
			phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=904");
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p50[0]);
			ZVAL_STRING(p50[0], "afterSave", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p50, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		}
		//$success
		phalcon_debug_vdump("Returning > ", v22 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(v22) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v22);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v22);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=907");
		phalcon_step_over("Phalcon_Model_Base::save (If) File=Library/Phalcon/Model/Base.php Line=908");
		//$disableEvents
		if (!zend_is_true(v1)) {
			phalcon_step_over("Phalcon_Model_Base::save (Block) File=Library/Phalcon/Model/Base.php Line=908");
			phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=909");
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p51[0]);
			ZVAL_STRING(p51[0], "notSave", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p51, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		}
		phalcon_step_over("Phalcon_Model_Base::save (MethodCall) File=Library/Phalcon/Model/Base.php Line=911");
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "_canceloperation" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_FALSE;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Model_Base::save (Method) File=Library/Phalcon/Model/Base.php Line=916");
}

PHP_METHOD(Phalcon_Model_Base, delete){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *a0 = NULL;
	zval *ac0 = NULL;
	zval *p2[] = { NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL }, *p5[] = { NULL, NULL }, *p6[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	phalcon_step_into_entry("Phalcon_Model_Base", "delete", 0);
	phalcon_step_over("Phalcon_Model_Base::delete (MethodCall) File=Library/Phalcon/Model/Base.php Line=918");
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_connect" TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::delete (If) File=Library/Phalcon/Model/Base.php Line=919");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Model_Base::delete (Block) File=Library/Phalcon/Model/Base.php Line=919");
		phalcon_step_over("Phalcon_Model_Base::delete (Assignment) File=Library/Phalcon/Model/Base.php Line=920");
		//$table
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		//$this
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_concat_vboth(r0, t1, ".", t2 TSRMLS_CC);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(r0);
		v0 = r0;
		phalcon_debug_assign("$table", r0 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Model_Base::delete (Block) File=Library/Phalcon/Model/Base.php Line=921");
		phalcon_step_over("Phalcon_Model_Base::delete (Assignment) File=Library/Phalcon/Model/Base.php Line=922");
		//$table
		//$this
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t3);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(t3);
		v0 = t3;
		phalcon_debug_assign("$table", t3 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Base::delete (Assignment) File=Library/Phalcon/Model/Base.php Line=925");
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_base_class_entry, "OP_DELETE");
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t4, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_operationMade", strlen("_operationMade"), copy TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Base::delete (Assignment) File=Library/Phalcon/Model/Base.php Line=927");
	//$primaryKeys
	PHALCON_ALLOC_ZVAL(r1);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "_getprimarykeyattributes" TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r1);
	v1 = r1;
	phalcon_debug_assign("$primaryKeys", r1 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::delete (If) File=Library/Phalcon/Model/Base.php Line=928");
	PHALCON_ALLOC_ZVAL(r2);
	//$primaryKeys
	p2[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r2, "count", 1, p2);
	phalcon_debug_vdump("count > ", r2 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t5);
	ZVAL_LONG(t5, 1);
	PHALCON_EQUAL_FUNCTION(r3, r2, t5);
	if (zend_is_true(r3)) {
		phalcon_step_over("Phalcon_Model_Base::delete (Block) File=Library/Phalcon/Model/Base.php Line=928");
		phalcon_step_over("Phalcon_Model_Base::delete (Assignment) File=Library/Phalcon/Model/Base.php Line=929");
		//$primaryKeyValue
		//$this
		PHALCON_ALLOC_ZVAL(t6);
		//$primaryKeys
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_array_fetch_long(r4, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_read_property_zval(t6, this_ptr, r4, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t6);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(t6);
		v2 = t6;
		phalcon_debug_assign("$primaryKeyValue", t6 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::delete (Assignment) File=Library/Phalcon/Model/Base.php Line=930");
		//$conditions
		//$primaryKeys
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_array_fetch_long(r6, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		//$primaryKeyValue
		PHALCON_ALLOC_ZVAL(r5);
		phalcon_concat_vboth(r5, r6, " = '", v2 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r7);
		phalcon_concat_right(r7, r5, "'" TSRMLS_CC);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r7);
		v3 = r7;
		phalcon_debug_assign("$conditions", r7 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Model_Base::delete (Block) File=Library/Phalcon/Model/Base.php Line=931");
		phalcon_step_over("Phalcon_Model_Base::delete (Assignment) File=Library/Phalcon/Model/Base.php Line=932");
		//$conditions
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(a0);
		v3 = a0;
		phalcon_debug_assign("$conditions", a0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Model_Base::delete (Foreach) File=Library/Phalcon/Model/Base.php Line=933");
		//$primaryKeys
		//$primaryKey
		FOREACH_V(v1, ac0, fes73, fee73, ah0, hp0, v4)
			phalcon_step_over("Phalcon_Model_Base::delete (Block) File=Library/Phalcon/Model/Base.php Line=933");
			phalcon_step_over("Phalcon_Model_Base::delete (Assignment) File=Library/Phalcon/Model/Base.php Line=934");
			//$primaryKeyValue
			//$this
			if (!t7) {
				PHALCON_ALLOC_ZVAL(t7);
			} else {
				if (Z_REFCOUNT_P(t7) > 1) {
					{
						zval *orig_ptr = t7;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(t7);
							*t7 = *orig_ptr;
							zval_copy_ctor(t7);
							Z_SET_REFCOUNT_P(t7, 1);
							Z_UNSET_ISREF_P(t7);
						}
					}
				} else {
					FREE_ZVAL(t7);
					PHALCON_ALLOC_ZVAL(t7);
				}
			}
			//$primaryKey
			phalcon_read_property_zval(t7, this_ptr, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t7);
			if (v2) {
				Z_DELREF_P(v2);
				if (!Z_REFCOUNT_P(v2)) {
					FREE_ZVAL(v2);
				}
			}
			Z_ADDREF_P(t7);
			v2 = t7;
			phalcon_debug_assign("$primaryKeyValue", t7 TSRMLS_CC);
			phalcon_step_over("Phalcon_Model_Base::delete (Assignment) File=Library/Phalcon/Model/Base.php Line=935");
			//$primaryKey
			//$primaryKeyValue
			if (!r8) {
				PHALCON_ALLOC_ZVAL(r8);
			} else {
				if (Z_REFCOUNT_P(r8) > 1) {
					{
						zval *orig_ptr = r8;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r8);
							*r8 = *orig_ptr;
							zval_copy_ctor(r8);
							Z_SET_REFCOUNT_P(r8, 1);
							Z_UNSET_ISREF_P(r8);
						}
					}
				} else {
					FREE_ZVAL(r8);
					PHALCON_ALLOC_ZVAL(r8);
				}
			}
			phalcon_concat_vboth(r8, v4, " = '", v2 TSRMLS_CC);
			if (!r9) {
				PHALCON_ALLOC_ZVAL(r9);
			} else {
				if (Z_REFCOUNT_P(r9) > 1) {
					{
						zval *orig_ptr = r9;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r9);
							*r9 = *orig_ptr;
							zval_copy_ctor(r9);
							Z_SET_REFCOUNT_P(r9, 1);
							Z_UNSET_ISREF_P(r9);
						}
					}
				} else {
					FREE_ZVAL(r9);
					PHALCON_ALLOC_ZVAL(r9);
				}
			}
			phalcon_concat_right(r9, r8, "'" TSRMLS_CC);
			//$conditions
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r9, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				{
					zval *orig_ptr = v3;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(v3);
						*v3 = *orig_ptr;
						zval_copy_ctor(v3);
						Z_SET_REFCOUNT_P(v3, 1);
						Z_UNSET_ISREF_P(v3);
					}
				}
				phalcon_array_append(v3, copy TSRMLS_CC);
			}
		END_FOREACH(ac0, fes73, fee73, ah0, hp0);
		phalcon_step_over("Phalcon_Model_Base::delete (Assignment) File=Library/Phalcon/Model/Base.php Line=937");
		//$conditions
		PHALCON_ALLOC_ZVAL(r10);
		PHALCON_ALLOC_ZVAL(p3[0]);
		ZVAL_STRING(p3[0], " AND ", 1);
		//$conditions
		p3[1] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r10, "join", 2, p3);
		phalcon_debug_vdump("join > ", r10 TSRMLS_CC);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r10);
		v3 = r10;
		phalcon_debug_assign("$conditions", r10 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Base::delete (Assignment) File=Library/Phalcon/Model/Base.php Line=978");
	//$disableEvents
	t8 = zend_read_static_property(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (v5) {
		Z_DELREF_P(v5);
		if (!Z_REFCOUNT_P(v5)) {
			FREE_ZVAL(v5);
		}
	}
	Z_ADDREF_P(t8);
	v5 = t8;
	phalcon_debug_assign("$disableEvents", t8 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::delete (If) File=Library/Phalcon/Model/Base.php Line=979");
	//$disableEvents
	if (!zend_is_true(v5)) {
		phalcon_step_over("Phalcon_Model_Base::delete (Block) File=Library/Phalcon/Model/Base.php Line=979");
		phalcon_step_over("Phalcon_Model_Base::delete (If) File=Library/Phalcon/Model/Base.php Line=980");
		PHALCON_ALLOC_ZVAL(r11);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p4[0]);
		ZVAL_STRING(p4[0], "beforeDelete", 1);
		PHALCON_CALL_METHOD_PARAMS(r11, this_ptr, "_callevent", 1, p4, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r11 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		if (Z_TYPE_P(r11) == IS_BOOL && !Z_BVAL_P(r11)) {
			phalcon_step_over("Phalcon_Model_Base::delete (Block) File=Library/Phalcon/Model/Base.php Line=980");
			phalcon_debug_vdump("Returning > FALSE", NULL TSRMLS_CC);
			phalcon_step_out_entry();
			RETURN_FALSE;
		}
	}
	phalcon_step_over("Phalcon_Model_Base::delete (Assignment) File=Library/Phalcon/Model/Base.php Line=984");
	//$success
	PHALCON_ALLOC_ZVAL(r12);
	//$this
	PHALCON_ALLOC_ZVAL(t9);
	phalcon_read_property(t9, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t9);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	phalcon_debug_method_call(t9, "delete" TSRMLS_CC);
	//$table
	Z_ADDREF_P(v0);
	p5[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	//$conditions
	Z_ADDREF_P(v3);
	p5[1] = v3;
	phalcon_debug_param(v3 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r12, t9, "delete", 2, p5, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r12 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	if (v6) {
		Z_DELREF_P(v6);
		if (!Z_REFCOUNT_P(v6)) {
			FREE_ZVAL(v6);
		}
	}
	Z_ADDREF_P(r12);
	v6 = r12;
	phalcon_debug_assign("$success", r12 TSRMLS_CC);
	phalcon_step_over("Phalcon_Model_Base::delete (If) File=Library/Phalcon/Model/Base.php Line=985");
	//$success
	if (zend_is_true(v6)) {
		phalcon_step_over("Phalcon_Model_Base::delete (Block) File=Library/Phalcon/Model/Base.php Line=985");
		phalcon_step_over("Phalcon_Model_Base::delete (If) File=Library/Phalcon/Model/Base.php Line=986");
		//$disableEvents
		if (!zend_is_true(v5)) {
			phalcon_step_over("Phalcon_Model_Base::delete (Block) File=Library/Phalcon/Model/Base.php Line=986");
			phalcon_step_over("Phalcon_Model_Base::delete (MethodCall) File=Library/Phalcon/Model/Base.php Line=987");
			//$this
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
			phalcon_debug_method_call(this_ptr, "_callevent" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p6[0]);
			ZVAL_STRING(p6[0], "afterDelete", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p6, PHALCON_CALL_DEFAULT);
			phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		}
	}
	//$success
	phalcon_debug_vdump("Returning > ", v6 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(v6) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v6);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v6);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Model_Base::delete (Method) File=Library/Phalcon/Model/Base.php Line=993");
}

PHP_METHOD(Phalcon_Model_Base, readAttribute){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "readAttribute", 0);
	phalcon_step_over("Phalcon_Model_Base::readAttribute (If) File=Library/Phalcon/Model/Base.php Line=994");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_dump", sizeof("_dump")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Model_Base::readAttribute (Block) File=Library/Phalcon/Model/Base.php Line=994");
		phalcon_step_over("Phalcon_Model_Base::readAttribute (MethodCall) File=Library/Phalcon/Model/Base.php Line=995");
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "_connect" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	}
	//$this
	PHALCON_ALLOC_ZVAL(t1);
	//$attribute
	phalcon_read_property_zval(t1, this_ptr, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
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
	phalcon_step_over("Phalcon_Model_Base::readAttribute (Method) File=Library/Phalcon/Model/Base.php Line=1000");
}

PHP_METHOD(Phalcon_Model_Base, writeAttribute){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Model_Base", "writeAttribute", 0);
	phalcon_step_over("Phalcon_Model_Base::writeAttribute (If) File=Library/Phalcon/Model/Base.php Line=1001");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_dumped", sizeof("_dumped")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Model_Base::writeAttribute (Block) File=Library/Phalcon/Model/Base.php Line=1001");
		phalcon_step_over("Phalcon_Model_Base::writeAttribute (MethodCall) File=Library/Phalcon/Model/Base.php Line=1002");
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "_connect" TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Model_Base" TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Model_Base::writeAttribute (Assignment) File=Library/Phalcon/Model/Base.php Line=1004");
	//$attribute
	//$value
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v0), Z_STRLEN_P(v0), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
}

