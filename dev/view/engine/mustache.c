
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
 * Phalcon_View_Engine_Mustache
 *
 * Adapter to use Mustache library as templating engine
 */

/**
 * Phalcon_View_Engine_Mustache constructor
 *
 * @param Phalcon_View $view
 * @param array $options
 */
PHP_METHOD(Phalcon_View_Engine_Mustache, __construct){

	zval *view = NULL, *options = NULL, *mustache = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *i0 = NULL;
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &view, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "Mustache", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "class_exists", c0);
	if (!zend_is_true(r0)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_view_exception_ce, "Mustache class must be loaded first");
		return;
	}
	eval_int = phalcon_array_isset_string(options, SL("mustache")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, options, SL("mustache"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(mustache, r1);
	} else {
		ce0 = zend_fetch_class("Mustache", strlen("Mustache"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, ce0);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
		PHALCON_CPY_WRT(mustache, i0);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_mustache"), mustache TSRMLS_CC);
	PHALCON_CALL_PARENT_PARAMS_2_NORETURN(this_ptr, "Phalcon_View_Engine_Mustache", "__construct", view, options);
	
	PHALCON_MM_RESTORE();
}

/**
 * Renders a view using the template engine
 *
 * @param string $path
 * @param array $params
 * @return string
 */
PHP_METHOD(Phalcon_View_Engine_Mustache, render){

	zval *path = NULL, *params = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &path, &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_params"), params TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_view"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_mustache"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "file_get_contents", path);
	PHALCON_CALL_METHOD_PARAMS_2(r0, t1, "render", r1, this_ptr, PHALCON_NO_CHECK);

	RETURN_DZVAL(r0);
}

PHP_METHOD(Phalcon_View_Engine_Mustache, __isset){

	zval *property = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &property) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_params"), PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, property);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	
	RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_View_Engine_Mustache, __get){

	zval *property = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &property) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_params"), PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, property);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_params"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, property, PHALCON_NOISY TSRMLS_CC);
		
		RETURN_CHECK_CTOR(r0);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_View_Engine_Mustache, __call){

	zval *method = NULL, *arguments = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &method, &arguments) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_mustache"), PHALCON_NOISY TSRMLS_CC);
	phalcon_array_append(&a0, t0, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	phalcon_array_append(&a0, method, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_2_NORETURN("call_user_func_array", a0, arguments);
	
	PHALCON_MM_RESTORE();
}

