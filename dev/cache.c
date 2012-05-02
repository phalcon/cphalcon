
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
 * Phalcon_Cache
 *
 * Phalcon_Cache can be used to caches output fragments to improve performance
 *
 *
 */

/**
 * Factories different caches backends from its adapters
 *
 * @paramstring $frontendAdapter
 * @paramstring $backendAdapter
 * @paramarray $frontendOptions
 * @paramarray $backendOptions
 * @return  Phalcon_Cache_Backend_File
 * @static
 */
PHP_METHOD(Phalcon_Cache, factory){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zval *p1[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL, NULL };
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v2, a0);
	}
	if (!v3) {
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_CPY_WRT(v3, a1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Cache_Frontend_", v0);
	PHALCON_CPY_WRT(v4, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v4);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", v4, 0x00F);
	Z_DELREF_P(v4);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_cache_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Frontend adapter \"", v1, "' doesn't exist");
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CONCAT_LEFT(r3, "Phalcon_Cache_Backend_", v1);
	PHALCON_CPY_WRT(v5, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	Z_ADDREF_P(v5);
	PHALCON_CALL_FUNC_PARAMS_1(r4, "class_exists", v5, 0x00F);
	Z_DELREF_P(v5);
	if (!zend_is_true(r4)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_cache_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_BOTH(r5,  "Backend adapter \"", v1, "' doesn't exist");
		Z_ADDREF_P(r5);
		p3[0] = r5;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		Z_DELREF_P(p3[0]);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	ce0 = zend_fetch_class(Z_STRVAL_P(v4), Z_STRLEN_P(v4), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i2);
	object_init_ex(i2, ce0);
	Z_ADDREF_P(v2);
	p4[0] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p4, PHALCON_CALL_CHECK);
	Z_DELREF_P(p4[0]);
	PHALCON_CPY_WRT(v6, i2);
	ce1 = zend_fetch_class(Z_STRVAL_P(v5), Z_STRLEN_P(v5), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i3);
	object_init_ex(i3, ce1);
	Z_ADDREF_P(v6);
	p5[0] = v6;
	Z_ADDREF_P(v3);
	p5[1] = v3;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 2, p5, PHALCON_CALL_CHECK);
	Z_DELREF_P(p5[0]);
	Z_DELREF_P(p5[1]);
	PHALCON_RETURN_CTOR(i3);
}

