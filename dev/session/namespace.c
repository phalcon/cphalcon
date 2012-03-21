
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
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

PHP_METHOD(Phalcon_Session_Namespace, __construct){

	zval *a0 = NULL;
	zval *v0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_session_namespace_class_entry, this_ptr, "_data", strlen("_data"), a0 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_name", strlen("_name"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Session_Namespace, __set){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_data", sizeof("_data")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v1);
	phalcon_array_update(t0, v0, v1 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_data", strlen("_data"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_name", sizeof("_name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t1);
	p0[0] = t1;
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_data", sizeof("_data")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t2);
	p0[1] = t2;
	PHALCON_CALL_STATIC_PARAMS_NORETURN("phalcon_session", "set", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Session_Namespace, __get){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_data", sizeof("_data")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v1, t0);
	eval_int = phalcon_array_isset(v1, v0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, v1, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r0);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

