
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
#include "kernel/output.h"
#include "kernel/hash.h"
#include "kernel/require.h"
#include "kernel/object.h"

#include "mvc/view/engine/helpers.h"

/**
 * Phalcon\Mvc\View\Engine\Php
 *
 * Adapter to use PHP itself as templating engine
 */


/**
 * Phalcon\Mvc\View\Engine\Php initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine_Php){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine, Php, mvc_view_engine_php, phalcon_mvc_view_engine_ce, phalcon_mvc_view_engine_php_method_entry, 0);

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

	zval *path, *params, *must_clean = NULL, *contents;
	zval *view;

	phalcon_fetch_params(0, 2, 1, &path, &params, &must_clean);
	
	if (!must_clean) {
		must_clean = PHALCON_GLOBAL(z_false);
	}
	
	if (PHALCON_IS_TRUE(must_clean)) {
		phalcon_ob_clean(TSRMLS_C);
	}
	
	/** 
	 * Create the variables in local symbol table
	 */
	if (Z_TYPE_P(params) == IS_ARRAY) { 
		if (!EG(active_symbol_table)) {
			zend_rebuild_symbol_table(TSRMLS_C);
		}

		zend_hash_merge_ex(
			EG(active_symbol_table),
			Z_ARRVAL_P(params),
			(copy_ctor_func_t)zval_add_ref,
			sizeof(zval*),
			phalcon_mvc_view_engine_php_symtable_merger
#ifdef ZTS
			TSRMLS_CC
#else
			NULL
#endif
		);
	}
	
	/** 
	 * Require the file
	 */
	if (phalcon_require(path TSRMLS_CC) == FAILURE) {
		RETURN_FALSE;
	}

	if (PHALCON_IS_TRUE(must_clean)) {
		PHALCON_ALLOC_GHOST_ZVAL(contents);
		phalcon_ob_get_contents(contents TSRMLS_CC);
	
		view = phalcon_fetch_nproperty_this(this_ptr, SL("_view"), PH_NOISY_CC);
		phalcon_call_method_params(NULL, NULL, view, SL("setcontent"), zend_inline_hash_func(SS("setcontent")) TSRMLS_CC, 1, contents);
	}

	RETURN_TRUE;
}
