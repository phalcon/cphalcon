
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
 * Phalcon_Cache
 *
 * Phalcon_Cache could be use to caches output fragments for improve perfomace
 */

/**
 * Factories diferent caches backends from its adapters
 *
 * @paramstring $adapter
 * @paramarray $frontendOptions
 * @paramarray $backendOptions
 * @static
 */
PHP_METHOD(Phalcon_Cache, factory){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL, NULL };
	zend_class_entry *ce0;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &v0, &v1, &v2) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Cache", "factory", 0);
	phalcon_step_over("Phalcon_Cache::factory (Assignment) File=/Cache Line=19");
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Cache_Adapter_", v0);
	PHALCON_CPY_WRT(v3, r0);
	phalcon_debug_assign("$adapterClass", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Cache::factory (If) File=/Cache Line=20");
	PHALCON_ALLOC_ZVAL(r1);
	Z_ADDREF_P(v3);
	p0[0] = v3;
	phalcon_debug_param(v3 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r1, "class_exists", 1, p0);
	phalcon_debug_vdump("class_exists > ", r1 TSRMLS_CC);
	if (!zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Cache::factory (Block) File=/Cache Line=20");
		phalcon_step_over("Phalcon_Cache::factory (Throw) File=/Cache Line=21");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_cache_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Cache" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_both(r2,  "Adapter \"", v0, "' doesn't exist" TSRMLS_CC);
		Z_ADDREF_P(r2);
		p1[0] = r2;
		phalcon_debug_param(r2 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Cache" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	ce0 = zend_fetch_class(Z_STRVAL_P(v3), Z_STRLEN_P(v3), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(i1);
	object_init_ex(i1, ce0);
	phalcon_assert_class(this_ptr, "Phalcon_Cache" TSRMLS_CC);
	phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
	Z_ADDREF_P(v1);
	p2[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	Z_ADDREF_P(v2);
	p2[1] = v2;
	phalcon_debug_param(v2 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p2, PHALCON_CALL_CHECK);
	phalcon_assert_class(this_ptr, "Phalcon_Cache" TSRMLS_CC);
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
	phalcon_step_out_entry();
}

