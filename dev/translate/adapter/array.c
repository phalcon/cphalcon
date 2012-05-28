
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
#include "kernel/memory.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Phalcon_Translate_Adapter_Array
 *
 * Allows to define translation lists using PHP arrays
 *
 */

/**
 * Phalcon_Translate_Adapter_Array constructor
 *
 * @param array $data
 */
PHP_METHOD(Phalcon_Translate_Adapter_Array, __construct){

	zval *options = NULL, *data = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(options, "content", strlen("content")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, options, "content", strlen("content"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(data, r0);
		if (Z_TYPE_P(data) != IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_translate_exception_ce);
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "Translation data must be an array", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
			phalcon_throw_exception(i0 TSRMLS_CC);
			return;
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_translate_exception_ce);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "Translation content was not provided", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c1, PHALCON_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	phalcon_update_property_zval(this_ptr, "_traslate", strlen("_traslate"), data TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the translation related to the given key
 *
 * @param string $index
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_Array, query){

	zval *index = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_traslate", sizeof("_traslate")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, index);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_traslate", sizeof("_traslate")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, index, PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_RETURN_CHECK_CTOR(r0);
	} else {
		
		PHALCON_RETURN_CHECK_CTOR(index);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether is defined a translation key in the internal array
 *
 * @param string $index
 * @return string
 */
PHP_METHOD(Phalcon_Translate_Adapter_Array, exists){

	zval *index = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_traslate", sizeof("_traslate")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, index);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	
	PHALCON_RETURN_NCTOR(r0);
}

