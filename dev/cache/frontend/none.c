
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
 * Phalcon_Cache_Frontend_None
 *
 * Discards any kind of frontend data input. This frontend does not have expiration time or any other options
 *
 */

/**
 * Phalcon_Cache_Frontend_None constructor
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, __construct){

	zval *frontend_options = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &frontend_options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_MM_RESTORE();
}

/**
 * Returns cache lifetime, always one second expiring content
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, getLifetime){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_LONG(1);
}

/**
 * Check whether if frontend is buffering output, always false
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, isBuffering){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Starts output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, start){


	
}

/**
 * Returns output cached content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, getContent){


	
}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_None, stop){


	
}

PHP_METHOD(Phalcon_Cache_Frontend_None, beforeStore){

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
PHP_METHOD(Phalcon_Cache_Frontend_None, afterRetrieve){

	zval *data = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_RETURN_CHECK_CTOR(data);
}

