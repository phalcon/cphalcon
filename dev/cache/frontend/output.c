
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
 * Phalcon_Cache_Frontend_Output
 *
 * Allows to cache output fragments captured with ob_* functions
 *
 */

/**
 * Phalcon_Cache_Frontend_Output constructor
 *
 * @param array $frontendOptions
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, __construct){

	zval *frontend_options = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_cache_frontend_output_ce, this_ptr, "_frontendOptions", strlen("_frontendOptions"), a0 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &frontend_options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_frontendOptions", strlen("_frontendOptions"), frontend_options TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns cache lifetime
 *
 * @return integer
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, getLifetime){

	zval *options = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_frontendOptions", sizeof("_frontendOptions")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(options, t0);
	eval_int = phalcon_array_isset_string(options, "lifetime", strlen("lifetime")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, options, "lifetime", strlen("lifetime"), PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_RETURN_CHECK_CTOR(r0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_LONG(1);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether if frontend is buffering output
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, isBuffering){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_buffering", sizeof("_buffering")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Starts output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, start){


	PHALCON_MM_GROW();
	phalcon_update_property_bool(this_ptr, "_buffering", strlen("_buffering"), 1 TSRMLS_CC);
	PHALCON_CALL_FUNC_NORETURN("ob_start", 0x014);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns output cached content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, getContent){

	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_buffering", sizeof("_buffering")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC(r0, "ob_get_contents", 0x015);
		PHALCON_RETURN_DZVAL(r0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, stop){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_buffering", sizeof("_buffering")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_CALL_FUNC_NORETURN("ob_end_clean", 0x016);
	}
	phalcon_update_property_bool(this_ptr, "_buffering", strlen("_buffering"), 0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Cache_Frontend_Output, beforeStore){

	zval *data = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_RETURN_CHECK_CTOR(data);
}

/**
 * Prepares data to be retrieved to user
 */
PHP_METHOD(Phalcon_Cache_Frontend_Output, afterRetrieve){

	zval *data = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_RETURN_CHECK_CTOR(data);
}

