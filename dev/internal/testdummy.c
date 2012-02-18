
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

PHP_METHOD(Phalcon_Internal_TestDummy, __construct){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_TestDummy", "__construct", 0);
	phalcon_step_over("Phalcon_Internal_TestDummy::__construct (Assignment) File=Library/Phalcon/Internal/TestDummy.php Line=8");
	//$p1
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_d1", strlen("_d1"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Internal_TestDummy::__construct (Method) File=Library/Phalcon/Internal/TestDummy.php Line=11");
}

PHP_METHOD(Phalcon_Internal_TestDummy, f1){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Internal_TestDummy", "f1", 0);
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_d1", sizeof("_d1")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_TestDummy" TSRMLS_CC);
	phalcon_debug_method_call(t0, "t12" TSRMLS_CC);
	//$p1
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, t0, "t12", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Internal_TestDummy" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
}

