
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

PHP_METHOD(Phalcon_Paginator, __contruct){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_RETURN_CHECK_CTOR(v0);
}

/**
     * Factories a builder component
     *
     * @param   string $component
     * @param   array $options
     * @return  Object
     */
PHP_METHOD(Phalcon_Paginator, factory){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *c0 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL };
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_STATIC_PARAMS(r0, "phalcon_utils", "camelize", 1, p0);
	Z_DELREF_P(p0[0]);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CONCAT_LEFT(r1, "Phalcon_Paginator_Adapter_", r0);
	PHALCON_CPY_WRT(v2, r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	Z_ADDREF_P(v2);
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 0);
	PHALCON_CALL_FUNC_PARAMS_2(r2, "class_exists", v2, c0, 0x000);
	Z_DELREF_P(v2);
	if (!zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		Z_ADDREF_P(v0);
		p2[0] = v0;
		PHALCON_CALL_STATIC_PARAMS(r3, "phalcon_utils", "camelize", 1, p2);
		Z_DELREF_P(p2[0]);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_BOTH(r4,  "../Library/Phalcon/Paginator/Adapter/", r3, ".php");
		PHALCON_CPY_WRT(v3, r4);
		if (phalcon_file_exists(v3 TSRMLS_CC) == SUCCESS) {
			phalcon_require(v3 TSRMLS_CC);
			if (EG(exception) || EG(exit_status) == 255) {
				return;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_paginator_exception_class_entry);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CONCAT_BOTH(r5,  "The paginator adapter file \"", v2, "\" does not exist");
			Z_ADDREF_P(r5);
			p3[0] = r5;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p3, PHALCON_CALL_CHECK);
			Z_DELREF_P(p3[0]);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			PHALCON_MM_RESTORE();
			return;
		}
	}
	ce0 = zend_fetch_class(Z_STRVAL_P(v2), Z_STRLEN_P(v2), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, ce0);
	Z_ADDREF_P(v1);
	p4[0] = v1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p4, PHALCON_CALL_CHECK);
	Z_DELREF_P(p4[0]);
	PHALCON_CPY_WRT(v4, i1);
	PHALCON_RETURN_CTOR(v4);
}

