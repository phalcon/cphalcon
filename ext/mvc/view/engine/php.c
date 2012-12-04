
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

#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"

/**
 * Phalcon\Mvc\View\Engine\Php
 *
 * Adapter to use PHP itself as templating engine
 */


/**
 * Phalcon\Mvc\View\Engine\Php initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine_Php){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine, Php, mvc_view_engine_php, "phalcon\\mvc\\view\\engine", phalcon_mvc_view_engine_php_method_entry, 0);

	zend_class_implements(phalcon_mvc_view_engine_php_ce TSRMLS_CC, 1, phalcon_mvc_view_engineinterface_ce);

	return SUCCESS;
}

/**
 * Renders a view using the template engine
 *
 * @param string $path
 * @param array $params
 * @param boolean $mustClean
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Php, render){

	zval *path, *params, *must_clean, *value = NULL, *key = NULL, *contents;
	zval *view;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &path, &params, &must_clean) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (PHALCON_IS_TRUE(must_clean)) {
		PHALCON_CALL_FUNC_NORETURN("ob_clean");
	}
	
	if (!phalcon_valid_foreach(params TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(params);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
	
		PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(value);
	
		if (phalcon_set_symbol(key, value TSRMLS_CC) == FAILURE){
			return;
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	if (phalcon_require(path TSRMLS_CC) == FAILURE) {
		return;
	}
	if (PHALCON_IS_TRUE(must_clean)) {
		PHALCON_INIT_VAR(contents);
		PHALCON_CALL_FUNC(contents, "ob_get_contents");
	
		PHALCON_INIT_VAR(view);
		phalcon_read_property(&view, this_ptr, SL("_view"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(view, "setcontent", contents, PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

