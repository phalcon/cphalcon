
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

	zval *view = NULL, *options = NULL, *params = NULL, *twig = NULL, *loader = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	int eval_int;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &view, &options, &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "Twig_Environment", 1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "class_exists", c0, 0x012);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_view_exception_ce);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "Twig library must be loaded first", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c1, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	eval_int = phalcon_array_isset_string(options, "twig", strlen("twig")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, options, "twig", strlen("twig"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(twig, r1);
	} else {
		eval_int = phalcon_array_isset_string(options, "loader", strlen("loader")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_array_fetch_string(&r2, options, "loader", strlen("loader"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(loader, r2);
		} else {
			ce0 = zend_fetch_class("Twig_Loader_Filesystem", strlen("Twig_Loader_Filesystem"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(i1);
			object_init_ex(i1, ce0);
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CALL_METHOD(r3, view, "getviewsdir", PHALCON_NO_CHECK);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", r3, PHALCON_CHECK);
			PHALCON_CPY_WRT(loader, i1);
		}
		ce1 = zend_fetch_class("Twig_Environment", strlen("Twig_Environment"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(i2);
		object_init_ex(i2, ce1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i2, "__construct", loader, PHALCON_CHECK);
		PHALCON_CPY_WRT(twig, i2);
	}
	
	phalcon_update_property_zval(this_ptr, "_twig", strlen("_twig"), twig TSRMLS_CC);
	PHALCON_CALL_PARENT_PARAMS_3_NORETURN(this_ptr, "Phalcon_View_Engine_Twig", "__construct", view, options, params);
	
	PHALCON_MM_RESTORE();
}

/**
 * Renders a view using the template engine
 *
 * @param string $path
 */
PHP_METHOD(Phalcon_View_Engine_Twig, render){

	zval *path = NULL, *params = NULL, *view = NULL, *relative_path = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(params, t0);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(view, t1);
	eval_int = phalcon_array_isset_string(params, "view", strlen("view")+1);
	if (!eval_int) {
		phalcon_array_update_string(&params, "view", strlen("view"), &view, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, "content", strlen("content")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, view, "getcontent", PHALCON_NO_CHECK);
		phalcon_array_update_string(&params, "content", strlen("content"), &r0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, view, "getviewsdir", PHALCON_NO_CHECK);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "", 1);
	PHALCON_CALL_FUNC_PARAMS_3(r1, "str_replace", r2, c0, path, 0x003);
	PHALCON_CPY_WRT(relative_path, r1);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_twig", sizeof("_twig")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2(r3, t3, "render", relative_path, params, PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(t2, "setcontent", r3, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

