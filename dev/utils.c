
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

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Utils
 *
 * Implements functionality used widely by the framework
 */

/**
 * Converts strings to camelize style
 *
 * 
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Utils, camelize){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p2[] = { NULL, NULL, NULL }, *p0[] = { NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], " ", 1);
	PHALCON_ALLOC_ZVAL(p0[1]);
	ZVAL_STRING(p0[1], "", 1);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(r2);
	PHALCON_ALLOC_ZVAL(p2[0]);
	ZVAL_STRING(p2[0], "_", 1);
	PHALCON_ALLOC_ZVAL(p2[1]);
	ZVAL_STRING(p2[1], " ", 1);
	PHALCON_ALLOC_ZVAL(r3);
	PHALCON_CALL_FUNC_PARAMS_1(r3, "strtolower", v0, 0x019);
	p2[2] = r3;
	PHALCON_CALL_FUNC_PARAMS(r2, "str_replace", 3, p2, 0x017);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "ucwords", r2, 0x018);
	p0[2] = r1;
	PHALCON_CALL_FUNC_PARAMS(r0, "str_replace", 3, p0, 0x017);
	RETURN_ZVAL(r0, 1, 0);
}

/**
 * Uncamelize strings which are camelized
 *
 * 
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Phalcon_Utils, uncamelize){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *ac0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p2[] = { NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	add_assoc_string(a0, "/(?<=(?:[A-Z]))([A-Z]+)([A-Z][A-z])/", "\\1_\\2", 1);
	add_assoc_string(a0, "/(?<=(?:[a-z]))([A-Z])/", "_\\1", 1);
	PHALCON_CPY_WRT(v1, a0);
	FOREACH_KV(v1, ac0, fes12, fee12, ah0, hp0, v3, v2)
		PHALCON_INIT_RESULT(r0);
		Z_ADDREF_P(v3);
		Z_ADDREF_P(v0);
		PHALCON_CALL_FUNC_PARAMS_2(r0, "preg_match", v3, v0, 0x01A);
		if (zend_is_true(r0)) {
			PHALCON_INIT_RESULT(r1);
			PHALCON_INIT_RESULT(r2);
			Z_ADDREF_P(v3);
			p2[0] = v3;
			Z_ADDREF_P(v2);
			p2[1] = v2;
			Z_ADDREF_P(v0);
			p2[2] = v0;
			PHALCON_CALL_FUNC_PARAMS(r2, "preg_replace", 3, p2, 0x01B);
			PHALCON_CALL_FUNC_PARAMS_1(r1, "strtolower", r2, 0x019);
			RETURN_ZVAL(r1, 1, 0);
		}
	END_FOREACH(ac0, fes12, fee12, ah0, hp0);
	PHALCON_ALLOC_ZVAL(r3);
	PHALCON_CALL_FUNC_PARAMS_1(r3, "strtolower", v0, 0x019);
	RETURN_ZVAL(r3, 1, 0);
}

/**
     * Changes only first letter to lowercase
     *     
     * @param string $str
     * @return string
     * @static
     **/
PHP_METHOD(Phalcon_Utils, lcfirst){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *c0 = NULL;
	zval *p1[] = { NULL, NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	PHALCON_ALLOC_ZVAL(p1[1]);
	ZVAL_LONG(p1[1], 0);
	PHALCON_ALLOC_ZVAL(p1[2]);
	ZVAL_LONG(p1[2], 1);
	PHALCON_CALL_FUNC_PARAMS(r1, "substr", 3, p1, 0x00A);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "strtolower", r1, 0x019);
	PHALCON_ALLOC_ZVAL(r2);
	Z_ADDREF_P(v0);
	PHALCON_ALLOC_ZVAL(c0);
	ZVAL_LONG(c0, 1);
	PHALCON_CALL_FUNC_PARAMS_2(r2, "substr", v0, c0, 0x00A);
	FREE_ZVAL(c0);
	PHALCON_ALLOC_ZVAL(r3);
	concat_function(r3, r0, r2 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r3);
}

/**
 * Gets public URL to phalcon instance
 *
 * @param string $params
 * @return string
 */
PHP_METHOD(Phalcon_Utils, getUrl){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
	PHALCON_CALL_METHOD(r0, r1, "getbaseuri", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(r2);
	concat_function(r2, r0, v0 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r2);
}

/**
 * Gets path to local file
 *
 * @param string $params
 * @return string
 */
PHP_METHOD(Phalcon_Utils, getLocalPath){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
	PHALCON_CALL_METHOD(r0, r1, "getbasepath", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(r2);
	concat_function(r2, r0, v0 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r2);
}

