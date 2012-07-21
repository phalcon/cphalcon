
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/object.h"

/**
 * Phalcon\Cache
 *
 * Phalcon\Cache can be used to cache output fragments, PHP data and raw data in order to improve performance
 *
 *
 */

/**
 * Factories different caches backends from their adapters
 *
 * @param string $frontendAdapter
 * @param string $backendAdapter
 * @param array $frontendOptions
 * @param array $backendOptions
 * @return  Phalcon_Cache_Backend_File
 */
PHP_METHOD(Phalcon_Cache, factory){

	zval *frontend_adapter = NULL, *backend_adapter = NULL;
	zval *frontend_options = NULL, *backend_options = NULL;
	zval *frontend_class = NULL, *backend_class = NULL, *front_object = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &frontend_adapter, &backend_adapter, &frontend_options, &backend_options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!frontend_options) {
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		PHALCON_CPY_WRT(frontend_options, a0);
	}
	
	if (!backend_options) {
		PHALCON_ALLOC_ZVAL_MM(a1);
		array_init(a1);
		PHALCON_CPY_WRT(backend_options, a1);
	}
	
	PHALCON_INIT_VAR(frontend_class);
	PHALCON_CONCAT_SV(frontend_class, "Phalcon\\Cache\\Frontend\\", frontend_adapter);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "class_exists", frontend_class);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_cache_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVS(r1, "Frontend adapter \"", backend_adapter, "\" doesn't exist");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r1, PH_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_INIT_VAR(backend_class);
	PHALCON_CONCAT_SV(backend_class, "Phalcon\\Cache\\Backend\\", backend_adapter);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "class_exists", backend_class);
	if (!zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_cache_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_SVS(r3, "Backend adapter \"", backend_adapter, "\" doesn't exist");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", r3, PH_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	
	ce0 = phalcon_fetch_class(frontend_class TSRMLS_CC);
	
	PHALCON_INIT_VAR(front_object);
	object_init_ex(front_object, ce0);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(front_object, "__construct", frontend_options, PH_CHECK);
	ce1 = phalcon_fetch_class(backend_class TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i2);
	object_init_ex(i2, ce1);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i2, "__construct", front_object, backend_options, PH_CHECK);
	
	RETURN_CTOR(i2);
}

