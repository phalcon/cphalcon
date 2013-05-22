
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

	zval *path, *params, *must_clean = NULL, *value = NULL, *key = NULL, *contents;
	zval *view;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &path, &params, &must_clean);
	
	if (!must_clean) {
		PHALCON_INIT_VAR(must_clean);
		ZVAL_BOOL(must_clean, 0);
	}
	
	if (PHALCON_IS_TRUE(must_clean)) {
		phalcon_call_func_noret("ob_clean");
	}
	if (Z_TYPE_P(params) == IS_ARRAY) { 
	
		if (!phalcon_is_iterable(params, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(value);
	
			if (phalcon_set_symbol(key, value TSRMLS_CC) == FAILURE){
				return;
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	if (phalcon_require(path TSRMLS_CC) == FAILURE) {
		return;
	}
	if (PHALCON_IS_TRUE(must_clean)) {
		PHALCON_INIT_VAR(contents);
		phalcon_call_func(contents, "ob_get_contents");
	
		PHALCON_OBS_VAR(view);
		phalcon_read_property_this(&view, this_ptr, SL("_view"), PH_NOISY_CC);
		phalcon_call_method_p1_noret(view, "setcontent", contents);
	}
	
	PHALCON_MM_RESTORE();
}

