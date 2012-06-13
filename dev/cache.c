
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
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/memory.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Phalcon_Cache
 *
 * Phalcon_Cache can be used to cache output fragments to improve performance
 *
 *
 */

/**
 * Factories different caches backends from its adapters
 *
 * @param string $frontendAdapter
 * @param string $backendAdapter
 * @param array $frontendOptions
 * @param array $backendOptions
 * @return  Phalcon_Cache_Backend_File
 * @static
 */
PHP_METHOD(Phalcon_Cache, factory){

	zval *frontend_adapter = NULL, *backend_adapter = NULL;
	zval *frontend_options = NULL, *backend_options = NULL;
	zval *frontend_class = NULL, *backend_class = NULL, *front_object = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &frontend_adapter, &backend_adapter, &frontend_options, &backend_options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!frontend_options) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(frontend_options, a0);
	}
	
	if (!backend_options) {
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_CPY_WRT(backend_options, a1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_SV(r0, "Phalcon_Cache_Frontend_", frontend_adapter);
	PHALCON_CPY_WRT(frontend_class, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", frontend_class, 0x012);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_cache_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_SVS(r2, "Frontend adapter \"", backend_adapter, "' doesn't exist");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r2, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CONCAT_SV(r3, "Phalcon_Cache_Backend_", backend_adapter);
	PHALCON_CPY_WRT(backend_class, r3);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_FUNC_PARAMS_1(r4, "class_exists", backend_class, 0x012);
	if (!zend_is_true(r4)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_cache_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_SVS(r5, "Backend adapter \"", backend_adapter, "' doesn't exist");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", r5, PHALCON_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	
	ce0 = phalcon_fetch_class(frontend_class TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i2);
	object_init_ex(i2, ce0);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i2, "__construct", frontend_options, PHALCON_CHECK);
	PHALCON_CPY_WRT(front_object, i2);
	ce1 = phalcon_fetch_class(backend_class TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i3);
	object_init_ex(i3, ce1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i3, "__construct", front_object, backend_options, PHALCON_CHECK);
	
	PHALCON_RETURN_CTOR(i3);
}

