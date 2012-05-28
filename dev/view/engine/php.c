
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
 *
 * Phalcon_View_Engine_Php
 *
 * Adapter to use PHP itself as templating engine
 */

/**
 * Phalcon_View_Engine_Php constructor
 *
 * @param Phalcon_View $view
 * @param array $options
 * @param array $params
 */
PHP_METHOD(Phalcon_View_Engine_Php, __construct){

	zval *view = NULL, *options = NULL, *params = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &view, &options, &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_CALL_PARENT_PARAMS_3_NORETURN(this_ptr, "Phalcon_View_Engine_Php", "__construct", view, options, params);
	
	PHALCON_MM_RESTORE();
}

/**
 * Renders a view using the template engine
 *
 * @param string $path
 */
PHP_METHOD(Phalcon_View_Engine_Php, render){

	zval *path = NULL, *value = NULL, *key = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_CALL_FUNC_NORETURN("ob_clean", 0x01D);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY TSRMLS_CC);
	if (phalcon_valid_foreach(t0 TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(t0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_4b07_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_4b07_0;
		} else {
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		}
		PHALCON_INIT_VAR(value);
		ZVAL_ZVAL(value, *hd, 1, 0);
		if (phalcon_set_symbol(key, value TSRMLS_CC) == FAILURE){
			return;
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_4b07_0;
		fee_4b07_0:
		if(0){}
	} else {
		return;
	}
	if (phalcon_require(path TSRMLS_CC) == FAILURE) {
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "ob_get_contents", 0x015);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(t1, "setcontent", r0, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

