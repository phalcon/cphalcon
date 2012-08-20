
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

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"

/**
 * Phalcon\Mvc\Url
 *
 * Generates internal URIs and Paths
 */

PHP_METHOD(Phalcon_Mvc_Url, setBaseUri){

	zval *base_uri = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &base_uri) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_baseUri"), base_uri TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Url, getBaseUri){

	zval *base_uri = NULL, *slash = NULL, *php_self = NULL, *dirname = NULL, *dir_parts = NULL;
	zval *slice = NULL, *uri = NULL;
	zval *g0 = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(base_uri);
	phalcon_read_property(&base_uri, this_ptr, SL("_baseUri"), PH_NOISY_CC);
	if (!zend_is_true(base_uri)) {
		PHALCON_INIT_VAR(slash);
		ZVAL_STRING(slash, "/", 1);
		phalcon_get_global(&g0, SL("_SERVER")+1 TSRMLS_CC);
		eval_int = phalcon_array_isset_string(g0, SL("PHP_SELF")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(php_self);
			phalcon_array_fetch_string(&php_self, g0, SL("PHP_SELF"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(dirname);
			PHALCON_CALL_FUNC_PARAMS_1(dirname, "dirname", php_self);
			
			PHALCON_INIT_VAR(dir_parts);
			phalcon_fast_explode(dir_parts, slash, dirname TSRMLS_CC);
			
			PHALCON_INIT_VAR(c0);
			ZVAL_LONG(c0, 1);
			
			PHALCON_INIT_VAR(t1);
			ZVAL_LONG(t1, 1);
			
			PHALCON_INIT_VAR(t0);
			ZVAL_LONG(t0, -1);
			
			PHALCON_ALLOC_ZVAL_MM(r0);
			mul_function(r0, t0, t1 TSRMLS_CC);
			
			PHALCON_INIT_VAR(slice);
			PHALCON_CALL_FUNC_PARAMS_3(slice, "array_slice", dir_parts, c0, r0);
			
			PHALCON_INIT_VAR(uri);
			phalcon_fast_join(uri, slash, slice TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(uri);
			ZVAL_STRING(uri, "", 1);
		}
		
		if (!zend_is_true(uri)) {
			PHALCON_CPY_WRT(base_uri, slash);
		} else {
			PHALCON_INIT_VAR(base_uri);
			PHALCON_CONCAT_VVV(base_uri, slash, uri, slash);
		}
		
		phalcon_update_property_zval(this_ptr, SL("_baseUri"), base_uri TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(base_uri);
}

PHP_METHOD(Phalcon_Mvc_Url, setBasePath){

	zval *base_path = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &base_path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_basePath"), base_path TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Url, getBasePath){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_basePath"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Gets a public URL prepending the application URI
 *
 * @param string $uri
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Url, get){

	zval *uri = NULL, *base_uri = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &uri) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!uri) {
		PHALCON_ALLOC_ZVAL_MM(uri);
		ZVAL_NULL(uri);
	}
	
	PHALCON_INIT_VAR(base_uri);
	PHALCON_CALL_METHOD(base_uri, this_ptr, "getbaseuri", PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_VV(r0, base_uri, uri);
	
	RETURN_CTOR(r0);
}

PHP_METHOD(Phalcon_Mvc_Url, path){

	zval *uri = NULL, *base_path = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &uri) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!uri) {
		PHALCON_ALLOC_ZVAL_MM(uri);
		ZVAL_NULL(uri);
	}
	
	PHALCON_INIT_VAR(base_path);
	phalcon_read_property(&base_path, this_ptr, SL("_basePath"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_VV(r0, base_path, uri);
	
	RETURN_CTOR(r0);
}

