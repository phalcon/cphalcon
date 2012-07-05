
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
#include "kernel/array.h"
#include "kernel/object.h"
/**
 * Phalcon_View_Engine_Twig
 *
 * Adapter to use Twig library as templating engine
 */

/**
 * Phalcon_View_Engine_Twig constructor
 *
 * @param Phalcon_View $view
 * @param array $options
 * @param array $params
 */
PHP_METHOD(Phalcon_View_Engine_Twig, __construct){

	zval *view = NULL, *options = NULL, *twig = NULL, *loader = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	int eval_int;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &view, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "Twig_Environment", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "class_exists", c0);
	if (!zend_is_true(r0)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_view_exception_ce, "Twig library must be loaded first");
		return;
	}
	eval_int = phalcon_array_isset_string(options, SL("twig")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, options, SL("twig"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(twig, r1);
	} else {
		eval_int = phalcon_array_isset_string(options, SL("loader")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_array_fetch_string(&r2, options, SL("loader"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(loader, r2);
		} else {
			ce0 = zend_fetch_class("Twig_Loader_Filesystem", strlen("Twig_Loader_Filesystem"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, ce0);
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CALL_METHOD(r3, view, "getviewsdir", PHALCON_NO_CHECK);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r3, PHALCON_CHECK);
			PHALCON_CPY_WRT(loader, i0);
		}
		ce1 = zend_fetch_class("Twig_Environment", strlen("Twig_Environment"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, ce1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", loader, PHALCON_CHECK);
		PHALCON_CPY_WRT(twig, i1);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_twig"), twig TSRMLS_CC);
	PHALCON_CALL_PARENT_PARAMS_2_NORETURN(this_ptr, "Phalcon_View_Engine_Twig", "__construct", view, options);
	
	PHALCON_MM_RESTORE();
}

/**
 * Renders a view using the template engine
 *
 * @param string $path
 * @param array $params
 * @return string
 */
PHP_METHOD(Phalcon_View_Engine_Twig, render){

	zval *path = NULL, *params = NULL, *view = NULL, *twig_params = NULL, *relative_path = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &path, &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_view"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(view, t0);
	PHALCON_CPY_WRT(twig_params, params);
	eval_int = phalcon_array_isset_string(twig_params, SL("content")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, view, "getcontent", PHALCON_NO_CHECK);
		phalcon_array_update_string(&twig_params, SL("content"), &r0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(twig_params, SL("view")+1);
	if (!eval_int) {
		phalcon_array_update_string(&twig_params, SL("view"), &view, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, view, "getviewsdir", PHALCON_NO_CHECK);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_fast_str_replace(r2, r1, c0, path TSRMLS_CC);
	PHALCON_CPY_WRT(relative_path, r2);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_view"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_twig"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2(r3, t2, "render", relative_path, twig_params, PHALCON_NO_CHECK);

	RETURN_DZVAL(r3);
}

