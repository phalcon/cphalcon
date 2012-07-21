
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

#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"

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
 */
PHP_METHOD(Phalcon_View_Engine_Php, __construct){

	zval *view = NULL, *options = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &view, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_CALL_PARENT_PARAMS_2_NORETURN(this_ptr, "Phalcon\\View\\Engine\\Php", "__construct", view, options);
	
	PHALCON_MM_RESTORE();
}

/**
 * Renders a view using the template engine
 *
 * @param string $path
 * @param array $params
 */
PHP_METHOD(Phalcon_View_Engine_Php, render){

	zval *path = NULL, *params = NULL, *value = NULL, *key = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &path, &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_CALL_FUNC_NORETURN("ob_clean");
	if (phalcon_valid_foreach(params TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(params);
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
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_view"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "ob_get_contents");
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(t0, "setcontent", r0, PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

