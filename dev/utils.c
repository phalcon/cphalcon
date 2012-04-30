
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(p0[0]);
	ZVAL_STRING(p0[0], " ", 1);
	PHALCON_INIT_VAR(p0[1]);
	ZVAL_STRING(p0[1], "", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_INIT_VAR(p2[0]);
	ZVAL_STRING(p2[0], "_", 1);
	PHALCON_INIT_VAR(p2[1]);
	ZVAL_STRING(p2[1], " ", 1);
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_FUNC_PARAMS_1(r3, "strtolower", v0, 0x031);
	p2[2] = r3;
	PHALCON_CALL_FUNC_PARAMS(r2, "str_replace", 3, p2, 0x003);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "ucwords", r2, 0x030);
	p0[2] = r1;
	PHALCON_CALL_FUNC_PARAMS(r0, "str_replace", 3, p0, 0x003);
	PHALCON_RETURN_DZVAL(r0);
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *p2[] = { NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_assoc_stringl_ex(a0, "/(?<=(?:[A-Z]))([A-Z]+)([A-Z][A-z])/", strlen("/(?<=(?:[A-Z]))([A-Z]+)([A-Z][A-z])/")+1, "\\1_\\2", strlen("\\1_\\2"), 1);
	add_assoc_stringl_ex(a0, "/(?<=(?:[a-z]))([A-Z])/", strlen("/(?<=(?:[a-z]))([A-Z])/")+1, "_\\1", strlen("_\\1"), 1);
	PHALCON_CPY_WRT(v1, a0);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_6277_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_6277_0;
		} else {
			PHALCON_INIT_VAR(v3);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v3, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v3, num);
				}
			}
		}
		PHALCON_INIT_VAR(v2);
		ZVAL_ZVAL(v2, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		Z_ADDREF_P(v3);
		Z_ADDREF_P(v0);
		PHALCON_CALL_FUNC_PARAMS_2(r0, "preg_match", v3, v0, 0x032);
		Z_DELREF_P(v3);
		Z_DELREF_P(v0);
		if (zend_is_true(r0)) {
			PHALCON_INIT_VAR(r1);
			PHALCON_INIT_VAR(r2);
			p2[0] = v3;
			p2[1] = v2;
			p2[2] = v0;
			PHALCON_CALL_FUNC_PARAMS(r2, "preg_replace", 3, p2, 0x033);
			PHALCON_CALL_FUNC_PARAMS_1(r1, "strtolower", r2, 0x031);
			PHALCON_RETURN_DZVAL(r1);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_6277_0;
		fee_6277_0:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_FUNC_PARAMS_1(r3, "strtolower", v0, 0x031);
	PHALCON_RETURN_DZVAL(r3);
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	PHALCON_INIT_VAR(p1[1]);
	ZVAL_LONG(p1[1], 0);
	PHALCON_INIT_VAR(p1[2]);
	ZVAL_LONG(p1[2], 1);
	PHALCON_CALL_FUNC_PARAMS(r1, "substr", 3, p1, 0x002);
	Z_DELREF_P(p1[0]);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "strtolower", r1, 0x031);
	PHALCON_ALLOC_ZVAL_MM(r2);
	Z_ADDREF_P(v0);
	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 1);
	PHALCON_CALL_FUNC_PARAMS_2(r2, "substr", v0, c0, 0x002);
	Z_DELREF_P(v0);
	PHALCON_ALLOC_ZVAL_MM(r3);
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
	PHALCON_CALL_METHOD(r0, r1, "getbaseuri", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r2);
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
	PHALCON_CALL_METHOD(r0, r1, "getbasepath", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r2);
	concat_function(r2, r0, v0 TSRMLS_CC);
	PHALCON_RETURN_CTOR(r2);
}

