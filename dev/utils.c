
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

/**
 * Phalcon\Utils
 *
 * Implements functionality used widely by the framework
 */

/**
 * Gets public URL to phalcon instance
 *
 * @param string $uri
 * @return string
 */
PHP_METHOD(Phalcon_Utils, getUrl){

	zval *uri = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &uri) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!uri) {
		PHALCON_ALLOC_ZVAL_MM(uri);
		ZVAL_NULL(uri);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC(r0, "phalcon\\controller\\front", "getinstance");
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, r0, "getbaseuri", PH_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_VV(r2, r1, uri);
	
	RETURN_CTOR(r2);
}

/**
 * Gets path to local file
 *
 * @param string $extraPath
 * @return string
 */
PHP_METHOD(Phalcon_Utils, getLocalPath){

	zval *extra_path = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &extra_path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!extra_path) {
		PHALCON_ALLOC_ZVAL_MM(extra_path);
		ZVAL_NULL(extra_path);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC(r0, "phalcon\\controller\\front", "getinstance");
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, r0, "getbasepath", PH_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_VV(r2, r1, extra_path);
	
	RETURN_CTOR(r2);
}

